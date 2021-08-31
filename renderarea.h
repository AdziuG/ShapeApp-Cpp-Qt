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

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid, Circle, FutureCurve};

    void setBackgroundColor (QColor color) {mBackgroundColor = color;} // setter
    QColor backgroundColor () const {return mBackgroundColor;} // getter

    void setShapeColor(QColor color) {mShapeColor = color;} // setter
    QColor shapeColor() const {return mShapeColor;} // getter


    void setShape ( ShapeType shape) // setter
    {
        mShape = shape;
        on_shape_changed();
    }
    ShapeType shape () const { return mShape; } // getter


    void setScale(float scale)  // setter
    {
        mScale = scale;
        repaint();
    }
    float scale() const {return mScale;}  // getter


    void setIntervalLength(float interval_length)  // setter
    {
        mIntervalLength = interval_length;
        repaint();
    }
    float intervalLength() const {return mIntervalLength;}  // getter


    void setStepCount(int spinCount) // setter
    {
        mStepCount = spinCount;
        repaint();
    }
    int step_count() const {return mStepCount;}   // getter


protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void on_shape_changed();
    QPointF compute (float t); // dispatch func based on mShape's type
    QPointF compute_astroid (float t);
    QPointF compute_cycloid (float t);
    QPointF compute_huygens (float t);
    QPointF compute_hypo (float t);
    QPointF compute_circle(float t);
    QPointF compute_future_curve (float t);
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    float mIntervalLength;
    float mScale;
    int mStepCount;

signals:

};

#endif // RENDERAREA_H
