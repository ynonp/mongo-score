#ifndef HIGHSCOREDIALOG_H
#define HIGHSCOREDIALOG_H

#include <QDialog>
#include "scoreentry.h"
#include <QtGui>

namespace Ui {
class HighscoreDialog;
}

class HighscoreDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit HighscoreDialog(QWidget *parent = 0);
    ~HighscoreDialog();

    void setScore( QList<ScoreEntry> score );

private:
    Ui::HighscoreDialog *ui;
};

#endif // HIGHSCOREDIALOG_H
