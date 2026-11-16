/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact (func_0038D000(dst, D_001DC860_sda, obj+0xC0) with extern u8 D_001DC860_sda[8] + .extern hint 8 for the gp address; vec_add_ba(dst,dst,obj+0x10)) only with -mvu0-use-vf0-vf2, which the file line lacks
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0031D188 */
extern u8 D_001DC860_sda[8];
__asm__(".extern D_001DC860_sda, 8");
extern void func_0038D000(void *, void *, void *);

void func_L01_0031D188(u8 *obj, void *dst) {
    func_0038D000(dst, D_001DC860_sda, obj + 0xC0);
    vec_add_ba(dst, dst, obj + 0x10);
}
/* localdecomp:end func_L01_0031D188 */
