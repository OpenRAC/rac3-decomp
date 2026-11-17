/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0048A848, the NTSC-U twin of func_L01_0048E0C0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0048B738.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

typedef struct { u8 p0[0x4954]; s32 f4954; u8 p4958[0x5950 - 0x4958]; u8 f5950[0x7080 - 0x5950]; u8 f7080[8]; } S_48A848;

extern void func_L01_00434488(void);
extern void func_00399F90(void);
extern void func_L01_0048A0C8(void);
extern s32 func_L01_00434480(void);
extern void func_L01_0048A0F8(void);
extern s32 func_0037DF98(s32);
extern s32 func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_0047A300(void);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_003E30C8(s32, s32);
extern void func_L01_00514D50(s32);
extern void func_L01_005145A0(s32, s32, s32);
extern void func_003E3BD0(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E3330(s32, f32, f32);
extern s32 func_L01_00514020(s32, s32);
extern void func_L01_00512AB0(s32, s32, s32);
extern s32 func_003E3DF0(s32, void *, s32, f32, f32, f32, f32, f32);
extern void func_L01_00513C08(s32, s32, s32, s32, s32, s32);
extern void func_L01_00513DC8(s32, s32, s32, f32);
extern void func_L01_00514680(s32, s32, s32);
extern s32 func_003E34A0(s32, s32, s32);
extern void func_L01_00512D70(s32, s32);
extern void func_L01_00512900(s32, f32);
extern s32 func_003B5EC8(s32);
extern s32 func_003AED40(s32);
extern void func_003AEF70(s32, s32, s32, s32, void *);
extern s32 func_003E31A8(s32, s32);
extern s32 func_003E2560(s32, s32);
extern void func_L01_00512BA0(s32, s32, s32);
extern s32 func_003E3D08(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E34F0(s32, s32, s32, s32, s32);
extern s32 func_003E2DE0(s32, s32);
extern s32 func_003E3250(s32, s32, s32);

/* localdecomp:start func_L01_0048A848 */
extern s32 D_001D8CB0_sda;
__asm__(".extern D_001D8CB0_sda, 4");
extern s32 D_001D8C60_sda;
__asm__(".extern D_001D8C60_sda, 4");
extern u8 *D_001D8CB4_sda;
__asm__(".extern D_001D8CB4_sda, 4");
extern s32 D_001D8CB8_sda;
__asm__(".extern D_001D8CB8_sda, 4");
extern s32 D_001D8CBC_sda;
__asm__(".extern D_001D8CBC_sda, 4");
extern s32 D_001D8CC0_sda;
__asm__(".extern D_001D8CC0_sda, 4");
extern s32 D_001D8CC4_sda;
__asm__(".extern D_001D8CC4_sda, 4");
extern f32 D_001D8CD4_sda;
__asm__(".extern D_001D8CD4_sda, 4");
extern f32 D_001D8CD8_sda;
__asm__(".extern D_001D8CD8_sda, 4");
extern f32 D_001D8CF0_sda;
__asm__(".extern D_001D8CF0_sda, 4");
extern f32 D_001D8CF4_sda;
__asm__(".extern D_001D8CF4_sda, 4");
extern f32 D_001D8CF8_sda;
__asm__(".extern D_001D8CF8_sda, 4");
extern f32 D_001D8D14_sda;
__asm__(".extern D_001D8D14_sda, 4");
extern f32 D_001D8D18_sda;
__asm__(".extern D_001D8D18_sda, 4");
extern f32 D_001D8D20_sda;
__asm__(".extern D_001D8D20_sda, 4");
extern f32 D_001D8D28_sda;
__asm__(".extern D_001D8D28_sda, 4");
extern f32 D_L01_001D8D24;
__asm__(".extern D_L01_001D8D24, 16");
extern f32 D_L01_001D8D2C;
__asm__(".extern D_L01_001D8D2C, 16");
extern u8 D_L01_001D8D30[];
extern u8 D_L01_002BCB40[];
extern S_48A848 D_00160C40;

void func_L01_0048A848(void) {
    s32 i;
    s32 t;
    s32 a;
    s32 b;

    func_L01_00434488();
    func_00399F90();
    D_001D8CB0_sda = 0;
    func_L01_0048A0C8();
    if (func_L01_00434480() != 0) {
        func_L01_0048A0F8();
        func_L01_00434488();
    }
    func_003B3DB8(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 0xD0008, func_0037DF98(0x174), 0xD0006, 0, 0xD0007, 0xCD5, 8.5f);
    if (D_001D8C60_sda == 0) {
        if (func_L01_0047A300() != 2) {
            func_003E3A80(0xD000A, func_0037DF98(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
            func_003E29B8(0xD000A, 1);
            func_003E30C8(0xD000B, 0xD000A);
        }
    }
    func_L01_00514D50(0x160000);
    func_L01_00514D50(0x160002);
    func_L01_005145A0(0x160000, 1, 1);
    func_003E3BD0(0x160008, 0x332299DE, 0.5f, 0.5f, 0.8f, 0.05f, 0);
    func_003E30C8(0x160000, 0x160008);
    for (i = 0; i < 4; i++) {
        func_003E3A80(0x160011 + i, func_0037DF98(*(s32 *)(D_001D8CB4_sda + i * 20)), 0x8066CCFF, D_001D8CD8_sda, D_001D8CD4_sda, 1.0f, 1.0f);
        func_003E3330(0x160011 + i, 0.8f, 0.8f);
        func_L01_00514020(0x160011 + i, 1);
        func_003E30C8(0x160000, 0x160011 + i);
        func_L01_00512AB0(0x160011 + i, 0x40, 1);
        func_003E3BD0(0x160016 + i, 0x332299DE, D_001D8CD8_sda, D_001D8CD4_sda, 0.77500004f, 0.006667f, 0);
        func_003E30C8(0x160000, 0x160016 + i);
    }
    func_003E3DF0(0x160003, D_L01_002BCB40, 0x8066CCFF, D_001D8D20_sda, D_L01_001D8D24, D_001D8D28_sda, D_L01_001D8D2C, 1.0f);
    func_L01_00512AB0(0x160003, 0x40, 1);
    func_L01_00513C08(0x160003, 1, 1, 1, 0, 0);
    func_L01_00513DC8(0x160003, 0x78, 0, 0.0005f);
    func_003E29B8(0x160003, 1);
    func_003E3DF0(0x160006, D_L01_001D8D30, 0x8066CCFF, D_001D8D14_sda, D_001D8D18_sda, D_001D8D28_sda, 0.061332f, 0.9f);
    func_L01_00512AB0(0x160006, 0x40, 1);
    func_L01_00514680(0x160006, 1, 1);
    func_003E34A0(0x160002, 0x160003, 0x160006);
    func_003E3BD0(0x16000F, 0x332299DE, 0.322916f, 0.359167f, 0.432999f, 0.006667f, 0);
    func_003E30C8(0x160002, 0x16000F);
    func_003E3BD0(0x160009, 0x706EC8FF, D_001D8CF0_sda, D_001D8CF4_sda, 0.035f, 0.043076925f, 0x7569);
    func_L01_00512D70(0x160009, 0);
    func_L01_00512900(0x160009, 4.712389f);
    func_L01_00512AB0(0x160009, 0x40, 1);
    func_003E3BD0(0x16000A, 0x706EC8FF, D_001D8CF0_sda, D_001D8CF8_sda, 0.035f, 0.043076925f, 0x7569);
    func_L01_00512900(0x16000A, 1.5707964f);
    func_L01_00512AB0(0x16000A, 0x40, 1);
    func_L01_00512D70(0x16000A, 0);
    func_003E34A0(0x160000, 0x160009, 0x16000A);
    a = func_003B5EC8(0);
    b = func_003B5EC8(0);
    D_001D8CB8_sda = b;
    D_001D8CBC_sda = (a + 0xF) & 0xFFFFFFF0;
    func_003AEF70(func_003AED40(0), D_001D8CBC_sda, D_001D8CB8_sda, D_00160C40.f4954, D_00160C40.f5950);
    t = func_003B5EC8(0);
    D_001D8CC0_sda = t;
    D_001D8CC4_sda = (t + 0x8C0F) & 0xFFFFFFF0;
    func_003AEF70(func_003AED40(1), D_001D8CC0_sda, D_001D8CC4_sda, D_00160C40.f4954, D_00160C40.f7080);
    func_003E3BD0(0x160004, 0x80808080, 0.742f, 0.437f, 0.3399f, 0.3415f, 0);
    func_003E31A8(0x160004, func_003AED40(0));
    func_003E30C8(0x160002, 0x160004);
    func_003E3BD0(0x160010, 0x80808080, 0.5025f, 0.195f, 0.8175f, 0.10576f, 0);
    func_003E31A8(0x160010, func_003AED40(1));
    func_L01_00512AB0(0x160010, 0x8000, 1);
    func_003E30C8(0x160002, 0x160010);
    func_003E3A80(0x160007, 0, 0xC066CCFF, 0.89f, 0.22f, 1.0f, 1.0f);
    func_003E29B8(0x160007, 1);
    func_003E2560(0x160007, 1);
    func_L01_00512BA0(0x160007, 2, 3);
    func_003E30C8(0x160002, 0x160007);
    func_003E3D08(0x16000D, 0x332299DE, 0.5f, 0.195f, 0.825f, 0.1145f, 0.0035f, 0.006f);
    func_003E3D08(0x16000B, 0x332299DE, 0.3245f, 0.43433f, 0.475f, 0.352f, 0.0035f, 0.006f);
    func_003E3D08(0x16000C, 0x332299DE, 0.74f, 0.43433f, 0.34425f, 0.352f, 0.0035f, 0.006f);
    func_003E3D08(0x16000E, 0x332299DE, 0.5f, 0.739f, 0.825f, 0.246f, 0.0035f, 0.006f);
    func_003E34F0(0x160002, 0x16000B, 0x16000C, 0x16000E, 0x16000D);
    func_003E2DE0(0x11, 0x160000);
    func_003E2DE0(0x12, 0x160002);
    func_L01_00512D70(0x160004, 0);
    func_003E3250(0x160004, 1, 10);
}
/* localdecomp:end func_L01_0048A848 */
