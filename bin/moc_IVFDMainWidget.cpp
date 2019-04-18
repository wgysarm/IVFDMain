/****************************************************************************
** Meta object code from reading C++ file 'IVFDMainWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../IVFDMainWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IVFDMainWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IVFDMainWidget_t {
    QByteArrayData data[148];
    char stringdata[2603];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IVFDMainWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IVFDMainWidget_t qt_meta_stringdata_IVFDMainWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "IVFDMainWidget"
QT_MOC_LITERAL(1, 15, 20), // "SIG_StartProcessMain"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 22), // "SIG_RestartProcessMain"
QT_MOC_LITERAL(4, 60, 19), // "SIG_KillProcessMain"
QT_MOC_LITERAL(5, 80, 18), // "SIG_StartHeartBeat"
QT_MOC_LITERAL(6, 99, 17), // "SIG_StopHeartBeat"
QT_MOC_LITERAL(7, 117, 23), // "SIG_StartLocalTcpServer"
QT_MOC_LITERAL(8, 141, 22), // "SIG_StopLocalTcpServer"
QT_MOC_LITERAL(9, 164, 19), // "SIG_StartProcessFtp"
QT_MOC_LITERAL(10, 184, 8), // "hostAddr"
QT_MOC_LITERAL(11, 193, 5), // "portn"
QT_MOC_LITERAL(12, 199, 8), // "username"
QT_MOC_LITERAL(13, 208, 8), // "password"
QT_MOC_LITERAL(14, 217, 8), // "rootpath"
QT_MOC_LITERAL(15, 226, 21), // "SIG_RestartProcessFtp"
QT_MOC_LITERAL(16, 248, 8), // "hostaddr"
QT_MOC_LITERAL(17, 257, 18), // "SIG_StopProcessFtp"
QT_MOC_LITERAL(18, 276, 26), // "SIG_StartProcessHttpServer"
QT_MOC_LITERAL(19, 303, 28), // "SIG_RestartProcessHttpServer"
QT_MOC_LITERAL(20, 332, 25), // "SIG_StopProcessHttpServer"
QT_MOC_LITERAL(21, 358, 20), // "SIG_StartProcessRtsp"
QT_MOC_LITERAL(22, 379, 22), // "SIG_RestartProcessRtsp"
QT_MOC_LITERAL(23, 402, 19), // "SIG_StopProcessRtsp"
QT_MOC_LITERAL(24, 422, 16), // "SIG_KillMainSelf"
QT_MOC_LITERAL(25, 439, 23), // "SIG_XParseTcpServerRecv"
QT_MOC_LITERAL(26, 463, 27), // "SIG_XParseCMDFromHttpServer"
QT_MOC_LITERAL(27, 491, 32), // "SIG_XParseAlgOutFromDipTcpClient"
QT_MOC_LITERAL(28, 524, 31), // "SIG_XParseMsgFromTerminalCLient"
QT_MOC_LITERAL(29, 556, 20), // "SIG_XParseGeneralMsg"
QT_MOC_LITERAL(30, 577, 22), // "SIG_SendCMDToDIPServer"
QT_MOC_LITERAL(31, 600, 10), // "serverAddr"
QT_MOC_LITERAL(32, 611, 10), // "serverPort"
QT_MOC_LITERAL(33, 622, 4), // "data"
QT_MOC_LITERAL(34, 627, 20), // "SIG_TellClientToSend"
QT_MOC_LITERAL(35, 648, 14), // "SIG_ClearAlarm"
QT_MOC_LITERAL(36, 663, 18), // "SIG_CmdFromBrowser"
QT_MOC_LITERAL(37, 682, 19), // "SIG_SetInitFilesVal"
QT_MOC_LITERAL(38, 702, 8), // "ECMDTYPE"
QT_MOC_LITERAL(39, 711, 6), // "EHWVAL"
QT_MOC_LITERAL(40, 718, 2), // "id"
QT_MOC_LITERAL(41, 721, 3), // "val"
QT_MOC_LITERAL(42, 725, 17), // "SIG_NoIdentityCmd"
QT_MOC_LITERAL(43, 743, 11), // "SIG_Control"
QT_MOC_LITERAL(44, 755, 16), // "SIG_SetByteArray"
QT_MOC_LITERAL(45, 772, 7), // "EBAITEM"
QT_MOC_LITERAL(46, 780, 5), // "baval"
QT_MOC_LITERAL(47, 786, 14), // "SIG_UploadFile"
QT_MOC_LITERAL(48, 801, 9), // "EFILEITEM"
QT_MOC_LITERAL(49, 811, 14), // "SIG_GetSysInfo"
QT_MOC_LITERAL(50, 826, 9), // "EREADITEM"
QT_MOC_LITERAL(51, 836, 27), // "SIG_SendCMDTypeAnd0ValToDIP"
QT_MOC_LITERAL(52, 864, 7), // "cmdtype"
QT_MOC_LITERAL(53, 872, 27), // "SIG_SendCMDTypeAnd1ValToDIP"
QT_MOC_LITERAL(54, 900, 27), // "SIG_SendCMDTypeAnd2ValToDIP"
QT_MOC_LITERAL(55, 928, 4), // "val1"
QT_MOC_LITERAL(56, 933, 4), // "val2"
QT_MOC_LITERAL(57, 938, 27), // "SIG_SendCMDTypeAnd3ValToDIP"
QT_MOC_LITERAL(58, 966, 4), // "val3"
QT_MOC_LITERAL(59, 971, 27), // "SIG_SendCMDTypeAnd4ValToDIP"
QT_MOC_LITERAL(60, 999, 4), // "val4"
QT_MOC_LITERAL(61, 1004, 15), // "SIG_StartAlgDet"
QT_MOC_LITERAL(62, 1020, 5), // "algId"
QT_MOC_LITERAL(63, 1026, 17), // "SIG_CapureYUVFile"
QT_MOC_LITERAL(64, 1044, 3), // "num"
QT_MOC_LITERAL(65, 1048, 22), // "SIG_SetCameraParameter"
QT_MOC_LITERAL(66, 1071, 4), // "name"
QT_MOC_LITERAL(67, 1076, 22), // "SIG_SetDIPAlgParameter"
QT_MOC_LITERAL(68, 1099, 7), // "algtype"
QT_MOC_LITERAL(69, 1107, 14), // "SIG_SetGPIOOUT"
QT_MOC_LITERAL(70, 1122, 3), // "pin"
QT_MOC_LITERAL(71, 1126, 25), // "SIG_AnswerCmdToHttpServer"
QT_MOC_LITERAL(72, 1152, 6), // "answer"
QT_MOC_LITERAL(73, 1159, 19), // "SIG_UpdateTimeStamp"
QT_MOC_LITERAL(74, 1179, 26), // "SIG_SendAlgOutToPlatServer"
QT_MOC_LITERAL(75, 1206, 4), // "addr"
QT_MOC_LITERAL(76, 1211, 12), // "SIG_SysReset"
QT_MOC_LITERAL(77, 1224, 12), // "SIG_AppReset"
QT_MOC_LITERAL(78, 1237, 13), // "SIG_SysUpdate"
QT_MOC_LITERAL(79, 1251, 13), // "SIG_AppUpdate"
QT_MOC_LITERAL(80, 1265, 13), // "SIG_AppBackup"
QT_MOC_LITERAL(81, 1279, 13), // "SIG_AppUpload"
QT_MOC_LITERAL(82, 1293, 12), // "SIG_AdjustXY"
QT_MOC_LITERAL(83, 1306, 17), // "SIG_CommandExcute"
QT_MOC_LITERAL(84, 1324, 24), // "SLOT_ProcessMainFinished"
QT_MOC_LITERAL(85, 1349, 8), // "exitCode"
QT_MOC_LITERAL(86, 1358, 20), // "QProcess::ExitStatus"
QT_MOC_LITERAL(87, 1379, 10), // "exitStatus"
QT_MOC_LITERAL(88, 1390, 23), // "SLOT_ProcessFtpFinished"
QT_MOC_LITERAL(89, 1414, 24), // "SLOT_ProcessHttpFinished"
QT_MOC_LITERAL(90, 1439, 24), // "SLOT_ProcessRtspFinished"
QT_MOC_LITERAL(91, 1464, 26), // "SLOT_ProcessSystemFinished"
QT_MOC_LITERAL(92, 1491, 24), // "SLOT_StartLocalTcpServer"
QT_MOC_LITERAL(93, 1516, 23), // "SLOT_StopLocalTcpServer"
QT_MOC_LITERAL(94, 1540, 21), // "SLOT_StartProcessMain"
QT_MOC_LITERAL(95, 1562, 23), // "SLOT_RestartProcessMain"
QT_MOC_LITERAL(96, 1586, 20), // "SLOT_KillProcessMain"
QT_MOC_LITERAL(97, 1607, 20), // "SLOT_StartProcessFtp"
QT_MOC_LITERAL(98, 1628, 22), // "SLOT_RestartProcessFtp"
QT_MOC_LITERAL(99, 1651, 19), // "SLOT_StopProcessFtp"
QT_MOC_LITERAL(100, 1671, 22), // "SLOT_ProcessFtpStarted"
QT_MOC_LITERAL(101, 1694, 27), // "SLOT_StartProcessHttpServer"
QT_MOC_LITERAL(102, 1722, 29), // "SLOT_RestartProcessHttpServer"
QT_MOC_LITERAL(103, 1752, 26), // "SLOT_StopProcessHttpServer"
QT_MOC_LITERAL(104, 1779, 21), // "SLOT_StartProcessRtsp"
QT_MOC_LITERAL(105, 1801, 23), // "SLOT_RestartProcessRtsp"
QT_MOC_LITERAL(106, 1825, 20), // "SLOT_StopProcessRtsp"
QT_MOC_LITERAL(107, 1846, 17), // "SLOT_KillMainSelf"
QT_MOC_LITERAL(108, 1864, 24), // "SLOT_XParseTcpServerRecv"
QT_MOC_LITERAL(109, 1889, 2), // "ba"
QT_MOC_LITERAL(110, 1892, 28), // "SLOT_XParseCMDFromHttpServer"
QT_MOC_LITERAL(111, 1921, 33), // "SLOT_XParseAlgOutFromDipTcpCl..."
QT_MOC_LITERAL(112, 1955, 32), // "SLOT_XParseMsgFromTerminalCLient"
QT_MOC_LITERAL(113, 1988, 21), // "SLOT_XParseGeneralMsg"
QT_MOC_LITERAL(114, 2010, 23), // "SLOT_SendCMDToDIPServer"
QT_MOC_LITERAL(115, 2034, 12), // "SLOT_Started"
QT_MOC_LITERAL(116, 2047, 20), // "SLOT_SetInitFilesVal"
QT_MOC_LITERAL(117, 2068, 18), // "SLOT_NoIdentityCmd"
QT_MOC_LITERAL(118, 2087, 12), // "SLOT_Control"
QT_MOC_LITERAL(119, 2100, 15), // "SLOT_GetSysInfo"
QT_MOC_LITERAL(120, 2116, 17), // "SLOT_SetByteArray"
QT_MOC_LITERAL(121, 2134, 7), // "ebaitem"
QT_MOC_LITERAL(122, 2142, 15), // "SLOT_UploadFile"
QT_MOC_LITERAL(123, 2158, 28), // "SLOT_SendCMDTypeAnd0ValToDIP"
QT_MOC_LITERAL(124, 2187, 28), // "SLOT_SendCMDTypeAnd1ValToDIP"
QT_MOC_LITERAL(125, 2216, 28), // "SLOT_SendCMDTypeAnd2ValToDIP"
QT_MOC_LITERAL(126, 2245, 28), // "SLOT_SendCMDTypeAnd3ValToDIP"
QT_MOC_LITERAL(127, 2274, 28), // "SLOT_SendCMDTypeAnd4ValToDIP"
QT_MOC_LITERAL(128, 2303, 16), // "SLOT_StartAlgDet"
QT_MOC_LITERAL(129, 2320, 18), // "SLOT_CapureYUVFile"
QT_MOC_LITERAL(130, 2339, 23), // "SLOT_SetCameraParameter"
QT_MOC_LITERAL(131, 2363, 15), // "SLOT_SetGPIOOUT"
QT_MOC_LITERAL(132, 2379, 23), // "SLOT_SetDIPAlgParameter"
QT_MOC_LITERAL(133, 2403, 15), // "SLOT_ClearAlarm"
QT_MOC_LITERAL(134, 2419, 27), // "SLOT_SendAlgOutToPlatServer"
QT_MOC_LITERAL(135, 2447, 13), // "SLOT_SysReset"
QT_MOC_LITERAL(136, 2461, 13), // "SLOT_AppReset"
QT_MOC_LITERAL(137, 2475, 14), // "SLOT_SysUpdate"
QT_MOC_LITERAL(138, 2490, 14), // "SLOT_AppUpdate"
QT_MOC_LITERAL(139, 2505, 6), // "fileid"
QT_MOC_LITERAL(140, 2512, 14), // "SLOT_AppBackup"
QT_MOC_LITERAL(141, 2527, 14), // "SLOT_AppUpload"
QT_MOC_LITERAL(142, 2542, 13), // "SLOT_AdjustXY"
QT_MOC_LITERAL(143, 2556, 3), // "adj"
QT_MOC_LITERAL(144, 2560, 12), // "SLOT_Offline"
QT_MOC_LITERAL(145, 2573, 6), // "online"
QT_MOC_LITERAL(146, 2580, 18), // "SLOT_CommandExcute"
QT_MOC_LITERAL(147, 2599, 3) // "cmd"

    },
    "IVFDMainWidget\0SIG_StartProcessMain\0"
    "\0SIG_RestartProcessMain\0SIG_KillProcessMain\0"
    "SIG_StartHeartBeat\0SIG_StopHeartBeat\0"
    "SIG_StartLocalTcpServer\0SIG_StopLocalTcpServer\0"
    "SIG_StartProcessFtp\0hostAddr\0portn\0"
    "username\0password\0rootpath\0"
    "SIG_RestartProcessFtp\0hostaddr\0"
    "SIG_StopProcessFtp\0SIG_StartProcessHttpServer\0"
    "SIG_RestartProcessHttpServer\0"
    "SIG_StopProcessHttpServer\0"
    "SIG_StartProcessRtsp\0SIG_RestartProcessRtsp\0"
    "SIG_StopProcessRtsp\0SIG_KillMainSelf\0"
    "SIG_XParseTcpServerRecv\0"
    "SIG_XParseCMDFromHttpServer\0"
    "SIG_XParseAlgOutFromDipTcpClient\0"
    "SIG_XParseMsgFromTerminalCLient\0"
    "SIG_XParseGeneralMsg\0SIG_SendCMDToDIPServer\0"
    "serverAddr\0serverPort\0data\0"
    "SIG_TellClientToSend\0SIG_ClearAlarm\0"
    "SIG_CmdFromBrowser\0SIG_SetInitFilesVal\0"
    "ECMDTYPE\0EHWVAL\0id\0val\0SIG_NoIdentityCmd\0"
    "SIG_Control\0SIG_SetByteArray\0EBAITEM\0"
    "baval\0SIG_UploadFile\0EFILEITEM\0"
    "SIG_GetSysInfo\0EREADITEM\0"
    "SIG_SendCMDTypeAnd0ValToDIP\0cmdtype\0"
    "SIG_SendCMDTypeAnd1ValToDIP\0"
    "SIG_SendCMDTypeAnd2ValToDIP\0val1\0val2\0"
    "SIG_SendCMDTypeAnd3ValToDIP\0val3\0"
    "SIG_SendCMDTypeAnd4ValToDIP\0val4\0"
    "SIG_StartAlgDet\0algId\0SIG_CapureYUVFile\0"
    "num\0SIG_SetCameraParameter\0name\0"
    "SIG_SetDIPAlgParameter\0algtype\0"
    "SIG_SetGPIOOUT\0pin\0SIG_AnswerCmdToHttpServer\0"
    "answer\0SIG_UpdateTimeStamp\0"
    "SIG_SendAlgOutToPlatServer\0addr\0"
    "SIG_SysReset\0SIG_AppReset\0SIG_SysUpdate\0"
    "SIG_AppUpdate\0SIG_AppBackup\0SIG_AppUpload\0"
    "SIG_AdjustXY\0SIG_CommandExcute\0"
    "SLOT_ProcessMainFinished\0exitCode\0"
    "QProcess::ExitStatus\0exitStatus\0"
    "SLOT_ProcessFtpFinished\0"
    "SLOT_ProcessHttpFinished\0"
    "SLOT_ProcessRtspFinished\0"
    "SLOT_ProcessSystemFinished\0"
    "SLOT_StartLocalTcpServer\0"
    "SLOT_StopLocalTcpServer\0SLOT_StartProcessMain\0"
    "SLOT_RestartProcessMain\0SLOT_KillProcessMain\0"
    "SLOT_StartProcessFtp\0SLOT_RestartProcessFtp\0"
    "SLOT_StopProcessFtp\0SLOT_ProcessFtpStarted\0"
    "SLOT_StartProcessHttpServer\0"
    "SLOT_RestartProcessHttpServer\0"
    "SLOT_StopProcessHttpServer\0"
    "SLOT_StartProcessRtsp\0SLOT_RestartProcessRtsp\0"
    "SLOT_StopProcessRtsp\0SLOT_KillMainSelf\0"
    "SLOT_XParseTcpServerRecv\0ba\0"
    "SLOT_XParseCMDFromHttpServer\0"
    "SLOT_XParseAlgOutFromDipTcpClient\0"
    "SLOT_XParseMsgFromTerminalCLient\0"
    "SLOT_XParseGeneralMsg\0SLOT_SendCMDToDIPServer\0"
    "SLOT_Started\0SLOT_SetInitFilesVal\0"
    "SLOT_NoIdentityCmd\0SLOT_Control\0"
    "SLOT_GetSysInfo\0SLOT_SetByteArray\0"
    "ebaitem\0SLOT_UploadFile\0"
    "SLOT_SendCMDTypeAnd0ValToDIP\0"
    "SLOT_SendCMDTypeAnd1ValToDIP\0"
    "SLOT_SendCMDTypeAnd2ValToDIP\0"
    "SLOT_SendCMDTypeAnd3ValToDIP\0"
    "SLOT_SendCMDTypeAnd4ValToDIP\0"
    "SLOT_StartAlgDet\0SLOT_CapureYUVFile\0"
    "SLOT_SetCameraParameter\0SLOT_SetGPIOOUT\0"
    "SLOT_SetDIPAlgParameter\0SLOT_ClearAlarm\0"
    "SLOT_SendAlgOutToPlatServer\0SLOT_SysReset\0"
    "SLOT_AppReset\0SLOT_SysUpdate\0"
    "SLOT_AppUpdate\0fileid\0SLOT_AppBackup\0"
    "SLOT_AppUpload\0SLOT_AdjustXY\0adj\0"
    "SLOT_Offline\0online\0SLOT_CommandExcute\0"
    "cmd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IVFDMainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     108,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      53,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  554,    2, 0x06 /* Public */,
       3,    0,  555,    2, 0x06 /* Public */,
       4,    0,  556,    2, 0x06 /* Public */,
       5,    0,  557,    2, 0x06 /* Public */,
       6,    0,  558,    2, 0x06 /* Public */,
       7,    0,  559,    2, 0x06 /* Public */,
       8,    0,  560,    2, 0x06 /* Public */,
       9,    5,  561,    2, 0x06 /* Public */,
      15,    5,  572,    2, 0x06 /* Public */,
      17,    0,  583,    2, 0x06 /* Public */,
      18,    2,  584,    2, 0x06 /* Public */,
      19,    2,  589,    2, 0x06 /* Public */,
      20,    0,  594,    2, 0x06 /* Public */,
      21,    0,  595,    2, 0x06 /* Public */,
      22,    0,  596,    2, 0x06 /* Public */,
      23,    0,  597,    2, 0x06 /* Public */,
      24,    0,  598,    2, 0x06 /* Public */,
      25,    1,  599,    2, 0x06 /* Public */,
      26,    1,  602,    2, 0x06 /* Public */,
      27,    1,  605,    2, 0x06 /* Public */,
      28,    1,  608,    2, 0x06 /* Public */,
      29,    1,  611,    2, 0x06 /* Public */,
      30,    3,  614,    2, 0x06 /* Public */,
      34,    4,  621,    2, 0x06 /* Public */,
      35,    0,  630,    2, 0x06 /* Public */,
      36,    2,  631,    2, 0x06 /* Public */,
      37,    3,  636,    2, 0x06 /* Public */,
      42,    3,  643,    2, 0x06 /* Public */,
      43,    3,  650,    2, 0x06 /* Public */,
      44,    3,  657,    2, 0x06 /* Public */,
      47,    3,  664,    2, 0x06 /* Public */,
      49,    3,  671,    2, 0x06 /* Public */,
      51,    1,  678,    2, 0x06 /* Public */,
      53,    2,  681,    2, 0x06 /* Public */,
      54,    3,  686,    2, 0x06 /* Public */,
      57,    4,  693,    2, 0x06 /* Public */,
      59,    5,  702,    2, 0x06 /* Public */,
      61,    2,  713,    2, 0x06 /* Public */,
      63,    2,  718,    2, 0x06 /* Public */,
      65,    5,  723,    2, 0x06 /* Public */,
      67,    4,  734,    2, 0x06 /* Public */,
      69,    3,  743,    2, 0x06 /* Public */,
      71,    1,  750,    2, 0x06 /* Public */,
      73,    1,  753,    2, 0x06 /* Public */,
      74,    4,  756,    2, 0x06 /* Public */,
      76,    0,  765,    2, 0x06 /* Public */,
      77,    0,  766,    2, 0x06 /* Public */,
      78,    0,  767,    2, 0x06 /* Public */,
      79,    1,  768,    2, 0x06 /* Public */,
      80,    1,  771,    2, 0x06 /* Public */,
      81,    1,  774,    2, 0x06 /* Public */,
      82,    1,  777,    2, 0x06 /* Public */,
      83,    1,  780,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      84,    2,  783,    2, 0x0a /* Public */,
      88,    2,  788,    2, 0x0a /* Public */,
      89,    2,  793,    2, 0x0a /* Public */,
      90,    2,  798,    2, 0x0a /* Public */,
      91,    2,  803,    2, 0x0a /* Public */,
      92,    0,  808,    2, 0x0a /* Public */,
      93,    0,  809,    2, 0x0a /* Public */,
      94,    0,  810,    2, 0x0a /* Public */,
      95,    0,  811,    2, 0x0a /* Public */,
      96,    0,  812,    2, 0x0a /* Public */,
      97,    5,  813,    2, 0x0a /* Public */,
      98,    5,  824,    2, 0x0a /* Public */,
      99,    0,  835,    2, 0x0a /* Public */,
     100,    0,  836,    2, 0x0a /* Public */,
     101,    2,  837,    2, 0x0a /* Public */,
     102,    2,  842,    2, 0x0a /* Public */,
     103,    0,  847,    2, 0x0a /* Public */,
     104,    0,  848,    2, 0x0a /* Public */,
     105,    0,  849,    2, 0x0a /* Public */,
     106,    0,  850,    2, 0x0a /* Public */,
     107,    0,  851,    2, 0x0a /* Public */,
     108,    1,  852,    2, 0x0a /* Public */,
     110,    1,  855,    2, 0x0a /* Public */,
     111,    1,  858,    2, 0x0a /* Public */,
     112,    1,  861,    2, 0x0a /* Public */,
     113,    1,  864,    2, 0x0a /* Public */,
     114,    3,  867,    2, 0x0a /* Public */,
     115,    0,  874,    2, 0x0a /* Public */,
     116,    3,  875,    2, 0x0a /* Public */,
     117,    3,  882,    2, 0x0a /* Public */,
     118,    3,  889,    2, 0x0a /* Public */,
     119,    3,  896,    2, 0x0a /* Public */,
     120,    3,  903,    2, 0x0a /* Public */,
     122,    3,  910,    2, 0x0a /* Public */,
     123,    1,  917,    2, 0x0a /* Public */,
     124,    2,  920,    2, 0x0a /* Public */,
     125,    3,  925,    2, 0x0a /* Public */,
     126,    4,  932,    2, 0x0a /* Public */,
     127,    5,  941,    2, 0x0a /* Public */,
     128,    2,  952,    2, 0x0a /* Public */,
     129,    2,  957,    2, 0x0a /* Public */,
     130,    5,  962,    2, 0x0a /* Public */,
     131,    3,  973,    2, 0x0a /* Public */,
     132,    4,  980,    2, 0x0a /* Public */,
     133,    0,  989,    2, 0x0a /* Public */,
     134,    4,  990,    2, 0x0a /* Public */,
     135,    0,  999,    2, 0x0a /* Public */,
     136,    0, 1000,    2, 0x0a /* Public */,
     137,    0, 1001,    2, 0x0a /* Public */,
     138,    1, 1002,    2, 0x0a /* Public */,
     140,    1, 1005,    2, 0x0a /* Public */,
     141,    1, 1008,    2, 0x0a /* Public */,
     142,    1, 1011,    2, 0x0a /* Public */,
     144,    1, 1014,    2, 0x0a /* Public */,
     146,    1, 1017,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   16,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,   31,   32,   33,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 39, QMetaType::Int,    2,   40,   41,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 39, QMetaType::Int,    2,   40,   41,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 39, QMetaType::Int,    2,   40,   41,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 45, QMetaType::QByteArray,    2,    2,   46,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 48, QMetaType::QByteArray,    2,    2,   46,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 50, QMetaType::Int,    2,   40,   41,
    QMetaType::Void, 0x80000000 | 38,   52,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int,   52,   41,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int,   52,   55,   56,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   55,   56,   58,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   55,   56,   58,   60,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int,   52,   62,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int,   52,   64,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   66,   55,   56,   58,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   68,   66,   41,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int,   52,   70,   41,
    QMetaType::Void, QMetaType::QByteArray,   72,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray, QMetaType::QByteArray,   75,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 86,   85,   87,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 86,   85,   87,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 86,   85,   87,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 86,   85,   87,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 86,   85,   87,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,  109,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,  109,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QByteArray,   31,   32,   33,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 39, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 39, QMetaType::Int,    2,   40,   41,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 39, QMetaType::Int,    2,   40,   41,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 50, QMetaType::Int,   52,   40,   41,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 45, QMetaType::QByteArray,   52,  121,   46,
    QMetaType::Void, 0x80000000 | 38, 0x80000000 | 48, QMetaType::QByteArray,    2,    2,   46,
    QMetaType::Void, 0x80000000 | 38,   52,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int,   52,   41,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int,   52,   55,   56,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   55,   56,   58,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   55,   56,   58,   60,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int,   52,   62,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int,   52,   64,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   66,   55,   56,   58,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int,   52,   70,   41,
    QMetaType::Void, 0x80000000 | 38, QMetaType::Int, QMetaType::Int, QMetaType::Int,   52,   68,   40,   41,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::UShort, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  139,
    QMetaType::Void, QMetaType::Int,  139,
    QMetaType::Void, QMetaType::Int,  139,
    QMetaType::Void, QMetaType::QString,  143,
    QMetaType::Void, QMetaType::Bool,  145,
    QMetaType::Void, QMetaType::QString,  147,

       0        // eod
};

void IVFDMainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IVFDMainWidget *_t = static_cast<IVFDMainWidget *>(_o);
        switch (_id) {
        case 0: _t->SIG_StartProcessMain(); break;
        case 1: _t->SIG_RestartProcessMain(); break;
        case 2: _t->SIG_KillProcessMain(); break;
        case 3: _t->SIG_StartHeartBeat(); break;
        case 4: _t->SIG_StopHeartBeat(); break;
        case 5: _t->SIG_StartLocalTcpServer(); break;
        case 6: _t->SIG_StopLocalTcpServer(); break;
        case 7: _t->SIG_StartProcessFtp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 8: _t->SIG_RestartProcessFtp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 9: _t->SIG_StopProcessFtp(); break;
        case 10: _t->SIG_StartProcessHttpServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->SIG_RestartProcessHttpServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: _t->SIG_StopProcessHttpServer(); break;
        case 13: _t->SIG_StartProcessRtsp(); break;
        case 14: _t->SIG_RestartProcessRtsp(); break;
        case 15: _t->SIG_StopProcessRtsp(); break;
        case 16: _t->SIG_KillMainSelf(); break;
        case 17: _t->SIG_XParseTcpServerRecv((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 18: _t->SIG_XParseCMDFromHttpServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 19: _t->SIG_XParseAlgOutFromDipTcpClient((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 20: _t->SIG_XParseMsgFromTerminalCLient((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 21: _t->SIG_XParseGeneralMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 22: _t->SIG_SendCMDToDIPServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 23: _t->SIG_TellClientToSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        case 24: _t->SIG_ClearAlarm(); break;
        case 25: _t->SIG_CmdFromBrowser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: _t->SIG_SetInitFilesVal((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 27: _t->SIG_NoIdentityCmd((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 28: _t->SIG_Control((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 29: _t->SIG_SetByteArray((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EBAITEM(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 30: _t->SIG_UploadFile((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EFILEITEM(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 31: _t->SIG_GetSysInfo((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EREADITEM(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 32: _t->SIG_SendCMDTypeAnd0ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1]))); break;
        case 33: _t->SIG_SendCMDTypeAnd1ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->SIG_SendCMDTypeAnd2ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 35: _t->SIG_SendCMDTypeAnd3ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 36: _t->SIG_SendCMDTypeAnd4ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 37: _t->SIG_StartAlgDet((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 38: _t->SIG_CapureYUVFile((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->SIG_SetCameraParameter((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 40: _t->SIG_SetDIPAlgParameter((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 41: _t->SIG_SetGPIOOUT((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 42: _t->SIG_AnswerCmdToHttpServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 43: _t->SIG_UpdateTimeStamp((*reinterpret_cast< qlonglong(*)>(_a[1]))); break;
        case 44: _t->SIG_SendAlgOutToPlatServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        case 45: _t->SIG_SysReset(); break;
        case 46: _t->SIG_AppReset(); break;
        case 47: _t->SIG_SysUpdate(); break;
        case 48: _t->SIG_AppUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->SIG_AppBackup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->SIG_AppUpload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 51: _t->SIG_AdjustXY((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 52: _t->SIG_CommandExcute((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 53: _t->SLOT_ProcessMainFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 54: _t->SLOT_ProcessFtpFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 55: _t->SLOT_ProcessHttpFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 56: _t->SLOT_ProcessRtspFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 57: _t->SLOT_ProcessSystemFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QProcess::ExitStatus(*)>(_a[2]))); break;
        case 58: _t->SLOT_StartLocalTcpServer(); break;
        case 59: _t->SLOT_StopLocalTcpServer(); break;
        case 60: _t->SLOT_StartProcessMain(); break;
        case 61: _t->SLOT_RestartProcessMain(); break;
        case 62: _t->SLOT_KillProcessMain(); break;
        case 63: _t->SLOT_StartProcessFtp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 64: _t->SLOT_RestartProcessFtp((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 65: _t->SLOT_StopProcessFtp(); break;
        case 66: _t->SLOT_ProcessFtpStarted(); break;
        case 67: _t->SLOT_StartProcessHttpServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 68: _t->SLOT_RestartProcessHttpServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 69: _t->SLOT_StopProcessHttpServer(); break;
        case 70: _t->SLOT_StartProcessRtsp(); break;
        case 71: _t->SLOT_RestartProcessRtsp(); break;
        case 72: _t->SLOT_StopProcessRtsp(); break;
        case 73: _t->SLOT_KillMainSelf(); break;
        case 74: _t->SLOT_XParseTcpServerRecv((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 75: _t->SLOT_XParseCMDFromHttpServer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 76: _t->SLOT_XParseAlgOutFromDipTcpClient((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 77: _t->SLOT_XParseMsgFromTerminalCLient((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 78: _t->SLOT_XParseGeneralMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 79: _t->SLOT_SendCMDToDIPServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 80: _t->SLOT_Started(); break;
        case 81: _t->SLOT_SetInitFilesVal((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 82: _t->SLOT_NoIdentityCmd((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 83: _t->SLOT_Control((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EHWVAL(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 84: _t->SLOT_GetSysInfo((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EREADITEM(*)>(_a[2])),(*reinterpret_cast< qint32(*)>(_a[3]))); break;
        case 85: _t->SLOT_SetByteArray((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EBAITEM(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 86: _t->SLOT_UploadFile((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< EFILEITEM(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 87: _t->SLOT_SendCMDTypeAnd0ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1]))); break;
        case 88: _t->SLOT_SendCMDTypeAnd1ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 89: _t->SLOT_SendCMDTypeAnd2ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 90: _t->SLOT_SendCMDTypeAnd3ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 91: _t->SLOT_SendCMDTypeAnd4ValToDIP((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 92: _t->SLOT_StartAlgDet((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 93: _t->SLOT_CapureYUVFile((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 94: _t->SLOT_SetCameraParameter((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 95: _t->SLOT_SetGPIOOUT((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 96: _t->SLOT_SetDIPAlgParameter((*reinterpret_cast< ECMDTYPE(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 97: _t->SLOT_ClearAlarm(); break;
        case 98: _t->SLOT_SendAlgOutToPlatServer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        case 99: _t->SLOT_SysReset(); break;
        case 100: _t->SLOT_AppReset(); break;
        case 101: _t->SLOT_SysUpdate(); break;
        case 102: _t->SLOT_AppUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 103: _t->SLOT_AppBackup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 104: _t->SLOT_AppUpload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 105: _t->SLOT_AdjustXY((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 106: _t->SLOT_Offline((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 107: _t->SLOT_CommandExcute((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StartProcessMain)) {
                *result = 0;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_RestartProcessMain)) {
                *result = 1;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_KillProcessMain)) {
                *result = 2;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StartHeartBeat)) {
                *result = 3;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StopHeartBeat)) {
                *result = 4;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StartLocalTcpServer)) {
                *result = 5;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StopLocalTcpServer)) {
                *result = 6;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StartProcessFtp)) {
                *result = 7;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_RestartProcessFtp)) {
                *result = 8;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StopProcessFtp)) {
                *result = 9;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StartProcessHttpServer)) {
                *result = 10;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_RestartProcessHttpServer)) {
                *result = 11;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StopProcessHttpServer)) {
                *result = 12;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StartProcessRtsp)) {
                *result = 13;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_RestartProcessRtsp)) {
                *result = 14;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StopProcessRtsp)) {
                *result = 15;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_KillMainSelf)) {
                *result = 16;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_XParseTcpServerRecv)) {
                *result = 17;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_XParseCMDFromHttpServer)) {
                *result = 18;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_XParseAlgOutFromDipTcpClient)) {
                *result = 19;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_XParseMsgFromTerminalCLient)) {
                *result = 20;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_XParseGeneralMsg)) {
                *result = 21;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , QString , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SendCMDToDIPServer)) {
                *result = 22;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , quint16 , QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_TellClientToSend)) {
                *result = 23;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_ClearAlarm)) {
                *result = 24;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_CmdFromBrowser)) {
                *result = 25;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , EHWVAL , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SetInitFilesVal)) {
                *result = 26;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , EHWVAL , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_NoIdentityCmd)) {
                *result = 27;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , EHWVAL , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_Control)) {
                *result = 28;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , EBAITEM , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SetByteArray)) {
                *result = 29;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , EFILEITEM , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_UploadFile)) {
                *result = 30;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , EREADITEM , qint32 );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_GetSysInfo)) {
                *result = 31;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SendCMDTypeAnd0ValToDIP)) {
                *result = 32;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SendCMDTypeAnd1ValToDIP)) {
                *result = 33;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SendCMDTypeAnd2ValToDIP)) {
                *result = 34;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SendCMDTypeAnd3ValToDIP)) {
                *result = 35;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SendCMDTypeAnd4ValToDIP)) {
                *result = 36;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_StartAlgDet)) {
                *result = 37;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_CapureYUVFile)) {
                *result = 38;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SetCameraParameter)) {
                *result = 39;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SetDIPAlgParameter)) {
                *result = 40;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(ECMDTYPE , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SetGPIOOUT)) {
                *result = 41;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_AnswerCmdToHttpServer)) {
                *result = 42;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(qlonglong );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_UpdateTimeStamp)) {
                *result = 43;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString , quint16 , QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SendAlgOutToPlatServer)) {
                *result = 44;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SysReset)) {
                *result = 45;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_AppReset)) {
                *result = 46;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_SysUpdate)) {
                *result = 47;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_AppUpdate)) {
                *result = 48;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_AppBackup)) {
                *result = 49;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_AppUpload)) {
                *result = 50;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_AdjustXY)) {
                *result = 51;
            }
        }
        {
            typedef void (IVFDMainWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IVFDMainWidget::SIG_CommandExcute)) {
                *result = 52;
            }
        }
    }
}

const QMetaObject IVFDMainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_IVFDMainWidget.data,
      qt_meta_data_IVFDMainWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IVFDMainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IVFDMainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IVFDMainWidget.stringdata))
        return static_cast<void*>(const_cast< IVFDMainWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int IVFDMainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 108)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 108;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 108)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 108;
    }
    return _id;
}

// SIGNAL 0
void IVFDMainWidget::SIG_StartProcessMain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void IVFDMainWidget::SIG_RestartProcessMain()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void IVFDMainWidget::SIG_KillProcessMain()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void IVFDMainWidget::SIG_StartHeartBeat()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void IVFDMainWidget::SIG_StopHeartBeat()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void IVFDMainWidget::SIG_StartLocalTcpServer()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void IVFDMainWidget::SIG_StopLocalTcpServer()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void IVFDMainWidget::SIG_StartProcessFtp(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void IVFDMainWidget::SIG_RestartProcessFtp(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void IVFDMainWidget::SIG_StopProcessFtp()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void IVFDMainWidget::SIG_StartProcessHttpServer(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void IVFDMainWidget::SIG_RestartProcessHttpServer(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void IVFDMainWidget::SIG_StopProcessHttpServer()
{
    QMetaObject::activate(this, &staticMetaObject, 12, Q_NULLPTR);
}

// SIGNAL 13
void IVFDMainWidget::SIG_StartProcessRtsp()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void IVFDMainWidget::SIG_RestartProcessRtsp()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void IVFDMainWidget::SIG_StopProcessRtsp()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void IVFDMainWidget::SIG_KillMainSelf()
{
    QMetaObject::activate(this, &staticMetaObject, 16, Q_NULLPTR);
}

// SIGNAL 17
void IVFDMainWidget::SIG_XParseTcpServerRecv(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void IVFDMainWidget::SIG_XParseCMDFromHttpServer(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void IVFDMainWidget::SIG_XParseAlgOutFromDipTcpClient(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void IVFDMainWidget::SIG_XParseMsgFromTerminalCLient(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void IVFDMainWidget::SIG_XParseGeneralMsg(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void IVFDMainWidget::SIG_SendCMDToDIPServer(QString _t1, QString _t2, QByteArray _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void IVFDMainWidget::SIG_TellClientToSend(QString _t1, quint16 _t2, QByteArray _t3, QByteArray _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void IVFDMainWidget::SIG_ClearAlarm()
{
    QMetaObject::activate(this, &staticMetaObject, 24, Q_NULLPTR);
}

// SIGNAL 25
void IVFDMainWidget::SIG_CmdFromBrowser(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void IVFDMainWidget::SIG_SetInitFilesVal(ECMDTYPE _t1, EHWVAL _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void IVFDMainWidget::SIG_NoIdentityCmd(ECMDTYPE _t1, EHWVAL _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void IVFDMainWidget::SIG_Control(ECMDTYPE _t1, EHWVAL _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void IVFDMainWidget::SIG_SetByteArray(ECMDTYPE _t1, EBAITEM _t2, QByteArray _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void IVFDMainWidget::SIG_UploadFile(ECMDTYPE _t1, EFILEITEM _t2, QByteArray _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void IVFDMainWidget::SIG_GetSysInfo(ECMDTYPE _t1, EREADITEM _t2, qint32 _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void IVFDMainWidget::SIG_SendCMDTypeAnd0ValToDIP(ECMDTYPE _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void IVFDMainWidget::SIG_SendCMDTypeAnd1ValToDIP(ECMDTYPE _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void IVFDMainWidget::SIG_SendCMDTypeAnd2ValToDIP(ECMDTYPE _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void IVFDMainWidget::SIG_SendCMDTypeAnd3ValToDIP(ECMDTYPE _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void IVFDMainWidget::SIG_SendCMDTypeAnd4ValToDIP(ECMDTYPE _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void IVFDMainWidget::SIG_StartAlgDet(ECMDTYPE _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void IVFDMainWidget::SIG_CapureYUVFile(ECMDTYPE _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void IVFDMainWidget::SIG_SetCameraParameter(ECMDTYPE _t1, int _t2, int _t3, int _t4, int _t5)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void IVFDMainWidget::SIG_SetDIPAlgParameter(ECMDTYPE _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 40, _a);
}

// SIGNAL 41
void IVFDMainWidget::SIG_SetGPIOOUT(ECMDTYPE _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}

// SIGNAL 42
void IVFDMainWidget::SIG_AnswerCmdToHttpServer(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 42, _a);
}

// SIGNAL 43
void IVFDMainWidget::SIG_UpdateTimeStamp(qlonglong _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 43, _a);
}

// SIGNAL 44
void IVFDMainWidget::SIG_SendAlgOutToPlatServer(QString _t1, quint16 _t2, QByteArray _t3, QByteArray _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 44, _a);
}

// SIGNAL 45
void IVFDMainWidget::SIG_SysReset()
{
    QMetaObject::activate(this, &staticMetaObject, 45, Q_NULLPTR);
}

// SIGNAL 46
void IVFDMainWidget::SIG_AppReset()
{
    QMetaObject::activate(this, &staticMetaObject, 46, Q_NULLPTR);
}

// SIGNAL 47
void IVFDMainWidget::SIG_SysUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 47, Q_NULLPTR);
}

// SIGNAL 48
void IVFDMainWidget::SIG_AppUpdate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 48, _a);
}

// SIGNAL 49
void IVFDMainWidget::SIG_AppBackup(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 49, _a);
}

// SIGNAL 50
void IVFDMainWidget::SIG_AppUpload(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 50, _a);
}

// SIGNAL 51
void IVFDMainWidget::SIG_AdjustXY(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 51, _a);
}

// SIGNAL 52
void IVFDMainWidget::SIG_CommandExcute(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 52, _a);
}
QT_END_MOC_NAMESPACE
