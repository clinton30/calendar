#ifndef STORAGE_H
#define STORAGE_H

#include "todoitem.h"
#include "fileinfo.h"

#include <QVector>
#include <QString>

class Storage
{
private:
    QVector<TodoItem> _items;
    static Storage *instance;
public:
    static const QString defaultFileName;
    Storage();
    static Storage *i();
    QVector<TodoItem> get(const QDate &date);
    int add(TodoItem item);
    void del(int id);
    TodoItem get(int id);
    void set(int id, const TodoItem &item);
    FileInfo putFile(const QString &source, const QDate &date);
    QVector<FileInfo> getFileList(const QDate &date);
    int getFileCount(const QDate &date);
    QString getFilePath(const QString &id);
    QByteArray getFileData(const QString &id);
    void delFile(const QString &id);
    void load();
    void save();
    void load(const QString &fileName);
    void save(const QString &fileName);
};

#endif // STORAGE_H
