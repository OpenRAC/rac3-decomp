#include "common.h"

/* Hand-written assembly (ASM_FUNC). The four large functions use the trapping `addi`/`add`/`sub`
 * for all their integer arithmetic, which the compiler never emits, and put VU0 instructions in
 * branch delay slots. func_L01_003FDCA0 has no stack frame: it saves $16-$18, $22 and $23 in
 * their own upper halves (`pcpyld`, restored with `pcpyud`). coll_sphere_camera_groups
 * (func_L01_003FE1D8) is a second entry to it: it loads another list into $24, has no `jr $ra`
 * and jumps to 0x003FDCA8, past the first entry's own two instructions. */

ASM_FUNC("asm/levels", func_L01_003FDCA0);

ASM_FUNC("asm/levels", func_L01_003FE1D8);

ASM_FUNC("asm/levels", func_L01_003FE1E8);

ASM_FUNC("asm/levels", func_L01_003FE378);

ASM_FUNC("asm/levels", func_L01_003FE540);
