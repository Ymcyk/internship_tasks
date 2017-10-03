#ifndef FILEPROXYMODEL_H
#define FILEPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>

class FileProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit FileProxyModel(QObject *parent = nullptr);

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

public slots:
    void onSearchTextChanged(const QString&);

private:
    QString filename_pattern_ = "";
};

#endif // FILEPROXYMODEL_H
