#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005C2F48);

/* localdecomp:start func_L39_005C2F50 */
typedef struct {
    u8 pad0[844];
    s32 idx;
    s32 pad350;
    s32 arr[7];
} T_5C0F08;
extern T_5C0F08 D_L39_00225780;
s32 func_L39_005C2F50(T_5C0F08 *a0) {
    if (a0 != 0) {
        return a0->arr[(a0->idx + 6) % 7];
    }
    return D_L39_00225780.arr[(D_L39_00225780.idx + 6) % 7];
}
/* localdecomp:end func_L39_005C2F50 */

INCLUDE_ASM("asm/levels", func_L39_005C2FA8);

/* localdecomp:start func_L39_005C2FD0 */
extern T_5C0F08 D_L39_00225780;
typedef struct {
    u8 pad0[416];
    s32 f1A0;
    s32 f1A4;
    s32 f1A8;
    u8 pad1AC[844 - 428];
    s32 k;
    s32 n;
    s32 a[7];
} S_005C0F88;
s32 func_L39_005C2FD0(S_005C0F88 *a0) {
    S_005C0F88 *p;
    if (a0 != 0) {
        p = a0;
    } else {
        p = &(*(S_005C0F88 *)&D_L39_00225780);
    }
    if (p->n >= 2) {
        return ~p->a[(p->k + 5) % 7] & p->a[(p->k + 6) % 7];
    }
    if (p->n == 1) {
        return ~p->f1A0 & p->a[(p->k + 6) % 7];
    }
    return p->f1A4;
}
/* localdecomp:end func_L39_005C2FD0 */

/* localdecomp:start func_L39_005C3078 */
extern T_5C0F08 D_L39_00225780;
typedef struct {
    u8 pad0[416];
    s32 f1A0;
    s32 f1A4;
    s32 f1A8;
    u8 pad1AC[844 - 428];
    s32 k;
    s32 n;
    s32 a[7];
} S_005C1030;
s32 func_L39_005C3078(S_005C1030 *a0) {
    S_005C1030 *p;
    if (a0 != 0) {
        p = a0;
    } else {
        p = &(*(S_005C1030 *)&D_L39_00225780);
    }
    if (p->n >= 2) {
        return ~p->a[(p->k + 6) % 7] & p->a[(p->k + 5) % 7];
    }
    if (p->n == 1) {
        return ~p->a[(p->k + 6) % 7] & p->f1A0;
    }
    return p->f1A8;
}
/* localdecomp:end func_L39_005C3078 */
