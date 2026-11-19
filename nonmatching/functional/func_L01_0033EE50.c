/* functional: high. Near miss at file flags (register choice/ordering only); constants (0x45AFDF66), gp slots (+0x770 float, +0x3778 list head) and the loop exits (type 0xFE/0xFD stop the scan) checked against retail. */
#include "vu0.h"
extern s32 D_L01_001DFB40[];
extern s32 D_001A71A0[];
extern f32 D_001DD020_sda;
extern u8 *D_001E0028_sda;
extern void func_003D4D00(void *, s32, s32, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_002F8F10(void *, void *);

void func_L01_0033EE50(u8 *m) {
    struct {
        vu0_q q0;
        u8 pad[0x24];
    } pk;
    u8 *n;
    u8 *pos;
    u8 *k;

    if (!(D_L01_001DFB40[0] & 1)) {
        return;
    }
    qzero(&pk);
    *(u16 *)((u8 *)&pk + 0x1A) = *(u16 *)(m + 0xAA);
    pos = m + 0x10;
    *(u8 *)((u8 *)&pk + 0x18) = 8;
    *(s32 *)((u8 *)&pk + 0x14) = 0x10000;
    *(f32 *)((u8 *)&pk + 0xC) = 5627.9248046875f;
    *(u8 **)((u8 *)&pk + 0x10) = m;
    *(u8 *)((u8 *)&pk + 0x19) = 0;
    *(s32 *)((u8 *)&pk + 0x1C) = 0;
    *(s32 *)((u8 *)&pk + 0x20) = 0;
    func_003D4D00(pos, 0, D_001A71A0[0], &pk, D_001DD020_sda);
    if (!(D_L01_001DFB40[0] & 1)) {
        return;
    }
    n = D_001E0028_sda;
    while (n != 0) {
        u8 t = n[0x20];
        if (t == 0xFE || t == 0xFD) {
            return;
        }
        k = *(u8 **)(n + 0x24);
        if (k != 0 && k[0x46] == 0x13) {
            if (func_0038CF00(n + 0x10, pos) < D_001DD020_sda) {
                func_L01_002F8F10(n, m);
            }
        }
        n = *(u8 **)(n + 0x28);
    }
}
