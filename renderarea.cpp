#include "renderarea.h"
#include <QPainter>
#include <QColor>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0, 0, 0),
    mShapeColor (255, 255, 255)
{
    on_shape_changed();
}

QPointF RenderArea::compute_astroid(float t)
{
    float cos_t = cos (t);
    float sin_t = sin (t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF (x, y);
}

QPointF RenderArea::compute_cycloid(float t)
{
    return QPointF(
                1.5 * (1 - cos(t)),  // x
                1.5 * (t - sin(t))   // y
                );
}

QPointF RenderArea::compute_huygens(float t)
{
    return QPointF(
                4*(3 * cos(t) - cos(3 * t)),  // x
                4*(3 * sin(t) - sin(3 * t))   // y
                );
}


QPointF RenderArea::compute_hypo(float t)
{
    return QPointF(
                1.5 * (2 * cos(t) + cos (2*t)),  // x
                1.5 * (2 * sin(t) - sin (2*t))  // y
                );
}

QPointF RenderArea::compute_circle(float t)
{
    return QPointF(
                cos(t),  // x
                sin(t)  // y
                );
}


QPointF RenderArea::compute_future_curve(float t)
{
    //TDB
}


void RenderArea::on_shape_changed()
{
    switch (mShape)
    {
    case Astroid:
        mScale = 90;
        mIntervalLength = 2 * M_PI;
        mStepCount = 512;
        break;
    case Cycloid:
        mScale = 10;
        mIntervalLength = 4 * M_PI;
        mStepCount = 256;
        break;
    case HuygensCycloid:
        mScale = 4;
        mIntervalLength = 4 * M_PI;
        mStepCount = 512;
        break;
    case HypoCycloid:
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 512;
        break;
    case Circle:
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 128;
        break;
    case FutureCurve:
        break;
    default:
        break;
    }
}

QPointF RenderArea::compute(float t)
{
    switch (mShape)
    {
    case Astroid:
        return compute_astroid(t);
        break;
    case Cycloid:
        return compute_cycloid(t);
        break;
    case HuygensCycloid:
        return compute_huygens(t);
        break;
    case HypoCycloid:
        return compute_hypo(t);
        break;
    case Circle:
        return compute_circle(t);
        break;
    case FutureCurve:
        return compute_future_curve(t);
    default:
        break;
    }
    return QPoint (0,0);
}

QSize RenderArea::minSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(mShapeColor);
    painter.setBrush(mBackgroundColor);


    // draws area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();

    QPointF prevPoint = compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());

    float step = mIntervalLength / mStepCount;
    for (float t = 0; t < mIntervalLength; t += step)
    {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

        painter.drawLine(pixel, prevPixel);
        prevPixel = pixel;
    }
}
