#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L01_004450F0(s32, s32, s32);
s32 func_L01_004561B8(void *);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_L32_001DFE1C;

/* localdecomp:start func_L32_003A44A8 */
extern u8 *D_L32_002A3E50[];
extern s32 D_L32_001DED30;
extern s32 D_L32_001DED34;
__asm__(".extern D_L32_001DED30, 16");
__asm__(".extern D_L32_001DED34, 16");
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_0038C750(void);
extern void func_L32_003B3A20(u8 *);
extern void func_L32_003B3D88(u8 *);

void func_L32_003A44A8(void) {
    s32 i;
    s32 j;
    u8 **p;

    for (i = 31, p = D_L32_002A3E50; i >= 0; i--, p++) {
        if (*p != 0 && (*p)[0x20] >= 0xFD) {
            *p = 0;
        }
    }
    func_003A9440(6, func_00389598(D_L32_001DED30));
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x8000000044UL);
    func_0038C750();
    for (j = 0; j < 32; j++) {
        if (D_L32_002A3E50[j] != 0) {
            func_L32_003B3A20(D_L32_002A3E50[j]);
        }
    }
    func_003A9440(6, func_00389598(D_L32_001DED34));
    func_003A9440(0x42, 0x8000000048UL);
    for (j = 0; j < 32; j++) {
        if (D_L32_002A3E50[j] != 0) {
            func_L32_003B3D88(D_L32_002A3E50[j]);
        }
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L32_003A44A8 */

INCLUDE_ASM("asm/levels", func_L32_003A45D8);

/* localdecomp:start func_L32_003A4F18 */
__asm__(".extern D_L32_001DE970, 4");
__asm__(".extern D_L32_001DE980, 4");
__asm__(".extern D_L32_001DE94C, 4");
__asm__(".extern D_L32_001DE98C, 4");
__asm__(".extern D_L32_001DE8B4, 4");
__asm__(".extern D_L32_001DE8B8, 4");
__asm__(".extern D_L32_001DE8BC, 4");
__asm__(".extern D_L32_001DE8CC, 4");
__asm__(".extern D_L32_001DEB30, 2");
__asm__(".extern D_L32_001DFE28, 16");
__asm__(".extern D_L32_001DFF00, 16");
extern s32 D_L32_001DE970;
extern s32 D_L32_001DE980;
extern f32 D_L32_001DE94C;
extern s32 D_L32_001DE98C;
extern f32 D_L32_001DE8B4;
extern s32 D_L32_001DE8B8;
extern s32 D_L32_001DE8BC;
extern s32 D_L32_001DE8CC;
extern u8 D_L32_001DEB30[2];
extern u8 *D_L32_001DFE28;
extern u8 *D_L32_001DFF00;
extern s32 D_L32_001E2320;
__asm__(".extern D_L32_001E2320, 16");
extern s32 D_L32_001E2330;
extern u8 D_00142660[];
extern u8 *D_L32_002A3E50[];
extern void func_L31_00346998(void *, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L30_0034CCD0(void *, f32 *, f32 *, f32 *, f32 *);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L32_003A7F48(void);

typedef struct {
    f32 x, y, z, w;
} V_003A4F18 __attribute__((aligned(16)));

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x4A];
    u8 b80[0x54];
    s32 fD4;
    u8 padD8[0x18];
    s32 fF0, fF4, fF8, fFC, f100, f104, f108, f10C, f110, f114, f118, f11C;
    s32 f120, f124, f128, f12C, f130, f134, f138, f13C;
    V_003A4F18 v140;
    u8 pad150[0x10];
    u8 *m160;
    u8 *m164;
    u8 pad168[4];
    u8 *p16C[2];
    f32 f174;
    f32 f178;
    f32 f17C;
    f32 f180;
    u8 *m184;
    s32 f188;
    s32 f18C;
    s32 f190;
} S_003A4F18;

