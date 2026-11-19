#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 *func_003B42C0();

/* localdecomp:start func_003B4258 */
void func_003B4258(void *p, s32 a) {
    void *q = *(void **)((u8 *)p + 0x4);
    ((void (*)(void *, s32, s32))*(void **)((u8 *)q + 0x1C))(p, a, 0);
}
/* localdecomp:end func_003B4258 */

/* localdecomp:start func_003B4280 */
extern s32 func_00396968(s32, s32);
s32 func_003B4280(u8 *p, s32 a, s32 b) {
    s32 r = func_00396968(a, b);
    *(s32 *)(p + 8) = r;
    return r != 0;
}
/* localdecomp:end func_003B4280 */

/* localdecomp:start func_003B42B8 */
s32 func_003B42B8(void *p) {
    return *(s32 *)((u8 *)p + 0x8);
}
/* localdecomp:end func_003B42B8 */

extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C[];
extern s32 D_001DA110[];
extern u8 D_001D8918[];
/* localdecomp:start func_003B42C0 */
extern s32 D_001DA114;
extern s32 D_001DA108;
extern u8 *D_001DA10C_003B42C0;
__asm__(".extern D_001DA10C_003B42C0, 16");
extern s32 D_001DA110_003B42C0;
__asm__(".extern D_001DA110_003B42C0, 16");
extern u8 D_001D8918_003B42C0[] __attribute__((section(".sdata")));
__asm__(".extern D_001D8918_003B42C0, 16");
s32 *func_003B42C0(void) {
    if (!D_001DA114) {
        D_001DA10C_003B42C0 = D_001D8918_003B42C0;
        D_001DA108 = 1;
        D_001DA114 = 1;
        D_001DA110_003B42C0 = 0;
    }
    return &D_001DA108;
}
/* localdecomp:end func_003B42C0 */

/* localdecomp:start func_003B42F8 */
extern void **func_003B4438();
extern s32 D_001DA118;
extern u8 D_00240A20[];
void *func_003B42F8(s32 arg0) {
    s32 i; u8 *p;
    if (D_001DA118 == 0) {
        p = D_00240A20;
        i = 3;
        do { func_003B4438(p); i--; __asm__ volatile("nop"); p += 0x20; } while (i != -1);
        D_001DA118 = 1;
    }
    return (arg0 << 5) + D_00240A20;
}
/* localdecomp:end func_003B42F8 */
