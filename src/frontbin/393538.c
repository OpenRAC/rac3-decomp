#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_00393538();
typedef struct { s32 pad0; s32 f4; s32 pad8[7]; s32 f24; s32 pad28[15]; s32 id; s32 f68; s32 pad6C[9]; } S_38ED78;
extern S_38ED78 D_00331AE0[];
extern s32 func_00392F68(s32 key);

/* localdecomp:start func_00393538 */
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
typedef struct { s32 x0; u8 pad[0x3C]; s16 x40; u8 x42; u8 x43; s32 x44; } S_38ED00;
extern E_38ED00 *D_001D9EA4[];
s32 func_00392F68(s32);
void func_00393538(S_38ED00 *d, s32 a) {
    s32 i = func_00392F68(a);
    if (i < 0) i = 0;
    d->x0 = D_001D9EA4[0][i].x0;
    d->x40 = i;
    d->x42 = D_001D9EA4[0][i].x6;
    d->x44 = D_001D9EA4[0][i].x4;

}
/* localdecomp:end func_00393538 */
