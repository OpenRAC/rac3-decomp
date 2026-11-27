#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 *func_003B4678();
extern void *func_003B46B0(s32);
extern void *func_003B46B0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B4610 */
void func_003B4610(void *p, s32 a) {
    void *q = *(void **)((u8 *)p + 0x4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)q + 0x1C))(p, a, 0);
}
/* localdecomp:end func_003B4610 */

/* localdecomp:start func_003B4638 */
extern s32 func_00396D48(s32, s32);
s32 func_003B4638(u8 *p, s32 a, s32 b) {
    s32 r = func_00396D48(a, b);
    *(s32 *)(p + 8) = r;
    return r != 0;
}
/* localdecomp:end func_003B4638 */

/* localdecomp:start func_003B4670 */
s32 func_003B4670(void *p) {
    return *(s32 *)((u8 *)p + 0x8);
}
/* localdecomp:end func_003B4670 */

extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C[];
extern s32 D_001DA110[];
extern u8 D_001D8918[];
/* localdecomp:start func_003B4678 */
extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C_003B4678;
__asm__(".extern D_001DA10C_003B4678, 16");
extern s32 D_001DA110_003B4678;
__asm__(".extern D_001DA110_003B4678, 16");
extern u8 D_001D8918_003B4678[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8918_003B4678, 16");
s32 *func_003B4678(void) {
    if (!D_001DA114) {
        D_001DA10C_003B4678 = D_001D8918_003B4678;
        D_001DA108 = 1;
        D_001DA114 = 1;
        D_001DA110_003B4678 = 0;
    }
    return &D_001DA108;
}
/* localdecomp:end func_003B4678 */

/* localdecomp:start func_003B46B0 */
extern void **func_003B47F0();
extern s32 D_001DA118;
extern u8 D_00240A20[];
void *func_003B46B0(s32 arg0) {
    s32 i; u8 *p;
    if (D_001DA118 == 0) {
        p = D_00240A20;
        i = 3;
        do { func_003B47F0(p); i--; p += 0x20; } while (i != -1);
        D_001DA118 = 1;
    }
    return (arg0 << 5) + D_00240A20;
}
/* localdecomp:end func_003B46B0 */
