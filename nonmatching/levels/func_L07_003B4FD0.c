/* Unlinked regional matching draft. PAL: 713 to 679 words; dispatch range and stack frame recovered. Case 20's return type remains unproven. */
#include "common.h"

/* P06 unlinked draft: PAL 679 differences, NTSC-U 686. Dispatch range, quadword copies and the actual 15-argument particle call are retail-backed. Case-20 return type remains open. */
extern u8 D_001DE478[];
extern u8 D_L07_001E1EC0[];
extern u8 D_L07_001D66B0[8];
extern u8 *D_L07_001DF41C;
extern void func_L07_003B5CC8(void *);
extern void func_L07_003B5E08(void *);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L07_003B64D0(void *, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L07_003B6BD8(void *, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L07_003B6800(void *);
extern f32 func_L07_003B6DC8(void *, void *);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L07_003B6E98(void *, s32);
extern s32 func_L01_0040E020(void *);
extern s32 func_L07_003B6CD8(void *, s32);
extern f32 func_L01_004395E0(void *);
extern f32 func_L01_0040F518(f32, f32);
extern void func_L07_003B70F0(void *, s32);
extern void func_L07_003B7230(void *);
extern void func_L07_003B6998(void *);
extern void func_L07_003B6AE8(void *);
extern void func_L07_003B7378(void *);
extern void func_L07_003B68F0(void *);
extern void func_L07_003B8D80(void *);
extern void func_L07_003A2450(void);
extern s32 func_00382468(s32);
extern void func_L07_003B6B38(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L07_003315B0(void *);
extern void func_L03_0043FC00(void *, s32, u8 *, s32, s32, f32, f32, f32, f32, u8, f32, f32, s32, s32, f32);

void func_L07_003B4FD0(void *self) {
    u8 *obj = self;
    u8 *p;
    f32 f, d, yaw, step, a;
    s32 t, s, idx, go;
    u8 *o;
    vu0_v4 pos;

    if (obj[0x20] == 0) {
        func_L07_003B5CC8(obj);
    }
    func_L07_003B5E08(obj);
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045A9F0(obj);
        if (func_0038CB00(p + 0x19E) != 0) {
            func_L07_003B64D0(obj, 3);
        }
        break;
    case 3:
        func_L07_003B64D0(obj, 4);
        break;
    case 4:
        if (func_L01_004561B8(obj) != 0) {
            *(u16 *)(obj + 0x34) |= 0x5000;
        }
        func_L01_0045A748(obj, *(u8 **)(p + 0x190) + 0x10);
        if (func_L01_0040E570(*(u8 **)(p + 0x190) + 0x10, obj + 0x10) < 484.0f) {
            p[0x1AE] = 1;
            func_L07_003B64D0(obj, 5);
        }
        break;
    case 5:
        func_L01_0045A9F0(obj);
        func_L07_003B6BD8(obj, 0);
        break;
    case 6:
        if (func_L01_004561B8(obj) != 0 && *(s16 *)(p + 0x328) == 0) {
            func_L07_003A2380(2, (s32)obj, 0, 100);
            *(s16 *)(p + 0x328) = 500;
        }
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 7);
        }
        break;
    case 7:
        if (func_L01_004561B8(obj) != 0) {
            if (*(s16 *)(p + 0x32A) == 0) {
                func_L07_003A2380(0xE, (s32)(D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8)), 0, 100);
                *(s16 *)(p + 0x32A) = 1000;
            }
            func_L01_00456230(obj, 0);
        }
        func_L01_0045A9F0(obj);
        func_L07_003B6800(obj);
        if (func_L01_0040E570(obj + 0x10, p + 0x80) < 64.0f) {
            func_L07_003B64D0(obj, 0x11);
        } else if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 8);
        }
        break;
    case 8:
        if (func_L01_004561B8(obj) != 0) {
            *(s16 *)(p + 0x31A) = 75;
            *(s16 *)(p + 0x318) = (p[0x321] == 5) ? 0x14D : 0x1F4;
            p[0x31C] = 5;
            p[0x31D] = func_00382468(4);
        }
        func_L01_0045A9F0(obj);
        func_L07_003B6800(obj);
        yaw = func_L07_003B6DC8(obj, p + 0x80);
        step = (func_0038DBA0(*(f32 *)(obj + 0xF8), yaw) / 0.5235988f * 0.7f + 0.3f) * 0.020833334f;
        if (obj[0x42] == 8) {
            *(f32 *)(obj + 0xF8) = func_0038DB00(*(f32 *)(obj + 0xF8), step);
            if (func_0038DB00(*(f32 *)(obj + 0xF8), yaw) < -0.5235988f) {
                if (obj[0x43] != 7) {
                    func_003C3A10(obj, 7, 0, 2);
                }
            }
        } else if (obj[0x42] == 7) {
            *(f32 *)(obj + 0xF8) = func_0038DAB8(*(f32 *)(obj + 0xF8), step);
            if (0.5235988f < func_0038DB00(*(f32 *)(obj + 0xF8), yaw)) {
                if (obj[0x43] != 8) {
                    func_003C3A10(obj, 8, 0, 2);
                }
            }
        }
        func_0038CB00(p + 0x31A);
        if (func_L01_0040E020(p + 0x31C) != 0) {
            func_L07_003B6E98(obj, p[0x31D]);
            p[0x31C] = 5;
            p[0x31D] = (p[0x31D] + 1) % 4;
        }
        if (func_L01_0040E570(obj + 0x10, p + 0x80) < 64.0f) {
            func_L07_003B64D0(obj, 0x11);
        } else if (func_0038CB00(p + 0x318) != 0 || func_L07_003B6CD8(obj, 1) != 0) {
            *(s32 *)(p + 0xD8) &= ~0x10;
            func_L07_003B64D0(obj, 9);
        }
        break;
    case 9:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 0xA);
        }
        break;
    case 10:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            t = p[0x320] + 1;
            s = p[0x321];
            p[0x320] = t;
            if (s == 0 || s == 5) {
                func_L07_003B6998(obj);
            } else if ((u8)t >= 2) {
                p[0x320] = 0;
                func_L07_003B6998(obj);
            } else {
                if (*(s16 *)(p + 0x328) == 0) {
                    func_L07_003A2380(4, (s32)obj, 0, 100);
                    *(s16 *)(p + 0x328) = 500;
                }
                func_L07_003B64D0(obj, 0xC);
            }
        }
        break;
    case 11:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 0xC);
        }
        break;
    case 12:
        if (func_L01_004561B8(obj) != 0) {
            func_L01_00456230(obj, 0);
        }
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 0xD);
        }
        break;
    case 13:
        func_L01_0045A9F0(obj);
        if (func_L01_004561B8(obj) != 0) {
            p[0x31E] = 0xFF;
            *(s16 *)(p + 0x318) = 200;
            if (p[0x321] == 2) {
                *(s16 *)(p + 0x318) = 100;
            }
        }
        f = func_L01_004395E0(obj);
        idx = (u8)(s32)(func_L01_0040F518(f + 1.0f, 10.0f) * 0.5f);
        if (p[0x31E] != 0xFF && p[0x31E] != idx) {
            func_L07_003B70F0(obj, D_001DE478[idx]);
        }
        p[0x31E] = idx;
        if (p[0x321] == 3) {
            o = D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8);
            if (o[0x20] == 1) {
                p[0x321] = 4;
                go = 1;
            } else {
                go = func_0038CB00(p + 0x318);
            }
        } else {
            go = func_0038CB00(p + 0x318) != 0 || func_L07_003B6CD8(obj, 1) != 0;
        }
        if (go) {
            func_L07_003B64D0(obj, 0xE);
        }
        break;
    case 14:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            s = p[0x321];
            if (s == 5) {
                func_L07_003B64D0(obj, 7);
            } else if (s == 3) {
                func_L07_003B64D0(obj, 0x16);
            } else if (s == 4) {
                p[0x321] = 5;
                func_L07_003B6B38(obj);
            } else {
                func_L07_003B64D0(obj, 0xF);
            }
        }
        break;
    case 15:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            t = p[0x320] + 1;
            s = p[0x321];
            p[0x320] = t;
            if (s == 0) {
                func_L07_003B6998(obj);
            } else if ((u8)t < 2) {
                func_L07_003B64D0(obj, 7);
            } else {
                p[0x320] = 0;
                func_L07_003B6998(obj);
            }
        }
        break;
    case 16:
        break;
    case 17:
        f = func_L01_004395E0(obj);
        if (obj[0x42] == 0xE && 10.0f <= f && f <= 20.0f) {
            func_L07_003B7230(obj);
        }
        if (obj[0x60] & 2) {
            func_L07_003B6998(obj);
        }
        break;
    case 18:
        if (func_L01_004561B8(obj) != 0) {
            *(s32 *)(p + 0xD8) &= ~0x415;
            *(u16 *)(obj + 0x34) &= 0xAFFF;
            if (0.0f < *(f32 *)(p + 0x148)) {
                *(f32 *)(p + 0x148) = 0.0f;
            }
        }
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B6AE8(obj);
        }
        break;
    case 19:
        if (func_L01_004561B8(obj) != 0) {
            *(s32 *)(p + 0xD8) |= 0x415;
        }
        if (obj[0x42] == 2 && 5.0f < func_L01_004395E0(obj)) {
            func_L07_003B7378(obj);
            func_L07_003B68F0(obj);
            *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
            pos.z = pos.z + 50.0f;
            func_L01_0045A748(obj, &pos);
        } else {
            func_L01_0045A9F0(obj);
        }
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 0x14);
        }
        break;
    case 20:
        if (func_L01_004561B8(obj) != 0) {
            *(f32 *)(p + 0x314) = func_0038CF38(obj + 0x10, p + 0x2F0);
        }
        func_L07_003B7378(obj);
        func_L07_003B68F0(obj);
        *(vu0_q *)&pos = *(vu0_q *)(p + 0x2F0);
        d = func_0038CF38(obj + 0x10, &pos);
        pos.z = pos.z + (d * 20.0f / *(f32 *)(p + 0x314) + 5.0f);
        if (((s32 (*)(void *, void *))func_L01_0045A748)(obj, &pos) & 0x80) {
            func_L07_003B64D0(obj, 0x15);
        }
        break;
    case 21:
        if (obj[0x42] != 4 || func_L01_004395E0(obj) <= 15.0f) {
            func_L07_003B7378(obj);
            func_L07_003B68F0(obj);
            func_L01_0045A748(obj, p + 0x2F0);
        } else {
            if (func_L01_004561B8(obj) != 0) {
                if (p[0x322] != 0x16) {
                    *(f32 *)(D_L07_001E1EC0 + 0x40) = 0.05f;
                    *(s32 *)(D_L07_001E1EC0 + 0x48) = 12;
                    *(s32 *)(D_L07_001E1EC0 + 0x2C) = 0;
                    *(f32 *)(D_L07_001E1EC0 + 0x20) = 0.05f;
                    *(s32 *)(D_L07_001E1EC0 + 0x28) = 12;
                }
                func_L07_003B8D80(obj);
            }
            func_L01_0045A9F0(obj);
        }
        if (obj[0x60] & 2) {
            *(s32 *)(p + 0xD8) &= ~0x415;
            if (p[0x322] != 0xFF) {
                func_L07_003B64D0(obj, p[0x322]);
            } else {
                s = p[0x31F];
                t = p[0x321];
                if (t == 5) {
                    go = 1;
                } else if (t == 1 || func_L07_003B6CD8(obj, 0) != 0) {
                    go = (s == 0);
                } else {
                    go = s;
                }
                func_L07_003B6BD8(obj, go);
            }
            if (p[0x321] == 5) {
                func_L07_003A2380(5, (s32)obj, 0, 100);
            }
        }
        break;
    case 22:
        func_L01_0045A9F0(obj);
        if (func_L01_004561B8(obj) != 0) {
            *(s16 *)(p + 0x318) = func_00382468(100) + 200;
        }
        func_0038CB00(p + 0x318);
        if (p[0x321] == 3) {
            o = D_L07_001DF41C + (*(s32 *)(p + 0x300) << 8);
            if (o[0x20] == 1) {
                p[0x321] = 5;
                func_L07_003A2380(7, (s32)obj, 0, 100);
                func_L07_003B6B38(obj);
            } else if (*(s16 *)(p + 0x318) == 0) {
                func_L07_003B64D0(obj, 0xC);
            }
        } else {
            s = obj[0xBC];
            if (s == 4) {
                p[0x321] = 3;
                func_L07_003B64D0(obj, 0xC);
                obj[0xBC] = 0;
            } else if (s == 3) {
                func_L07_003B6B38(obj);
                obj[0xBC] = 0;
            } else if (*(s16 *)(p + 0x318) == 0) {
                if (s == 2) {
                    func_L07_003B64D0(obj, 0x17);
                    obj[0xBC] = 0;
                } else if (s == 1) {
                    func_L07_003B64D0(obj, 0x18);
                    obj[0xBC] = 0;
                }
            }
        }
        break;
    case 23:
    case 24:
        func_L01_0045A9F0(obj);
        if (obj[0x60] & 2) {
            func_L07_003B64D0(obj, 0x16);
        }
        break;
    case 25:
        if (obj[0x60] & 2) {
            func_L07_003A2450();
            if (func_00382468(2) != 0) {
                func_L07_003A2380(0x4F, (s32)obj, 0, 100);
            } else {
                func_L07_003A2380(0x50, (s32)obj, 0, 100);
            }
            func_L03_0043FC00(obj, 0x1FFF, D_L07_001D66B0, 2, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
            func_L07_003315B0(obj);
        }
        break;
    }
}
