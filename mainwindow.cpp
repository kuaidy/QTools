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
    QString tagName=index.data(Qt::DisplayRole).toString();
    if(tagName=="发现"){
        QWebEngineView *view;
        view = new QWebEngineView(ui->ToolApps);
        view->load(QUrl("https://www.rdonly.com"));
        view->resize(ui->ToolApps->size());
        view->show();
    }
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
    toolTagInfo1->mIconPath=":/image/image/other.png";
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
    //读取json数据
    QFile file(":/data/data/tooltags.json");
    if(!file.open(QIODevice::ReadOnly)){
        return ;
    }
    QByteArray allData=file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
    if(jsonError.error!=QJsonParseError::NoError){
        return ;
    }
    QJsonArray jsonArray=jsonDoc.array();
    for(int i=0;i<jsonArray.size();i++){
        QJsonObject tagObj=jsonArray.at(i).toObject();
        ToolTagInfo toolTagInfo;
        if(tagObj.contains("Name")){
            toolTagInfo.mTagName=tagObj["Name"].toString();
        }
        if(tagObj.contains("EName")){
            toolTagInfo.mTagCode=tagObj["EName"].toString();
        }
        if(tagObj.contains("IconPath")){
            toolTagInfo.mIconPath=tagObj["IconPath"].toString();
        }
        toolTags.append(toolTagInfo);
    }

//    ToolTagInfo toolTagInfo1;
//    toolTagInfo1.mIconPath=":/image/image/other.png";
//    toolTagInfo1.mTagCode="more";
//    toolTagInfo1.mTagName="发现";
//    toolTags.append(toolTagInfo1);

//    ToolTagInfo toolTagInfo2;
//    toolTagInfo2.mIconPath=":/image/image/set.png";
//    toolTagInfo2.mTagCode="set";
//    toolTagInfo2.mTagName="设置";
//    toolTags.append(toolTagInfo2);

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

    //读取json数据
    QFile file(":/data/data/toolapps.json");
    if(!file.open(QIODevice::ReadOnly)){
        return ;
    }
    QByteArray allData=file.readAll();
    file.close();
    QJsonParseError jsonError;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData,&jsonError));
    if(jsonError.error!=QJsonParseError::NoError){
        return ;
    }
    QJsonArray jsonArray=jsonDoc.array();
    QStandardItemModel *appModel=new QStandardItemModel(jsonArray.size(),1);
    for(int i=0;i<jsonArray.size();i++){
        QJsonObject tagObj=jsonArray.at(i).toObject();
        ToolAppInfo toolAppInfo;
        if(tagObj.contains("Name")){
            toolAppInfo.mAppName=tagObj["Name"].toString();
        }
        if(tagObj.contains("EName")){
            toolAppInfo.mAppCode=tagObj["EName"].toString();
        }
        if(tagObj.contains("IconPath")){
            toolAppInfo.mIconPath=tagObj["IconPath"].toString();
        }
        if(tagObj.contains("Path")){
            toolAppInfo.mAppPath=tagObj["IconPath"].toString();
        }
        QModelIndex modelIndex=appModel->index(i,0);
        appModel->setData(modelIndex,toolAppInfo.mAppName,Qt::DisplayRole);
        appModel->setData(modelIndex,QIcon(toolAppInfo.mIconPath),Qt::DecorationRole);
        appModel->setData(modelIndex,toolAppInfo.mAppPath,Qt::UserRole);
    }
//    ToolAppInfo *toolAppInfo=new ToolAppInfo();
//    toolAppInfo->mIconPath=":/new/prefix/image/everything.png";
//    toolAppInfo->mAppCode="everything";
//    toolAppInfo->mAppName="EveryThing";
//    toolAppInfo->mAppPath="apps/Efficiency/EveryThing/Everything.exe";
    ui->ToolApps->setViewMode(QListView::IconMode);
    ui->ToolApps->setIconSize(QSize(50, 50));
    ui->ToolApps->setGridSize(QSize(100, 100));
    ui->ToolApps->setFlow(QListView::LeftToRight);
    ui->ToolApps->setWrapping(true);
    ui->ToolApps->setResizeMode(QListView::Adjust);
    ui->ToolApps->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->ToolApps->setModel(appModel);
}

void MainWindow::on_ToolApps_doubleClicked(const QModelIndex &index)
{
    qDebug()<<index.data(Qt::UserRole);
    qDebug()<<QCoreApplication::applicationDirPath();
    QString exePath=QCoreApplication::applicationDirPath()+"/"+index.data(Qt::UserRole).toString();
    QFileInfo file(exePath);
    if(file.exists()){
        QProcess::startDetached(exePath,QStringList());
    }
}

