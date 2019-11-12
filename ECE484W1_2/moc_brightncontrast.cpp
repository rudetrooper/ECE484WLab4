/****************************************************************************
** Meta object code from reading C++ file 'brightncontrast.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "brightncontrast.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'brightncontrast.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BrightNContrast_t {
    QByteArrayData data[17];
    char stringdata0[318];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrightNContrast_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrightNContrast_t qt_meta_stringdata_BrightNContrast = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BrightNContrast"
QT_MOC_LITERAL(1, 16, 23), // "on_LoadOriginal_clicked"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 22), // "on_LoadOverlay_clicked"
QT_MOC_LITERAL(4, 64, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 86, 27), // "on_TransferOriginal_clicked"
QT_MOC_LITERAL(6, 114, 26), // "on_TransferOverlay_clicked"
QT_MOC_LITERAL(7, 141, 15), // "on_closeOverlay"
QT_MOC_LITERAL(8, 157, 30), // "on_BrightSlider_sliderReleased"
QT_MOC_LITERAL(9, 188, 32), // "on_ContrastSlider_sliderReleased"
QT_MOC_LITERAL(10, 221, 28), // "on_BrightSlider_valueChanged"
QT_MOC_LITERAL(11, 250, 8), // "position"
QT_MOC_LITERAL(12, 259, 30), // "on_ContrastSlider_valueChanged"
QT_MOC_LITERAL(13, 290, 5), // "value"
QT_MOC_LITERAL(14, 296, 9), // "SendImage"
QT_MOC_LITERAL(15, 306, 7), // "QImage*"
QT_MOC_LITERAL(16, 314, 3) // "img"

    },
    "BrightNContrast\0on_LoadOriginal_clicked\0"
    "\0on_LoadOverlay_clicked\0on_pushButton_clicked\0"
    "on_TransferOriginal_clicked\0"
    "on_TransferOverlay_clicked\0on_closeOverlay\0"
    "on_BrightSlider_sliderReleased\0"
    "on_ContrastSlider_sliderReleased\0"
    "on_BrightSlider_valueChanged\0position\0"
    "on_ContrastSlider_valueChanged\0value\0"
    "SendImage\0QImage*\0img"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrightNContrast[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    1,   77,    2, 0x08 /* Private */,
      12,    1,   80,    2, 0x08 /* Private */,
      14,    1,   83,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void BrightNContrast::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BrightNContrast *_t = static_cast<BrightNContrast *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_LoadOriginal_clicked(); break;
        case 1: _t->on_LoadOverlay_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_TransferOriginal_clicked(); break;
        case 4: _t->on_TransferOverlay_clicked(); break;
        case 5: _t->on_closeOverlay(); break;
        case 6: _t->on_BrightSlider_sliderReleased(); break;
        case 7: _t->on_ContrastSlider_sliderReleased(); break;
        case 8: _t->on_BrightSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_ContrastSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->SendImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BrightNContrast::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BrightNContrast.data,
      qt_meta_data_BrightNContrast,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BrightNContrast::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrightNContrast::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BrightNContrast.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BrightNContrast::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
