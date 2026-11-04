#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    u8 *f1C;
    u8 pad20[0x38];
    s32 f58;
    u8 pad5C[0x24];
} E_005F2FF8;

/* localdecomp:start func_L39_005F2FF8 */
extern E_005F2FF8 D_L39_001FE0E0[];
extern void func_L39_005F3088(s32);

void func_L39_005F2FF8(u8 *a0, s32 a1) {
    E_005F2FF8 *e;
    s32 i;

    if (a0 != 0) {
        e = D_L39_001FE0E0;
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

/* localdecomp:start func_L39_005F3088 */
extern u8 D_L39_001FE020_005F3088[];

void func_L39_005F3088(s32 a0) {
    u8 *p;
    s32 state;
    if ((u32)a0 < 0x34) {
        p = D_L39_001FE020_005F3088 + a0 * 0x80;
        state = p[0xD0];
        if (state == 7) {
            *(s32 *)(p + 0xDC) = 0;
            *(s32 *)(p + 0x100) = 0;
            p[0xD0] = 0;
            return;
        }
        if (state != 0 && state != 6) {
            p[0xD0] = 4;
        }
    }
}
/* localdecomp:end func_L39_005F3088 */

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

/* localdecomp:start func_L39_005F3488 */
extern u8 D_L39_00272590[];
extern char *D_L39_00271B40[];
extern s32 func_L39_005F3138(void *, s32, void *, s32, s32);

s32 func_L39_005F3488(s32 index, s32 value, char *object, s32 kind) {
    char *header = D_L39_00271B40[D_L39_00272590[kind]];
    char *entries;
    s32 result;
    u8 *row;

    if (header == 0) {
        return -1;
    }
    entries = *(char **)(header + 0x28);
    if (entries == 0) {
        return -1;
    }
    if (index >= (u8)header[0xD]) {
        return -1;
    }
    result = func_L39_005F3138(entries + index * 32, value, object, 0, 0x400);
    if (result >= 0) {
        row = (u8 *)&D_L39_001FE020 + result * 128;
        *(char **)(row + 0xDC) = object;
        *(s16 *)(row + 0xCA) = index;
        *(s32 *)(row + 0x108) = kind;
    }
    return result;
}
/* localdecomp:end func_L39_005F3488 */

INCLUDE_ASM("asm/levels", func_L39_005F3548);

INCLUDE_ASM("asm/levels", func_L39_005F35D8);

INCLUDE_ASM("asm/levels", func_L39_005F3668);

INCLUDE_ASM("asm/levels", func_L39_005F3718);
