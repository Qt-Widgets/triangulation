#include <QMouseEvent>
#include <QTextStream>
#include <QGraphicsEllipseItem>

#include "MyGraphicsView.h"

void MyGraphicsView::mouseDoubleClickEvent (QMouseEvent* event) {
    QTextStream(stdout) << "event->pos() = {" << event->pos().x() << ", " << event->pos().y() << "}\n";
    QTextStream(stdout) << "event->posF() = {" << event->posF().x() << ", " << event->posF().y() << "}\n";
    QTextStream(stdout) << "event->globalPos() = {" << event->globalPos().x() << ", " << event->globalPos().y() << "}\n";
    QPointF vertex = event->posF();
//  QPointF vertex = event->globalPos();
    m_vertex.append(vertex);
    QGraphicsEllipseItem* ellipse = scene()->addEllipse(vertex.x() - 3, vertex.y() - 3, 5, 5);
//  QGraphicsEllipseItem* ellipse = scene()->addEllipse(event->x() - 3, event->y() - 3, 5, 5);
    QTextStream(stdout) << "ellipse->rect() = {" << ellipse->rect().x() << ", " << ellipse->rect().y() << "}\n";
}
