/* functional: medium. Decoded from the PAL asm block by block (types 0x3A,0x39,0x38,0x37,0x36); every call/arg/constant checked, loop shapes kept; byte-level scheduling and register use differ. */
typedef int Q_330820 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_330820;
typedef struct {
    u8 pad0[0x0C];
    f32 scale;          /* 0x0C */
    s16 type;           /* 0x10: effect kind 0x36..0x3A */
    u8 pad12[0x16 - 0x12];
    s16 h16;            /* 0x16 */
    u8 pad18[0x2C - 0x18];
    s32 w2C;            /* 0x2C */
    s16 h30;            /* 0x30 */
    s16 h32;            /* 0x32 */
    u8 pad34[0x36 - 0x34];
    s16 h36;            /* 0x36 */
    s32 w38;            /* 0x38 */
    s16 h3C;            /* 0x3C */
    u8 pad3E[0x58 - 0x3E];
    s32 w58;            /* 0x58 */
    u8 pad5C[4];
    s32 w60;            /* 0x60 */
} P_330820;
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern s32 D_001DCF00_sda;
__asm__(".extern D_001DCF00_sda, 4");
extern u8 D_L01_001E2A40[];
extern f32 D_L01_002AF410[];
extern u8 *D_L01_00221098[];
extern u8 *D_001A71A0;
extern u8 D_L01_001EAA40[];
extern void func_L01_0044C638(void *, s32, void *, void *, void *, void *);
extern void func_L01_0044C870(void *, s32, void *, void *);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00470668(void *, void *, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, s32, s32);
extern f32 func_00382538(void);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00331DD0(void *);
extern void func_003C2880(void *);

