#include "common.h"

/* NTSC-U counterpart of func_L39_00679DA0 (src/levels/shared/L39_00677F28.c) */
extern s32 func_L39_006773A8(void);

/* localdecomp:start func_L39_006773A8 */
typedef struct {
    u8 pad0[0x174];
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
    s32 f184;
    s32 f188;
} S_00679DA0;
extern void func_00139328(u8 *);
extern void func_0019D640(s32);
extern s32 func_L39_005B2498(s32);
extern u8 *D_L39_002417C0;
__asm__(".extern D_L39_002417C0, 16");
extern S_00679DA0 D_L39_001FC830;

s32 func_L39_006773A8(void) {
    u8 buf[8];
    u8 *p;
    func_00139328(buf);
    func_0019D640((buf[1] << 24 | buf[2] << 16 | buf[3] << 8 | buf[5]) ^ *(volatile s32 *)0x10000800 /* T0_COUNT */);
    p = D_L39_002417C0;
    switch (*(s32 *)(p + 0x180)) {
    case 0:
        if (*(s8 *)(p + 0x196) == 0) {
            if (D_L39_001FC830.f174 == 0) {
                D_L39_001FC830.f174 = 1;
                return 0x18DE;
            }
        } else {
            if (D_L39_001FC830.f178 == 0) {
                D_L39_001FC830.f178 = 1;
                return 0x18DF;
            }
        }
        break;
    case 1:
        if (*(s8 *)(p + 0x196) == 0) {
            if (D_L39_001FC830.f17C == 0) {
                D_L39_001FC830.f17C = 1;
                return 0x18E0;
            }
        } else {
            if (D_L39_001FC830.f180 == 0) {
                D_L39_001FC830.f180 = 1;
                return 0x18E1;
            }
        }
        break;
    case 2:
        if (*(s8 *)(p + 0x197) != 0) {
            if (D_L39_001FC830.f184 == 0) {
                D_L39_001FC830.f184 = 1;
                return 0x18E2;
            }
        } else {
            if (D_L39_001FC830.f188 == 0) {
                D_L39_001FC830.f188 = 1;
                return 0x18E3;
            }
        }
        break;
    }
    return func_L39_005B2498(0x24) + 0x18E4;
}
/* localdecomp:end func_L39_006773A8 */
