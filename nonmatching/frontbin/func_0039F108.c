/* Near miss of func_0039F108: tools/check.py reports 19 diff.
   What differs: the last loop
   (`g->f2c == 1 && !(g->f18 & 2)` counting into D_001D9FBC): retail loads `f2c` in the delay
   slot of the loop-back `beql`, so the loop branches past that load; the C loads it at the top
   of the loop. While/do-while/for forms and a `continue` form all give the same 19. */
#include "common.h"
/* localdecomp:start func_0039F108 */
typedef struct { u8 p0[0x8]; s16 h8; s16 hA; s32 fC; s16 h10; u8 p1[2]; s32 f14; u16 f18; u8 p2[0xA]; s32 (*f24)(s32); s32 f28; s16 f2c; s16 f2e; } E_39A170;
extern E_39A170 *D_00333AC8_0039F108[];
extern E_39A170 *D_001D9FC0_0039F108;
extern s32 D_001D9FBC;
extern u8 D_001D5570[8];
__asm__(".extern D_001D9FC0_0039F108, 16");
__asm__(".extern D_001D5570, 16");
__asm__(".extern D_001D9FBC, 16");
extern s32 func_0039F348(s32, s32, s32);
extern void func_0039EF18();
static __inline__ u8 isEnd_39A170(E_39A170 *e) {
    s32 r = 1;
    if (e != 0 && e->h8 != 0) r = 0;
    return r;
}
s32 func_0039F108(u32 i) {
    E_39A170 *e, *f, *g;
    s32 j;
    s32 r;
    if (i >= 0x3C) return 0;
    if (D_00333AC8_0039F108[i] == 0) return 0;
    func_0039F0C8(i);
    if (D_001D9FC0_0039F108 == 0) return 0;
    for (j = 0; isEnd_39A170(e = &D_00333AC8_0039F108[i][j]) == 0; j++) {
        if ((e->f18 & 4) && D_001D5570[i] == 0) {
            e->f2c = 0;
            continue;
        }
        if (func_0039F348(i, e->hA, e->fC) == 0) {
            if (e->f2c != 0) func_0039EF18();
            e->f2c = 0;
            continue;
        }
        if (func_0039F348(i, e->h10, e->f14) == 0) {
            if (e->f2c != 1) {
                e->f2c = 1;
                func_0039EFD8(i, j);
                func_0039EF18();
            }
            continue;
        }
        if (e->f2c != 2) {
            func_0039EF18();
            e->f2c = 2;
            func_0039EFD8(i, j);
        }
    }
    for (j = 0; isEnd_39A170(f = &D_001D9FC0_0039F108[j]) == 0; j++) {
        if (f->f24 != 0) {
            r = f->f24(f->f28);
            D_001D9FC0_0039F108[j].f2e = r;
        }
    }
    D_001D9FBC = 0;
    for (g = D_001D9FC0_0039F108; isEnd_39A170(g) == 0; g++) {
        if (g->f2c == 1 && !(g->f18 & 2)) D_001D9FBC++;
    }
    return D_001D9FBC == 0;
}
/* localdecomp:end func_0039F108 */
