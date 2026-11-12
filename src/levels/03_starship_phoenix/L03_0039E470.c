#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0039E470);

INCLUDE_ASM("asm/levels", func_L03_0039E748);

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

INCLUDE_ASM("asm/levels", func_L03_0039EE10);

INCLUDE_ASM("asm/levels", func_L03_0039EEE8);

INCLUDE_ASM("asm/levels", func_L03_0039F028);

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

INCLUDE_ASM("asm/levels", func_L03_0039F3C0);

INCLUDE_ASM("asm/levels", func_L03_0039F960);

/* localdecomp:start func_L03_0039FB18 */
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

INCLUDE_ASM("asm/levels", func_L03_0039FEF0);

/* localdecomp:start func_L03_003A02B0 */
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
f32 func_L03_0032DC08(s32, void *, void *, f32);
void func_L01_0045A7A8(void *, void *, f32);
void func_L03_0032D6B8(void *);

void func_L03_003A02B0(void *arg0, f32 arg1) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    f32 ang;
    void *p;
    if (*(s32 *)(s + 0x188) & 0x10) {
        p = (u8 *)arg0 + 0xF8;
        ang = func_0038D160(*(f32 *)(s + 0x130) - *(f32 *)((u8 *)arg0 + 0x10), *(f32 *)(s + 0x134) - *(f32 *)((u8 *)arg0 + 0x14));
        func_L01_00448890(p, s + 0x204, 0, ang, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    }
    func_L03_0032FAF0((f32 *)(s + 0x440), (f32 *)(s + 0x130), *(f32 *)(s + 0x264), arg1);
    ang = func_0038DB00(*(f32 *)(s + 0x260), *(f32 *)(s + 0x264));
    ang = func_L03_0032DC08(*(s32 *)(s + 0x250), arg0, s + 0x440, ang * 0.15f);
    func_L01_0045A7A8(arg0, s + 0x440, ang);
    func_L03_0032D6B8(arg0);
}
/* localdecomp:end func_L03_003A02B0 */

INCLUDE_ASM("asm/levels", func_L03_003A0398);

/* localdecomp:start func_L03_003A04D0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A04D0;
typedef struct { f32 pad[10]; f32 f28; f32 f2c; V4_003A04D0 v30; } S_003A04D0;

void func_L03_003A04D0(void *arg0) {
    S_003A04D0 s;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 t;
    func_0038D2D0(&s, 0.75f);
    s.v30 = *(V4_003A04D0 *)((u8 *)arg0 + 0x10);
    s.f28 = -0.85f;
    s.v30.z += 0.85f;
    t = *(f32 *)(p + 0x454) + 0.096f;
    *(f32 *)(p + 0x454) = t;
    if (1.0f < t) {
        *(f32 *)(p + 0x454) = t - 1.0f;
    }
    func_003D9740(&s, 0x28,
                  ((s32)((p[0x45B] / 15.0f) * 255.0f) << 24) | 0xFF4040, 5, 1, *(f32 *)(p + 0x454));
}
/* localdecomp:end func_L03_003A04D0 */

INCLUDE_ASM("asm/levels", func_L03_003A05D0);

INCLUDE_ASM("asm/levels", func_L03_003A0BF8);

/* localdecomp:start func_L03_003A0DA0 */
typedef struct {
    u8 pad0[0x30]; f32 f30;
    u8 pad34[0x3E - 0x34]; u8 b3E; u8 pad3F[0x5E - 0x3F]; u8 b5E; u8 pad5F; u8 b60;
    u8 pad61[0x70 - 0x61]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x228 - 0x138]; s32 i228;
    u8 pad22C[0x270 - 0x22C]; u8 a270[0x68];
    f32 f2D8; u8 pad2DC[0x300 - 0x2DC]; u8 *p300; u8 pad304[0x312 - 0x304]; u8 b312;
} P_003A0DA0;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st; u8 pad21[0x10]; u8 f31;
    u8 pad32[0x68 - 0x32]; P_003A0DA0 *p; u8 pad6C[3]; u8 b6F; u8 pad70[0x88]; f32 fF8;
} S_003A0DA0;
void func_L01_00404808(void *, void *);
s32 func_L01_00452FB0_003A0DA0(void *, void *, s32, s32, s32);
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
void func_L03_003A16D8(void *);
extern u8 D_L03_001E24C0[];
void func_L03_003A0DA0(S_003A0DA0 *s) {
    P_003A0DA0 *p;
    char buf[0x40];
    f32 one;
    f32 a;
    p = s->p;
    if (s->st == 1) return;
    if (p->i228 == 1) {
        func_L01_00404808(func_L03_003A16D8, s);
        if (p->b312 < 15) p->b312++;
    } else if (p->b312 != 0) {
        func_L01_00404808(func_L03_003A16D8, s);
        p->b312--;
    }
    if (func_L01_00452FB0_003A0DA0(s, p->a70, 0, 0, 0)) func_L03_0032DA08(s);
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
/* localdecomp:end func_L03_003A0DA0 */

/* localdecomp:start func_L03_003A1050 */
void func_003C2880(s32);
void func_L03_0032FD50(void *);
void func_L03_003A1158(void *, s32);

void func_L03_003A1050(void *arg0) {
    s32 temp_a0;
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s1 + 0x300);
    if (temp_a0 != 0) {
        func_003C2880(temp_a0);
        *(s32 *)((u8 *)temp_s1 + 0x300) = 0;
    }
    func_L03_0032FD50(arg0);
    func_L03_003A1158(arg0, 1);
}
/* localdecomp:end func_L03_003A1050 */

