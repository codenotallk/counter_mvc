add_executable (display_service "")
target_link_libraries (display_service PUBLIC sat pthread)

target_sources (display_service
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/main.c
  ${CMAKE_CURRENT_LIST_DIR}/domain/model/counter.c
  ${CMAKE_CURRENT_LIST_DIR}/domain/repository/counter_repository.c
  ${CMAKE_CURRENT_LIST_DIR}/controller/controller.c
  ${CMAKE_CURRENT_LIST_DIR}/controller/provider/counter_json.c
  ${CMAKE_CURRENT_LIST_DIR}/controller/dto/counter_input.c
  ${CMAKE_CURRENT_LIST_DIR}/presenter/presenter.c
  ${CMAKE_CURRENT_LIST_DIR}/presenter/dto/counter_representation.c
  ${CMAKE_CURRENT_LIST_DIR}/presenter/view/cli.c
)

target_include_directories (display_service
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/domain/model
  ${CMAKE_CURRENT_LIST_DIR}/domain/repository
  ${CMAKE_CURRENT_LIST_DIR}/controller
  ${CMAKE_CURRENT_LIST_DIR}/controller/provider
  ${CMAKE_CURRENT_LIST_DIR}/controller/dto
  ${CMAKE_CURRENT_LIST_DIR}/presenter
  ${CMAKE_CURRENT_LIST_DIR}/presenter/dto
  ${CMAKE_CURRENT_LIST_DIR}/presenter/view
)
