#include "common.h"

typedef struct {
    char pad0[0x10];
    char pos[0x2];
    s16 active;
    char pad14[0x18 - 0x14];
    f32 unk18;
    f32 unk1C;
    char pad20[0x40 - 0x20];
} Entry;
typedef struct {
    char pad0[0x1A];
    s16 unk1A;
} Vars;
typedef struct {
    char pad0[0x68];
    Vars *vars;
} Moby;
typedef struct {
    s32 unk0;
    s32 offset;
} Info;
typedef struct {
    u8 pad0[24];
    s32 x18;
    u8 pad1[20];
} S_27F600;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 f10[16];
} Src_0034C508;
typedef struct {
    u8 pad0[24];
    Src_0034C508 *src;
    u8 pad1C[20];
} Ent_0034C508;
typedef struct {
    u8 pad0[124];
    s32 f124;
    u8 pad128[8];
    s32 f136;
    u8 pad140[20];
} Sub_0034CC80;
typedef struct {
    u8 pad0[48];
    Sub_0034CC80 sub;
} Entry_0034CC80;
typedef int s128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L01_00348620);

INCLUDE_ASM("asm/levels", func_L01_00348A98);

/* localdecomp:start func_L01_00348C88 */
#include "vu0.h"
typedef struct { vu0_q a,b; vu0_v4 c; vu0_q d,e; s16 active,timer; f32 u,v; s32 tail; } Row_00348C88;
__asm__(".extern D_L01_001DD35C, 4");
__asm__(".extern D_L01_001DD394, 4");
__asm__(".extern D_L01_001DD370, 4");
extern f32 D_L01_001DD35C __attribute__((section(".sdata")));
extern f32 D_L01_001DD394 __attribute__((section(".sdata")));
extern f32 D_L01_001DD370 __attribute__((section(".sdata")));
s32 func_L01_00348C88(u8 *self) {
    extern char *func_L01_00457480(s32, s32);
    extern Info *func_L01_004574B0(s32, s32);
    extern s32 func_0038CB00(void *);
    extern void func_0038CF68(void *, void *, f32);
    u8 *p = *(u8 **)(self + 0x68);
    Row_00348C88 *rows;
    vu0_v4 v;
    rows = (Row_00348C88 *)(func_L01_00457480(0xC04, *(s16 *)(p + 0x1A)) + func_L01_004574B0(0xC04, *(s16 *)(p + 0x1A))->unk0);
    if (!rows[*(s16 *)(p + 0x18)].active) return 0;
    if (func_0038CB00(&rows[*(s16 *)(p + 0x18)].timer)) {
        rows[*(s16 *)(p + 0x18)].active = 0;
        return 0;
    }
    *(vu0_q *)((u8 *)&rows[*(s16 *)(p + 0x18)] + 0x20) = *(vu0_q *)(self + 0x10);
    rows[*(s16 *)(p + 0x18)].u += D_L01_001DD35C;
    if (rows[*(s16 *)(p + 0x18)].u >= 4.0f) rows[*(s16 *)(p + 0x18)].u -= 4.0f;
    rows[*(s16 *)(p + 0x18)].v += D_L01_001DD394;
    if (rows[*(s16 *)(p + 0x18)].v >= 4.0f) rows[*(s16 *)(p + 0x18)].v -= 4.0f;
    func_0038CF68(&v, p, D_L01_001DD370 * 0.020000001415610313f);
    vec_add_ba(&rows[*(s16 *)(p + 0x18)].a, &rows[*(s16 *)(p + 0x18)].a, &v);
    vec_add_ba(&rows[*(s16 *)(p + 0x18)].b, &rows[*(s16 *)(p + 0x18)].b, &v);
    return 1;
}
/* localdecomp:end func_L01_00348C88 */

INCLUDE_ASM("asm/levels", func_L01_00348E30);

/* localdecomp:start func_L01_003493C8 */
typedef struct {
    f32 pos[4];
    s16 life;     /* 0x10: frames */
    s16 active;   /* 0x12 */
    f32 per_tick; /* 0x14: 1 / life */
    f32 roll;     /* 0x18 */
    f32 spin;     /* 0x1C: radians a frame */
    f32 size_a;   /* 0x20 */
    f32 grow_a;   /* 0x24 */
    f32 size_b;   /* 0x28 */
    f32 grow_b;   /* 0x2C */
    s32 age;      /* 0x30 */
    f32 swing;    /* 0x34: radians a frame */
    f32 x38;
    u8 pad3C[4];
} Sprite_003493C8;

