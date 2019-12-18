cmake_minimum_required(VERSION 3.1.0)

project(LearnFrom3D)


if (MINGW)
  set(OpenCV_DIR "D:/OpenCV/3.4.5/mingw530_32/install")
elseif (MSVC)
  set(OpenCV_DIR "D:/OpenCV/3.4.2/vs2015/install/x64/vc14/lib")
endif (MINGW)

find_package(OpenCV REQUIRED)


# Set Qt location if needed
if (MINGW)
  set(Qt5Core_DIR "D:/Qt/5.9.6/mingw53_32")
elseif (MSVC)
  set(Qt5Core_DIR "D:/Qt/5.9.6/msvc2015_64")
elseif (LINUX)
  # 'CMAKE_PREFIX_PATH=/opt/Qt/5.9.8/gcc_64/lib/cmake cmake ..'
endif (MINGW)

find_package (Qt5Core QUIET)
if (Qt5Core_FOUND)
  message(STATUS "Using Qt5")
  find_package(Qt5 COMPONENTS Core Widgets Gui 3DCore 3DExtras 3DRender 3DInput REQUIRED)
else (Qt5Core_FOUND)
  message(FATAL_ERROR "Qt5 not found!")
endif (Qt5Core_FOUND)


# Use C++ standard (98, 11, 14)
set (CMAKE_CXX_STANDARD 11)
set (CXX_EXTENSIONS OFF)


# Default build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)


#add_definitions(-D${SOMEVAR})


set(INSTALL_DIR ${CMAKE_SOURCE_DIR}/bin)


add_subdirectory(src)