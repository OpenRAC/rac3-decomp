#include "common.h"

/* localdecomp:start func_L03_003DA010 */
extern void func_L03_003DA058(s32 a0);
typedef struct { s32 w0; s32 w4; f32 f8; s32 wC; void *w10; } P_3D7F00;
typedef struct { u8 p0[0x3F0]; P_3D7F00 p; u8 pad[0x460 - 0x3F0 - 0x14]; } E_3D7F00;
extern E_3D7F00 D_L03_001E24C0[];

void func_L03_003DA010(s32 i) {
    E_3D7F00 *e = &D_L03_001E24C0[i];
    P_3D7F00 *p = &e->p;
    p->w4 = 0;
    e->p.w0 = 0;
    p->f8 = 10000.0f;
    p->wC = 0;
    p->w10 = ((void (*)(void))func_L03_003DA058);
}
/* localdecomp:end func_L03_003DA010 */

/* localdecomp:start func_L03_003DA058 */
extern E_3D7F00 D_L03_001E24C0[];
typedef struct {
    u8 pad0[1020];
    f32 f1020;
    u8 pad1[96];
} Ent1120;
extern void func_L01_003E8C70(f32 a, f32 b, s32 a0, s32 a1);
extern void func_L03_003DA0E0(void);
extern void func_L03_003E0F30(s32 a0, void (*cb)(void));
void func_L03_003DA058(s32 a0) {
    f32 v;
    v = (((Ent1120 *)&D_L03_001E24C0) + a0)->f1020;
    if (v != 0.0f) {
        func_L01_003E8C70(v * 0.35f + 0.0f, 0.005f, a0, 1);
        func_L03_003E0F30(a0, func_L03_003DA0E0);
    }
}
/* localdecomp:end func_L03_003DA058 */

INCLUDE_ASM("asm/levels", func_L03_003DA0E0);

INCLUDE_ASM("asm/levels", func_L03_003DA148);
