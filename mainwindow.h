#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scorekeeper.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool eventFilter( QObject *obj, QEvent *ev );

private slots:
    void startRound();
    void winRound();
    void looseRound();
    void startGame();
    void showHighScore();

private:
    Ui::MainWindow *ui;
    QList<QWidget *> squares;
    int winnerIdx;
    int score;
    bool playing;
    ScoreKeeper scoreKeeper;
};

#endif // MAINWINDOW_H
