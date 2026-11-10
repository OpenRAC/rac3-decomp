#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_003E8630(s32, s32);
s32 func_L39_0067F1B0(void);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00681018 */
s32 func_L39_0067F1B0(void);
s32 func_003E8630(s32, s32);
s32 func_003E9138(s32, u32, s32, f32, f32, f32, f32);
s32 func_L01_00517190(s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);
void func_L39_00681158(void *);
extern s32 D_L39_0024736C __attribute__((section(".data")));

void func_L39_00681018(void *arg0) {
    u8 *p = arg0;
    s32 t;

    if (*(s32 *)(p + 0x64) == -1) {
        t = func_L39_0067F1B0();
        *(s32 *)(p + 0x64) = t;
        func_003E9138(t, 0x80808080, 0, *(f32 *)(p + 0x50), *(f32 *)(p + 0x54), *(f32 *)(p + 0x58), *(f32 *)(p + 0x5C));
        func_L01_00517190(*(s32 *)(p + 0x64), 0);
        func_003E8630(D_L39_0024736C, *(s32 *)(p + 0x64));
        t = func_L39_0067F1B0();
        *(s32 *)(p + 0x68) = t;
        func_003E9138(t, 0, 0, *(f32 *)(p + 0x50), *(f32 *)(p + 0x54), *(f32 *)(p + 0x58), *(f32 *)(p + 0x5C));
        func_L01_00517190(*(s32 *)(p + 0x68), 0);
        func_003E8630(D_L39_0024736C, *(s32 *)(p + 0x68));
        *(s32 *)(p + 0x74) = 0;
        *(u8 *)(p + 0x78) = 0;
        if (*(s32 *)(p + 0x64) >= 0) {
            func_L01_00516AA0(*(s32 *)(p + 0x64), 0x8000, *(u8 *)(p + 0x6C) ^ 1);
        }
        if (*(s32 *)(p + 0x68) >= 0) {
            func_L01_00516AA0(*(s32 *)(p + 0x68), 0x8000, *(u8 *)(p + 0x6C) ^ 1);
        }
        if (*(u32 *)(p + 0x7C) < 0x4A) {
            func_L39_00681158(p);
        }
    }
}
/* localdecomp:end func_L39_00681018 */
