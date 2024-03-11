set(gos_finance_display_library_target libfinancedisplay)
set(gos_finance_display_prototype_target financedisplay)

set(gos_finance_display_source_include "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(gos_finance_display_binary_include "${CMAKE_CURRENT_BINARY_DIR}/include")

list(APPEND gos_finance_display_include
  ${gos_finance_display_source_include}
  ${gos_finance_display_binary_include})

add_subdirectory(src)

if (BUILD_TESTS)
  add_subdirectory(tests)
endif (BUILD_TESTS)
