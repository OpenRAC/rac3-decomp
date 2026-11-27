#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BA4F8(void *, s32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_003BA358();
/* --- end of declarations from other files --- */

/* declarations of 3B9BD0.c's earlier functions */
extern void func_003BA340();
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003B9E50(void *p, s32 x, s32 y);
extern s32 func_003B9E70(s32 a0, s32 a1);

/* localdecomp:start func_003BA340 */
void func_003BA340(void *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    *(s32 *)((u8 *)a0 + 0x8c) = a1;
    *(s32 *)((u8 *)a0 + 0x90) = a2;
    *(s32 *)((u8 *)a0 + 0x94) = a3;
    *(s32 *)((u8 *)a0 + 0x98) = a4;
}
/* localdecomp:end func_003BA340 */

/* localdecomp:start func_003BA358 */
extern s32 func_003B9E50(void *, s32, s32);
extern s32 func_003E7928(s32, s32, s32);
typedef struct { u8 p[0x10]; s32 n; } S_B4E78;
void func_003BA358(S_B4E78 *s) {
    s32 i, t;
    for (i = 0; ; ) {
        t = s->n + 2;
        if (i >= t) break;
        func_003E7928(func_003B9E50(s, 0, i), 1, 3);
        func_003E7928(func_003B9E50(s, 1, i), 2, 3);
        i++;
    }
}
/* localdecomp:end func_003BA358 */

LINKER_REMNANT("asm/remnants", func_003BA3E8);

/* localdecomp:start func_003BA3F0 */
extern s32 func_003E7A18(s32 arg0, s32 arg1);
void func_003BA3F0(u8 *p) {
    func_003E7A18(0x4F00B0, p[0xA8]);
    func_003E7A18(0x4F00B1, p[0xA8]);
}
/* localdecomp:end func_003BA3F0 */

/* localdecomp:start func_003BA430 */
extern s32 func_003B9E70(s32, s32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7A18(s32, s32);
typedef struct { u8 p0[0x10]; s32 x10; u8 p14[0x4C]; f32 x60; u8 p64[0x10]; u8 x74; u8 p75[0x2B]; f32 xA0; f32 xA4; } S_4F;
void func_003BA430(S_4F *a0) {
    f32 t = a0->x60 - a0->xA0;
    s32 i;
    if (t < 0.0f) t = 0.0f;
    for (i = 0; i < a0->x10 + 2; i++) {
        func_003E81F0(func_003B9E70((s32)a0, i), t, a0->xA4);
        func_003E7A18(func_003B9E70((s32)a0, i), a0->x74);
    }
}
/* localdecomp:end func_003BA430 */

/* localdecomp:start func_003BA4E0 */
void func_003BA4E0(void *a0, s32 a1, f32 a2, f32 a3, f32 a4) {
    __asm__ volatile (
        "sb $5, 0x74($4)\n"
        "swc1 $12, 0x70($4)\n"
        "swc1 $13, 0xa4($4)\n"
        :: "r"(a0), "r"(a1)
    );
    *(f32 *)((u8 *)a0 + 0xa0) = a4;
}
/* localdecomp:end func_003BA4E0 */

/* localdecomp:start func_003BA4F8 */
extern void func_003BA430();
extern void func_003BA6D0(void *);
extern void func_003BA790(void *);
extern void func_003BA920(void *, s32);
extern void func_003BACD8(void *);
extern void func_003BB5D0();
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E7760(s32, f32);
extern s32 func_003E7A18(s32 arg0, s32 arg1);
extern s32 func_003E81F0(s32, f32, f32);

void func_003BA4F8(void *arg0, s32 arg1) {
    func_003BA3F0(arg0);
    func_003BA608(arg0);
    func_003BA6D0(arg0);
    func_003BA790(arg0);
    func_003BACD8(arg0);
    func_003BA430(arg0);
    func_003BB5D0();
    if ((*(s32 *)((u8 *)(arg0) + 0x1C)) == 0) {
        func_003BA920(arg0, arg1);
    }
    func_003E73B8(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_003E81F0(0x4F00A8, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_003E73B8(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x7C)), (*(f32 *)((u8 *)(arg0) + 0x80)));
    func_003E81F0(0x4F00B3, (*(f32 *)((u8 *)(arg0) + 0x84)), (*(f32 *)((u8 *)(arg0) + 0x88)));
    func_003E7A18(0x4F00B3, (*(u8 *)((u8 *)(arg0) + 0xA9)));
    func_003E7760(0x4F00B0, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_003E7760(0x4F00B1, (*(f32 *)((u8 *)(arg0) + 0x6C)));
    func_003E81F0(0x4F00AF, (*(f32 *)((u8 *)(arg0) + 0x60)), (*(f32 *)((u8 *)(arg0) + 0x64)));
}
/* localdecomp:end func_003BA4F8 */
