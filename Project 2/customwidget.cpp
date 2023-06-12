#include "customwidget.h"

#include <QPainter>

CustomWidget::CustomWidget(QWidget* parent)
    : QWidget(parent)
{
}

void CustomWidget::paintEvent(QPaintEvent* /* event */)
{
    QPainter painter(this);
    painter.setBrush(Qt::GlobalColor::darkCyan);
    painter.drawRect(QRect(0, 0, this->width() - 1, this->height() - 1));
    painter.setBrush(QBrush(QColorConstants::Svg::yellow, Qt::SolidPattern));
    painter.setPen(QPen(Qt::yellow, 5, Qt::CustomDashLine));
    painter.drawEllipse(35,55,30, 30);
    painter.drawEllipse(119,50,15, 15);
    painter.drawEllipse(119,75,15, 15);
    painter.drawEllipse(105,62,15, 15);
    painter.drawEllipse(132,62,15, 15);
    painter.drawLine(20, 25, 165, 25);
    painter.drawLine(20, 25, 20, 110);
    painter.drawLine(20, 110, 165, 110);
    painter.drawLine(165, 110, 165, 25);

    //painter.drawArc(90, 35, 90, 145)
}
