#include "common.h"

/* NTSC-U counterpart of func_L01_003C76A0 (src/levels/shared/L01_003C7560.c): 0.02 -> 0.0166667 */
/* localdecomp:start func_L01_003C5E20 */
typedef struct { char p0[0xC8]; f32 timer; char p1[0x5F0]; s32 index; char p2[0x10]; s32 a[8]; s32 b[8]; s32 c[4]; s32 d[8]; } State_003C76A0;
extern void func_L01_003C5670_003C5E20(void *, State_003C76A0 *);
extern s32 func_L01_003C4FE0_003C5E20(void *);
extern void func_L01_003C5F90_003C5E20(void *, State_003C76A0 *, s32, s32, s32);
extern void func_L01_00441FB8_003C5E20(void *, s32, s32);
extern void func_L01_003C3C68_003C5E20(void *, State_003C76A0 *);
extern void func_L01_003C3F30_003C5E20(void *, State_003C76A0 *, s32);
extern void func_L01_003C55F8_003C5E20(void *, State_003C76A0 *);
extern void func_L01_003C3A10_003C5E20(void *, State_003C76A0 *);
extern f32 D_L01_001DECC0_003C5E20;
__asm__(".extern D_L01_001DECC0_003C5E20, 4");

void func_L01_003C5E20(void *obj, State_003C76A0 *s, s32 enabled) {
    func_L01_003C5670_003C5E20(obj, s);
    if (enabled && s->d[s->index] != -1 && !func_L01_003C4FE0_003C5E20(obj)) {
        func_L01_003C5F90_003C5E20(obj, s, s->d[s->index], s->a[s->index], 1);
        s->timer = D_L01_001DECC0_003C5E20 * 0.0166666675f;
        if (s->c[s->index] != -1) {
            func_L01_00441FB8_003C5E20(obj, 1, -1);
        } else {
            func_L01_00441FB8_003C5E20(obj, 2, -1);
        }
        func_L01_003C3C68_003C5E20(obj, s);
    } else {
        s->timer = 0;
        func_L01_003C3F30_003C5E20(obj, s, s->a[s->index]);
        if (s->b[s->index]) {
            func_L01_00441FB8_003C5E20(obj, 5, -1);
        } else {
            func_L01_00441FB8_003C5E20(obj, 4, -1);
        }
        func_L01_003C55F8_003C5E20(obj, s);
        func_L01_003C3A10_003C5E20(obj, s);
    }
}
/* localdecomp:end func_L01_003C5E20 */
