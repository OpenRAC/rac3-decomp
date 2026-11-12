#include "common.h"

/* localdecomp:start func_L24_0034F040 */
#include "vu0.h"
typedef struct {
    u8 p0[0x80];
    vu0_q x80;
    vu0_q x90;
    u8 pA0[0x30];
    vu0_q xD0;
    u8 pE0[0x25C0 - 0xE0];
    u8 *x25C0;
} S_34F040;
extern S_34F040 D_001A4BE0;

void func_L24_0034F040(u8 *obj) {
    S_34F040 *g = &D_001A4BE0;
    *(vu0_q *)(g->x25C0 + 0x10) = *(vu0_q *)(obj + 0x10);
    g->x80 = *(vu0_q *)(g->x25C0 + 0x10);
    *(vu0_q *)(g->x25C0 + 0xF0) = *(vu0_q *)(obj + 0xF0);
    g->x90 = *(vu0_q *)(g->x25C0 + 0xF0);
    g->xD0 = *(vu0_q *)(obj + 0x10);
}
/* localdecomp:end func_L24_0034F040 */

INCLUDE_ASM("asm/levels", func_L24_0034F080);

INCLUDE_ASM("asm/levels", func_L24_0034F1B8);

LINKER_REMNANT("asm/levels", func_L24_0034F4D8);

INCLUDE_ASM("asm/levels", func_L24_0034F4E0);

INCLUDE_ASM("asm/levels", func_L24_0034F5D8);

INCLUDE_ASM("asm/levels", func_L24_0034F828);

/* localdecomp:start func_L24_0034FA98 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_L24_00350980(u8 *, void *, s32, f32, f32, f32, f32, f32, f32, f32);
__asm__(".extern D_L24_001DD4B0, 4");
__asm__(".extern D_L24_001DD498, 2");
extern f32 D_L24_001DD4B0;
extern s16 D_L24_001DD498;

void func_L24_0034FA98(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 c[4];
    f32 b[4];
    u8 m1[0x30];
    u8 m2[0x40];
    f32 w[4];

    *(vu0_q *)a = 0;
    qzero(b);
    b[2] = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    func_00382760(a, 1.0f, func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    func_0038CE20(c, s + 0x100, 3.0f);
    vec_add_ab(a, a, c);
    func_003C2F58(obj, 2, out);
    func_0038D308(m1, b);
    func_0038D5B0(m2, m1);
    func_0038D028(w, s + 0x100, m2);
    if (func_L24_00350980(obj, out, *(s32 *)(s + 0x15C), b[2], b[1], *(f32 *)(s + 0x160), b[2], b[1], w[0], D_L24_001DD4B0) != 0) {
        *(s16 *)(s + 0x168) = (D_L24_001DD498 * 5 + 2) / 6;
    }
}
/* localdecomp:end func_L24_0034FA98 */

/* localdecomp:start func_L24_0034FBE8 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L24_00351448(void *, void *, void *, s32, s32, f32, f32, f32, f32);
__asm__(".extern D_L24_001DD4D8, 4");
__asm__(".extern D_L24_001DD4DC, 4");
__asm__(".extern D_L24_001DD4E0, 4");
__asm__(".extern D_L24_001DD4E4, 2");
extern f32 D_L24_001DD4D8;
extern f32 D_L24_001DD4DC;
extern f32 D_L24_001DD4E0;
extern s16 D_L24_001DD4E4;

void func_L24_0034FBE8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 b[4];
    f32 k;

    *(vu0_q *)a = 0;
    qzero(b);
    b[2] = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    k = D_L24_001DD4D8 * 0.020000001f;
    func_00382760(a, k, func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    vec_add_ab(a, a, s + 0x100);
    func_003C2F58(obj, 2, out);
    if (func_L24_00351448(out, obj, a, 2, 3, D_L24_001DD4DC, D_L24_001DD4E0, 2.0f, 2.0f) != 0) {
        *(s16 *)(s + 0x168) = (D_L24_001DD4E4 * 5 + 2) / 6;
    }
}
/* localdecomp:end func_L24_0034FBE8 */

