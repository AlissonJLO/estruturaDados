# Definindo a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(MeuProjeto)

include(CTest)
enable_testing()


# Definindo o padrão de C++ para C++11
set(CMAKE_CXX_STANDARD 20)

# Incluindo todos os arquivos .cpp da pasta src/
file(GLOB SOURCES "src/*.cpp")

# Criando o executável
add_executable(meu_programa ${SOURCES})
