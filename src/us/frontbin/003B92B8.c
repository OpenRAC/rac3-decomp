#include "common.h"

/* NTSC-U counterpart of func_003BE7B0 (src/frontbin/3BE528.c): particle colour 0x43 -> 0x50, 0.02f -> 1/60.0f */
/* localdecomp:start func_U_003B92B8 */
typedef struct {
    f32 x, y, z, fC, f10;
    u8 b14, b15;
    u8 pad16[6];
    void *f1C;
} Q_3B9160;
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
extern void func_U_00388830(s32, s32, f32);
extern void func_U_00388758(void *, void *, void *);
extern f32 func_U_00388770(void *);
extern void func_U_00388700(void *, void *, f32);
extern f32 func_U_00388960(f32);
extern s32 func_U_0037E1D8(s32);
extern f32 func_U_0037E250(f32, f32);
extern S_3B9160 *func_U_003B9160(Q_3B9160 *, f32 *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_U_003B92B8(u8 *obj, V4_3B92B8 *pos, V4_3B92B8 *tgt, f32 *ang) {
    V4_3B92B8 m0, m10, m20, m30, m40, m50, m60, m70;
    Q_3B92B8 x, y;
    f32 a, a1, a2;
    f32 l;
    m0 = *(V4_3B92B8 *)(obj + 0xC0);
    m10 = *(V4_3B92B8 *)(obj + 0xD0);
    func_U_00388830((s32)&m0, (s32)&m0, 1.0f);
    func_U_00388830((s32)&m10, (s32)&m10, 1.0f);
    func_U_00388758(&m20, &m0, &m10);
    m30 = m10;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*tgt));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(m50) : "j"(x));
    m40 = m50;
    l = func_U_00388770(&m40);
    func_U_00388700(&m50, &m30, l * 0.1f);
    a = *ang;
    a1 = a + 2.09439611f;
    a2 = a + 4.18878937f;
    if (3.14159274f < a1) a1 -= 6.28318548f;
    if (3.14159274f < a2) a2 -= 6.28318548f;

    func_U_00388830((s32)&m50, (s32)&m0, func_U_00388960(a) * 0.25f);
    func_U_00388830((s32)&m60, (s32)&m20, func_U_00388960(a) * 0.25f);
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
    func_U_003B9160((Q_3B9160 *)&m70, (f32 *)&m30, 0x50, 0x808080, func_U_0037E1D8(0xC), 0x40, 0x20,
                  func_U_0037E250(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_U_0037E250(0.04f, 0.1f) * 0.016666668f));

    func_U_00388830((s32)&m50, (s32)&m0, func_U_00388960(a1) * 0.25f);
    func_U_00388830((s32)&m60, (s32)&m20, func_U_00388960(a1) * 0.25f);
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
    func_U_003B9160((Q_3B9160 *)&m70, (f32 *)&m30, 0x50, 0x808080, func_U_0037E1D8(0xC), 0x40, 0x20,
                  func_U_0037E250(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_U_0037E250(0.04f, 0.1f) * 0.016666668f));

    func_U_00388830((s32)&m50, (s32)&m0, func_U_00388960(a2) * 0.25f);
    func_U_00388830((s32)&m60, (s32)&m20, func_U_00388960(a2) * 0.25f);
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
    func_U_003B9160((Q_3B9160 *)&m70, (f32 *)&m30, 0x50, 0x808080, func_U_0037E1D8(0xC), 0x40, 0x20,
                  func_U_0037E250(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_U_0037E250(0.04f, 0.1f) * 0.016666668f));

    *ang -= func_U_0037E250(0.02f, 0.2f);
    if (*ang < -3.14159274f) *ang += 6.28318548f;
}
/* localdecomp:end func_U_003B92B8 */
