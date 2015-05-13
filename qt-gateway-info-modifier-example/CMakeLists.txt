cmake_minimum_required (VERSION 2.6)
project (GatewayInfoModifier)
include(local.cmake)

if (NOT QXT_WEB_LIB) 
	SET (QXT_WEB_LIB ${LINUX_LIB_BASE}/libQxtWeb.so.0 CACHE STRING "libQxtWeb")
endif()
if (NOT QXT_CORE_LIB) 
	SET (QXT_CORE_LIB ${LINUX_LIB_BASE}/libQxtCore.so.0 CACHE STRING "libQxtCore")
endif()
if (NOT MODBUS_LIB) 
	SET (MODBUS_LIB ${LINUX_LIB_BASE}/libmodbus.so.5 CACHE STRING "libmodbus")
endif()
if (NOT CURL_LIB) 
	SET (CURL_LIB ${LINUX_LIB_BASE}/libcurl.so CACHE STRING "libcurl")
endif()
if (NOT QXT2_INCL_WEB) 
	SET (QXT2_INCL_WEB ${LINUX_BASE}/include/qxt/QxtWeb/ CACHE STRING "QxtWeb")
endif()
if (NOT QXT2_INCL_CORE) 
	SET (QXT2_INCL_CORE ${LINUX_BASE}/include/qxt/QxtCore/ CACHE STRING "QxtCore")
endif()
if (NOT QT_XML) 
	SET (QT_XML ${LINUX_LIB_BASE}/libQtXml.so CACHE STRING "QtXml")
endif()

FIND_PACKAGE(Qt4 REQUIRED)


SET(QXT_USE_QXTCORE TRUE)
SET(QXT_USE_QXTWEB TRUE)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR} )
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(QT_DONT_USE_QTGUI TRUE)
SET(QT_USE_QTNETWORK TRUE)

include_directories(${QT_INCLUDES} ${QXT_INCLUDE_DIRS} ${QXT2_INCL_CORE} ${QXT2_INCL_WEB} ${CMAKE_CURRENT_BINARY_DIR} ${MODBUS_INCL} ${CURL_INCL})

INCLUDE(${QT_USE_FILE})

enable_testing()

add_subdirectory (src) 
