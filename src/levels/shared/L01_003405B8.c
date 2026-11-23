#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);

/* localdecomp:start func_L01_003405B8 */
typedef struct {
    u8 pad[0x50];
} S_003405B8;
extern S_003405B8 D_L01_00278E20[];
extern s16 D_L01_001E18D0_003405B8[] __attribute__((section(".sdata")));
extern s16 D_L01_001E18D8[] __attribute__((section(".sdata")));
extern f32 D_L01_001E18F8_003405B8[] __attribute__((section(".sdata")));
extern f32 D_L01_001DD140;
extern f32 D_L01_001DD144;
__asm__(".extern D_L01_001DD140, 4");
__asm__(".extern D_L01_001DD144, 4");
extern void func_L01_00340670(void *, s32, s32, s32, f32, f32, f32);

void func_L01_003405B8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_L01_001E18D0_003405B8[i] != 0) {
            s32 n = D_L01_001E18D8[i];
            n = n * D_L01_001E18F8_003405B8[0];
            func_L01_00340670(&D_L01_00278E20[i], n, n, 5, D_L01_001DD140, D_L01_001DD144, 0.2f);
        }
    }
}
/* localdecomp:end func_L01_003405B8 */
