/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: MATCH only with -mvu0-use-vf0-vf2 (vec_add_ab): the file's later extern is (Entry_3E6C58 *, q128_3E48D8 *, f32, s32): the C uses q128 * for the second parameter (same TI type; checked that the later redeclaration does not conflict) and the f12 pass-through ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003E4828 */
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_003E4198(u8 *, void *, s32);

void func_L01_003E4828(Entry_3E6C58 *entry, q128 *target, f32 height, s32 from_ground) {
    u8 *e = (u8 *)entry;
    u8 *p = e + 0x60;
    vu0_q v[2];
    func_0038CE20(&v[0], e + 0x80, height);
    if (from_ground != 0) {
        func_L01_003E4198(e, &v[1], 1);
    } else {
        func_L01_003E4028(*(u8 **)(e + 0x50), &v[1]);
    }
    vec_add_ab(&v[0], &v[0], &v[1]);
    func_0038CE20(target, p + 0x30, func_0038CE68(p + 0x30, &v[0]));
}
/* localdecomp:end func_L01_003E4828 */
