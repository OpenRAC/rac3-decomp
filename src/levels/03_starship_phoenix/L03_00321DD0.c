#include "common.h"

typedef struct Obj_00322548 {
    u8 pad0[0x30];
    u8 f30;
    u8 pad31[0x33];
    void (*f64)(struct Obj_00322548 *);
    u8 pad68[0x98];
} Obj_00322548;

typedef struct { s32 f0; s32 f4; u8 pad8[4]; s32 fC; u8 pad10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; u8 pad44[0x26]; s16 f6A; u8 f6C; } S_00321DD0;

/* localdecomp:start func_L03_00321DD0 */
extern s32 D_001A8114[];
extern s32 D_001A8318[];
extern s32 D_00142C10[];
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C;
extern u8 D_00142CA0[];
extern u8 D_001426E0[];
extern u8 D_001A4C60[];
extern void func_L03_003220D8(void *);
extern void func_L03_00322160(void *);
extern void func_L03_00322548(u8 *, s32);
extern void func_L01_004BAF50(void);
extern s32 func_L01_004BA800(void);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_00456230(u8 *, s32);
extern void func_0039EF28(void);
extern s32 func_0038CB00(void *);
extern s32 func_00382380(void *, s32, s32);
extern Obj_00322548 *D_L03_001DF99C;

