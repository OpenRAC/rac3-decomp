/* functional: medium. Boss/creature per-frame state machine (states 1-6) re-derived from PAL asm; jump-table order (state-1 -> cases 0..5) assumed ascending, table itself not readable here; callee arg lists and unknown helper meanings (e.g. func_L01_003303B8, func_L01_00463378) follow sibling matched code in L19_003CDD90.c; 622 words differ (register allocation shifts, s4/s5 swap), same structure. */
typedef struct {
    u8 p00[0x30];
    f32 f30;
    u8 p34[0x70 - 0x34];
    u8 b70[7];
    u8 b77;
    u8 p78[0x88 - 0x78];
    s32 f88, f8C, f90, f94, f98;
    u8 p9C[4];
    s32 fA0, fA4;
    f32 fA8, fAC, fB0, fB4, fB8, fBC;
} PV_3C2CC8;
extern s32 D_L19_001DE880_sda, D_L19_001DE884_sda, D_L19_001DE88C_sda, D_L19_001DF240_sda;
extern f32 D_L19_001DE888_sda, D_L19_001DE890_sda, D_L19_001DE894_sda, D_L19_001DE898_sda, D_L19_001DE89C_sda, D_L19_001DE8A0_sda, D_L19_001DE8A4_sda;
extern s32 D_L19_001DF240;
extern u8 D_001A4C60[], D_001A30B0[];
__asm__(".extern D_L19_001DE880_sda, 4");
__asm__(".extern D_L19_001DE884_sda, 4");
__asm__(".extern D_L19_001DE888_sda, 4");
__asm__(".extern D_L19_001DE88C_sda, 4");
__asm__(".extern D_L19_001DE890_sda, 4");
__asm__(".extern D_L19_001DE894_sda, 4");
__asm__(".extern D_L19_001DE898_sda, 4");
__asm__(".extern D_L19_001DE89C_sda, 4");
__asm__(".extern D_L19_001DE8A0_sda, 4");
__asm__(".extern D_L19_001DE8A4_sda, 4");
__asm__(".extern D_L19_001DF240_sda, 4");
extern s32 func_L01_0044C108(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00404808(void *, void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_0038D750(void *, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00448248(void *, s32, s32);
extern void func_003C6FB0(void *, void *, void *, void *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_L19_003C3998(u8 *);
extern u8 *func_L19_003C3A78(u8 *);
extern void func_L19_003C3788(u8 *);
extern void func_L19_003C3898(void *);
extern void func_L19_003C3B60(u8 *);

void func_L19_003C2CC8(u8 *o) {
    vu0_v4 t90, tA0, b, c;
    s32 d0, d4, d8;
    PV_3C2CC8 *v;
    u8 *h, *slot;
    s32 n, i, k1, k2, k3, col;
    f32 r, ang, r2, f20;
    u8 *vb;

    if (!func_L01_0044C108(o + 0x10)) return;
    if (o[0x20] == 0 && func_0038CF38(o + 0x10, D_001A4C60) < 9.0f) {
        func_003C2880(o);
        return;
    }
    v = *(PV_3C2CC8 **)(o + 0x68);
    vb = (u8 *)v;
    if (D_L19_001DE880_sda != 0) func_L01_00404808(func_L19_003C3B60, o);
    h = func_L01_00447490(o, 0x1170000, 0);
    if (h != 0) {
        if (!(D_L19_001DF240_sda < v->fA4)) {
            func_003A52A0(2, 0, o);
            v->f30 = v->f30 - *(f32 *)(h + 0x2C);
            if (v->f30 <= 0.0f) func_L01_004450F0(o, 5, -1);
            v->b77 = 0xFF;
            func_003C4A40(o, v->b70);
            v->fA4 = D_L19_001DF240 + D_L19_001DE884_sda;
        }
        o[0xA8] = 0xFF;
    }
    if (o[0x20] != 5) func_L01_0044ABD0(o, v->b70);
    if (o[0x20] == 0) func_L19_003C3788(o);
    switch ((u8)(o[0x20] - 1)) {
    case 0:
        if ((D_L19_001DF240 & 0x1F) != (((s32)o >> 8) & 0x1F)) break;
        if (v->f88 != -1 && !func_00382380(D_001A4C60, v->f88, 0)) break;
        if (v->f8C != -1 && func_L01_00445AD0(v->f8C, -1, 0)) break;
        func_L01_004450F0(o, 2, -1);
        break;
    case 1:
        if (func_L01_004561B8(o)) {
            if (v->f90 < 10) v->f94 = (s32)((f32)v->f90 * 50.0f);
            else v->f94 = (v->f90 * 5 + 2) / 6;
        }
        func_0038CAD0(v->f94);
        if (v->f98 == 0 || v->f94 > 0) break;
        if ((D_L19_001DF240 & 0xF) != (((s32)o >> 8) & 0xF)) break;
        if (func_L19_003C3998(o) <= 0) break;
        func_L01_004450F0(o, 3, -1);
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            if (!(v->fA0 != -1 && *(u8 **)(D_001A30B0 + (v->fA0 << 7) + 0xDC) == o && D_001A30B0[(v->fA0 << 7) + 0xD0] != 0))
                v->fA0 = func_003A52A0(1, 4, o);
            func_L19_003C3898(o);
        }
        func_L01_00448890(&v->fB0, &v->fA8, 0, v->fAC, 0.000628318579f, 0.000628318579f, 0.0314159282f);
        func_0038D750(vb + 0xD0, 2, v->fB0);
        func_L01_00448890(&v->fBC, &v->fB4, 0, v->fB8, 0.000628318579f, 0.000628318579f, 0.0314159282f);
        func_0038D750(vb + 0x110, 1, 1.57079637f - v->fBC);
        if (*(u16 *)(o + 0x96) >= 0x3D && fabs_asm(v->fB4) < 0.000349065871f && fabs_asm(v->fA8) < 0.000349065871f) {
            if (v->fA0 != -1) {
                slot = D_001A30B0 + (v->fA0 << 7);
                if (*(u8 **)(slot + 0xDC) == o && slot[0xD0] != 0) func_003A4F28(v->fA0);
            }
            v->fA0 = -1;
            func_L01_004450F0(o, 4, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(o)) {
            if (o[0x43] != 1) func_003C3A10(o, 1, 0, 0);
            v->f98 = v->f98 - 1;
        }
        if (func_L01_0044E1B8(o, 8.0f)) {
            r = func_0038DAB8(*(f32 *)(o + 0xF8), v->fB0);
            func_00382760(&t90, D_L19_001DE888_sda, r, v->fBC);
            func_003C2F58(o, 2, (u8 *)&tA0);
            h = func_L19_003C3A78(o);
            if (h != 0) {
                func_L19_003C2BF0(h, (void *)&tA0, (void *)&t90);
                i = 0;
                func_003A52A0(0, 0, o);
                if (D_L19_001DE88C_sda > 0) {
                    do {
                        i++;
                        r = func_003824E0(D_L19_001DE8A0_sda, D_L19_001DE8A4_sda);
                        func_0038CE20(&b, &t90, r);
                        f20 = func_00382538();
                        r2 = func_00382538();
                        func_00382760(&c, D_L19_001DE89C_sda, f20, r2);
                        vec_add_ab(&b, &b, &c);
                        r = func_003824E0(D_L19_001DE890_sda, D_L19_001DE894_sda);
                        qzero(&c);
                        b.w = r;
                        c.w = r + D_L19_001DE898_sda;
                        col = func_0038DBD8(0x60202020, 0x60707070, func_003824E0(0.0f, 1.0f));
                        n = func_00382468(0x1E) + 0x1E;
                        func_L01_00463378(&tA0, &b, &c, col, 0x30707070, 4, (n * 5 + 2) / 6, 4, -1);
                    } while (i < D_L19_001DE88C_sda);
                }
            }
        }
        if (!(o[0x60] & 2)) break;
        if (o[0x42] != o[0x43]) break;
        if (o[0x42] != 0) func_003C3A10(o, 0, 0, 0);
        func_L01_004450F0(o, 2, -1);
        break;
    case 4:
        if (v->fA0 != -1) {
            slot = D_001A30B0 + (v->fA0 << 7);
            if (*(u8 **)(slot + 0xDC) == o && slot[0xD0] != 0) func_003A4F28(v->fA0);
        }
        v->fA0 = -1;
        if (-0.261799395f < v->fBC) {
            func_L01_00448890(&v->fBC, &v->fB4, 0, -1.57079637f, 0.000628318579f, 0.000628318579f, 0.0314159282f);
            func_0038D750(vb + 0x110, 1, 1.57079637f - v->fBC);
        }
        if (*(u16 *)(o + 0x96) < 0x320) {
            qzero(&t90);
            t90.z = func_003824E0(0.0200000014f, 0.0300000012f);
            qzero(&tA0);
            tA0.w = 0.2f;
            t90.w = 0.1f;
            f20 = func_00382538();
            r = func_003824E0(-0.150000006f, 0.150000006f);
            b.x = func_0038D098(f20) * r;
            b.y = func_0038D0B0(f20) * r;
            b.z = 0.5f;
            vec_add_ba(&b, &b, o + 0x10);
            k1 = (func_00382498(5, 10) * 5 + 2) / 6;
            k2 = (func_00382498(0x3C, 0x64) * 5 + 2) / 6;
            k3 = (func_00382498(0x14, 0x28) * 5 + 2) / 6;
            func_L01_00463378(&b, &t90, &tA0, 0x75000000, 0x60404040, k1, k2, k3, -1);
        }
        func_003C6FB0(o, &d0, &d4, &d8);
        func_L01_00448248(&d0, 0, 2);
        func_L01_00448248(&d8, 0, 2);
        func_L01_00448248(&d4, 0, 2);
        func_L01_0043B9E8(o, d0, d4, d8);
        if (!(v->f30 < -1.0f)) break;
        func_L01_004450F0(o, 6, -1);
        break;
    case 5:
        qzero(&t90);
        if (v->fA0 != -1) {
            slot = D_001A30B0 + (v->fA0 << 7);
            if (*(u8 **)(slot + 0xDC) == o && slot[0xD0] != 0) func_003A4F28(v->fA0);
        }
        v->fA0 = -1;
        func_003A52A0(3, 0, o);
        func_L01_003303B8(o + 0x10, 0, 8, 8, 8, 8, 0xA, 2, 1.0f, 0.0f, 0.0f, 2.0f,
            0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_L01_00451FE0(o, 0xFFFD, &t90, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_004443E8(o, 0, 3);
        func_003C2880(o);
        return;
    }
    if (*(u16 *)(o + 0x96) < 0xFFFF) ++*(u16 *)(o + 0x96);
}
