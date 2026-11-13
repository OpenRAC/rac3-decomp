#include "common.h"

/* localdecomp:start func_L41_0041B308 */
typedef struct { u8 p0[0x20]; u8 b20; } M_41AA50;
extern void func_L41_0048B8C0(M_41AA50 *, s32);
extern void func_L01_004450F0(M_41AA50 *, s32, s32);

void func_L41_0041B308(M_41AA50 *m) {
    if (m->b20 == 0) {
        func_L41_0048B8C0(m, -1);
        func_L01_004450F0(m, 1, -1);
    }
}
/* localdecomp:end func_L41_0041B308 */

INCLUDE_ASM("asm/levels", func_L41_0041B350);

INCLUDE_ASM("asm/levels", func_L41_0041B578);

INCLUDE_ASM("asm/levels", func_L41_0041B6F0);

INCLUDE_ASM("asm/levels", func_L41_0041B858);

INCLUDE_ASM("asm/levels", func_L41_0041B9C8);

INCLUDE_ASM("asm/levels", func_L41_0041BAF8);

/* localdecomp:start func_L41_0041BDD0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0041BDD0;
typedef struct { u8 b[8]; } B8_0041BDD0;
typedef struct { s32 f0; f32 f4; s32 f8; s32 fC; } V_0041BDD0;
typedef struct {
    u8 p0[0x20]; u8 b20;
    u8 p21[0x2C - 0x21]; f32 f2C;
    u8 b30; u8 p31; s16 h32; u16 h34;
    u8 p36[0x68 - 0x36]; V_0041BDD0 *vars;
    u8 p6C[0xA8 - 0x6C]; u8 bA8;
    u8 pA9[0xC0 - 0xA9]; u8 fC0[0x10];
} M_0041BDD0;

extern V4_0041BDD0 D_L41_00242930 __attribute__((section(".sdata")));
extern B8_0041BDD0 D_L41_00247778[];
extern B8_0041BDD0 D_L41_00247780[];
extern s32 D_001A5DF8[];
extern s32 D_001D5BCC_sda;
__asm__(".extern D_001D5BCC_sda, 4");
extern void func_L41_0048B4B8(M_0041BDD0 *, s32);
extern M_0041BDD0 *func_L41_0041C1E8(M_0041BDD0 *);
extern s32 func_L03_003FB6C8(void *, void *, s32);
extern void func_L41_0041B858(M_0041BDD0 *);
extern void func_L41_0041BAF8(void *, s32, u32, f32);
extern void func_L41_0041C170(void *, s32);
extern void func_L40_004C5C78(s32, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004398C8(void *, s32, void *);
extern void func_L41_0041B9C8(void *, s32, f32, f32, f32);
extern void func_L41_00491978(void *, void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_004897A8(void *, s32);
extern void func_003C2880(void *);

void func_L41_0041BDD0(M_0041BDD0 *m) {
    V_0041BDD0 *v = m->vars;
    M_0041BDD0 *t;
    s32 flag;
    s32 id;
    B8_0041BDD0 a;
    B8_0041BDD0 b;
    V4_0041BDD0 pts[2];
    V4_0041BDD0 w;

    if (m->b20 == 0) {
        v->f0 = -1;
        m->b20 = 1;
        m->b30 = 0xFF;
        m->h32 = 0xFF;
        m->h34 |= 0x4041;
        v->f8 = 0;
        func_L41_0048B4B8(m, v->fC);
    }
    if (v->f0 == -1) {
        flag = 0;
        t = func_L41_0041C1E8(m);
        if (v->f8 > 0) {
            v->f8--;
        }
        if (t != 0 && v->f8 == 0) {
            v->f8 = 0x19;
            v->f4 = v->f4 - t->f2C;
            if (func_L03_003FB6C8(&D_L41_00242930, t, 0x10) == 0) {
                if (t->f2C >= 8.0f) {
                    func_L41_0041B858(m);
                }
                func_L41_0041BAF8(t, 0x14, 0x80555E6A, 1.0f);
            }
            if (v->f4 <= 0.0f) {
                v->f4 = 0.0f;
                flag = 1;
            }
        }
        m->bA8 = 0xFF;
        if (flag) {
            func_L41_0041C170(m, 0xFA);
        }
    }
    if (v->f0 >= 0 && v->f0 < D_001A5DF8[0]) {
        a = D_L41_00247778[0];
        b = D_L41_00247780[0];
        id = -1;
        switch (D_001D5BCC_sda) {
        case 0x29:
        case 0x33:
            id = 0x13;
            break;
        case 0x2A:
        case 0x34:
            id = 0x12;
            break;
        case 0x2D:
        case 0x37:
            id = 0x11;
            break;
        }
        if (id != -1) {
            func_L40_004C5C78(id, 0, m, 0);
        }
        func_0038CE20(&pts[0], m->fC0, -3.0f);
        func_0038CE20(&pts[1], m->fC0, -6.0f);
        func_L01_004398C8(m, 0, &w);
        func_L41_0041B9C8(&w, 5, 1.0f, 4.0f, 12.0f);
        func_L41_0041BAF8(&w, 0x14, 0x80555E6A, 1.5f);
        func_L01_004398C8(m, 1, &w);
        func_L41_0041B9C8(&w, 5, 1.0f, 8.0f, 12.0f);
        func_L41_0041BAF8(&w, 0x14, 0x80555E6A, 1.5f);
        func_L01_004398C8(m, 2, &w);
        func_L41_0041B9C8(&w, 5, 1.0f, 4.0f, 12.0f);
        func_L41_0041BAF8(&w, 0x14, 0x80555E6A, 1.5f);
        func_L41_00491978(m, pts, &b, &a, 0xFFFF, -1, -1, 1, 0xFFFF, 0xFF, 0);
        func_L40_004897A8(m, v->fC);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L41_0041BDD0 */

