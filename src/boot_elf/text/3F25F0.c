#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003F2740(s32, s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2738();
extern s32 func_003F2740();
extern s32 *func_003F2748(s32 *);
extern s32 func_003F2760(s32 *);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003F25F0 */
extern u8 D_001D9858[];
void func_003F25F0(u8 *p, s32 f) { *(u8 **)p = D_001D9858; if (f & 1) func_003F2738(p); }
/* localdecomp:end func_003F25F0 */

/* localdecomp:start func_003F2620 */
typedef struct { s32 f0; u8 *base; u32 size; s32 elem; u32 used; s32 count; void **freelist; } P_3ECCA0;
void *func_003F2620(P_3ECCA0 *p) {
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
/* localdecomp:end func_003F2620 */

/* localdecomp:start func_003F2688 */
extern void * func_003F2620();
 
s32 func_003F2688(void *p, u32 n) {
    if (*(u32 *)((u8 *)p + 0xC) < n) {
        return 0;
    }
    return (s32)func_003F2620(p);
}
/* localdecomp:end func_003F2688 */

/* localdecomp:start func_003F26C0 */
void func_003F26C0(s32 *p, s32 *node) {
    *node = p[6];
    p[6] = (s32)node;
    p[5]--;
}
/* localdecomp:end func_003F26C0 */

/* localdecomp:start func_003F26E0 */
extern u8 D_001D9858_g;
extern s32 func_003F2738();
void func_003F26E0(u8 *p, s32 f) {
    *(u8 **)p = &D_001D9858_g;
    if (f & 1) func_003F2738(p);
}
/* localdecomp:end func_003F26E0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2710);

/* localdecomp:start func_003F2738 */
s32 func_003F2738(void) {
}
/* localdecomp:end func_003F2738 */

/* localdecomp:start func_003F2740 */
s32 func_003F2740(s32 a0, s32 a1) {
    return a1;
}
/* localdecomp:end func_003F2740 */

/* localdecomp:start func_003F2748 */
s32 *func_003F2748(s32 *p) {
    *p = 0;
    return p;
}
/* localdecomp:end func_003F2748 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2758);

/* localdecomp:start func_003F2760 */
s32 func_003F2760(s32 *p) {
    return *p != 0;
}
/* localdecomp:end func_003F2760 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003F2770);
