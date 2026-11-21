/* functional: high. Codex near miss: scheduling and prologue order only; pointer loop uses sltu vs retail slt on the same RAM addresses. Fills the first free 0x50-byte row of the table at D_L01_002A3A40. */
#include "common.h"
/* localdecomp:start func_L01_003DF7A8 */
extern vu0_v4 D_L01_001E29C0;
void func_L01_003DF7A8(u8 *owner, void *origin, s32 mode, s32 a, s32 b, s32 c, s32 d, f32 scale, f32 e, f32 f, f32 phase) {
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    vu0_v4 view;
    u8 *p;
    Row_003DF620 *r;
    for (p=D_L01_002A3A40; p<D_L01_002A3A40+0x780; p+=0x50) {
        r=(Row_003DF620 *)(p+0x10);
        if (!r->owner) {
            r->owner=owner;
            r->scale=scale;
            *(s32 *)r->p2C=mode;
            r->a=a; r->b=b; r->c=c; r->d=d;
            r->e=e; r->f=f; r->phase=phase;
            func_00382580(p,1.0f,1.0f);
            vec_sub_ab(&view,&D_L01_001E29C0,origin);
            func_0038CF68(&view,&view,1.0f);
            func_0038CE90(r,p,&view);
            func_0038CF68(r,r,phase);
            break;
        }
    }
}
/* localdecomp:end func_L01_003DF7A8 */
