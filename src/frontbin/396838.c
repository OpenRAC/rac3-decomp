#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 396690.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_00396838(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u16 x0; u16 x2; u16 x4; u8 x6; u8 x7; } E_38ED00;
extern E_38ED00 *D_001D9EA4[];
s32 func_00392F68(s32);

typedef struct { u8 p0[0x18]; void (*f18)(void *); u8 p1c[0x74]; } S_391FD8;
extern S_391FD8 D_00331AE0_00396838[];
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern s32 D_001D9E94;
extern s32 D_001D9DF8;
extern s32 D_001D9DFC;
extern s32 D_001D9E00;
extern s32 D_001D5B94;
/* localdecomp:start func_00396838 */
extern s32 D_001D9EC0;
extern s32 D_001D9EBC_00396838;
extern s32 D_001D9BDC;
extern s32 D_001D9E94;
extern s32 D_001D9E00;
extern s32 D_001D9DF8_00396838;
extern s32 D_001D9DFC_00396838;
extern s32 D_001D9DF8;
__asm__(".extern D_001D9DF8, 4");
extern s32 D_001D9DFC;
__asm__(".extern D_001D9DFC, 4");
extern s32 D_001D5B94;
__asm__(".extern D_001D5B94, 4");
void func_00396838(void) {
    S_391FD8 *p;
    s32 i;
    s32 z;
    if (D_001D9EC0 || D_001D9BDC) {
        (&D_001D9EBC_00396838)[1] = 0;
        return;
    }
    D_001D9E94 = 0xFFFFF0;
    p = D_00331AE0_00396838;
    for (i = 12; i >= 0; i--) {
        if (p->f18) p->f18(p);
        p++;
    }
    if (D_001D9DF8_00396838 || D_001D9DFC_00396838) {
        if (D_001D5B94 == 0) {
            if (D_001D9DF8_00396838) {
                D_001D9DFC += 0x12;
                if (D_001D9DFC > 0x80) D_001D9DFC = 0x80;
            } else {
                D_001D9DFC -= 0x12;
                if (D_001D9DFC < 0) D_001D9DFC_00396838 = 0;
            }
            if (D_001D9DF8_00396838) D_001D9DF8_00396838 = D_001D9DF8_00396838 - 1;
            if (D_001D9DF8_00396838 == 1000) D_001D9DF8 = 0;
            return;
        }
    }
    D_001D9E00 = 100;
}
/* localdecomp:end func_00396838 */
