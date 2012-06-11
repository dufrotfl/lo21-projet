/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 10. Jun 10:37:15 2012
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
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
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
    QPushButton *ReturnPushButton;
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
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout;
    QPushButton *PowPushButton;
    QPushButton *SinPushButton;
    QPushButton *CosPushButton;
    QPushButton *TanPushButton;
    QPushButton *LnPushButton;
    QPushButton *LogPushButton;
    QPushButton *InvPushButton;
    QPushButton *SinhPushButton;
    QPushButton *CoshPushButton;
    QPushButton *TanhPushButton;
    QPushButton *ModPushButton;
    QPushButton *SignPushButton;
    QPushButton *SqrPushButton;
    QPushButton *CubePushButton;
    QPushButton *SqrtPushButton;
    QPushButton *FactPushButton;
    QWidget *gridLayoutWidget_4;
    QGridLayout *PileOpGridLayout;
    QPushButton *SumPushButton;
    QPushButton *MeanPushButton;
    QPushButton *ClearPushButton;
    QPushButton *DupPushButton;
    QPushButton *DropPushButton;
    QPushButton *EvalPushButton;
    QSpacerItem *verticalSpacer;
    QPushButton *SwapPushButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuAffichage;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 376);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 376));
        MainWindow->setMaximumSize(QSize(800, 376));
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
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 311, 25));
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

        ReturnPushButton = new QPushButton(horizontalLayoutWidget);
        ReturnPushButton->setObjectName(QString::fromUtf8("ReturnPushButton"));

        inputHorizontalLayout->addWidget(ReturnPushButton);

        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 50, 320, 170));
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
        QFont font;
        font.setPointSize(8);
        font.setKerning(true);
        EspacePushButton->setFont(font);

        KeyBoardGridLayout->addWidget(EspacePushButton, 2, 3, 1, 1);

        DeletePushButton = new QPushButton(gridLayoutWidget);
        DeletePushButton->setObjectName(QString::fromUtf8("DeletePushButton"));

        KeyBoardGridLayout->addWidget(DeletePushButton, 1, 3, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(620, 10, 160, 251));
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
        StackDisplaySizespinBox->setGeometry(QRect(470, 270, 42, 22));
        StackDisplaySizespinBox->setMinimum(10);
        StackDisplaySizespinBox->setMaximum(20);
        StackDisplayTextEdit = new QTextEdit(centralWidget);
        StackDisplayTextEdit->setObjectName(QString::fromUtf8("StackDisplayTextEdit"));
        StackDisplayTextEdit->setGeometry(QRect(390, 10, 121, 251));
        sizePolicy.setHeightForWidth(StackDisplayTextEdit->sizePolicy().hasHeightForWidth());
        StackDisplayTextEdit->setSizePolicy(sizePolicy);
        StackDisplayTextEdit->setBaseSize(QSize(0, 0));
        StackDisplayTextEdit->setLineWidth(1);
        StackDisplayTextEdit->setReadOnly(true);
        StackDisplayTextEdit->setTabStopWidth(80);
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 220, 321, 111));
        gridLayout = new QGridLayout(gridLayoutWidget_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        PowPushButton = new QPushButton(gridLayoutWidget_3);
        PowPushButton->setObjectName(QString::fromUtf8("PowPushButton"));

        gridLayout->addWidget(PowPushButton, 0, 0, 1, 1);

        SinPushButton = new QPushButton(gridLayoutWidget_3);
        SinPushButton->setObjectName(QString::fromUtf8("SinPushButton"));

        gridLayout->addWidget(SinPushButton, 1, 0, 1, 1);

        CosPushButton = new QPushButton(gridLayoutWidget_3);
        CosPushButton->setObjectName(QString::fromUtf8("CosPushButton"));

        gridLayout->addWidget(CosPushButton, 1, 1, 1, 1);

        TanPushButton = new QPushButton(gridLayoutWidget_3);
        TanPushButton->setObjectName(QString::fromUtf8("TanPushButton"));

        gridLayout->addWidget(TanPushButton, 1, 2, 1, 1);

        LnPushButton = new QPushButton(gridLayoutWidget_3);
        LnPushButton->setObjectName(QString::fromUtf8("LnPushButton"));

        gridLayout->addWidget(LnPushButton, 3, 0, 1, 1);

        LogPushButton = new QPushButton(gridLayoutWidget_3);
        LogPushButton->setObjectName(QString::fromUtf8("LogPushButton"));

        gridLayout->addWidget(LogPushButton, 3, 1, 1, 1);

        InvPushButton = new QPushButton(gridLayoutWidget_3);
        InvPushButton->setObjectName(QString::fromUtf8("InvPushButton"));

        gridLayout->addWidget(InvPushButton, 3, 2, 1, 1);

        SinhPushButton = new QPushButton(gridLayoutWidget_3);
        SinhPushButton->setObjectName(QString::fromUtf8("SinhPushButton"));

        gridLayout->addWidget(SinhPushButton, 1, 3, 1, 1);

        CoshPushButton = new QPushButton(gridLayoutWidget_3);
        CoshPushButton->setObjectName(QString::fromUtf8("CoshPushButton"));

        gridLayout->addWidget(CoshPushButton, 1, 4, 1, 1);

        TanhPushButton = new QPushButton(gridLayoutWidget_3);
        TanhPushButton->setObjectName(QString::fromUtf8("TanhPushButton"));

        gridLayout->addWidget(TanhPushButton, 1, 5, 1, 1);

        ModPushButton = new QPushButton(gridLayoutWidget_3);
        ModPushButton->setObjectName(QString::fromUtf8("ModPushButton"));

        gridLayout->addWidget(ModPushButton, 0, 5, 1, 1);

        SignPushButton = new QPushButton(gridLayoutWidget_3);
        SignPushButton->setObjectName(QString::fromUtf8("SignPushButton"));

        gridLayout->addWidget(SignPushButton, 0, 4, 1, 1);

        SqrPushButton = new QPushButton(gridLayoutWidget_3);
        SqrPushButton->setObjectName(QString::fromUtf8("SqrPushButton"));

        gridLayout->addWidget(SqrPushButton, 0, 1, 1, 1);

        CubePushButton = new QPushButton(gridLayoutWidget_3);
        CubePushButton->setObjectName(QString::fromUtf8("CubePushButton"));

        gridLayout->addWidget(CubePushButton, 0, 2, 1, 1);

        SqrtPushButton = new QPushButton(gridLayoutWidget_3);
        SqrtPushButton->setObjectName(QString::fromUtf8("SqrtPushButton"));

        gridLayout->addWidget(SqrtPushButton, 0, 3, 1, 1);

        FactPushButton = new QPushButton(gridLayoutWidget_3);
        FactPushButton->setObjectName(QString::fromUtf8("FactPushButton"));

        gridLayout->addWidget(FactPushButton, 3, 3, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(530, 10, 77, 251));
        PileOpGridLayout = new QGridLayout(gridLayoutWidget_4);
        PileOpGridLayout->setSpacing(6);
        PileOpGridLayout->setContentsMargins(11, 11, 11, 11);
        PileOpGridLayout->setObjectName(QString::fromUtf8("PileOpGridLayout"));
        PileOpGridLayout->setContentsMargins(0, 0, 0, 0);
        SumPushButton = new QPushButton(gridLayoutWidget_4);
        SumPushButton->setObjectName(QString::fromUtf8("SumPushButton"));

        PileOpGridLayout->addWidget(SumPushButton, 1, 0, 1, 1);

        MeanPushButton = new QPushButton(gridLayoutWidget_4);
        MeanPushButton->setObjectName(QString::fromUtf8("MeanPushButton"));

        PileOpGridLayout->addWidget(MeanPushButton, 2, 0, 1, 1);

        ClearPushButton = new QPushButton(gridLayoutWidget_4);
        ClearPushButton->setObjectName(QString::fromUtf8("ClearPushButton"));

        PileOpGridLayout->addWidget(ClearPushButton, 5, 0, 1, 1);

        DupPushButton = new QPushButton(gridLayoutWidget_4);
        DupPushButton->setObjectName(QString::fromUtf8("DupPushButton"));

        PileOpGridLayout->addWidget(DupPushButton, 7, 0, 1, 1);

        DropPushButton = new QPushButton(gridLayoutWidget_4);
        DropPushButton->setObjectName(QString::fromUtf8("DropPushButton"));

        PileOpGridLayout->addWidget(DropPushButton, 8, 0, 1, 1);

        EvalPushButton = new QPushButton(gridLayoutWidget_4);
        EvalPushButton->setObjectName(QString::fromUtf8("EvalPushButton"));

        PileOpGridLayout->addWidget(EvalPushButton, 10, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        PileOpGridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        SwapPushButton = new QPushButton(gridLayoutWidget_4);
        SwapPushButton->setObjectName(QString::fromUtf8("SwapPushButton"));

        PileOpGridLayout->addWidget(SwapPushButton, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        PileOpGridLayout->addItem(verticalSpacer_2, 4, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 270, 71, 16));
        QFont font1;
        font1.setPointSize(10);
        label->setFont(font1);
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
        QObject::connect(actionQuitter, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice", 0, QApplication::UnicodeUTF8));
        actionClavier->setText(QApplication::translate("MainWindow", "Clavier", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("MainWindow", "A propos", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setText(QApplication::translate("MainWindow", "Annuler", 0, QApplication::UnicodeUTF8));
        actionAnnuler->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setText(QApplication::translate("MainWindow", "R\303\251tablir", 0, QApplication::UnicodeUTF8));
        actionR_tablir->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        ReturnPushButton->setText(QApplication::translate("MainWindow", "RETURN", 0, QApplication::UnicodeUTF8));
        ReturnPushButton->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
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
        EspacePushButton->setText(QApplication::translate("MainWindow", "SPACE", 0, QApplication::UnicodeUTF8));
        EspacePushButton->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        DeletePushButton->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
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
        PowPushButton->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        SinPushButton->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        CosPushButton->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        TanPushButton->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        LnPushButton->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        LogPushButton->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        InvPushButton->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        SinhPushButton->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        CoshPushButton->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        TanhPushButton->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        ModPushButton->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        SignPushButton->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        SqrPushButton->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        CubePushButton->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        SqrtPushButton->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        FactPushButton->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        SumPushButton->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        MeanPushButton->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        ClearPushButton->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        ClearPushButton->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        DupPushButton->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        DropPushButton->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        EvalPushButton->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        SwapPushButton->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Affichage:", 0, QApplication::UnicodeUTF8));
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
