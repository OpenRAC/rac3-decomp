/* functional: high. Draft from PAL near miss, verified block by block against asm; byte diffs only (address folding of D_L01_002C5600+0x70, scheduling). */
typedef struct {
    f32 v[4];
    s32 w16;
    f32 f20;
    s32 w24;
    s32 w28;
    f32 f32_;
    s32 w36;
    f32 f40;
    f32 f44;
} S_0030CD20;
#include "vu0.h"
typedef struct {
    vu0_v4 a, b, start, end;
    f32 phase0[3], step0[3], size0[3];
    f32 phase1[3], step1[3], size1[3];
    s32 timer;
    u8 *owner, *target;
    s32 remaining, duration, done;
} Arc_0030CB20;
extern u8 *D_L01_001E1724;
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
void func_L01_0030CB20(u8 *obj) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern u8 *func_00382348(void *);
    extern void func_L01_00451290(void *, void *, s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CF68(S_0030CD20 *, S_0030CD20 *, f32);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_0030E630(void *, s32, s32);
    extern void func_L01_0031B090(void *, s32, void *);
    vu0_v4 delta;
    Query_003090E0 hit;
    u8 *vars=*(u8 **)(obj+0x68);
    Arc_0030CB20 *a;
    s32 i;
    for (i=0;i<12;i++) {
        a=(Arc_0030CB20 *)(i*160+(s32)D_L01_001E1724);
        if (a->owner != obj) continue;
        *(vu0_q *)&a->start=*(vu0_q *)(obj+0x10);
        if (a->remaining) {
            a->phase0[0]=func_0038DAB8(a->phase0[0],a->step0[0]*100.0f);
            a->phase0[1]=func_0038DAB8(a->phase0[1],a->step0[1]*100.0f);
            a->phase0[2]=func_0038DAB8(a->phase0[2],a->step0[2]*100.0f);
            a->phase1[0]=func_0038DAB8(a->phase1[0],a->step1[0]*100.0f);
            a->phase1[1]=func_0038DAB8(a->phase1[1],a->step1[1]*100.0f);
            a->phase1[2]=func_0038DAB8(a->phase1[2],a->step1[2]*100.0f);
        } else {
            a->phase0[0]=func_0038DAB8(a->phase0[0],a->step0[0]);
            a->phase0[1]=func_0038DAB8(a->phase0[1],a->step0[1]);
            a->phase0[2]=func_0038DAB8(a->phase0[2],a->step0[2]);
            a->phase1[0]=func_0038DAB8(a->phase1[0],a->step1[0]);
            a->phase1[1]=func_0038DAB8(a->phase1[1],a->step1[1]);
            a->phase1[2]=func_0038DAB8(a->phase1[2],a->step1[2]);
        }
        a->a.x=func_0038D098(a->phase0[0])*a->size0[0];
        a->a.y=func_0038D0B0(a->phase0[1])*a->size0[1];
        a->a.z=-func_0038D0B0(a->phase0[2])*a->size0[2];
        a->b.x=func_0038D098(a->phase1[0])*a->size1[0];
        a->b.y=func_0038D0B0(a->phase1[1])*a->size1[1];
        a->b.z=-func_0038D0B0(a->phase1[2])*a->size1[2];
        if (a->target) {
            u8 *state=func_00382348(a->target);
            if (state) {
                func_L01_00451290(a->target,&delta,1);
                func_0038CE20((f32 *)&delta,(f32 *)&delta,*(f32 *)(state+0x10));
                vec_add_ab(&a->end,&delta,a->target+0x10);
            } else {
                *(vu0_q *)&a->end=*(vu0_q *)(a->target+0x10);
            }
            func_0038CDF8(&a->end,&a->start,&a->end,1.0f-(f32)a->remaining/(f32)a->duration);
        }
        if (func_0038CAD0(&a->remaining)) {
            if (*(s32 *)(a->target+0x98) && !a->done) {
                vec_sub_ba(&delta,&a->end,&a->start);
                func_0038CF68((S_0030CD20 *)&delta,(S_0030CD20 *)&delta,0.040000003f);
                func_L01_00446760(&hit,obj,0x410000,&delta,*(f32 *)(D_L01_002C5600+D_001425C0[0x10]*240+0x70));
                hit.b18=1;
                hit.b19=3;
                hit.h1A=*(u16 *)(obj+0xAA);
                func_L01_00446978(a->target,&hit);
                a->done=1;
                func_L01_0030E630(&a->end,10,1);
                func_L01_0031B090(a->target,0x10,*(void **)(obj+0xB8));
            }
            if (func_0038CAD0(&a->timer)) {
                a->owner=0;
                --*(s32 *)(vars+0x1C);
            }
        }
    }
}
