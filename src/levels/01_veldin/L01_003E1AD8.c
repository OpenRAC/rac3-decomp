#include "common.h"

/* localdecomp:start func_L01_003E1AD8 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_0038D328(f32 *, u8 *);
extern s32 func_00382498(s32, s32);
extern void func_0038D890(f32 *, f32 *, f32 *, f32);
extern void func_003C48A8(f32 *, u8 *);

u8 *func_L01_003E1AD8(u8 *src, s32 id, s32 type) {
    u8 *m;
    long t;
    f32 v[16];
    f32 r;

    m = func_003C24B0(id, 128);
    if (m != 0) {
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        *(f32 *)(m + 44) *= *(f32 *)(src + 44) / *(f32 *)(*(u8 **)(src + 36) + 36);
        *(u128_t *)(m + 16) = *(u128_t *)(src + 16);
        func_0038D328(v, src + 240);
        r = (f32)func_00382498(0, 7) * 3.1415927f * 0.25f;
        func_0038D890(v + 4, v + 4, v, r);
        func_0038D890(v + 8, v + 8, v, r);
        func_003C48A8(v, m + 240);
        t = *(long *)(src + 56);
        m[48] = type;
        *(s16 *)(m + 52) = 0;
        *(long *)(m + 56) = t;
        func_003C7C38(m);
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 36) + 16);
        return m;
    }
    return 0;
}
/* localdecomp:end func_L01_003E1AD8 */

/* localdecomp:start func_L01_003E1C00 */
extern u8 *func_L01_003E1AD8(u8 *src, s32 id, s32 type);
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
extern u8 D_L01_001D66B0[];
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L01_003E1C00(void *o) {
    if (func_L01_00447490(o, -1, 0) != 0) {
        func_003A52A0(0, 0, o);
        func_L01_00451FE0(o, 15, D_L01_001D66B0, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        ((void (*)(void *, s32, s32))func_L01_003E1AD8)(o, 0x1e3d, 0);
        func_L01_00451E78(o, 1, 0.0f);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L01_003E1C00 */

INCLUDE_ASM("asm/levels", func_L01_003E1CD0);

INCLUDE_ASM("asm/levels", func_L01_003E1D68);

/* localdecomp:start func_L01_003E1DC0 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
typedef int s128 __attribute__((mode(TI)));
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 *func_L01_003B1750(u8 *, s128 *, s128 *, s32, s32, s32, s32, f32, f32);
void func_L01_003E1DC0(u8 *o, s32 *p) {
    s128 v[2];
    switch (*p) {
    case 0x13A1:
        func_L01_003303B8(o + 16, 1, 25, 20, 20, 20, 45, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                      1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        break;
    case 0x19C5:
        v[0] = *(s128 *)(o + 16);
        v[1] = *(s128 *)(o + 192);
        func_L01_003B1750(o, &v[0], &v[1], 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 0.0f, 0.65f);
        break;
    }
}
/* localdecomp:end func_L01_003E1DC0 */

/* localdecomp:start func_L01_003E1F08 */
void func_L01_004450F0(s32, s32, s32);
void func_L01_003E1F08(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) != 3) {
        func_L01_004450F0((s32) arg0, 3, -1);
    }
}
/* localdecomp:end func_L01_003E1F08 */

LINKER_REMNANT("asm/levels", func_L01_003E1F38);
