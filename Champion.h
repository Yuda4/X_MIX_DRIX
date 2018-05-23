#pragma once
#include "Player.h"

class Champion: public Player {
public:
	int counter=-1;
	int x=0;
	const string name() const override { return "Yehuda and Adiel"; }

	const Coordinate play(const Board& board) override;
};