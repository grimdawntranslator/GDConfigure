#ifndef JOB_H
#define JOB_H

#include <QtCore>
#include <QProcess>

typedef enum JobType {
    JobExtract = 0,
    JobPackage,
} JobType;

class Job : public QProcess
{
    Q_OBJECT

    QString _name;
    JobType _type;

public:
    Job(JobType type, const QString &name, QObject *parent = nullptr) : QProcess(parent) { _type = type; _name = name; }
    ~Job() { _name.clear(); }

    const QString& name() const { return _name; }
    JobType type() const { return _type; }
};

#endif // JOB_H
