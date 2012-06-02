#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow* MainWindow::mw = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    _pile = new Pile();
    ui->setupUi(this);
    statusBar()->setFont(QFont("Arial", 13));
    ui->ConstantTypeDelimiterPushButton->setVisible(false);
    ui->ComplexDelimiterPushButton->setVisible(false);
}

MainWindow * MainWindow::getInstance() {
    if(!mw)
        mw = new MainWindow();
    return mw;
}

void MainWindow::freeInstance() {
    if(!mw)
        delete mw;
}

MainWindow::~MainWindow()
{
    delete mw;
}

void MainWindow::on_IntegerRadioButton_clicked()
{
    ui->ConstantTypeDelimiterPushButton->setVisible(false);
    Settings::getInstance()->setTypeConstante(Settings::ENTIER);
}

void MainWindow::on_RationalRadioButton_clicked()
{
    ui->ConstantTypeDelimiterPushButton->setVisible(true);
    ui->ConstantTypeDelimiterPushButton->setText("/");
    Settings::getInstance()->setTypeConstante(Settings::RATIONNEL);
}

void MainWindow::on_RealRadioButton_clicked()
{
    ui->ConstantTypeDelimiterPushButton->setVisible(true);
    ui->ConstantTypeDelimiterPushButton->setText(",");
    Settings::getInstance()->setTypeConstante(Settings::REEL);
}

void MainWindow::on_ComplexesYesRadioButton_clicked()
{
    ui->ComplexDelimiterPushButton->setVisible(true);
    Settings::getInstance()->setUtilisationDeComplexe(Settings::COMPLEXE);
}

void MainWindow::on_ComplexesNoRadioButton_clicked()
{
    Settings::getInstance()->setUtilisationDeComplexe(Settings::NON_COMPLEXE);
}

void MainWindow::on_AnglesDegreesRadioButton_clicked()
{
    Settings::getInstance()->setAngles(Settings::DEGRES);
}

void MainWindow::on_AnglesRadianRadioButton_clicked()
{
    Settings::getInstance()->setAngles(Settings::RADIANS);
}

void MainWindow::on_EspacePushButton_clicked()
{
    if(!ui->InputLineEdit->text().isEmpty() && !ui->InputLineEdit->text().at(ui->InputLineEdit->text().length()-1).isSpace())
        ui->InputLineEdit->setText(ui->InputLineEdit->text()+" ");
    ui->InputLineEdit->setFocus();
}

void MainWindow::on_AddPushButton_clicked()
{
    on_EspacePushButton_clicked();
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"+");
    on_EspacePushButton_clicked();
}


void MainWindow::on_DividePushButton_clicked()
{
    on_EspacePushButton_clicked();
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"/");
    on_EspacePushButton_clicked();
}

void MainWindow::on_MultiplyPushButton_clicked()
{
    on_EspacePushButton_clicked();
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"*");
    on_EspacePushButton_clicked();
}

void MainWindow::on_ExpressionPushButton_clicked()
{
    /*if(!ui->InputLineEdit->selectedText().isEmpty())
        ui->InputLineEdit->setText(ui->InputLineEdit->text().mid(0, ui->InputLineEdit->selectionStart()-1)+"\'"+ui->InputLineEdit->selectedText()+"\'"+ui->InputLineEdit->text().mid(ui->InputLineEdit->selectionStart()+ui->InputLineEdit->selectedText().length(), ui->InputLineEdit->text().length()-1));
    */ui->InputLineEdit->setText(ui->InputLineEdit->text()+"\'");
}

void MainWindow::on_SubstractPushButton_clicked()
{
    on_EspacePushButton_clicked();
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"-");
    on_EspacePushButton_clicked();
}

void MainWindow::on_NinePushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"9");
}

void MainWindow::on_EightPushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"8");
}

void MainWindow::on_SevenPushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"7");
}

void MainWindow::on_SixPushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"6");
}

void MainWindow::on_FivePushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"5");
}

void MainWindow::on_FourPushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"4");
}

void MainWindow::on_ThreePushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"3");
}

void MainWindow::on_TwoPushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"2");
}

void MainWindow::on_OnePushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"1");
}

void MainWindow::on_ZeroPushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"0");
}

void MainWindow::on_ComplexDelimiterPushButton_clicked()
{
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"$");
}

void MainWindow::on_ConstantTypeDelimiterPushButton_clicked()
{
    if(Settings::getInstance()->getTypeConstante() == Settings::RATIONNEL)
        ui->InputLineEdit->setText(ui->InputLineEdit->text()+"/");
    if(Settings::getInstance()->getTypeConstante() == Settings::REEL)
        ui->InputLineEdit->setText(ui->InputLineEdit->text()+",");
}

void MainWindow::on_EvalPushButton_clicked()
{
    //Gui::getInstance()->eval();
}

void MainWindow::on_StackDisplaySizespinBox_valueChanged(int arg1)
{

}

void MainWindow::on_DeletePushButton_clicked()
{
    ui->InputLineEdit->clear();
}
#include "QDebug"
void MainWindow::on_InputLineEdit_returnPressed() throw (LogMessage) {
    QString input(ui->InputLineEdit->text());
    if(input.isEmpty()) {
        Constante* c = _pile->pop();
        if(typeid(*c)==typeid(Expression)) {
            Expression* e = dynamic_cast<Expression*>(c);
            try {
                _pile->push(e->eval());
                ui->InputLineEdit->clear();
            }
            catch(LogMessage lm) {
                LogSystem::getInstance()->addMessage(lm);
            }
        }
        else
            _pile->push(c);
    }
    else if((QRegExp("^'\.+'$").indexIn(ui->InputLineEdit->text()))!=-1) {
        qDebug() << "passes-tu ici? 1";
        _pile->push(ConstanteFactory::getConstante(ui->InputLineEdit->text()));
        ui->InputLineEdit->clear();
    }
    else {
        try {
            QStringList constantes(input.split(' '));
            QStringList::iterator i;

            for(i=constantes.begin(); i != constantes.end(); i++) {
                Constante * p = ConstanteFactory::getConstante(*i);
                _pile->push(p);
                ui->InputLineEdit->clear();
            }
        }
        catch(LogMessage lm) {
            LogSystem::getInstance()->addMessage(lm);
        }
    }
    ui->StackDisplayTextEdit->clear();
    _pile->affiche();
}

void MainWindow::setStackDisplayTextEdit(const QString & str) {
    ui->StackDisplayTextEdit->append(str);
}
