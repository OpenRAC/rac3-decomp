/* PAL near miss, 2026-11-27: 2 of 560 words differ with the owning file's flags
 * (L07_003AF600.c: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as),
 * written from asm. Register allocation, stack layout and every store match; the only
 * difference is in the strip loop's preheader, where retail schedules `ori $v1, 0x2020`
 * (the 0x202020 colour constant) before the `vsub.xyz vf1, vf0, vf1` of vec_neg(&dir) and
 * this C after it. Unchanged by all 720 orders of the preheader statements, the colour
 * expression forms, the colour computed inside the loop, local declaration order and a
 * 20-minute permuter run. Levers that got here are in notes (strip loop indexed by i,
 * separate counters j/k, colour stores in scrambled order, D_L07_001D9AE0 in .sdata for
 * the `la` + delay-slot nop). Splice in place of the INCLUDE_ASM line. */
#include "common.h"
#include "vu0.h"
extern u8 D_L07_001E1EC0[];
extern void func_L07_003B1C08(void *);
/* localdecomp:start func_L07_003B1C08 */
typedef struct {
    vu0_v4 pos;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    u8 b24;
} Priv_003B1C08;
typedef struct { f32 x, y, z; } V3_003B1C08;
extern vu0_v4 D_L07_001D9AE0 __attribute__((section(".sdata")));
extern V3_003B1C08 D_L07_002A24C0[];
extern u32 D_L07_002A2808[];
extern f32 D_L07_002A26B8[];
typedef struct { f32 u, v; } UV_003B1C08;
extern UV_003B1C08 D_L07_001DE448[] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DE448, 4");

