#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0039E470);

INCLUDE_ASM("asm/levels", func_L03_0039E748);

INCLUDE_ASM("asm/levels", func_L03_0039E8F0);

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

INCLUDE_ASM("asm/levels", func_L03_0039ECA0);

INCLUDE_ASM("asm/levels", func_L03_0039EE10);

INCLUDE_ASM("asm/levels", func_L03_0039EEE8);

INCLUDE_ASM("asm/levels", func_L03_0039F028);

INCLUDE_ASM("asm/levels", func_L03_0039F2C8);

INCLUDE_ASM("asm/levels", func_L03_0039F3C0);

INCLUDE_ASM("asm/levels", func_L03_0039F960);

INCLUDE_ASM("asm/levels", func_L03_0039FB18);

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

INCLUDE_ASM("asm/levels", func_L03_003A04D0);

INCLUDE_ASM("asm/levels", func_L03_003A05D0);

INCLUDE_ASM("asm/levels", func_L03_003A0BF8);

INCLUDE_ASM("asm/levels", func_L03_003A0DA0);

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

INCLUDE_ASM("asm/levels", func_L03_003A16D8);

INCLUDE_ASM("asm/levels", func_L03_003A17D8);

INCLUDE_ASM("asm/levels", func_L03_003A1A78);

INCLUDE_ASM("asm/levels", func_L03_003A1B70);

INCLUDE_ASM("asm/levels", func_L03_003A1C60);

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
