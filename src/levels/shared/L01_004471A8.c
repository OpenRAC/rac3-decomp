#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    union {
        s128 q;
        f32 f[4];
    } pos;
    s128 col;
} E_001E8D00;

/* localdecomp:start func_L01_004471A8 */


extern s32 D_L01_001DF9E0;
extern E_001E8D00 D_L01_001E8C80[];
extern s128 D_L01_001EAA40[];
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_003D5630(void);

void func_L01_004471A8(u8 *a0, f32 scale)
{
    f32 h;
    f32 t;
    E_001E8D00 *e;
    s32 n;

    if (a0[49] == 0) {
        return;
    }
    if (D_L01_001DF9E0 >= 32) {
        return;
    }
    D_L01_001E8C80[D_L01_001DF9E0].pos.q = *(s128 *)(a0 + 16);
    h = func_003C3D30(a0 + 16, 0, 0, 0.5f);
    if (func_003D5630() == 0) {
        return;
    }
    n = D_L01_001DF9E0;
    e = &D_L01_001E8C80[n];
    e->pos.f[2] = h + 0.025f;
    D_L01_001E8C80[n].col = D_L01_001EAA40[0];
    t = (8.0f - __builtin_fabsf(*(f32 *)(a0 + 24) - h)) * 0.125f;
    if (t < 0.25f) {
        t = 0.25f;
    }
    D_L01_001DF9E0 = n + 1;
    e->pos.f[3] = scale * t;
}
/* localdecomp:end func_L01_004471A8 */

INCLUDE_ASM("asm/levels", func_L01_004472C0);

/* localdecomp:start func_L01_00447450 */
extern void func_L01_004472C0_00447450();
 
void func_L01_00447450(void) {
    func_L01_004472C0_00447450();
}
/* localdecomp:end func_L01_00447450 */

/* localdecomp:start func_L01_00447470 */
extern void func_0038DBD8_00447470();
 
void func_L01_00447470(void) {
    func_0038DBD8_00447470();
}
/* localdecomp:end func_L01_00447470 */

INCLUDE_ASM("asm/levels", func_L01_00447490);

INCLUDE_ASM("asm/levels", func_L01_004474E8);

INCLUDE_ASM("asm/levels", func_L01_00447718);

INCLUDE_ASM("asm/levels", func_L01_00447878);

INCLUDE_ASM("asm/levels", func_L01_00447938);

LINKER_REMNANT("asm/levels", func_L01_00448060);

/* localdecomp:start func_L01_00448070 */
int func_L01_00448070(int a, int b, float t)
{
    return a + (int)((b - a) * t);
}
/* localdecomp:end func_L01_00448070 */
