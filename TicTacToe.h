#pragma once
#include "Board.h"
#include "Player.h"

#include "Champion.h"
#include "DummyPlayers.h"

//using Coordinate=pairs;

class TicTacToe{
    private:
        int _size;
        int counter;
        Board _playGround;
        Player* _winnerPlayer;
    public:
        TicTacToe(): _size(3),_playGround(3),counter(0),_winnerPlayer() {}
        TicTacToe(const int size): _size(size),_playGround(size),counter(0),_winnerPlayer() {}
        
        const Board& board()const;
        
        void play(Player&, Player&);
        Player& winner()const;

        bool game_over(const char);
        bool check_row(const char);
        bool check_colm(const char);
        bool check_diagonal(const char);
};

