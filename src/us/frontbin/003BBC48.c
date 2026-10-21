#include "common.h"

/* NTSC-U version of func_003C1158 (frontbin): 6 -> 7; 6 -> 7 */

typedef int u128_t __attribute__((mode(TI)));

extern s32 func_U_003B8840();
extern void func_U_003B8E10();
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
u8 func_U_003B8700(void);
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 h40; } S_3B9A08;
extern void func_U_003B7288();
extern s32 func_U_003B8A18();
extern s32 func_U_003B8A20();
extern void func_U_003B8C70();
extern void func_U_003B6488();
extern s32 func_U_003B8840();
extern void func_U_003B8968();
extern void func_U_003B8E10();
extern void func_U_003B8A48();
extern void func_U_003B8A68();
extern void func_U_003B8A48();
extern void func_U_003B7288();
extern s32 func_U_003B8840(void);
extern void func_U_003B8E10(void *);
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
extern void func_U_003B7288();
extern s32 func_U_003B8A18();
extern s32 func_U_003B8A20();
extern void func_U_003B6488();
extern void func_U_003B8C70();
extern s32 func_U_003B8840();
extern void func_U_003B8968();
extern void func_U_003B8E10();
extern void func_U_003B8A48();
extern void func_U_003B8A68();
extern void func_U_003B8A48();
extern void func_U_003B7288();
extern s32 func_U_003B8840(void);
extern void func_U_003B8E10(void *);
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
typedef int u128_3BA490 __attribute__((mode(TI)));
typedef struct {
    u128_3BA490 a;
    u128_3BA490 b;
    f32 f20, f24, f28;
    s32 x2C, x30, x34, x38, x3C, x40, x44, x48, x4C;
} P_3BA490;
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
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
typedef int Q_3BA9A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BA9A0;
typedef struct { f32 x, y; } V2_3BA9A0;
typedef struct { f32 v[3]; } V3_3BA9A0;
typedef struct { u8 pad[8]; u8 b8; } O_3BA9A0;
typedef int Q_3BAE98 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BAE98;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[8]; s16 f40; } T_3BB398;
extern void func_U_003B7288();
extern void func_U_003B8C70();
extern void func_U_003B6488();
extern void func_U_003B8968();
extern void func_U_003B8A48();
extern s32 func_U_003B8A18();
extern s32 func_U_003B8A20();
u8 func_U_003B8700(void);
extern void func_U_003B8A48();
extern void func_U_003B7288();
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern s32 func_11BB58(void *, s32, s32);
extern s32 func_U_003B8A20();
extern void func_U_003B6488();
extern s32 func_11BB58(void *, s32, s32);
typedef struct { s32 f0; u8 p4[0x4C]; u8 f50; u8 f51; } S_BB7E8;
typedef struct { s32 a; s32 b; } P_BB7E8;
typedef struct { u8 p[0x68]; s32 f68; } T_BB7E8;
extern void func_U_003BB9F0();
typedef struct { u8 p0[0x24]; struct { u8 p[0x24]; f32 f24; } *w24; u8 p28[4]; f32 f2C; u8 p30[0x32]; u8 b62; u8 p63[0x32]; u8 b95; u8 p96[0x14]; s16 hAA; } Q_3BBA50;
typedef struct { u8 p0[0x34]; s32 w34; u8 p38[8]; s16 h40; u8 p42[0x12]; Q_3BBA50 *w54; } G_3BBA50;
/* localdecomp:start func_U_003BBC48 */
extern s32 D_U_001D9060_003C1158;
extern u8 D_U_002CE088_003C1158[];
extern u8 D_U_00225780_003C1158[];
extern void func_U_003B7288();
extern s32 func_U_003B8A18();
extern s32 func_U_003B8A20();
extern void func_U_003B6488();
extern void func_U_003B8C70();
extern s32 func_U_003B8840();
extern void func_U_003B8968();
extern void func_U_003B8E10();
extern void func_U_003B8A48();
extern void func_U_003BB790();
extern void func_U_003B8A68();
extern void func_U_003BB9F0();
__asm__(".extern D_U_001D9060_003C1158, 4");
void func_U_003BBC48(s32 a0) {
    s32 v4;
    s32 v5;
    u8 *g;
    if (D_U_002CE088_003C1158[0x50] != 0) {
        func_U_003B7288();
        if (func_U_003B8A18() == 1) {
            func_U_003B8C70();
        }
        if (func_U_003B8A18() > 0 && func_U_003B8A20() != 0) {
            func_U_003B6488();
        }
        if (D_U_002CE088_003C1158[0x51] == 0) {
            if (func_U_003B8A18() > 0 && a0 != 0) {
                v4 = D_U_001D9060_003C1158;
                D_U_002CE088_003C1158[0x51] = 1;
            } else {
                v4 = func_U_003B8840();
            }
            func_U_003B8968(v4);
            func_U_003B8E10(func_U_003BB9F0);
            func_U_003B8A48();
            func_U_003BB790();
        }
    }
    g = D_U_00225780_003C1158;
    v5 = *(s16 *)(g + 0x40);
    if (D_U_002CE088_003C1158[0x51] != 0) {
        if (*(s32 *)(g + 0x34) >= 0x1F) v5 += 0x1E;
    }
    func_U_003B8A68(*(s32 *)(g + 0x34), v5, 7, 7);
}
/* localdecomp:end func_U_003BBC48 */
