/* functional: high. Written from the PAL asm only (no draft). Draws the 0xABE effect: a 5x10 sphere-patch grid of textured quads, then 3x28 ribbon quads; all constants, quad layout (Quad at sp+0, matrix at sp+0x90), colours and uv orders checked against the asm. Compiled frame size equals retail (0x190); bytes differ only in constant loading (.sdata vs inline, file flag). */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 pos[4][4];
    u32 rgba[4];
    f32 uv[4][2];
    unsigned long count;
    unsigned long tex;
    unsigned long tex0;
    unsigned long alpha;
} Quad_00310558;

extern s32 D_001DEF40;
extern f32 func_L01_0040F518(f32, f32);
extern void func_0038D328(void *, void *);
extern long func_00389598(s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(f32, u32, u32);
extern void func_003D2DA0(Quad_00310558 *, f32 *, s32);

void func_L07_00310558(u8 *m) {
    Quad_00310558 q __attribute__((aligned(16)));
    f32 M[16] __attribute__((aligned(16)));
    u128_t axis __attribute__((aligned(16)));
    u8 *s;
    f32 radius, scroll, fade, amp, lat0, lat1, a0, a1, prevA, prevE, e1, r;
    s32 i, j, c0, c1, n;

    if (m == 0 || m[0x20] == 0xFE || m[0x20] == 0xFD || *(s16 *)(m + 0xAA) != 0xABE) {
        return;
    }
    s = *(u8 **)(m + 0x68);
    radius = *(f32 *)(s + 0x70) * *(f32 *)(s + 0x78);
    scroll = func_L01_0040F518((f32)D_001DEF40, 25.333334f) / 25.333334f;

    axis = *(u128_t *)(m + 0xF0);
    *(s32 *)&axis = 0;
    func_0038D328(M, &axis);
    *(u128_t *)&M[12] = *(u128_t *)(m + 0x10);
    q.tex = func_00389598(0x15);
    q.tex0 = 0xFF9000000260UL;
    q.alpha = 0x8000000048UL;
    q.count = 0;

    for (i = 0; i < 5; i++) {
        lat0 = (f32)i * 0.06981317f / 5.0f - 0.034906585f;
        lat1 = (f32)(i + 1) * 0.06981317f / 5.0f - 0.034906585f;
        for (j = 0; j < 10; j++) {
            a0 = func_0038DB48((f32)j * 1.3962634f / 10.0f) - 0.6981317f;
            a1 = func_0038DB48((f32)(j + 1) * 1.3962634f / 10.0f) - 0.6981317f;
            q.uv[0][0] = scroll + (func_0038D098(a0) + 1.0f) * 0.5f;
            q.uv[1][0] = scroll + (func_0038D098(a1) + 1.0f) * 0.5f;
            q.uv[2][0] = scroll + (func_0038D098(a0) + 1.0f) * 0.5f;
            q.uv[3][0] = scroll + (func_0038D098(a1) + 1.0f) * 0.5f;
            q.uv[0][1] = (func_0038D0B0(lat0) + 1.0f) * 0.5f;
            q.uv[1][1] = (func_0038D0B0(lat0) + 1.0f) * 0.5f;
            q.uv[2][1] = (func_0038D0B0(lat1) + 1.0f) * 0.5f;
            q.uv[3][1] = (func_0038D0B0(lat1) + 1.0f) * 0.5f;
            n = *(s32 *)(s + 0x74);
            if (n != 0) {
                amp = (f32)n / 15.0f * 64.0f;
            } else {
                amp = 64.0f;
            }
            c0 = (s32)(amp * func_0038D0B0((f32)i * 3.1415927f / 5.0f));
            c1 = (s32)(amp * func_0038D0B0((f32)(i + 1) * 3.1415927f / 5.0f));
            q.rgba[0] = (j == 0) ? 0xA06060 : ((c0 << 24) | 0xA06060);
            q.rgba[1] = (j == 9) ? 0xA06060 : ((c0 << 24) | 0xA06060);
            q.rgba[2] = (j == 0) ? 0xA06060 : ((c1 << 24) | 0xA06060);
            q.rgba[3] = (j == 9) ? 0xA06060 : ((c1 << 24) | 0xA06060);
            func_00382760(&q.pos[0], radius, a0, lat0);
            func_00382760(&q.pos[1], radius, a1, lat0);
            func_00382760(&q.pos[2], radius, a0, lat1);
            func_00382760(&q.pos[3], radius, a1, lat1);
            q.pos[0][3] = 1.0f;
            q.pos[1][3] = 1.0f;
            q.pos[2][3] = 1.0f;
            q.pos[3][3] = 1.0f;
            func_003D2DA0(&q, M, 0);
        }
    }

    q.tex = func_00389598(0xE);
    for (i = 0; i < 3; i++) {
        prevA = 0.0f;
        prevE = 0.0f;
        for (j = 0; j < 0x1C; j++) {
            a0 = func_0038DB48((f32)j * 1.3962634f / 28.0f) - 0.6981317f;
            a1 = func_0038DB48((f32)(j + 1) * 1.3962634f / 28.0f) - 0.6981317f;
            r = func_003824E0(a0, a1);
            if (j == 0) {
                prevA = a0;
            } else if (j == 0x1B) {
                r = a1;
            }
            q.uv[0][0] = (f32)j / 28.0f;
            q.uv[0][1] = 0.0f;
            q.uv[1][0] = (f32)(j + 1) / 28.0f;
            q.uv[1][1] = 0.0f;
            q.uv[2][0] = (f32)j / 28.0f;
            q.uv[2][1] = 1.0f;
            q.uv[3][0] = (f32)(j + 1) / 28.0f;
            q.uv[3][1] = 1.0f;
            n = *(s32 *)(s + 0x74);
            if (n != 0) {
                fade = 1.0f - (f32)n / 15.0f;
            } else {
                fade = q.uv[0][1];
            }
            if (fade < 0.0f) {
                fade = 0.0f;
            }
            c0 = func_0038DBD8(fade, 0x7FC04070, 0xFF0000);
            q.rgba[0] = c0;
            q.rgba[3] = c0;
            q.rgba[2] = c0;
            q.rgba[1] = c0;
            e1 = *(f32 *)(s + j * 4) * 0.017453292f * func_003824E0(-1.0f, 1.0f) * *(f32 *)(s + 0x78) * 3.0f;
            if (e1 > 0.027925268f) {
                e1 = 0.027925268f;
            }
            if (e1 < -0.027925268f) {
                e1 = -0.027925268f;
            }
            if (j == 0) {
                prevE = 0.0f;
            }
            func_00382760(&q.pos[0], radius, prevA, prevE);
            func_00382760(&q.pos[1], radius, r, e1);
            func_00382760(&q.pos[2], radius, prevA, prevE);
            prevE = e1;
            func_00382760(&q.pos[3], radius, r, e1);
            prevA = r;
            q.pos[2][2] -= 0.15f;
            q.pos[3][2] -= 0.15f;
            q.pos[3][3] = 1.0f;
            q.pos[0][3] = 1.0f;
            q.pos[1][3] = 1.0f;
            q.pos[2][3] = 1.0f;
            func_003D2DA0(&q, M, 0);
        }
    }
}
