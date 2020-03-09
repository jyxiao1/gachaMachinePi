cmake_minimum_required (VERSION 3.0)
SET(PROJECT_NAME GachaMachinePi)
project(${PROJECT_NAME})

IF(WIN32)
    IF (${CMAKE_SIZEOF_VOID_P} MATCHES 4)
        SET(TOOLS_DIR_SEARCH_PATHS
                "$ENV{TOOLS_DIR}"
                "C:/Tools"
                "D:/Tools"
                )
    ELSEIF(MSVC14)
        SET(TOOLS_DIR_SEARCH_PATHS
                "C:/tools-vc14"
                "D:/tools-vc14"
                "C:/Tools_vc14"
                "D:/Tools_vc14"
                "$ENV{TOOLS_DIR}"
                )
    ELSE()
        SET(TOOLS_DIR_SEARCH_PATHS
                "$ENV{TOOLS_DIR}"
                "C:/tools-win64"
                "D:/tools-win64"
                "C:/Tools_x64"
                "D:/Tools_x64"
                )
    ENDIF()
ELSE()
    SET(TOOLS_DIR_SEARCH_PATHS
            /opt/tools /usr/tools /usr/local/tools
            $ENV{HOME}/tools )
ENDIF()

# find Qt5 if not found already
IF(NOT Qt5_FOUND)
    message(STATUS "Finding Qt5")
    set(QT_MIN_VERSION 5.9.0)

    message(STATUS "Setting Qt5 version to minimum version ${QT_MIN_VERSION}")
    set(QT5_COMPONENTS Core Gui Network Xml Multimedia Widgets) #  Qml Quick

    IF(WIN32)
        set(Qt5_DIR "${TOOLS_DIR}/Qt5/5.9.0/lib/cmake/Qt5/")
    ELSEIF()
        set(Qt5_DIR "")
    ENDIF()

    set(CMAKE_PREFIX_PATH "C:/Qt/5.14.1/mingw73_32")

    #set(Qt5_DIR ${Qt5_DIR} CACHE PATH "Path to Qt5 package configuration file." PARENT_SCOPE)

    find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS ${QT5_COMPONENTS})

ENDIF(NOT Qt5_FOUND)

IF(Qt5_FOUND)
    message(STATUS "Found Qt5 version ${Qt5_VERSION}")

    # Find includes in corresponding build directories
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    # Instruct CMake to run moc automatically when needed.
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTORC)

#    get_filename_component(QT_BIN_DIR ${QT_MOC_EXECUTABLE} DIRECTORY)
#    set(QT_LIBRARIES ${QT_LIBRARIES} Qt5::Widgets Qt5::Charts Qt5::PrintSupport) # Qt5::Qml Qt5::Quick
#
#    qt5_add_resources(CONDORVIEWER_RC_SRCS ${CONDORVIEWER_RCS})
#
#    get_target_property(qsqlite_loc Qt5::QSQLiteDriverPlugin LOCATION_Release)
#    get_filename_component(Qt5SqlDriver_PLUGIN_DIR ${qsqlite_loc} DIRECTORY)
#    get_filename_component(Qt5_PLUGINS_DIR ${Qt5SqlDriver_PLUGIN_DIR} DIRECTORY)
#
#    add_definitions( ${Qt5Widgets_DEFINITIONS} ${Qt5Sql_DEFINITIONS} ${Qt5Network_DEFINITIONS})
#    include_directories( ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Sql_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS} )
#
#    foreach(qtplugin ${qtplugins})
#        INSTALL(DIRECTORY "${qtplugin}" DESTINATION bin COMPONENT viewer FILES_MATCHING PATTERN "*.dll")
#    endforeach()
#    INSTALL(FILES ${QT_BIN_DIR}/qt.conf DESTINATION bin COMPONENT viewer)
#    set(CONDORVIEWER_UI_HDRS ${CONDORVIEWER_UIS} )

ELSE()
    Message(WARNING "Qt minimum version not found to build CondorViewer, ignoring and continuing")
    return()
ENDIF(Qt5_FOUND)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.14.0\\5.14.0\\mingw73_32\\")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

#find_package(Qt5 #[[${QT_MIN_VERSION}]] REQUIRED COMPONENTS Core Gui Network Xml Multimedia MultimediaWidget Widgets)
SET(GM_SRCS
        StateMachine.cpp
        State.cpp)
add_executable(helloworld main.cpp ${GM_SRCS})#[[application.qrc]]
target_link_libraries(helloworld Qt5::Widgets)
