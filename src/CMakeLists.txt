cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

qt5_wrap_ui(UI_HEADERS QtUI.ui)

if (WIN32)
  set(GUI_TYPE WIN32)
endif(WIN32)

include_directories (${Qt5Gui_INCLUDE_DIRS})

add_executable(learnfrom3D ${GUI_TYPE} main.cpp QtUI.cpp ${UI_HEADERS})

target_link_libraries(learnfrom3D Qt5::Core Qt5::Gui Qt5::Widgets Qt5::3DCore Qt5::3DExtras Qt5::3DRender Qt5::3DInput)
target_link_libraries(learnfrom3D ${OpenCV_LIBS})

install (TARGETS learnfrom3D DESTINATION ${INSTALL_DIR})
