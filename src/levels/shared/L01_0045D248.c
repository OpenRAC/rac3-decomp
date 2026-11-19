#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;

/* localdecomp:start func_L01_0045D248 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
extern s32 D_L01_001DFB40;
extern void func_0038D5B0(void *, void *);
extern void func_L01_0045D4B8(u8 *, u8 *, s32);
extern void func_L01_0045E1B8(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0045B908(u8 *, u8 *);
extern void func_L01_0045B8D8(u8 *, u8 *);
extern void func_L01_0045D5C0(u8 *, u8 *);
extern void func_L01_0045D788(u8 *, u8 *, u8 *, s32, void *, void *, void *);
extern void func_L01_0045DA60(u8 *, u8 *, void *, void *);
extern void func_L01_0045DBF0(u8 *, u8 *, u8 *, void *);
extern void func_0038CF68(f32, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern u8 D_L01_001EAA00[];
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);


s32 func_L01_0045D248(u8 *a, u8 *b, s32 c) {
    u8 *o;
    f32 m[16];
    f32 v1[4];
    f32 v2[12];
    f32 *mp;
    f32 v3[4];
    f32 v4[4];
    f32 v5[4];
    f32 v6[4];

    o = ((u8 * (*)(u8 *))func_L01_0045B958)(a);
    if (o == 0) {
        return 8;
    }
    if (D_L01_001DFB40 != *(s32 *)(o + 0xBC)) {
        func_0038D5B0(m, a + 0xC0);
        mp = m;
        func_L01_0045D4B8(a, (u8 *)v1, 0);
        func_L01_0045E1B8(a + 0xC0, v1, v2);
        func_0038D000(o + 0xA0, o + 0xA0, v2);
        *(s32 *)(o + 0x98) = *(s32 *)(o + 0x94);
        *(s32 *)(o + 0x94) = 0;
        func_L01_0045B908(a, o);
        func_L01_0045B8D8(a, o);
        if (D_L01_001DFB40 - *(s32 *)(o + 0xBC) >= 2 || *(s32 *)(o + 0xBC) == 0) {
            func_L01_0045D5C0(a, o);
            *(s32 *)(o + 0xB4) = 0;
            *(u8 *)(o + 0xEA) = 0xFF;
            *(s32 *)(o + 0x9C) |= -3;
            qzero(o + 0xA0);
        }
        *(s32 *)(o + 0xBC) = D_L01_001DFB40;
        func_L01_0045D788(a, o, b, c, v3, v4, mp);
        func_L01_0045DA60(a, o, v4, mp);
        func_L01_0045DBF0(a, o, b, mp);
        if (*(s32 *)(o + 0x38) & 0x400) {
            return *(s32 *)(o + 0x94);
        }
        func_0038CF68(0.1f, v5, a + 0xE0);
        func_0038CF68(-3.0f, v6, a + 0xE0);
        vec_add_ba(v5, v5, a + 0x10);
        vec_add_ba(v6, v6, a + 0x10);
        if (func_0038CE68(D_L01_001EAA00 + 0x40, a + 0xE0) > 0.7f) {
            if (func_003D3CB0(v5, v6, 2, a, 0) != 0) {
                *(vu0_q *)(a + 0x10) = *(vu0_q *)(D_L01_001EAA00 + 0x20);
            }
        }
    }
    return *(s32 *)(o + 0x94);
}
/* localdecomp:end func_L01_0045D248 */

LINKER_REMNANT("asm/levels", func_L01_0045D4A8);

INCLUDE_ASM("asm/levels", func_L01_0045D4B8);

INCLUDE_ASM("asm/levels", func_L01_0045D5C0);

/* localdecomp:start func_L01_0045D728 */
extern f32 func_0038CED8(u8 *);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);

f32 func_L01_0045D728(u8 *a0, void *a1) {
    f32 v[4];
    f32 m[12];
    func_L01_0040EE50(m, a0 + 192);
    func_0038D000(v, a1, m);
    return func_0038D160(v[2], ((f32 (*)(void *))func_0038CED8)(v));
}
/* localdecomp:end func_L01_0045D728 */

INCLUDE_ASM("asm/levels", func_L01_0045D788);

INCLUDE_ASM("asm/levels", func_L01_0045DA60);

INCLUDE_ASM("asm/levels", func_L01_0045DBF0);

INCLUDE_ASM("asm/levels", func_L01_0045DF48);

INCLUDE_ASM("asm/levels", func_L01_0045E010);

INCLUDE_ASM("asm/levels", func_L01_0045E0D8);

/* localdecomp:start func_L01_0045E1B8 */
extern void func_0038CE20(void *, void *, float);
extern void func_L01_0045E0D8(void *, void *, void *);
void func_L01_0045E0D8(void *a0, void *a1, void *a2);

/* from rac2-decomp's func_002B03B8, renamed */
void func_L01_0045E1B8(void *first, void *second, void *third) {
    float vector[4];
    func_0038CE20(vector, second, -1.0f);
    func_L01_0045E0D8(first, vector, third);
}
/* localdecomp:end func_L01_0045E1B8 */
