add_executable(${PROJECT_NAME}_main ${PROJECT_SOURCE_DIR}/main/main.cpp)

target_link_libraries(${PROJECT_NAME}_main PUBLIC ${PROJECT_NAME}_tst)

#HACK: PROBLEM: in tests/ there are hpp files. Bazel understands either #include "lib/Composite.hpp" or "../lib/Composite.hpp", while cmake understands ONLY #include "Composite.hpp"
#      SOLUTION: To make cmake understands #include "lib/Composite.hpp" we have to include the parent dir of lib.
# target_include_directories(${PROJECT_NAME}_main PUBLIC "${PROJECT_SOURCE_DIR}")
