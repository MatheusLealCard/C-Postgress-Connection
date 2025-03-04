cmake_minimum_required(VERSION 3.31.5)
project(PostgresExample)

set(CMAKE_CXX_STANDARD 17)

find_package(PostgreSQL REQUIRED)
find_package(PkgConfig REQUIRED)

# Definir caminhos manualmente
set(PQXX_INCLUDE_DIRS /opt/homebrew/Cellar/libpqxx/7.10.0/include)
set(PQXX_LIBRARIES /opt/homebrew/Cellar/libpqxx/7.10.0/lib/libpqxx.dylib)
set(PostgreSQL_LIBRARIES /opt/homebrew/opt/postgresql@14/lib/postgresql@14/libpq.dylib)

add_executable(main sign_in.cpp)

target_include_directories(main PRIVATE ${PQXX_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${PQXX_LIBRARIES} ${PostgreSQL_LIBRARIES})

