#include <QMouseEvent>
#include <QTextStream>
#include <QGraphicsEllipseItem>

#include "MyGraphicsView.h"

void MyGraphicsView::mouseDoubleClickEvent (QMouseEvent* event) {
    QPointF vertex = mapToScene(event->pos());
    m_vertex.append(vertex);
    scene()->addEllipse(vertex.x() - 3, vertex.y() - 3, 5, 5);
}
