#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7058 - 0x4958];
    u8 fX[1];
} S_func_00498868;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_498978;
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_0049C950;
extern S_0049C950 *D_001D52FC[] __attribute__((section(".sdata")));

/* declared by functions of L01_0049BE80.c, which this file was cut from */
extern s32 func_L01_0049C630(void);

/* localdecomp:start func_L01_0049C630 */
extern s32 func_L01_0049C630(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0C10;
extern s32 D_L01_001E0BF8[2];
extern void func_L01_0049C688();
extern void func_L01_0049C9A0();
extern void func_L01_0049C950();
extern void func_L01_0049C9E8_0049C630(void);
extern void func_L01_0049CA08_0049C630();
s32 func_L01_0049C630(void) {
    if (D_L01_001E0C10 == 0) {
        func_003E6FA0(D_L01_001E0BF8, (s32)func_L01_0049C688, (s32)func_L01_0049C9A0, (s32)func_L01_0049C950, (s32)func_L01_0049C9E8_0049C630, (s32)func_L01_0049CA08_0049C630);
        D_L01_001E0C10 = 1;
    }
    return (s32)D_L01_001E0BF8;
}
/* localdecomp:end func_L01_0049C630 */
