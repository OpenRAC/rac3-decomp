/* functional: high. Builds the final-boss lightning bolt: 32 random path points (A) and jitter (B), smooths them into two vertex sets (positions v[0..31], velocities v[32..63]), then picks 4 branch anchors per set with 3 rows of random offsets, and throws spark particles when the bolt is >= 4 away from the anchor (D_L20_001E2E00). Every gp slot, loop bound and call order re-read against retail; stack frame is larger than retail (extra temporaries) which does not matter. */
typedef struct {
    u8 pad0[0x8];
    s32 i8;
    u8 padC[0x22 - 0xC];
    s16 count;
    s32 color;
    u8 idx[4];
    u8 pad2C[4];
    struct {
        vu0_v4 v[64];
        vu0_v4 sel[4];
        vu0_v4 g[7][4];
        f32 ang[3];
        f32 pad60C;
    } set[2];
} Bolt_003E6378;

extern f32 D_L20_001DF130;
__asm__(".extern D_L20_001DF130, 4");
extern f32 D_L20_001DF134;
__asm__(".extern D_L20_001DF134, 4");
extern s32 D_L20_001DF13C;
__asm__(".extern D_L20_001DF13C, 4");
extern s32 D_L20_001DF140;
__asm__(".extern D_L20_001DF140, 4");
extern f32 D_L20_001DF148;
__asm__(".extern D_L20_001DF148, 4");
extern s32 D_L20_001DF150;
__asm__(".extern D_L20_001DF150, 4");
extern s32 D_L20_001DF154;
__asm__(".extern D_L20_001DF154, 4");
extern s32 D_L20_001DF158;
__asm__(".extern D_L20_001DF158, 4");
extern s32 D_L20_001DF15C;
__asm__(".extern D_L20_001DF15C, 4");
extern u8 D_L20_001E2E00[];
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(f32 *, f32 *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D328(void *, void *);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L20_003E6378(u8 *obj) {
    Bolt_003E6378 *s;
    vu0_v4 A[32];
    vu0_v4 B[32];
    vu0_v4 r1;
    vu0_v4 r2;
    vu0_v4 M[4];
    vu0_v4 res;
    vu0_v4 vel;
    vu0_v4 sum;
    f32 span;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 t;
    s32 cnt;
    s32 color;
    s32 lo;
    s32 hi;

    lo = (5 * D_L20_001DF158 + 2) / 6;
    hi = (5 * D_L20_001DF15C + 2) / 6;
    *(f32 *)(obj + 0x1C) = 1.0f;
    s = *(Bolt_003E6378 **)(obj + 0x68);
    cnt = func_00382498(lo, hi);
    s->i8 = (s16)cnt;
    s->count = cnt;
    span = func_003824E0(4.0f, 5.0f);
    /* two control polylines of 32 points: A = path, B = velocity jitter */
    for (i = 0; i < 32; i++) {
        f32 amp = (0.5f - (f32)i / 31.0f) * span;
        if (i >= 3 && i <= 28) {
            func_L01_00443B88(&A[i], 0.0f, D_L20_001DF130);
            func_L01_00443B88(&B[i], 0.0f, D_L20_001DF134 * 0.020000001f);
        } else {
            qzero(&A[i]);
            qzero(&B[i]);
        }
        A[i].w = 1.0f;
        A[i].y = A[i].y + amp;
    }
    /* smoothed copies into both sets: positions v[0..31], velocities v[32..63] */
    for (n = 0; n < 2; n++) {
        for (k = 0; k < 32; k++) {
            if (k == 0 || k == 31) {
                s->set[n].v[k] = A[k];
                s->set[n].v[32 + k] = B[k];
            } else {
                vec_add_ab(&sum, &A[k - 1], &A[k]);
                vec_add_ab(&sum, &sum, &A[k + 1]);
                func_0038CE20(&s->set[n].v[k], &sum, 0.333f);
                vec_add_ab(&sum, &B[k - 1], &B[k]);
                vec_add_ab(&sum, &sum, &B[k + 1]);
                func_0038CE20(&s->set[n].v[32 + k], &sum, 0.333f);
            }
        }
    }
    /* branch anchors: 4 picks per set, each grown into 3 rows of random offsets */
    for (n = 0; n < 2; n++) {
        for (j = 0; j < 4; j++) {
            func_L01_00443B88(&r1, D_L20_001DF130, D_L20_001DF130);
            t = (s32)func_003824E0((f32)j * 6.0f, (f32)(j + 1) * 6.0f);
            s->idx[j] = t + 4;
            s->set[n].sel[j] = s->set[n].v[t + 4];
            s->set[n].g[3][j] = s->set[n].v[32 + t + 4];
            for (k = 0; k < 3; k++) {
                func_L01_00443B88(&r2, 0.1f, 0.1f);
                func_L01_00443B88(&s->set[n].g[4 + k][j], 0.0f, D_L20_001DF134 * 0.020000001f);
                vec_add_ab(&s->set[n].g[k][j], k == 0 ? &s->set[n].sel[j] : &s->set[n].g[k - 1][j], &r1);
                vec_add_ab(&s->set[n].g[k][j], &s->set[n].g[k][j], &r2);
            }
        }
    }
    /* lightning sparks: when the bolt is 4+ units from the anchor, throw sparks along it */
    for (n = 0; n < 2; n++) {
        if (func_0038CF38((f32 *)(obj + 0x10), (f32 *)D_L20_001E2E00) >= 4.0f) {
            s->set[n].ang[2] = *(f32 *)(obj + 0xF8);
            s->set[n].ang[1] = *(f32 *)(obj + 0xF4);
            s->set[n].ang[1] += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
            s->set[n].ang[0] = func_00382538();
            func_0038D328(M, s->set[n].ang);
            M[3] = *(vu0_v4 *)(obj + 0x10);
            for (i = 0; i < 4; i++) {
                func_0038D028(&res, &s->set[n].v[i * 8], M);
                vel = s->set[n].v[32 + i * 8];
                vel.w = D_L20_001DF148;
                color = func_00382468(2) != 0 ? D_L20_001DF150 : D_L20_001DF154;
                k = func_00382468(10);
                func_L01_00463378(&res, &vel, &vel, D_L20_001DF13C, D_L20_001DF140, i * 4, 15,
                                  (5 * (k + 20) + 2) / 6, color);
            }
            for (i = 0; i < 2; i++) {
                func_0038D028(&res, &s->set[n].g[2][i], M);
                vel = s->set[n].g[6][i];
                vel.w = D_L20_001DF148;
                func_00382468(2);
                k = func_00382468(10);
                func_L01_00463378(&res, &vel, &vel, D_L20_001DF13C, D_L20_001DF140, s->idx[i] >> 1, 15,
                                  (5 * (k + 20) + 2) / 6, D_L20_001DF154);
            }
        }
    }
}
