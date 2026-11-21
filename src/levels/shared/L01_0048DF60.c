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
extern s32 D_L01_001E0958[] __attribute__((section(".sdata")));
extern f32 D_L01_001D8CCC;

/* localdecomp:start func_L01_0048DF60 */
__asm__(".extern D_L01_001D8CCC, 4");
extern s32 D_L01_001E0958[] __attribute__((section(".sdata")));
extern f32 D_L01_001D8CCC;

void func_L01_0048DF60(void) {
    f32 speed;
    f32 dir;

    speed = 0.0048076923f;
    switch (D_L01_001E0958[0]) {
    case 1:
        dir = -1.0f;
        break;
    case 3:
        dir = -1.0f;
        speed = 0.01923077f;
        break;
    case 2:
        dir = 1.0f;
        break;
    case 4:
        dir = 1.0f;
        speed = 0.01923077f;
        break;
    default:
        dir = 0.0f;
        break;
    }
    D_L01_001D8CCC += dir * speed;
}
/* localdecomp:end func_L01_0048DF60 */
