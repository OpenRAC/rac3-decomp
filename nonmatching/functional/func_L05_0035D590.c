/* functional: high. Read block by block from the PAL asm (3 iterations, every constant, gp-relative global, delay-slot store and callee checked). Early return when the u64 at obj+0x40 does not have 0x0505 in bits 16-31 skips the 0x3DC fixup, as retail does. 292 word diffs vs retail (frame 0x150 vs 0x140: one extra vector temp, plus regalloc). */
#include "vu0.h"
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L05_0035DA38(vu0_v4 *, s32, u32, u32, f32, f32);
extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern s32 D_L05_001EA6D8[];
extern u8 D_L05_001EA6E0[];
extern vu0_v4 D_L05_00285A20[5];
__asm__(".extern D_L05_001DD7B0, 4");
extern vu0_v4 D_L05_001DD7B0[3];
__asm__(".extern D_L05_001DD768, 4");
extern f32 D_L05_001DD768;
__asm__(".extern D_L05_001DD76C, 4");
extern f32 D_L05_001DD76C;
__asm__(".extern D_L05_001DD7A4, 4");
extern f32 D_L05_001DD7A4;
__asm__(".extern D_L05_001DD790, 4");
extern f32 D_L05_001DD790;
__asm__(".extern D_L05_001DD794, 4");
extern u32 D_L05_001DD794;
__asm__(".extern D_L05_001DD798, 4");
extern u32 D_L05_001DD798;
__asm__(".extern D_L05_001DD79C, 4");
extern f32 D_L05_001DD79C;

void func_L05_0035D590(u8 *obj) {
    u8 *d;
    s32 i;
    s32 k;
    s32 w;
    f32 x;
    f32 r;
    vu0_v4 mat[4];
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    vu0_v4 vC0;
    vu0_v4 v80;
    vu0_v4 v70;
    vu0_v4 v60;
    vu0_v4 v50;
    vu0_v4 v40;

    d = *(u8 **)(obj + 0x68);
    *(s32 *)(d + 0x3DC) = -1;
    for (i = 0; i < 3; i = k) {
        k = i + 1;
        func_003C2EC0(obj, k, mat);
        v90 = mat[3];
        func_0038D028(&vA0, &D_L05_001DD7B0[i], mat);
        vec_add_ab(&v90, &v90, &vA0);
        if ((*(long *)(obj + 0x40) & 0xFFFF0000) != 0x05050000) {
            return;
        }
        {
            u8 *o2 = *(u8 **)(d + 0x230);
            r = func_0038DBA0(*(f32 *)(obj + 0xF8),
                              func_0038D160(*(f32 *)(o2 + 0x10) - *(f32 *)(obj + 0x10),
                                            *(f32 *)(o2 + 0x14) - *(f32 *)(obj + 0x14)));
        }
        if (r < 0.17453292f) {
            x = ((f32)*(s32 *)(d + 0x2E0) - (D_L05_001DD76C * 5.0f + 2.0f) / 6.0f)
                / ((D_L05_001DD768 * 5.0f + 2.0f) / 6.0f);
            if (x < 0.0f) {
                x = 0.0f;
            }
            vC0 = *(vu0_v4 *)(d + 0x330);
            func_003C4098(&vB0, D_L05_001D66B0, &vC0, x);
            vec_sub_ba(&v80, d + 0x220, &v90);
            func_0038CF68(&v80, &v80, 35.0f);
            vec_add_ba(&v80, &v80, &vB0);
            vec_add_ab(&v70, &v80, &v90);
        } else {
            v90 = mat[3];
            func_0038CF68(&v80, &mat[1], -35.0f);
            vec_add_ab(&v70, &v80, &v90);
        }
        if (func_003D3CB0(&v90, &v70, 0x10, obj, 0) != 0) {
            v70 = *(vu0_v4 *)D_L05_001EA6E0;
            w = D_L05_001EA6D8[0];
            if (w != 0) {
                if (*(s32 *)(d + 0x3DC) == -1) {
                    *(s32 *)(d + 0x3DC) = w;
                } else if (w != *(s32 *)(d + 0x3DC)) {
                    *(s32 *)(d + 0x3DC) = 0;
                } else {
                    *(s32 *)(d + 0x3DC) = w;
                }
                func_003D9508(D_L05_001EA6E0, 0x39, 0x4F2020FF, 1, 0.5f, 0.24f, func_00382538());
                func_003D9508(D_L05_001EA6E0, 0x31, 0x6F808080, 1, 0.25f, 0.24f, func_00382538());
            } else {
                *(s32 *)(d + 0x3DC) = 0;
                func_003D9508(D_L05_001EA6E0, 0x39, 0x3F2020FF, 1, 0.3f, 0.24f, func_00382538());
                func_003D9508(D_L05_001EA6E0, 0x31, 0x4F808080, 1, 0.2f, 0.24f, func_00382538());
            }
        }
        D_L05_00285A20[0] = v90;
        func_003D9508(D_L05_00285A20, 0x31, 0x153064FF, 1, 0.17f, 0.0f, D_L05_001DD7A4);
        func_0038CDF8(&v40, &v90, &v70, 0.05f);
        D_L05_00285A20[1] = v40;
        r = func_0038DAB8(D_L05_001DD7A4, 0.020943951f);
        D_L05_001DD7A4 = r;
        func_0038CDF8(&v50, &v90, &v70, (func_0038D0B0(r) * 0.5f + 0.5f) * 0.45f + 0.1f);
        D_L05_00285A20[2] = v50;
        func_0038CDF8(&v60, &v90, &v70, 0.66f);
        D_L05_00285A20[4] = v70;
        D_L05_00285A20[3] = v60;
        func_L05_0035DA38(D_L05_00285A20, 4, D_L05_001DD794, D_L05_001DD798, D_L05_001DD790, D_L05_001DD79C);
    }
    if (*(s32 *)(d + 0x3DC) == -1) {
        *(s32 *)(d + 0x3DC) = 0;
    }
}
