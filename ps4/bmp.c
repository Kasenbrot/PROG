#include <stdio.h>
#include <stdlib.h>
#include "./bmp.h"

struct bmp_header* read_bmp_header(FILE* stream){

    if(stream == NULL){                                                         //ak je stream prazdny, ukoncime funkciu
        return NULL;
    }

    struct bmp_header* hlavicka = calloc(1, sizeof(struct bmp_header));         //deklaracia pointra pre header
    fseek(stream,0,SEEK_SET);                                                   //presunutie kurzora na zaciatok fileu
    fread(hlavicka, sizeof(struct bmp_header), 1, stream);                      //precitanie hlavicky a ulozenie do pointra

    if (hlavicka->type != 0x4D42)                                               //overovanie ci sme nacitali hlavicku BMP obrazku
    {
        fclose(stream);
        free(hlavicka);
        fprintf(stderr, "Error: This is not a BMP file.\n");
        return NULL;
    }

    return hlavicka;
}

bool write_bmp(FILE* stream, const struct bmp_image* image){

    if(stream != NULL && image != NULL){

            //zapisanie hlavicky do fileu
        fwrite(image->header, sizeof(struct bmp_header), 1, stream);

        int pocet_pixelov = (image->header->width * image->header->height);
        
        for (size_t i = 0; i < 23; i++){}
        
        //cyklime sa cez pixely a zapisujeme jeden za druhym
        for (size_t i = 0; i < pocet_pixelov; i++)
        {
            if(i % image->header->width == 0 && i != 0){
                //tu pchame padding
                if(image->header->width % 4 != 0){
                    fwrite("\0", 1, (image->header->width % 4) , stream);
                }     
            }
            fwrite(&image->data[i], sizeof(struct pixel), 1, stream);
        }
        if(image->header->width % 4 != 0){
            fwrite("\0",1,image->header->width % 4,stream);
        }
        return true;
    }   
    return false;
};

struct pixel* read_data(FILE* stream, const struct bmp_header * header){

    if(stream == NULL || header == NULL){                                                         //ak je stream prazdny, ukoncime funkciu
        return NULL;
    }

    int number_of_pixels = header->height * header->width;

    struct pixel* stvorceky = calloc(number_of_pixels, sizeof(struct pixel));         //deklaracia pointra pre pixely
    fseek(stream, header->offset ,SEEK_SET);  

    int pocet = 0;
    int sucet = 0;

    int padding = (4 - ((3 * header->width) % 4)) % 4;
    
    for (size_t i = 0; i < header->height; i++)                                     //stlpce
    {  
        for (size_t j = 0; j < header->width; j++)                                  //riadok
        {
            sucet += fread(&stvorceky[pocet],sizeof(struct pixel),1,stream);
            pocet++;
        }

        fseek(stream,padding, SEEK_CUR);
        
    }

    if (sucet != number_of_pixels)
    {
        free(stvorceky);
        return NULL;
    }

    return stvorceky;
};

void free_bmp_image(struct bmp_image* image){

    if (image != NULL)
    {
        if (image->data != NULL)
        {
            free(image->data);
        }
        if (image->header != NULL)
        {
            free(image->header);
        }  
        free(image);
    }
}

//TODO
struct bmp_image* read_bmp(FILE* stream){

    if(stream == NULL){                                                         //ak je stream prazdny, ukoncime funkciu
        return NULL;
    }
    
    //  zadeklarovat si tie jednotlive pointre: bmp_image, bmp_header, pixel format
    struct bmp_header* hlavicka = NULL;
    struct pixel* stvorceky = NULL;
    struct bmp_image* obrazok = calloc(1, sizeof(struct bmp_image));

    //  dosadis vystupy z danych funkcii 

    hlavicka = read_bmp_header(stream);

    if (hlavicka == NULL)                                               //overovanie ci sme nacitali hlavicku BMP obrazku
    {
        fclose(stream);
        free_bmp_image(obrazok);
        return NULL;
    }

    stvorceky = read_data(stream, hlavicka);

    if (stvorceky == NULL)                                               //overovanie ci sme nacitali hlavicku BMP obrazku
    {
        fclose(stream);
        free_bmp_image(obrazok);
        fprintf(stderr,"Error: Corrupted BMP file.\n");
        return NULL;
    }

    obrazok->header = hlavicka;
    obrazok->data = stvorceky;

    // header_pointer* == NULL { *bezpecne ukoncenie funkcie* }
    if(hlavicka == NULL || stvorceky == NULL){
        free(obrazok);
        free_bmp_image(obrazok);
        return NULL;
    }

    // nezabudnut overovat ci nahodou funkcie nevratili null

    //
    return obrazok;
}
