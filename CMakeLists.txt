cmake_minimum_required(VERSION 3.16)

# Nombre del proyecto y estándar de C++
project(CONSULTUM VERSION 1.0 LANGUAGES CXX)

# Selección del estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Constantes de subdirectorios
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/design/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/design/include")
# set(EXTERNAL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external/include")
set(EXTERNAL_LIB_DIR "$ENV{TBBROOT}/lib")

set(CMAKE_CXX_COMPILER "/opt/intel/oneapi/2025.1/bin/icpx")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsycl")

# Recoger todos los .cpp en SRC_DIR
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# Añadir los directorios de includes 
include_directories(
    ${INCLUDE_DIR}
    # ${EXTERNAL_INCLUDE_DIR}
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Vincular librerías externas si es necesario
# (por ejemplo, si tienes archivos .a o .so en EXTERNAL_LIB_DIR)
target_link_directories(${PROJECT_NAME} PRIVATE ${EXTERNAL_LIB_DIR})

# Especificar las librerías a enlazar, si las conoces
target_link_libraries(${PROJECT_NAME} tbb)

# Ejemplo si quieres linkear "libmiLibreria.a" manualmente:
# target_link_libraries(${PROJECT_NAME} miLibreria)
