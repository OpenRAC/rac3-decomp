#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L24_00359248);

/* localdecomp:start func_L24_00359528 */
typedef struct {
    s32 f0;
    f32 f4;
} S_359528;
extern u8 D_001A4C60[];
extern u8 *D_001D52FC;
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L24_00359528(u8 *a0) {
    S_359528 *p = *(S_359528 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        p->f0 = 0;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_0038CF38(D_001A4C60, a0 + 0x10) <= p->f4) {
            func_L01_00452560(0, 1, 0x16BE, 1, 0, 0, 0);
            if (*(u32 *)(D_001D52FC + 0x1A4) & 0x10) {
                p->f0++;
                if (p->f0 >= *(u8 *)(*(u8 **)(a0 + 0x24) + 0xC)) {
                    p->f0 = 0;
                }
                func_L01_004450F0(a0, 2, -1);
            }
        }
        break;
    case 2:
        if (a0[0x43] != p->f0) {
            func_003C3A10(a0, p->f0, 0, 10);
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    }
}
/* localdecomp:end func_L24_00359528 */

/* localdecomp:start func_L24_00359650 */
typedef int Q_00359650 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x160]; f32 x160; f32 x164; } S_00359650;
extern f32 D_L24_001DD5F0;
extern f32 D_L24_001DD5EC;
extern f32 D_L24_001DD60C;
extern f32 D_L24_001DD608;
extern f32 D_L24_001DD5BC;
extern f32 D_L24_001DD5D4;
extern f32 D_L24_001DD638;
extern s32 D_L24_001DD63C;
extern s32 D_L24_001DD640;
extern s32 D_L24_001DD644;
extern s32 D_L24_001DD648;
extern s32 D_L24_001DD64C;
__asm__(".extern D_L24_001DD5F0, 4");
__asm__(".extern D_L24_001DD5EC, 4");
__asm__(".extern D_L24_001DD60C, 4");
__asm__(".extern D_L24_001DD608, 4");
__asm__(".extern D_L24_001DD5BC, 4");
__asm__(".extern D_L24_001DD5D4, 4");
__asm__(".extern D_L24_001DD638, 4");
__asm__(".extern D_L24_001DD63C, 4");
__asm__(".extern D_L24_001DD640, 4");
__asm__(".extern D_L24_001DD644, 4");
__asm__(".extern D_L24_001DD648, 4");
__asm__(".extern D_L24_001DD64C, 4");
extern u8 D_L24_001D9A20[] __attribute__((section(".sdata")));
extern void func_L24_0035A908(void *, s32);
extern void func_L24_0035AB58(void *);
extern void func_L24_00359FE0(u8 *);
extern s32 func_L24_0035A470(u8 *);
extern s32 func_0038CB00(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_00454370(void *, void *);
extern void func_L02_003A5010(s32);
extern void func_L01_00315900(void *, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_L01_004395E0(void *);
extern s32 func_L24_003A4E60(void *, void *, void *, f32);
extern void func_L24_003A5360(void *, void *);
extern void func_L24_0035ABD0(void *, s32);
extern s32 func_L24_0035B0D0(void *);
extern s32 func_L24_0035ACB0(void *, s32, s32);
extern void func_L24_0035A970(void *, s32);
extern s32 func_L24_0035A580(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L24_0035B1F8(void *, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L24_00359650(u8 *obj)
{
    u8 *v = *(u8 **)(obj + 0x68);
    S_00359650 *sv = (S_00359650 *)v;
    s32 st;
    s32 r;
    f32 d[4] __attribute__((aligned(16)));
    f32 *o;

    func_L24_00359FE0(obj);
    st = obj[0x95];
    switch (st) {
    case 1:
        if (v[0x199] != 0 && v[0x198] != 2) {
            v[0x198] = 2;
            r = func_00382498(0, D_L24_001DD640);
            v[0x199] = 0;
            *(s16 *)(v + 0x194) = (r * 5 + 2) / 6;
        }
        if (func_L24_0035A470(obj) != 0 && func_0038CB00(v + 0x222) != 0 && v[0x198] != 2) {
            v[0x198] = 2;
            r = func_00382498(0, D_L24_001DD640);
            *(s16 *)(v + 0x194) = (r * 5 + 2) / 6;
        }
        break;
    case 2:
        if (func_L01_004561E0(obj) != 0) {
            v[0x198] = 1;
            r = func_00382498(0, D_L24_001DD640);
            *(s16 *)(v + 0x194) = ((D_L24_001DD644 + r) * 5 + 2) / 6;
        }
        if (func_L24_0035A470(obj) != 0 && func_0038CB00(v + 0x226) != 0 && v[0x198] != 3) {
            v[0x198] = 3;
            r = func_00382498(0, D_L24_001DD640);
            *(s16 *)(v + 0x194) = (r * 5 + 2) / 6;
        }
        break;
    case 3:
        if (func_L24_0035A470(obj) == 0 && v[0x198] != 2) {
            func_L24_0035A908(obj, 0);
            v[0x198] = 2;
            r = func_00382498(0, D_L24_001DD640);
            *(s16 *)(v + 0x194) = (r * 5 + 2) / 6;
        }
        break;
    case 4:
        if (func_L01_004561E0(obj) != 0) {
            v[0x198] = st;
        }
        r = func_L01_00454370(obj, v + 0x70);
        if (r & 1) {
            func_L02_003A5010((s32)obj);
            func_L01_00315900(obj, 0, 0);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x144) == 1 && func_L24_0035A470(obj) != 0) {
                v[0x198] = 3;
            } else {
                v[0x198] = 2;
            }
            r = func_00382498(0, D_L24_001DD63C);
            *(s16 *)(v + 0x194) = (r * 5 + 2) / 6;
        }
        break;
    }
    func_L24_0035AB58(obj);
    switch (obj[0x20]) {
    case 1:
        if (func_L01_0044E1B8(obj, 29.0f) != 0) {
            func_L24_0035ABD0(obj, 1);
            return;
        }
        break;
    case 2:
        if (func_L01_0044E1B8(obj, 89.0f) != 0) {
            func_L24_0035ABD0(obj, 1);
            return;
        }
        break;
    case 3:
        if ((func_L24_003A4E60(v + 0x1C0, obj, v + 0x160, -9999999827968.0f) & 0xA) != 0) {
            *(Q_00359650 *)(v + 0x160) = *(Q_00359650 *)(v + 0x150);
            sv->x160 += func_003824E0(-D_L24_001DD5F0, D_L24_001DD5F0);
            sv->x164 += func_003824E0(-D_L24_001DD5F0, D_L24_001DD5F0);
        }
        if (func_0038CF38(obj + 0x10, v + 0x160) < D_L24_001DD5EC) {
            func_L24_0035ABD0(obj, 1);
            return;
        }
        break;
    case 4:
        if ((func_L24_003A4E60(v + 0x1C0, obj, v + 0x160, -9999999827968.0f) & 0xA) != 0) {
            *(Q_00359650 *)(v + 0x160) = *(Q_00359650 *)(v + 0x150);
            sv->x160 += func_003824E0(-D_L24_001DD60C, D_L24_001DD60C);
            sv->x164 += func_003824E0(-D_L24_001DD60C, D_L24_001DD60C);
        }
        if (func_0038CF38(obj + 0x10, v + 0x160) < D_L24_001DD608) {
            func_L24_0035ABD0(obj, 1);
            return;
        }
        break;
    case 5:
        if (func_L01_0044E1B8(obj, 89.0f) != 0) {
            func_L24_0035ABD0(obj, 2);
            return;
        }
        break;
    case 6:
        if (func_L01_0044E1B8(obj, 23.0f) != 0) {
            func_L24_003A5360(v + 0x1C0, obj);
            if (func_0038CB00(v + 0x196) == 0) {
                return;
            }
            if (func_00382468(2) != 0) {
                if (func_L24_0035B0D0(obj) == 0) {
                    func_L24_0035ACB0(obj, 4, 2);
                    return;
                }
                r = func_00382498(0, D_L24_001DD640);
                *(s16 *)(v + 0x196) = ((D_L24_001DD648 + r) * 5 + 2) / 6;
                break;
            }
            func_L24_0035ABD0(obj, 2);
            return;
        }
        func_L24_0035A970(obj, (s32)(v + 0x160));
        return;
    case 7:
        if (func_L01_004395E0(obj) < 8.0f || 23.0f <= func_L01_004395E0(obj)) {
            *(Q_00359650 *)(v + 0x160) = *(Q_00359650 *)(v + 0x130);
            if (func_0038CF38(D_001A4C60, obj + 0x10) < D_L24_001DD5BC) {
                func_L24_0035ACB0(obj, 8, 3);
            }
        }
        func_L24_0035A970(obj, (s32)(v + 0x160));
        return;
    case 8:
        if (func_L01_0044E1B8(obj, 25.0f) != 0) {
            vec_sub_ba(d, D_001A4C60, obj + 0x10);
            d[2] = 0.0f;
            func_0038CF68(d, d, D_L24_001DD5D4);
            o = (f32 *)(v + 0x1B0);
            o[0] = d[0];
            o[1] = d[1];
            o[2] = d[2];
            vec_add_ab(v + 0x160, obj + 0x10, d);
            *(s16 *)(v + 0x196) = (D_L24_001DD64C * 5 + 2) / 6;
            func_L24_0035ACB0(obj, 9, 3);
        }
        func_L24_003A4E60(v + 0x1C0, obj, v + 0x130, -9999999827968.0f);
        return;
    case 9:
        if (func_0038CB00(v + 0x196) == 0) {
            f32 q;
            f32 lim;
            if (func_L24_0035A580(obj) != 0) {
                return;
            }
            q = func_0038D0C8(func_0038CE68(obj + 0xE0, D_L24_001D9A20));
            lim = 1.0f / D_L24_001DD638;
            if (1.5707964f - q < lim) {
                func_L24_0035B1F8(obj, 1.5707964f - q);
                func_L24_0035ACB0(obj, 0xB, 3);
                return;
            }
            func_L24_0035B1F8(obj, 1.5707964f - q);
            func_L24_0035ACB0(obj, 0xB, 3);
            qzero(v + 0x1C0);
            return;
        }
        func_L24_0035B1F8(obj, 1.5707964f - func_0038D0C8(func_0038CE68(obj + 0xE0, D_L24_001D9A20)));
        func_L24_0035ACB0(obj, 0xB, 3);
        func_L24_003A5360(v + 0x1C0, obj);
        return;
    case 10:
    case 11: {
        s32 f = 0;
        if (*(s16 *)(v + 0x196) != 0) {
            f = 1;
            if (obj[0x42] == obj[0x43]) {
                if (6.5f < func_L01_004395E0(obj)) {
                    func_L24_0035A580(obj);
                    if (func_0038CB00(v + 0x196) != 0) {
                        *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) & 0xFEFF;
                    }
                }
            }
        }
        if (func_L01_0044E1B8(obj, 29.0f) != 0) {
            func_L24_0035ACB0(obj, 7, 3);
        }
        if (f != 0) {
            return;
        }
        func_L24_003A4E60(v + 0x1C0, obj, v + 0x130, -9999999827968.0f);
        return;
    }
    case 12:
        if (obj[0x60] & 2) {
            *(f32 *)(obj + 0x48) = 1.0f;
            if (obj[0x43] != 5) {
                func_003C3A10(obj, 5, 0, 2);
            }
            func_L01_004450F0(obj, 0xD, -1);
        }
        break;
    case 13:
    case 14:
        break;
    }
}
/* localdecomp:end func_L24_00359650 */

/* localdecomp:start func_L24_00359E30 */
typedef int u128_00359E30 __attribute__((mode(TI)));
__asm__(".extern D_L24_001DD630, 4");
__asm__(".extern D_L24_001DD634, 4");
extern f32 D_L24_001DD630;
extern f32 D_L24_001DD634;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    s16 x34;
    s16 x36;
    u8 pad38[0x1];
    u8 x39;
    u8 pad3A[0x6];
    f32 x40;
    u8 x44;
    u8 pad45[0x13];
    u8 x58;
    u8 pad59[0x1];
    u8 x5A;
    u8 pad5B[0x25];
    u8 x80;
    u8 pad81[0x5];
    u8 x86;
    u8 pad87[0x5];
    f32 x8C;
    f32 x90;
    f32 x94;
    f32 x98;
    f32 x9C;
    f32 xA0;
    f32 xA4;
    u8 padA8[0x4];
    f32 xAC;
    u8 padB0[0x8];
    u8 xB8;
    u8 padB9[0x29];
    u8 xE2;
    u8 xE3;
    u8 padE4[0x3];
    u8 xE7;
    u8 padE8[0x2];
    u8 xEA;
    u8 padEB[0x2D];
    f32 x118;
    u8 pad11C[0x34];
    u128_00359E30 x150;
    u8 pad160[0x34];
    s16 x194;
    u8 pad196[0x2];
    u8 x198;
    u8 pad199[0xF];
    f32 x1A8;
    u8 pad1AC[0x10];
    s32 x1BC;
    u8 pad1C0[0x1C];
    f32 x1DC;
    u8 pad1E0[0x10];
    f32 x1F0;
    f32 x1F4;
    f32 x1F8;
    f32 x1FC;
    f32 x200;
    f32 x204;
    u8 pad208[0xC];
    f32 x214;
} S_00359E30;
extern void func_L24_0035AB58(void *);
extern void func_L24_0035A300(u8 *);

