/* near miss (level 3, Starship Phoenix): 2 differences: retail has `sd $s0; move $s0,$a0; sd $ra` in the prologue, the C gives `sd $s0; sd $ra; move $s0,$a0`; about 12 wordings tried (parameter types, local copy, callee return types, hints, @ps2as) */
#include "common.h"

/* localdecomp:start func_L03_0032EBF0 */
extern int D_001D7C20_sda;
__asm__(".extern D_001D7C20_sda, 4");
void func_L03_0032EC38(void);
void func_L03_0032ED88(void *a);
void func_L03_0032EDE0(void *a);
void func_L03_0032EF78(void *a);

void func_L03_0032EBF0(void *a) {
    D_001D7C20_sda = -1;
    func_L03_0032EC38();
    func_L03_0032ED88(a);
    func_L03_0032EDE0(a);
    func_L03_0032EF78(a);
}
/* localdecomp:end func_L03_0032EBF0 */
