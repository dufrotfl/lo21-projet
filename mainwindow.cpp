#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

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
    _pile->clear();
    ui->InputLineEdit->clear();
    ui->StackDisplayTextEdit->clear();
}

void MainWindow::on_ComplexesNoRadioButton_clicked()
{
    ui->ComplexDelimiterPushButton->setVisible(false);
    Settings::getInstance()->setUtilisationDeComplexe(Settings::NON_COMPLEXE);
    _pile->clear();
    ui->InputLineEdit->clear();
    ui->StackDisplayTextEdit->clear();
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
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"\'");
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
    Settings::getInstance()->setNbElementAffichable(arg1);
}

void MainWindow::on_DeletePushButton_clicked()
{
    ui->InputLineEdit->clear();
}

void MainWindow::on_InputLineEdit_returnPressed() throw (LogMessage) {
    // Le texte entré par l'utilisateur dans le InputLineEdit
    QString input(ui->InputLineEdit->text());
    // Si il n'y a pas de texte entré
    if(input.isEmpty()) {
        Constante* c = _pile->sommet();
        // Si la constante en haut de la pile est une Expression
        if(typeid(*c)==typeid(Expression)) {
            Expression* e = dynamic_cast<Expression*>(c);
            try {
                // On évalue cette Expression et on empile le résultat
                _pile->pop();
                _pile->push(e->eval());
                ui->InputLineEdit->clear();
            }
            catch(LogMessage lm) {
                LogSystem::getInstance()->addMessage(lm);
            }
        }
    }
    // Si l'utilisateur a entré une Expression, on l'empile sans la modifier
    else if(QRegExp("^'\.+'$").indexIn(input)!=-1) {
        try {
            _pile->push(ConstanteFactory::getConstante(input));
            ui->InputLineEdit->clear();
        }
        catch(LogMessage lm) {
            LogSystem::getInstance()->addMessage(lm);
        }
    }
    // Sinon, l'utilisateur a entré un NombreNonComplexe ou un Operateur
    else {
        try {
            QStringList constantes(input.split(' '));
            QStringList::iterator i;

            for(i=constantes.begin(); i != constantes.end(); i++) {
                Constante* p = ConstanteFactory::getConstante(*i);

                // Si c'est un Operateur
                if(typeid(*p)==typeid(Operateur)) {
                    Operateur* o = dynamic_cast<Operateur*>(p);
                    // Si l'arité de l'opérateur est 1, on dépile un élément de la pile
                    // et on appelle l'opérateur sur notre NombreNonComplexe ou Epxression
                    // (car la pile ne peut contenir que ces deux types là).
                    if(o->getArite()==1) {
                        Constante *cpop = _pile->pop();
                        _pile->push(o->call(cpop));
                        delete cpop;
                    }
                    // Si l'arité de l'opérateur est 2, on dépile deux éléments de la pile
                    // et on appelle l'opérateur sur nos NombreNonComplexe ou Epxression
                    // (car la pile ne peut contenir que ces deux types là).
                    else if(o->getArite()==2) {
                        Constante *cpop1 = _pile->pop();
                        Constante *cpop2 = _pile->pop();
                        _pile->push(o->call(cpop2, cpop1));
                        delete cpop1, cpop2;
                    }
                }
                else
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
