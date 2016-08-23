#ifndef TODOLIST_H
#define TODOLIST_H

#include <QDialog>
#include <QDate>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QMap>

class TodoList : public QDialog
{
    Q_OBJECT
protected:
    QTableWidget *table;
    QVBoxLayout *mainLayout;
    QHBoxLayout *controllers;
    QHBoxLayout *okLayout;
public:
    const QDate date;
    explicit TodoList(const QDate &date, QWidget *parent = nullptr);
    ~TodoList();
public slots:
    void add();
    void del();
private:
    QMap<int, int> indexToID;
    void refreshTable();
};

#endif // TODOLIST_H
