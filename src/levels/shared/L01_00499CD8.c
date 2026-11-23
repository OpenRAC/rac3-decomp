#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* declared by functions of L01_00499C80.c, which this file was cut from */
extern void func_L01_00499CD8();

/* localdecomp:start func_L01_00499CD8 */
extern u8 D_001439F4[];
extern s32 D_L01_001D92EC;
__asm__(".extern D_L01_001D92EC, 4");
extern E_496DC0 *D_L01_001D92E8;
__asm__(".extern D_L01_001D92E8, 4");
extern char D_L01_001D9330[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9330, 8");
extern E_496DC0 D_L01_002EB9C0[];
extern E_496DC0 D_L01_002EBAD0[];
extern E_496DC0 D_L01_002EBA78[];
extern u8 D_L01_002EBB48[];
extern void func_L01_0049A2F0(void);
extern void func_L01_0049A348(void);
extern void func_0038E150(s32);
extern void func_L01_0049A748(s32, f32 *, f32 *);
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_0049A010(void *);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003E8348(s32, s32);
extern void func_003E7F20(s32, s32);
extern void *func_003B42F8(s32);
extern void func_003E8710(s32, void *);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern void func_003E87B8(s32, s32, s32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00517D18(s32);

void func_L01_00499CD8(void) {
    f32 scale = 1.0f;
    f32 width = 0.0f;

    switch (D_001439F4[0]) {
    case 0:
        D_L01_001D92EC = 14;
        D_L01_001D92E8 = D_L01_002EB9C0;
        break;
    case 1:
        D_L01_001D92EC = 9;
        D_L01_001D92E8 = D_L01_002EBAD0;
        break;
    case 2:
        D_L01_001D92EC = 6;
        D_L01_001D92E8 = D_L01_002EBA78;
        break;
    }
    func_L01_0049A2F0();
    func_L01_0049A348();
    func_0038E150(0);
    func_L01_0049A748(0x113, &scale, &width);
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005,
        0xD0008, func_00381FF0(0x113), 0xD0006, 0x124, 0xD0007, 0xCD5, width);
    func_L01_00516FD8(0xD0006, (s32)D_L01_001D9330);
    func_L01_0049A010(D_L01_002EBB48);
    func_L01_00517538(0xD0005, scale, scale);
    func_003E8348(0x11, 0x4B0000);
    func_003E7F20(0x4B0005, 1);
    func_003E7F20(0x4B0006, 1);
    func_003E8710(0x4B0009, func_003B42F8(0));
    func_L01_00517190(0x4B0009, 0);
    func_L01_00516D60(0x4B0009, 0);
    func_003E87B8(0x4B0009, 1, 8);
    func_L01_00517BF8(0x4B0006, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0x4B0006, 0x78, 0, 0.0005f);
    func_L01_00517D18(0x4B0006);
}
/* localdecomp:end func_L01_00499CD8 */
