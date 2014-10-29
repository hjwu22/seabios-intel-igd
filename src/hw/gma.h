#ifndef _GMA_H_
#define _GMA_H_
#include "types.h"
#include "hw/pci.h" // foreachpci

/* The current implementation fixes DEV0_0_0_CGF_0x50_[7:3] to 0x08 
 * which pre allocate 480MB memory for IGD.
 * possible value are
 * 0x00         0MB
 * 0x01         32MB
 * 0x02         64MB
 * y, y<=0x10   32*y MB
 * The base of GFX stolen memory is TOLUD - GFX stolen memory size.
 * The base of GFX GTT stolen memory is base of GFX stolen memory - 2MB. 
 */
#define GFX_STOLEN_SIZE (0xf << 25)

/* Intel Gen4 Core Family */
#define IS_DEVICE_HASWELL(did) \
    (did == 0x0402 || \
     did == 0x0412 || \
     did == 0x0422 || \
     did == 0x041a)

/* Intel Gen3 Core Family */
#define IS_DEVICE_IVYBRIDGE(did) \
    (did == 0x0512)

#define IS_DEVICE_IGD(did) (\
    IS_DEVICE_HASWELL(did) || \
    IS_DEVICE_IVYBRIDGE(did) )


u32 gma_setup(struct pci_device *);
#endif
