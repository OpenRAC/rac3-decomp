/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Compile blocked by existing callee signature void func_L01_003E8FE8(u8 *, f32): retail passes stack vector pointer in a1 (offset 0x10), no mtc1; existing func_L01_003E9218(u8 *, f32) also contradicts live pointer a1 at entry. Requires both signatures ...
 */
#include "common.h"
/* localdecomp:start func_L01_003E9218 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003E9218;
/* Retail passes the vector address in a1 to func_L01_003E8FE8.
 * Its existing (u8 *, f32) declaration needs correction before this can compile. */
void func_L01_003E9218(u8 *camera, Vec_003E9218 *position) {
    extern void func_L01_003E8FE8(u8 *, f32);
    Vec_003E9218 delta;
    u8 *follow=*(u8 **)(camera+0x70);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(*position), "m"(*(Vec_003E9218 *)(follow+0x60)) : "vf1", "vf2");
    func_L01_003E8FE8(camera,&delta);
}
/* localdecomp:end func_L01_003E9218 */
