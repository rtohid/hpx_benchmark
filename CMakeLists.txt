cmake_minimum_required(VERSION 3.17)
project(hpx_datapar_benchmarks VERSION 1.0.0)

find_package(HPX REQUIRED)

enable_testing()

function(add_simd_test target)
  add_hpx_executable(${target} ESSENTIAL SOURCES main.cpp)

  target_compile_options(${target} PUBLIC "-O3" "-std=c++20" "-march=native"
                                          "-fno-tree-vectorize" "-ffast-math")
  target_link_libraries(${target} PUBLIC "-ltbb")

  set(CORES)
  if(${SIMD_CORES})
    set(CORES "--hpx:threads=${SIMD_CORES}")
  endif()

  set(END)
  if(${SIMD_END})
    set(END "--end=${SIMD_END}")
  endif()

  add_test(NAME ${target}_test COMMAND ${target} ${CORES} ${END})
endfunction()

set(subdirs src)

# set(subdirs
#     src
#     for_each
#     count
#     reduce
# )

include_directories("${PROJECT_SOURCE_DIR}")

foreach(subdir ${subdirs})
  message("Adding subdir ${subdir}")
  add_subdirectory(${subdir})
endforeach(subdir)
