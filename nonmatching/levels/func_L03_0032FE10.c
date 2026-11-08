/* near miss (level 3, Starship Phoenix): 9 differences: retail has a single `sq $zero, 0xF0($s0)` (the quadword zero store, known out of reach from plain C, see level 1 notes), gcc emits `por` + `sq` and shifts the rest by one; everything else matches (store order 2E,0E,30,2F) */
#include "common.h"

/* localdecomp:start func_L03_0032FE10 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct S_0032FE10b { u8 pad00[0x10]; s32 f10; u8 pad14[0x24-0x14]; f32 f24; } S_0032FE10b;
typedef struct S_0032FE10 {
    u8 pad00[0x24]; S_0032FE10b *f24; u8 pad28[4]; f32 f2C; u8 pad30[4]; u16 f34;
    u8 pad36[0x98-0x36]; s32 f98; u8 pad9C[0xF0-0x9C]; u128_t fF0;
} S_0032FE10;
typedef struct S_0032FE10c { u8 pad00[0xE]; u8 fE; u8 pad0F[0x2E - 0xF]; u8 fa; u8 fb; u8 fc; } S_0032FE10c;
extern void *func_00382348(void *);
void func_L03_0032FE10(S_0032FE10 *p) {
    S_0032FE10c *q = func_00382348(p);
    S_0032FE10b *r;
    q->fa = 0;
    q->fc = 0;
    q->fb = 0;
    q->fE = 1;
    p->f34 = p->f34 & 0xBFB8;
    r = p->f24;
    p->f98 = r->f10;
    p->fF0 = 0;
    p->f2C = r->f24;
}
/* localdecomp:end func_L03_0032FE10 */
