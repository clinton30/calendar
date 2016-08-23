#ifndef TODOITEM_H
#define TODOITEM_H

#include <QDate>
#include <QString>
#include <QObject>
#include <QColor>

class TodoItem
{
public:
    // -1 means to match all
    int id = 0;
    int year, month, day, dayOfWeek = -1;
    QString thing;
    QColor color = Qt::GlobalColor::white;
    TodoItem();
    bool match(const QDate &) const;
    QString matchToString() const;
    ~TodoItem();
};

#endif // TODOITEM_H
