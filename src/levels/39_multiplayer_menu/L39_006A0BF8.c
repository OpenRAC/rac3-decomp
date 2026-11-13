#include "common.h"

/* declared by functions of L39_006A0AC0.c, which this file was cut from */
typedef struct W_006A0AC0 W_006A0AC0;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(W_006A0AC0 *, s32, s32);
    u8 pad20[4];
    void (*f24)(W_006A0AC0 *, void *);
} VT_006A0AC0;
struct W_006A0AC0 {
    u8 pad0[0x60];
    VT_006A0AC0 *vt;
};
typedef struct {
    u8 pad0[4];
    s32 state;
} T_006A0AC0;
typedef struct {
    u8 pad0[0x110];
    W_006A0AC0 *w110;
    W_006A0AC0 *w114;
    u8 pad118[4];
    T_006A0AC0 *t11C;
    u8 pad120[4];
    T_006A0AC0 *t124;
    T_006A0AC0 *t128;
} S_006A0AC0;
extern void func_L39_0068B2F8(S_006A0AC0 *, s32, s32);

INCLUDE_ASM("asm/levels", func_L39_006A0BF8);
