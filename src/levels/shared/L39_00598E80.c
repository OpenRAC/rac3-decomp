#include "common.h"

/* declared by functions of L39_00598780.c, which this file was cut from */
extern void func_L39_005F3548(s32, s32, s32);

/* localdecomp:start func_L39_00598E80 */
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

extern s32 func_L39_005F1718(void);
extern void func_L01_0045A570(s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L01_00432F38(void);
extern void func_L39_005FBDA0(void);
extern void func_L01_00433098(void);
extern void func_0039BFF0(void);
extern void func_L01_003F19B0_00598E80(void);
extern s32 func_L39_005BF840(s32, s32);
extern void func_L01_0041A008(s32);
extern f32 func_0038CEA8(void *);
extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003E37B0(void *, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C4BB0(void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003E3980(void *);
extern void func_003C48A8(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_003C3FC0(void *, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D6C8(void *, void *, void *, f32);
extern void func_0038D810(void *, void *);
extern void func_003E38F8(void *);
extern void func_L01_00422388(void);
extern void func_L01_00418C68(void);
extern void func_L01_00418C80(void);
extern void func_L39_005F3548(s32, s32, s32);
extern void func_003E1370(void);
extern void func_L39_0057B1C0(void);

extern S_00598E80 D_L39_0025F440_00598E80;
extern P32_00598E80 D_L39_0024DE00[];
extern f32 D_L39_0024BC50;
__asm__(".extern D_L39_0024BC50, 16");
extern Cam_00598E80 D_001A43E0;
extern Pad_00598E80 *D_L39_00241164;
__asm__(".extern D_L39_00241164, 16");
extern Obj_00598E80 *D_L39_0024BF5C;
extern Obj_00598E80 *D_L39_0024BF60;
__asm__(".extern D_L39_0024BF60, 16");
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern s32 D_L39_002413A0;
__asm__(".extern D_L39_002413A0, 16");
extern s32 D_L39_00241440;
__asm__(".extern D_L39_00241440, 16");
extern s32 D_L39_00242910;
extern u8 D_L39_002429AC;
__asm__(".extern D_L39_002429AC, 16");
extern u8 D_L39_002429AD;
__asm__(".extern D_L39_002429AD, 16");
extern u8 D_L39_002439FC;
__asm__(".extern D_L39_002439FC, 16");
extern u8 D_L39_0024BE70;
__asm__(".extern D_L39_0024BE70, 16");
extern s32 D_L39_0024BB90;
__asm__(".extern D_L39_0024BB90, 16");
extern s32 D_L39_0024BB94;
__asm__(".extern D_L39_0024BB94, 16");
extern s32 D_001D71A4_sda;
__asm__(".extern D_001D71A4_sda, 4");
extern f32 D_001D71A8_sda;
__asm__(".extern D_001D71A8_sda, 4");
extern s32 D_001D7170_sda;
__asm__(".extern D_001D7170_sda, 4");
extern s32 D_001D7174_sda;
__asm__(".extern D_001D7174_sda, 4");
extern s32 D_001D7178_sda;
__asm__(".extern D_001D7178_sda, 4");

void func_L39_00598E80(void) {
    V4_00598E80 v0;
    V4_00598E80 v10;
    M4_00598E80 m20;
    f32 len;
    Obj_00598E80 *p;

    func_L39_005F1718();
    D_L39_0024BB90 = D_L39_0025F440_00598E80.f94;
    if (D_L39_0025F440_00598E80.f44 != 0) {
        D_L39_0025F440_00598E80.f44--;
    }
    if (D_L39_0025F440_00598E80.s7C != 0) {
        D_L39_0025F440_00598E80.s7C--;
    }
    switch (D_L39_0025F440_00598E80.f40) {
    case 1:
        if (D_L39_00242910 == -2) {
            D_L39_0025F440_00598E80.f5C++;
            if (D_L39_0025F440_00598E80.f5C >= 0x1A) {
                if (D_L39_0025F440_00598E80.f60 != 0) {
                    D_L39_0025F440_00598E80.f60--;
                }
            }
            switch (D_L39_002403F8) {
            case 3:
                if (D_L39_0025F440_00598E80.f60 == 0) {
                    if (D_L39_00241164->f1A4 & 0x40) {
                        D_L39_0025F440_00598E80.s84 = 2;
                        D_L39_002403FC &= ~1;
                        if (D_L39_002429AD != 0) {
                            func_L01_0045A570(5);
                            func_L39_005BF798(3, 2, 7, 0, 0);
                        } else {
                            func_L39_005BF840(0, 0);
                        }
                    }
                }
                break;
            case 8:
                if (D_L39_0025F440_00598E80.f60 == 0) {
                    if (D_L39_00241164->f1A4 & 0x20) {
                        D_L39_0025F440_00598E80.s84 = 2;
                        D_L39_002403FC |= 8;
                        break;
                    }
                }
                if (D_L39_0025F440_00598E80.f44 == 0) {
                    if (D_L39_00241164->f1A4 & 0x10) {
                        if (D_L39_002429AD != 0) {
                            D_L39_0025F440_00598E80.s84 = 2;
                            func_L39_005FBDA0();
                        } else {
                            D_L39_0025F440_00598E80.s84 = 1;
                            D_L39_002403FC |= 0x20;
                            D_L39_002403FC &= ~2;
                            D_L39_002403FC &= ~4;
                            if (D_L39_002429AC == 0) {
                                func_L39_005BF840(6, 0);
                            }
                        }
                    }
                }
                break;
            case 15:
                if (D_L39_0025F440_00598E80.f60 == 0) {
                    if (D_L39_00241164->f1A4 & 0x20) {
                        func_L01_00432F38();
                        D_L39_0025F440_00598E80.s84 = 2;
                        break;
                    }
                }
                if (D_L39_0025F440_00598E80.f44 == 0) {
                    if (D_L39_00241164->f1A4 & 0x10) {
                        if (D_L39_002429AD != 0) {
                            D_L39_0025F440_00598E80.s84 = 2;
                            func_L39_005FBDA0();
                        } else {
                            D_L39_0025F440_00598E80.s84 = 1;
                            D_L39_002403FC |= 0x20;
                            D_L39_002403FC &= ~2;
                            D_L39_002403FC &= ~4;
                            if (D_L39_002429AC == 0) {
                                func_L39_005BF840(0, 0);
                            }
                        }
                    }
                }
                break;
            case 33: {
                u32 pad = D_L39_00241164->f1A4;
                if (pad & 0x20) {
                    func_L01_00432F38();
                } else if (pad & 0x10) {
                    func_L01_00433098();
                    func_0039BFF0();
                }
                break;
            }
            case 22:
                if (D_L39_0025F440_00598E80.f60 == 0) {
                    if (D_L39_00241164->f1A4 & 0x40) {
                        D_L39_002403FC &= ~0x40;
                        D_L39_002403FC &= ~0x400;
                        D_L39_002403FC &= ~2;
                        D_L39_002403FC &= ~4;
                        D_L39_0025F440_00598E80.s84 = 2;
                        {
                            u8 online = D_L39_002429AC;
                            if (online != 0) {
                                func_L39_005BF840(0, 0);
                            } else {
                                func_L39_005BF840(online, 0);
                            }
                        }
                    }
                }
                break;
            case 19:
            case 20:
            case 24:
                if (D_L39_0025F440_00598E80.f68 > 0) {
                    if (--D_L39_0025F440_00598E80.f68 <= 0) {
                        if (D_001A43E0.f8 == 2) {
                            s32 v = D_001A43E0.f10;
                            if (v == 0) {
                                D_L39_002403F8 = 0xB;
                            } else if (v == -1) {
                                D_L39_002403F8 = 0xB;
                                D_001A43E0.f10 = 0;
                            } else if (v == -2) {
                                D_L39_002403F8 = 7;
                            } else {
                                D_L39_002403F8 = 0xE;
                            }
                            func_L39_005BF840(0, 0);
                        } else {
                            D_L39_0025F440_00598E80.s84 = 2;
                            func_L39_005FBDA0();
                        }
                    }
                } else if (D_L39_0025F440_00598E80.f60 == 0) {
                    if (D_L39_00241164->f1A4 & 0x40) {
                        if (D_L39_002429AD != 0) {
                            D_L39_0025F440_00598E80.f68 = 0xC;
                        } else {
                            D_L39_002403FC &= ~0x40;
                            D_L39_002403FC &= ~0x400;
                            D_L39_002403FC &= ~2;
                            D_L39_0025F440_00598E80.s84 = 2;
                            D_L39_002403FC &= ~4;
                            func_L39_005BF840(0, 0);
                            if (D_L39_002439FC != 0) {
                                func_L01_0041A008(1);
                            } else {
                                func_L01_0041A008(7);
                            }
                        }
                    }
                }
                break;
            case 1:
            case 18:
                if ((D_L39_002403FC & 6) == 0) {
                    func_L39_005BF840(0, 0);
                }
                break;
            case 14:
                func_L39_005BF840(0, 0);
            case 4:
            case 5:
            case 7:
                if (D_L39_0025F440_00598E80.f60 == 0) {
                    if (D_L39_00241164->f1A4 & 0x40) {
                        D_L39_002403FC &= ~2;
                        D_L39_0025F440_00598E80.s84 = 1;
                        D_L39_002403FC &= ~4;
                        func_L39_005BF840(0, 0);
                    }
                }
                break;
            case 21:
                if (D_L39_002429AC != 0 && D_L39_0024BE70 == 0) {
                    if (D_L39_0025F440_00598E80.f60 == 0) {
                        if (D_L39_00241164->f1A4 & 0x40) {
                            func_L01_003F19B0_00598E80();
                            D_L39_002403FC &= ~2;
                            D_L39_0025F440_00598E80.s84 = 2;
                            D_L39_002403FC &= ~4;
                            D_L39_002403FC |= 0x20;
                            func_L39_005FBDA0();
                        }
                    }
                    break;
                }
                if (D_L39_002429AD != 0) {
                    if (D_L39_0025F440_00598E80.f60 == 0) {
                        if (D_L39_00241164->f1A4 & 0x40) {
                            D_L39_0025F440_00598E80.s84 = 2;
                            func_L39_005FBDA0();
                        }
                    }
                } else {
                    if (D_L39_0025F440_00598E80.f60 == 0) {
                        if (D_L39_00241164->f1A4 & 0x40) {
                            D_L39_002403FC &= ~2;
                            D_L39_0025F440_00598E80.s84 = 2;
                            D_L39_002403FC &= ~4;
                            func_L39_005BF840(0, 0);
                        }
                    }
                }
                break;
            case 26:
            case 27:
                if (D_L39_0025F440_00598E80.f60 == 0) {
                    u32 pad = D_L39_00241164->f1A4;
                    if (pad & 0x40) {
                        func_L01_003F19B0_00598E80();
                        D_L39_002403FC &= ~2;
                        D_L39_0025F440_00598E80.s84 = 2;
                        D_L39_002403FC &= ~4;
                        D_L39_002403FC |= 0x20;
                        func_L39_005FBDA0();
                    } else if (pad & 0x10) {
                        D_L39_0025F440_00598E80.s84 = 1;
                        D_L39_002403FC |= 0x20;
                        func_L39_005BF840(0, 0);
                    }
                }
                break;
            case 6:
                if (D_L39_002429AC != 0) {
                    if (D_L39_0024BE70 == 0) {
                        if (D_L39_0025F440_00598E80.f60 == 0) {
                            if (D_L39_00241164->f1A4 & 0x40) {
                                func_L01_003F19B0_00598E80();
                                D_L39_002403FC &= ~2;
                                D_L39_0025F440_00598E80.s84 = 2;
                                D_L39_002403FC &= ~4;
                                func_L39_005FBDA0();
                            }
                            if (D_L39_0025F440_00598E80.f60 == 0) {
                                if (D_L39_00241164->f1A4 & 0x10) {
                                    D_L39_0025F440_00598E80.s84 = 1;
                                    D_L39_002403FC |= 0x20;
                                    D_L39_002403FC &= ~2;
                                    D_L39_002403FC &= ~4;
                                    func_L39_005BF840(0, 0);
                                }
                            }
                        }
                    } else {
                        if (D_L39_0025F440_00598E80.f60 == 0) {
                            if (D_L39_00241164->f1A4 & 0x40) {
                                D_L39_0025F440_00598E80.s84 = 1;
                                D_L39_002403FC |= 0x20;
                                D_L39_002403FC &= ~2;
                                D_L39_002403FC &= ~4;
                                func_L39_005BF840(0, 0);
                            }
                        }
                    }
                } else if (D_L39_002429AD != 0) {
                    if (D_L39_0025F440_00598E80.f60 == 0) {
                        if (D_L39_00241164->f1A4 & 0x20) {
                            D_L39_0025F440_00598E80.s84 = 2;
                            func_L39_005FBDA0();
                        }
                    }
                } else {
                    if (D_L39_0025F440_00598E80.f60 == 0) {
                        u32 pad = D_L39_00241164->f1A4;
                        if (pad & 0x20) {
                            D_L39_0025F440_00598E80.s84 = 1;
                            D_L39_002403FC |= 0x20;
                            D_L39_002403FC &= ~2;
                            D_L39_002403FC &= ~4;
                            func_L39_005BF840(0, 0);
                        } else if (pad & 0x10) {
                            D_L39_0025F440_00598E80.s84 = 1;
                            D_L39_002403FC |= 0x20;
                            D_L39_002403FC &= ~2;
                            D_L39_002403FC &= ~4;
                            func_L39_005BF840(0, 0);
                            D_L39_00241440 = 7;
                        }
                    }
                }
                break;
            case 11:
                if ((D_L39_002403FC & 6) == 0) {
                    func_L39_005BF840(0, 0);
                }
                break;
            }
        }
        break;
    case 6:
        switch (D_L39_0025F440_00598E80.f58) {
        case 0:
            *(P32_00598E80 *)&D_L39_0025F440_00598E80 = D_L39_0024DE00[0];
            D_L39_0025F440_00598E80.f58 = 1;
            if (D_L39_002412DC == 0xB) {
                if (D_L39_0024BC50 == 200.0f) {
                    D_001D71A4_sda = 0xAF;
                } else {
                    D_001D71A4_sda = 0x7D;
                }
            }
            break;
        case 1:
            if (D_L39_002412DC != 0xB) {
                D_L39_0024BB90 = 3;
            }
            vec_sub_ba(&v0, &D_L39_0024DE00[0], &D_L39_0024BC50);
            len = func_0038CEA8(&v0);
            func_003C41A0(&len, &D_L39_0025F440_00598E80.f6C, (f32)D_001D71A4_sda, 0.0600000024f, 0.0600000024f, 6.00000048f);
            func_0038CF68(&v0, &v0, len);
            vec_add_ab(&D_L39_0024DE00[0], &v0, &D_L39_0024BC50);
            func_003E37B0(&D_L39_0025F440_00598E80.f70, 0);
            if ((f32)D_001D71A4_sda <= len) {
                D_L39_0025F440_00598E80.f58 = 2;
            }
            break;
        case 2:
            if (D_L39_002412DC != 0xB) {
                D_L39_0024BB90 = 3;
            }
            if (D_L39_00241164->f148 != 0.0f || D_L39_00241164->f14C != 0.0f) {
                v10 = (V4_00598E80){0};
                v10.y = D_L39_00241164->f148;
                v10.z = D_L39_00241164->f14C;
                v0 = v10;
                func_0038D000(&v0, &v0, &D_L39_0024DE00[1]);
                func_003C4BB0(&v0, 1.0f);
                func_0038CE20(&v0, &v0, (f32)-D_001D71A4_sda * (D_001D71A8_sda * 0.0174532924f * 0.0200000014f));
                func_003E3980(&v0);
            }
            func_003E37B0(&D_L39_0025F440_00598E80.f70, 1);
            func_003E38F8((u8 *)D_L39_00241164 + 0x100);
            break;
        case 3: {
            f32 a;
            f32 f20;
            V4_00598E80 *pos;
            if (D_L39_002412DC != 0xB) {
                D_L39_0024BB90 = 3;
            }
            a = (f32)D_001D71A4_sda;
            f20 = a * (D_001D71A8_sda * 0.0174532924f * 0.0200000014f);
            vec_sub_ab(&v10, &D_L39_0025F440_00598E80.f00, &D_L39_0024BC50);
            func_0038CF68(&v10, &v10, a);
            vec_add_ab(&v10, &v10, &D_L39_0024BC50);
            vec_sub_ba(&v0, &v10, &D_L39_0024DE00[0]);
            func_0038D5B0(&m20, &D_L39_0024DE00[1]);
            func_0038D000(&v0, &v0, &m20);
            v0.x = 0.0f;
            if (v0.y == v0.x && v0.z == v0.x) {
                v0.y = 1.0f;
            }
            func_003C4BB0(&v0, f20);
            func_0038D000(&v0, &v0, &D_L39_0024DE00[1]);
            func_003E3980(&v0);
            func_003E37B0(&D_L39_0025F440_00598E80.f70, 1);
            if (func_0038CEA8(&v0) < f20 - 0.00999999978f) {
                D_L39_0024BB94 = 2;
                pos = &D_L39_0025F440_00598E80.f20;
                *pos = D_L39_0024DE00[0].a;
                func_003C48A8(&D_L39_0024DE00[1], &D_L39_0025F440_00598E80.f30);
                D_L39_0025F440_00598E80.f58 = 4;
            }
            break;
        }
        case 4:
            if (D_L39_002412DC != 0xB) {
                D_L39_0024BB90 = 3;
            }
            func_003C41A0(&D_L39_0025F440_00598E80.f6C, &D_L39_0025F440_00598E80.f70, 1.0f, 0.000800000038f, 0.000800000038f, 0.0300000012f);
            func_0038CDF8(&D_L39_0024DE00[0], &D_L39_0025F440_00598E80.f20, &D_L39_0025F440_00598E80, D_L39_0025F440_00598E80.f6C);
            func_003C3FC0(&v0, &D_L39_0025F440_00598E80.f30);
            func_003C3FC0(&v10, &D_L39_0025F440_00598E80.f10);
            func_0038D6C8(&m20, &v0, &v10, D_L39_0025F440_00598E80.f6C);
            func_0038D810(&m20, &D_L39_0024DE00[1]);
            if (1.0f <= D_L39_0025F440_00598E80.f6C) {
                func_L39_005BF840(0, 0);
            }
            break;
        }
        D_L39_0025F440_00598E80.s7E = 1;
        if (D_L39_00241164->f1A4 & 0x500) {
            if (D_L39_0025F440_00598E80.f58 == 2) {
                D_L39_0025F440_00598E80.f70 = 0;
                D_L39_0025F440_00598E80.f6C = 0;
                D_L39_0025F440_00598E80.f58 = 3;
            }
        }
        if (D_L39_002412DC == 0x16 || D_L39_002412DC == 0x17) {
            for (p = D_L39_0024BF5C; p < D_L39_0024BF60; p++) {
                if (p->fAA == 0xD3D) {
                    if (p->f64 != 0) {
                        p->f64(p);
                    }
                }
            }
        }
        break;
    case 7:
        if (D_L39_0025F440_00598E80.f58 == 0) {
            D_L39_0025F440_00598E80.s7E = 1;
            D_L39_0025F440_00598E80.f58 = 1;
            D_001D7170_sda = D_001D7174_sda;
            D_001D7178_sda = 0;
            func_L01_00422388();
            func_L01_00418C68();
        }
        break;
    case 8:
        if (D_L39_0025F440_00598E80.f58 != 2) {
            if (D_L39_0025F440_00598E80.f58 < 3) {
                if (D_L39_0025F440_00598E80.f58 >= 0) {
                    D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
                }
            }
        } else {
            func_L39_005BF798(3, 2, D_L39_0025F440_00598E80.f54, 0, 0);
            func_L01_0045A570(3);
            D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
        }
        break;
    case 9:
        switch (D_L39_0025F440_00598E80.f58) {
        case 1:
            if (D_L39_00241164->f1C4 & D_L39_0025F440_00598E80.f8C) {
                D_L39_0025F440_00598E80.s84 = 2;
                func_L39_005BF840(0, 0);
            } else if (D_L39_00241164->f1C4 & D_L39_0025F440_00598E80.f90) {
                D_L39_0025F440_00598E80.s84 = 1;
                func_L39_005BF840(0, 0);
            }
            break;
        case 0:
            func_L01_00418C80();
            D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
            break;
        }
        break;
    case 10:
        switch (D_L39_0025F440_00598E80.f58) {
        case 0:
            func_L01_00418C80();
            D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
            break;
        case 1:
            if (D_L39_00241164->f1C4 & D_L39_0025F440_00598E80.f8C) {
                D_L39_0025F440_00598E80.s84 = 2;
                func_L39_005F3548(0x12, 0, 0);
                func_L39_005BF840(0, 0);
            }
            break;
        }
        break;
    case 11:
        switch (D_L39_0025F440_00598E80.f58) {
        case 0:
            func_L01_00418C80();
            D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
            if (D_L39_002413A0 != 0) {
                D_L39_002413A0 = !D_L39_002413A0;
                func_003E1370();
                func_L39_005BF840(D_L39_0025F440_00598E80.f54, 0);
            }
            break;
        case 1:
            if (D_L39_00241164->f1C4 & 0x40) {
                D_L39_0025F440_00598E80.s84 = 2;
                D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
            } else if (D_L39_00241164->f1C0 & 0x10) {
                D_L39_0025F440_00598E80.s84 = 1;
                func_L39_005BF840(D_L39_0025F440_00598E80.f54, 0);
            }
            break;
        case 2:
            D_L39_0025F440_00598E80.f5C = 0x2EE;
            D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
            D_L39_0025F440_00598E80.f60 = 0;
            D_L39_0025F440_00598E80.s84 = 0;
            D_L39_002413A0 = !D_L39_002413A0;
            func_003E1370();
            break;
        case 3:
            if (D_L39_00241164->f1C4 & 0x20) {
                D_L39_0025F440_00598E80.s84 = 2;
            } else if (D_L39_00241164->f1C4 & 0x10) {
                D_L39_0025F440_00598E80.s84 = 1;
            }
            if (--D_L39_0025F440_00598E80.f5C > 0) {
                if (D_L39_0025F440_00598E80.s84 == 0) {
                    break;
                }
            }
            D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
            break;
        case 4:
            if (D_L39_0025F440_00598E80.s84 >= 0) {
                if (D_L39_0025F440_00598E80.s84 < 2) {
                    D_L39_002413A0 = !D_L39_002413A0;
                    func_003E1370();
                }
            }
            D_L39_0025F440_00598E80.f58 = D_L39_0025F440_00598E80.f58 + 1;
            break;
        case 5:
            func_L39_005BF840(D_L39_0025F440_00598E80.f54, 0);
            break;
        }
        break;
    case 12:
        func_L39_0057B1C0();
        break;
    }
}
/* localdecomp:end func_L39_00598E80 */
