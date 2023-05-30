# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\l10__autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\l10__autogen.dir\\ParseCache.txt"
  "l10__autogen"
  )
endif()
