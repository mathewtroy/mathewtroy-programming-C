/* convert a number from any number system to any other number system  */

#include <stdio.h>
#include <math.h>
#include <string.h>

char int_symbol(int in) {
    char out[]={'0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
    'P','Q','R','S','T','U','V','W','X','Y','Z'};
    return out[in];
}

void ten_base(int in, int base) {
    if (in<base) {
        printf("%c", int_symbol(in));
        return;
    }
    ten_base(in/base,base);
    printf("%c", int_symbol(in%base));
}

int main() {
    long long decimalCislo=0;
    char numFirst[36]={'0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
    'P','Q','R','S','T','U','V','W','X','Y','Z'};

    char numFirstLen[100];
    int numBase1, numBase2, i, j, power=0;

    printf("Enter the number system to enter   (2-36): ");
    scanf("%d", &numBase1);

    printf("Enter the number system for output (2-26): ");
    scanf("%d", &numBase2);

    printf("Enter a number in the %d system: ", numBase1);
    scanf("%s", numFirstLen);

    for(i=strlen(numFirstLen)-1; i >= 0; i--) {
        for(j=0; j<numBase1; j++){
            if(numFirstLen[i] == numFirst[j]) {
                decimalCislo += j*pow(numBase1, power);
            }
        }
        power++;
    }

    printf("Your number is: ");
    ten_base(decimalCislo,numBase2);
    return 0;
}
