#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAstroid_clicked()
{
    // set render area's shape
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();

}


void MainWindow::on_btn_Cycloid_clicked()
{
    // set render area's shape
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
}


void MainWindow::on_btnHuygens_clicked()
{
    // set render area's shape
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
}


void MainWindow::on_btnHypoCycloid_clicked()
{
    // set render area's shape
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
}

