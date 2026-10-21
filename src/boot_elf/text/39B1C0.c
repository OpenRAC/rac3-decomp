#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_0039B1C0(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 39A9A8.c's earlier functions (tools/port_from_us.py) */
extern void func_0038CF58(void *, s32, s32);
extern u8 D_0016C690[];
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_0039AB28;
typedef struct { s32 f0; s32 f4; } S_00395958;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_003959A8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_003959A8 el[0x30]; } S_003959A8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } L_003959A8;
typedef struct { s32 f0; s32 f4; u8 *f8; } A_003959A8;
extern S_003959A8 D_160C40_0039AB78;
extern void func_0039AB28();
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_003A2A30();
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_0039AC98;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_0039AC98;
extern s32 D_001D6000_0039AC98;
extern u8 D_001D6004_0039AC98;
extern u8 D_001D6008_0039AC98;
extern s32 func_003A2A30();
extern void func_0039AB28();
extern void func_0039AB78();
typedef struct { s32 k; u8 pad[0x10]; } E_395BC0;
typedef struct { u8 pad[0x4590]; E_395BC0 e[0x30]; } S_395BC0;
typedef struct { u8 d[0xC800]; } B_395BC0;
typedef struct { u8 pad[0x34]; s32 f34[3]; B_395BC0 blk[1]; } S_395BC0b;
extern S_395BC0 D_160C40_0039AD90;
extern S_395BC0b D_16C690_0039AD90;
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[0xDC]; } E_395C48;
typedef struct { s32 id; s32 pad[4]; } F_395C48;
typedef struct { u8 pad[0x4590]; F_395C48 e[0x30]; } S_395C48;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395C48;
typedef struct { u8 pad[0x25F8]; s32 f25F8; u8 pad2[0x18]; s32 f2614; } A_395C48;
extern A_395C48 D_1A4BE0;
extern u8 D_001425C0[];
extern s32 D_00142674[];
extern s16 D_001CCFD4[];
extern E_395C48 D_001DAA40[];
extern S_395C48 D_160C40_0039AE18;
extern T_395C48 D_16C690_0039AE18;
extern s32 func_0039AFE8(s32);
typedef struct { s32 id; s32 pad[4]; } E_395E18;
typedef struct { u8 pad[0x4590]; E_395E18 e[0x30]; } S_395E18;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395E18;
extern S_395E18 D_160C40[];
extern T_395E18 D_16C690[];
typedef struct { u8 *data; u8 *clut; u8 pad8[0xC]; s32 f14; u8 pad18[0x34]; s32 tw; s32 th; u8 pad54[4]; } T_395EB8;
typedef struct { u8 *data; s16 f4; s16 f6; u8 *clut; u8 tw; u8 th; s16 fE; } E_395EB8;
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern E_395EB8 D_00225C00[];

/* localdecomp:start func_0039B1C0 */
__asm__(".extern D_001D4CE8_g_00395FF0, 4");
__asm__(".extern D_001D9FA4_g_00395FF0, 4");
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x10]; s32 f24; u8 p28[0x144]; s32 f16C; } S_395FF0;
extern S_395FF0 D_00142430_0039B1C0[];
extern u8 D_001D9FA8_0039B1C0;
extern s32 D_001D4CE8_g_00395FF0;
extern s32 D_001D4CE8_0039B1C0;
extern volatile s32 D_001D4CEC_0039B1C0;
extern s32 D_001D9FA4_g_00395FF0;
extern s32 D_001D9FA4;
extern void (*D_003322F8[])(void);
void func_0039B1C0(void) {
    S_395FF0 *s = D_00142430_0039B1C0;
    s32 old;
    s32 v;
    if (s->f16C != 0 || (s->f8 == 2 && s->f10 != 0) || s->f24 > 0) {
        D_001D9FA8_0039B1C0 = 1;
    }
    old = D_001D4CE8_g_00395FF0;
    v = D_001D4CEC_0039B1C0;
    if (v & 0x80) {
        D_001D4CE8_0039B1C0 = 0x18;
        D_001D4CEC_0039B1C0 = (v & -129) | 0x40;
        v = D_001D4CEC_0039B1C0;
    }
    if (v & 0x100) {
        D_001D4CE8_0039B1C0 = 0x16;
        D_001D4CEC_0039B1C0 = (v & -257) | 0x40;
    }
    D_003322F8[D_001D4CE8_0039B1C0]();
    D_001D9FA4_g_00395FF0 = D_001D9FA4 + 1;
    if (D_001D4CE8_0039B1C0 != old) {
        D_001D9FA4 = 0;
    }
}
/* localdecomp:end func_0039B1C0 */

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad1[0x150];
    s32 f164;
    s32 f168;
    u8 pad2[0x10];
    s32 f17c;
} S_142430;
extern S_142430 D_00142430;

