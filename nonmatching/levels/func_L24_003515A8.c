/* func_L24_003515A8: 2 differences (level 24, file L24_0034F040.c, flags as committed). Projectile update: trail
   particles (func_L01_004637C8) from a random vector, a collision probe (func_003D3CB0 with a query struct whose 0x30
   bytes reuse the trail vectors' stack slots, here three vectors declared in order with the query cast onto the first),
   then the explosion burst (func_L01_0044AF78, func_003D4D00) and the out-of-bounds kill. Everything matches except the
   order of two argument moves before func_L01_004637C8: retail moves n ($s0) to $t0 before the second
   func_00382498 result ($v0) to $t2; this C schedules the $v0 move first (it depends on the call just scheduled).
   j as a local, n or j inline in the call, a re-split n, u32/s16/varargs/K&R prototypes: no change.
   Prototype finding: func_L01_0044AF78's float x*4 (f14) and its int copy (t0) need the two int parameters a3/t0
   ahead of the third float, or the product is allocated to $f14 and retail's mov.s $f14,$f3 is lost. The file's
   current declaration (floats after the third int, needed by func_L24_00350980) does not allow that; 37 interleavings
   keep func_L24_00350980 matching and fix this one, all of the form (void *, void *, s32, f32, f32, s32, s32, ...),
   e.g. the cast below. Adopt one for both if this function is matched. */
#include "common.h"
#include "vu0.h"
typedef struct { vu0_v4 v; void *obj; s32 f14; u8 b18; u8 b19; u16 id; f32 f1C; s32 f20; } Q_3515A8;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_00451388(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0044AF78(void *, void *, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern void func_003C2880(void *);

void func_L24_003515A8(u8 *obj) {
    vu0_v4 p20;
    vu0_v4 p30;
    u8 *pos = obj + 0x10;
    u8 *s;
    f32 x;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 r60;

    p30 = p20 = *(vu0_v4 *)(obj + 0x10);
    s = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        {
            s32 n;

            *(vu0_q *)&r60 = 0;
            r60.x = func_003824E0(-1.0f, 1.0f);
            r60.y = func_003824E0(-1.0f, 1.0f);
            r60.z = func_003824E0(-1.0f, 1.0f);
            v50 = r60;
            func_0038CF68(&v50, &v50, func_003824E0(0.1f, 0.2f) * 0.020000001f);
            func_0038CF68(&v40, s, -func_003824E0(0.002f, 0.020000001f));
            vec_add_ba(&v50, &v50, &v40);
            func_0038CE20((f32 *)&v40, s, func_003824E0(0.0f, 1.0f));
            vec_add_ab(&v40, &v40, pos);
            n = (func_00382498(0x1C, 0x28) * 5 + 2) / 6;
            func_L01_004637C8(&v40, &v50, 0x6F00AFFF, 0x100000FF, n, 0x28, func_00382498(0x28, 0x46), 1);
        }
        vec_add_ba(pos, pos, s);
        *(f32 *)(obj + 0xF8) = func_0038D160(*(f32 *)(s + 0), *(f32 *)(s + 4));
        *(f32 *)(obj + 0xF4) = -func_0038D160(func_0038CED8(s), *(f32 *)(s + 8));
        func_L01_00451388(obj, s, s, *(f32 *)(s + 0x18));
        {
            ((Q_3515A8 *)&v40)->obj = obj;
            ((Q_3515A8 *)&v40)->f14 = 0x10001;
            ((Q_3515A8 *)&v40)->f1C = *(f32 *)(s + 0x20);
            ((Q_3515A8 *)&v40)->f20 = 1;
            ((Q_3515A8 *)&v40)->v = *(vu0_v4 *)s;
            func_0038CF68(&((Q_3515A8 *)&v40)->v, &((Q_3515A8 *)&v40)->v, *(f32 *)(s + 0x24));
            ((Q_3515A8 *)&v40)->v.w = 5627.925f;
            ((Q_3515A8 *)&v40)->b18 = s[0x28];
            ((Q_3515A8 *)&v40)->b19 = s[0x2C];
            ((Q_3515A8 *)&v40)->id = *(u16 *)(obj + 0xAA);
            if (func_003D3CB0(&p30, pos, 0, *(void **)(s + 0x10), (Q_3515A8 *)&v40) != 0
                || func_L01_003FB640(pos, 0, *(u8 **)(s + 0x10), 0.2f) != 0) {
                func_003A52A0(0, 0, obj);
                x = *(f32 *)(s + 0x14);
                ((void (*)(void *, void *, s32, f32, f32, s32, s32, s32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32))
                     func_L01_0044AF78)(obj, s, 0, 0.0f, 0.0f, (s32)(x * 5.0f), (s32)(x * 4.0f), (s32)(x * 10.0f),
                                        x * 4.0f, x + x, 9.0f, *(f32 *)(s + 0x14), x * 15.0f, -1, 1, 1, -1, 0, 0x1010001);
                func_003D4D00(pos, 0x10, *(void **)(s + 0x10), (Q_3515A8 *)&v40, *(f32 *)(s + 0x14) * 4.0f);
                func_003C2880(obj);
                return;
            }
        }
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10)
        || *(f32 *)(obj + 0x14) < 2.0f || 1021.0f < *(f32 *)(obj + 0x14)
        || *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
        func_003C2880(obj);
    }
}
