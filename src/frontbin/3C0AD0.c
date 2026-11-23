#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[0x40]; s32 w40; s32 w44; } S_3BB558;
extern S_3BB558 D_002D1FC0[];
extern void func_003BE008(f32);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


extern s32 func_0038CAD0();
extern s32 func_003BDF18();
extern void func_003BB968();
/* localdecomp:start func_003C0AD0 */
s32 func_003C0AD0(s32 a) {
    S_3BB558 *g = D_002D1FC0;
    s32 r = 0;
    s32 k;
    switch (g->w44) {
    case 0:
        if (func_0038CAD0(&g->w40) == 1) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 1:
        if (func_0038CAD0(&g->w40) == 1) {
            g->w40 = 0x4B;
            g->w44 = g->w44 + 1;
        }
        func_003BE008((f32)g->w40 / 12.0f);
        break;
    case 2:
        if (func_003BDF18()) func_003BB968();
        if (func_0038CAD0(&g->w40) == 1 && a != 0) {
            g->w40 = 0xC;
            g->w44 = g->w44 + 1;
        }
        break;
    case 3:
        if (func_0038CAD0(&g->w40) == 1) r = 1;
        func_003BE008(1.0f - (f32)g->w40 / 12.0f);
        break;
    }
    return r;
}
/* localdecomp:end func_003C0AD0 */

extern s32 D_001D4BC0;
extern u8 D_002D1FC0_003C0C40[];
extern void func_00389240();
extern void func_00390F50(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00389370();
/* localdecomp:start func_003C0C40 */
extern s32 D_001D4BC0_003C0C40;
extern u8 D_002D1FC0_003C0C40_003C0C40[];
extern void func_00389240_003C0C40();
extern void func_00390F50_003C0C40(s32, s32, unsigned long, u8 *, s32, f32);
extern void func_00389370_003C0C40();
void func_003C0C40(void) {
    func_00389240_003C0C40(1);
    func_00390F50_003C0C40(D_001D4BC0_003C0C40 >> 1, 0xA0, 0x80FFFFFF, D_002D1FC0_003C0C40_003C0C40, -1, 1.2f);
    func_00389370_003C0C40();
}
/* localdecomp:end func_003C0C40 */
