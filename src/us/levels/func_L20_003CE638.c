#include "common.h"

/* NTSC-U counterpart of func_L20_003D0090 (src/levels/20_final_boss/L20_003CFBF0.c) */
#include "vu0.h"
extern u8 D_L20_001E2E00_003CE638[];
extern f32 func_0037E250(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00402498(void (*)(void *), void *);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L20_003CE638 */
#include "vu0.h"

extern u8 D_001A30B0[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern vu0_v4 D_001A4CB0;
extern u8 D_L20_00220258_003CE638[];
extern s32 D_L20_001DEBBC;
__asm__(".extern D_L20_001DEBBC, 4");

extern s32 func_L01_004A72A8(s32, s32, u8 *, s32);
extern void func_0039FB08(s32);
extern void func_003BD360(void *);
extern f32 func_00389380(f32, f32);
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_0037E2A8(void);
extern s32 func_003883C8(void *);
extern void func_L01_00402498(void (*)(void *), void *);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_L03_004307B8(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern u8 *func_L01_0046FE70(void *, void *, s32, f32);
extern void func_L01_004026A0(void *, void *);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_L20_003CCB38(u8 *);
extern void func_L20_003CD458(u8 *);
extern void func_L20_003CE428(u8 *);
extern void func_L20_003CE198(u8 *a0);
extern void func_L20_003CD6B0(u8 *);
extern void func_L20_003CE0B0(u8 *);
extern void func_00388830(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);

void func_L20_003CE638(u8 *obj)
{
    u8 *v;
    s32 h;
    u8 *e;
    s32 i;
    s32 i2;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;

    (*(u16 *)(obj + 0x96))++;
    v = *(u8 **)(obj + 0x68);
    {
        s32 t = *(s32 *)(v + 0xD70);
        if (t == -1 || (e = D_001A30B0 + (t << 7), *(u8 **)(e + 0xDC) != obj) || e[0xD0] == 0) {
            *(s32 *)(v + 0xD70) = func_L01_004A72A8(0xB, 4, obj, 0x1AFD);
        }
    }
    if (*(u16 *)(obj + 0x96) > 360 && D_001D545C != 0x45) {
        h = *(s32 *)(v + 0xD70);
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == obj && e[0xD0] != 0) {
                func_0039FB08(h);
            }
        }
        *(s32 *)(v + 0xD70) = -1;
        if (*(u8 **)(v + 0xD74) != 0) {
            func_003BD360(*(u8 **)(v + 0xD74));
        }
        func_003BD360(obj);
        return;
    }

    *(f32 *)(v + 0x0) = func_00389380(*(f32 *)(v + 0x0), 0.02908882312476635f);
    *(f32 *)(v + 0x4) = func_00389380(*(f32 *)(v + 0x4), 0.0872664675f);

    switch (obj[0x20]) {
    case 0: {
        u8 *p;
        vu0_v4 *pv;
        s32 j;

        p = func_003BCFB0(0x1DA0, 0x40);
        *(u8 **)(v + 0xD74) = p;
        if (p != 0) {
            *(vu0_q *)(p + 0xF0) = *(vu0_q *)(obj + 0xF0);
            *(vu0_q *)(*(u8 **)(v + 0xD74) + 0x10) = *(vu0_q *)(obj + 0x10);
            (*(u8 **)(v + 0xD74))[0x30] = 0xFF;
            *(u8 **)(*(u8 **)(v + 0xD74) + 0xB8) = obj;
        }
        *(vu0_v4 *)(v + 0xD50) = D_001A4CB0;
        vec_sub_ba(&a, obj + 0x10, &D_001A4CB0);
        func_00388830(&a, &a, -25.0f);
        vec_add_ab(v + 0xD50, &a, v + 0xD50);
        for (j = 0; j < 12; j++) {
            ((f32 *)(v + 0xD10))[j] = func_0037E250(0.014544411562383175f, 0.0436332338f);
            *(f32 *)(v + 0x2C) = 2.0f;
            b.x = func_00388960(*(f32 *)(obj + 0xF8));
            b.y = func_00388978(*(f32 *)(obj + 0xF8));
            b.z = 0.0f;
            vec_sub_ba(&c, &D_L20_001E2E00_003CE638, obj + 0x10);
            func_00388830(&c, &c, 1.0f);
            pv = (vu0_v4 *)(v + 0xC50) + j;
            func_00388758(pv, &b, &c);
            func_00388830(pv, pv, *(f32 *)(v + 0x2C));
            func_00389158(pv, pv, &c, func_0037E2A8());
        }
        func_L20_003CCB38(obj);
        *(s16 *)(v + 0x20) = *(u16 *)(v + 0x1C);
        obj[0x20] = 2;
        *(f32 *)(v + 0xC) = 2.5f;
        *(s16 *)(v + 0x18) = 1;
        *(s16 *)(v + 0x1A) = 1;
        break;
    }
    case 2:
        if (func_003883C8(v + 0x20)) {
            obj[0x20] = 3;
            *(s16 *)(v + 0x20) = *(u16 *)(v + 0x14);
            func_L20_003CCB38(obj);
        }
        break;
    case 3:
        if (func_003883C8(v + 0x20)) {
            if (*(s16 *)(v + 0x16) != 0) {
                obj[0x20] = 2;
                *(s16 *)(v + 0x20) = 5;
            } else {
                *(s16 *)(v + 0x20) = 5;
            }
        } else if (*(s16 *)(v + 0x22) == 0) {
            func_L20_003CCB38(obj);
        }
        break;
    }

    switch (obj[0x95]) {
    case 0:
        if (*(u16 *)(obj + 0x96) > 3) {
            obj[0x95] = 2;
            *(vu0_q *)(v + 0xD60) = *(vu0_q *)(obj + 0x10);
            *(vu0_v4 *)(v + 0xD50) = D_001A4CB0;
            vec_sub_ba(&a, obj + 0x10, &D_001A4CB0);
            a.z = 0.0f;
            func_00388830(&a, &a, 25.0f);
            vec_add_ab(v + 0xD50, &a, v + 0xD50);
        }
        break;
    case 2: {
        s32 k;
        s32 n;
        u8 *p;

        func_L01_00402498(func_L20_003CE428, obj);
        *(f32 *)(v + 0xD4C) += 0.166666672f;
        *(f32 *)(v + 0xD44) = 1.0f;
        if (*(f32 *)(v + 0xD4C) > 1.0f) {
            *(f32 *)(v + 0xD4C) = 1.0f;
        }
        *(f32 *)(v + 0xD48) += 0.0333333351f;
        if (*(f32 *)(v + 0xD48) > 1.0f) {
            *(f32 *)(v + 0xD48) = 1.0f;
        }
        for (k = 0; k < 3; k++) {
            u8 *g = D_L20_00220258_003CE638;

            func_0037E2F0(&a, 0.05000000447034836f, 0.0666666701f);
            if (a.z < 0.0f) {
                a.z = -a.z;
            }
            n = func_L01_00440918(2.0f, 3.0f);
            p = func_L01_0046DCB8(v + 0xD60, &a, 0x14, 0, n, 0x7F, 0x7F, func_0037E250(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.0f, 6);
            if (p != 0) {
                p[3] = 0x44;
                p[2] = **(u8 **)(g + 0xD4);
            }
            n = func_L01_00440918(2.0f, 3.0f);
            p = func_L01_0046DCB8(v + 0xD60, &a, 0x14, 0x7C0030, n, 0x30, 0x30, func_0037E250(0.8f, 1.25f) * 210000.0f * 1.25f, 4200.0f, 0.0f, 0);
            if (p != 0) {
                p[3] = 0x44;
                p[2] = **(u8 **)(g + 0xD4);
            }
        }
        func_L03_004307B8(obj, obj + 0x10, v + 0xD60, 1, 0, 1, 0, 45.0f, 1.0f);
        break;
    }
    }

    for (i = 0; i < 1; i++) {
        u8 *p;

        func_0037E2F0(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, obj + 0x10);
        vec_sub_ba(&b, obj + 0x10, &a);
        func_00388830(&b, &b, 0.0125000011f);
        p = func_L01_0046FE70(&a, &b, 0xF, 3.0f);
        if (p != 0) {
            *(u32 *)(p + 4) = 0xFFFF2020;
        }
    }
    for (i2 = 0; i2 < 1; i2++) {
        u8 *p;

        func_0037E2F0(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, obj + 0x10);
        vec_sub_ba(&b, obj + 0x10, &a);
        func_00388830(&b, &b, 0.0125000011f);
        p = func_L01_0046FE70(&a, &b, 0xF, 1.5f);
        if (p != 0) {
            *(u32 *)(p + 4) = 0x7FFFFFFF;
        }
    }

    func_L01_004026A0(func_L20_003CE0B0, obj);
    func_L01_004026A0(func_L20_003CE198, obj);
    if (*(s16 *)(v + 0x22) != 0) {
        func_L20_003CD458(obj);
        if (D_L20_001DEBBC < *(s16 *)(v + 0x22)) {
            func_L01_004026A0(func_L20_003CD6B0, obj);
        }
    }
    if (*(u8 **)(v + 0xD74) != 0) {
        vec_sub_ba(&c, v + 0xD50, obj + 0x10);
        *(f32 *)(*(u8 **)(v + 0xD74) + 0xF4) = -func_00388A28(func_003887A0(&c), c.z);
        *(f32 *)(*(u8 **)(v + 0xD74) + 0xF8) = func_00388A28(c.x, c.y);
    }
}
/* localdecomp:end func_L20_003CE638 */
