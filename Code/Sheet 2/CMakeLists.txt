cmake_minimum_required(VERSION 3.26)
project(Sheet_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Sheet_2
        list.h
        list_add_first.c
        list_add_last.c
        list_get_first.c
        list_get_last.c
        list_new.c
        list_new_random.c
        list_print.c
        list_remove_first.c
        list_remove_last.c
        list_size.c
        node_new.c
        use_list.c
        use_vector.c
        vector.h
        vector_add.c
        vector_mod.c
        vector_new.c
        vector_scale.c
        vector_sprod.c
        vector_sub.c
        vector_vprod.c)
