#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;

/* localdecomp:start func_L01_0051CDE0 */

extern u8 D_L01_001E245A;
extern void *func_L01_00519E98(HT_8 *, u32);
s32 func_L01_0051CDE0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519E98(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E245A) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051CDE0 */

/* localdecomp:start func_L01_0051CEB0 */
extern s32 func_L01_0051CEB0(u8 *p, s32 a, s32 b);
extern void func_003EDAD0(void *, s32, s32);
extern s32 D_L01_001DC150;

s32 func_L01_0051CEB0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC150)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051CEB0 */

/* localdecomp:start func_L01_0051CF18 */
extern s32 func_L01_0051CF18(u8 *p, s32 a, u8 *out);
extern s32 func_003EDAF8();
extern s32 D_L01_001DC150;

s32 func_L01_0051CF18(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC150)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051CF18 */

/* localdecomp:start func_L01_0051CF80 */
extern s32 func_L01_0051CF80(u8 *p, s32 a, s32 b);
extern void func_003EDB08();
extern s32 D_L01_001DC150;

s32 func_L01_0051CF80(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC150)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051CF80 */

/* localdecomp:start func_L01_0051CFE8 */
extern s32 func_L01_0051CFE8(u8 *p, s32 a, s32 b);
extern void func_003EDB40();
extern s32 D_L01_001DC150;

s32 func_L01_0051CFE8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC150)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051CFE8 */

INCLUDE_ASM("asm/levels", func_L01_0051D050);

INCLUDE_ASM("asm/levels", func_L01_0051D0B8);

/* localdecomp:start func_L01_0051D128 */
extern s32 func_L01_0051D128(u8 *p, s32 a, s32 b);
extern void func_003EDB78();
extern s32 D_L01_001DC150;

s32 func_L01_0051D128(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC150)) {
        func_003EDB78(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051D128 */

INCLUDE_ASM("asm/levels", func_L01_0051D190);
