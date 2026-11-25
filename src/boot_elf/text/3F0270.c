#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003F02D0();
extern void func_003F03A0(void *p, f32, f32);
extern void func_003F0358(u8 *p, u8, s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003F0270 */
extern char D_001D9670[];
extern s32 func_003F2738();
void func_003F0270(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003F0270 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F02A0);

/* localdecomp:start func_003F02C8 */
s32 func_003F02C8(void) {
    return 2;
}
/* localdecomp:end func_003F02C8 */

/* localdecomp:start func_003F02D0 */
extern void func_003EDD40(void);
extern u8 D_001D9798[];
void *func_003F02D0(void *arg0) {
    func_003EDD40();
    (*(s32 **)((u8 *)arg0 + 8)) = D_001D9798;
    (*(s32 *)((u8 *)arg0 + 0x50)) = 0x80808080;
    (*(s8 *)((u8 *)arg0 + 0x54)) = 0x10;
    (*(s32 *)((u8 *)arg0 + 0x2C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x30)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x38)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x3C)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x40)) = 0;
    (*(s8 *)((u8 *)arg0 + 0x44)) = 0;
    (*(s32 *)((u8 *)arg0 + 0x48)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x4C)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x34)) = 0;
    (*(f32 *)((u8 *)arg0 + 0x5C)) = 1.0f;
    (*(f32 *)((u8 *)arg0 + 0x60)) = 1.0f;
    (*(s32 *)((u8 *)arg0 + 0x58)) = 2;
    return arg0;
}
/* localdecomp:end func_003F02D0 */

/* localdecomp:start func_003F0358 */
void func_003F0358(u8 *p, u8 m, s32 set) {
    if (set != 0) {
        p[0x44] |= m;
    } else {
        p[0x44] &= ~m;
    }
}
/* localdecomp:end func_003F0358 */

/* localdecomp:start func_003F0388 */
s32 func_003F0388(void *a0, s32 a1) {
    s32 b = a1 & 0xff;
    return (*(u8 *)((u8 *)a0 + 0x44) & b) != 0;
}
/* localdecomp:end func_003F0388 */

/* localdecomp:start func_003F03A0 */
void func_003F03A0(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x48) = x;
    *(f32 *)((u8 *)p + 0x4C) = y;
}
/* localdecomp:end func_003F03A0 */
