# Install script for directory: /home/anis/ros_workspace/kuka_controller/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller/libXDESimpleController-gnulinux.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller/libXDESimpleController-gnulinux.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller/libXDESimpleController-gnulinux.so"
         RPATH "/usr/local/lib/orocos/gnulinux:/usr/local/lib:/usr/local/lib/orocos/gnulinux/kuka_controller:/usr/lib/orocos/gnulinux/ocl:/usr/lib/orocos/gnulinux/ocl/plugins:/usr/lib/orocos/gnulinux/ocl/types:/opt/ros/groovy/lib:/home/anis/libs/CoinIpopt/build/lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../x86_64-linux-gnu:/home/anis/ros_workspace/orocos/orocos_toolchain/rtt/install/lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../../lib:/lib/../lib:/usr/lib/../lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../..:/home/anis/libs/gurobi563/linux64/lib:/home/anis/libs/ReflexxesTypeII/Linux/x64/release/lib/shared:/home/anis/libs/boost_1_56_0/bin.v2/libs")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller" TYPE SHARED_LIBRARY FILES "/home/anis/ros_workspace/kuka_controller/lib/orocos/gnulinux/libXDESimpleController-gnulinux.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller/libXDESimpleController-gnulinux.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller/libXDESimpleController-gnulinux.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller/libXDESimpleController-gnulinux.so"
         OLD_RPATH "/usr/lib/orocos/gnulinux/ocl:/usr/lib/orocos/gnulinux/ocl/plugins:/usr/lib/orocos/gnulinux/ocl/types:/usr/local/lib:/opt/ros/groovy/lib:/home/anis/libs/CoinIpopt/build/lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../x86_64-linux-gnu:/home/anis/ros_workspace/orocos/orocos_toolchain/rtt/install/lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../../lib:/lib/../lib:/usr/lib/../lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../..:/home/anis/libs/gurobi563/linux64/lib:/home/anis/libs/ReflexxesTypeII/Linux/x64/release/lib/shared:/home/anis/libs/boost_1_56_0/bin.v2/libs::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"
         NEW_RPATH "/usr/local/lib/orocos/gnulinux:/usr/local/lib:/usr/local/lib/orocos/gnulinux/kuka_controller:/usr/lib/orocos/gnulinux/ocl:/usr/lib/orocos/gnulinux/ocl/plugins:/usr/lib/orocos/gnulinux/ocl/types:/opt/ros/groovy/lib:/home/anis/libs/CoinIpopt/build/lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../x86_64-linux-gnu:/home/anis/ros_workspace/orocos/orocos_toolchain/rtt/install/lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../../../lib:/lib/../lib:/usr/lib/../lib:/usr/lib/gcc/x86_64-linux-gnu/4.6/../../..:/home/anis/libs/gurobi563/linux64/lib:/home/anis/libs/ReflexxesTypeII/Linux/x64/release/lib/shared:/home/anis/libs/boost_1_56_0/bin.v2/libs")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orocos/gnulinux/kuka_controller/libXDESimpleController-gnulinux.so")
    endif()
  endif()
endif()

