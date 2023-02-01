#include "k.h"
#include <stdio.h>
#include <stdlib.h>
#include "hof.h"
#include "ui.h"
#include <math.h>
#include <time.h>

int main(){
    struct game game = {
            .board = {
                    {'A', ' ', ' ', ' '},
                    {'B', ' ', ' ', 'B'},
                    {'C', 'C', 'C', ' '},
                    {'D', 'D', 'D', 'D'}
            },
            .score = 0
    };

<<<<<<< HEAD
    printf("is won: %d\n", is_game_won(game));
=======
    bool result = update(&game, 0, 1);

>>>>>>> fecca7b34bb54ee75d45e56ceba26ae2c2ba6923
    add_random_tile(&game);
    render(game);
    printf("is won: %d\n", is_game_won(game));
    printf("is move possible: %d\n", is_move_possible(game));
    printf("%d\n", result);
    struct player a[10];
    int size = load(a);
    printf("%d\n", size);
    return 0;
}



