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

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
   Ui::MainWindow* ui;
   static MainWindow* mw;
   explicit MainWindow(QWidget *parent = 0);
   Pile* _pile;
    ~MainWindow();
public:
    static MainWindow* getInstance() ;
    static void freeInstance();
    Pile* getPile() const {return _pile;}
    void setPile(Pile *pile) {_pile = pile;}
    void setStackDisplayTextEdit(const QString &);
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
    void on_InputLineEdit_textChanged(const QString &arg1);
    void on_ReturnPushButton_clicked();
    void on_DropPushButton_clicked();
    void on_SumPushButton_clicked();
    void on_MeanPushButton_clicked();
    void on_DupPushButton_clicked();
    void on_SwapPushButton_clicked();
    void on_ClearPushButton_clicked();
    void keyPressEvent(QKeyEvent *);
signals:
    QKeyEvent* keyPressed(QKeyEvent*);
};

#endif // MAINWINDOW_H
