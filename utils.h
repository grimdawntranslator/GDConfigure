#ifndef UTILS_H
#define UTILS_H

#include <QString>

#define MAX(x,y) (x>y?x:y)
#define MIN(x,y) (x>y?y:x)

inline QString Strip(const QString &str, const QString &strip="\"")
{
    QString _str = str.trimmed();
    if (str.startsWith(strip))
        _str.remove(0, 1);
    if (str.endsWith(strip))
        _str.chop(1);

    return _str;
}

#endif // UTILS_H
