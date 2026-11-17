#include "common.h"

typedef struct R_L07_003A2380 {
    u8 pad0[0x1D0];
    s32 f1D0[8];
    u8 f1F0[8];
    u8 f1F8[8];
    s16 f200[8];
    s16 f210;
    s16 f212;
    s16 f214;
} R_L07_003A2380;
typedef struct Q_L07_003A2380 {
    u8 pad0[0x68];
    R_L07_003A2380 *f68;
} Q_L07_003A2380;

/* localdecomp:start func_L07_003A2108 */
extern Q_L07_003A2380 *D_L07_001DE330;
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
    s32 group;
    u8 *g;
    if (obj[0x20] == 0) {
        *(s16 *)(s + 0x214) = 0;
        *(s16 *)(s + 0x212) = 0;
        *(s16 *)(s + 0x210) = 0;
        D_L07_001DE330 = (Q_L07_003A2380 *)obj;
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
                u8 *lines = s + 0x1F0;
                u8 *line = lines + n;

                group = func_L07_003A2408(*line);
                if (group != -1) {
                    u8 *last = s + 0x218;
                    u8 *prev = last + group;
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
/* localdecomp:end func_L07_003A2108 */

/* localdecomp:start func_L07_003A2380 */
extern Q_L07_003A2380 *D_L07_001DE330;

s32 func_L07_003A2380(u8 a, s32 b, u8 c, s16 d)
{
    R_L07_003A2380 *r = D_L07_001DE330->f68;

    if (r->f214 < 8) {
        r->f1D0[r->f212] = b;
        r->f1F8[r->f212] = c;
        r->f1F0[r->f212] = a;
        r->f200[r->f212] = d;
        r->f212 = (r->f212 + 1) & 7;
        r->f214++;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L07_003A2380 */

/* localdecomp:start func_L07_003A2408 */
s32 func_L07_003A2408(u8 x) {
    if (x < 9) return 0;
    if (x < 17) return 1;
    if (x < 27) return 2;
    if (x < 98) return 3;
    return -1;
}
/* localdecomp:end func_L07_003A2408 */

/* localdecomp:start func_L07_003A2450 */
extern u8 *D_L07_001DE330_003A2450;
extern u8 D_001CCFD0[];
__asm__(".extern D_001CCFD0, 16");

void func_L07_003A2450(void) {
    u8 *m = D_L07_001DE330_003A2450;
    s16 *p = (s16 *)(*(u8 **)(m + 0x68) + 0x20E);
    s32 i;
    u16 *h;

    for (i = 7; i >= 0; i--) {
        *p = 0;
        p--;
    }
    D_L07_001DE330_003A2450[0x20] = 1;
    h = (u16 *)D_001CCFD0;
    if ((u16)(h[0x76 / 2] - 6) >= 2) h[0x76 / 2] = 5;
    if ((u16)(h[0x9E / 2] - 6) >= 2) h[0x9E / 2] = 5;
}
/* localdecomp:end func_L07_003A2450 */

/* localdecomp:start func_L07_003A24C8 */
extern u8 *D_L07_001DE330_003A24C8;
s32 func_L07_003A24C8(void) {
    u8 *m = D_L07_001DE330_003A24C8;
    u8 *p = *(u8 **)(m + 0x68);
    if (m[0x20] == 1 && *(s16 *)(p + 0x214) == 0) {
        return *(u16 *)(m + 0x96);
    }
    return 0;
}
/* localdecomp:end func_L07_003A24C8 */
