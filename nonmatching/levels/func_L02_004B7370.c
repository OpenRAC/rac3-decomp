/* func_L02_004B7370: 40 diff with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division), checked at its home place. Calls, order of the 0x238 store, the 0x25E4 tests and the 0x288x timer logic are right. Still differs: retail keeps the %hi of D_1A4BE0 in $s2 across the calls and forms each field address as addiu $v0,$s2,0x4BE0 (gcc folds it into a lui per use), and the frame saves $s2 in retail. Tried: local u8 *g set at the top (lui hoisted, 63 diff), g set after the first call (58 diff). */
#include "common.h"

extern u8 D_001A4BE0[];
extern void func_L01_0050FF00(void);
extern void func_L01_004EE4E0(void);
extern void func_L02_004BDA00(void);
extern void func_L02_004DA1D0(void);
extern void func_L01_004E9450(void);
extern void func_L01_004F5010(void);
extern void func_L01_004E04A0(void);
extern void func_L01_004E4770(void);
extern void func_L01_004E3148(void);
extern void func_L01_00512E68(void);
extern void func_L01_004E2ED0(void);
extern void func_L01_00430118(void *);
extern void func_L01_004E48C8(void);
extern void func_L01_004436F4(void *);

void func_L02_004B7370(void) {
    func_L01_0050FF00();
    func_L01_004EE4E0();
    func_L02_004BDA00();
    *(s32 *)(D_001A4BE0 + 0x238) = 3;
    func_L02_004DA1D0();
    func_L01_004E9450();
    if (D_001A4BE0[0x25E4] == 0)
        return;
    func_L01_004F5010();
    func_L01_004E04A0();
    if (D_001A4BE0[0x25E4] == 0)
        return;
    func_L01_004E4770();
    func_L01_004E3148();
    func_L01_00512E68();
    func_L01_004E2ED0();
    func_L01_00430118(D_001A4BE0 + 0x80);
    if (D_001A4BE0[0x25E4] == 3) {
        if (*(s32 *)(D_001A4BE0 + 0x25F8) == 0 || *(s32 *)(D_001A4BE0 + 0x25F8) == 30) {
            *(s32 *)(D_001A4BE0 + 0x25F8) = 0;
        } else if (*(s16 *)(D_001A4BE0 + 0x288C) == 0) {
            *(s16 *)(D_001A4BE0 + 0x288A) = 1;
            *(s16 *)(D_001A4BE0 + 0x288C) = 0x12;
            *(s16 *)(D_001A4BE0 + 0x2888) = 1;
        }
    }
    func_L01_004E48C8();
    func_L01_004436F4(*(void **)(D_001A4BE0 + 0x25C0));
}
