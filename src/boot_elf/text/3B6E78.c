#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B6CD8.c's earlier functions (tools/port_from_us.py) */
extern void func_00393340(s32);
extern void func_0039E9C0(s32);
extern void func_003BB5A8(s32);
extern s32 func_003BB760(s32);
extern s32 D_001D8AA0;
extern s32 D_001D8A9C;
extern s32 D_001D8AAC;
extern s32 D_001D8AB0;
extern s32 D_001D8AA4;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC[];
extern u8 D_001D5BDC_003B6DB0[];
extern void func_003A5748(s32, s32, s32);

/* localdecomp:start func_003B6E78 */
typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6E78;
__asm__(".extern D_001D8A18_003B6E78, 4");
extern F D_001D8A48_003B6E78[1];
__asm__(".extern D_001D8A48_003B6E78, 8");
extern T D_001D8A4C[1];
__asm__(".extern D_001D8A4C, 16");
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6C00();
extern void func_003B6CC8();
extern void func_003B6D28();
extern void func_003B6D68();
extern void func_003B6E50();
void func_003B6E78(s32 unused) {
    s32 i;
    s32 m = D_001D8A18_003B6E78;
    for (i = 0; i < 4; i++) {
        D_001D8A48_003B6E78[i].on = 1;
        switch (m) {
        case 0: D_001D8A4C[i].fn = func_003B6D28; break;
        case 1:
            D_001D8A4C[i].fn = func_003B6CC8;
            if (D_142430[i].a[12] == -1) D_001D8A4C[i].fn = func_003B6E50;
            break;
        case 2: D_001D8A4C[i].fn = func_003B6C00; break;
        case 3: D_001D8A4C[i].fn = func_003B6D68; break;
        }
    }
}
/* localdecomp:end func_003B6E78 */
