cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
if(POLICY CMP0048)
  cmake_policy(SET CMP0048 OLD) # do not use VERSION option in project() command
endif()

if(POLICY CMP0054)
  cmake_policy(SET CMP0054 OLD) # Silent warnings about quoted variables
endif()
project(HelloPCLWorld)

find_package(OpenMP)
#notice the "recycling" of CMAKE_C_FLAGS
#this is necessary to pick up android flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic ${OpenMP_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

if(WIN32 OR ANDROID)
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_STATIC ON)
    set(Boost_NO_BOOST_CMAKE ON)
    if(ANDROID)
	  set(Boost_COMPILER "-gcc")
	  set(Boost_DEBUG OFF)
	endif(ANDROID)
endif(WIN32 OR ANDROID)
message(${CMAKE_FIND_ROOT_PATH})
message(${CMAKE_TOOLCHAIN_FILE})
SET(Boost_ADDITIONAL_VERSIONS "1.47" "1.47.0" "1.48" "1.48.0" "1.49" "1.49.0" "1.55" "1.55.0" "1.53" "1.53.0")
find_package(Boost 1.47.0 REQUIRED COMPONENTS system date_time)
include_directories(${Boost_INCLUDE_DIRS})
find_package(PCL REQUIRED COMPONENTS common io octree kdtree)
include_directories(${PCL_INCLUDE_DIRS})  
link_directories(${Boost_LIBRARY_DIRS})
set(NDK_HOME CACHE PATH "Home of NDK")

if($ENV{NDKROOT})
  set(NDK_HOME $ENV{NDKROOT})
endif()

#link_directories ("${NDK_HOME}/toolchains/${ANDROID_TOOLCHAIN_NAME}/prebuild/linux-x86_64/user/lib")

#test for ANDROID and look for stuff not relevant to android.
if(NOT ANDROID)
#jni is available by default on android
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
endif()


#this will be overridden by the android toolchain
set( LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/pc CACHE PATH
        "Single Directory for all Libraries")

include_directories(${EIGEN_INCLUDE_DIRS})
#make sure to used shared in in the jni library, as this will be loaded by
#java
message(${PCL_LIBRARIES})
add_library(helloPCLWorld SHARED jni/hello-pcl.cpp)
target_link_libraries(helloPCLWorld 
${BOOST_LIBRARIES}
android
log
${PCL_LIBRARIES}
${FLANN_LIBRARY}
)


