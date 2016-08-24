#ifndef NEWTODO_H
#define NEWTODO_H

#include "todoitem.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include<QPushButton>

class TodoEdit : public QDialog
{
    Q_OBJECT
protected:
    TodoItem _item;
    QVBoxLayout *mainLayout;
    QHBoxLayout *boxLayout;
    QHBoxLayout *textboxLayout;
    QHBoxLayout *okLayout;
    QComboBox *yearBox, *monthBox, *dayBox, *dayOfWeekBox;
    QLabel *labText;
    QPushButton *btnColor;
    QLineEdit *text;

public:
    explicit TodoEdit(QWidget *parent = 0);
    TodoItem item();
signals:

public slots:
    void setYearByIndex(int);
    void setMonthByIndex(int);
    void setDayByIndex(int);
    void setDayOfWeekByIndex(int);
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    void setDayOfWeek(int);
    void setItem(TodoItem);
    void ok();
    void setColor();
private:
    bool _warningShowed = false;
    void initControllers();
    void updateDays();
    void updateColor();
};

#endif // NEWTODO_H
