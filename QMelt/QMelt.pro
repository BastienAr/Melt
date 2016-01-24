#-------------------------------------------------
#
# Project created by QtCreator 2015-05-03T11:50:51
#
#-------------------------------------------------

QT       += core qml quick widgets

greaterThan(QT_MAJOR_VERSION, 4):

TARGET = QMelt
TEMPLATE = app

CONFIG += c++11

SOURCES += \
# Ableton
src/ableton/alsliveset.cpp \
src/ableton/alsaudiotrack.cpp \
src/ableton/alsmiditrack.cpp \
src/ableton/alsableton.cpp \
src/ableton/alstrackdelay.cpp \
src/ableton/alstrack.cpp \
src/ableton/alsname.cpp \
src/ableton/alsdevicechain.cpp \
src/ableton/alsmastertrack.cpp \
src/ableton/alsreturntrack.cpp \
src/ableton/alsmasterchain.cpp \
src/ableton/alsmainsequencer.cpp \
src/ableton/alsclipslot.cpp \
src/ableton/alsinnerclipslot.cpp \
src/ableton/alsclipslotvalue.cpp \
src/ableton/alsmidiclip.cpp \
src/ableton/alsfactory.cpp \
src/ableton/alsgrouptrack.cpp \
# App
src/app/main.cpp\
src/app/meltapplication.cpp \
src/app/meltcommandline.cpp \
src/app/melt.cpp\
# IO
src/io/alsfilesystem.cpp \
src/io/alstextstream.cpp \
# DIFF
src/diff/diffengine.cpp \
src/diff/diffnode.cpp \
src/diff/matchengine.cpp \
src/diff/match.cpp \
src/diff/matchresult.cpp \
src/diff/depthfirsttraversal.cpp \
src/diff/stringcomparator.cpp \
# Parser
src/parser/xmlobject.cpp \
src/parser/xmlcontext.cpp \
src/parser/xmlcontenthandler.cpp \
src/parser/corexmlparser.cpp \
src/parser/alsxmlcontenthandler.cpp \
src/test/melttestcore.cpp \
# UI
src/ui/meltui.cpp \
src/ui/clickablewidget.cpp

HEADERS  += \
            src/app/meltapplication.h \
            src/io/alsfilesystem.h \
           src/app/meltcommandline.h \
            src/io/alsfilestreambase.h \
            src/io/alstextstream.h \
    src/ableton/alsliveset.h \
    src/ableton/alsaudiotrack.h \
    src/ableton/alsmiditrack.h \
    src/ableton/abletonobject.h \
    src/ableton/alsableton.h \
    src/ableton/alstrack.h \
    src/ableton/alsname.h \
    src/ableton/alsdevicechain.h \    
    src/ableton/alsfactory.h \
    src/ableton/alstrackdelay.h \
    src/ableton/alsmastertrack.h \
    src/ableton/alsreturntrack.h \
    src/ableton/alsgrouptrack.h \
    src/parser/xmlobject.h \
    src/parser/xmlcontext.h \
    src/parser/xmlcontenthandler.h \
    src/parser/corexmlparser.h \
    src/parser/alsxmlcontenthandler.h \
    src/test/melttestcore.h \
    src/common/common.h \
    src/ui/meltui.h \
    src/ableton/alsmasterchain.h \
    src/ableton/alsmainsequencer.h \
    src/ableton/alsclipslot.h \
    src/ableton/alsinnerclipslot.h \
    src/ableton/alsclipslotvalue.h \
    src/ableton/alsmidiclip.h \
    src/utils/colormap.h \
    src/ui/clickablewidget.h \
    src/diff/diffengine.h \
    src/diff/diffnode.h \
    src/diff/matchengine.h \
    src/diff/match.h \
    src/diff/matchresult.h \
    src/diff/depthfirsttraversal.h \
    src/diff/stringcomparator.h \
    src/app/melt.h

RESOURCES += resources/qml.qrc \
    resources/icons.qrc
