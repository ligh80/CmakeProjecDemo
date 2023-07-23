# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

# 增加项目头文件搜索路径
include_directories ("${PROJECT_SOURCE_DIR}/include") #增加项目头文件搜索路径





# 以下使能模块控制功能
###################################################################################
# 根据选项功能将input文件转化成output;作用是让普通文件也能使用CMake中的变量
configure_file(
 "${PROJECT_SOURCE_DIR}/config.h.in"
 "${PROJECT_BINARY_DIR}/config.h" 
)

# 将PROJECT_SOURCE_DIR和PROJECT_BINARY_DIR添加到include路径
# PROJECT_SOURCE_DIR是根目录 PROJECT_BINARY_DIR通常是${PROJECT_SOURCE_DIR}/build
set(CMAKE_INCLUDE_CURRENT_DIR ON)
####################################################################################

# 以下的对具体模块的编译控制
#####################################################################################
option (USE_MYMATH
       "use provided math implementation" ON)

# 是否加入 MathFunctions 库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/lib/math") #增加具体模块头文件搜索路径
  add_subdirectory (lib/math)   #跳转到该关键字指定的路径下执行该路径下的CMakelist
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions) #增加链接库名字
endif (USE_MYMATH)
####################################################################################3
# add google test library & add test sample
set(gtest_force_shared_crt ON CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib.")
add_subdirectory("${PROJECT_SOURCE_DIR}/lib/googletest")
include_directories("${PROJECT_SOURCE_DIR}/lib/googletest/googletest/include")
add_subdirectory("${PROJECT_SOURCE_DIR}/test")

####################################################################################




# 显示当前所包含的所有include路径
get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs=${dirs}") #打印一下目录情况

# 查找src目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(./src DIR_SRCS)

# 指定生成目标
add_executable (Demo  ${DIR_SRCS})
target_link_libraries (Demo ${EXTRA_LIBS})


#以下使用CTEST来启动测试 使用make test来启动
# 启用测试
enable_testing()

# 测试程序是否成功运行
add_test (test_run Demo 5 2)

# 测试帮助信息是否可以正常提示
add_test (test_usage Demo)
set_tests_properties (test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")

# 测试 5 的平方
add_test (test_5_2 Demo 5 2)

set_tests_properties (test_5_2
  PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

# 测试 10 的 5 次方
add_test (test_10_5 Demo 10 5)

set_tests_properties (test_10_5
 PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")

# 测试 2 的 10 次方
add_test (test_2_10 Demo 2 10)

 set_tests_properties (test_2_10 PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")
