#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QDir>
#include <QFile>
#include "QIODevice"
#include <QMessageBox>
#include <QString>
#include <QApplication>
#include <QSysInfo>
#include <QFileDialog>
#include <QDataStream>
#include <QTextStream>
#include <Encryption.h>
#include <QActionGroup>
#ifdef Q_OS_WIN
#include "windows.h"
#include <stdio.h>
#include <iostream>
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new QSettings(this);
    QDir dirPath;
    QString folder1;
    folder1=dirPath.homePath();
    settingsIni = new QSettings(folder1+"/AppData/Local/Adventorium Inc/Kursach/settings.dll", QSettings::IniFormat, this);
    loadSettings();
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::Runne()
{
    //Проверка на лицензию и благодарность =)

    if ((lic==true)&&(lic2==true)&&(flag==false))
    {
        QMessageBox::information(0, "Благодарность", "Спасибо за покупку лицензии!");
        flag=true;//Поблагодарить только один раз
    }

    if ((lic==true)&&(lic2==true)) flag2=true;//куплена
    else flag2=false;//не куплена

    if (flag2==false)
    {

        if ((mtimes>=3)||(mtimes2>=3)) {QMessageBox::critical(this, "Eror: Триальный период закончился!", "Купите лицензию!"); nook(); if ((lic==false)||(lic2==false)) exit(1);}
        else {mtimes++; mtimes2++;}
    }
}

void MainWindow::saveSettings()
{
    slic="fgghrewlor"+QString::number(lic)+"jasdbvoiub3owjhbnv34sdf"; slic=stringEncrypt(slic, "kjzsfionjweh807348uhewghnui724");
    slic2="fgghrewlor"+QString::number(lic2)+"jasdbvoiub3owjhbnv34sdf"; slic2=stringEncrypt(slic2, "kjzsfionjweh807348uhewghnui724");
    stime1="ghrewlor"+QString::number(mtimes)+"jasdbvoiub3owjhbnv34sdf"; stime1=stringEncrypt(stime1, "jhasbvfijwbv762v3f478263f123");
    stime2="ghrewlor"+QString::number(mtimes2)+"jasdbvoiub3owjhbnv34sdf"; stime2=stringEncrypt(stime2, "jhasbvfijwbv762v3f478263f123");

    settings->setValue("License", slic);
    settings->setValue("Times", stime1);
    settings->setValue("Flag",flag);
    settingsIni->setValue("License", slic2);
    settingsIni->setValue("Times", stime2);
}

void MainWindow::loadSettings()
{
    QString zerrro="ghrewlor0jasdbvoiub3owjhbnv34sdf"; zerrro=stringEncrypt(zerrro, "jhasbvfijwbv762v3f478263f123");
    QString zerrr1="ghrewlor1jasdbvoiub3owjhbnv34sdf"; zerrr1=stringEncrypt(zerrr1, "jhasbvfijwbv762v3f478263f123");
    QString zerrr2="ghrewlor2jasdbvoiub3owjhbnv34sdf"; zerrr2=stringEncrypt(zerrr2, "jhasbvfijwbv762v3f478263f123");
    QString NOTzerrro="ghrewlor3jasdbvoiub3owjhbnv34sdf"; NOTzerrro=stringEncrypt(NOTzerrro, "jhasbvfijwbv762v3f478263f123");
    QString szerrro="fgghrewlor0jasdbvoiub3owjhbnv34sdf"; szerrro=stringEncrypt(szerrro, "kjzsfionjweh807348uhewghnui724");
    QString szerrr1="fgghrewlor0jasdbvoiub3owjhbnv34sdf"; szerrr1=stringEncrypt(szerrr1, "kjzsfionjweh807348uhewghnui724");
    slic=(settings->value("License", szerrro).toString());
    slic2=(settingsIni->value("License", szerrr1).toString());
    flag=(settings->value("Flag",0).toBool());
    stime1=(settings->value("Times", zerrro).toString());
    stime2=(settingsIni->value("Times", zerrro).toString());

    //int x= QString::compare(stime1, zerrro); QString brrr=QString::number(x); QMessageBox::information(0, tr("Debug"), brrr);

    if (((QString::compare(stime1, zerrro))==0)||((QString::compare(stime1, zerrr1))==0)||((QString::compare(stime2, zerrr2))==0)||((QString::compare(stime1, NOTzerrro))==0))
        { stime1=stime1;}
    else stime1=NOTzerrro;
    if (((QString::compare(stime2, zerrro))==0)||((QString::compare(stime2, zerrr1))==0)||((QString::compare(stime2, zerrr2))==0)||((QString::compare(stime2, NOTzerrro))==0))
        { stime2=stime2;}
    else stime2=NOTzerrro;
    if ((QString::compare(slic, szerrro)!=0)||(QString::compare(slic, szerrr1)!=0)) slic=slic;
    else slic=szerrro;
    if ((QString::compare(slic2, szerrro)!=0)||(QString::compare(slic2, szerrr1)!=0)) slic2=slic2;
    else slic=szerrro;

    slic=stringDecrypt(slic, "kjzsfionjweh807348uhewghnui724"); slic=slic.mid(10,1); lic=slic.toInt();
    slic2=stringDecrypt(slic2, "kjzsfionjweh807348uhewghnui724"); slic2=slic2.mid(10,1); lic2=slic2.toInt();
    stime1=stringDecrypt(stime1, "jhasbvfijwbv762v3f478263f123"); stime1=stime1.mid(8,1); mtimes=stime1.toInt();
    stime2=stringDecrypt(stime2, "jhasbvfijwbv762v3f478263f123"); stime2=stime2.mid(8,1); mtimes2=stime2.toInt();

    /*lic=(settings->value("License", 0).toBool());
    lic2=(settingsIni->value("License", 0).toBool());
    flag=(settings->value("Flag",0).toBool());
    mtimes=(settings->value("Times", 0).toInt());
    mtimes2=(settingsIni->value("Times", 0).toInt());*/
}

