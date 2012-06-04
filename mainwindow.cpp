#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "operateur.h"
#include "nombreComplexe.h"

MainWindow* MainWindow::mw = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    _pile = new Pile();
    ui->setupUi(this);
    statusBar()->setFont(QFont("Arial", 11));
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
    ui->ConstantTypeDelimiterPushButton->setText("/ (Rationnel)");
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
    try {
        Constante* c = _pile->sommet();
        // Si la constante en haut de la pile est une Expression
        if(typeid(*c)==typeid(Expression)) {
            Expression* e = dynamic_cast<Expression*>(c);
                // On évalue cette Expression et on empile le résultat
                ui->InputLineEdit->setText(e->getListe());
                _pile->pop();
                on_ReturnPushButton_clicked();
                ui->InputLineEdit->clear();
            }
        else
            throw LogMessage("Le sommet de la pile n'est pas une Expression.", 1);
    }
    catch(LogMessage lm) {
        LogSystem::getInstance()->addMessage(lm);
    }
}

void MainWindow::on_StackDisplaySizespinBox_valueChanged(int arg1)
{
    Settings::getInstance()->setNbElementAffichable(arg1);    
    ui->StackDisplayTextEdit->clear();
    _pile->affiche();
}

void MainWindow::on_DeletePushButton_clicked()
{
    ui->InputLineEdit->clear();
}

void MainWindow::on_InputLineEdit_returnPressed() throw (LogMessage) {
    // Le texte entré par l'utilisateur dans le InputLineEdit
    QString input(ui->InputLineEdit->text());
    input = input.simplified();
    // Si il n'y a pas de texte entré
    if(input.isEmpty()) {
        on_DupPushButton_clicked();
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
                    if(o->getArite()==0) {
                        o->call();
                    }
                    // Si l'arité de l'opérateur est 1, on dépile un élément de la pile
                    // et on appelle l'opérateur sur notre NombreNonComplexe ou Epxression
                    // (car la pile ne peut contenir que ces deux types là).
                    else if(o->getArite()==1) {
                        Constante *cpop;
                        if(_pile->getPileAffichageSize() > 1 )
                             cpop = _pile->pop();
                        else
                            throw LogMessage("Impossible de faire la somme car la pile contient qu'un seul élément.", 2);
                        if(o->getOperateur() != "MEAN" && o->getOperateur() != "SUM")
                            _pile->push(o->call(cpop));
                        else {
                                o->call(cpop);
                        }
                        delete cpop;
                    }
                    // Si l'arité de l'opérateur est 2, on dépile deux éléments de la pile
                    // et on appelle l'opérateur sur nos NombreNonComplexe ou Epxression
                    // (car la pile ne peut contenir que ces deux types là).
                    else if(o->getArite()==2) {
                        if(_pile->getPileAffichageSize()>= 2) {
                            Constante *cpop1 = _pile->pop();
                            if(o->getOperateur()=="/" &&( typeid(*cpop1)==typeid(Entier) || typeid(*cpop1)==typeid(Reel) || typeid(*cpop1)==typeid(Rationnel))) {
                                NombreNonComplexe* den = dynamic_cast<NombreNonComplexe*>(cpop1);
                                if(den->getFloatVal() == 0) {
                                    delete den;
                                    throw LogMessage("Division par 0 non autorisée.", 1);
                                }
                            }
                            Constante *cpop2 = _pile->pop();
                            _pile->push(o->call(cpop2, cpop1));
                            delete cpop1, cpop2;
                        }
                        else
                            throw LogMessage("Pas assez d'élément à dépiler.", 1);
                    }
                }
                else {
                    if(Settings::getInstance()->getUtilisationDeComplexe()==Settings::COMPLEXE) {
                        NombreComplexe * pcopy;
                        if(typeid(*p)==typeid(NombreComplexe)) {
                            pcopy = dynamic_cast<NombreComplexe*>(p);
                        }
                        else {
                            pcopy = dynamic_cast<NombreNonComplexe*>(p)->toNombreComplexe();
                        }
                        _pile->push(pcopy);
                    }
                    else
                        _pile->push(p);
                }

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

void MainWindow::on_InputLineEdit_textChanged(const QString &arg1)
{
    //qDebug() << arg1;
}

void MainWindow::on_ReturnPushButton_clicked()
{
    on_InputLineEdit_returnPressed();
}


void MainWindow::on_DropPushButton_clicked()
{
    _pile->drop();
    ui->StackDisplayTextEdit->clear();
    _pile->affiche();
}


void MainWindow::on_SumPushButton_clicked()
{
    on_EspacePushButton_clicked();
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"SUM");
    on_EspacePushButton_clicked();
}

void MainWindow::on_MeanPushButton_clicked()
{
    on_EspacePushButton_clicked();
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"MEAN");
    on_EspacePushButton_clicked();
}

void MainWindow::on_DupPushButton_clicked()
{
    _pile->dup();
    ui->StackDisplayTextEdit->clear();
    _pile->affiche();
}

void MainWindow::on_SwapPushButton_clicked()
{
    on_EspacePushButton_clicked();
    ui->InputLineEdit->setText(ui->InputLineEdit->text()+"SWAP");
    on_EspacePushButton_clicked();
}

void MainWindow::on_ClearPushButton_clicked()
{
    _pile->clear();
    ui->StackDisplayTextEdit->clear();
    _pile->affiche();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return) {
        if(ui->InputLineEdit->text().isEmpty())
            on_DropPushButton_clicked();
    }
}
/*
try {
    Constante* c = _pile->sommet();
    // Si la constante en haut de la pile est une Expression
    if(typeid(*c)==typeid(Expression)) {
        Expression* e = dynamic_cast<Expression*>(c);
        // On évalue cette Expression et on empile le résultat
        _pile->pop();
        _pile->push(e->eval());
        ui->InputLineEdit->clear();
    }
}
catch(LogMessage lm) {
    LogSystem::getInstance()->addMessage(lm);
}*/