void func_L24_00359E30(void *arg) {
    u8 *a0 = arg;
    S_00359E30 *p = *(S_00359E30 **)(a0 + 0x68);
    f32 f6;
    p->xB8 = 4;
    p->x86 = 7;
    p->x80 = 0xE;
    p->xE3 = 0xF;
    p->xE2 = 8;
    p->xA0 = 0.5f;
    p->xA4 = 0.5f;
    p->xAC = 0.15f;
    p->xE7 = 1;
    p->x8C = 0.3f;
    p->x90 = 0.0200000014f;
    p->x94 = 0.0100000007f;
    p->x98 = 0.0140000004f;
    p->x9C = 0.000800000038f;
    p->xEA = 3;
    p->x118 = 0.25f;
    p->x58 = 0x14;
    p->x5A = 0xE;
    if (p->x34 == 0) {
        p->x34 = 1;
        p->x30 = 1.1f;
    }
    p->x39 = 1;
    p->x44 = 1;
    f6 = p->x1A8;
    p->x40 = 0.5f;
    p->x36 = 0x19;
    p->x1DC = 0.00392000005f;
    p->x1F0 = D_L24_001DD630;
    p->x1F4 = D_L24_001DD634;
    p->x1FC = -(f6 + 0.15f);
    p->x204 = 0.2f;
    p->x200 = 0.2f;
    p->x214 = 0.00100000005f;
    p->x1F8 = f6;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.75f;
    p->x150 = *(u128_00359E30 *)(a0 + 0x10);
    p->x198 = 1;
    p->x1BC = 0;
    p->x194 = 0;
    func_L24_0035AB58(a0);
    func_L24_0035A300(a0);
}
/* localdecomp:end func_L24_00359E30 */

