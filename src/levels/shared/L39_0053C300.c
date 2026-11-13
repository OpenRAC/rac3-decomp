#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
extern void func_L39_005FE358(u8 *, u8 *, void *, s32, f32);
extern u8 *D_L39_0024BF5C;
extern void func_0038CF68(void *, void *, f32);

/* declared by functions of L39_0053C2A0.c, which this file was cut from */
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L39_0053C300 */
#include "vu0.h"

extern u8 *D_L39_00296818[];

extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L39_005CE670(void *, void *, s32, f32, f32, f32, u32, u32, s32);
extern u32 func_L01_00480A78(u32, u32, f32);
extern void func_0038CF68(void *, void *, f32);
extern u32 func_L01_00448D88(u32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C7B40(void *, void *, u32, u32, f32, s32, s32, s32, s32, s32);

/* from rac1-decomp's mine detonation effect (mine_bomb_and_debris.c): cr/cg/cb colour locals, loop order */
void func_L39_0053C300(u8 *a0) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 hit;
    f32 ground;
    f32 r;
    f32 ang;
    f32 size;
    s32 n1;
    s32 n2;
    s32 i;
    s32 j;
    u32 c1;
    u32 c2;
    s32 t;
    s32 cr;
    s32 cg;
    s32 cb;

    v10 = *(vu0_v4 *)(a0 + 0x10);
    v10.z += 3.5f;
    ground = func_003C3D30(&v10, 0, 0, 0.5f);
    v20 = *(vu0_v4 *)(a0 + 0x10);
    v20.w = 1.0f;
    if (func_L39_005BE900(&v20, (s32)&hit, 64.0f) < 0) {
        return;
    }
    n1 = 100;
    n2 = 20;
    if (1024.0f <= hit.x) {
        n1 = 50;
        n2 = 5;
    }
    cr = 0x60;
    cg = 0x60;
    cb = 0x7F;
    for (i = 0; i < n1; i++) {
        *(vu0_q *)&v40 = 0;
        v40.x = func_L39_005B4410(-0.015000001f, 0.015000001f);
        v40.y = func_L39_005B4410(-0.015000001f, 0.015000001f);
        v40.z = func_L39_005B4410(0.080000006f, 0.32000002f);
        v30 = v40;
        r = func_L39_005B4410(0.0f, 0.35f);
        ang = func_L39_005B44C8();
        v40.x = func_0038D098(ang) * r;
        v40.y = func_0038D0B0(ang) * r;
        v40.z = 0.0f;
        vec_add_ba(&v40, &v40, a0 + 0x10);
        v40.z = ground + 0.5f;
        v30.z -= r * 0.020000001f * 8.0f;
        func_L39_005CE670(&v40, &v30, 0, func_L39_005B4410(0.35f, 1.25f), ground, 0.008f, (0x16 << 24) | (cb << 16) | (cg << 8) | cr, (cb << 16) | (cg << 8) | cr, 1);
    }
    for (j = 0; j < n2; j++) {
        c1 = func_L01_00480A78(0x7F000000, (0x7F << 24) | (cb << 16) | (cg << 8) | cr, func_L39_005B4410(0.25f, 1.0f));
        c2 = func_L01_00480A78(0, ((cb / 2) << 16) | ((cg / 2) << 8) | (cr / 2), func_L39_005B4410(0.5f, 1.0f));
        v40.x = func_L39_005B4410(-3.0f, 3.0f);
        v40.y = func_L39_005B4410(-3.0f, 3.0f);
        v40.z = func_L39_005B4410(0.080000006f, 0.28000003f);
        func_0038CF68(&v40, &v40, func_L39_005B4410(1.5f, 3.0f) * 0.020000001f);
        v40.z = func_L39_005B4410(3.0f, 6.0f) * 0.020000001f;
        v30 = *(vu0_v4 *)(a0 + 0x10);
        v30.z = ground;
        c1 = func_L01_00448D88(c1, 0);
        c2 = func_L01_00448D88(c2, 0);
        size = func_L39_005B4410(31500.002f, 52500.0f);
        t = func_L39_005B43C8(0x4B, 0x7D);
        func_L39_005C7B40(&v30, &v40, c1, c2, size, t, 1, *D_L39_00296818[11], -1, 0);
    }
}
/* localdecomp:end func_L39_0053C300 */

INCLUDE_ASM("asm/levels", func_L39_0053C758);
