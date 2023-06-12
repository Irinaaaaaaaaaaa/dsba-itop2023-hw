#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include "proxymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addRow_clicked();

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_deletRow_clicked();

    void on_sortCB_currentTextChanged(const QString &arg1);

    void on_goButton_clicked();

private:
    Ui::MainWindow *ui;
    TableModel *model;
    ProxyModel *proxyModel;

};
#endif // MAINWINDOW_H
