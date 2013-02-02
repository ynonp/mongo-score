#include <QtCore>
#include "scorekeeper.h"

using namespace mongo;

ScoreKeeper::ScoreKeeper()
{
    m_conn.connect("ds031957.mongolab.com:31957");
    std::string err;
    m_conn.auth("demo", "ynon", "123456", err);
}

void ScoreKeeper::addHighScore(const ScoreEntry &e) {
    BSONObjBuilder b;
    b << "name" << e.getName().toStdString();
    b << "score" << e.getScore();

    m_conn.insert( "demo.highscore", b.obj());
}

void ScoreKeeper::addHighScore(QString name, int score) {
    this->addHighScore( ScoreEntry(name, score ) );
}

QList<ScoreEntry> ScoreKeeper::getTopScore() {
    auto_ptr<DBClientCursor> cursor = m_conn.query(
                "demo.highscore",
                Query(BSONObj()).sort("score", -1),
                10);
    QList<ScoreEntry> result;

    while ( cursor->more() )
    {
        BSONObj p = cursor->next();
        QString name  = p.getStringField("name");
        int     score = p.getIntField("score");
        result << ScoreEntry(name, score);
    }

    return result;
}
