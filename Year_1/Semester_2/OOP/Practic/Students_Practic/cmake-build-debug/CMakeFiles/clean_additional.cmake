# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Students_Practic_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Students_Practic_autogen.dir\\ParseCache.txt"
  "Students_Practic_autogen"
  )
endif()
