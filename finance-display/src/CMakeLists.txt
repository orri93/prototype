
list(APPEND gos_finance_display_library_source
  format.cpp)

list(APPEND gos_finance_display_library_definitions
  GOS_PROTOTYPE)

list(APPEND gos_finance_display_library_include
  ${gos_finance_display_include})

add_library(${gos_finance_display_library_target}
  ${gos_finance_display_library_source})

if (gos_finance_display_library_definitions)
  target_compile_definitions(${gos_finance_display_library_target} PUBLIC
    ${gos_finance_display_library_definitions})
endif ()

target_include_directories(${gos_finance_display_library_target} PUBLIC
  ${gos_finance_display_library_include})

if (BUILD_PROTOTYPE)
  list(APPEND gos_finance_display_prototype_source
    prototype.cpp)
  list(APPEND gos_finance_display_prototype_include
    ${gos_finance_display_include})
  list(APPEND gos_finance_display_prototype_libraries
    ${gos_finance_display_library_target})
  add_executable(${gos_finance_display_prototype_target})
  if (gos_finance_display_library_definitions)
    target_compile_definitions(${gos_finance_display_prototype_target} PUBLIC
      ${gos_finance_display_library_definitions})
  endif ()
  target_include_directories(${gos_finance_display_prototype_target} PUBLIC
    ${gos_finance_display_prototype_include})
  target_link_libraries(${gos_finance_display_prototype_target}
    ${gos_finance_display_prototype_libraries})
endif (BUILD_PROTOTYPE)
