/* PAL level-07 reconstruction from the owned retail ELF (Wave2 P04).
 * Near miss: stock tools/check.py reports 243 diff with the owning-file flags.
 * Activation/list-walk reconstruction; saved registers, list-loop control and subsequent instruction alignment still differ.
 * Checked with the owning file's normal prelude/earlier declarations; not linked.
 */
#include "common.h"
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
extern u8 *D_L07_001DF420;
extern s32 D_L07_001DF458;
extern s32 D_L07_00142668;
extern s32 func_00382468(s32);
extern void func_L07_003C0638(void *, s32);
extern void func_L07_003B2870(void *);
extern void func_L07_003A8D58(void *, s32, void *);
extern void func_L07_003B91C8(void *, s32, void *);
extern void func_L07_003BCCD0(void *, s32, void *);
extern void func_L07_003C8608(void *, s32, void *);
extern void func_L07_003BE2A0(void *, s32, void *);
extern void func_L07_003B04C8(void *, s32, void *);
extern void func_L07_003510B8(void *, s32, void *);
extern void func_L07_003CCD40(void *, s32, void *);
extern void func_L07_003D2B98(void *, s32, void *);
extern void func_L07_003B9948(void *, s32);
extern void func_L07_003E3458(void *, s32);
extern void func_L07_003BB768(u8 *);
void func_L07_003BA500(u8 *self, s32 index) {
    u8 *p = *(u8 **)(self + 0x68);
    u8 *m;
    u16 *list = D_L07_0021C020[*(s32 *)(p + 0x40)];
    p[0xAE] = index;
    while ((u8)*(s32 *)(p + 0x40) != 255 && *(s32 *)(p + 0x40) <= D_L07_001DF458 && list &&
           ((s16)list[-1] >= 0 || list == D_L07_0021C020[*(s32 *)(p + 0x40)])) {
        m = D_L07_001DF41C + ((*list & 0x7FFF) << 8);
        if (!m) break;
        list++;
        func_L07_003C0638(m, p[0xAE]);
    }
    list = D_L07_0021C020[*(s32 *)(p + 0x44)];
    while ((u8)*(s32 *)(p + 0x44) != 255 && *(s32 *)(p + 0x44) <= D_L07_001DF458 && list &&
           ((s16)list[-1] >= 0 || list == D_L07_0021C020[*(s32 *)(p + 0x44)])) {
        m = D_L07_001DF41C + ((*list & 0x7FFF) << 8);
        if (!m) break;
        list++;
        func_L07_003B2870(m);
    }
    for (m = D_L07_001DF41C; m < D_L07_001DF420; m += 0x100) {
        if (m[0xB0] != *(s32 *)(p + 0x4C)) {
            switch (*(s16 *)(m + 0xAA)) {
            case 0x1982: func_L07_003A8D58(m, p[0xAE], self); break;
            case 0x1A4A: func_L07_003B91C8(m, p[0xAE], self); break;
            case 0x19D2: case 0x1A85: case 0x1D88: func_L07_003BCCD0(m, p[0xAE], self); break;
            case 0x19BD: case 0x1ADB: case 0x1D8A: func_L07_003C8608(m, p[0xAE], self); break;
            case 0x19BE: case 0x1A9B: case 0x1D89: func_L07_003BE2A0(m, p[0xAE], self); break;
            case 0x19DA: func_L07_003B04C8(m, p[0xAE], self); break;
            case 0x161E: func_L07_003510B8(m, p[0xAE], self); break;
            case 0x1769: case 0x1B36: case 0x1D8B: func_L07_003CCD40(m, p[0xAE], self); break;
            case 0x1C34: func_L07_003D2B98(m, p[0xAE], self); break;
            case 0x1A58: func_L07_003B9948(m, p[0xAE]); break;
            case 0x1E26: func_L07_003E3458(m, p[0xAE]); break;
            }
        }
    }
    *(s16 *)(p + 0xA0) = 0; *(s16 *)(p + 0xA2) = 0; *(s16 *)(p + 0xA4) = 0;
    *(s32 *)(p + 0x94) = 0; *(s32 *)(p + 0x98) = 0; *(s16 *)(p + 0xA6) = 0; *(s16 *)(p + 0xAA) = 0;
    *(s16 *)(p + 0xA8) = func_00382468(50) + 100; *(s16 *)(p + 0xAC) = 0;
    *(s32 *)((u8 *)&D_001A4BE0 + 0x2850) = D_L07_00142668;
    func_L07_003BB768(self);
    func_L01_004450F0(self, 2, -1);
}
