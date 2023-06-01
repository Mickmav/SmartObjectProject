if(ARGOS_BUILD_FOR_SIMULATOR)
	# Set up ARGoS compilation information
	include_directories(${CMAKE_SOURCE_DIR} ${ARGOS_INCLUDE_DIRS})
	link_directories(${ARGOS_LIBRARY_DIRS})

	# Headers
	set(HEADERS
		SmartObjectDAO.h
	  SOReferenceModel1Dot1.h
	)

	# Sources
	set(SOURCES
		SmartObjectDAO.cpp
	  SOReferenceModel1Dot1.cpp
	)
else()
endif(ARGOS_BUILD_FOR_SIMULATOR)


add_library(argos3_demiurge_smartobject_dao SHARED ${HEADERS} ${SOURCES} )
target_link_libraries(argos3_demiurge_smartobject_dao argos3plugin_${ARGOS_BUILD_FOR}_smartobject)

install(
  FILES ${HEADERS}
  DESTINATION include/argos3/demiurge/smartobject-dao)

# Install location for the e-puck plugin
install(TARGETS argos3_demiurge_smartobject_dao
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
