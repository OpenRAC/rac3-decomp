#include "common.h"

/*
 * PAL reconstruction; stock check.py: 6 differences in 632 bytes.
 * Flags: -O2 -G8 -fopt-stack -mno-check-zero-division.
 * The line/history base-plus-offset computations associate the index first;
 * history's group then occupies $v1 instead of retail's $a1.
 * Integer pointer sums, struct-array members and widened sums repeat these
 * six differences. An inline pointer helper instead hoists both array bases.
 * Stopped after six compiles, including three identical six-word residuals.
 * No source marker replaced. Full PAL/US build verification remains pending.
 */
extern u8 *D_L07_001DE330_003A2108;
extern u8 D_001CCFD0[];
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_0038CB00(s16 *);
extern s32 func_L07_003A2408(u8);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);

void func_L07_003A2108(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    s32 i;
    u8 n;
    u8 *line;
    s32 group;
    u8 *g;
    if (obj[0x20] == 0) {
        *(s16 *)(s + 0x214) = 0;
        *(s16 *)(s + 0x212) = 0;
        *(s16 *)(s + 0x210) = 0;
        D_L07_001DE330_003A2108 = obj;
        func_L01_004450F0(obj, 1, -1);
    }
    for (i = 0; i < *(s16 *)(s + 0x214); i++) {
        func_0038CB00((s16 *)(s + 0x200 + (((*(s16 *)(s + 0x210) + i) & 7) << 1)));
    }
    switch (obj[0x20]) {
    case 1:
        g = D_001CCFD0;
        if (*(s32 *)(g + 0x6C) != 0 || *(s32 *)(g + 0x24) != -1 || *(s32 *)(g + 0x94) != 0) break;
        *(u16 *)(obj + 0x96) += 1;
        while (*(s16 *)(s + 0x214) > 0) {
            n = *(u8 *)(s + 0x210);
            *(s16 *)(s + 0x214) -= 1;
            *(s16 *)(s + 0x210) = (*(u16 *)(s + 0x210) + 1) & 7;
            if (*(s16 *)((s32)s + (n << 1) + 0x200) > 0) {
                line = (u8 *)((s32)(s + 0x1F0) + n);
                group = func_L07_003A2408(*line);
                if (group != -1) {
                    u8 *prev = (u8 *)((s32)(s + 0x218) + group);
                    if (*prev == *line) continue;
                    *prev = *line;
                }
                if (*line >= 0x62 && *line <= 0x72) {
                    func_003A2B68(((*(s32 *)(s + (*line << 2))) & 0x3FFF) + 0xBB8, 0);
                } else if (*(u8 *)((s32)s + n + 0x1F8) != 0) {
                    func_003A2B68(*(s32 *)(s + (*line << 2)) + 0x7D0, *(s32 *)((s32)s + (n << 2) + 0x1D0));
                } else {
                    func_003A2B68((*(s32 *)(s + (*line << 2)) & 0x3FFF) + 0x7D0, 0);
                }
                func_L01_004450F0(obj, 2, -1);
                break;
            }
        }
        break;
    case 2:
        g = D_001CCFD0;
        if (*(s16 *)(g + 0x76) == 0 && *(s16 *)(g + 0x9E) == 3 && *(s16 *)(g + 0x98) < 7000) {
            func_003A1798();
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
}
