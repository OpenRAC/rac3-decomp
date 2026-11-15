#include "common.h"

INCLUDE_ASM("asm/levels", func_L16_003DD528);

/* localdecomp:start func_L16_003DD6E8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) V_003DD6E8;

extern s32 func_L01_004561B8(void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L16_003DD860(void *, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L16_003E8DC0(void *, void *, void *, s32, f32, f32, f32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern f32 D_L16_001DF298;
__asm__(".extern D_L16_001DF298, 4");
extern f32 D_L16_001DF29C;
__asm__(".extern D_L16_001DF29C, 4");
extern f32 D_L16_001DF2A0;
__asm__(".extern D_L16_001DF2A0, 4");
extern f32 D_L16_001DF2A4;
__asm__(".extern D_L16_001DF2A4, 4");
extern f32 D_L16_001DF2A8;
__asm__(".extern D_L16_001DF2A8, 4");
extern f32 D_L16_001DF2AC;
__asm__(".extern D_L16_001DF2AC, 4");

void func_L16_003DD6E8(u8 *self) {
    s32 *v = *(s32 **)(self + 0x68);

    switch (self[0x20]) {
    case 0:
        if (func_L01_004561B8(self) != 0) {
            *v = 0;
        }
        if (func_L01_00447490(self, -1, 0) != 0) {
            s32 n;

            func_L16_003DD860(self, 1.3f, 1.0f);
            {
                V_003DD6E8 dir = { D_L16_001DF298, D_L16_001DF29C, D_L16_001DF2A0 };
                V_003DD6E8 pos = { D_L16_001DF2A4, D_L16_001DF2A8, D_L16_001DF2AC };

                func_0038CF68(&dir, &dir, 1.0f);
                switch (D_001D545C) {
                case 0x10:
                    n = 0x6C;
                    break;
                case 0x401:
                    n = 0x6E;
                    break;
                }
                func_L16_003E8DC0(self + 0x10, &pos, &dir, n, 5.0f, 0.0f, 35.0f, 0x8EF3F4);
            }
            func_L01_004450F0(self, 1, -1);
        }
        break;
    case 1:
        func_003C2880(self);
        break;
    }
}
/* localdecomp:end func_L16_003DD6E8 */

INCLUDE_ASM("asm/levels", func_L16_003DD860);
