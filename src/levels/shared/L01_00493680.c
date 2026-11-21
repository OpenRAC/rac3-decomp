#include "common.h"

typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;
typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;
typedef struct O_490778 O_490778;
typedef struct {
    u8 pad0[12];
    void (*fn)(O_490778 *);
} V_490778;
struct O_490778 {
    u8 pad0[4];
    V_490778 *vt;
};

/* declared by functions of L01_00492C80.c, which this file was cut from */
extern s32 func_003B9BD0(s32);
extern s32 func_L01_00516D60(s32, s32);

/* localdecomp:start func_L01_00493680 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_00493680;
typedef struct { u8 pad0[0x694]; s32 f694; u8 pad698[0x1180 - 0x698]; u8 f1180[1]; } S_160C40_00493680;
extern f32 D_L01_001D8E98[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8E98, 4");
extern f32 D_L01_001D8EA8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8EA8, 4");
extern f32 D_L01_001D8EB8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8EB8, 4");
extern f32 D_L01_001D8EC8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8EC8, 4");
extern f32 D_L01_001D8ED8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8ED8, 4");
extern f32 D_L01_001D8EE8[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8EE8, 4");
extern f32 D_L01_001D8EF8;
__asm__(".extern D_L01_001D8EF8, 4");
extern s32 D_L01_001D8E90;
__asm__(".extern D_L01_001D8E90, 4");
extern char D_L01_001E0AC0[] __attribute__((section(".sdata")));
extern S_00493680 D_L01_002EB890;
extern S_160C40_00493680 D_00160C40;
extern char *func_00381FF0(s32);
extern void func_003B9298(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00518D40_00493680(s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern void func_003B4528(void *, s32, s32, s32, s32);
extern void func_003E8710(s32, void *);
extern void func_003E8A08(s32, s32, s32);
extern void func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518010(s32, s32);
extern void func_003E8898(s32, f32, f32);
extern void func_003E7F20(s32, s32);
extern void func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_003E8348(s32, s32);
extern void func_L01_0047DE68(void);
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern void func_003B9C68(s32, S_00493680 *);
extern void func_003BABB0(s32, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(s32, f32, f32, f32, f32);

void func_L01_00493680() {
    f32 off;

    func_003B9298(0x10, 9.5f, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005,
                  0xD0008, (s32)func_00381FF0(0x1BF), 0xD0006, 0, 0xD0007, 0x177);
    off = 0.0035f;
    func_L01_00516D60(0xD0006, 0);
    func_L01_00518D40_00493680(0x530000);
    func_003E9270(0x530001, 0x332299DE, D_L01_001D8E98[0], D_L01_001D8E98[1], D_L01_001D8E98[2], D_L01_001D8E98[3], off, 0.006f);
    func_003E8630(0x530000, 0x530001);
    func_003E9138(0x530003, 0x80808080, 0, D_L01_001D8EB8[0], D_L01_001D8EB8[1], D_L01_001D8EB8[2] - off, D_L01_001D8EB8[3] - 0.006f);
    D_L01_001D8E90 = func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), D_L01_001D8E90, 0, D_00160C40.f694, (s32)D_00160C40.f1180);
    func_003E8710(0x530003, func_003B42F8(0));
    func_003E9270(0x530002, 0x332299DE, D_L01_001D8EB8[0], D_L01_001D8EB8[1], D_L01_001D8EB8[2], D_L01_001D8EB8[3], off, 0.006f);
    func_003E8A08(0x530000, 0x530003, 0x530002);
    func_003E8FE8(0x530005, 0, 0x8066CCFF, D_L01_001D8EC8[0], D_L01_001D8EC8[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x530005, 0x40, 1);
    func_L01_00518010(0x530005, 1);
    func_003E8898(0x530005, D_L01_001D8EC8[2], D_L01_001D8EC8[3]);
    func_003E7F20(0x530005, 1);
    func_003E9270(0x530004, 0x332299DE, D_L01_001D8EC8[0], D_L01_001D8EC8[1], D_L01_001D8EC8[2], D_L01_001D8EC8[3], off, 0.006f);
    func_003E8A08(0x530000, 0x530005, 0x530004);
    func_003E9358(0x530007, 0, 0x8066CCFF, D_L01_001D8ED8[0], D_L01_001D8ED8[1], D_L01_001D8ED8[2] - D_L01_001D8EF8, D_L01_001D8ED8[3] - D_L01_001D8EF8, 1.0f);
    func_L01_00517BF8(0x530007, 1, 1, 0, 0, 1);
    func_L01_00517DB8(0x530007, 0x1E, 0, 0.0005f);
    func_L01_00518670(0x530007, 1, 1);
    func_L01_00516AA0(0x530007, 0x40, 1);
    func_003E7F20(0x530007, 1);
    func_003E9270(0x530006, 0x332299DE, D_L01_001D8ED8[0], D_L01_001D8ED8[1], D_L01_001D8ED8[2], D_L01_001D8ED8[3], off, 0.006f);
    func_003E8A08(0x530000, 0x530007, 0x530006);
    func_003E8FE8(0x530009, (s32)D_L01_001E0AC0, 0x8066CCFF, D_L01_001D8EE8[0], D_L01_001D8EE8[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x530009, 0x40, 1);
    func_003E7F20(0x530007, 1);
    func_003E9270(0x530008, 0x332299DE, D_L01_001D8EE8[0], D_L01_001D8EE8[1], D_L01_001D8EE8[2], D_L01_001D8EE8[3], off, 0.006f);
    func_003E8A08(0x530000, 0x530009, 0x530008);
    func_003E8348(0x11, 0x530000);
    func_L01_0047DE68();
    D_L01_002EB890.f0 = func_L01_0047DAE0();
    D_L01_002EB890.f4 = func_003BB118(0);
    func_003B9C68(func_003B9BD0(0), &D_L01_002EB890);
    func_003BABB0(func_003B9BD0(0), D_L01_001D8EA8[0], D_L01_001D8EA8[2] - off, D_L01_001D8EA8[3], 0.0425f, 0.35f, 0);
    func_003BABD0(func_003B9BD0(0), D_L01_001D8E98[0], D_L01_001D8E98[1], D_L01_001D8E98[2] - off, D_L01_001D8E98[3] - 0.006f);
}
/* localdecomp:end func_L01_00493680 */
