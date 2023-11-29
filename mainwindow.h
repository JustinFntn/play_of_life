#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsRectItem>
#include <QTimer>

#include "GraphicScene.h"
#include "Plateau.h"


class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void changeColor(QGraphicsRectItem* rect);
    void updateBoard();
    void onSceneClicked(QGraphicsSceneMouseEvent* event);
    void playClicked();
    void pauseClicked();
    void resetClicked();

private:
    int cellSize;
    Plateau plateau;
    GraphicScene* scene;
    QTimer* timer;
};

#endif // MAINWINDOW_H