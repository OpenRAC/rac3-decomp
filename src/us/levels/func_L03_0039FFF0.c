#include "common.h"

/* NTSC-U counterpart of func_L03_003A17D8 (src/levels/03_starship_phoenix/L03_003A13E8.c) */
#include "vu0.h"
typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0x47]; s32 *p68; } S_003A17D8;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } G_003A17D8;
#include "vu0.h"

/* localdecomp:start func_L03_0039FFF0 */
extern u8 D_001A4C60[];
extern u8 D_0014271D[];
extern s32 D_00142C14[];
extern u8 *D_L03_001DFA1C;
__asm__(".extern D_L03_001DFA1C, 16");
extern f32 D_L03_001DF350;
__asm__(".extern D_L03_001DF350, 16");
extern f32 D_L03_001DF358;
__asm__(".extern D_L03_001DF358, 16");
extern s32 D_L03_002D09F0[];
__asm__(".extern D_L03_002D09F0, 16");
extern G_003A17D8 *D_001D52FC;
__asm__(".extern D_001D52FC, 4");
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004FC518(s32, s32);
extern void func_L03_0032C828(void *);
extern s32 func_L03_003A04F0();
extern void func_L03_003A0290();
extern void func_L01_00441FB8(void *, s32, s32);

void func_L03_0039FFF0(S_003A17D8 *a) {
    s32 *p;
    u8 *o;
    func_L03_003A0290(a);
    p = a->p68;
    if (D_0014271D[0] != 0 && !(D_00142C14[2] & 0x20000000)
        && func_0037E0F0(D_001A4C60, p[1], 0) != 0) {
        o = D_L03_001DFA1C + (p[2] << 8);
        func_L01_00452F40(o, 1);
        (*(void (**)(void *))(o + 0x64))(o);
    }
    switch (a->f20) {
    case 1:
        if (func_L03_003A04F0(a) != 0) {
            func_L01_00441FB8(a, 2, -1);
        }
        break;
    case 2:
        func_L01_0044F2E8(0, 12, 0xA24, 1, 0, 0, 0);
        if (D_L03_002D09F0[0] == 12 && (D_001D52FC->f1A4 & 0x10)) {
            func_L01_00441FB8(a, 5, -1);
        } else if (func_L03_003A04F0(a) == 0) {
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 3:
        D_L03_001DF350 = D_L03_001DF350 - 0.1f;
        if (D_L03_001DF350 < 0.0f) {
            D_L03_001DF350 = 0.0f;
            func_L01_004FC518(0, 1);
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 5:
        D_L03_001DF350 = D_L03_001DF350 + 0.1f;
        if (D_L03_001DF350 >= 1.0f) {
            D_L03_001DF350 = 1.0f;
            func_L01_00441FB8(a, 6, -1);
        }
        break;
    case 6:
        func_L03_0032C828(D_L03_001DFA1C + (p[0] << 8));
        func_L01_00441FB8(a, 1, -1);
        break;
    case 7:
        D_L03_001DF350 = D_L03_001DF350 - 0.1f;
        if (D_L03_001DF350 <= 0.0f) {
            func_L01_004FC518(0, 1);
            D_L03_001DF350 = 0.0f;
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    case 8:
        D_L03_001DF358 = D_L03_001DF358 - 0.03f;
        if (D_L03_001DF358 <= 0.0f) {
            func_L01_004FC518(0, 1);
            D_L03_001DF358 = 0.0f;
            func_L01_00441FB8(a, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L03_0039FFF0 */
