/* functional: high. compiles; 228 diff lines at level_01 (regalloc/stack); read fully; 210000.0f literal from 0x484D1400; stack matrix output of func_003C2EC0 inferred (mat rows used at +0x10/+0x20) */
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003CE780(void *, void *, void *, u32, u32, f32);
extern void func_L01_00303C00(void *, void *, void *, f32);
extern void func_003A52A0(s32, s32, void *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_0046A610(void *, void *, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00445170(void *, s32);
extern u8 D_L01_001E2A40[];
extern s32 D_001DE444_sda;
extern f32 D_001DE448_sda;
extern f32 D_001DE44C_sda;
extern f32 D_001DE450_sda;
extern f32 D_001DE454_sda;
extern f32 D_001DE458_sda;
extern f32 D_001DE45C_sda;
extern f32 D_001DE460_sda;
extern s32 D_001DE464_sda;
extern s32 D_001DE468_sda;
extern s32 D_001DE46C_sda;

void func_L01_003AD418(void *obj, u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    f32 pos[4] __attribute__((aligned(16)));
    f32 dir[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 spark[4] __attribute__((aligned(16)));
    f32 mat[16] __attribute__((aligned(16)));
    f32 off[4] __attribute__((aligned(16)));
    f32 vel2[4] __attribute__((aligned(16)));
    f32 s;
    s32 visible;
    s32 i;
    s32 j;
    s32 n;
    s32 r;
    u8 *e;
    s32 c;
    f32 d;

    if (*(s32 *)(pv + 0x10) == 0) {
        return;
    }
    visible = 1;
    d = func_L01_0040E548(D_L01_001E2A40, *(u8 **)(m + 0x64) + 0x10);
    r = *(s16 *)(*(u8 **)(m + 0x64) + 0x32);
    if ((f32)(r * r) < d) {
        visible = 0;
    }
    e = *(u8 **)(pv + 0x14);
    for (i = 0; i < *(s32 *)(pv + 0x10); i++, e += 0x40) {
        if (func_L01_0044E1B8(*(void **)(m + 0x64), *(f32 *)(e + 0x28)) == 0) {
            continue;
        }
        func_003C2EC0(*(void **)(m + 0x64), *(s32 *)e, mat);
        func_0038D028(pos, e + 0x10, mat);
        s = func_003824E0(-*(f32 *)(e + 0x30), *(f32 *)(e + 0x30));
        func_0038CE20(off, mat + 4, s * *(f32 *)(m + 0xCF0));
        vec_add_ba(dir, off, mat);
        s = func_003824E0(-*(f32 *)(e + 0x30), *(f32 *)(e + 0x30));
        func_0038CE20(off, mat + 8, s * *(f32 *)(m + 0xCF0) + *(f32 *)(e + 0x24));
        vec_add_ab(dir, off, dir);
        func_0038CF68(dir, dir, 1.0f);
        func_0038CE20(vel, dir, *(f32 *)(e + 0x2C));
        if (*(s16 *)(*(u8 **)(m + 0x64) + 0xAA) == 0x1A90) {
            func_L01_003CE780(*(void **)(m + 0x64), pos, vel, 0xF01038FF, 0xF0002080, *(f32 *)(pv + 0x18));
        } else {
            func_L01_00303C00(*(void **)(m + 0x64), vel, pos, *(f32 *)(pv + 0x18));
        }
        if (*(s32 *)(*(u8 **)(m + 0x68) + 0x30) >= 0) {
            func_003A52A0(*(s32 *)(*(u8 **)(m + 0x68) + 0x30), 0, *(void **)(m + 0x64));
        }
        if (visible != 0) {
            func_0038CE20(dir, dir, D_001DE44C_sda);
            for (j = 0; j < D_001DE444_sda; j++) {
                spark[0] = pos[0] + func_003824E0(-D_001DE448_sda, D_001DE448_sda);
                spark[1] = pos[1] + func_003824E0(-D_001DE448_sda, D_001DE448_sda);
                spark[2] = pos[2] + func_003824E0(-D_001DE448_sda, D_001DE448_sda);
                vel2[0] = dir[0] * func_003824E0(1.0f - D_001DE450_sda, D_001DE450_sda + 1.0f);
                vel2[1] = dir[1] * func_003824E0(1.0f - D_001DE450_sda, D_001DE450_sda + 1.0f);
                vel2[2] = dir[2] * func_003824E0(1.0f - D_001DE450_sda, D_001DE450_sda + 1.0f);
                c = (s32)func_L01_00443A18(1.0f, 3.0f);
                s = func_003824E0(D_001DE458_sda, D_001DE45C_sda) * 210000.0f;
                vec_sub_ab(spark, spark, vel2);
                func_L01_0046A610(spark, vel2, s, D_001DE460_sda, D_001DE454_sda, 0.0f, 0.0f,
                                  D_001DE464_sda, D_001DE468_sda, D_001DE46C_sda, c);
            }
        }
        n = *(s32 *)(m + 0xCEC) - 1;
        *(s32 *)(m + 0xCEC) = n;
        if (n == 0) {
            *(s32 *)(m + 0xCEC) = -1;
            *(s32 *)(m + 0xC60) = func_00382498(*(s32 *)(m + 0xCE4), *(s32 *)(m + 0xCE8));
            func_L01_00445170(obj, 1);
        } else if (n < 0) {
            *(s32 *)(m + 0xCEC) = *(s32 *)(m + 0xCE0) - 1;
        }
    }
}
