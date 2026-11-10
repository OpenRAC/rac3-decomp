#include "common.h"

/* localdecomp:start func_L39_004CBF70 */
extern s32 func_L39_004E0ED0(s32 *);

s32 func_L39_004CBF70(s32 *arg0) {
    if (arg0 != 0) {
        if ((*arg0 != 0x74) || (func_L39_004C4F30(2) != 0)) {
            return func_L39_004E0ED0(arg0);
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004CBF70 */

/* localdecomp:start func_L39_004CBFC8 */
extern s32 func_L39_004E0F28(s32, s32);

s32 func_L39_004CBFC8(s32 arg0, s32 arg1) {
    if (func_L39_004C4F30(2) != 0) {
        return func_L39_004E0F28(arg0, arg1);
    }
    return 0;
}
/* localdecomp:end func_L39_004CBFC8 */

INCLUDE_ASM("asm/levels", func_L39_004CC018);

INCLUDE_ASM("asm/levels", func_L39_004CC088);

INCLUDE_ASM("asm/levels", func_L39_004CC0B0);

INCLUDE_ASM("asm/levels", func_L39_004CC178);

INCLUDE_ASM("asm/levels", func_L39_004CC190);

INCLUDE_ASM("asm/levels", func_L39_004CC228);

/* localdecomp:start func_L39_004CC2C8 */
typedef s32 (*Cmp_004CC2C8)(const void *, const void *);

typedef struct S_004CC2C8 {
    s32 count;
    s32 *items;
    s32 sorted;
    u8 padC[4];
    Cmp_004CC2C8 cmp;
} S_004CC2C8;

extern void func_0011E788(void *, s32, s32, Cmp_004CC2C8);
extern void *func_00118FF0(const void *, const void *, s32, s32, Cmp_004CC2C8);

s32 func_L39_004CC2C8(S_004CC2C8 *t, s32 key) {
    s32 i;
    s32 *r;
    Cmp_004CC2C8 c = t->cmp;

    if (c == 0) {
        for (i = 0; i < t->count; i++) {
            if (t->items[i] == key) {
                return i;
            }
        }
        return -1;
    }
    if (t->sorted == 0) {
        func_0011E788(t->items, t->count, 4, c);
        t->sorted = 1;
    }
    if (key == 0) {
        return -1;
    }
    r = func_00118FF0(&key, t->items, t->count, 4, c);
    if (r == 0) {
        return -1;
    }
    for (i = r - t->items; i > 0; i--) {
        if (t->cmp(&t->items[i - 1], &key) < 0) {
            break;
        }
    }
    return i;
}
/* localdecomp:end func_L39_004CC2C8 */

INCLUDE_ASM("asm/levels", func_L39_004CC3E0);
