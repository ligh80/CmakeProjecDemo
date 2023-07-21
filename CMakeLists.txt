# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

# 定义一个选项功能,默认为ON
option(USE_MYMATH
       "use provided math implementation" ON)

# 根据选项功能将input文件转化成output;作用是让普通文件也能使用CMake中的变量
configure_file(
 "${PROJECT_SOURCE_DIR}/config.h.in"
 "${PROJECT_BINARY_DIR}/config.h" 
)

# 将PROJECT_SOURCE_DIR和PROJECT_BINARY_DIR添加到include路径
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 是否加入 MathFunctions 库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/lib/math") #增加头文件搜索路径
  add_subdirectory (lib/math)   #跳转到该关键字指定的路径下执行该路径下的CMakelist
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions) #增加链接库名字
endif (USE_MYMATH)

# 查找src目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)


# 指定生成目标
add_executable (Demo  ${DIR_SRCS})
target_link_libraries (Demo ${EXTRA_LIBS})
