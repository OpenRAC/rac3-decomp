/* near miss (level 22): 99 diff with --as ps2as; logic follows retail (all branches present), but gcc keeps one more value in a callee-saved register (frame 0x30 vs 0x20, extra $s3) and folds D_001A4BE0+0x35C into one lui/lw where retail builds hi/lo apart ($17 holds the hi half for later); needs @ps2as only if the file is made ps2as, default flags otherwise */
#include "common.h"

/* localdecomp:start func_L22_003BC778 */
typedef struct { u8 pad[0x18]; u8 *f18; } S_3BC778;
extern u8 D_001BBC40[];
extern u8 D_001D5570[];
extern u8 D_001A4BE0[];
extern S_3BC778 D_L22_001E9840;
extern s32 D_001D545C;
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_0043B510(s32);
extern void func_L01_004A3610(void *, void *);
extern u8 *func_L01_0045B958(void);
s32 func_L22_003BC778(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    u8 *p;
    s32 id;
    if (*(s32 *)(st + 0x20) != 0) {
        if (D_001BBC40[self[0xB0] + (D_001D545C << 4)] & 0x80) return 1;
    }
    if (*(s32 *)(st + 0x30) != 0) {
        if (D_001D5570[*(s32 *)(st + 0x30)] != 0) return 1;
    }
    if (*(u8 **)(D_001A4BE0 + 0x35C) == self) {
        if (*(s32 *)(D_001A4BE0 + 0x360) >= 2) return 1;
    }
    if (func_L01_003FB640(self + 0x10, 1, self, *(f32 *)(self + 0x2C) * 1.1f / *(f32 *)(*(u8 **)(self + 0x24) + 0x24)) == 0) return 0;
    if (D_L22_001E9840.f18 == 0) return 0;
    if ((u8 *)D_L22_001E9840.f18 == *(u8 **)(D_001A4BE0 + 0x25C0) && *(u8 **)(D_001A4BE0 + 0x35C) == self) {
        if (*(s32 *)(st + 0x20) == 0) return 1;
        func_L01_0043B510(self[0xB0]);
        func_L01_004A3610(D_001A4BE0 + 0x80, D_001A4BE0 + 0x90);
        return 1;
    }
    if (!(*(u16 *)(D_L22_001E9840.f18 + 0x34) & 0x20)) return 0;
    p = func_L01_0045B958();
    if (p == 0) return 0;
    if (*(u8 **)(p + 0x88) != self && *(u8 **)(p + 0x84) != self) return 0;
    id = *(s16 *)(D_L22_001E9840.f18 + 0xAA);
    if (id == 0x1A4E || id == 0x1AA0 || id == 0x1BD3 || id == 0x16BE || id == 0x1BA0) return 1;
    return 0;
}
/* localdecomp:end func_L22_003BC778 */
