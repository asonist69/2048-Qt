#include "scoreswindow.h"

ScoresWindow::ScoresWindow(QWidget *parent) : QDialog(parent), scoresFile("scores.dat") {
    setWindowTitle("Таблица результатов");
    resize(400, 300);

    table = new QTableWidget(0, 2, this);
    table->setHorizontalHeaderLabels({"Имя", "Очки"});
    table->horizontalHeader()->setStretchLastSection(true);
    table->verticalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);

    QPushButton *deleteButton = new QPushButton("Удалить запись", this);
    connect(deleteButton, &QPushButton::clicked, this, &ScoresWindow::removeSelectedScore);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(table);
    layout->addWidget(deleteButton);

    loadScores();
}

ScoresWindow::~ScoresWindow() {
    saveScores();
}

void ScoresWindow::loadScores() {
    QFile file(scoresFile);
    if (!file.open(QIODevice::ReadOnly)) return;

    QDataStream in(&file);
    table->setRowCount(0);

    while (!in.atEnd()) {
        QString name;
        int score;
        in >> name >> score;

        int row = table->rowCount();
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(name));
        table->setItem(row, 1, new QTableWidgetItem(QString::number(score)));
    }
    file.close();
}

void ScoresWindow::saveScores() {
    QFile file(scoresFile);
    if (!file.open(QIODevice::WriteOnly)) return;

    QDataStream out(&file);
    for (int i = 0; i < table->rowCount(); ++i) {
        QString name = table->item(i, 0)->text();
        int score = table->item(i, 1)->text().toInt();
        out << name << score;
    }
    file.close();
}

void ScoresWindow::addScore(const QString &name, int score) {
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(name));
    table->setItem(row, 1, new QTableWidgetItem(QString::number(score)));

    while (table->rowCount() > 10) {
        table->removeRow(0);
    }

    saveScores();
}

void ScoresWindow::removeSelectedScore() {
    int row = table->currentRow();
    if (row >= 0) {
        table->removeRow(row);
        saveScores();
    }
}

