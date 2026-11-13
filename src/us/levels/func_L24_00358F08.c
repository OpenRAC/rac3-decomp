#include "common.h"

/* NTSC-U counterpart of func_L24_00359FE0 (src/levels/24_insomniac_museum/L24_00359248.c): 12 -> 15 */
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

/* localdecomp:start func_L24_00358F08 */
extern u8 D_L24_001E2200_00358F08[];
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L24_00358D68(void *);
extern void func_L01_00443A90(void *, void *, s32, void *, f32);
extern void func_L24_003597D8(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004412D0(void *, s32, s32);
extern void func_003C2880(void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_L24_00359170(u8 *);
extern s32 func_L01_0044F5E8(void *, void *, s32);
extern void func_L01_004538E0(void *, s32);
extern f32 func_L24_003598E8(void *);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L24_00358F08(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L24_001E2200_00358F08, a0 + 0x10) < 576.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x16;
        }
    }
    if (a0[0x95] == 0 && a0[0x20] == 0) {
        func_L24_00358D68(a0);
    }
    if (*(f32 *)(a0 + 0x18) <= *(f32 *)(p + 0xB0)) {
        func_L01_00443A90(a0, a0, 0x10000, a0 + 0x10, (f32)*(s16 *)(p + 0x34));
    }
    if (a0[0xBC] != 0 && a0[0x95] != 5 && 0.0f < *(f32 *)(p + 0x30)) {
        func_L24_003597D8(a0, 0);
        func_L01_00441FB8(a0, 0xC, 5);
        if (a0[0x43] != 4) {
            func_003C3A10(a0, 4, 0, 0xF);
        }
        *(f32 *)(a0 + 0x48) = 0.75f;
    }
    if (p[0x5E] != 0) {
        func_L01_004412D0(a0, 0, 3);
        func_003C2880(a0);
        return;
    }
    if (func_L01_0044FCD0(a0, p + 0x70, 0, 0, 0) != 0) {
        func_L24_00359170(a0);
        func_L24_003597D8(a0, 1);
    }
    func_L01_0044F5E8(a0, p + 0x30, 0);
    if (p[0x5F] != 0) {
        func_L01_004538E0(a0, 5);
        func_L01_004539A8(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 3, 0, 0, 0, func_L24_003598E8(a0), 10.0f, 1.0f);
    } else {
        func_L01_004538E0(a0, 3);
        func_L01_004539A8(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 1, 0, 0, 0, func_L24_003598E8(a0), 10.0f, 1.0f);
    }
}
/* localdecomp:end func_L24_00358F08 */
