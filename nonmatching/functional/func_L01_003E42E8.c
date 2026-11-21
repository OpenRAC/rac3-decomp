/* functional: high. 18 diff vs retail; stores, offsets and operand order checked vs asm */
/* localdecomp:start func_L01_003E42E8 */
#include "vu0.h"
extern Entry_3E6C58 D_L01_001E2A40[];
static __inline__ void sub_ba_003E42E8(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_ba_003E42E8(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L01_003E42E8(u8 *cam) {
    extern void func_L01_003E4198(Entry_3E6C58 *, void *, s32);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    vu0_v4 at, projected, offset;
    u8 *follow = *(u8 **)(cam + 0x70);
    Entry_3E6C58 *entry = &D_L01_001E2A40[*(s32 *)(cam + 0x94)];
    u8 *vertical = follow + 0x60;
    u8 *springs = follow + 0x180;
    vu0_v4 *up;
    vu0_v4 *forward = (vu0_v4 *)((u8 *)entry + 0x80);
    func_L01_003E4198(entry, &at, 0);
    up = (vu0_v4 *)((u8 *)entry + 0x90);
    {
        f32 dot = func_0038CE68((f32 *)&at, (f32 *)up);
        func_0038CE20(&projected, up, dot);
    }
    sub_ba_003E42E8((vu0_v4 *)(follow + 0x60), &at, &projected);
    *(vu0_q *)(follow + 0x70) = *(vu0_q *)&projected;
    add_ba_003E42E8((vu0_v4 *)(follow + 0x60), (vu0_v4 *)(follow + 0x60), (vu0_v4 *)(follow + 0x70));
    func_0038CE20(&offset, forward, *(f32 *)(vertical + 0xD0));
    add_ba_003E42E8((vu0_v4 *)(follow + 0xA0), &offset, (vu0_v4 *)(follow + 0x60));
    add_ba_003E42E8((vu0_v4 *)(follow + 0x110), &offset, (vu0_v4 *)(follow + 0x60));
    qzero(follow + 0x120);
    *(f32 *)(vertical + 0xE8) = 1.0f;
    vertical[0xE5] = 0;
    *(s16 *)(vertical + 0xE6) = 0;
    vertical[0xE4] = 0;
    qzero(follow + 0xF0);
    qzero(follow + 0x100);
    *(vu0_q *)(follow + 0xC0) = *(vu0_q *)(follow + 0x60);
    func_0038CE20(&offset, forward, *(f32 *)(springs + 0x30));
    add_ba_003E42E8((vu0_v4 *)(follow + 0xB0), &offset, (vu0_v4 *)(follow + 0x60));
}
/* localdecomp:end func_L01_003E42E8 */
