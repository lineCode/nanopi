#include <stdio.h>
#include "libfahw.h"

static struct sensor fire[] = {
        {
                TINY4412_GPIO_PIN1,
                IRQ_TYPE_EDGE_FALLING,
        }
};

int main(void)
{
    int i;
    int retSize = -1;
    char value[ARRAY_SIZE(fire)];
    int devFD = -1;
    if ((devFD =sensorInit(fire, ARRAY_SIZE(fire))) == -1) {
        printf("Fail to init sensor\n");
        return -1;
    }

    if (( retSize = sensorRead(devFD, value, ARRAY_SIZE(fire)) ) == -1) {
        printf("Fail to read sensors\n");
    }
    if (retSize > 0) {
        i = 0;
        for(i=0; i<retSize; i++)
        {
            printf("fire:%d\n", value[i]);
        }
    }
    sensorDeinit(devFD);
    return 0;
}
