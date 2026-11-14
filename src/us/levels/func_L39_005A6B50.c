#include "common.h"

typedef struct { u8 *f0; s32 f4, f8, fC; } E_005A8968;
typedef struct { s32 f0; u8 p4[0x20]; struct { s32 f24; u8 p28[0x9C]; } c[1]; } S_005A8968;
typedef struct { u8 p0[0x14C]; s32 f14C; } SH_005A8968;

/* localdecomp:start func_L39_005A6B50 */
extern s32 D_001D79B0_sda;
extern S_005A8968 D_1A43E0;
extern s32 func_003997F0();
extern s32 func_00399710();
extern s32 func_11D2EC();
extern void func_00388550();

/* Parses a saved-data block of tagged records against a table, copying each record that matches a
 * table entry into place, counting mismatches in sizes, checks and a total size from func_00399710,
 * and returns the number of failures. */
s32 func_L39_005A6B50(u8 *p, u8 *end, s32 idx, E_005A8968 *tab) {
    s32 fail, total, i, n;
    u8 *dst, *data;
    s32 *slot;
    s32 val;

    if (func_003997F0(p) == 0) return 1;
    p += 8;
    fail = 0;
    total = 8;
    for (i = 0; tab[i].f0 != 0; i++) tab[i].fC = 0;
    while (p < end && *(s32 *)p != -1) {
        for (i = 0; tab[i].f0 != 0; i++) {
            if (tab[i].f8 == *(s32 *)p) break;
        }
        if (tab[i].f0 != 0) {
            dst = tab[i].f0 + idx * tab[i].f4;
            if (((s32 *)p)[1] == tab[i].f4) {
                tab[i].fC = 1;
                n = tab[i].f4;
            } else if (((s32 *)p)[1] < tab[i].f4) {
                n = ((s32 *)p)[1];
                tab[i].fC = -1;
            } else {
                tab[i].fC = -2;
                n = tab[i].f4;
            }
            data = p + 8;
            if (func_11D2EC(dst, data, n)) D_001D79B0_sda++;
            if (tab[i].f8 != 0x1770) {
                func_00388550(dst, data, n);
                total += 8 + ((n + 3) & ~3);
            } else {
                total += 8 + ((((s32 *)p)[1] + 3) & ~3);
            }
        } else {
            fail++;
        }
        p += 8 + ((((s32 *)p)[1] + 3) & ~3);
    }
    total += 8;
    if (total != func_00399710(tab)) fail++;
    p += 8;
    for (i = 0; tab[i].f0 != 0 && tab[i].f8 != *(s32 *)p; i++) {
        if (tab[i].fC <= 0) fail++;
    }
    slot = &D_1A43E0.c[((SH_005A8968 *)&D_1A43E0)->f14C].f24;
    val = *slot;
    val += fail;
    *slot = val;
    return fail;
}
/* localdecomp:end func_L39_005A6B50 */
