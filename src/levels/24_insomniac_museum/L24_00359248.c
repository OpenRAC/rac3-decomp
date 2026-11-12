#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_00359248);

/* localdecomp:start func_L24_00359528 */
typedef struct {
    s32 f0;
    f32 f4;
} S_359528;
extern u8 D_L24_001A4C60[];
extern u8 *D_L24_001D52FC;
extern f32 func_L24_003F6780(void *, void *);
extern void func_L24_00437D98(s32, s32, s32, s32, s32, s32, s32);
extern void func_L24_0042BAC0(void *, s32, s32);
extern void func_L24_0042B760(void *, s32, s32, s32);

void func_L24_00359528(u8 *a0) {
    S_359528 *p = *(S_359528 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        p->f0 = 0;
        func_L24_0042BAC0(a0, 1, -1);
        break;
    case 1:
        if (func_L24_003F6780(D_L24_001A4C60, a0 + 0x10) <= p->f4) {
            func_L24_00437D98(0, 1, 0x16BE, 1, 0, 0, 0);
            if (*(u32 *)(D_L24_001D52FC + 0x1A4) & 0x10) {
                p->f0++;
                if (p->f0 >= *(u8 *)(*(u8 **)(a0 + 0x24) + 0xC)) {
                    p->f0 = 0;
                }
                func_L24_0042BAC0(a0, 2, -1);
            }
        }
        break;
    case 2:
        if (a0[0x43] != p->f0) {
            func_L24_0042B760(a0, p->f0, 0, 10);
        }
        func_L24_0042BAC0(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L24_00359528 */

INCLUDE_ASM("asm/levels", func_L24_00359650);

INCLUDE_ASM("asm/levels", func_L24_00359E30);

/* localdecomp:start func_L24_00359FE0 */
extern u8 D_L24_001E2200[];
extern f32 func_L24_003F67B0(void *, void *);
extern void func_L24_0042DDF0(void *);
extern void func_L24_00359E30(void *);
extern void func_L24_0042D6F8(void *, void *, s32, void *, f32);
extern void func_L24_0035A908(void *, s32);
extern void func_L24_0042BAC0(void *, s32, s32);
extern void func_L24_0042B760(void *, s32, s32, s32);
extern void func_L24_0042ADB8(void *, s32, s32);
extern void func_L24_00420080(void *);
extern s32 func_L24_004387B8(void *, void *, s32, s32, s32);
extern void func_L24_0035A248(u8 *);
extern s32 func_L24_00438098(void *, void *, s32);
extern void func_L24_0043C8B8(void *, s32);
extern f32 func_L24_0035AA18(void *);
extern void func_L24_0043C980(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L24_00359FE0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x31] != 0) {
        if (func_L24_003F67B0(D_L24_001E2200, a0 + 0x10) < 576.0f) {
            func_L24_0042DDF0(a0);
            a0[0x6F] = 0x16;
        }
    }
    if (a0[0x95] == 0 && a0[0x20] == 0) {
        func_L24_00359E30(a0);
    }
    if (*(f32 *)(a0 + 0x18) <= *(f32 *)(p + 0xB0)) {
        func_L24_0042D6F8(a0, a0, 0x10000, a0 + 0x10, (f32)*(s16 *)(p + 0x34));
    }
    if (a0[0xBC] != 0 && a0[0x95] != 5 && 0.0f < *(f32 *)(p + 0x30)) {
        func_L24_0035A908(a0, 0);
        func_L24_0042BAC0(a0, 0xC, 5);
        if (a0[0x43] != 4) {
            func_L24_0042B760(a0, 4, 0, 0xC);
        }
        *(f32 *)(a0 + 0x48) = 0.75f;
    }
    if (p[0x5E] != 0) {
        func_L24_0042ADB8(a0, 0, 3);
        func_L24_00420080(a0);
        return;
    }
    if (func_L24_004387B8(a0, p + 0x70, 0, 0, 0) != 0) {
        func_L24_0035A248(a0);
        func_L24_0035A908(a0, 1);
    }
    func_L24_00438098(a0, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_L24_0043C8B8(a0, 5);
        func_L24_0043C980(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 3, 0, 0, 0, func_L24_0035AA18(a0), 10.0f, 1.0f);
    } else {
        func_L24_0043C8B8(a0, 3);
        func_L24_0043C980(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 1, 0, 0, 0, func_L24_0035AA18(a0), 10.0f, 1.0f);
    }
}
/* localdecomp:end func_L24_00359FE0 */

/* localdecomp:start func_L24_0035A248 */
__asm__(".extern D_L24_001DF558, 4");
extern u16 *D_L24_0021C360[];
extern u8 *D_L24_001DF51C;
extern s32 D_L24_001DF558;

void func_L24_0035A248(u8 *arg0)
{
    u16 *p;

    if (arg0[0x21] == 0xFF)
        return;
    p = D_L24_0021C360[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L24_001DF558 && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L24_0021C360[arg0[0x21]])) {
        u8 *e = D_L24_001DF51C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(arg0 + 0xAA)) {
            *(u8 *)(*(u8 **)(e + 0x68) + 0x199) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L24_0035A248 */

/* localdecomp:start func_L24_0035A300 */
__asm__(".extern D_L24_001DF558, 4");
extern u16 *D_L24_0021C360[];
extern u8 *D_L24_001DF51C;
extern s32 D_L24_001DF558;
s32 func_00382498(s32, s32);
void func_L24_0035A300(u8 *arg0)
{
    u16 *p;
    s32 n;

    if (arg0[0x21] == 0xFF)
        return;
    n = 0;
    p = D_L24_0021C360[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_L24_001DF558 && p != 0 &&
           ((p != 0 && (s16)p[-1] >= 0) || p == D_L24_0021C360[arg0[0x21]])) {
        u8 *e = D_L24_001DF51C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(arg0 + 0xAA)) {
            u8 t = e[0x20];
            if (t == 0xFE) {
            } else if (t == 0xFD) {
            } else {
                u8 *s = *(u8 **)(e + 0x68);
                s32 v;
                if (*(s16 *)(s + 0x222) != 0)
                    return;
                v = (n * 5 + 2) / 6;
                *(s16 *)(s + 0x220) = v;
                *(s16 *)(s + 0x222) = v;
                *(s16 *)(s + 0x224) = v;
                n += func_00382498(2, 4);
            }
        }
        p++;
    }
}
/* localdecomp:end func_L24_0035A300 */

/* localdecomp:start func_L24_0035A438 */
void func_L24_0035A438(int *a0) {
    short *p = (short *)a0[0x68/4];
    p[0x222/2] = p[0x220/2];
    p[0x224/2] = p[0x220/2];
}
/* localdecomp:end func_L24_0035A438 */
