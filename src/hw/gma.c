
#include "gma.h"
#include "memmap.h" // add_e820
#include "output.h" //dprintf
#define MMIO_READ(addr, value, bits) {\
    value = *((u##bits *)gmmio + (addr));\
}

#define MMIO_WRITE(addr, value, bits) {\
    *((u##bits *)gmmio + (addr)) = value;\
    u32 flush;\
    MMIO_READ((addr + 0x32), flush, 32);\
    flush = 0x0;\
}


/* FIXME: error handler ?*/

static
u32 setup_opRegion(void)
{
    /* FIXME: implement setup opRegion
     * Current implementation simply mask register value to 0x0*/
    return 0;
}

u32 gma_setup(struct pci_device *pci)
{
    /* check again */
    if(!IS_DEVICE_IGD(pci->device))
        return 1;
    
    u16 ggc = pci_config_readw(0, 0x50);
    pci_config_writel(pci->bdf, 0x50, ggc);

    u32 bdsm = pci_config_readl(0, 0xB4);
    pci_config_writel(pci->bdf, 0x5C, bdsm);
    return 0;

}
