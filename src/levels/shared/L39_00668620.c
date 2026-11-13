#include "common.h"

/* localdecomp:start func_L39_00668620 */
typedef struct { s32 id; u8 p4[0x2CC]; s32 w2D0; u8 p2D4[0x340 - 0x2D4]; } E_665D48;
extern s32 D_L39_002461F8;
extern E_665D48 D_L39_00337700[];
E_665D48 *func_L39_00668620(s32 a0) {
    s32 i;
    E_665D48 *p;
    for (i = 0; i < D_L39_002461F8; i++) {
        p = &D_L39_00337700[i];
        if (p->w2D0 == a0) return p;
    }
    return 0;
}
/* localdecomp:end func_L39_00668620 */

INCLUDE_ASM("asm/levels", func_L39_00668660);

/* localdecomp:start func_L39_00668BD8 */
#include "vu0.h"
typedef struct {
    u32 id; u8 p4[0x26C]; u8 q270[0x10]; u8 q280[0x10]; u8 p290[0x40]; s32 w2D0; s32 w2D4; s32 w2D8; s32 w2DC;
    u8 p2E0[0x18]; s32 w2F8; s16 h2FC; u8 p2FE[6]; s16 h304; s16 h306; f32 f308; f32 f30C; s32 w310;
    u8 p314[8]; s32 w31C; s32 w320; s32 w324; u8 p328[0x18];
} E_00668BD8;
typedef struct { s32 w0, w4, w8, wC, w10, w14, w18; } F_00668BD8;
extern F_00668BD8 D_L39_0033AB08_00668BD8[];
extern s32 D_001DAAE8_sda;
__asm__(".extern D_001DAAE8_sda, 4");

void func_L39_00668BD8(void) {
    s32 p;
    s32 f;
    D_001DAAE8_sda = 0;
    p = (s32)D_L39_00337700;
    do {
        E_00668BD8 *e = (E_00668BD8 *)p;
        e->id = -1;
        qzero(e->q270);
        e->w2D0 = 0;
        qzero(e->q280);
        e->w2D4 = 0;
        e->w2D8 = 0;
        e->w2DC = 0;
        e->w2F8 = 0;
        e->f308 = 40.0f;
        e->f30C = 40.0f;
        e->w310 = 0;
        e->h2FC = -1;
        e->h304 = -1;
        e->w31C = 0;
        e->w320 = 0;
        e->w324 = 0;
        e->h306 = 0;
        p += 0x340;
    } while (p < (s32)D_L39_00337700 + 0x3400);
    f = (s32)D_L39_0033AB08_00668BD8;
    do {
        F_00668BD8 *g = (F_00668BD8 *)f;
        g->w0 = 0; g->w4 = 0; g->w8 = 0; g->wC = 0; g->w10 = 0; g->w14 = 0; g->w18 = 0;
        f += 0x1C;
    } while (f < (s32)D_L39_0033AB08_00668BD8 + 0x8C);
}
/* localdecomp:end func_L39_00668BD8 */

/* localdecomp:start func_L39_00668C90 */
typedef struct { s32 a, b, c, d, e, f, g; } S_00668C90;
extern S_00668C90 D_L39_0033AB08[];
void func_L39_00668C90(s32 i, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    D_L39_0033AB08[i].a = a;
    D_L39_0033AB08[i].b = b;
    D_L39_0033AB08[i].c = c;
    D_L39_0033AB08[i].d = d;
    D_L39_0033AB08[i].e = e;
    D_L39_0033AB08[i].f = f;
    D_L39_0033AB08[i].g = g;
}
/* localdecomp:end func_L39_00668C90 */

/* localdecomp:start func_L39_00668CD8 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern Vec4 D_L39_0025F760;
extern s32 func_003D3CB0(Vec4 *, Vec4 *, s32, s32, s32);

void func_L39_00668CD8(s32 arg0, Vec4 *arg1)
{
    Vec4 a;
    Vec4 b;

    a.q = arg1->q;
    b.q = a.q;
    b.f[2] -= 10.0f;
    a.f[2] += 10.0f;
    if (func_003D3CB0(&a, &b, 4, arg0, 0)) {
        arg1->q = D_L39_0025F760.q;
    } else {
        arg1->q = b.q;
    }
}
/* localdecomp:end func_L39_00668CD8 */
