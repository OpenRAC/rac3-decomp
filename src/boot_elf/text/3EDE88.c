#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2738();
extern s32 func_003EDF90();
extern void func_003EE038();
extern void func_003EDE88(void *p, s32, s32);
extern void func_003EDF30();
extern void func_003EDE88(void *, s32, s32);
extern s32 func_003EDEB0();
extern void func_003EDEC0(void *, s32, s32);
extern void func_003EDEF8();
extern void func_003EDF20(void *, f32, f32);
extern void func_003EDF48(void *, f32, f32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003EDE88 */
void func_003EDE88(void *p, s32 mask, s32 set) {
    if (set != 0) {
        *(s32 *)((u8 *)p + 0xC) |= mask;
    } else {
        *(s32 *)((u8 *)p + 0xC) &= ~mask;
    }
}
/* localdecomp:end func_003EDE88 */

/* localdecomp:start func_003EDEB0 */
s32 func_003EDEB0(void *p, s32 mask) {
    return (*(s32 *)((u8 *)p + 0xC) & mask) != 0;
}
/* localdecomp:end func_003EDEB0 */

/* localdecomp:start func_003EDEC0 */
void func_003EDEC0(void *p, s32 a, s32 b) {
    *(u32 *)((u8 *)p + 0xC) = (((*(u32 *)((u8 *)p + 0xC) & ~0x600) | (a << 9)) & ~0x1800) | (b << 11);
}
/* localdecomp:end func_003EDEC0 */

/* localdecomp:start func_003EDEF8 */
void func_003EDEF8(void *p, s32 *a, s32 *b) {
    *a = (*(u32 *)((u8 *)p + 0xC) >> 9) & 3;
    *b = (*(u32 *)((u8 *)p + 0xC) >> 11) & 3;
}
/* localdecomp:end func_003EDEF8 */

/* localdecomp:start func_003EDF20 */
void func_003EDF20(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x10) = x;
    *(f32 *)((u8 *)p + 0x14) = y;
}
/* localdecomp:end func_003EDF20 */

/* localdecomp:start func_003EDF30 */
void func_003EDF30(void *a0, f32 *a1, f32 *a2) {
    *a1 = *(f32 *)((u8 *)a0 + 0x10);
    *a2 = *(f32 *)((u8 *)a0 + 0x14);
}
/* localdecomp:end func_003EDF30 */

/* localdecomp:start func_003EDF48 */
void func_003EDF48(void *p, f32 x, f32 y) {
    *(f32 *)((u8 *)p + 0x18) = x;
    *(f32 *)((u8 *)p + 0x1C) = y;
}
/* localdecomp:end func_003EDF48 */

/* localdecomp:start func_003EDF58 */
s32 func_003EDF58(void) {
    return 1;
}
/* localdecomp:end func_003EDF58 */

/* localdecomp:start func_003EDF60 */
s32 func_003EDF60(s32 p, s32 k) {
    if (k == 1) {
        return 1;
    }
    return func_003E74B8(p, k);   /* defined earlier in text.c */
}
/* localdecomp:end func_003EDF60 */

/* localdecomp:start func_003EDF90 */
typedef struct V_3E8670 { u8 pad[0x14]; s32 (*fn)(void *, s32); } V_3E8670;
typedef struct { u8 pad[8]; V_3E8670 *vt; } O_3E8670;
extern s32 func_003EDEB0();
s32 func_003EDF90(O_3E8670 *a, s32 b) {
    if (func_003EDEB0(a, 1) != 0) return a->vt->fn(a, b);
    return 0;
}
/* localdecomp:end func_003EDF90 */

/* localdecomp:start func_003EDFE8 */
typedef struct { u8 pad[0x18]; void (*fn)(void *, s32); } V_3E86C8;
typedef struct { u8 pad[8]; V_3E86C8 *vt; } S_3E86C8;
extern s32 func_003EDEB0();
void func_003EDFE8(S_3E86C8 *a, s32 b) {
    if (func_003EDEB0(a, 1)) a->vt->fn(a, b);
}
/* localdecomp:end func_003EDFE8 */

/* localdecomp:start func_003EE038 */
extern void func_003E75D0(void);
extern void func_003E75F0(void);
extern s32 func_003EDEB0(void *, s32);
void func_003EE038(void *arg0, s32 arg1) {
    if (func_003EDEB0(arg0, 1) != 0) {
        (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)arg0 + 8)) + 0x1C))(arg0, arg1);
    }
    if (func_003EDEB0(arg0, 0x4000) != 0) {
        func_003E75F0();
        func_003E75D0();
    }
}
/* localdecomp:end func_003EE038 */

/* localdecomp:start func_003EE0A8 */
s32 func_003EE0A8(void) {
}
/* localdecomp:end func_003EE0A8 */

/* localdecomp:start func_003EE0B0 */
extern char D_001D9670[];
void func_003EE0B0(u8 *p, s32 f) { *(u8 **)(p + 8) = D_001D9670; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003EE0B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003EE0E0);
