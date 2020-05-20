cmake_minimum_required(VERSION 3.16)
project(Embedded_Software_Elements C)

set(CMAKE_C_STANDARD 99)

add_executable(Embedded_Software_Elements main.c; ring_buffer/ring_buffer_unit_test.c; ring_buffer/ring_buffer_unit_test.h; ring_buffer/ring_buffer.c; ring_buffer/ring_buffer.h; simply_linked_list/simply_linked_list_unit_test.h; simply_linked_list/simply_linked_list_unit_test.c; simply_linked_list/linked_list.c; simply_linked_list/linked_list.h;
        )