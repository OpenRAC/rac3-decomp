/* functional: medium-high. Written from the PAL asm (no draft). Same frame (0x520) and same opening instructions as retail; 564 words differ (scheduling/regalloc/VU0 loads). Builds two 32-point jittered strands (A/B), smooths them with a 3-tap sum into the 0x50/0x250 and 0x660/0x860 sets, picks 4 branch start points (index byte at s+0x48+i, rewritten by the 2nd set as in retail) with 3-step random-walk chains, then, if the object is >= 4.0 from D_L20_001E2E00 (func_0038CF38), rolls an orientation and spawns particle bursts via func_L01_00463378 (9 args, last on stack). func_0038CE20 is the 3-arg vector scale at 0x0042CD40 (factor 0.3333f). The rand(2) result in the 2-iteration spawn loops is discarded by retail and kept as a bare call. Globals D_L20_001DF3D0..3FC are gp-relative level data. */
#include "vu0.h"
extern s32 D_L20_001DF3F8;
extern s32 D_L20_001DF3FC;
extern f32 D_L20_001DF3D0;
extern f32 D_L20_001DF3D4;
extern f32 D_L20_001DF3E8;
extern s32 D_L20_001DF3DC;
extern s32 D_L20_001DF3E0;
extern s32 D_L20_001DF3F0;
extern s32 D_L20_001DF3F4;
__asm__(".extern D_L20_001DF3F8, 4");
__asm__(".extern D_L20_001DF3FC, 4");
__asm__(".extern D_L20_001DF3D0, 4");
__asm__(".extern D_L20_001DF3D4, 4");
__asm__(".extern D_L20_001DF3E8, 4");
__asm__(".extern D_L20_001DF3DC, 4");
__asm__(".extern D_L20_001DF3E0, 4");
__asm__(".extern D_L20_001DF3F0, 4");
__asm__(".extern D_L20_001DF3F4, 4");
extern vu0_v4 D_L20_001E2E00;
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_00382538(void);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D328(void *, void *);
extern s32 func_L01_00463378(void *, void *, void *, u32, u32, s32, s32, s32, s32);

