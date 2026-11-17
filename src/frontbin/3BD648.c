#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


/* localdecomp:start func_003BD648 */
typedef int u128_3B8168 __attribute__((mode(TI)));
typedef struct { u8 p0[0x38]; s32 idx; u8 p1[0x28]; u8 *tab; } S_3B8168;
extern S_3B8168 D_00225700_003BD648;
extern f32 D_002259B0[];
typedef struct { u8 p0[0x140]; u128_3B8168 q; u8 p1[0x10]; f32 m[3][4]; } D_3BD648;
extern u8 D_002222C0[];
extern void func_003873C0();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
s32 func_003BD648(void) {
    f32 m[16];
    D_3BD648 *d;
    S_3B8168 *s = &D_00225700_003BD648;
    u8 *p = s->tab + s->idx * 32;
    f32 *q = (f32 *)(p + 0x10);
    s32 flag = p[0xC] != 0;
    D_002259B0[0] = q[3];
    func_003873C0();
    *(u128_3B8168 *)(D_002222C0 + 0x140) = *(u128_3B8168 *)p;
    func_12FF40(m);
    func_130088(m, m, *(f32 *)(p + 0x10));
    func_130130(m, m, q[1]);
    func_12FFE0(m, m, q[2]);
    d = (D_3BD648 *)D_002222C0;
    d->m[0][0] = -m[8];
    d->m[1][0] = -m[0];
    d->m[2][0] = m[4];
    d->m[0][1] = -m[9];
    d->m[1][1] = -m[1];
    d->m[2][1] = m[5];
    d->m[0][2] = -m[10];
    d->m[1][2] = -m[2];
    d->m[2][2] = m[6];
    return flag;
}
/* localdecomp:end func_003BD648 */

extern u8 D_001DA2A0[];
extern s32 D_001DA2B0[];
extern f32 D_001DA2B4[];
extern f32 D_001DA2B8[];
INCLUDE_ASM("asm/nonmatchings/text", func_003BD760);

INCLUDE_ASM("asm/nonmatchings/text", func_003BD7A0);
