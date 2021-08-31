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
    update_ui();

}


void MainWindow::on_btn_Cycloid_clicked()
{
    // set render area's shape
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnHuygens_clicked()
{
    // set render area's shape
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_btnHypoCycloid_clicked()
{
    // set render area's shape
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();
    update_ui();
}


void MainWindow::on_spinScale_valueChanged(double arg1)
{
    this->ui->renderArea->setScale(arg1);
}

void MainWindow::on_spinIntervalLength_valueChanged(double arg1)
{
    this->ui->renderArea->setIntervalLength(arg1);
}

void MainWindow::on_spinCount_valueChanged(int arg1)
{
    this->ui->renderArea->setStepCount(arg1);
}

void MainWindow::update_ui()
{
    this->ui->renderArea->setScale(this->ui->spinScale->value());
    this->ui->renderArea->setIntervalLength(this->ui->spinIntervalLength->value());
    this->ui->renderArea->setStepCount(this->ui->spinCount->value());

}

void MainWindow::on_btnBackground_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->backgroundColor(), this, "Select color");
    ui->renderArea->setBackgroundColor(color);
}


void MainWindow::on_btnLineColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->shapeColor(), this, "Select color");
    ui->renderArea->setShapeColor(color);
}

