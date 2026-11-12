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

/* localdecomp:start func_L39_00683180 */
typedef struct S_00683180 {
    u8 pad0[0x64];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683180;

void func_L39_00683180(S_00683180 *arg0) {
    arg0->f6C = -1;
    arg0->f70 = -1;
    arg0->f74 = -1;
    arg0->f64 = -1;
    arg0->f68 = -1;
}
/* localdecomp:end func_L39_00683180 */

/* localdecomp:start func_L39_006831A0 */
s32 func_L39_00688340(s32, s32, s32);

s32 func_L39_006831A0(void *arg0, s32 arg1) {
    s32 r = 0;
    s32 cur;

    if (arg1 == 4 || arg1 == 7) {
        r = 1;
        *(s32 *)((u8 *)arg0 + 0x80) += *(s32 *)((u8 *)arg0 + 0x84);
        func_L39_00688340(3, 0, 0);
    } else if (arg1 == 3) {
        r = 1;
        *(s32 *)((u8 *)arg0 + 0x80) -= *(s32 *)((u8 *)arg0 + 0x84);
        func_L39_00688340(3, 0, 0);
    }
    cur = *(s32 *)((u8 *)arg0 + 0x80);
    if (*(s32 *)((u8 *)arg0 + 0x7C) < cur) {
        *(s32 *)((u8 *)arg0 + 0x80) = *(s32 *)((u8 *)arg0 + 0x7C);
    } else if (cur < *(s32 *)((u8 *)arg0 + 0x78)) {
        *(s32 *)((u8 *)arg0 + 0x80) = *(s32 *)((u8 *)arg0 + 0x78);
    }
    return r;
}
/* localdecomp:end func_L39_006831A0 */
