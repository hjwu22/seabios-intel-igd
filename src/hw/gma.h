#ifndef _GMA_H_
#define _GMA_H_
#include "types.h"
/* FIXME: make ajustable */ 
/* The current implementation fixes DEV0_0_0_CGF_0x50_[7:3] to 0x08 
 * which pre allocate 256MB memory for IGD.
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
 *
 */
#define GFX_STOLEN_SIZE         (256 * 1024 * 1024)
#define GFX_GTT_STOLEN_SIZE     (2 * 1024 *1024)
#define GFX_GTT_STOLEN_BASE     0xC0010000
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
