#ifndef HELPP_H
#define HELPP_H

#include <QDialog>
#include "customwidget.h"

namespace Ui {
class Helpp;
}

class Helpp : public QDialog
{
    Q_OBJECT

public:
    explicit Helpp(QWidget *parent = nullptr);
    ~Helpp();

private slots:
    //void on_buttonBox_accepted();//?

    //void on_widgetLogoContainer_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Helpp *ui;
    CustomWidget* _logo;
};

#endif // HELPP_H
