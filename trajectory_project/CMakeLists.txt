cmake_minimum_required(VERSION 3.16)

project(trajectory_project LANGUAGES CXX)

add_library(trajectory_lib STATIC
    src/TrajectoryAnalyzer.cpp
)

target_include_directories(trajectory_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(trajectory_lib PUBLIC cxx_std_17)

target_compile_options(trajectory_lib PRIVATE
    -Wall -Wextra -Wpedantic
)

add_executable(trajectory_app
    app/main.cpp
)

target_link_libraries(trajectory_app PRIVATE trajectory_lib)

target_compile_options(trajectory_app PRIVATE
    -Wall -Wextra -Wpedantic
)

find_package(Eigen3 REQUIRED NO_MODULE)

add_executable(eigen_demo app/eigen_demo.cpp)

target_compile_features(eigen_demo PRIVATE cxx_std_17)

target_link_libraries(eigen_demo PRIVATE Eigen3::Eigen)

add_executable(export_trajectory
    app/export_trajectory.cpp
)

target_compile_features(export_trajectory PRIVATE cxx_std_17)

target_compile_options(export_trajectory PRIVATE
    -Wall -Wextra -Wpedantic
)
