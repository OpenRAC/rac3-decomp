#include "common.h"
#include "vu0.h"
f32 func_0038D160(f32, f32);
void func_0038D2D0(void *, float);
f32 func_0038DB00(f32, f32);
void func_003D9740(void *, int, int, int, int, float);
f32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
void func_L01_0045A7A8(void *, void *, f32);
void func_L03_0032D6B8(void *);
f32 func_L03_0032DC08(s32, void *, void *, f32);
void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
void func_L03_003A16D8(void *);

typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0x47]; s32 *p68; } S_003A17D8;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } G_003A17D8;

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

/* localdecomp:start func_L03_003A14D0 */
#include "vu0.h"
typedef struct { u8 pad0[0x130]; vu0_v4 v130; u8 pad140[0x1C0]; void *p300; } P_003A14D0;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C4098(void *, void *, void *, f32);
void func_L03_003A14D0(void *a, void *out, void *opt, s32 flag) {
    P_003A14D0 *p = *(P_003A14D0 **)((u8 *)a + 0x68);
    vu0_v4 v0;
    vu0_v4 d;
    vu0_v4 pos;
    vu0_v4 t;
    f32 len;
    u8 f = flag;
    pos = p->v130;
    func_003C2F58(p->p300, 0, &v0);
    if (opt != 0) *(vu0_v4 *)opt = v0;
    vec_sub_ab(&d, &pos, &v0);
    d.z = 0;
    len = func_0038CEA8(&d);
    if (len > 6.0f) len = 6.0f;
    else if (len < 4.0f) len = 4.0f;
    func_0038CF68(&pos, &d, len);
    vec_add_ab(&pos, &v0, &pos);
    pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
    if (f != 0) {
        *(vu0_v4 *)out = pos;
    } else {
        t = *(vu0_v4 *)out;
        func_003C4098(out, &pos, &t, 0.90400004f);
    }
}
/* localdecomp:end func_L03_003A14D0 */

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

/* localdecomp:start func_L03_003A17D8 */
extern u8 D_001A4C60[];
extern u8 D_0014271D[];
extern s32 D_00142C14[];
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern f32 D_L03_001DF2D0;
__asm__(".extern D_L03_001DF2D0, 16");
extern f32 D_L03_001DF2D8;
__asm__(".extern D_L03_001DF2D8, 16");
extern s32 D_L03_002D09B0[];
__asm__(".extern D_L03_002D09B0, 16");
extern G_003A17D8 *D_001D52FC_sda_003A17D8;
__asm__(".extern D_001D52FC_sda_003A17D8, 4");
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_005003D0(s32, s32);
extern void func_L03_0032CED0(void *);
extern s32 func_L03_003A1CD8();
extern void func_L03_003A1A78();
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_003A17D8(S_003A17D8 *a) {
    s32 *p;
    u8 *o;
    func_L03_003A1A78(a);
    p = a->p68;
    if (D_0014271D[0] != 0 && !(D_00142C14[2] & 0x20000000)
        && func_00382380(D_001A4C60, p[1], 0) != 0) {
        o = D_L03_001DF99C + (p[2] << 8);
        func_L01_00456230(o, 1);
        (*(void (**)(void *))(o + 0x64))(o);
    }
    switch (a->f20) {
    case 1:
        if (func_L03_003A1CD8(a) != 0) {
            func_L01_004450F0(a, 2, -1);
        }
        break;
    case 2:
        func_L01_00452560(0, 12, 0xA24, 1, 0, 0, 0);
        if (D_L03_002D09B0[0] == 12 && (D_001D52FC_sda_003A17D8->f1A4 & 0x10)) {
            func_L01_004450F0(a, 5, -1);
        } else if (func_L03_003A1CD8(a) == 0) {
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 3:
        D_L03_001DF2D0 = D_L03_001DF2D0 - 0.120000005f;
        if (D_L03_001DF2D0 < 0.0f) {
            D_L03_001DF2D0 = 0.0f;
            func_L01_005003D0(0, 1);
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 5:
        D_L03_001DF2D0 = D_L03_001DF2D0 + 0.120000005f;
        if (D_L03_001DF2D0 >= 1.0f) {
            D_L03_001DF2D0 = 1.0f;
            func_L01_004450F0(a, 6, -1);
        }
        break;
    case 6:
        func_L03_0032CED0(D_L03_001DF99C + (p[0] << 8));
        func_L01_004450F0(a, 1, -1);
        break;
    case 7:
        D_L03_001DF2D0 = D_L03_001DF2D0 - 0.120000005f;
        if (D_L03_001DF2D0 <= 0.0f) {
            func_L01_005003D0(0, 1);
            D_L03_001DF2D0 = 0.0f;
            func_L01_004450F0(a, 1, -1);
        }
        break;
    case 8:
        D_L03_001DF2D8 = D_L03_001DF2D8 - 0.036000002f;
        if (D_L03_001DF2D8 <= 0.0f) {
            func_L01_005003D0(0, 1);
            D_L03_001DF2D8 = 0.0f;
            func_L01_004450F0(a, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_003A17D8 */

/* localdecomp:start func_L03_003A1A78 */
extern u8 D_00142CA0[];
extern u8 D_00142D40[];
__asm__(".extern D_00142D40, 16");
__asm__(".extern D_00142CA0, 16");
__asm__(".extern D_00142765, 16");
extern u8 D_00142765[];
extern s32 D_L03_00235A00[];
extern f32 D_L03_001DF5B0;
typedef struct { u8 pad[0x20]; u8 f20; u8 pad2[0x47]; f32 *p68; } S_003A1A78;
void func_0039EF28(void);
void func_L03_0040F9E8(s32);
void func_L03_004F54E0(s32);
s32 func_L01_0044CD60(s32);
void func_L01_004450F0(void *, s32, s32);

void func_L03_003A1A78(S_003A1A78 *a) {
    u8 *t;
    if (a->f20 == 0) {
        a->p68[3] = D_L03_001DF5B0;
        t = D_00142CA0;
        if ((t[0xB] != 0 || t[0x14] != 0) && D_00142765[0] == 0) {
            t[0xB] = 0;
            D_00142D40[0xB] = 0;
            func_0039EF28();
            func_L03_0040F9E8(0xB);
            func_L03_004F54E0(0xB);
            t[0x14] = 0;
            D_00142D40[0x14] = 0;
            func_0039EF28();
            func_L03_0040F9E8(0x14);
            func_L03_004F54E0(0x14);
            func_L01_0044CD60(9);
            if (D_L03_00235A00[0] != 0) {
                func_L01_004450F0(a, 5, -1);
                return;
            }
        }
        func_L01_004450F0(a, 1, -1);
    }
}
/* localdecomp:end func_L03_003A1A78 */

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
