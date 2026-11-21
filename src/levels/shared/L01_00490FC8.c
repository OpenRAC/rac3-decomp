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
extern s32 func_L01_00516470(s32, f32, f32);

/* localdecomp:start func_L01_00490FC8 */
extern s32 D_00143950[];
extern f32 D_L01_001D8D88;
extern f32 D_L01_001D8D8C;
extern f32 D_L01_001D8D90;
__asm__(".extern D_L01_001D8D88, 4");
__asm__(".extern D_L01_001D8D8C, 4");
__asm__(".extern D_L01_001D8D90, 4");
extern void func_L01_00516558(s32, f32 *, f32 *);

void func_L01_00490FC8(void) {
    f32 y1, x1, y0, x0;
    f32 a, b, base, d;
    f32 e = 0.008f;
    f32 z = 0.0f;

    b = (f32)D_00143950[3] * (1.0f / 1024.0f);
    a = (f32)D_00143950[4] * (1.0f / 1024.0f);
    x0 = z;
    y0 = z;
    x1 = z;
    y1 = z;
    func_L01_00516558(0x1E0009, &x0, &y0);
    func_L01_00516558(0x1E000C, &x1, &y1);
    base = D_L01_001D8D88 + D_L01_001D8D90;
    d = D_L01_001D8D8C - base - e;
    base = base + e;
    x0 = base + d * b;
    x1 = base + d * a;
    func_L01_00516470(0x1E0009, x0, y0);
    func_L01_00516470(0x1E000C, x1, y1);
}
/* localdecomp:end func_L01_00490FC8 */
