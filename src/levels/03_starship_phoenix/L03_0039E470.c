#include "common.h"

typedef struct {
    u8 pad0[0x20]; u8 st; u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; void *p68;
} S_0039E470;
typedef struct {
    u8 pad0[0x23]; u8 b23;
} T_0039E470;
typedef struct {
    u8 pad0[0x144]; s16 h144;
    u8 pad146[0x250 - 0x146]; void *p250;
    u8 pad254[0x268 - 0x254]; s16 h268;
    u8 pad26A[0x300 - 0x26A]; T_0039E470 *p300;
    u8 pad304[0x309 - 0x304]; u8 b309; s16 h30A; f32 f30C; u8 b310;
} P_0039E470;

typedef struct {
    u8 pad0[0x39];
    u8 b39;
    u8 pad3A[0x6];
    f32 f40;
    u8 pad44[0x14];
    u8 b58;
    u8 pad59[0x1];
    u8 b5A;
    u8 pad5B[0x25];
    u8 b80;
    u8 b81;
    u8 b82;
    u8 pad83[0x3];
    u8 b86;
    u8 pad87[0x5];
    f32 f8C;
    f32 f90;
    f32 f94;
    f32 f98;
    f32 f9C;
    f32 fA0;
    f32 fA4;
    u8 padA8[0x4];
    f32 fAC;
    u8 padB0[0x8];
    u8 bB8;
    u8 padB9[0x2F];
    u8 bE8;
    u8 bE9;
    u8 padEA[0x1];
    u8 bEB;
    u8 padEC[0x64];
    f32 f150;
    f32 f154;
    f32 f158;
    f32 f15C;
    f32 f160;
    u8 pad164[0x18];
    f32 f17C;
    f32 f180;
    f32 f184;
    s32 w188;
    u8 pad18C[0xB0];
    s32 w23C;
    u8 pad240[0x14];
    void * p254;
    void * p258;
    u8 pad25C[0x11];
    u8 b26D;
    u8 pad26E[0x92];
    s32 w300;
} P_0039E748;

typedef struct {
    u8 pad0[0x44]; u8 b44;
    u8 pad45[0x70 - 0x45]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x144 - 0x138]; s16 s144;
    u8 pad146[0x188 - 0x146]; s32 i188;
    u8 pad18C[0x250 - 0x18C]; void *p250;
    u8 pad254[0x268 - 0x254]; s16 s268; s16 s26A; u8 pad26C[4]; u8 a270[0x80];
    u8 a2F0[0x10]; u8 *p300;
    u8 pad304[0x30C - 0x304]; f32 f30C; u8 a310[0x10];
} P_003A05D0;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st;
    u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; P_003A05D0 *p;
    u8 pad6C[0xBC - 0x6C]; u8 bBC;
} S_003A05D0;

typedef struct { u8 pad0[0x16C]; u8 *p16C; } T_0039F028;

typedef struct {
    u8 pad0[0x30]; f32 f30;
    u8 pad34[0x3E - 0x34]; u8 b3E; u8 pad3F[0x5E - 0x3F]; u8 b5E; u8 pad5F; u8 b60;
    u8 pad61[0x70 - 0x61]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x188 - 0x138]; s32 i188;
    u8 pad18C[0x228 - 0x18C]; s32 i228;
    u8 pad22C[0x270 - 0x22C]; u8 a270[0x68];
    f32 f2D8; u8 pad2DC[0x2F0 - 0x2DC]; u8 a2F0[0x450 - 0x2F0];
    u8 *p450; u8 pad454[0x45B - 0x454]; u8 b45B;
} P_0039FB18;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st; u8 pad21[0x10]; u8 f31;
    u8 pad32[0x68 - 0x32]; P_0039FB18 *p; u8 pad6C[3]; u8 b6F; u8 pad70[0x88]; f32 fF8;
} S_0039FB18;
typedef struct S_0039F3C0 S_0039F3C0;
typedef struct P_0039F3C0 P_0039F3C0;
struct P_0039F3C0 {
    u8 pad0[0x70]; u8 a70[0xC0]; f32 f130; f32 f134;
    u8 pad138[0x144 - 0x138]; s16 s144;
    u8 pad146[0x188 - 0x146]; s32 i188;
    u8 pad18C[0x250 - 0x18C]; void *p250;
    u8 pad254[0x260 - 0x254]; f32 f260;
    u8 pad264[0x268 - 0x264]; s16 s268; s16 s26A;
    u8 pad26C[0x270 - 0x26C]; u8 a270[0x80];
    u8 a2F0[0x150]; u8 a440[0x10];
    S_0039F3C0 *p450; u8 pad454[0x458 - 0x454]; s16 s458; u8 b45A; u8 pad45B; f32 f45C;
};
struct S_0039F3C0 {
    u8 pad0[0x10]; f32 x; f32 y;
    u8 pad18[0x20 - 0x18]; u8 st; u8 pad21[2]; u8 b23;
    u8 pad24[0x60 - 0x24]; u8 b60;
    u8 pad61[0x68 - 0x61]; P_0039F3C0 *p;
};

