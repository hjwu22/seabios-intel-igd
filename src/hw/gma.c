
#include "gma.h"
#include "memmap.h" // add_e820
/* FIXME: error handler ?*/

    static 
u32 setup_stolen(void)
{
    add_e820(GFX_GTT_STOLEN_BASE, GFX_GTT_STOLEN_SIZE, E820_RESERVED);
    add_e820(GFX_STOLEN_BASE, GFX_STOLEN_SIZE, E820_RESERVED);
    return 0;
}


static
u32 setup_opRegion(void)
{
    /* FIXME: implement setup opRegion
     * Current implementation simply mask register value to 0x0*/
    return 0;
}

u32 gma_setup(u16 did)
{
    /* check again*/
    if(!IS_DEVICE_IGD(did))
        return 1;
    
    setup_stolen();
    setup_opRegion();
    
    return 0;

}
