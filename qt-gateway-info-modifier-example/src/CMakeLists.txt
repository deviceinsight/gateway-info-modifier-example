SET(rmcsagent_SOURCES 
	GatewayInfoModifier.cpp 
	ConfigReader.cpp   
	)

SET(rmcsagent_HEADERS
	ConfigReader.h 
	GatewayInfoMessage.h 
	MobileInterfacesInfo.h 
	PackageInfo.h 
	PanamaMessage.h 
	StreamConnectorInfo.h 
	Header.h
	)

qt4_automoc(${rmcsagent_SOURCES})
QT4_WRAP_CPP(rmcsagent_HEADERS_MOC ${rmcsagent_HEADERS})

add_executable(GatewayInfoModifier ${rmcsagent_HEADERS_MOC} ${rmcsagent_SOURCES} )

SET(LIBRARIES 
	${QXT_LIBRARIES} 
	${QT_QXTNETWORK_LIBRARY} 
	${QXT_CORE_LIB} 
	${QXT_WEB_LIB} 
	${QT_QTCORE_LIBRARY} 
	${QT_LIBRARIES}
	${QT_XML}
	${QT_QTNETWORK_LIBRARY}
)

target_link_libraries(GatewayInfoModifier ${LIBRARIES})
