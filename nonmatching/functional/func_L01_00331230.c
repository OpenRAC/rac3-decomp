/* functional: medium. Decoded block by block from the PAL asm (3 particle bursts, light flash, shake, glow quad); table-index/PRNG state (gp+0x650) advanced per component as retail; byte scheduling and register use differ. */
typedef int Q_331230 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x0C];
    f32 scale;          /* 0x0C */
    u8 pad10[0x1C - 0x10];
    s16 h1C;            /* 0x1C */
    u8 pad1E[0x20 - 0x1E];
    s32 n20;            /* 0x20: burst counts */
    s32 n24;            /* 0x24 */
    s32 n28;            /* 0x28 */
    u8 pad2C[0x40 - 0x2C];
    s32 c40;            /* 0x40..0x5C: colours */
    s32 c44;
    s32 c48;
    s32 c4C;
    s32 c50;
    s32 c54;
    s32 c58;
    s32 c5C;
    u8 pad60[0x6C - 0x60];
    f32 f6C;            /* 0x6C */
} P_331230;
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern s32 D_001DCF00_sda;
__asm__(".extern D_001DCF00_sda, 4");
extern u8 D_L01_001E2A40[];
extern f32 D_L01_002AF410[];
extern u8 *D_L01_00221098[];
extern u8 *D_L01_00221208[];
extern u8 D_L01_002AF3C0[];
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_002F9578(f32, void *, void *, void *, s32, u8, u8, u8, u8);
extern s32 func_L01_00459590(f32, void *, s32);
extern void func_L01_003006C0(u8 *, void *, s32, s32);
extern void func_L01_00331D28(void *, f32);

