#ifndef _MYGRAPHICSVIEW_H
#define _MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QVector>
#include <QPointF>

#include <fractal_types.h>

class MyGraphicsView : public QGraphicsView {
Q_OBJECT
    QVector<QPointF> m_vertex;
public:
    MyGraphicsView (QGraphicsScene* scene, QWidget* parent = 0);
protected:
    virtual void mouseDoubleClickEvent (QMouseEvent* event);
    virtual void keyReleaseEvent (QKeyEvent* event);
public:
    bool between (index_t, index_t, index_t, index_t) const;
};

#endif
