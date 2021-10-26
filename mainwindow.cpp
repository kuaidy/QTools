#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ToolTagModel * toolTagModel = new ToolTagModel();
    toolTagModel->InitData();
    ui->ToolTags->setModel(toolTagModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

