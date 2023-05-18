cmake_minimum_required(VERSION 3.22.1)
project(BWT_SEMB VERSION 1.0)
set(CMAKE_C_STANDARD 17)
message("Todas as configurações foram feitas")
add_executable(
    bwt
    BWT/file_manager.c
    BWT/file_manager.h
    ApplicationArgs/app_args.c
    ApplicationArgs/app_args.h
    BWT/bwt.c
    BWT/bwt.h
    main.c
)