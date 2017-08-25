/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Donate/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "Mouse_position"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 44, 4), // "item"
QT_MOC_LITERAL(5, 49, 9), // "Show_info"
QT_MOC_LITERAL(6, 59, 11), // "Insert_Show"
QT_MOC_LITERAL(7, 71, 6), // "Delete"
QT_MOC_LITERAL(8, 78, 11), // "Change_Show"
QT_MOC_LITERAL(9, 90, 12), // "Sort_student"
QT_MOC_LITERAL(10, 103, 11), // "Sort_donate"
QT_MOC_LITERAL(11, 115, 9), // "More_than"
QT_MOC_LITERAL(12, 125, 5), // "Ratio"
QT_MOC_LITERAL(13, 131, 17), // "Search_Class_show"
QT_MOC_LITERAL(14, 149, 14), // "Insert_College"
QT_MOC_LITERAL(15, 164, 12), // "Insert_Class"
QT_MOC_LITERAL(16, 177, 14), // "Insert_Student"
QT_MOC_LITERAL(17, 192, 14), // "Change_College"
QT_MOC_LITERAL(18, 207, 12), // "Change_Class"
QT_MOC_LITERAL(19, 220, 14), // "Change_Student"
QT_MOC_LITERAL(20, 235, 12) // "Search_Class"

    },
    "MainWindow\0Mouse_position\0\0QTreeWidgetItem*\0"
    "item\0Show_info\0Insert_Show\0Delete\0"
    "Change_Show\0Sort_student\0Sort_donate\0"
    "More_than\0Ratio\0Search_Class_show\0"
    "Insert_College\0Insert_Class\0Insert_Student\0"
    "Change_College\0Change_Class\0Change_Student\0"
    "Search_Class"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       5,    2,  102,    2, 0x08 /* Private */,
       6,    0,  107,    2, 0x08 /* Private */,
       7,    0,  108,    2, 0x08 /* Private */,
       8,    0,  109,    2, 0x08 /* Private */,
       9,    0,  110,    2, 0x08 /* Private */,
      10,    0,  111,    2, 0x08 /* Private */,
      11,    0,  112,    2, 0x08 /* Private */,
      12,    0,  113,    2, 0x08 /* Private */,
      13,    0,  114,    2, 0x08 /* Private */,
      14,    0,  115,    2, 0x08 /* Private */,
      15,    0,  116,    2, 0x08 /* Private */,
      16,    0,  117,    2, 0x08 /* Private */,
      17,    0,  118,    2, 0x08 /* Private */,
      18,    0,  119,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Mouse_position((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->Show_info((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->Insert_Show(); break;
        case 3: _t->Delete(); break;
        case 4: _t->Change_Show(); break;
        case 5: _t->Sort_student(); break;
        case 6: _t->Sort_donate(); break;
        case 7: _t->More_than(); break;
        case 8: _t->Ratio(); break;
        case 9: _t->Search_Class_show(); break;
        case 10: _t->Insert_College(); break;
        case 11: _t->Insert_Class(); break;
        case 12: _t->Insert_Student(); break;
        case 13: _t->Change_College(); break;
        case 14: _t->Change_Class(); break;
        case 15: _t->Change_Student(); break;
        case 16: _t->Search_Class(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
