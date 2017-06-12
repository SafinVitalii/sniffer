#-------------------------------------------------
#
# Project created by QtCreator 2017-01-04T16:33:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sniffer
TEMPLATE = app
LIBS += -lws2_32
RESOURCES += resource.qrc

SOURCES +=\
        snifferfacade.cc \
    sniffer.cc \
    datalogger.cc \
    observer.cc \
    otherpacket.cc \
    packet.cc \
    packetfactory.cc \
    packettable.cc \
    tcppacket.cc \
    trafficinterceptor.cc \
    udppacket.cc \
    filter.cc \
    statistics.cc

HEADERS  += snifferfacade.h \
    datalogger.h \
    observer.h \
    otherpacket.h \
    packet.h \
    packetfactory.h \
    packettable.h \
    protocolheaders.h \
    tcppacket.h \
    trafficinterceptor.h \
    udppacket.h \
    filter.h \
    statistics.h

FORMS    += snifferfacade.ui \
    trafficinterceptor.ui \
    statistics.ui

win32 {
  RC_FILE = Sniffer.rc
}
