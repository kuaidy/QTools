#include "tooltagsmodel.h"

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
    ToolTag toolTagEfficiency("EfficiencyTools", "效率工具");
    ToolTag toolTagMore("More", "发现");
    m_datas.push_back(toolTagEfficiency);
    m_datas.push_back(toolTagMore);
}
