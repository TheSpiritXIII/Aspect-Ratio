#include "widget.h"
#include <QPainter>
#include <QResizeEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: green");
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
    sizePolicy.setHeightForWidth(true);
    setSizePolicy(sizePolicy);
}

QSize Widget::sizeHint() const
{
    int heightHint = width() * (1/1.33f);

    return QSize(QWidget::sizeHint().width(), heightHint);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setBrush(Qt::green);
    painter.drawRect(rect());
}

void Widget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    updateGeometry();
}
