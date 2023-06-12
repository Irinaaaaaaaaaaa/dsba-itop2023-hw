#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"

#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new TableModel), proxyModel(new ProxyModel)
{
    ui->setupUi(this);
    proxyModel->setSourceModel(model);
    ui->tableView->setModel(proxyModel);
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode());
    ui->tableView->setSortingEnabled(true);
//    for (int i = 0; i < 12; i++)
//    {
//        if (i != 3 && i != 0 && i != 2 && i != 8 && i != 10)
//            ui->tableView->setColumnHidden(i, true);
//    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QList<QString> targetLine =(*model)[index.row()];
    ui->nameLine->setText(targetLine[0]);
    ui->locationLine->setText(targetLine[1]);
    ui->yearLine->setText(targetLine[2]);
    ui->mileageLine->setText(targetLine[3]);
    ui->fuelLine->setText(targetLine[4]);
    ui->transmissionLine->setText(targetLine[5]);
    ui->ownerLine->setText(targetLine[6]);
    ui->capacityLine->setText(targetLine[7]);
    ui->powerLine->setText(targetLine[8]);
    ui->seatsLine->setText(targetLine[9]);
    ui->priceLine->setText(targetLine[10]);
}


void MainWindow::on_addRow_clicked()
{
//    model->addRow(QList<QString>());
    AddRowDialog dialog;
    if (dialog.exec())
    {
        model->addRow(dialog.getRowData());
    }
//    if (dialog.close()){}
}


void MainWindow::on_deletRow_clicked()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    qDebug()<<select->selectedIndexes();
    if (select->hasSelection())
        model->deleteRow(select->selectedIndexes()[0].row());
}


void MainWindow::on_sortCB_currentTextChanged(const QString &arg1)
{
    QString bySort = ui->sortCB->currentText();
    if (bySort == "Price: Low to High")
        proxyModel->sort(10, Qt::AscendingOrder);
    else if (bySort == "Price: High to Low")
        proxyModel->sort(10, Qt::DescendingOrder);

}


void MainWindow::on_goButton_clicked()
{
    QString needToSearch = ui->searchLine->text();
    proxyModel->setName(needToSearch);
}

