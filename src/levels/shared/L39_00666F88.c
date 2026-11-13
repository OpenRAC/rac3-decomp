#include "common.h"

typedef struct { u8 pad[0x2D8]; s32 x2D8; s32 x2DC; u8 pad2E0[0x2F8 - 0x2E0]; s32 x2F8; } X_006683F8;
typedef struct { u8 pad[0x2528]; X_006683F8 *x2528; u8 pad2[0x254C - 0x252C]; s32 x254C; } P_006683F8;

/* localdecomp:start func_L39_00666F88 */
extern s32 D_L39_002461F8;
extern char D_L39_00337700[];
char *func_L39_00666F88(s32 a0) {
    char *r = 0;
    if (a0 < D_L39_002461F8) r = D_L39_00337700 + a0 * 832;
    return r;
}
/* localdecomp:end func_L39_00666F88 */

INCLUDE_ASM("asm/levels", func_L39_00666FB8);

INCLUDE_ASM("asm/levels", func_L39_006670C0);

/* localdecomp:start func_L39_00667208 */
typedef struct { u8 pad[0x50]; s32 x50; } R_664930;
typedef struct { u8 pad[0x324]; s32 x324; u8 pad328[8]; s32 x330; } O_664930;
extern s32 func_L39_00662678(O_664930 *, s32, s32);
extern R_664930 *func_L39_006625A8(O_664930 *, s32, s32, s32);
extern void func_L39_00662AA0(R_664930 *, void *, s32);
void func_L39_00667208(O_664930 *a0, s32 a1, u16 a2, s32 a3) {
    s32 buf[4];
    R_664930 *r;
    if (a2 == 6 || a2 == 14) {
        if (a0->x324 != 0) {
            return;
        }
        a0->x324 = 1;
    }
    if (func_L39_00662678(a0, a2, 0) != 0) {
        return;
    }
    r = func_L39_006625A8(a0, a2, 0, -1);
    buf[0] = a1;
    func_L39_00662AA0(r, buf, 4);
    r->x50 = a3;
    a0->x330 = 0;
}
/* localdecomp:end func_L39_00667208 */

/* localdecomp:start func_L39_006672C0 */
struct Sub2D0_006672C0 {
    u8 padB8[0xB8];
    void *wB8;
    u8 padBC[2];
    u8 bBE;
};
struct Pl_006672C0;
struct Vt_006672C0 {
    u8 pad0[0x34];
    void (*fn34)(void *, s32, s32, s32, s32);
};
typedef struct Pl_006672C0 {
    u8 pad0[0x14];
    struct Vt_006672C0 *vt;
    u8 pad18[0x1A0A - 0x18];
    u8 b1A0A;
    u8 pad1A0B[0x2524 - 0x1A0B];
    struct { u8 pad98[0x98]; s32 w98; } *p2524;
    void *p2528;
    s32 s252C;
    u8 pad2530[0x2534 - 0x2530];
    void *p2534;
    u8 pad2538[0x2548 - 0x2538];
    s32 s2548;
    s32 s254C;
} Pl_006672C0;
typedef struct {
    u8 pad0[0x2D0];
    struct Sub2D0_006672C0 *p2D0;
    u8 pad2D4[0x2DC - 0x2D4];
    void *p2DC;
    u8 pad2E0[0x2F8 - 0x2E0];
    u32 w2F8;
} Self_006672C0;
extern s32 func_L39_0061BF68(void *);
extern void func_L01_003F2278(s32, void *);

void func_L39_006672C0(Self_006672C0 *a, Pl_006672C0 *b) {
    s32 r = func_L39_0061BF68(b);
    if (r >= 0) {
        func_L01_003F2278(0, b->p2534);
    }
    a->p2DC = b;
    b->s254C = 6;
    b->p2528 = a;
    b->s252C = 0;
    b->vt->fn34(b, 0x31, 1, 0, 1);
    a->p2D0->wB8 = b->p2524;
    a->w2F8 &= 0xFFFFFBFF;
    if (b->s2548 == 0) {
        a->p2D0->bBE |= 0x10;
        a->p2D0->bBE &= 0xF7;
    } else if (b->s2548 == 1) {
        a->p2D0->bBE |= 8;
        a->p2D0->bBE &= 0xEF;
    }
    b->p2524->w98 = 0;
    if (r >= 0 || (a->w2F8 & 0x4000000) == 0) {
        b->b1A0A = 1;
    }
}
/* localdecomp:end func_L39_006672C0 */

INCLUDE_ASM("asm/levels", func_L39_006673E8);

INCLUDE_ASM("asm/levels", func_L39_00667540);

INCLUDE_ASM("asm/levels", func_L39_00667700);

INCLUDE_ASM("asm/levels", func_L39_00667908);

INCLUDE_ASM("asm/levels", func_L39_006679A0);

INCLUDE_ASM("asm/levels", func_L39_00667B68);

/* localdecomp:start func_L39_006683F8 */
extern s32 D_001A5CD8[];

void func_L39_006683F8(P_006683F8 *p, s32 a1) {
    X_006683F8 *x;
    s32 v;

    a1 = a1 + 1;
    if (a1 >= 8) a1 = 0;
    x = p->x2528;
    if (x == 0) return;
    v = p->x254C;
    if (v == 5 || v == 3) {
        x->x2D8 = 0;
        if (D_001A5CD8[0] == a1) {
            p->x2528->x2F8 |= 4;
            p->x2528->x2F8 |= 2;
            p->x2528->x2F8 &= 0xFFFFFFDF;
        }
    } else if (v == 6 || v == 4) {
        x->x2DC = 0;
    }
    p->x2528 = 0;
    p->x254C = 0;
}
/* localdecomp:end func_L39_006683F8 */

INCLUDE_ASM("asm/levels", func_L39_006684A0);

/* localdecomp:start func_L39_006685D8 */
extern char D_L39_00337700[];
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D00;
extern s32 D_L39_002461F8;
E_665D00 *func_L39_006685D8(s32 a0) {
    s32 i;
    for (i = 0; i < D_L39_002461F8; i++) {
        if (((E_665D00 *)&D_L39_00337700)[i].id == a0) return &((E_665D00 *)&D_L39_00337700)[i];
    }
    return 0;
}
/* localdecomp:end func_L39_006685D8 */