void func_L20_003F2918(u8 *obj) {
    vu0_v4 A[32];
    vu0_v4 B[32];
    vu0_v4 T;
    vu0_v4 U;
    vu0_v4 mat[4];
    u8 *s;
    f32 w, f;
    s32 i, j, k, m, r, life, c;

    r = func_00382498((D_L20_001DF3F8 * 5 + 2) / 6, (D_L20_001DF3FC * 5 + 2) / 6);
    *(f32 *)(obj + 0x1C) = 1.0f;
    s = *(u8 **)(obj + 0x68);
    *(s32 *)(s + 0x28) = (s16)r;
    *(s16 *)(s + 0x42) = r;
    w = func_003824E0(4.0f, 5.0f);

    for (i = 0; i < 32; i++) {
        f = ((f32)i / 31.0f);
        f = (0.5f - f) * w;
        if ((u32)(i - 3) < 26) {
            func_L01_00443B88(&A[i], 0.0f, D_L20_001DF3D0);
            func_L01_00443B88(&B[i], 0.0f, D_L20_001DF3D4 * 0.020000001f);
        } else {
            qzero(&A[i]);
            qzero(&B[i]);
        }
        A[i].w = 1.0f;
        A[i].y = A[i].y + f;
    }

    for (j = 0; j < 32; j++) {
        if (j == 0 || j == 31) {
            *(vu0_q *)(s + 0x50 + j * 16) = *(vu0_q *)&A[j];
            *(vu0_q *)(s + 0x250 + j * 16) = *(vu0_q *)&B[j];
        } else {
            vec_add_ab(&T, &A[j - 1], &A[j]);
            vec_add_ab(&T, &T, &A[j + 1]);
            func_0038CE20(s + 0x50 + j * 16, &T, 0.3333f);
            vec_add_ab(&T, &B[j - 1], &B[j]);
            vec_add_ab(&T, &T, &B[j + 1]);
            func_0038CE20(s + 0x250 + j * 16, &T, 0.3333f);
        }
    }
    for (j = 0; j < 32; j++) {
        if (j == 0 || j == 31) {
            *(vu0_q *)(s + 0x660 + j * 16) = *(vu0_q *)&A[j];
            *(vu0_q *)(s + 0x860 + j * 16) = *(vu0_q *)&B[j];
        } else {
            vec_add_ab(&T, &A[j - 1], &A[j]);
            vec_add_ab(&T, &T, &A[j + 1]);
            func_0038CE20(s + 0x660 + j * 16, &T, 0.3333f);
            vec_add_ab(&T, &B[j - 1], &B[j]);
            vec_add_ab(&T, &T, &B[j + 1]);
            func_0038CE20(s + 0x860 + j * 16, &T, 0.3333f);
        }
    }

    for (i = 0; i < 4; i++) {
        func_L01_00443B88(&T, D_L20_001DF3D0, D_L20_001DF3D0);
        r = (s32)func_003824E0((f32)i * 6.0f, (f32)(i + 1) * 6.0f);
        *(u8 *)(s + 0x48 + i) = r + 4;
        *(vu0_q *)(s + 0x450 + i * 16) = *(vu0_q *)(s + 0x50 + (r + 4) * 16);
        *(vu0_q *)(s + 0x550 + i * 16) = *(vu0_q *)(s + 0x250 + (r + 4) * 16);
        for (m = 0; m < 3; m++) {
            func_L01_00443B88(&U, 0.1f, 0.1f);
            func_L01_00443B88(s + 0x590 + i * 16 + m * 0x40, 0.0f, D_L20_001DF3D4 * 0.020000001f);
            vec_add_ab(s + 0x490 + i * 16 + m * 0x40, s + 0x450 + i * 16 + m * 0x40, &T);
            vec_add_ab(s + 0x490 + i * 16 + m * 0x40, s + 0x490 + i * 16 + m * 0x40, &U);
        }
    }
    for (i = 0; i < 4; i++) {
        func_L01_00443B88(&T, D_L20_001DF3D0, D_L20_001DF3D0);
        r = (s32)func_003824E0((f32)i * 6.0f, (f32)(i + 1) * 6.0f);
        *(u8 *)(s + 0x48 + i) = r + 4;
        *(vu0_q *)(s + 0xA60 + i * 16) = *(vu0_q *)(s + 0x660 + (r + 4) * 16);
        *(vu0_q *)(s + 0xB60 + i * 16) = *(vu0_q *)(s + 0x860 + (r + 4) * 16);
        for (m = 0; m < 3; m++) {
            func_L01_00443B88(&U, 0.1f, 0.1f);
            func_L01_00443B88(s + 0xBA0 + i * 16 + m * 0x40, 0.0f, D_L20_001DF3D4 * 0.020000001f);
            vec_add_ab(s + 0xAA0 + i * 16 + m * 0x40, s + 0xA60 + i * 16 + m * 0x40, &T);
            vec_add_ab(s + 0xAA0 + i * 16 + m * 0x40, s + 0xAA0 + i * 16 + m * 0x40, &U);
        }
    }

    if (4.0f <= func_0038CF38(obj + 0x10, &D_L20_001E2E00)) {
        *(f32 *)(s + 0x658) = *(f32 *)(obj + 0xF8);
        *(f32 *)(s + 0x654) = *(f32 *)(obj + 0xF4);
        *(f32 *)(s + 0x654) = *(f32 *)(s + 0x654) + func_L01_00443A18(0.0f, 30.0f) * 0.0174532924f;
        *(f32 *)(s + 0x650) = func_00382538();
        func_0038D328(mat, s + 0x650);
        *(vu0_q *)&mat[3] = *(vu0_q *)(obj + 0x10);
        for (k = 0; k < 32; k += 8) {
            func_0038D028(&T, s + 0x50 + k * 16, mat);
            *(vu0_q *)&U = *(vu0_q *)(s + 0x250 + k * 16);
            U.w = D_L20_001DF3E8;
            if (func_00382468(2) != 0) c = D_L20_001DF3F0;
            else c = D_L20_001DF3F4;
            life = ((func_00382468(10) + 20) * 5 + 2) / 6;
            func_L01_00463378(&T, &U, &U, D_L20_001DF3DC, D_L20_001DF3E0, k >> 1, 15, life, c);
        }
        for (m = 0; m < 2; m++) {
            func_0038D028(&T, s + 0x510 + m * 16, mat);
            *(vu0_q *)&U = *(vu0_q *)(s + 0x610 + m * 16);
            U.w = D_L20_001DF3E8;
            func_00382468(2);
            life = ((func_00382468(10) + 20) * 5 + 2) / 6;
            func_L01_00463378(&T, &U, &U, D_L20_001DF3DC, D_L20_001DF3E0, *(u8 *)(s + 0x48 + m) >> 1, 15, life, D_L20_001DF3F4);
        }
    }
    if (4.0f <= func_0038CF38(obj + 0x10, &D_L20_001E2E00)) {
        *(f32 *)(s + 0xC68) = *(f32 *)(obj + 0xF8);
        *(f32 *)(s + 0xC64) = *(f32 *)(obj + 0xF4);
        *(f32 *)(s + 0xC64) = *(f32 *)(s + 0xC64) + func_L01_00443A18(0.0f, 30.0f) * 0.0174532924f;
        *(f32 *)(s + 0xC60) = func_00382538();
        func_0038D328(mat, s + 0xC60);
        *(vu0_q *)&mat[3] = *(vu0_q *)(obj + 0x10);
        for (k = 0; k < 32; k += 8) {
            func_0038D028(&T, s + 0x660 + k * 16, mat);
            *(vu0_q *)&U = *(vu0_q *)(s + 0x860 + k * 16);
            U.w = D_L20_001DF3E8;
            if (func_00382468(2) != 0) c = D_L20_001DF3F0;
            else c = D_L20_001DF3F4;
            life = ((func_00382468(10) + 20) * 5 + 2) / 6;
            func_L01_00463378(&T, &U, &U, D_L20_001DF3DC, D_L20_001DF3E0, k >> 1, 15, life, c);
        }
        for (m = 0; m < 2; m++) {
            func_0038D028(&T, s + 0xB20 + m * 16, mat);
            *(vu0_q *)&U = *(vu0_q *)(s + 0xC20 + m * 16);
            U.w = D_L20_001DF3E8;
            func_00382468(2);
            life = ((func_00382468(10) + 20) * 5 + 2) / 6;
            func_L01_00463378(&T, &U, &U, D_L20_001DF3DC, D_L20_001DF3E0, *(u8 *)(s + 0x48 + m) >> 1, 15, life, D_L20_001DF3F4);
        }
    }
}
