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

/* localdecomp:start func_L01_00348A98 */
#include "vu0.h"
typedef struct { vu0_q a, b; vu0_v4 c; vu0_q d, e; s16 active, timer; f32 u, v, inv; } Row_00348A98;
extern s32 D_001A71A4[];
extern s32 D_L01_001D673C;
extern s32 D_L01_001DD36C;
__asm__(".extern D_L01_001DD36C, 4");
static __inline__ void qcopy_00348A98(void *dst, void *src) {
    *(vu0_q *)dst = *(vu0_q *)src;
}
void func_L01_00348A98(u8 *m) {
    extern char *func_L01_00457480(s32, s32);
    extern Info *func_L01_004574B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE90(void *, void *, void *);
    vu0_v4 a, b, c;
    u8 *p = *(u8 **)(m + 0x68);
    Row_00348A98 *rows;
    if (D_001A71A4[0] == 29) return;
    rows = (Row_00348A98 *)(func_L01_00457480(0xC04, *(s16 *)(p + 0x1A)) + func_L01_004574B0(0xC04, *(s16 *)(p + 0x1A))->unk0);
    func_0038CF68(&a, p, 1.0f);
    *(vu0_q *)&b = 0;
    b.z = 1.0f; b.w = 1.0f;
    if (D_L01_001D673C) func_003C5180(m + 0x10, &b.x, 1);
    func_0038CE90(&c, &a, &b);
    func_0038CF68(&c, &c, 1.0f);
    func_0038CE90(&rows[*(s16 *)(p + 0x18)].e, &c, &a);
    rows[*(s16 *)(p + 0x18)].d = *(vu0_q *)&a;
    rows[*(s16 *)(p + 0x18)].a = *(vu0_q *)(m + 0x10);
    vec_add_ab(&rows[*(s16 *)(p + 0x18)].b, m + 0x10, p);
    qcopy_00348A98(&rows[*(s16 *)(p + 0x18)].c, &rows[*(s16 *)(p + 0x18)].b);
    rows[*(s16 *)(p + 0x18)].timer = (D_L01_001DD36C * 5 + 2) / 6;
    rows[*(s16 *)(p + 0x18)].inv = 1.0f / rows[*(s16 *)(p + 0x18)].timer;
    rows[*(s16 *)(p + 0x18)].u = 0;
    rows[*(s16 *)(p + 0x18)].v = 0;
    rows[*(s16 *)(p + 0x18)].active = 1;
}
/* localdecomp:end func_L01_00348A98 */

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

