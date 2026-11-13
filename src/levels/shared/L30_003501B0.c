#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern void func_L01_004AA7E8(void *, s32);

/* localdecomp:start func_L30_003501B0 */
typedef struct { u8 pad[0x4]; s32 x4; f32 x8; f32 xC; u8 pad10[0x30 - 0x10]; u8 x30[1]; } V_3501B0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; u8 x20; u8 pad21[0x34 - 0x21]; u16 x34; u8 pad36[0x68 - 0x36]; V_3501B0 *x68; u8 pad6C[0x98 - 0x6C]; s32 x98; } O_3501B0;
typedef struct { u8 pad[0x20]; f32 x20; u8 pad24[4]; s32 x28; s32 x2C; } G_3501B0;
__asm__(".extern D_L30_001DD734, 4");
__asm__(".extern D_L30_001DD738, 4");
__asm__(".extern D_L30_001DD73C, 4");
__asm__(".extern D_L30_001DD740, 4");
__asm__(".extern D_L30_001DD754, 4");
__asm__(".extern D_L30_001DD758, 4");
extern f32 D_L30_001DD734;
extern f32 D_L30_001DD738;
extern f32 D_L30_001DD73C;
extern s32 D_L30_001DD740;
extern s32 D_L30_001DD754;
extern s32 D_L30_001DD758;
extern G_3501B0 D_L30_001E22C0;
extern void func_L30_003509A8(O_3501B0 *);
extern void func_L30_00350A30(O_3501B0 *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L30_00350970(u8 *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L30_0034CB68(u8 *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L30_00350690(O_3501B0 *);
extern s32 func_0038CAD0(void *);

void func_L30_003501B0(O_3501B0 *o) {
    V_3501B0 *v = o->x68;

    switch (o->x20) {
    case 0:
        func_L30_003509A8(o);
        func_L30_00350A30(o);
        if (func_L30_0034D8D8(o->x10, D_L30_001DD738) == 0) {
            func_L30_00350970((u8 *)o);
        }
        break;
    case 1:
        if (func_L01_004561B8(o) != 0) {
            o->x98 = 0;
            o->x34 = (o->x34 | 0x41) & ~0x1000;
            func_L01_004AA7E8(o, 1);
            v->x4 = D_L30_001DD740;
            func_L30_0034CB68((u8 *)o, v->x30, 0, -1, 0, 0, D_L30_001DD734, D_L30_001DD73C);
            D_L30_001E22C0.x20 = D_L30_001DD754;
            D_L30_001E22C0.x28 = D_L30_001DD758;
            D_L30_001E22C0.x2C = 0;
            v->x8 = v->xC = 0.0f;
        }
        func_L30_00350690(o);
        if (func_0038CAD0(&v->x4) != 0) {
            func_L30_00350970((u8 *)o);
        }
        break;
    }
}
/* localdecomp:end func_L30_003501B0 */

INCLUDE_ASM("asm/levels", func_L30_003502D0);

INCLUDE_ASM("asm/levels", func_L30_00350690);

/* localdecomp:start func_L30_00350970 */
extern void func_L30_0034DAC0(u8 *p);
extern void func_003C2880(u8 *p);

void func_L30_00350970(u8 *a) {
    func_L30_0034DAC0(*(u8 **)(a + 104) + 16);
    func_003C2880(a);
}
/* localdecomp:end func_L30_00350970 */
