/* functional: high. Retail repeats the state-sync tails per branch; C uses one tail with an offset (0x2FC/0x2DC/0x260). 233 diffs, all control-flow shape. Mode a2==0 reads obj->24->0x10 with no null check, as retail. */
#include "common.h"
extern u8 *D_L04_001DFD9C;
extern s32 D_001D545C;

void func_L04_003C89E0(s32 a0, s32 a1, s32 a2) {
    u8 *obj = D_L04_001DFD9C + (a0 << 8);
    u8 *cls;
    s32 b7c, b7d, b7f, off, game;
    u8 *pv;
    u8 *m;

    if (obj == 0) return;
    if (obj[0x20] == 0xFE) return;
    if (obj[0x20] == 0xFD) return;
    b7c = *(s8 *)(a1 + 0x7C);
    b7d = *(s8 *)(a1 + 0x7D);
    b7f = *(s8 *)(a1 + 0x7F);
    cls = *(u8 **)(obj + 0x24);
    if (a2 != 0) {
        if (b7c > 0) {
            *(u16 *)(obj + 0x34) &= ~2;
        } else if (b7c < 0) {
            *(u16 *)(obj + 0x34) |= 2;
        }
        if (b7d > 0) {
            if (!(cls != 0 && cls[0x46] == 0x12)) {
                obj[0x31] = 1;
                *(u16 *)(obj + 0x34) &= ~1;
            }
        } else if (b7d < 0) {
            if (!(cls != 0 && cls[0x46] == 0x12)) {
                obj[0x31] = 0;
                *(u16 *)(obj + 0x34) |= 1;
            }
        }
        if (b7f > 0) {
            if (cls != 0) *(s32 *)(obj + 0x98) = *(s32 *)(cls + 0x10);
        } else if (b7f < 0) {
            if (cls != 0) *(s32 *)(obj + 0x98) = 0;
        }
    } else {
        if (b7c > 0) {
            if (!(cls != 0 && cls[0x46] == 0x12)) *(u16 *)(obj + 0x34) |= 2;
        } else if (b7c < 0) {
            if (!(cls != 0 && cls[0x46] == 0x12)) *(u16 *)(obj + 0x34) &= ~2;
        }
        if (b7d > 0) {
            if (!(cls != 0 && cls[0x46] == 0x12)) {
                obj[0x31] = 0;
                *(u16 *)(obj + 0x34) |= 1;
            }
        } else if (b7d < 0) {
            if (!(cls != 0 && cls[0x46] == 0x12)) {
                obj[0x31] = 1;
                *(u16 *)(obj + 0x34) &= ~1;
            }
        }
        if (b7f > 0) {
            *(s32 *)(obj + 0x98) = 0;
        } else if (b7f < 0) {
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        }
    }
    game = D_001D545C;
    if (game == 4) {
        if (*(s16 *)(obj + 0xAA) != 0x16E5) return;
        off = 0x2FC;
    } else if (game == 0xE) {
        if (*(s16 *)(obj + 0xAA) == 0x1612) {
            off = 0x2DC;
        } else if (*(s16 *)(obj + 0xAA) == 0x1699) {
            off = 0x260;
        } else {
            return;
        }
    } else {
        return;
    }
    pv = *(u8 **)(obj + 0x68);
    if (pv == 0) return;
    m = *(u8 **)(pv + off);
    if (m == 0) return;
    if (obj[0x31] != 0) {
        *(u16 *)(m + 0x34) &= ~1;
        (*(u8 **)(pv + off))[0x31] = 1;
    } else {
        *(u16 *)(m + 0x34) |= 1;
        (*(u8 **)(pv + off))[0x31] = 0;
    }
    m = *(u8 **)(pv + off);
    if (*(s32 *)(obj + 0x98) != 0) {
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    } else {
        *(s32 *)(m + 0x98) = 0;
    }
}
