#include "common.h"

/* NTSC-U counterpart of func_L39_005F3948 (src/levels/shared/L39_005F3828.c) */
extern u8 D_L39_001FE1A0[];

/* localdecomp:start func_L39_005F1248 */
#include "vu0.h"

extern u8 D_L39_001FE1A0[];
extern u8 D_L39_001FE1F0[];
extern s32 D_001D86FC_sda;
extern void func_00194760(void);
extern s32 func_00193680(void);
extern void func_00193EE0(void);
extern s32 func_00139E08(s32);
extern void func_003A0200(void);

void func_L39_005F1248(void) {
    s32 i;
    u8 *p;

    func_00194760();
    func_00193680();
    func_00193EE0();
    D_001D86FC_sda = 0xB4;
    while (func_00193680() != 0) {
        func_00139E08(0);
        if (D_001D86FC_sda == 0) {
            break;
        }
        D_001D86FC_sda--;
    }
    for (i = 3; i >= 0; i--) {
        qzero(D_L39_001FE1F0 + i * 0x10);
    }
    p = D_L39_001FE1A0;
    *(s32 *)(p + 0x48) = 0;
    for (i = 0x33; i >= 0; i--) {
        *(s32 *)(p + 0xC0) = 0;
        p[0xD0] = 0;
        p += 0x80;
    }
    func_003A0200();
}
/* localdecomp:end func_L39_005F1248 */
