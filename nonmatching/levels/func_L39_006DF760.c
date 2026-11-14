/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_006DCC00, the NTSC-U twin of func_L39_006DF760, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/39_multiplayer_menu/L39_006DC228.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L39_006DCC00 */
typedef struct {
    s16 a;
    s16 b;
} P_006DCC00;

typedef struct {
    u8 pad0[0x120];
    s32 sel[8];
    P_006DCC00 pair[8];
    u8 b160[8];
    u8 b168[8];
    u8 b170[8];
    u8 b178[8];
    f32 f180[8];
    f32 f1A0[2];
    s32 cur;
    u8 pad1AC[0xC];
    s16 h1B8[8];
    P_006DCC00 row[8][9];
    u8 pad2E8[0x520];
    s32 w808;
    s32 w80C;
    u8 pad810[0xC];
    s32 w81C;
    s32 w820;
    s32 w824;
} G_006DCC00;

typedef struct {
    u8 pad0[0xEC];
    f32 fEC;
    f32 fF0;
} H_006DCC00;

extern G_006DCC00 D_L39_001FD968;
extern H_006DCC00 D_001A6AD0;
extern void func_L39_006DC8F0(s32 *, s32, s32, s32);
extern void func_L39_006DC988(s32 *, s32, s32, s32);
extern void func_L39_006DCAE0(s32);
extern s32 func_L39_0066F7C8(u32);
extern f32 func_003BEB48(f32, f32, f32);

