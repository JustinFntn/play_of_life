#ifndef GRAPHICSCENE_H
#define GRAPHICSCENE_H
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class GraphicScene : public QGraphicsScene {
    Q_OBJECT
signals:
    void sceneClicked(QGraphicsSceneMouseEvent* mouseEvent);

public:
    GraphicScene(QObject* parent = nullptr) : QGraphicsScene(parent) {}
    void mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) override;
};

#endif // GRAPHICSCENE_H