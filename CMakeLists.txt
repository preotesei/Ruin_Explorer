cmake_minimum_required(VERSION 3.21)
project(Ruin_Explorer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Ruin_Explorer
        .idea/.gitignore
        .idea/modules.xml
        ".idea/Ruin Explorer.iml"
        .idea/workspace.xml
        ActionsMadeByHero.cpp
        ActionsMadeByHero.h
        BattleVsMobs.cpp
        BattleVsMobs.h
        Game.cpp
        Game.h
        Hero.cpp
        Hero.h
        Monster.cpp
        Monster.h
        Utilities.cpp
        Utilities.h
        Zona.cpp
        Zona.h
        main.cpp)
