#include <QtCore>
#include "scorekeeper.h"

ScoreKeeper::ScoreKeeper()
{
}

void ScoreKeeper::addHighScore(const ScoreEntry &e) {
    m_highScore.append( e );
}

void ScoreKeeper::addHighScore(QString name, int score) {
    m_highScore.append( ScoreEntry(name, score ) );
}

QList<ScoreEntry> ScoreKeeper::getTopScore() {
    return m_highScore;
}
