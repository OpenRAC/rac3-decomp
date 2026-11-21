/* func_L08_003A3C90: NEAR 67 diff with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division). Calls, gp slot, the $f1 compare and the stores match; the diff is control flow: retail uses a branch-likely (bnel) for the call path with e+0x10 in its delay slot, and the 0xFE/0xFD test is two branches where gcc makes one sltiu. Tried: nested if for the byte test, a goto out of the b block. */
#include "common.h"

extern s32 func_L01_00456500(u8 *, s32);
extern s32 func_L01_00456250(void *);
extern f32 func_L01_0040E548(void *, void *);
extern u8 *D_L08_001DF21C;
extern u8 D_L08_00235280[];
extern u8 D_1BBE90[];
extern s32 D_001D545C[];

s32 func_L08_003A3C90(u8 *o, s32 flag) {
    u8 *st;
    u8 *e;
    u8 *f;
    s32 a;
    s32 b;
    s32 c;
    s32 h;
    s32 bits;
    u8 byte;

    st = *(u8 **)(o + 0x68);
    a = flag ? *(s32 *)(st + 0x2EC) : *(s32 *)(st + 0x2D4);
    b = flag ? *(s32 *)(st + 0x2F4) : *(s32 *)(st + 0x2DC);
    c = flag ? *(s32 *)(st + 0x2FC) : *(s32 *)(st + 0x2E4);

    if (a != -1 && func_L01_00456500(st + 0x220, a) != 0) {
        return 1;
    }
    if (b != -1) {
        e = D_L08_001DF21C + (b << 8);
        if (func_L01_00456250(e) != 0) {
            return 1;
        }
        h = (s16)*(u16 *)(e + 0xB2);
        bits = 1;
        if (D_L08_00235280[h + 0x464] == 0) {
            byte = D_1BBE90[(h >> 1) + (D_001D545C[0] << 10)];
            bits = (h & 1) ? ((byte >> 4) & 7) : (byte & 7);
        }
        if (bits != 0 && func_L01_0040E548(st + 0x220, e + 0x10) < 49.0f) {
            return 1;
        }
    }
    if (c == -1) {
        return 0;
    }
    f = D_L08_001DF21C + (c << 8);
    if (f != 0) {
        byte = f[0x20];
        if (byte != 0xFE && byte != 0xFD) {
            return 0;
        }
    }
    if (flag) {
        *(s32 *)(st + 0x2FC) = -1;
    } else {
        *(s32 *)(st + 0x2E4) = -1;
    }
    return 1;
}
