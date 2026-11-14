#include "common.h"

/* NTSC-U counterpart of func_L02_004B7370 (src/levels/shared/L02_004B7370.c) */
/* localdecomp:start func_L02_004B31E0 */
typedef struct {
    u8 pad0[0x80];
    u8 v80[0x10];
    u8 pad90[0x238 - 0x90];
    s32 w238;
    u8 pad23C[0x25C0 - 0x23C];
    u8 *p25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 b25E4;
    u8 pad25E5[0x25F8 - 0x25E5];
    s32 w25F8;
    u8 pad25FC[0x2888 - 0x25FC];
    s16 h2888;
    s16 h288A;
    s16 h288C;
} H_004B31E0;

extern H_004B31E0 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern void func_L01_0050BF58(void);
extern void func_L01_004EA708(void);
extern void func_L02_004B97B8(void);
extern void func_L02_004D5DE0(void);
extern void func_L01_004E5688_004B31E0(void);
extern void func_L01_004F1208(void);
extern void func_L01_004DC790(void);
extern void func_L01_004E09A8(void);
extern void func_L01_004DF380(void);
extern void func_L01_0050EE90(void);
extern void func_L01_004DF108(void);
extern void func_L01_0042D288(void *);
extern void func_L01_004E0B00(void);
extern void func_L01_004405F4(void *);

void func_L02_004B31E0(void) {
    func_L01_0050BF58();
    func_L01_004EA708();
    func_L02_004B97B8();
    D_001A4BE0.w238 = 4;
    func_L02_004D5DE0();
    func_L01_004E5688_004B31E0();
    if (D_001A4BE0.b25E4 != 0) {
        func_L01_004F1208();
        func_L01_004DC790();
        if (D_001A4BE0.b25E4 != 0) {
            func_L01_004E09A8();
            func_L01_004DF380();
            func_L01_0050EE90();
            func_L01_004DF108();
            func_L01_0042D288(D_001A4BE0.v80);
            if (D_001A4BE0.b25E4 == 3) {
                if (D_001A4BE0.w25F8 != 0 && D_001A4BE0.w25F8 != 0x1E) {
                    if (D_001A4BE0.h288C == 0) {
                        D_001A4BE0.h2888 = 1;
                        D_001A4BE0.h288C = 0x12;
                        D_001A4BE0.h288A = 1;
                    }
                } else {
                    D_001A4BE0.w25F8 = 0;
                }
            }
            func_L01_004E0B00();
            func_L01_004405F4(D_001A4BE0.p25C0);
        }
    }
}
/* localdecomp:end func_L02_004B31E0 */