/* localdecomp:start func_L03_0039E470 */
extern void func_L03_0039E748(void *);
extern void func_L03_0039E8F0();
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CB00(void *);
extern void func_L03_0039ECA0(void *, s32);
extern void func_L01_0045A9F0(void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L03_0032D598(void *, void *);
extern s32 func_L03_0032D640(void *, void *);
extern s32 func_L03_0039EEE8(void *);
extern void func_L03_0039EE10(void *, f32);
extern s32 func_00382468(s32);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);

void func_L03_0039E470(S_0039E470 *s) {
    P_0039E470 *p;
    func_L03_0039E748(s);
    func_L03_0039E8F0(s);
    p = s->p68;
    switch (s->st) {
    case 2:
        if (func_L01_004561B8(s)) {
            p->f30C = 1.0f / (f32)p->h268;
        }
        s->b23 = (s32)((1.0f - p->f30C * (f32)p->h268) * 128.0f);
        if (func_0038CB00(&p->h268)) {
            s->b23 = 0x80;
            func_L03_0039ECA0(s, 3);
        }
        if (p->p300 != 0) {
            p->p300->b23 = s->b23;
        }
        break;
    case 3:
        func_L01_0045A9F0(s);
        func_L03_0039ECA0(s, 5);
    case 4:
        if (func_L01_00454370(s, (u8 *)p + 0x70) & 2) {
            func_L03_0039ECA0(s, 5);
        }
        break;
    case 5:
        func_L01_0045A9F0(s);
        if (func_0038CB00(&p->h30A)) {
            if (p->h144 == 1) {
                if (func_L03_0032D598(p->p250, s) != 0) {
                    func_L03_0039ECA0(s, 6);
                } else {
                    func_L03_0039ECA0(s, 8);
                }
            }
        }
        break;
    case 6:
        if (p->p300 != 0) {
            if (p->b309 < 0xFF) p->b309++;
            if (func_L03_0039EEE8(s)) p->b310 = 1;
        }
        func_L03_0039EE10(s, 3.0f);
        if (p->b310 != 0 && p->b309 >= 0x19) {
            func_L03_0039ECA0(s, 7);
        }
        if (p->h144 != 1) {
            func_L03_0032D640(p->p250, s);
            func_L03_0039ECA0(s, 5);
        } else if (func_L03_0032D598(p->p250, s) == 0) {
            func_L03_0039ECA0(s, 8);
        }
        break;
    case 7:
        func_L03_0039EE10(s, 3.0f);
        if (s->b60 & 2) {
            p->h30A = func_00382468(0x19) + 0x32;
            func_L03_0039ECA0(s, 6);
        }
        break;
    case 8:
        func_L03_0039EE10(s, 5.0f);
        if (p->h144 != 1) {
            func_L03_0039ECA0(s, 5);
        } else if (func_L03_0032D598(p->p250, s) != 0) {
            func_L03_0039ECA0(s, 6);
        }
        break;
    case 1:
    default:
        break;
    }
    func_L01_00451DF8(s, (u8 *)p + 0x270, 2, 1, 1.5f);
}
/* localdecomp:end func_L03_0039E470 */

/* localdecomp:start func_L03_0039E748 */
extern void func_L03_0039EBE8();
extern void func_L03_0039EB90(void *);
extern void func_00449540(void *, f32, f32, f32, f32);
void func_L03_0039E748(void *a) {
    P_0039E748 *p;
    if (*(u8 *)((u8 *)a + 0x20) == 0) {
        p = *(P_0039E748 **)((u8 *)a + 0x68);
        p->bB8 = 0xFF;
        p->b39 = 0;
        p->w23C = 0;
        p->b26D = 0;
        p->b80 = 4;
        p->b81 = 3;
        p->b82 = 3;
        p->bE8 = 5;
        p->bE9 = 5;
        p->fAC = 0.150000006f;
        p->bEB = 0xFF;
        p->b86 = 0xFF;
        p->f8C = 0.300000012f;
        p->f90 = 0.0200000014f;
        p->f94 = 0.0100000007f;
        p->f98 = 0.0140000004f;
        p->f9C = 0.000800000038f;
        p->b58 = 0x14;
        p->b5A = 0xE;
        p->f40 = 1.0f;
        p->f160 = 1.57079637f;
        p->f180 = 0.244346097f;
        p->f17C = 0.196000025f;
        p->fA0 = 0.5f;
        p->fA4 = 0.5f;
        p->f150 = 0.5f;
        p->f154 = 0.5f;
        p->f158 = 0.5f;
        p->f15C = 0.5f;
        p->f184 = 0.5f;
        p->p254 = func_L03_0039EBE8;
        p->p258 = func_L03_0039EB90;
        func_00449540(a, 0.00120000006f, 0.0600000024f, 0.00125663716f, 0.0628318563f);
        p->w188 |= 0x10;
        func_L03_0039EB90(a);
        p->w300 = 0;
    }
}
/* localdecomp:end func_L03_0039E748 */

