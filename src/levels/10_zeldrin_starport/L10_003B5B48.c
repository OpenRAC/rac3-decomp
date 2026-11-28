#include "common.h"

INCLUDE_ASM("asm/levels", func_L10_003B5B48);

/* localdecomp:start func_L10_003B64C8 */
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; long d[0x20]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x1000]; s8 c[0x1000]; s16 h[0x800]; u16 uh[0x800]; s32 i[0x400]; u32 u[0x400]; f32 f[0x400]; void *p[0x400]; long d[0x200]; u128_t q[0x100]; } Pv;
typedef union G_ { u8 b[0x4000]; s8 c[0x4000]; s16 h[0x2000]; u16 uh[0x2000]; s32 i[0x1000]; u32 u[0x1000]; f32 f[0x1000]; void *p[0x1000]; long d[0x800]; u128_t q[0x400]; } G;
typedef union { f32 f[4]; s32 i[4]; s8 c[16]; u8 b[16]; s16 h[8]; u16 uh[8]; u128_t q; } __attribute__((aligned(16))) U16;
extern s32 *D_L10_0021D1C0[];
extern f32 D_L10_001DE75C;
__asm__(".extern D_L10_001DE75C, 4");
extern f32 D_L10_001DE764;
__asm__(".extern D_L10_001DE764, 4");
extern f32 D_L10_001DE768;
__asm__(".extern D_L10_001DE768, 4");
extern f32 D_L10_001DE76C;
__asm__(".extern D_L10_001DE76C, 4");
extern s32 func_00382498(s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_00447878(void *, void *, s32, f32, f32);
extern void func_L01_004482A0(void *, f32, void *, f32, f32, f32);
extern void func_L01_00448340(void *, void *, void *, f32, f32, f32);
extern void func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045A898(void *, void *, f32);
extern void func_L01_0045A9F0(void *);
extern void func_L01_0045BD10(void *, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(void *, s32);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern s32 func_L01_0045C2A0(void *, f32, f32, f32);
extern void func_L05_0032B880(void *, void *, void *, f32);
extern s32 func_L10_003B85A0(u8 *);
extern void func_L10_003B8ED0(void *, s32);
extern void func_L10_003B8F50(u8 *);
extern void func_L10_003B9078(void *, s32, s32, s32);
extern s32 func_L10_003B9D28(void *);
#include "vu0.h"
void func_L10_003B64C8(Mo *m) {
    U16 sp90;
    U16 spA0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    void *temp_16_3;
    s32 *temp_16_6;
    s32 *temp_17_11;
    s32 *temp_17_3;
    s32 *temp_17_4;
    s32 *temp_17_5;
    s32 *temp_17_6;
    s32 temp_2_10;
    s32 temp_2_3;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_5;
    void *temp_16;
    void *temp_16_10;
    void *temp_16_11;
    void *temp_16_12;
    void *temp_16_13;
    void *temp_16_14;
    void *temp_16_16;
    void *temp_16_17;
    void *temp_16_18;
    void *temp_16_19;
    void *temp_16_22;
    void *temp_16_2;
    void *temp_16_4;
    void *temp_16_5;
    void *temp_16_7;
    void *temp_16_8;
    void *temp_17_2;
    void *temp_17_7;
    void *temp_17_8;
    void *temp_17_9;
    Pv *pv;
    void *temp_2_8;
    void *temp_2_9;
    void *temp_3_4;
    void *temp_4_3;
    void *temp_4_4;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_4_7;
    void *temp_4_8;
    void *temp_4_9;
    void *temp_6;
    void *var_21;
    void *var_21_2;

    pv = m->p[0x68/4];
    if ((pv->i[0x33C/4] != 0) && (m->b[0x20] == 0x1D)) {
        return;
    }
    if (func_L10_003B85A0(m->b) != 0) {
        return;
    }
    switch (m->b[0x95]) {
    case 0:
        if (func_L01_004561E0(m) != 0) {
            pv->h[0x2D6/2] = (func_00382498(0, 0x1E) * 5 + 2) / 6;
        }
        if (pv->h[0x234/2] == 1) {
                func_L10_003B9078(m, 6, 0, 8);
                func_L01_004450F0(m, 9, 2);
                temp_3_2 = pv->i[0x310/4];
                if (temp_3_2 != -1) {
                    func_L01_004450F0(m, 0xC, 2);
                    func_L10_003B9078(m, 6, 0, 8);
                    if (pv->i[0x320/4] != 0) {
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                        if (m->b[0x43] != 6) {
                            func_003C3A10(m->b, 6, 0, 8);
                        }
                        func_L01_004450F0(m, 0x11, -1);
                    }
                } else if (pv->i[0x314/4] != temp_3_2) {
                    func_L01_004450F0(m, 0xD, 2);
                    func_L10_003B9078(m, 6, 0, 8);
                    if (pv->i[0x320/4] != 0) {
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                        if (m->b[0x43] != 6) {
                            func_003C3A10(m->b, 6, 0, 8);
                        }
                        func_L01_004450F0(m, 0xF, -1);
                    }
                }
                if (pv->i[0x328/4] != 0) {
                    func_L01_004450F0(m, 0xE, -1);
                    func_L10_003B9078(m, 0xD, 0, 2);
                    func_003C3A10(pv->p[0x2DC/4], 2, 0, 8);
                    if (pv->i[0x320/4] != 0) {
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                        func_L01_004450F0(m, 0x10, -1);
                    }
                    if (pv->i[0x310/4] != -1) {
                        func_003C3A10(pv->p[0x2DC/4], 2, 0, 8);
                        func_L01_004450F0(m, 0x10, -1);
                    }
                }
        } else if ((pv->i[0x2D8/4] != 0) && (func_0038CB00(pv->b + 0x2D6) != 0)) {
            pv->i[0x2D8/4] = 0;
            if (pv->i[0x2D0/4] < 0xFA) {
                pv->i[0x2D0/4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 9, 2);
        } else if (pv->i[0x2D0/4] == 0) {
            func_L01_004450F0(m, 1, 0);
        }
        break;
    case 2:
        if ((pv->h[0x234/2] != 1) && (m->b[0x20] != 0x10) && (m->b[0x20] != 0xE)) {
            func_L10_003B9078(m, 0, 0, 8);
            func_L01_004450F0(m, 2, 1);
            pv->i[0x2D0/4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    case 3:
        {
            s32 r = func_L01_00454370(m, pv->b + 0x160);
            if (pv->f[0x30/4] <= 0.0f) {
                func_L10_003B8ED0(m, 0);
                func_003A52A0(4, 0, m);
                func_L01_003303B8(m->b + 0x10, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f, 1, 1, 1, 0, 1, 0, 0x01010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_003C2880(m);
                return;
            }
            if (r & 2) {
                if (pv->h[0x234/2] == 1) {
                    func_L10_003B9078(m, 6, 0, 8);
                    func_L01_004450F0(m, 9, 2);
                } else {
                    func_L10_003B9078(m, 0, 0, 8);
                    func_L01_004450F0(m, 2, 1);
                    pv->i[0x2D0/4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
                }
            }
        }
        break;
    case 5:
        break;
    }
                switch (m->b[0x20]) {                   /* switch 2 */
                case 1:
                    break;
                case 12:                            /* switch 2 */
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, m->f[0xF8/4], pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0);
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    if (func_L01_0045BDE8(m, pv->i[0x310/4]) != 0) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if ((func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 10.0f) && ((u16) m->uh[0x96/2] >= 5U) && (pv->i[0x348/4] == 0)) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    break;
                case 17:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_16 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16, ang, pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0); }
                    if (func_L01_0045BDE8(m, pv->i[0x310/4]) != 0) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 8.0f) {
                        if ((u16) m->uh[0x96/2] >= 5U) {
                            func_L10_003B9078(m, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        }
                    }
                    if ((m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 5);
                        func_L01_004450F0(m, 0x13, -1);
                    }
                    break;
                case 19:                            /* switch 2 */
                    temp_16_2 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16_2, ang, pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0); }
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0x11, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    if ((func_L01_0045BDE8(m, pv->i[0x310/4]) != 0) && (m->b[0x43] != 9)) {
                        func_003C3A10(m->b, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_3 = pv->p[0x2DC/4];
                        if (((G *)temp_4_3)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_3, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            } else {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            }
                            spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, -0.0044f);
                            func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                        }
                    }
                    break;
                case 14:                            /* switch 2 */
                    temp_17_2 = m->b + 0x10;
                    temp_16_3 = (u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10;
                    func_L01_00448340(temp_17_2, temp_16_3, pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_17_2, temp_16_3) < 0.25f) {
                        if (pv->i[0x32C/4] == 0) {
                            func_L10_003B9078(m, 0xE, 0, 8);
                            func_L01_004450F0(m, 8, -1);
                            pv->i[0x334/4] = 0;
                        } else {
                            func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, -1);
                        }
                    }
                    break;
                case 16:                            /* switch 2 */
                    temp_16_4 = m->b + 0x10;
                    temp_17_3 = D_L10_0021D1C0[pv->i[0x310/4]];
                    func_L01_00448340(temp_16_4, (u8 *)temp_17_3 + ((pv->i[0x334/4] * 0x10) + 0x10), pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_16_4, (u8 *)temp_17_3 + ((pv->i[0x334/4] * 0x10) + 0x10)) < 0.25f) {
                        temp_2_3 = pv->i[0x334/4] + 1;
                        pv->i[0x334/4] = temp_2_3;
                        if (temp_2_3 >= *temp_17_3) {
                            if (pv->i[0x32C/4] == 0) {
                                func_L10_003B9078(m, 0xE, 0, 8);
                                func_L01_004450F0(m, 8, -1);
                                pv->i[0x334/4] = 0;
                            } else {
                                func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                                func_L01_004450F0(m, 0x1B, -1);
                            }
                        }
                    }
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0) && (((G *)(pv->p[0x2DC/4]))->b[0x42] == 9)) {
                        func_L01_004450F0(m, 0x14, -1);
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 3);
                    }
                    break;
                case 20:                            /* switch 2 */
                    temp_16_5 = m->b + 0x10;
                    temp_17_4 = D_L10_0021D1C0[pv->i[0x310/4]];
                    var_21_2 = temp_16_5;
                    func_L01_00448340(temp_16_5, (u8 *)temp_17_4 + ((pv->i[0x334/4] * 0x10) + 0x10), pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_16_5, (u8 *)temp_17_4 + ((pv->i[0x334/4] * 0x10) + 0x10)) < 0.25f) {
                        temp_2_10 = pv->i[0x334/4] + 1;
                        pv->i[0x334/4] = temp_2_10;
                        temp_3_3 = *temp_17_4;
                        if (temp_2_10 >= temp_3_3) {
                            pv->i[0x334/4] = (s32) (temp_3_3 - 1);
                        }
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_4 = pv->p[0x2DC/4];
                        if (((G *)temp_4_4)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_4, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            } else {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            }
                            spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, -0.0044f);
                            func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                        }
                    }
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0x10, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    break;
                case 24:                            /* switch 2 */
                    pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                    temp_16_6 = D_L10_0021D1C0[pv->i[0x314/4]];
                    temp_6 = (u8 *)temp_16_6 + (pv->i[0x334/4] * 0x10);
                    func_L01_004482A0(m->b + 0x18, ((G *)temp_6)->f[0x18/4], pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        temp_2_5 = pv->i[0x334/4] + 1;
                        pv->i[0x334/4] = temp_2_5;
                        if (temp_2_5 >= *temp_16_6) {
                            func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, -1);
                        }
                    }
                    break;
                case 25:                            /* switch 2 */
                    func_L01_004482A0(m->b + 0x18, ((G *)((u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + (pv->i[0x334/4] << 4)))->f[0x18/4], pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        temp_16_7 = m->b + 0x10;
                        temp_17_5 = D_L10_0021D1C0[pv->i[0x314/4]];
                        temp_f20 = func_0038CF38(temp_16_7, (u8 *)temp_17_5 + 0x10);
                        if (func_0038CF38(temp_16_7, (u8 *)temp_17_5 + (*temp_17_5 * 0x10)) < temp_f20) {
                            func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], 0, *temp_17_5 - 1);
                        } else {
                            func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], *temp_17_5 - 1, 0);
                        }
                    }
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        func_L01_004450F0(m, 0x1A, -1);
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 3);
                    }
                    break;
                case 26:                            /* switch 2 */
                    pv->i[0xA8/4] = (s32) (pv->i[0xA8/4] | 4);
                    temp_17_6 = D_L10_0021D1C0[pv->i[0x314/4]];
                    temp_16_8 = m->b + 0x10;
                    var_21_2 = temp_16_8;
                    func_L01_00448340(temp_16_8, (u8 *)temp_17_6 + ((pv->i[0x334/4] * 0x10) + 0x10), pv->b + 0x2E8, 0.0032000002f, 0.014400001f, 0.080000006f);
                    if (func_0038CF00(temp_16_8, (u8 *)temp_17_6 + ((pv->i[0x334/4] * 0x10) + 0x10)) < 0.25f) {
                        temp_2_6 = pv->i[0x334/4] + 1;
                        pv->i[0x334/4] = temp_2_6;
                        temp_5 = *temp_17_6;
                        if (temp_2_6 >= temp_5) {
                            pv->i[0x334/4] = (s32) (temp_5 - 1);
                        }
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_5 = pv->p[0x2DC/4];
                        if (((G *)temp_4_5)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_5, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            } else {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            }
                            spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, -0.0044f);
                            func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                        }
                    }
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0x10, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    break;
                case 3:                             /* switch 2 */
                    if (m->b[0x60] & 2) {
                        pv->i[0x338/4] = 1;
                        if (pv->i[0x314/4] != -1) {
                            func_L01_004450F0(m, 0x18, -1);
                            func_L10_003B9078(m, 0xD, 0, 5);
                            pv->i[0x334/4] = 1;
                        }
                    }
                    break;
                case 8:                             /* switch 2 */
                    if (func_L01_0044E1B8(m, 8.0f) != 0) {
                        pv->i[0x338/4] = 0;
                        func_L01_004450F0(m, 0x1B, -1);
                        func_L10_003B9078(m, 9, 0, 8);
                    }
                    if (func_L01_004395E0(m) > 4.0f) {
                        temp_f0 = func_003C3D30((m->b + 0x10), 0, 0, 0.5f);
                        sp90.q = m->q[0x10/16];
                        sp90.f[2] = temp_f0;
                        func_L01_00448340((m->b + 0x10), &sp90, pv->b + 0x2E8, 0.0072000003f, 0.010400001f, 0.28000003f);
                    }
                    break;
                case 13:                            /* switch 2 */
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, m->f[0xF8/4], pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0);
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_17_7 = m->b + 0x10;
                    temp_16_10 = (u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10;
                    func_L01_0045A748(m, temp_16_10);
                    if (func_0038CF38(temp_17_7, temp_16_10) < 0.5f) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if ((func_0038CF38(temp_17_7, ((G *)pv->p[0x230/4])->b + 0x10) < 10.0f) && ((u16) m->uh[0x96/2] >= 5U)) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    break;
                case 15:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_17_8 = m->b + 0x10;
                    temp_16_11 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16_11, ang, pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0); }
                    temp_16_12 = (u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10;
                    func_L01_0045A748(m, temp_16_12);
                    if (func_0038CF38(temp_17_8, temp_16_12) < 0.5f) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if (func_0038CF38(temp_17_8, ((G *)pv->p[0x230/4])->b + 0x10) < 8.0f) {
                        if ((u16) m->uh[0x96/2] >= 5U) {
                            func_L10_003B9078(m, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        }
                    }
                    if ((m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 5);
                        func_L01_004450F0(m, 0x12, -1);
                    }
                    break;
                case 18:                            /* switch 2 */
                    temp_16_13 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16_13, ang, pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0); }
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0xF, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    temp_17_9 = m->b + 0x10;
                    var_21 = temp_17_9;
                    temp_16_14 = (u8 *)D_L10_0021D1C0[pv->i[0x314/4]] + 0x10;
                    func_L01_0045A748(m, temp_16_14);
                    if ((func_0038CF38(temp_17_9, temp_16_14) < 0.5f) && (m->b[0x43] != 9)) {
                        func_003C3A10(m->b, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_6 = pv->p[0x2DC/4];
                        if (((G *)temp_4_6)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_6, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            } else {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            }
                            spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, -0.0044f);
                            func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                        }
                    }
                    break;
                case 21:                            /* switch 2 */
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, m->f[0xF8/4], pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0);
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10);
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    break;
                case 22:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->i[0x2D8/4] = 0;
                    }
                    temp_16_16 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16_16, ang, pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0); }
                    if (func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) {
                        func_L10_003B9078(m, 9, 0, 8);
                        func_L01_004450F0(m, 0x1B, 2);
                    }
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 5);
                        func_L01_004450F0(m, 0x17, -1);
                    }
                    break;
                case 23:                            /* switch 2 */
                    temp_16_17 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16_17, ang, pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0); }
                    if (((G *)(pv->p[0x2DC/4]))->b[0x60] & 2) {
                        func_L01_004450F0(m, 0x16, 2);
                        func_003C3A10(pv->p[0x2DC/4], 9, 0, 5);
                    }
                    if ((func_L01_0045BDE8(m, pv->i[0x314/4]) != 0) && (m->b[0x43] != 9)) {
                        func_003C3A10(m->b, 9, 0, 8);
                    }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 0.5f) != 0) {
                        temp_4_7 = pv->p[0x2DC/4];
                        if (((G *)temp_4_7)->b[0x42] == 0xA) {
                            func_003C2F58(temp_4_7, 0, &sp90);
                            if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            } else {
                                u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                                func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                            }
                            spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, -0.0044f);
                            func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                        }
                    }
                    break;
                case 27:                            /* switch 2 */
                    temp_16_18 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16_18, ang, pv->b + 0x330, 0.0050265486f, 0.0050265486f, 0.25132743f, 0); }
                    if (((u16) m->uh[0x96/2] >= 0x5BU) && (func_L10_003B9D28(m) != 0)) {
                        if (m->b[0x42] == 0xD) {
                            func_003C3A10(pv->p[0x2DC/4], 0xA, 0, 8);
                            func_L01_004450F0(m, 0xA, -1);
                        } else {
                            func_L10_003B9078(m, 0xA, 0, 8);
                            func_L01_004450F0(m, 0xA, -1);
                        }
                    }
                    break;
                case 9:                             /* switch 2 */
                    func_L10_003B9078(m, 6, 0, 8);
                    func_L01_00448728(pv->p[0x2DC/4] + 0xF8, m->f[0xF8/4], pv->b + 0x330, 0.0030717796f, 0.0008377581f, 0.15358898f, 0);
                    func_L01_0045A748(m, pv->b + 0x220);
                    if (((func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) < 14.0f) || (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) > 3.0f)) && (func_0038DBA0(m->f[0xF8/4], func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4])) < 0.5235988f)) {
                        func_L10_003B9078(m, 0xA, 0, 8);
                        func_L01_004450F0(m, 0xA, -1);
                    }
                    break;
                case 10:                            /* switch 2 */
                    temp_16_19 = pv->p[0x2DC/4] + 0xF8;
                    { f32 ang = func_0038D160(pv->f[0x220/4] - m->f[0x10/4], pv->f[0x224/4] - m->f[0x14/4]); func_L01_00448728(temp_16_19, ang, pv->b + 0x330, 0.0050265486f, 0.0050265486f, 0.25132743f, 0); }
                    if (func_L01_0044E1B8(pv->p[0x2DC/4], 5.0f) != 0) {
                        func_003C2F58(pv->p[0x2DC/4], 0, &sp90);
                        if (fabs_asm(m->f[0x18/4] - pv->f[0x228/4]) < 2.0f) {
                            u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                            func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                        } else {
                            u8 *src = pv->p[0x2DC/4] + 0xC0; U16 *dst = &spA0;
                            func_0038CF68(dst, src, (func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) / 1.3f) * 0.020000001f);
                        }
                        spA0.f[2] = func_L01_00447878(&sp90, pv->b + 0x220, 0, func_0038CF38(m->b + 0x10, ((G *)pv->p[0x230/4])->b + 0x10) * 0.020000001f, -0.0044f);
                        func_L05_0032B880(&sp90, &spA0, m, 5.0f);
                    }
                    temp_4_8 = pv->p[0x2DC/4];
                    if (((G *)temp_4_8)->b[0x60] & 2) {
                        if (pv->i[0x32C/4] == 0) {
                            func_L10_003B9078(m, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        } else {
                            func_003C3A10(temp_4_8, 9, 0, 8);
                            func_L01_004450F0(m, 0x1B, 2);
                        }
                        if (pv->i[0x314/4] != -1) {
                            temp_16_22 = m->b + 0x10;
                            func_L01_004450F0(m, 0x15, -1);
                            func_L10_003B9078(m, 6, 0, 8);
                            temp_17_11 = D_L10_0021D1C0[pv->i[0x314/4]];
                            temp_f20_2 = func_0038CF38(temp_16_22, (u8 *)temp_17_11 + 0x10);
                            if (func_0038CF38(temp_16_22, (u8 *)temp_17_11 + (*temp_17_11 * 0x10)) < temp_f20_2) {
                                func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], 0, *temp_17_11 - 1);
                            } else {
                                func_L01_0045C150(m, D_L10_0021D1C0[pv->i[0x314/4]], *temp_17_11 - 1, 0);
                            }
                            if (pv->i[0x324/4] != 0) {
                                func_003C3A10(pv->p[0x2DC/4], 9, 0, 8);
                                func_L01_004450F0(m, 0x16, -1);
                            }
                            if (pv->i[0x32C/4] != 0) {
                                if (pv->i[0x338/4] == 0) {
                                    func_L01_004450F0(m, 3, -1);
                                    func_L10_003B9078(m, 0xC, 0, 5);
                                    pv->i[0x334/4] = 1;
                                } else {
                                    func_L01_004450F0(m, 0x18, -1);
                                    func_L10_003B9078(m, 0xD, 0, 5);
                                    pv->i[0x334/4] = 1;
                                }
                            }
                        }
                    }
                    break;
                case 30:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        pv->f[0x1B8/4] = 2.0f;
                        pv->f[0x1BC/4] = 2.0f;
                    }
                    temp_f1 = pv->f[0x2F8/4];
                    if (temp_f1 < 1.0f) {
                        temp_f0_2 = temp_f1 + D_L10_001DE75C;
                        pv->f[0x2F8/4] = temp_f0_2;
                        if (temp_f0_2 > 1.0f) {
                            pv->f[0x2F8/4] = 1.0f;
                        }
                        m->f[0x2C/4] = (f32) (((G *)(m->p[0x24/4]))->f[0x24/4] * pv->f[0x2F8/4]);
                        temp_3_4 = pv->p[0x2DC/4];
                        ((G *)temp_3_4)->f[0x2C/4] = (f32) (((G *)(((G *)temp_3_4)->p[0x24/4]))->f[0x24/4] * pv->f[0x2F8/4]);
                    }
                    temp_2_8 = pv->p[0x2F4/4];
                    if (temp_2_8 != 0) {
                        ((G *)temp_2_8)->i[0x98/4] = 0;
                    }
                    if (func_L01_0045C2A0(m, D_L10_001DE764, D_L10_001DE768, D_L10_001DE76C) != 0) {
                        m->f[0x48/4] = 1.0f;
                        ((G *)(pv->p[0x2DC/4]))->f[0x48/4] = 1.0f;
                        func_L01_0045A9F0(m);
                        pv->f[0x1BC/4] = 0.75f;
                        pv->f[0x1B8/4] = 0.2f;
                        if (pv->i[0x2F0/4] != 0) {
                            func_L01_004450F0(m, 0x1F, 5);
                            func_L10_003B9078(m, 4, 0, 8);
                        } else {
                            func_L01_004450F0(m, 1, 0);
                            func_L10_003B9078(m, 0, 0, 8);
                        }
                    } else {
                        temp_2_9 = pv->p[0x2DC/4];
                        if (temp_2_9 != 0) {
                            ((G *)temp_2_9)->f[0x48/4] = (f32) m->f[0x48/4];
                        }
                    }
                    temp_4_9 = pv->p[0x2F4/4];
                    if (temp_4_9 != 0) {
                        ((G *)temp_4_9)->i[0x98/4] = (s32) ((G *)(((G *)temp_4_9)->p[0x24/4]))->i[0x10/4];
                    }
                    break;
                case 31:                            /* switch 2 */
                    if (func_L01_004561B8(m) != 0) {
                        func_L01_0045BD78(m, 0.0064000003f, 0.060000002f, 0.010053097f, 0.25132743f);
                    }
                    if (func_0038CF38(m->b + 0x10, (pv->b + 0x300)) > 0.5f) {
                        func_L01_0045A748(m, (pv->b + 0x300));
                    } else {
                        func_L01_0045A898(m, (pv->b + 0x300), pv->f[0x2FC/4]);
                    }
                    if (pv->h[0x234/2] == 1) {
                        func_L01_0045BD78(m, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
                        func_L01_004450F0(m, 2, 1);
                        func_L10_003B9078(m, 0, 0, 8);
                        pv->i[0x2D0/4] = (s32) ((s32) ((func_00382498(0x244, 0x258) * 5) + 2) / 6);
                    } else if (func_0038CF38(m->b + 0x10, (pv->b + 0x300)) <= pv->f[0xA4/4]) {
                        if (pv->f[0xA0/4] < fabs_asm(func_0038DBA0(m->f[0xF8/4], pv->f[0x2FC/4]))) {
                            func_L01_0045BD10(m, pv->f[0x2FC/4]);
                        } else {
                            func_L01_0045BD78(m, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
                            func_L01_004450F0(m, 1, 0);
                            func_L10_003B9078(m, 0, 0, 8);
                        }
                    }
                    break;
                }
            func_L10_003B8F50(m->b);
}
/* localdecomp:end func_L10_003B64C8 */

