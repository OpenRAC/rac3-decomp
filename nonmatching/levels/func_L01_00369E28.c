/* func_L01_00369E28 (Claude wave 14 r65, 2026-11-28). First draft kept here. */
/* func_L01_00369E28 (3128 B, 34 places, src/levels/shared/L01_00363E68.c, its own line
   '-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2'): first draft, written from retail by
   wr65 (wave 14, 2026-11-28). Called by func_L01_00369700 as (moby, &pos, &direction): a burst of sparks whose
   shape depends on the level of weapon slot 0x37 (D_L01_002C5600[D_001425C0[0x37]].kind >= 2): eight hit-test
   rays from pos along the hero's +0xC0 row (func_L01_00369C48 on a hit), then four spark loops per branch
   (func_0038D890 turns about the hero's +0xD0/+0xE0 rows by random degrees, func_L01_004713C8 particles with the
   0x30/0x20 kinds and the D_L01_00221098 pointer table entries 105/23/34, func_L01_00466F50 for the last).
   709 diff (p10 check.py, level 01), 52 rows aligned with registers masked (wr65/adiff.py; 759 vs 783 words):
   every call, constant and argument agrees; what differs is the loop control. Retail keeps the counts as
   values: fp = 16 is live across the first loops (eqz fp+4 guard, i < fp + 4 recomputed each pass,
   eqz fp + s2 = fp), the 12-pass loops test 8 + 4 at run time behind if (1)/if (8) guards, and
   several loops count up with slt; here the counts fold to constants and loop.c reverses the loops into
   countdowns. Retail's form looks like the counts were inline-helper parameters or locals the compiler did
   not propagate; not found this round. Also the first row index mult uses a0 where retail has v1. */
#include "common.h"

/* localdecomp:start func_L01_00369E28 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x25C0];
    u8 *x25C0;
} H_00369E28;
extern H_00369E28 D_001A4BE0_00369E28;
extern u8 *D_L01_00221098_00369E28[];
extern vu0_v4 D_L01_001EAA20_00369E28;

void func_L01_00369E28(u8 *moby, vu0_v4 *pos, vu0_v4 *vel) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_00369C48(vu0_v4 *pos);
    extern void func_0038D890(void *, void *, void *, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    s32 i;
    s32 n;
    s32 m;
    s32 life;
    u8 *p;

    if (D_L01_002C5600[D_001425C0[0x37]].kind >= 2) {
        a = *(vu0_v4 *)(D_001A4BE0_00369E28.x25C0 + 0xC0);
        n = 16;
        func_0038CF68(&a, &a, 12.0f);
        vec_add_ab(&b, &a, pos);
        for (i = 0; i < 8; i++) {
            func_0038CDF8(&d, pos, &b, func_003824E0(0.0f, 1.0f));
            func_L01_004C7D98(&d, &c);
            func_0038CF68(&c, &c, -5.0f);
            vec_add_ab(&c, &d, &c);
            if (func_L01_004CB2D8() == 0 && func_003D3CB0(&d, &c, 0, D_001A4BE0_00369E28.x25C0, 0) != 0) {
                func_L01_00369C48(&D_L01_001EAA20_00369E28);
            }
        }
        for (i = 0; i < n + 4; i++) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.2f, 0.6f));
            life = (func_00382498(30, 50) * 5 + 2) / 6;
            p = func_L01_004713C8(pos, vel, life, 0x5A182, func_00382498(1, 4), 0x30, 0, 0, 63000.004f, 42000.0f, 0.002f);
            if (p != 0) {
                p[3] = func_00382468(2) ? 0x48 : 0x44;
                p[2] = *D_L01_00221098_00369E28[105];
            }
        }
        for (; n != 0; n--) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-0.5f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-1.0f, 1.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.2f, 0.5f));
            life = (func_00382498(30, 50) * 5 + 2) / 6;
            p = func_L01_004713C8(pos, vel, life, 0x5A182, func_00382498(-1, -3), 0x20, 0, 0, 84000.0f, 168000.0f, 0.002f);
            if (p != 0) {
                p[3] = func_00382468(2) ? 0x48 : 0x44;
                p[2] = *D_L01_00221098_00369E28[23];
            }
        }
        m = 8;
        for (i = 0; i < m + 4; i++) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.2f, 0.6f));
            p = func_L01_004713C8(pos, vel, (func_00382498(30, 50) * 5 + 2) / 6, 0x5A182, -1, 0x30, 0, 0, 63000.004f, 21000.0f, 0.0016000000759959221f);
            if (p != 0) {
                p[3] = func_00382468(2) ? 0x48 : 0x44;
                p[2] = *D_L01_00221098_00369E28[34];
            }
            func_0038CF68(vel, vel, func_003824E0(0.25f, 0.5f));
        }
        for (i = 0; i < m + 4; i++) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-2.0f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-3.0f, 3.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.2f, 0.5f));
            func_L01_00466F50(pos, vel, 0x4005A182, -1.0f, -0.008f);
        }
    } else {
        for (i = 0; i < 16; i++) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-2.5f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-4.0f, 4.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.1f, 0.5f));
            life = (func_00382498(30, 50) * 5 + 2) / 6;
            p = func_L01_004713C8(pos, vel, life, 0x5A182, func_00382498(1, 4), 0x30, 0, 0, 63000.004f, 42000.0f, 0.00040000001899898052f);
            if (p != 0) {
                p[3] = func_00382468(2) ? 0x48 : 0x44;
                p[2] = *D_L01_00221098_00369E28[105];
            }
        }
        m = 8;
        for (i = 0; i < m + 4; i++) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-0.5f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-1.0f, 1.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.1f, 0.4f));
            life = (func_00382498(20, 40) * 5 + 2) / 6;
            p = func_L01_004713C8(pos, vel, life, 0x5A182, func_00382498(-1, -3), 0x20, 0, 0, 84000.0f, 168000.0f, 0.0f);
            if (p != 0) {
                p[3] = func_00382468(2) ? 0x48 : 0x44;
                p[2] = *D_L01_00221098_00369E28[23];
            }
        }
        for (i = 0; i < m; i++) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-2.5f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-4.0f, 4.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.1f, 0.5f));
            p = func_L01_004713C8(pos, vel, (func_00382498(20, 40) * 5 + 2) / 6, 0x5A182, -1, 0x30, 0, 0, 63000.004f, 21000.0f, 0.0f);
            if (p != 0) {
                p[3] = func_00382468(2) ? 0x48 : 0x44;
                p[2] = *D_L01_00221098_00369E28[34];
            }
            func_0038CF68(vel, vel, func_003824E0(0.25f, 0.5f));
        }
        for (i = 0; i < m; i++) {
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xD0, func_003824E0(-2.5f, 1.0f) * 0.017453292f);
            func_0038D890(vel, vel, D_001A4BE0_00369E28.x25C0 + 0xE0, func_003824E0(-4.0f, 4.0f) * 0.017453292f);
            func_0038CF68(vel, vel, func_003824E0(0.1f, 0.4f));
            func_L01_00466F50(pos, vel, 0x4005A182, -1.0f, -0.008f);
        }
    }
}
/* localdecomp:end func_L01_00369E28 */
