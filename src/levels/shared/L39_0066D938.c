#include "common.h"

/* declared by functions of L39_0066C808.c, which this file was cut from */
typedef struct {
    char pad0[0x44];
    union {
        u8 b;
        s32 w;
    } team;
    char pad48[0x50 - 0x48];
    u8 unk50;
} Obj;

/* localdecomp:start func_L39_0066D938 */
typedef struct {
    s32 pad0;
    s32 f4;
    u8 pad8[0x2C];
    s32 f34;
    u8 pad38[0x18];
    u8 f50;
} S_0066D938;
typedef struct {
    s32 pad[2];
    s32 f8;
} G_0066D938;
extern void func_L39_0061E1B8(S_0066D938 *, s32);
extern G_0066D938 D_001A5CD0;

void func_L39_0066D938(S_0066D938 *arg0, u8 arg1, u8 arg2) {
    if (func_L39_0066D888((Obj *)arg0, arg1, arg2) != 0) {
        arg0->f50 = arg1;
        if (arg0->f34 != D_001A5CD0.f8) {
            arg0->f34 = D_001A5CD0.f8;
            arg0->f4 = D_001A5CD0.f8;
            func_L39_0061E1B8(arg0, 0);
        }
    }
}
/* localdecomp:end func_L39_0066D938 */

/* localdecomp:start func_L39_0066D9A8 */
extern void func_L39_0061E278(s32 *);

void func_L39_0066D9A8(Obj *o, u8 b, u8 c) {
    if (func_L39_0066D888(o, b, c)) {
        o->unk50 = b;
        if (*(s32 *)((u8 *)o + 0x34) == D_001A5CD0.f8) {
            func_L39_0061E278((s32 *)o);
        }
        *(s32 *)((u8 *)o + 0x34) = -1;
        *(s32 *)((u8 *)o + 4) = -1;
    }
}
/* localdecomp:end func_L39_0066D9A8 */

/* localdecomp:start func_L39_0066DA10 */
extern s32 D_001A5CD8[];
extern void func_L39_0061E278(s32 *);
extern void func_L39_0066DA90(s32 *, s32, u8, u8);
void func_L39_0066DA10(s32 *a0, s32 a1, u8 a2, u8 a3) {
    if (a0[13] == D_001A5CD8[0]) {
        func_L39_0061E278(a0);
    }
    func_L39_0066DA90(a0, a1, a2, a3);
    a0[13] = -1;
    a0[1] = -1;
}
/* localdecomp:end func_L39_0066DA10 */
