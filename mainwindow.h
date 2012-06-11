/*!
 \file mainwindow.h
 \author Sebastien Fradcourt & Florian Dufrot
 \date 03 Juin 2012
 \version 1.0
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settings.h"
#include "pile.h"
#include "typeinfo"
#include "expression.h"
#include "logSystem.h"
#include "constanteFactory.h"
#include "QKeyEvent"
#include <QLineEdit>
#include "QDebug"

namespace Ui {
class MainWindow;
}

/*!
 \class MainWindow
 \brief Classe (utilisant le Design Pattern Singleton) permettant de g�rer l'interface de la calculatrice, ainsi que les interactions entre celle-ci et les classes associ�es.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
   Ui::MainWindow* ui;
   /**<
     Bool�en permettant de savoir si le clavier est affich� ou non
     */
   bool showClavier;
   /**<
     L'instance de la classe MainWindow
     */
   static MainWindow* mw;

   Pile* _pile;
   /*!
     \brief Constructeur
     */
   explicit MainWindow(QWidget *parent = 0);
   /*!
     \brief Destructeur de la classe
     */
    ~MainWindow();
public:
   /*!
     \brief M�thode permettant de retourner l'instance de la classe
     \return L'instance de la classe
     */
    static MainWindow* getInstance() ;
    /*!
      \brief M�thode permettant de lib�rer l'instance de classe
      */
    static void freeInstance();
    /*!
      \brief M�thode permettant de charger le contexte : cad charger les bons param�tres en fonction des settings
      */
    void chargerContexte();
    /*!
      \brief Getter permettant de retourner la pile utilis�.
      \return La pile de la calculatrice
      */
    Pile* getPile() const {return _pile;}
    /*!
      \brief M�thode permettant de fixer le nombre d'�l�ments de la pile � afficher.
      \param i Le nombre d'�l�ments � afficher
      */
    void setStackDisplaySpinBox(int i);
    /*!
      \brief M�thode permettant de modifier le contenu du champ de saisie par la string en param�tre, et appelle la m�thode permettant de traiter cette chaine
      \param str La chaine de caract�res � ins�rer
      */
    void setInputLineEdit(const QString &str);
    /*!
      \brief M�thode permettant d'ajouter "str" au contenu d�j� pr�sent dans le champ de saisie.
      \param str La chaine de caract�res � ajouter
      */
    void setStackDisplayTextEdit(const QString &str);
private slots:
    void on_IntegerRadioButton_clicked();
    void on_RationalRadioButton_clicked();
    void on_RealRadioButton_clicked();
    void on_ComplexesYesRadioButton_clicked();
    void on_ComplexesNoRadioButton_clicked();
    void on_AnglesDegreesRadioButton_clicked();
    void on_AnglesRadianRadioButton_clicked();
    void on_AddPushButton_clicked();
    void on_EspacePushButton_clicked();
    void on_DividePushButton_clicked();
    void on_MultiplyPushButton_clicked();
    void on_SubstractPushButton_clicked();
    void on_ExpressionPushButton_clicked();
    void on_NinePushButton_clicked();
    void on_EightPushButton_clicked();
    void on_SevenPushButton_clicked();
    void on_SixPushButton_clicked();
    void on_FivePushButton_clicked();
    void on_FourPushButton_clicked();
    void on_ThreePushButton_clicked();
    void on_TwoPushButton_clicked();
    void on_OnePushButton_clicked();
    void on_ZeroPushButton_clicked();
    void on_ComplexDelimiterPushButton_clicked();
    void on_ConstantTypeDelimiterPushButton_clicked();
    void on_EvalPushButton_clicked();
    void on_StackDisplaySizespinBox_valueChanged(int arg1);
    void on_DeletePushButton_clicked();
    void on_InputLineEdit_returnPressed() throw (LogMessage);
    void on_ReturnPushButton_clicked();
    void on_DropPushButton_clicked();
    void on_SumPushButton_clicked();
    void on_MeanPushButton_clicked();
    void on_DupPushButton_clicked();
    void on_SwapPushButton_clicked();
    void on_ClearPushButton_clicked();
    void undo();
    void redo();
    void on_PowPushButton_clicked();
    void on_SqrPushButton_clicked();
    void on_CubePushButton_clicked();
    void on_SqrtPushButton_clicked();
    void on_SignPushButton_clicked();
    void on_ModPushButton_clicked();
    void on_SinPushButton_clicked();
    void on_CosPushButton_clicked();
    void on_TanPushButton_clicked();
    void on_SinhPushButton_clicked();
    void on_CoshPushButton_clicked();
    void on_TanhPushButton_clicked();
    void on_LnPushButton_clicked();
    void on_LogPushButton_clicked();
    void on_InvPushButton_clicked();
    void on_FactPushButton_clicked();
    void on_actionClavier_triggered();
    void on_actionA_propos_triggered();
};

#endif // MAINWINDOW_H
