/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 2. Jun 17:36:37 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClavier;
    QAction *actionQuitter;
    QAction *actionA_propos;
    QAction *actionAnnuler;
    QAction *actionR_tablir;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *inputHorizontalLayout;
    QLineEdit *InputLineEdit;
    QPushButton *EvalPushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *KeyBoardGridLayout;
    QPushButton *SevenPushButton;
    QPushButton *FourPushButton;
    QPushButton *OnePushButton;
    QPushButton *EightPushButton;
    QPushButton *FivePushButton;
    QPushButton *TwoPushButton;
    QPushButton *ZeroPushButton;
    QPushButton *NinePushButton;
    QPushButton *SixPushButton;
    QPushButton *ThreePushButton;
    QPushButton *DividePushButton;
    QPushButton *MultiplyPushButton;
    QPushButton *SubstractPushButton;
    QPushButton *AddPushButton;
    QPushButton *ExpressionPushButton;
    QPushButton *ConstantTypeDelimiterPushButton;
    QPushButton *ComplexDelimiterPushButton;
    QPushButton *EspacePushButton;
    QPushButton *DeletePushButton;
    QWidget *gridLayoutWidget_2;
    QGridLayout *ParametresGridLayout;
    QGroupBox *ComplexesGroupBox;
    QRadioButton *ComplexesYesRadioButton;
    QRadioButton *ComplexesNoRadioButton;
    QGroupBox *AnglesGroupBox;
    QRadioButton *AnglesDegreesRadioButton;
    QRadioButton *AnglesRadianRadioButton;
    QGroupBox *ConstantTypeGroupBox;
    QRadioButton *IntegerRadioButton;
    QRadioButton *RationalRadioButton;
    QRadioButton *RealRadioButton;
    QSpinBox *StackDisplaySizespinBox;
    QTextEdit *StackDisplayTextEdit;
    QLabel *StackLabel;
    QMenuBar *menuBar;
    QMenu *menuAffichage;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        actionClavier = new QAction(MainWindow);
        actionClavier->setObjectName(QString::fromUtf8("actionClavier"));
        actionClavier->setCheckable(true);
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionA_propos = new QAction(MainWindow);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        actionAnnuler = new QAction(MainWindow);
        actionAnnuler->setObjectName(QString::fromUtf8("actionAnnuler"));
        actionR_tablir = new QAction(MainWindow);
        actionR_tablir->setObjectName(QString::fromUtf8("actionR_tablir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 281, 51));
        inputHorizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        inputHorizontalLayout->setSpacing(6);
        inputHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        inputHorizontalLayout->setObjectName(QString::fromUtf8("inputHorizontalLayout"));
        inputHorizontalLayout->setContentsMargins(0, 0, 0, 0);
        InputLineEdit = new QLineEdit(horizontalLayoutWidget);
        InputLineEdit->setObjectName(QString::fromUtf8("InputLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(InputLineEdit->sizePolicy().hasHeightForWidth());
        InputLineEdit->setSizePolicy(sizePolicy1);

        inputHorizontalLayout->addWidget(InputLineEdit);

        EvalPushButton = new QPushButton(horizontalLayoutWidget);
        EvalPushButton->setObjectName(QString::fromUtf8("EvalPushButton"));

        inputHorizontalLayout->addWidget(EvalPushButton);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 70, 320, 170));
        KeyBoardGridLayout = new QGridLayout(gridLayoutWidget);
        KeyBoardGridLayout->setSpacing(6);
        KeyBoardGridLayout->setContentsMargins(11, 11, 11, 11);
        KeyBoardGridLayout->setObjectName(QString::fromUtf8("KeyBoardGridLayout"));
        KeyBoardGridLayout->setContentsMargins(0, 0, 0, 0);
        SevenPushButton = new QPushButton(gridLayoutWidget);
        SevenPushButton->setObjectName(QString::fromUtf8("SevenPushButton"));

        KeyBoardGridLayout->addWidget(SevenPushButton, 1, 0, 1, 1);

        FourPushButton = new QPushButton(gridLayoutWidget);
        FourPushButton->setObjectName(QString::fromUtf8("FourPushButton"));

        KeyBoardGridLayout->addWidget(FourPushButton, 2, 0, 1, 1);

        OnePushButton = new QPushButton(gridLayoutWidget);
        OnePushButton->setObjectName(QString::fromUtf8("OnePushButton"));

        KeyBoardGridLayout->addWidget(OnePushButton, 3, 0, 1, 1);

        EightPushButton = new QPushButton(gridLayoutWidget);
        EightPushButton->setObjectName(QString::fromUtf8("EightPushButton"));

        KeyBoardGridLayout->addWidget(EightPushButton, 1, 1, 1, 1);

        FivePushButton = new QPushButton(gridLayoutWidget);
        FivePushButton->setObjectName(QString::fromUtf8("FivePushButton"));

        KeyBoardGridLayout->addWidget(FivePushButton, 2, 1, 1, 1);

        TwoPushButton = new QPushButton(gridLayoutWidget);
        TwoPushButton->setObjectName(QString::fromUtf8("TwoPushButton"));

        KeyBoardGridLayout->addWidget(TwoPushButton, 3, 1, 1, 1);

        ZeroPushButton = new QPushButton(gridLayoutWidget);
        ZeroPushButton->setObjectName(QString::fromUtf8("ZeroPushButton"));

        KeyBoardGridLayout->addWidget(ZeroPushButton, 4, 0, 1, 2);

        NinePushButton = new QPushButton(gridLayoutWidget);
        NinePushButton->setObjectName(QString::fromUtf8("NinePushButton"));

        KeyBoardGridLayout->addWidget(NinePushButton, 1, 2, 1, 1);

        SixPushButton = new QPushButton(gridLayoutWidget);
        SixPushButton->setObjectName(QString::fromUtf8("SixPushButton"));

        KeyBoardGridLayout->addWidget(SixPushButton, 2, 2, 1, 1);

        ThreePushButton = new QPushButton(gridLayoutWidget);
        ThreePushButton->setObjectName(QString::fromUtf8("ThreePushButton"));

        KeyBoardGridLayout->addWidget(ThreePushButton, 3, 2, 1, 1);

        DividePushButton = new QPushButton(gridLayoutWidget);
        DividePushButton->setObjectName(QString::fromUtf8("DividePushButton"));

        KeyBoardGridLayout->addWidget(DividePushButton, 0, 1, 1, 1);

        MultiplyPushButton = new QPushButton(gridLayoutWidget);
        MultiplyPushButton->setObjectName(QString::fromUtf8("MultiplyPushButton"));

        KeyBoardGridLayout->addWidget(MultiplyPushButton, 0, 2, 1, 1);

        SubstractPushButton = new QPushButton(gridLayoutWidget);
        SubstractPushButton->setObjectName(QString::fromUtf8("SubstractPushButton"));

        KeyBoardGridLayout->addWidget(SubstractPushButton, 0, 3, 1, 1);

        AddPushButton = new QPushButton(gridLayoutWidget);
        AddPushButton->setObjectName(QString::fromUtf8("AddPushButton"));

        KeyBoardGridLayout->addWidget(AddPushButton, 0, 0, 1, 1);

        ExpressionPushButton = new QPushButton(gridLayoutWidget);
        ExpressionPushButton->setObjectName(QString::fromUtf8("ExpressionPushButton"));

        KeyBoardGridLayout->addWidget(ExpressionPushButton, 4, 2, 1, 1);

        ConstantTypeDelimiterPushButton = new QPushButton(gridLayoutWidget);
        ConstantTypeDelimiterPushButton->setObjectName(QString::fromUtf8("ConstantTypeDelimiterPushButton"));

        KeyBoardGridLayout->addWidget(ConstantTypeDelimiterPushButton, 4, 3, 1, 1);

        ComplexDelimiterPushButton = new QPushButton(gridLayoutWidget);
        ComplexDelimiterPushButton->setObjectName(QString::fromUtf8("ComplexDelimiterPushButton"));

        KeyBoardGridLayout->addWidget(ComplexDelimiterPushButton, 3, 3, 1, 1);

        EspacePushButton = new QPushButton(gridLayoutWidget);
        EspacePushButton->setObjectName(QString::fromUtf8("EspacePushButton"));

        KeyBoardGridLayout->addWidget(EspacePushButton, 2, 3, 1, 1);

        DeletePushButton = new QPushButton(gridLayoutWidget);
        DeletePushButton->setObjectName(QString::fromUtf8("DeletePushButton"));

        KeyBoardGridLayout->addWidget(DeletePushButton, 1, 3, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(510, 10, 160, 251));
        ParametresGridLayout = new QGridLayout(gridLayoutWidget_2);
        ParametresGridLayout->setSpacing(6);
        ParametresGridLayout->setContentsMargins(11, 11, 11, 11);
        ParametresGridLayout->setObjectName(QString::fromUtf8("ParametresGridLayout"));
        ParametresGridLayout->setContentsMargins(0, 0, 0, 0);
        ComplexesGroupBox = new QGroupBox(gridLayoutWidget_2);
        ComplexesGroupBox->setObjectName(QString::fromUtf8("ComplexesGroupBox"));
        ComplexesYesRadioButton = new QRadioButton(ComplexesGroupBox);
        ComplexesYesRadioButton->setObjectName(QString::fromUtf8("ComplexesYesRadioButton"));
        ComplexesYesRadioButton->setGeometry(QRect(10, 20, 82, 17));
        ComplexesNoRadioButton = new QRadioButton(ComplexesGroupBox);
        ComplexesNoRadioButton->setObjectName(QString::fromUtf8("ComplexesNoRadioButton"));
        ComplexesNoRadioButton->setGeometry(QRect(10, 40, 82, 17));
        ComplexesNoRadioButton->setChecked(true);

        ParametresGridLayout->addWidget(ComplexesGroupBox, 1, 0, 1, 1);

        AnglesGroupBox = new QGroupBox(gridLayoutWidget_2);
        AnglesGroupBox->setObjectName(QString::fromUtf8("AnglesGroupBox"));
        AnglesDegreesRadioButton = new QRadioButton(AnglesGroupBox);
        AnglesDegreesRadioButton->setObjectName(QString::fromUtf8("AnglesDegreesRadioButton"));
        AnglesDegreesRadioButton->setGeometry(QRect(10, 20, 82, 17));
        AnglesDegreesRadioButton->setChecked(true);
        AnglesRadianRadioButton = new QRadioButton(AnglesGroupBox);
        AnglesRadianRadioButton->setObjectName(QString::fromUtf8("AnglesRadianRadioButton"));
        AnglesRadianRadioButton->setGeometry(QRect(10, 40, 82, 17));

        ParametresGridLayout->addWidget(AnglesGroupBox, 2, 0, 1, 1);

        ConstantTypeGroupBox = new QGroupBox(gridLayoutWidget_2);
        ConstantTypeGroupBox->setObjectName(QString::fromUtf8("ConstantTypeGroupBox"));
        IntegerRadioButton = new QRadioButton(ConstantTypeGroupBox);
        IntegerRadioButton->setObjectName(QString::fromUtf8("IntegerRadioButton"));
        IntegerRadioButton->setGeometry(QRect(10, 20, 82, 17));
        IntegerRadioButton->setChecked(true);
        RationalRadioButton = new QRadioButton(ConstantTypeGroupBox);
        RationalRadioButton->setObjectName(QString::fromUtf8("RationalRadioButton"));
        RationalRadioButton->setGeometry(QRect(10, 40, 82, 17));
        RealRadioButton = new QRadioButton(ConstantTypeGroupBox);
        RealRadioButton->setObjectName(QString::fromUtf8("RealRadioButton"));
        RealRadioButton->setGeometry(QRect(10, 60, 82, 17));

        ParametresGridLayout->addWidget(ConstantTypeGroupBox, 0, 0, 1, 1);

        StackDisplaySizespinBox = new QSpinBox(centralWidget);
        StackDisplaySizespinBox->setObjectName(QString::fromUtf8("StackDisplaySizespinBox"));
        StackDisplaySizespinBox->setGeometry(QRect(400, 10, 42, 22));
        StackDisplaySizespinBox->setMinimum(10);
        StackDisplaySizespinBox->setMaximum(20);
        StackDisplayTextEdit = new QTextEdit(centralWidget);
        StackDisplayTextEdit->setObjectName(QString::fromUtf8("StackDisplayTextEdit"));
        StackDisplayTextEdit->setGeometry(QRect(360, 40, 121, 241));
        sizePolicy.setHeightForWidth(StackDisplayTextEdit->sizePolicy().hasHeightForWidth());
        StackDisplayTextEdit->setSizePolicy(sizePolicy);
        StackDisplayTextEdit->setBaseSize(QSize(0, 0));
        StackDisplayTextEdit->setLineWidth(1);
        StackDisplayTextEdit->setReadOnly(true);
        StackDisplayTextEdit->setTabStopWidth(80);
        StackLabel = new QLabel(centralWidget);
        StackLabel->setObjectName(QString::fromUtf8("StackLabel"));
        StackLabel->setGeometry(QRect(360, 10, 46, 21));
        QFont font;
        font.setPointSize(13);
        StackLabel->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuAffichage->addAction(actionClavier);
        menuFichier->addAction(actionQuitter);
        menuFichier->addAction(actionA_propos);
        menuEdition->addAction(actionAnnuler);
        menuEdition->addAction(actionR_tablir);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice", 0, QApplication::UnicodeUTF8));
        actionClavier->setText(QApplication::translate("MainWindow", "Clavier", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        EvalPushButton->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        SevenPushButton->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        SevenPushButton->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        FourPushButton->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        FourPushButton->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        OnePushButton->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        OnePushButton->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        EightPushButton->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        EightPushButton->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        FivePushButton->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        FivePushButton->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        TwoPushButton->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        TwoPushButton->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        ZeroPushButton->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        ZeroPushButton->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        NinePushButton->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        NinePushButton->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        SixPushButton->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        SixPushButton->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        ThreePushButton->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        ThreePushButton->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        DividePushButton->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        DividePushButton->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        MultiplyPushButton->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        MultiplyPushButton->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        SubstractPushButton->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        SubstractPushButton->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        AddPushButton->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        AddPushButton->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        ExpressionPushButton->setText(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        ExpressionPushButton->setShortcut(QApplication::translate("MainWindow", "'", 0, QApplication::UnicodeUTF8));
        ConstantTypeDelimiterPushButton->setText(QString());
        ComplexDelimiterPushButton->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        ComplexDelimiterPushButton->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        EspacePushButton->setText(QApplication::translate("MainWindow", "Espace", 0, QApplication::UnicodeUTF8));
        EspacePushButton->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        DeletePushButton->setText(QApplication::translate("MainWindow", "Effacer", 0, QApplication::UnicodeUTF8));
        ComplexesGroupBox->setTitle(QApplication::translate("MainWindow", "Complexes", 0, QApplication::UnicodeUTF8));
        ComplexesYesRadioButton->setText(QApplication::translate("MainWindow", "Oui", 0, QApplication::UnicodeUTF8));
        ComplexesNoRadioButton->setText(QApplication::translate("MainWindow", "Non", 0, QApplication::UnicodeUTF8));
        AnglesGroupBox->setTitle(QApplication::translate("MainWindow", "Angles", 0, QApplication::UnicodeUTF8));
        AnglesDegreesRadioButton->setText(QApplication::translate("MainWindow", "Degr\303\251s", 0, QApplication::UnicodeUTF8));
        AnglesRadianRadioButton->setText(QApplication::translate("MainWindow", "Radians", 0, QApplication::UnicodeUTF8));
        ConstantTypeGroupBox->setTitle(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        IntegerRadioButton->setText(QApplication::translate("MainWindow", "Entier", 0, QApplication::UnicodeUTF8));
        RationalRadioButton->setText(QApplication::translate("MainWindow", "Rationnel", 0, QApplication::UnicodeUTF8));
        RealRadioButton->setText(QApplication::translate("MainWindow", "R\303\251el", 0, QApplication::UnicodeUTF8));
        StackLabel->setText(QApplication::translate("MainWindow", "Pile", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Affichage", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
