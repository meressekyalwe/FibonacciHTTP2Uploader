include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE ENGINE_SOURCES *.cpp *.c)
file(GLOB_RECURSE ENGINE_HEADERS *.hpp *.h *.inl)

add_executable(FibonacciHTTP2Uploader ${ENGINE_SOURCES} ${ENGINE_HEADERS})
find_package(SQLite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIR})

target_link_libraries(FibonacciHTTP2Uploader PRIVATE cpr::cpr)
target_link_libraries(FibonacciHTTP2Uploader PRIVATE SQLite::SQLite3)