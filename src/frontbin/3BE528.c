#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


/* localdecomp:start func_003BE528 */
extern s32 func_003BE588();
extern void func_003BED78();
void func_003BE528(u8 *p) {
    s32 ok = 0;
    switch (*(s16 *)(p + 0xAA)) {
    case 0x19E9:
        ok = 1;
        *(void **)(p + 0x64) = func_003BE588;
        break;
    case 0x1D98:
        ok = 1;
        *(void **)(p + 0x64) = func_003BED78;
        break;
    }
    if (ok) *(u16 *)(p + 0x34) &= ~2;
    else *(u16 *)(p + 0x34) |= 2;
}
/* localdecomp:end func_003BE528 */

/* localdecomp:start func_003BE588 */
s32 func_003BE588(void) {
}
/* localdecomp:end func_003BE588 */

/* localdecomp:start func_003BE590 */
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
extern s32 func_0038CB00(void *);
extern void func_003CD250(s32);
void func_003BE590(S_3B9098 *p) {
    Sub_3B9098 *s;
    V4_3B9098 v;
    Q_3B9098 a, b;
    if (func_0038CB00(p->hA)) {
        func_003CD250((s32)p);
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
/* localdecomp:end func_003BE590 */

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
extern void *func_003CD108(s32);
extern s32 func_00382468(s32);
extern u8 *D_002FCF20[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BE658);

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
extern void func_0038CF68(s32, s32, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE38(void *, void *, f32);
extern f32 func_0038D098(f32);
extern s32 func_00382468();
extern f32 func_003824E0(f32, f32);
extern S_3B9160 *func_003BE658(Q_3B9160 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003BE7B0);

INCLUDE_ASM("asm/nonmatchings/text", func_003BEC28);

/* localdecomp:start func_003BED78 */
extern void func_003BEDB0_003BED78();
extern void func_00389F18();
extern void func_003BEC28(void *);
void func_003BED78(void *p) {
    func_00389F18(func_003BEDB0_003BED78, p);
    func_003BEC28(p);
}
/* localdecomp:end func_003BED78 */
