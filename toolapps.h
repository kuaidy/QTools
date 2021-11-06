#ifndef TOOLAPPS_H
#define TOOLAPPS_H

#include <QAbstractTableModel>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QPainterPath>

class ToolApp
{
public:
    ToolApp(const QString& appCode, const QString& appName,const QString& appDownUrl,const QString& appExeUrl):m_AppCode(appCode),m_AppName(appCode), m_AppDownUrl(appDownUrl), m_AppExeUrl(appExeUrl)
    {

    }
    QString  AppCode() const { return this->m_AppCode; }
    QString  AppName() const { return this->m_AppName; }
    QString  AppDownUrl() const { return this->m_AppDownUrl; }
    QString  AppExeUrl() const { return this->m_AppExeUrl; }
    //当前model的组件对象
    QVariant  obj;
private:
    QString  m_AppCode;
    QString m_AppName;
    //下载地址
    QString m_AppDownUrl;
    //启动地址
    QString m_AppExeUrl;
};

class ToolAppModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ToolAppModel(QObject *parent = nullptr);
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //初始化数据
    void InitData();
private:
    //model数据集合
    std::vector<ToolApp>  m_datas;
};

class ToolAppInfo{
public:
    QString mIconPath;
    QString mAppCode;
    QString mAppName;
};

//自定义list的样式
class ToolAppDelegate:public QStyledItemDelegate
{
public:
    ToolAppDelegate(QObject *parent=nullptr);
    void paint(QPainter *painter,const QStyleOptionViewItem &option,const QModelIndex &index) const Q_DECL_OVERRIDE;
    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index)const Q_DECL_OVERRIDE;
private:
    int mListHeight=30;
    int mFontSize=10;
    int mIconWidth=30;
    int mIconHeight=30;
};




#endif // TOOLAPPS_H