/* localdecomp:start func_L10_003B85A0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B85A0;
__asm__(".extern D_L10_001DE774, 4");
__asm__(".extern D_L10_001DE778, 4");
extern f32 D_L10_001DE774;
extern f32 D_L10_001DE778;
extern u8 D_001A30B0[];
extern u8 D_L10_001D66B0[8];
extern s32 func_L10_003B8A80(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_00382538(void);
extern void func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_0038D308(void *, void *);
extern void func_L10_003B8ED0(void *, s32);
extern int func_L10_003B90E0(u8 *, void *, s32);
extern void func_L02_0034FD58(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L10_003B85A0(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    V4_3B85A0 a;
    V4_3B85A0 b;
    u8 *e;
    s32 h;
    s32 t;

    if (m[0x20] == 0 && func_L10_003B8A80(m) != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x338) != 0 && m[0x95] != 4) {
        {
            s32 k = *(s32 *)(p + 0x34C);
            if (k == -1 || *(u8 **)((e = D_001A30B0 + (k << 7)) + 0xDC) != *(u8 **)(p + 0x2DC) || e[0xD0] == 0) {
                *(s32 *)(p + 0x34C) = func_003A52A0(7, 4, *(u8 **)(p + 0x2DC));
            }
        }
        func_L01_0044EAE0(m, p + 0x340, p + 0x344, D_L10_001DE774, D_L10_001DE778 * 0.017453292f * 0.020000001f, -1.0f);
        t = m[0x43];
        if (t != 0xE) {
            if (t != 0xD) {
                func_003C3A10(m, 0xD, 0, 8);
            }
        }
        p[0x171] = 0xFF;
        p[0x172] = 0xFF;
        *(f32 *)(p + 0x1BC) = 2.0f;
        *(f32 *)(p + 0x1B8) = 2.0f;
        func_003C2F58(*(u8 **)(p + 0x2DC), 1, &a);
        func_003C2F58(*(u8 **)(p + 0x2DC), 2, &b);
        func_L01_0046A610(&a, D_L10_001D66B0, 0xC, 0x40, 0x406080, (s32)func_00382538(), 73500.0f, 200.0f, 0.95f, 0.010000001f, 0.0f);
        func_L01_0046A610(&b, D_L10_001D66B0, 0xC, 0x40, 0x406080, (s32)func_00382538(), 73500.0f, 200.0f, 0.95f, 0.010000001f, 0.0f);
    } else {
        h = *(s32 *)(p + 0x34C);
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        p[0x171] = 0x11;
        *(s32 *)(p + 0x34C) = -1;
        p[0x172] = 0x11;
        *(f32 *)(p + 0x1BC) = 0.75f;
        *(f32 *)(p + 0x1B8) = 0.2f;
    }
    func_003C2F58(m, 0, *(u8 **)(p + 0x2DC) + 0x10);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF0) = *(f32 *)(m + 0xF0);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF4) = *(f32 *)(m + 0xF4);
    func_0038D308(*(u8 **)(p + 0x2DC) + 0xC0, *(u8 **)(p + 0x2DC) + 0xF0);
    if (p[0x3E] == 2) {
        func_L10_003B8ED0(m, 0);
        return 1;
    }
    if (func_L10_003B90E0(m, p + 0x160, 0) != 0) {
        func_L02_0034FD58(m);
    }
    func_L01_00452860(m, p + 0x30, 0);
    if (p[0x5F] != 0) {
        if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_00456BD0(m, 5);
            }
        }
        if (m[0x95] == 0) {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) {
                func_L01_00456BD0(m, 3);
            }
        }
        if (m[0x95] == 0) {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    }
    return 0;
}
/* localdecomp:end func_L10_003B85A0 */

