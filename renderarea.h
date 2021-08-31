#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minSizeHint() const ;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid, FutureCurve};

    void setBackgroundColor (QColor color) {mBackgroundColor = color;} // setter
    QColor backgroundColor () const {return mBackgroundColor;} // getter

    void setShape ( ShapeType shape) // setter
    {
        mShape = shape;
        on_shape_changed();
    }
    ShapeType shape () const { return mShape; } // getter

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    QPointF compute (float t); // dispatch func based on mShape's type
    QPointF compute_astroid (float t);
    QPointF compute_cycloid (float t);
    QPointF compute_huygens (float t);
    QPointF compute_hypo (float t);
    QPointF compute_future_curve (float t);
    void on_shape_changed();
    float mIntervalLength;
    float mScale;
    int mStepCount;


signals:

};

#endif // RENDERAREA_H
