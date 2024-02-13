# export CMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake
cmake_minimum_required(VERSION 3.25.0)
project(cpp-unnecessary VERSION 0.0.1 LANGUAGES C CXX)

add_executable(cpp-unnecessary src/main.cpp)

include(CTest)
enable_testing()

# include(CPack)
# include($ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

# find_package(poco CONFIG REQUIRED)
# find_package(Poco REQUIRED Util)
find_package(Poco CONFIG REQUIRED Util)
target_link_libraries (cpp-unnecessary PRIVATE Poco::Util)

# find_package(Boost CONFIG REQUIRED)
# target_link_libraries (cpp-unnecessary PRIVATE boost::any)
# target_link_libraries (cpp-unnecessary PRIVATE boost::uuid)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(cpp-unnecessary PRIVATE unofficial::sqlite3::sqlite3)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
