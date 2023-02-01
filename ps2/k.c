#include <stdlib.h>

#include "k.h"


void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}
<<<<<<< HEAD


//bool is_game_won(const struct game game){
=======
>>>>>>> fecca7b34bb54ee75d45e56ceba26ae2c2ba6923

bool is_game_won(const struct game game){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(game.board[i][j] == 'K')
                return true;
        }
    }
    return false;
}

bool is_move_possible(const struct game game){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(game.board[i][j] == ' ' || (game.board[i][j] == game.board[i-1][j] && i != 0) ||
                    (game.board[i][j] == game.board[i][j-1] && j != 0))
                return true;
        }
    }
    return false;
}

bool update(struct game *game, int dy, int dx){
    if(dy == dx || dy == -dx || 1<dy || dy<-1 || 1<dx || dx<-1){
        return false;
    }
    return true;
}


