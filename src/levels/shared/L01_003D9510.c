#include "common.h"
#include "vu0.h"

typedef int s128_3D8F20 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L01_003D9510 */
extern s32 D_L01_001D6740;
extern s16 D_001A4F48[];

s32 func_L01_003D9510(void) {
    s32 r = 0;
    if (D_L01_001D6740 != 0 || D_001A4F48[0] != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_003D9510 */

/* localdecomp:start func_L01_003D9540 */
extern s32 D_L01_001D673C_003D9540;
s32 func_L01_003D9540(void) {
    return D_L01_001D673C_003D9540;
}
/* localdecomp:end func_L01_003D9540 */

INCLUDE_ASM("asm/levels", func_L01_003D9548);

INCLUDE_ASM("asm/levels", func_L01_003D9FD0);

INCLUDE_ASM("asm/levels", func_L01_003DA3F0);

/* localdecomp:start func_L01_003DA6E8 */
extern u8 *D_L01_00221098[];
void func_L01_003DA6E8(u8 *obj) {
    extern s32 func_00382498(s32,s32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_003C2F58(void *,s32,s128_3D8F20 *);
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern u8 *func_L01_004713C8(void *,void *,s32,s32,s32,s32,s32,s32,f32,f32,f32);
    extern u8 *func_L01_004669B0(void *,s32,void *,s32,s32,f32,f32,f32,f32);
    extern void func_L01_003DB200(void *,void *);
    extern s32 func_0013D3E0(void);
    extern void func_L01_00466F50(void *,void *,s32,f32,f32);
    union {s128_3D8F20 q; f32 v[4];} pos;
    s128_3D8F20 vel,point;
    s32 i,color,kind;
    f32 scale;
    u8 *particle;
    for(i=0;i<8;i++) {
        u8 *particle;
        func_003C2F58(obj,func_00382498(1,13),&pos.q);
        pos.v[0]+=func_003824E0(-0.02f,0.02f);
        pos.v[1]+=func_003824E0(-0.02f,0.02f);
        pos.v[2]+=func_003824E0(-0.02f,0.02f);
        func_L01_004C7D98(obj+0x10,&vel);
        func_0038CE20(&vel,&vel,func_003824E0(0.4f,1.0f)*0.020000001415610313f);
        if(func_00382468(4)) color=func_00382498(64,100)|0x5F404000;
        else color=(func_00382498(150,100)<<16)|0x5F002C2C;
        particle=func_L01_004713C8(&pos,&vel,(func_00382498(10,15)*5+2)/6,color,1,79,0,0,58800.0f,27299.998046875f,0.0f);
        if(particle)particle[2]=D_L01_00221098[0x5B][0];
    }
    func_L01_004C7D98(obj+0x10,&vel);
    func_0038CE20(&vel,&vel,func_003824E0(0.4f,1.0f)*0.020000001415610313f);
    pos.v[0]+=func_003824E0(-0.02f,0.02f);
    pos.v[1]+=func_003824E0(-0.02f,0.02f);
    pos.v[2]+=func_003824E0(-0.02f,0.02f);
    kind=func_00382468(5)+1;
    scale=func_003824E0(0.25f,0.4f)*210000.0f;
    color=func_00382498(64,80)|0x404000;
    particle=func_L01_004669B0(&pos,kind,&vel,color,0,0.0f,0.99f,0.995f,scale);
    if(particle) {
        particle[3]=func_00382468(2)?68:72;
        *(s16 *)(particle+0xA)=2;
    }
    if(obj[0x20]==2) {
        func_003C2F58(obj,0,&point);
        func_L01_003DB200(obj,&point);
    }
    func_003C2F58(obj,17,&point);
    func_0038CF68(&vel,&vel,func_003824E0(0.0025f,0.01f));
    if(func_0013D3E0()%15==0)func_L01_00466F50(&point,&vel,0,-1.0f,0.0f);
}
/* localdecomp:end func_L01_003DA6E8 */

/* localdecomp:start func_L01_003DAAE0 */
extern void func_003C2F58(void *, s32, s128_3D8F20 *);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L01_003DAAE0(void *m) {
    s128_3D8F20 v;
    func_003C2F58(m, 14, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
    func_003C2F58(m, 15, &v);
    func_003D9508(&v, 11, 0x40202080, 1, func_003824E0(0.09f, 0.16f), 0.08f, 0.0f);
}
/* localdecomp:end func_L01_003DAAE0 */

INCLUDE_ASM("asm/levels", func_L01_003DABC8);

INCLUDE_ASM("asm/levels", func_L01_003DB200);

/* localdecomp:start func_L01_003DB3F8 */
extern u8 D_L01_002A2E40_003DB3F8[];

void func_L01_003DB3F8(void) {
    s32 i;
    u8 *h = D_L01_002A2E40_003DB3F8;

    for (i = 0; i < 64; i++) {
        *(s32 *)(h + i * 0x30 + 0x20) = 0;
    }
}
/* localdecomp:end func_L01_003DB3F8 */

/* localdecomp:start func_L01_003DB428 */
typedef struct {
    u128_t position;           /* 0x00 */
    u8 pad_10[0x20 - 0x10];
    s32 active;                /* 0x20 */
    u8 pad_24[0x28 - 0x24];
    f32 phase;                 /* 0x28 */
    u8 pad_2C[0x30 - 0x2C];
} Duck_3DB428;

/* The V5 ducks in flight, 64 slots */
extern Duck_3DB428 D_L01_002A2E40[];
extern f32 func_0038D0B0(f32 angle);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_003DB768(void *position, s32 texture, s32 blend, f32 size, f32 a, f32 b, f32 c);

/* qwack_duck_v5_star_draw: draws each V5 Qwack-O-Ray duck in flight: two stars of texture 57
   turning both ways, pulsing with the duck's phase, and a 0x3B glow */
void func_L01_003DB428(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        if (D_L01_002A2E40[i].active != 0) {
            Duck_3DB428 *duck = &D_L01_002A2E40[i];

            func_003D9508(duck, 0x39, 0x207F7F8F, 1, func_0038D0B0(duck->phase) * 0.25f + 0.5f, -0.1f, duck->phase);
            func_003D9508(duck, 0x39, 0x207F7F8F, 1, func_0038D0B0(duck->phase) * 0.25f + 0.5f, -0.1f, -duck->phase);
            func_L01_003DB768(duck, 0x3B, 1, (func_0038D0B0(duck->phase) * 0.7f + 0.75f) * 0.1f, 0.2f, 0.0f, 0.005f);
        }
    }
}
/* localdecomp:end func_L01_003DB428 */

/* localdecomp:start func_L01_003DB588 */
extern Duck_3DB428 D_L01_002A2E40[64];
void func_L01_003DB588(u8 *obj) {
    extern void func_L01_004C7D98(void *,void *);
    extern void func_0038D890(void *,void *,void *,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_L01_003DB428(void);
    extern void func_L01_00404A10_003DB588(void (*)(void),void *);
    vu0_v4 base;
    vu0_v4 temp;
    Duck_3DB428 *p;
    Duck_3DB428 *end;
    u8 *dir;
    f32 c;
    s32 address;
    func_L01_004C7D98(obj+0x10,&base);
    address=(s32)D_L01_002A2E40;
    dir=(u8 *)(address+0x10);
    p=(Duck_3DB428 *)address;
    end=(Duck_3DB428 *)((u8 *)p+0xC00);
    do {
        if (p->active) {
            func_0038D890(&temp,dir,&base,p->phase);
            vec_add_ab(p,&temp,obj+0x10);
            p->phase=func_0038DAB8(p->phase,*(f32 *)((u8 *)p+0x24));
            c=func_0038D0B0(p->phase);
            c*=func_003824E0(0.01f,0.015f);
            *(f32 *)((u8 *)p+8)+=c;
        }
        p++;
        dir+=0x30;
    } while ((s32)p<(s32)end);
    func_L01_00404A10_003DB588(func_L01_003DB428,obj);
}
/* localdecomp:end func_L01_003DB588 */

/* localdecomp:start func_L01_003DB680 */
void func_L01_003DB680(void) {
    extern f32 func_003824E0(f32, f32);
    Duck_3DB428 *p = D_L01_002A2E40;
    Duck_3DB428 *end = (Duck_3DB428 *)((u8 *)p + 0xC00);
    do {
        if (!p->active) {
            p->active = 1;
            *(f32 *)((u8 *)p + 0x10) = func_003824E0(-0.65f, 0.65f);
            *(f32 *)((u8 *)p + 0x14) = func_003824E0(-0.65f, 0.65f);
            *(f32 *)((u8 *)p + 0x18) = func_003824E0(0.3f, 1.0f);
            *(f32 *)((u8 *)p + 0x1C) = 1.0f;
            *(f32 *)((u8 *)p + 0x24) = func_003824E0(0.10471975803375244f, 0.19198623299598694f);
            break;
        }
        p++;
    } while ((s32)p < (s32)end);
}
/* localdecomp:end func_L01_003DB680 */

/* localdecomp:start func_L01_003DB768 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    u8 pad70[0x18]; unsigned long tag;
} Draw_003DB768;
typedef struct {
    Draw_003DB768 draw;
    vu0_v4 basis[3]; vu0_v4 pos; vu0_v4 delta; vu0_v4 matrix[3];
} Work_003DB768;
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L01_001D7C50[];
void func_L01_003DB768(void *position, s32 texture, s32 blend, f32 size, f32 offset, f32 angle, f32 jitter) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003A9440(s32, unsigned long);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_00389478(void *, f32 *, f32 *);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    Work_003DB768 w;
    s32 i;
    func_003D93B0(&w.draw, texture, 1, 0x80);
    w.draw.tag = 0x800000004A;
    w.draw.color[3] = 0x80808080;
    w.draw.color[2] = 0x80808080;
    w.draw.color[1] = 0x80808080;
    w.draw.color[0] = 0x80808080;
    *(u128_t *)&w.pos = *(u128_t *)position;
    w.draw.uv[0][0] = 0; w.draw.uv[0][1] = 0;
    w.draw.uv[1][0] = 0; w.draw.uv[1][1] = 1;
    w.draw.uv[2][0] = 1; w.draw.uv[2][1] = 0;
    w.draw.uv[3][0] = 1; w.draw.uv[3][1] = 1;
    vec_sub_ab(&w.basis[0], &D_L01_001E29C0, &w.pos);
    func_0038CF68(&w.basis[0], &w.basis[0], 1.0f);
    func_0038CE90(&w.basis[1], &w.basis[0], &D_001A4EC0);
    func_0038CF68(&w.basis[1], &w.basis[1], 1.0f);
    func_0038CE90(&w.basis[2], &w.basis[1], &w.basis[0]);
    if (angle != 0.0f) {
        *(u128_t *)&w.delta = 0;
        w.delta.x = angle;
        func_0038D308(w.matrix, &w.delta);
        func_0038D5F0(w.basis, w.basis, w.matrix);
    }
    func_0038CE20(&w.delta, w.basis, offset);
    vec_add_ab(&w.pos, &w.pos, &w.delta);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&w.draw.v[i], &D_L01_001D7C50[i], size);
        func_0038D028(&w.draw.v[i], &w.draw.v[i], w.basis);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&w.draw, 0, 0);
    if (blend) {
        s32 k;
        s32 j;
        *(u128_t *)&w.matrix[0] = *(u128_t *)&w.draw.v[0];
        for (k = 1; k < 4; k++) vec_add_ba(&w.matrix[0], &w.matrix[0], &w.draw.v[k]);
        func_0038CE20(&w.matrix[0], &w.matrix[0], 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ba(&w.matrix[1], &w.draw.v[j], &w.matrix[0]);
            func_0038CE20(&w.matrix[1], &w.matrix[1], 2.0f);
            vec_add_ab(&w.matrix[1], &w.matrix[0], &w.matrix[1]);
            func_00389478(&w.matrix[1], &w.draw.uv[j][0], &w.draw.uv[j][1]);
            if (!func_00382468(1)) {
                w.draw.uv[j][0] += func_003824E0(-jitter, jitter);
                w.draw.uv[j][1] += func_003824E0(-jitter, jitter);
            }
            if (w.draw.uv[j][0] > 1.0f) w.draw.uv[j][0] = 1.0f;
            else if (w.draw.uv[j][0] < 0.0f) w.draw.uv[j][0] = 0.0f;
            if (w.draw.uv[j][1] > 1.0f) w.draw.uv[j][1] = 1.0f;
            else if (w.draw.uv[j][1] < 0.0f) w.draw.uv[j][1] = 0.0f;
        }
    } else {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_00389478(&w.draw.v[j], &w.draw.uv[j][0], &w.draw.uv[j][1]);
            if (!func_00382468(1)) {
                w.draw.uv[j][0] += func_003824E0(-jitter, jitter);
                w.draw.uv[j][1] += func_003824E0(-jitter, jitter);
            }
            if (w.draw.uv[j][0] > 1.0f) w.draw.uv[j][0] = 1.0f;
            else if (w.draw.uv[j][0] < 0.0f) w.draw.uv[j][0] = 0.0f;
            if (w.draw.uv[j][1] > 1.0f) w.draw.uv[j][1] = 1.0f;
            else if (w.draw.uv[j][1] < 0.0f) w.draw.uv[j][1] = 0.0f;
        }
    }
    func_003D93B0(&w.draw, -1, 6, 0x80);
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&w.draw, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L01_003DB768 */

/* localdecomp:start func_L01_003DBC60 */
extern u8 D_L01_001DF538[8];
__asm__(".extern D_L01_001DF538, 8");

u8 *func_L01_003DBC60(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 4;
        return D_L01_001DF538;
    }
    return 0;
}
/* localdecomp:end func_L01_003DBC60 */

INCLUDE_ASM("asm/levels", func_L01_003DBC80);

/* localdecomp:start func_L01_003DC268 */
typedef struct {
    u128_t direction;
    f32 life;
    s32 ticks;
    s32 flag;
    s32 state;
    f32 length;
    s32 lead;
    s32 target;
} Vars_003DC268;
typedef struct {
    u8 pad0[16];
    u128_t position;
    u8 pad20[4];
    u8 *cls;
    u8 pad28[4];
    f32 scale;
    u8 opacity;
    u8 mode;
    u16 flags;
    u8 pad34[0x34];
    Vars_003DC268 *vars;
    u8 pad6C[0x4C];
    void *parent;
    u8 padBC[4];
    u8 matrix[0x30];
    f32 rotation[4];
} Obj_003DC268;
extern s32 D_L01_001DF4F8;
extern s32 D_L01_001DF4FC;
extern s32 D_L01_001DF528;
extern s32 D_L01_001DF52C;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DF4F8, 4");
__asm__(".extern D_L01_001DF4FC, 4");
__asm__(".extern D_L01_001DF528, 4");
__asm__(".extern D_L01_001DF52C, 4");
Obj_003DC268 *func_L01_003DC268(void *parent, s32 flag, u128_t *pos, f32 *dir, f32 life) {
    extern Obj_003DC268 *func_003C24B0(s32, s32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038D308(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_003C7C38(void *);
    Obj_003DC268 *obj;
    Vars_003DC268 *v;
    s32 end;
    s32 now;
    obj = func_003C24B0(7556, 128);
    if (obj) {
        v = obj->vars;
        obj->parent = parent;
        v->flag = flag;
        obj->opacity = 255;
        obj->flags = 128;
        obj->mode = 1;
        obj->scale = *(f32 *)(obj->cls + 36) * 0.75f;
        obj->position = *pos;
        obj->rotation[1] = -func_0038D160(func_0038CED8(dir), dir[2]);
        obj->rotation[2] = func_0038D160(dir[0], dir[1]);
        func_0038D308(obj->matrix, obj->rotation);
        v->direction = *(u128_t *)dir;
        v->length = func_0038CEA8(dir);
        v->life = life;
        if (v->flag) v->ticks = D_L01_001DF4F8 * 2;
        else v->ticks = func_00382498(D_L01_001DF4FC, D_L01_001DF4F8);
        now = D_L01_001DFB40;
        v->target = -1;
        v->state = 0;
        end = now + D_L01_001DF52C;
        if (end < D_L01_001DF528) D_L01_001DF528 = -1;
        if (D_L01_001DF528 < now) {
            v->lead = 1;
            D_L01_001DF528 = end;
        } else v->lead = 0;
        func_L01_004450F0(obj, 1, -1);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003DC268 */

/* localdecomp:start func_L01_003DC400 */
#include "vu0.h"
extern f32 D_L01_001DF518;
extern s32 D_001A71A0[];
__asm__(".extern D_L01_001DF518, 4");
void func_L01_003DC400(u8 *obj, u8 *hit, void *point) {
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004669B0(void *, s32, void *, s32, s32, f32, f32, f32, f32);
    extern void func_L01_004668A0(void *, void *, s32, s32, s32, f32);
    vu0_v4 old, velocity, pos, delta;
    s32 shade, color, choice, rgb, blue, low, high;
    f32 length;
    f32 size;
    *(u128_t *)&old = *(u128_t *)point;
    *(u128_t *)&pos = *(u128_t *)(obj + 0x10);
    func_0038CE20(&pos, obj + 0xC0, -1.2f);
    vec_add_ab(&pos, &pos, obj + 0x10);
    length = func_0038CEA8(hit);
    func_0038CE20(&velocity, obj + 0xC0, length * D_L01_001DF518);
    shade = func_00382498(32, 64);
    { s32 red = shade + 8;
    s32 green = shade << 8;
    green |= 0x7F000000;
    red <<= 16;
    red |= green;
    color = red | shade; }
    choice = func_00382498(0, 2) - 1;
    func_L01_004669B0(&pos, choice, &velocity, color, 0, 0.25f, 0.8f, 1.01f, func_003824E0(1.5f, 2.0f) * 210000.0f);
    vec_sub_ba(&delta, obj + 0x10, &old);
    func_0038CE20(&delta, &delta, 0.5f);
    vec_add_ab(&pos, &pos, &delta);
    shade = func_00382498(64, 128);
    low = (shade << 8) | 0x40000000;
    rgb = (shade << 16) | low;
    color = rgb | shade;
    size = func_003824E0(2.0f, 2.5f) * 210000.0f;
    func_L01_004668A0(&pos, &velocity, color, 0x101010, (func_00382498(25, 30) * 5 + 2) / 6, size);
    if (*(s32 *)(hit + 0x18) != 0 && *(s32 *)(hit + 0x18) == D_001A71A0[0]) {
        color = rgb | (shade << 1);
        size = func_003824E0(2.5f, 3.0f) * 210000.0f;
        func_L01_004668A0(&pos, &velocity, color, 0x101010, (func_00382498(25, 30) * 5 + 2) / 6, size);
    }
}
/* localdecomp:end func_L01_003DC400 */

INCLUDE_ASM("asm/levels", func_L01_003DC690);

INCLUDE_ASM("asm/levels", func_L01_003DC780);

INCLUDE_ASM("asm/levels", func_L01_003DCAA0);

LINKER_REMNANT("asm/levels", func_L01_003DD0F0);

INCLUDE_ASM("asm/levels", func_L01_003DD0F8);

/* localdecomp:start func_L01_003DD9C8 */
#include "vu0.h"
extern vu0_v4 D_L01_001E29C0;
extern u8 D_00142657[];
typedef struct { u8 pad[0x6C]; f32 scale; u8 pad70[0x80]; } Row_003DD9C8;
extern Row_003DD9C8 D_L01_002C5600[];
extern f32 D_L01_001D66B0;
void func_L01_003DD9C8(u8 *owner, f32 *origin) {
    extern f32 func_0038D160(f32, f32);
    extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    extern void func_L01_00470C78(void *, s32, s32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
    vu0_v4 delta;
    f32 velocity[4], point[4];
    f32 heading, speed, pitch, angle;
    Row_003DD9C8 *row;
    f32 *v, *p;
    s32 spin, i;
    vec_sub_ab(&delta, &D_L01_001E29C0, origin);
    heading = func_0038D160(delta.x, delta.y);
    row = &D_L01_002C5600[D_00142657[0]];
    func_L01_00446780(owner, origin, 0x08110000, 1.25f, row->scale, 1.0f, 0, 1, 0);
    p = point;
    v = velocity;
    for (i = 0; i < 4; i++) {
        speed = func_003824E0(0.5f, 1.0f);
        spin = (s32)func_L01_00443A18(1.0f, 2.0f);
        func_003824E0(0.05f, 0.2f);
        {
            f32 units = 210000.0f;
            pitch = func_003824E0(0.0f, 1.3962633609771729f);
            angle = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962633609771729f));
            func_00382760(v, speed * 0.020000001f, angle, pitch);
            point[0] = origin[0] + func_L01_00443A18(0.0f, 0.1f);
            point[1] = origin[1] + func_L01_00443A18(0.0f, 0.1f);
            point[2] = origin[2] + func_L01_00443A18(0.0f, 0.1f);
            func_L01_0046A610(p, v, 25, 127, 0x20207F, spin, func_003824E0(0.05f, 0.2f) * units, 500.0f, 1.0f, 0.0f, 1.0f);
        }
    }
    func_L01_00470C78(origin, 66, 0x64A0A0FF, 2, 4, &D_L01_001D66B0, 0, 1, 6, 1, 0.1f, 1.05f);
    func_L01_00470C78(origin, 50, 0x3C0A32F7, 2, 0, &D_L01_001D66B0, 0, 0, 6, 1, 0.4f, 2.05f);
    func_L01_00470C78(origin, 66, 0x320A32F7, 0, 2, &D_L01_001D66B0, 0, 4, 6, 1, 0.15f, 1.65f);
    func_L01_00470C78(origin, 44, 0x3C0014F7, 2, 0, &D_L01_001D66B0, 3, 0, 6, 1, 0.5f, 2.35f);
    func_L01_00470C78(origin, 44, 0x1E0014F7, 1, -2, &D_L01_001D66B0, 3, 4, 6, 1, 0.3f, 1.75f);
}
/* localdecomp:end func_L01_003DD9C8 */

/* localdecomp:start func_L01_003DDDA8 */
extern u8 D_001425C0[];
extern u8 *D_L01_001EEA80[];
typedef struct {
    u8 p0[0x25C0];
    u8 *camera;            /* 0x25C0 */
    u8 p25C4[0x28C8 - 0x25C4];
    u8 shift;              /* 0x28C8 */
} Game_003DDDA8;
extern Game_003DDDA8 D_001A4BE0_003DDDA8;
typedef struct {
    u8 p0[0x25C];
    s32 bolts;             /* 0x25C */
} Save_003DDDA8;
extern Save_003DDDA8 D_00142DE0_003DDDA8;
extern s32 D_00142660[];
extern s32 D_001D545C;
extern u8 D_001BBE90[];
extern u8 D_L01_001D60E0[] __attribute__((section(".sdata")));
extern u8 D_L01_001D60D8[] __attribute__((section(".sdata")));
extern u8 D_001426E0[];
extern f32 D_L01_001DAA34;
extern f32 D_L01_002F1600[];
typedef struct {
    u128_t velocity;
    u8 pad[0x10];
    s32 flags;
    u8 rest[0xC];
} Damage_003DDDA8;
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_L01_004006C8(u8 *, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00315900(void *, s32, void *);
extern void func_L01_00446748(void *, void *, s32, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_003DE198(void);
extern u8 *func_00382348(void);

static __inline__ Row_003DD9C8 *row_003DDDA8(void) {
    return &D_L01_002C5600[D_001425C0[0x97]];
}

static __inline__ s32 scale_003DDDA8(s32 n) {
    return (f32)n * ((D_001D545C == 7 && D_001426E0[0x7B]) ? D_L01_001DAA34 : D_L01_002F1600[D_001D545C]);
}

void func_L01_003DDDA8(u8 *obj, u128_t *direction) {
    struct {
        u128_t impulse;
        Damage_003DDDA8 damage;
    } f;
    u8 *pos;
    s32 count;
    s32 i;
    f32 radius;

    func_0038CE20(&f.impulse, direction, -3.0f);
    radius = 4.0f;
    if (row_003DDDA8()->pad[1] >= 4) {
        radius = 1.0f;
    }
    pos = obj + 0x10;
    count = func_003D4D00(pos, 16, obj, 0, radius);
    if (count != 0) {
        for (i = 0; i < count; i++) {
            u8 *state;

            if (D_L01_001EEA80[i] == D_001A4BE0_003DDDA8.camera || *(s16 *)(obj + 0xAA) == 0x1A90) {
                continue;
            }
            state = ((u8 *(*)(void *))func_00382348)(D_L01_001EEA80[i]);
            if (D_L01_001EEA80[i] != 0 && *(u8 **)(D_L01_001EEA80[i] + 0x24) != 0
                && (*(u8 **)(D_L01_001EEA80[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] != 3) {
                if (*(f32 *)state > row_003DDDA8()->scale) {
                    f.damage.flags = 1;
                    func_0038CE20(&f.damage.velocity, obj + 0xD0, -1.0f);
                    ((f32 *)&f.damage.velocity)[3] = 5627.925f;
                    func_L01_00446748(&f.damage, D_L01_001EEA80[i], 0x110000, row_003DDDA8()->scale);
                    func_L01_00446978(D_L01_001EEA80[i], &f.damage);
                } else {
                    s32 bonus = (D_00142660[14] + 49) / 50;
                    u16 id = *(u16 *)(D_L01_001EEA80[i] + 0xB2);
                    s32 bits = D_001BBE90[((s16)id >> 1) + (D_001D545C << 10)];
                    s32 reward;

                    if (((id & 1) ? bits >> 4 : bits) & 8) {
                        reward = func_L01_004006C8(D_L01_001D60E0, *(u16 *)(D_L01_001EEA80[i] + 0xB6), *(s16 *)(D_L01_001EEA80[i] + 0xB2));
                    } else {
                        reward = func_L01_004006C8(D_L01_001D60D8, *(u16 *)(D_L01_001EEA80[i] + 0xB6), *(s16 *)(D_L01_001EEA80[i] + 0xB2));
                    }
                    reward <<= D_001A4BE0_003DDDA8.shift;
                    if (func_L01_0041A4F0()) {
                        reward = scale_003DDDA8(reward);
                    }
                    D_00142DE0_003DDDA8.bolts += reward + bonus;
                    func_L01_00315900(D_L01_001EEA80[i], 2, func_L01_003DE198);
                }
            } else if (D_L01_001EEA80[i] != 0 && *(u8 **)(D_L01_001EEA80[i] + 0x24) != 0
                       && (*(u8 **)(D_L01_001EEA80[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] == 3) {
                f.damage.flags = 1;
                func_0038CE20(&f.damage.velocity, obj + 0xD0, -1.0f);
                ((f32 *)&f.damage.velocity)[3] = 5627.925f;
                func_L01_00446748(&f.damage, D_L01_001EEA80[i], 0x110000, row_003DDDA8()->scale);
                func_L01_00446978(D_L01_001EEA80[i], &f.damage);
            } else {
                func_L01_003DD9C8(obj, (f32 *)(obj + 0x10));
            }
        }
    } else {
        func_L01_003DD9C8(obj, (f32 *)pos);
    }
}
/* localdecomp:end func_L01_003DDDA8 */

/* localdecomp:start func_L01_003DE198 */
extern u8 *func_00382348(void);

void func_L01_003DE198(void) {
    u8 *p = func_00382348();
    if (p != 0 && (u8)(p[14] - 1) < 2) {
        p[14] = 2;
    }
}
/* localdecomp:end func_L01_003DE198 */

INCLUDE_ASM("asm/levels", func_L01_003DE1D8);

/* localdecomp:start func_L01_003DE418 */
extern void func_0038D000(void *, void *, void *);

void func_L01_003DE418(u8 *obj, u128_t *out) {
    vu0_v4 v;

    *(vu0_q *)&v = 0;
    v.x = -0.1f;
    v.w = 1.0f;
    func_0038D000(&v, &v, obj + 0xC0);
    vec_add_ba(out, &v, obj + 0x10);
}
/* localdecomp:end func_L01_003DE418 */

/* localdecomp:start func_L01_003DE488 */

extern void func_L01_003DE418(u8 *, u128_t *);
extern void func_L01_003DE510(u128_t *, u8 *, s32, s32, f32, f32, f32);
extern void func_L01_00409B08(u128_t *, s32, s32);

void func_L01_003DE488(u8 *m) {
    u128_t a;
    u128_t b;
    u8 *t;

    t = *(u8 **)(m + 104);
    if (t != 0) {
        func_L01_003DE418(m, &a);
        b = *(u128_t *)(m + 16);
        func_L01_003DE510(&b, t + 16, 0x1030FF, 4, 0.0f, 0.85f, 0.25f);
        func_L01_00409B08(&a, 0x2040FF, 0);
    }
}
/* localdecomp:end func_L01_003DE488 */

INCLUDE_ASM("asm/levels", func_L01_003DE510);

/* localdecomp:start func_L01_003DEB40 */
void func_L01_003DEB40(u8 *obj) {
    extern s32 func_00382468(s32);
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i;
    for (i = 0; i < 4; i++) ((f32 *)v)[i] = func_00382468(255);
    *(f32 *)(v + 0x10) = -1.0f;
    *(f32 *)(v + 0x14) = -2.25f;
    *(f32 *)(v + 0x18) = 1.25f;
    *(f32 *)(v + 0x1c) = 2.5f;
     { s32 j; for (j = 1; j <= 4; j++) ((s32 *)(v + 0x20))[j-1] = (j * 320 - 3) / 6; }
    *(f32 *)(v + 0x3c) = *(f32 *)(v + 0x30) = 2.5f;
    *(f32 *)(v + 0x38) = *(f32 *)(v + 0x34) = 3.0f;
}
/* localdecomp:end func_L01_003DEB40 */

INCLUDE_ASM("asm/levels", func_L01_003DEC20);

/* localdecomp:start func_L01_003DEDF8 */
#include "vu0.h"
extern u8 D_00142CC0[];
extern u8 D_00142D60[];
extern f32 D_001A4C60[];
extern f32 D_L01_001DF548;
__asm__(".extern D_L01_001DF548, 4");
void func_L01_003DEDF8(u8 *obj) {
    extern void func_L01_003DEB40(u8 *);
    extern void func_003C2880(u8 *);
    extern void func_L01_004450F0(u8 *, s32, s32);
    extern void func_L01_003DEC20(u8 *);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_00451F60(s32, s32, s32);
    extern s32 func_0039EF28(void);
    extern s32 func_L01_00436620(s32);
    extern s32 func_L01_0041A5B0(s32, s32);
    s32 state = obj[0x20];
    switch (state) {
    case 0:
        func_L01_003DEB40(obj);
        if (D_00142CC0[0]) {
            func_003C2880(obj);
        } else {
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    case 1:
        func_L01_003DEC20(obj);
        if (func_L01_0040E570(obj + 0x10, D_001A4C60) < D_L01_001DF548 * D_L01_001DF548) {
            if (fabs_asm(*(f32 *)(obj + 0x18) - D_001A4C60[2]) < D_L01_001DF548) {
                func_L01_00451F60(0xAF7, -1, 0);
                D_00142CC0[0] = state;
                D_00142D60[0] = state;
                func_0039EF28();
                obj[0x31] = 0;
                *(u16 *)(obj + 0x34) |= 1;
                func_L01_004450F0(obj, 2, -1);
            }
        }
        break;
    case 2:
        if (!func_L01_00436620(0) && func_L01_0041A5B0(0x1627, 0x138)) {
            func_003C2880(obj);
        }
        break;
    }
}
/* localdecomp:end func_L01_003DEDF8 */

/* localdecomp:start func_L01_003DEF68 */
typedef struct {
    u8 p0[0x1210];
    s32 w1210;
    u8 p1214[0xC];
    s32 w1220;
} S_003DEF68;
extern S_003DEF68 D_001A4BE0;
extern s32 D_L01_001D6694;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_003A0EC0(s32, s32, s32, s32, s32);

void func_L01_003DEF68(u8 *obj) {
    if (obj[0x20] == 0) {
        obj[0x20] = 1;
    }
    if (D_L01_001D6694 == 0) {
        u8 *hero = D_001D52FC;
        if ((*(s32 *)(hero + 0x1A4) & D_001A4BE0.w1210) != 0) {
            if (D_001A4BE0.w1220 >= 0x13) {
                func_003A0EC0(5, 1, 4, 0, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_003DEF68 */

/* localdecomp:start func_L01_003DEFE8 */
extern vu0_v4 D_L01_001E29C0;
extern s32 D_L01_001DF550;
__asm__(".extern D_L01_001DF550, 4");
u8 *func_L01_003DEFE8(u128_t *position) {
    extern Obj_003DC268 *func_003C24B0(s32,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_003C5180(void *,void *,s32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_L01_003DF7A8(void *,void *,f32,f32,f32,s32,u32,u32,f32,s32,s32);
    vu0_v4 direction;
    vu0_v4 normal;
    u8 *obj=(u8 *)func_003C24B0(0x1df6,128);
    u8 *vars;
    s32 i;
    if(obj) {
        obj[0x30]=255;
        *(s16 *)(obj+0x32)=255;
        obj[0x20]=0;
        *(u128_t *)(obj+0x10)=*position;
        vars=*(u8 **)(obj+0x68);
        *(f32 *)(obj+0x1c)=1.0f;
        vec_sub_ba(&direction,&D_L01_001E29C0,obj+0x10);
        func_0038CF68(&direction,&direction,1.0f);
        func_003C5180(obj+0x10,&normal,1);
        *(u128_t *)(obj+0xc0)=*(u128_t *)&direction;
        func_0038CE90(obj+0xd0,obj+0xc0,&normal);
        func_0038CF68(obj+0xd0,obj+0xd0,1.0f);
        func_0038CE90(obj+0xe0,obj+0xd0,obj+0xc0);
        *(f32 *)(obj+0xcc)=*(f32 *)(obj+0xdc)=*(f32 *)(obj+0xec)=0.0f;
        *(s32 *)(vars+8)=53;
        *(s32 *)(vars+0x10)=25;
        *(s32 *)(vars+0xc)=-1;
        *(s32 *)(vars+0x14)=0;
        obj[0x20]=1;
        *(s32 *)(vars+0x18)=-1;
        *(s32 *)(vars+0x28)=0;
        for(i=0;i<24;i++) {
            func_L01_003DF7A8(obj,obj+0x10,0.03490658476948738f,0.3f,1.1f,D_L01_001DF550,0x204080ff,0x204080ff,4.0f,255,255);
        }
    }
    return obj;
}
/* localdecomp:end func_L01_003DEFE8 */

INCLUDE_ASM("asm/levels", func_L01_003DF1B0);

/* localdecomp:start func_L01_003DF558 */
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s16 D_001CFEC0[];

void func_L01_003DF558(u8 *p)
{
    s32 *o = *(s32 **)(p + 0x68);
    s32 c;
    s32 rgba;

    c = 0x80 - o[2] * 2;
    rgba = c << 24 | c << 16 | c << 8 | c;
    func_003A9440(0x42, 0x48);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
    func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], rgba);
}
/* localdecomp:end func_L01_003DF558 */

/* localdecomp:start func_L01_003DF620 */
typedef struct { u8 p[0x20]; f32 angle; s32 timer; } State_003DF620;
typedef struct { vu0_v4 position; void *owner; u8 p24[4]; f32 scale; u8 p2C[4]; s32 a, b, c, d; f32 e, f, phase; u8 p3C[0x14]; } Row_003DF620;
extern u8 D_L01_002A3A40[];
extern s32 D_L01_001DF550;
__asm__(".extern D_L01_001DF550, 4");
void func_L01_003DF620(u8 *obj) {
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, f32);
    vu0_v4 out;
    vu0_v4 origin;
    State_003DF620 *state;
    Row_003DF620 *row;
    u8 *base;
    s32 n, count;
    state = *(State_003DF620 **)(obj + 0x68);
    if (state != 0) {
        count = 0;
        for (n = 0; n < 24; n++) {
            base = D_L01_002A3A40 + n * 0x50;
            row = (Row_003DF620 *)(base + 0x10);
            if (row->owner != obj) goto next;
            if (count < (120 - state->timer) / 5) {
                func_0038D890(&row->position, &row->position, base, row->scale);
                count++;
                row->phase += 0.06f;
                func_0038CF68(&row->position, &row->position, row->phase);
                vec_add_ab(&out, &row->position, obj + 0x10);
                *(u128_t *)&origin = *(u128_t *)(obj + 0x10);
                func_L01_0040A8C0(&origin, &out, D_L01_001DF550, 1, row->e, row->f, row->a, row->b, row->c, row->d, state->angle);
            }
        next:;
        }
        state->angle -= 0.018f;
        if (state->angle <= -8.0f) state->angle += 8.0f;
    }
}
/* localdecomp:end func_L01_003DF620 */

INCLUDE_ASM("asm/levels", func_L01_003DF7A8);

/* localdecomp:start func_L01_003DF8B8 */
void func_L01_003DF8B8(void) {

}
/* localdecomp:end func_L01_003DF8B8 */

INCLUDE_ASM("asm/levels", func_L01_003DF8C0);

/* localdecomp:start func_L01_003E0058 */
Obj_003DC268 *func_L01_003E0058(u128_t *position, u128_t *direction) {
    extern Obj_003DC268 *func_003C24B0(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern void func_0038D308(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_003C4840(f32, void *, void *);
    extern s32 func_L01_004C85C8(void *, s32, f32, f32, f32);
    extern void func_003C7C38(void *);
    Obj_003DC268 *obj = func_003C24B0(0x1E05, 0x80);
    u8 *state;
    if (obj != 0) {
        obj->pad20[0] = 0;
        obj->opacity = obj->flags = 255;
        state = (u8 *)obj->vars;
        obj->position = *position;
        *(u128_t *)state = *direction;
        *(s16 *)(state + 0x20) = (func_00382498(300, 500) * 5 + 2) / 6;
        *(u16 *)((u8 *)obj + 0x34) |= 0x100;
        *(f32 *)((u8 *)obj + 0xF0) = func_00382538();
        *(f32 *)((u8 *)obj + 0xF4) = func_00382538();
        *(f32 *)((u8 *)obj + 0xF8) = func_00382538();
        obj->pad20[3] = 64;
        func_0038D308((u8 *)obj + 0xC0, (u8 *)obj + 0xF0);
        func_003C4840(func_003824E0(0.05235988f, 0.10471976f), state + 0x10, (u8 *)obj + 0xD0);
        *(f32 *)((u8 *)obj + 0x2C) = *(f32 *)(*(u8 **)((u8 *)obj + 0x24) + 0x24) * func_003824E0(0.25f, 0.3f);
        *(s32 *)(state + 0x28) = func_L01_004C85C8(obj, 0, 1.0f, 1.0f, 1.0f);
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L01_003E0058 */

INCLUDE_ASM("asm/levels", func_L01_003E01B8);
