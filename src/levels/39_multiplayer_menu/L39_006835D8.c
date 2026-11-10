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

/* localdecomp:start func_L39_006835D8 */
extern s32 func_L39_0067F1B0(void);
extern void func_003E5360(s32);
extern void func_003E8630(s32, s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 D_0024736C __attribute__((section(".data")));
extern s32 D_001DBC5C_sda;

void func_L39_006835D8(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x64) == -1) {
        *(s32 *)(arg0 + 0x70) = func_L39_0067F1B0();
        func_003E9138(*(s32 *)(arg0 + 0x70), 0x40000000, 0,
                      *(f32 *)(arg0 + 0x50) + 0.008f, *(f32 *)(arg0 + 0x54) + 0.01f,
                      *(f32 *)(arg0 + 0x58), *(f32 *)(arg0 + 0x5C));
        func_003E8630(D_0024736C, *(s32 *)(arg0 + 0x70));
        *(s32 *)(arg0 + 0x68) = func_L39_0067F1B0();
        func_003E9138(*(s32 *)(arg0 + 0x68), 0x331465B7, 0,
                      *(f32 *)(arg0 + 0x50), *(f32 *)(arg0 + 0x54),
                      *(f32 *)(arg0 + 0x58), *(f32 *)(arg0 + 0x5C));
        func_003E8630(D_001DBC5C_sda, *(s32 *)(arg0 + 0x68));
        *(s32 *)(arg0 + 0x64) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)(arg0 + 0x64));
        func_003E8630(D_0024736C, *(s32 *)(arg0 + 0x64));
        *(s32 *)(arg0 + 0x6C) = func_L39_0067F1B0();
        func_003E9270(*(s32 *)(arg0 + 0x6C), 0x332299DE,
                      *(f32 *)(arg0 + 0x50), *(f32 *)(arg0 + 0x54),
                      *(f32 *)(arg0 + 0x58), *(f32 *)(arg0 + 0x5C), 0.004f, 0.005f);
        func_003E8630(D_001DBC5C_sda, *(s32 *)(arg0 + 0x6C));
    }
}
/* localdecomp:end func_L39_006835D8 */
