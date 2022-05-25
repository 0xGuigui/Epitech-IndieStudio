# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais;/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais")
set(CPACK_CMAKE_GENERATOR "Unix Makefiles")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "/usr/local/share/cmake-3.19/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "indie built using CMake")
set(CPACK_GENERATOR "ZIP;TGZ")
set(CPACK_INSTALL_CMAKE_PROJECTS "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais;indie;ALL;/")
set(CPACK_INSTALL_PREFIX "/usr/local")
set(CPACK_MODULE_PATH "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais/_deps/raylib-src/cmake")
set(CPACK_NSIS_DISPLAY_NAME "raylib 4.0.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "raylib 4.0.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais/_deps/raylib-src/src/../README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Simple and easy-to-use library to enjoy videogames programming")
set(CPACK_PACKAGE_FILE_NAME "raylib-4.0.0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "raylib 4.0.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "raylib 4.0.0")
set(CPACK_PACKAGE_NAME "raylib")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "4.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "")
set(CPACK_PACKAGE_VERSION_MINOR "")
set(CPACK_PACKAGE_VERSION_PATCH "")
set(CPACK_RESOURCE_FILE_LICENSE "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais/_deps/raylib-src/src/../LICENSE")
set(CPACK_RESOURCE_FILE_README "/usr/local/share/cmake-3.19/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais/_deps/raylib-src/src/../README.md")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Linux")
set(CPACK_TOPLEVEL_TAG "Linux")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/yusisako/Documents/2nd year epitech/B-YEP-400-LIL-4-1-indiestudio-paul.gervais/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
