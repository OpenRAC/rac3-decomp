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
s32 func_L39_00688340(s32, s32, s32);

/* localdecomp:start func_L39_00686768 */
void func_L39_00686768(void *arg0) {
    S_00686768 *s = arg0;
    u8 *self = arg0;
    s32 i;
    s32 n = *(s32 *)(self + 0x270);
    if (n >= 0) {
        u8 *o = s->arr[n];
        u8 *vt = *(u8 **)(o + 0x60);
        Fn_00686768 f = *(Fn_00686768 *)(vt + 0x18);
        f(o);
    }
    for (i = *(s32 *)(self + 0x270) + 1; i <= *(s32 *)(self + 0x274); i++) {
        u8 *o = ((u8 **)(self + 0x110))[i];
        u8 *vt = *(u8 **)(o + 0x60);
        Fn_00686768 f = *(Fn_00686768 *)(vt + 0x18);
        f(o);
    }
}
/* localdecomp:end func_L39_00686768 */

INCLUDE_ASM("asm/levels", func_L39_00686810);

INCLUDE_ASM("asm/levels", func_L39_00686E40);

/* localdecomp:start func_L39_00687268 */
extern void func_L39_00686E40(void *);
extern s32 func_L39_00688340(s32, s32, s32);
extern void func_00195410(void);

void func_L39_00687268(void *arg0, s32 arg1) {
    s32 saved;

    *(s32 *)((u8 *)arg0 + 0x28C) = arg1;
    saved = *(s32 *)((u8 *)arg0 + 0x274);
    func_L39_00686E40(arg0);
    func_L39_00688340(0x15, 0, 0);
    do {
        func_00195410();
        (*(void (**)(void *))(*(u8 **)((u8 *)arg0 + 0x60) + 0xE8))(arg0);
        func_L39_00686E40(arg0);
    } while (*(s32 *)((u8 *)arg0 + 0x274) != saved);
    func_L39_00688340(0x14, 0, 0);
}
/* localdecomp:end func_L39_00687268 */

INCLUDE_ASM("asm/levels", func_L39_006872E8);
