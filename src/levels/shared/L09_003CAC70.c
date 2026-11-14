#include "common.h"

INCLUDE_ASM("asm/levels", func_L09_003CAC70);

/* localdecomp:start func_L09_003CACB0 */
extern u8 D_001A4BE0[];
extern s32 D_L09_001DFBC0;
extern s32 D_L09_001DFBC8;
extern f32 D_L09_001DF9D0;
__asm__(".extern D_L09_001DFBC0, 16");
__asm__(".extern D_L09_001DFBC8, 16");
__asm__(".extern D_L09_001DF9D0, 16");
extern s32 D_L09_002D1E30[];
extern s32 D_L09_001D6694[];
extern s32 D_L09_001D6694_003CACB0;
extern s32 D_L09_001D6690;
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L09_003C7B78(u8 *);
extern void func_L09_005164C0(s32, s32);
extern void func_L09_003CAC70(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L09_003CACB0(u8 *self) {
    s32 v;
    f32 d;
    u8 *p;
    u8 *hero;

    d = func_L01_0040E548(D_001A4BE0 + 0x80, self + 0x10);
    p = *(u8 **)(self + 0x68);
    if (d < 12.0f) {
        if (D_L09_001DFBC0 < 4 || D_L09_001DFBC8 < 4) {
            return;
        }
        hero = D_001A4BE0;
        if (*(s32 *)(hero + 0x25CC) != 0x1F
            && *(f32 *)(p + 0x30) > 0.0f && hero[0x25E4] == 0 && D_L09_001DF9D0 == 0.0f) {
            s32 st = *(s32 *)(hero + 0x25C4);
            if (st == 0x1D || st == 0x74 || st == 1) {
                return;
            }
            if (D_L09_002D1E30[0] != 4) {
                if (D_L09_002D1E30[0] != 0) {
                    return;
                }
                v = D_L09_001D6694[0];
            } else {
                v = D_L09_001D6694_003CACB0;
            }
            if (v == 2 || D_L09_001D6690 == 2) {
                return;
            }
            if (*(s16 *)(hero + 0x288C) == 0) {
                func_L01_00452560(0, 4, 0x8C2, 1, 0, 0, 0);
                if (*(u32 *)(*(u8 **)0x1D52FC + 0x1A4) & 0x10) {
                    func_L09_003C7B78(self);
                    func_L09_005164C0(0x31, 1);
                    func_L09_003CAC70(self);
                    func_L01_004450F0(self, 2, -1);
                    *(u16 *)(*(u8 **)(self + 0x68) + 0x710) |= 4;
                }
            }
        }
    }
}
/* localdecomp:end func_L09_003CACB0 */

/* localdecomp:start func_L09_003CAE58 */
s32 func_L09_003CAE58(u8 *obj) {
    return obj[32] == 2;
}
/* localdecomp:end func_L09_003CAE58 */

INCLUDE_ASM("asm/levels", func_L09_003CAE68);

INCLUDE_ASM("asm/levels", func_L09_003CB6C0);

INCLUDE_ASM("asm/levels", func_L09_003CB7B0);
