#include "common.h"

/* localdecomp:start func_L20_003D6F30 */
#include "vu0.h"

typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    u8 pad50[0x40];
} S_003D6F30;
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} S_1CFEC0_003D6F30;

extern vu0_v4 D_L20_001E2E80;
extern S_1CFEC0_003D6F30 D_001CFEC0_003D6F30[];

extern void func_003C2F58(void *, s32, void *);
extern void func_L20_003D7220(void *, s32, s32, f32, f32, f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_003A9440(s32 reg, long value);
extern void func_0038AF30(s32, s32, s32, s32, s32);

void func_L20_003D6F30(u8 *obj) {
    vu0_v4 p0;
    S_003D6F30 s;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 t;
    u8 *v = *(u8 **)(obj + 0x68);
    s32 color;

    func_003C2F58(obj, 3, &p0);
    func_L20_003D7220(&p0, 0x42, *(s32 *)(v + 0x2EC) * 5, 1.0f, 0.0f, 0.0f, 0.9f);
    a = p0;
    func_003C5180(&a, &b, 1);
    vec_sub_ba(&c, &D_L20_001E2E80, &a);
    func_0038CF68(&c, &c, 1.0f);
    func_0038CE20(&d, &b, 6.0f);
    vec_add_ab(&e, &a, &d);
    if (*(s32 *)(v + 0x2F0) != 0) {
        g = a;
        color = -1;
        if (*(s32 *)(v + 0x5E0) == 0) {
            color = 0xFF7C0030;
        } else if (*(s32 *)(v + 0x5E0) == 1) {
            color = 0xFF06065C;
        } else if (*(s32 *)(v + 0x5E0) == 2) {
            color = 0xFF007C30;
        }
        func_003D93B0(&s, 0xB, 0, 0x80);
        s.c[3] = color;
        s.c[2] = color;
        s.c[1] = color;
        s.c[0] = color;
        func_0038CE20(&t, &c, -0.1f);
        vec_add_ba(&g, &D_L20_001E2E80, &t);
        func_0038CE90(&f, &c, &b);
        func_0038CF68(&f, &f, 0.04f);
        func_0038CE90(&d, &f, &c);
        func_0038CF68(&d, &d, 0.04f);
        vec_add_ba(&e, &g, &d);
        vec_add_ab(&s.v[0], &e, &f);
        vec_sub_ab(&s.v[1], &e, &f);
        vec_sub_ab(&e, &g, &d);
        vec_add_ab(&s.v[2], &e, &f);
        vec_sub_ab(&s.v[3], &e, &f);
        func_003D2DA0(&s, 0, 0);
        if (*(s32 *)(v + 0x5E0) == 0) {
            color = 0x207C0030;
        } else if (*(s32 *)(v + 0x5E0) == 1) {
            color = 0x2006065C;
        } else if (*(s32 *)(v + 0x5E0) == 2) {
            color = 0x20007C30;
        }
        s.c[3] = color;
        s.c[2] = color;
        s.c[1] = color;
        s.c[0] = color;
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0_003D6F30->h152, 0, D_001CFEC0_003D6F30->h150, s.c[0]);
    }
}
/* localdecomp:end func_L20_003D6F30 */

