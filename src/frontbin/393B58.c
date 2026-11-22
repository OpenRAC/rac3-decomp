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

typedef struct { u8 pad[0x38]; u16 h38; u8 pad2[0xF0 - 0x3A]; } S_38F310;
typedef struct { s32 w0; u8 pad[0x14]; s32 w18; } D_393B58;
extern s32 D_001D9EE8_00393B58;
extern s32 *D_001D9EF0_00393B58;
extern s32 D_001D5D40;
extern s32 D_001D5CAC;
extern s32 D_1D4C60[2];
extern s32 D_1D4C80[2];
extern u8 D_001425C0[];
extern S_38F310 D_001DAA40_00393B58[];
extern D_393B58 D_00331990[];
/* localdecomp:start func_00393B58 */
__asm__(".extern D_001D9EE8_00393B58, 16");
__asm__(".extern D_001D9EF0_00393B58, 16");
__asm__(".extern D_1D4C60, 16");
__asm__(".extern D_1D4C80, 16");
__asm__(".extern D_001D5D40, 4");
__asm__(".extern D_001D5CAC, 4");
void func_00393B58(s32 a) {
    s32 *p;
    s32 i;
    S_38F310 *e;

    D_001D9EE8_00393B58 = 8;
    D_001D9EF0_00393B58 = &D_001D5D40;
    p = a ? D_1D4C80 : D_1D4C60;
    D_001D5CAC = 0;
    for (i = 0; i < 8; i++) {
        e = &D_001DAA40_00393B58[D_001425C0[p[i]]];
        D_00331990[i].w0 = e->h38;
        D_00331990[i].w18 = p[i];
    }
}
/* localdecomp:end func_00393B58 */
