#include "renderarea.h"
#include <QPainter>
#include <QColor>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0, 0, 255),
    mShapeColor (255, 255, 255)
{

}

QSize RenderArea::minSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::setShape(ShapeType shape) { mShape = shape; }

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    switch (mShape) {
    case Astroid:
        mBackgroundColor = Qt::red;
        break;
    case Cycloid:
        mBackgroundColor = Qt::green;
        break;
    case HuygensCycloid:
        mBackgroundColor = Qt::blue;
        break;
    case HypoCycloid:
        mBackgroundColor = Qt::yellow;
        break;
    default:
        mBackgroundColor = Qt::black;

    }
    painter.setPen(mShapeColor);
    painter.setBrush(mBackgroundColor);


    // draws area
    painter.drawRect(this->rect());
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());
}
