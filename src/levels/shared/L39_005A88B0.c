#include "common.h"

typedef struct { u8 *f0; s32 f4, f8, fC; } E_005A8968;
typedef struct { s32 f0; u8 p4[0x20]; struct { s32 f24; u8 p28[0x9C]; } c[1]; } S_005A8968;
typedef struct { u8 p0[0x14C]; s32 f14C; } SH_005A8968;

/* localdecomp:start func_L39_005A88B0 */
typedef struct {
    int first, second, third, fourth;
    char stamp[8];
    int invalid;
} SaveInfoEntry;
typedef struct {
    char header[0x30];
    SaveInfoEntry entries[4];
} SaveInfoSlot;
extern SaveInfoSlot D_001A43E0[];
extern void *memcpy(void *, const void *, unsigned int);
int func_0039E788(char *a0);

/* from rac2-decomp's func_0029B0B0, renamed, constants adapted */
void func_L39_005A88B0(char *src, int slot, int entry)
{
    D_001A43E0[slot].entries[entry].invalid = func_0039E788(src) == 0;
    src += 0x10;
    D_001A43E0[slot].entries[entry].first = *(int *)src;
    src += 0xC;
    D_001A43E0[slot].entries[entry].second = *(int *)src;
    D_001A43E0[slot].entries[entry].third = *(unsigned char *)(src + 0x32);
    src += 0x88;
    D_001A43E0[slot].entries[entry].fourth = *(int *)src;
    memcpy(D_001A43E0[slot].entries[entry].stamp, src + 0xC, 8);
}
/* localdecomp:end func_L39_005A88B0 */

/* localdecomp:start func_L39_005A8968 */
extern s32 D_001D79B0_sda;
extern S_005A8968 D_1A43E0;
extern s32 func_0039E788();
extern s32 func_0039E6A8();
extern s32 func_11D2EC();
extern void func_0038CC88();
s32 func_L39_005A8968(u8 *p, u8 *end, s32 idx, E_005A8968 *tab) {
    s32 fail, total, i, n;
    u8 *dst, *data;
    s32 *slot;
    s32 val;

    if (func_0039E788(p) == 0) return 1;
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
                func_0038CC88(dst, data, n);
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
    if (total != func_0039E6A8(tab)) fail++;
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
/* localdecomp:end func_L39_005A8968 */

/* localdecomp:start func_L39_005A8BF8 */
typedef struct { u8 p0[0x148]; s32 f148; u8 p14C[0x10]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[8]; s32 f174; u8 p178[4]; s32 f17C; } M_005A8BF8;
__asm__(".extern D_001D79B8_sda, 4");
extern s32 D_001D79B8_sda;
__asm__(".extern D_240320, 16");
extern s32 D_240320;
extern u8 D_21E260[];
extern void func_139328(void *);
extern void func_192418(void *);
s32 func_L39_005A8BF8(void) {
    func_139328(&D_240320);
    func_192418(&D_240320);
    if (((M_005A8BF8 *)&D_1A43E0)->f148 == -1) return 0;
    if (((M_005A8BF8 *)&D_1A43E0)->f17C != 0 && ((M_005A8BF8 *)&D_1A43E0)->f15C < 3 && ((M_005A8BF8 *)&D_1A43E0)->f164 < 0) {
        ((M_005A8BF8 *)&D_1A43E0)->f174 = (s32)D_21E260;
        func_0039E7C8(D_21E260, 0, &D_001D79B8_sda);
        if (((M_005A8BF8 *)&D_1A43E0)->f164 < 0) {
            ((M_005A8BF8 *)&D_1A43E0)->f164 = 0x22;
            ((M_005A8BF8 *)&D_1A43E0)->f168 = ((M_005A8BF8 *)&D_1A43E0)->f148;
        }
    }
    return ((M_005A8BF8 *)&D_1A43E0)->f164 == 0x22;
}
/* localdecomp:end func_L39_005A8BF8 */

/* localdecomp:start func_L39_005A8CC8 */
extern s32 D_1FC340[];
__asm__(".extern D_2402A0, 16");
__asm__(".extern D_2402D0, 16");
__asm__(".extern D_2402E0, 16");
extern s32 D_2402A0, D_2402D0, D_2402E0;
void func_L39_005A8CC8(void) {
    D_2402A0 = -1;
    D_2402D0 = -1;
    D_2402E0 = -1;
    D_1FC340[12] = -1;
    D_1FC340[6] = -1;
}
/* localdecomp:end func_L39_005A8CC8 */
