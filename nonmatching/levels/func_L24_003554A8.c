/* func_L24_003554A8: 99 differences (level 24, file L24_003554A8.c, -mvu0-use-vf0-vf2 @ps2as). The target search over
   the moby list D_L24_001DF528 (distance, height, class 0x1F4/0x1663, path check through D_L24_001DF1CC and
   func_L24_00432C00) has retail's instructions and block order; what differs is register allocation: retail keeps ok
   in $s0 and the moby in $s1 (this C the other way round), computes the argument m+0x10 into $a1 and copies it to $s2,
   and loads -1 and 0x30 once per pass where this C rematerialises them. Written as a while loop gcc hoists both
   constants out of the loop into $fp/$s7 (124 differences); the goto loop here does not. Tried (about 15 compiles): p
   assigned in the call, m+0x10 at every use, a pos local, ok initialised, the height read through p, the table entry
   kept in e. */
#include "common.h"
#include "vu0.h"
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00456250(void *);
extern s32 func_L24_00432C00(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_L24_001DF528;
extern u8 *D_L24_001DF1CC;

s32 func_L24_003554A8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *m;
    u8 *best;
    u8 *p;
    f32 bd;
    s32 ok;
    s32 a;
    s32 b;
    s32 id;
    u8 *e;

    if (*(s32 *)(s + 0x2F0) != 0) {
        *(u8 **)(s + 0x2E0) = 0;
        return 0;
    }
    m = D_L24_001DF528;
    bd = 0.0f;
    best = 0;
    if (m == 0) goto done;
loop:
        p = m + 0x10;
        if (func_0038CF38(obj + 0x10, p) <= 20.0f) {
            if (fabs_asm(*(f32 *)(p + 8) - *(f32 *)(obj + 0x18)) < 5.0f) {
                id = *(s16 *)(m + 0xAA);
                if ((id == 0x1F4 || id == 0x1663) && *(s16 *)(m + 0xB2) != 0 && func_L01_00456250(m) == 0) {
                    a = *(s32 *)(s + 0x2C0);
                    b = *(s32 *)(s + 0x2F8);
                    if (a == -1 && b == -1) {
                        ok = 1;
                    } else if (*(s16 *)((e = D_L24_001DF1CC + a * 0x30) + 0x30) == 0 && *(s16 *)(D_L24_001DF1CC + b * 0x30 + 0x30) == 0) {
                        ok = 1;
                    } else {
                        if (b == -1) {
                            b = **(s32 **)(e + 0x3C);
                        } else {
                            b = **(s32 **)(D_L24_001DF1CC + b * 0x30 + 0x3C);
                        }
                        ok = func_L24_00432C00(p, b, 0) != 0;
                    }
                    if (best == 0 && ok) {
                        best = m;
                        bd = func_0038CF38(obj + 0x10, best + 0x10);
                    } else if (func_0038CF38(obj + 0x10, p) <= bd && ok) {
                        bd = func_0038CF38(obj + 0x10, p);
                        best = m;
                    }
                }
            }
        }
        m = *(u8 **)(m + 0x28);
    if (m != 0) goto loop;
done:
    if (best != 0) {
        *(u8 **)(s + 0x2E0) = best;
        func_L01_00456230(best, 1);
        return 1;
    }
    *(u8 **)(s + 0x2E0) = 0;
    return 0;
}
