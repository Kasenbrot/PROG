#include <stdio.h>

int main() {

    int i = 0;
    char ch;
    int x = 0;
    while (i == 0) {
        scanf("%c", &ch);
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
            x = x + (int)(ch-48);
        }
        else {
            break;
        }
}
//////////////////////////////////////////////////////////////////////////
    int sum = 0;
    for (int a = 0; a < 10; a++ ){
        sum = 0;
        while (x!=0){
            sum += x%10;
            x = x/10;
        }
        x = sum;
    }
    printf("%d\n", sum);

    //return sum;
}
