#include "common.h"

/* NTSC-U version of func_003C0118 (boot_elf): 0.02 -> 0.0166667 */

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
typedef struct { u8 pad[0x34]; u16 h34; u8 pad2[0x2E]; void *x64; u8 pad3[0x42]; s16 hAA; } S_3BA368;
extern void func_U_003C0010(S_3BA368 *p);
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
/* localdecomp:start func_U_003C0010 */
__asm__(".extern D_U_001D8E94, 4");
__asm__(".extern D_U_001D8E98, 4");
__asm__(".extern D_U_001D8E9C, 4");
__asm__(".extern D_U_001D8EA0, 4");
extern u8 *D_U_001DA39C_003C0118[2];
extern u8 D_U_003800F0[];
typedef struct { u8 p[0x1C]; f32 f1C; } S_3BA850;
extern u8 D_U_001DA398[8];
extern f32 D_U_001D8E94;
extern s32 D_U_001D8E98;
extern f32 D_U_001D8E9C;
extern f32 D_U_001D8EA0;
extern u8 *func_U_003BFD78(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_U_003C0010(S_3BA368 *a) {
    s32 i;
    u8 **p = D_U_001DA39C_003C0118;
    u8 *e = D_U_003800F0;
    u8 *r;
    for (i = 5; i >= 0; i--) {
        if (*p == 0) {
            r = func_U_003BFD78(e, (s32)a, D_U_001D8E98, 0, 0, -1, 0, -1, 0, 0, D_U_001D8E9C * 210000.0f, D_U_001D8EA0, 1.0f);
            *p = r;
            if (r != 0) r[3] = 0x44;
        }
        e += 0x10;
        p++;
    }
    { S_3BA850 *q = (S_3BA850 *)D_U_001DA398; q->f1C = D_U_001D8E94 * 0.0166666675f; }
}
/* localdecomp:end func_U_003C0010 */
