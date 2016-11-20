//#include <functional>

#include <QMouseEvent>
#include <QTextStream>
#include <QGraphicsEllipseItem>

#include "MyGraphicsView.h"

#include <fractal.h>

namespace {

const MyGraphicsView* instance = 0;

extern "C"
int _between (index_t new_vx, index_t e1_vx, index_t e2_vx, index_t aux_vx) {
    return instance->between(new_vx, e1_vx, e2_vx, aux_vx) ? 1 : 0;
}

}

MyGraphicsView::MyGraphicsView (QGraphicsScene* scene, QWidget* parent) : QGraphicsView(scene, parent) {
    instance = this;
}

void MyGraphicsView::mouseDoubleClickEvent (QMouseEvent* event) {
    QPointF vertex = mapToScene(event->pos());
    scene()->addEllipse(vertex.x() - 3, vertex.y() - 3, 5, 5);
    if (!m_vertex.empty()) {
        scene()->addLine(m_vertex.last().x(),
                         m_vertex.last().y(),
                         vertex.x(),
                         vertex.y());
    }
    m_vertex.append(vertex);
}

void MyGraphicsView::keyReleaseEvent (QKeyEvent* event) {
    if (Qt::Key_Space == event->key()) {
        if (m_vertex.size() > 1) {
            scene()->addLine(m_vertex.last().x(),
                             m_vertex.last().y(),
                             m_vertex.first().x(),
                             m_vertex.first().y());
        }
        if (m_vertex.size() >= 3) {
            triangle_t* triangulation = new triangle_t[m_vertex.size() - 2];
            int result = fractal(m_vertex.size(), _between, triangulation);
//          int result = fractal(m_vertex.size(), std::bind(&MyGraphicsView::between, this), triangulation);
            if (result == 0) {
                for (int i = 0; i < m_vertex.size() - 2; ++i) {
                    const triangle_t& T = triangulation[i];
                    scene()->addLine(m_vertex[T.vx1].x(),
                                     m_vertex[T.vx1].y(),
                                     m_vertex[T.vx2].x(),
                                     m_vertex[T.vx2].y());
                    scene()->addLine(m_vertex[T.vx2].x(),
                                     m_vertex[T.vx2].y(),
                                     m_vertex[T.vx3].x(),
                                     m_vertex[T.vx3].y());
                    scene()->addLine(m_vertex[T.vx3].x(),
                                     m_vertex[T.vx3].y(),
                                     m_vertex[T.vx1].x(),
                                     m_vertex[T.vx1].y());
                }
            }
            else {
                QTextStream(stdout) << "Failed to triangulate\n";
            }
            delete[] triangulation;
        }
    }
}

bool MyGraphicsView::between (index_t new_vx, index_t e1_vx, index_t e2_vx, index_t aux_vx) const {
    qreal delta_x = m_vertex[e2_vx].x() - m_vertex[aux_vx].x();
    qreal delta_y = m_vertex[e2_vx].y() - m_vertex[aux_vx].y();
    qreal s1 = (m_vertex[new_vx].x() - m_vertex[e2_vx].x()) * delta_y -
               (m_vertex[new_vx].y() - m_vertex[e2_vx].y()) * delta_x;
    qreal s2 = (m_vertex[e1_vx].x() - m_vertex[e2_vx].x()) * delta_y -
               (m_vertex[e1_vx].y() - m_vertex[e2_vx].y()) * delta_x;
    return s1 * s2 <= 0;
}
