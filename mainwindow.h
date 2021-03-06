#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAstroid_clicked();

    void on_btn_Cycloid_clicked();

    void on_btnHuygens_clicked();

    void on_btnHypoCycloid_clicked();

    void on_spinScale_valueChanged(double arg1);

    void on_spinIntervalLength_valueChanged(double arg1);

    void on_spinCount_valueChanged(int arg1);

    void on_btnBackground_clicked();

    void on_btnLineColor_clicked();

    void on_btnCircle_clicked();

    void on_btnEllipse_clicked();

private:
    void update_ui();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
