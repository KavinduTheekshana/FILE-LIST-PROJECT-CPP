#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAdd_clicked()
{
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->setText(NULL);
}

void MainWindow::on_btnRemove_clicked()
{
    foreach (QListWidgetItem *item, ui->listWidget->selectedItems())  delete item;
}

void MainWindow::on_btnClear_clicked()
{
    ui->listWidget->clear();
}

void MainWindow::on_btnSave_clicked()
{
    QFile m_file("mytext.txt");  m_file.open(QFile::WriteOnly);
    QTextStream m_stream(&m_file);
    for (int i=0; i<ui->listWidget->count(); i++)
    {
        m_stream << ui->listWidget->item(i)->text() << "\n";
    }
    m_file.close();
    ui->listWidget->clear();
}

void MainWindow::on_btnLoad_clicked()
{
    QFile m_file("mytext.txt");
    m_file.open(QFile::ReadOnly);
    QTextStream m_stream(&m_file);
    int i=0;  while (!m_stream.atEnd())
    {
        ui->listWidget->addItem(m_stream.readLine());  i++;
    }
}
