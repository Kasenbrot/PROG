#include <stdio.h>
#include <stdlib.h>
#include "./transformations.h"
#include "./bmp.h"
#include <math.h>
#include <ctype.h>
#include <string.h>

struct bmp_image* flip_horizontally(const struct bmp_image* image){

    if(image == NULL){                                                         //ak je stream prazdny, ukoncime funkciu
        return NULL;
    }

    int pocet_pixelov = (image->header->width * image->header->height);

    struct bmp_image* newBmp = calloc(1, sizeof(struct bmp_image));
    struct pixel* stvorceky = calloc(pocet_pixelov, sizeof(struct pixel));
    struct bmp_header* hlavicka = calloc(1, sizeof(struct bmp_header));
    
    int h = image->header->height;
    int w = image->header->width;

    //okopirovanie headera
    memcpy(hlavicka, image->header, sizeof(struct bmp_header));


    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            memcpy(stvorceky + (i * w) + j , image->data + (i * w) + (w-j) - 1, sizeof(struct pixel));
        }
        
    }

    newBmp->header = hlavicka;
    newBmp->data = stvorceky;
    
    return newBmp;
};

struct bmp_image* flip_vertically(const struct bmp_image* image){

    if(image == NULL){                                                         //ak je stream prazdny, ukoncime funkciu
        return NULL;
    }

    int pocet_pixelov = (image->header->width * image->header->height);

    struct bmp_image* newBmp = calloc(1, sizeof(struct bmp_image));
    struct pixel* stvorceky = calloc(pocet_pixelov, sizeof(struct pixel));
    struct bmp_header* hlavicka = calloc(1, sizeof(struct bmp_header));
    
    int h = image->header->height;
    int w = image->header->width;

    //okopirovanie headera
    memcpy(hlavicka, image->header, sizeof(struct bmp_header));


    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            memcpy(stvorceky + (i * w) + j , image->data + (((w * h) - w) + j) - (i * w), sizeof(struct pixel));
        }
        
    }

    newBmp->header = hlavicka;
    newBmp->data = stvorceky;
    
    return newBmp;
};

struct bmp_image* scale(const struct bmp_image* image, float factor){

    if(image != NULL && factor > 0){
        unsigned int h = (unsigned int)round(image->header->height * factor);
        unsigned int w = (unsigned int)round(image->header->width * factor);

    struct bmp_image* output = calloc(1,sizeof(struct bmp_image));
    if(true){}
    unsigned int countPxls = w * h;


    struct pixel* stvorceky = calloc(countPxls, sizeof(struct pixel));
    struct bmp_header* hlavicka = calloc(1,sizeof(struct bmp_header));
    memcpy(hlavicka,image->header,sizeof(struct bmp_header));
    unsigned int dorovnanie =(4 - ((3 * w) % 4)) % 4;                         //komentar
    hlavicka->image_size = countPxls * sizeof(struct pixel) + (h * dorovnanie);
    hlavicka->size = hlavicka->image_size + 54;
    hlavicka->width = w;
    hlavicka->height = h;


    for (float k = 0; k < h; k++)
    {
        for (float l = 0; l < w; l++)
        {
            
            // while(iy+1 <= k/factor){ iy++;};
            // i = ((w * iy) + l) / factor;
            // while(ix+1 <= i){ ix++;};
            // memcpy(stvorceky + (w * k) + l, image->data + ix,sizeof(struct pixel));
            // ix = 0;

            memcpy(stvorceky + (int)((w * k) + l), image->data + (int)(image->header->width * (int)round(k/factor)) + (int)round(l/factor) ,sizeof(struct pixel));
        }
        
    }

    //spojenie
    output->data = stvorceky;
    output->header = hlavicka;

    return output;
    }
    return NULL;
}

struct bmp_image* crop(const struct bmp_image* image, const uint32_t start_y, const uint32_t start_x, const uint32_t height, const uint32_t width){
    
    int h = height;
    int w = width;

    if(image != NULL && h >= 1 && w >= 1){
        if(true){}

        if(start_x + w > image->header->width || start_y + h > image->header->height)
            return NULL;

        if(true){}

        struct bmp_image* output = calloc(1,sizeof(struct bmp_image));
        unsigned int count = w * h;
        struct bmp_header* hlavicka = malloc(sizeof(struct bmp_header));
        struct pixel* stvorceky = calloc(count, sizeof(struct pixel));


        if(true){}
        memcpy(hlavicka,image->header,sizeof(struct bmp_header));
        //toto je tazke
        unsigned int airbag = (4 - ((3*w)%4))%4 ;
        hlavicka->image_size = count * sizeof(struct pixel) + (h * airbag);
        hlavicka->size = hlavicka->image_size + 54;

        hlavicka->width = w;                  //na toto som hrdy
        hlavicka->height = h;
        if(true){}
        for (int k = 0; k < h; k++)
        {
            for (int l = 0; l < w; l++)
            {
                //hlavny chod
                if(true){}
                memcpy(stvorceky + (w * k) + l, image->data + (image->header->width * (k+(image->header->height - h - start_y))) + (l + start_x),sizeof(struct pixel));
            }
        }
        if(true){}
        output->header = hlavicka;
        output->data = stvorceky;
        if(true){}
        return output;
    }
    return NULL;
}