/* functional: high. Compiles with the file flags; diff is stack layout and scheduling only; all control flow, constants and call args traced by hand against the asm. */
/* localdecomp:start func_L01_00349C58 */
#include "vu0.h"
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_00349C58;
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
void func_L01_00349C58(u8 *m) {
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_0034C378(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_0038CB00(void *);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(void *);
    extern void func_L01_00404AD8_00349C58(void *, void *);
    extern void func_L01_0034ACD8_00349C58(u8 *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004CABD8(void *, void *, void *);
    extern void *func_L01_00470668(void *, void *, s32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, s32, s32, f32, s32, s32, s32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern s32 func_00382468(s32);
    u8 *v = *(u8 **)(m + 0x68);
    Vec_00349C58 q10, q20, q30, q40, q50, q60;
    s32 state, n, i, j;
    f32 t, d, e, lim, nf, f, vy;

    func_L01_004CAB30(m + 0x10, m + 0x10);
    func_L01_0034C378(v);
    *(f32 *)(v + 0x00) = func_0038DAB8(*(f32 *)(v + 0x00), 0.05235987901687622f);
    *(f32 *)(v + 0x04) = func_0038DAB8(*(f32 *)(v + 0x04), 0.003490658476948738f);
    *(f32 *)(v + 0x08) = func_0038DAB8(*(f32 *)(v + 0x08), 0.004363323096185923f);
    *(f32 *)(v + 0x0C) = func_0038DAB8(*(f32 *)(v + 0x0C), -0.004363323096185923f);
    *(f32 *)(v + 0x10) = func_0038DAB8(*(f32 *)(v + 0x10), 0.006981316953897476f);
    *(f32 *)(v + 0x14) = func_0038DAB8(*(f32 *)(v + 0x14), -0.006981316953897476f);
    func_0038CB00(v + 0x1E);
    func_0038CB00(v + 0x34);
    func_0038CAD0(v + 0x40);
    if (func_0038CB00(v + 0x1C) != 0) {
        if (*(s16 *)(v + 0x1E) == 0) {
            if (*(s32 *)(v + 0x4C) == 0) func_003C2880(m);
            return;
        }
    }
    if (*(s32 *)(v + 0x50) < 4) func_L01_00404AD8_00349C58((void *)func_L01_0034ACD8_00349C58, m);

    if (*(s16 *)(v + 0x1E) >= 0x2D) {
        n = 20;
        switch (*(s32 *)(v + 0x50)) {
        case 2:
            n = 10;
            break;
        case 3:
            n = 5;
            break;
        case 4:
            n = 2;
            break;
        }
        for (i = 0; i < n; i++) {
            f = func_003824E0(16.0f, 32.0f);
            func_0038CE20(&q10, m + 0xC0, f * 0.020000001415610313f);
            t = func_L01_00443A18(0.2617993950843811f, 1.3962633609771729f);
            d = func_L01_00443A18(0.2617993950843811f, 1.3962633609771729f);
            func_003C4840(&q30, m + 0xD0, t);
            func_0038D850(&q20, &q10, &q30);
            func_003C4840(&q30, m + 0xC0, d);
            func_0038D850(&q20, &q20, &q30);
            j = (func_00382498(0x14, 0x28) * 5 + 2) / 6;
            func_L01_004CABD8(&q20, &q20, m + 0x10);
            func_L01_00470668(m + 0x10, &q20, j, 0.005840000230818987f);
        }
    }

    if (*(s32 *)(v + 0x50) < 3 && (u16)(*(u16 *)(v + 0x1E) - 11) < 0x16) {
        f32 a, b, c;
        a = func_003824E0(-0.9599310755729675f, -1.3962633609771729f);
        b = func_00382538();
        c = func_003824E0(0.0f, 0.5f);
        func_00382760(&q10, c * 0.020000001415610313f, b, a);
        f = func_003824E0(0.25f, 0.75f) * 210000.0f;
        func_0038CE20(&q20, m + 0xC0, -0.44999998807907104f);
        vec_add_ba(&q20, m + 0x10, &q20);
        q30.v[0] = q20.v[0] + func_L01_00443A18(0.0f, 0.25f);
        q30.v[1] = q20.v[1] + func_L01_00443A18(0.0f, 0.25f);
        q30.v[2] = q20.v[2] + func_L01_00443A18(0.0f, 0.25f);
        func_L01_004CABD8(&q10, &q10, &q30);
        func_L01_004708C8(&q30, &q10, 0x4F93E5FF, 0x102434EE, f, func_00382498(0x19, 0x25), 1, 0.5f, -1, -1, 0);
    }

    lim = ((f32)*(s16 *)(v + 0x1E) * *(f32 *)(v + 0x24) * -3.0f + 4.0f) * 1.5f;
    vy = *(f32 *)(v + 0x18);
    e = *(f32 *)(m + 0x18) - vy;
    if (0.0f < e && e < lim && *(s16 *)(v + 0x1E) >= 0x16) {
        f32 r = e / lim;
        f32 one = 1.0f;
        s32 c;
        s32 k;
        *(s128 *)&q10 = 0;
        q10.v[2] = one;
        q10.v[3] = one;
        c = (s32)((one - r) * 30.0f);
        r = r * -0.6499999761581421f;
        r = r + 0.75f;
        if (!(0 < c)) c = 1;
        func_0038CE90(&q20, &q10, m + 0xC0);
        nf = (f32)c;
        func_0038CF68(&q20, &q20, lim * r);
        *(Vec_00349C58 *)&q30 = *(Vec_00349C58 *)(m + 0x10);
        q30.v[2] = vy + 0.25f;
        vec_add_ba(&q40, &q30, &q20);
        vec_sub_ab(&q50, &q30, &q20);
        vec_sub_ab(&q60, &q50, &q40);
        func_0038CE20(&q60, &q60, one / nf);
        switch (*(s32 *)(v + 0x50)) {
        case 2:
            c = (s32)(nf * 0.6f);
            break;
        case 3:
            c = (s32)(nf * 0.3f);
            break;
        case 4:
            c = (s32)(nf * 0.1f);
            break;
        }
        for (k = 0; k < c; k++) {
            s32 r = func_00382468(0x10);
            s32 neg = func_00382468(2);
            u8 *o;
            if (neg != 0) r = -r;
            f = func_003824E0(0.20000000298023224f, 1.5f);
            o = func_L01_004669B0(&q40, 0.30000001192092896f, 1.0f, 0.8999999761581421f, f * 210000.0f, r, D_L01_001D66B0, 0x7F204080, 1);
            vec_add_ab(&q40, &q40, &q60);
            if (o != 0) {
                s32 rr;
                u8 *data;
                rr = func_00382498(8, 0x19);
                *(s16 *)(o + 0xA) = (rr * 5 + 2) / 6;
                o[9] = 0x44;
                data = o + 0x20;
                *(s32 *)(data + 4) = 2;
                data[0xA] = func_00382498(0x50, 0x7F);
                data[0xB] = o[0xA];
            }
        }
    }
}
/* localdecomp:end func_L01_00349C58 */

/* localdecomp:start func_L01_0034A3C8 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x10];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
} E_0034A3C8;

extern E_0034A3C8 D_L01_001E2A40_0034A3C8[] __asm__("D_L01_001E2A40");
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));
extern u8 *D_L01_00221098[];
extern s32 func_L01_00459590(void *, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_0034C300(u8 *, f32);
extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, f32, void *, u32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern f32 D_001A4EC0[];
extern void func_0038CE20(f32 *, f32 *, f32);

void func_L01_0034A3C8(u8 *a0, f32 *a1, s32 a2) {
    vu0_v4 sphere;
    vu0_v4 d;
    vu0_v4 mid;
    vu0_v4 p50;
    vu0_v4 v60;
    vu0_v4 p70;
    f32 heading;
    s32 n;
    s32 i;
    s32 j;
    s32 m;
    s32 s;
    vu0_v4 *pos = (vu0_v4 *)(a0 + 0x10);

    sphere = *pos;
    sphere.w = 2.0f;
    if (func_L01_00459590(&sphere, 0, 48.0f) == 1) {
        func_L01_0034C300(*(u8 **)(a0 + 0x68), func_0038CF00(pos, D_L01_001E2A40_0034A3C8));
        D_L01_001E2A40_0034A3C8[0].w28 = 0x21;
        D_L01_001E2A40_0034A3C8[0].f20 = 0.1f;
        D_L01_001E2A40_0034A3C8[0].w2C = 0;
    }
    func_L01_0044AF78(a0, D_L01_001D66B0, pos, 0, 0, 0, -1, 0,
                      0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.0f, 20.0f, 0, -1, 0, 0x1010001);
    vec_sub_ba(&d, D_L01_001E2A40_0034A3C8, pos);
    func_0038CF68(&d, &d, 0.5f);
    vec_add_ab(&mid, pos, &d);
    *pos = mid;
    heading = func_0038D160(D_L01_001E2A40_0034A3C8[0].pos.x - *(f32 *)(a0 + 0x10),
                            D_L01_001E2A40_0034A3C8[0].pos.y - *(f32 *)(a0 + 0x14));

    n = 20;
    switch (a2) {
    case 2:
        n = 10;
        break;
    case 3:
        n = 5;
        break;
    case 4:
        n = 1;
        break;
    }
    s = 1;
    for (i = 0; i < n; i++) {
        f32 a;
        f32 b;
        u8 *q;
        p50.x = mid.x + func_L01_00443A18(0.0f, 1.0f);
        s = -s;
        p50.y = mid.y + func_L01_00443A18(0.0f, 1.0f);
        p50.z = mid.z + func_L01_00443A18(0.0f, 1.0f);
        a = func_003824E0(0.020000001f, 0.040000003f);
        b = func_L01_00443A18(0.0f, 1.3962634f);
        func_00382760(&v60, a, func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.5707964f)), b);
        q = func_L01_004669B0(&p50, 0.0f, 1.0f, 1.01f, s, 315000.0f, &v60, 0x7F60A0FF, 1);
        if (q != 0) {
            s32 r;
            u8 *data;
            r = func_00382498(0x28, 0x46);
            q[9] = 0x44;
            *(s16 *)(q + 0xA) = (r * 5 + 2) / 6;
            data = q + 0x20;
            *(s32 *)(data + 4) = 3;
            r = func_00382498(1, 10);
            data[0xA] = 0x40;
            *(f32 *)(data + 0x1C) = (r * 5 + 2) / 6;
            data[0xB] = q[0xA];
        }
    }

    n = 32;
    switch (a2) {
    case 2:
        n = 16;
        break;
    case 3:
        n = 8;
        break;
    case 4:
        n = 2;
        break;
    }
    for (j = 0; j < n; j++) {
        s32 k;
        s32 col;
        s32 r;
        f32 sz;
        f32 big;
        f32 sp;
        f32 yaw;
        u8 *q;
        k = func_L01_00443A18(2.0f, 5.0f);
        r = func_00382498(0x32, 0x50);
        p50.x = mid.x + func_L01_00443A18(0.0f, 0.1f);
        p50.y = mid.y + func_L01_00443A18(0.0f, 0.1f);
        p50.z = mid.z + func_L01_00443A18(0.0f, 0.1f);
        sz = func_003824E0(0.35f, 0.75f);
        sp = func_003824E0(4.0f, 8.0f);
        yaw = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
        sp *= 0.020000001f;
        big = sz * 210000.0f;
        v60.x = func_0038D098(yaw) * sp;
        v60.y = func_0038D0B0(yaw) * sp;
        v60.z = 0.0f;
        v60.z = func_003824E0(0.0f, 12.0f) * 0.020000001f;
        col = (r * 5 + 2) / 6;
        func_L01_0046FB40(&p50, &v60, col, 0x7F7F7F, k, 0x7F, 0x7F, big, 2100.0f, 0.00584f, 1);
        p70.x = p50.x + func_L01_00443A18(0.0f, 0.01f);
        p70.y = p50.y + func_L01_00443A18(0.0f, 0.01f);
        p70.z = p50.z + func_L01_00443A18(0.0f, 0.01f);
        func_L01_0046FB40(&p70, &v60, col, 0x7F7F7F, -k, 0x7F, 0x7F, big, 2100.0f, 0.00584f, 1);
        k *= 2;
        sz *= 6.0f;
        q = func_L01_0046FB40(&p50, &v60, col, 0x202080, -k, 0x30, 0x30, sz * 210000.0f, 4200.0f, 0.00584f, 1);
        if (q != 0) {
            q[2] = *D_L01_00221098[0x35];
        }
    }

    vec_sub_ba(&p50, D_L01_001E2A40_0034A3C8, &mid);
    func_0038CF68(&p50, &p50, 1.0f);
    vec_add_ab(&mid, &mid, &p50);

    n = 20;
    switch (a2) {
    case 2:
        n = 10;
        break;
    case 3:
        n = 5;
        break;
    case 4:
        n = 1;
        break;
    }
    for (m = 0; m < n; m++) {
        s32 k;
        s32 r;
        f32 sz;
        u8 *q;
        func_0038CE20(&v60.x, D_001A4EC0, -(func_003824E0(0.2f, 3.0f) * 0.020000001f));
        r = (func_00382498(0x5A, 0xB4) * 5 + 2) / 6;
        k = func_L01_00443A18(1.0f, 2.0f);
        sz = func_003824E0(0.5f, 1.5f) * 210000.0f;
        p70.x = mid.x + func_L01_00443A18(0.0f, 0.75f);
        p70.y = mid.y + func_L01_00443A18(0.0f, 0.75f);
        p70.z = mid.z + func_L01_00443A18(0.0f, 0.75f);
        q = func_L01_004669B0(&p70, 0.0f, 1.0f, 1.01f, k, sz, &v60, 0x7F202020, 1);
        if (q != 0) {
            u8 *data;
            *(s16 *)(q + 0xA) = r;
            q[3] = 0x44;
            q[9] = 0x44;
            data = q + 0x20;
            k = func_00382498(7, 0xF);
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x7F;
            *(f32 *)(data + 0x1C) = (k * 5 + 2) / 6;
            data[0xB] = q[0xA];
        }
    }
}
/* localdecomp:end func_L01_0034A3C8 */

/* localdecomp:start func_L01_0034ACD8 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_0034ACD8;
typedef struct {
    f32 ang[6];
    u8 pad18[4];
    s16 h1C;
    s16 h1E;
    f32 f20;
    f32 f24;
    s16 h28;
    s16 h2A;
    f32 f2C;
    f32 f30;
    s16 h34;
    s16 h36;
    f32 f38;
    f32 f3C;
    s32 n40;
    f32 f44;
} V_0034ACD8;

static __inline__ f32 lerp_0034ACD8(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}

void func_L01_0034ACD8(u8 *a0) {
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern s32 func_0038CB00(void *);
    extern void func_003860A8(f32 *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_003A9440(s32, unsigned long);
    extern void func_00389478(void *, f32 *, f32 *);
    extern unsigned long func_00389598(s32);
    extern void func_003C5180(void *, f32 *, s32);
    Q_0034ACD8 q;
    vu0_v4 m[4];
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 basis[4];
    vu0_v4 cam;
    vu0_v4 t2;
    V_0034ACD8 *v;
    f32 len;
    f32 fade;
    f32 dot;
    f32 size;
    f32 t;
    f32 k;
    f32 c;
    s32 a;
    s32 i;

    vec_sub_ab(&d, a0 + 0x10, D_L01_001E2A40);
    v = *(V_0034ACD8 **)(a0 + 0x68);
    len = func_0038CEA8(&d);
    if (len != 0.0f) {
        func_0038CE20(&d, &d, 1.0f / len);
    }
    fade = 1.0f;
    if (len < 11.0f) {
        if (len <= 7.0f) {
            fade = 0.0f;
        } else {
            fade = (len - 7.0f) * 0.25f;
        }
    }
    dot = func_0038CE68(&d, a0 + 0xC0);
    t = v->h1C * v->f20;
    size = lerp_0034ACD8(20.0f, 2.0f, t);
    {
        s32 col;

        if (v->h1C < v->h28) {
            c = v->h1C * v->f2C;
            col = (s32)(c * 60.0f * dot * dot) << 24;
        } else {
            col = (s32)(dot * 60.0f * dot) << 24;
        }
        /* 1 */
        if (fabs_asm(v->ang[0]) > 1e-5f) {
            func_003C4840(&r, a0 + 0xC0, v->ang[0]);
            func_0038D850(&m[1], a0 + 0xD0, &r);
            func_0038D850(&m[2], a0 + 0xE0, &r);
        } else {
            m[1] = *(vu0_v4 *)(a0 + 0xD0);
            m[2] = *(vu0_v4 *)(a0 + 0xE0);
        }
        m[3] = *(vu0_v4 *)(a0 + 0x10);
        func_0038CE20(&m[0], a0 + 0xC0, size);
        func_0038CE20(&m[1], &m[1], size);
        func_0038CE20(&m[2], &m[2], size);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        func_003D93B0(&q, 0x38, 1, 0x80);
        q.col[3] = col | 0x7F7F7F;
        q.col[2] = col | 0x7F7F7F;
        q.col[1] = col | 0x7F7F7F;
        q.col[0] = col | 0x7F7F7F;
        q.uv[0][0] = 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = 0.0f;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = 1.0f;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = 1.0f;
        q.uv[3][1] = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);
        /* 2 */
        if (fabs_asm(v->ang[0]) > 1e-5f) {
            func_003C4840(&r, a0 + 0xC0, -v->ang[0]);
            func_0038D850(&m[1], a0 + 0xD0, &r);
            func_0038D850(&m[2], a0 + 0xE0, &r);
        } else {
            m[1] = *(vu0_v4 *)(a0 + 0xD0);
            m[2] = *(vu0_v4 *)(a0 + 0xE0);
        }
        m[3] = *(vu0_v4 *)(a0 + 0x10);
        func_0038CE20(&m[0], a0 + 0xC0, size);
        func_0038CE20(&m[1], &m[1], size);
        func_0038CE20(&m[2], &m[2], size);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);
        t = v->h1E * v->f24;
        size = lerp_0034ACD8(4.0f, 1.0f, t);
        if (v->h1E < v->h2A) {
            c = func_L01_004451D0(1.0f, 0.0f, 1.0f, 2.0f, v->h1E * v->f30);
        } else {
            c = 1.0f;
        }
        col = (s32)(c * 255.0f * fade);
        a = (s32)(col * 0.2f) << 24;
        col <<= 24;
        q.col[3] = a | 0xFFFFFF;
        q.col[2] = a | 0xFFFFFF;
        q.col[1] = a | 0xFFFFFF;
        q.col[0] = a | 0xFFFFFF;
        /* 3 */
        if (fabs_asm(v->ang[1]) > 1e-5f) {
            func_003C4840(&r, a0 + 0xC0, v->ang[1]);
            func_0038D850(&m[1], a0 + 0xD0, &r);
            func_0038D850(&m[2], a0 + 0xE0, &r);
        } else {
            m[1] = *(vu0_v4 *)(a0 + 0xD0);
            m[2] = *(vu0_v4 *)(a0 + 0xE0);
        }
        k = size * 1.5f;
        func_0038CE20(&m[0], a0 + 0xC0, k);
        func_0038CE20(&m[1], &m[1], k);
        func_0038CE20(&m[2], &m[2], k);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);
        a = (s32)(c * 255.0f * fade * 1.5f);
        if (a > 255) {
            a = 255;
        }
        func_003D93B0(&q, 0x39, 1, 0x80);
        basis[3] = *(vu0_v4 *)(a0 + 0x10);
        q.col[3] = (a << 24) | 0xFFFFFF;
        q.col[2] = (a << 24) | 0xFFFFFF;
        q.col[1] = (a << 24) | 0xFFFFFF;
        q.col[0] = (a << 24) | 0xFFFFFF;
        q.uv[0][0] = 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = 0.0f;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = 1.0f;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = 1.0f;
        q.uv[3][1] = 1.0f;
        /* 4 */
        if (fabs_asm(v->ang[2]) > 1e-5f) {
            func_003C4840(&r, a0 + 0xC0, v->ang[2]);
            func_0038D850(&m[1], a0 + 0xD0, &r);
            func_0038D850(&m[2], a0 + 0xE0, &r);
        } else {
            m[1] = *(vu0_v4 *)(a0 + 0xD0);
            m[2] = *(vu0_v4 *)(a0 + 0xE0);
        }
        k = size * 1.25f;
        func_0038CE20(&m[0], a0 + 0xC0, k);
        func_0038CE20(&m[1], &m[1], k);
        func_0038CE20(&m[2], &m[2], k);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);
        /* 5 */
        if (fabs_asm(v->ang[3]) > 1e-5f) {
            func_003C4840(&r, a0 + 0xC0, v->ang[3]);
            func_0038D850(&m[1], a0 + 0xD0, &r);
            func_0038D850(&m[2], a0 + 0xE0, &r);
        } else {
            m[1] = *(vu0_v4 *)(a0 + 0xD0);
            m[2] = *(vu0_v4 *)(a0 + 0xE0);
        }
        m[3] = *(vu0_v4 *)(a0 + 0x10);
        func_0038CE20(&m[0], a0 + 0xC0, size);
        func_0038CE20(&m[1], &m[1], size);
        func_0038CE20(&m[2], &m[2], size);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);
        q.col[3] = col | 0xFFFFFF;
        q.col[2] = col | 0xFFFFFF;
        q.col[1] = col | 0xFFFFFF;
        q.col[0] = col | 0xFFFFFF;
        vec_sub_ab(&r, D_L01_001E2A40, a0 + 0x10);
        func_0038CF68(&r, &r, 0.25f);
        vec_add_ba(&m[3], a0 + 0x10, &r);
        {
            vu0_v4 *b = basis;
            func_003C5180(&b[3], &cam.x, 1);
            vec_sub_ba(&b[0], D_L01_001E2A40, &m[3]);
            func_0038CF68(&b[0], &b[0], 1.0f);
            func_0038CE90(&b[1], &b[0], &cam);
            func_0038CF68(&b[1], &b[1], 1.0f);
            func_0038CE90(&b[2], &b[1], &b[0]);
        }    /* 6 */
        if (fabs_asm(v->ang[4]) > 1e-5f) {
            func_003C4840(&t2, &basis[0], v->ang[4]);
            func_0038D850(&m[1], &basis[1], &t2);
            func_0038D850(&m[2], &basis[2], &t2);
        } else {
            m[1] = basis[1];
            m[2] = basis[2];
        }
        func_0038CE20(&m[0], &basis[0], size);
        func_0038CE20(&m[1], &m[1], size);
        func_0038CE20(&m[2], &m[2], size);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);

        /* 7 */
        if (fabs_asm(v->ang[5]) > 1e-5f) {
            func_003C4840(&t2, &basis[0], v->ang[5]);
            func_0038D850(&m[1], &basis[1], &t2);
            func_0038D850(&m[2], &basis[2], &t2);
        } else {
            m[1] = basis[1];
            m[2] = basis[2];
        }
        k = size * 0.75f;
        func_0038CE20(&m[0], &basis[0], k);
        func_0038CE20(&m[1], &m[1], k);
        func_0038CE20(&m[2], &m[2], k);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);

        a = (s32)((f32)((col >> 24) & 0xFF) * 0.2f) << 24;
        func_003D93B0(&q, 0x38, 1, 0x80);
        q.col[3] = a | 0xFFFFFF;
        q.col[2] = a | 0xFFFFFF;
        q.col[1] = a | 0xFFFFFF;
        q.col[0] = a | 0xFFFFFF;
        /* 8 */
        if (fabs_asm(v->ang[1]) > 1e-5f) {
            func_003C4840(&t2, &basis[0], v->ang[1]);
            func_0038D850(&m[1], &basis[1], &t2);
            func_0038D850(&m[2], &basis[2], &t2);
        } else {
            m[1] = basis[1];
            m[2] = basis[2];
        }
        k = size * 1.5f;
        func_0038CE20(&m[0], &basis[0], k);
        func_0038CE20(&m[1], &m[1], k);
        func_0038CE20(&m[2], &m[2], k);
        m[0].w = m[1].w = m[2].w = 0.0f;
        m[3].w = 1.0f;
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                func_0038D028(&q.v[j], D_L01_001D7C50[j], m);
            }
        }
        func_003D2DA0(&q, 0, 0);
        if (func_0038CB00(&v->h36) == 0) {
            func_003860A8(&t2.x, a0 + 0x10);
            if (28492.0f <= t2.x && t2.x <= 37082.0f && 28492.0f <= t2.y && t2.y <= 37082.0f) {
                vu0_v4 ax;
                f32 w[4];
                vu0_v4 off;
                vu0_v4 sd;
                vu0_v4 o;
                vu0_v4 o2;
                f32 one;
                f32 W;
                f32 iW;
                f32 rx;
                f32 ry;
                f32 u;
                f32 mn;
                t2.x -= 28492.0f;
                t2.y -= 28492.0f;
                one = 1.0f;
                W = 8590.0f;
                iW = 1.0f / 8590.0f;
                c = v->h36 * v->f38;
                col = (s32)(c * 64.0f) << 24;
                func_0038D890(&ax, &cam, &d, 0.7853982f);
                func_003D93B0(&q, 0xB, 1, 0x80);
                q.u70 = 5;
                q.uv[0][0] = 0.0f;
                q.uv[0][1] = 1.0f;
                q.uv[1][0] = 1.0f;
                q.uv[1][1] = 1.0f;
                q.uv[2][0] = 0.0f;
                q.uv[2][1] = 0.0f;
                q.uv[3][0] = 1.0f;
                q.uv[3][1] = 0.0f;
                q.col[1] = 0x104050;
                q.col[0] = 0x104050;
                q.col[3] = col | 0x104050;
                q.col[2] = col | 0x104050;
                mn = t2.x < t2.y ? t2.x : t2.y;
                u = mn * iW;
                if (u < 0.5f) {
                    w[3] = lerp_0034ACD8(0.0f, one, u * 2.0f);
                } else {
                    w[3] = lerp_0034ACD8(one, 6.0f, (u - 0.5f) * 2.0f);
                }
                ry = W - t2.y;
                mn = t2.x < ry ? t2.x : ry;
                u = mn * iW;
                if (u < 0.5f) {
                    w[2] = lerp_0034ACD8(0.0f, 1.0f, u * 2.0f);
                } else {
                    w[2] = lerp_0034ACD8(1.0f, 6.0f, (u - 0.5f) * 2.0f);
                }
                rx = W - t2.x;
                mn = rx < ry ? rx : ry;
                u = mn * iW;
                if (u < 0.5f) {
                    w[1] = lerp_0034ACD8(0.0f, 1.0f, u * 2.0f);
                } else {
                    w[1] = lerp_0034ACD8(1.0f, 6.0f, (u - 0.5f) * 2.0f);
                }
                mn = rx < t2.y ? rx : t2.y;
                u = mn * iW;
                if (u < 0.5f) {
                    w[0] = lerp_0034ACD8(0.0f, 1.0f, u * 2.0f);
                } else {
                    w[0] = lerp_0034ACD8(1.0f, 6.0f, (u - 0.5f) * 2.0f);
                }
                func_0038CF68(&off, &d, 2.0f);
                for (i = 0; i < 4; i++) {
                    func_0038CF68(&ax, &ax, w[i]);
                    func_0038CE90(&sd, &d, &ax);
                    func_0038CF68(&sd, &sd, 0.01f);
                    vec_add_ba(&o, D_L01_001E2A40, &off);
                    vec_sub_ba(&o2, &o, a0 + 0x10);
                    vec_add_ba(&q.v[0], &o, &sd);
                    vec_sub_ab(&q.v[1], &o, &sd);
                    vec_add_ab(&o, a0 + 0x10, &ax);
                    vec_add_ba(&o, &o2, &o);
                    func_0038CE20(&sd, &sd, 5.0f);
                    vec_add_ab(&q.v[2], &o, &sd);
                    vec_sub_ab(&q.v[3], &o, &sd);
                    func_003D2DA0(&q, 0, 0);
                    if (i < 3) {
                        func_0038D890(&ax, &ax, &d, 1.5707964f);
                    }
                }
            }
        }
        if (v->h34 != 0) {
          {
            vu0_v4 dd;
            vu0_v4 o;
            vu0_v4 sx;
            vu0_v4 sy;
            vu0_v4 o2;
            c = v->h34 * v->f3C;
            func_003D93B0(&q, 0xB, 4, 0x80);
            q.col[3] = ((s32)(c * 255.0f) << 24) | 0x808080;
            q.col[2] = ((s32)(c * 255.0f) << 24) | 0x808080;
            q.col[1] = ((s32)(c * 255.0f) << 24) | 0x808080;
            q.col[0] = ((s32)(c * 255.0f) << 24) | 0x808080;
            q.uv[0][0] = 0.0f;
            q.uv[0][1] = 0.0f;
            q.uv[1][0] = 0.0f;
            q.uv[1][1] = 1.0f;
            q.uv[2][0] = 1.0f;
            q.uv[2][1] = 0.0f;
            q.uv[3][0] = 1.0f;
            q.uv[3][1] = 1.0f;
            vec_sub_ba(&t2, a0 + 0x10, D_L01_001E2A40);
            func_0038CF68(&dd, &t2, 0.1f);
            vec_add_ba(&o, D_L01_001E2A40, &dd);
            func_0038CE90(&sx, &t2, &cam);
            func_0038CF68(&sx, &sx, 0.075f);
            func_0038CE90(&sy, &sx, &t2);
            func_0038CF68(&sy, &sy, 0.075f);
            vec_add_ba(&o2, &o, &sy);
            vec_add_ab(&q.v[0], &o2, &sx);
            vec_sub_ab(&q.v[1], &o2, &sx);
            vec_sub_ab(&o2, &o, &sy);
            vec_add_ab(&q.v[2], &o2, &sx);
            vec_sub_ab(&q.v[3], &o2, &sx);
            func_003D2DA0(&q, 0, 0);
          }
        }
        if (v->n40 != 0 && v->n40 < 13) {
            vu0_v4 B;
            vu0_v4 C;
            vu0_v4 X;
            vu0_v4 Y;
            vu0_v4 Z;
            vu0_v4 P;
            vu0_v4 D;
            s32 j;
            s32 k;
            s32 cc;
            f32 s;
            f32 tt;
            tt = v->n40 * v->f44;
            s = lerp_0034ACD8(0.5f, 0.0f, tt);
            vec_sub_ba(&t2, a0 + 0x10, D_L01_001E2A40);
            func_0038CF68(&t2, &t2, 0.3f);
            vec_add_ba(&B, D_L01_001E2A40, &t2);
            func_003D93B0(&q, 0x36, 1, 0x80);
            q.gif = 0x800000004AUL;
            C = cam;
            cc = ((s32)(tt * 255.0f) << 24) | 0x808080;
            q.col[3] = cc;
            q.col[2] = cc;
            q.col[1] = cc;
            q.col[0] = cc;
            q.uv[0][0] = 0.0f;
            q.uv[0][1] = 0.0f;
            q.uv[1][0] = 0.0f;
            q.uv[1][1] = 1.0f;
            q.uv[2][0] = 1.0f;
            q.uv[2][1] = 0.0f;
            q.uv[3][0] = 1.0f;
            q.uv[3][1] = 1.0f;
            func_0038CE90(&X, &t2, &C);
            func_0038CF68(&X, &X, s);
            func_0038CE90(&Y, &X, &t2);
            func_0038CF68(&Y, &Y, s);
            vec_add_ba(&Z, &B, &Y);
            vec_add_ba(&q.v[0], &Z, &X);
            vec_sub_ab(&q.v[1], &Z, &X);
            vec_sub_ba(&Z, &B, &Y);
            vec_add_ab(&q.v[2], &Z, &X);
            vec_sub_ab(&q.v[3], &Z, &X);
            func_003A9440(0x47, 0x31001);
            func_003D2DA0(&q, 0, 0);
            func_003A9440(0x47, 0x33001);
            qzero(&P);
            for (k = 0; k < 4; k++) {
                vec_add_ba(&P, &P, &q.v[k]);
            }
            func_0038CE20(&P, &P, 0.25f);
            for (j = 0; j < 4; j++) {
                vec_sub_ba(&D, &q.v[j], &P);
                func_0038CE20(&D, &D, 0.8f);
                vec_add_ab(&D, &P, &D);
                func_00389478(&q.v[j], &q.uv[j][0], &q.uv[j][1]);
                if (q.uv[j][0] > 0.9f) {
                    q.uv[j][0] = 0.9f;
                } else if (q.uv[j][0] < 0.0f) {
                    q.uv[j][0] = 0.0f;
                }
                if (q.uv[j][1] > 0.9f) {
                    q.uv[j][1] = 0.9f;
                } else if (q.uv[j][1] < 0.0f) {
                    q.uv[j][1] = 0.0f;
                }
            }
            q.u78 = func_00389598(-7);
            q.u80 = 0xFF9000000260UL;
            q.gif = 0x8000000054UL;
            q.u70 = 0;
            func_003D2DA0(&q, 0, 0);
        }
    }
}
/* localdecomp:end func_L01_0034ACD8 */

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

