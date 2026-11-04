#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *f1C;
    u8 pad20[0x38];
    s32 f58;
    u8 pad5C[0x24];
} E_005F2FF8;

/* localdecomp:start func_L39_005F2FF8 */
extern E_005F2FF8 D_1FE0E0[];
extern void func_L39_005F3088(s32);

void func_L39_005F2FF8(u8 *a0, s32 a1) {
    E_005F2FF8 *e;
    s32 i;

    if (a0 != 0) {
        e = D_1FE0E0;
        for (i = 0; i < 52; i++) {
            if (a0 == e->f1C) {
                if (a1 == 0 || (e->f58 & 4)) {
                    func_L39_005F3088(i);
                }
            }
            e++;
        }
        a0[0x6D] = 0xFF;
    }
}
/* localdecomp:end func_L39_005F2FF8 */

INCLUDE_ASM("asm/levels", func_L39_005F3088);

/* localdecomp:start func_L39_005F30E0 */
typedef struct {
    u8 pad0[80];
    u8 b;
    u8 pad51[47];
} E_5F09E0;
typedef struct {
    u8 pad0[128];
    E_5F09E0 e[52];
} T_5F09E0;
extern T_5F09E0 D_L39_001FE020;
s32 func_L39_005F30E0(s32 a0) {
    s32 n = a0 == 0 ? 42 : 52;
    s32 i;
    for (i = 0; i < n; i++) {
        if (D_L39_001FE020.e[i].b == 0) {
            break;
        }
    }
    return i == n ? -1 : i;
}
/* localdecomp:end func_L39_005F30E0 */

INCLUDE_ASM("asm/levels", func_L39_005F3138);

/* localdecomp:start func_L39_005F33E0 */
extern s32 func_L39_005F3138(void *, s32, void *, s32, s32);

s32 func_L39_005F33E0(s32 index, s32 a1, u8 *a2) {
    s32 v0;
    s32 v1;
    s32 r;
    u8 *p;

    if (a2 == 0) {
        return -1;
    }
    v0 = *(s32 *)(a2 + 0x24);
    if (v0 == 0) {
        return -1;
    }
    v1 = *(s32 *)(v0 + 0x28);
    if (v1 == 0) {
        return -1;
    }
    v0 = *(u8 *)(v0 + 0xD);
    if (index >= v0) {
        return -1;
    }
    r = func_L39_005F3138((u8 *)(v1 + index * 32), a1, a2, 0, 1024);
    if (r >= 0) {
        p = (u8 *)&D_L39_001FE020 + r * 128;
        *(s32 *)(p + 0xDC) = (s32)a2;
        *(s16 *)(p + 0xCA) = (s16)index;
        *(s32 *)(p + 0x108) = -1;
    }
    return r;
}
/* localdecomp:end func_L39_005F33E0 */

INCLUDE_ASM("asm/levels", func_L39_005F3488);

INCLUDE_ASM("asm/levels", func_L39_005F3548);

INCLUDE_ASM("asm/levels", func_L39_005F35D8);

INCLUDE_ASM("asm/levels", func_L39_005F3668);

INCLUDE_ASM("asm/levels", func_L39_005F3718);
