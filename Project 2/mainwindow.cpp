#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"
#include "helpp.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}
/*void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QList<QString> targetLine =(*model)[proxyModel -> mapToSource(index).row()];
    ui->RankLine->setText(targetLine[0]);
    ui->NameLine->setText(targetLine[1]);
    ui->genreLine->setText(targetLine[2]);
    ui->yearLine->setText(targetLine[3]);
    //ui->mileageLine->setText(targetLine[3]);
    ui->PublisherLine->setText(targetLine[4]);
    //ui->transmissionLine->setText(targetLine[5]);
    //ui->ownerLine->setText(targetLine[6]);
    //ui->capacityLine->setText(targetLine[7]);
    //ui->powerLine->setText(targetLine[8]);
    //ui->seatsLine->setText(targetLine[9]);
    //ui->priceLine->setText(targetLine[10]);
}*/


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
    //QObject::connect(ui->minAgeLineEdit, &QLineEdit::textChanged, this, ::MainWindow::setMinFilterAge);
    //QObject::connect(ui->yearSlider, &QSlider::valueChanged, this, &MainWindow::setMinFilterAge);
    qDebug()<<select->selectedIndexes();
    if (select->hasSelection())
        model->deleteRow(proxyModel -> mapToSource(select->selectedIndexes()[0]).row());
    on_goButton_clicked();
}


/*void MainWindow::on_sortCB_currentTextChanged(const QString &arg1)
{
    //QString bySort = ui->SortPB->currentText();
    ui->
    if (bySort == "Price: Low to High")
        proxyModel->sort(10, Qt::AscendingOrder);
    else if (bySort == "Price: High to Low")
        proxyModel->sort(10, Qt::DescendingOrder);
}*/


void MainWindow::on_goButton_clicked()
{
    /*
    QString needToSearch = ui->searchLine->text();
    proxyModel->setName(needToSearch);
*/
}

void MainWindow::on_pushButton_clicked()
{
    Helpp help;
    help.setModal(true);
    help.exec();
}
/*void MainWindow::setMinFilterYear(int value)
{

    //int newMinYear = ui->minAgeLineEdit->text().toInt();//?

   // ui->minAgeLineEdit->setText(QString::number(value));
    proxyModel->setMinYear(value);

}
void MainWindow::setMinFilterYearString(QString value)
{

    //ui->minAgeLineEdit->setText(value); //?
    ui->yearSlider->setValue(value.toInt());
    proxyModel->setMinYear(value.toInt());
}
*/