void func_L32_003A4F18(u8 *o) {
    S_003A4F18 *s = *(S_003A4F18 **)(o + 0x68);
    s32 i;
    u8 *m;

    for (i = 0; i < 3; i++) {
        (&D_L32_001DE980)[i] = (&D_L32_001DE970)[i];
    }
    if (D_00142660[0x77] & 8) {
        for (i = 0; i < 3; i++) {
            (&D_L32_001DE980)[i] -= 2;
        }
    }
    if (D_00142660[0x77] & 0x10) {
        for (i = 0; i < 3; i++) {
            (&D_L32_001DE980)[i] -= 2;
        }
    }
    if (D_00142660[0x77] & 0x20) {
        for (i = 0; i < 3; i++) {
            (&D_L32_001DE980)[i] -= 4;
        }
    }
    s->h34 = (&D_L32_001DE980)[0] + (&D_L32_001DE980)[1] + (&D_L32_001DE980)[2];
    s->f30 = s->h34;
    func_L31_00346998(o, s->b80);
    qzero(&s->v140);
    s->fF0 = 1;
    s->fF8 = 0;
    s->fFC = 0;
    s->f100 = 1;
    s->f108 = 0;
    s->f10C = 0;
    s->f110 = 0;
    s->f118 = -1;
    s->f18C = 0;
    s->f190 = 0;
    s->f128 = 0;
    s->f114 = -1;
    s->f11C = 0;
    s->f120 = 0;
    s->f134 = 0;
    s->f138 = 0;
    s->f13C = 0;
    s->fF4 = -3;
    s->f124 = -1;
    s->f12C = 1;
    s->v140.z = D_L32_001DE94C;
    s->m160 = 0;
    for (m = D_L32_001DFE28; m != 0; m = *(u8 **)(m + 0x28)) {
        if (*(s16 *)(m + 0xAA) == 0x1B55) {
            s->m160 = m;
        }
    }
    s->m164 = 0;
    {
        u8 *m2;
        for (m2 = D_L32_001DFE28; m2 != 0; m2 = *(u8 **)(m2 + 0x28)) {
            if (*(s16 *)(m2 + 0xAA) == 0x184C) {
                s->m164 = m2;
            }
        }
    }
    for (i = 0; i < 2; i++) {
        s->p16C[i] = func_003C24B0(0x1C1B, 0x80);
        *(u16 *)(s->p16C[i] + 0x34) |= 0x41;
        *(u16 *)(s->p16C[i] + 0x34) &= 0xEFFF;
        *(s32 *)(s->p16C[i] + 0x98) = 0;
        func_L01_004AA7E8(s->p16C[i], 1);
        *(u16 *)(s->p16C[i] + 0x32) = 0x40;
    }
    s->f174 = func_003C3D30(o + 0x10, 0, 0, 0.5f);
    if (s->fD4 != -1) {
        func_L30_0034CCD0(D_L32_001DFF00 + (s->fD4 << 7), &s->f178, &s->f180, 0, 0);
        s->f17C = (s->f178 + s->f180) * 0.5f;
    }
    {
        u8 *m3;
        for (m3 = D_L32_001DFE28; m3 != 0; m3 = *(u8 **)(m3 + 0x28)) {
            if (*(s16 *)(m3 + 0xAA) == 0x1E17) {
                s->m184 = m3;
            }
        }
    }
    s->f188 = 0;
    D_L32_001DEB30[1] = 0;
    D_L32_001DEB30[0] = 0;
    if (D_L32_001DE98C == 0) {
        func_L03_0034B218((u8 *)&D_L32_001E2320, D_L32_001DE8B8, D_L32_001DE8BC, D_L32_001DE8B4, D_L32_001DE8CC, func_L32_003A7F48);
        D_L32_001E2330 = 0x44;
    }
    {
        s32 k;
        for (k = 31; k >= 0; k--) {
            D_L32_002A3E50[k] = 0;
        }
    }
}
/* localdecomp:end func_L32_003A4F18 */

INCLUDE_ASM("asm/levels", func_L32_003A52A8);

/* localdecomp:start func_L32_003A5720 */
extern s32 D_001DD6A4;
extern void func_L01_00404A10(void (*)(void *), void *);
void func_L32_003554C0(void *);

typedef struct {
    u8 pad0[0xF4];
    s32 fF4;
    u8 padF8[0x24];
    s32 f11C;
    u8 pad120[0x44];
    u8 *f164;
} S_003A5720;

