cmake_minimum_required(VERSION 3.10)
project(md_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Wextra")

# Trouver les packages nécessaires
find_package(MPI REQUIRED)
find_package(OpenMP REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Inclure les répertoires d'en-têtes
include_directories(${MPI_INCLUDE_PATH})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${Qt5Widgets_INCLUDE_DIRS})

# Ajouter les fichiers source
set(SOURCES
    src/main.cpp
    src/particle.cpp
    src/system.cpp
    src/lennard_jones.cpp
    src/verlet_integrator.cpp
    src/benchmark.cpp
    # Qt file clear
)

# Créer l'exécutable
add_executable(md_simulator ${SOURCES})

# Lier les bibliothèques
target_link_libraries(md_simulator PRIVATE MPI::MPI_CXX OpenMP::OpenMP_CXX Qt5::Widgets)
