#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStandardItemModel *pModel=new QStandardItemModel();

    InitData(pModel);

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
//初始化菜单数据
void MainWindow::InitData(QStandardItemModel *pModel){
    QStandardItem *pItem=new QStandardItem();
    ToolTagInfo *toolTagInfo=new ToolTagInfo();
    toolTagInfo->mIconPath=":/new/prefix/image/efficiency.png";
    toolTagInfo->mTagCode="efficiency";
    toolTagInfo->mTagName="效率";
    QVariant variant;
    variant.setValue(toolTagInfo);
    pItem->setData(QVariant::fromValue(variant),Qt::UserRole+1);
    pModel->appendRow(pItem);

    QStandardItem *pItem1=new QStandardItem();
    ToolTagInfo *toolTagInfo1=new ToolTagInfo();
    toolTagInfo1->mIconPath=":/new/prefix/image/more.png";
    toolTagInfo1->mTagCode="more";
    toolTagInfo1->mTagName="发现";
    QVariant variant1;
    variant1.setValue(toolTagInfo1);
    pItem1->setData(QVariant::fromValue(variant1),Qt::UserRole+1);
    pModel->appendRow(pItem1);

    QStandardItem *pItem2=new QStandardItem();
    ToolTagInfo *toolTagInfo2=new ToolTagInfo();
    toolTagInfo2->mIconPath=":/new/prefix/image/set.png";
    toolTagInfo2->mTagCode="set";
    toolTagInfo2->mTagName="设置";
    QVariant variant2;
    variant2.setValue(toolTagInfo2);
    pItem2->setData(QVariant::fromValue(variant2),Qt::UserRole+1);
    pModel->appendRow(pItem2);
}