void func_L32_003A5720(void *arg0) {
    S_003A5720 *p = *(S_003A5720 **)((u8 *)arg0 + 0x68);
    u8 *pv;
    f32 f;

    switch (p->fF4) {
    case -3:
        if (*(u8 *)((u8 *)arg0 + 0x20) == 0x13) {
            break;
        }
        p->f11C++;
        if (D_001DD6A4 < p->f11C) {
            p->f11C = D_001DD6A4;
        }
        *(f32 *)(*(u8 **)(p->f164 + 0x68) + 0xD0) = (f32)p->f11C / (f32)D_001DD6A4;
        func_L01_00404A10(func_L32_003554C0, p->f164);
        break;
    case 1:
        pv = *(u8 **)(p->f164 + 0x68);
        f = *(f32 *)(pv + 0xD0);
        if (0.0f < f) {
            *(f32 *)(pv + 0xD0) = f - 1.0f / (f32)D_001DD6A4;
            pv = *(u8 **)(p->f164 + 0x68);
            if (*(f32 *)(pv + 0xD0) < 0.0f) {
                *(f32 *)(pv + 0xD0) = 0.0f;
            }
            func_L01_00404A10(func_L32_003554C0, p->f164);
        }
        break;
    case -2:
    case -1:
    case 0:
    case 2:
        break;
    }
}
/* localdecomp:end func_L32_003A5720 */

/* localdecomp:start func_L32_003A5850 */
extern u8 D_L32_001DE964;
extern f32 D_L32_001DEAE0[][3] __attribute__((section(".sdata")));
extern f32 D_L32_001DEB08[][3] __attribute__((section(".sdata")));
extern f32 D_1A4C60 __attribute__((section(".data")));
__asm__(".extern D_L32_001DE964, 1");
__asm__(".extern D_L32_001DEAE0, 0");
__asm__(".extern D_L32_001DEB08, 0");
extern void func_L30_00358210(u8 *);
extern f32 func_003824E0(f32, f32);
void func_L32_003A52A8(void *, s32);

typedef struct {
    u8 padE0[0xF0];
    s32 fF0;
    s32 fF4;
    s32 fF8;
    s32 fFC;
    s32 f100;
    u8 pad104[0x10];
    s32 f114;
    u8 pad118[4];
    s32 f11C;
    u8 pad120[0xC];
    s32 f12C;
    u8 pad130[4];
    s32 f134;
    s32 f138;
    u8 pad13C[0x28];
    u8 *f164;
    s32 f168;
    u8 pad16C[0xC];
    f32 f178;
    f32 f17C;
} S_003A5850;

void func_L32_003A5850(void *arg0) {
    S_003A5850 *p = *(S_003A5850 **)((u8 *)arg0 + 0x68);
    s32 found = 0;
    f32 sum;
    f32 r;
    f32 v;
    s32 i;

    D_L32_001DE964 = 0;
    sum = 0.0f;
    p->f114 = p->fF4;
    if (p->fF4 == -3 && p->f164 != 0) {
        func_L30_00358210(p->f164);
    }
    if (p->f114 == -1 || p->f168 != 0) {
        p->fF4 = 1;
    } else {
        for (i = 0; i < 3; i++) {
            if (p->f114 != i) {
                sum += D_L32_001DEAE0[p->fF8][i];
            } else {
                sum += D_L32_001DEB08[p->fF8][i];
            }
        }
        r = func_003824E0(0.0f, sum - 0.001f);
        for (i = 0; !found && i < 3; i++) {
            if (p->f114 != i) {
                v = D_L32_001DEAE0[p->fF8][i];
            } else {
                v = D_L32_001DEB08[p->fF8][i];
            }
            if (r < v) {
                p->fF4 = i;
                found = 1;
            } else {
                r -= v;
            }
        }
    }
    switch (p->fF4) {
    case 1:
        p->f11C = 0;
        if (p->f114 == -1) {
            func_L32_003A52A8(arg0, 0xE);
        } else if (p->f134 != 0 && p->f138 != 0 && p->fF0 != 0) {
            func_L32_003A52A8(arg0, p->f100 != 0 ? 16 : 15);
        } else if (p->fFC == 0 || p->f12C == 0) {
            func_L32_003A52A8(arg0, 0x12);
        } else if ((u8)(*(u8 *)((u8 *)arg0 + 0x20) - 4) < 2 || p->fF0 == 0) {
            func_L32_003A52A8(arg0, 7);
        } else {
            func_L32_003A52A8(arg0, 0xE);
        }
        break;
    case 0:
    case 2:
        if (p->fFC != 0 ? fabs_asm(*(f32 *)((u8 *)arg0 + 0x10) - D_1A4C60) < fabs_asm(*(f32 *)((u8 *)arg0 + 0x10) - p->f17C)
                        : fabs_asm(*(f32 *)((u8 *)arg0 + 0x10) - p->f17C) < fabs_asm(p->f178 - p->f17C) * 0.5f) {
            func_L32_003A52A8(arg0, 7);
        } else {
            func_L32_003A52A8(arg0, 0xD);
        }
        break;
    }
}
/* localdecomp:end func_L32_003A5850 */
