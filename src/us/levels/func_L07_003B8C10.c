#include "common.h"

/* NTSC-U counterpart of func_L07_003BA500 (src/levels/07_annihilation_nation/L07_003B9A90.c): the random timer is 60 + 120 frames, not 50 + 100 */
/* localdecomp:start func_L07_003B8C10 */
typedef struct { u8 pad[0x2850]; s32 health; } Hero_003BA500;
extern Hero_003BA500 D_001A4BE0;
extern void func_L07_003BECE8(u8 *, s32);
extern void func_L07_003B0FB8(u8 *);
extern void func_L07_003A7518(u8 *, s32, u8 *);
extern void func_L07_003B78D8(u8 *, s32, u8 *);
extern void func_L07_003BB3C0(u8 *, s32, u8 *);
extern void func_L07_003C6C48(u8 *, s32, u8 *);
extern void func_L07_003BC958(u8 *, s32, u8 *);
extern void func_L07_003AEC48(u8 *, s32, u8 *);
extern void func_L07_00350400(u8 *, s32, u8 *);
extern void func_L07_003CB328(u8 *, s32, u8 *);
extern void func_L07_003D10A8(u8 *, s32, u8 *);
extern void func_L07_003B8058(u8 *, s32);
extern void func_L07_003E1668(u8 *, s32);
extern s32 func_0037E1D8(s32);
extern void func_L07_003B9E78(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
extern u8 *D_L07_001DF420;
extern s32 D_L07_001DF458;
extern s32 D_00142660[];
void func_L07_003B8C10(u8 *obj, s32 state) {
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *m;
    s32 index = *(s32 *)(vars + 0x40);
    s16 *list;
    vars[0xAE] = state;
    list = D_L07_0021C020[index];
    while ((*(s32 *)(vars + 0x40) & 0xFF) != 0xFF &&
           *(s32 *)(vars + 0x40) <= D_L07_001DF458 &&
           list != 0 &&
           (list[-1] >= 0 || list == D_L07_0021C020[*(s32 *)(vars + 0x40)])) {
        m = D_L07_001DF41C + ((list[0] & 0x7FFF) << 8);
        if (m == 0) break;
        func_L07_003BECE8(m, vars[0xAE]);
        list++;
    }
    { s16 *second = D_L07_0021C020[*(s32 *)(vars + 0x44)];
    while ((*(s32 *)(vars + 0x44) & 0xFF) != 0xFF &&
           *(s32 *)(vars + 0x44) <= D_L07_001DF458 &&
           second != 0 &&
           (second[-1] >= 0 || second == D_L07_0021C020[*(s32 *)(vars + 0x44)])) {
        m = D_L07_001DF41C + ((second[0] & 0x7FFF) << 8);
        if (m == 0) break;
        func_L07_003B0FB8(m);
        second++;
    }
    }
    for (m = D_L07_001DF41C; m < D_L07_001DF420; m += 0x100) {
        if (m[0xB0] == *(s32 *)(vars + 0x4C)) continue;
        switch (*(s16 *)(m + 0xAA)) {
        case 0x1982: func_L07_003A7518(m, vars[0xAE], obj); break;
        case 0x1A4A: func_L07_003B78D8(m, vars[0xAE], obj); break;
        case 0x19D2:
        case 0x1A85:
        case 0x1D88: func_L07_003BB3C0(m, vars[0xAE], obj); break;
        case 0x19BD:
        case 0x1ADB:
        case 0x1D8A: func_L07_003C6C48(m, vars[0xAE], obj); break;
        case 0x19BE:
        case 0x1A9B:
        case 0x1D89: func_L07_003BC958(m, vars[0xAE], obj); break;
        case 0x19DA: func_L07_003AEC48(m, vars[0xAE], obj); break;
        case 0x161E: func_L07_00350400(m, vars[0xAE], obj); break;
        case 0x1769:
        case 0x1B36:
        case 0x1D8B: func_L07_003CB328(m, vars[0xAE], obj); break;
        case 0x1C34: func_L07_003D10A8(m, vars[0xAE], obj); break;
        case 0x1A58: func_L07_003B8058(m, vars[0xAE]); break;
        case 0x1E26: func_L07_003E1668(m, vars[0xAE]); break;
        }
    }
    *(s16 *)(vars + 0xA0) = 0;
    *(s16 *)(vars + 0xA2) = 0;
    *(s16 *)(vars + 0xA4) = 0;
    *(s32 *)(vars + 0x94) = 0;
    *(s32 *)(vars + 0x98) = 0;
    *(s16 *)(vars + 0xA6) = 0;
    *(s16 *)(vars + 0xAA) = 0;
    *(s16 *)(vars + 0xA8) = func_0037E1D8(60) + 120;
    *(s16 *)(vars + 0xAC) = 0;
    D_001A4BE0.health = D_00142660[2];
    func_L07_003B9E78(obj);
    func_L01_00441FB8(obj, 2, -1);
}
/* localdecomp:end func_L07_003B8C10 */
