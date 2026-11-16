/* PAL near miss (Codex wave 6): near miss: 68 words differ with the file's flags.
 * Worker's note: 68 diff in w265/func_L01_0044E850.02.log. Existing whole-file func_003C2C98(s32) prototype omits retail a1=p at both calls; retained exact file type, no incompatible cast. One missing instruction shifts tail; scale store ordering also differs. Draft ...
 */
#include "common.h"
/* localdecomp:start func_L01_0044E850 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x20];
    u8 state;
} Owner_0044E850;
typedef struct {
    u8 pad0;
    u8 active;
    u8 pad2[0xE];
    vu0_v4 transform;
    vu0_v4 scale;
    u8 pad30[0x10];
    vu0_v4 rotation;
    vu0_v4 speed;
    vu0_v4 target;
    f32 factor;
    u8 pad74[4];
    Owner_0044E850 *owner;
} State_0044E850;
void func_L01_0044E850(Owner_0044E850 *owner, State_0044E850 *p, void *arg, f32 a, f32 b) {
    extern void func_003C2C98(s32);
    extern void func_L01_00448728(f32 *, f32 *, f32, f32, f32, f32, s32);
    extern void func_L01_0043A430(void *, void *, void *);
    extern void func_003C3FC0(void *, void *);
    if (p->owner != 0) {
        if (p->owner == owner) goto test;
        if (p->active != 0 && p->owner->state < 127) {
            func_003C2C98((s32)p->owner);
        }
        p->active = 0;
    }
    p->owner = owner;
test:
    if (p->target.x == 0.0f && p->target.y == 0.0f &&
        p->target.z == 0.0f && p->factor == 1.0f &&
        fabs_asm(p->rotation.x) < 0.005f &&
        fabs_asm(p->rotation.y) < 0.005f &&
        fabs_asm(p->rotation.z) < 0.005f) {
        if (p->active != 0) func_003C2C98((s32)owner);
    } else {
        func_L01_00448728(&p->rotation.x, &p->speed.x, p->target.x, a, b, 0.0f, 0);
        func_L01_00448728(&p->rotation.y, &p->speed.y, p->target.y, a, b, 0.0f, 0);
        func_L01_00448728(&p->rotation.z, &p->speed.z, p->target.z, a, b, 0.0f, 0);
        if (p->active == 0) func_L01_0043A430(owner, arg, p);
        func_003C3FC0(&p->transform, &p->rotation);
        p->scale.x = p->scale.y = p->scale.z = p->factor;
        qzero(&p->target);
        p->factor = 1.0f;
    }
}
/* localdecomp:end func_L01_0044E850 */