/* localdecomp:start func_L03_0039E8F0 */
typedef struct {
    u8 pad0[0x30]; f32 f30;
    u8 pad34[0x3E - 0x34]; u8 b3E; u8 pad3F[0x5E - 0x3F]; u8 b5E; u8 pad5F; u8 b60;
    u8 pad61[0x70 - 0x61]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x228 - 0x138]; s32 i228;
    u8 pad22C[0x270 - 0x22C]; u8 a270[0x68];
    f32 f2D8; u8 pad2DC[0x300 - 0x2DC]; u8 *p300; u8 pad304[4]; u8 b308;
} P_0039E8F0;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st; u8 pad21[0x10]; u8 f31;
    u8 pad32[0x68 - 0x32]; P_0039E8F0 *p; u8 pad6C[3]; u8 b6F; u8 pad70[0x88]; f32 fF8;
} S_0039E8F0;
void func_L01_00404808(void *, void *);
void func_L01_00452FB0(void *, void *, s32, s32, s32);
void func_L03_0032DDC8(void *, s32, s32);
void func_L03_0032DF10(void *);
void func_003A52A0(s32, s32, void *);
void func_L03_0032FBC8(void *);
void func_003C2F58(void *, s32, void *);
void func_003C2EC0(void *, s32, void *);
void func_0038D590(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_003C7C38(void *);
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
void func_L01_0044E850(void *, void *, s32, f32, f32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
void func_L03_0039F2C8(void *);
extern u8 D_L03_001E24C0[];
void func_L03_0039E8F0(S_0039E8F0 *s) {
    P_0039E8F0 *p;
    char buf[0x40];
    f32 one;
    f32 a;
    p = s->p;
    if (s->st == 1) return;
    if (p->i228 == 1) {
        func_L01_00404808(func_L03_0039F2C8, s);
        if (p->b308 < 15) p->b308++;
    } else if (p->b308 != 0) {
        func_L01_00404808(func_L03_0039F2C8, s);
        p->b308--;
    }
    func_L01_00452FB0(s, p->a70, 0, 0, 0);
    if (p->f30 <= 0.0f) {
        func_L03_0032DDC8(s, 15, 2);
        func_L03_0032DF10(s);
        func_003A52A0(6, 0, s);
        return;
    }
    if (p->b5E != 0 || p->b60 != 0 || p->b3E == 2) {
        func_L03_0032DF10(s);
        return;
    }
    func_L03_0032FBC8(s);
    if (p->p300 != 0) {
        one = 1.0f;
        func_003C2F58(s, 0, p->p300 + 0x10);
        func_003C2EC0(s, 0, buf);
        func_0038D590(p->p300 + 0xC0, buf);
        func_0038CF68(p->p300 + 0xC0, p->p300 + 0xC0, one);
        func_0038CF68(p->p300 + 0xD0, p->p300 + 0xD0, one);
        func_0038CF68(p->p300 + 0xE0, p->p300 + 0xE0, one);
        func_003C7C38(p->p300);
    }
    if (s->st >= 6) {
        a = func_0038DB00(func_0038D160(p->f130 - s->x, p->f134 - s->y), s->fF8);
        p->f2D8 = a;
        if (a > 1.04719758f) p->f2D8 = 1.04719758f; else if (a < -1.04719758f) p->f2D8 = -1.04719758f;
    }
    func_L01_0044E850(s, p->a270, 1, 0.0432000011f, 0.432000041f);
    if (s->f31 != 0) {
        if (func_L01_0040E548(D_L03_001E24C0, &s->x) < 576.0f) {
            func_L01_004472C0(s);
            s->b6F = 22;
        }
    }
}
/* localdecomp:end func_L03_0039E8F0 */

/* localdecomp:start func_L03_0039EB90 */
void func_003C2880(s32);
void func_L03_0032FD50(void *);
void func_L03_0039ECA0(void *, s32);

void func_L03_0039EB90(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x300);
    *(s8 *)((u8 *)temp_s0 + 0x308) = 0;
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x300) = 0;
    }
    func_L03_0032FD50(arg0);
    func_L03_0039ECA0(arg0, 1);
}
/* localdecomp:end func_L03_0039EB90 */