/* localdecomp:start func_L03_003A10A8 */
void *func_003C24B0(s32, s32);
void func_003C7C38(void *);
void func_L01_0044A7D0(u8 *);
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L03_0032FE10(void *);
void func_L03_003A1158(void *, s32);

void func_L03_003A10A8(void *arg0) {
    void *temp_s0;
    void *temp_v0;
    void *temp_v0_2;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_v0 = func_003C24B0(0x18FB, 0x80);
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
    func_L01_004AAC98(4, 4, arg0, 0x197C);
    func_L03_0032FE10(arg0);
    func_L03_003A1158(arg0, 2);
}
/* localdecomp:end func_L03_003A10A8 */

INCLUDE_ASM("asm/levels", func_L03_003A1158);

/* localdecomp:start func_L03_003A13E8 */

typedef struct {
    char p0[0x130];
    float x130, x134;
    char p1[0x28];
    float x160, x164, x168, x16C;
    char p2[0x18];
    int x188;
    char p3[0x78];
    char x204[0x4C];
    void *x250;
    char p4[0xC];
    float x260, x264;
} S_003A13E8;

typedef struct {
    char p0[0x10];
    float x10, x14;
    char p1[0xE0];
    char xF8[1];
    char p2[0x6F];
    S_003A13E8 *x68;
} S_003A13E8_o;

void func_L03_003A13E8(void *arg0, float arg1) {
    char buf[16];
    char *ps;
    char *o = arg0;
    S_003A13E8 *s = *(S_003A13E8 **)(o + 0x68);
    if (s->x188 & 0x10) {
        float d;
        ps = o + 0xF8;
        d = func_0038D160(s->x130 - *(float *)(o + 0x10), s->x134 - *(float *)(o + 0x14));
        func_L01_00448890(ps, s->x204, 0, d, s->x164, s->x168, s->x16C);
    }
    func_L03_0032FAF0(buf, &s->x130, s->x264, arg1);
    {
        float f = func_0038DB00(s->x260, s->x264);
        float r = func_L03_0032DC08(s->x250, arg0, buf, f * 0.15f);
        func_L01_0045A7A8(arg0, buf, r);
    }
    func_L03_0032D6B8(arg0);
}
/* localdecomp:end func_L03_003A13E8 */

INCLUDE_ASM("asm/levels", func_L03_003A14D0);

/* localdecomp:start func_L03_003A1600 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003A1600;
typedef struct { char pad[0x2F0]; V4_003A1600 pos; char pad2[0x304 - 0x300]; float t; } S_003A1600;
extern int D_L03_001D9BE0;
__asm__(".extern D_L03_001D9BE0, 16");
int func_0038DBD8(float, int, int);
void func_L01_004C70A8(void *, void *, void *, int, float);

void func_L03_003A1600(void *arg0) {
    S_003A1600 *s = *(S_003A1600 **)((char *)arg0 + 0x68);
    V4_003A1600 v;
    int c[2];
    float t, f, g;
    v = s->pos;
    v.z += 0.15f;
    t = s->t + 0.072000004f;
    s->t = t;
    if (2.0f < t) {
        s->t = t - 2.0f;
    }
    c[0] = 0x80802020;
    f = s->t;
    c[1] = func_0038DBD8(f < 1.0f ? f : 2.0f - f, 0x80A0A0A0, 0x80202080);
    func_L01_004C70A8(&v, &D_L03_001D9BE0, c, 1, 1.0f);
}
/* localdecomp:end func_L03_003A1600 */

