#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    for(int i = 0; i < 5; i++)
    {
        QPushButton *lala = new QPushButton();
        test.push_back(lala);
    }

    path.addRoundedRect(ui->pushButton->rect(), 11, 13);
    ui->pushButton->setMask(path.toFillPolygon().toPolygon());

    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setShowGrid(false);

    connect(ui->widget_button, &QPushButton::clicked, this, &MainWindow::OnAddWidget);
}

void MainWindow::OnAddWidget()
{
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(ui->frame_2->layout());

    QHBoxLayout* newlayout = new QHBoxLayout(ui->frame_2);

    QString buttonText = tr("Button: #%1").arg(layout->count());
    QPushButton *button = new QPushButton(buttonText, ui->frame_2);
    //layout->insertWidget(0, button);
    newlayout->addWidget(button);


    mButtonToLayoutMap.insert(button, newlayout);

    QLabel * label = new QLabel("Check me!", ui->frame_2);
    label->setAlignment(Qt::AlignCenter);
    newlayout->addWidget(label);
    layout->insertLayout(0, newlayout);

    QLabel * label2 = new QLabel("Site Numéro 2!", ui->frame_2);
    label2->setAlignment(Qt::AlignCenter);
    newlayout->addWidget(label2);
    layout->insertLayout(0, newlayout);


    connect(button, &QPushButton::clicked, this, &MainWindow::onRemoveWidget);
}

void MainWindow::onRemoveWidget()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    QHBoxLayout* layout = mButtonToLayoutMap.value(button);

    while(layout->count() !=0)
    {
        QLayoutItem *item = layout->takeAt(0);
        delete item->widget();
    }
    delete layout;

}
MainWindow::~MainWindow()
{
    delete ui;
}

