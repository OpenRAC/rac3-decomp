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
extern s32 func_L01_00516470(s32, f32, f32);

void func_L01_00490FC8(void) {
    f32 b[4];
    f32 f20;
    f32 f21;
    f32 p;
    f32 d;
    f32 s;
    f32 t;
    f32 u;
    f32 k;
    f32 v;
    f32 w;
    f32 z;

    z = 0.0f;
    k = 0.008f;
    f20 = (f32)D_00143950[3] * 0.0009765625f;
    f21 = (f32)D_00143950[4] * 0.0009765625f;
    b[0] = z;
    b[1] = z;
    b[2] = z;
    b[3] = z;
    func_L01_00516558(0x1e0009, &b[0], &b[1]);
    func_L01_00516558(0x1e000c, &b[2], &b[3]);
    p = D_L01_001D8D88 + D_L01_001D8D90;
    d = D_L01_001D8D8C - p;
    d = d - k;
    s = p + k;
    t = d * f20;
    u = d * f21;
    w = s + u;
    b[2] = w;
    v = s + t;
    b[0] = v;
    func_L01_00516470(0x1e0009, v, b[1]);
    { f32 x = b[2]; f32 y = b[3]; func_L01_00516470(0x1e000c, x, y); };
}
/* localdecomp:end func_L01_00490FC8 */
