#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L27_003A1250);

INCLUDE_ASM("asm/levels", func_L27_003A17B0);

INCLUDE_ASM("asm/levels", func_L27_003A1B30);

INCLUDE_ASM("asm/levels", func_L27_003A2548);

INCLUDE_ASM("asm/levels", func_L27_003A2B98);

/* localdecomp:start func_L27_003A2E08 */
typedef struct { u8 pad[0x44]; s32 f44; s32 f48; s32 f4C; } S_2E08_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_2E08_D *f68; } S_2E08_O;
typedef struct { u8 pad[0x30]; vu0_v4 v30; u8 p40[0x30]; f32 f70; f32 f74; f32 f78; u8 p7C[4]; } S_2E08_E;
extern void func_L01_003EB5E0(s32, s32);
extern void func_L01_004ED658(s32);
extern void func_L01_004F5DC8(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_00504E38(s32);
extern void func_L01_00511A40(void *, s32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s16 D_001A7464[];
extern S_2E08_E *D_L27_001DEE00;

void func_L27_003A2E08(S_2E08_O *self) {
    S_2E08_D *d = self->f68;
    vu0_v4 v;
    func_L01_003EB5E0(0, 2);
    D_001A7464[0] = 1;
    func_L01_004ED658(0);
    func_L01_004F5DC8();
    if (self->b20 == 5) {
        func_L01_004F50C8(&D_L27_001DEE00[d->f44].v30, &D_L27_001DEE00[d->f44].f70, -1, 1);
        func_L01_00504E38(0);
    } else if (self->b20 == 7) {
        func_L01_004F50C8(&D_L27_001DEE00[d->f4C].v30, &D_L27_001DEE00[d->f4C].f70, -1, 1);
        v.x = func_0038D098(D_L27_001DEE00[d->f4C].f78);
        v.y = func_0038D0B0(D_L27_001DEE00[d->f4C].f78);
        v.z = 0;
        vec_add_ab(&v, &v, &D_L27_001DEE00[d->f4C].v30);
        func_L01_00511A40(&v, 1, D_L27_001DEE00[d->f4C].f78);
    }
}
/* localdecomp:end func_L27_003A2E08 */

/* localdecomp:start func_L27_003A2F58 */
typedef struct { u8 p0[0x4A0]; s32 f4A0; } S_2F58_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_2F58_D *f68; } S_2F58_E;
typedef struct { u8 p0[0x98]; s32 f98; s32 f9C; u8 pA0[0x24]; s32 fC4; s32 fC8; s32 fCC; s32 fD0; } S_2F58_P;
typedef struct { u8 p0[0x68]; S_2F58_P *f68; u8 p6C[0x29]; u8 b95; } S_2F58_O;
extern u8 *D_001DED1C_sda;
__asm__(".extern D_001DED1C_sda, 4");
extern u8 *D_L27_001DED1C_003A2F58;
__asm__(".extern D_L27_001DED1C_003A2F58, 16");
extern void func_L27_0039F718(void *, void *);

void func_L27_003A2F58(S_2F58_O *arg0) {
    S_2F58_P *p;
    s32 i;
    s32 j;
    p = arg0->f68;
    if (arg0->b95 == 0) return;
    i = p->fC4;
    if (i == -1 || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_L27_001DED1C_003A2F58 + (i << 8), D_L27_001DED1C_003A2F58 + (p->fC8 << 8));
    }
    i = p->fCC;
    if (i == -1 || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((i << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_L27_001DED1C_003A2F58 + (i << 8), D_L27_001DED1C_003A2F58 + (p->fD0 << 8));
    }
    j = p->f98;
    if (j == -1 || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->b20 == 0xFE || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->b20 == 0xFD || ((S_2F58_E *)((j << 8) + (s32)D_001DED1C_sda))->f68->f4A0 <= 0) {
        func_L27_0039F718(D_001DED1C_sda + (j << 8), D_001DED1C_sda + (p->f9C << 8));
    }
}
/* localdecomp:end func_L27_003A2F58 */

INCLUDE_ASM("asm/levels", func_L27_003A3098);

INCLUDE_ASM("asm/levels", func_L27_003A3310);

INCLUDE_ASM("asm/levels", func_L27_003A3498);
