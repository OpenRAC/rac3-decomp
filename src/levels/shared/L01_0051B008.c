#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E_0051B1A0;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_0051B2D8;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E_0051B8F8;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_0051B960;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_0051BA20;

/* localdecomp:start func_L01_0051B008 */

extern u8 D_L01_001E2453;
extern void *func_L01_00519B10(HT_8 *, u32);
s32 func_L01_0051B008(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519B10(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E2453) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051B008 */

/* localdecomp:start func_L01_0051B0D8 */
extern s32 func_L01_0051B0D8(u8 *p, f32 a, f32 b);

extern s32 D_L01_001DC210_0051B0D8[];
extern void func_003EDB90(void *, f32, f32);
s32 func_L01_0051B0D8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B0D8[0])) {
        func_003EDB90(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B0D8 */

/* localdecomp:start func_L01_0051B148 */
extern void func_003F0980(void *, s32);
extern s32 D_L01_001DC210_0051B148;

s32 func_L01_0051B148(u8 *p, s32 k) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B148)) {
        func_003F0980(p, k);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B148 */

/* localdecomp:start func_L01_0051B1A0 */
extern s32 D_L01_001DC210_0051B1A0;
extern void func_003EDAD0(void *, s32, s32);
s32 func_L01_0051B1A0(u8 *p, s32 a, s32 b) {
    if ((*(VT_E_0051B1A0 **)(p + 8))->isA(p, D_L01_001DC210_0051B1A0)) {
        func_003EDAD0(p, a, b != 0);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B1A0 */

/* localdecomp:start func_L01_0051B208 */
extern s32 func_L01_0051B208(u8 *p, s32 a, u8 *out);
extern s32 func_003EDAF8();
extern s32 D_L01_001DC210_0051B208;

s32 func_L01_0051B208(u8 *p, s32 a, u8 *out) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B208)) {
        *out = func_003EDAF8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B208 */

/* localdecomp:start func_L01_0051B270 */
extern void func_003EDB08(void *, s32, s32);
extern s32 D_L01_001DC210;

s32 func_L01_0051B270(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210)) {
        func_003EDB08(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B270 */

/* localdecomp:start func_L01_0051B2D8 */
extern s32 func_L01_0051B2D8(u8 *p, s32 a, s32 b);
extern void func_003EDB40();
extern s32 D_L01_001DC210_0051B2D8;

s32 func_L01_0051B2D8(u8 *p, s32 a, s32 b) {
    if ((*(VT_0051B2D8 **)(p + 8))->isA(p, D_L01_001DC210_0051B2D8)) {
        func_003EDB40(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B2D8 */

/* localdecomp:start func_L01_0051B340 */
extern s32 func_L01_0051B340(u8 *p, f32 a, f32 b);
extern s32 D_L01_001DC210_0051B340[];

s32 func_L01_0051B340(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B340[0])) {
        *(f32 *)(p + 0x20) = a;
        *(f32 *)(p + 0x24) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B340 */
