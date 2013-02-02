#include <QtCore>
#include "scoreentry.h"

ScoreEntry::ScoreEntry(QString name, int score):
    m_name( name ),
    m_score ( score )
{
}

ScoreEntry::ScoreEntry()
{
}

QString ScoreEntry::getName() const {
    return m_name;
}

int ScoreEntry::getScore() const {
    return m_score;
}

bool operator<(const ScoreEntry &e1, const ScoreEntry &e2)
{
    return e1.getScore() > e2.getScore();
}

QDebug operator<<(QDebug d, const ScoreEntry &entry)
{
    d << entry.getName() << entry.getScore();
    return d;
}

const ScoreEntry &ScoreEntry::operator=(const ScoreEntry &other)
{
    this->m_name = other.getName();
    this->m_score = other.getScore();
    return *this;
}

