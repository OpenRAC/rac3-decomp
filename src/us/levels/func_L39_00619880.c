#include "common.h"

/* NTSC-U counterpart of func_L39_0061BFF8 (src/levels/shared/L39_0061BED0.c) */
extern s32 *D_L39_002412A0;

/* localdecomp:start func_L39_00619880 */
extern u8 D_001A5990[];
typedef struct { s32 f0; s32 f4; s32 f8; u8 pad[0x15C]; u8 b168; u8 b169; u8 pad2[2]; s32 f16C; } G_001A5CD0_0061BFF8;
extern G_001A5CD0_0061BFF8 D_001A5E50[];
void func_L39_0061E448(void);
void func_L39_0061AA38(s32, s32);
void func_L39_0065F168(s32);
void func_L39_0066B5A8(void);
void func_L39_00619B58(void);
s32 func_L01_00433038(void *, void *, s32);
void func_L39_00670060(void);
void func_L39_00672470_00619880(void);
s32 func_L39_0054BE68(s32, s32, s32, u8 *);
extern s32 (*D_L39_00240770)(s32, s32, s32, u8 *);
__asm__(".extern D_L39_002412A0, 16");
__asm__(".extern D_L39_00240770, 16");
extern s32 *D_L39_002412A0;

void func_L39_00619880(void) {
    s32 i;
    s32 j;
    func_L39_0061E448();
    func_L39_0061AA38(D_001A5E50->f8, D_001A5E50->f16C);
    for (i = 0; i < *D_L39_002412A0; i++) {
        func_L39_0065F168(i);
    }
    for (j = 7; j >= 0; j--) {
        D_001A5990[0xA4 + j] = 0;
    }
    func_L39_0066B5A8();
    func_L39_00619B58();
    func_L01_00433038(0, func_L39_00672470_00619880, 0);
    D_001A5E50->b169 = 0;
    func_L39_00670060();
    D_L39_00240770 = func_L39_0054BE68;
}
/* localdecomp:end func_L39_00619880 */
