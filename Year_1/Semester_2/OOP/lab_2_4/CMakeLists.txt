cmake_minimum_required(VERSION 3.24)
project(lab_2_4 C)

set(CMAKE_C_STANDARD 17)
include_directories(src)
set(SOURCE_FILES
        lab2_4/model/electronic.h
        lab2_4/my_list/MyList.h)
add_executable(lab_2_4 magazin_de_electronice.c model/electronic.h my_list/MyList.h repository/repository.h service/service.h ui/ui.h ui/ui.c service/service.c model/electronic.c my_list/MyList.c)
