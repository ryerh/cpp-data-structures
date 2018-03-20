cmake_minimum_required(VERSION 3.3)
project(data_structure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bstree.c
    bstree.h
    dac.h
    DecimalConverter.h
    eight_queen.h
    functions.h
    graph.h
    linkedlist.h
    main.c
    play.h
    QiuQiu.h
    seqlist.h
    singlelist.h
    sort.h
    stack.h
    utilities.h)

add_executable(data_structure ${SOURCE_FILES})