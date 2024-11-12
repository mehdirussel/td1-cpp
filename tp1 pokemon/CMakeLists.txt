cmake_minimum_required(VERSION 3.10)

project(td_pokemon)

set(CMAKE_CXX_STANDARD 20)


include_directories(include)


add_executable(pokemon_game
        src/Card.cpp
        src/EnergyCard.cpp
        src/PokemonCard.cpp
        src/TrainerCard.cpp
        src/Player.cpp
        src/main.cpp
)