#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00681758.c, which this file was cut from */
extern void func_L39_0067EEC8(u8 *, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);

/* localdecomp:start func_L39_00683420 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_00683420(u8 *arg0, s32 arg1) {
    s32 mode = 2;

    if (arg1 == 1) {
        mode = 1;
    }
    if (*(s32 *)(arg0 + 0x64) != -1) {
        func_003E7F20(*(s32 *)(arg0 + 0x64), mode);
    }
    if (*(s32 *)(arg0 + 0x68) != -1) {
        func_003E7F20(*(s32 *)(arg0 + 0x68), mode);
    }
    return 1;
}
/* localdecomp:end func_L39_00683420 */

/* localdecomp:start func_L39_00683490 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00683490(void *arg0, s32 arg1, s32 arg2) {
    s32 r = 0;

    if (*(s32 *)((u8 *)arg0 + 0x64) != -1) {
        r = func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x64), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x68) != -1) {
        r |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x68), arg1, arg2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00683490 */

/* localdecomp:start func_L39_00683510 */
void func_L39_00683510(void *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = *(s32 *)((u8 *)arg0 + 0x7C);
    *(s32 *)((u8 *)arg0 + 0x80) = arg1;
    if ((var_v1 < arg1) || (var_v1 = (*(s32 *)((u8 *)arg0 + 0x78)), ((arg1 < var_v1) != 0))) {
        *(s32 *)((u8 *)arg0 + 0x80) = var_v1;
    }
}
/* localdecomp:end func_L39_00683510 */

/* localdecomp:start func_L39_00683540 */
s32 func_L39_00683540(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x80));
}
/* localdecomp:end func_L39_00683540 */

LINKER_REMNANT("asm/levels", func_L39_00683548);

/* localdecomp:start func_L39_00683550 */
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern u8 D_L39_0047BD58[];

S_00683550 *func_L39_00683550(S_00683550 *self, T_00683550 *o) {
    func_L39_0067EE40(self, o);
    self->f60 = D_L39_0047BD58;
    self->f64 = -1;
    self->f68 = -1;
    self->f6C = -1;
    self->f70 = -1;
    self->f74 = o->f48;
    return self;
}
/* localdecomp:end func_L39_00683550 */

/* localdecomp:start func_L39_006835B0 */
extern u8 D_L39_0047BD58[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006835B0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BD58;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_006835B0 */
