#include "common.h"

/* localdecomp:start func_L39_00675830 */
typedef struct S_00675830 {
    u8 pad0[0x48];
    s16 h48;
    s16 h4A;
    u8 pad4C[0xC];
    s32 w58;
    s32 w5C;
    u8 pad60[0x10];
    s32 w70;
    s32 w74;
    s32 w78;
    u8 pad7C[0x14];
} S_00675830;

extern S_00675830 D_L39_00498B10[];
extern u8 D_L39_00246510[8];
extern u8 *func_L39_0061BF38(s32);
extern s32 func_L39_005C42E8(s32, s32);
extern void func_L39_00674F50(u8 *);

void func_L39_00675830(S_00675830 *p) {
    s32 i = p - D_L39_00498B10 - 8;
    u8 *s = func_L39_0061BF38(i);
    u8 *q;
    s32 m = func_L39_005C42E8(8, *(s32 *)(s + 0x2544)) | 2;

    q = *(u8 **)(s + 0x2534);
    if ((*(u32 *)(q + 0x1C0) & m) != 0) {
        *(s32 *)(q + 0x1C4) = 0;
        D_L39_00246510[i] = 4;
    } else {
        D_L39_00246510[i] = 0;
    }
    func_L39_00674F50(s);
    p->w58 = 0xD2;
    p->w5C = 0xC8;
    p->w74 = -2;
    p->w78 = 0x19;
    p->h48 = 0;
    p->h4A = 0;
    p->w70 = 0;
}
/* localdecomp:end func_L39_00675830 */
