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

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid};

    void setBackgroundColor (QColor color) {mBackgroundColor = color;} // setter
    QColor backgroundColor () const {return mBackgroundColor;} // getter

    void setShape ( ShapeType shape); // setter
    ShapeType shape () const { return mShape; } // getter

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;



signals:

};

#endif // RENDERAREA_H