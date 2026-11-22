/* PAL draft (2026-11-21, Promises): written from level 3's assembly. 29 words differ with its file's
 * flags (src/levels/shared/L03_003AE9A0.c): register allocation only. Retail frees the register of
 * a0->p68 for the second loop's counter and needs one saved register fewer (frame 0xD0, ours 0xE0,
 * $s7 extra). The 9-matrix array (0x41 first, bones 0x20..0x3C after) and the second loop's
 * base-pointer form are right: earlier wordings were 45-64 diff. */
#include "common.h"

/* localdecomp:start func_L03_003AEA48 */
typedef int u128_003AEA48 __attribute__((mode(TI)));

typedef struct {
    u128_003AEA48 a;
    u128_003AEA48 b;
    s32 c20;
    s32 c24;
    u8 pad28[0x88];
} E_003AEA48;

typedef struct {
    void *p0;
    u8 pad4[0x26C];
    E_003AEA48 arr[8];
    u8 x7F0[0x10];
} V_003AEA48;

typedef struct {
    u8 pad0[0x68];
    V_003AEA48 *p68;
} S_003AEA48;

extern void func_003C2F58(void *, s32, u128_003AEA48 *);
extern void func_L01_0040C7A0(void *, void *);

void func_L03_003AEA48(S_003AEA48 *a0) {
    u128_003AEA48 mats[9];
    V_003AEA48 *v = a0->p68;
    s32 i;

    for (i = 0; i < 8; i++) {
        func_003C2F58(v->p0, i * 4 + 0x20, &mats[i + 1]);
    }
    func_003C2F58(v->p0, 0x41, &mats[0]);
    for (i = 0; i < 8; i++) {
        V_003AEA48 *q = (V_003AEA48 *)((u8 *)v + i * 0xB0);
        u128_003AEA48 *mp = &mats[i];
        q->arr[0].c20 = 0x1B4E206C;
        q->arr[0].c24 = -1;
        func_L01_0040C7A0(q->arr, v->x7F0);
        q->arr[0].a = mats[0];
        q->arr[0].b = mp[1];
    }
}
/* localdecomp:end func_L03_003AEA48 */
