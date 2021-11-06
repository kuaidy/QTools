#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //InitTagData();
    InitTagDataNew();
    InitAppsData();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ToolTags_clicked(const QModelIndex &index)
{

}
//初始化菜单数据
void MainWindow::InitTagData(){
    QStandardItemModel *pModel=new QStandardItemModel();
    ToolTagDelegate *toolTagDelegate=new ToolTagDelegate(this);
    ui->ToolTags->setItemDelegate(toolTagDelegate);
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(ui->ToolTags);
    proxyModel->setSourceModel(pModel);
    proxyModel->setFilterRole(Qt::UserRole);
    proxyModel->setDynamicSortFilter(true);
//    ui->ToolTags->setViewMode(QListView::IconMode);
    ui->ToolTags->setModel(proxyModel);
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
//初始化分类
void MainWindow::InitTagDataNew(){
    QVector<ToolTagInfo> toolTags;
    ToolTagInfo toolTagInfo;
    toolTagInfo.mIconPath=":/new/prefix/image/efficiency.png";
    toolTagInfo.mTagCode="efficiency";
    toolTagInfo.mTagName="效率";
    toolTags.append(toolTagInfo);
    ToolTagInfo toolTagInfo1;
    toolTagInfo1.mIconPath=":/new/prefix/image/more.png";
    toolTagInfo1.mTagCode="more";
    toolTagInfo1.mTagName="发现";
    toolTags.append(toolTagInfo1);
    ToolTagInfo toolTagInfo2;
    toolTagInfo2.mIconPath=":/new/prefix/image/set.png";
    toolTagInfo2.mTagCode="set";
    toolTagInfo2.mTagName="设置";
    toolTags.append(toolTagInfo2);
    QStandardItemModel *appModel=new QStandardItemModel(toolTags.count(),1);
    for(int i=0;i<toolTags.count();i++){
        QModelIndex modelIndex=appModel->index(i,0);
        appModel->setData(modelIndex,toolTags[i].mTagName,Qt::DisplayRole);
        appModel->setData(modelIndex,QIcon(toolTags[i].mIconPath),Qt::DecorationRole);
    }
    ui->ToolTags->setViewMode(QListView::ListMode);
    ui->ToolTags->setIconSize( QSize(30, 30) );
    ui->ToolTags->setGridSize( QSize(200, 40));
    ui->ToolTags->setFlow(QListView::TopToBottom);
    ui->ToolTags->setWrapping(true);
    ui->ToolTags->setResizeMode(QListView::Adjust);
    ui->ToolTags->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ToolTags->setModel(appModel);
}
//初始化内容数据
void MainWindow::InitAppsData(){
    ToolAppInfo *toolAppInfo=new ToolAppInfo();
    toolAppInfo->mIconPath=":/new/prefix/image/everything.png";
    toolAppInfo->mAppCode="everything";
    toolAppInfo->mAppName="EveryThing";
    QStandardItemModel *appModel=new QStandardItemModel(1,1);
    QModelIndex modelIndex=appModel->index(0,0);
    appModel->setData(modelIndex,toolAppInfo->mAppName,Qt::DisplayRole);
    appModel->setData(modelIndex,QIcon(toolAppInfo->mIconPath),Qt::DecorationRole);
    ui->ToolApps->setViewMode(QListView::IconMode);
    ui->ToolApps->setIconSize( QSize(50, 50) );
    ui->ToolApps->setGridSize( QSize(100, 100));
    ui->ToolApps->setFlow(QListView::LeftToRight);
    ui->ToolApps->setWrapping(true);
    ui->ToolApps->setResizeMode(QListView::Adjust);
    ui->ToolApps->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ToolApps->setModel(appModel);
}

void MainWindow::on_ToolApps_doubleClicked(const QModelIndex &index)
{

}

