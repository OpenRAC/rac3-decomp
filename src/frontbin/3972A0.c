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
extern void func_00397980(s32, s32, s32, s32, s32, s32);
extern void func_00397B10();
typedef struct { s16 a; s16 b; } P_392108;


typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_392A40;
extern P_392108 *D_001D9EA8_003972A0;
extern E_392A40 *D_001D9EAC_003972A0;
typedef int Q_392A40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392A40;
extern u32 *D_001DA050;
extern s32 func_00396A38_003972A0();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern Q_392A40 D_001D76F0_003972A0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003972A0);

typedef int Q_392DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392DD8;
extern u32 *D_001DA050;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern s32 D_001D9E94;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
/* localdecomp:start func_00397638 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } V4_00397638;
extern u32 *D_001DA050_00397638;
extern s32 D_001D4BD0_00397638;
extern s32 D_001D4BD4_00397638;
extern s32 D_001D9E94_00397638;
extern f32 func_0038D098_00397638(f32);
extern f32 func_0038D0B0_00397638(f32);
void func_00397638(f32 x, f32 y, f32 w, f32 h, f32 ang, s32 tw, s32 th, s32 tex) {
    V4_00397638 a, b, c, p0, p1, p2, p3;
    unsigned long *q;
    c.x = x;
    c.y = y;
    a.x = h * func_0038D0B0_00397638(ang);
    a.y = h * func_0038D098_00397638(ang);
    b.x = -w * func_0038D098_00397638(ang);
    b.y = w * func_0038D0B0_00397638(ang);
    vec_add_ba(&p0, &c, &a);
    vec_sub_ba(&p0, &p0, &b);
    vec_add_ba(&p1, &c, &a);
    vec_add_ba(&p1, &p1, &b);
    vec_sub_ab(&p2, &c, &a);
    vec_sub_ba(&p2, &p2, &b);
    vec_sub_ab(&p3, &c, &a);
    vec_add_ab(&p3, &p3, &b);
    D_001DA050_00397638[0] = 0x10000007;
    D_001DA050_00397638[1] = 0;
    D_001DA050_00397638[2] = 0;
    D_001DA050_00397638[3] = 0x50000007;
    q = (unsigned long *)(D_001DA050_00397638 + 4);
    D_001DA050_00397638 = (u32 *)q;
    q[0] = 0xB400000000008001UL;
    q[1] = 0x53535353106UL;
    q[2] = tex;
    q[3] = 0x154;
    q[4] = 0x807F7F7F;
    q[5] = tw << 4;
    q[6] = (unsigned long)(((s32)p0.x + D_001D4BD0_00397638 - 8) | ((long)((s32)p0.y + D_001D4BD4_00397638 - 8) << 16)) | ((long)D_001D9E94_00397638 << 32);
    q[7] = (th << 20) + (tw << 4);
    q[8] = (unsigned long)(((s32)p1.x + D_001D4BD0_00397638 - 8) | ((long)((s32)p1.y + D_001D4BD4_00397638 - 8) << 16)) | ((long)D_001D9E94_00397638 << 32);
    q[9] = 0;
    q[10] = (unsigned long)(((s32)p2.x + D_001D4BD0_00397638 - 8) | ((long)((s32)p2.y + D_001D4BD4_00397638 - 8) << 16)) | ((long)D_001D9E94_00397638 << 32);
    q[11] = th << 20;
    q[12] = (unsigned long)(((s32)p3.x + D_001D4BD0_00397638 - 8) | ((long)((s32)p3.y + D_001D4BD4_00397638 - 8) << 16)) | ((long)D_001D9E94_00397638 << 32);
    q[13] = 0;
    D_001DA050_00397638 += 0x1C;
}
/* localdecomp:end func_00397638 */

/* PAL candidate for func_00397980 (US draft: rac3-uya-decomp func_00393120, commit 13cf5c5).
   The US matched it with `@ps2as`; here the file's own flags (-mno-split-addresses, default
   assembler) must do it, so the global is reached the way retail reaches it: the reads of the
   pointer at 0x001DA050 go through an unsized alias (never small data, so `lui`/`lw`), while the
   writes of the pointer itself stay on the sized declaration ($gp). */

/* localdecomp:start func_00397980 */
extern u32 *D_001DA050_00397980;
extern u32 D_001DA050_00397980_lui[];
extern void func_12C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, s32);
void func_00397980(s32 a0, s32 a1, s32 a2, s32 d, s32 e, s32 f) {
    u32 tmp[24];
    u32 *buf;
    s32 c, m;
    c = (1 << d) >> 6;
    m = 1 << (d + e - 4);
    if (c <= 0) c = 1;
    if (f == 0) {
        ((u32 *)D_001DA050_00397980_lui[0])[0] = 0x10000006;
        ((u32 *)D_001DA050_00397980_lui[0])[1] = 0;
        ((u32 *)D_001DA050_00397980_lui[0])[2] = 0;
        ((u32 *)D_001DA050_00397980_lui[0])[3] = 0x50000006;
        buf = (u32 *)D_001DA050_00397980_lui[0] + 4;
        D_001DA050_00397980 = (u32 *)((u8 *)D_001DA050_00397980_lui[0] + 0x70);
    } else {
        buf = tmp;
    }
    func_12C9A0(buf, a1, c, a2, 0, 0, 1 << d, 1 << e);
    if (f == 0) {
        D_001DA050_00397980[0] = m | 0x30000000;
        ((u32 *)D_001DA050_00397980_lui[0])[1] = a0;
        ((u32 *)D_001DA050_00397980_lui[0])[2] = 0;
        ((u32 *)D_001DA050_00397980_lui[0])[3] = m | 0x50000000;
        D_001DA050_00397980 = (u32 *)D_001DA050_00397980_lui[0] + 4;
    } else {
        func_11F0A0(0);
        func_12CCC8(buf, a0);
    }
}
/* localdecomp:end func_00397980 */

LINKER_REMNANT("asm/remnants", func_00397AF0);

typedef struct {
    u8 pad0[8]; s32 f8; s32 *fC; u8 pad10[0x5C]; s32 f6C; u8 b[2]; u8 pad72[2]; s32 f74; u8 pad78[4]; s32 f7C;
} S_3932B0;
/* US draft of func_00397B10 (rac3-uya-decomp func_003932B0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00397B10 */
typedef struct {
    u8 pad0[8]; s32 f8; s32 *fC; u8 pad10[0x5C]; s32 f6C; u8 b[2]; u8 pad72[2]; s32 f74; u8 pad78[4]; s32 f7C;
} S_3932B0_00397B10;
void func_00397B10(S_3932B0_00397B10 *p) {
    u8 *b = p->b;
    s32 t = *p->fC;
    s32 a = p->f8;
    p->f74 = t;
    if (a < t) {
        p->f74 = a;
    } else if (t < 0) {
        p->f74 = 0;
    }
    if (p->f7C >= 4) {
        p->f7C = 4;
        if (b[0] < 8) {
            b[0]++;
        } else if (b[1] < 8) {
            b[1]++;
        }
    } else {
        p->f6C = 1;
        if (b[1] != 0) {
            b[1]--;
        } else if (b[0] != 0) {
            b[0]--;
        } else {
            p->f6C = -6;
        }
    }
}
/* localdecomp:end func_00397B10 */
