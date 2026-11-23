#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_004D0E90);

/* localdecomp:start func_L01_004D1700 */
extern s32 D_L01_002D15F0[];
typedef struct { u8 pad[0xB0]; f32 fB0; } S_004D1700;
typedef struct I_004D1700 { u8 pad0[0x24]; void (**vptr)(struct I_004D1700 *); u8 pad28[8]; } I_004D1700;
extern S_004D1700 D_L01_001E7580;
typedef struct { s32 x0; u8 pad4[0x56]; u8 x5A; } S_142660_004D1700;
typedef struct { u8 pad0[0xB7]; u8 xB7; } S_143950_004D1700;
extern S_142660_004D1700 D_00142660;
extern S_143950_004D1700 D_00143950;
extern char D_L01_001DB738[];
extern char D_L01_001DB740[];
extern char D_L01_001DB748[];
__asm__(".extern D_L01_001DB71C, 4");
__asm__(".extern D_L01_001DB720, 4");
__asm__(".extern D_L01_001DB724, 4");
__asm__(".extern D_L01_001DB728, 4");
__asm__(".extern D_L01_001DB72C, 4");
__asm__(".extern D_L01_001DB730, 4");
__asm__(".extern D_L01_001DB348, 4");
__asm__(".extern D_L01_001DB34C, 4");
__asm__(".extern D_L01_001DB350, 4");
extern u32 D_L01_001DB71C;
extern u32 D_L01_001DB720;
extern u32 D_L01_001DB724;
extern u32 D_L01_001DB728;
extern u32 D_L01_001DB72C;
extern u32 D_L01_001DB730;
extern s32 D_L01_001DB348;
extern s32 D_L01_001DB34C;
extern u32 D_L01_001DB350;
extern u32 *func_L01_004CC758(u8 *);
extern f32 *func_L01_004CC750(u8 *);
extern f32 *func_L01_004CC748(u8 *);
extern void func_003AB398(u8 *);
extern void func_L01_004CB540_004D1700(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003AB890(u8 *);
extern void func_003AAF00(u8 *, s32);
extern void func_003ABAC8(u8 *);
extern long func_00389598(s32);
extern void func_003873C0(void);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_L01_00412BC0(unsigned long, char *, s32, f32, f32, f32, long, s32);
extern s32 func_L01_004129E0(s32, s32, s32, char *, s32);

void func_L01_004D1700(u8 *a0) {
    char buf[32];
    char buf2[16];
    f32 scale;
    u8 *p;
    u8 *q;
    f32 *s;
    s32 n;
    s16 mult;
    s32 digits;
    s32 alt;
    u32 col;
    u32 c2;
    u32 sh = 0;
    s16 j;
    s32 k;
    f32 x, y, f, fx, fy;
    s32 dx, dy;
    char *fmt;
    long tex;

    if (D_L01_002D15F0[0] == 0) {
        scale = D_L01_001E7580.fB0;
        if (scale != 0.62f) {
            D_L01_001E7580.fB0 = 0.62f;
            func_003873C0();
        }
        *func_L01_004CC758(a0 + 0x244) = D_L01_001DB71C;
        *func_L01_004CC758(a0 + 0x4D8) = D_L01_001DB720;
        *func_L01_004CC758(a0 + 0x280) = D_L01_001DB724;
        *func_L01_004CC758(a0 + 0x514) = D_L01_001DB728;
        *func_L01_004CC758(a0 + 0x49C) = D_L01_001DB72C;
        *func_L01_004CC758(a0 + 0x550) = D_L01_001DB71C;
        *func_L01_004CC758(a0 + 0x58C) = D_L01_001DB728;
        func_L01_004CB540_004D1700(1);
        func_003A9440(0x47, 0x513F1);
        func_003AB398(a0 + 0x244);
        func_003AB398(a0 + 0x4D8);
        func_003AB398(a0 + 0x280);
        func_003AB398(a0 + 0x514);
        func_003AB398(a0 + 0x49C);
        func_003AB398(a0 + 0x550);
        func_003AB398(a0 + 0x58C);
        { f32 *t = func_L01_004CC750(a0 + 0x244); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x4D8); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x280); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x514); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x49C); *t = -*t; }
        func_003AB398(a0 + 0x244);
        func_003AB398(a0 + 0x4D8);
        func_003AB398(a0 + 0x280);
        func_003AB398(a0 + 0x514);
        func_003AB398(a0 + 0x49C);
        { f32 *t = func_L01_004CC750(a0 + 0x244); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x4D8); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x280); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x514); *t = -*t; }
        { f32 *t = func_L01_004CC750(a0 + 0x49C); *t = -*t; }
        func_003AB398(a0 + 0x628);
        {
            s32 i;
            for (i = 0; i < 8; i++) {
                u32 *c = func_L01_004CC758((u8 *)&((I_004D1700 *)(a0 + 0x664))[i]);
                *c = (*c & 0xFF000000) | (D_L01_001DB730 & 0xFFFFFF);
            }
        }
        for (j = 0; j < 8; j++) {
        }
        {
            u32 *c = func_L01_004CC758(a0 + 0x5C8);
            *c = (*c & 0xFF000000) | 0x6EC8FF;
        }
        {
            u32 *c = func_L01_004CC758(a0 + 0x5F8);
            *c = (*c & 0xFF000000) | 0x6EC8FF;
        }
        for (k = 0; k < 8; k++) {
            ((I_004D1700 *)(a0 + 0x664))[k].vptr[2](&((I_004D1700 *)(a0 + 0x664))[k]);
        }
        func_003AB890(a0 + 0x5C8);
        func_003AB890(a0 + 0x5F8);
        *func_L01_004CC758(a0 + 0x628) = 0x706EC8FF;
        q = a0 + 0xA90;
        if (q[0x28] == 0) {
            func_003AAF00(a0 + 0x628, 0);
        }
        if (scale != 0.62f) {
            D_L01_001E7580.fB0 = scale;
            func_003873C0();
        }
    }
    func_L01_004CB540_004D1700(0);
    func_003AB398(a0 + 0x140);
    func_003AB398(a0 + 0x17C);
    func_003ABAC8(a0 + 0x1D0);
    func_003AB890(a0 + 0x210);
    x = func_L01_004CC748(a0 + 0x1D0)[0];
    y = func_L01_004CC748(a0 + 0x1D0)[1];
    x += 32.0f;
    y += -10.0f;
    col = *func_L01_004CC758(a0 + 0x1D0);
    digits = 1;
    for (n = D_00142660.x0; n >= 10; n /= 10) {
        digits++;
    }
    alt = D_00143950.xB7 != 3 && D_00143950.xB7 != 5;
    if (alt) {
        fmt = D_L01_001DB738;
    } else {
        fmt = D_L01_001DB740;
    }
    func_0011B2E8(buf, fmt);
    dy = alt ? 0x15 : 0xA;
    dx = alt ? -0x22 : -0x1D;
    for (f = 3.0f; f < digits; f += 3.0f) {
        fx = x + dx - (s32)(f * 11.6f);
        fy = y + dy;
        p = a0 + 0x1D0;
        s = func_L01_004CC750(p);
        tex = *(long *)(p + 0x30);
        func_L01_00412BC0(col, buf, -1, fx, fy, *s, func_00389598(tex), *(s32 *)(p + 0x28));
    }
    mult = D_00142660.x5A + 1;
    if (mult >= 2) {
        func_0011B2E8(buf2, D_L01_001DB748, mult);
        c2 = (D_L01_001DB350 & 0xFFFFFF) | (col & 0xFF000000);
        sh |= col & 0xFF000000;
        func_L01_004129E0(D_L01_001DB348, D_L01_001DB34C + 2, sh, buf2, -1);
        func_L01_004129E0(D_L01_001DB348 + 2, D_L01_001DB34C, sh, buf2, -1);
        func_L01_004129E0(D_L01_001DB348 + 2, D_L01_001DB34C + 2, sh, buf2, -1);
        func_L01_004129E0(D_L01_001DB348, D_L01_001DB34C, c2, buf2, -1);
    }
}
/* localdecomp:end func_L01_004D1700 */

LINKER_REMNANT("asm/levels", func_L01_004D1DC0);
