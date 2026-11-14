/* func_L40_004250A0: near miss, 5 diff at every place. 1276 bytes, 10 places (levels 40-45,
   50-53), src/levels/shared/L40_00424F88.c. Needs "-mvu0-use-vf0-vf2 ... @ps2as" on that file's
   line (vadd.xyz through include/vu0.h; Ps2EeAs for the loop's .p2align nop and the $gp loads).
   The multiplayer moby's message handler (msg[0] & 0xF: 0 position, 1 spawn/die, 2 damage).
   Written from retail by c9 (2026-11-14). What closed rows:
   - case 1's func_L01_003303B8 set-up: m + 0x10 in a local (pos) set before func_L39_005BE900,
     so it sits in $s4 and `$4 = pos` is an early register copy in sched1; with that, every
     stack-argument constant (0x1010000 a1, 0x388EF7 v1, 1 v0, 0x63F7 a2 ...) allocates as retail
     with plain constants;
   - the two byte-add loops as one inline helper (acc8) and the 0x58 offset as a struct member of
     D_L40_00357260 (lui/addiu %lo then addiu 0x58, i in $a1, pointer in $a0);
   - one extern u8 *D_L40_0024845C for all three entity tables: Ps2EeAs writes the first use as
     lui/lw and the later ones $gp-relative, as retail; e = D; e += idx << 8;
   - the -1 tests as u32 (lui/ori 0xFFFFFFFF), the "m[0x20] == 1: return" tail written in both arms
     (cse keeps the constant-1 register $s4; jump2 cross-jumps them), the -1 arm as the else;
   - case 1 stores in the order s+8, s+0xC, s+0; func_L01_00452310's prototype interleaved
     (ptr, f, int, f, ptr, f, int, f, int, f, int, f, f, int, int).
   Left (5 rows, case 2's last block): retail keeps dt in $f0, the pv+0x30 load in $f3, 0.0 in
   $f1, the difference in $f0 and the result in $f4 ($f2 unused); ours puts the load and the
   result in $f2. Tried about 350 variants without a change: where dt is read or copied (inside
   or before either if), temporaries for the load/difference/result, if/else vs ternary vs
   stores in the arms vs result = 0 first, the compare written four ways, inline max helpers,
   block-scoped declarations, the locals as one struct, @ee29. The gap at $f2 looks like a pseudo
   that got $f2 and was removed after reload (a second 0.0 or a copy of dt that reload_cse
   folded), so retail's tail probably had one more value than ours. */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L40_00357260[];
extern u8 D_L40_00242930[] __attribute__((section(".sdata")));
extern u8 *D_L40_0024845C;