/* localdecomp:start func_L03_0039EBE8 */
void *func_003C24B0(s32, s32);
void func_003C7C38(void *);
void func_L01_0044A7D0(u8 *);
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L03_0032FE10(void *);
void func_L03_0039ECA0(void *, s32);

void func_L03_0039EBE8(void *arg0) {
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_v0 = func_003C24B0(0x18F9, 0x80);
    *(void **)((u8 *)temp_s0 + 0x300) = temp_v0;
    if (temp_v0 != 0) {
        *(u16 *)((u8 *)temp_v0 + 0x34) = (u16) ((*(u16 *)((u8 *)temp_v0 + 0x34)) | 0x100);
        *(u16 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x32) = (u16) (*(u16 *)((u8 *)arg0 + 0x32));
        *(u8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x31) = (u8) (*(u8 *)((u8 *)arg0 + 0x31));
        *(s8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x300))) + 0x30) = 0;
        temp_v0_2 = *(void **)((u8 *)temp_s0 + 0x300);
        *(void **)((u8 *)temp_s0 + 0x240) = temp_v0_2;
        func_L01_0044A7D0(temp_v0_2);
        func_003C7C38((*(void **)((u8 *)temp_s0 + 0x300)));
    }
    *(s16 *)((u8 *)temp_s0 + 0x30A) = 0;
    func_L01_004AAC98(4, 4, arg0, 0x197A);
    func_L03_0032FE10(arg0);
    func_L03_0039ECA0(arg0, 2);
}
/* localdecomp:end func_L03_0039EBE8 */

/* localdecomp:start func_L03_0039ECA0 */
void func_003C3A10(void *, s32, s32, s32);
void func_L03_0032D6B8(void *);
void func_L01_004450F0(void *, s32, s32);

void func_L03_0039ECA0(void *arg0, s32 arg1) {
    u8 *p = arg0;
    f32 *r;
    f32 *r2;
    u8 *q = *(u8 **)(p + 0x68);
    switch (arg1) {
    case 1:
    case 2:
        if (p[0x43] != 4) {
            func_003C3A10(arg0, 4, 0, 0);
            break;
        }
        break;
    case 3:
        *(u16 *)(p + 0x34) |= 0x5000;
        break;
    case 4:
        break;
    case 5:
        if (p[0x43] != 0) {
            func_003C3A10(arg0, 0, 0, 2);
            break;
        }
        break;
    case 6:
        r = (f32 *)(q + 0x150);
        r[8] = 0.0012000001f;
        r[10] = 0.060000002f;
        r[9] = 0.0012000001f;
        q[0x310] = 0;
        q[0x309] = 0;
        func_L03_0032D6B8(arg0);
        if (p[0x43] != 1) {
            func_003C3A10(arg0, 1, 0, 2);
            break;
        }
        break;
    case 7:
        if (p[0x43] != 2) {
            func_003C3A10(arg0, 2, 0, 2);
            break;
        }
        break;
    case 8:
        r2 = (f32 *)(q + 0x150);
        r2[8] = 0.00080000004f;
        r2[10] = 0.040000003f;
        r2[9] = 0.00080000004f;
        if (p[0x43] != 0) {
            func_003C3A10(arg0, 0, 0, 3);
        }
        break;
    }
    func_L01_004450F0(arg0, arg1, -1);
}
/* localdecomp:end func_L03_0039ECA0 */

/* localdecomp:start func_L03_0039EE10 */
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
f32 func_L03_0032DC08(s32, void *, void *, f32);
void func_L01_0045A7A8(void *, void *, f32);
void func_L03_0032D6B8(void *);

void func_L03_0039EE10(void *arg0, f32 arg1) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    f32 ang;
    void *p;
    p = (u8 *)arg0 + 0xF8;
    func_L03_0032FAF0((f32 *)(s + 0x2F0), (f32 *)(s + 0x130), *(f32 *)(s + 0x264), arg1);
    ang = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)((u8 *)arg0 + 0x10), *(f32 *)(s + 0x134) - *(f32 *)((u8 *)arg0 + 0x14));
    func_L01_00448890(p, s + 0x204, 0, ang, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    ang = func_0038DB00(*(f32 *)(s + 0x260), *(f32 *)(s + 0x264));
    ang = func_L03_0032DC08(*(s32 *)(s + 0x250), arg0, s + 0x2F0, ang * 0.15f);
    func_L01_0045A7A8(arg0, s + 0x2F0, ang);
    func_L03_0032D6B8(arg0);
}
/* localdecomp:end func_L03_0039EE10 */

