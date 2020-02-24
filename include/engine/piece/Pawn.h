#ifndef PAWN_H
#define PAWN_H

#include "engine/piece/Piece.h"

class Pawn : public Piece {
  public:
	Pawn(Color color, Position position);
	string get_name() const;

  private:
};

#endif