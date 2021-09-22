// HW001
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  long int decNum1,first,decNum2,second,decFirst=0,decSec=0,lenHexaFirst,lenHexaSec,lenDeciFirst,lenDeciSec;
  int tmp, soucet, rozdil, soucin, podil;
  float prumer;
  char strFirst, strSec;
        
  scanf("%ld  %ld", &decNum1, &decNum2);

    if ( decNum1<-10000 || decNum1>10000 ){
            printf("Vstup je mimo interval!");
            return 1;
    }
    if ( decNum2<-10000 || decNum2>10000 ){
            printf("Vstup je mimo interval!");
            return 1;
    }

  first = decNum1;
  second = decNum2;

        for(lenDeciFirst=abs(first); lenDeciFirst>0; lenDeciFirst=lenDeciFirst/16) {
          tmp = lenDeciFirst % 16;
          if( tmp < 10)
          tmp = tmp + 48; else
          tmp = tmp + 55;
          decFirst=decFirst*100+tmp;
        }
              for(lenDeciSec=abs(second); lenDeciSec>0; lenDeciSec=lenDeciSec/16) {
                tmp = lenDeciSec % 16;
                if( tmp < 10)
                tmp = tmp + 48; else
                tmp = tmp + 55;
                decSec=decSec*100+tmp;
              }

    printf("Decitkova soustava: %ld  %ld", decNum1, decNum2);
    printf("\nSestnactkova soustava: ");

    if(decNum1==0)
            printf(" 0");    
            else if(decNum1<0)
            printf(" -");
            else 
            printf(" ");

        for(lenHexaFirst=decFirst;lenHexaFirst>0;lenHexaFirst=lenHexaFirst/100) {
               strFirst=lenHexaFirst % 100;
               printf("%c",strFirst);
        }

    if(decNum2==0)
            printf(" 0");    
            else if(decNum2<0)
            printf(" -");
            else 
            printf(" ");

        for(lenHexaSec=decSec;lenHexaSec>0;lenHexaSec=lenHexaSec/100) {
               strSec=lenHexaSec % 100;
               printf("%c",strSec);
        }

    soucet = decNum1 + decNum2;
    rozdil = decNum1 - decNum2;
    soucin = decNum1 * decNum2;
    prumer = (decNum1 + decNum2)/2.0;

    printf("\nSoucet: %ld + %ld = %d ", decNum1, decNum2, soucet );
    printf("\nRozdil: %ld - %ld = %d ", decNum1, decNum2, rozdil );
    printf("\nSoucin: %ld * %ld = %d ", decNum1, decNum2, soucin );
            
            if(decNum2==0) {
              printf("\nNedefinovany vysledek!");
            }

            else { 
              podil = decNum1/decNum2;
              printf("\nPodil: %ld / %ld = %d ", decNum1, decNum2, podil );
            }

    printf("\nPrumer: = %.1f ", prumer );

return 0;
}
