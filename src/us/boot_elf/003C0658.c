#include "common.h"

/* NTSC-U version of func_003C0760 (boot_elf): 0.02 -> 0.0166667 */
#include "common.h"


typedef int u128_t __attribute__((mode(TI)));



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
typedef struct { u8 b[8]; } V8_3B98B8;
typedef struct { u128_t q[4]; } M4_3B98B8;
u8 func_U_003BDEC0(void);
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x74]; s16 hAA; } S_3B9BE8;
typedef int Q_3B9C50 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9C50;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u8 padA[2];
    s32 wC;
    Q_3B9C50 q10;
    V4_3B9C50 v20;
    Q_3B9C50 q30;
} S_3B9C50;
typedef struct { u8 pad[4]; u8 b4; } T_3B9C50;
typedef int Q_3B9DA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B9DA8;
typedef struct {
    u8 pad0[0x10];
    V4_3B9DA8 v10;
    V4_3B9DA8 v20;
    V4_3B9DA8 v30;
} S_3B9DA8;
typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x15E]; s32 w1A0; } S_3BA108;
extern s32 D_U_001DA3B8;
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
typedef int Q_3BA5B8 __attribute__((mode(TI)));
typedef struct { u8 pad[0x10]; Q_3BA5B8 q10; u8 pad20[0x12]; s16 h32; } B_3BA5B8;
typedef struct {
    B_3BA5B8 *b;
    s32 w4;
    f32 f8;
    u8 bC, bD, bE, bF;
    union { Q_3BA5B8 q; f32 f[4]; } q10;
} Sub_3BA5B8;
typedef struct {
    u8 b0, b1, b2, b3;
    s32 w4;
    u8 b8, b9;
    u16 hA;
    f32 fC;
    Q_3BA5B8 q10;
    Sub_3BA5B8 s20;
} S_3BA5B8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BA748;
typedef int Q_3BA748 __attribute__((mode(TI)));
typedef struct { s8 p0[0x20]; s8 b20; } O_3BA748;
typedef struct { O_3BA748 *obj; s32 f4; u8 p8[5]; u8 b0D; u8 pE[2]; V_3BA748 v10; } B_3BA748;
typedef struct { u8 p0[4]; s32 f4; u8 b8; u8 p9; s16 h0A; f32 fC; V_3BA748 v10; B_3BA748 b; } P_3BA748;
extern void func_U_003C3160(u8 *, s32, u8 *);
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
typedef int Q_3BA9A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BA9A0;
typedef struct { f32 x, y; } V2_3BA9A0;
typedef struct { f32 v[3]; } V3_3BA9A0;
typedef struct { u8 pad[8]; u8 b8; } O_3BA9A0;
extern s32 D_U_001D9D80;
extern void func_U_003C3160();
extern void func_U_003A96B0(s32, unsigned long);
extern void func_U_0038CA78(void);
extern void func_U_0038D350();
extern void func_U_0038D148(f32 *, void *, f32);
extern s32 func_U_0038DF00(s32, s32, f32);
typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
extern f32 D_U_001D8E90;
extern f32 D_U_001D8FF8;
extern s32 D_U_001D8FC4;
extern s32 D_U_001D8EB0;
extern s32 D_U_001D8FCC;
extern s32 D_U_001D8FC8;
extern f32 D_U_001D8FD0;
extern f32 D_U_001D8FD4;
extern f32 D_U_001D8FD8;
extern f32 D_U_001D8FDC;
extern f32 D_U_001D8FE8;
extern f32 D_U_001D8FEC;
extern f32 D_U_001D8FF0;
extern f32 D_U_001D8FF4;
extern s32 D_U_001D8FE0;
extern s32 D_U_001D8FE4;
extern s32 D_U_001D8FC0;
extern f32 D_U_001DA3B4;
extern s32 D_U_001D9D80;
extern void func_U_003C3160();
extern void func_U_003A96B0(s32, unsigned long);
extern void func_U_0038CA78(void);
extern void func_U_0038D350();
extern s32 func_U_0038DF00(s32, s32, f32);
extern void func_U_0038D148(f32 *, void *, f32);
extern void func_U_003D99A0(void *, s32, s32, s32, s32, f32);
/* localdecomp:start func_U_003C0658 */
/* from the NTSC decomp's func_003C0658 (the US draft in nonmatching/boot_elf/) */
#include "vu0.h"
__asm__(".extern D_U_001D8E90, 4");
__asm__(".extern D_U_001D8FF8, 4");
__asm__(".extern D_U_001D8FC4, 4");
__asm__(".extern D_U_001D8EB0, 4");
__asm__(".extern D_U_001D8FCC, 4");
__asm__(".extern D_U_001D8FC8, 4");
__asm__(".extern D_U_001D8FD0, 4");
__asm__(".extern D_U_001D8FD4, 4");
__asm__(".extern D_U_001D8FD8, 4");
__asm__(".extern D_U_001D8FDC, 4");
__asm__(".extern D_U_001D8FE8, 4");
__asm__(".extern D_U_001D8FEC, 4");
__asm__(".extern D_U_001D8FF0, 4");
__asm__(".extern D_U_001D8FF4, 4");
__asm__(".extern D_U_001D8FE0, 4");
__asm__(".extern D_U_001D8FE4, 4");
__asm__(".extern D_U_001D8FC0, 4");
extern s32 D_U_001DA3B8;
extern f32 D_U_001DA3B4;
extern s32 D_U_001D9D80;
extern void func_U_003C3160();
extern void func_U_003A96B0(s32, unsigned long);
extern void func_U_0038CA78(void);
extern void func_U_0038D350();
extern s32 func_U_0038DF00(s32, s32, f32);
extern void func_U_0038D148(f32 *, void *, f32);
extern void func_U_003D99A0(void *, s32, s32, s32, s32, f32);
void func_U_003C0658(void *p) {
    V4_3BAE98 m0[3];
    V4_3BAE98 m30;
    V4_3BAE98 m40[3];
    V4_3BAE98 m70;
    V4_3BAE98 m80[4];
    f32 k, ph, t, s, w;
    s32 i, j, n, col, al, lo;
    u8 ob;
    k = D_U_001DA3B4 / (D_U_001D8E90 * 0.0166666675f);
    if (D_U_001D8FF8 < k) {
        func_U_003C3160(p, 0, m80);
        k = 1.0f;
        ph = (f32)(D_U_001D9D80 % D_U_001D8FC4) / (f32)D_U_001D8FC4;
        func_U_003A96B0(8, 0);
        func_U_003A96B0(0x14, 0xFF9000000260UL);
        func_U_003A96B0(0x47, 0x533F1);
        func_U_0038CA78();
        for (i = 0; i < 4; i++) {
            m0[0] = m80[1];
            m0[1] = m80[2];
            m0[2] = m80[0];
            func_U_0038D350(&m30, (V4_3BAE98 *)&D_U_001D8EB0 + i, m80);
            for (j = 0; j < D_U_001D8FCC; j++) {
                n = D_U_001D8FC8;
                t = (f32)((D_U_001DA3B8 + n / D_U_001D8FCC * j) % n) / (f32)n;
                ob = i & 1;
                if (ob) {
                    t += 0.5f;
                    if (1.0f < t) t -= 1.0f;
                }
                t = t * t;
                if (i < 2) {
                    w = (D_U_001D8FD4 - D_U_001D8FD0) * t * k + D_U_001D8FD0;
                    s = (D_U_001D8FDC - D_U_001D8FD8) * t + D_U_001D8FD8;
                } else {
                    w = (D_U_001D8FEC - D_U_001D8FE8) * t * k + D_U_001D8FE8;
                    s = (D_U_001D8FF4 - D_U_001D8FF0) * t + D_U_001D8FF0;
                }
                col = func_U_0038DF00(D_U_001D8FE0, D_U_001D8FE4, t);
                lo = col & 0xFFFFFF;
                al = (s32)((f32)((u32)(col & 0xFF000000) >> 24) * k);
                col = lo | (al << 24);
                func_U_0038D148((f32 *)&m40[0], &m0[0], s);
                func_U_0038D148((f32 *)&m40[1], &m0[1], s);
                func_U_0038D148((f32 *)&m40[2], &m0[2], w);
                vec_sub_ab(&m70, &m30, &m40[2]);
                func_U_003D99A0(m40, D_U_001D8FC0, col, 4, 1, ph + t + (f32)(i & 1) * 0.5f);
            }
        }
        func_U_003A96B0(0x47, 0x5360B);
    }
}
/* localdecomp:end func_U_003C0658 */
