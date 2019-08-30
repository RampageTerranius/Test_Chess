#pragma once

enum PieceType {
	TYPE_NONE,
	TYPE_PAWN,
	TYPE_ROOK,
	TYPE_KNIGHT,
	TYPE_BISHOP,
	TYPE_QUEEN,
	TYPE_KING
};

enum PlayerColor {
	PLAYER_NONE,
	PLAYER_BLACK,
	PLAYER_WHITE
};

class Piece {
public:
	Piece();
	void Reset();

	PieceType type;
	PlayerColor player;
};

void Piece::Reset()
{
	type = TYPE_NONE;
	player = PLAYER_NONE;
}

Piece::Piece()
{
	Reset();
}