/* localdecomp:start func_L03_0039EEE8 */
#include "vu0.h"
typedef struct { vu0_v4 r[4]; } M_0039EEE8;
typedef struct { u8 pad0[0x44]; u8 b44; u8 pad45[0x2BB]; void *p300; u8 pad304[5]; u8 b309; } P_0039EEE8;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L03_0039F028(void *, void *, void *, f32);
extern s32 func_L03_0032DBC0(void *);
extern s32 func_L03_0032DBD0(void *, s32);
extern s32 func_L03_00433C70(void *, void *, void *, s32, f32, f32, s32, s32, s32);
s32 func_L03_0039EEE8(void *a) {
    P_0039EEE8 *p = *(P_0039EEE8 **)((u8 *)a + 0x68);
    M_0039EEE8 m;
    vu0_v4 v;
    vu0_v4 u;
    f32 one = 1.0f;
    f32 f;
    vu0_v4 *q;
    s32 s;
    func_003C2EC0(p->p300, 0, &m);
    func_0038CF68(&v, &m.r[1], -2.0f);
    f = p->b309 * 0.125f;
    if (one < f) f = one;
    u = m.r[3];
    func_L03_0039F028(a, &u, &v, f);
    func_0038CE20(&v, &v, f);
    vec_add_ab(&v, &m.r[3], &v);
    q = &m.r[3];
    s = func_L03_0032DBC0(a);
    return func_L03_00433C70(a, q, &v, s, (f32)p->b44, one, func_L03_0032DBD0(a, 5), 1, 0) != 0;
}
/* localdecomp:end func_L03_0039EEE8 */

/* localdecomp:start func_L03_0039F028 */
extern T_0039F028 D_L03_0021F298;
__asm__(".extern D_L03_0021F298, 16");
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4C18(f32 *v, f32 r);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_004739D8(void *, void *, f32, s32, s32, s16, s32);

void func_L03_0039F028(void *arg, void *src, void *dir, f32 r) {
    vu0_v4 p0;
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 t;
    vu0_v4 vel;
    int n;
    vu0_v4 *pp = &p0;
    vu0_v4 *pd = &d;
    p0 = *(vu0_v4 *)src;
    d = *(vu0_v4 *)dir;
    n = (s32)(r * 8.0f);
    {
        int j;
        for (j = 0; j < n; j++) {
            f32 k = func_003824E0(0.0f, r);
            s32 life;
            f32 sz;
            u8 *p;
            func_0038CE20(&t, pd, k);
            vec_add_ba(&pos, pp, &t);
            func_003C4C18(&pos.x, k * 0.19f + 0.01f);
            *(vu0_q *)&vel = 0;
            vel.z = k * 0.120000005f + 0.20000002f;
            life = func_00382498(4, 6);
            sz = k * 294000.0f + 126000.01f;
            p = func_L01_0046A610(&pos, &vel, life, 0x7F, 0xFF4040, func_00382468(2) != 0 ? 3 : -3, sz, -sz / (f32)life, 1.0f, 0.0f, 0.0f);
            if (p != 0) {
                p[2] = D_L03_0021F298.p16C[1];
            }
        }
    }
    if (func_00382468(20) == 0) {
        f32 sz;
        func_0038CF68(&pos, pd, func_003824E0(0.060000002f, 0.16000001f));
        func_003C4C18(&pos.x, 0.020000001f);
        sz = func_003824E0(21000.0f, 63000.004f);
        func_L01_004739D8(pp, &pos, sz, 0x80A02020, 0x20808080, func_00382498(0x21, 0x32), 0);
    }
}
/* localdecomp:end func_L03_0039F028 */

/* localdecomp:start func_L03_0039F2C8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_0039F2C8;
typedef struct { unsigned char pad0[0x2F0]; V4_0039F2C8 pos; unsigned char pad300[4]; float t; unsigned char a; } S_0039F2C8;
typedef struct { float pad[10]; float f28; float pad2c; V4_0039F2C8 pos; } L_0039F2C8;
void func_0038D2D0(void *, float);
void func_003D9740(void *, int, int, int, int, float);

void func_L03_0039F2C8(void *arg0) {
    S_0039F2C8 *s = *(S_0039F2C8 **)((char *)arg0 + 0x68);
    L_0039F2C8 l;
    float t;
    t = s->t + 0.096f;
    s->t = t;
    if (1.0f < t) {
        s->t = t - 1.0f;
    }
    func_0038D2D0(&l, 0.75f);
    l.pos = *(V4_0039F2C8 *)((char *)arg0 + 0x10);
    l.f28 = -0.85f;
    l.pos.z += 0.85f;
    func_003D9740(&l, 0x28, ((int)(s->a / 15.0f * 255.0f) << 24) | 0xFF4040, 5, 1, s->t);
}
/* localdecomp:end func_L03_0039F2C8 */

