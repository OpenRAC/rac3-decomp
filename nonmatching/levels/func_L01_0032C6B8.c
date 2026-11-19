/* near miss: 4 diff of 57 words (needs @ps2as -mvu0-use-vf0-vf2, as its file has now; vu0.h comes from the file, s128 does not: the file defines it in
 * func_L01_0032C9F0's block, after this function, so the typedef below has to move to the file's prelude with the block's copy removed): retail copies
 * the call result of func_L01_004C80D0 into $s2 before the two argument moves of the first func_0038CE90 call; ours does it after (sched1 puts it
 * there, sched2 moves it behind the swc1). Tried in round 9 without change: callees returning s32 (each and all), r as s32 / void * / a struct
 * pointer, r declared at its use, a local for a0->p68, L.a and L.d stored separately or reversed, L.e first, the call as the second statement (14). */
#include "common.h"

typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_0032C6B8 */
typedef struct {
    u8 pad0[0x48];
    s32 w48;
} S_32C6B8m;
typedef struct {
    u8 pad0[0x68];
    S_32C6B8m *p68;
} S_32C6B8;
extern u8 *func_L01_004C80D0(s32 a0);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C47E8(void *, void *);

void func_L01_0032C6B8(S_32C6B8 *a0, s128 *a1) {
    struct { s128 a, b, c, d, e, f, g; } L;
    u8 *r;

    r = func_L01_004C80D0(a0->p68->w48);
    L.a = L.d = *a1;
    L.e = 0;
    ((f32 *)&L.e)[2] = 1.0f;
    func_0038CE90(&L.b, &L.a, &L.e);
    func_0038CF68(&L.b, &L.b, 1.0f);
    func_0038CE90(&L.c, &L.b, &L.a);
    func_003C47E8(r + 0x10, &L.a);
    func_003C2F58(a0, 0, &L.f);
    func_0038D000(&L.d, a1, (u8 *)a0 + 0xC0);
    vec_add_ab(&L.g, &L.d, &L.f);
}
/* localdecomp:end func_L01_0032C6B8 */
