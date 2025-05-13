#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../Headers/scoreswindow.h"
#include "../Headers/field.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),grid(NULL),previousGrid(NULL),size(4) {
    this->show();
    ui->setupUi(this);
    ui->widget=new field(this);
    ui->widget->move(13,25);
    static_cast<field*>(ui->widget)->createTiles(size);
    this->setWindowTitle(tr("2048"));
    this->setWindowIcon(QIcon(":/Images/2048.bmp"));
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
    newGame();

    new QShortcut(QKeySequence(Qt::Key_Up), this, SLOT(on_moveUpButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Down), this, SLOT(on_moveDownButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Left), this, SLOT(on_moveLeftButton_clicked()));
    new QShortcut(QKeySequence(Qt::Key_Right), this, SLOT(on_moveRightButton_clicked()));
    new QShortcut(QKeySequence("Ctrl+Z"), this, SLOT(on_undoButton_clicked()));
}

MainWindow::~MainWindow() {
    if (grid!=NULL) {
        deleteField();
    }
    if (previousGrid!=NULL) {
        deletePreviousField();
    }
    static_cast<field*>(ui->widget)->deleteTiles(size);
    delete ui;
}

enum class Direction {
    Up,
    Down,
    Left,
    Right
};

void MainWindow::updateUI(int **grid) {
    static_cast<field*>(ui->widget)->setLabels(grid,size);
}

void MainWindow::createField() {
    grid=new int*[size];
    for (int i=0;i<size;++i) {
        grid[i]=new int[size]{};
    }
}

void MainWindow::deleteField() {
    for (int i=0;i<size;++i) {
        delete[] grid[i];
        grid[i]=NULL;
    }
    delete []grid;
    grid=NULL;
}

void MainWindow::createPreviousField() {
    previousGrid=new int*[size];
    for (int i=0;i<size;++i) {
        previousGrid[i]=new int[size]{};
    }
}

void MainWindow::deletePreviousField() {
    for (int i=0;i<size;++i) {
        delete[] previousGrid[i];
        previousGrid[i]=NULL;
    }
    delete []previousGrid;
    previousGrid=NULL;
}

void MainWindow::newGame() {
    if (grid!=NULL) {
        deleteField();
    }
    if (previousGrid!=NULL) {
        deletePreviousField();
    }

    createField();
    createPreviousField();
    maxNumber=2;
    addRandomTile();
    addRandomTile();
    ui->widget->show();

    updateUI(grid);
}

void MainWindow::saveGame() {
    QString saveDir = QDir::currentPath() + "/saves";
    QDir dir(saveDir);
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QString fileName = saveDir + "/game.qt2048";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out << size;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                out << grid[i][j];
            }
        }
        out << gameOver;
        out <<  canUndo;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                out << previousGrid[i][j];
            }
         }
        file.close();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось сохранить игру."));
    }
}

void MainWindow::loadGame() {
    QString saveDir = QDir::currentPath() + "/saves";
    QDir dir(saveDir);
    if (!dir.exists()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Папка saves не существует."));
        return;
    }

    QStringList fileNames = dir.entryList(QStringList() << "game.qt2048", QDir::Files);
    if (fileNames.isEmpty()) {
        QMessageBox::warning(this, tr("Ошибка"), tr("Нет сохраненной игры."));
        return;
    }

    QString fileName = saveDir + "/game.qt2048";
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        maxNumber=2;

        int tmp_size;
        bool tmp_canUndo;
        bool tmp_gameOver;
        int **tmp_grid, **tmp_previousGrid;

        try {
            loadSave(file, tmp_grid, tmp_previousGrid, tmp_size, tmp_gameOver, tmp_canUndo);
        } catch(...) {
            QMessageBox::warning(this, tr("Ошибка"), tr("Файл сохранения повреждён"));
            file.close();
            return;
        }
        file.close();
        static_cast<field*>(ui->widget)->deleteTiles(this->size);

        deleteField();
        deletePreviousField();

        this -> size = tmp_size;
        this -> gameOver = tmp_gameOver;
        this -> canUndo = tmp_canUndo;

        createFieldFromSave(tmp_grid, tmp_previousGrid, tmp_size);

        static_cast<field*>(ui->widget)->createTiles(size);

        updateUI(grid);
        ui->maxNumberLabel->setText(QString("%1").arg(maxNumber));
        checkGameOver();
    } else {
        QMessageBox::warning(this, tr("Ошибка"), tr("Не удалось загрузить игру."));
    }
}

