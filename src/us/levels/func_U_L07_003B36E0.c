#include "common.h"
#include "structs/moby.h"

extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern s32 func_0037E1D8(s32);
extern s32 func_0038CB00(void *);
extern s32 func_003883C8(void *);
extern f32 func_00388800(void *, void *);
extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00452F40(void *, s32);
extern void func_L07_00330E70(void *);
extern s32 func_L07_003A0BC0(u8, s32, u8, s16);
extern void func_L07_003A0C90(void);

/* localdecomp:start func_U_L07_003B36E0 */
extern s32 func_L01_004576E8(void *);
extern s32 func_L01_00457440(void *, void *);
extern void func_L07_003B43D8(u8 *);
extern void func_L07_003B4518(u8 *);
extern void func_L07_003B4BE0(u8 *, s32);
extern s32 func_L01_0040BAF0(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L01_00436500(void *);
extern f32 func_L01_0040CFE8(f32, f32);
extern s32 func_00382468(s32);
extern void func_L03_0043C598(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L07_003B52E8(u8 *, s32);
extern void func_L07_003B4F10(u8 *);
extern f32 func_L07_003B54D8(u8 *, u8 *);
extern void func_L07_003B55A8(u8 *, u8);
extern s32 func_L07_003B53E8(u8 *, u8);
extern void func_L07_003B5800(u8 *, u8);
extern void func_L07_003B5940(u8 *);
extern void func_L07_003B50A8(u8 *);
extern void func_L07_003B51F8(u8 *);
extern void func_L07_003B5A88(void *);
extern void func_L07_003B5000(u8 *);
extern void func_L07_003B7490(u8 *);
extern void func_L07_003B5248(u8 *);
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001DE4B8[8];
__asm__(".extern D_L07_001DE4B8, 8");
extern u8 D_L07_001E1EC0[];

typedef struct { f32 rate; s32 pad4; s32 count; s32 phase; u8 pad10[0x10]; } Fx_003B4FD0;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B4FD0;

void func_U_L07_003B36E0(u8 *obj) {
    u8 *p;
    u8 *target;
    u8 *flags;
    f32 lim;
    f32 a;
    f32 step;
    f32 f;
    s32 k;
    u8 n;
    s32 x;
    V4_003B4FD0 v;

    if (obj[0x20] == 0) {
        func_L07_003B43D8(obj);
    }
    func_L07_003B4518(obj);
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_004576E8(obj);
        if (func_0038CB00(p + 0x19E)) {
            func_L07_003B4BE0(obj, 3);
        }
        break;
    case 3:
        func_L07_003B4BE0(obj, 4);
        break;
    case 4:
        if (func_L01_00452EC8(obj)) {
            *(u16 *)(obj + 0x34) |= 0x5000;
        }
        func_L01_00457440(obj, *(u8 **)(p + 0x190) + 0x10);
        if (func_L01_0040C040(*(u8 **)(p + 0x190) + 0x10, obj + 0x10) < 484.0f) {
            p[0x1AE] = 1;
            func_L07_003B4BE0(obj, 5);
        }
        break;
    case 5:
        func_L01_004576E8(obj);
        func_L07_003B52E8(obj, 0);
        break;
    case 6:
        if (func_L01_00452EC8(obj) && *(s16 *)(p + 0x328) == 0) {
            func_L07_003A0BC0(2, (s32)obj, 0, 120);
            *(s16 *)(p + 0x328) = 600;
        }
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            func_L07_003B4BE0(obj, 7);
        }
        break;
    case 7:
        if (func_L01_00452EC8(obj)) {
            if (*(s16 *)(p + 0x32A) == 0) {
                func_L07_003A0BC0(14, (s32)(D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8)), 0, 120);
                *(s16 *)(p + 0x32A) = 1200;
            }
            func_L01_00452F40(obj, 0);
        }
        func_L01_004576E8(obj);
        func_L07_003B4F10(obj);
        if (func_L01_0040C040(obj + 0x10, p + 0x80) < 64.0f) {
            func_L07_003B4BE0(obj, 0x11);
        } else if (obj[0x60] & 2) {
            func_L07_003B4BE0(obj, 8);
        }
        break;
    case 8:
        if (func_L01_00452EC8(obj)) {
            *(s16 *)(p + 0x31A) = 90;
            if (p[0x321] == 5) {
                *(s16 *)(p + 0x318) = 400;
            } else {
                *(s16 *)(p + 0x318) = 600;
            }
            p[0x31C] = 6;
            p[0x31D] = func_00382468(4);
        }
        target = p + 0x80;
        func_L01_004576E8(obj);
        lim = 0.5235988f;
        func_L07_003B4F10(obj);
        a = func_L07_003B54D8(obj, target);
        step = (func_0038DBA0(*(f32 *)(obj + 0xF8), a) / lim * 0.7f + 0.3f) * 0.017453294f;
        if (obj[0x42] == 8) {
            *(f32 *)(obj + 0xF8) = func_0038DB00(*(f32 *)(obj + 0xF8), step);
            if (func_0038DB00(*(f32 *)(obj + 0xF8), a) < -0.5235988f && obj[0x43] != 7) {
                func_003C3A10(obj, 7, 0, 3);
            }
        } else if (obj[0x42] == 7) {
            *(f32 *)(obj + 0xF8) = func_0038DAB8(*(f32 *)(obj + 0xF8), step);
            if (lim < func_0038DB00(*(f32 *)(obj + 0xF8), a) && obj[0x43] != 8) {
                func_003C3A10(obj, 8, 0, 3);
            }
        }
        func_0038CB00(p + 0x31A);
        if (func_L01_0040BAF0(p + 0x31C)) {
            func_L07_003B55A8(obj, p[0x31D]);
            p[0x31C] = 6;
            p[0x31D] = (p[0x31D] + 1) % 4;
        }
        if (func_L01_0040C040(obj + 0x10, p + 0x80) < 64.0f) {
            func_L07_003B4BE0(obj, 0x11);
        } else if (func_0038CB00(p + 0x318) || func_L07_003B53E8(obj, 1)) {
            *(s32 *)(p + 0xD8) &= ~0x10;
            func_L07_003B4BE0(obj, 9);
        }
        break;
    case 9:
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            func_L07_003B4BE0(obj, 10);
        }
        break;
    case 10:
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            p[0x320]++;
            if (p[0x321] == 0 || p[0x321] == 5) {
                func_L07_003B50A8(obj);
            } else if (p[0x320] >= 2) {
                p[0x320] = 0;
                func_L07_003B50A8(obj);
            } else {
                if (*(s16 *)(p + 0x328) == 0) {
                    func_L07_003A0BC0(4, (s32)obj, 0, 120);
                    *(s16 *)(p + 0x328) = 600;
                }
                func_L07_003B4BE0(obj, 12);
            }
        }
        break;
    case 11:
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            func_L07_003B4BE0(obj, 12);
        }
        break;
    case 12:
        if (func_L01_00452EC8(obj)) {
            func_L01_00452F40(obj, 0);
        }
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            func_L07_003B4BE0(obj, 13);
        }
        break;
    case 13:
        func_L01_004576E8(obj);
        if (func_L01_00452EC8(obj)) {
            p[0x31E] = 0xFF;
            *(s16 *)(p + 0x318) = 240;
            if (p[0x321] == 2) {
                *(s16 *)(p + 0x318) = 120;
            }
        }
        n = (s32)(func_L01_0040CFE8(func_L01_00436500(obj) + 1.0f, 10.0f) * 0.5f);
        if (p[0x31E] != 0xFF && p[0x31E] != n) {
            func_L07_003B5800(obj, D_L07_001DE4B8[n]);
        }
        p[0x31E] = n;
        if (p[0x321] == 3) {
            if ((D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8))[0x20] == 1) {
                p[0x321] = 4;
                func_L07_003B4BE0(obj, 14);
            } else if (func_0038CB00(p + 0x318)) {
                func_L07_003B4BE0(obj, 14);
            }
        } else if (func_0038CB00(p + 0x318) || func_L07_003B53E8(obj, 1)) {
            func_L07_003B4BE0(obj, 14);
        }
        break;
    case 14:
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            if (p[0x321] == 5) {
                func_L07_003B4BE0(obj, 7);
            } else if (p[0x321] == 3) {
                func_L07_003B4BE0(obj, 0x16);
            } else if (p[0x321] == 4) {
                p[0x321] = 5;
                func_L07_003B5248(obj);
            } else {
                func_L07_003B4BE0(obj, 15);
            }
        }
        break;
    case 15:
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            p[0x320]++;
            if (p[0x321] == 0) {
                func_L07_003B50A8(obj);
            } else if (p[0x320] >= 2) {
                p[0x320] = 0;
                func_L07_003B50A8(obj);
            } else {
                func_L07_003B4BE0(obj, 7);
            }
        }
        break;
    case 17:
        f = func_L01_00436500(obj);
        if (obj[0x42] == 14 && 10.0f <= f && f <= 20.0f) {
            func_L07_003B5940(obj);
        }
        if (obj[0x60] & 2) {
            func_L07_003B50A8(obj);
        }
        break;
    case 18:
        if (func_L01_00452EC8(obj)) {
            *(s32 *)(p + 0xD8) &= ~0x415;
            *(u16 *)(obj + 0x34) &= 0xAFFF;
            if (0.0f < *(f32 *)(p + 0x148)) {
                *(f32 *)(p + 0x148) = 0.0f;
            }
        }
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            func_L07_003B51F8(obj);
        }
        break;
    case 19:
        if (func_L01_00452EC8(obj)) {
            flags = p + 0xA0;
            *(s32 *)(flags + 0x38) |= 0x415;
        }
        if (obj[0x42] == 2 && 5.0f < func_L01_00436500(obj)) {
            func_L07_003B5A88(obj);
            func_L07_003B5000(obj);
            v = *(V4_003B4FD0 *)(obj + 0x10);
            v.z += 50.0f;
            func_L01_00457440(obj, &v);
        } else {
            func_L01_004576E8(obj);
        }
        if (obj[0x60] & 2) {
            func_L07_003B4BE0(obj, 0x14);
        }
        break;
    case 20:
        if (func_L01_00452EC8(obj)) {
            *(f32 *)(p + 0x314) = func_0038CF38(obj + 0x10, p + 0x2F0);
        }
        func_L07_003B5A88(obj);
        func_L07_003B5000(obj);
        v = *(V4_003B4FD0 *)(p + 0x2F0);
        v.z += func_0038CF38(obj + 0x10, &v) * 20.0f / *(f32 *)(p + 0x314) + 5.0f;
        if (func_L01_00457440(obj, &v) & 0x80) {
            func_L07_003B4BE0(obj, 0x15);
        }
        break;
    case 21:
        if (obj[0x42] != 4 || func_L01_00436500(obj) <= 15.0f) {
            func_L07_003B5A88(obj);
            func_L07_003B5000(obj);
            func_L01_00457440(obj, p + 0x2F0);
        } else {
            if (func_L01_00452EC8(obj)) {
                if (p[0x322] != 0x16) {
                    Fx_003B4FD0 *fx = (Fx_003B4FD0 *)D_L07_001E1EC0;
                    fx[1].rate = 0.05f;
                    fx[1].count = 15;
                    fx[2].rate = 0.05f;
                    fx[2].count = 15;
                    fx[1].phase = 0;
                }
                func_L07_003B7490(obj);
            }
            func_L01_004576E8(obj);
        }
        if (obj[0x60] & 2) {
            *(s32 *)(p + 0xD8) &= ~0x415;
            if (p[0x322] == 0xFF) {
                x = p[0x31F];
                if (p[0x321] == 5) {
                    x = 1;
                } else if (p[0x321] == 1 || func_L07_003B53E8(obj, 0)) {
                    if (x) {
                        x = 0;
                    } else {
                        x = 1;
                    }
                }
                func_L07_003B52E8(obj, x);
            } else {
                func_L07_003B4BE0(obj, p[0x322]);
            }
            if (p[0x321] == 5) {
                func_L07_003A0BC0(5, (s32)obj, 0, 120);
            }
        }
        break;
    case 22:
        func_L01_004576E8(obj);
        if (func_L01_00452EC8(obj)) {
            *(s16 *)(p + 0x318) = func_00382468(120) + 240;
        }
        func_0038CB00(p + 0x318);
        if (p[0x321] == 3) {
            if ((D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8))[0x20] == 1) {
                p[0x321] = 5;
                func_L07_003A0BC0(7, (s32)obj, 0, 120);
                func_L07_003B5248(obj);
            } else if (*(s16 *)(p + 0x318) == 0) {
                func_L07_003B4BE0(obj, 12);
            }
        } else {
            k = obj[0xBC];
            if (k == 4) {
                p[0x321] = 3;
                func_L07_003B4BE0(obj, 12);
                obj[0xBC] = 0;
            } else if (k == 3) {
                func_L07_003B5248(obj);
                obj[0xBC] = 0;
            } else if (*(s16 *)(p + 0x318) == 0) {
                if (k == 2) {
                    func_L07_003B4BE0(obj, 0x17);
                    obj[0xBC] = 0;
                } else if (k == 1) {
                    func_L07_003B4BE0(obj, 0x18);
                    obj[0xBC] = 0;
                }
            }
        }
        break;
    case 23:
    case 24:
        func_L01_004576E8(obj);
        if (obj[0x60] & 2) {
            func_L07_003B4BE0(obj, 0x16);
        }
        break;
    case 25:
        if (obj[0x60] & 2) {
            func_L07_003A0C90();
            if (func_00382468(2)) {
                func_L07_003A0BC0(0x4F, (s32)obj, 0, 120);
            } else {
                func_L07_003A0BC0(0x50, (s32)obj, 0, 120);
            }
            func_L03_0043C598(obj, 0x1FFF, D_L07_001D66B0, 2, 3, 0xFF, 0xB4, 0,
                3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f);
            func_L07_00330E70(obj);
        }
        break;
    }
}
/* localdecomp:end func_U_L07_003B36E0 */
