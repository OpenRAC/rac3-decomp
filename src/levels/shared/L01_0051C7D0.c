#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;

/* localdecomp:start func_L01_0051C7D0 */

extern u8 D_L01_001E2457;
extern void *func_L01_00519D18(HT_8 *, u32);
s32 func_L01_0051C7D0(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519D18(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E2457) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051C7D0 */

/* localdecomp:start func_L01_0051C8A0 */
extern s32 func_L01_0051C8A0(u8 *p, s32 a, s32 b);
extern void func_003EDAD0(void *, s32, s32);
extern s32 D_L01_001DC240_0051C8A0;

s32 func_L01_0051C8A0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC240_0051C8A0)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C8A0 */

/* localdecomp:start func_L01_0051C908 */
extern s32 func_L01_0051C908(u8 *p, s32 a, u8 *out);
extern s32 func_003EDAF8();
extern s32 D_L01_001DC240_0051C908;

s32 func_L01_0051C908(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC240_0051C908)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C908 */

/* localdecomp:start func_L01_0051C970 */
extern s32 func_L01_0051C970(u8 *p, s32 a, s32 b);
extern void func_003EDB08();
extern s32 D_L01_001DC240_0051C970;

s32 func_L01_0051C970(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC240_0051C970)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C970 */

/* localdecomp:start func_L01_0051C9D8 */
extern s32 func_L01_0051C9D8(u8 *p, s32 a, s32 b);
extern void func_003EDB40();
extern s32 D_L01_001DC240_0051C9D8;

s32 func_L01_0051C9D8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC240_0051C9D8)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C9D8 */

INCLUDE_ASM("asm/levels", func_L01_0051CA40);