/* localdecomp:start func_L10_003B8A80 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B8A80;
extern s32 *D_L10_0021D1C0[];
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L10_003B9078(void *, s32, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);

s32 func_L10_003B8A80(u8 *m) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_L01_00456160(void *, void *);
    extern void func_L01_004AA7E8(void *, s32);
    u8 *p = *(u8 **)(m + 0x68);
    s32 one = 1;

    p[0x171] = 0x11;
    *(f32 *)(p + 0x180) = 0.120000005f;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    p[0x1CC] = 6;
    p[0x1CD] = 0xC;
    *(f32 *)(p + 0x74) = 0.5f;
    p[0x170] = 0x1C;
    p[0x1A8] = 3;
    *(s32 *)(p + 0x334) = one;
    *(s32 *)(p + 0x338) = 0;
    p[0x1D7] = 0;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    p[0x1DA] = 0;
    *(s16 *)(p + 0x198) = 0;
    p[0x172] = 0x11;
    *(f32 *)(p + 0x17C) = 0.64000005f;
    *(f32 *)(p + 0x184) = 0.0088f;
    *(f32 *)(p + 0x188) = 0.014800001f;
    *(f32 *)(p + 0x18C) = 0.016f;
    *(f32 *)(p + 0x19C) = 0.4f;
    p[0x1CE] = 6;
    p[0x1CF] = 0xC;
    p[0x1DB] = 0xFF;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 0.7853982f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.00392f;
    func_L01_0045BD78(m, 0.0064000003f, 0.120000005f, 0.010053097f, 0.25132743f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 0xA;
        *(f32 *)(p + 0x30) = 10.0f;
    }
    p[0x39] = one;
    p[0x3E] = one;
    *(f32 *)(p + 0x40) = 2.0f;
    *(u8 **)(p + 0x2DC) = func_003C24B0(0x1611, 0x80);
    func_L01_00456160(*(u8 **)(p + 0x2DC), m);
    m[0x30] = (*(u8 **)(p + 0x2DC))[0x30];
    *(u16 *)(m + 0x32) = *(u16 *)(*(u8 **)(p + 0x2DC) + 0x32);
    *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) |= 0x100;
    func_003C2F58(m, 0, *(u8 **)(p + 0x2DC) + 0x10);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF0) = *(f32 *)(m + 0xF0);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF4) = *(f32 *)(m + 0xF4);
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0xF8) = *(f32 *)(m + 0xF8);
    func_0038D308(*(u8 **)(p + 0x2DC) + 0xC0, *(u8 **)(p + 0x2DC) + 0xF0);
    *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.5f;
    *(f32 *)(*(u8 **)(p + 0x2DC) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(p + 0x2DC) + 0x24) + 0x24) * 1.5f;
    if (*(s32 *)(p + 0x2EC) != 0) {
        *(V4_3B8A80 *)(p + 0x300) = *(V4_3B8A80 *)(m + 0x10);
        *(f32 *)(p + 0x2FC) = *(f32 *)(m + 0xF8);
        func_L01_004450F0(m, 0x1D, 4);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) |= 0x41;
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) &= 0xEFFF;
        *(s32 *)(*(u8 **)(p + 0x2DC) + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(p + 0x2DC), 1);
    } else if (*(s32 *)(p + 0x328) != 0) {
        if (*(s32 *)(p + 0x310) != -1) {
            func_L10_003B9078(m, 0xD, 0, 0);
            *(V4_3B8A80 *)(m + 0x10) = *(V4_3B8A80 *)((u8 *)D_L10_0021D1C0[*(s32 *)(p + 0x310)] + 0x10);
            func_L01_004450F0(m, 1, 0);
            *(s32 *)(p + 0x338) = one;
        } else {
            func_L10_003B9078(m, 0xD, 0, 0);
            func_L01_004450F0(m, 1, 0);
            *(s32 *)(p + 0x338) = one;
        }
    } else {
        func_L01_004450F0(m, 1, 0);
        if (m[0x43] != 0) {
            func_003C3A10(m, 0, 0, 0);
        }
        func_003C3A10(*(u8 **)(p + 0x2DC), 0, 0, 0);
    }
    if (*(s32 *)(p + 0x33C) != 0) {
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) |= 0x41;
        *(u16 *)(*(u8 **)(p + 0x2DC) + 0x34) &= 0xEFFF;
        *(s32 *)(*(u8 **)(p + 0x2DC) + 0x98) = 0;
        func_L01_004AA7E8(*(u8 **)(p + 0x2DC), 1);
        func_L01_004450F0(m, 0x1D, 4);
    }
    return 0;
}
/* localdecomp:end func_L10_003B8A80 */

