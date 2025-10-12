cmake_minimum_required(VERSION 3.16)
project(SFMLapp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Thêm đường dẫn thư mục include (nơi có Account.h, User.h, ...)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Tìm SFML (2.5 cũng được, 3.0.2 cũng được tùy bạn cài bản nào)
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

# Gom tất cả file .cpp trong src/
file(GLOB SRC_FILES src/*.cpp)

# Tạo executable
add_executable(SFMLapp ${SRC_FILES})

# Link SFML
target_link_libraries(SFMLapp sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
