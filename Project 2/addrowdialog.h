#ifndef ADDROWDIALOG_H
#define ADDROWDIALOG_H

#include <QDialog>

namespace Ui {
class AddRowDialog;
}

class AddRowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowDialog(QWidget *parent = nullptr);
    QList<QString> getRowData();
    ~AddRowDialog();

/*private slots:
    void on_seatsLabel_linkActivated(const QString &link);

    void on_fuelCB_activated(int index);

    void on_yearSpinB_textChanged(const QString &arg1);*/

private:
    Ui::AddRowDialog *ui;
};

#endif // ADDROWDIALOG_H
