file (GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

add_library(${PROJECT_NAME}_tst SHARED ${SRC_FILES})
target_include_directories(${PROJECT_NAME}_tst INTERFACE
                            "${PROJECT_SOURCE_DIR}/tests"
                            # "${PROJECT_SOURCE_DIR}"
                        )
#HACK: PROBLEM: in tests/ there are hpp files. Bazel understands either #include "lib/Composite.hpp" or "../lib/Composite.hpp", while cmake understands ONLY #include "Composite.hpp"
#      SOLUTION: To make cmake understands #include "lib/Composite.hpp" we have to include the parent dir of lib.
target_include_directories(${PROJECT_NAME}_tst PUBLIC "${PROJECT_SOURCE_DIR}")

# include design_patterns lib to the lib defined above
target_link_libraries(${PROJECT_NAME}_tst PUBLIC ${PROJECT_NAME}_lib)

# make CMake determine the language CXX for this target
set_target_properties(${PROJECT_NAME}_tst PROPERTIES LINKER_LANGUAGE CXX)
#NOTE: SM: You can also use the following line but it sets compiler to a fixed version which sould be specified in toppest cmake file
# target_compile_features(${PROJECT_NAME}_tst PRIVATE cxx_std_17)