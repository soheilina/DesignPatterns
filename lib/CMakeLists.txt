file (GLOB SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp
)

# add_executable(${PROJECT_NAME} ${SRC_FILES})
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/headers ${CMAKE_SOURCE_DIR}/tests)
# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

add_library(${PROJECT_NAME}_lib STATIC ${SRC_FILES})
target_include_directories(${PROJECT_NAME}_lib INTERFACE "${PROJECT_SOURCE_DIR}/lib") #NOTE: you can use ${CMAKE_CURRENT_SOURCE_DIR} instead of "${PROJECT_SOURCE_DIR}/lib"
