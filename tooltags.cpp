#include "tooltags.h"

ToolTagModel::ToolTagModel(QObject* parent) :QAbstractListModel(parent)
{

}
void ToolTagModel::Add(ToolTag& tt)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_datas.push_back(tt);
    endInsertRows();
}
void ToolTagModel::clear()
{
    //清除rows 界面将不显示
    beginRemoveRows(QModelIndex(), 0, m_datas.size());
    //清空动态数组
    m_datas.clear();
    endRemoveRows();
    //end

}
int ToolTagModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_datas.size();
}
QVariant ToolTagModel::data(const QModelIndex &index, int role)  const
{
    if (index.row() < 0 || index.row() >= m_datas.size())
    {
        return QVariant();
    }
    int nRow=index.row();
    int nCol=index.column();
    const ToolTag& d = m_datas[index.row()];

    switch(role){
        case Qt::DisplayRole:
            switch (nCol) {
                case 0:
                    return m_datas[nRow].TagName();
                    break;
                case 1:
                    return m_datas[nRow].TagCode();
                    break;
            }
            break;
    }
    return QVariant();
}
//初始化数据
void ToolTagModel::InitData(){
//    ToolTag toolTagEfficiency("123","EfficiencyTools", "效率工具");
//    ToolTag toolTagMore("123","More", "发现");
//    m_datas.push_back(toolTagEfficiency);
//    m_datas.push_back(toolTagMore);
}
//自定义listview的样式
ToolTagDelegate::ToolTagDelegate(QObject *parent):QStyledItemDelegate(parent)
{
}
void ToolTagDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid()){
        painter->save();
        ToolTagInfo *toolTagInfo=index.data(Qt::UserRole+1).value<ToolTagInfo*>();
        //矩形区域
        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width());
        rect.setHeight(option.rect.height());

        QPainterPath path;
        path.moveTo(rect.topRight());
        path.lineTo(rect.topLeft());
        path.quadTo(rect.topLeft(),rect.topLeft());
        path.lineTo(rect.bottomLeft());
        path.quadTo(rect.bottomLeft(), rect.bottomLeft());
        path.lineTo(rect.bottomRight());
        path.quadTo(rect.bottomRight(), rect.bottomRight());
        path.lineTo(rect.topRight());
        path.quadTo(rect.topRight(), rect.topRight());
        //绘制图标，名称
        painter->setPen(QPen(Qt::black));
//        painter->drawPath(path);
        QRect iconRect;
        iconRect.setX(option.rect.x()+10);
        iconRect.setY(option.rect.y()+mListHeight/2-mIconHeight/2);
        iconRect.setWidth(mIconHeight);
        iconRect.setHeight(mIconHeight);
        painter->drawImage(iconRect,QImage(toolTagInfo->mIconPath));
//        painter->fillPath(path,Qt::cyan);
        painter->setFont(QFont("Microsoft Yahei", mFontSize));
        painter->drawText(option.rect.x()+iconRect.x()+mIconWidth+10,option.rect.y()+mListHeight/2+mFontSize/2,toolTagInfo->mTagName);
        painter->restore();
    }
}
QSize ToolTagDelegate::sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index)const{
    return QSize(option.rect.width(), mListHeight);
}
