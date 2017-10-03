#include "fileproxymodel.h"

#include <QDebug>

FileProxyModel::FileProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{

}

bool FileProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex nameIdx = sourceModel()->index(source_row, 0, source_parent);
    QModelIndex sizeIdx = sourceModel()->index(source_row, 1, source_parent);

    QString filename =  sourceModel()->data(nameIdx).toString();

    if (!filename.contains(filename_pattern_))
        return false;

    return true;
}

QVariant FileProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Vertical && role == Qt::TextAlignmentRole)
    {
        return QVariant(Qt::AlignCenter);
    }

    return sourceModel()->headerData(section, orientation, role);
}

void FileProxyModel::onSearchTextChanged(const QString &text)
{
    filename_pattern_ = text;
    invalidateFilter();
}
