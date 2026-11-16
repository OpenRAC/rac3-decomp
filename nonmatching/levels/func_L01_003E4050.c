/* PAL near miss (Codex wave 8): near miss: 47 words differ with the file's flags.
 * Worker's note: 45 diff: 4050-05.log with injected divs 2; opaque operand/clobber-correct VU blocks cannot reproduce retail interleaving under fixed no-vf2 flags; first jal delay nop missing and VU scheduling differs. Draft out/func_L01_003E4050.near.c; no all-place proof.
 */
#include "common.h"
/* localdecomp:start func_L01_003E4050 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_003E4050;
extern u8 *D_L01_001E0124;
extern Vec_003E4050 D_L01_001EAA30[];
s32 func_L01_003E4050(q128 *position, f32 extra) {
    extern s32 func_L01_003F7350(q128 *, f32);
    extern f32 func_0038CEA8(f32 *);
    extern void func_0038CE20(void *, void *, f32);
    struct { q128 copy; Vec_003E4050 delta; } local;
    u8 *hit;
    u8 *entry;
    f32 radius, inverse;
    local.copy = *position;
    hit = (u8 *)func_L01_003F7350(&local.copy, extra);
    if (hit) {
    entry = D_L01_001E0124 + (*(s32 *)(hit + 0x14) << 7);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(local.delta) : "m"(*(Vec_003E4050 *)position), "m"(*(Vec_003E4050 *)(entry+0x30)) : "vf1", "vf2");
    radius = func_0038CEA8((f32 *)entry);
    inverse = 1.0f / func_0038CEA8((f32 *)&local.delta);
    func_0038CE20(D_L01_001EAA30, &local.delta, (radius + extra) * inverse);
    func_0038CE20(D_L01_001EAA30 - 1, &local.delta, radius * inverse);
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(D_L01_001EAA30[0]) : "m"(*(Vec_003E4050 *)(entry+0x30)) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "+m"(D_L01_001EAA30[-1]) : "m"(*(Vec_003E4050 *)(entry+0x30)) : "vf1", "vf2");
    return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003E4050 */
