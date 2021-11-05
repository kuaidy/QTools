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
//    ui->ToolTags->setViewMode(QListView::IconMode);
    ui->ToolTags->setModel(proxyModel);

    QStringList nameItem;
    nameItem << "Linux" << "Android" << "Mac OS";
    QStandardItemModel *appModel=new QStandardItemModel(nameItem.length(),1);
    for(int i=0;i<appModel->rowCount();++i){
        QModelIndex modelIndex=appModel->index(i,0);
        QString str=nameItem.at(i);
        appModel->setData(modelIndex,str,Qt::DisplayRole);
        appModel->setData(modelIndex,"i",Qt::ToolTipRole);
        appModel->setData(modelIndex,QIcon(":/new/prefix/image/more.png"),Qt::DecorationRole);
    }
    ui->ToolApps->setViewMode(QListView::IconMode);
    ui->ToolApps->setIconSize( QSize(80, 80) );
    ui->ToolApps->setGridSize( QSize(100, 100));
    ui->ToolApps->setFlow(QListView::LeftToRight);
    ui->ToolApps->setWrapping(true);
    ui->ToolApps->setResizeMode(QListView::Adjust);
    ui->ToolApps->setGeometry(100,100,200,200);
    ui->ToolApps->setModel(appModel);
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

//初始化内容数据
void MainWindow::InitAppsData(QStandardItemModel *pModel){
    QStandardItem *pItem=new QStandardItem();
    ToolAppInfo *toolAppInfo=new ToolAppInfo();
    toolAppInfo->mIconPath=":/new/prefix/image/efficiency.png";
    toolAppInfo->mTagCode="efficiency";
    toolAppInfo->mTagName="效率";
    QVariant variant;
    variant.setValue(toolAppInfo);
    pItem->setData(QVariant::fromValue(variant),Qt::UserRole+1);
    pModel->appendRow(pItem);

    QStandardItem *pItem1=new QStandardItem();
    ToolAppInfo *toolAppInfo1=new ToolAppInfo();
    toolAppInfo1->mIconPath=":/new/prefix/image/more.png";
    toolAppInfo1->mTagCode="more";
    toolAppInfo1->mTagName="发现";
    QVariant variant1;
    variant1.setValue(toolAppInfo1);
    pItem1->setData(QVariant::fromValue(variant1),Qt::UserRole+1);
    pModel->appendRow(pItem1);

    QStandardItem *pItem2=new QStandardItem();
    ToolAppInfo *toolAppInfo2=new ToolAppInfo();
    toolAppInfo2->mIconPath=":/new/prefix/image/set.png";
    toolAppInfo2->mTagCode="set";
    toolAppInfo2->mTagName="设置";
    QVariant variant2;
    variant2.setValue(toolAppInfo2);
    pItem2->setData(QVariant::fromValue(variant2),Qt::UserRole+1);
    pModel->appendRow(pItem2);
}
