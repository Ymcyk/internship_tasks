#ifndef ANIMALMODEL_H
#define ANIMALMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QHash>

#include "animal.h"

class AnimalModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum AnimalRoles {
        NameRole = Qt::UserRole + 1,
        SpeciesRole,
        AgeRole,
        LegsRole,
        HeightRole
    };

    explicit AnimalModel(QObject *parent = nullptr);

    void addAnimal(const Animal &animal);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    void populateList();

private:
    QList<Animal> list_;
};

#endif // ANIMALMODEL_H
