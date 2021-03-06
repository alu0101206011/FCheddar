#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QDir>
#include <QFileDialog>
#include <QSqlTableModel>

#include "./scheduler.h"
#include "./database.h"
#include "./calendar.h"
#include "./graph.h"
#include "./settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void writeSettings();
    void readSettings();

private slots:
    void on_actionScheduler_Settings_triggered();
    void on_actionNew_Schedule_triggered();
    void on_openDatabaseButton_clicked();
    void on_newDatabaseButton_clicked();
    void on_connectToDatabase_clicked();
    void on_actionSave_triggered();
    void on_deleteButton_clicked();
    void on_projectTable_clicked(const QModelIndex &index);
    void on_filterButton_clicked();
    void on_cleanButton_clicked();
    void on_calendarButton_clicked();
    void on_actionRun_Scheduler_triggered();
    void on_actionRestart_Scheduler_triggered();
    void on_actionDeleteCurrent_Scheduler_triggered();
    void on_actionServer_Database_triggered();
    void on_actionWindow_settings_triggered();
    void on_actionSave_Graph_as_png_triggered();
    void on_actionServer_Database_help_triggered();
    void on_actionClient_Database_help_triggered();
    void on_actionGeneral_Usage_Information_Simulation_triggered();
    void on_actionEdit_appearance_Simulation_triggered();
    void on_actionInfo_FCheddar_help_triggered();
    void on_actionGeneral_Usage_Information_Database_triggered();
    void on_actionFilter_triggered();

private:
    enum typeAction {OPEN, NEW};

    void openDatabase(typeAction);
    void insertImage(const QModelIndex &index);
    void createGraph(bool, bool);
    bool is_plannable();

    Ui::MainWindow *ui;
    Scheduler* schedule;
    Database* database;
    QSqlTableModel *mModel;
    const QModelIndex *lastIndex;
    Calendar* calendar;
    Settings* settings;

    Graph *graph;
    QChartView *chartView;
    QVBoxLayout *layout;
    bool projectCreated;
    bool mPlannable;
};
#endif // MAINWINDOW_H
