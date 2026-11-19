#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3BEE98.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003BDD38();
extern void func_003BE308();

extern u8 D_001DA310;
extern u8 D_001DA311;
extern s32 D_001D8DF0;
extern s32 D_001D8DF4;
extern void *D_002FCC40;
extern void func_003BBA08(s32, s32);
extern void func_003BC408();
extern void func_003BDCB0(s32, s32 *, s32);
extern s32 func_003BDD38(void);
extern void func_003BDE20(s32);
extern void func_003BF2A0();
extern void func_003BF0E0();
extern void func_003BE308(void *);
extern void func_003BE1F8(s32);
/* localdecomp:start func_003BF058 */
extern void *D_002FCC40_003BF058[];
extern u8 D_001DA310_003BF058[2];
__asm__(".extern D_001DA310_003BF058, 16");
__asm__(".extern D_001D8DF4, 16");
s32 func_003BF058(void) {
    D_001DA310_003BF058[0] = 0;
    D_001DA310_003BF058[1] = 0;
    func_003BBA08(0, 0);
    func_003BC408(4, &D_001D8DF0);
    func_003BDCB0(3, &D_001D8DF4, D_001D8DF0);
    func_003BDE20(func_003BDD38());
    D_002FCC40_003BF058[0] = func_003BF2A0;
    func_003BE308(func_003BF0E0);
    func_003BE1F8(1);
    return 1;
}
/* localdecomp:end func_003BF058 */
