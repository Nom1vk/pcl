cmake_minimum_required(VERSION 2.8)

project(HelloPCLWorld)

#notice the "recycling" of CMAKE_C_FLAGS
#this is necessary to pick up android flags
set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic" )

if(WIN32 OR ANDROID)
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_STATIC ON)
    set(Boost_USE_MULTITHREADED ON)
    if(ANDROID)
	  set(Boost_COMPILER "-gcc")
	  set(Boost_DEBUG ON)
	endif(ANDROID)
endif(WIN32 OR ANDROID)
find_package(Boost 1.55.0 COMPONENTS date_time system filesystem thread iostreams)
include_directories(${Boost_INCLUDE_DIRS})
find_package(PCL REQUIRED COMPONENTS common io octree kdtree)
include_directories(${PCL_INCLUDE_DIRS})  

set(NDK_HOME CACHE PATH "Home of NDK")

if($ENV{NDKROOT})
  set(NDK_HOME $ENV{NDKROOT})
endif()

link_directories ("${NDK_HOME}/toolchains/${ANDROID_TOOLCHAIN_NAME}/prebuild/linux-x86_64/user/lib")

#test for ANDROID and look for stuff not relevant to android.
if(NOT ANDROID)
#jni is available by default on android
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
endif()


#this will be overridden by the android toolchain
set( LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/pc CACHE PATH
        "Single Directory for all Libraries")



#make sure to used shared in in the jni library, as this will be loaded by
#java

add_library(helloPCLWorld SHARED jni/hello-pcl.cpp)
target_link_libraries(helloPCLWorld 
${BOOST_LIBRARIES}
android
log
pcl_kdtree
pcl_io
flann_cpp_s pcl_common)


