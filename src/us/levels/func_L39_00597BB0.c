#include "common.h"

/* NTSC-U counterpart of func_L39_00598E80 (src/levels/shared/L39_00598E80.c) */
extern void func_L39_005F0E48(s32, s32, s32);

/* localdecomp:start func_L39_00597BB0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00598E80;
typedef struct { V4_00598E80 a, b; } P32_00598E80;
typedef struct { V4_00598E80 r[4]; } M4_00598E80;

typedef struct {
    V4_00598E80 f00;
    V4_00598E80 f10;
    V4_00598E80 f20;
    V4_00598E80 f30;
    s32 f40;
    s32 f44;
    u8 pad48[0x54 - 0x48];
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x68 - 0x64];
    s32 f68;
    f32 f6C;
    f32 f70;
    u8 pad74[0x7C - 0x74];
    s16 s7C;
    s16 s7E;
    u8 pad80[0x84 - 0x80];
    s16 s84;
    u8 pad86[0x8C - 0x86];
    u32 f8C;
    u32 f90;
    s32 f94;
} S_00598E80;

typedef struct {
    u8 pad00[0x148];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1A4 - 0x150];
    u32 f1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    u32 f1C0;
    u32 f1C4;
} Pad_00598E80;

typedef struct {
    u8 pad00[0x64];
    void (*f64)(void *);
    u8 pad68[0xAA - 0x68];
    s16 fAA;
    u8 padAC[0x100 - 0xAC];
} Obj_00598E80;

typedef struct {
    u8 pad00[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
} Cam_00598E80;

extern s32 func_L39_005EF018(void);
extern void func_L01_00457268(s32);
extern void func_L39_005BD7D8(s32, s32, s32, s32, s32);
extern void func_L01_004300A8(void);
extern void func_L39_005F9608(void);
extern void func_L01_00430208(void);
extern void func_00397200(void);
extern void func_L01_003EFA70_00597BB0(void);
extern s32 func_L39_005BD880(s32, s32);
extern void func_L01_004179B8(s32);
extern f32 func_00388770(void *);
extern void func_003BEC60(f32 *, f32 *, f32, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003DE260(void *, s32);
extern void func_003888C8(void *, void *, void *);
extern void func_003BF640(void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003DE430(void *);
extern void func_003BF360(void *, void *);
extern void func_003886C0(void *, void *, void *, f32);
extern void func_003BEA80(void *, void *);
extern void func_00388E78(void *, void *);
extern void func_00388F90(void *, void *, void *, f32);
extern void func_003890D8(void *, void *);
extern void func_003DE3A8(void *);
extern void func_L01_0041FC58(void);
extern void func_L01_00416618(void);
extern void func_L01_00416630(void);
extern void func_L39_005F0E48(s32, s32, s32);
extern void func_003DBE20(void);
extern void func_L39_0057A218(void);

extern S_00598E80 D_L39_0025F540_00597BB0;
extern P32_00598E80 D_L39_0024DF00[];
extern f32 D_L39_0024BD50;
__asm__(".extern D_L39_0024BD50, 16");
extern Cam_00598E80 D_001A4560;
extern Pad_00598E80 *D_L39_002412E4;
__asm__(".extern D_L39_002412E4, 16");
extern Obj_00598E80 *D_L39_0024C05C;
extern Obj_00598E80 *D_L39_0024C060;
__asm__(".extern D_L39_0024C060, 16");
extern s32 D_L39_00240578;
__asm__(".extern D_L39_00240578, 16");
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024057C, 16");
extern s32 D_L39_0024145C;
__asm__(".extern D_L39_0024145C, 16");
extern s32 D_L39_00241520;
__asm__(".extern D_L39_00241520, 16");
extern s32 D_L39_002415C0;
__asm__(".extern D_L39_002415C0, 16");
extern s32 D_L39_00242A90;
extern u8 D_L39_00242B2C;
__asm__(".extern D_L39_00242B2C, 16");
extern u8 D_L39_00242B2D;
__asm__(".extern D_L39_00242B2D, 16");
extern u8 D_L39_00243B34;
__asm__(".extern D_L39_00243B34, 16");
extern u8 D_L39_0024BF70;
__asm__(".extern D_L39_0024BF70, 16");
extern s32 D_L39_0024BC90;
__asm__(".extern D_L39_0024BC90, 16");
extern s32 D_L39_0024BC94;
__asm__(".extern D_L39_0024BC94, 16");
extern s32 D_001D71A4_sda_00597BB0;
__asm__(".extern D_001D71A4_sda_00597BB0, 4");
extern f32 D_001D71A8_sda_00597BB0;
__asm__(".extern D_001D71A8_sda_00597BB0, 4");
extern s32 D_001D7170_sda_00597BB0;
__asm__(".extern D_001D7170_sda_00597BB0, 4");
extern s32 D_001D7174_sda_00597BB0;
__asm__(".extern D_001D7174_sda_00597BB0, 4");
extern s32 D_001D7178_sda_00597BB0;
__asm__(".extern D_001D7178_sda_00597BB0, 4");

void func_L39_00597BB0(void) {
    V4_00598E80 v0;
    V4_00598E80 v10;
    M4_00598E80 m20;
    f32 len;
    Obj_00598E80 *p;

    func_L39_005EF018();
    D_L39_0024BC90 = D_L39_0025F540_00597BB0.f94;
    if (D_L39_0025F540_00597BB0.f44 != 0) {
        D_L39_0025F540_00597BB0.f44--;
    }
    if (D_L39_0025F540_00597BB0.s7C != 0) {
        D_L39_0025F540_00597BB0.s7C--;
    }
    switch (D_L39_0025F540_00597BB0.f40) {
    case 1:
        if (D_L39_00242A90 == -2) {
            D_L39_0025F540_00597BB0.f5C++;
            if (D_L39_0025F540_00597BB0.f5C >= 0x1F) {
                if (D_L39_0025F540_00597BB0.f60 != 0) {
                    D_L39_0025F540_00597BB0.f60--;
                }
            }
            switch (D_L39_00240578) {
            case 3:
                if (D_L39_0025F540_00597BB0.f60 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x40) {
                        D_L39_0025F540_00597BB0.s84 = 2;
                        D_L39_0024057C &= ~1;
                        if (D_L39_00242B2D != 0) {
                            func_L01_00457268(5);
                            func_L39_005BD7D8(3, 2, 7, 0, 0);
                        } else {
                            func_L39_005BD880(0, 0);
                        }
                    }
                }
                break;
            case 8:
                if (D_L39_0025F540_00597BB0.f60 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x20) {
                        D_L39_0025F540_00597BB0.s84 = 2;
                        D_L39_0024057C |= 8;
                        break;
                    }
                }
                if (D_L39_0025F540_00597BB0.f44 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x10) {
                        if (D_L39_00242B2D != 0) {
                            D_L39_0025F540_00597BB0.s84 = 2;
                            func_L39_005F9608();
                        } else {
                            D_L39_0025F540_00597BB0.s84 = 1;
                            D_L39_0024057C |= 0x20;
                            D_L39_0024057C &= ~2;
                            D_L39_0024057C &= ~4;
                            if (D_L39_00242B2C == 0) {
                                func_L39_005BD880(6, 0);
                            }
                        }
                    }
                }
                break;
            case 15:
                if (D_L39_0025F540_00597BB0.f60 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x20) {
                        func_L01_004300A8();
                        D_L39_0025F540_00597BB0.s84 = 2;
                        break;
                    }
                }
                if (D_L39_0025F540_00597BB0.f44 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x10) {
                        if (D_L39_00242B2D != 0) {
                            D_L39_0025F540_00597BB0.s84 = 2;
                            func_L39_005F9608();
                        } else {
                            D_L39_0025F540_00597BB0.s84 = 1;
                            D_L39_0024057C |= 0x20;
                            D_L39_0024057C &= ~2;
                            D_L39_0024057C &= ~4;
                            if (D_L39_00242B2C == 0) {
                                func_L39_005BD880(0, 0);
                            }
                        }
                    }
                }
                break;
            case 33: {
                u32 pad = D_L39_002412E4->f1A4;
                if (pad & 0x20) {
                    func_L01_004300A8();
                } else if (pad & 0x10) {
                    func_L01_00430208();
                    func_00397200();
                }
                break;
            }
            case 22:
                if (D_L39_0025F540_00597BB0.f60 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x40) {
                        D_L39_0024057C &= ~0x40;
                        D_L39_0024057C &= ~0x400;
                        D_L39_0024057C &= ~2;
                        D_L39_0024057C &= ~4;
                        D_L39_0025F540_00597BB0.s84 = 2;
                        {
                            u8 online = D_L39_00242B2C;
                            if (online != 0) {
                                func_L39_005BD880(0, 0);
                            } else {
                                func_L39_005BD880(online, 0);
                            }
                        }
                    }
                }
                break;
            case 19:
            case 20:
            case 24:
                if (D_L39_0025F540_00597BB0.f68 > 0) {
                    if (--D_L39_0025F540_00597BB0.f68 <= 0) {
                        if (D_001A4560.f8 == 2) {
                            s32 v = D_001A4560.f10;
                            if (v == 0) {
                                D_L39_00240578 = 0xB;
                            } else if (v == -1) {
                                D_L39_00240578 = 0xB;
                                D_001A4560.f10 = 0;
                            } else if (v == -2) {
                                D_L39_00240578 = 7;
                            } else {
                                D_L39_00240578 = 0xE;
                            }
                            func_L39_005BD880(0, 0);
                        } else {
                            D_L39_0025F540_00597BB0.s84 = 2;
                            func_L39_005F9608();
                        }
                    }
                } else if (D_L39_0025F540_00597BB0.f60 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x40) {
                        if (D_L39_00242B2D != 0) {
                            D_L39_0025F540_00597BB0.f68 = 0xF;
                        } else {
                            D_L39_0024057C &= ~0x40;
                            D_L39_0024057C &= ~0x400;
                            D_L39_0024057C &= ~2;
                            D_L39_0025F540_00597BB0.s84 = 2;
                            D_L39_0024057C &= ~4;
                            func_L39_005BD880(0, 0);
                            if (D_L39_00243B34 != 0) {
                                func_L01_004179B8(1);
                            } else {
                                func_L01_004179B8(7);
                            }
                        }
                    }
                }
                break;
            case 1:
            case 18:
                if ((D_L39_0024057C & 6) == 0) {
                    func_L39_005BD880(0, 0);
                }
                break;
            case 14:
                func_L39_005BD880(0, 0);
            case 4:
            case 5:
            case 7:
                if (D_L39_0025F540_00597BB0.f60 == 0) {
                    if (D_L39_002412E4->f1A4 & 0x40) {
                        D_L39_0024057C &= ~2;
                        D_L39_0025F540_00597BB0.s84 = 1;
                        D_L39_0024057C &= ~4;
                        func_L39_005BD880(0, 0);
                    }
                }
                break;
            case 21:
                if (D_L39_00242B2C != 0 && D_L39_0024BF70 == 0) {
                    if (D_L39_0025F540_00597BB0.f60 == 0) {
                        if (D_L39_002412E4->f1A4 & 0x40) {
                            func_L01_003EFA70_00597BB0();
                            D_L39_0024057C &= ~2;
                            D_L39_0025F540_00597BB0.s84 = 2;
                            D_L39_0024057C &= ~4;
                            D_L39_0024057C |= 0x20;
                            func_L39_005F9608();
                        }
                    }
                    break;
                }
                if (D_L39_00242B2D != 0) {
                    if (D_L39_0025F540_00597BB0.f60 == 0) {
                        if (D_L39_002412E4->f1A4 & 0x40) {
                            D_L39_0025F540_00597BB0.s84 = 2;
                            func_L39_005F9608();
                        }
                    }
                } else {
                    if (D_L39_0025F540_00597BB0.f60 == 0) {
                        if (D_L39_002412E4->f1A4 & 0x40) {
                            D_L39_0024057C &= ~2;
                            D_L39_0025F540_00597BB0.s84 = 2;
                            D_L39_0024057C &= ~4;
                            func_L39_005BD880(0, 0);
                        }
                    }
                }
                break;
            case 26:
            case 27:
                if (D_L39_0025F540_00597BB0.f60 == 0) {
                    u32 pad = D_L39_002412E4->f1A4;
                    if (pad & 0x40) {
                        func_L01_003EFA70_00597BB0();
                        D_L39_0024057C &= ~2;
                        D_L39_0025F540_00597BB0.s84 = 2;
                        D_L39_0024057C &= ~4;
                        D_L39_0024057C |= 0x20;
                        func_L39_005F9608();
                    } else if (pad & 0x10) {
                        D_L39_0025F540_00597BB0.s84 = 1;
                        D_L39_0024057C |= 0x20;
                        func_L39_005BD880(0, 0);
                    }
                }
                break;
            case 6:
                if (D_L39_00242B2C != 0) {
                    if (D_L39_0024BF70 == 0) {
                        if (D_L39_0025F540_00597BB0.f60 == 0) {
                            if (D_L39_002412E4->f1A4 & 0x40) {
                                func_L01_003EFA70_00597BB0();
                                D_L39_0024057C &= ~2;
                                D_L39_0025F540_00597BB0.s84 = 2;
                                D_L39_0024057C &= ~4;
                                func_L39_005F9608();
                            }
                            if (D_L39_0025F540_00597BB0.f60 == 0) {
                                if (D_L39_002412E4->f1A4 & 0x10) {
                                    D_L39_0025F540_00597BB0.s84 = 1;
                                    D_L39_0024057C |= 0x20;
                                    D_L39_0024057C &= ~2;
                                    D_L39_0024057C &= ~4;
                                    func_L39_005BD880(0, 0);
                                }
                            }
                        }
                    } else {
                        if (D_L39_0025F540_00597BB0.f60 == 0) {
                            if (D_L39_002412E4->f1A4 & 0x40) {
                                D_L39_0025F540_00597BB0.s84 = 1;
                                D_L39_0024057C |= 0x20;
                                D_L39_0024057C &= ~2;
                                D_L39_0024057C &= ~4;
                                func_L39_005BD880(0, 0);
                            }
                        }
                    }
                } else if (D_L39_00242B2D != 0) {
                    if (D_L39_0025F540_00597BB0.f60 == 0) {
                        if (D_L39_002412E4->f1A4 & 0x20) {
                            D_L39_0025F540_00597BB0.s84 = 2;
                            func_L39_005F9608();
                        }
                    }
                } else {
                    if (D_L39_0025F540_00597BB0.f60 == 0) {
                        u32 pad = D_L39_002412E4->f1A4;
                        if (pad & 0x20) {
                            D_L39_0025F540_00597BB0.s84 = 1;
                            D_L39_0024057C |= 0x20;
                            D_L39_0024057C &= ~2;
                            D_L39_0024057C &= ~4;
                            func_L39_005BD880(0, 0);
                        } else if (pad & 0x10) {
                            D_L39_0025F540_00597BB0.s84 = 1;
                            D_L39_0024057C |= 0x20;
                            D_L39_0024057C &= ~2;
                            D_L39_0024057C &= ~4;
                            func_L39_005BD880(0, 0);
                            D_L39_002415C0 = 7;
                        }
                    }
                }
                break;
            case 11:
                if ((D_L39_0024057C & 6) == 0) {
                    func_L39_005BD880(0, 0);
                }
                break;
            }
        }
        break;
    case 6:
        switch (D_L39_0025F540_00597BB0.f58) {
        case 0:
            *(P32_00598E80 *)&D_L39_0025F540_00597BB0 = D_L39_0024DF00[0];
            D_L39_0025F540_00597BB0.f58 = 1;
            if (D_L39_0024145C == 0xB) {
                if (D_L39_0024BD50 == 200.0f) {
                    D_001D71A4_sda_00597BB0 = 0xAF;
                } else {
                    D_001D71A4_sda_00597BB0 = 0x7D;
                }
            }
            break;
        case 1:
            if (D_L39_0024145C != 0xB) {
                D_L39_0024BC90 = 3;
            }
            vec_sub_ba(&v0, &D_L39_0024DF00[0], &D_L39_0024BD50);
            len = func_00388770(&v0);
            func_003BEC60(&len, &D_L39_0025F540_00597BB0.f6C, (f32)D_001D71A4_sda_00597BB0, 0.0416666679084f, 0.0416666679084f, 5.00000047684f);
            func_00388830(&v0, &v0, len);
            vec_add_ab(&D_L39_0024DF00[0], &v0, &D_L39_0024BD50);
            func_003DE260(&D_L39_0025F540_00597BB0.f70, 0);
            if ((f32)D_001D71A4_sda_00597BB0 <= len) {
                D_L39_0025F540_00597BB0.f58 = 2;
            }
            break;
        case 2:
            if (D_L39_0024145C != 0xB) {
                D_L39_0024BC90 = 3;
            }
            if (D_L39_002412E4->f148 != 0.0f || D_L39_002412E4->f14C != 0.0f) {
                v10 = (V4_00598E80){0};
                v10.y = D_L39_002412E4->f148;
                v10.z = D_L39_002412E4->f14C;
                v0 = v10;
                func_003888C8(&v0, &v0, &D_L39_0024DF00[1]);
                func_003BF640(&v0, 1.0f);
                func_003886E8(&v0, &v0, (f32)-D_001D71A4_sda_00597BB0 * (D_001D71A8_sda_00597BB0 * 0.0174532924f * 0.0166666675359f));
                func_003DE430(&v0);
            }
            func_003DE260(&D_L39_0025F540_00597BB0.f70, 1);
            func_003DE3A8((u8 *)D_L39_002412E4 + 0x100);
            break;
        case 3: {
            f32 a;
            f32 f20;
            V4_00598E80 *pos;
            if (D_L39_0024145C != 0xB) {
                D_L39_0024BC90 = 3;
            }
            a = (f32)D_001D71A4_sda_00597BB0;
            f20 = a * (D_001D71A8_sda_00597BB0 * 0.0174532924f * 0.0166666675359f);
            vec_sub_ab(&v10, &D_L39_0025F540_00597BB0.f00, &D_L39_0024BD50);
            func_00388830(&v10, &v10, a);
            vec_add_ab(&v10, &v10, &D_L39_0024BD50);
            vec_sub_ba(&v0, &v10, &D_L39_0024DF00[0]);
            func_00388E78(&m20, &D_L39_0024DF00[1]);
            func_003888C8(&v0, &v0, &m20);
            v0.x = 0.0f;
            if (v0.y == v0.x && v0.z == v0.x) {
                v0.y = 1.0f;
            }
            func_003BF640(&v0, f20);
            func_003888C8(&v0, &v0, &D_L39_0024DF00[1]);
            func_003DE430(&v0);
            func_003DE260(&D_L39_0025F540_00597BB0.f70, 1);
            if (func_00388770(&v0) < f20 - 0.00999999978f) {
                D_L39_0024BC94 = 2;
                pos = &D_L39_0025F540_00597BB0.f20;
                *pos = D_L39_0024DF00[0].a;
                func_003BF360(&D_L39_0024DF00[1], &D_L39_0025F540_00597BB0.f30);
                D_L39_0025F540_00597BB0.f58 = 4;
            }
            break;
        }
        case 4:
            if (D_L39_0024145C != 0xB) {
                D_L39_0024BC90 = 3;
            }
            func_003BEC60(&D_L39_0025F540_00597BB0.f6C, &D_L39_0025F540_00597BB0.f70, 1.0f, 0.000555555569008f, 0.000555555569008f, 0.0250000022352f);
            func_003886C0(&D_L39_0024DF00[0], &D_L39_0025F540_00597BB0.f20, &D_L39_0025F540_00597BB0, D_L39_0025F540_00597BB0.f6C);
            func_003BEA80(&v0, &D_L39_0025F540_00597BB0.f30);
            func_003BEA80(&v10, &D_L39_0025F540_00597BB0.f10);
            func_00388F90(&m20, &v0, &v10, D_L39_0025F540_00597BB0.f6C);
            func_003890D8(&m20, &D_L39_0024DF00[1]);
            if (1.0f <= D_L39_0025F540_00597BB0.f6C) {
                func_L39_005BD880(0, 0);
            }
            break;
        }
        D_L39_0025F540_00597BB0.s7E = 1;
        if (D_L39_002412E4->f1A4 & 0x500) {
            if (D_L39_0025F540_00597BB0.f58 == 2) {
                D_L39_0025F540_00597BB0.f70 = 0;
                D_L39_0025F540_00597BB0.f6C = 0;
                D_L39_0025F540_00597BB0.f58 = 3;
            }
        }
        if (D_L39_0024145C == 0x16 || D_L39_0024145C == 0x17) {
            for (p = D_L39_0024C05C; p < D_L39_0024C060; p++) {
                if (p->fAA == 0xD3D) {
                    if (p->f64 != 0) {
                        p->f64(p);
                    }
                }
            }
        }
        break;
    case 7:
        if (D_L39_0025F540_00597BB0.f58 == 0) {
            D_L39_0025F540_00597BB0.s7E = 1;
            D_L39_0025F540_00597BB0.f58 = 1;
            D_001D7170_sda_00597BB0 = D_001D7174_sda_00597BB0;
            D_001D7178_sda_00597BB0 = 0;
            func_L01_0041FC58();
            func_L01_00416618();
        }
        break;
    case 8:
        if (D_L39_0025F540_00597BB0.f58 != 2) {
            if (D_L39_0025F540_00597BB0.f58 < 3) {
                if (D_L39_0025F540_00597BB0.f58 >= 0) {
                    D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
                }
            }
        } else {
            func_L39_005BD7D8(3, 2, D_L39_0025F540_00597BB0.f54, 0, 0);
            func_L01_00457268(3);
            D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
        }
        break;
    case 9:
        switch (D_L39_0025F540_00597BB0.f58) {
        case 1:
            if (D_L39_002412E4->f1C4 & D_L39_0025F540_00597BB0.f8C) {
                D_L39_0025F540_00597BB0.s84 = 2;
                func_L39_005BD880(0, 0);
            } else if (D_L39_002412E4->f1C4 & D_L39_0025F540_00597BB0.f90) {
                D_L39_0025F540_00597BB0.s84 = 1;
                func_L39_005BD880(0, 0);
            }
            break;
        case 0:
            func_L01_00416630();
            D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
            break;
        }
        break;
    case 10:
        switch (D_L39_0025F540_00597BB0.f58) {
        case 0:
            func_L01_00416630();
            D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
            break;
        case 1:
            if (D_L39_002412E4->f1C4 & D_L39_0025F540_00597BB0.f8C) {
                D_L39_0025F540_00597BB0.s84 = 2;
                func_L39_005F0E48(0x12, 0, 0);
                func_L39_005BD880(0, 0);
            }
            break;
        }
        break;
    case 11:
        switch (D_L39_0025F540_00597BB0.f58) {
        case 0:
            func_L01_00416630();
            D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
            if (D_L39_00241520 != 0) {
                D_L39_00241520 = !D_L39_00241520;
                func_003DBE20();
                func_L39_005BD880(D_L39_0025F540_00597BB0.f54, 0);
            }
            break;
        case 1:
            if (D_L39_002412E4->f1C4 & 0x40) {
                D_L39_0025F540_00597BB0.s84 = 2;
                D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
            } else if (D_L39_002412E4->f1C0 & 0x10) {
                D_L39_0025F540_00597BB0.s84 = 1;
                func_L39_005BD880(D_L39_0025F540_00597BB0.f54, 0);
            }
            break;
        case 2:
            D_L39_0025F540_00597BB0.f5C = 0x384;
            D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
            D_L39_0025F540_00597BB0.f60 = 0;
            D_L39_0025F540_00597BB0.s84 = 0;
            D_L39_00241520 = !D_L39_00241520;
            func_003DBE20();
            break;
        case 3:
            if (D_L39_002412E4->f1C4 & 0x20) {
                D_L39_0025F540_00597BB0.s84 = 2;
            } else if (D_L39_002412E4->f1C4 & 0x10) {
                D_L39_0025F540_00597BB0.s84 = 1;
            }
            if (--D_L39_0025F540_00597BB0.f5C > 0) {
                if (D_L39_0025F540_00597BB0.s84 == 0) {
                    break;
                }
            }
            D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
            break;
        case 4:
            if (D_L39_0025F540_00597BB0.s84 >= 0) {
                if (D_L39_0025F540_00597BB0.s84 < 2) {
                    D_L39_00241520 = !D_L39_00241520;
                    func_003DBE20();
                }
            }
            D_L39_0025F540_00597BB0.f58 = D_L39_0025F540_00597BB0.f58 + 1;
            break;
        case 5:
            func_L39_005BD880(D_L39_0025F540_00597BB0.f54, 0);
            break;
        }
        break;
    case 12:
        func_L39_0057A218();
        break;
    }
}
/* localdecomp:end func_L39_00597BB0 */