/* localdecomp:start func_L03_003A16D8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003A16D8;
typedef struct { unsigned char pad0[0x308]; float t; unsigned char pad30C[6]; unsigned char a; } S_003A16D8;
typedef struct { float pad[10]; float f28; float pad2c; V4_003A16D8 pos; } L_003A16D8;

void func_L03_003A16D8(void *arg0) {
    S_003A16D8 *s = *(S_003A16D8 **)((char *)arg0 + 0x68);
    L_003A16D8 l;
    float t;
    func_0038D2D0(&l, 0.75f);
    l.pos = *(V4_003A16D8 *)((char *)arg0 + 0x10);
    l.f28 = -0.85f;
    l.pos.z += 0.85f;
    t = s->t + 0.096f;
    s->t = t;
    if (1.0f < t) {
        s->t = t - 1.0f;
    }
    func_003D9740(&l, 0x28, ((int)(s->a / 15.0f * 255.0f) << 24) | 0xFF4040, 5, 1, s->t);
}
/* localdecomp:end func_L03_003A16D8 */

INCLUDE_ASM("asm/levels", func_L03_003A17D8);

INCLUDE_ASM("asm/levels", func_L03_003A1A78);

/* localdecomp:start func_L03_003A1B70 */
typedef struct { char pad[0xC]; float f; } S_003A1B70;
extern float D_L03_001DF5B0;
__asm__(".extern D_L03_001DF5B0, 16");
extern float D_001DF2D8_sda;
__asm__(".extern D_001DF2D8_sda, 4");
void func_L01_005003D0(int, int);
void func_L03_003A1C60(void *, void *, void *);
void func_L01_004F50C8(void *, void *, int, int);
void func_L03_003A2B48(void);
void func_L01_004450F0(void *, int, int);

void func_L03_003A1B70(void *a, int b) {
    S_003A1B70 *p = *(S_003A1B70 **)((char *)a + 0x68);
    char buf[0x20];
    func_L01_005003D0(0x74, 1);
    if (b == 0) {
        func_L03_003A1C60(a, buf, buf + 0x10);
        func_L01_004F50C8(buf, buf + 0x10, 0x74, 1);
        func_L01_004450F0(a, 3, -1);
    } else if (b == 1) {
        D_L03_001DF5B0 = p->f;
        func_L03_003A1C60(a, buf, buf + 0x10);
        func_L01_004F50C8(buf, buf + 0x10, 0x74, 1);
        func_L03_003A2B48();
        D_001DF2D8_sda = 0.6f;
        func_L01_004450F0(a, 8, -1);
    }
}
/* localdecomp:end func_L03_003A1B70 */

/* localdecomp:start func_L03_003A1C60 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; u128_t v; u8 pad20[0xD8]; f32 fF8; } S_003A1C60;
typedef struct { f32 x, y, z, w; } V_003A1C60;
extern f32 func_0038DAB8(f32, f32);
void func_L03_003A1C60(void *a, void *b, void *c) {
    S_003A1C60 *s = a;
    V_003A1C60 *o = b;
    V_003A1C60 *q = c;
    qzero(q);
    q->z = func_0038DAB8(s->fF8, 3.14159274f);
    *(u128_t *)o = s->v;
    o->z += 0.2f;
}
/* localdecomp:end func_L03_003A1C60 */

/* localdecomp:start func_L03_003A1CD8 */
typedef struct { s32 x0; u8 pad4[0x20]; s32 x24; } S_003A1CD8a;
typedef struct { u8 pad0[0x35C]; s32 x35C; s32 x360; u8 pad364[0x2280]; u8 x25E4; u8 pad25E5[0x2A7]; s16 x288C; } S_003A1CD8b;
extern S_003A1CD8a D_L03_002E52F0;
extern u16 D_00143954[];
extern S_003A1CD8b D_001A4BE0;

s32 func_L03_003A1CD8(s32 arg0) {
    s32 r = 0;
    if ((D_L03_002E52F0.x0 == 0 && D_L03_002E52F0.x24 == -1) || D_00143954[0] == 0) {
        if (D_001A4BE0.x360 != 0 && D_001A4BE0.x35C == arg0 && D_001A4BE0.x25E4 == 0) {
            r = D_001A4BE0.x288C == 0;
        }
    }
    return r;
}
/* localdecomp:end func_L03_003A1CD8 */
