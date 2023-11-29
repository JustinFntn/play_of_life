#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include "GraphicScene.h"


MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent) {
    resize(1000, 600);
    setWindowTitle("Jeu de la vie");

    this->scene = new GraphicScene(this);
    this->cellSize = 20;
    this->timer = new QTimer(this);
    connect(this->timer, &QTimer::timeout, this, &MainWindow::updateBoard);

    QHBoxLayout* mainLayout = new QHBoxLayout(this); // layout principal
    QVBoxLayout* jeu = new QVBoxLayout(); // layout pour le jeu
    QVBoxLayout* option = new QVBoxLayout(); // layout pour les options

    // les options
    QLabel* cellSizeLabel = new QLabel("Cliquez sur les cases pour les colorer en rouge ");
    QPushButton* playButton = new QPushButton("Play");
    QPushButton* pauseButton = new QPushButton("Pause");
    QPushButton* resetButton = new QPushButton("Reset");
    QPushButton* iter = new QPushButton("itération suivante");
    connect(playButton, &QPushButton::clicked, this, &MainWindow::playClicked);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::pauseClicked);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetClicked);
    connect(iter, &QPushButton::clicked, this, &MainWindow::updateBoard);

    // option d'affichage pour les layouts
    option->setAlignment(Qt::AlignTop);

    // ajout des options au layout
    option->addWidget(cellSizeLabel);
    // option->addWidget(cellSizeEdit);
    option->addWidget(playButton);
    option->addWidget(pauseButton);
    option->addWidget(resetButton);
    option->addWidget(iter);

    // scene pour le plateau de jeu
    QGraphicsView* view = new QGraphicsView(this->scene);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    jeu->addWidget(view);

    // ##ajout de la grille au plateau de jeu##
    // Obtenir la taille de la vue
    QSize viewSize = view->size();
    int minSide = viewSize.width() < viewSize.height() ? viewSize.width() : viewSize.height();
    // Calcul du nombre de lignes et de colonnes en fonction de la taille de la vue
    int rows = minSide / cellSize;
    int cols = minSide / cellSize;
    this->plateau = Plateau(rows, cols);
    std::cout << "rows: " << rows << " cols: " << cols << std::endl;

    // Création du quadrillage avec des cases blanches
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            QGraphicsRectItem* rect = this->scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize, QPen(Qt::black), QBrush(Qt::white));
            rect->setAcceptedMouseButtons(Qt::AllButtons);
            rect->setData(0, QVariant(false)); // Utilisation de la propriété pour définir l'état de la case (noir/blanc)
            rect->setData(1, QVariant(i)); // Utilisation de la propriété pour définir la ligne de la case
            rect->setData(2, QVariant(j)); // Utilisation de la propriété pour définir la colonne de la case
        }
    }

    // connecté le clic sur une case à la fonction changeColor
    connect(this->scene, &GraphicScene::sceneClicked, this, &MainWindow::onSceneClicked);

    // ajout des layouts au layout principal
    mainLayout->addLayout(jeu, 2);
    mainLayout->addLayout(option, 1);
}

void MainWindow::changeColor(QGraphicsRectItem* item) {
    bool state = item->data(0).toBool();
    if (state) {
        item->setBrush(QBrush(Qt::red));
    }
    else {
        item->setBrush(QBrush(Qt::white));
    }
}

void MainWindow::updateBoard() {
    this->plateau.updateBoard();
    int* size = this->plateau.getSize();
    int size_x = size[0], size_y = size[1];
    delete[] size;
    for (int i = 0; i < size_x; ++i) {
        for (int j = 0; j < size_y; ++j) {
            QGraphicsItem* item = this->scene->itemAt(j * cellSize, i * cellSize, QTransform());
            QGraphicsRectItem* rect = qgraphicsitem_cast<QGraphicsRectItem*>(item);
            rect->setData(0, QVariant(this->plateau.getBoard()[i][j].getState()));
            changeColor(rect);
        }
    }
}

void MainWindow::onSceneClicked(QGraphicsSceneMouseEvent* event) {
    // Obtenez l'élément cliqué dans la scène à partir de la position du clic
    QGraphicsItem* item = this->scene->itemAt(event->scenePos(), QTransform());
    QGraphicsRectItem* rect = qgraphicsitem_cast<QGraphicsRectItem*>(item);
    if (rect) {
        bool state = rect->data(0).toBool();
        rect->setData(0, QVariant(!state));
        this->plateau.setCellState(rect->data(1).toInt(), rect->data(2).toInt());
        changeColor(rect);
    }
}

void MainWindow::playClicked() {
    this->timer->start(500);
}

void MainWindow::pauseClicked() {
    this->timer->stop();
}

void MainWindow::resetClicked() {
    this->timer->stop();
    this->plateau = Plateau(this->plateau.getSize()[0], this->plateau.getSize()[1]);
    this->updateBoard();
}

MainWindow::~MainWindow() {
}