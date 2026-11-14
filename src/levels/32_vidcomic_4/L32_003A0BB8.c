#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L32_003A0BB8 */
extern f32 D_L32_001DE6D4;
extern f32 D_L32_001DE6C8;
void func_L32_003A25B0(void *, f32, f32);
void func_L32_003A2508(void *, s32, f32);
void func_L32_003A14C8(void *, s32);

void func_L32_003A0BB8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L32_003A25B0(arg0, D_L32_001DE6D4, D_L32_001DE6C8);
    func_L32_003A2508(arg0, 0, 0.0f);
    if (p[0x228] != 0) {
        func_L32_003A14C8(arg0, 1);
    }
}
/* localdecomp:end func_L32_003A0BB8 */

INCLUDE_ASM("asm/levels", func_L32_003A0C18);

INCLUDE_ASM("asm/levels", func_L32_003A0E20);

INCLUDE_ASM("asm/levels", func_L32_003A11C8);

INCLUDE_ASM("asm/levels", func_L32_003A14C8);

/* localdecomp:start func_L32_003A1670 */
void func_L01_004450F0(s32, s32, s32);

void func_L32_003A1670(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L01_004450F0((s32) arg0, arg1, -1);
    if (*(u8 *)((u8 *)arg0 + 0x20) == 3) {
        *(s8 *)(p + 0x229) = 1;
        *(s8 *)(p + 0x228) = 0;
        *(s32 *)(p + 0x21C) = 4;
    }
}
/* localdecomp:end func_L32_003A1670 */

INCLUDE_ASM("asm/levels", func_L32_003A16C8);

INCLUDE_ASM("asm/levels", func_L32_003A1BF0);

INCLUDE_ASM("asm/levels", func_L32_003A1D30);

INCLUDE_ASM("asm/levels", func_L32_003A1E58);

INCLUDE_ASM("asm/levels", func_L32_003A20C8);

/* localdecomp:start func_L32_003A21E0 */
extern s32 D_L32_001DE6F8;
extern f32 D_L32_001DE614;
extern u8 *D_L32_001DFF00;
__asm__(".extern D_L32_001DE6F8, 4");
__asm__(".extern D_L32_001DE614, 4");
__asm__(".extern D_L32_001DFF00, 16");
s32 func_L01_004561B8(void *);
f32 func_003C4088(f32, f32, f32);
void func_L32_003A1BF0(void *, void *, f32, f32);
void func_L32_003A1670(void *, s32);

void func_L32_003A21E0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 f20;
    f32 r;
    s32 v;
    u8 b;

    if (func_L01_004561B8(arg0) != 0) {
        *(s32 *)(p + 0x78) = 0;
    }
    v = *(s32 *)(p + 0x78);
    f20 = (f32) (v + 1) / (f32) D_L32_001DE6F8;
    *(s32 *)(p + 0x78) = v + 1;
    if (f20 > 1.0f) {
        f20 = 1.0f;
    }
    r = func_003C4088(D_L32_001DE614, 0.0f, f20);
    if (*(s16 *)(p + 0x22A) != -1) {
        func_L32_003A1BF0(arg0, D_L32_001DFF00 + ((*(s32 *)(p + (*(s16 *)(p + 0x22A) << 2) + 0x90)) << 7) + 0x30, r, 1.0f - f20);
    } else {
        func_L32_003A1BF0(arg0, (u8 *)arg0 + 0x10, r, 1.0f);
    }
    b = *(u8 *)(p + 0x229);
    if (b != 0) {
        func_L32_003A1670(arg0, 2);
    }
}
/* localdecomp:end func_L32_003A21E0 */

INCLUDE_ASM("asm/levels", func_L32_003A22E0);

/* localdecomp:start func_L32_003A23C8 */
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L32_003A1670(void *, s32);
extern void func_L32_003A2468(void *, s32);
extern u8 D_1A4C60[];
extern u8 *D_L32_001DFE1C;

void func_L32_003A23C8(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    s32 i;
    s32 none;
    s32 *p;
    u8 *base;

    if (func_00382380(D_1A4C60, *(s32 *)(v + 0xEC), 0)) {
        func_L32_003A2468(arg0, 1);
        p = (s32 *)(v + 0xE0);
        none = -1;
        for (i = 1; i >= 0; i--) {
            base = D_L32_001DFE1C;
            if (*p != none) {
                func_L01_00456230(base + (*p << 8), 1);
            }
            p++;
        }
        func_L32_003A1670(arg0, 2);
    }
}
/* localdecomp:end func_L32_003A23C8 */

INCLUDE_ASM("asm/levels", func_L32_003A2468);

INCLUDE_ASM("asm/levels", func_L32_003A2508);

INCLUDE_ASM("asm/levels", func_L32_003A25B0);

INCLUDE_ASM("asm/levels", func_L32_003A2830);

