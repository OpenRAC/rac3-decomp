#include "common.h"

/* NTSC-U counterpart of func_L39_00560A00 (src/levels/shared/L39_005611A0.c) */
/* localdecomp:start func_L39_00560A00 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00560A00;
typedef struct { u8 pad0[0x24]; f32 f24; } P_00560A00;
typedef struct { u8 pad0[0x24]; P_00560A00 *x24; u8 pad28[4]; f32 f2C; } O_00560A00;

extern s32 D_L39_002412AC;
extern f32 D_001DFCAC_sda;
__asm__(".extern D_001DFCAC_sda, 4");
extern f32 D_001DFCB0_sda;
__asm__(".extern D_001DFCB0_sda, 4");
extern s32 D_001DFCB4_sda;
__asm__(".extern D_001DFCB4_sda, 4");
extern s32 D_001DFCB8_sda;
__asm__(".extern D_001DFCB8_sda, 4");
extern void func_003886E8(void *, void *, f32);
extern s32 func_003894A0(f32, s32, s32);
extern s32 func_L39_005CB8E0(void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L39_00560A00(O_00560A00 *o) {
    V_00560A00 v0;
    s32 i;
    s32 idx;
    s32 c;
    f32 f;

    func_003886E8(&v0, o, 0.0009765625f);
    for (i = 0; i < 4; i++) {
        idx = func_003894A0(fabs_asm(0.5f - (f32)(0xFF - ((D_L39_002412AC + i * 0x14) & 0xFF)) / 255.0f), 0x200AD7EC, 0x5AE9F8);
        f = (D_001DFCAC_sda + (f32)i * D_001DFCB0_sda) * (o->f2C / o->x24->f24);
        c = *(u8 *)&D_L39_002412AC;
        if ((i & 2) != 0) {
            c = c * 2;
        }
        if ((i & 1) != 0) {
            c = 0xFF - c;
        }
        func_L39_005CB8E0(&v0, idx, (u8)c, D_001DFCB8_sda, D_001DFCB4_sda, 2, 0, 0, f);
    }
}
/* localdecomp:end func_L39_00560A00 */
