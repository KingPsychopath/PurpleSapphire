#include "common.h"
#include "iphone2g.h"

enum class device_type
{
    iphone2g
};

int main(int ac, char** av)
{   
    if(ac < 2)
    {
        printf("usage: purplesapphire [device]\n");
        printf("device can be \"iphone2g\". No other devices are supported at this time.");
        return 1;
    }

    std::string device = av[1];
    device_type dev_type;
    if(device == "iphone2g") dev_type = device_type::iphone2g;
    else return 2;

    iphone2g dev;

    dev.init();

    FILE* fp = fopen("roms/iphone1-bootrom.bin","rb");
    fread(dev.bootrom, 1, 0x10000, fp);
    fclose(fp);

    printf("Opcode: %08x\n", dev.rw(0));

    return 0;
}