#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003AC300();
extern void *func_003AC270();
extern s32 func_003AC190(u8 *, s32);
/* --- end of declarations from other files --- */

/* declarations of 3ABF50.c's earlier functions (tools/port_from_us.py) */
extern void func_00121760();
extern void func_003AA070();
extern char D_001D8230[];
extern char D_001D8270[];
extern char D_001D82A0[];
extern s32 D_001D5C84;

/* localdecomp:start func_003AC190 */
typedef struct { s32 k, v; } E_3A6830;
s32 func_003AC190(u8 *p, s32 k) {
    s32 n = *(s32 *)(p + 0x18);
    E_3A6830 *e = (E_3A6830 *)(p + 0x1C);
    s32 i;
    s32 r = 0;
    for (i = 0; i < n; i++) {
        if (e[i].k == k) {
            r = e[i].v;
            break;
        }
    }
    return r;
}
/* localdecomp:end func_003AC190 */

/* localdecomp:start func_003AC1E0 */
void *func_003AC1E0(void *p) {
    return p;
}
/* localdecomp:end func_003AC1E0 */

/* localdecomp:start func_003AC1E8 */
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D82F8[];
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; s32 f10; s32 f14; } S_003A6888;

void func_003AC1E8(S_003A6888 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    if (arg1 < 4U) {
        func_00116F98(D_001D82D8, 0x26, D_001D82F8);
    }
    arg0->f0 = arg2;
    arg0->f4 = arg3;
    arg0->f8 = arg1;
    arg0->f14 = 0;
    arg0->fC = 0;
    arg0->f10 = 0;
}
/* localdecomp:end func_003AC1E8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AC268);

/* localdecomp:start func_003AC270 */
void func_00116F98(void *, s32, void *);
extern u8 D_001D82D8[];
extern u8 D_001D8320[];
typedef struct { u8 *base; u32 size; s32 elem; u32 used; s32 count; void **free; } S_003A6910;

void *func_003AC270(S_003A6910 *pool) {
    void **p;
    u32 used;
    u32 next;

    p = pool->free;
    if (p != 0) {
        pool->free = *p;
        pool->count++;
        return p;
    }
    used = pool->used;
    next = used + pool->elem;
    if (pool->size < next) {
        func_00116F98(D_001D82D8, 0x54, D_001D8320);
        return 0;
    }
    { u8 *r = pool->base + used; pool->used = next; pool->count++; return r; }
}
/* localdecomp:end func_003AC270 */

/* localdecomp:start func_003AC300 */
void func_003AC300(void *a0, void *a1) {
    *(s32 *)a1 = *(s32 *)((u8 *)a0 + 0x14);
    *(s32 *)((u8 *)a0 + 0x14) = (s32)a1;
    *(s32 *)((u8 *)a0 + 0x10) = *(s32 *)((u8 *)a0 + 0x10) - 1;
}
/* localdecomp:end func_003AC300 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003AC320);

/* localdecomp:start func_003AC328 */
extern u8 *func_003AB5D0(u8 *);
u8 *func_003AC328(u8 *p) {
    func_003AB5D0(p + 0x10);
    func_003AB5D0(p + 0x4C);
    return p;
}
/* localdecomp:end func_003AC328 */

typedef struct {
    s32 *p0; s32 *p4; s32 *p8; s32 *pC;
    u8 sub10[0x3C]; u8 sub4C[0x3C]; u8 b88; u8 pad89[0x188 - 0x89];
    s32 f188, f18C, f190; u8 pad194[4]; s32 f198; u8 pad19C[8];
    s32 f1A4, f1A8, f1AC; u8 pad1B0[4]; s32 f1B4; u8 f1B8[0x78];
} O_3A6A00;
extern s32 D_001D5C78;
extern u8 D_001D8370[], D_001D8380[];
extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2740(s32, s32);
extern void func_003AB608();
extern void func_003AB7E0(u8 *, u8 *, s32);
extern void func_003AB810(void *, f32);
extern void func_003AB2B8(void *, s32);
extern s32 func_003AB270(void *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AC360);

LINKER_REMNANT("asm/boot_elf/remnants", func_003AC568);
