#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_003AAD60);

/* localdecomp:start func_L03_003AC868 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003C7C38(void *);
extern u8 D_L03_001E24C0[];
__asm__(".extern D_L03_001DE5E0, 8");
extern u8 D_L03_001DE5E0[8];
__asm__(".extern D_L03_001DE5F0, 8");
extern u8 D_L03_001DE5F0[8];
extern u8 D_L03_001F02C0[];

u8 *func_L03_003AC868(u8 *a0, f32 t) {
    u8 *m = func_003C24B0(0x1C01, 0x80);
    u8 *v;
    vu0_v4 d;
    u8 *mat;
    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        v = *(u8 **)(m + 0x68);
        mat = m + 0xC0;
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(vu0_q *)(m + 0x10) = *(vu0_q *)(D_L03_001E24C0 + 0x00);
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(D_L03_001E24C0 + 0x10);
        *(s32 *)(m + 0xF0) = 0;
        *(f32 *)(v + 4) = *(f32 *)(v + 0) = *(f32 *)(m + 0xF0);
        *(s32 *)(v + 8) = 4;
        func_0038D308(mat, m + 0xF0);
        func_0038CF68(&d, mat, t);
        vec_add_ba(m + 0x10, &d, m + 0x10);
        *(vu0_q *)(D_L03_001F02C0 + 0x10) = *(vu0_q *)D_L03_001DE5E0;
        qzero(D_L03_001F02C0 + 0x30);
        *(vu0_q *)(D_L03_001F02C0 + 0x00) = *(vu0_q *)D_L03_001DE5F0;
        qzero(D_L03_001F02C0 + 0x20);
        func_003C6F90(m, 0x604040, 0xE, 0xE, 0xE);
        *(u16 *)(m + 0x34) &= 0xFF7F;
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L03_003AC868 */

/* localdecomp:start func_L03_003AC998 */
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003C7C38(void *);
extern u8 D_L03_001E24C0[];

u8 *func_L03_003AC998(u8 *a0, void *a1, s32 a2) {
    u8 *m = func_003C24B0(0x1C40, 0x80);
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 d;
    if (m != 0) {
        if (a1 != 0) {
            func_003C2F58(a1, 0x20, m + 0x10);
        }
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(D_L03_001E24C0 + 0x10);
        func_0038D308(m + 0xC0, m + 0xF0);
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(u16 *)(m + 0x34) &= 0xFF7F;
        func_003C6F90(m, 0x505050, 0xE, 0xE, 0xE);
        func_003C2F58(a1, a2 - 0x20, &p);
        func_003C2F58(a1, a2, &q);
        vec_sub_ba(&d, &q, &p);
        func_0038CF68(&d, &d, 0.75f);
        vec_add_ab(m + 0x10, m + 0x10, &d);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L03_003AC998 */

/* localdecomp:start func_L03_003ACAD0 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);

u8 *func_L03_003ACAD0(u8 *a0, u8 *a1) {
    u8 *m = func_003C24B0(0x1C4F, 0x80);
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        *(long *)(m + 0x38) = *(long *)(a1 + 0x38);
        *(u8 **)(*(u8 **)(m + 0x68) + 0x20) = a1;
        *(u128_t *)(m + 0x10) = *(u128_t *)(a1 + 0x10);
        *(u128_t *)(m + 0xF0) = *(u128_t *)(a1 + 0xF0);
        func_0038D308(m + 0xC0, m + 0xF0);
    }
    return m;
}
/* localdecomp:end func_L03_003ACAD0 */

INCLUDE_ASM("asm/levels", func_L03_003ACB68);

/* localdecomp:start func_L03_003AD030 */
f32 func_L03_003AD030(f32 a, f32 b) {
    a = a + b;
    if (a < 0.0f) {
        a += 360.0f;
    } else if (359.0f < a) {
        a -= 360.0f;
    }
    return a;
}
/* localdecomp:end func_L03_003AD030 */

INCLUDE_ASM("asm/levels", func_L03_003AD098);

/* localdecomp:start func_L03_003AD510 */
extern void func_L03_003ADC48(void);
extern void func_L01_004450F0(u8 *o, s32 a, s32 b);

s32 func_L03_003AD510(u8 *a0) {
    u8 *v;
    if (*(s16 *)(a0 + 170) != 6880) {
        return 0;
    }
    v = *(u8 **)(a0 + 104);
    if (*(s32 *)(v + 80) >= v[*(s32 *)(v + 44) * 32 + 522]) {
        return 0;
    }
    func_L03_003ADC48();
    func_L01_004450F0(a0, 7, -1);
    return 1;
}
/* localdecomp:end func_L03_003AD510 */

/* localdecomp:start func_L03_003AD580 */
extern void func_003C7C38(void *);
extern u8 *D_L03_001DF9A0;
extern u8 *D_L03_001DF9A4;
typedef struct { void (*a)(void); void (*b)(void); } Cb_3AD580;
typedef struct { u8 pad[0x24E10]; Cb_3AD580 cb[3]; } G_3AD580;
extern G_3AD580 *D_001D67C8;

void func_L03_003AD580(void) {
    u8 *p;
    s32 i;
    u16 u;
    for (p = D_L03_001DF9A0; p <= D_L03_001DF9A4; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            u = *(u16 *)(p + 0xAA);
            if ((u32)(u - 0x1C04) < 3 || (s16)u == 0x1C16 || (s16)u == 0x1C19 || (s16)u == 0x1C01 || (s16)u == 0x1C40 || (s16)u == 0x1C3F || (s16)u == 0x1C3E || (s16)u == 0x1C4F) {
                (*(void (**)(u8 *))(p + 0x64))(p);
                if (*(s32 *)(p + 0x24) != 0) {
                    func_003C7C38(p);
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (D_001D67C8->cb[i].a != 0) {
            (&D_001D67C8->cb[i])->a();
        }
        if (D_001D67C8->cb[i].b != 0) {
            (&D_001D67C8->cb[i])->b();
        }
    }
}
/* localdecomp:end func_L03_003AD580 */

/* localdecomp:start func_L03_003AD740 */
extern u8 *D_L03_001DF9A0_003AD740;
extern u8 *D_L03_001DF9A4_003AD740;
extern void func_003C2880(void *);

void func_L03_003AD740(s32 a0) {
    u8 *p;
    for (p = D_L03_001DF9A0_003AD740; p <= D_L03_001DF9A4_003AD740; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            if (*(s16 *)(p + 0xAA) == 0x1C04 || *(s16 *)(p + 0xAA) == 0x1C05 || *(s16 *)(p + 0xAA) == 0x1C06 || *(s16 *)(p + 0xAA) == 0x1C16 || *(s16 *)(p + 0xAA) == 0x1C19 || *(s16 *)(p + 0xAA) == 0x1C01 || *(s16 *)(p + 0xAA) == 0x1C40 || *(s16 *)(p + 0xAA) == 0x1C3F || *(s16 *)(p + 0xAA) == 0x1C3E || *(s16 *)(p + 0xAA) == 0x1C4F) {
                if (*(s16 *)(p + 0xAA) == 0x1C19) {
                    p[0x20] = 1;
                } else if (*(s16 *)(p + 0xAA) != 0x1C01 && *(s16 *)(p + 0xAA) != 0x1C40 && *(s16 *)(p + 0xAA) != 0x1C3F && *(s16 *)(p + 0xAA) != 0x1C4F && (*(s16 *)(p + 0xAA) != 0x1C3E || a0 == 1)) {
                    func_003C2880(p);
                }
            }
        }
    }
}
/* localdecomp:end func_L03_003AD740 */
