cmake_minimum_required(VERSION 3.15)
project(eight_minute_empire)

set(CMAKE_CXX_STANDARD 14)

include_directories(Bidding)
include_directories(Card)
include_directories(GameMainLoop)
include_directories(GameScore)
include_directories(GameState)
include_directories("James's Part 2/Bidding")
include_directories("James's Part 2/Card")
include_directories("James's Part 2/GameMainLoop")
include_directories("James's Part 2/GameScore")
include_directories("James's Part 2/GameState")
include_directories("James's Part 2/Map")
include_directories("James's Part 2/MapLoader")
include_directories("James's Part 2/Player")
include_directories("James's Part 2/StartUpPhase")
include_directories(Map)
include_directories(MapLoader)
include_directories(Player)
include_directories(StartUpPhase)

add_executable(eight_minute_empire
        Bidding/Bidding.cpp
        Bidding/Bidding.h
        Bidding/BiddingDriver.cpp
        Bidding/BiddingDriver.h
        Card/CardDriver.h
        Card/Cards.cpp
        Card/Cards.h
        Card/CardsDriver.cpp
        GameMainLoop/GameMainLoop.cpp
        GameMainLoop/GameMainLoop.h
        GameScore/GameScore.cpp
        GameScore/GameScore.h
        GameScore/GameScoreDriver.cpp
        GameScore/GameScoreDriver.h
        GameState/GameState.cpp
        GameState/GameState.h
        GameState/GameStateDriver.cpp
        GameState/GameStateDriver.h
        "James's Part 2/Bidding/Bidding.cpp"
        "James's Part 2/Bidding/Bidding.h"
        "James's Part 2/Bidding/BiddingDriver.cpp"
        "James's Part 2/Bidding/BiddingDriver.h"
        "James's Part 2/Card/CardDriver.h"
        "James's Part 2/Card/Cards.cpp"
        "James's Part 2/Card/Cards.h"
        "James's Part 2/Card/CardsDriver.cpp"
        "James's Part 2/GameMainLoop/GameMainLoop.cpp"
        "James's Part 2/GameMainLoop/GameMainLoop.h"
        "James's Part 2/GameScore/GameScore.cpp"
        "James's Part 2/GameScore/GameScore.h"
        "James's Part 2/GameScore/GameScoreDriver.cpp"
        "James's Part 2/GameScore/GameScoreDriver.h"
        "James's Part 2/GameState/GameState.cpp"
        "James's Part 2/GameState/GameState.h"
        "James's Part 2/GameState/GameStateDriver.cpp"
        "James's Part 2/GameState/GameStateDriver.h"
        "James's Part 2/Map/Map.cpp"
        "James's Part 2/Map/Map.h"
        "James's Part 2/Map/MapDriver.cpp"
        "James's Part 2/Map/MapDriver.h"
        "James's Part 2/MapLoader/MapLoader.cpp"
        "James's Part 2/MapLoader/MapLoader.h"
        "James's Part 2/MapLoader/MapLoaderDriver"
        "James's Part 2/MapLoader/MapLoaderDriver.cpp"
        "James's Part 2/MapLoader/MapLoaderDriver.h"
        "James's Part 2/Player/Player.cpp"
        "James's Part 2/Player/Player.h"
        "James's Part 2/Player/PlayerDriver.cpp"
        "James's Part 2/Player/PlayerDriver.h"
        "James's Part 2/StartUpPhase/StartUpPhase.cpp"
        "James's Part 2/StartUpPhase/StartUpPhase.h"
        "James's Part 2/StartUpPhase/StartUpPhaseDriver.cpp"
        "James's Part 2/StartUpPhase/StartUpPhaseDriver.h"
        "James's Part 2/example.map"
        "James's Part 2/main"
        "James's Part 2/main.cpp"
        "James's Part 2/MapLoaderDriver"
        "James's Part 2/README.md"
        "James's Part 2/short_syntax.map"
        "James's Part 2/version1.map"
        Map/Map.cpp
        Map/Map.h
        Map/MapDriver.cpp
        Map/MapDriver.h
        MapLoader/MapLoader.cpp
        MapLoader/MapLoader.h
        MapLoader/MapLoaderDriver
        MapLoader/MapLoaderDriver.cpp
        MapLoader/MapLoaderDriver.h
        Player/Player.cpp
        Player/Player.h
        Player/PlayerDriver.cpp
        Player/PlayerDriver.h
        StartUpPhase/StartUpPhase.cpp
        StartUpPhase/StartUpPhase.h
        StartUpPhase/StartUpPhaseDriver.cpp
        StartUpPhase/StartUpPhaseDriver.h
        example.map
        main
        main.cpp
        README.md
        short_syntax.map
        version1.map)
