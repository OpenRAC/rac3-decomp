#include "common.h"

/* declared by functions of L40_00426B60.c, which this file was cut from */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_426250;
typedef struct {
    u8 pad0[720];
    f32 *pos;
} Q426250;
typedef struct {
    u8 pad0[9508];
    f32 *pos;
    Q426250 *q;
    u8 pad252C[9544 - 9516];
    s32 team;
} P426250;
typedef struct {
    u8 pad0[16];
    s32 f10;
} V426250;
typedef struct {
    u8 pad0[36];
    V426250 *v;
    u8 pad28[152 - 40];
    s32 f98;
} A426250;
typedef struct {
    u8 pad0[596];
    f32 range;
    u8 pad258[636 - 600];
    s32 team;
} B426250;
extern s32 func_L39_006481F8(P426250 *p);
extern f32 func_L01_0040E548(void *a, void *b);
extern s32 func_L40_00424BA0(void *a, void *b, f32 *c);

/* localdecomp:start func_L40_00426CC0 */
typedef union Buf_00426CC0 {
    u8 b[8];
    u32 w[2];
} Buf_00426CC0;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_00426CC0;

extern u8 D_L40_003BFE20[];
extern void func_L39_005FF198(u8 *, u8 *, f32 *);
extern void func_003C2F58(void *, s32, void *);
extern u32 func_L39_0061D780(void *);
extern u8 *func_L39_0061D7B0(void *);
extern u8 *func_L39_00668620(void *);

u32 func_L40_00426CC0(A426250 *a, s32 a1) {
    B426250 *pv = *(B426250 **)((u8 *)a + 0x68);
    u32 s20 = *(u32 *)((u8 *)pv + 0x220);
    s32 team = pv->team;
    Vec4_00426CC0 v0;
    Vec4_00426CC0 v1;
    f32 *t;
    Vec4_00426CC0 *pos;
    u32 id;
    u8 *r;

    func_L39_005FF198(0, (u8 *)a + 0x10, &v0.x);
    func_003C2F58(a, 3, &v1);
    pos = &v1;
    if (a1 == 0 && s20 != 0xFFFFFFFF) {
        return 0xFFFFFFFF;
    }
    a->f98 = 0;
    t = func_L40_00426B60(a, pv, pos);
    a->f98 = a->v->f10;
    if (t == 0) {
        return 0xFFFFFFFF;
    }
    id = func_L39_0061D780(t);
    r = func_L39_0061D7B0(t);
    if (r == 0) {
        return 0xFFFFFFFF;
    }
    switch (r[3] & 0xF) {
    case 0: {
        u32 v;

        if (id == 0xFFFFFFFF) {
            return 0xFFFFFFFF;
        }
        if (*(s32 *)(r + 0x2548) == team) {
            return 0xFFFFFFFF;
        }
        {
            u8 *q = r + 0x19E6;
            if (*q == 0) {
                v = 0;
            } else {
                Buf_00426CC0 buf;
                u32 x;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
                }
                x = buf.w[0] ^ (u32)q;
                buf.w[0] = x;
                buf.w[1] ^= x;
                v = buf.w[1];
            }
        }
        if ((v ^ 0x14) == 0) {
            return 0xFFFFFFFF;
        }
        {
            u8 *q = r + 0x19E4;
            if (*q == 0) {
                v = 0;
            } else {
                Buf_00426CC0 buf;
                u32 x;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
                }
                x = buf.w[0] ^ (u32)q;
                buf.w[0] = x;
                buf.w[1] ^= x;
                v = buf.w[1];
            }
        }
        if ((v ^ 0x31) == 0) {
            return 0xFFFFFFFF;
        }
        return *(s32 *)r;
    }
    case 3: {
        u8 *o = func_L39_00668620(t);

        if ((*(u8 **)(o + 0x2D0))[0xBC] == 7 || (*(u8 **)(o + 0x2D0))[0xBC] == 10) {
            return 0xFFFFFFFF;
        }
        if (*(u8 **)(o + 0x2D8) != 0 || *(u8 **)(o + 0x2DC) != 0) {
            if (*(u8 **)(o + 0x2D8) != 0 && *(s32 *)(*(u8 **)(o + 0x2D8) + 0x2548) == team) {
                return 0xFFFFFFFF;
            }
            if (*(u8 **)(o + 0x2DC) != 0 && *(s32 *)(*(u8 **)(o + 0x2DC) + 0x2548) == team) {
                return 0xFFFFFFFF;
            }
            return *(s32 *)o;
        }
        break;
    }
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    }
    return 0xFFFFFFFF;
}
/* localdecomp:end func_L40_00426CC0 */

INCLUDE_ASM("asm/levels", func_L40_00426F68);
