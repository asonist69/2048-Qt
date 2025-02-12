#include "field.h"
#include "ui_field.h"

field::field(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::field)
{
    ui->setupUi(this);
}

field::~field()
{
    delete ui;
}

/*void field::setLabels(const int **grid) {
    auto tiles = new QLabel*[][] {
        {ui->tile_0_0, ui->tile_0_1, ui->tile_0_2, ui->tile_0_3},
        {ui->tile_1_0, ui->tile_1_1, ui->tile_1_2, ui->tile_1_3},
        {ui->tile_2_0, ui->tile_2_1, ui->tile_2_2, ui->tile_2_3},
        {ui->tile_3_0, ui->tile_3_1, ui->tile_3_2, ui->tile_3_3} };

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int value = grid[i][j];
            tiles[i][j]->setText(value == 0 ? "" : QString::number(value));

            QString style = QString("background: %1; border: 2px solid gray; font-size: 20px; color: black;")
                                .arg(value == 0 ? colorMap[0] : colorMap[qCeil(qLn(value) / qLn(2))]);

            tiles[i][j]->setStyleSheet(style);
        }
    }
}
*/