void MainWindow::loadSave(QFile &file, int **&grid, int **&previousGrid, int &size, bool &gameOver, bool &canUndo) {
    QDataStream in(&file);
    in >> size;
    grid=new int*[size];
    for (int i = 0; i < size; ++i) {
        grid[i]=new int[size];
        for (int j = 0; j < size; ++j) {
            in >> grid[i][j];
            if (grid[i][j] > maxNumber) {
                maxNumber = grid[i][j];
            }
        }
    }
    in >> gameOver;
    in >>  canUndo;
    previousGrid=new int*[size];
    for (int i = 0; i < size; ++i) {
        previousGrid[i]=new int[size];
        for (int j = 0; j < size; ++j) {
            in >> previousGrid[i][j];
        }
    }
}

void MainWindow::createFieldFromSave(int **&grid, int **&previousGrid, int &size) {
    this->grid=new int*[size];
    this->previousGrid=new int*[size];

    for (int i = 0; i < size; ++i) {
        this->grid[i]=new int[size];
        this->previousGrid[i]=new int[size];
        for (int j = 0; j < size; ++j) {
            this->grid[i][j] = grid[i][j];
            this->previousGrid[i][j] = previousGrid[i][j];
        }
        delete [] grid[i];
        delete [] previousGrid[i];
        grid[i]=NULL;
        previousGrid[i]=NULL;
    }
    delete [] grid;
    delete [] previousGrid;
    grid=NULL;
    previousGrid=NULL;
}

bool MainWindow::moveUp() {
    bool moved = false;

    for (int col = 0; col < size; ++col) {
        int previousMerged = -1;
        for (int row = 1; row < size; ++row) {
            if (grid[row][col] == 0) continue;

            int targetRow = row;
            while (targetRow > 0 && grid[targetRow - 1][col] == 0) {
                --targetRow;
            }

            if (targetRow > 0 && grid[targetRow - 1][col] == grid[row][col] && targetRow - 1 != previousMerged) {
                grid[targetRow - 1][col] *= 2;
                grid[row][col] = 0;
                moved = true;
                previousMerged = targetRow - 1;

                if (grid[targetRow - 1][col] > maxNumber) {
                    maxNumber = grid[targetRow - 1][col];
                    ui->maxNumberLabel->setText(QString("%1").arg(maxNumber));
                }
            } else if (targetRow != row) {
                std::swap(grid[row][col], grid[targetRow][col]);
                moved = true;
            }
        }
    }
    return moved;
}


bool MainWindow::moveDown() {
    bool moved = false;

    for (int col = 0; col < size; ++col) {
        int previousMerged = size;
        for (int row = size-2; row >= 0; --row) {
            if (grid[row][col] == 0) continue;

            int targetRow = row;
            while (targetRow < size-1 && grid[targetRow + 1][col] == 0) {
                ++targetRow;
            }

            if (targetRow < size-1 && grid[targetRow + 1][col] == grid[row][col] && targetRow + 1 != previousMerged) {
                grid[targetRow + 1][col] *= 2;
                grid[row][col] = 0;
                moved = true;
                previousMerged = targetRow + 1;

                if (grid[targetRow + 1][col] > maxNumber) {
                    maxNumber = grid[targetRow + 1][col];
                    ui->maxNumberLabel->setText(QString("%1").arg(maxNumber));
                }
            } else if (targetRow != row) {
                std::swap(grid[row][col], grid[targetRow][col]);
                moved = true;
            }
        }
    }
    return moved;
}

bool MainWindow::moveLeft() {
    bool moved = false;

    for (int row = 0; row < size; ++row) {
        int previousMerged = -1;
        for (int col = 1; col < size; ++col) {
            if (grid[row][col] == 0) continue;

            int targetCol = col;
            while (targetCol > 0 && grid[row][targetCol - 1] == 0) {
                --targetCol;
            }

            if (targetCol > 0 && grid[row][targetCol - 1] == grid[row][col] && targetCol - 1 != previousMerged) {
                grid[row][targetCol - 1] *= 2;
                grid[row][col] = 0;
                moved = true;
                previousMerged = targetCol - 1;

                if (grid[row][targetCol - 1] > maxNumber) {
                    maxNumber = grid[row][targetCol - 1];
                    ui->maxNumberLabel->setText(QString("%1").arg(maxNumber));
                }
            } else if (targetCol != col) {
                std::swap(grid[row][col], grid[row][targetCol]);
                moved = true;
            }
        }
    }
    return moved;
}


