#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *pModel=new QStandardItemModel();

    for(int i=0;i<5;i++){
        QStandardItem *pItem=new QStandardItem();
        ToolTagInfo *toolTagInfo=new ToolTagInfo();
        toolTagInfo->mIconPath="";
        toolTagInfo->mTagCode="More";
        toolTagInfo->mTagName="发现";
        QVariant variant;
        variant.setValue(toolTagInfo);
        pItem->setData(QVariant::fromValue(variant),Qt::UserRole+1);
        pModel->appendRow(pItem);
    }

    ToolTagDelegate *toolTagDelegate=new ToolTagDelegate(this);
    ui->ToolTags->setItemDelegate(toolTagDelegate);
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(ui->ToolTags);
    proxyModel->setSourceModel(pModel);
    proxyModel->setFilterRole(Qt::UserRole);
    proxyModel->setDynamicSortFilter(true);
    ui->ToolTags->setModel(proxyModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ToolTags_clicked(const QModelIndex &index)
{

}

