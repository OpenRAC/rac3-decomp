#include "common.h"

/* NTSC-U counterpart of func_L24_00356168 (src/levels/24_insomniac_museum/L24_00356100.c) */
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);

/* localdecomp:start func_L24_00355130 */
#include "vu0.h"
typedef struct {
    u8 pad[0x1A0];
    u32 held;
    u32 pressed;
} __attribute__((aligned(16))) Pad_00356168;
extern Pad_00356168 D_001CD0C0;
extern s32 D_L24_002CF570[];
extern s32 D_L24_001DD5B4_00355130;
/* a button-code sequence: its step and its countdown (func_L24_00357D28 counts it down) */
typedef struct {
    s32 step;
    s32 timer;
} Code_00356168;
extern Code_00356168 D_L24_001E0FF0_00355130;
extern Code_00356168 D_L24_001E1000_00355130;
extern Code_00356168 D_L24_001E1010_00355130;
extern s32 D_L24_001E0FF8_00355130;
extern s32 D_L24_001E1008_00355130;
extern s32 D_L24_001E1018_00355130;
extern s32 func_L24_00356600(u8 *);
extern void func_L02_003F84F0(s32, s32, f32);
extern s32 func_L24_00357CD0(void *);
extern void func_003BD360(void *);
extern void func_L24_00356B78(u8 *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_L24_00356550(u8 *, s32, s32, s32, f32);
extern void func_L24_003550C8(u8 *, u8 *);
extern void func_003BDA38(void *, s32, void *);
extern u8 *func_L01_003AFF80(u8 *, void *, void *, s32, s32, s32, s32, f32, f32);
extern f32 func_L01_00436500(void *);
extern void func_L24_003562A0(u8 *, u8 *);
extern void func_00388830(void *, void *, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_003BEC60(f32 *, f32, void *, f32, f32, f32);
extern void func_L24_00357D28(u8 *);

void func_L24_00355130(u8 *obj) {
    u8 *s;
    f32 pos[4];
    f32 d[4];
    f32 e[4];
    f32 u[4];
    s32 dir;
    s32 up;
    s32 r;
    u32 pressed;

    s = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0) {
        func_L24_00356600(obj);
        obj[0x20] = 1;
    }
    if (*(f32 *)(obj + 0x10) < 273.0f) {
        *(f32 *)(obj + 0x10) = 273.0f;
    }
    if (*(f32 *)(obj + 0x10) > 284.0f) {
        *(f32 *)(obj + 0x10) = 284.0f;
    }
    if (D_L24_002CF570[0] == 5) {
        dir = 0;
        if ((D_001CD0C0.held & 0x2000)) {
            dir = 1;
        }
        if ((D_001CD0C0.held & 0x8000)) {
            dir = -1;
        }
        up = 0;
        if ((D_001CD0C0.held & 0x4000)) {
            up = 1;
        }
        func_L02_003F84F0(0, 0, *(f32 *)(s + 0x30) / (f32)*(s16 *)(s + 0x34));
        if (D_L24_001DD5B4_00355130 != 0) {
            func_L24_00356B78(obj);
            func_L01_00441FB8(obj, 1, 0);
            if (obj[0x43] != 0) {
                func_003BE4F0(obj, 0, 0, 4);
            }
            *(f32 *)(s + 0x30) = (f32)*(s16 *)(s + 0x34);
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
            *(s16 *)(s + 0x198) = 0;
            return;
        }
        if (func_L24_00357CD0(obj) != 0) {
            func_003BD360(obj);
            return;
        }
        pressed = D_001CD0C0.pressed;
        if (D_L24_001E0FF0_00355130.step == 0) {
            if (pressed & 0x4000) {
                D_L24_001E0FF0_00355130.step = 1;
                D_L24_001E0FF0_00355130.timer = 12;
            }
        } else if (D_L24_001E0FF0_00355130.step == 1) {
            if ((D_001CD0C0.held & 0x4000) && (D_001CD0C0.pressed & 0x8000)) {
                D_L24_001E0FF0_00355130.step = 2;
                D_L24_001E0FF0_00355130.timer = 12;
            }
        } else if (D_L24_001E0FF0_00355130.step == 2) {
            if ((D_001CD0C0.held & 0x8000)) {
                D_L24_001E0FF0_00355130.step = 3;
                D_L24_001E0FF0_00355130.timer = 12;
            }
        }
        if (D_L24_001E0FF0_00355130.step == 3) {
            if ((D_001CD0C0.pressed & 0x0080)) {
                D_L24_001E0FF8_00355130 = 1;
                D_L24_001E0FF0_00355130.timer = 10;
            }
        }
        if (D_L24_001E1010_00355130.step == 0) {
            if ((D_001CD0C0.pressed & 0x8000)) {
                D_L24_001E1010_00355130.step = 1;
                D_L24_001E1010_00355130.timer = 12;
            }
        } else if (D_L24_001E1010_00355130.step == 1) {
            if ((D_001CD0C0.held & 0x4000)) {
                D_L24_001E1010_00355130.step = 2;
                D_L24_001E1010_00355130.timer = 12;
            }
        } else if (D_L24_001E1010_00355130.step == 2) {
            if ((D_001CD0C0.held & 0x8000) && !(D_001CD0C0.held & 0x4000)) {
                D_L24_001E1010_00355130.step = 3;
                D_L24_001E1010_00355130.timer = 12;
            }
        }
        if (D_L24_001E1010_00355130.step == 3) {
            if ((D_001CD0C0.pressed & 0x0020)) {
                D_L24_001E1018_00355130 = 1;
                D_L24_001E1010_00355130.timer = 10;
            }
        }
        if (D_L24_001E1000_00355130.step == 0) {
            if ((D_001CD0C0.pressed & 0x4000)) {
                D_L24_001E1000_00355130.step = 1;
                D_L24_001E1000_00355130.timer = 12;
            }
        } else if (D_L24_001E1000_00355130.step == 1) {
            if ((D_001CD0C0.held & 0x4000) && (D_001CD0C0.pressed & 0x2000)) {
                D_L24_001E1000_00355130.step = 2;
                D_L24_001E1000_00355130.timer = 12;
            }
        } else if (D_L24_001E1000_00355130.step == 2) {
            if ((D_001CD0C0.held & 0x2000)) {
                D_L24_001E1000_00355130.step = 3;
                D_L24_001E1000_00355130.timer = 12;
            }
        }
        if (D_L24_001E1000_00355130.step == 3) {
            if ((D_001CD0C0.pressed & 0x0040)) {
                D_L24_001E1008_00355130 = 1;
                D_L24_001E1000_00355130.timer = 10;
            }
        }
        if (obj[0x95] == 3) {
            r = func_L01_00451078(obj, s + 0x160);
            if (obj[0x42] == 9 && (obj[0x60] & 2)) {
                D_L24_001DD5B4_00355130 = D_L24_001DD5B4_00355130 + 1;
                func_L24_00356B78(obj);
                func_L01_00441FB8(obj, 1, 0);
                if (obj[0x43] != 0) {
                    func_003BE4F0(obj, 0, 0, 4);
                }
                *(f32 *)(s + 0x30) = (f32)*(s16 *)(s + 0x34);
                *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
                *(s16 *)(s + 0x198) = 0;
                return;
            }
            if ((r & 2) && *(f32 *)(s + 0x30) > 0.0f) {
                func_L01_00441FB8(obj, 1, 0);
            }
        }
        switch (obj[0x20]) {
        case 10:
            if (func_L01_00452EC8(obj) != 0 && obj[0x43] != 8) {
                func_003BE4F0(obj, 8, 0, 3);
            }
        case 9:
            if (dir > 0 && D_L24_001E1000_00355130.timer == 0) {
                *(f32 *)(s + 0x8EC) = 3.1415927f;
            } else {
                *(f32 *)(s + 0x8EC) = 0.0f;
            }
            *(f32 *)(s + 0x1C4) = *(f32 *)(s + 0x8EC);
            ((void (*)(void *, void *, f32, f32, f32, f32, s32))func_L01_00445758)(obj + 0xF8, s + 0x8E8, *(f32 *)(s + 0x8EC), 0.261799395084f, 0.261799395084f, 0.290888220072f, 0);
            break;
        case 1:
            if (dir > 0 && D_L24_001E1000_00355130.timer == 0) {
                *(f32 *)(s + 0x8EC) = 3.1415927f;
            } else {
                *(f32 *)(s + 0x8EC) = 0.0f;
            }
            ((void (*)(void *, void *, f32, f32, f32, f32, s32))func_L01_00445758)(obj + 0xF8, s + 0x8E8, *(f32 *)(s + 0x8EC), 0.261799395084f, 0.261799395084f, 0.290888220072f, 0);
            if (dir != 0 && D_L24_001E0FF0_00355130.timer == 0 && D_L24_001E1000_00355130.timer == 0) {
                if (up) {
                    *(f32 *)(obj + 0x48) = 1.0f;
                    if (obj[0x43] != 3) {
                        func_003BE4F0(obj, 3, 0, 6);
                    }
                    *(f32 *)(obj + 0x10) -= (f32)dir * 0.0666666701436f;
                } else {
                    if (obj[0x43] != 2) {
                        func_003BE4F0(obj, 2, 0, 6);
                    }
                    *(f32 *)(obj + 0x10) -= (f32)dir * 0.166666671634f;
                }
            } else if (!up) {
                if (obj[0x43] != 0) {
                    func_003BE4F0(obj, 0, 0, 6);
                }
            }
            if (up && dir == 0) {
                if (obj[0x42] == 3) {
                    *(f32 *)(obj + 0x48) = 0.0f;
                }
                if (obj[0x43] != 3) {
                    func_003BE4F0(obj, 3, 0, 6);
                }
            }
            if ((D_001CD0C0.pressed & 0x0020)) {
                *(s32 *)(s + 0x8E0) = dir;
                if (obj[0x43] != 4) {
                    func_003BE4F0(obj, 4, 10, 3);
                }
                func_L01_00441FB8(obj, 4, -1);
            } else if ((D_001CD0C0.pressed & 0x0080)) {
                *(s32 *)(s + 0x8E0) = dir;
                if (obj[0x43] != 7) {
                    func_003BE4F0(obj, 7, 10, 3);
                }
                func_L01_00441FB8(obj, 4, -1);
            } else if ((D_001CD0C0.pressed & 0x0040)) {
                *(s32 *)(s + 0x8E0) = dir;
                if (obj[0x43] != 11) {
                    func_003BE4F0(obj, 11, 8, 3);
                }
                func_L01_00441FB8(obj, 4, -1);
            } else if ((D_001CD0C0.pressed & 0x0010)) {
                *(s32 *)(s + 0x8E0) = dir;
                if (obj[0x43] != 5) {
                    func_003BE4F0(obj, 5, 10, 3);
                }
                func_L01_00441FB8(obj, 8, -1);
            }
            if ((D_001CD0C0.held & 0x1000)) {
                *(s32 *)(s + 0x8E0) = dir;
                *(s32 *)(s + 0x8DC) = 0;
                func_L01_00441FB8(obj, 2, -1);
                if (obj[0x43] != 1) {
                    func_003BE4F0(obj, 1, 7, 2);
                }
            }
            if (D_L24_001E0FF8_00355130 != 0) {
                func_L01_00441FB8(obj, 5, -1);
                if (obj[0x43] != 6) {
                    func_003BE4F0(obj, 6, 10, 3);
                }
            }
            if (D_L24_001E1008_00355130 != 0) {
                func_L01_00441FB8(obj, 6, -1);
                if (obj[0x43] != 11) {
                    func_003BE4F0(obj, 11, 8, 3);
                }
            }
            if (D_L24_001E1018_00355130 != 0) {
                func_L01_00441FB8(obj, 7, -1);
                if (obj[0x43] != 10) {
                    func_003BE4F0(obj, 10, 7, 2);
                }
            }
            break;
        case 6:
            if (*(s32 *)(s + 0x8E0) > 0) {
                *(f32 *)(s + 0x8EC) = 3.1415927f;
            } else {
                *(f32 *)(s + 0x8EC) = 0.0f;
            }
            if (func_L01_0044AF40(obj, 19.0f) != 0 && obj[0x42] == 11 && *(u16 *)(obj + 0x96) < 60) {
                func_003BE4F0(obj, 11, 12, 6);
            }
            func_L24_00356550(obj, (s32)s, 8, 11, 0.3f);
            *(f32 *)(obj + 0x10) += 0.0444444455206f;
            *(f32 *)(obj + 0x48) = 1.75f;
            if (func_L01_0044AF40(obj, 30.0f) != 0) {
                *(f32 *)(obj + 0x48) = 1.0f;
                if (obj[0x43] != 0) {
                    func_003BE4F0(obj, 0, 0, 10);
                }
                func_L01_00441FB8(obj, 1, -1);
            }
            break;
        case 5:
            func_L24_003550C8(obj, s);
            if (func_L01_0044AF40(obj, 17.0f) != 0 && obj[0x42] == 6) {
                *(vu0_q *)pos = *(vu0_q *)(obj + 0xC0);
                func_003BDA38(obj, 4, d);
                func_L01_003AFF80(obj, d, pos, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010, 4.0f, 0.65f);
            }
            if (func_L01_0044AF40(obj, 35.0f) != 0) {
                if (obj[0x43] != 0) {
                    func_003BE4F0(obj, 0, 0, 10);
                }
                func_L01_00441FB8(obj, 1, -1);
            }
            break;
        case 8:
            func_L24_003550C8(obj, s);
            if (func_L01_0044AF40(obj, 30.0f) != 0) {
                if (obj[0x43] != 0) {
                    func_003BE4F0(obj, 0, 0, 10);
                }
                func_L01_00441FB8(obj, 1, -1);
            }
            break;
        case 4:
            func_L24_003550C8(obj, s);
            if (obj[0x60] & 2) {
                if (obj[0x43] != 0) {
                    func_003BE4F0(obj, 0, 0, 10);
                }
                func_L01_00441FB8(obj, 1, -1);
            }
            if (obj[0x42] == 11) {
                func_L24_00356550(obj, (s32)s, 8, 11, 0.3f);
                if (func_L01_0044AF40(obj, 30.0f) != 0) {
                    if (obj[0x43] != 0) {
                        func_003BE4F0(obj, 0, 0, 10);
                    }
                    func_L01_00441FB8(obj, 1, -1);
                }
            } else if (obj[0x42] == 7) {
                f32 t = func_L01_00436500(obj);
                if (t > 14.0f && t < 18.0f) {
                    func_L24_00356550(obj, (s32)s, 4, 11, 0.25f);
                }
                if (func_L01_0044AF40(obj, 30.0f) != 0) {
                    if (obj[0x43] != 0) {
                        func_003BE4F0(obj, 0, 0, 10);
                    }
                    func_L01_00441FB8(obj, 1, -1);
                }
            } else if (obj[0x42] == 4) {
                func_L24_003562A0(obj, s);
                if (func_L01_0044AF40(obj, 35.0f) != 0) {
                    if (obj[0x43] != 0) {
                        func_003BE4F0(obj, 0, 0, 10);
                    }
                    func_L01_00441FB8(obj, 1, -1);
                }
            }
            break;
        case 2:
            func_L24_003550C8(obj, s);
            if (dir != 0) {
                *(f32 *)(obj + 0x10) -= (f32)dir * 0.175000011921f;
            }
            if (obj[0x42] == 1 || obj[0x43] == 10) {
                f32 f = func_L01_00436500(obj);
                if (f > 8.0f && f < 24.0f) {
                    u[0] = 1.0f;
                    u[2] = 0.0f;
                    u[1] = 0.0f;
                    func_00388830(e, u, (f32)*(s32 *)(s + 0x8E0) * -0.09375f);
                    vec_add_ba(pos, obj + 0x10, e);
                }
                if (f > 8.0f && f < 16.0f) {
                    func_003BEC60(&pos[2], func_003BE7F0(obj + 0x10, 0, 0, 0.5f) + 3.5f, s + 0x8B4, 0.41666669f, 0.20833334f, 0.4375f);
                }
                if (f == 16.0f) {
                    *(f32 *)(s + 0x8B4) = 0.0f;
                    if (*(s32 *)(s + 0x8DC) != 0 && obj[0x43] != 10) {
                        func_003BE4F0(obj, 10, 16, 0);
                    }
                }
                if (f > 16.0f && f < 24.0f) {
                    func_003BEC60(&pos[2], func_003BE7F0(obj + 0x10, 0, 0, 0.5f), s + 0x8B4, 0.036458332f, 0.21875f, 0.4375f);
                }
                if (f > 8.0f && f < 24.0f) {
                    vec_sub_ab(d, pos, obj + 0x10);
                    *(vu0_q *)(obj + 0x10) = *(vu0_q *)pos;
                }
                if (obj[0x42] == 1 && func_L01_0044AF40(obj, 26.0f) != 0) {
                    if (obj[0x43] != 0) {
                        func_003BE4F0(obj, 0, 0, 10);
                    }
                    func_L01_00441FB8(obj, 1, -1);
                } else if (obj[0x42] == 10 && func_L01_0044AF40(obj, 30.0f) != 0) {
                    if (obj[0x43] != 0) {
                        func_003BE4F0(obj, 0, 0, 10);
                    }
                    func_L01_00441FB8(obj, 1, -1);
                }
            }
            break;
        case 7:
            func_L24_003550C8(obj, s);
            func_L24_003562A0(obj, s);
            if (obj[0x42] == 1 || obj[0x43] == 10) {
                f32 f = func_L01_00436500(obj);
                if (f > 8.0f && f < 24.0f) {
                    f32 z = 0.0f;
                    u[0] = 1.0f;
                    u[2] = z;
                    u[1] = z;
                    func_00388830(e, u, z);
                    vec_add_ba(pos, obj + 0x10, e);
                }
                if (f > 8.0f && f < 16.0f) {
                    func_003BEC60(&pos[2], func_003BE7F0(obj + 0x10, 0, 0, 0.5f) + 3.5f, s + 0x8B4, 0.41666669f, 0.20833334f, 0.4375f);
                }
                if (f == 16.0f) {
                    *(f32 *)(s + 0x8B4) = 0.0f;
                    if (*(s32 *)(s + 0x8DC) != 0 && obj[0x43] != 10) {
                        func_003BE4F0(obj, 10, 16, 0);
                    }
                }
                if (f > 16.0f && f < 24.0f) {
                    func_003BEC60(&pos[2], func_003BE7F0(obj + 0x10, 0, 0, 0.5f), s + 0x8B4, 0.036458332f, 0.21875f, 0.4375f);
                }
                if (f > 8.0f && f < 24.0f) {
                    vec_sub_ab(d, pos, obj + 0x10);
                    *(vu0_q *)(obj + 0x10) = *(vu0_q *)pos;
                }
                if (obj[0x42] == 1 && func_L01_0044AF40(obj, 26.0f) != 0) {
                    if (obj[0x43] != 0) {
                        func_003BE4F0(obj, 0, 0, 10);
                    }
                    func_L01_00441FB8(obj, 1, -1);
                } else if (obj[0x42] == 10 && func_L01_0044AF40(obj, 30.0f) != 0) {
                    if (obj[0x43] != 0) {
                        func_003BE4F0(obj, 0, 0, 10);
                    }
                    func_L01_00441FB8(obj, 1, -1);
                }
            }
            break;
        }
    }
    func_L24_00357D28(obj);
}
/* localdecomp:end func_L24_00355130 */
