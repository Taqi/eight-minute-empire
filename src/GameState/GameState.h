#pragma once
#include "Cards.h"
#include "Map.h"
#include "MapLoader.h"
#include "Player.h"
#include <iostream>

// Forward Declaration
class Deck;

class GameState {
public:
  // game state member variables public as their purpose is to be mutated
  // throughout the game

  // game map
  Map *map;

  // deck of cards and hand placed on table
  Deck *deck;

  // players
  std::vector<Player *> *players;

  GameState();
  ~GameState();

  int determineGameLength();
};