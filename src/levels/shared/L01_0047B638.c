#include "common.h"

/* localdecomp:start func_L01_0047B638 */
extern s32 func_L01_0047B638(s32);
extern void func_003E4EA8();

typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_003E4588(s32);
extern void func_003E4F10(void);
extern void func_003E4EA8(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0410;
extern s32 D_L01_001E0430;
extern s32 D_L01_001E0450;
extern s32 D_L01_001E0470;
extern s32 D_L01_001E03F8[2];
extern s32 D_L01_001E0418[2];
extern s32 D_L01_001E0438[2];
extern s32 D_L01_001E0458[2];
extern V16_3DF9E0 D_L01_001D80B8[];
s32 func_L01_0047B638(s32 idx) {
    V16_3DF9E0 v;
    if (D_L01_001E0410 == 0) {
        func_003E6FA0(D_L01_001E03F8, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_L01_001E0410 = 1;
    }
    if (D_L01_001E0430 == 0) {
        func_003E6FA0(D_L01_001E0418, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_L01_001E0430 = 1;
    }
    if (D_L01_001E0450 == 0) {
        func_003E6FA0(D_L01_001E0438, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_L01_001E0450 = 1;
    }
    if (D_L01_001E0470 == 0) {
        func_003E6FA0(D_L01_001E0458, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_L01_001E0470 = 1;
    }
    v = D_L01_001D80B8[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_0047B638 */
