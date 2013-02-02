#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include "highscoredialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect( ui->btnStart, SIGNAL(clicked()),
                      this, SLOT(startGame()) );
    QObject::connect( ui->pushButton, SIGNAL(clicked()),
                      this, SLOT(showHighScore()) );

    squares << ui->widget;
    squares << ui->widget_2;
    squares << ui->widget_3;
    squares << ui->widget_4;

    foreach ( QWidget *s, squares )
    {
        s->installEventFilter(this);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    playing = true;
    score = 0;
    ui->lcdScore->display(score);
    startRound();
}

bool MainWindow::eventFilter( QObject *obj, QEvent *ev )
{
    if ( playing && ev->type() == QEvent::MouseButtonPress )
    {
        if ( obj == squares.at(winnerIdx) )
        {
            winRound();
        }
        else
        {
            looseRound();
        }
    }

    return QMainWindow::eventFilter( obj, ev );
}

void MainWindow::startRound()
{
    winnerIdx = qrand() % 4;
    foreach ( QWidget *s, squares )
    {
        s->setStyleSheet("background: blue;");
    }

    squares.at(winnerIdx)->setStyleSheet("background: red");
}

void MainWindow::winRound()
{
    qDebug() << "Win";
    startRound();
    score += 10;
    ui->lcdScore->display(score);
}

void MainWindow::looseRound()
{
    QString name = QInputDialog::getText(this, "Name", "Player Name");
    qDebug() << "Loose";
    playing = false;

    scoreKeeper.addHighScore(name, score);
    qDebug() << scoreKeeper.getTopScore();
}

void MainWindow::showHighScore()
{
    HighscoreDialog dlg;
    dlg.setScore( scoreKeeper.getTopScore() );
    dlg.exec();
}
