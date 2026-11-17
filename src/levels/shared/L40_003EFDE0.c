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

/* localdecomp:start func_L40_003F0B28 */
typedef struct {
    s32 count;
    s32 id;
    s32 pad8[2];
    s32 items[8];
} S_003F0B28;

extern u8 *D_L40_00249450[];

void func_L40_003F0B28(s32 a0, s32 id) {
    s32 i;
    for (i = 0; i < 8; i++) {
        u8 *m = D_L40_00249450[i];
        if (m != 0) {
            S_003F0B28 *v = *(S_003F0B28 **)(m + 104);
            if (v->id == id) {
                if (v->count < 8) {
                    v->items[v->count] = a0;
                    v->count++;
                }
                return;
            }
        }
    }
}
/* localdecomp:end func_L40_003F0B28 */

/* localdecomp:start func_L40_003F0B90 */
extern u8 *D_L40_00249450[];
extern void func_L40_003EDAB8(Moby *);

void func_L40_003F0B90(Moby *m, s32 id) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        u8 *p = D_L40_00249450[i];
        if (p != 0) {
            s32 *s = *(s32 **)(p + 0x68);
            if (s[1] == id) {
                for (j = 0; j < s[0]; j++) {
                    Moby **list = (Moby **)(s + 4);
                    if (list[j] == m) {
                        s32 k;
                        for (k = j + 1; k < s[0]; k++) {
                            list[k - 1] = list[k];
                        }
                        s[0]--;
                        func_L40_003EDAB8(m);
                        return;
                    }
                }
            }
        }
    }
    func_L40_003EDAB8(m);
}
/* localdecomp:end func_L40_003F0B90 */

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

/* localdecomp:start func_L40_003F0D10 */
void func_L40_003F0D10(char *a0, int a1)
{
    char *s = *(char **)(a0 + 0x68);
    int i;
    for (i = 0; i < *(int *)(s + 0x2FC); i++) {
        char *e = *(char **)(*(char **)(s + 0x310 + i * 4) + 0x68);
        *(int *)(e + 0x26C) = a1;
        *(char *)(e + 0x33E) = 1;
    }
}
/* localdecomp:end func_L40_003F0D10 */

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
