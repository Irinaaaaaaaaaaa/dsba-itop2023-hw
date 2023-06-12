#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>

class ProxyModel: public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ProxyModel(QObject* parent = 0);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void setName(const QString& string);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    //void setMinYear(int minYear);
    //bool YearFitsFilter(QVariant dataYear) const;
    //bool filterAcceptsRow(int sourceRow, const QModelIndex& sourceParent) const override;

private:
    QString _name;
    //int _minYear;
    //int _maxYear;
    //bool _YearFilterEnabled;
};

#endif // PROXYMODEL_H
