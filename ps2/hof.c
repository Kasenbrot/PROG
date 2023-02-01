#include <stdlib.h>
#include "hof.h"
#include <string.h>
#include <stdio.h>

int cmp_by_score(const void* p1, const void* p2){
    struct player* player1 = (struct player*)p1;
    struct player* player2 = (struct player*)p2;

    int result = player1->score > player2->score?0:1;

    return result;
}

int load(struct player list[]){
    FILE *fp;
    fp = fopen("score", "r");
    int pocet_riadkov;
    for(pocet_riadkov=0; true; pocet_riadkov++){
        if(fscanf(fp, "%s %d", list[pocet_riadkov].name, &list[pocet_riadkov].score) == EOF){
            break;
        }
    }
    qsort(list, (size_t)pocet_riadkov, sizeof(struct player), cmp_by_score);
    fclose(fp);
    return pocet_riadkov;
}