INCLUDE_ASM("asm/levels", func_L32_003A2A38);

INCLUDE_ASM("asm/levels", func_L32_003A2C30);

INCLUDE_ASM("asm/levels", func_L32_003A2E30);

INCLUDE_ASM("asm/levels", func_L32_003A3038);

INCLUDE_ASM("asm/levels", func_L32_003A3310);

INCLUDE_ASM("asm/levels", func_L32_003A3420);

INCLUDE_ASM("asm/levels", func_L32_003A3888);

INCLUDE_ASM("asm/levels", func_L32_003A3CA8);

/* localdecomp:start func_L32_003A3E70 */
void func_L32_003A3038(void *);
void func_L32_003A3888(void *, s32);
extern s32 D_L32_001DE6E0;
extern s32 D_L32_001DE6E4;

void func_L32_003A3E70(void *arg0) {
    if ((D_L32_001DE6E4 - (*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x78))) < D_L32_001DE6E0) {
        func_L32_003A3888(arg0, D_L32_001DE6E0);
    }
    func_L32_003A3038(arg0);
}
/* localdecomp:end func_L32_003A3E70 */

INCLUDE_ASM("asm/levels", func_L32_003A3EC8);

INCLUDE_ASM("asm/levels", func_L32_003A40B0);

INCLUDE_ASM("asm/levels", func_L32_003A4270);

INCLUDE_ASM("asm/levels", func_L32_003A4360);

INCLUDE_ASM("asm/levels", func_L32_003A44A8);

INCLUDE_ASM("asm/levels", func_L32_003A45D8);

INCLUDE_ASM("asm/levels", func_L32_003A4F18);

INCLUDE_ASM("asm/levels", func_L32_003A52A8);

INCLUDE_ASM("asm/levels", func_L32_003A5720);

INCLUDE_ASM("asm/levels", func_L32_003A5850);

/* localdecomp:start func_L32_003A5B20 */
extern f32 D_L32_001DE9D4;
extern f32 D_L32_001DEA88;
extern f32 D_L32_001DEA50;
extern s32 func_L01_004561B8(void *);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A52A8(void *, s32);

void func_L32_003A5B20(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);

    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(s + 0x90) = 0;
    }
    *(s32 *)(s + 0x110) = func_L30_0034D1E8(a0, a0 + 0x10, s + 0x90, s + 0x140, D_L32_001DE9D4, D_L32_001DE9D4, D_L32_001DEA88, 0.0f, 0.0f, D_L32_001DEA50, 1, 1, 1, 0);
    if (a0[0x60] & 2) {
        func_L32_003A52A8(a0, a1);
    }
}
/* localdecomp:end func_L32_003A5B20 */

INCLUDE_ASM("asm/levels", func_L32_003A5BC0);

/* localdecomp:start func_L32_003A5C78 */
extern f32 D_001DE9D4_sda, D_001DEA88_sda, D_001DEA50_sda;
__asm__(".extern D_001DE9D4_sda, 4");
__asm__(".extern D_001DEA88_sda, 4");
__asm__(".extern D_001DEA50_sda, 4");
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L32_003A5850(void *);

void func_L32_003A5C78(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);

    *(s32 *)(d + 0x110) = func_L30_0034D1E8(obj, obj + 0x10, d + 0x90, d + 0x140, D_001DE9D4_sda, D_001DE9D4_sda, D_001DEA88_sda, 0.0f, 0.0f, D_001DEA50_sda, 1, 1, 1, 0);
    if (obj[0x60] & 2) {
        func_L32_003A5850(obj);
    }
}
/* localdecomp:end func_L32_003A5C78 */

INCLUDE_ASM("asm/levels", func_L32_003A5CF8);

INCLUDE_ASM("asm/levels", func_L32_003A5E48);

INCLUDE_ASM("asm/levels", func_L32_003A6168);

INCLUDE_ASM("asm/levels", func_L32_003A6308);

INCLUDE_ASM("asm/levels", func_L32_003A63E0);

INCLUDE_ASM("asm/levels", func_L32_003A6608);

INCLUDE_ASM("asm/levels", func_L32_003A66B0);

INCLUDE_ASM("asm/levels", func_L32_003A6920);

INCLUDE_ASM("asm/levels", func_L32_003A6D70);

INCLUDE_ASM("asm/levels", func_L32_003A70A0);

INCLUDE_ASM("asm/levels", func_L32_003A7210);

INCLUDE_ASM("asm/levels", func_L32_003A77D8);

INCLUDE_ASM("asm/levels", func_L32_003A7948);

INCLUDE_ASM("asm/levels", func_L32_003A7C88);

INCLUDE_ASM("asm/levels", func_L32_003A7E18);

INCLUDE_ASM("asm/levels", func_L32_003A7F48);
