#include "common.h"

/* localdecomp:start func_L02_004B7370 */
typedef struct {
    u8 p0[0x238]; s32 mode;
    u8 p23C[0x25C0-0x23C]; u8 *moby;
    u8 p25C4[0x25E4-0x25C4]; u8 critter;
    u8 p25E5[0x25F8-0x25E5]; s32 active;
    u8 p25FC[0x2888-0x25FC]; s16 a, b, c;
} Hero_004B7370;
extern Hero_004B7370 D_001A4BE0;
extern void func_L01_0050FF00(void);
extern void func_L01_004EE4E0(void);
extern void func_L02_004BDA00(void);
extern void func_L02_004DA1D0(void);
extern void func_L01_004E9450_004B7370(void);
extern void func_L01_004F5010(void);
extern void func_L01_004E04A0(void);
extern void func_L01_004E4770(void);
extern void func_L01_004E3148(void);
extern void func_L01_00512E68(void);
extern void func_L01_004E2ED0(void);
extern void func_L01_00430118(void *);
extern void func_L01_004E48C8(void);
extern void func_L01_004436F4(u8 *);
void func_L02_004B7370(void) {
    func_L01_0050FF00();
    func_L01_004EE4E0();
    func_L02_004BDA00();
    D_001A4BE0.mode = 3;
    func_L02_004DA1D0();
    func_L01_004E9450_004B7370();
    if (D_001A4BE0.critter == 0) return;
    func_L01_004F5010();
    func_L01_004E04A0();
    if (D_001A4BE0.critter == 0) return;
    func_L01_004E4770();
    func_L01_004E3148();
    func_L01_00512E68();
    func_L01_004E2ED0();
    func_L01_00430118((u8 *)&D_001A4BE0 + 0x80);
    if (D_001A4BE0.critter == 3) {
        if (D_001A4BE0.active != 0 && D_001A4BE0.active != 30) {
            if (D_001A4BE0.c == 0) {
                D_001A4BE0.a = 1;
                D_001A4BE0.c = 18;
                D_001A4BE0.b = 1;
            }
        } else {
            D_001A4BE0.active = 0;
        }
    }
    func_L01_004E48C8();
    func_L01_004436F4(D_001A4BE0.moby);
}
/* localdecomp:end func_L02_004B7370 */
