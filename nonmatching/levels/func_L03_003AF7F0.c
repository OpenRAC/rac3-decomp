/* near miss (level 3, Starship Phoenix): 6 differences: everything matches except the order of the float argument loads; retail loads $f13 and $f14 (lui $at form) first and puts the $gp load of $f12 in the jal delay slot, the C loads the $gp one first; tried locals, pointer alias, callee return types, @ps2as */
#include "common.h"

/* localdecomp:start func_L03_003AF7F0 */
extern char *D_001DF99C;
__asm__(".extern D_001DF99C, 16");
extern f32 D_001DE820_sda;
__asm__(".extern D_001DE820_sda, 4");
extern f32 D_001DE824;
__asm__(".extern D_001DE824, 16");
extern f32 D_001DE828;
__asm__(".extern D_001DE828, 16");
void func_L01_00450DE8(void *q, void *p, f32 a, f32 b, f32 c);
void func_L03_003AF7F0(void *self) {
    char *s = (char *)self;
    char *t = *(char **)(s + 0x68);
    char *q = D_001DF99C + (*(int *)(t + 0x15C) << 8);
    *(f32 *)(s + 0xF8) = *(f32 *)(q + 0xF8);
    func_L01_00450DE8(q, s + 0x10, D_001DE820_sda, D_001DE824, D_001DE828);
}
/* localdecomp:end func_L03_003AF7F0 */
