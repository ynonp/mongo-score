#include "highscoredialog.h"
#include "ui_highscoredialog.h"

HighscoreDialog::HighscoreDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HighscoreDialog)
{
    ui->setupUi(this);
}

HighscoreDialog::~HighscoreDialog()
{
    delete ui;
}


void HighscoreDialog::setScore( QList<ScoreEntry> score )
{
    ui->tableWidget->clear();

    ui->tableWidget->setRowCount( score.length() );
    ui->tableWidget->setColumnCount( 2 );
    qDebug() << score;

    for ( int i=0; i < score.length(); i++ )
    {
        ScoreEntry e = score.at(i);
        QTableWidgetItem *itemName = new QTableWidgetItem(e.getName() );

        QTableWidgetItem *itemScore = new QTableWidgetItem(QString::number(e.getScore()));

        ui->tableWidget->setItem(i, 0, itemName );
        ui->tableWidget->setItem(i, 1, itemScore );
    }


}

