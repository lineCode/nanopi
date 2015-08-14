#include <stdio.h>
#include "libfahw.h"

static struct sensor lean[] = {
        {
                TINY4412_GPIO_PIN1,
                IRQ_TYPE_EDGE_RISING,
        }
};

int main(void)
{
    int i;
    int retSize = -1;
    char value[ARRAY_SIZE(lean)];
    int devFD = -1;
    if ((devFD =sensorInit(lean, ARRAY_SIZE(lean))) == -1) {
        printf("Fail to init sensor\n");
        return -1;
    }

    if (( retSize = sensorRead(devFD, value, ARRAY_SIZE(lean)) ) == -1) {
        printf("Fail to read sensors\n");
    }
    if (retSize > 0) {
        i = 0;
        for(i=0; i<retSize; i++)
        {
            printf("lean:%d\n", value[i]);
        }
    }
    sensorDeinit(devFD);
    return 0;
}
