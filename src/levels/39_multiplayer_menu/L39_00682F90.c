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
s32 func_L39_00688340(s32, s32, s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);

/* localdecomp:start func_L39_00682F90 */
void func_L39_00682F90(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
}
/* localdecomp:end func_L39_00682F90 */

/* localdecomp:start func_L39_00682F98 */
s32 func_L39_00682F98(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00682F98 */

/* localdecomp:start func_L39_00682FA0 */
s32 func_L39_00682FA0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64)) != *(s32 *)((u8 *)arg0 + 0x68);
}
/* localdecomp:end func_L39_00682FA0 */

LINKER_REMNANT("asm/levels", func_L39_00682FB8);

/* localdecomp:start func_L39_00682FC0 */
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern u8 D_L39_0047BC68[];

void *func_L39_00682FC0(void *arg0, void *arg1) {
    S_00683550 *self = (S_00683550 *)arg0;

    func_L39_0067EE40(arg0, arg1);
    self->f60 = D_L39_0047BC68;
    self->f6C = -1;
    self->f70 = -1;
    self->f74 = -1;
    self->f64 = -1;
    self->f68 = -1;
    *(s32 *)((u8 *)arg0 + 0x78) = *(s32 *)((u8 *)arg1 + 0x48);
    *(s32 *)((u8 *)arg0 + 0x7C) = *(s32 *)((u8 *)arg1 + 0x4C);
    *(s32 *)((u8 *)arg0 + 0x80) = *(s32 *)((u8 *)arg1 + 0x50);
    *(s32 *)((u8 *)arg0 + 0x84) = *(s32 *)((u8 *)arg1 + 0x54);
    return arg0;
}
/* localdecomp:end func_L39_00682FC0 */

/* localdecomp:start func_L39_00683038 */
extern u8 D_L39_0047BC68[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00683038(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BC68;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00683038 */
