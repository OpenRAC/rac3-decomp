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

/* localdecomp:start func_L39_00682B80 */
extern s32 func_L39_0067F1B0(void);
extern void func_003E5360(s32);
extern void func_003E8630(s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 D_0024736C __attribute__((section(".data")));
extern u8 D_00247388[];

typedef struct {
    u8 pad0[0x68];
    s32 f68;
    u8 pad6C[0xA0 - 0x6C];
    s32 fA0;
    s32 fA4;
    s32 fA8;
} S_00682B80;

void func_L39_00682B80(S_00682B80 *arg0)
{
    if (arg0->fA0 == -1) {
        arg0->fA0 = func_L39_0067F1B0();
        func_003E5360(arg0->fA0);
        func_003E8630(D_0024736C, arg0->fA0);
        func_L01_00516C78(arg0->fA0, 1, 3);
    }
    if (arg0->fA4 == -1) {
        arg0->fA4 = func_L39_0067F1B0();
        func_003E5360(arg0->fA4);
        func_003E8630(D_0024736C, arg0->fA4);
        func_L01_00516FD8(arg0->fA4, (s32)D_00247388);
        func_L01_00516C78(arg0->fA4, 1, 3);
    }
    if (arg0->fA8 == -1) {
        arg0->fA8 = func_L39_0067F1B0();
        func_003E5360(arg0->fA8);
        func_003E8630(D_0024736C, arg0->fA8);
        func_L01_00516C78(arg0->fA8, 2, 3);
    }
    arg0->f68 = -999;
}
/* localdecomp:end func_L39_00682B80 */
