#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034B580 */
typedef struct {
    u8 pad[0xC0];
    s32 start;
    s32 count;
    s32 cur;
    s32 prev;
    s32 step;
} Vars_0034B580;

typedef struct {
    u8 pad[0x68];
    Vars_0034B580 *vars;
} Moby_0034B580;

extern s32 D_L31_001DD21C;
__asm__(".extern D_L31_001DD21C, 4");
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L31_0034CD18(Moby_0034B580 *);

void func_L31_0034B580(Moby_0034B580 *m) {
    Vars_0034B580 *v = m->vars;

    v->prev = v->cur;
    if (v->cur >= v->start) {
        if (v->step == D_L31_001DD21C - 1) {
            v->cur = v->start - 1;
            func_L01_004450F0(m, 3, -1);
        } else {
            v->cur = func_00382498(0, v->start - 2);
            func_L01_004450F0(m, 2, -1);
        }
    } else {
        if (v->step == D_L31_001DD21C - 1) {
            v->cur = v->start + v->count - 1;
            func_L01_004450F0(m, 3, -1);
        } else {
            v->cur = func_00382498(v->start, v->start + v->count - 2);
            func_L01_004450F0(m, 2, -1);
        }
    }
    v->step = (v->step + 1) % D_L31_001DD21C;
    func_L31_0034CD18(m);
}
/* localdecomp:end func_L31_0034B580 */
