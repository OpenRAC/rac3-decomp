#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

INCLUDE_ASM("asm/levels", func_L39_004C1F40);

/* localdecomp:start func_L39_004C2068 */
/* Near miss, ported from rac4-decomp's func_L00_004FDE68 (cross-game near pair). NEAR: SQ_RA: frame 0x20/ra@0x10 vs 0x10; v0/v1 swap in inner-pointer loads goes with it; rest of body identical */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

extern char *func_L39_004BEED8(void);
extern int func_L39_004C2118(void *, int);
typedef struct Inner { int pad[12]; int ready; void *value; } Inner;
typedef struct Outer { char pad[80]; Inner *inner; char pad2[188]; unsigned int size; int other; } Outer;

int func_L39_004C2068(Outer *p)
{
    void *value;
    unsigned int size;
    if (p->inner->ready == 0 && func_L39_004C2118(p, p->other) == 0) goto fail;
    if (p->inner->value) goto success;
    size = p->size;
    if (size - 1 > 0x8000) { p->size = 0x8001; size = 0x8001; }
    value = ((void *(*)(unsigned int))func_L39_004BEED8)(size);
    if (!value) goto fail;
    p->inner->value = value;
success:
    return 1;
fail:
    func_L39_004BC6C8(20, 219, 33, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004C2068 */

INCLUDE_ASM("asm/levels", func_L39_004C2118);

INCLUDE_ASM("asm/levels", func_L39_004C21E0);

INCLUDE_ASM("asm/levels", func_L39_004C22B0);

INCLUDE_ASM("asm/levels", func_L39_004C23A0);

INCLUDE_ASM("asm/levels", func_L39_004C23F8);
