#include "common.h"

/* NTSC-U counterpart of func_L39_005E9658 (src/levels/shared/L39_005E9658.c) */
extern void func_L39_005E70E8(void);

/* localdecomp:start func_L39_005E70E8 */
typedef struct { u8 pad[0xA4]; u8 bA4[10]; } T_005E9658;
typedef struct { s32 cur; s32 reset; s32 max; } S_005E9658;
extern T_005E9658 D_001A5990;
extern s32 D_L39_0024C990[] __attribute__((section(".sdata")));
extern s32 D_L39_0024C980[] __attribute__((section(".sdata")));
extern S_005E9658 D_L39_0049A558[];
extern u8 D_L39_0049A498_005E70E8[];
__asm__(".extern D_001D8574_sda, 4");
__asm__(".extern D_001D8578_sda, 4");
__asm__(".extern D_001D857C_sda, 4");
__asm__(".extern D_001D8580_sda_005E70E8, 4");
__asm__(".extern D_001D8584_sda_005E70E8, 4");
__asm__(".extern D_001D8588_sda_005E70E8, 4");
extern f32 D_001D8574_sda;
extern f32 D_001D8578_sda;
extern f32 D_001D857C_sda;
extern f32 D_001D8580_sda_005E70E8;
extern f32 D_001D8584_sda_005E70E8;
extern f32 D_001D8588_sda_005E70E8;

extern s32 func_L01_00513698(void);
extern u8 *func_L39_006197C0(s32);
extern void func_L39_005E8DC0(void);
extern void func_L39_005E87E0(void);
extern void func_L01_0047B550_005E70E8(void);
extern s32 func_0037DF98(s32);
extern s32 func_L39_005E5028(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0048F508(void *);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_L01_00512650(s32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_003AED40(s32);
extern s32 func_003E31A8(s32, s32);
extern void func_L39_005E7CD0(void);
extern void func_L01_00481220(s32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E3BD0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00512C88_005E70E8(s32, s32, s32);
extern s32 func_L01_00514120(s32, s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_L01_005130C8(s32, s32);
extern void func_L39_005E8A80(void);
extern void func_L01_0049D220(void);

void func_L39_005E70E8(void) {
    s32 i;
    s32 pl;
    u8 *o;
    f32 fi;
    s32 m;
    f32 tw;
    f32 th;

    i = 3;
    pl = func_L01_00513698();
    tw = 0.0035f;
    th = 0.006f;
    o = func_L39_006197C0(pl);
    m = D_001A5990.bA4[*(s32 *)(o + 0x2544)];
    if (m == 2) {
        D_L39_0024C990[pl] = m;
    } else if (m == 1) {
        D_L39_0024C990[pl] = m;
    } else {
        D_L39_0024C990[pl] = 0;
    }
    D_L39_0024C980[pl] = D_L39_0024C990[pl];
    fi = (f32)i;
    func_L39_005E8DC0();
    func_L39_005E87E0();
    func_L01_0047B550_005E70E8();
    func_L39_005E5028(0x10, 0.0f, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_0037DF98(0x112), 0xD0006, 0xFF, 0xD0007, 0xCD5);
    func_L01_0048F508(D_L39_0049A498_005E70E8);
    func_003E2DE0(0x11, 0x540000);
    func_L01_00512650(0x540002, 0.0035f, 0.006f);
    func_003E29B8(0x54000A, 1);
    func_003E29B8(0x54000E, 1);
    func_003E29B8(0x540012, 1);
    func_003E29B8(0x540016, 1);
    func_003E29B8(0x54001A, 1);
    func_003E29B8(0x54001E, 1);
    func_003E29B8(0x540022, 1);
    func_003E29B8(0x540026, 1);
    func_003E29B8(0x54002A, 1);
    func_003E29B8(0x54002E, 1);
    func_003E29B8(0x540032, 1);
    func_003E29B8(0x540036, 1);
    func_003E31A8(0x540003, func_003AED40(0));
    func_L39_005E7CD0();
    func_L01_00481220(0x54003A);
    func_003E3D08(0x54003D, 0x706EC8FF, D_001D857C_sda + D_001D8584_sda_005E70E8, D_001D8574_sda + D_001D8578_sda * fi, 0.01953f, 0.040868f, 0.0035f, 0.006f);
    func_003E3D08(0x54003C, 0x332299DE, (D_001D857C_sda + D_001D8584_sda_005E70E8 + D_001D8580_sda_005E70E8) * 0.5f, D_001D8574_sda + D_001D8578_sda * fi, D_001D8580_sda_005E70E8 - (D_001D857C_sda + D_001D8584_sda_005E70E8), D_001D8588_sda_005E70E8, 0.0035f, 0.006f);
    func_003E3BD0(0x54003B, 0x332299DE, 0, D_001D857C_sda + D_001D8584_sda_005E70E8 + tw, D_001D8574_sda + D_001D8578_sda * fi, D_001D8580_sda_005E70E8 - (D_001D857C_sda + D_001D8584_sda_005E70E8) - tw * 2, D_001D8588_sda_005E70E8 - th * 2);
    func_L01_00512C88_005E70E8(0x54003B, 1, 3);
    func_L01_00514120(0x54003A, 0x54003B, 0x54003C, 0x54003D);
    func_003E30C8(0x540000, 0x54003A);
    func_L01_005130C8(0x54003C, 0x331465B7);
    func_L01_005130C8(0x54003B, 0x60000000);
    switch (D_001A5990.bA4[*(s32 *)(o + 0x2544)]) {
    case 0:
        D_L39_0024C990[pl] = 0;
        D_L39_0049A558[pl].cur = 0;
        break;
    case 1:
        D_L39_0024C990[pl] = 1;
        D_L39_0049A558[pl].cur = 2;
        break;
    case 2:
        D_L39_0024C990[pl] = 2;
        D_L39_0049A558[pl].cur = 1;
        break;
    }
    func_L39_005E8A80();
    func_L01_0049D220();
}
/* localdecomp:end func_L39_005E70E8 */
