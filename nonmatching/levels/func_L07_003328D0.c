/* near miss (level 7, Annihilation Nation): 11 differences. The instruction sequence is
   retail's; only the register allocation differs: retail has counter `$4`, `s` `$5`, `e` `$6`
   and the three hoisted table-address groups interleaved (`lui v1,0x2B`, `lui v0,0x14`,
   `addiu t0`, `addiu a2`, `lui a1,0x1E`, `addiu a1`, `addiu a0`). The high temporary of
   D_001E0CD0 takes `$4` in our build and `$5` in retail, which pushes the counter out of `$4`.
   About 90 wordings (pointer walks, indexed forms, ascending/descending/while/do-while,
   u8*/s32* types, an explicit destination pointer, early-return CFG and temporaries) all stay
   at 11 or worse; the ascending indexed form with a `k` temporary is this one. */
#include "common.h"

/* localdecomp:start func_L07_003328D0 */
typedef struct { s32 idx; s32 x; } E_003328D0;
extern E_003328D0 D_L07_002B0EB0[];
extern s32 D_L07_001E0CD0[];
extern s32 D_001427F0[];

void func_L07_003328D0(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 i;

    if (p[0xBF] != 0) {
        for (i = 0; i < 16; i++) {
            s32 k = D_L07_002B0EB0[i].idx;
            D_001427F0[k] = D_L07_001E0CD0[i];
        }
        p[0xBF] = 0;
    }
}
/* localdecomp:end func_L07_003328D0 */
