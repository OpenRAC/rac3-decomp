#include "common.h"

/* NTSC-U counterpart of func_L39_00576B28 (src/levels/shared/L39_005768C8.c) */
extern s32 D_L39_0024BAC8;

/* localdecomp:start func_L39_00575DE8 */
extern s32 D_001A5990[];
extern s8 D_L39_0025D021[];
extern s32 D_L39_002412A8[];
__asm__(".extern D_001D6330_sda_00575DE8, 4");
extern s32 D_001D6330_sda_00575DE8;
__asm__(".extern D_001D6334_sda_00575DE8, 4");
extern s32 D_001D6334_sda_00575DE8;
/* the frame counter D_L39_0024BAC8, stored here through $gp (the prelude's .extern 16 makes the plain name lui) */
__asm__(".extern D_L39_0024BAC8_00575DE8, 4");
extern s32 D_L39_0024BAC8_00575DE8;
extern void func_L01_0045E370(void);
extern void func_L39_005F9780(void);
extern void func_L39_005F9EF0(void);
extern void func_L39_00577308(void);
extern s32 func_00139E08(s32);

void func_L39_00575DE8(void) {
    s32 limit;
    s32 t;

    t = *(volatile s32 *)0x10000800; /* T0_COUNT */
    limit = 0x2580;
    if (D_001A5990[0] != 0) {
        limit = 0x2D00;
    }
    if (D_001D6330_sda_00575DE8 == 0) {
        if (limit < t) {
            D_001D6330_sda_00575DE8 = 1;
            D_001D6334_sda_00575DE8 = 0;
        }
    } else if (D_001D6330_sda_00575DE8 == 1) {
        if (D_001D6334_sda_00575DE8 >= 2) {
            D_001D6330_sda_00575DE8 = 2;
            D_001D6334_sda_00575DE8 = 0;
        }
    } else if (D_001D6330_sda_00575DE8 == 2) {
        if (D_001D6334_sda_00575DE8 >= 4 && !(limit < t)) {
            D_001D6330_sda_00575DE8 = 3;
            D_001D6334_sda_00575DE8 = 0;
        }
    } else if (D_001D6330_sda_00575DE8 == 3) {
        D_001D6330_sda_00575DE8 = 0;
        D_001D6334_sda_00575DE8 = 0;
    }
    D_001D6334_sda_00575DE8++;
    if (D_001D6330_sda_00575DE8 != 0) {
        if (D_001D6330_sda_00575DE8 == 1) {
            D_L39_0024BAC8_00575DE8 = D_L39_0024BAC8 + 1;
            return;
        } else if (D_001D6330_sda_00575DE8 == 2) {
            if (limit < t) {
                D_001D6334_sda_00575DE8 = 0;
            }
            if (D_L39_002412A8[0] == 0) {
                func_L01_0045E370();
                func_L39_005F9780();
            } else if (D_L39_002412A8[0] == 2 && D_L39_0025D021[0] == 0) {
                func_L01_0045E370();
                func_L39_005F9EF0();
            }
            func_L39_00577308();
        } else if (D_001D6330_sda_00575DE8 == 3) {
            func_00139E08(0);
        } else {
            return;
        }
    }
    func_00139E08(0);
    D_L39_0024BAC8++;
}
/* localdecomp:end func_L39_00575DE8 */