extern s32 D_001D4CE8[];

/* localdecomp:start func_0039B2D0 */
typedef struct { 
    u8 pad[0x10]; 
    s32 f10; 
    u8 pad2[0x150]; 
    s32 f164; 
    s32 f168; 
    u8 pad3[0x10]; 
    s32 f17C; 
} S_142430x;

extern S_142430x D_142430;
extern s32 D_001D4CE8_g;

void func_0039B2D0(void) {
    S_142430x *p = &D_142430;
    D_001D4CE8_g = 4;
    p->f17C = 0;
    p->f10 = 0;
}
/* localdecomp:end func_0039B2D0 */

/* localdecomp:start func_0039B2F0 */
typedef struct { u8 p0[8]; s32 f8; u8 pC[4]; s32 f10; u8 p14[0x168]; s32 f17C; } S_142430_00396120;
__asm__(".extern D_001D4CE8_00396122, 4");
__asm__(".extern D_001D4CEC_00396122, 4");
extern S_142430_00396120 D_142430_0039B2F0;
extern s32 D_001D4CE8_00396122;
extern s32 D_001D4CEC_00396122;
extern s32 D_001D4CE8_0039B2F0;
extern s32 D_001D4CEC_0039B2F0;
void func_0039B2F0(void) {
    if (D_142430_0039B2F0.f17C == 0 && D_142430_0039B2F0.f8 != 2) {
        D_001D4CE8_00396122 = 4;
        return;
    }
    if (D_142430_0039B2F0.f17C != 0 && D_142430_0039B2F0.f8 != 2) {
        D_142430_0039B2F0.f17C = 0;
        D_001D4CE8_0039B2F0 = 3;
        D_001D4CEC_00396122 = D_001D4CEC_00396122 | 1;
        return;
    }
    if (D_001D4CEC_0039B2F0 & 4) {
        D_001D4CE8_00396122 = 0x1E;
        return;
    }
    if (D_001D4CEC_0039B2F0 & 2) {
        D_001D4CE8_00396122 = 0x1D;
        return;
    }
    if (D_142430_0039B2F0.f17C == 0 || (D_142430_0039B2F0.f8 == 2 && D_142430_0039B2F0.f10 != 0)) {
        D_001D4CE8_00396122 = 5;
        return;
    }
    if (D_001D4CEC_0039B2F0 & 0x80) {
        D_001D4CE8_0039B2F0 = 0x18;
        D_001D4CEC_00396122 = (D_001D4CEC_0039B2F0 ^ 0x80) | 0x40;
        return;
    }
    if (D_001D4CEC_0039B2F0 & 0x100) {
        D_001D4CE8_0039B2F0 = 0x16;
        D_001D4CEC_00396122 = (D_001D4CEC_0039B2F0 ^ 0x100) | 0x40;
        return;
    }
    if (D_001D4CEC_0039B2F0 & 0x200) {
        D_001D4CEC_0039B2F0 = D_001D4CEC_0039B2F0 ^ 0x200;
        D_001D4CE8_0039B2F0 = 0x1C;
    }
}
/* localdecomp:end func_0039B2F0 */

/* localdecomp:start func_0039B418 */
/* Ps2EeAs only uses $gp for this if it knows it is small before the use. */
__asm__(".extern D_001D6300_0039B418, 4");
extern s32 D_001D4CE8_0039B418;
extern s32 (*D_001D6300_0039B418)();
typedef struct { u8 pad0[0x16C]; s32 f16C; u8 pad170[0xC]; s32 f17C; } S_00142430_00396248_00396248;
extern S_00142430_00396248_00396248 D_00142430_0039B418[];

