#include "proxymodel.h"

ProxyModel::ProxyModel(QObject* parent): QSortFilterProxyModel(parent), _name("")
{
}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex nameIndex = sourceModel()->index(source_row, 0, source_parent);
    bool isContains = (((sourceModel()->data(nameIndex)).toString()).contains(_name, Qt::CaseInsensitive));
    if (isContains)
        return true;
    else
        return false;
}

void ProxyModel::setName(const QString& string)
{
    _name = string;
    invalidateFilter();
}

/*ProxyModel::ProxyModel(QObject* parent)
    : QSortFilterProxyModel(parent)
{
    _minYear = 1980;
    //_maxAge = 2020;
    _ageFilterEnabled = true;
}*/


/*bool ProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const
{
    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);
    QVariant data0 = sourceModel()->data(index0);
    bool accepts0 = data0.toString().contains(filterRegularExpression());

    QModelIndex indexYear = sourceModel()->index(sourceRow, 5, sourceParent);
    QVariant dataAge = sourceModel()->data(indexAge);
    bool acceptsYear = YearFitsFilter(dataYear);

    return accepts0 && acceptsYear;
}*/
