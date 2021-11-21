#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainterPath>
#include <QDebug>
#include <QCheckBox>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


    /*Test*/
    void OnAddWidget();

    void onRemoveWidget();
    ~MainWindow();

private:

    QHash<QPushButton*, QHBoxLayout*> mButtonToLayoutMap;
    vector<QPushButton *> test;
    QPainterPath path;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
