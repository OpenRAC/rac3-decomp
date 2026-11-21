#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;
typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;
typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;
typedef struct { u8 b[16]; } V16_48DCD8;

/* declared by functions of L01_0048B738.c, which this file was cut from */
extern char *func_00381FF0(s32 id);
extern void func_L01_0047EC88(void);
extern u8 *D_001D52FC[] __attribute__((section(".sdata")));
extern void *func_L01_0047EBE0(void);
extern void func_L01_00517748(void *);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_L01_0047DE68(void);
extern s32 func_L01_0048EE70(void);

/* localdecomp:start func_L01_0048EEC8 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7080 - 0x4958];
    u8 f7080[1];
} S_0048EEC8;

extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32, f32);
extern void func_L01_0047DE68(void);
extern void *func_003BB3A8(s32);
__asm__(".extern D_L01_001D8D08, 4");
extern s32 D_L01_001D8D08;
extern void func_L01_00518D40_0048EEC8(s32);
extern void func_003E8348(s32, s32);
extern s32 func_003E8FE8(s32, char *, s32, f32, f32, f32, f32);
extern void func_003E7AC8(s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern void func_003E7F20(s32, s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, void *);
extern void func_L01_00518480(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern S_0048EEC8 D_00160C40_0048EEC8;

void func_L01_0048EEC8(void) {
    f32 scale = 0.8f;
    f32 left = 0.1f;
    f32 top = 0.785f;
    f32 right = 0.9f;
    f32 bottom = 0.825f;
    f32 barX = 0.5f;
    f32 barY = 0.827f;
    f32 barW = 0.0035f;
    f32 barH = 0.006f;
    s32 p;
    s32 q;

    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005,
        0xD0008, func_00381FF0(0x116), 0xD0006, 0x15C6, 0xD0007, 0x177, 7.5f);
    func_L01_0047DE68();
    D_L01_001D8D08 = (s32)func_003BB3A8(0);
    func_L01_00518D40_0048EEC8(0x180001);
    func_003E8348(0x11, 0x180001);
    func_003E8FE8(0x180003, func_00381FF0(0x172), 0x8066CCFF, left, top, scale, scale);
    func_003E7AC8(0x180003, 1);
    func_L01_00516B90(0x180003, 1, 3);
    func_003E8FE8(0x180002, func_00381FF0(0x171), 0x8066CCFF, right, top, scale, scale);
    func_003E7AC8(0x180002, 1);
    func_L01_00516B90(0x180002, 2, 3);
    func_003E8FE8(0x180008, func_00381FF0(0x11A), 0x8066CCFF, left, bottom, scale, scale);
    func_003E7AC8(0x180008, 1);
    func_L01_00516B90(0x180008, 1, 3);
    func_003E8FE8(0x180009, func_00381FF0(0x11B), 0x8066CCFF, right, bottom, scale, scale);
    func_003E7AC8(0x180009, 1);
    func_L01_00516B90(0x180009, 2, 3);
    func_003E8FE8(0x180007, 0, 0x8066CCFF, 0.89f, 0.32f, 1.25f, 1.25f);
    func_003E7AC8(0x180007, 1);
    func_L01_00516B90(0x180007, 2, 3);
    func_003E7F20(0x180007, 1);
    func_003E9270(0x180004, 0x332299DE, barX, 0.25f, barY, 0.225f, barW, barH);
    func_003E9270(0x180005, 0x332299DE, barX, 0.615f, barY, 0.4935f, barW, barH);
    func_003E9138(0x180006, 0x80808080, 0, 0.5025f, 0.251f, 0.818f, 0.21225f);
    func_L01_00516AA0(0x180006, 0x8000, 1);
    p = (D_L01_001D8D08 + 15) & 0xFFFFFFF0;
    q = (p + 0x8000 + 15) & 0xFFFFFFF0;
    func_003B4528(func_003B42F8(0), p, q, D_00160C40_0048EEC8.f4954, (s32)D_00160C40_0048EEC8.f7080);
    func_003E8710(0x180006, func_003B42F8(0));
    func_L01_00518480(0x180001, 0x180002, 0x180003, 0x180008, 0x180009, 0x180006, 0x180007, 0x180004, 0x180005);
}
/* localdecomp:end func_L01_0048EEC8 */

INCLUDE_ASM("asm/levels", func_L01_0048F390);