/* localdecomp:start func_L03_0039F3C0 */
/* PAL port of the NTSC-U match src/us/levels/func_L03_0039DBE8.c */

extern void func_L03_0039F960(u8 *);
extern void func_L03_0039FB18(S_0039FB18 *s);
void func_L03_0039FEF0(void *, s32);
void func_L03_003A02B0(void *, f32);
s32 func_L03_003A0398(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_0045A9F0(void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L03_0032D598(void *, void *);
f32 func_L01_0040E570(void *, void *);
f32 func_0038D160(f32, f32);
s32 func_L01_0045AA10(void *, f32);
void func_L03_0032DA08(void *);
s32 func_L03_0032D8C0(void *);
s32 func_L03_0032DB58(void *);
s32 func_L01_0044E1B8(void *, f32);
void func_L01_0044E468(void *, s32);
s32 func_L01_0045A748(void *, void *);
void func_L01_0044E740(void *);
extern s32 func_00382468(s32);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);

void func_L03_0039F3C0(S_0039F3C0 *s) {
    P_0039F3C0 *p;
    s32 v;
    s32 w;
    s32 n;
    s32 m;
    func_L03_0039F960(s);
    func_L03_0039FB18(s);
    p = s->p;
    switch (s->st) {
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(s)) {
            p->f45C = 1.0f / p->s268;
        }
        s->b23 = (1.0f - p->f45C * p->s268) * 128.0f;
        if (func_0038CB00(&p->s268)) {
            s->b23 = 0x80;
            func_L03_0039FEF0(s, 3);
        }
        if (p->p450 != 0) {
            p->p450->b23 = s->b23;
        }
        break;
    case 3:
        func_L01_0045A9F0(s);
        func_L03_0039FEF0(s, 5);
    case 4:
        if ((func_L01_00454370(s, p->a70) & 2) == 0) {
            break;
        }
        goto L884;
    case 5:
        func_L01_0045A9F0(s);
        if (p->s144 == 1) {
            if (func_L03_0032D598(p->p250, s)) {
                if (func_L01_0040E570(&s->x, &p->f130) < 36.0f) {
                    goto L650;
                }
                goto L660;
            }
            goto L6C8;
        }
        break;
    case 6:
        func_L01_0045AA10(s, func_0038D160(p->f130 - s->x, p->f134 - s->y));
        if (s->b60 & 2) {
            func_L03_0039FEF0(s, 7);
        }
        break;
    case 7:
        func_L03_003A02B0(s, 2.0f);
        if (p->s144 == 1) {
            if (func_L03_0032D598(p->p250, s)) {
                if (!(func_L01_0040E570(&s->x, &p->f130) < 6.25f)) {
                    break;
                }
            }
        }
        func_L03_0039FEF0(s, 8);
        break;
    case 8:
        if (!(s->b60 & 2)) {
            break;
        }
        if (p->s144 != 1) {
            goto L884;
        }
        if (func_L03_0032D598(p->p250, s)) {
            if (!(func_L01_0040E570(&s->x, &p->f130) < 36.0f)) {
                goto L660;
            }
            p->s458 = 0;
L650:
            func_L03_0039FEF0(s, 9);
            break;
L660:
            func_L03_0039FEF0(s, 6);
            break;
        }
        goto L6C8;
    case 9:
        func_L03_003A02B0(s, 3.5f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0032DA08(s);
            goto L884;
        }
        if (func_L03_0032D598(p->p250, s) == 0) {
            func_L03_0032DA08(s);
L6C8:
            func_L03_0039FEF0(s, 14);
            break;
        }
        if (func_0038CB00(&p->s458)) {
            if (p->s26A == -1) {
                p->s26A = func_L03_0032D8C0(s);
            }
            if (func_L03_0032DB58(s)) {
                p->i188 &= ~0x10;
                func_L03_0039FEF0(s, 10);
            }
        }
        break;
    case 10:
        func_L01_0045AA10(s, func_0038D160(p->f130 - s->x, p->f134 - s->y));
        if (func_L01_0044E1B8(s, 17.0f)) {
            func_L01_004AAC98(6, 0, s, 0x197B);
        }
        if (s->b60 & 2) {
            func_L03_0039FEF0(s, 11);
        }
        break;
    case 11:
        func_L01_0044E468(p->a2F0, 0);
        v = func_L01_0045A748(s, p->a440);
        p->f260 = func_0038D160(s->x - p->f130, s->y - p->f134);
        if (!(v & 0x80)) {
            if (func_L03_003A0398(s) == 0) {
                break;
            }
        }
        p->i188 &= ~0x10;
        func_L01_0044E740(p->a2F0);
        func_L03_0039FEF0(s, 12);
        break;
    case 12:
        func_L01_0045A9F0(s);
        p->f260 = func_0038D160(s->x - p->f130, s->y - p->f134);
        if (s->b60 & 2) {
            p->s458 = func_00382468(25) + 50;
            func_L03_0032DA08(s);
            if (p->b45A) {
                func_L03_0039FEF0(s, 13);
                break;
            }
L884:
            func_L03_0039FEF0(s, 5);
        }
        break;
    case 13:
        func_L03_003A02B0(s, 3.5f);
        if (s->b60 & 2) {
            p->i188 &= ~0x10;
            func_L03_0039FEF0(s, 5);
        }
        break;
    case 14:
        func_L03_003A02B0(s, 5.0f);
        if (p->s144 != 1) {
            p->i188 &= ~0x10;
            func_L03_0039FEF0(s, 5);
            break;
        }
        if (func_L03_0032D598(p->p250, s)) {
            p->i188 &= ~0x10;
            func_L03_0039FEF0(s, 6);
        }
        break;
    }
    func_L01_00451DF8(s, p->a270, 1, 1, 1.5f);
}
/* localdecomp:end func_L03_0039F3C0 */

