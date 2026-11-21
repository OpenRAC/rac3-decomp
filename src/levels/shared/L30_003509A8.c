#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern void func_L01_004450F0(void *, s32, s32);
typedef struct { u8 pad[0x4]; s32 x4; f32 x8; f32 xC; u8 pad10[0x30 - 0x10]; u8 x30[1]; } V_3501B0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; u8 x20; u8 pad21[0x34 - 0x21]; u16 x34; u8 pad36[0x68 - 0x36]; V_3501B0 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_3501B0;
extern void func_L30_003509A8(O_3501B0 *);

/* localdecomp:start func_L30_003509A8 */
#include "vu0.h"
extern s32 func_L01_003FB640(f32 *, s32, u8 *, f32);
__asm__(".extern D_L30_001DD730, 4");
extern f32 D_L30_001DD730;
extern s32 D_L30_001E9018 __attribute__((section(".data")));
typedef struct { u8 pad0[0x1B24]; s32 x1B24; u8 pad1B28[0x25C0 - 0x1B28]; s32 x25C0; } D_1A4BE0_T;
extern D_1A4BE0_T D_001A4BE0;
void func_L30_003509A8(O_3501B0 *self) {
    vec_add_ab(self->x10, self->x10, self->x68->x30);
    if (func_L01_003FB640((f32 *)self->x10, 0x10, (u8 *)self, D_L30_001DD730) != 0) {
        s32 v = D_L30_001E9018;
        if (v == 0 || (v != D_001A4BE0.x25C0 && v != D_001A4BE0.x1B24)) {
            func_L01_004450F0(self, 1, -1);
        }
    }
}
/* localdecomp:end func_L30_003509A8 */
