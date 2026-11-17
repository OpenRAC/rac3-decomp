/* Level 17 (Crash Site), PAL. 7 diff with check.py (55 counted with the sized-pointer form below,
   one cause). Needs `-mvu0-use-vf0-vf2` on L17_003BE8C8.c (already @ps2as), include/vu0.h, and a
   config/levels/divs_nops.txt row `func_L17_003BEEE8 2`.
   What differs: only the delay slot of the second `bltz`. Retail fills it with `lui $s2,
   %hi(D_001A4C60)` and loads the node table D_001DF180 after it (`lui $a2; lw $a2`, the assembler
   macro). With the table as a sized `u8 *` plus `.extern D_L17_001DF180, 16` (as the other files
   declare it) every other instruction is retail's, but reorg takes the table load into that slot
   (Ps2EeAs writes it through $gp there) and the rest shifts by one. The unsized `u8 *[]` form below
   keeps the load out of the slot but gcc splits it (`lui $v0` / `lw $a2, %lo($v0)`) and schedules
   the `lq` earlier: 7 differences. A load at symbol+offset (a struct starting at 0x1DF17C) fills
   the slot as retail does, which suggests retail's load was not slot-eligible, but there is no
   evidence for such a struct. The `rel` subtraction is a VU0 block of its own: retail computes it
   into the subtrahend's register (`vsub.xyz $vf1, $vf2, $vf1`), which vec_sub_ab does not give. */
#include "vu0.h"
typedef struct { u8 p0[0x30]; vu0_v4 pos; u8 p40[0x40]; } N_3BEEE8;
extern u8 D_001A4C60[];
extern u8 *D_L17_001DF180[];
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L17_003BEEE8(u8 *self) {
    s32 *ids = *(s32 **)(self + 0x68);
    vu0_v4 a, dir, rel, proj, hero;
    f32 t;
    s32 i0 = ids[0];

    if (i0 < 0 || ids[1] < 0) return;
    vec_copy(&hero, D_001A4C60);
    a = ((N_3BEEE8 *)D_L17_001DF180[0])[i0].pos;
    vec_sub_ba(&dir, &((N_3BEEE8 *)D_L17_001DF180[0])[ids[1]].pos, &a);
    {
        vu0_q h, q;
        __asm__("lqc2 %0, %1" : "=j"(h) : "m"(hero));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(a));
        __asm__("vsub.xyz %0, %1, %0" : "+j"(q) : "j"(h));
        __asm__("sqc2 %1, %0" : "=m"(rel) : "j"(q));
    }
    t = func_0038CE68(&dir, &rel);
    t = t / func_0038CE68(&dir, &dir);
    func_0038CE20(&proj, &dir, t);
    vec_sub_ab(&proj, &rel, &proj);
    func_0038CF68(D_001A4C60 + 0x290, &proj, -1.0f);
    *(f32 *)(D_001A4C60 + 0x29C) = 1.0f;
}
