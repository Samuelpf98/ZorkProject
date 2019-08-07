#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScrollBar>
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QMediaPlayer>


/*
 * Refactor code:
 * DONE ---- Templates - Templates for functions getPlayerStamina/Health. Player class
 * DONE ----Operator Overloading - use where it makes sense. Hero and Enemy fighting + equals fight;
 * DONE ---- Friend Classes - Friend ZorkUL with Character and inherited classes
 * DONE ---- Inheritance - Character class -> Player and Enemy class.
 *
 * CLEAN UP CODE -- NOT DONE
 * ADD MORE RESOURCES
 * */
using namespace std;

ZorkUL temp;


//Win state collect 4 pieces of key and escape
//Loss state, run out of stamina or health

//add pic dynamically
// ui->elementName -> setStyleSheet("background-image:url(:/prefix/different_file)");
//url(:/! Zork:/images/maxresdefault.jpg)


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    temp.createRooms();
    temp.createPlayer();
    connect(&temp, SIGNAL(gameOver()), this, SLOT(on_gameOver()));
    connect(&temp, SIGNAL(gameWin()), this, SLOT(on_gameWin()));



    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->insertPlainText(QString::fromStdString(temp.printWelcome()));
    //make methods in ZorkUL that get attributes and call them with temp.getplayerhealth();



      ui->progressBar->setMinimum(0);
      ui->progressBar->setMaximum(160);
      ui->progressBar->setValue(temp.getPlayerStamina());
      ui->progressBar->show();

      ui->progressBar_2->setMinimum(0);
      ui->progressBar_2->setMaximum(100);
      ui->progressBar_2->setValue(temp.getPlayerHealth());
      ui->progressBar_2->show();

      ui->textEdit_2->setReadOnly(true);
      ui->textEdit_2->insertPlainText("Inventory: ");
      ui->textEdit_2->insertPlainText(QString::fromStdString(temp.Inventory));

      //play sound
      QMediaPlayer *introSound =new QMediaPlayer();
      introSound->setMedia(QUrl("qrc:/! Zork:/images/DungeonMusic.mp3"));

      introSound->play();








}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("north")));
    temp.playerTravel();
 ui->progressBar->setValue(temp.getPlayerStamina());
  ui->textEdit->insertPlainText(QString::fromStdString(temp.fight()));
   ui->progressBar_2->setValue(temp.getPlayerHealth());
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    temp.gameCheck();
    background();





}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("west")));
    temp.playerTravel();
 ui->progressBar->setValue(temp.getPlayerStamina());
  ui->textEdit->insertPlainText(QString::fromStdString(temp.fight()));
   ui->progressBar_2->setValue(temp.getPlayerHealth());
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    temp.gameCheck();
    background();
}

void MainWindow::on_pushButton_3_clicked()
{

    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("east")));
    temp.playerTravel();
 ui->progressBar->setValue(temp.getPlayerStamina());
 ui->textEdit->insertPlainText(QString::fromStdString(temp.fight()));
  ui->progressBar_2->setValue(temp.getPlayerHealth());
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    temp.gameCheck();
    background();
}

void MainWindow::on_pushButton_4_clicked()
{

    ui->textEdit->insertPlainText(QString::fromStdString(temp.go("south")));
    temp.playerTravel();
 ui->progressBar->setValue(temp.getPlayerStamina());
  ui->textEdit->insertPlainText(QString::fromStdString(temp.fight()));
   ui->progressBar_2->setValue(temp.getPlayerHealth());
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    temp.gameCheck();
    background();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString(temp.teleport()));
    temp.playerTravel();
 ui->progressBar->setValue(temp.getPlayerStamina());
  ui->textEdit->insertPlainText(QString::fromStdString(temp.fight()));
   ui->progressBar_2->setValue(temp.getPlayerHealth());
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    temp.gameCheck();
    background();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->textEdit->insertPlainText(QString::fromStdString(temp.map()));
    ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
    temp.gameCheck();

}

void MainWindow::on_pushButton_7_clicked()
{
 exit(0);
}



void MainWindow::on_gameWin(){
    this->hide();
    QLabel *label = new QLabel();
    QHBoxLayout *hbox = new QHBoxLayout();
    QWidget *wind = new QWidget();

    QFont gameFont("Castellar", 15);
    label->setFont(gameFont);
    label->setStyleSheet("QLabel {color: white;background:rgb(5, 32, 130);}");
    label->setText("You have collected the four pieces.\n You craft a key and escape!.\n\n YOU WIN");
    label->setAlignment(Qt::AlignCenter);
    label->setWindowTitle("Game Won");
    hbox->addWidget(label);
    wind->setLayout(hbox);

    wind->setFixedSize(900,400);
    wind->show();

}

void MainWindow::on_gameOver(){
    this->hide();
    QLabel *label = new QLabel();
    QHBoxLayout *hbox = new QHBoxLayout();
    QWidget *wind = new QWidget();

    QFont gameFont("Castellar", 15);
    label->setFont(gameFont);
    label->setStyleSheet("QLabel {color: white;background:rgb(5, 32, 130);}");
    label->setText("You feel all your energy leave your body.\n You pass out and never wake up.\n\nGAME OVER");
    label->setAlignment(Qt::AlignCenter);
    label->setWindowTitle("Game Over");
    hbox->addWidget(label);
    wind->setLayout(hbox);

    wind->setFixedSize(900,400);
    wind->show();


 ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());


}



void MainWindow::on_pushButton_8_clicked()
{
 QString text = ui->lineEdit->text();
 temp.setText(text);
 string text1 = temp.getText().toStdString();
 string take = "take";
 Command* itemTake = new Command(take,text1);
 ui->textEdit->insertPlainText(QString::fromStdString(temp.processCommand(*itemTake)));
 ui->textEdit_2->clear();
 ui->textEdit_2->insertPlainText("Inventory: ");
 ui->textEdit_2->insertPlainText(QString::fromStdString(temp.Inventory));
 ui->lineEdit->clear();
 ui->textEdit->verticalScrollBar()->setValue(ui->textEdit->verticalScrollBar()->maximum());
 temp.gameCheck();


}



void MainWindow::background(){
    //url(:/! Zork:/images/a.jpg);
   // ui->elementName->setStyleSheet("background-image:url(:/prefix/different_file);");
    //ui->textEdit->setStyleSheet("background-image:url(:/! Zork:/images/"+QString::fromStdString(temp.getCurRoom())+".jpg)");
 ui->textEdit->setStyleSheet("border: 4px solid black;padding 35px;background-image:url(:/! Zork:/images/"+QString::fromStdString(temp.getCurRoom())+".jpg);background-position: center; background-repeat: no-repeat;  background-attachment: fixed;font: 8pt Castellar ;color: white;");

}


