#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L23_004CF810 */
extern u8 D_001A4BE0[];
extern u8 D_L23_00250540[];
extern u8 D_L23_00250B40[];
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern void func_003C2880(s32);
extern void func_L01_00439D70(s32, void *);
extern void func_003935B0(s32, s32);
extern void func_L01_004E04E8(void);
extern void func_00393BE8(void);
extern void func_00393C40(void);
extern void func_00394620(void);
extern s32 func_00393348(s32, s32, void *, void *, void *, s32, s32);
extern void func_L01_0041C828(s32);
extern void func_L01_004E1560(void);
extern void func_L01_0050FED0(void);
extern s32 func_L01_004DFCC8(u8 *, s32, s32, void *);
extern void func_L23_004E3428(s32, s32);

void func_L23_004CF810(void) {
    u8 *hero = D_001A4BE0;
    u8 *hero2, *hero3;
    u8 *moby, *from;
    s32 mode;

    if (hero[0x25E4] == 1) {
        *(s32 *)(hero + 0x2854) = *(s32 *)(hero + 0x2850);
        *(s32 *)(hero + 0x2850) = *(s16 *)(hero + 0x2858);
        if (*(s32 *)(hero + 0x1A20) != 0) {
            func_003C2880(*(s32 *)(hero + 0x1A20));
            *(s32 *)(hero + 0x1A20) = 0;
        }
        if (*(s32 *)(hero + 0x1A24) != 0) {
            func_003C2880(*(s32 *)(hero + 0x1A24));
            *(s32 *)(hero + 0x1A24) = 0;
        }
        if (*(s32 *)(hero + 0x1A50) != 0) {
            func_003C2880(*(s32 *)(hero + 0x1A50));
            *(s32 *)(hero + 0x1A50) = 0;
        }
        if (*(s32 *)(hero + 0x1A58) != 0) {
            func_003C2880(*(s32 *)(hero + 0x1A58));
            *(s32 *)(hero + 0x1A58) = 0;
        }
        if (*(s32 *)(hero + 0x1A10) != 0) {
            func_L01_00439D70(*(s32 *)(hero + 0x25C0), hero + 0x1A10);
        }
    }
    hero2 = D_001A4BE0;
    if (hero2[0x25E4] == 2) {
        if (*(s16 *)(hero2 + 0x1A88) != -1) {
            func_003935B0(*(s16 *)(hero2 + 0x1A88), 0);
            *(s16 *)(hero2 + 0x1A88) = -1;
        }
    }
    func_L01_004E04E8();
    hero3 = D_001A4BE0;
    hero3[0x25E4] = 0;
    func_00393348(0x23, 0, func_00393BE8, func_00393C40, func_00394620, 0, 0);
    func_L01_0041C828(3);
    if (*(u8 **)(hero3 + 0xBF4) != 0)
        *(u16 *)(*(u8 **)(hero3 + 0xBF4) + 0x34) &= 0xFFF9;
    *(s32 *)(hero3 + 0xBF4) = 0;
    if (*(s32 *)(hero3 + 0xBFC) != 0) {
        func_003C2880(*(s32 *)(hero3 + 0xBFC));
        *(s32 *)(hero3 + 0xBFC) = 0;
    }
    func_L01_004E1560();
    moby = *(u8 **)(hero3 + 0xBF8);
    from = hero3 + 0x80;
    *(u8 **)(hero3 + 0x25C0) = moby;
    *(u128_t *)(moby + 0x10) = *(u128_t *)from;
    *(s32 *)(*(u8 **)(hero3 + 0x25C0) + 0x9C) = 0;
    *(float *)(hero3 + 0xC04) = 1.0f;
    func_L01_0050FED0();
    if (*(u8 *)(*(u8 **)(hero3 + 0x25C0) + 0x42) != 0xFF)
        *(s32 *)(*(u8 **)(hero3 + 0x25C0) + 0x58) = func_L01_004DFCC8(*(u8 **)(hero3 + 0x25C0), *(u8 *)(*(u8 **)(hero3 + 0x25C0) + 0x42), *(u8 *)(*(u8 **)(hero3 + 0x25C0) + 0x40), D_L23_00250540);
    *(s32 *)(*(u8 **)(hero3 + 0x25C0) + 0x5C) = func_L01_004DFCC8(*(u8 **)(hero3 + 0x25C0), *(u8 *)(*(u8 **)(hero3 + 0x25C0) + 0x43), *(u8 *)(*(u8 **)(hero3 + 0x25C0) + 0x41), D_L23_00250B40);
    if (*(s32 *)(hero3 + 0x25C4) != 0x65 || ((mode = D_L23_001D6694) != 2 && mode != 6))
        func_L23_004E3428(0, 1);
}
/* localdecomp:end func_L23_004CF810 */
