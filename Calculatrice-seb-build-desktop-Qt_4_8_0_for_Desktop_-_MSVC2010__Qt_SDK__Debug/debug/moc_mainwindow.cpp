/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon 4. Jun 09:59:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   11,   12,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     177,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     251,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     315,   11,   11,   11, 0x08,
     345,   11,   11,   11, 0x08,
     375,   11,   11,   11, 0x08,
     407,   11,   11,   11, 0x08,
     440,   11,   11,   11, 0x08,
     474,   11,   11,   11, 0x08,
     502,   11,   11,   11, 0x08,
     531,   11,   11,   11, 0x08,
     560,   11,   11,   11, 0x08,
     587,   11,   11,   11, 0x08,
     615,   11,   11,   11, 0x08,
     643,   11,   11,   11, 0x08,
     672,   11,   11,   11, 0x08,
     699,   11,   11,   11, 0x08,
     726,   11,   11,   11, 0x08,
     754,   11,   11,   11, 0x08,
     794,   11,   11,   11, 0x08,
     839,   11,   11,   11, 0x08,
     872,  867,   11,   11, 0x08,
     917,   11,   11,   11, 0x08,
     947,   11,   11,   11, 0x08,
     980,  867,   11,   11, 0x08,
    1018,   11,   11,   11, 0x08,
    1048,   11,   11,   11, 0x08,
    1076,   11,   11,   11, 0x08,
    1103,   11,   11,   11, 0x08,
    1131,   11,   11,   11, 0x08,
    1158,   11,   11,   11, 0x08,
    1186,   11,   11,   11, 0x08,
    1215,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0QKeyEvent*\0keyPressed(QKeyEvent*)\0"
    "on_IntegerRadioButton_clicked()\0"
    "on_RationalRadioButton_clicked()\0"
    "on_RealRadioButton_clicked()\0"
    "on_ComplexesYesRadioButton_clicked()\0"
    "on_ComplexesNoRadioButton_clicked()\0"
    "on_AnglesDegreesRadioButton_clicked()\0"
    "on_AnglesRadianRadioButton_clicked()\0"
    "on_AddPushButton_clicked()\0"
    "on_EspacePushButton_clicked()\0"
    "on_DividePushButton_clicked()\0"
    "on_MultiplyPushButton_clicked()\0"
    "on_SubstractPushButton_clicked()\0"
    "on_ExpressionPushButton_clicked()\0"
    "on_NinePushButton_clicked()\0"
    "on_EightPushButton_clicked()\0"
    "on_SevenPushButton_clicked()\0"
    "on_SixPushButton_clicked()\0"
    "on_FivePushButton_clicked()\0"
    "on_FourPushButton_clicked()\0"
    "on_ThreePushButton_clicked()\0"
    "on_TwoPushButton_clicked()\0"
    "on_OnePushButton_clicked()\0"
    "on_ZeroPushButton_clicked()\0"
    "on_ComplexDelimiterPushButton_clicked()\0"
    "on_ConstantTypeDelimiterPushButton_clicked()\0"
    "on_EvalPushButton_clicked()\0arg1\0"
    "on_StackDisplaySizespinBox_valueChanged(int)\0"
    "on_DeletePushButton_clicked()\0"
    "on_InputLineEdit_returnPressed()\0"
    "on_InputLineEdit_textChanged(QString)\0"
    "on_ReturnPushButton_clicked()\0"
    "on_DropPushButton_clicked()\0"
    "on_SumPushButton_clicked()\0"
    "on_MeanPushButton_clicked()\0"
    "on_DupPushButton_clicked()\0"
    "on_SwapPushButton_clicked()\0"
    "on_ClearPushButton_clicked()\0"
    "keyPressEvent(QKeyEvent*)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: { QKeyEvent* _r = _t->keyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QKeyEvent**>(_a[0]) = _r; }  break;
        case 1: _t->on_IntegerRadioButton_clicked(); break;
        case 2: _t->on_RationalRadioButton_clicked(); break;
        case 3: _t->on_RealRadioButton_clicked(); break;
        case 4: _t->on_ComplexesYesRadioButton_clicked(); break;
        case 5: _t->on_ComplexesNoRadioButton_clicked(); break;
        case 6: _t->on_AnglesDegreesRadioButton_clicked(); break;
        case 7: _t->on_AnglesRadianRadioButton_clicked(); break;
        case 8: _t->on_AddPushButton_clicked(); break;
        case 9: _t->on_EspacePushButton_clicked(); break;
        case 10: _t->on_DividePushButton_clicked(); break;
        case 11: _t->on_MultiplyPushButton_clicked(); break;
        case 12: _t->on_SubstractPushButton_clicked(); break;
        case 13: _t->on_ExpressionPushButton_clicked(); break;
        case 14: _t->on_NinePushButton_clicked(); break;
        case 15: _t->on_EightPushButton_clicked(); break;
        case 16: _t->on_SevenPushButton_clicked(); break;
        case 17: _t->on_SixPushButton_clicked(); break;
        case 18: _t->on_FivePushButton_clicked(); break;
        case 19: _t->on_FourPushButton_clicked(); break;
        case 20: _t->on_ThreePushButton_clicked(); break;
        case 21: _t->on_TwoPushButton_clicked(); break;
        case 22: _t->on_OnePushButton_clicked(); break;
        case 23: _t->on_ZeroPushButton_clicked(); break;
        case 24: _t->on_ComplexDelimiterPushButton_clicked(); break;
        case 25: _t->on_ConstantTypeDelimiterPushButton_clicked(); break;
        case 26: _t->on_EvalPushButton_clicked(); break;
        case 27: _t->on_StackDisplaySizespinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_DeletePushButton_clicked(); break;
        case 29: _t->on_InputLineEdit_returnPressed(); break;
        case 30: _t->on_InputLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->on_ReturnPushButton_clicked(); break;
        case 32: _t->on_DropPushButton_clicked(); break;
        case 33: _t->on_SumPushButton_clicked(); break;
        case 34: _t->on_MeanPushButton_clicked(); break;
        case 35: _t->on_DupPushButton_clicked(); break;
        case 36: _t->on_SwapPushButton_clicked(); break;
        case 37: _t->on_ClearPushButton_clicked(); break;
        case 38: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
QKeyEvent * MainWindow::keyPressed(QKeyEvent * _t1)
{
    QKeyEvent* _t0;
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