void func_0039B418(void) {
    if (D_001D6300_0039B418 != 0) {
        D_001D6300_0039B418();
        D_001D6300_0039B418 = 0;
    }
    if (D_00142430_0039B418->f16C == 0) {
        D_00142430_0039B418->f17C = 1;
    }
    D_001D4CE8_0039B418 = 1;
}
/* localdecomp:end func_0039B418 */

extern u8 D_001D4CEC_0039B468;
extern s32 D_001D4CE8_0039B468;
/* localdecomp:start func_0039B468 */
void func_0039B468(void) {
    if ((D_001D4CEC_0039B468 ^ 1) & 1) {
        D_001D4CE8_0039B468 = 4;
    }
}
/* localdecomp:end func_0039B468 */

/* localdecomp:start func_0039B490 */

extern S_142430x D_142430;
extern s32 D_001D4CE8_g;

void func_0039B490(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_0039B490 */

/* localdecomp:start func_0039B4B8 */
extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
void func_0039B4B8(void) {
    S_142430x *p = &D_142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_0039B4B8 */

/* localdecomp:start func_0039B4E0 */
extern s32 D_00142430_0039B4E0[];
extern s32 D_001D4CE8_0039B4E0;
extern s32 D_001D4CEC_0039B4E0;
void func_0039B4E0(void) {
    s32 *s = D_00142430_0039B4E0;
    D_001D4CEC_0039B4E0 &= ~0x20;
    if (s[2] == 2) {
        if (s[5] == 0) {
            D_001D4CE8_0039B4E0 = 7;
            return;
        }
        if (s[4]) {
            s[4] = 0;
            D_001D4CE8_0039B4E0 = 0xB;
            return;
        }
        D_001D4CE8_0039B4E0 = 0xB;
    }
}
/* localdecomp:end func_0039B4E0 */

/* localdecomp:start func_0039B548 */
typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, b11:1, b12:1, b13:1, b14:1, rest:17; } F_4CEC;
extern F_4CEC D_001D4CEC_f;
extern s32 D_00142438[];
extern u8 D_001D5BDD;
extern s32 D_001D4CE8_g;
void func_0039B548(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D5BDD != 0 || (*(s32 *)&D_001D4CEC_f & 0x12)) D_001D4CE8_g = 8;
}
/* localdecomp:end func_0039B548 */

/* localdecomp:start func_0039B598 */
extern s32 D_00142430_0039B598[];
extern s32 D_001D4CE8_0039B598;
extern s32 D_001D4CEC_0039B598;
extern u8 D_001D5BDC;
extern void func_0039C408(void);
void func_0039B598(void) {
    s32 v;
    if (D_00142430_0039B598[2] != 2) {
        D_001D4CE8_0039B598 = 4;
        return;
    }
    v = D_001D4CEC_0039B598;
    if (v & 0x20) {
        func_0039C408();
        if (D_001D5BDC) D_001D4CE8_0039B598 = 0x1A;
        else D_001D4CE8_0039B598 = 7;
    } else if (v & 8) {
        D_001D4CEC_0039B598 = v ^ 8;
        D_001D4CE8_0039B598 = 9;
    }
}
/* localdecomp:end func_0039B598 */

extern S_142430x D_142430;
extern s32 D_001D4CE8_g;
/* localdecomp:start func_0039B628 */
void func_0039B628(void) {
    S_142430x *p = &D_142430;
    p->f10 = 0;
    if (p->f164 < 0) {
        p->f168 = 0;
        p->f164 = 3;
    }
    D_001D4CE8_g = 10;
}
/* localdecomp:end func_0039B628 */

/* localdecomp:start func_0039B658 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396488;
extern S_396488 D_00142430_0039B658[];
extern s32 D_001D4CEC_0039B658;
extern s32 D_001D4CE8_0039B658;
void func_0039B658(void) {
    S_396488 *p = D_00142430_0039B658;
    if (p->x15C == 2 && p->x164 < 0) {
        if (p->x16C) {
            D_001D4CE8_0039B658 = 0x13;
            D_001D4CEC_0039B658 |= 0x40;
        } else {
            D_001D4CE8_0039B658 = 0x10;
        }
    }
}
/* localdecomp:end func_0039B658 */

