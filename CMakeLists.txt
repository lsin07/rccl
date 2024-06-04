cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++11")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
    src-gen
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
link_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(talker
  src/publisher_member_function.cpp
  src-gen/v1/rccltest/RcclTestSomeIPStubAdapter.cpp
  src-gen/v1/rccltest/RcclTestSomeIPDeployment.cpp
  )
target_link_libraries(talker CommonAPI CommonAPI-SomeIP vsomeip3)
ament_target_dependencies(talker rclcpp std_msgs)

install(TARGETS
  talker
  DESTINATION lib/${PROJECT_NAME})

add_executable(listener
  src/subscriber_member_function.cpp
)
ament_target_dependencies(listener rclcpp std_msgs)

add_executable(RcclTestClient
    src/RcclTestClient.cpp
    src-gen/v1/rccltest/RcclTestSomeIPProxy.cpp
    src-gen/v1/rccltest/RcclTestSomeIPDeployment.cpp
)
target_link_libraries(RcclTestClient CommonAPI CommonAPI-SomeIP vsomeip3)
  
install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
