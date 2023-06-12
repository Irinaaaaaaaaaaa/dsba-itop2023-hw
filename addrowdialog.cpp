#include "addrowdialog.h"
#include "ui_addrowdialog.h"

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
}

QList<QString> AddRowDialog::getRowData()
{
    QList<QString> newList(11, "No data");
    if (ui->nameLine->text() != "")
        newList[0] = ui->nameLine->text();
    if (ui->locationLine->text() != "")
        newList[1] = ui->locationLine->text();
    newList[2] = ui->yearSpinB->text();
    newList[3] = ui->mileageSpinBox->text();
    newList[4] = ui->fuelCB->currentText();
    newList[5] = ui->transmissionCB->currentText();
    newList[6] = ui->ownerCB->currentText();
    newList[7] = ui->capacitySpinB->text() + " CC";
    newList[8] = ui->powerSpinB->text() + " bhp";
    newList[9] = ui->seatsSpinB->text();
    newList[10] = ui->priceSpinB->text();
    return newList;
}

AddRowDialog::~AddRowDialog()
{
    delete ui;
}