/* localdecomp:start func_L01_0034C4E8 */
extern vu0_q D_001A4BE0;
extern S_27F600 D_L01_0027F580[];
extern u8 *D_L01_001EEA80[];
typedef struct {
    s32 f0, color1, color2;
    f32 angle, power, period;
    u8 *moby;
    f32 timer;
    s32 f20, count, f28, f2C;
} Effect_0034C4E8;
void func_L01_0034C4E8(u8 *self) {
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_0038CAD0(void *);
    extern s32 func_L01_0040E050(void *);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern f32 *func_00382348(void *);
    extern s32 func_0013D3E0(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_0034D078(void *, void *, void *, void *, void *, s32, s32, s32, void *, f32);
    extern void func_L01_0034C910(u8 *s);
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern void func_L01_0034D2F0(void *);
    extern void func_L01_0034CF88(s32);
    extern void func_L01_00404A10(void *, void *);
    vu0_v4 first, second;
    vu0_v4 *pf;
    vu0_v4 *ps;
    s32 i = 0;
    *(vu0_q *)(self + 0x10) = D_001A4BE0;
    do {
        s32 next = i + 1;
        if (D_L01_0027F580[i].x18 != 0) {
            Effect_0034C4E8 *p = (Effect_0034C4E8 *)&D_L01_0027F580[i];
            s32 dead;
            p->angle = func_0038DAB8(p->angle, 0.25132742524147034f);
            dead = 0;
            if (*(s8 *)(p->moby + 0x20) < 0) dead = 1;
            if (*(s32 *)(p->moby + 0x98) == 0) dead = 1;
            if (func_0038CAD0(p)) dead = 1;
            if (func_L01_0040E050(&p->timer)) {
                s32 n, j;
                p->timer = p->period;
                n = func_003D4D00(p->moby + 0x10, 0, 8.0f, p->moby, 0);
                for (j = 0; j < n; j++) {
                    u8 *target = D_L01_001EEA80[j];
                    f32 *damage = func_00382348(target);
                    if ((*(u16 *)(target + 0x34) & 0x1000) && target != 0 && target[0x20] != 0xFE && target[0x20] != 0xFD && target[0x31] != 0 && !(*(u16 *)(target + 0x34) & 2) && (*(u8 **)(target + 0x24))[0x46] == 5 && *(s16 *)(target + 0xAA) != 0x1AE6 && damage && damage[0] > 0.0f) {
                        pf = &first;
                        qzero(&first);
                        func_L01_0034D078(self, p->moby, target, pf, pf, 1, 10, 30, p, p->power);
                        func_L01_0034D078(self, p->moby, target, pf, pf, 0, 10, 30, p, 0.0f);
                        break;
                    }
                }
            }
            if (func_0013D3E0() % 11 == 0) {
                s32 life1, life2;
                ps = &second;
                func_00382760(&first, *(f32 *)(p->moby + 0xC) * 0.0009765f * func_003824E0(0.3f, 0.65f), func_00382538(), func_00382538());
                func_00382760(ps, *(f32 *)(p->moby + 0xC) * 0.0009765f * func_003824E0(0.3f, 0.65f), func_00382538(), func_00382538());
                life1 = func_00382498(5, 15);
                life2 = func_00382498(15, 30);
                func_L01_0034D078(self, p->moby, p->moby, &first, ps, 0, life1, life2, p, 0.0f);
            }
            if (dead) {
                func_L01_0034C910((u8 *)p);
                p->moby = 0;
            } else if (p->count == 0) {
                s32 color = func_0038DBD8(p->color1, p->color2, (func_0038D098(p->angle) + 1.0f) * 0.5f);
                func_L01_0043B9E8(p->moby, color & 255, (color >> 8) & 255, (color >> 16) & 255);
            } else p->count--;
        }
        i = next;
    } while (i < 30);
    func_L01_0034D2F0(self);
    func_L01_00404A10(func_L01_0034CF88, self);
}
/* localdecomp:end func_L01_0034C4E8 */

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

/* localdecomp:start func_L01_0034C9F0 */
typedef struct { u8 active, level; u8 pad2[0x46]; s16 replacement; u8 pad4A[0x22]; f32 damage; u8 pad70[0x80]; } Weapon_0034C9F0;
typedef struct { f32 damage, arc_damage; s32 seconds; f32 interval; } Row_0034C9F0;
typedef struct {
    s32 timer;
    s32 color;
    s32 amount;
    f32 threshold;
    f32 arc;
    f32 rate;
    u8 *target;
    s32 zero;
    s32 owner;
    s32 active;
    u8 pad28[8];
} Shock_0034C9F0;
typedef struct {
    s128 position;
    u8 pad10[8];
    u8 kind, active;
    u16 class_id;
    u8 pad1C[4];
    s32 enabled;
    u8 pad24[12];
} Hit_0034C9F0;
extern Weapon_0034C9F0 D_L01_002C5600[];
extern u8 D_00142A60[];
extern u8 D_001425C0[];
extern s32 D_001A5E08[];
extern Row_0034C9F0 D_L01_00282220_0034C9F0[][204];
__asm__(".extern D_L01_001DD3D8, 4");
extern s32 D_L01_001DD3D8;

/* the item (through the D_001425C0 map) is owned and at the given level */
static __inline__ u8 atLevel_0034C9F0(s32 n, s32 level) {
    if (D_L01_002C5600[D_001425C0[n]].active) {
        if (D_L01_002C5600[D_001425C0[n]].level == level) return 1;
        return 0;
    }
    return 0;
}
/* the item (through the D_001425C0 map) is owned and at level 3 */
static __inline__ u8 isV3_0034C9F0(s32 n) {
    u8 v3;
    return v3 = D_L01_002C5600[D_001425C0[n]].active && D_L01_002C5600[D_001425C0[n]].level == 3;
}
s32 func_L01_0034C9F0(u8 *m, s32 weapon, s32 owner) {
    extern f32 *func_00382348(u8 *);
    extern s32 func_L01_0034C990(s32);
    extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
    extern void func_L01_00446760(void *, s32, s32, void *, f32);
    extern void func_L01_00446978(u8 *, void *);
    f32 direction[4] __attribute__((aligned(16)));
    Hit_0034C9F0 hit;
    s32 result = 1;
    s32 bank1_level = 2; /* the first item level of the second table bank */
    s32 mode;
    s32 effective = ((Weapon_0034C9F0 *)(weapon * 240 + (u8 *)D_L01_002C5600))->replacement;
    unsigned long flags;
    f32 *health;
    s32 i;
    s32 r, g, b;
    s32 override;
    Shock_0034C9F0 *slot;
    if (effective == 0) effective = weapon;
    flags = D_00142A60[effective];
    if (((flags >> 1) & 1) == 0) return 1;
    mode = 0;
    if (atLevel_0034C9F0(effective, bank1_level) || isV3_0034C9F0(effective)) mode = 1;
    if ((*(u8 **)(m + 0x24))[0x46] != 5) return 1;
    if ((*(u16 *)(m + 0x34) & 0x1000) == 0) return 1;
    if (*(s8 *)(m + 0x20) < 0) return 1;
    if (*(s32 *)(m + 0x98) == 0) return 1;
    {
        f32 *hp = func_00382348(m);
        if (hp == 0) return 1;
        if (*hp <= 0.0f) return 1;
    }
    if (func_L01_0034C990((s32)m) != -1) return 1;
    override = D_001A5E08[0];
    for (i = 0; i < 30; i++) {
        if (D_L01_0027F580[i].x18 == 0) {
            u8 *q;
            s32 got;
            slot = (Shock_0034C9F0 *)&D_L01_0027F580[i];
            slot->timer = D_L01_00282220_0034C9F0[mode][weapon].seconds * 50;
            slot->arc = D_L01_00282220_0034C9F0[mode][weapon].arc_damage;
            if (override == 0x27) slot->arc = ((Weapon_0034C9F0 *)(D_001425C0[0x27] * 240 + (u8 *)D_L01_002C5600))->damage * 0.25f;
            else if (override == 0x77) slot->arc = ((Weapon_0034C9F0 *)(D_001425C0[0x77] * 240 + (u8 *)D_L01_002C5600))->damage * 0.25f;
            else if (override == 0x2F) slot->arc = ((Weapon_0034C9F0 *)(D_001425C0[0x2F] * 240 + (u8 *)D_L01_002C5600))->damage * 0.25f;
            else if (override == 0x15) slot->arc = ((Weapon_0034C9F0 *)(D_001425C0[0x15] * 240 + (u8 *)D_L01_002C5600))->damage * 0.25f;
            else if (override == 0x47) slot->arc = ((Weapon_0034C9F0 *)(D_001425C0[0x47] * 240 + (u8 *)D_L01_002C5600))->damage * 0.25f;
            slot->rate = (D_L01_00282220_0034C9F0[mode][weapon].interval * 5.0f + 2.0f) / 6.0f;
            slot->target = m;
            slot->owner = owner;
            slot->zero = 0;
            health = func_00382348(m);
            *health -= D_L01_00282220_0034C9F0[mode][weapon].damage;
            got = 0;
            if (*(u16 *)(slot->target + 0x34) & 0x20) {
                q = *(u8 **)(*(u8 **)(slot->target + 0x68) + 0x10);
                if (q != 0 && *(s16 *)q != 0) {
                    r = q[4]; g = q[5]; b = q[6];
                    got = 1;
                }
            }
            if (!got) func_003C6FB0(slot->target, &r, &g, &b);
            slot->threshold = 0.0f;
            slot->amount = 0xFF0000;
            slot->active = 1;
            slot->color = (b << 16) + (g << 8) + r;
            result = 0;
            if (*health <= slot->threshold && D_L01_001DD3D8 != 0) {
                s32 who;
                func_0038CE20(direction, (f32 *)(slot->target + 0xC0), -1.0f);
                func_0038CF68(&hit, &hit, 0.002f);
                who = slot->owner;
                *(s32 *)(D_L01_001DD3D8 + 0xB8) = who;
                func_L01_00446760(&hit, who, 0x410000, direction, 0.001f);
                hit.position = *(s128 *)direction;
                ((f32 *)&hit)[3] = 5627.9248046875f;
                hit.kind = 5;
                hit.enabled = 1;
                hit.active = 1;
                hit.class_id = *(u16 *)(slot->target + 0xAA);
                func_L01_00446978(slot->target, &hit);
                slot->target = 0;
            }
            break;
        }
    }
    return result;
}
/* localdecomp:end func_L01_0034C9F0 */

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
