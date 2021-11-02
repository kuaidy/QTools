#ifndef TOOLTAGS_H
#define TOOLTAGS_H

#include <QStyledItemDelegate>
#include <QPainterPath>
#include <QPainter>
#include <QColor>

class ToolTag{
public:
    ToolTag(const QString& tagCode, const QString& tagName,const QString &iconPath):mTagCode(tagCode),mTagName(tagName),mIconPath(iconPath)
    {
    }
    QString TagCode() const { return this->mTagCode; }
    QString TagName() const { return this->mTagName; }
    QString IconPath() const {return this->mIconPath;}
    QVariant  obj;//当前model的组件对象
private:
    QString mTagCode;
    QString mTagName;
    QString mIconPath;
};

class ToolTagInfo{
public:
    QString mIconPath;
    QString mTagCode;
    QString mTagName;
};

class ToolTagModel  :public QAbstractListModel
{
    Q_OBJECT
public:
    ToolTagModel(QObject*  parent=NULL);
    ~ToolTagModel() {}
    //外部接口 C++调用 添加数据
    void  Add(ToolTag &tt);
    //外部接口 清除model
    Q_INVOKABLE void clear();
    //虚函数  qml内部调用  获取第index行的内容  role 内容索引
    QVariant data(const QModelIndex &index, int role =Qt::DisplayRole) const;
    //虚函数 获取model行数
    int rowCount(const QModelIndex &parent  = QModelIndex() ) const;
    // 虚函数 内容的别名  qml 内部调用
    //QHash<int, QByteArray> roleNames()  const;
    //自定义  设置当前model第index行的当前组件指针
    Q_INVOKABLE void setcuritem(int index , QVariant  j)
    {
        m_datas[index].obj = j;
    }
    void InitData();

private:
      //model数据集合
    std::vector<ToolTag>  m_datas;
};

//自定义list的样式
class ToolTagDelegate:public QStyledItemDelegate
{
public:
    ToolTagDelegate(QObject *parent=nullptr);
    void paint(QPainter *painter,const QStyleOptionViewItem &option,const QModelIndex &index) const Q_DECL_OVERRIDE;
    QSize sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index)const Q_DECL_OVERRIDE;
private:
    int mListHeight=30;
    int mFontSize=10;
    int mIconWidth=15;
    int mIconHeight=15;
};

#endif // TOOLTAGS_H
