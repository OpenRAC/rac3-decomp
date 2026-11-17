/* NTSC-U draft (Codex wave 4): C of func_L01_00301E88, the NTSC-U twin of func_L01_00302048, with NTSC-U names and addresses.
 * near miss: 9 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_00301E88").
 * Worker's note: Sister build/codex/pool/X4/us_func_L01_00301E88_rac2.c; best log build/codex/w171/func_L01_00301E88-01.log; 9 diff: only initial table address register allocation/scheduling; assigned -mno-split-addresses emits adjacent lui/addiu while retail splits them; ...
 */
#include "common.h"

/* localdecomp:start func_L01_00301E88 */
extern char D_L01_0026ED10[];
extern char D_L01_0026ED90[];
extern float D_001DC4A0_sda __attribute__((sda));
extern float D_001DC4C8_sda __attribute__((sda));
void func_L01_00301E88(void)
{
    extern void func_00389158(void *, void *, void *, float);
    extern void func_00388830(void *, void *, float);
    int i;

    for (i = 0; i < 8; i++) {
        char *entry = D_L01_0026ED10 + i * 16;
        func_00389158(entry, entry, D_L01_0026ED90 + i * 16, D_001DC4A0_sda);
        func_00388830(entry, entry, D_001DC4C8_sda);
    }
}
/* localdecomp:end func_L01_00301E88 */
