#include "common.h"

/* localdecomp:start func_L01_0045CED0 */
#include "vu0.h"
extern s32 func_L01_0045CF00(u8 *, void *, void *);

s32 func_L01_0045CED0(u8 *a, u8 *b) {
    vu0_v4 d;

    vec_sub_ab(&d, b, a + 0x10);
    return func_L01_0045CF00(a, b, &d);
}
/* localdecomp:end func_L01_0045CED0 */

/* localdecomp:start func_L01_0045CF00 */
#include "vu0.h"
extern s32 D_L01_001DFB40_0045CF00;
extern u8 *func_L01_0045B958_0045CF00(u8 *);
extern void func_L01_0045C1D0_0045CF00(void);
extern void func_0038D5B0(void *, void *);
extern void func_L01_004511C0_0045CF00(u8 *, f32 *, s32);
extern void func_L01_004515D8_0045CF00(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0045B908_0045CF00(u8 *, u8 *);
extern void func_L01_0045B8D8_0045CF00(u8 *, u8 *);
extern void func_L01_0045CDA0_0045CF00(u8 *, u8 *);
extern void func_L01_0045C510_0045CF00(u8 *self, u8 *p, void *tgt, s32 a3, s32 t0, s32 t1, s32 t2);
extern void func_L01_0045C7A8_0045CF00(u8 *, u8 *, void *, void *);
extern void func_L01_0045C950_0045CF00(u8 *a, u8 *b, u8 *c, s32 d);

s32 func_L01_0045CF00(u8 *a0, void *a1, void *a2) {
    f32 m[16] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[12] __attribute__((aligned(16)));
    f32 v80[4] __attribute__((aligned(16)));
    f32 v90[4] __attribute__((aligned(16)));
    u8 *o;
    f32 *mp;
    s32 t;

    o = func_L01_0045B958_0045CF00(a0);
    if (o == 0) {
        return 8;
    }
    if (D_L01_001DFB40_0045CF00 == *(s32 *)(o + 0xBC)) {
        return *(s32 *)(o + 0x94);
    }
    func_L01_0045C1D0_0045CF00();
    func_0038D5B0(m, a0 + 0xC0);
    mp = m;
    func_L01_004511C0_0045CF00(a0 + 0x10, v40, 0);
    func_L01_004515D8_0045CF00(a0 + 0xC0, v40, v50);
    func_0038D000(o + 0xA0, o + 0xA0, v50);
    *(s32 *)(o + 0x98) = *(s32 *)(o + 0x94);
    *(s32 *)(o + 0x94) = 0;
    func_L01_0045B908_0045CF00(a0, o);
    func_L01_0045B8D8_0045CF00(a0, o);
    t = *(s32 *)(o + 0xBC);
    if (D_L01_001DFB40_0045CF00 - t >= 2 || t == 0) {
        func_L01_0045CDA0_0045CF00(a0, o);
        *(s32 *)(o + 0x80) = 0;
        *(s32 *)(o + 0x9C) &= ~2;
        o[0xEA] = 0xFF;
        qzero(o + 0xA0);
        *(s32 *)(o + 0xB4) = 0;
    }
    *(s32 *)(o + 0xBC) = D_L01_001DFB40_0045CF00;
    func_L01_0045C510_0045CF00(a0, o, a1, (s32)a2, (s32)v80, (s32)v90, (s32)mp);
    func_L01_0045C7A8_0045CF00(a0, o, v90, mp);
    func_L01_0045C950_0045CF00(a0, o, a1, (s32)mp);
    return *(s32 *)(o + 0x94);
}
/* localdecomp:end func_L01_0045CF00 */

LINKER_REMNANT("asm/levels", func_L01_0045D0A8);
