#include "common.h"

/* localdecomp:start func_L39_006928D0 */
__asm__(".extern D_L39_0024D760, 16");

typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_006928D0_inner;

typedef struct {
    char pad[0x38];
    S_006928D0_inner *f38;
} S_006928D0_outer;

typedef struct {
    char pad[0x284];
    s32 f284;
} S_006928D0_slot;

extern S_006928D0_outer *D_L39_0024D760;
extern S_006928D0_slot *D_001DC204_sda;

s32 func_L39_006928D0(void)
{
    S_006928D0_inner *inner = D_L39_0024D760->f38;
    s32 result = 0;

    if (inner->f34 == 0) {
        if (inner->f0 == -1) {
            D_001DC204_sda->f284 = 8;
            result = 1;
        } else {
            D_001DC204_sda->f284 = 6;
            result = 1;
        }
    }
    return result;
}
/* localdecomp:end func_L39_006928D0 */

INCLUDE_ASM("asm/levels", func_L39_00692918);

INCLUDE_ASM("asm/levels", func_L39_00692C38);

INCLUDE_ASM("asm/levels", func_L39_00692F20);

LINKER_REMNANT("asm/levels", func_L39_006932C8);

INCLUDE_ASM("asm/levels", func_L39_006932E8);

LINKER_REMNANT("asm/levels", func_L39_006938E0);

/* localdecomp:start func_L39_006938E8 */
extern u8 D_L39_0047CA68[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006938E8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047CA68;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006938E8 */

INCLUDE_ASM("asm/levels", func_L39_00693910);

/* localdecomp:start func_L39_00693F40 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00693F40(void *);

extern void func_L39_0067F168();
void func_L39_00693F40(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00693F40 */

INCLUDE_ASM("asm/levels", func_L39_00693F70);
