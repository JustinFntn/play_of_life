#include "GraphicScene.h"

void GraphicScene::mousePressEvent(QGraphicsSceneMouseEvent* mouseEvent) {
    emit sceneClicked(mouseEvent);
}