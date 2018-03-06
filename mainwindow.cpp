#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <commands.h>
#include "noicefilter.h"
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <iostream>
using namespace std;
Noicefilter filter;
QString FIle_Path= "";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   this->ui->widget->ReadDataCheck=true;
   this->ui->widget->Point_S=filter.get_Points();
   this->ui->widget->update();
}

void MainWindow::on_pushButton_2_clicked()
{

   if(this->ui->checkBox->checkState()){
    filter.MedianaFilter();
    this->ui->widget->NoiceCheck=true;

  }
  if(this->ui->checkBox_2->checkState()){
    filter.AveregeGeometric();
    this->ui->widget->NoiceCheck=true;

  }
    this->ui->widget->Point_B=filter.get_Points();
    this->ui->widget->update();

}

void MainWindow::on_pushButton_3_clicked()
{

    this->ui->widget->DrawLines=filter.ArrayOfPoints();


    }

void MainWindow::on_pushButton_4_clicked()
{
  /*  Point Start,End;

   filter.LinerRegresion(Start,End);

    Start.set_x(506);
    Start.set_y(395);
    End.set_x(275);
    End.set_y(457);
*/
  //  this->ui->widget->Start=Start;
   // this->ui->widget->End=End;
    this->ui->widget->AproximationCheck=true;
    this->ui->widget->update();
}

void MainWindow::on_pushButton_5_clicked()
{

    QFileDialog *FileDialog = new QFileDialog(this);
    FileDialog->setDirectory("/home/shsergiy/FilterData");
    FIle_Path= FileDialog->getOpenFileName();
    std::string utf8_text = FIle_Path.toUtf8().constData();
    filter.setParameters(utf8_text,7);
}
