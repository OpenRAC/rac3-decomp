#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B69F8.c's earlier functions */
extern void func_003B6A98(void);

typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6AC0;
extern F D_001D8A48_003B6AC0[1];
extern T D_001D8A4C[1];
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6848();
extern void func_003B6910();
extern void func_003B6970();
extern void func_003B69B0();
/* localdecomp:start func_003B6AC0 */
/* from boot_elf's func_003B6E78 (its twin); the types and externs are the file's */
__asm__(".extern D_001D8A18_003B6AC0, 4");
__asm__(".extern D_001D8A48_003B6AC0, 8");
__asm__(".extern D_001D8A4C, 16");
extern void func_003B6A98(void);
void func_003B6AC0(s32 unused) {
    s32 i;
    s32 m = D_001D8A18_003B6AC0;
    for (i = 0; i < 4; i++) {
        D_001D8A48_003B6AC0[i].on = 1;
        switch (m) {
        case 0: D_001D8A4C[i].fn = func_003B6970; break;
        case 1:
            D_001D8A4C[i].fn = func_003B6910;
            if (D_142430[i].a[12] == -1) D_001D8A4C[i].fn = func_003B6A98;
            break;
        case 2: D_001D8A4C[i].fn = func_003B6848; break;
        case 3: D_001D8A4C[i].fn = func_003B69B0; break;
        }
    }
}
/* localdecomp:end func_003B6AC0 */
