#include "common.h"

/* localdecomp:start func_L39_006B4A78 */
extern s32 D_001A4560[];
extern s32 D_001DDA04_sda;
extern s32 D_001DDA08_sda;
extern s32 D_001DDA34_sda;
extern u8 D_L39_0037C948[];
extern void func_L39_006B4298(void);
extern void func_L39_006B42E0(void *);
extern void func_L39_006B6010(void *, s32);

void func_L39_006B4A78(void *object) {
    D_001DDA34_sda = 3;
    if (D_001A4560[2] == 2) {
        if (D_001A4560[0x5B] == 0) {
            func_L39_006B4298();
            if (D_001DDA08_sda != 0) {
                func_L39_006B42E0(D_L39_0037C948 + D_001DDA04_sda * 0x1F0);
                D_001DDA08_sda = 0;
            }
            func_L39_006B6010(object, 0);
            *(u8 *)((u8 *)object + 0x2BC) = 1;
        }
    }
}
/* localdecomp:end func_L39_006B4A78 */
