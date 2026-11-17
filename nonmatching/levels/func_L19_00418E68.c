/* func_L19_00418E68: 38 diff with --as ps2as (file needs @ps2as in config/levels/text_parts.txt); $gp globals declared sized + .extern hints.
   2026-11-13 retry: the callee is func_L01_00423068 (catalogue name). The rest stems from one thing: gcc's first
   jump pass turns `found = 1` (inner test) into movz (jump.c conditional move); retail keeps a branch
   (beql with the set in its slot) and tests `found & 0xFF` at the loop bottom. Tried: found as u8/s8/s16/u16
   (u8 loses the andi), `(u8)found == 0`, `&&` vs nested ifs, `!(v5 > hi)`, empty then + else, a dead second
   set, `continue` after the set: all keep the movz. */
/* localdecomp:start func_L19_00418E68 */
typedef struct { u8 pad0[0x20]; void *f20; u8 pad24[0xC]; s32 f30; } S_418E68a;
typedef struct { u8 pad0[0x30]; s32 f30; s32 f34; } S_418E68b;
extern S_418E68a D_L19_002E9320;
extern S_418E68b D_L19_001E6440;
extern u8 D_L19_002E9370[];
extern s32 D_001D545C;
__asm__(".extern D_L19_001D6B84, 4");
extern f32 D_L19_001D6B84;
__asm__(".extern D_L19_001D6AE5, 1");
extern u8 D_L19_001D6AE5;
__asm__(".extern D_L19_001D6AF0, 4");
extern s32 D_L19_001D6AF0;
__asm__(".extern D_L19_001D6BC8, 4");
extern s32 D_L19_001D6BC8;
__asm__(".extern D_L19_001D6BE0, 4");
extern s32 D_L19_001D6BE0;
__asm__(".extern D_L19_001D6BB0, 4");
extern s32 D_L19_001D6BB0;
extern void func_L01_00423068(void *, s32, void *, s32, s32, s32, s32);

void func_L19_00418E68(void) {
    S_418E68a *t = &D_L19_002E9320;
    void *p = 0;
    void *a2 = 0;
    s32 a3 = 0;
    s32 found;
    s32 i;
    s32 v5 = 0;
    s32 *pa;
    s32 *pb;
    D_L19_001D6B84 = 1.0f;
    t->f20 = &D_L19_001D6AF0;
    D_L19_001D6AE5 = 0;
    t->f30 = 1;
    if (D_001D545C == 0x13 && D_L19_001E6440.f30 == 1) {
        found = 0;
        t->f30 = 0;
        a3 = 1;
        v5 = D_L19_001E6440.f34;
        D_L19_001D6B84 = -1.0f;
        pa = &D_L19_001D6BC8;
        pb = &D_L19_001D6BE0;
        for (i = 0; i < 6 && (found & 0xFF) == 0; i++) {
            if (v5 >= (pa[i] * 5 + 2) / 6) {
                if (v5 <= (pb[i] * 5 + 2) / 6) {
                    found = 1;
                }
            }
        }
        D_L19_001D6AE5 = found;
        a2 = &D_L19_001D6BB0;
        p = D_L19_002E9370;
    }
    if (p) {
        func_L01_00423068(p, 0, a2, a3, 0, 1, 0);
    }
}
/* localdecomp:end func_L19_00418E68 */