/* localdecomp:start func_0039B6B8 */
extern s32 D_00142438[];
extern s32 D_001D4CEC_0039B6B8;
extern s32 D_001D4CE8_0039B6B8;
void func_0039B6B8(void) {
    s32 v;
    if (D_00142438[0] != 2) {
        D_001D4CE8_0039B6B8 = 4;
        return;
    }
    v = D_001D4CEC_0039B6B8;
    if (v & 0x806) {
        D_001D4CE8_0039B6B8 = 0xC;
        return;
    }
    if (v & 0x200) {
        D_001D4CE8_0039B6B8 = 0x1C;
    }
}
/* localdecomp:end func_0039B6B8 */

/* localdecomp:start func_0039B708 */
typedef struct { u32 b0:11; u32 f11:1; u32 rest:20; } S_396538;
extern s32 D_00142430_0039B708[];
extern s32 D_001D4CE8_0039B708;
extern union { s32 i; S_396538 b; } D_001D4CEC_0039B708;
void func_0039B708(void) {
    s32 *p = D_00142430_0039B708;
    if (p[0x15C/4] == 2 && p[0x164/4] < 0) {
        p[0x164/4] = 7;
        p[4] = 0;
p[0x168/4] = 0;
        D_001D4CE8_0039B708 = 0xD;
        D_001D4CEC_0039B708.b.f11 = 0;
    }
}
/* localdecomp:end func_0039B708 */

/* localdecomp:start func_0039B760 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 h18; u8 p1A[6]; s32 f20; u8 p24[0x15C - 0x24]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_396590;
extern S_396590 D_00142430_0039B760[];
extern s32 D_001D4CE8_0039B760;
void func_0039B760(void) {
    S_396590 *s = D_00142430_0039B760;
    if (s->f15C != 2) return;
    if (s->f164 >= 0) return;
    if (s->f16C != 0) {
        D_001D4CE8_0039B760 = 0xE;
        return;
    }
    if (s->f8 != 2) {
        D_001D4CE8_0039B760 = 4;
        return;
    }
    if (s->h18 == -2) {
        if (s->fC + s->f20 < 0x258) {
            D_001D4CE8_0039B760 = 0x15;
            return;
        }
        D_001D4CE8_0039B760 = 0xE;
        return;
    }
    if (s->h18 >= -1) {
        D_001D4CE8_0039B760 = 0x12;
    }
}
/* localdecomp:end func_0039B760 */

/* localdecomp:start func_0039B7F8 */
typedef struct { u8 pad0[0x10]; s32 x10; u8 pad[0x15C-0x14]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396628;
extern S_396628 D_00142430_0039B7F8[];
extern s32 D_001D4CEC_0039B7F8;
extern s32 D_001D4CE8_0039B7F8;
void func_0039B7F8(void) {
    S_396628 *p = D_00142430_0039B7F8;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 7;
        p->x10 = 0;
        p->x168 = 0;
        D_001D4CEC_0039B7F8 &= ~0x800;
        D_001D4CE8_0039B7F8 = 0x20;
    }
}
/* localdecomp:end func_0039B7F8 */

