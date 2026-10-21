#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00373438);

INCLUDE_ASM("asm/levels", func_L01_003738E0);

INCLUDE_ASM("asm/levels", func_L01_003739B8);

INCLUDE_ASM("asm/levels", func_L01_003739C0);

INCLUDE_ASM("asm/levels", func_L01_00373F78);

INCLUDE_ASM("asm/levels", func_L01_003743C8);

/* localdecomp:start func_L01_00374630 */
extern s32 func_0038CAD0(void *);
extern void func_L01_003743C8(void *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);

void func_L01_00374630(u8 *obj) {
    u8 *v = *(u8 **)(obj + 104);
    u8 *m;

    if (func_0038CAD0(v + 84) != 0) {
        return;
    }
    func_L01_003743C8(obj);
    func_L01_003743C8(obj);
    m = v + 16;
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 49, 0x3F204090, 1, 0.9f, 0.0f, func_00382538());
    func_003D9508(m, 11, 0x3F204090, 1, 0.9f, 0.08f, 0.0f);
    func_003D9508(m, 65, 0x3F909090, 1, 1.0f, 0.0f, func_003824E0(30.0f, 60.0f) * 0.017453292f);
}
/* localdecomp:end func_L01_00374630 */

LINKER_REMNANT("asm/levels", func_L01_00374770);

INCLUDE_ASM("asm/levels", func_L01_00374790);

/* localdecomp:start func_L01_00374908 */
typedef struct S_3738B0 S_3738B0;

typedef struct {
    u8 pad0[0x54];
    S_3738B0 *w54;
} S_3738B0m;

struct S_3738B0 {
    u8 pad0[0x10];
    f32 pos[4];
    u8 pad20[0x68 - 0x20];
    S_3738B0m *p68;
};

extern S_3738B0 *D_L01_001E10E0[];
extern f32 func_L01_0040E548(f32 *a0, f32 *a1);

void func_L01_00374908(S_3738B0 *a0, S_3738B0 *a1) {
    S_3738B0m *m;
    S_3738B0m *q;
    S_3738B0 **pp;
    f32 d;
    s32 i;

    if (a0 == 0 || a1 == 0) {
        return;
    }
    m = a0->p68;
    for (i = 0; i < 6; i++) {
        pp = &D_L01_001E10E0[i];
        if (*pp == 0) {
            continue;
        }
        q = (*pp)->p68;
        if (q == 0 || q->w54 != a1) {
            continue;
        }
        if (m == 0) {
            return;
        }
        d = func_L01_0040E548(a0->pos, a1->pos);
        if (d < func_L01_0040E548((*pp)->pos, a1->pos)) {
            m->w54 = a1;
            q->w54 = 0;
        }
        return;
    }
    m->w54 = a1;
}
/* localdecomp:end func_L01_00374908 */

INCLUDE_ASM("asm/levels", func_L01_003749E8);

LINKER_REMNANT("asm/levels", func_L01_00376170);

INCLUDE_ASM("asm/levels", func_L01_00376178);

INCLUDE_ASM("asm/levels", func_L01_00376490);

INCLUDE_ASM("asm/levels", func_L01_00376D08);

INCLUDE_ASM("asm/levels", func_L01_003770A8);

INCLUDE_ASM("asm/levels", func_L01_003773C0);

INCLUDE_ASM("asm/levels", func_L01_003778D0);

/* localdecomp:start func_L01_00377908 */
extern S_3738B0 *D_L01_001E10E0[];
s32 func_L01_00377908(void) {
    s32 i;
    for (i = 0; i < 6; i++) {
        if (((s32 *)&D_L01_001E10E0)[i] == 0) return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00377908 */

/* localdecomp:start func_L01_00377940 */
extern S_3738B0 *D_L01_001E10E0[];
extern s32 func_00382468(s32 a0);
s32 func_L01_00377940(void) {
    s32 i;
    u8 *e;
    i = func_00382468(4);
    e = ((u8 * *)&D_L01_001E10E0)[i];
    if (e != 0) {
        e[32] = 3;
        ((u8 * *)&D_L01_001E10E0)[i] = 0;
        return 1;
    }
    for (i = 0; i < 6; i++) {
        e = ((u8 * *)&D_L01_001E10E0)[i];
        if (e != 0) {
            e[32] = 3;
            ((u8 * *)&D_L01_001E10E0)[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00377940 */

/* localdecomp:start func_L01_003779C8 */
extern S_3738B0 *D_L01_001E10E0[];
int func_L01_003779C8(int a)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (((int *)&D_L01_001E10E0)[i] == a) {
            ((int *)&D_L01_001E10E0)[i] = 0;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003779C8 */

LINKER_REMNANT("asm/levels", func_L01_00377A08);

INCLUDE_ASM("asm/levels", func_L01_00377A10);

INCLUDE_ASM("asm/levels", func_L01_00377C38);

/* localdecomp:start func_L01_00379368 */
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L01_00379368(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (p != 0) {
        *(s32 *)(p + 20) = 0;
    }
    func_L01_004450F0(a0, 5, -1);
}
/* localdecomp:end func_L01_00379368 */

INCLUDE_ASM("asm/levels", func_L01_00379398);

INCLUDE_ASM("asm/levels", func_L01_00379B20);

INCLUDE_ASM("asm/levels", func_L01_0037A0F8);

INCLUDE_ASM("asm/levels", func_L01_0037A880);
