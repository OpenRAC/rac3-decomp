#include "common.h"

typedef struct { u32 key; void *val; } HE_8;
typedef struct { s32 f0; s32 n; HE_8 e[8]; } HT_8;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;
typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;

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

INCLUDE_ASM("asm/levels", func_L01_0051B148);

INCLUDE_ASM("asm/levels", func_L01_0051B1A0);

INCLUDE_ASM("asm/levels", func_L01_0051B208);

INCLUDE_ASM("asm/levels", func_L01_0051B270);

INCLUDE_ASM("asm/levels", func_L01_0051B2D8);

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

INCLUDE_ASM("asm/levels", func_L01_0051B3A8);

/* localdecomp:start func_L01_0051B480 */
extern s32 func_L01_0051B480(u8 *p, f32 a, f32 b);
extern s32 D_L01_001DC210_0051B480[];
extern void func_003F0AC0(u8 *, s32, f32, f32);

s32 func_L01_0051B480(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B480[0])) {
        func_003F0AC0(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B480 */

/* localdecomp:start func_L01_0051B4F0 */
extern s32 func_L01_0051B4F0(void *, s32, void *);

extern s32 D_L01_001E244B_0051B4F0;
extern s32 func_L01_00519700_0051B4F0();
s32 func_L01_0051B4F0(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_L01_00519700_0051B4F0() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)&D_L01_001E244B_0051B4F0) {
                    p->e[idx].val = (s32)v;
                    p->e[idx].key = k;
                    p->n++;
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051B4F0 */

/* localdecomp:start func_L01_0051B5C8 */
extern s32 func_L01_0051B5C8(u8 *p, f32 a);
extern s32 D_L01_001DC210_0051B5C8[];

extern void func_003F0A30(void *, f32);
s32 func_L01_0051B5C8(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B5C8[0])) {
        func_003F0A30(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B5C8 */

/* localdecomp:start func_L01_0051B628 */
extern s32 func_L01_0051B628(void *, s32, void *);

extern s32 D_L01_001E244C;
extern s32 func_L01_00519788();
s32 func_L01_0051B628(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_L01_00519788() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)&D_L01_001E244C) {
                    p->e[idx].val = (s32)v;
                    p->e[idx].key = k;
                    p->n++;
                    return 1;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051B628 */

/* localdecomp:start func_L01_0051B700 */
extern s32 func_L01_0051B700(u8 *p, f32 a);
extern s32 D_L01_001DC210_0051B700[];

extern void func_003F0A70(void *, f32);
s32 func_L01_0051B700(u8 *p, f32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B700[0])) {
        func_003F0A70(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B700 */

/* localdecomp:start func_L01_0051B760 */
extern s32 func_L01_0051B760(u8 *p, f32 a, f32 b);
extern s32 D_L01_001DC210_0051B760[];
extern void func_003F0AC0(u8 *, s32, f32, f32);

s32 func_L01_0051B760(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051B760[0])) {
        func_003F0AC0(p, 1, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B760 */

INCLUDE_ASM("asm/levels", func_L01_0051B7D0);

/* localdecomp:start func_L01_0051B828 */

extern u8 D_L01_001E2459;
extern void *func_L01_00519E18(HT_8 *, u32);
s32 func_L01_0051B828(HT_8 *t, u32 key, void *val) {
    s32 i;
    if (t->n >= 8 || func_L01_00519E18(t, key) != 0) return 0;
    for (i = 0; i < 8; i++) {
        s32 h = ((key & 7) + ((key % 7) * i + i)) & 7;
        void *v = t->e[h].val;
        if (v == 0 || v == &D_L01_001E2459) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0051B828 */

INCLUDE_ASM("asm/levels", func_L01_0051B8F8);

INCLUDE_ASM("asm/levels", func_L01_0051B960);

/* localdecomp:start func_L01_0051B9B8 */
extern s32 func_L01_0051B9B8(u8 *p, f32 a, f32 b);

extern s32 D_L01_001DC1B0_0051B9B8[];
s32 func_L01_0051B9B8(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051B9B8[0])) {
        *(f32 *)(p + 0x10) = a;
        *(f32 *)(p + 0x14) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051B9B8 */

INCLUDE_ASM("asm/levels", func_L01_0051BA20);

/* localdecomp:start func_L01_0051BA88 */
extern s32 func_L01_0051BA88(u8 *p, f32 a, f32 b);
extern s32 D_L01_001DC1B0_0051BA88[];

s32 func_L01_0051BA88(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC1B0_0051BA88[0])) {
        *(f32 *)(p + 0x18) = a;
        *(f32 *)(p + 0x1C) = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051BA88 */