struct bmp_image* extract(const struct bmp_image* image, const char* colors_to_keep){

    if(image == NULL || colors_to_keep == NULL || (strlen(colors_to_keep) != 1 && strlen(colors_to_keep) != 2 && strlen(colors_to_keep) != 3))
        return NULL;

    int r =0,g=0,b=0;

    for (size_t i = 0; i < strlen(colors_to_keep); i++)
    {
        switch (colors_to_keep[i])
        {
        case 'r':
        case 'R':
            if (r){
                return NULL;
            }
            r=1;
            break;
        case 'g':
        case 'G':
            if (g){
                return NULL;
            }
            g=1;
            break;
        case 'b':
        case 'B':
            if (b){
                return NULL;
            }
            b=1;
            break;
        default:
            return NULL;
        }
    }
    int dokopy = r + g + b;
    if(dokopy != strlen(colors_to_keep))
        return NULL;
    
    int pocet_pixelov = (image->header->width * image->header->height);
    struct bmp_image* newBmp = calloc(1, sizeof(struct bmp_image));
    struct pixel* stvorceky = calloc(pocet_pixelov, sizeof(struct pixel));
    struct bmp_header* hlavicka = calloc(1, sizeof(struct bmp_header));


    memcpy(hlavicka, image->header, sizeof(struct bmp_header));



    for (size_t i = 0; i < pocet_pixelov; i++)
    {
        if (b){
            memcpy(&stvorceky[i].blue,&image->data[i].blue,8);

        }else
            stvorceky[i].blue = 0x0;
        if (g){
            memcpy(&stvorceky[i].green,&image->data[i].green,8);
        }else
            stvorceky[i].green = 0x0;
        if (r){
            memcpy(&stvorceky[i].red,&image->data[i].red,8);
        }else
            stvorceky[i].red = 0x0;

    }

    newBmp->header = hlavicka;
    newBmp->data = stvorceky;
    
    return newBmp;
};

struct bmp_image* rotate_right(const struct bmp_image* image){



    if(image == NULL){                                                         //ak je stream prazdny, ukoncime funkciu
        return NULL;
    }


    int pocet_pixelov = (image->header->width * image->header->height);
    struct bmp_image* newBmp = calloc(1, sizeof(struct bmp_image));
    struct pixel* stvorceky = calloc(pocet_pixelov, sizeof(struct pixel));
    struct bmp_header* hlavicka = calloc(1, sizeof(struct bmp_header));
    
    int h = image->header->width;
    int w = image->header->height;

    //okopirovanie headera
    memcpy(hlavicka, image->header, sizeof(struct bmp_header));

    hlavicka->height = h;
    hlavicka->width = w;

    unsigned int airbag = (4 - ((3*w)%4))%4;
    hlavicka->image_size = pocet_pixelov * sizeof(struct pixel) + (h * airbag);
    hlavicka->size = hlavicka->image_size + 54;



    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            memcpy(stvorceky + (i * w) + j, image->data + (j * h) - i -1 +h, sizeof(struct pixel));
        }
        
    }

    newBmp->header = hlavicka;
    newBmp->data = stvorceky;

    return newBmp;
};

struct bmp_image* rotate_left(const struct bmp_image* image){

        if(image == NULL){                                                         //ak je stream prazdny, ukoncime funkciu
        return NULL;
    }


    int pocet_pixelov = (image->header->width * image->header->height);
    struct bmp_image* newBmp = calloc(1, sizeof(struct bmp_image));
    struct pixel* stvorceky = calloc(pocet_pixelov, sizeof(struct pixel));
    struct bmp_header* hlavicka = calloc(1, sizeof(struct bmp_header));
    
    int h = image->header->width;
    int w = image->header->height;

    //okopirovanie headera
    memcpy(hlavicka, image->header, sizeof(struct bmp_header));

    hlavicka->height = h;
    hlavicka->width = w;

    unsigned int airbag =(4 - ((3*w)%4))%4;

    hlavicka->image_size = pocet_pixelov * sizeof(struct pixel) + (h * airbag);
    hlavicka->size = hlavicka->image_size + 54;

    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            memcpy(stvorceky + (i * w) + j , image->data + pocet_pixelov -h - (h * j) + i  , sizeof(struct pixel));
        }
        
    }

    newBmp->header = hlavicka;
    newBmp->data = stvorceky;
    
    return newBmp;
};
