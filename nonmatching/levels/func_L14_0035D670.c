/* func_L14_0035D670: near miss, 170 diff (draft): needs -mvu0-use-vf0-vf2 on L14_0035D590.c (func_L14_0035D590 still matches with it) and the divs_nops row "func_L14_0035D670 2 2"; logic complete and the loop body lines up up to register names; left: the stack frame (retail 0x110: v at sp+0, r at 0x10, the four-vector table at 0x20 built in a temporary at 0x30 that overlaps it; this C 0x120 with another layout, so every slot offset and one saved register differ); partial initialisers (w omitted) give retail sq $zero clearing; declaration orders tried
   Level 14 (Koros) only; flags of its file in config/levels/text_parts.txt. */
#include "vu0.h"
typedef struct {
    u8 pad[0x10];
    u8 *p10;
} S_35D670;
__asm__(".extern D_L14_001DD6E0, 4");
__asm__(".extern D_L14_001DD6E8, 4");
__asm__(".extern D_L14_001DD6EC, 4");
__asm__(".extern D_L14_001DD6F0, 4");
__asm__(".extern D_L14_001DD6F4, 4");
__asm__(".extern D_L14_001DD6F8, 4");
__asm__(".extern D_L14_001DD6FC, 4");
__asm__(".extern D_L14_001DD700, 4");
__asm__(".extern D_L14_001DD704, 4");
__asm__(".extern D_L14_001DD708, 4");
__asm__(".extern D_L14_001DD70C, 4");
__asm__(".extern D_L14_001DD710, 4");
__asm__(".extern D_L14_001DD714, 4");
__asm__(".extern D_L14_001DD718, 4");
extern s32 D_L14_001DD6E0;
extern s32 D_L14_001DD6E8;
extern s32 D_L14_001DD6EC;
extern s32 D_L14_001DD6F0;
extern s32 D_L14_001DD6F4;
extern s32 D_L14_001DD6F8;
extern f32 D_L14_001DD6FC;
extern f32 D_L14_001DD700;
extern f32 D_L14_001DD704;
extern f32 D_L14_001DD708;
extern f32 D_L14_001DD70C;
extern f32 D_L14_001DD710;
extern f32 D_L14_001DD714;
extern f32 D_L14_001DD718;
extern S_35D670 D_L14_0021F958;
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_00382580(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00470668(void *, void *, s32, f32);
void func_L14_0035D670(u8 *a0, s32 dir) {
    vu0_v4 r;
    vu0_v4 v;
    vu0_v4 tab[4] = {
        { D_L14_001DD708, 0.0f, D_L14_001DD704 },
        { 0.0f, D_L14_001DD708, D_L14_001DD704 },
        { -D_L14_001DD708, 0.0f, D_L14_001DD704 },
        { 0.0f, -D_L14_001DD708, D_L14_001DD704 },
    };
    vu0_v4 p90;
    vu0_v4 p80;
    vu0_v4 d;
    vu0_v4 w;
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *e;
    f32 t;
    f32 x;
    s32 i;
    s32 k;
    s32 alpha;
    s32 col;
    s32 life;
    switch (dir) {
    case 0:
        v = tab[0];
        break;
    case 1:
        v = tab[1];
        break;
    case 2:
        v = tab[2];
        break;
    case 3:
        v = tab[3];
        break;
    }
    t = *(f32 *)(a0 + 0x2C) / D_L14_001DD70C;
    func_0038CE20(&v, &v, t);
    func_0038D000(&v, &v, a0 + 0xC0);
    vec_copy(&p90, a0 + 0x10);
    vec_copy(&p80, a0 + 0x10);
    vec_add_ab(&v, &v, &p90);
    *(vu0_q *)&d = 0;
    d.z = D_L14_001DD704 * t;
    w = d;
    vec_add_ba(&w, &w, &p80);
    k = *(s32 *)(s + 0x44);
    alpha = 0x7F;
    if (k < 50) {
        alpha = (u8)(s32)((f32)k * 127.0f / 50.0f);
    }
    for (i = 0; i < D_L14_001DD6E0; i++) {
        vec_sub_ba(&d, &v, &w);
        x = D_L14_001DD710 * t;
        func_00382580(&r, x * 0.5f, x);
        vec_add_ab(&r, &r, &d);
        func_0038CF68(&r, &r, func_003824E0(D_L14_001DD714 * 0.5f, D_L14_001DD714) * 0.020000001f);
        col = func_00382468(4) ? D_L14_001DD6F8 : D_L14_001DD6F0;
        life = (D_L14_001DD6E8 * 5 + 2) / 6;
        col |= alpha << 24;
        k = func_00382498(-2, 2);
        e = func_L01_00475C60(&v, &r, life, k, col, D_L14_001DD6F4, 0, D_L14_001DD6FC * 210000.0f, D_L14_001DD700 * 210000.0f,
                              func_003824E0(D_L14_001DD718 * 0.3f, D_L14_001DD718));
        if (e != 0) {
            e[2] = D_L14_0021F958.p10[0];
            e[3] = func_00382468(2) ? 0x48 : 0x44;
        }
    }
    if (func_00382468(6) == 0) {
        life = (func_00382498(D_L14_001DD6EC - 5, D_L14_001DD6EC) * 5 + 2) / 6;
        func_L01_00470668(&v, &r, life, func_003824E0(40.0f, 80.0f) * 0.00040000002f);
    }
}
