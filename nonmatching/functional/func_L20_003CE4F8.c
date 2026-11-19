/* functional: high. Rewritten from the PAL asm (the nonmatching draft was an NTSC twin with different constants/offsets); every offset, gp global, callee and loop order checked against retail; rope 1/2 blocks folded into a loop over rope[2] (same call order); compiles via check.py, 566 byte diffs are scheduling/regalloc only. Unused 'position' copy kept as retail does it. */
extern s32 D_L20_001DEB70;
extern s32 D_L20_001DEB74;
extern f32 D_L20_001DEB48;
extern f32 D_L20_001DEB4C;
extern s32 D_L20_001DEB54;
extern s32 D_L20_001DEB58;
extern f32 D_L20_001DEB60;
extern s32 D_L20_001DEB68;
extern s32 D_L20_001DEB6C;
__asm__(".extern D_L20_001DEB70, 4");
__asm__(".extern D_L20_001DEB74, 4");
__asm__(".extern D_L20_001DEB48, 4");
__asm__(".extern D_L20_001DEB4C, 4");
__asm__(".extern D_L20_001DEB54, 4");
__asm__(".extern D_L20_001DEB58, 4");
__asm__(".extern D_L20_001DEB60, 4");
__asm__(".extern D_L20_001DEB68, 4");
__asm__(".extern D_L20_001DEB6C, 4");
extern vu0_v4 D_L20_001E2E00;
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_0038CF38(f32 *, f32 *);
extern void func_0038D328(void *, void *);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

typedef struct {
    vu0_v4 pos[32];
    vu0_v4 vel[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    vu0_v4 rotation;
} Rope_3CE4F8;
typedef struct {
    u8 pad0[8];
    s32 life;
    u8 pad0C[0x16];
    s16 timer;
    u8 pad24[4];
    u8 idx[4];
    u8 pad2C[4];
    Rope_3CE4F8 rope[2];
} Vars_3CE4F8;

void func_L20_003CE4F8(u8 *self) {
    vu0_v4 a[32];
    vu0_v4 b[32];
    vu0_v4 sum;
    vu0_v4 t0;
    vu0_v4 t1;
    vu0_v4 matrix[3];
    vu0_v4 position;
    vu0_v4 p;
    vu0_v4 q;
    Vars_3CE4F8 *v;
    s32 r;
    s32 i;
    s32 k;
    s32 j;
    s32 n;
    s32 index;
    s32 lo;
    s32 hi;
    f32 width;
    f32 displacement;

    lo = (D_L20_001DEB70 * 5 + 2) / 6;
    hi = (D_L20_001DEB74 * 5 + 2) / 6;
    *(f32 *)(self + 0x1C) = 1.0f;
    v = *(Vars_3CE4F8 **)(self + 0x68);
    r = func_00382498(lo, hi);
    v->life = (s16)r;
    v->timer = r;
    width = func_003824E0(4.0f, 5.0f);
    for (i = 0; i < 32; i++) {
        displacement = (0.5f - (f32)i / 31.0f) * width;
        if (i < 3 || i > 28) {
            qzero(&a[i]);
            qzero(&b[i]);
        } else {
            func_L01_00443B88(&a[i], 0.0f, D_L20_001DEB48);
            func_L01_00443B88(&b[i], 0.0f, D_L20_001DEB4C * 0.02f);
        }
        a[i].w = 1.0f;
        a[i].y += displacement;
    }
    for (r = 0; r < 2; r++) {
        for (i = 0; i < 32; i++) {
            if (i == 0 || i == 31) {
                v->rope[r].pos[i] = a[i];
                v->rope[r].vel[i] = b[i];
            } else {
                vec_add_ab(&sum, &a[i - 1], &a[i]);
                vec_add_ab(&sum, &sum, &a[i + 1]);
                func_0038CE20(&v->rope[r].pos[i], &sum, 0.333f);
                vec_add_ab(&sum, &b[i - 1], &b[i]);
                vec_add_ab(&sum, &sum, &b[i + 1]);
                func_0038CE20(&v->rope[r].vel[i], &sum, 0.333f);
            }
        }
    }
    for (r = 0; r < 2; r++) {
        for (k = 0; k < 4; k++) {
            func_L01_00443B88(&t0, D_L20_001DEB48, D_L20_001DEB48);
            index = (s32)func_003824E0((f32)k * 6.0f, (f32)(k + 1) * 6.0f) + 4;
            v->idx[k] = index;
            v->rope[r].grid[0][k] = v->rope[r].pos[index];
            v->rope[r].gvel[0][k] = v->rope[r].vel[index];
            for (j = 1; j < 4; j++) {
                func_L01_00443B88(&t1, 0.1f, 0.1f);
                func_L01_00443B88(&v->rope[r].gvel[j][k], 0.0f, D_L20_001DEB4C * 0.02f);
                vec_add_ab(&v->rope[r].grid[j][k], &v->rope[r].grid[j - 1][k], &t0);
                vec_add_ab(&v->rope[r].grid[j][k], &v->rope[r].grid[j][k], &t1);
            }
        }
    }
    for (r = 0; r < 2; r++) {
        if (func_0038CF38((f32 *)(self + 0x10), (f32 *)&D_L20_001E2E00) >= 4.0f) {
            v->rope[r].rotation.z = *(f32 *)(self + 0xF8);
            v->rope[r].rotation.y = *(f32 *)(self + 0xF4);
            v->rope[r].rotation.y += func_L01_00443A18(0.0f, 30.0f) * 0.017453292f;
            v->rope[r].rotation.x = func_00382538();
            func_0038D328(matrix, &v->rope[r].rotation);
            position = *(vu0_v4 *)(self + 0x10);
            for (n = 0; n < 32; n += 8) {
                s32 color;
                func_0038D028(&p, &v->rope[r].pos[n], matrix);
                q = v->rope[r].vel[n];
                q.w = D_L20_001DEB60;
                color = func_00382468(2) ? D_L20_001DEB68 : D_L20_001DEB6C;
                func_L01_00463378(&p, &q, &q, D_L20_001DEB54, D_L20_001DEB58,
                    n >> 1, 15, ((func_00382468(10) + 20) * 5 + 2) / 6, color);
            }
            for (n = 0; n < 2; n++) {
                func_0038D028(&p, &v->rope[r].grid[3][n], matrix);
                q = v->rope[r].gvel[3][n];
                q.w = D_L20_001DEB60;
                func_00382468(2);
                func_L01_00463378(&p, &q, &q, D_L20_001DEB54, D_L20_001DEB58,
                    v->idx[n] >> 1, 15, ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DEB6C);
            }
        }
    }
}
