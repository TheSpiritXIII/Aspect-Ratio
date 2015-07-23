#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget.h"

#include <QSplitter>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSplitter *splitter = new QSplitter(Qt::Vertical, this);
    QWidget *splitterWidget = new QWidget(this);
    splitterWidget->setLayout(ui->horizontalLayout);
    splitter->addWidget(centralWidget());
    splitter->addWidget(new QPushButton("YES"));
    setCentralWidget(splitter);

    ui->horizontalLayout->addStretch();
    ui->horizontalLayout->addWidget(new Widget(this));
    ui->horizontalLayout->addWidget(new Widget(this));
    ui->horizontalLayout->addStretch();
}

MainWindow::~MainWindow()
{
    delete ui;
}
