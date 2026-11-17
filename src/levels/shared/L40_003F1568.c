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

/* declared by functions of L40_003EFDE0.c, which this file was cut from */
extern void func_L40_003F0B90(Moby *, s32);

/* localdecomp:start func_L40_003F1568 */
extern u8 D_L40_00242930[];
extern void func_L40_003F19F8(Moby *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L39_005F2FF8(void *, s32);

void func_L40_003F1568(Moby *self) {
    u8 *v = self->pVar;
    Vec4 tmp;

    if (*(s32 *)(v + 0x264) == 0x539) {
        func_L40_003F19F8(self);
    }
    func_L40_003F0B90(self, *(s32 *)(v + 0x304));
    func_L01_00451FE0(self, 0x3F, D_L40_00242930, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_L39_005F3488(0xB, 0, self, 0x109D);
    func_003C2F58(self, 0, &tmp);
    *(s32 *)((u8 *)self + 0x98) = 0;
    *(u16 *)((u8 *)self + 0x34) = (*(u16 *)((u8 *)self + 0x34) | 0x41) & 0xEFFF;
    func_L39_005F2FF8(self, 1);
}
/* localdecomp:end func_L40_003F1568 */

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

/* localdecomp:start func_L40_003F16A8 */
extern u8 *func_L39_0066B870(s32 a0);
extern u8 *func_L39_0066B8A8(u8 *a0, s32 *a1);
extern f32 func_0038CE68(void *, void *);

void func_L40_003F16A8(u8 *a0) {
    s32 i;
    u8 *it;
    u8 *v;
    u8 *e;
    u8 *pv = *(u8 **)(a0 + 104);
    f32 zero = 0.0f;

    it = func_L39_0066B870(*(s32 *)(pv + 684));
    for (i = 0; (v = func_L39_0066B8A8(it, &i)) != 0 && (e = *(u8 **)(v + 28)) != 0; i++) {
        if (e != a0) {
            if (zero < func_0038CE68(pv + 272, *(u8 **)(e + 104) + 272)) {
                *(s32 *)(e + 152) = 0;
            }
        }
    }
}
/* localdecomp:end func_L40_003F16A8 */

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

/* localdecomp:start func_L40_003F17E0 */
void func_L40_003F17E0(Moby *self) {
    Vars *v = self->pVar;
    s32 n = 1;
    s32 i;

    *(s32 *)((u8 *)v + 0x330) = 0;
    for (i = 0; i < v->count; i++) {
        Moby *m = v->items[i];
        u8 st = m->field_20;
        if (st == 0xFD || st == 0xFE || st == 0x25) {
            continue;
        }
        if (m->pVar != v) {
            *(s32 *)((u8 *)m->pVar + 0x330) = n++;
        }
    }
}
/* localdecomp:end func_L40_003F17E0 */

/* localdecomp:start func_L40_003F1858 */
void func_L40_003F1858(Moby *self) {
    Vars *v = self->pVar;
    s32 i;
    s32 k;

    for (i = 0; i < v->count; i++) {
        u8 st = v->items[i]->field_20;
        if (st == 0xFD || st == 0xFE || st == 0x25) {
            for (k = i + 1; k < v->count; k++) {
                v->items[k - 1] = v->items[k];
            }
            v->count--;
        }
    }
}
/* localdecomp:end func_L40_003F1858 */

/* localdecomp:start func_L40_003F1908 */
extern s32 func_L01_003FB640(void *a0, s32 a1, u8 *a2, f32 f12);
s32 func_L40_003F1908(u8 *a0, u128_3F1460 *a1) {
    u128_3F1460 tmp = *a1;
    u8 *p = *(u8 **)(a0 + 104);
    ((f32 *)&tmp)[2] += *(f32 *)(p + 116) + *(f32 *)(p + 112);
    return func_L01_003FB640(&tmp, 16, a0, *(f32 *)(p + 112)) == 0;
}
/* localdecomp:end func_L40_003F1908 */
