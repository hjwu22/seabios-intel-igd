#ifndef _GMA_H_
#define _GMA_H_
#include "types.h"
/* FIXME: make ajustable */ 
/* The current implementation fixes DEV0_0_0_CGF_0x50_[7:3] to 0x08 
 * which pre allocate 480MB memory for IGD.
 * possible value are
 * 0x00         0MB
 * 0x01         32MB
 * 0x02         64MB
 * y, y<=0x10   32*y MB
 * 
 * As GTT Stolen is always fixed at 2MB, the base address of GTT stolen
 * is next to MMCFG which the size is of 256MB at B000_0000h,
 * thus the base address of GTT Stolen is C000_0000h,
 * and stolen memory base addr is C001_0000h.
 * Aware that the lower boundary of PCI memory hole is E000_0000,
 * so total stolen memory address space should not over E000_0000
 * in this case, C000_0000 + 482 << 20 = DE01_0000
 */
#define GFX_STOLEN_SIZE         (480 * 1024 * 1024)
#define GFX_GTT_STOLEN_SIZE     (2 * 1024 *1024)
#define GFX_GTT_STOLEN_BASE     0xC0000000
#define GFX_STOLEN_BASE     (GFX_GTT_STOLEN_BASE + GFX_GTT_STOLEN_SIZE)


/* Intel Gen4 Core Family */
#define IS_DEVICE_HASWELL(did) \
    (did == 0x0402 || \
     did == 0x0412 || \
     did == 0x0422 )

/* Intel Gen3 Core Family */
#define IS_DEVICE_IVYBRIDGE(did) \
    (did == 0x0512)

#define IS_DEVICE_IGD(did) (\
    IS_DEVICE_HASWELL(did) || \
    IS_DEVICE_IVYBRIDGE(did) )


u32 gma_setup(u16 did);
#endif
