#include "common.h"

/* localdecomp:start func_L39_00602010 */
/* from rac2-decomp's func_00336CE8 (loop shape) */
__asm__(".extern D_001D734C_sda, 4");
extern s32 D_001D734C_sda;
extern char D_L39_002452A0[];
extern char D_L39_002452E0[];
extern char D_L39_00245310[];
__asm__(".extern D_L39_00242A5C, 16");
extern s32 D_L39_00242A5C;
extern void func_00128BF0(void *, ...);
extern void func_003A9CB8(s32);

void func_L39_00602010(s32 *a) {
    s32 *row;
    s32 n;
    s32 i;

    func_00128BF0(D_L39_002452A0);
    row = a + 7;
    n = a[6];
    func_00128BF0(D_L39_002452E0, row, n);
    for (i = 0; i < n; i++) {
        row[i * 2 + 1] += (s32)a;
        func_003A9CB8(row[i * 2 + 1]);
        D_001D734C_sda = D_L39_00242A5C + 1;
    }
    func_00128BF0(D_L39_00245310);
}
/* localdecomp:end func_L39_00602010 */
