#include "common.h"
#include "vu0.h"

__asm__(".extern D_001D545C, 16");

/* localdecomp:start func_L04_00379A18 */
extern s32 D_L04_001DD988[2];

s32 *func_L04_00379A18(s32 a0, s32 a1, s32 *a2) {
    if (a1 == 0) {
        *a2 = 8;
        return D_L04_001DD988;
    }
    return 0;
}
/* localdecomp:end func_L04_00379A18 */

/* localdecomp:start func_L04_00379A38 */
extern void func_L04_00379B28(u8 *, u8 *);
extern s32 func_0038DC20(void *, f32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00404A10_00379A38(void *, void *);
extern void func_L04_00379D10(u8 *);
extern void func_L04_0037A190(u8 *);
extern s32 D_001D545C;

void func_L04_00379A38(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 pos;
    f32 r;
    if (*(u16 *)(m + 0x34) & 0x80) {
        return;
    }
    switch (m[0x20]) {
    case 0:
        func_L04_00379B28(m, v);
        break;
    case 1:
        *(vu0_q *)&pos = *(vu0_q *)(m + 0x10);
        pos.w = 4.0f;
        r = 40.0f;
        if (D_001D545C == 11) {
            r = 255.0f;
        }
        if (func_0038DC20(&pos, r) != -1) {
            if (func_L01_00456250(m) != 0) {
                func_L01_00404A10_00379A38(func_L04_00379D10, m);
            } else if (*(s32 *)(v + 4) != 6) {
                func_L01_00404A10_00379A38(func_L04_0037A190, m);
            }
        }
        break;
    }
}
/* localdecomp:end func_L04_00379A38 */

/* localdecomp:start func_L04_00379B28 */
extern u8 *func_L04_003BAA98(u8 *);
extern u8 *func_L04_003BAF58(u8 *);
extern u8 *func_L04_003BB2E0(u8 *);
extern void func_L01_004AA7E8(void *, s32);

void func_L04_00379B28(u8 *m, u8 *v) {
    u8 *c;
    s32 t;
    if (D_001D545C == 11) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
    } else {
        m[0x30] = 0x28;
        *(s16 *)(m + 0x32) = 0x28;
    }
    *(s32 *)v = 0;
    m[0x20] = 1;
    c = 0;
    t = *(s32 *)(v + 4);
    if (t != -1 || *(s32 *)(v + 8) != t) {
        if (t != 0) {
            c = func_L04_003BAA98(m);
        } else if (*(s32 *)(v + 8) != 0) {
            c = func_L04_003BAF58(m);
        } else {
            c = func_L04_003BB2E0(m);
        }
    }
    if (*(s32 *)(v + 4) == 6) {
        *(s32 *)(c + 0x98) = 0;
        *(u16 *)(c + 0x34) = (*(u16 *)(c + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(c, 1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    }
    if (*(s32 *)(v + 4) == 5) {
        *(u16 *)(c + 0x34) |= 0x41;
    }
    *(u16 *)(m + 0x34) |= 0x41;
}
/* localdecomp:end func_L04_00379B28 */

/* localdecomp:start func_L04_00379C68 */
f32 func_L04_00379C68(void *arg0) {
    s32 temp_v1;
    void *temp_a0;

    temp_a0 = *(void **)((u8 *)arg0 + 0x68);
    temp_v1 = *(s32 *)((u8 *)temp_a0 + 4);
    if (((temp_v1 != -1) || ((*(s32 *)((u8 *)temp_a0 + 8)) != temp_v1)) && ((temp_v1 != 0) || ((*(s32 *)((u8 *)temp_a0 + 8)) != 0))) {
        return 0.5f;
    }
    return 0.25f;
}
/* localdecomp:end func_L04_00379C68 */

/* localdecomp:start func_L04_00379CC0 */
extern f32 func_L04_00379C68(void *arg0);
extern void func_0038CE20(void *, void *, f32);

void func_L04_00379CC0(u8 *a0, void *out) {
    f32 s = func_L04_00379C68(a0);
    func_0038CE20(out, a0 + 0xC0, s);
    vec_add_ba(out, out, a0 + 0x10);
}
/* localdecomp:end func_L04_00379CC0 */

INCLUDE_ASM("asm/levels", func_L04_00379D10);

INCLUDE_ASM("asm/levels", func_L04_0037A190);

/* localdecomp:start func_L04_0037A5B8 */
typedef struct {
    u8 pad[0x68];
    s32 *w68;
} Moby_003791A0;

extern void func_L01_00456230(Moby_003791A0 *, s32);

void func_L04_0037A5B8(Moby_003791A0 *m, s32 value, s32 force) {
    s32 *p = m->w68;
    if (p == 0) return;
    if (force == 0 && *p != value) return;
    *p = value;
    func_L01_00456230(m, force);
}
/* localdecomp:end func_L04_0037A5B8 */
