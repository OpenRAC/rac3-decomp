/* PAL port of func_L01_00303E30 (from the NTSC-U draft of func_L01_00303C18): 13 words differ with the file's own flags
 * (src/levels/shared/L01_00302118.c). Everything else matches, including the vu0.h helpers and the constants.
 * What differs: retail computes the table address (`lui; addiu`) in the prologue into a register of its own and
 * does `mult $ac3, idx, 0x460; addu $s0, product, base`; ours builds the address into $s0 after the mult.
 * Tried without effect: base pointer local, index local, pointer arithmetic on a u8 table, scalar extern.
 * The three stores of the 15.0f/5.0f blocks match only in the order 0x18, 0x14, 0x10 (cross-jumped tails).
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00303E30 */
typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x50 - 0x1C];
    u8 *f50;
    u8 pad54[0x190 - 0x54];
    vu0_v4 position;
    u8 pad1A0[8];
    f32 f1A8;
    u8 pad1AC[0x240 - 0x1AC];
    u8 *f240;
    u8 pad244[0x260 - 0x244];
    f32 f260;
    u8 pad264[0x460 - 0x264];
} S_00303E30;
extern S_00303E30 D_L01_001E2A40[];
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DBA0(f32, f32);

void func_L01_00303E30(u8 *m) {
    vu0_v4 d, p;
    S_00303E30 *s = &D_L01_001E2A40[m[0xBC]];
    f32 t;
    if (s->f50) {
        *(vu0_q *)(m + 0x10) = *(vu0_q *)(s->f50 + 0x30);
        vec_sub_ba(&d, m + 0x10, &s->position);
        t = func_0038CE68(&d, s->f240 + 0xE0);
        func_0038CE20(&p, s->f240 + 0xE0, t);
        vec_sub_ab(&d, &d, &p);
        if (fabs_asm(t) < 2.5f) {
            if (func_0038CEA8(&d) < 0.1f || func_0038DBA0(s->f1A8, s->f18) < 2.3561945f || s->f260 < 0.0020000001f) {
                *(f32 *)(m + 0x18) = 15.0f;
                *(f32 *)(m + 0x14) = 15.0f;
                *(f32 *)(m + 0x10) = 15.0f;
            } else {
                t = func_0038CE68(m + 0x10, s->f240 + 0xE0);
                func_0038CE20(&p, s->f240 + 0xE0, t);
                vec_sub_ba(&d, m + 0x10, &p);
                t = func_0038CE68(&s->position, s->f240 + 0xE0);
                func_0038CE20(&p, s->f240 + 0xE0, t);
                vec_add_ab(m + 0x10, &d, &p);
            }
        }
    } else {
        *(f32 *)(m + 0x18) = 5.0f;
        *(f32 *)(m + 0x14) = 5.0f;
        *(f32 *)(m + 0x10) = 5.0f;
    }
}
/* localdecomp:end func_L01_00303E30 */
