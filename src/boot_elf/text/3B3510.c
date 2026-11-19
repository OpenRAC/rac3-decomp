#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B3510(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B3408.c's earlier functions */
extern void func_003AA060();
extern void *func_003E6FC0();

extern void func_003AA060();
extern void func_003E71C8_003B3510();
extern void func_003E6F70();
extern void *func_003E6FC0();
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA938_003B3510;
/* localdecomp:start func_003B3510 */
__asm__(".extern D_001D8881, 1");
typedef struct { s16 h0; s16 h2; s32 f4; } V_003B3510;
extern V_003B3510 D_001D9EBC_003B3510;
void func_003B3510(s32 a) {
    S_003ADBB0 *q;
    void *base;
    if (D_001D9EC0 || D_001D9BDC) {
        D_001D9EBC_003B3510.f4 = 0;
        return;
    }
    func_003AA060(1);
    if (D_001D8881) return;
    q = &D_001DA938_003B3510;
    if (q->f4 != 0) base = q; else base = func_003E6FC0(q);
    func_003E71C8_003B3510(base, a);
    q = &D_001DA938_003B3510;
    if (q->f4 != 0) base = q; else base = func_003E6FC0(q);
    func_003E6F70(base);
}
/* localdecomp:end func_003B3510 */