extern void func_L39_00662B18(void *, void *, s32);
extern s32 func_L40_00424D98(s32);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 *func_00382348(void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005BE900(void *, s32, f32);
extern void func_L39_005F33E0(s32, s32, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00452310(void *, f32, s32, f32, void *, f32, s32, f32, s32, f32, s32, f32, f32, s32, s32);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L40_004897A8(void *, s32);

static inline void acc8(u8 *b) {
    s32 i;
    for (i = 0; i < 8; i++) {
        ((struct { u8 _p[0x58]; f32 a[8]; } *)D_L40_00357260)->a[i] += b[i];
    }
}

void func_L40_004250A0(u8 *m, u32 *msg) {
    u8 *pv = *(u8 **)(m + 0x68);
    u8 *s = pv + 0x220;
    u8 *p;
    u8 *x;
    u8 *pos;
    u8 *e;
    u8 *e2;
    u8 *e3;
    s32 i;
    s32 idx;
    u32 nv;
    vu0_v4 v;
    vu0_v4 sph;
    f32 dt;
    f32 xx;
    f32 yy;

    *(s32 *)(pv + 0x2A0) = 0;
    switch (msg[0] & 0xF) {
    case 0:
        if (*(s32 *)(s + 8) != 0) {
            return;
        }
        nv = msg[1] + (msg[0] >> 13);
        if (*(s32 *)(s + 4) >= (s32)nv) {
            return;
        }
        *(s32 *)(s + 4) = nv;
        func_L39_00662B18(msg, s, 4);
        if (*(u32 *)(pv + 0x220) != -1) {
            if ((*(s32 *)(pv + 0x230) = func_L40_00424D98(*(s32 *)(pv + 0x220))) != 0) {
                if (m[0x20] == 1 || m[0x20] == 4) {
                    func_L01_004450F0(m, 2, -1);
                }
                p = *(u8 **)(pv + 0x230);
                *(u128_t *)(pv + 0x200) = *(u128_t *)(p + 0x10);
                x = func_00382348(p);
                if (x != 0) {
                    func_0038CE20(&v, *(u8 **)(pv + 0x230) + 0xE0, *(f32 *)(x + 0x10) * -0.5f);
                    vec_add_ab(pv + 0x200, pv + 0x200, &v);
                }
                *(u128_t *)(pv + 0x210) = *(u128_t *)(pv + 0x200);
                return;
            }
            if (m[0x20] == 1) {
                return;
            }
            func_L01_004450F0(m, 4, -1);
            return;
        } else {
            *(s32 *)(pv + 0x230) = 0;
            if (m[0x20] == 1) {
                return;
            }
            func_L01_004450F0(m, 4, -1);
            return;
        }
    case 1:
        func_L39_00662B18(msg, &v, 8);
        acc8((u8 *)&v);
        if (m[0x20] != 5) {
            pos = m + 0x10;
            sph = *(vu0_v4 *)pos;
            sph.w = 3.5f;
            if (func_L39_005BE900(&sph, 0, m[0x30]) != -1) {
                func_L39_005F33E0(1, 0, m);
                func_L01_003303B8(pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 2.0f, 0.0f, 0.0f, 2.0f,
                                  1, 1, 1, 0, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_L01_00452310(m, -1.0f, 0x1FF, 3.0f, D_L40_00242930, 7.0f, 1, 6.0f, 0x23, 12.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0);
            }
            func_L01_004450F0(m, 5, -1);
        }
        *(s32 *)(s + 8) = 1;
        *(s32 *)(s + 0xC) = msg[1];
        *(u32 *)(s + 0) = -1;
        *(f32 *)(pv + 0x30) = 0.0f;
        *(s32 *)(pv + 0x230) = 0;
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_L39_005F2FF8(m, 1);
        idx = *(s32 *)(pv + 0x284);
        if (idx >= 0) {
            e = D_L40_0024845C;
            e += idx << 8;
            *(s32 *)(e + 0x98) = 0;
            *(u16 *)(e + 0x34) = (*(u16 *)(e + 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(e, 1);
            func_L40_004897A8(e, *(s32 *)(pv + 0x290));
        }
        idx = *(s32 *)(pv + 0x288);
        if (idx >= 0) {
            e2 = D_L40_0024845C;
            e2 += idx << 8;
            *(s32 *)(e2 + 0x98) = 0;
            *(u16 *)(e2 + 0x34) = (*(u16 *)(e2 + 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(e2, 1);
            func_L40_004897A8(e2, *(s32 *)(pv + 0x294));
        }
        idx = *(s32 *)(pv + 0x28C);
        if (idx >= 0) {
            e3 = D_L40_0024845C;
            e3 += idx << 8;
            *(s32 *)(e3 + 0x98) = 0;
            *(u16 *)(e3 + 0x34) = (*(u16 *)(e3 + 0x34) | 0x41) & ~0x1000;
            func_L39_005F2FF8(e3, 1);
            func_L40_004897A8(e3, *(s32 *)(pv + 0x298));
        }
        break;
    case 2:
        func_L39_00662B18(msg, &dt, 4);
        func_L39_00662B18(msg, &v, 8);
        acc8((u8 *)&v);
        if (*(s32 *)(s + 8) == 0) {
            if ((s32)msg[1] > *(s32 *)(s + 0xC)) {
                yy = *(f32 *)(pv + 0x30);
                xx = yy - dt;
                if (0.0f < xx) {
                    yy = xx;
                } else {
                    yy = 0.0f;
                }
                *(f32 *)(pv + 0x30) = yy;
            }
        }
        break;
    }
}
