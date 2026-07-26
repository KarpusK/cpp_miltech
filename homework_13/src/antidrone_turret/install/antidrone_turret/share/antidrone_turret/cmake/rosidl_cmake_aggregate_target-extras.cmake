# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target antidrone_turret::antidrone_turret
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${antidrone_turret_TARGETS}.
if(antidrone_turret_TARGETS AND NOT TARGET antidrone_turret::antidrone_turret)
  add_library(antidrone_turret::antidrone_turret INTERFACE IMPORTED)
  set_target_properties(antidrone_turret::antidrone_turret PROPERTIES
    INTERFACE_LINK_LIBRARIES "${antidrone_turret_TARGETS}")
endif()