__asm__(".extern D_L01_001DD398, 4");
__asm__(".extern D_L01_001DD39C, 4");
__asm__(".extern D_L01_001DD3A0, 4");
__asm__(".extern D_L01_001DD3A4, 4");
__asm__(".extern D_L01_001DD3A8, 4");
__asm__(".extern D_L01_001DD3AC, 4");
__asm__(".extern D_L01_001DD3B0, 4");
__asm__(".extern D_L01_001DD3B4, 4");
__asm__(".extern D_L01_001DD3C8, 4");
__asm__(".extern D_L01_001DD3CC, 4");
__asm__(".extern D_L01_001DD3D0, 4");
__asm__(".extern D_L01_001DD3D4, 4");
extern s32 D_L01_001DD398;
extern s32 D_L01_001DD39C;
extern f32 D_L01_001DD3A0;
extern f32 D_L01_001DD3A4;
extern f32 D_L01_001DD3A8;
extern f32 D_L01_001DD3AC;
extern f32 D_L01_001DD3B0;
extern f32 D_L01_001DD3B4;
extern f32 D_L01_001DD3C8;
extern f32 D_L01_001DD3CC;
extern f32 D_L01_001DD3D0;
extern f32 D_L01_001DD3D4;
extern char *func_L01_00457480(s32, s32);
extern Info *func_L01_004574B0(s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);

/* flux_trail_sprite_add: lays one of the Flux Rifle shot's trail sprites (twice a frame from
   V3) at pos, in the first free of the gun's 120: a life of 45-60 frames (D_L01_001DD398,
   D_L01_001DD39C) x 5/6 for PAL's 50 Hz, rounded; a random roll, a spin of 1-4 degrees a
   frame either way, sizes 0.3-0.5 growing 0.75-1.25, a swing of 1-2 degrees a frame and
   0.1-0.25 at 0x38. */
void func_L01_003493C8(Moby *shot, s128 *pos)
{
    Vars *vars = shot->vars;
    Sprite_003493C8 *sprite;
    s32 i;

    sprite = (Sprite_003493C8 *)(func_L01_00457480(0xC04, vars->unk1A)
                                 + func_L01_004574B0(0xC04, vars->unk1A)->offset);
    for (i = 0; i < 120; i++, sprite++) {
        if (sprite->active == 0) {
            sprite->active = 1;
            *(s128 *)sprite->pos = *pos;
            /* (n * 5 + 2) / 6: n x 50/60, rounded */
            sprite->life = (func_00382498(D_L01_001DD398, D_L01_001DD39C) * 5 + 2) / 6;
            sprite->per_tick = 1.0f / sprite->life;
            sprite->roll = func_00382538();
            sprite->spin = func_L01_00443A18(D_L01_001DD3A0, D_L01_001DD3A4) * 0.017453292f;
            sprite->size_a = func_003824E0(D_L01_001DD3A8, D_L01_001DD3AC);
            sprite->grow_a = func_003824E0(D_L01_001DD3B0, D_L01_001DD3B4);
            sprite->size_b = func_003824E0(D_L01_001DD3A8, D_L01_001DD3AC);
            sprite->grow_b = func_003824E0(D_L01_001DD3B0, D_L01_001DD3B4);
            sprite->age = 0;
            sprite->swing = func_003824E0(D_L01_001DD3C8, D_L01_001DD3CC) * 0.017453292f;
            sprite->x38 = func_003824E0(D_L01_001DD3D0, D_L01_001DD3D4);
            return;
        }
    }
}
/* localdecomp:end func_L01_003493C8 */

/* localdecomp:start func_L01_00349538 */




