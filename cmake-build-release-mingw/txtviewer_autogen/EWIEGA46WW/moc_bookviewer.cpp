/****************************************************************************
** Meta object code from reading C++ file 'bookviewer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../bookviewer.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bookviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSbookviewerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSbookviewerENDCLASS = QtMocHelpers::stringData(
    "bookviewer",
    "nextchapter",
    "",
    "prevchapter",
    "showchapter",
    "showbyclick",
    "QListWidgetItem*",
    "item",
    "setupbutton",
    "applysetup",
    "setups"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSbookviewerENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[12];
    char stringdata5[12];
    char stringdata6[17];
    char stringdata7[5];
    char stringdata8[12];
    char stringdata9[11];
    char stringdata10[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSbookviewerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSbookviewerENDCLASS_t qt_meta_stringdata_CLASSbookviewerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "bookviewer"
        QT_MOC_LITERAL(11, 11),  // "nextchapter"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 11),  // "prevchapter"
        QT_MOC_LITERAL(36, 11),  // "showchapter"
        QT_MOC_LITERAL(48, 11),  // "showbyclick"
        QT_MOC_LITERAL(60, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(77, 4),  // "item"
        QT_MOC_LITERAL(82, 11),  // "setupbutton"
        QT_MOC_LITERAL(94, 10),  // "applysetup"
        QT_MOC_LITERAL(105, 6)   // "setups"
    },
    "bookviewer",
    "nextchapter",
    "",
    "prevchapter",
    "showchapter",
    "showbyclick",
    "QListWidgetItem*",
    "item",
    "setupbutton",
    "applysetup",
    "setups"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSbookviewerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    1,   53,    2, 0x08,    4 /* Private */,
       8,    0,   56,    2, 0x08,    6 /* Private */,
       9,    1,   57,    2, 0x0a,    7 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject bookviewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSbookviewerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSbookviewerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSbookviewerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<bookviewer, std::true_type>,
        // method 'nextchapter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'prevchapter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showchapter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showbyclick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'setupbutton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'applysetup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QString> &, std::false_type>
    >,
    nullptr
} };

void bookviewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bookviewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nextchapter(); break;
        case 1: _t->prevchapter(); break;
        case 2: _t->showchapter(); break;
        case 3: _t->showbyclick((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 4: _t->setupbutton(); break;
        case 5: _t->applysetup((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *bookviewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bookviewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSbookviewerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int bookviewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
