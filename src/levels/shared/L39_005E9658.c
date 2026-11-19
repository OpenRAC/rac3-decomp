#include "common.h"

typedef struct { u8 b[16]; } V16_48DCD8;

/* declared by functions of L39_005E94F8.c, which this file was cut from */
extern void func_L39_005E9658(void);

/* localdecomp:start func_L39_005E9658 */
typedef struct { u8 pad[0xA4]; u8 bA4[10]; } T_005E9658;
typedef struct { s32 cur; s32 reset; s32 max; } S_005E9658;
extern T_005E9658 D_001A5810;
extern s32 D_L39_0024C890[] __attribute__((section(".sdata")));
extern s32 D_L39_0024C880[] __attribute__((section(".sdata")));
extern S_005E9658 D_L39_0049A498[];
extern u8 D_L39_0049A3D8[];
__asm__(".extern D_001D858C_sda, 4");
__asm__(".extern D_001D8590_sda, 4");
__asm__(".extern D_001D8594_sda, 4");
__asm__(".extern D_001D8598_sda, 4");
__asm__(".extern D_001D859C_sda, 4");
__asm__(".extern D_001D85A0_sda, 4");
extern f32 D_001D858C_sda;
extern f32 D_001D8590_sda;
extern f32 D_001D8594_sda;
extern f32 D_001D8598_sda;
extern f32 D_001D859C_sda;
extern f32 D_001D85A0_sda;

extern s32 func_L01_00517688(void);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005EB330(void);
extern void func_L39_005EAD50(void);
extern void func_L01_0047EDB0_005E9658(void);
extern s32 func_00381FF0(s32);
extern void func_L39_005E7598(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00492D00(void *);
extern s32 func_003E8348(s32, s32);
extern s32 func_L01_00516640(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003B42F8(s32);
extern s32 func_003E8710(s32, s32);
extern void func_L39_005EA240(void);
extern void func_L01_00484A80(s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516C78_005E9658(s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_L39_005EAFF0(void);
extern void func_L01_004A0A80(void);

void func_L39_005E9658(void) {
    s32 i;
    s32 pl;
    u8 *o;
    f32 fi;
    s32 m;
    f32 tw;
    f32 th;

    i = 3;
    pl = func_L01_00517688();
    tw = 0.0035f;
    th = 0.006f;
    o = func_L39_0061BF38(pl);
    m = D_001A5810.bA4[*(s32 *)(o + 0x2544)];
    if (m == 2) {
        D_L39_0024C890[pl] = m;
    } else if (m == 1) {
        D_L39_0024C890[pl] = m;
    } else {
        D_L39_0024C890[pl] = 0;
    }
    D_L39_0024C880[pl] = D_L39_0024C890[pl];
    fi = (f32)i;
    func_L39_005EB330();
    func_L39_005EAD50();
    func_L01_0047EDB0_005E9658();
    func_L39_005E7598(0x10, 0.0f, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x112), 0xD0006, 0xFF, 0xD0007, 0xCD5);
    func_L01_00492D00(D_L39_0049A3D8);
    func_003E8348(0x11, 0x540000);
    func_L01_00516640(0x540002, 0.0035f, 0.006f);
    func_003E7F20(0x54000A, 1);
    func_003E7F20(0x54000E, 1);
    func_003E7F20(0x540012, 1);
    func_003E7F20(0x540016, 1);
    func_003E7F20(0x54001A, 1);
    func_003E7F20(0x54001E, 1);
    func_003E7F20(0x540022, 1);
    func_003E7F20(0x540026, 1);
    func_003E7F20(0x54002A, 1);
    func_003E7F20(0x54002E, 1);
    func_003E7F20(0x540032, 1);
    func_003E7F20(0x540036, 1);
    func_003E8710(0x540003, func_003B42F8(0));
    func_L39_005EA240();
    func_L01_00484A80(0x54003A);
    func_003E9270(0x54003D, 0x706EC8FF, D_001D8594_sda + D_001D859C_sda, D_001D858C_sda + D_001D8590_sda * fi, 0.01953f, 0.040868f, 0.0035f, 0.006f);
    func_003E9270(0x54003C, 0x332299DE, (D_001D8594_sda + D_001D859C_sda + D_001D8598_sda) * 0.5f, D_001D858C_sda + D_001D8590_sda * fi, D_001D8598_sda - (D_001D8594_sda + D_001D859C_sda), D_001D85A0_sda, 0.0035f, 0.006f);
    func_003E9138(0x54003B, 0x332299DE, 0, D_001D8594_sda + D_001D859C_sda + tw, D_001D858C_sda + D_001D8590_sda * fi, D_001D8598_sda - (D_001D8594_sda + D_001D859C_sda) - tw * 2, D_001D85A0_sda - th * 2);
    func_L01_00516C78_005E9658(0x54003B, 1, 3);
    func_L01_00518110(0x54003A, 0x54003B, 0x54003C, 0x54003D);
    func_003E8630(0x540000, 0x54003A);
    func_L01_005170B8(0x54003C, 0x331465B7);
    func_L01_005170B8(0x54003B, 0x60000000);
    switch (D_001A5810.bA4[*(s32 *)(o + 0x2544)]) {
    case 0:
        D_L39_0024C890[pl] = 0;
        D_L39_0049A498[pl].cur = 0;
        break;
    case 1:
        D_L39_0024C890[pl] = 1;
        D_L39_0049A498[pl].cur = 2;
        break;
    case 2:
        D_L39_0024C890[pl] = 2;
        D_L39_0049A498[pl].cur = 1;
        break;
    }
    func_L39_005EAFF0();
    func_L01_004A0A80();
}
/* localdecomp:end func_L39_005E9658 */
