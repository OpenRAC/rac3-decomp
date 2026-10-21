#include "common.h"

typedef struct { s32 key; s32 val; } E;
typedef struct { s32 pad; s32 n; E e[3]; } T;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_E;

typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3E6108;

/* localdecomp:start func_L01_0051AD70 */
extern s32 func_L01_0051AD70(void *, s32, void *);

extern s32 D_L01_001E2455;
extern s32 func_L01_00519C10();
s32 func_L01_0051AD70(void *pp, s32 k, void *v) {
    T *p = pp;
    if (p->n < 3) {
        if (func_L01_00519C10() == 0) {
            s32 i;
            for (i = 0; i < 3; i++) {
                s32 t = (u32)k % 3; s32 b = k & 1;
                s32 idx = (u32)(t + i * (b + 1)) % 3;
                if (p->e[idx].val == 0 || p->e[idx].val == (s32)&D_L01_001E2455) {
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
/* localdecomp:end func_L01_0051AD70 */

/* localdecomp:start func_L01_0051AE48 */
extern s32 func_L01_0051AE48(u8 *p, f32 a, f32 b);

extern s32 D_L01_001DC210_0051AE48[];
extern void func_003EDB68(void *, f32, f32);
s32 func_L01_0051AE48(u8 *p, f32 a, f32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210_0051AE48[0])) {
        func_003EDB68(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051AE48 */

/* localdecomp:start func_L01_0051AEB8 */
extern s32 func_L01_0051AEB8(u8 *p, s32 a, s32 b);
extern void func_003EDB78_0051AEB8();
extern s32 D_L01_001DC210;

s32 func_L01_0051AEB8(u8 *p, s32 a, s32 b) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210)) {
        func_003EDB78_0051AEB8(p, a, b);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051AEB8 */

/* localdecomp:start func_L01_0051AF20 */
extern s32 func_L01_0051AF20(u8 *p, s32 a);
extern s32 D_L01_001DC210;

extern void func_003F09C8(void *, s32);
s32 func_L01_0051AF20(u8 *p, s32 a) {
    if ((*(VT_E **)(p + 8))->isA(p, D_L01_001DC210)) {
        func_003F09C8(p, a);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_0051AF20 */