bool MainWindow::moveRight() {
    bool moved = false;

    for (int row = 0; row < size; ++row) {
        int previousMerged = size;
        for (int col = size-2; col >= 0; --col) {
            if (grid[row][col] == 0) continue;

            int targetCol = col;
            while (targetCol < size-1 && grid[row][targetCol + 1] == 0) {
                ++targetCol;
            }

            if (targetCol < size-1 && grid[row][targetCol + 1] == grid[row][col] && targetCol + 1 != previousMerged) {
                grid[row][targetCol + 1] *= 2;
                grid[row][col] = 0;
                moved = true;
                previousMerged = targetCol + 1;

                if (grid[row][targetCol + 1] > maxNumber) {
                    maxNumber = grid[row][targetCol + 1];
                    ui->maxNumberLabel->setText(QString("%1").arg(maxNumber));
                }
            } else if (targetCol != col) {
                std::swap(grid[row][col], grid[row][targetCol]);
                moved = true;
            }
        }
    }
    return moved;
}


void MainWindow::addRandomTile() {
    QVector<QPoint> emptyCells;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (grid[i][j] == 0) {
                emptyCells.append(QPoint(i, j));
            }
        }
    }

    if (!emptyCells.isEmpty()) {
        int randIndex = QRandomGenerator::global()->bounded(static_cast<int>(emptyCells.size()));
        QPoint cell = emptyCells[randIndex];
        bool tmp=QRandomGenerator::global()->bounded(10) == 0;
        grid[cell.x()][cell.y()] = (tmp) ? 4 : 2;
        if (tmp && maxNumber<4) {
            maxNumber=4;
        }
        ui->maxNumberLabel->setText(QString("%1").arg(maxNumber));
    }
}

void MainWindow::checkGameOver() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 2048) {
                QMessageBox msgBox;
                msgBox.setWindowTitle(tr("Поздравляем!"));
                msgBox.setText(tr("Вы достигли 2048! Что хотите сделать?"));
                QPushButton *newGameButton = msgBox.addButton(tr("Новая игра"), QMessageBox::YesRole);
                QPushButton *continueGameButton = msgBox.addButton(tr("Продолжить"), QMessageBox::ActionRole);
                QPushButton *exitButton = msgBox.addButton(tr("Выйти"), QMessageBox::NoRole);

                msgBox.exec();

                if (msgBox.clickedButton() == newGameButton) {
                    newGame();
                } else if (msgBox.clickedButton() == exitButton) {
                    QApplication::quit();
                } else if (msgBox.clickedButton() == continueGameButton) {
                    gameOver=true;
                }
                return;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 0) return;
            if (i < size-1 && grid[i][j] == grid[i + 1][j]) return;
            if (j < size-1 && grid[i][j] == grid[i][j + 1]) return;
        }
    }

    QMessageBox::information(this, tr("Игра окончена"), tr("Игра окончена! (Рекорд: %1)").arg(maxNumber));

    QString playerName = QInputDialog::getText(this, tr("Введите имя"), tr("Ваше имя:"));
    if (!playerName.isEmpty()) {
        ScoresWindow scoresWindow(this);
        scoresWindow.addScore(playerName, maxNumber);
    }
}


void MainWindow::move(Direction dir) {
    if (!canUndo) canUndo = true;
    bool moved = false;

    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            previousGrid[i][j]=grid[i][j];
        }
    }

    previousMaxNumber = maxNumber;

    switch (dir) {
    case Direction::Up:
        moved = moveUp();
        break;
    case Direction::Down:
        moved = moveDown();
        break;
    case Direction::Left:
        moved = moveLeft();
        break;
    case Direction::Right:
        moved = moveRight();
        break;
    }

    if (moved) {
        addRandomTile();
        updateUI(grid);
        if (gameOver==false)
        checkGameOver();
    }
}

void MainWindow::undoMove() {
    if (!canUndo) {
        QMessageBox::information(this, tr("Ошибка"), tr("Нет хода для отмены."));
        return;
    }

    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            grid[i][j]=previousGrid[i][j];
        }
    }
    maxNumber = previousMaxNumber;

    updateUI(grid);
    ui->maxNumberLabel->setText(QString::number(maxNumber));

    canUndo = false;
}

void MainWindow::on_newGame_triggered() {
    newGame();
}

void MainWindow::on_saveGame_triggered() {
    saveGame();
}

