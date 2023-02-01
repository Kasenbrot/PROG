#include <stdio.h>
#include <stdlib.h>
#include "./transformations.h"
#include "./bmp.h"
#include <getopt.h>
#include <string.h>

int main(int argc, char *argv[]){        //argc = argument count argv

    int option = 0;
    int y,x,h,w;
    FILE* fpi = NULL;
    FILE* fpo = NULL;
    struct bmp_image* obrazok = NULL;
    int o = 0;


    while((option = getopt(argc, argv, "i:o:hvlrs:c:e:")) != -1){

        switch (option)
        {
        case 'i':
            fpi = fopen(optarg,"rb");       //otvorenie komunikacneho kanalu
            obrazok = read_bmp(fpi);
            if (obrazok == NULL)
            {
                fprintf(stderr, "Error: Input File doesn't exist.\n");
                return 0;
            }
            
            break;
        case 'o':
            fpo = fopen(optarg,"wb");
            o++;
            break;
        case 'h':

            obrazok = flip_horizontally(obrazok);
            break;
        case 'l':
            obrazok = rotate_left(obrazok);
            break;
        case 'r':
            obrazok = rotate_right(obrazok);
            break;
        case 'v':
            obrazok = flip_vertically(obrazok);
            break;
        case 's':
            obrazok = scale(obrazok, atof(optarg));

            break;
        case 'c':
            if(sizeof(optarg) >= 8)
            {
                sscanf(optarg, "%d,%d,%d,%d",&y,&x,&h,&w);
                obrazok = crop(obrazok,y,x,h,w);
            }else{
                free_bmp_image(obrazok);
                fclose(fpi);
                fclose(fpo);
                return 0;
            }
            break;
        case 'e':
            obrazok = extract(obrazok,optarg);
            if (obrazok == NULL)
            {
                fclose(fpi);
                fclose(fpo);
                return 0;
            }
            

        break;
            
        default:
            printf("Neznamy prepinac %c\n", optopt);
            break;
        }
    }
    for (size_t i = 0; i < 6; i++){}
    

    //vykonanie prepinacov ktore musia ist ako posledne
    if(o != 0 && obrazok != NULL){

        write_bmp(fpo, obrazok);
        
    }


    fclose(fpi);
    fclose(fpo);
    return 0;
}
