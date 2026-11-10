#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
s32 func_L01_00516C78(s32, s32, s32);
s32 func_003E5360(s32);
s32 func_003E8630(s32, s32);
s32 func_L39_0067F1B0(void);

/* localdecomp:start func_L39_00680B18 */
s32 func_003E5360(s32);
s32 func_003E8630(s32, s32);
s32 func_L39_0067F1B0(void);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516FD8(s32, void *);
extern s32 D_L39_0024736C __attribute__((section(".data")));
extern u8 D_L39_00247388[];

void func_L39_00680B18(void *arg0) {
    s32 t;

    if (*(s32 *)((u8 *)arg0 + 0x1470) == -1) {
        t = func_L39_0067F1B0();
        *(s32 *)((u8 *)arg0 + 0x1470) = t;
        func_003E5360(t);
        func_003E8630(D_L39_0024736C, *(s32 *)((u8 *)arg0 + 0x1470));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x1470), 1, 3);
    }
    if (*(s32 *)((u8 *)arg0 + 0x1474) == -1) {
        t = func_L39_0067F1B0();
        *(s32 *)((u8 *)arg0 + 0x1474) = t;
        func_003E5360(t);
        func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0x1474), D_L39_00247388);
        func_003E8630(D_L39_0024736C, *(s32 *)((u8 *)arg0 + 0x1474));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x1474), 1, 3);
    }
    if (*(s32 *)((u8 *)arg0 + 0x1478) == -1) {
        t = func_L39_0067F1B0();
        *(s32 *)((u8 *)arg0 + 0x1478) = t;
        func_003E5360(t);
        func_003E8630(D_L39_0024736C, *(s32 *)((u8 *)arg0 + 0x1478));
        func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0x1478), 1, 3);
    }
}
/* localdecomp:end func_L39_00680B18 */
