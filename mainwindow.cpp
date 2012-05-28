#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->setFont(QFont("Arial", 13));
}

QString MainWindow::getInput() const {
    return ui->InputLineEdit->text();
}

void MainWindow::setInput(const QString &str) {
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+" "+str);
}

MainWindow::~MainWindow()
{
    delete ui;
}
