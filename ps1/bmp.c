#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



/*unsigned char* bit_encrypt(const char* text){
    if (text == NULL){
        return NULL;
    }            
}
*/
/////////////////////////////////////////////////////////////////////////////
char* vigenere_decrypt(const char* key, const char* text){
    if ((text == NULL || key == NULL) || (strlen(key) == 1 && key[0] == ' ')){
        return NULL;
    }
    int len = strlen(text);
    int len2 = strlen(key);
    int x = 0;
    for ( int i = 0; i < len2; i++ ){
        if (key[i] < 65 || key[i] > 122 || (key[i] > 90 && key[i] < 97)){
            return NULL;
        }
    }
                                     
    char* result = (char*)calloc(len + 1, sizeof(char));
    for( int index = 0; index < len; index++ ){
        if ((text[index] > 64 && text[index] < 91) || (text[index] > 96 && text[index] < 123)){
            if (((toupper(text[index]) - 'A') - (toupper(key[(index-x)%len2]) - 'A')) > -1){
                result[index] = ((toupper(text[index]) - 'A') - (toupper(key[(index-x)%len2]) - 'A')) % 26 + 'A';
            }
            else{
                result[index] = ((toupper(text[index]) - 'A') - (toupper(key[(index-x)%len2]) - 'A')+26) + 'A';
            }
        }
        else {
            result[index] = text[index];
            x = x + 1;
        }
    }
    result[len] = '\0';
    return result;
}
///////////////////////////////////////////////////////////////////
char* vigenere_encrypt(const char* key, const char* text){
    if ((text == NULL || key == NULL) || (strlen(key) == 1 && key[0] == ' ')){
        return NULL;
    }
    int len = strlen(text);
    int len2 = strlen(key);
    int x = 0;
    char* result = (char*)calloc(len + 1, sizeof(char));
    for ( int i = 0; i < len2; i++ ){
        if (key[i] < 65 || key[i] > 122 || (key[i] > 90 && key[i] < 97)){
            return NULL;
        }
    }
    for( int index = 0; index < len; index++ ){
        if ((text[index] > 64 && text[index] < 91) || (text[index] > 96 && text[index] < 123)){
            result[index] = ((toupper(text[index]) - 'A') + (toupper(key[(index-x)%len2]) - 'A' + 1)-1) % 26 + 'A';
        }
        else {
            result[index] = text[index];
            x = x + 1;
        }
    }
    result[len] = '\0';
    return result;    
}
/////////////////////////////////////////////////////////////////////
char* reverse(const char* text){
    if (text == NULL){
        return NULL;
    }
    int len = strlen(text);
    char* result = (char*)calloc(len + 1, sizeof(char));
    
    for (int index = 0; index < len; index++){
        result[index] = (toupper(text[len - index - 1]));
    }
    result[len] = '\0';
    return result;
}

    