/* localdecomp:start func_0039B850 */
typedef struct { u8 p0[8]; s32 f8; s32 fC; u8 p10[8]; s16 f18; u8 p1A[2]; s32 f1C; s32 f20; u8 p24[0x138]; s32 f15C; u8 p160[4]; s32 f164; u8 p168[4]; s32 f16C; } S_142430_00396680;
__asm__(".extern D_001D4CEC_00396682, 4");
__asm__(".extern D_001D62F0_0039B850, 4");
__asm__(".extern D_001D6304_0039B850, 4");
extern S_142430_00396680 D_142430_0039B850;
extern s32 D_001D4CEC_00396682;
extern s32 D_001D4CEC_0039B850;
extern s32 D_001D4CE8_0039B850;
extern void (*D_001D6304_0039B850)(void);
extern s32 D_001D62F0_0039B850;
void func_0039B850(void) {
    s32 c;
    s32 a;
    s32 u;
    s32 w;
    a = D_142430_0039B850.f15C;
    if (a == 2 && D_142430_0039B850.f164 < 0) {
        if (D_142430_0039B850.f16C != 0) {
            u = D_001D4CEC_00396682;
            c = 0x18; D_001D4CE8_0039B850 = c; D_001D4CEC_00396682 = u | 0x40;
            goto cb;
        }
        if (D_142430_0039B850.f8 != a) {
            D_001D4CE8_0039B850 = 4;
        } else {
            a = D_142430_0039B850.f18;
            if (a == -2) {
                if (D_142430_0039B850.fC + D_142430_0039B850.f20 >= 0x258) {
                    u = D_001D4CEC_0039B850;
                    c = 0x18; D_001D4CE8_0039B850 = c; D_001D4CEC_00396682 = u | 0x40;
                } else {
                    D_001D4CE8_0039B850 = 0x15;
                }
            } else if (a < -1) {
            } else if (a != -1) {
                D_001D4CE8_0039B850 = 0x12;
            } else {
                w = D_001D4CEC_0039B850;
                if (w & 0x1000) {
                    s32 t = *(u16 *)&D_001D62F0_0039B850;
                    D_001D62F0_0039B850 = a;
                    D_142430_0039B850.f18 = t;
                    D_001D4CEC_0039B850 = w & ~0x1000;
                }
                D_001D4CE8_0039B850 = 0x12;
            }
        }
cb:
        if (D_001D6304_0039B850 != 0) {
            D_001D6304_0039B850();
            D_001D6304_0039B850 = 0;
        }
    }
}
/* localdecomp:end func_0039B850 */

/* localdecomp:start func_0039B950 */
extern s32 D_00142438[];
extern s32 D_001D4CE8_g;
extern s32 D_001D4CEC_g;
void func_0039B950(void) {
    if (D_00142438[0] != 2) {
        D_001D4CE8_g = 4;
        return;
    }
    if (D_001D4CEC_g & 0x12) D_001D4CE8_g = 15;
}
/* localdecomp:end func_0039B950 */

/* localdecomp:start func_0039B990 */
extern s32 D_00142438[];
extern s32 D_001D4CEC_0039B990;
extern s32 D_001D4CE8_0039B990;
extern u8 D_001D5BDC;
void func_0039B990(void) {
    s32 f;
    if (D_00142438[0] != 2) { D_001D4CE8_0039B990 = 4; return; }
    f = D_001D4CEC_0039B990;
    if (f & 0x20) {
        D_001D4CEC_0039B990 = f ^ 0x20;
        if (D_001D5BDC != 0) { D_001D4CE8_0039B990 = 0x1B; } else { D_001D4CE8_0039B990 = 0xE; }
        return;
    }
    if (f & 0x2000) { D_001D4CE8_0039B990 = 0x10; }
}
/* localdecomp:end func_0039B990 */

/* localdecomp:start func_0039BA00 */
typedef struct { u8 pad[0x15C]; s32 x15C; s32 x160; s32 x164; s32 x168; s32 x16C; } S_396830;
extern S_396830 D_00142430_0039BA00[];
extern s32 D_001D4CEC_0039BA00;
extern s32 D_001D4CE8_0039BA00;
void func_0039BA00(void) {
    S_396830 *p = D_00142430_0039BA00;
    if (p->x15C == 2 && p->x164 < 0) {
        p->x164 = 9;
        D_001D4CEC_0039BA00 &= ~2;
        D_001D4CEC_0039BA00 &= ~0x10;
        p->x168 = 0;
        D_001D4CE8_0039BA00 = 0x11;
    }
}
/* localdecomp:end func_0039BA00 */

/* localdecomp:start func_0039BA60 */
typedef struct { u8 pad[0x18]; s16 f18; u8 padA[0x12E]; s32 f148; u8 padB[0x10]; s32 f15C; u8 pad2[4]; s32 f164; u8 pad3[4]; s32 f16C; } S_396890;
extern S_396890 D_142430_0039BA60;
extern s32 D_001D4CEC_0039BA60;
extern s32 D_001D4CE8_0039BA60;
void func_0039BA60(void) {
    S_396890 *s = &D_142430_0039BA60;
    if (s->f15C == 2 && s->f164 < 0) {
        if (s->f16C != 0) {
            D_001D4CE8_0039BA60 = 0x14;
            D_001D4CEC_0039BA60 |= 0x40;
        } else {
            s->f148 = 0;
            s->f18 = 0;
            D_001D4CE8_0039BA60 = 0x1F;
        }
    }
}
/* localdecomp:end func_0039BA60 */