void MainWindow::on_loadGame_triggered() {
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Внимание!"));
    msgBox.setText(tr("Текущий прогресс будет утерян. Хотите продолжить?"));
    QPushButton *loadGameButton = msgBox.addButton(tr("Загрузить"), QMessageBox::YesRole);
    msgBox.addButton(tr("Продолжить"), QMessageBox::ActionRole);
    msgBox.exec();

    if (msgBox.clickedButton() == loadGameButton) {
        loadGame();
    }
}

void MainWindow::on_exitGame_triggered() {
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Внимание!"));
    msgBox.setText(tr("Текущий прогресс будет утерян. Хотите сохранить?"));
    QPushButton *saveAndQuitGameButton = msgBox.addButton(tr("Сохранить и выйти"), QMessageBox::YesRole);
    QPushButton *quitGameButton = msgBox.addButton(tr("Выйти без сохранения"), QMessageBox::ActionRole);
    msgBox.addButton(tr("Продолжить"), QMessageBox::ActionRole);
    msgBox.exec();

    if (msgBox.clickedButton() == saveAndQuitGameButton) {
        saveGame();
        QApplication::quit();
    }
    else if (msgBox.clickedButton() == quitGameButton){
        QApplication::quit();
    }
}

void MainWindow::on_moveUpButton_clicked()
{
    move(Direction::Up);
}


void MainWindow::on_moveDownButton_clicked()
{
    move(Direction::Down);
}


void MainWindow::on_moveLeftButton_clicked()
{
    move(Direction::Left);
}


void MainWindow::on_moveRightButton_clicked()
{
    move(Direction::Right);
}

void MainWindow::on_undoButton_clicked()
{
    undoMove();
}

void MainWindow::on_help_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Помощь"));
    msgBox.setText(tr("Для управления в игре используются клавиши стрелок:\n\n"
                      "Up - Вверх\n"
                      "Down - Вниз\n"
                      "Left - Влево\n"
                      "Right - Вправо\n"
                      "Ctrl + Z - Отмена хода\n"
                      "Ctrl + R - Список рекордов\n"
                      "Ctrl + S - Сохранить игру\n"
                      "Ctrl + L - Загрузить игру\n"
                      "Ctrl + 3 - Режим 3х3\n"
                      "Ctrl + 4 - Режим 4х4\n"
                      "Ctrl + 5 - Режим 5х5\n"
                      "Ctrl + 6 - Режим 6х6\n"
                      "Ctrl + 7 - Режим 7х7\n"
                      "Ctrl + 8 - Режим 8х8\n"
                      "Ctrl + E - Выход\n\n"
                      "Цель игры: соединить плитки, чтобы достигнуть 2048."));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}


void MainWindow::on_about_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Об игре"));
    msgBox.setText(tr("2048 - это логическая игра, в которой нужно объединять плитки с числами.\n\n"
                      "Как играть:\n"
                      "• Используйте стрелки на клавиатуре (↑, ↓, →, ←), чтобы сдвигать все плитки в выбранном направлении.\n"
                      "• Когда две плитки с одинаковым числом соприкасаются при движении, они сливаются в одну с суммой их значений.\n"
                      "• После каждого хода на свободном месте появляется новая плитка (со значением 2 или 4).\n"
                      "• Цель игры - получить плитку со значением 2048.\n\n"
                      "Советы:\n"
                      "• Старайтесь держать самые большие числа в углу.\n"
                      "• Не заполняйте пространство беспорядочно - планируйте ходы заранее.\n\n"
                      "Автор: Горесь Артём, Э-62"));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::on_showScores_triggered() {
    ScoresWindow scoresWindow(this);
    scoresWindow.exec();
}

void MainWindow::resizeField(int size)
{
    if (grid!=NULL) {
        deleteField();
    }
    if (previousGrid!=NULL) {
        deletePreviousField();
    }

    static_cast<field*>(ui->widget)->deleteTiles(this->size);
    this->size=size;
    static_cast<field*>(ui->widget)->createTiles(size);
}

void MainWindow::on_action3x3_triggered()
{
    if (size!=3)
        resizeField(3);
    newGame();
}

void MainWindow::on_action4x4_triggered()
{
    if (size!=4)
        resizeField(4);
    newGame();
}


void MainWindow::on_action5x5_triggered()
{
    if (size!=5)
        resizeField(5);
    newGame();
}


void MainWindow::on_action6x6_triggered()
{
    if (size!=6)
        resizeField(6);
    newGame();
}


void MainWindow::on_action7x7_triggered()
{
    if (size!=7)
        resizeField(7);
    newGame();
}


void MainWindow::on_action8x8_triggered()
{
    if (size!=8)
        resizeField(8);
    newGame();
}

