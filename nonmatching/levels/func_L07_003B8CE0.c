/* PAL near miss (Claude wave S/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 added to the file line" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact with vec_sub_ab/vec_add_ba (vu0.h) only when -mvu0-use-vf0-vf2 is added to L07_003B7408.c line (file has @ps2as, no vu0 flag); without it the "j" class fails to compile. C in near/
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003B8CE0 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L07_003B8690(void *, s32);

void func_L07_003B8CE0(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);

    s[0x299] = 1;
    vec_sub_ab(s + 0x270, self + 0x10, *(u8 **)(s + 0x190) + 0x10);
    *(s32 *)(s + 0x278) = 0;
    func_0038CF68(s + 0x270, s + 0x270, 20.0f);
    vec_add_ba(s + 0x270, *(u8 **)(s + 0x190) + 0x10, s + 0x270);
    s[0x298] = 1;
    *(s32 *)(s + 0x290) = 0;
    s[0x297] = 5;
    func_L07_003B8690(self, 10);
    self[0xBC] = 0;
}
/* localdecomp:end func_L07_003B8CE0 */
