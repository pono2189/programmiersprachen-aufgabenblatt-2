# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  )

target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  mat2.cpp
  vec2.cpp
  glew.c
  tests.cpp
  circle.cpp
  rectangle.cpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )


