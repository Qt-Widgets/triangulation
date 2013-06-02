#include <QApplication>
#include <QGraphicsScene>
#include <QPolygonF>

#include "MyGraphicsView.h"

int main (int argc, char* argv[]) {
    QApplication app(argc, argv);

    QGraphicsScene scene;
    MyGraphicsView view(&scene);
    view.show();

    return app.exec();
}
