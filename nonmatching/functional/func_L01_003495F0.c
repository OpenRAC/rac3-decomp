/* functional: high. Near miss (221 words): scheduling/allocation only; full asm read against C. */
/* localdecomp:start func_L01_003495F0 */
#include "vu0.h"
__asm__(".extern D_001DD3C4_sda, 4");
__asm__(".extern D_001DD3B8_sda, 4");
__asm__(".extern D_001DD3C0_sda, 4");
__asm__(".extern D_001DD3BC_sda, 4");
extern s32 D_001DD3C4_sda;
extern f32 D_001DD3B8_sda;
extern s32 D_001DD3C0_sda;
extern s32 D_001DD3BC_sda;
extern void *D_001E1A04_sda;
typedef struct { u8 pad0[0x16B0]; s32 w16B0; u8 pad16B4[0x25C4-0x16B4]; s32 w25C4; } Game_003495F0;
extern Game_003495F0 D_001A4BE0;
extern f32 D_L01_001E29C0[];
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
    v.basis[2] = v.basis[3] = 1.0f;
    fade = (f32)D_001DD3C4_sda;
    if (D_001A4BE0.w25C4 == 29 || D_001A4BE0.w16B0 != 0) fade *= 0.5f;
    func_003D93B0(&v, D_001E1A04_sda, 0, 0x80);
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
            color |= func_0038DBD8(D_001DD3C0_sda, D_001DD3BC_sda, fabs_asm(func_0038D0B0(func_L01_0044AE78(t * (D_001DD3B8_sda * 3.1415927f)))));
            v.colors[0] = v.colors[1] = v.colors[2] = v.colors[3] = color;
            x = s->grow_a + (s->size_a - s->grow_a) * t;
            y = s->grow_b + (s->size_b - s->grow_b) * t;
            { f32 phase = func_0038DAB8(*(f32 *)&s->age, s->swing); *(f32 *)&s->age = phase; }
            dx = s->x38 * x * func_0038D098(*(f32 *)&s->age);
            dy = *(f32 *)((u8 *)s + 0x3C) * y * func_0038D0B0(*(f32 *)&s->age);
            *(s128 *)v.pos = *(s128 *)s->pos;
            __asm__("lqc2 $vf2, 0(%3)\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)v.a) : "m"(*(vu0_v4 *)D_L01_001E29C0), "m"(*(vu0_v4 *)v.pos), "r"(D_L01_001E29C0) : "vf1", "vf2");
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
                v.corner[0] = template[0];
                v.scratch[1] = ty; v.scratch[2] = tz;
                v.scratch[0] = template[0];
                v.corner[2] = ty * sn + tz * cs;
                v.corner[1] = ty * cs - tz * sn;
                func_0038D028(dest, v.corner, v.a);
                dest += 4; template += 4;
            }
            func_003D2DA0(&v, 0, 0);
        }
        i = next;
    }
}
/* localdecomp:end func_L01_003495F0 */
