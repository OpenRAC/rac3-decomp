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
extern void func_L01_00517190(s32 id, s32 v);
extern void func_L01_00516D60(s32 id, s32 v);
extern u8 *D_001D52FC[] __attribute__((section(".sdata")));
extern void *func_L01_0047EBE0(void);
extern void func_L01_00517748(void *);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern s32 func_L01_00517538(s32, f32, f32);

/* localdecomp:start func_L01_0048FBF0 */
__asm__(".extern D_L01_001D8D68, 4");
__asm__(".extern D_L01_001D8D7C, 4");
__asm__(".extern D_L01_001D8D84, 4");
__asm__(".extern D_L01_001D8D88, 4");
__asm__(".extern D_L01_001D8D8C, 4");
__asm__(".extern D_L01_001D8D90, 4");
__asm__(".extern D_L01_001D8D94, 4");
extern s32 D_L01_001D8D68;
extern f32 D_L01_001D8D7C;
extern f32 D_L01_001D8D84;
extern f32 D_L01_001D8D88;
extern f32 D_L01_001D8D8C;
extern f32 D_L01_001D8D90;
extern f32 D_L01_001D8D94;
extern u8 D_L01_002EB098[];
extern void func_L01_004908D8(void);
extern s32 func_L01_004903F0(void *);
extern void func_L01_00499B20(s32, s32, s32);
extern s32 func_L01_0041A878(s32);
extern s32 func_L01_00497C90(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005176C8(s32, s32);
extern s32 func_L01_004906D0(void);
extern void func_L01_00518D40_0048FBF0(s32);
extern s32 func_L01_00518B60(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_00518A28(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_005182C0(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_005180C0(s32, s32, s32);
extern void func_L01_00490FC8(void);
extern s32 func_L01_00494160(s32);
extern s32 func_L01_00517A80(s32, s32);
extern s32 func_L01_00517B28(s32, s32, s32);

void func_L01_0048FBF0(void) {
    f32 scale;
    f32 val;

    scale = 1.0f;
    val = 0.0f;
    D_L01_001D8D68 = -1;
    func_L01_004908D8();
    func_L01_004903F0(D_L01_002EB098);
    func_L01_00499B20(0xCBD, (s32)&scale, (s32)&val);
    func_L01_00497C90(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008,
                      func_L01_0041A878(0xCBD), 0xD0006, 0xFF, 0xD0007, 0xCD5, val);
    func_L01_00517538(0xD0005, scale, scale);
    func_L01_005176C8(0x11, 0x1E0000);
    func_L01_004906D0();
    func_L01_00518D40_0048FBF0(0x1E0006);

    func_L01_00518B60(0x1E0009, 0x706EC8FF, D_L01_001D8D88 + D_L01_001D8D90,
                      D_L01_001D8D7C + D_L01_001D8D84 * 2.0f, 0.01953f, 0.040868f, 0.004f, 0.005f);
    func_L01_00518B60(0x1E0008, 0x332299DE,
                      (D_L01_001D8D88 + D_L01_001D8D90 + D_L01_001D8D8C) * 0.5f,
                      D_L01_001D8D7C + D_L01_001D8D84 * 2.0f,
                      D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90), D_L01_001D8D94, 0.004f, 0.005f);
    func_L01_00518A28(0x1E0007, 0x332299DE, 0, D_L01_001D8D88 + D_L01_001D8D90 + 0.004f,
                      D_L01_001D8D7C + D_L01_001D8D84 * 2.0f,
                      D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90) - 0.008f, D_L01_001D8D94 - 0.01f);
    func_L01_00516B90(0x1E0007, 1, 3);

    func_L01_00518B60(0x1E000C, 0x706EC8FF, D_L01_001D8D88 + D_L01_001D8D90,
                      D_L01_001D8D7C + D_L01_001D8D84 * 3.0f, 0.01953f, 0.040868f, 0.004f, 0.005f);
    func_L01_00518B60(0x1E000B, 0x332299DE,
                      (D_L01_001D8D88 + D_L01_001D8D90 + D_L01_001D8D8C) * 0.5f,
                      D_L01_001D8D7C + D_L01_001D8D84 * 3.0f,
                      D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90), D_L01_001D8D94, 0.004f, 0.005f);
    func_L01_00518A28(0x1E000A, 0x332299DE, 0, D_L01_001D8D88 + D_L01_001D8D90 + 0.004f,
                      D_L01_001D8D7C + D_L01_001D8D84 * 3.0f,
                      D_L01_001D8D8C - (D_L01_001D8D88 + D_L01_001D8D90) - 0.008f, D_L01_001D8D94 - 0.01f);

    func_L01_005170B8(0x1E0008, 0x331465B7);
    func_L01_005170B8(0x1E0007, 0x60000000);
    func_L01_005170B8(0x1E000B, 0x331465B7);
    func_L01_005170B8(0x1E000A, 0x60000000);
    func_L01_00516B90(0x1E000A, 1, 3);
    func_L01_005182C0(0x1E0006, 0x1E0007, 0x1E0008, 0x1E000A, 0x1E0009, 0x1E000B, 0x1E000C);
    func_L01_005180C0(0x1E0000, 0x1E0006, 0x1E000D);
    func_L01_00490FC8();
    func_L01_00517A80(0x1E0003, func_L01_00494160(1));
    func_L01_00517190(0x1E0003, 0);
    func_L01_00516D60(0x1E0003, 0);
    func_L01_00517B28(0x1E0003, 1, 8);
}
/* localdecomp:end func_L01_0048FBF0 */

INCLUDE_ASM("asm/levels", func_L01_00490050);
