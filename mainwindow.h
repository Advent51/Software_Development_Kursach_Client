#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSettings>
#include <QMainWindow>
#include "QString"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    QString slic, slic2, stime1, stime2;
    bool lic,lic2,flag,flag2,snaka;
    int mtimes, mtimes2;
    QSettings keysettings;
    void saveSettings();
    void loadSettings();
    void Runne();
    void nook();
    void CreationFile();
    void LicenseSelect();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_action_triggered();

    void on_action_2_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
    QSettings *settings,*settingsIni;
};

#endif // MAINWINDOW_H
