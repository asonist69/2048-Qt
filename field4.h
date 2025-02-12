#ifndef FIELD4_H
#define FIELD4_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class field4;
}

class field4 : public QWidget
{
    Q_OBJECT


    const QString colorMap[12] {
        "lightgrey", "white", "cornsilk", "sandybrown", "coral", "orangered",
        "red", "khaki", "darkkhaki", "goldenrod", "gold", "yellow"
    };

public:
    explicit field4(QWidget *parent = nullptr);
    ~field4();

    void setLabels(int **grid, int size);

    void createTiles(int size);
    void deleteTiles(int size);

private:
    Ui::field4 *ui;
    QLabel*** tiles;
};

#endif
