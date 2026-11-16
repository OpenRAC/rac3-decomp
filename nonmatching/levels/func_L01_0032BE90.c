/* NTSC-U draft (Codex wave 4): C of func_L01_0032BA28, the NTSC-U twin of func_L01_0032BE90, with NTSC-U names and addresses.
 * near miss: 16 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_0032BA28").
 * Worker's note: sister build/codex/pool/X4/us_func_L01_0032BA28_rac2.c; best log build/codex/w163/func_L01_0032BA28-02.log; 16 positional diff; unsized global declaration fixes retail lw v1 instead of v0; remaining sequence differs only by the assigned default assembler ...
 */
#include "common.h"
/* localdecomp:start func_L01_0032BA28 */
extern int D_L01_001EAA9C;
__asm__(".extern D_L01_001EAA9C, 16");
void func_L01_0032BA28(void *object) {
    extern void func_003BDA38(void *, int, void *);
    extern int func_L01_003F9498(void *, int, void *, float);
    char local[16];
    func_003BDA38(object, 0, local);
    if (func_L01_003F9498(local, 2, object, 0.2f) && D_L01_001EAA9C > 0)
        *((unsigned char *)object + 0x20) = 8;
}
/* localdecomp:end func_L01_0032BA28 */
