#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AAD90.c's earlier functions */
extern void func_003AB520();
extern s32 D_001D81D0[];
extern void func_003AB520(u8 *p, s32 f);

extern s32 D_001D81D0[];
/* localdecomp:start func_003ABE10 */
void func_003ABE10(void *p) {
    *(s32 **)((u8 *)p + 0x24) = &D_001D81D0[0];
    ((void (*)(void *))func_003AB520)(p);
}
/* localdecomp:end func_003ABE10 */

/* localdecomp:start func_003ABE38 */
void func_003ABE38(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x3C) = value;
}
/* localdecomp:end func_003ABE38 */

/* localdecomp:start func_003ABE40 */
void func_003ABE40(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x38) = value;
}
/* localdecomp:end func_003ABE40 */

/* localdecomp:start func_003ABE48 */
extern void func_00391150(s32, s32, s32, f32);
void func_003ABE48(u8 *p) {
    func_00391150(*(s32 *)(p + 0x38), -1, *(s32 *)(p + 0x28), **(f32 **)(p + 4));
}
/* localdecomp:end func_003ABE48 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003ABE78);

/* localdecomp:start func_003ABE80 */
typedef struct { f32 x, y; } V2_A6520;
typedef struct { V2_A6520 *f0; V2_A6520 *f4; u8 p8[4]; s32 *fC; f32 *f10; u8 p14[0x14]; s32 f28; u8 p2C[4]; s32 f30; u8 p34[4]; s32 f38; s32 f3C; } O_A6520;
extern s32 func_003ABE48_A6520();
extern long func_00389978(s32);

extern void func_00391458_A6520(f32, f32, f32, s32, s32, s32, s32, s32);
void func_003ABE80(O_A6520 *o) {
    s32 t;
    f32 x;
    V2_A6520 *p0;
    V2_A6520 *p4;
    s32 a;
    if (*o->f10 != 0.0f && o->f38 != 0) {
        t = func_003ABE48_A6520(o);
        x = o->f0->x;
        switch (o->f3C) {
        case 0:
            break;
        case 1:
            x -= (f32)(t >> 1);
            break;
        case 2:
            x -= (f32)t;
            break;
        }
        a = *o->fC;
        p0 = o->f0;
        p4 = o->f4;
        func_00391458_A6520(x, p0->y, p4->x, a, o->f38, t, ((s32 (*)(s32))func_00389978)(o->f30), o->f28);
    }
}
/* localdecomp:end func_003ABE80 */

/* localdecomp:start func_003ABF98 */
void func_003ABF98(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x34) = value;
}
/* localdecomp:end func_003ABF98 */
