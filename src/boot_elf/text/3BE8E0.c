#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BE8E0();
extern void func_003BE948();
/* --- end of declarations from other files --- */

/* declarations of 3BE710.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001DA2D0_003BE800;
extern u8 D_001DA2D4_003BE800;
extern s32 D_001DA2D8_003BE800;
extern s32 D_001DA2DC_003BE800;
extern s32 D_001D8D28_003BE800;
extern s32 D_001D8D40_003BE800;
extern u8 D_001D8D2C_003BE800[8];
extern u8 D_001D8D44_003BE800[8];
extern s32 D_002FCDC4[];
extern void func_003BBDC0(s32, s32);
extern void func_003BC7C0();
extern void func_003BE068(s32, s32 *, s32);
extern s32 func_003BE0F0();
extern void func_003BE1D8();
extern void func_003BE6C0();

/* localdecomp:start func_003BE8E0 */
extern s32 func_003BE940();
extern void func_003BF130();
void func_003BE8E0(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x19E9:
        ok = 1;
        *(void **)(p + 0x64) = func_003BE940;
        break;
    case 0x1D98:
        ok = 1;
        *(void **)(p + 0x64) = func_003BF130;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003BE8E0 */

/* localdecomp:start func_003BE940 */
s32 func_003BE940(void) {
}
/* localdecomp:end func_003BE940 */

/* localdecomp:start func_003BE948 */
typedef int Q_3B9098 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9098;
typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; } Sub_3B9098;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 b8;
    u8 pad9;
    u8 hA[2];
    f32 fC;
    V4_3B9098 v10;
    Sub_3B9098 s20;
} S_3B9098;
extern s32 func_0038CEE0(void *);
extern void func_003CD608(s32);
void func_003BE948(S_3B9098 *p) {
    Sub_3B9098 *s;
    V4_3B9098 v;
    Q_3B9098 a, b;
    if (func_0038CEE0(p->hA)) {
        func_003CD608((s32)p);
        return;
    }
    s = &p->s20;
    p->w4 = (p->w4 & 0xFFFFFF) | (((p->w4 >> 24) + s->b14) << 24);
    v.w = 0;
    v.x = s->f0;
    v.y = s->f4;
    v.z = s->f8;
    __asm__("lqc2 %0, %1" : "=j"(a) : "m"(p->v10));
    __asm__("lqc2 %0, %1" : "=j"(b) : "m"(v));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(a) : "j"(a), "j"(b));
    __asm__("sqc2 %1, %0" : "=m"(p->v10) : "j"(a));
    s->f8 -= s->fC;
    p->b8 += s->b15;
    p->fC += s->f10;
}
/* localdecomp:end func_003BE948 */

typedef int u128_3B9160 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, fC, f10;
    u8 b14, b15;
    u8 pad16[6];
    void *f1C;
} Q_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 x4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    u128_3B9160 v10;
    Q_3B9160 q;
} P_3B9160;
extern void *func_003CD4C0(s32);
extern s32 func_00382848(s32);
extern u8 *D_002FCF20[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BEA10);

typedef struct { f32 f0, f4, f8, fC, f10; u8 b14, b15; u8 pad16[6]; void *f1C; } Sub_3B9160;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3B9160 q10;
    Sub_3B9160 s20;
} S_3B9160;
typedef int Q_3B92B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B92B8;
extern void func_0038D348(s32, s32, f32);
extern void func_0038D270(void *, void *, void *);
extern f32 func_0038D288(void *);
extern void func_0038D218(void *, void *, f32);
extern f32 func_0038D478(f32);
extern s32 func_00382848();
extern f32 func_003828C0(f32, f32);
extern S_3B9160 *func_003BEA10(Q_3B9160 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BEB68);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BEFE0);

/* localdecomp:start func_003BF130 */
extern void func_003BF168();
extern void func_0038A2F8();
extern void func_003BEFE0(void *);
void func_003BF130(void *p) {
    func_0038A2F8(func_003BF168, p);
    func_003BEFE0(p);
}
/* localdecomp:end func_003BF130 */
