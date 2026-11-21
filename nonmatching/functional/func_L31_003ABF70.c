/* functional: high. EXACT (MATCH) at 3 places with the vu0 flag line */
#include "vu0.h"
typedef struct {
    u8 pad00[0x18];
    s32 target;
    u8 pad1C[4];
    vu0_v4 pos;
} Glob_003ABF70;
extern Glob_003ABF70 D_L31_001E9180;
extern s32 func_L30_0034D8D8(void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L31_003AC238(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);

/* Falling/moving prop: advances its height by its speed, drops itself when it leaves the world,
 * turns toward its heading and, on hitting the ground/hit target, snaps to the hit point and
 * switches state. */
void func_L31_003ABF70(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    vu0_v4 pos;
    vu0_v4 d;

    func_0038CAD0(v + 0x1C);
    *(f32 *)(v + 8) = *(f32 *)(v + 8) + *(f32 *)(v + 0x18);
    vec_add_ba(&pos, obj + 0x10, v);
    if (func_L30_0034D8D8(&pos, 1.5f) == 0) {
        func_003C2880(obj);
        return;
    }
    *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), *(f32 *)(v + 0x28));
    if (func_L01_003FB640(&pos, *(f32 *)(v + 0x24), 0x10, obj) != 0 && *(s32 *)(v + 0x1C) <= 0) {
        vec_sub_ab(&d, &D_L31_001E9180.pos, obj + 0x10);
        if (0.0f < func_0038CE68(&d, v)) {
            if (D_L31_001E9180.target == 0 || D_L31_001E9180.target != *(s32 *)(v + 0x20)) {
                func_L31_003AC238(obj, &D_L31_001E9180.pos);
                *(vu0_q *)(obj + 0x10) = *(vu0_q *)&D_L31_001E9180.pos;
                func_L01_004450F0(obj, 1, -1);
                return;
            }
        }
    }
    *(vu0_q *)(obj + 0x10) = *(vu0_q *)&pos;
}
