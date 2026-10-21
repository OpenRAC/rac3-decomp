#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003F2388(s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2380();
extern s32 func_003F2388();
extern s32 *func_003F2390(s32 *);
extern s32 func_003F23A8(s32 *);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003F2238 */
extern u8 D_001D9858[];
void func_003F2238(u8 *p, s32 f) { *(u8 **)p = D_001D9858; if (f & 1) func_003F2380(p); }
/* localdecomp:end func_003F2238 */

/* localdecomp:start func_003F2268 */
typedef struct { s32 f0; u8 *base; u32 size; s32 elem; u32 used; s32 count; void **freelist; } P_3ECCA0;
void *func_003F2268(P_3ECCA0 *p) {
    void **n = p->freelist;
    u32 off, end;
    if (n != 0) {
        p->freelist = *n;
        p->count++;
        return n;
    }
    off = p->used;
    end = off + p->elem;
    if (p->size < end) return 0;
    { u8 *r = p->base + off; p->used = end; p->count++; return r; }
}
/* localdecomp:end func_003F2268 */

/* localdecomp:start func_003F22D0 */
extern void * func_003F2268();
 
s32 func_003F22D0(void *p, u32 n) {
    if (*(u32 *)((u8 *)p + 0xC) < n) {
        return 0;
    }
    return (s32)func_003F2268(p);
}
/* localdecomp:end func_003F22D0 */

/* localdecomp:start func_003F2308 */
void func_003F2308(s32 *p, s32 *node) {
    *node = p[6];
    p[6] = (s32)node;
    p[5]--;
}
/* localdecomp:end func_003F2308 */

/* localdecomp:start func_003F2328 */
extern u8 D_001D9858_g;
extern s32 func_003F2380();
void func_003F2328(u8 *p, s32 f) {
    *(u8 **)p = &D_001D9858_g;
    if (f & 1) func_003F2380(p);
}
/* localdecomp:end func_003F2328 */

LINKER_REMNANT("asm/remnants", func_003F2358);

/* localdecomp:start func_003F2380 */
s32 func_003F2380(void) {
}
/* localdecomp:end func_003F2380 */

/* localdecomp:start func_003F2388 */
s32 func_003F2388(s32 a0, s32 a1) {
    return a1;
}
/* localdecomp:end func_003F2388 */

/* localdecomp:start func_003F2390 */
s32 *func_003F2390(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003F2390 */

LINKER_REMNANT("asm/remnants", func_003F23A0);

/* localdecomp:start func_003F23A8 */
s32 func_003F23A8(s32 *p) {
    return *p != 0;
}
/* localdecomp:end func_003F23A8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003F23B8);