extern char *func_L01_00457480(s32, s32);
extern Info *func_L01_004574B0(s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038DAB8(f32, f32);

s32 func_L01_00349538(Moby *m) {
    Vars *v = m->vars;
    Entry *e;
    s32 i;
    s32 count = 0;

    e = (Entry *)(func_L01_00457480(3076, v->unk1A) + func_L01_004574B0(3076, v->unk1A)->offset);
    for (i = 0; i < 120; i++) {
        if (e[i].active != 0) {
            if (func_0038CB00(e[i].pos) != 0) {
                e[i].active = 0;
            } else {
                count++;
                e[i].unk18 = func_0038DAB8(e[i].unk18, e[i].unk1C);
            }
        }
    }
    return count;
}
/* localdecomp:end func_L01_00349538 */

/* localdecomp:start func_L01_003495F0 */
#include "vu0.h"
__asm__(".extern D_L01_001DD3C4, 4");
__asm__(".extern D_L01_001DD3B8, 4");
__asm__(".extern D_L01_001DD3C0, 4");
__asm__(".extern D_L01_001DD3BC, 4");
extern s32 D_L01_001DD3C4;
extern f32 D_L01_001DD3B8;
extern s32 D_L01_001DD3C0;
extern s32 D_L01_001DD3BC;
extern void *D_L01_001E1A04;
typedef struct { u8 pad0[0x16B0]; s32 w16B0; u8 pad16B4[0x25C4-0x16B4]; s32 w25C4; } Game_003495F0;
extern Game_003495F0 D_001A4BE0_003495F0;
extern f32 D_L01_001E29C0_003495F0[];
extern s32 D_L01_001D673C;
extern f32 D_L01_001D7C50[][4];
void func_L01_003495F0(Moby *m) {
    extern char *func_L01_00457480(s32, s32);
    extern Info *func_L01_004574B0(s32, s32);
    extern void func_003D93B0(void *, void *, s32, s32);
    extern f32 func_L01_0044AE78(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    struct {
        u8 packet[0x40];
        s32 colors[4];
        f32 uv[8];
        u8 pad70[0x20];
        f32 basis[4];
        f32 a[4], b[4], c[4], pos[4], scratch[4], corner[4];
    } __attribute__((aligned(16))) v;
    Sprite_003493C8 *sprites;
    Sprite_003493C8 *s;
    Vars *vars = m->vars;
    f32 fade;
    f32 zero;
    s32 i, next, j, color;
    f32 t, x, y, dx, dy, cs, sn, width, height;
    f32 one;
    f32 *template;
    f32 *dest;
    sprites = (Sprite_003493C8 *)(func_L01_00457480(0xC04, vars->unk1A) + func_L01_004574B0(0xC04, vars->unk1A)->offset);
    *(s128 *)v.basis = 0;
    v.basis[3] = v.basis[2] = 1.0f;
    fade = (f32)D_L01_001DD3C4;
    if (D_001A4BE0_003495F0.w25C4 == 29 || D_001A4BE0_003495F0.w16B0 != 0) fade *= 0.5f;
    func_003D93B0(&v, D_L01_001E1A04, 0, 0x80);
    v.uv[0] = 0.0f;
    v.uv[1] = 0.0f;
    v.uv[2] = 0.0f;
    v.uv[3] = 1.0f;
    v.uv[4] = 1.0f;
    v.uv[5] = 0.0f;
    v.uv[6] = 1.0f;
    v.uv[7] = 1.0f;
    zero = v.uv[0];
    i = 0;
    while (i < 120) {
        s = (Sprite_003493C8 *)(i * 0x40 + (s32)sprites);
        next = i + 1;
        if (s->active != 0) {
            one = 1.0f;
            t = (f32)s->life * s->per_tick;
            color = (s32)(fade * t) << 24;
            color |= func_0038DBD8(D_L01_001DD3C0, D_L01_001DD3BC, fabs_asm(func_0038D0B0(func_L01_0044AE78(t * (D_L01_001DD3B8 * 3.1415927f)))));
            v.colors[0] = v.colors[1] = v.colors[2] = v.colors[3] = color;
            x = s->grow_a + (s->size_a - s->grow_a) * t;
            y = s->grow_b + (s->size_b - s->grow_b) * t;
            { f32 phase = func_0038DAB8(*(f32 *)&s->age, s->swing); *(f32 *)&s->age = phase; }
            dx = s->x38 * x * func_0038D098(*(f32 *)&s->age);
            dy = *(f32 *)((u8 *)s + 0x3C) * y * func_0038D0B0(*(f32 *)&s->age);
            *(s128 *)v.pos = *(s128 *)s->pos;
            vec_sub_ab(v.a, D_L01_001E29C0_003495F0, v.pos);
            func_0038CF68(v.a, v.a, one);
            if (D_L01_001D673C != 0) func_003C5180(v.pos, v.basis, 1);
            func_0038CE90(v.b, v.a, v.basis);
            x += dx;
            width = x;
            y += dy;
            height = y;
            func_0038CF68(v.b, v.b, one);
            func_0038CE90(v.c, v.b, v.a);
            v.c[3] = zero; v.b[3] = zero; v.a[3] = zero; v.pos[3] = one;
            cs = func_0038D098(s->roll);
            sn = func_0038D0B0(s->roll);
            template = D_L01_001D7C50[0];
            dest = (f32 *)&v;
            for (j = 3; j >= 0; j--) {
                f32 ty = template[1] * width;
                f32 tz = template[2] * height;
                f32 w = 1.0f;
                v.corner[3] = w;
                v.scratch[0] = template[0];
                v.scratch[1] = ty; v.scratch[2] = tz;
                v.corner[0] = template[0];
                v.corner[1] = ty * cs - tz * sn;
                v.corner[2] = ty * sn + tz * cs;
                func_0038D028(dest, v.corner, v.a);
                dest += 4; template += 4;
            }
            func_003D2DA0(&v, 0, 0);
        }
        i = next;
    }
}
/* localdecomp:end func_L01_003495F0 */

/* localdecomp:start func_L01_00349998 */
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vector_00349998;
extern u8 D_L01_001E2A40[];
typedef struct { f32 random[6]; f32 height; s16 a1C, a1E; f32 a20, a24; s16 a28, a2A; f32 a2C, a30; s16 a34, a36; f32 a38, a3C; s32 a40; f32 a44; u8 pad48[8]; s32 owner; } State_00349998;
u8 *func_L01_00349998(s32 unused, s128 *position, s128 *direction, f32 height, s32 owner) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_00382538(void);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern s32 func_L01_00459590(void *, s32, f32);
    extern void func_L01_0034A3C8(u8 *, f32 *, s32);
    Vector_00349998 matrix;
    Vector_00349998 offset;
    Vector_00349998 test;
    u8 *m = func_003C24B0(0xD4E, 0x80);
    State_00349998 *v;
    if (m != 0) {
        f32 zero = 0.0f;
        m[0x30] = 255;
        *(s16 *)(m + 0x32) = 255;
        m[0x20] = 0;
        v = *(State_00349998 **)(m + 0x68);
        *(s128 *)(m + 0x10) = *position;
        *(f32 *)(m + 0x1C) = 1.0f;
        func_003C5180(m + 0x10, matrix.v, 1);
        *(s128 *)(m + 0xC0) = *direction;
        func_0038CE90(m + 0xD0, m + 0xC0, &matrix);
        func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
        func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
        *(f32 *)(m + 0xEC) = zero;
        *(f32 *)(m + 0xDC) = zero;
        *(f32 *)(m + 0xCC) = zero;
        v->owner = owner;
        func_0038CE20(offset.v, (f32 *)(m + 0xC0), 0.5f);
        vec_add_ab(m + 0x10, m + 0x10, &offset);
        if (height != zero && *(f32 *)(m + 0x18) - height >= 6.0f) height = zero;
        v->height = height;
        v->random[0] = func_00382538();
        v->random[1] = func_00382538();
        v->random[2] = func_00382538();
        v->random[3] = func_00382538();
        v->random[4] = func_00382538();
        v->random[5] = func_00382538();
        v->a1C = 17;
        v->a1E = 50;
        v->a20 = 0.05882352963089943f;
        v->a24 = 0.019999999552965164f;
        v->a28 = 15;
        v->a2C = 0.06666667014360428f;
        v->a2A = 33;
        v->a30 = 0.03030303120613098f;
        if (func_003D3CB0(m + 0x10, D_L01_001E2A40, 18, 0, 0)) {
            v->a36 = 0;
        } else {
            v->a36 = 13;
            v->a38 = 0.07692307978868484f;
            *(s128 *)&test = *(s128 *)(m + 0x10);
            test.v[3] = 1.0f;
            if (func_L01_00459590(&test, 0, 128.0f) == 1) {
                f32 fade_step = 0.3333333432674408f;
                s32 fade_time = 3;
                f32 step = 0.0833333358168602f;
                s32 duration = 13;
                v->a34 = fade_time;
                v->a3C = fade_step;
                v->a44 = step;
                v->a40 = duration;
            } else {
                v->a34 = 0;
                v->a40 = 0;
            }
        }
        func_L01_0034A3C8(m, matrix.v, owner);
    }
    return m;
}
/* localdecomp:end func_L01_00349998 */

INCLUDE_ASM("asm/levels", func_L01_00349C58);

INCLUDE_ASM("asm/levels", func_L01_0034A3C8);

INCLUDE_ASM("asm/levels", func_L01_0034ACD8);

/* localdecomp:start func_L01_0034C300 */
typedef struct {
    u8 pad0[0x228];
    s32 w228;
    f32 f22C;
    u8 pad230[8];
    f32 f238;
    f32 f23C;
    u8 pad240[0x10];
    s32 w250;
    s32 w254;
    s32 w258;
} G_0034C300;

extern G_0034C300 D_L01_001E7580;
extern void func_003873C0(void);

void func_L01_0034C300(u8 *obj, f32 scale) {
    *(s32 *)(obj + 0x4C) = 0x19;
    *(f32 *)(obj + 0x48) = scale;
    D_L01_001E7580.f238 = 255.0f;
    D_L01_001E7580.f22C = scale * 1024.0f * 0.4f;
    D_L01_001E7580.f23C = 100.0f;
    D_L01_001E7580.w228 = 0;
    D_L01_001E7580.w250 = 0xFF;
    D_L01_001E7580.w254 = 0xFF;
    D_L01_001E7580.w258 = 0xFF;
    func_003873C0();
}
/* localdecomp:end func_L01_0034C300 */

/* localdecomp:start func_L01_0034C378 */
extern u8 D_L01_001DF9E4;
extern u8 D_L01_001DF9E5;
extern u8 D_L01_001DF9E6;
extern f32 D_L01_001DF9E8;
extern f32 D_L01_001DF9EC;
extern f32 D_L01_001DF9F0;
extern f32 D_L01_001DF9F4;
void func_L01_0034C378(u8 *obj)
{
    extern void func_0038CAD0(s32 *);
    extern void func_003873C0(void);
    f32 t, r, g, b, a, x, y, z;
    if (*(s32 *)(obj + 0x4C) > 0) {
        func_0038CAD0((s32 *)(obj + 0x4C));
        t = (f32)*(s32 *)(obj + 0x4C) / 25.0f;
        r = D_L01_001DF9E4;
        g = D_L01_001DF9E5;
        b = D_L01_001DF9E6;
        a = D_L01_001DF9E8;
        x = D_L01_001DF9EC;
        y = D_L01_001DF9F0;
        z = D_L01_001DF9F4;
        r += (255.0f - r) * t;
        g += (255.0f - g) * t;
        b += (255.0f - b) * t;
        a += (0.0f - a) * t;
        D_L01_001E7580.w250 = (s32)r;
        D_L01_001E7580.w254 = (s32)g;
        D_L01_001E7580.w258 = (s32)b;
        *(f32 *)&D_L01_001E7580.w228 = a;
        y += (255.0f - y) * t;
        z += (100.0f - z) * t;
        x += (*(f32 *)(obj + 0x48) * 1024.0f * 0.4f - x) * t;
        D_L01_001E7580.f238 = y;
        D_L01_001E7580.f23C = z;
        D_L01_001E7580.f22C = x;
        func_003873C0();
    }
}
/* localdecomp:end func_L01_0034C378 */

/* localdecomp:start func_L01_0034C4E0 */
void func_L01_0034C4E0(void) {

}
/* localdecomp:end func_L01_0034C4E0 */

INCLUDE_ASM("asm/levels", func_L01_0034C4E8);

/* localdecomp:start func_L01_0034C910 */
extern void func_L01_0043B9E8(void *, s32, s32, s32);

void func_L01_0034C910(u8 *s) {
    u8 *m;

    func_L01_0043B9E8(*(u8 **)(s + 0x18), s[4], s[5], s[6]);
    m = *(u8 **)(s + 0x18);
    if (*(u16 *)(m + 0x34) & 0x20) {
        u8 *p = *(u8 **)(*(u8 **)(m + 0x68) + 0x10);
        if (p != 0 && *(s16 *)p != 0) {
            p[4] = s[4];
            p[5] = *(s32 *)(s + 4) >> 8;
            p[6] = *(s32 *)(s + 4) >> 16;
        }
    }
}
/* localdecomp:end func_L01_0034C910 */

/* localdecomp:start func_L01_0034C990 */

extern S_27F600 D_L01_0027F580[];

s32 func_L01_0034C990(s32 id) {
    s32 r = -1;
    s32 i;

    for (i = 0; i < 30; i++) {
        if (D_L01_0027F580[i].x18 == id) {
            r = i;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L01_0034C990 */

INCLUDE_ASM("asm/levels", func_L01_0034C9F0);

/* localdecomp:start func_L01_0034CE70 */
/* func_L01_0034CE70: first draft, adapted from the rac2 donor */
__asm__(".extern D_L01_001DD3D8, 4");
extern s32 D_L01_001DD3D8;
extern u8 *func_003C24B0(s32, s32);

void *func_L01_0034CE70(void) {
    u8 *p = func_003C24B0(4406, 128);

    if (p != 0) {
        s32 v = 0xFF;

        D_L01_001DD3D8 = (s32)p;
        p[0x20] = 1;
        *(u16 *)(p + 0x32) = v;
        p[0x30] = v;
    }
    return p;
}
/* localdecomp:end func_L01_0034CE70 */

/* localdecomp:start func_L01_0034CEB8 */
typedef struct {
    f32 damage;     /* taken at once on the hit */
    f32 arc_damage; /* each arc's */
    s32 seconds;    /* how long the target keeps arcing */
    f32 interval;   /* seconds between arcs */
} ShockRow_0034CEB8;

__asm__(".extern D_L01_001DD3D8, 4");
extern s32 D_L01_001DD3D8;
extern S_27F600 D_L01_0027F580[];
extern void *func_L01_0034CE70(void);
/* the per-item tables: bank 0, then bank 1 (the gun at V3 or V4) */
extern ShockRow_0034CEB8 D_L01_00282220[][204];

/* shock_mod_tables_init: at the level start, empties the shock slots and fills the shock
   mod's per-item tables in two banks; only the Miniturret Glove (0x15, 0xA2) has numbers. */
void func_L01_0034CEB8(void)
{
    s32 i;

    for (i = 29; i >= 0; i--) {
        D_L01_0027F580[i].x18 = 0;
    }
    D_L01_001DD3D8 = 0;
    /* its moby (class 0x1136), which D_L01_001DD3D8 keeps; called with a 0 it ignores */
    ((void *(*)(s32))func_L01_0034CE70)(0);
    for (i = 0; i < 204; i++) {
        D_L01_00282220[0][i].interval = 1.0f;
        D_L01_00282220[1][i].interval = 1.0f;
    }
    /* the Miniturret Glove: 1 at once, arcs of 2, for 3 s (bank 1: 2, 4, 3 s) */
    D_L01_00282220[0][0x15].damage = 1.0f;
    D_L01_00282220[0][0x15].arc_damage = 2.0f;
    D_L01_00282220[0][0x15].seconds = 3;
    D_L01_00282220[0][0xA2].damage = 1.0f;
    D_L01_00282220[0][0xA2].arc_damage = 2.0f;
    D_L01_00282220[0][0xA2].seconds = 3;
    D_L01_00282220[1][0x15].damage = 2.0f;
    D_L01_00282220[1][0x15].arc_damage = 4.0f;
    D_L01_00282220[1][0x15].seconds = 3;
    D_L01_00282220[1][0xA2].damage = 2.0f;
    D_L01_00282220[1][0xA2].arc_damage = 4.0f;
    D_L01_00282220[1][0xA2].seconds = 3;
}
/* localdecomp:end func_L01_0034CEB8 */

/* localdecomp:start func_L01_0034CF88 */
extern S_27F600 D_L01_0027F580[];
extern void func_003C5180(void *, f32 *, s32);
extern void func_0038CE20(f32 *, f32 *, f32);
extern void func_L01_0034D700(s32);
void func_L01_0034CF88(s32 a) {
    f32 v[4];
    Ent_0034C508 *p;
    s32 i;
    f32 k1;
    f32 k2;
    p = ((Ent_0034C508 *)&D_L01_0027F580);
    k1 = 0.000976499985f;
    k2 = 0.850000024f;
    for (i = 0; i < 30; i++, p++) {
        if (p->src != 0) {
            func_003C5180(p->src->f10, v, 1);
            func_0038CE20(v, v, p->src->fC * k1 * k2);
            v[0] += p->src->f0 * k1;
            v[1] += p->src->f4 * k1;
            v[2] += p->src->f8 * k1;
        }
    }
    func_L01_0034D700(a);
}
/* localdecomp:end func_L01_0034CF88 */
