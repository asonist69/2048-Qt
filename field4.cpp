#include "field4.h"
#include "ui_field4.h"
#include <QDebug>
field4::field4(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::field4)
{
    ui->setupUi(this);
}

field4::~field4()
{
    delete ui;
}

void field4::setLabels(int **grid, int size) {

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int value = grid[i][j];
            tiles[i][j]->setText(value == 0 ? "" : QString::number(value));

            QString style = QString("background: %1; border: 2px solid gray; font-size: 28px; color: black;")
                                .arg(value == 0 ? colorMap[0] : colorMap[qCeil(qLn(value) / qLn(2))]);

            tiles[i][j]->setStyleSheet(style);
        }
    }
}

void field4::createTiles(int size) {
    int tileSize=this->width()/size;
    tiles = new QLabel**[size];
    for (int i=0; i < size; ++i) {
        tiles[i]= new QLabel*[size];
        for (int j=0; j<size; j++) {
            tiles[i][j]=new QLabel(this);
            tiles[i][j]->setGeometry(j*tileSize,i*tileSize,tileSize,tileSize);
            tiles[i][j]->setAlignment(Qt::AlignCenter);
            tiles[i][j]->show();
        }
    }
}

void field4::deleteTiles(int size) {
    for (int i=0; i < size; ++i) {
        for (int j=0; j<size; j++) {
            delete tiles[i][j];
        }
        delete [] tiles[i];
    }
    delete [] tiles;
}
