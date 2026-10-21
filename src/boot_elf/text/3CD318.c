#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003CD318();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003CD318 */
typedef struct { u8 p[0x24]; } T36_3C79F0;
typedef struct { s32 k; s32 f4; T36_3C79F0 *f8; } E12_3C79F0;
extern E12_3C79F0 D_00380F00[];
extern T36_3C79F0 D_00380F0C[];
extern s32 D_001DA480;
extern s32 D_001DA484;
extern s32 D_002DD190[];
extern u8 D_002DD390[];
extern s32 D_002DAB00[];
extern u8 D_002DAEC0[];
void func_003CD318(s32 key, s32 flag) {
    s32 i = 0;
    while (D_00380F00[i].k != -1 && D_00380F00[i].k != key) i++;
    if (flag) {
        D_002DD190[D_001DA484] = D_00380F00[i].f4;
        D_002DD390[D_001DA484] = D_00380F00[i].f8 - D_00380F0C;
    } else {
        D_002DAB00[D_001DA480] = D_00380F00[i].f4;
        D_002DAEC0[D_001DA480] = D_00380F00[i].f8 - D_00380F0C;
    }
}
/* localdecomp:end func_003CD318 */