/* localdecomp:start func_L24_0034FCF8 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

s32 func_L24_0034FCF8(u8 *obj, void *a1, void *a2, void *a3, s32 b0, s32 b1, s32 n, f32 scale, f32 d) {
    f32 v[4];
    u8 q[0x30];

    if (*(u16 *)(obj + 0x34) & 0x100) {
        *(u128_t *)v = *(u128_t *)(obj + 0xC0);
    } else {
        v[0] = func_0038D098(*(f32 *)(obj + 0xF8));
        v[1] = func_0038D0B0(*(f32 *)(obj + 0xF8));
        v[2] = 0.0f;
    }
    func_0038CE20(v, v, d);
    v[2] = 1.0f;
    v[3] = 5627.925f;
    func_L01_00446760(q, obj, (s32)a3, v, scale);
    q[0x18] = b0;
    q[0x19] = b1;
    *(u16 *)(q + 0x1A) = *(u16 *)(obj + 0xAA);
    return func_003D3CB0(a1, a2, n, obj, q);
}
/* localdecomp:end func_L24_0034FCF8 */

INCLUDE_ASM("asm/levels", func_L24_0034FE28);

/* localdecomp:start func_L24_00350190 */
#include "vu0.h"
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern s32 func_L01_004C7A18(f32, void *, void *, void *, void *, void *, s32, s32);
__asm__(".extern D_L24_001DD4D8, 4");
__asm__(".extern D_L24_001DD4DC, 4");
extern f32 D_L24_001DD4D8;
extern f32 D_L24_001DD4DC;

void func_L24_00350190(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 out[4];
    f32 a[4];
    f32 b[4];
    f32 k;

    *(u128_t *)a = 0;
    qzero(b);
    b[2] = func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8));
    b[1] = *(f32 *)(s + 0x148);
    k = D_L24_001DD4D8 * 0.020000001f;
    func_00382760(a, k, func_0038DAB8(*(f32 *)(s + 0x140), *(f32 *)(obj + 0xF8)), -*(f32 *)(s + 0x148));
    vec_add_ba(a, a, s + 0x100);
    func_003C2F58(obj, 2, out);
    s[0x1A4] = func_L01_004C7A18(D_L24_001DD4DC * 0.00040000002f, out, a, s + 0x170, s + 0x180, obj, 0, 0);
}
/* localdecomp:end func_L24_00350190 */

INCLUDE_ASM("asm/levels", func_L24_00350288);

/* localdecomp:start func_L24_003503F0 */
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern u8 D_L24_001E2200[];
extern f32 D_001A65CC[];

void func_L24_003503F0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *r;
    u8 *t;
    s32 h;

    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L24_001E2200, obj + 0x10) < 1024.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0x1E;
        }
    }
    if (obj[0x95] != 0) {
        *(f32 *)(obj + 0x18) = *(f32 *)(s + 0x150);
        r = (u8 *)func_L01_00447490(obj, 1, 0);
        if (r != 0 && *(u8 **)(r + 0x20) != 0) {
            t = *(u8 **)(r + 0x20);
            h = *(s16 *)(t + 0xAA);
            if (h != 0x15D4 && h != 0) {
                if (t != *(u8 **)(s + 0x48) || *(s16 *)(s + 0x36) == 0) {
                    s[0x77] = 0xD2;
                    s[0x78] = 0xD2;
                    s[0x79] = 0xD2;
                    func_003C4A40(obj, s + 0x70);
                    *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - *(f32 *)(r + 0x2C);
                    D_001A65CC[0] = *(f32 *)(s + 0x30);
                    if (*(f32 *)(s + 0x30) <= 0.0f) {
                        obj[0x95] = 6;
                    }
                    *(u8 **)(s + 0x48) = *(u8 **)(r + 0x20);
                    *(s16 *)(s + 0x36) = 8;
                }
            }
        }
        obj[0xA8] = 0xFF;
    } else {
        *(f32 *)(s + 0x150) = *(f32 *)(obj + 0x18);
    }
    func_L01_0044ABD0(obj, s + 0x70);
}
/* localdecomp:end func_L24_003503F0 */

INCLUDE_ASM("asm/levels", func_L24_00350560);

INCLUDE_ASM("asm/levels", func_L24_00350980);

INCLUDE_ASM("asm/levels", func_L24_00350C30);

INCLUDE_ASM("asm/levels", func_L24_00351448);

INCLUDE_ASM("asm/levels", func_L24_003515A8);
