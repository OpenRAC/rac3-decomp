#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AA9D8.c's earlier functions */
extern void func_003AB038();
void func_003AB038();

extern s32 D_003357E0[];
typedef struct { u8 pad[4]; f32 *v; u8 p2[0x28-8]; void *p28; u8 p3[4]; long l30; s32 w38; s32 w3C; } S_3A6450;
/* localdecomp:start func_003AB9F8 */
void func_003AB9F8(S_3A6450 *p) {
    func_003AB038(p);
    p->p28 = D_003357E0;
    p->l30 = 1;
    p->w38 = 0;
    p->v[0] = 1.0f;
    p->v[1] = 1.0f;
    p->w3C = 1;
}
/* localdecomp:end func_003AB9F8 */
