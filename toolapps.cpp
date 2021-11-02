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
