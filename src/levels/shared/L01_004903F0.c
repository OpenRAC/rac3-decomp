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
extern s32 func_003BB118(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);

INCLUDE_ASM("asm/levels", func_L01_004903F0);

/* localdecomp:start func_L01_004906D0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
} S_004906D0;
extern s32 D_L01_001D8D60;
extern f32 D_L01_001D8D7C;
extern f32 D_L01_001D8D80;
extern f32 D_L01_001D8D84;
extern f32 D_L01_001D8D88;
extern f32 D_L01_001D8D8C;
extern f32 D_L01_001D8D90;
__asm__(".extern D_L01_001D8D60, 4");
__asm__(".extern D_L01_001D8D7C, 4");
__asm__(".extern D_L01_001D8D80, 4");
__asm__(".extern D_L01_001D8D84, 4");
__asm__(".extern D_L01_001D8D88, 4");
__asm__(".extern D_L01_001D8D8C, 4");
__asm__(".extern D_L01_001D8D90, 4");
extern s32 func_L01_0047DAE0(void);
extern s32 *func_003B9BD0(s32);
extern void func_003B9C68(s32 *, void *);
extern void func_003BABB0(s32 *, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32 *, f32, f32, f32, f32);
extern void func_003BA4E0(s32 *, s32, f32, f32, f32);
extern void func_003BA358(s32 *, s32, s32, s32);
extern void func_L01_00490A50(void);

void func_L01_004906D0(void) {
    S_004906D0 d;
    s32 n;
    s32 x;

    n = 7;
    D_L01_001D8D60 = n;
    d.f0 = func_L01_0047DAE0();
    d.f4 = func_003BB118(0);
    x = D_L01_001D8D60;
    n = x < 9 ? x : 8;
    d.f18 = 1.0f;
    d.f1C = D_L01_001D8D7C;
    d.f8 = 0x14;
    D_L01_001D8D84 = (f32)(x + 1) * 0.0532f / (f32)x;
    d.f20 = D_L01_001D8D84;
    d.f24 = D_L01_001D8D88;
    d.f28 = D_L01_001D8D8C;
    d.f2C = 1.0f;
    d.f30 = 1.0f;
    d.f34 = D_L01_001D8D90;
    d.f10 = n;
    d.f14 = 2;
    d.fC = x;
    d.f38 = d.f28 - d.f24 - d.f34;
    d.f3C = 0;
    d.f40 = 0;
    d.f44 = 0;
    d.f48 = 0;
    d.f4C = 0;
    d.f50 = 0;
    func_003B9C68(func_003B9BD0(0), &d);
    func_003BABB0(func_003B9BD0(0), 0, 0.5f, 0.817342f, 0.045f, 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), 0.5f, 0.632204f, 0.817342f, 0.439128f);
    func_003BA4E0(func_003B9BD0(0), 1, D_L01_001D8D80, 0.00666f, 0.03f);
    func_003BA358(func_003B9BD0(0), 0, 1, 3);
    func_003BA358(func_003B9BD0(0), 1, 2, 3);
    func_L01_00490A50();
}
/* localdecomp:end func_L01_004906D0 */
