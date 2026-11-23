#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003BE528();
extern void func_003BE590();
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
/* localdecomp:start func_003BE658 */
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
S_3B9160 *func_003BE658(Q_3B9160 *pos, f32 *velocity, s32 duration,
    s32 color, s32 delta, s32 alpha0, s32 alpha1, f32 scale0, f32 scale1, f32 gravity) {
    extern void func_003BE590(S_3B9098 *);
    P_3B9160 *p;
    Q_3B9160 *q;
    p = func_003CD108(0x61);
    if (p) {
        u128_3B9160 position = *(u128_3B9160 *)pos;
        p->b1 = 0;
        p->fC = scale0;
        p->v10 = position;
        p->x4 = (alpha0 << 24) | color;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b8 = func_00382468(255);
        p->b2 = D_002FCF20[0][0];
        p->hA = duration;
        q = &p->q;
        q->x = velocity[0];
        q->y = velocity[1];
        q->z = velocity[2];
        q->fC = gravity;
        q->b15 = delta;
        q->f10 = (scale1 - scale0) / duration;
        q->b14 = (alpha1 - alpha0) / duration;
        q->f1C = func_003BE590;
    }
    return (S_3B9160 *)p;
}
/* localdecomp:end func_003BE658 */

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
/* localdecomp:start func_003BE7B0 */
void func_003BE7B0(u8 *obj, V4_3B92B8 *pos, V4_3B92B8 *tgt, f32 *ang) {
    V4_3B92B8 m0, m10, m20, m30, m40, m50, m60, m70;
    Q_3B92B8 x, y;
    f32 a, a1, a2;
    f32 l;
    m0 = *(V4_3B92B8 *)(obj + 0xC0);
    m10 = *(V4_3B92B8 *)(obj + 0xD0);
    func_0038CF68((s32)&m0, (s32)&m0, 1.0f);
    func_0038CF68((s32)&m10, (s32)&m10, 1.0f);
    func_0038CE90(&m20, &m0, &m10);
    m30 = m10;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*tgt));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(m50) : "j"(x));
    m40 = m50;
    l = func_0038CEA8(&m40);
    func_0038CE38(&m50, &m30, l * 0.1f);
    a = *ang;
    a1 = a + 2.09439611f;
    a2 = a + 4.18878937f;
    if (3.14159274f < a1) a1 -= 6.28318548f;
    if (3.14159274f < a2) a2 -= 6.28318548f;

    func_0038CF68((s32)&m50, (s32)&m0, func_0038D098(a) * 0.25f);
    func_0038CF68((s32)&m60, (s32)&m20, func_0038D098(a) * 0.25f);
    {
        Q_3B92B8 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m50));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
    }
    func_003BE658((Q_3B9160 *)&m70, (f32 *)&m30, 0x43, 0x808080, func_00382468(0xC), 0x40, 0x20,
                  func_003824E0(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_003824E0(0.04f, 0.1f) * 0.020000001f));

    func_0038CF68((s32)&m50, (s32)&m0, func_0038D098(a1) * 0.25f);
    func_0038CF68((s32)&m60, (s32)&m20, func_0038D098(a1) * 0.25f);
    {
        Q_3B92B8 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m50));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(y));
    }
    func_003BE658((Q_3B9160 *)&m70, (f32 *)&m30, 0x43, 0x808080, func_00382468(0xC), 0x40, 0x20,
                  func_003824E0(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_003824E0(0.04f, 0.1f) * 0.020000001f));

    func_0038CF68((s32)&m50, (s32)&m0, func_0038D098(a2) * 0.25f);
    func_0038CF68((s32)&m60, (s32)&m20, func_0038D098(a2) * 0.25f);
    {
        Q_3B92B8 x, y;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m50));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
    }
    func_003BE658((Q_3B9160 *)&m70, (f32 *)&m30, 0x43, 0x808080, func_00382468(0xC), 0x40, 0x20,
                  func_003824E0(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_003824E0(0.04f, 0.1f) * 0.020000001f));

    *ang -= func_003824E0(0.02f, 0.2f);
    if (*ang < -3.14159274f) *ang += 6.28318548f;
}
/* localdecomp:end func_003BE7B0 */

/* localdecomp:start func_003BEC28 */
/* func_003BEC28 log: ported from boot_elf's twin func_003BEFE0 (3BE8E0.c); callees renamed
 * (003BE2B8->003BDF00, 0038D200->0038CE20, 0038D3E0->0038D000, 003BEB68->003BE7B0); the twin's
 * in-body externs moved to file scope. */
#include "vu0.h"
typedef struct { Q_3B92B8 v[2]; } Pair_003BEC28;
extern Pair_003BEC28 D_001D8D60;
extern s32 D_001DA2D8_003BEC28[] __attribute__((section(".sdata")));
extern s32 D_001DA2DC_003BEC28[] __attribute__((section(".sdata")));
extern Q_3B92B8 D_001DA2E0_003BEC28 __attribute__((section(".sdata")));
extern Q_3B92B8 D_001DA2F0_003BEC28 __attribute__((section(".sdata")));
extern s32 func_003BDF00(void);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003BE7B0();
void func_003BEC28(void *object)
{
    Pair_003BEC28 pair;
    vu0_v4 pos;
    s32 reset;
    u8 *p = object;
    pair = D_001D8D60;
    reset = func_003BDF00() == 0;
    func_0038CE20(&pos.x, &pair.v[0], *(f32 *)(p + 0x2C));
    *(Q_3B92B8 *)&pos = pair.v[0];
    func_0038D000(&pos, &pos, p + 0xC0);
    vec_add_ab(&pos, &pos, p + 0x10);
    if (reset) D_001DA2E0_003BEC28 = *(Q_3B92B8 *)&pos;
    func_003BE7B0(p, &pos, &D_001DA2E0_003BEC28, D_001DA2D8_003BEC28);
    D_001DA2E0_003BEC28 = *(Q_3B92B8 *)&pos;
    func_0038CE20(&pos.x, &pair.v[1], *(f32 *)(p + 0x2C));
    *(Q_3B92B8 *)&pos = pair.v[1];
    func_0038D000(&pos, &pos, p + 0xC0);
    vec_add_ab(&pos, &pos, p + 0x10);
    if (reset) D_001DA2F0_003BEC28 = *(Q_3B92B8 *)&pos;
    func_003BE7B0(p, &pos, &D_001DA2F0_003BEC28, D_001DA2DC_003BEC28);
    D_001DA2F0_003BEC28 = *(Q_3B92B8 *)&pos;
}
/* localdecomp:end func_003BEC28 */

/* localdecomp:start func_003BED78 */
extern void func_003BEDB0_003BED78();
extern void func_00389F18();
extern void func_003BEC28(void *);
void func_003BED78(void *p) {
    func_00389F18(func_003BEDB0_003BED78, p);
    func_003BEC28(p);
}
/* localdecomp:end func_003BED78 */
