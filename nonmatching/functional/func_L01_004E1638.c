/* functional: medium. Per-frame hero stats/achievement tracker written from the PAL asm (no draft): all 17 calls match retail in order; branch structure re-derived by hand (labels follow retail), repeated stat record update folded into a static helper. Not gate-tested; the pad pointer D_001D52FC is u8* here (the file declares it as s32 later). */
#include "vu0.h"
extern s32 D_001D4C38;
extern u8 *D_001D52FC;
extern s32 D_L01_001DBFA4;
extern s32 D_L01_001DFB40;
extern u8 D_001A7C10[];
extern u8 D_001A7E18[];
extern s32 D_001A7D04;
extern u8 D_001426E0[];
extern u8 D_00142CA0[];

/* one "stat" record: u16 count (saturating), u32 best (max of the rescaled frame counter), u32 mask of levels */
static void stat_hit_4E1638(u8 *b) {
    s32 v;
    if (*(u16 *)b <= 0xFFFE) *(u16 *)b += 1;
    v = (D_001D4C38 * 5 + 2) / 6;
    if (*(u32 *)(b + 4) < (u32)v) *(u32 *)(b + 4) = v;
    *(u32 *)(b + 8) |= (1 << D_001D545C) | 0x80000000;
}

void func_L01_004E1638(void) {
    extern s32 func_L01_0041A5B0(s32, s32);
    extern s32 func_L01_0041A4F0(void);
    extern s32 func_L01_00418FB8(s32);
    extern void func_L01_0041BF08(void);
    extern s32 func_L01_00513EF0(void);
    extern s32 func_L01_004606E8(s32, s32, s32, s32);
    extern s32 func_0039EF28(void);
    u8 *h = (u8 *)&D_001A4BE0;
    u8 *S = D_001A7C10;
    u8 *T = D_001A7E18;
    u8 *P;
    s32 st = *(s32 *)(h + 0x25C4);
    s32 neg, sv, n, newst, tick, v, cnt, i, lt9;
    f32 px, ax;

    if (D_L01_001DBFA4 != st) {
        if (st == 0xD || st == 0xF) stat_hit_4E1638(S + 0x3C);
        else if (st == 0xA || st == 0x10) stat_hit_4E1638(S + 0x30);
        else if (st == 8) stat_hit_4E1638(S + 0x18);
        D_L01_001DBFA4 = *(s32 *)(h + 0x25C4);
    }
    if (*(u16 *)(T + 0x15C) != 0) goto L1AB4;
    if (!(D_001D545C < 5)) goto L1AB4;
    if (*(u16 *)(S + 0x1D4) != 0) goto L1AB4;
    if (*(s32 *)(h + 0x25C4) == 1 || *(s32 *)(h + 0x25C4) == 0x1D) goto L1AB4;
    px = *(f32 *)(D_001D52FC + 0x100);
    ax = fabs_asm(px);
    neg = px < 0.0f;
    sv = *(s32 *)(h + 0x710);
    if (sv == 1) goto C1;
    if (sv < 2) {
        if (sv == 0) goto C0;
        goto L1AB4;
    }
    if (sv == 2) goto C2;
    if (sv == 3) goto C3;
    goto L1AB4;
C0:
    if (!(0.8f < ax)) goto L1AB4;
    *(s32 *)(h + 0x714) = neg;
    *(s32 *)(h + 0x710) = 1;
    *(s32 *)(h + 0x71C) = 0;
    *(s32 *)(h + 0x718) = 0;
    goto L1AB4;
C1:
    n = *(s32 *)(h + 0x718) + 1;
    *(s32 *)(h + 0x718) = n;
    if (ax < 0.2f) {
        if (n < 9) {
            *(s32 *)(h + 0x710) = 0;
            goto L1AB4;
        }
        newst = 2;
    } else {
        if (*(s32 *)(h + 0x714) == neg) goto L1AB4;
        if (n < 9) {
            *(s32 *)(h + 0x710) = 0;
            goto L1AB4;
        }
        newst = 3;
    }
    *(s32 *)(h + 0x71C) = 0;
    *(s32 *)(h + 0x710) = newst;
    goto L1AB4;
C2:
    n = *(s32 *)(h + 0x71C) + 1;
    *(s32 *)(h + 0x71C) = n;
    if (0.8f < ax && *(s32 *)(h + 0x714) != neg) {
        *(s32 *)(h + 0x71C) = 0;
        *(s32 *)(h + 0x710) = 3;
        goto L1AB4;
    }
    if (*(s32 *)(h + 0x71C) >= 0x65) *(s32 *)(h + 0x710) = 0;
    goto L1AB4;
C3:
    n = *(s32 *)(h + 0x71C) + 1;
    *(s32 *)(h + 0x71C) = n;
    if (n >= 0x22 && *(s32 *)(h + 0x718) + 0x11 < n) {
        stat_hit_4E1638(S + 0x1E0);
        if (*(u16 *)(S + 0x1E0) >= 2) func_L01_0041A5B0(0xB7A, 0x1D);
        *(s32 *)(h + 0x710) = 0;
        goto L1AB4;
    }
    if (ax < 0.2f || neg == *(s32 *)(h + 0x714)) *(s32 *)(h + 0x710) = 0;
L1AB4:
    tick = D_L01_001DFB40;
    if (tick < 0x78) {
        if (D_001D545C == 2 || D_001D545C == 4 || D_001D545C == 7) {
            v = (D_001D4C38 * 5 + 2) / 6;
            if (!(0x2BF20U < (u32)(v - D_001A7D04))) goto L1B48;
            if (!(0x2BF20U < (u32)(v - *(s32 *)(T + 0x2D4)))) goto L1B50;
            if (*(s32 *)(T + 0x2D8) < 0) goto L1B48;
            func_L01_0041A5B0(0xB99, 0x3C);
        } else {
            goto L1B50;
        }
    }
L1B48:
    tick = D_L01_001DFB40;
L1B50:
    tick = D_L01_001DFB40;
    if (tick > 0 && (tick & 0x7F) == 0) {
        P = D_001426E0;
        if (P[0xDF] < 7) {
            cnt = 0;
            for (i = 0; i < 0x9C; i++) {
                if (*(s32 *)((u8 *)D_L01_002C5600 + D_001425C0[i] * 0xF0 + 8) == 0 && i != 9 && D_00142CA0[i] != 0) {
                    if (func_L01_00418FB8(i)) cnt++;
                }
                if (P[0x85] == 0 && (i == 0xB || i == 0x14)) {
                    if (D_00142CA0[i]) cnt--;
                }
                if (P[0xD6] != 0 && P[0xD6] == i) {
                    if (D_00142CA0[i]) cnt--;
                }
            }
            lt9 = cnt < 9;
            if (*(u16 *)(S + 0xFC) == 0) {
                if (!lt9 && *(u16 *)(T + 0xE4) == 0) {
                    if (func_L01_0041A5B0(0xB3E, 0x13)) {
                        P[0xDF] |= 1;
                        func_0039EF28();
                    }
                } else if (cnt >= 0x11 && !(P[0xDF] & 2)) {
                    if (func_L01_0041A5B0(0xB3E, 0x13)) {
                        P[0xDF] |= 2;
                        func_0039EF28();
                    }
                }
            }
            if (!lt9 && !(P[0xDF] & 4)) {
                if (func_L01_00513EF0()) {
                    if (func_L01_0041A5B0(0x14FC, 0x11F)) {
                        P[0xDF] |= 4;
                        func_0039EF28();
                    }
                } else {
                    if (func_L01_0041A5B0(0x14FB, 0x11E)) {
                        P[0xDF] |= 4;
                        func_0039EF28();
                    }
                }
            }
        }
        if (*(u16 *)(T + 0xFC) == 0) {
            if (func_L01_0041A4F0()) {
                if (D_00142668[0] == 0xC8) func_L01_0041A5B0(0xB40, 0x15);
            } else {
                if (D_00142668[0] == 0x64) func_L01_0041A5B0(0xB40, 0x15);
            }
        }
    }
    if (*(s16 *)(h + 0x1434) == 0) {
        if (*(s32 *)(h + 0x16B0) != 1) {
            *(s16 *)(h + 0x220) = 0;
            goto L1E40;
        }
        if (func_L01_004606E8(0x28, 2, 0, 0) == 0) {
            *(s16 *)(h + 0x220) = 0;
            goto L1E40;
        }
    }
    if (*(s32 *)(h + 0x25C4) != 0) *(u16 *)(h + 0x220) += 1;
L1E40:
    if (*(s16 *)(h + 0x220) >= 0x33) stat_hit_4E1638(S + 0x1BC);
    func_L01_0041BF08();
}
