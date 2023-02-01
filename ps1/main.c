#include <stdio.h>
#include "bmp.h"
#include <stdlib.h>

int main(){

    char* reversed = reverse("Hello world!");
    printf("%s\n", reversed);
////////////////////////////////////
    char* encrypted;
    encrypted = vigenere_encrypt("CoMPuTeR", "Hello world!");
    printf("%s\n", encrypted);
// "JSXAI PSINR!"///////////////////
    char* decrypted;
    decrypted = vigenere_decrypt("CoMPuTeR", "JSXAI PSINR!");
    printf("%s\n", decrypted);
//////////////////////////////////////
/*    unsigned char* encrypted_bit;
    encrypted_bit = bit_encrypt("H");
        for(int i=0; i < 12;i++) {
            printf("%s ", encrypted);
            //80 9c 95 95 96 11 bc 96 b9 95 9d 10
        }
    free(encrypted);
*/
///////////////////////////////////////////////
    return 0;
}




