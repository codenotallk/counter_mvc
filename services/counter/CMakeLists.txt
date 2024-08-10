add_executable (counter_service "")
target_link_libraries (counter_service PUBLIC sat)

target_sources (counter_service
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  ${CMAKE_CURRENT_LIST_DIR}/domain/counter.c
  ${CMAKE_CURRENT_LIST_DIR}/controller/controller.c
  ${CMAKE_CURRENT_LIST_DIR}/controller/provider/counter_json.c
  ${CMAKE_CURRENT_LIST_DIR}/controller/dto/counter_output.c
)

target_include_directories (counter_service
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/domain
  ${CMAKE_CURRENT_LIST_DIR}/controller
  ${CMAKE_CURRENT_LIST_DIR}/controller/provider
  ${CMAKE_CURRENT_LIST_DIR}/controller/dto
)
