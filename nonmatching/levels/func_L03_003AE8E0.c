/* Level 3. File L03_003AE810.c. Matches with check.py --mode S (split addresses) on its own, but the file's flags are -mno-split-addresses, which func_L03_003AE810 and func_L03_003AE880 in the same file need (they give 29 and 26 diff in S): with the file's flags 20 diff (retail splits the lui/addiu of D_L03_001DE7B0 apart). Needs func_00381FF0 declared as in those blocks. */
#include "common.h"

extern s32 func_00381FF0(s32);
typedef struct { char b[28]; } B28_3AE8E0;
extern B28_3AE8E0 D_L03_001DE7B0;
extern void func_003AF408(void *buf, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_003A9440(s32, unsigned long);
extern void func_0038E138(void);

void func_L03_003AE8E0(void) {
    B28_3AE8E0 buf = D_L03_001DE7B0;
    s32 r = func_00381FF0(0x16C3);
    func_003AF408(&buf, 0x80F0F0F0, r, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
