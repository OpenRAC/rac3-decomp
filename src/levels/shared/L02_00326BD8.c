#include "common.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x60 - 0x1C];
    f32 f60;
    f32 f64;
    f32 f68;
} State_416A50;
typedef struct {
    u8 pad0[0x24];
    f32 f24;
} Class_416A50;
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x20 - 0x1C];
    u8 b20;
    u8 pad2[0x24 - 0x21];
    Class_416A50 *cls;
    u8 pad3[0x2C - 0x28];
    f32 f2C;
    u8 pad4[0x68 - 0x30];
    State_416A50 *st;
    u8 pad5[0xF0 - 0x6C];
    f32 fF0;
    f32 fF4;
    f32 fF8;
    f32 fFC;
} Obj_416A50;

/* localdecomp:start func_L02_00326BD8 */
typedef struct {
    char pad0[0xB9];
    u8 done;
} State;

extern State D_001426E0;
extern s32 D_L02_001DC920;
extern s32 func_L01_004527A0(s32);
extern s32 func_L01_004527F0(s32);
extern void func_0039EF28(void);
extern void func_L01_00451F60(s32, s32, s32);

void func_L02_00326BD8(void) {
    s32 a;
    s32 b;
    s32 i;

    D_L02_001DC920++;
    if (D_001426E0.done == 0) {
        a = 0;
        b = 0;
        for (i = 0; i < 36; i++) {
            a += func_L01_004527A0(i);
            b += func_L01_004527F0(i);
        }
        if (a >= b) {
            D_001426E0.done = 1;
            func_0039EF28();
            func_L01_00451F60(4784, -1, 0);
        }
    }
}
/* localdecomp:end func_L02_00326BD8 */
