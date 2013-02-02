#ifndef SCOREENTRY_H
#define SCOREENTRY_H
class QString;

class ScoreEntry
{
public:
    ScoreEntry();
    ScoreEntry(QString name, int score);

    QString getName() const;
    int getScore() const;

    friend bool operator<(const ScoreEntry &e1, const ScoreEntry &e2);
    const ScoreEntry &operator=(const ScoreEntry &other);

private:
    QString m_name;
    int     m_score;
};

// debug friendly
QDebug operator<<(QDebug d, const ScoreEntry &entry);

#endif // SCOREENTRY_H
