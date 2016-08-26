#include "dateitem.h"
#include "global.h"

#include <QPaintEvent>
#include <QPainter>
#include <QTextDocument>

DateItem::DateItem(QWidget *parent) : QWidget(parent)
{

}

void DateItem::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.fillRect(rect(), colorBackground);

    if (_enabled)
    {
        if (_date.dayOfWeek() >= 1 && _date.dayOfWeek() <= 5)
        {
            p.setPen(_colorWeekdayText);
        }
        else
        {
            p.setPen(_colorWeekendText);
        }
    }
    else
    {
        p.setPen(_colorDisabledText);
    }

    QFont f = p.font();
    // f.setPointSize(13);
    f.setBold(true);
    p.setFont(f);
    QString dayNumber = QString::number(_date.day());
    if (_selected && _enabled)
    {
        dayNumber = QString("[%1]").arg(dayNumber);
    }
    QRect txtRect;
    p.drawText(rect(), Qt::AlignTop | Qt::AlignLeft, dayNumber, &txtRect);

    p.save();
    p.translate(0, txtRect.height());
    QTextDocument doc;
    doc.setHtml(_text);
    doc.drawContents(&p);
    p.restore();

    if (_selected && _enabled)
    {
        p.fillRect(this->rect(), QColor::fromRgb(0, 0, 0, 100));
    }
}

void DateItem::mouseReleaseEvent(QMouseEvent *e)
{
    if (rect().contains(e->pos()))
    {
        emit clicked();
    }
    e->ignore();
}

void DateItem::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (_enabled)
    {
        emit doubleClicked();
    }
}

void DateItem::setColor(QColor color)
{
    this->_colorWeekdayText = color;
    update();
}

void DateItem::setText(QString text)
{
    this->_text = text;
    update();
}

void DateItem::setDate(QDate date)
{
    this->_date = date;
    update();
}

QColor DateItem::color()
{
    return _colorWeekdayText;
}

QString DateItem::text()
{
    return _text;
}

QDate DateItem::date()
{
    return _date;
}

void DateItem::setEnabled(bool enabled)
{
    this->_enabled = enabled;
    update();
}

bool DateItem::enabled()
{
    return _enabled;
}

bool DateItem::selected()
{
    return _selected;
}

void DateItem::setSelected(bool selected)
{
    _selected = selected;
    update();
}

void DateItem::setBackgroundColor(QColor color)
{
    this->colorBackground = color;
    this->_colorWeekdayText = Global::getTextColor(color);
}