/* localdecomp:start func_L03_0039F960 */
void func_L03_0039FDE0(void *);
void func_L03_0039FE40(void *);
void func_L01_0045BD78(u8 *a0, f32 a, f32 b, f32 c, f32 d);

void func_L03_0039F960(u8 *arg0) {
    u8 *s;
    if (arg0[0x20] == 0) {
        s = *(u8 **)(arg0 + 0x68);
        s[0x80] = 4;
        s[0xB8] = 255;
        s[0x81] = 9;
        s[0xE8] = 5;
        s[0x82] = 9;
        s[0xEB] = 255;
        s[0xE9] = 5;
        *(f32 *)(s + 0xAC) = 0.15f;
        s[0x86] = 255;
        *(f32 *)(s + 0x8C) = 0.3f;
        *(f32 *)(s + 0xA0) = 0.5f;
        *(f32 *)(s + 0x90) = 0.020000001f;
        *(f32 *)(s + 0x94) = 0.010000001f;
        *(f32 *)(s + 0x98) = 0.014f;
        *(f32 *)(s + 0x9C) = 0.00080000004f;
        *(f32 *)(s + 0x118) = 0.25f;
        s[0x58] = 20;
        *(f32 *)(s + 0xA4) = 0.5f;
        *(f32 *)(s + 0x150) = 0.5f;
        s[0x5A] = 14;
        s[0x39] = 0;
        *(f32 *)(s + 0x40) = 1.0f;
        *(f32 *)(s + 0x160) = 1.5707964f;
        *(s32 *)(s + 0x23C) = 0;
        *(f32 *)(s + 0x180) = 0.2443461f;
        *(f32 *)(s + 0x154) = 0.5f;
        *(f32 *)(s + 0x158) = 0.5f;
        *(f32 *)(s + 0x17C) = 0.19600002f;
        *(f32 *)(s + 0x15C) = 0.5f;
        *(f32 *)(s + 0x184) = 0.5f;
        *(void **)(s + 0x254) = func_L03_0039FE40;
        *(void **)(s + 0x258) = func_L03_0039FDE0;
        s[0x26D] = 2;
        func_L01_0045BD78(arg0, 0.0012f, 0.060000002f, 0.0012566372f, 0.06283186f);
        *(s16 *)(s + 0x26A) = -1;
        func_L03_0039FDE0(arg0);
        *(s32 *)(s + 0x450) = 0;
    }
}
/* localdecomp:end func_L03_0039F960 */