INCLUDE_ASM("asm/levels", func_L41_0041C170);

INCLUDE_ASM("asm/levels", func_L41_0041C1E8);

/* localdecomp:start func_L41_0041C2E8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0041C2E8;
extern s32 func_L39_005BE900(void *, s32, f32);

s32 func_L41_0041C2E8(V4_0041C2E8 *p) {
    V4_0041C2E8 v = *p;
    s32 r;

    v.w = 1.0f;
    r = ((s32 (*)(void *, s32))func_L39_005BE900)(&v, 0);
    return ~r >> 31 != 0;
}
/* localdecomp:end func_L41_0041C2E8 */

/* localdecomp:start func_L41_0041C328 */
typedef struct { s32 f0; f32 f4; s32 f8; s32 fC; } V_0041C328;
typedef struct { u8 p0[0x68]; V_0041C328 *vars; u8 p6C[0x100 - 0x6C]; } M_0041C328;
extern M_0041C328 *D_L41_0024865C;
extern void func_L41_0041C170(void *, s32);
void func_L41_0041C328(M_0041C328 *m, s32 a1) {
    V_0041C328 *v = m->vars;
    M_0041C328 *a;
    M_0041C328 *b;
    M_0041C328 *r;

    a = v->f8 >= 0 ? &D_L41_0024865C[v->f8] : 0;
    b = v->fC >= 0 ? &D_L41_0024865C[v->fC] : 0;
    r = 0;
    if (a == 0 || b == 0) {
        if (a != 0) {
            r = a;
        } else if (b != 0) {
            r = b;
        }
    } else {
        V_0041C328 *av = a->vars;
        V_0041C328 *bv = b->vars;
        if (av->f4 > 0.0f && bv->f4 > 0.0f) {
            r = av->f4 < bv->f4 ? a : b;
        } else if (av->f4 > 0.0f) {
            r = a;
        } else if (bv->f4 > 0.0f) {
            r = b;
        }
    }
    if (r != 0) {
        V_0041C328 *rv = r->vars;
        func_L41_0041C170(r, a1);
        rv->f4 = 0;
    }
}
/* localdecomp:end func_L41_0041C328 */

INCLUDE_ASM("asm/levels", func_L41_0041C430);

INCLUDE_ASM("asm/levels", func_L41_0041C568);

INCLUDE_ASM("asm/levels", func_L41_0041C778);

LINKER_REMNANT("asm/levels", func_L41_0041CCE0);

/* localdecomp:start func_L41_0041CCF8 */
/* from rac4-decomp's func_L01_004E5DC0, renamed */
void func_L41_0041CCF8(void *p) {
    *(u8*)((u8*)p + 0x30) = 0xff;
}
/* localdecomp:end func_L41_0041CCF8 */