static __inline__ void put_003B1C08(V3_003B1C08 *d, vu0_v4 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

void func_L07_003B1C08(void *arg0) {
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CC88(void *, void *, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038DB48(f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern long func_00389598(s32);
    extern void func_003A9440(s32, unsigned long);
    extern void func_0038C750(void);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    vu0_v4 end;
    vu0_v4 dir;
    vu0_v4 tmp;
    vu0_v4 side0;
    vu0_v4 side1;
    vu0_v4 toCam;
    vu0_v4 quad;
    vu0_v4 point;
    vu0_v4 wave;
    vu0_v4 sum;
    vu0_v4 off;
    Priv_003B1C08 *p;
    f32 fade;
    f32 t;
    f32 angle;
    f32 c;
    f32 d;
    f32 width;
    f32 step;
    f32 freq;
    f32 alpha;
    f32 size;
    u32 color;
    u32 color1;
    u32 color2;
    u32 color3;
    u32 edge;
    s32 i;
    s32 j;
    s32 k;
    u8 *obj = arg0;

    if (obj == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD || *(s16 *)(obj + 0xAA) != 0x19F3) {
        return;
    }
    p = *(Priv_003B1C08 **)(obj + 0x68);
    if (p->f14 < 1.0f) {
        tmp = *(vu0_v4 *)(obj + 0x10);
        func_0038CE20(&dir, obj + 0xC0, p->f10);
        vec_add_ba(&end, &tmp, &dir);
        fade = 1.0f - p->f14;
        func_003A9440(6, func_00389598(0x17));
        func_003A9440(8, 0);
        func_003A9440(0x42, 0x8000000044UL);
        func_0038C750();
        vec_sub_ba(&toCam, (vu0_v4 *)D_L07_001E1EC0, &end);
        func_0038CE90(&side0, &dir, &toCam);
        func_0038CF68(&side0, &side0, fade * 0.2f);
        vec_sub_ba(&toCam, (vu0_v4 *)D_L07_001E1EC0, &tmp);
        func_0038CE90(&side1, &dir, &toCam);
        func_0038CF68(&side1, &side1, fade * 0.05f);
        vec_add_ab(&quad, &end, &side0);
        put_003B1C08(&D_L07_002A24C0[0], &quad);
        vec_sub_ab(&quad, &end, &side0);
        put_003B1C08(&D_L07_002A24C0[1], &quad);
        vec_add_ab(&quad, &tmp, &side1);
        put_003B1C08(&D_L07_002A24C0[2], &quad);
        vec_sub_ab(&quad, &tmp, &side1);
        put_003B1C08(&D_L07_002A24C0[3], &quad);
        color1 = ((s32)(fade * 160.0f) << 24) | 0x806040;
        D_L07_002A2808[1] = color1;
        D_L07_002A2808[0] = color1;
        D_L07_002A2808[3] = 0x800603;
        D_L07_002A2808[2] = 0x800603;
        func_003D3A24(4, D_L07_002A24C0, D_L07_002A2808, D_L07_001DE448, 1);

        func_003A9440(6, func_00389598(0x15));
        func_003A9440(8, 0);
        func_003A9440(0x42, 0x8000000048UL);
        func_0038C750();
        color = ((s32)(fade * 64.0f) << 24) | 0x202020;
        freq = p->f10 * 6.2831855f * 0.125f;
        width = p->f14 * 1.5f + 0.5f;
        step = p->f14 * 0.8f + 0.2f;
        vec_neg(&dir, &dir);
        for (i = 0; i <= 20; i++) {
            t = (f32)i / 20.0f;
            angle = func_0038DB48(t * freq + p->f18);
            func_0038CE20(&point, &dir, t * t);
            vec_add_ab(&point, &end, &point);
            qzero(&wave);
            c = func_0038D098(angle);
            if (c != 0.0f) {
                func_0038CE20(&sum, obj + 0xD0, c);
                vec_add_ab(&wave, &wave, &sum);
            }
            c = func_0038D0B0(angle);
            if (c != 0.0f) {
                func_0038CE20(&sum, obj + 0xE0, c);
                vec_add_ab(&wave, &wave, &sum);
            }
            func_0038CE20(&off, &wave, width);
            vec_add_ab(&sum, &point, &off);
            put_003B1C08(&D_L07_002A24C0[i * 2], &sum);
            func_0038CE20(&off, &wave, width + step);
            vec_add_ab(&sum, &point, &off);
            put_003B1C08(&D_L07_002A24C0[i * 2 + 1], &sum);
            edge = func_0038DBD8(color, 0xFFFFFF, t);
            D_L07_002A2808[i * 2] = edge;
            D_L07_002A2808[i * 2 + 1] = edge;
            D_L07_002A26B8[i * 4] = t;
            D_L07_002A26B8[i * 4 + 2] = t;
            D_L07_002A26B8[i * 4 + 3] = 1.0f;
            D_L07_002A26B8[i * 4 + 1] = 0.0f;
        }
        func_003D3A24(0x2A, D_L07_002A24C0, D_L07_002A2808, D_L07_002A26B8, 1);
    }
    if (p->b24 != 0) {
        func_003A9440(6, func_00389598(0xB));
        func_003A9440(8, 0);
        func_003A9440(0x42, 0x8000000048UL);
        func_0038C750();
        if (p->f1C > 1.0f) {
            size = 1.0f;
            alpha = 2.0f - p->f1C;
        } else {
            alpha = p->f1C;
            size = alpha;
        }
        for (j = 0; j < 4; j++) {
            func_0038CC88(&D_L07_002A24C0[j], p, 12);
            if (j < 2) {
                d = -size;
            } else {
                d = size;
            }
            if (j == 0 || j == 3) {
                D_L07_002A24C0[j].x += d;
            } else {
                D_L07_002A24C0[j].y += d;
            }
        }
        color2 = ((s32)(alpha * 255.0f) << 24) | 0x804020;
        D_L07_002A2808[3] = color2;
        D_L07_002A2808[2] = color2;
        D_L07_002A2808[1] = color2;
        D_L07_002A2808[0] = color2;
        func_003D3A24(4, D_L07_002A24C0, D_L07_002A2808, D_L07_001DE448, 1);

        func_003A9440(6, func_00389598(0x17));
        func_003A9440(8, 0);
        func_003A9440(0x42, 0x8000000048UL);
        func_0038C750();
        vec_sub_ba(&dir, (vu0_v4 *)D_L07_001E1EC0, p);
        func_0038CE90(&end, &dir, &D_L07_001D9AE0);
        func_0038CF68(&end, &end, size * 0.8f);
        vec_add_ba(&tmp, p, &end);
        put_003B1C08(&D_L07_002A24C0[0], &tmp);
        vec_sub_ba(&tmp, p, &end);
        put_003B1C08(&D_L07_002A24C0[1], &tmp);
        side0 = p->pos;
        side0.z += size + size;
        vec_add_ba(&tmp, &side0, &end);
        put_003B1C08(&D_L07_002A24C0[2], &tmp);
        vec_sub_ab(&tmp, &side0, &end);
        put_003B1C08(&D_L07_002A24C0[3], &tmp);
        color3 = ((s32)(alpha * 128.0f) << 24) | 0x804020;
        D_L07_002A2808[1] = color3;
        D_L07_002A2808[0] = color3;
        D_L07_002A2808[3] = 0x804020;
        D_L07_002A2808[2] = 0x804020;
        for (k = 0; k < 4; k++) {
            ((UV_003B1C08 *)D_L07_002A26B8)[k].u = D_L07_001DE448[k].u - p->f20;
            ((UV_003B1C08 *)D_L07_002A26B8)[k].v = D_L07_001DE448[k].v;
        }
        func_003D3A24(4, D_L07_002A24C0, D_L07_002A2808, D_L07_002A26B8, 1);
    }
}
/* localdecomp:end func_L07_003B1C08 */