void MainWindow::nook()
{
    QMessageBox msgBox;
    msgBox.setText("The trial period passed.");
    msgBox.setInformativeText("Do you want to save your key or select the license?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel | QMessageBox::Open);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret)
    {
      case QMessageBox::Save:
          // Save was clicked
          {CreationFile();
          break;}
      case QMessageBox::Open:
          {LicenseSelect();
          break;}
      default:
          // should never be reached
          break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::CreationFile()
{
    //СОЗДАНИЕ КЛЮЧ-ФАЙЛА
        QString UID;
        QString folder2;
        folder2=QFileDialog::getSaveFileName(this, tr("Выберете место сохранения ключ-данных"), "C://", tr("Key file (*.key)"));
        if (folder2=="") return;
        QFile keyFile(folder2);
        //QMessageBox::information(0, tr("Debug"), "UID");

#ifdef Q_OS_WIN

        FILE *lsofFile_p = popen("wmic path win32_physicalmedia get SerialNumber", "r");
        QTextStream data1(lsofFile_p);
        QString text1= data1.readAll();
          pclose(lsofFile_p);
        UID=text1;
        //QMessageBox::information(0, tr("Debug"), text1);
#endif

#ifdef Q_OS_LINUX
        FILE *lsofFile_p = popen("hdparm -i /dev/hda | grep -i serial", "r");
        QTextStream data1(lsofFile_p);
        QString text1= data1.readAll();
          pclose(lsofFile_p);
        UID=text1;
#endif
        if(keyFile.open(QIODevice::ReadWrite|QIODevice::Truncate|QIODevice::Text)&&(UID!=""))    //Копирование текста выбранного файла в новый + нужно добавить соль
        {
            QTextStream data2(&keyFile);
            QString text2;
            data2.setCodec("UTF-8");

            text2=UID;//QMessageBox::information(0, tr("SimpleData"), text2);
            text2=stringEncrypt(text2,"65sdfgh98sdf1sdf4");

            data2<<text2;
            //QMessageBox::information(0, tr("CryptoData"), text2);
            keyFile.close();
            QMessageBox::information(0,"Success", "Ключ-файл был успешно создан!");
        }
        else QMessageBox::critical(0,"Проблема", "Ключ-файл не был создан!");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"Та cамая защищаемая функция", "Молодец!)");
}

void MainWindow::on_action_triggered()
{
    CreationFile();
}

void MainWindow::LicenseSelect()
{
    QString filename=QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "License file (*.lic)");
    if (filename=="") return;
    QFile read_file;
    read_file.setFileName(filename);

    //if (!read_file.exists()) {QMessageBox::information(this, tr("Ошибка доступа - файла не существует"), "Выберите существующий файл"); return;}
QString text1;
    if(read_file.open(QIODevice::ReadOnly|QIODevice::Text)) //Считываем лицензию
    {
        QTextStream out(&read_file);
        out.setCodec("UTF-8");          // Установка кодека
        text1 = out.readAll();       // Считываем весь файл в QString
        read_file.close();
    }

    text1=stringDecrypt(text1,"456789ApOiNtR55$%^&*&^%$#");
    FILE *lsofFile_p = popen("wmic path win32_physicalmedia get SerialNumber", "r");
    QTextStream data1(lsofFile_p);
    QString text2= data1.readAll();
    pclose(lsofFile_p);

    if (text1==text2) {lic=lic2=true; QMessageBox::information(0, "License","Thank you for purchaising our product!");}
    else {QMessageBox::warning(0, "Oh, Pirate!","Please, buy your own license!");}
}

void MainWindow::on_action_2_triggered()
{
    LicenseSelect();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Kursach Client"),
              tr("<h2>Created by Andrei Abramov SSAU group 6310</h2>"
              "<p>Copyright &copy; 2014 Adventorium Inc."
              "<p>It is a small application that "
              "<p>demonstrates my professional skills "));
}
