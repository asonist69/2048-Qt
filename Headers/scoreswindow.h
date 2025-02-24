#ifndef SCORESWINDOW_H
#define SCORESWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QFile>
#include <QDataStream>
#include <QVBoxLayout>
#include <QHeaderView>
#include <QPushButton>

class ScoresWindow : public QDialog {
    Q_OBJECT

public:
    explicit ScoresWindow(QWidget *parent = nullptr);
    ~ScoresWindow();

    void loadScores();
    void saveScores();
    void addScore(const QString &name, int score);
    void removeSelectedScore();

private:
    QTableWidget *table;
    QString scoresFile;
};

#endif
