/* functional: medium. Equal structure after masking regs; float temp register naming differs only; needs vu0 flag line. */
#include "vu0.h"
typedef struct { s32 v[6]; } Arr6_0051FD90;
extern u8 D_L39_0024DE80[];
extern f32 D_001DF228_sda, D_001DF22C_sda, D_001DF230_sda, D_001DF234_sda;
extern Arr6_0051FD90 D_L39_0024A948;
extern Arr6_0051FD90 D_L39_0024A960;
extern f32 D_L39_0046F5E0[];
extern f32 func_0038CEA8(void *);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_L39_005BE900(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L39_005C6E90(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_003006C0(void *, void *, s32, s32);
extern u32 func_L01_00448D88(u32, s32);
extern void func_L39_005C7B40(void *, void *, u32, u32, f32, s32, s32, s32, s32, s32);

/* Multiplayer-menu level: the explosion effect of a big blast at `hit` (m = the blast object),
 * sibling of func_L39_0051EF98: strength from the distance to the nearest player, then sprays dust,
 * debris, a ring flash and sparks. */
void func_L39_0051FD90(u8 *m, vu0_v4 *hit) {
    vu0_v4 d, q20, q30, q40;
    Arr6_0051FD90 A, B;
    struct { f32 dist; s32 cntSpark; s32 big; } out;
    f32 dist, f20, f21;
    s32 cntDust, cntDebris, i, k, r;
    u8 *p = *(u8 **)(*(u8 **)(m + 0x68) + 0x30);
    u8 *ref;

    if (p != 0) {
        ref = D_L39_0024DE80 + p[0x24C9] * 0x460;
    } else {
        ref = D_L39_0024DE80;
    }
    vec_sub_ba(&d, ref, hit);
    cntDust = 5;
    dist = func_0038CEA8(&d);
    cntDebris = 10;
    q20 = *(vu0_v4 *)(m + 0x10);
    out.big = 1;
    out.cntSpark = 50;
    q20.w = 0.5f;
    if (func_L39_005BE900(&q20, &out, D_001DF234_sda) > 0) {
        if (out.dist < D_001DF228_sda * D_001DF228_sda) {
        } else if (out.dist < D_001DF22C_sda * D_001DF22C_sda) {
            cntDust = 2;
            cntDebris = 5;
            out.cntSpark = 25;
        } else if (out.dist < D_001DF230_sda * D_001DF230_sda) {
            cntDust = 0;
            cntDebris = 5;
            out.cntSpark = 10;
        } else {
            cntDust = 0;
            cntDebris = 3;
            out.cntSpark = 0;
        }
    } else {
        out.cntSpark = 0;
        cntDust = 0;
        out.big = 0;
        cntDebris = 0;
    }
    if (cntDust != 0) {
        q40.x = func_L39_005B4410(-1.0f, 1.0f);
        cntDust--;
        q40.y = func_L39_005B4410(-1.0f, 1.0f);
        q40.z = func_L39_005B4410(-1.0f, 1.0f);
        q40.w = 0.0f;
        d.z = d.z + dist * 0.5f;
        q30 = q40;
        func_0038CF68(&q30, &q30, dist / 5.0f * 0.020000001415610313f);
        func_0038CF68(&d, &d, (dist + dist) * 0.020000001415610313f);
        vec_add_ab(&q30, &q30, &d);
        func_L01_0040E6B8(&q30, &q30, 0.20000001788139343f);
        func_0038D000(&q30, &q30, m + 0xC0);
        func_L01_002FB660(hit, &q30, func_L39_005B43C8(50, 75), 0, 0, 0);
        for (k = cntDust; k > 0; k--) {
            f21 = func_L39_005B4410(0.4363323152065277f, 0.7853981852531433f);
            f20 = func_L39_005B44C8();
            func_00382760(&q40, func_L39_005B4410(13.0f, 20.0f) * 0.020000001415610313f, f20, f21);
            func_0038D000(&q40, &q40, m + 0xC0);
            func_L01_002FB660(hit, &q40, func_L39_005B43C8(50, 75), 1, 0, 0);
        }
    }
    qzero(&q30);
    if (cntDebris != 0) {
        k = cntDebris;
        do {
            s32 n17, n42;
            f20 = func_L39_005B4410(8.0f, 10.0f);
            k--;
            A = D_L39_0024A948;
            B = D_L39_0024A960;
            f20 = f20 * 0.020000001415610313f;
            i = func_L39_005B4398(6);
            r = func_L39_005B4398(6);
            n17 = func_L39_005B43C8(17, 33);
            n42 = func_L39_005B43C8(42, 58);
            func_L39_005C6E90(hit, &q30, A.v[i], B.v[r], n17, n42, 0, 0, 600000.0f, f20 * 1.5f);
        } while (k != 0);
    }
    D_L39_0046F5E0[8] = 40.0f;
    D_L39_0046F5E0[9] = 40.0f;
    D_L39_0046F5E0[10] = 40.0f;
    if (out.big != 0) {
        func_L01_003006C0(D_L39_0046F5E0, hit, 0, 0);
    }
    if (out.cntSpark != 0) {
        k = out.cntSpark;
        do {
            u32 c1, c2;
            f21 = func_L39_005B4410(0.13962633907794952f, 0.6108652353286743f);
            k--;
            f20 = func_L39_005B44C8();
            func_00382760(&q40, func_L39_005B4410(16.0f, 30.0f) * 0.020000001415610313f, f20, f21);
            c1 = func_L01_00448D88(0x4F007FFF, 0);
            c2 = func_L01_00448D88(0x1F00007F, 0);
            func_0038D000(&q40, &q40, m + 0xC0);
            func_L39_005C7B40(hit, &q40, c1, c2, 40000.0f, func_L39_005B43C8(50, 100) - 10, 1, -1, -1, 0);
        } while (k != 0);
    }
}
