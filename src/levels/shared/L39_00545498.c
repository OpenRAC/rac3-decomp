#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00545498);

INCLUDE_ASM("asm/levels", func_L39_005455C8);

INCLUDE_ASM("asm/levels", func_L39_00545740);

INCLUDE_ASM("asm/levels", func_L39_00545918);

INCLUDE_ASM("asm/levels", func_L39_00545B20);

/* localdecomp:start func_L39_00546250 */
s32 func_L39_00546250(s32 a0) {
    s32 p = *(s32 *)(*(s32 *)(*(s32 *)(a0 + 104) + 900) + 728);
    s32 r = 0;
    if (p != 0) {
        r = *(u8 *)(p + 6676) != 0;
    }
    return r;
}
/* localdecomp:end func_L39_00546250 */

INCLUDE_ASM("asm/levels", func_L39_00546278);

INCLUDE_ASM("asm/levels", func_L39_00546428);

INCLUDE_ASM("asm/levels", func_L39_00546B38);

/* localdecomp:start func_L39_00546F30 */
typedef struct {
    char pad0[0x3];
    u8 flags;
} Ent;

extern Ent *func_L39_0061D7B0(s32);

void func_L39_00546F30(s32 id, f32 *a, f32 *b) {
    Ent *e = func_L39_0061D7B0(id);
    Ent *r;

    r = 0;
    if (e != 0) {
        if (e->flags & 0xF) {
            r = 0;
        } else {
            r = e;
        }
    }

    if (r != 0) {
        if (a != 0) {
            *a = 4.0f;
        }
        if (b != 0) {
            *b = 7.0f;
        }
    } else {
        if (a != 0) {
            *a = 7.0f;
        }
        if (b != 0) {
            *b = 15.0f;
        }
    }
}
/* localdecomp:end func_L39_00546F30 */

INCLUDE_ASM("asm/levels", func_L39_00546FE0);

INCLUDE_ASM("asm/levels", func_L39_00547E10);

INCLUDE_ASM("asm/levels", func_L39_00548130);

INCLUDE_ASM("asm/levels", func_L39_00548648);

/* localdecomp:start func_L39_00548DB0 */
extern void func_L39_0061C4D0(u8 *, u8 **);
extern u32 func_L39_0061D780(s32);

void func_L39_00548DB0(u8 *self, u8 *msg) {
    u8 *v;
    u8 *p;
    f32 *src;
    f32 *dst;

    if (msg[3] != 8) {
        return;
    }
    v = *(u8 **)(self + 104);
    p = *(u8 **)(v + 80);
    if (p == 0) {
        func_L39_0061C4D0(self, (u8 **)(v + 80));
        p = *(u8 **)(*(u8 **)(self + 104) + 80);
        if (p == 0) {
            return;
        }
    }
    src = (f32 *)(p + 944);
    dst = (f32 *)(msg + 24);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    if (*(s32 *)(p + 4216) != 0) {
        *(u32 *)(msg + 8) = func_L39_0061D780(*(s32 *)(p + 4216));
    } else {
        *(u32 *)(msg + 8) = 0xFFFFFFFF;
    }
}
/* localdecomp:end func_L39_00548DB0 */

INCLUDE_ASM("asm/levels", func_L39_00548E60);

INCLUDE_ASM("asm/levels", func_L39_005490D0);

INCLUDE_ASM("asm/levels", func_L39_00549510);