/* localdecomp:start func_L03_0039FB18 */
void func_L01_00404808(void *, void *);
s32 func_L01_00452FB0_0039FB18(void *, void *, s32, s32, s32);
void func_L01_0044E740(void *);
void func_L03_0032DA08(void *);
void func_L03_0032DDC8(void *, s32, s32);
void func_L03_0032DF10(void *);
void func_003A52A0(s32, s32, void *);
void func_L03_0032FBC8(void *);
void func_003C2F58(void *, s32, void *);
void func_003C2EC0(void *, s32, void *);
void func_0038D590(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_003C7C38(void *);
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
void func_L01_0044E850(void *, void *, s32, f32, f32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
void func_L03_003A04D0(void *);
extern u8 D_L03_001E24C0[];
void func_L03_0039FB18(S_0039FB18 *s) {
    P_0039FB18 *p;
    char buf[0x40];
    f32 one;
    f32 a;
    p = s->p;
    if (s->st == 1) return;
    if (p->i228 == 1) {
        func_L01_00404808(func_L03_003A04D0, s);
        if (p->b45B < 15) p->b45B++;
    } else if (p->b45B != 0) {
        func_L01_00404808(func_L03_003A04D0, s);
        p->b45B--;
    }
    if (func_L01_00452FB0_0039FB18(s, p->a70, 0, 0, 0)) {
        func_L01_0044E740(p->a2F0);
        func_L03_0032DA08(s);
        p->i188 &= ~0x10;
    }
    if (p->f30 <= 0.0f) {
        func_L03_0032DDC8(s, 7, 1);
        func_L03_0032DF10(s);
        func_003A52A0(7, 0, s);
        return;
    }
    if (p->b5E != 0 || p->b60 != 0 || p->b3E == 2) {
        func_L03_0032DF10(s);
        return;
    }
    func_L03_0032FBC8(s);
    if (p->p450 != 0) {
        one = 1.0f;
        func_003C2F58(s, 0, p->p450 + 0x10);
        func_003C2EC0(s, 0, buf);
        func_0038D590(p->p450 + 0xC0, buf);
        func_0038CF68(p->p450 + 0xC0, p->p450 + 0xC0, one);
        func_0038CF68(p->p450 + 0xD0, p->p450 + 0xD0, one);
        func_0038CF68(p->p450 + 0xE0, p->p450 + 0xE0, one);
        func_003C7C38(p->p450);
    }
    if (s->st >= 6) {
        a = func_0038DB00(func_0038D160(p->f130 - s->x, p->f134 - s->y), s->fF8);
        p->f2D8 = a;
        if (a > 1.04719758f) p->f2D8 = 1.04719758f; else if (a < -1.04719758f) p->f2D8 = -1.04719758f;
    }
    func_L01_0044E850(s, p->a270, 1, 0.0432000011f, 0.432000041f);
    if (s->f31 != 0) {
        if (func_L01_0040E548(D_L03_001E24C0, &s->x) < 576.0f) {
            func_L01_004472C0(s);
            s->b6F = 22;
        }
    }
}
/* localdecomp:end func_L03_0039FB18 */

/* localdecomp:start func_L03_0039FDE0 */
void func_003C2880(s32);
void func_L01_0044E740(void *);
void func_L03_0032FD50(void *);
void func_L03_0039FEF0(void *, s32);

void func_L03_0039FDE0(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x450);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x450) = 0;
    }
    func_L01_0044E740(temp_s0 + 0x2F0);
    func_L03_0032FD50(arg0);
    func_L03_0039FEF0(arg0, 1);
}
/* localdecomp:end func_L03_0039FDE0 */

/* localdecomp:start func_L03_0039FE40 */
void *func_003C24B0(s32, s32);
void func_003C7C38(void *);
void func_L01_0044A7D0(u8 *);
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L03_0032FE10(void *);
void func_L03_0039FEF0(void *, s32);

void func_L03_0039FE40(void *arg0) {
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_v0 = func_003C24B0(0x18FE, 0x80);
    *(void **)((u8 *)temp_s0 + 0x450) = temp_v0;
    if (temp_v0 != 0) {
        *(u16 *)((u8 *)temp_v0 + 0x34) = (u16) ((*(u16 *)((u8 *)temp_v0 + 0x34)) | 0x100);
        *(u16 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x450))) + 0x32) = (u16) (*(u16 *)((u8 *)arg0 + 0x32));
        *(u8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x450))) + 0x31) = (u8) (*(u8 *)((u8 *)arg0 + 0x31));
        *(s8 *)((u8 *)((*(void **)((u8 *)temp_s0 + 0x450))) + 0x30) = 0;
        temp_v0_2 = *(void **)((u8 *)temp_s0 + 0x450);
        *(void **)((u8 *)temp_s0 + 0x240) = temp_v0_2;
        func_L01_0044A7D0(temp_v0_2);
        func_003C7C38((*(void **)((u8 *)temp_s0 + 0x450)));
    }
    func_L01_004AAC98(4, 4, arg0, 0x197B);
    func_L03_0032FE10(arg0);
    func_L03_0039FEF0(arg0, 2);
}
/* localdecomp:end func_L03_0039FE40 */
