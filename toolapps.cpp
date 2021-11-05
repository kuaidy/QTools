#include "toolapps.h"

ToolAppModel::ToolAppModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant ToolAppModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int ToolAppModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_datas.size();
}

int ToolAppModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

}

QVariant ToolAppModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int nRow=index.row();
    int nCol=index.column();
    const ToolApp& ta = m_datas[index.row()];
    switch(role){
        case Qt::DisplayRole:
            switch (nCol) {
                case 0:
                    return m_datas[nRow].AppName();
                    break;
            }
            break;
    }
    // FIXME: Implement me!
    return QVariant();
}
//
void ToolAppModel::InitData(){
    ToolApp toolItem("everything", "everything","https://www.rdonly.com","https://www.rdonly.com");
    m_datas.push_back(toolItem);
}

//自定义listview的样式
ToolAppDelegate::ToolAppDelegate(QObject *parent):QStyledItemDelegate(parent)
{
}
void ToolAppDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.isValid()){
        painter->save();
        ToolAppInfo *toolAppInfo=index.data(Qt::UserRole+1).value<ToolAppInfo*>();
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
        painter->drawPath(path);
        QRect iconRect;
        iconRect.setX(option.rect.x()+10);
        iconRect.setY(option.rect.y()+mListHeight/2-mIconHeight/2);
        iconRect.setWidth(mIconHeight);
        iconRect.setHeight(mIconHeight);
//        painter->drawImage(iconRect,QImage(ToolAppInfo->mIconPath));
//        painter->fillPath(path,Qt::cyan);
        painter->setFont(QFont("Microsoft Yahei", mFontSize));
        painter->drawText(option.rect.x()+iconRect.x()+mIconWidth+10,option.rect.y()+mListHeight/2+mFontSize/2,toolAppInfo->mTagName);
        painter->restore();
    }
}
QSize ToolAppDelegate::sizeHint(const QStyleOptionViewItem &option,const QModelIndex &index)const{
    return QSize(option.rect.width(), mListHeight);
}



