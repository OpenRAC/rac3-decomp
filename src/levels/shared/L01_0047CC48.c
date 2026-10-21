#include "common.h"

/* localdecomp:start func_L01_0047CC48 */
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern s32 D_L01_001D81F4;
extern void func_L01_0047D210(void);
extern void func_003B3230();

extern void func_0039BD08();
void func_L01_0047CC48(void) {
    switch (D_L01_001D81F4) {
    case 0:
        func_0039BD08(func_003B3230, 0, 0);
    case 1:
        func_003A0EC0(4, 1, 1, 0, 0);
        D_L01_001D81F4++;
        break;
    case 2:
        func_L01_0047D210();
        break;
    }
}
/* localdecomp:end func_L01_0047CC48 */

/* localdecomp:start func_L01_0047CCD8 */
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern s32 D_L01_001D81F4;
extern void func_L01_0047D210(void);
extern void func_003B3230();

extern void func_0039BD90();
void func_L01_0047CCD8(void) {
    switch (D_L01_001D81F4) {
    case 0:
        func_0039BD90(func_003B3230, 0, 0);
    case 1:
        func_003A0EC0(4, 1, 1, 0, 0);
        D_L01_001D81F4++;
        break;
    case 2:
        func_L01_0047D210();
        break;
    }
}
/* localdecomp:end func_L01_0047CCD8 */