void func_L01_00331230(u8 *obj, void *unused, void *vec, f32 fparam) {
    P_331230 *st = *(P_331230 **)(obj + 0x68);
    f32 *pos = (f32 *)(obj + 0x10);
    f32 *E;
    f32 V0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 *vv = (f32 *)vec;
    f32 f20, f21, f22, ang, ang0, big, mult;
    s32 i, k, c, n, g;
    u8 *r;
    s32 col;
    s32 w;

    f21 = st->scale * 4.5f * 210000.0f;
    f20 = st->scale * 3.0f * 210000.0f;
    r = func_L01_0046FB40(pos, vec, 0x19, st->c40, 0, 0x64, 0, 0, f20, f21, 0.0f);
    if (r != 0) {
        r[2] = *D_L01_00221208[0];
    }
    r = func_L01_0046FB40(pos, vec, 0x19, st->c44, 0, 0x64, 0, 0, f20, f21, 0.0f);
    if (r != 0) {
        r[2] = *D_L01_00221208[0];
    }
    for (k = 1; k >= 0; k--) {
        r = func_L01_0046FB40(pos, vec, 0x19, st->c40, 0, 0x7F, 0, 0, f20, f21, 0.0f);
        if (r != 0) {
            r[2] = D_L01_00221098[0x170 / 4][5];
        }
    }
    for (k = 1; k >= 0; k--) {
        r = func_L01_0046FB40(pos, vec, 0x19, st->c40, 0, 0x7F, 0, 0, f20, f21, 0.0f);
        if (r != 0) {
            r[2] = D_L01_00221098[0x170 / 4][6];
        }
    }
    E = (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460);
    ang0 = func_0038D160(E[0] - pos[0], E[1] - pos[1]);

    /* burst A: fast sparks, two particles each */
    for (i = 0; i < st->n20; i++) {
        k = (s32)func_L01_00443A18(2.0f, 5.0f);
        for (c = 0; c < 3; c++) {
            D_001DCF00_sda = (D_001DCF00_sda + 1) % 44;
            V0[c] = pos[c] + D_L01_002AF410[D_001DCF00_sda] * 0.1f * st->scale;
        }
        f22 = func_003824E0(0.6f, 1.0f) * st->scale;
        f21 = func_003824E0(9.0f, 12.0f) * st->scale;
        ang = func_0038DAB8(ang0, func_L01_00443A18(0.0f, 1.3962634f));
        f21 = f21 * 0.020000001f;
        v10[0] = func_0038D098(ang) * f21;
        v10[1] = func_0038D0B0(ang) * f21;
        v10[2] = 0.0f;
        f21 = func_003824E0(0.0f, 12.0f) * st->scale;
        v10[2] = f21 * 0.020000001f;
        v10[0] = v10[0] + vv[0];
        v10[1] = v10[1] + vv[1];
        v10[2] = v10[2] + vv[2];
        n = func_00382498(0x1E, 0x32);
        func_L01_004713C8(V0, v10, (n * 5 + 2) / 6, st->c48, k, 0x7F, 0x7F, 1,
                          f22 * 210000.0f, st->scale * 0.01f * 210000.0f, 0.00584f);
        k = -(k * 2);
        n = func_00382498(0x1E, 0x32);
        f22 = f22 * 6.0f;
        r = func_L01_004713C8(V0, v10, (n * 5 + 2) / 6, st->c4C, k, 0x30, 0x30, 0,
                              f22 * 210000.0f, st->scale * 0.02f * 210000.0f, 0.00584f);
        if (r != 0) {
            r[2] = *D_L01_00221098[0xD4 / 4];
        }
    }

    /* burst B */
    for (i = 0; i < st->n24; i++) {
        k = (s32)func_L01_00443A18(2.0f, 5.0f);
        for (c = 0; c < 3; c++) {
            D_001DCF00_sda = (D_001DCF00_sda + 1) % 44;
            V0[c] = pos[c] + D_L01_002AF410[D_001DCF00_sda] * 0.1f * st->scale;
        }
        f22 = func_003824E0(0.75f, 1.5f) * st->scale;
        f21 = func_003824E0(9.0f, 12.0f) * st->scale;
        ang = func_0038DAB8(ang0, func_L01_00443A18(0.0f, 1.3962634f));
        f21 = f21 * 0.020000001f;
        v10[0] = func_0038D098(ang) * f21;
        v10[1] = func_0038D0B0(ang) * f21;
        v10[2] = 0.0f;
        f21 = func_003824E0(0.0f, 12.0f) * st->scale;
        v10[2] = f21 * 0.020000001f;
        v10[0] = v10[0] + vv[0];
        v10[1] = v10[1] + vv[1];
        v10[2] = v10[2] + vv[2];
        n = func_00382498(0x1E, 0x32);
        func_L01_004713C8(V0, v10, (n * 5 + 2) / 6, st->c50, k, 0x7F, 0x7F, 5,
                          f22 * 210000.0f, st->scale * 0.01f * 210000.0f, 0.00584f);
    }

    /* burst C */
    for (i = 0; i < st->n28; i++) {
        k = (s32)func_L01_00443A18(2.0f, 5.0f);
        for (c = 0; c < 3; c++) {
            D_001DCF00_sda = (D_001DCF00_sda + 1) % 44;
            V0[c] = pos[c] + D_L01_002AF410[D_001DCF00_sda] * 0.1f * st->scale;
        }
        f22 = func_003824E0(0.6f, 1.0f) * st->scale;
        f21 = func_003824E0(9.0f, 12.0f) * st->scale;
        ang = func_0038DAB8(ang0, func_L01_00443A18(0.0f, 1.3962634f));
        f21 = f21 * 0.020000001f;
        v10[0] = func_0038D098(ang) * f21;
        v10[1] = func_0038D0B0(ang) * f21;
        v10[2] = 0.0f;
        f21 = func_003824E0(0.0f, 12.0f) * st->scale;
        v10[2] = f21 * 0.020000001f;
        v10[0] = v10[0] + vv[0];
        v10[1] = v10[1] + vv[1];
        v10[2] = v10[2] + vv[2];
        n = func_00382498(0x1E, 0x32);
        func_L01_004713C8(V0, v10, (n * 5 + 2) / 6, st->c54, k, 0x7F, 0x7F, 3,
                          f22 * 210000.0f, st->scale * 2100.0f, 0.00584f);
    }

    if (st->h1C != 0) {
        *(Q_331230 *)v10 = 0;
        v10[2] = st->scale * 8.0f * 0.020000001f;
        *(Q_331230 *)V0 = *(Q_331230 *)v10;
        V0[0] = V0[0] + vv[0];
        V0[1] = V0[1] + vv[1];
        V0[2] = V0[2] + vv[2];
        col = st->c5C;
        func_L01_002F9578(st->scale * 3.5f, obj, pos, V0, 0xD, col & 0xFF, (col >> 8) & 0xFF,
                          (col >> 16) & 0xFF, (u32)col >> 24);
    }
    if (0.0f < fparam) {
        *(Q_331230 *)V0 = *(Q_331230 *)pos;
        V0[3] = st->scale * 3.0f;
        if (func_L01_00459590(96.0f, V0, 0) > 0) {
            *(f32 *)(D_L01_002AF3C0 + 0x20) = fparam;
            *(f32 *)(D_L01_002AF3C0 + 0x24) = fparam;
            *(f32 *)(D_L01_002AF3C0 + 0x28) = fparam;
            func_L01_003006C0(D_L01_002AF3C0, pos, 0, 0);
        }
    }
    if (0.0f < st->f6C) {
        func_L01_00331D28(obj, st->f6C);
    }
}
