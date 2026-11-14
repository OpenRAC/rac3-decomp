#include "common.h"

typedef struct {
    u8 pad0[0x80];
    s32 f80;
} Sub_003BEF28;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x47];
    Sub_003BEF28 *f68;
} Obj_003BEF28;
typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x6C - 0x28];
    s32 f6C;
    u8 pad70[0x94 - 0x70];
    s32 f94;
} Glob_003BEF28;

typedef struct { u8 pad0[0x70]; s16 f70; u8 pad72[4]; s16 f76; u8 pad78[0x20]; s16 f98; u8 pad9A[4]; s16 f9E; } S_L34_003BEFF8_g;

/* localdecomp:start func_L34_003BEF28 */
extern Glob_003BEF28 D_001CCFD0[];
extern void func_L34_003BEFC0(Obj_003BEF28 *);
extern void func_L01_004450F0(Obj_003BEF28 *, s32, s32);
extern void func_L34_003BEFF8(Obj_003BEF28 *);
extern void func_L34_003BF080(Obj_003BEF28 *);

void func_L34_003BEF28(Obj_003BEF28 *p) {
    Sub_003BEF28 *q = p->f68;

    if (p->f20 == 0) {
        func_L34_003BEFC0(p);
        func_L01_004450F0(p, 1, -1);
    }
    if (D_001CCFD0[0].f6C == 0 && D_001CCFD0[0].f24 == -1 && D_001CCFD0[0].f94 == 0 && q->f80 == 0) {
        func_L34_003BF080(p);
    }
    func_L34_003BEFF8(p);
}
/* localdecomp:end func_L34_003BEF28 */

/* localdecomp:start func_L34_003BEFC0 */
void func_L34_003BEFC0(Obj_003BEF28 *p) {
    u8 *q = (u8 *)p->f68;

    *(u8 *)((u8 *)p + 0x30) = 0xFF;
    *(s32 *)(q + 0x60) = 0;
    *(s32 *)(q + 0x64) = 0;
    *(s32 *)(q + 0x68) = 0;
    *(s32 *)(q + 0x6C) = 0;
    *(s32 *)(q + 0x70) = 0;
    *(s32 *)(q + 0x74) = 0;
    *(s32 *)(q + 0x78) = 0;
    *(s32 *)(q + 0x7C) = 0;
    *(s32 *)(q + 0x80) = 0;
}
/* localdecomp:end func_L34_003BEFC0 */

/* localdecomp:start func_L34_003BEFF8 */
extern void func_003A1798(void);
extern S_L34_003BEFF8_g D_001CCFD0_003BEFF8;

void func_L34_003BEFF8(Obj_003BEF28 *a) {
    Sub_003BEF28 *s = a->f68;

    if (D_001CCFD0_003BEFF8.f70 >= 7000) {
        if (s->f80 != 0) {
            s->f80 = 0;
        }
    }
    if (D_001CCFD0_003BEFF8.f76 == 0 && D_001CCFD0_003BEFF8.f9E == 3 && D_001CCFD0_003BEFF8.f98 < 7000) {
        func_003A1798();
        s->f80 = 0;
    }
}
/* localdecomp:end func_L34_003BEFF8 */

/* localdecomp:start func_L34_003BF080 */
typedef struct {
    s32 snd[13];
    u8 pad34[0x40 - 0x34];
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
} S_003BF080;

typedef struct {
    u8 pad0[0x1B38];
    union {
        u32 w;
        u8 b;
    } f1B38;
    u8 pad1B3C[0x2850 - 0x1B3C];
    s32 f2850;
} G_003BF080;

extern G_003BF080 D_001A4BE0;
extern u8 D_001A4C60[];
extern u8 *D_001DF79C;
extern f32 D_L34_001DEE10;
extern s32 func_00382380(void *, s32, s32);
extern void func_003A2B68(s32, s32);
extern s32 func_L30_0034CA78(void);

void func_L34_003BF080(Obj_003BEF28 *p) {
    S_003BF080 *q = (S_003BF080 *)p->f68;
    f32 f;

    if (q->f60 == 0 && q->f50 != -1 && func_00382380(D_001A4C60, q->f50, 0)) {
        q->f60 = 1;
        func_003A2B68((q->snd[0] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if ((D_001A4BE0.f1B38.b ^ 1) & 1) {
        D_001A4BE0.f1B38.w |= 1;
        func_003A2B68((q->snd[1] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f78 == 0 && q->f58 != -1 && D_001DF79C[(q->f58 << 8) + 0x20] == 2) {
        q->f78 = 1;
        func_003A2B68((q->snd[2] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f78 == 1) {
        q->f78 = 2;
        func_003A2B68((q->snd[3] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f78 == 2 && func_00382380(D_001A4C60, q->f5C, 0)) {
        q->f78++;
        func_003A2B68((q->snd[3] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f64 == 0 && q->f4C != -1 && func_00382380(D_001A4C60, q->f4C, 0)) {
        q->f64 = 1;
        func_003A2B68((q->snd[5] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f7C == 0 && q->f48 != -1 && func_00382380(D_001A4C60, q->f48, 0)) {
        q->f7C++;
        func_003A2B68((q->snd[6] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f7C == 1) {
        q->f7C = 2;
        func_003A2B68((q->snd[7] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f7C == 2) {
        q->f7C = 3;
        func_003A2B68((q->snd[8] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f68 == 0 && q->f40 != -1 && func_00382380(D_001A4C60, q->f40, 0)) {
        q->f68 = 1;
        func_003A2B68((q->snd[9] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f6C == 0 && q->f44 != -1 && func_00382380(D_001A4C60, q->f44, 0)) {
        q->f6C = 1;
        func_003A2B68((q->snd[10] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    f = (f32)D_001A4BE0.f2850 / ((f32)func_L30_0034CA78() * 20.0f + 100.0f);
    if (q->f70 == 0 && f < D_L34_001DEE10) {
        q->f70 = 1;
        func_003A2B68((q->snd[11] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
        return;
    }
    if (q->f74 == 0 && q->f54 != -1 && func_00382380(D_001A4C60, q->f54, 0)) {
        q->f74 = 1;
        func_003A2B68((q->snd[12] & 0x3FFF) + 2000, 0);
        q->f80 = 1;
    }
}
/* localdecomp:end func_L34_003BF080 */