/* localdecomp:start func_L24_00359FE0 */
extern u8 D_L24_001E2200[];
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L24_00359E30(void *);
extern void func_L01_00446BC8(void *, void *, s32, void *, f32);
extern void func_L24_0035A908(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L24_0035A248(u8 *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern f32 func_L24_0035AA18(void *);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L24_00359FE0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L24_001E2200, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    if (a0[0x95] == 0 && a0[0x20] == 0) {
        func_L24_00359E30(a0);
    }
    if (*(f32 *)(a0 + 0x18) <= *(f32 *)(p + 0xB0)) {
        func_L01_00446BC8(a0, a0, 0x10000, a0 + 0x10, (f32)*(s16 *)(p + 0x34));
    }
    if (a0[0xBC] != 0 && a0[0x95] != 5 && 0.0f < *(f32 *)(p + 0x30)) {
        func_L24_0035A908(a0, 0);
        func_L01_004450F0(a0, 0xC, 5);
        if (a0[0x43] != 4) {
            func_003C3A10(a0, 4, 0, 0xC);
        }
        *(f32 *)(a0 + 0x48) = 0.75f;
    }
    if (p[0x5E] != 0) {
        func_L01_004443E8(a0, 0, 3);
        func_003C2880(a0);
        return;
    }
    if (func_L01_00452FB0(a0, p + 0x70, 0, 0, 0) != 0) {
        func_L24_0035A248(a0);
        func_L24_0035A908(a0, 1);
    }
    func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        func_L01_00456C98(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 3, 0, 0, 0, func_L24_0035AA18(a0), 10.0f, 1.0f);
    } else {
        func_L01_00456BD0(a0, 3);
        func_L01_00456C98(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 1, 0, 0, 0, func_L24_0035AA18(a0), 10.0f, 1.0f);
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
