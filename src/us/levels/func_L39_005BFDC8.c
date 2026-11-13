#include "common.h"

/* NTSC-U counterpart of func_L39_005C1E10 (src/levels/shared/L39_005C1E10.c) */
/* localdecomp:start func_L39_005BFDC8 */
typedef struct S_005C1E10 {
    u8 pad0[0x2C];
    s16 h2C;
    u8 pad2E[0xE];
    s16 h3C;
    s16 h3E;
    u8 pad40[4];
    s32 w44;
    s16 h48;
    u8 pad4A[2];
    s16 h4C;
    s16 h4E;
    u8 pad50[0x1C];
    s32 w6C;
    u8 pad70[4];
    s16 h74;
    s16 h76;
    u8 pad78[0x1C];
    s32 w94;
    u8 pad98[4];
    s16 h9C;
    s16 h9E;
    u8 padA0[0x1C];
    s32 wBC;
    u8 padC0[4];
    s16 hC4;
    s16 hC6;
} S_005C1E10;

extern s32 D_001D7CF8_sda;
extern s32 D_L39_0024C280_2;
__asm__(".extern D_L39_0024C280, 16");
extern s32 D_L39_0024C280;
extern S_005C1E10 D_L39_002257E0;
extern void func_00194760(void);
extern void func_00194820(void);
extern s32 func_00193680(void);
extern s32 func_00139E08(s32);
extern void func_00194A38(s32);

void func_L39_005BFDC8(void) {
    u16 t;
    D_001D7CF8_sda = 1;
    D_L39_0024C280_2 = 0xB4;
    func_00194760();
    func_00194820();
    while (func_00193680() != 0) {
        func_00139E08(0);
        if (D_L39_0024C280 == 0) {
            break;
        }
        D_L39_0024C280--;
    }
    func_00194A38(1);
    t = D_L39_002257E0.h3C;
    D_L39_002257E0.h4E = 0;
    D_L39_002257E0.h4C = 0;
    D_L39_002257E0.w44 = 0;
    if (D_L39_002257E0.h3C != -1) {
        D_L39_002257E0.h48 = t;
    }
    D_L39_002257E0.h76 = 0;
    D_L39_002257E0.h74 = 0;
    D_L39_002257E0.w6C = 0;
    D_L39_002257E0.h9E = 0;
    D_L39_002257E0.h9C = 0;
    D_L39_002257E0.w94 = 0;
    D_L39_002257E0.hC6 = 0;
    D_L39_002257E0.hC4 = 0;
    D_L39_002257E0.wBC = 0;
    D_L39_002257E0.h2C = 0;
    D_L39_002257E0.h3C = -1;
    D_L39_002257E0.h3E = -1;
    D_001D7CF8_sda = 0;
}
/* localdecomp:end func_L39_005BFDC8 */
