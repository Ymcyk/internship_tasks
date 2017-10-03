#include "animalmodel.h"
#include <QString>
#include <QDebug>

AnimalModel::AnimalModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

void AnimalModel::addAnimal(const Animal &animal)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    list_.append(animal);
    endInsertRows();
}

int AnimalModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return list_.length();
}

QVariant AnimalModel::data(const QModelIndex &index, int role) const
{
    QVariant result;

    const Animal &animal = list_[index.row()];

    switch(role)
    {
    case NameRole:
        result = animal.name();
        break;
    case SpeciesRole:
        result = animal.species();
        break;
    case AgeRole:
        result = animal.age();
        break;
    case LegsRole:
        result = animal.legs();
        break;
    case HeightRole:
        result = animal.height();
        break;
    default:
        break;
    }

    return result;
}

QHash<int, QByteArray> AnimalModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[NameRole] = "name";
    roles[SpeciesRole] = "species";
    roles[AgeRole] = "age";
    roles[LegsRole] = "legs";
    roles[HeightRole] = "height";

    return roles;
}

