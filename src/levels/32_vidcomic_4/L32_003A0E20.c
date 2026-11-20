#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L32_003A0E20 */
extern u8 D_1A4BE0[];
extern u8 *D_L32_001DFE1C;
extern s32 D_L32_001DE6F0;
extern f32 D_L32_001DE6B0;
__asm__(".extern D_L32_001DE6F0, 4");
__asm__(".extern D_L32_001DE6B0, 4");
extern s32 func_0038CAD0(void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L32_0034B5A8(void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C6FB0(void *, s32 *, s32 *, s32 *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern void func_L32_003A2468(void *, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L32_003A1670(void *, s32);
extern void *func_L01_00447490(void *, u32, s32);
extern void func_003C4A40(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003A52A0(s32, s32, void *);

void func_L32_003A0E20(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    vu0_v4 d;
    s32 a, b, c;
    f32 x0, x1, x2, x3;
    u8 **q;
    u8 **list;
    s32 *p;
    s32 i;
    u8 *r;
    f32 dmg;
    u8 *h;

    func_0038CAD0(v + 0x74);
    if (func_L30_0034D8D8((u8 *)arg0 + 0x10, 1.0f) != 0) {
        func_L32_0034B5A8(arg0);
    }
    func_L01_0044ABD0(arg0, v + 0x40);
    list = (u8 **)(v + 0x200);
    func_003C6FB0(arg0, &a, &b, &c);
    for (i = 0; i < 6; i++) {
        if (list[i] != 0) {
            func_L01_0043B9E8(list[i], a, b, c);
        }
    }
    if (*(f32 *)(*(u8 **)(*(u8 **)(v + 0x218) + 0x68) + (*(s32 *)(v + 0xE8) << 5) + 0x4C) >= 1.0f) {
        func_L30_0034CDC0(&x0, &x1, 0, &x2, 0.93f);
        func_L30_0034CDC0(0, 0, &x3, 0, 1.0f);
        {
            u8 *h = D_1A4BE0;
            if ((x0 >= *(f32 *)(h + 0x80) && *(f32 *)(h + 0xF0) < 0.0f) ||
                (x1 <= *(f32 *)(h + 0x80) && *(f32 *)(h + 0xF0) > 0.0f)) {
                u8 *g = D_1A4BE0;
                *(f32 *)(g + 0x100) -= *(f32 *)(g + 0xF0);
            }
        }
        {
            u8 *h = D_1A4BE0;
            if (x2 <= *(f32 *)(h + 0x88) && *(f32 *)(h + 0xF8) > 0.0f) {
                *(f32 *)(h + 0x108) -= *(f32 *)(h + 0xF8);
            }
        }
        h = D_1A4BE0;
        if (x3 >= *(f32 *)(h + 0x88) && *(f32 *)(h + 0xF8) < 0.0f) {
            func_L32_003A2468(arg0, 0);
            p = (s32 *)(v + 0xE0);
            for (i = 0; i < 2; i++) {
                if (p[i] != -1) {
                    func_L01_00456230(D_L32_001DFE1C + (p[i] << 8), 0);
                }
            }
            func_L32_003A1670(arg0, 3);
        }
    }
    for (i = 0; i < 6; i++) {
        q = &list[i];
        if (*q != 0) {
            r = func_L01_00447490(*q, 0x10000, 0);
            if (r != 0) {
                (*q)[0xA8] = 0xFF;
                dmg = *(f32 *)(r + 0x2C);
                if (dmg > 0.0f && *(u8 *)((u8 *)arg0 + 0x20) != 0x42 &&
                    *(s32 *)(v + 0x74) <= 0) {
                    *(s32 *)(v + 0x74) = D_L32_001DE6F0;
                    *(f32 *)v -= dmg;
                    func_003C4A40(arg0, v + 0x40);
                    func_0038CF68(&d, r + 0x10, D_L32_001DE6B0);
                    vec_add_ab(v + 0x60, v + 0x60, &d);
                    if (*(f32 *)v <= 0.0f) {
                        func_L32_003A1670(arg0, 0x42);
                        func_003A52A0(5, 0, arg0);
                    } else {
                        func_003A52A0(4, 0, arg0);
                        *(s16 *)(v + 0x22A) = *(s32 *)(v + 0xF0);
                    }
                }
            }
        }
    }
    h = D_1A4BE0;
    *(f32 *)((u8 *)arg0 + 0x14) = *(f32 *)(h + 0x84);
    *(s32 *)(v + 0x64) = 0;
}
/* localdecomp:end func_L32_003A0E20 */

/* localdecomp:start func_L32_003A11C8 */
extern void func_L31_00346998(void *, void *);
extern void func_003C2880(void *);
extern s32 func_L32_0039FE78(void *, s32, s32, f32 *, f32 *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0034B218(u8 *, s32, s32, f32, s32, void *);
extern void func_L32_003A16C8(void);
extern void func_L32_003A0370(void);
extern void func_L32_003A0C18(void);
extern u8 *D_L32_001DFE28;
extern s32 D_L32_001DE704;
__asm__(".extern D_L32_001DE704, 4");
extern s32 D_L32_001DE7AC;
__asm__(".extern D_L32_001DE7AC, 4");
extern s32 D_L32_001DE718;
__asm__(".extern D_L32_001DE718, 4");
extern s32 D_L32_001DE71C;
__asm__(".extern D_L32_001DE71C, 4");
extern f32 D_L32_001DE72C;
__asm__(".extern D_L32_001DE72C, 4");
extern s32 D_L32_001DE730;
__asm__(".extern D_L32_001DE730, 4");
extern s32 D_L32_001DE760;
__asm__(".extern D_L32_001DE760, 4");
extern s32 D_L32_001DE764;
__asm__(".extern D_L32_001DE764, 4");
extern f32 D_L32_001DE768;
__asm__(".extern D_L32_001DE768, 4");
extern s32 D_L32_001DE76C;
__asm__(".extern D_L32_001DE76C, 4");
extern f32 D_L32_001DE6A8;
__asm__(".extern D_L32_001DE6A8, 4");
extern u8 D_L32_001E2280[] __attribute__((section(".sdata")));
extern u8 D_L32_001E2240[] __attribute__((section(".sdata")));
extern u8 D_L32_001E2260[] __attribute__((section(".sdata")));
extern vu0_v4 D_L32_001E2230 __attribute__((section(".sdata")));

void func_L32_003A11C8(u8 *e) {
    u8 *v = *(u8 **)(e + 0x68);
    s32 i;
    s32 j;
    s32 *q;
    u8 *pos;
    u8 *m;

    v[0x49] = 0;
    v[0x48] = 0;
    *(s16 *)(v + 0x4C) = 4;
    *(s16 *)(v + 0x4E) = 0xF;
    *(f32 *)v = *(s16 *)(v + 4);
    v[0x47] = 0xFF;
    func_L31_00346998(e, v + 0x50);
    if (*(s32 *)(v + 0x80) == -1 || *(s32 *)(v + 0x90) == -1 || *(s32 *)(v + 0xA0) == -1 ||
        *(s32 *)(v + 0xC0) == -1 || *(s32 *)(v + 0xE8) == -1 || *(s32 *)(v + 0xEC) == -1 ||
        *(s32 *)(v + 0xF0) == -1) {
        func_003C2880(e);
        return;
    }
    pos = e + 0x10;
    q = (s32 *)(v + 0x200);
    {
        f32 *p100 = (f32 *)(v + 0x100);
        f32 *p110 = (f32 *)(v + 0x110);
        f32 *p120 = (f32 *)(v + 0x120);
        f32 *p130 = (f32 *)(v + 0x130);
        f32 *p140 = (f32 *)(v + 0x140);
        f32 *p150 = (f32 *)(v + 0x150);
        f32 *p160 = (f32 *)(v + 0x160);
        f32 *p170 = (f32 *)(v + 0x170);
        f32 *p180 = (f32 *)(v + 0x180);
        f32 *p190 = (f32 *)(v + 0x190);
        f32 *p1A0 = (f32 *)(v + 0x1A0);
        f32 *p1B0 = (f32 *)(v + 0x1B0);
        for (i = 0; i < 4; i++) {
            p100[i] = p110[i] = p120[i] = p130[i] = p140[i] = p150[i] = p160[i] = p170[i] = p180[i] = p190[i] = p1A0[i] = p1B0[i] = 0.0f;
        }
    }
    *(s32 *)(v + 0x1F4) = -1;
    qzero(v + 0x1C0);
    *(f32 *)(v + 0x1F0) = *(f32 *)(v + 0x1E4) = *(f32 *)(v + 0x1E0) = *(f32 *)(v + 0x1DC) = *(f32 *)(v + 0x1D0) = *(f32 *)(v + 0x1D4) = *(f32 *)(v + 0x1D8) = 0.0f;
    v[0x1F8] = 0;
    v[0x1F9] = 0;
    *(s16 *)(v + 0x1FA) = 0;
    for (j = 0; j < 6; j++) {
        q[j] = func_L32_0039FE78(pos, 0, 0x10, 0, 0);
    }
    for (m = D_L32_001DFE28; m != 0; m = *(u8 **)(m + 0x28)) {
        if (*(s16 *)(m + 0xAA) == 0x1B55) {
            *(u8 **)(v + 0x218) = m;
        }
    }
    *(s32 *)(v + 0x21C) = 4;
    v[0x229] = 1;
    *(s32 *)(v + 0x224) = 0;
    v[0x228] = 0;
    *(s16 *)(v + 0x22A) = 0;
    *(s32 *)(e + 0x98) = 0;
    *(u16 *)(e + 0x34) = (*(u16 *)(e + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(e, 1);
    if (D_L32_001DE704 == 0) {
        D_L32_001DE704 = 1;
        func_L03_0034B218(D_L32_001E2280, 2, 2, 1.0f, D_L32_001DE7AC, func_L32_003A16C8);
        func_L03_0034B218(D_L32_001E2240, D_L32_001DE718, D_L32_001DE71C, D_L32_001DE72C, D_L32_001DE730, func_L32_003A0370);
        func_L03_0034B218(D_L32_001E2260, D_L32_001DE760, D_L32_001DE764, D_L32_001DE768, D_L32_001DE76C, func_L32_003A0C18);
        qzero(&D_L32_001E2230);
        D_L32_001E2230.z = D_L32_001DE6A8;
    }
}
/* localdecomp:end func_L32_003A11C8 */
