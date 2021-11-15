#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QFileInfo>
#include <QProcess>
#include <QUrl>
#include <QWebEngineView>
#include "tooltags.h"
#include "toolapps.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitTagData();
    void InitTagDataNew();
    void InitAppsData();

private slots:
    void on_ToolApps_doubleClicked(const QModelIndex &index);

    void on_ToolTags_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
