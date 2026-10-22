#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4;
typedef struct Moby Moby;
typedef struct {
    u8 pad0[0x29C];
    s32 field_29C;
    u8 pad2A0[0x5C];
    s32 count;
    s32 field_300;
    s32 field_304;
    u8 pad308[8];
    Moby *items[1];
} Vars;
typedef struct {
    u8 pad0[0x354];
    s32 field_354;
    u8 pad358[8];
    Vec4 pos;
} VarsB;
struct Moby {
    u8 pad0[0x10];
    Vec4 pos;
    u8 field_20;
    u8 pad21[0x47];
    void *pVar;
};
typedef int u128_3F1460 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_003F1538;

INCLUDE_ASM("asm/levels", func_L40_003EFDE0);

INCLUDE_ASM("asm/levels", func_L40_003F0B28);

INCLUDE_ASM("asm/levels", func_L40_003F0B90);

/* localdecomp:start func_L40_003F0C68 */
extern u8 *D_L40_00249450[];
s32 func_L40_003F0C68(s32 id) {
    s32 i;
    for (i = 0; i < 8; i++) {
        u8 *m = D_L40_00249450[i];
        if (m != 0) {
            s32 *v = *(s32 **)(m + 104);
            if (v[1] == id) {
                return v[0];
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L40_003F0C68 */

/* localdecomp:start func_L40_003F0CB0 */
extern u8 *D_L40_00249450[];
extern s32 func_L40_004167D0(u8 *a0);
s32 func_L40_003F0CB0(s32 a0) {
    s32 i;
    for (i = 0; i < 8; i++) {
        u8 *p = D_L40_00249450[i];
        if (p != 0 && *(s32 *)(*(u8 **)(p + 104) + 4) == a0) {
            return func_L40_004167D0(p);
        }
    }
    return 0;
}
/* localdecomp:end func_L40_003F0CB0 */

INCLUDE_ASM("asm/levels", func_L40_003F0D10);

/* localdecomp:start func_L40_003F0D58 */





extern s32 func_L39_0061BFB0(s32);
extern void func_L40_003F0B90(Moby *, s32);

void func_L40_003F0D58(Moby *self) {
    Vars *v = self->pVar;
    s32 i;

    func_L39_0061BFB0(v->field_304);
    for (i = 0; i < v->count; i++) {
        Vars *w = v->items[i]->pVar;
        func_L40_003F0B90(v->items[i], w->field_304);
        ((u8 *)w)[829] = 1;
        w->field_304 = 0;
        w->field_29C = 0;
        w->field_300 = 1;
        ((u8 *)w)[828] = 0;
        v->items[i]->field_20 = 1;
        ((VarsB *)w)->pos = v->items[i]->pos;
        ((VarsB *)w)->field_354 = 0;
    }
}
/* localdecomp:end func_L40_003F0D58 */

INCLUDE_ASM("asm/levels", func_L40_003F0E18);

INCLUDE_ASM("asm/levels", func_L40_003F11C8);

INCLUDE_ASM("asm/levels", func_L40_003F12A0);

INCLUDE_ASM("asm/levels", func_L40_003F1388);

INCLUDE_ASM("asm/levels", func_L40_003F1568);

/* localdecomp:start func_L40_003F1660 */
extern void func_003C3A10(u8 *, s32);

void func_L40_003F1660(u8 *obj, s32 v) {
    if (obj[67] != v) {
        func_003C3A10(obj, v);
    }
}
/* localdecomp:end func_L40_003F1660 */

/* localdecomp:start func_L40_003F1688 */
void func_L40_003F1688(void *arg0) {
    u16 temp_v1;

    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L40_003F1688 */

INCLUDE_ASM("asm/levels", func_L40_003F16A8);

/* localdecomp:start func_L40_003F1758 */
extern u8 *func_L39_0066B870(s32 a0);
extern u8 *func_L39_0066B8A8(u8 *a0, s32 *a1);
void func_L40_003F1758(u8 *a0) {
    s32 i;
    u8 *it;
    u8 *v;
    u8 *e;
    it = func_L39_0066B870(*(s32 *)(*(u8 **)(a0 + 104) + 684));
    for (i = 0; (v = func_L39_0066B8A8(it, &i)) != 0 && (e = *(u8 **)(v + 28)) != 0; i++) {
        if (e != a0) {
            *(s32 *)(e + 152) = *(s32 *)(*(u8 **)(e + 36) + 16);
        }
    }
}
/* localdecomp:end func_L40_003F1758 */

INCLUDE_ASM("asm/levels", func_L40_003F17E0);

INCLUDE_ASM("asm/levels", func_L40_003F1858);

/* localdecomp:start func_L40_003F1908 */
extern s32 func_L01_003FB640(void *a0, s32 a1, u8 *a2, f32 f12);
s32 func_L40_003F1908(u8 *a0, u128_3F1460 *a1) {
    u128_3F1460 tmp = *a1;
    u8 *p = *(u8 **)(a0 + 104);
    ((f32 *)&tmp)[2] += *(f32 *)(p + 116) + *(f32 *)(p + 112);
    return func_L01_003FB640(&tmp, 16, a0, *(f32 *)(p + 112)) == 0;
}
/* localdecomp:end func_L40_003F1908 */

INCLUDE_ASM("asm/levels", func_L40_003F1958);

/* localdecomp:start func_L40_003F19E0 */
void func_L40_003F19E0(Vec4_003F1538 *a) {
    Vec4_003F1538 v = *a;
}
/* localdecomp:end func_L40_003F19E0 */

INCLUDE_ASM("asm/levels", func_L40_003F19F8);

INCLUDE_ASM("asm/levels", func_L40_003F1AD0);

INCLUDE_ASM("asm/levels", func_L40_003F1E48);

INCLUDE_ASM("asm/levels", func_L40_003F1FA0);

/* localdecomp:start func_L40_003F2158 */
float func_L40_003F2158(int n, float a, float b)
{
    return (float)n * a + (float)((n - 1) * n) * b * 0.5f;
}
/* localdecomp:end func_L40_003F2158 */

/* localdecomp:start func_L40_003F2198 */
f32 func_L40_003F2198(s32 arg0, f32 fparg0) {
    return -fparg0 / (f32) (arg0 - 1);
}
/* localdecomp:end func_L40_003F2198 */

INCLUDE_ASM("asm/levels", func_L40_003F21B8);
