#ifndef _MYGRAPHICSVIEW_H
#define _MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QVector>
#include <QPointF>

class MyGraphicsView : public QGraphicsView {
Q_OBJECT
    QVector<QPointF> m_vertex;
public:
    MyGraphicsView (QGraphicsScene* scene, QWidget* parent = 0) : QGraphicsView(scene, parent) {
    }
protected:
    virtual void mouseDoubleClickEvent (QMouseEvent* event);
};

#endif
