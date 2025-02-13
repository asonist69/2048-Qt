#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include <QDir>
#include <QVector>
#include <QPoint>
#include <QRandomGenerator>
#include <QShortcut>
#include <QKeySequence>
#include <QInputDialog>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int **grid;
    int maxNumber=2;
    int **previousGrid;
    int size;
    int previousMaxNumber;
    bool canUndo = false;

    enum class Direction {
        Up,
        Down,
        Left,
        Right
    };

    void updateUI(int **grid);
    void newGame();
    void saveGame();
    void loadGame();
    void addRandomTile();
    void checkGameOver();
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
    void move(Direction dir);
    void undoMove();
    void createField();
    void deleteField();
    void createPreviousField();
    void deletePreviousField();
    void resizeField(int size);

private slots:
    void on_newGame_triggered();
    void on_saveGame_triggered();
    void on_loadGame_triggered();
    void on_exitGame_triggered();
    void on_moveUpButton_clicked();
    void on_moveDownButton_clicked();
    void on_moveLeftButton_clicked();
    void on_moveRightButton_clicked();
    void on_help_triggered();
    void on_about_triggered();
    void on_undoButton_clicked();
    void on_showScores_triggered();
    void on_action3x3_triggered();
    void on_action4x4_triggered();
    void on_action5x5_triggered();
    void on_action6x6_triggered();
    void on_action7x7_triggered();
    void on_action8x8_triggered();
};

#endif
