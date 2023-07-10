# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\partial_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\partial_autogen.dir\\ParseCache.txt"
  "partial_autogen"
  )
endif()
