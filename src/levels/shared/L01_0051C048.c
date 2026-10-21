#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;

/* localdecomp:start func_L01_0051C048 */

extern u8 D_L01_001E244D;
extern void *func_L01_00519810(HT_8 *, u32);
s32 func_L01_0051C048(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519810(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E244D) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051C048 */

/* localdecomp:start func_L01_0051C118 */
extern s32 func_L01_0051C118(u8 *p, f32 a, f32 b);

extern s32 D_L01_001DC180_0051C118[];
s32 func_L01_0051C118(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC180_0051C118[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C118 */

INCLUDE_ASM("asm/levels", func_L01_0051C180);

/* localdecomp:start func_L01_0051C1E8 */
extern s32 func_L01_0051C1E8(u8 *p, f32 a, f32 b);
extern s32 D_L01_001DC180_0051C1E8[];

s32 func_L01_0051C1E8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC180_0051C1E8[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051C1E8 */