/* localdecomp:start func_0039BAC8 */
__asm__(".extern D_001D6308, 2");
__asm__(".extern D_001D62F4_0039BAC8, 4");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x15C - 0x1A]; s32 x15C; s32 pad4; s32 x164; } S_3968F8;
extern S_3968F8 D_00142430_0039BAC8[];
extern void (*D_001D62F4_0039BAC8)(void);
extern u16 D_001D6308;
extern s32 D_001D4CE8_0039BAC8;
extern s32 D_001D4CEC_0039BAC8;
extern void func_0039C408(void);
void func_0039BAC8(void) {
    S_3968F8 *p = D_00142430_0039BAC8;
    if (p->x15C == 2 && p->x164 < 0) {
        if (*(s32 *)((u8 *)p + *(s32 *)&D_001D6308 * 0x1C + 0x30) == -1 || (D_001D4CEC_0039BAC8 & 0x6000) != 0) {
            func_0039C408();
            D_001D4CEC_0039BAC8 &= ~0x4000;
            if (D_001D62F4_0039BAC8) {
                D_001D62F4_0039BAC8();
                D_001D62F4_0039BAC8 = 0;
            }
            p->h18 = D_001D6308;
            D_001D4CE8_0039BAC8 = 0x19;
        } else {
            D_001D4CE8_0039BAC8 = 0x21;
        }
    }
}
/* localdecomp:end func_0039BAC8 */

/* localdecomp:start func_0039BB88 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_001D62FC, 4");
__asm__(".extern D_001D6308, 2");
typedef struct { u8 pad[0x18]; u16 h18; u8 pad2[0x148 - 0x1A]; s32 x148; u8 pad3[0x10]; s32 x15C; s32 pad4; s32 x164; } S_3969B8;
extern S_3969B8 D_00142430_0039BB88[];
extern void (*D_001D62FC)(void);
extern u16 D_001D6308;
extern s32 D_001D4CE8_0039BB88;
void func_0039BB88(void) {
    S_3969B8 *p = D_00142430_0039BB88;
    if (p->x15C == 2 && p->x164 < 0) {
        if (D_001D62FC) {
            D_001D62FC();
            D_001D62FC = 0;
        }
        p->h18 = D_001D6308;
        p->x148 = 0;
        D_001D4CE8_0039BB88 = 0x17;
    }
}
/* localdecomp:end func_0039BB88 */

/* localdecomp:start func_0039BBF8 */
typedef struct { u8 pad[8]; s32 f8; u8 pad2[0x170]; s32 f17C; } S_142430_396A28;
extern S_142430_396A28 D_142430_0039BBF8;
extern s32 D_001D4CE8_0039BBF8;
extern s32 D_001D4CEC_0039BBF8;
void func_0039BBF8(void) {
    s32 f = D_001D4CEC_0039BBF8;
    if (f & 4) D_001D4CE8_0039BBF8 = 0x1E;
    if (f & 2) D_001D4CE8_0039BBF8 = 0x1D;
    if (f & 0x800) D_001D4CE8_0039BBF8 = 0xC;
    if (f & 0x80) {
        D_001D4CE8_0039BBF8 = 0x18;
        D_001D4CEC_0039BBF8 = (f ^ 0x80) | 0x40;
        return;
    }
    if (f & 0x100) {
        D_001D4CE8_0039BBF8 = 0x16;
        D_001D4CEC_0039BBF8 = (f ^ 0x100) | 0x40;
        return;
    }
    if (D_142430_0039BBF8.f8 != 2) {
        D_001D4CE8_0039BBF8 = 4;
        return;
    }
    if (D_142430_0039BBF8.f17C) D_001D4CE8_0039BBF8 = 1;
}
/* localdecomp:end func_0039BBF8 */