void func_L39_006DCC00(s32 *buf, s32 idx, f32 scale) {
    s32 sel;
    s32 same;
    s32 other;
    s32 i;
    s32 X0, X1, X2, X3, X4, X5, X6;
    s32 A, B, C, F, S6;

    sel = D_L39_001FD968.sel[idx];
    same = 0;
    other = 0;
    if (D_L39_001FD968.cur != -1) {
        if (D_L39_001FD968.cur == sel) {
            same = 1;
        } else {
            other = 1;
        }
    }
    buf[2] += same;
    buf[3] += other;
    func_L39_006DC988(buf, 4, 2, 3);
    buf[5] += D_L39_001FD968.pair[idx].a;
    buf[6] += D_L39_001FD968.pair[idx].b;
    func_L39_006DC988(buf, 8, 5, 6);
    if (D_L39_001FD968.w80C != 2) {
        if (0.0f < D_L39_001FD968.f1A0[sel]) {
            buf[9] += (s32)(D_L39_001FD968.f180[idx] * 100.0f / D_L39_001FD968.f1A0[sel]);
        }
        buf[10] += D_L39_001FD968.b160[idx];
    }
    buf[7] += D_L39_001FD968.h1B8[idx];
    buf[11]++;
    buf[89] += D_L39_001FD968.w81C;
    buf[92] += D_L39_001FD968.w820;
    buf[95] += D_L39_001FD968.w824;
    func_L39_006DC8F0(buf, 0x5A, 0x59, 0xB);
    func_L39_006DC8F0(buf, 0x5D, 0x5C, 0xB);
    func_L39_006DC8F0(buf, 0x60, 0x5F, 0xB);
    func_L39_006DC988(buf, 0x5B, 0x59, 5);
    func_L39_006DC988(buf, 0x5E, 0x5C, 6);
    func_L39_006DC8F0(buf, 0x45, 5, 0xB);
    func_L39_006DC8F0(buf, 0x46, 6, 0xB);
    func_L39_006DC8F0(buf, 0x47, 7, 0xB);
    func_L39_006DC8F0(buf, 0x48, 0xA, 0xB);
    func_L39_006DC8F0(buf, 0x49, 9, 0xB);
    if (D_L39_001FD968.w808 == 2) {
        func_L39_006DCAE0(idx);
        buf[13] += same;
        buf[14] += other;
    }
    i = func_L39_0066F7C8(1);
    buf[20] += D_L39_001FD968.row[idx][i].b;
    buf[21] += D_L39_001FD968.row[idx][i].a;
    X0 = 0;
    X1 = 0;
    X2 = 0;
    S6 = 0;
    F = 0;
    X3 = 0;
    X4 = 0;
    X5 = 0;
    X6 = 0;
    i = func_L39_0066F7C8(2);
    buf[32] += D_L39_001FD968.row[idx][i].b;
    buf[33] += D_L39_001FD968.row[idx][i].a;
    i = func_L39_0066F7C8(7);
    buf[22] += D_L39_001FD968.row[idx][i].b;
    buf[23] += D_L39_001FD968.row[idx][i].a;
    i = func_L39_0066F7C8(5);
    buf[24] += D_L39_001FD968.row[idx][i].b;
    buf[25] += D_L39_001FD968.row[idx][i].a;
    i = func_L39_0066F7C8(3);
    buf[26] += D_L39_001FD968.row[idx][i].b;
    buf[27] += D_L39_001FD968.row[idx][i].a;
    i = func_L39_0066F7C8(6);
    buf[28] += D_L39_001FD968.row[idx][i].b;
    buf[29] += D_L39_001FD968.row[idx][i].a;
    i = func_L39_0066F7C8(9);
    buf[30] += D_L39_001FD968.row[idx][i].b;
    buf[31] += D_L39_001FD968.row[idx][i].a;
    i = func_L39_0066F7C8(4);
    buf[34] += D_L39_001FD968.row[idx][i].b;
    buf[35] += D_L39_001FD968.row[idx][i].a;
    i = func_L39_0066F7C8(10);
    buf[36] += D_L39_001FD968.row[idx][i].b;
    buf[37] += D_L39_001FD968.row[idx][i].a;
    A = 0;
    B = 0;
    C = 0;

    switch (D_L39_001FD968.w80C) {
    case 0:
        if (0.0f < D_L39_001FD968.f1A0[sel]) {
            buf[44] += (s32)(D_L39_001FD968.f180[idx] * 100.0f / D_L39_001FD968.f1A0[sel]);
        }
        buf[45] += D_L39_001FD968.b160[idx];
        S6 = 0x2E;
        func_L39_006DC8F0(buf, 0x4D, 0x2C, 0x2E);
        X1 = 0x29;
        F = 0x2A;
        func_L39_006DC8F0(buf, 0x4C, 0x2D, 0x2E);
        X2 = 0x2B;
        X3 = 0x42;
        A = 0x26;
        B = 0x27;
        C = 0x28;
        X4 = 0x4A;
        X5 = 0x4B;
        X6 = 0x4E;
        X0 = 0x11;
        break;
    case 2:
        X1 = 0x32;
        S6 = 0x35;
        A = 0x2F;
        B = 0x30;
        C = 0x31;
        F = 0x33;
        X2 = 0x34;
        X3 = 0x44;
        X4 = 0x56;
        X5 = 0x57;
        X6 = 0x58;
        X0 = 0x12;
        break;
    case 1:
        if (0.0f < D_L39_001FD968.f1A0[sel]) {
            buf[60] += (s32)(D_L39_001FD968.f180[idx] * 100.0f / D_L39_001FD968.f1A0[sel]);
        }
        buf[61] += D_L39_001FD968.b160[idx];
        buf[62] += D_L39_001FD968.b170[idx];
        buf[63] += D_L39_001FD968.b178[idx];
        S6 = 0x40;
        X1 = 0x39;
        F = 0x3A;
        X2 = 0x3B;
        X3 = 0x43;
        X4 = 0x4F;
        X5 = 0x50;
        X6 = 0x55;
        X0 = 0x13;
        func_L39_006DC8F0(buf, 0x52, 0x3C, 0x40);
        func_L39_006DC8F0(buf, 0x51, 0x3D, 0x40);
        func_L39_006DC8F0(buf, 0x53, 0x3E, 0x40);
        func_L39_006DC8F0(buf, 0x54, 0x3F, 0x40);
        A = 0x36;
        B = 0x37;
        C = 0x38;
        break;
    }
    buf[A] += same;
    buf[B] += other;
    func_L39_006DC988(buf, C, A, B);
    buf[X1] += D_L39_001FD968.pair[idx].a;
    buf[F] += D_L39_001FD968.pair[idx].b;
    func_L39_006DC988(buf, X2, X1, F);
    buf[X3] += D_L39_001FD968.h1B8[idx];
    func_L39_006DC8F0(buf, X4, X1, S6);
    func_L39_006DC8F0(buf, X5, F, S6);
    func_L39_006DC8F0(buf, X6, X3, S6);
    buf[S6]++;
    if ((f32)buf[S6] < D_001A6AD0.fEC) {
        if (D_001A6AD0.fF0 < (f32)buf[S6]) {
            buf[X0] = (s32)func_003BEB48(0.0f, scale * 100.0f,
                                         ((f32)buf[S6] - D_001A6AD0.fF0) / (D_001A6AD0.fEC - D_001A6AD0.fF0));
        } else {
            buf[X0] = 0;
        }
    } else {
        buf[X0] = (s32)(scale * 100.0f);
    }
    buf[1] = (s32)((f32)(buf[17] + buf[19] + buf[18]) / 3.0f);
    for (i = 0; i < 100; i++) {
        if (i != 0 && i != 0xC && i != 0x41 && buf[i] < 0) {
            buf[i] = 0;
        }
    }
}
/* localdecomp:end func_L39_006DCC00 */
