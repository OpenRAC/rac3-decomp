#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 800488.c's earlier functions (tools/port_from_us.py) */
typedef struct {
    u32 *dst;
    u32 size;
    u32 pad8;
    u32 entry;
} Hdr_800488;
extern u8 D_8C6200[];
extern u8 D_00806080[];
extern void func_00800160(void *, void *);
extern void func_008026F0(void);
extern u32 func_00800488(void);

INCLUDE_ASM("asm/i5bootn/nonmatchings/text", func_008006E0);
