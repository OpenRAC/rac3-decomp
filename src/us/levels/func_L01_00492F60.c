#include "common.h"

/* NTSC-U counterpart of the PAL function at the same position (L01 shared) */
/* localdecomp:start func_L01_00492F60 */
extern u8 D_L01_001D91C0;
__asm__(".extern D_L01_001D91C0, 1");
extern s16 D_L01_001D91C2;
__asm__(".extern D_L01_001D91C2, 2");
extern f32 D_L01_001D91C4;
__asm__(".extern D_L01_001D91C4, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 *func_L01_00438468(s32, s32);
extern void func_L01_00493080(s32);
extern void func_003866E8(s32, s32, s32, s32);
extern void func_L01_0047ACC0(void);

void func_L01_00492F60(void) {
    s32 r;
    u8 *p;

    if (D_L01_001D91C0 == 1) {
        if (D_001D545C == 7) {
            p = func_L01_00438468(0x1AD1, 0xC);
            if (p != 0) {
                r = ((s32(*)(void)) * (void **)(p + 8))();
                if (r != -1) {
                    func_L01_00493080(r);
                } else {
                    D_L01_001D91C0 = 0;
                }
            }
        }
    } else if (D_L01_001D91C0 == 2) {
        func_003866E8(0, 0, 0, (s32)((f32)D_L01_001D91C2 / D_L01_001D91C4 * 255.0f));
    }
    func_L01_0047ACC0();
}
/* localdecomp:end func_L01_00492F60 */