LINKER_REMNANT("asm/levels", func_L10_003B8EC0);

/* localdecomp:start func_L10_003B8ED0 */
void func_003C2880(void *);
void func_L01_004443E8(void *, s32, s32);

void func_L10_003B8ED0(void *arg0, s32 arg1) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    temp_a0 = *(s32 *)((u8 *)temp_s0 + 0x2DC);
    if (temp_a0 != 0) {
        func_003C2880((void *)temp_a0);
        *(s32 *)((u8 *)temp_s0 + 0x2DC) = 0;
    }
    if (((*(f32 *)((u8 *)temp_s0 + 0x30)) <= 0.0f) && (arg1 == 0)) {
        func_L01_004443E8(arg0, 0, 3);
    }
}
/* localdecomp:end func_L10_003B8ED0 */

/* localdecomp:start func_L10_003B8F50 */
extern void func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);

void func_L10_003B8F50(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u16 value;

    func_0038CAD0(p + 0x2D0);
    func_0038CB00(p + 0x2D4);
    value = *(u16 *)(a0 + 0x96);
    if (value <= 0xFFFEu) {
        *(u16 *)(a0 + 0x96) = value + 1;
    }
    func_L01_00451DF8(a0, p + 0x240, 1, 1, 2.5f);
}
/* localdecomp:end func_L10_003B8F50 */
