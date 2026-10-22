#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0043B260);

/* localdecomp:start func_L01_0043B510 */
extern u8 D_001BBC40[];
extern s32 D_001D545C;

void func_L01_0043B510(s32 arg0) {
    u8 *temp_v0;

    if (arg0 != 0xFF) {
        temp_v0 = arg0 + (D_001D545C * 0x10) + D_001BBC40;
        *temp_v0 |= 0x80;
    }
}
/* localdecomp:end func_L01_0043B510 */

/* localdecomp:start func_L01_0043B548 */
extern s32 func_L01_0043B568(s32 a0, s32 a1);
void func_L01_0043B548(void *p, s32 a) {
    ((void (*)(void *, s32, s32))func_L01_0043B568)(p, 0, a);
}
/* localdecomp:end func_L01_0043B548 */

/* localdecomp:start func_L01_0043B568 */
typedef s32 (*Fn438488)(s32, s32, void *);
extern u8 *func_L01_0045E420(s32);

s32 func_L01_0043B568(s32 a0, s32 a1) {
    s32 buf[4];
    u8 *p;
    p = func_L01_0045E420(a0);
    if (p == 0) {
        return 0;
    }
    if (*(Fn438488 *)(p + 24) == 0) {
        return 0;
    }
    return (*(Fn438488 *)(p + 24))(a0, a1, buf);
}
/* localdecomp:end func_L01_0043B568 */

/* localdecomp:start func_L01_0043B5C8 */
extern s32 D_L01_001E005C;
extern s32 D_L01_001E0058;
extern s32 D_L01_0021DE20[];
extern s32 D_L01_001E00C8;
void func_L01_0043B5C8(void) {
    s32 i;
    for (i = D_L01_001E005C; i < D_L01_001E0058; i++) {
        D_L01_0021DE20[i] = 0;
    }
    D_L01_001E00C8 = 0;
}
/* localdecomp:end func_L01_0043B5C8 */

INCLUDE_ASM("asm/levels", func_L01_0043B618);

LINKER_REMNANT("asm/levels", func_L01_0043B748);

/* localdecomp:start func_L01_0043B750 */
extern s32 D_L01_0021DE20[];
typedef struct { s16 v[24]; } Ent_00438670;
extern Ent_00438670 D_L01_0021E260[];
extern s32 D_L01_001E005C;
extern u8 *D_L01_001E001C;
s32 func_L01_0043B750(s32 idx, u8 *obj) {
    Ent_00438670 **slot;
    Ent_00438670 *e;
    Ent_00438670 *n;
    s32 i;
    slot = (Ent_00438670 **)((u8 *)((Ent_00438670 * *)&D_L01_0021DE20) + idx * 4);
    if (*slot == 0) {
        n = (Ent_00438670 *)((u8 *)D_L01_0021E260 + (idx - D_L01_001E005C) * 48);
        *slot = n;
        n->v[0] = ((obj - D_L01_001E001C) >> 8) | 0x8000;
        obj[33] = idx;
        return 1;
    }
    e = (Ent_00438670 *)((u8 *)D_L01_0021E260 + (idx - D_L01_001E005C) * 48);
    for (i = 0; i < 23; i++) {
        if (e->v[i] & 0x8000) {
            e->v[i] &= 0x7FFF;
            i++;
            *(s16 *)((u8 *)e + i * 2) = ((obj - D_L01_001E001C) >> 8) | 0x8000;
            obj[33] = idx;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0043B750 */

/* localdecomp:start func_L01_0043B840 */
extern s32 D_L01_0021DE20[];
extern Ent_00438670 D_L01_0021E260[];
typedef struct { s16 v[24]; } Ent_00438760;
extern s32 D_L01_001E005C;
extern u8 *D_L01_001E001C;
s32 func_L01_0043B840(s32 idx, u8 *obj) {
    Ent_00438760 *e;
    s32 key;
    s32 i;
    if (*(Ent_00438760 **)((u8 *)((Ent_00438760 * *)&D_L01_0021DE20) + idx * 4) == 0) {
        return 0;
    }
    e = (Ent_00438760 *)((u8 *)((Ent_00438760 *)&D_L01_0021E260) + (idx - D_L01_001E005C) * 48);
    key = (obj - D_L01_001E001C) >> 8;
    for (i = 0; i < 24; i++) {
        if ((e->v[i] & 0x7FFF) == key) {
            obj[33] = 0xFF;
            if (e->v[i] & 0x8000) {
                if (i == 0) {
                    *(Ent_00438760 **)((u8 *)((Ent_00438760 * *)&D_L01_0021DE20) + idx * 4) = 0;
                } else {
                    e->v[i - 1] |= 0x8000;
                }
            } else {
                for (; i < 23; i++) {
                    e->v[i] = e->v[i + 1];
                }
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_0043B840 */

/* localdecomp:start func_L01_0043B930 */
extern s32 D_L01_0021DE20[];

s32 func_L01_0043B930(s32 a0) {
    if (a0 == 255) {
        return 1;
    }
    return D_L01_0021DE20[a0] == 0;
}
/* localdecomp:end func_L01_0043B930 */
