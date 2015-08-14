#include <stdio.h>
#include <unistd.h> 
#include "libfahw.h"

int main(int argc, char ** argv)
{   
    int CKPin = TINY4412_GPIO_PIN1;
    int LDPin = TINY4412_GPIO_PIN2;
    int DIPin = TINY4412_GPIO_PIN3;
    int pos;
    int number;
    if (digitronInit(CKPin, LDPin, DIPin) == -1) {
        printf("Fail to init digitron");
    }

    for (number = 0; number <= 9; number++) {
        for (pos = 1; pos <= 4; pos++) {
            if (digitronDispChar(pos, number) == -1) {
                printf("Fail to display %d at %d\n",number, pos);
            }
            printf("Displaying number %d at position %d\n", number, pos);
            sleep(1);
        }
    }    
    digitronDeInit();
    return 0;
}