void func_L01_00330820(u8 *o) {
    P_330820 *st = *(P_330820 **)(o + 0x68);
    f32 *pos = (f32 *)(o + 0x10);
    f32 *E;
    V4_330820 v0, v10, v20, v30, v40, v50;
    f32 ang, ang2, f21, f20, f23;
    s32 i, k, n, sgn, x;
    u8 *r;
    u8 *r2;

    if (st->w38 != 0) {
        func_L01_0044C638(o, st->w38, o + 0x10, o + 0xF0, o + 0x10, o + 0xF0);
    }
    if (func_0038CB00((u8 *)st + 0x10) != 0) {
        func_003C2880(o);
        return;
    }
    E = (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460);
    f23 = func_0038D160(E[0] - pos[0], E[1] - pos[1]);
    v0 = (V4_330820){0.0f, 0.0f, 0.0f, 0.0f};
    if (st->w38 != 0) {
        func_L01_0044C870(o, st->w38, o + 0x10, &v0);
    }

    if (st->type == 0x3A && st->h32 > 0) {
        i = 0;
        do {
            i++;
            func_00382580(&v10, st->scale * 0.3f, st->scale * 0.40000004f);
            v10.x = v10.x + v0.x;
            v10.y = v10.y + v0.y;
            v10.z = v10.z + v0.z;
            x = func_00382498(0x19, 0x28);
            func_L01_00470668(o + 0x10, &v10, (x * 5 + 2) / 6, 0.00584f);
        } while (i < st->h32);
    }

    if (st->type == 0x39) {
        sgn = 1;
        if (st->w2C > 0) {
            i = 0;
            do {
                sgn = -sgn;
                D_001DCF00_sda = (D_001DCF00_sda + 1) % 44;
                v10.x = pos[0] + D_L01_002AF410[D_001DCF00_sda] * st->scale;
                D_001DCF00_sda = (D_001DCF00_sda + 1) % 44;
                v10.y = pos[1] + D_L01_002AF410[D_001DCF00_sda] * st->scale;
                D_001DCF00_sda = (D_001DCF00_sda + 1) % 44;
                v10.z = pos[2] + D_L01_002AF410[D_001DCF00_sda] * st->scale;
                f21 = func_003824E0(0.020000001f, 0.040000003f) * st->scale;
                f20 = func_L01_00443A18(0.0f, 1.3962634f);
                ang = func_0038DAB8(f23, func_L01_00443A18(0.0f, 1.5707964f));
                func_00382760(&v20, f21, ang, f20);
                v20.x = v20.x + v0.x;
                v20.y = v20.y + v0.y;
                v20.z = v20.z + v0.z;
                r = func_L01_004669B0(&v10, 0.0f, 1.0f, 1.01f, st->scale * 1.5f * 210000.0f, sgn, &v20, st->w58, 0);
                if (r != 0) {
                    x = func_00382498(0x28, 0x46);
                    r[9] = 0x44;
                    *(s16 *)(r + 0xA) = (x * 5 + 2) / 6;
                    *(s32 *)(r + 0x24) = 3;
                    x = func_00382498(1, 0xA);
                    r[0x2A] = 0x40;
                    *(f32 *)(r + 0x3C) = (f32)((x * 5 + 2) / 6);
                    r[0x2B] = r[0xA];
                }
                i++;
            } while (i < st->w2C);
        }
    }

    if (st->type == 0x38 && st->h30 > 0) {
        i = 0;
        do {
            i++;
            f21 = func_003824E0(0.43633232f, 0.7853982f);
            f20 = func_00382538();
            f21 = f21;
            func_00382760(&v10, func_003824E0(10.0f, 20.0f) * 0.020000001f * st->scale, f20, f21);
            v10.x = v10.x + v0.x;
            v10.y = v10.y + v0.y;
            v10.z = v10.z + v0.z;
            x = func_00382498(0x64, 0x7D);
            func_L01_002FB660(o + 0x10, &v10, x, 2, 0, 1);
        } while (i < st->h30);
    }

    if (st->type == 0x37 && st->h3C != 0) {
        f21 = func_00382538();
        func_00382580(&v10, 1.0f, 1.0f);
        v20.x = E[0] - pos[0];
        v20.y = E[1] - pos[1];
        v20.z = E[2] - pos[2];
        v20.w = E[3];
        func_0038CE90(&v30, &v20, &v10);
        func_0038CF68(&v30, &v30, 1.0f);
        for (i = 99; i >= 0; i--) {
            k = (s32)func_L01_00443A18(2.0f, 5.0f);
            func_0038D890(&v40, &v30, &v10, f21);
            func_0038CF68(&v40, &v40, st->scale * 0.3f);
            x = func_00382498(0x14, 0x1B);
            r2 = func_L01_004713C8(o + 0x10, &v40, (x * 5 + 2) / 6, st->w60, k, 0x4F, 0, 1,
                                   st->scale * 231000.0f, st->scale * 252000.02f, 0.0f);
            if (r2 != 0) {
                r2[2] = *D_L01_00221098[0x170 / 4];
            }
            f21 = func_0038DAB8(f21, 0.06346652f);
        }
    }

    if (st->type == 0x36 && st->h16 != 0) {
        f21 = func_00382538();
        if (func_L01_003FB640(o + 0x10, 0x14, D_001A71A0, 1.0f) != 0) {
            v20 = *(V4_330820 *)(D_L01_001EAA40 - 0x20);
            v10 = *(V4_330820 *)D_L01_001EAA40;
        } else {
            func_00382580(&v10, 1.0f, 1.0f);
            v20 = *(V4_330820 *)(o + 0x10);
        }
        func_0038CF68(&v10, &v10, 0.05f);
        v20.x = v20.x + v10.x;
        v20.y = v20.y + v10.y;
        v20.z = v20.z + v10.z;
        func_0038CF68(&v10, &v10, 1.0f);
        E = (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460);
        v30.x = E[0] - pos[0];
        v30.y = E[1] - pos[1];
        v30.z = E[2] - pos[2];
        v30.w = E[3];
        func_0038CE90(&v40, &v30, &v10);
        func_0038CF68(&v40, &v40, 1.0f);
        if (st->h36 != 0) {
            i = 0;
            do {
                k = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&v50, &v40, &v10, f21);
                func_0038CF68(&v50, &v50, func_003824E0(5.0f, 9.0f) * 0.020000001f * st->scale);
                if (i % 3 == 0) {
                    x = func_00382498(0x14, 0x1B);
                    r2 = func_L01_004713C8(&v20, &v50, (x * 5 + 2) / 6, st->w60, k, 0x4F, 0, 1,
                                           st->scale * 231000.0f, st->scale * 252000.02f, 0.0f);
                    if (r2 != 0) {
                        r2[2] = *D_L01_00221098[0x170 / 4];
                    }
                }
                f21 = func_0038DAB8(f21, 0.06346652f);
                i++;
            } while (i < 100);
        } else {
            for (i = 99; i >= 0; i--) {
                k = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&v50, &v40, &v10, f21);
                func_0038CF68(&v50, &v50, st->scale * 0.3f);
                x = func_00382498(0x14, 0x1B);
                r2 = func_L01_004713C8(&v20, &v50, (x * 5 + 2) / 6, st->w60, k, 0x4F, 0, 1,
                                       st->scale * 231000.0f, st->scale * 252000.02f, 0.0f);
                if (r2 != 0) {
                    r2[2] = *D_L01_00221098[0x170 / 4];
                }
                f21 = func_0038DAB8(f21, 0.06346652f);
            }
        }
    }

    func_0038CB00((u8 *)st + 0x14);
    func_L01_00404A10(func_L01_00331DD0, o);
}
