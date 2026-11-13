#include "common.h"

/* NTSC-U counterpart of func_L39_006D8B88 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
extern u8 D_001A5E50[];
s32 func_001962E8(void);
extern u8 D_001A5E50[];
s32 func_001962E8(void);
s32 func_001962E8(void);
s32 func_001962E8(void);
extern u8 D_001A5E50[];
s32 func_001962E8(void);
extern u8 D_001A5E50[];
s32 func_001962E8(void);
extern u8 D_001A5E50[];
s32 func_001962E8(void);
extern s32 func_001962E8(void);

/* localdecomp:start func_L39_006D6030 */
typedef struct G_006D8B88 {
    u8 pad0[0x2D8];
    s32 f2D8;
    s32 f2DC;
    u8 pad2E0[4];
    u8 f2E4;
} G_006D8B88;
extern u8 D_001A5E50[];
s32 func_001962E8(void);
s32 func_0019B8E8(void);
s32 func_0019B708(void);
s32 func_L39_006DB790(void *);
s32 func_L39_006CAF58(void *);
s32 func_L39_006CDE18(void *);
s32 func_L39_006D3550(u8 *);
s32 func_L39_006D3F28(void *);
s32 func_L39_006D4CE0(u8 *);
s32 func_L39_006D3248(void *);
s32 func_L39_006D2410(void *);
s32 func_L39_006D7E00(void *);

typedef struct S_006D8B88 {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x34 - 0x18];
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    u8 pad48[0x4C - 0x48];
    void *f4C;
    u8 pad50[0x54 - 0x50];
    void *f54;
    u8 pad58[0x70 - 0x58];
    void *f70;
    u8 f74;
    u8 pad75[0x78 - 0x75];
    void *f78;
    u8 pad7C[0x80 - 0x7C];
    s32 f80;
    s32 f84;
} S_006D8B88;

s32 func_L39_006D6030(S_006D8B88 *arg0)
{
    s32 r;
    r = 1;
    if (((G_006D8B88 *)D_001A5E50)->f2E4 == 0) {
        return 0;
    }
    if (func_001962E8() != 0) {
        arg0->f10 = 8;
        if (arg0->f14 == 0) {
            arg0->f14 = 8;
        }
        r = 0;
    }
    if (((G_006D8B88 *)D_001A5E50)->f2DC != 0) {
        arg0->f80++;
    } else {
        arg0->f80 = 0;
    }
    if (arg0->f80 > 0x3C) {
        arg0->f10 = 8;
        if (arg0->f14 == 0) {
            arg0->f14 = 8;
        }
        r = 0;
    }
    if (func_0019B8E8() != 0) {
        if (((G_006D8B88 *)D_001A5E50)->f2D8 != 0) {
            arg0->f84++;
        } else {
            arg0->f84 = 0;
        }
        if (arg0->f84 > 0x3C) {
            arg0->f10 = 8;
            if (arg0->f14 == 0) {
                arg0->f14 = 8;
            }
            r = 0;
        }
    }
    if (arg0->f54 != 0) {
        func_L39_006DB790(arg0->f54);
    }
    if (arg0->f34 != 0) {
        func_L39_006CAF58(arg0->f34);
    }
    if (arg0->f38 != 0) {
        func_L39_006CDE18(arg0->f38);
    }
    if (arg0->f40 != 0) {
        func_L39_006D3550(arg0->f40);
    }
    if (arg0->f44 != 0) {
        func_L39_006D3F28(arg0->f44);
    }
    if (arg0->f78 != 0) {
        func_L39_006D4CE0(arg0->f78);
    }
    if (r != 0) {
        if (arg0->f74) {
            r = func_L39_006D3248(arg0->f70);
        }
        if (r != 0) {
            if (arg0->f3C != 0 && ~func_0019B708() != 0) {
                r = func_L39_006D2410(arg0->f3C);
            }
            if (r != 0 && arg0->f4C != 0) {
                r = func_L39_006D7E00(arg0->f4C);
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D6030 */
