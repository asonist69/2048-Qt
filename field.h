#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class field;
}

class field : public QWidget
{
    Q_OBJECT


    const QString colorMap[12] {
        "lightgrey", "white", "cornsilk", "sandybrown", "coral", "orangered",
        "red", "khaki", "darkkhaki", "goldenrod", "gold", "yellow"
    };

public:
    explicit field(QWidget *parent = nullptr);
    ~field();

    void setLabels(const int **grid);

private:
    Ui::field *ui;
};

#endif
