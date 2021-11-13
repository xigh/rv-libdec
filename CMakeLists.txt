cmake_minimum_required(VERSION 2.80)

project(libdec)

# add_subdirectory(rv-libopc)
add_subdirectory(rv-libsys)

add_library(libdec
    src/dec.c
    src/dec_amo.c
    src/dec_auipc.c
    src/dec_branch.c
    src/dec_compr.c
    src/dec_cust.c
    src/dec_ext48.c
    src/dec_ext64.c
    src/dec_ext80.c
    src/dec_fma.c
    src/dec_jal.c
    src/dec_jalr.c
    src/dec_load.c
    src/dec_loadfp.c
    src/dec_lui.c
    src/dec_misc.c
    src/dec_op.c
    src/dec_op32.c
    src/dec_opfp.c
    src/dec_opimm.c
    src/dec_opimm32.c
    src/dec_rsvd.c
    src/dec_store.c
    src/dec_storefp.c
    src/dec_sys.c
    src/extr.c
)

target_link_libraries(libdec rv-libsys)
target_include_directories(libdec PUBLIC include rv-libsys/include rv-libopc/include)