void func_L03_00321DD0(u8 *a) {
    S_00321DD0 *s = *(S_00321DD0 **)(a + 0x68);
    s32 v;

    func_L03_003220D8(a);
    func_L03_00322160(a);
    switch (a[0x20]) {
    case 0:
        func_L01_004BAF50();
        if (D_00142CA0[0x22] != 0) {
            v = s->f40;
        } else if (D_001426E0[0x28] != 0) {
            v = s->f3C;
        } else if (D_001426E0[0x20] != 0) {
            v = s->f38;
        } else if (D_001426E0[0x3D] != 0) {
            v = s->f34;
        } else if (D_001426E0[0x74] != 0) {
            v = s->f30;
        } else if (D_00142CA0[0x1E] == 0) {
            goto L24;
        } else {
            if (D_001426E0[0xC] == 0) {
                D_001426E0[0xC] = 1;
                func_0039EF28();
                D_001426E0[0x16] = 1;
                func_0039EF28();
            }
            v = s->f28;
        }
        func_L03_00322548(a, v);
        break;
    L24:
        func_L03_00322548(a, s->f24);
        s->f6C = 0xFF;
        func_L01_004450F0(a, 1, -1);
        break;
    case 1:
        if (D_001426E0[8] != 0) {
            func_L01_004450F0(a, 2, -1);
            break;
        }
        if (func_L01_004BA800() == 0) {
            s32 m = D_001A8114[0];
            s32 bit = 1 << D_001D545C;
            if (!(m & bit)) {
                func_L01_0041A5B0(0xB9C, 0x3F);
            }
        }
        if (s->f6C == 0xFF) {
            if (func_00382380(D_001A4C60, s->fC, 0) != 0) {
                s->f6C = 0;
                s->f6A = 3000;
                func_L01_0041A5B0(0xA1C, 9);
            }
        } else if (func_0038CB00(&s->f6A) != 0) {
            s->f6A = 3000;
            if (func_00382380(D_001A4C60, s->f0, 0) != 0) {
                s->f6C = (s->f6C + 1) % 3;
                func_L01_0041A5B0(0xA1C + s->f6C, 9 + s->f6C);
            }
        }
        break;
    case 2:
        if (D_001426E0[9] != 0) {
            func_L01_004450F0(a, 4, -1);
        } else if (func_00382380(D_001A4C60, s->f4, 0) != 0) {
            D_001426E0[9] = 1;
            func_0039EF28();
            func_L01_00456230((u8 *)(D_L03_001DF99C + s->f2C), 1);
            func_L01_004450F0(a, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004BA800() == 0) {
            if ((D_00142C10[0] & 0x20000) != 0) {
                s32 m = D_001A8318[0];
                s32 bit = 1 << D_001D545C;
                if (!(m & bit)) {
                    func_L01_0041A5B0(0xCB8, 0x6A);
                }
                func_L01_004450F0(a, 4, -1);
            }
        }
        break;
    case 4:
    default:
        break;
    }
}
/* localdecomp:end func_L03_00321DD0 */

/* localdecomp:start func_L03_003220D8 */
typedef struct { u8 pad0[0x20]; s32 f20; u8 pad24[0x30]; s32 f54; s32 f58; s32 f5C; s32 f60; } S_003220D8;
extern Obj_00322548 *D_L03_001DF99C;
extern u8 D_001A4C60[];
extern s16 D_001CD018[];
extern s32 func_L03_0032F660(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_0045F1E8(s32, s32);
void func_L03_003220D8(void *a) {
    S_003220D8 *s = *(S_003220D8 **)((u8 *)a + 0x68);
    s32 v = s->f54;
    if (func_L03_0032F660(D_L03_001DF99C + s->f20) != 0) {
        v = s->f58;
    } else if (func_00382380(D_001A4C60, s->f60, 0) != 0) {
        v = s->f5C;
    }
    if (D_001CD018[0] != v) {
        func_L01_0045F1E8(v, -1);
    }
}
/* localdecomp:end func_L03_003220D8 */

/* localdecomp:start func_L03_00322160 */
typedef struct S_00322160 {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 pad20[0x24];
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    u8 pad54[0x10];
    s32 f64;
    u16 f68;
} S_00322160;

typedef struct A_00322160 {
    u8 pad0[0x68];
    S_00322160 *f68;
} A_00322160;

extern s32 D_00142C10[];
__asm__(".extern D_00142C10, 16");
extern u8 D_001426E0[];
__asm__(".extern D_001426E0, 16");
extern s16 D_001426A0[];
__asm__(".extern D_001426A0, 16");
typedef struct G_00322160 {
    u8 pad0[0x30]; u16 f30; u8 pad32[0x16]; u16 f48; u8 pad4A[0xA]; u16 f54;
    u8 pad56[0xA]; u16 f60; u8 pad62[0x2E]; u16 f90; u8 pad92[0xA]; u16 f9C; u8 pad9E[0xA]; u16 fA8;
    u8 padAA[0x156]; u32 f200; u8 pad204[0x630]; u16 f834;
} G_00322160;
extern G_00322160 D_001A7E18;
extern u16 D_001A7D00[];
__asm__(".extern D_001A7D00, 16");
extern u8 D_001A4C60[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001D554F;
__asm__(".extern D_001D554F, 16");
extern u8 D_001D5550[3];
__asm__(".extern D_001D5550, 16");
extern u8 D_001D5588;
__asm__(".extern D_001D5588, 16");
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_0041BE28(s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern void func_0039EF28(void);

void func_L03_00322160(void *arg) {
    A_00322160 *a = arg;
    S_00322160 *p = a->f68;
    s32 i;
    u8 *q;

    if (D_00142C10[0] & 0x10000) {
        p->f68++;
        if ((s16)p->f68 >= 0x2EF) {
            if (!(D_001A7E18.f200 & (1 << D_001D545C)) && D_001A7D00[0] == 0) {
                func_L01_0041A5B0(0xB87, 0x2A);
            }
        }
        if (D_001A7E18.f90 == 0 && D_001D554F == 0) {
            if (func_00382380(D_001A4C60, p->f10, 0)) func_L01_0041A5B0(0xA1F, 0xC);
        }
        if (D_001A7E18.fA8 == 0) {
            if (func_00382380(D_001A4C60, p->f48, 0)) func_L01_0041A5B0(0xA21, 0xE);
        }
    }
    if (D_001A7E18.f834 == 0) {
        if (func_00382380(D_001A4C60, p->f44, 0)) func_L01_0041A5B0(0xEF5, 0xAF);
    }
    if (D_001A7E18.f9C == 0) {
        if (func_00382380(D_001A4C60, p->f8, 0)) func_L01_0041A5B0(0xA20, 0xD);
    }
    if (D_001A7E18.f54 == 0) {
        if (func_00382380(D_001A4C60, p->f14, 0)) func_L01_0041A5B0(0xA1A, 7);
    }
    if (D_001A7E18.f48 == 0) {
        if (func_00382380(D_001A4C60, p->f18, 0)) func_L01_0041A5B0(0xA19, 6);
    }
    if (D_001A7E18.f30 == 0) {
        if (func_00382380(D_001A4C60, p->f1C, 0)) func_L01_0041A5B0(0xA17, 4);
    }
    if (func_00382380(D_001A4C60, p->f50, 0)) {
        for (i = 0; i < 3; i++) {
            s32 u = (u32)i < 8;

            q = (u8 *)((s32)D_001D5550 + i);
            if (!u) {
                if (!*q) continue;
            } else {
                if (!(((D_001426E0[0x76] >> i) ^ 1) & 1)) continue;
                if (!*q) continue;
            }
            do {
                switch (i) {
                case 0:
                    break;
                case 1:
                    func_L01_0041A5B0(0x1602, 0x136);
                    break;
                case 2:
                    func_L01_0041A5B0(0x1603, 0x137);
                    break;
                }
            } while (0);
            if (u) D_001426E0[0x76] |= 1 << i;
            func_0039EF28();
        }
    }
    if ((D_001426E0[0x3E] & 8) && !(D_001426E0[0x75] & 8) && D_001426A0[0] < 3) {
        if ((&D_001D5588)[8]) {
            if (func_00382380(D_001A4C60, p->f4C, 0)) {
                D_001426E0[0x75] |= 8;
                func_0039EF28();
                func_L01_0041A5B0(0xC9A, 0x5D);
                func_L01_0041BE28(0x15FB, 0x132);
            }
        }
    }
    if (D_001426E0[9]) {
        if (D_001A7E18.f60 == 0) {
            if (func_00382380(D_001A4C60, p->f64, 0)) func_L01_0041A5B0(0xA1B, 8);
        }
    }
}
/* localdecomp:end func_L03_00322160 */

/* localdecomp:start func_L03_00322548 */
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);

extern Obj_00322548 *D_L03_001DF99C;

void func_L03_00322548(u8 *a, s32 b) {
    Obj_00322548 *p = D_L03_001DF99C + b;

    func_L01_00456230((u8 *)p, 1);
    p->f30 = 0xFF;
    p->f64(p);
    func_L01_004450F0(a, 4, -1);
}
/* localdecomp:end func_L03_00322548 */