/* localdecomp:start func_L20_003D7220 */
typedef struct { u8 pad[0x150]; s16 width,height; } Screen_0036DB78;
extern Screen_0036DB78 D_001CFEC0;
typedef struct { s32 a,b,buffer; } Buffer_0036DB78;
extern Buffer_0036DB78 D_001A1ED0[1];
extern s32 D_001D5520;
extern s32 D_L20_001DEC48;
__asm__(".extern D_L20_001DEC48, 4");
extern s32 D_L20_001DEC40;
__asm__(".extern D_L20_001DEC40, 4");
extern s32 D_L20_001DEC44;
__asm__(".extern D_L20_001DEC44, 4");
extern s32 D_L20_001DEC1C;
__asm__(".extern D_L20_001DEC1C, 4");
extern s32 D_L20_001DEC18;
__asm__(".extern D_L20_001DEC18, 4");
extern s32 D_L20_001DEC20;
__asm__(".extern D_L20_001DEC20, 4");
extern s32 D_L20_001DEC24;
__asm__(".extern D_L20_001DEC24, 4");
extern s32 D_L20_001DEC10;
__asm__(".extern D_L20_001DEC10, 4");
extern s32 D_L20_001DEC28;
__asm__(".extern D_L20_001DEC28, 4");
extern s32 D_L20_001DEC2C_003D7220;
__asm__(".extern D_L20_001DEC2C_003D7220, 4");
extern s32 D_L20_001DEC30_003D7220;
__asm__(".extern D_L20_001DEC30_003D7220, 4");
extern s32 D_L20_001DEC34_003D7220;
__asm__(".extern D_L20_001DEC34_003D7220, 4");
extern s32 D_L20_001DEC14;
__asm__(".extern D_L20_001DEC14, 4");
extern s32 D_L20_001DEC38;
__asm__(".extern D_L20_001DEC38, 4");
extern s32 D_L20_001DEC3C;
__asm__(".extern D_L20_001DEC3C, 4");
void func_L20_003D7220(void *pos, s32 tex, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    extern void func_L01_004C5E28(void *,s32,f32,f32,f32,f32);
    extern void func_003D1030(void);
    extern long func_00389598(s32);
    extern void func_0038B4D0(s32,s32,s32,s32,s32,s32,s32,s32,long,unsigned long);
    unsigned long texture;
    long color;
    func_L01_004C5E28(pos,tex,a,b,c,d);
    if (D_001D5520 != 0) {
        D_L20_001DEC48=-1;
        D_L20_001DEC40=0xEC;
        D_L20_001DEC44=0xF0;
    }
    func_003A9440(0x4E, (D_001A1ED0[0].buffer >> 13) | 0x01000000UL | 0x100000000UL);
    func_003A9440(0x42, (long)D_L20_001DEC18 | ((long)D_L20_001DEC1C<<2) | ((long)D_L20_001DEC20<<4) | ((long)D_L20_001DEC24<<6) | 0x8000000000UL);
    func_003D1030();
    texture=func_00389598(D_L20_001DEC10);
    color=(alpha<<24)|0x7F7F7F;
    func_0038B4D0(0,0,(s32)(D_001CFEC0.width*0.5f),(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_0038B4D0(D_001CFEC0.width,0,-(s32)(D_001CFEC0.width*0.5f),(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_0038B4D0(0,D_001CFEC0.height,(s32)(D_001CFEC0.width*0.5f),-(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_0038B4D0(D_001CFEC0.width,D_001CFEC0.height,-(s32)(D_001CFEC0.width*0.5f),-(s32)(D_001CFEC0.height*0.5f),0,0,255,255,color,texture);
    func_003A9440(0x42, (long)D_L20_001DEC18 | ((long)D_L20_001DEC1C<<2) | ((long)D_L20_001DEC20<<4) | ((long)D_L20_001DEC24<<6) | 0x8000000000UL);
    func_003A9440(0x42, (long)D_L20_001DEC28 | ((long)D_L20_001DEC2C_003D7220<<2) | ((long)D_L20_001DEC30_003D7220<<4) | ((long)D_L20_001DEC34_003D7220<<6) | 0x8000000000UL);
    func_0038B4D0(0,0,D_001CFEC0.width,D_001CFEC0.height,D_L20_001DEC38,D_L20_001DEC3C,D_L20_001DEC40,D_L20_001DEC44,D_L20_001DEC14,func_00389598(D_L20_001DEC48));
    func_003A9440(0x4E, 0x01000000UL | (D_001A1ED0[0].buffer >> 13));
}
/* localdecomp:end func_L20_003D7220 */

/* localdecomp:start func_L20_003D7558 */
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    f32 uv[8];
    unsigned long q[4];
} S_003D7558;

typedef struct {
    vu0_v4 r[4];
} M_003D7558;

typedef struct {
    s16 i[4];
} I_003D7558;

extern s32 D_L20_001DEC4C;
extern f32 D_L20_001DEC50;
extern f32 D_L20_001DEC54;
extern f32 D_L20_001DEC58;
extern s32 D_L20_001DEC5C;
__asm__(".extern D_L20_001DEC4C, 4");
__asm__(".extern D_L20_001DEC50, 4");
__asm__(".extern D_L20_001DEC54, 4");
__asm__(".extern D_L20_001DEC58, 4");
__asm__(".extern D_L20_001DEC5C, 4");
extern f32 D_L20_001E2E00[];
extern f32 D_L20_0026DF50[][3];
extern vu0_v4 D_L20_002AF3E0[];
extern unsigned long D_L20_002B0600[];
extern vu0_v4 D_L20_002B0F20[];
extern I_003D7558 D_L20_002B1520[];
extern u8 D_001A4EC0[];

extern long func_00389598(s32);
extern void func_0038C750(void);
extern void func_0038D028(void *, void *, void *);
extern void func_003D3A24(s32, void *, void *, void *, s32);

void func_L20_003D7558(u8 *obj) {
    S_003D7558 s;
    M_003D7558 m;
    vu0_v4 d;
    vu0_v4 up;
    vu0_v4 t;
    u32 colors[0x122];
    s32 k;
    s32 i;
    s32 j;
    f32 sa;
    f32 sb;

    s.q[1] = func_00389598(D_L20_001DEC4C);
    s.q[2] = 0xFF9000000260;
    s.q[3] = 0x8000000044;
    s.q[0] = 0;
    func_003A9440(0x47, 0x53001);
    m.r[3] = *(vu0_v4 *)(obj + 0x10);
    m.r[3].w = 1.0f;
    m.r[3].z += 2.0f;
    vec_sub_ab(&d, D_L20_001E2E00, &m.r[3]);
    func_0038CF68(&m.r[0], &d, 1.0f);
    func_0038CE20(&up, D_001A4EC0, -1.0f);
    func_0038CE90(&m.r[1], &m.r[0], &up);
    func_0038CF68(&m.r[1], &m.r[1], 1.0f);
    func_0038CE90(&m.r[2], &m.r[1], &m.r[0]);
    func_0038CE20(&m.r[0], &m.r[0], D_L20_001DEC50);
    func_0038CE20(&m.r[1], &m.r[1], D_L20_001DEC50);
    func_0038CE20(&m.r[2], &m.r[2], D_L20_001DEC50);
    k = D_L20_001DEC5C | 0xA06565;
    s.c[3] = k;
    s.c[2] = k;
    s.c[1] = k;
    s.c[0] = k;
    func_003A9440(6, func_00389598(D_L20_001DEC4C));
    func_003A9440(0x42, 0x8000000044);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260);
    func_003A9440(0x4A, 0);
    func_0038C750();
    for (j = 0; j < 0x122; j++) {
        func_0038D028(&t, &D_L20_002AF3E0[j], &m);
        D_L20_0026DF50[j][0] = t.x;
        D_L20_0026DF50[j][1] = t.y;
        D_L20_0026DF50[j][2] = t.z;
        colors[j] = s.c[0];
    }
    func_003D3A24(0x94, D_L20_0026DF50, colors, D_L20_002B0600, 1);
    func_003D3A24(0x6D, D_L20_0026DF50[0x92], &colors[0x92], &D_L20_002B0600[0x92], 1);
    func_003D3A24(0x24, D_L20_0026DF50[0xFE], &colors[0xFE], &D_L20_002B0600[0xFE], 1);
    s.q[1] = func_00389598(0xB);
    s.q[3] = 0x8000000048;
    sa = D_L20_001DEC54;
    sb = sa * D_L20_001DEC58;
    s.c[1] = 0x40A06565;
    s.c[0] = 0x40A06565;
    s.c[3] = 0;
    s.c[2] = 0;
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 4; j++) {
            s16 idx = D_L20_002B1520[i].i[j];
            if (j >= 2) {
                func_0038CE20(&s.v[j], &D_L20_002B0F20[idx], sb);
            } else {
                func_0038CE20(&s.v[j], &D_L20_002B0F20[idx], sa);
            }
        }
        s.uv[0] = 0.5f;
        s.uv[1] = 0.5f;
        s.uv[2] = 0.5f;
        s.uv[3] = 0.5f;
        s.uv[4] = 0.5f;
        s.uv[5] = 1.0f;
        s.uv[6] = 0.5f;
        s.uv[7] = 1.0f;
        func_003D2DA0(&s, &m, 0);
    }
}
/* localdecomp:end func_L20_003D7558 */

/* localdecomp:start func_L20_003D7950 */
typedef struct { u8 pad[0xF8]; u8 *fF8; } S_220258_7950;
extern S_220258_7950 D_L20_00220258;
extern s32 D_L20_001E2640[] __attribute__((section(".sdata")));
extern vu0_v4 D_L20_001E2600[] __attribute__((section(".sdata")));
extern vu0_v4 D_L20_002A2940[][20];
extern f32 D_L20_001DEBF8_003D7950;
extern s32 D_L20_001DEBFC;
extern s32 D_L20_001DEC00;
extern s32 D_L20_001DEC04;
extern f32 D_L20_001DEC08;
extern f32 D_L20_001DEC0C;
__asm__(".extern D_L20_001DEBF8_003D7950, 4");
__asm__(".extern D_L20_001DEBFC, 4");
__asm__(".extern D_L20_001DEC00, 4");
__asm__(".extern D_L20_001DEC04, 4");
__asm__(".extern D_L20_001DEC08, 4");
__asm__(".extern D_L20_001DEC0C, 4");
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_003C4C18(void *, f32);
extern f32 func_0038CEA8(void *);
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    s32 color;
    u8 pad8[4];
    f32 scale;
} Particle_7950;
extern Particle_7950 *func_L01_0046CA28(void *, s32, s32, s32);
extern void func_L20_003D7CE0(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L20_003D7950(u8 *obj) {
    vu0_v4 trail[20];
    vu0_v4 position;
    vu0_v4 delta;
    s32 i;
    s32 j;
    s32 last;
    f32 angle = 6.0f;
    f32 length;
    f32 limit;
    Particle_7950 *particle;
    vu0_v4 *end;
    position = *(vu0_v4 *)(obj + 0x10);
    position.z += 2.0f;
    for (i = 0; i < 4; i++) {
        D_L20_001E2640[i]++;
        if (D_L20_001E2640[i] >= 20) {
            D_L20_001E2640[i] = 20;
        }
        last = D_L20_001E2640[i] - 1;
        j = last;
        for (; j > 0; j--) {
            D_L20_002A2940[i][j] = D_L20_002A2940[i][j - 1];
            vec_add_ba(&trail[last - j], &position, &D_L20_002A2940[i][j]);
            trail[last - j].w = 0.05f;
        }
        func_003C4840(&delta, &D_L20_001E2600[i], angle * 0.017453292f);
        func_0038D850(&D_L20_002A2940[i][0], &D_L20_002A2940[i][0], &delta);
        func_003C4C18(&D_L20_002A2940[i][0], 0.025f);
        length = func_0038CEA8(&D_L20_002A2940[i][0]);
        limit = D_L20_001DEBF8_003D7950 * 1.1f;
        if (limit < length) {
            func_0038CE20(&D_L20_002A2940[i][0], &D_L20_002A2940[i][0], limit / length);
        } else {
            limit = D_L20_001DEBF8_003D7950 * 0.9f;
            if (length < limit) {
                func_0038CE20(&D_L20_002A2940[i][0], &D_L20_002A2940[i][0], limit / length);
            }
        }
        vec_add_ab(&trail[last], &position, &D_L20_002A2940[i][0]);
        trail[last].w = 0.05f;
        end = (vu0_v4 *)((u8 *)trail + ((D_L20_001E2640[i] - 1) << 4));
        particle = func_L01_0046CA28(end, 2, 0, 1);
        if (particle != 0) {
            particle->color = D_L20_001DEBFC | 0xA06565;
            particle->scale = D_L20_001DEC08 * 210000.0f;
            particle->b2 = D_L20_00220258.fF8[1];
        }
        particle = func_L01_0046CA28(end, 2, 0, 1);
        if (particle != 0) {
            particle->color = 0x407F7F7F;
            particle->scale = D_L20_001DEC08 * 0.15f * 210000.0f;
        }
        func_L20_003D7CE0(trail, 20, 15, 15, D_L20_001DEC00,
            D_L20_001DEC00 & 0xFFFFFF, D_L20_001DEC04 | 0xA06565, D_L20_001DEC04,
            0, D_L20_001E2640[i] - 1, D_L20_001E2640[i], 0.02f, 0.07f, D_L20_001DEC0C);
    }
}
/* localdecomp:end func_L20_003D7950 */
