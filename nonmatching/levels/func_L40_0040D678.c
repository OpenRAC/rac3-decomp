/* func_L40_0040D678: near miss, 2 diff at level 40. 340 bytes, 14 levels (40-53),
   src/levels/shared/L40_0040A4D0.c (flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as).
   Written from asm (2026-11-11). One walk step of a Ranger towards `target`: once a frame its
   walker (func_L01_0045B958) is reset, then the walk helpers run.

   Every instruction is retail's except the $gp immediates of the two loads of the frame counter
   D_L40_0024112C in branch delay slots (ours 0x516C, retail -0x6E94). Retail reads the counter
   through lui/lw where it can and through $gp in a delay slot: Ps2EeAs, which does not know its
   size, cannot expand the two-word load in a slot. For such a $gp access Ps2EeAs writes an addend
   of -0x4000 into the instruction and 0x4000 as the object's gp0 (.reginfo ri_gp_value). Retail's
   linker undid that; GNU ld adds gp0 only for local symbols, so it links this object 0x4000 off
   (an isolated link reports "relocation truncated to fit: R_MIPS_GPREL16"), and tools/check.py and
   tools/level_symbols.py, which ignore gp0, report the same 0x4000 (level_symbols would derive
   0x0024512C for the name). So this C is the function, and it waits for the build to honour
   Ps2EeAs's gp0 (subtract 0x4000 from such an access's addend before linking, or apply gp0).

   Tried: a sized alias with an .extern hint for the slot loads (the documented two-name form): the
   first one is fine, but the second slot load is reorg's copy of the join block's first insn (the
   fall-through keeps the lui/lw), so a second name for it moves the store into the slot instead
   (5 diff). func_L40_0040D310 has the same mix on the same counter (its row).
   Context: the file's prelude (vu0.h) and earlier blocks (D_L40_0024112C[] in .sdata is
   func_L40_0040B9C0's). */
#include "common.h"
#include "vu0.h"

extern s32 D_L40_0024112C[] __attribute__((section(".sdata")));
/* localdecomp:start func_L40_0040D678 */
extern u8 *func_L01_0045B958(u8 *m);
extern void func_L01_0045B908(u8 *m, u8 *w);
extern void func_L01_0045B6C8(u8 *m, u8 *w, f32 f);
extern void func_L01_0045AF28(u8 *m, u8 *w);
extern void func_L01_0045B110(u8 *m, u8 *w, void *target);
extern void func_L01_0045BB60(u8 *m, u8 *w, f32 yaw);
extern void func_L01_0045C240(void);
extern void func_L40_0040D7D0(u8 *m, u8 *w, void *target, f32 yaw, vu0_v4 *a, vu0_v4 *b);

/* One walk step towards `target`: the moby's walker (once a frame), then the walk itself. */
s32 func_L40_0040D678(u8 *m, void *target, f32 yaw) {
    u8 *w;
    s32 last;
    vu0_v4 old;
    vu0_v4 a;
    vu0_v4 b;

    w = func_L01_0045B958(m);
    if (w == 0) {
        return 8;
    }
    if (D_L40_0024112C[0] == *(s32 *)(w + 0xBC)) {
        return *(s32 *)(w + 0x94);
    }
    *(s32 *)(w + 0x98) = *(s32 *)(w + 0x94);
    *(s32 *)(w + 0x94) = 0;
    if (!(*(s32 *)(w + 0x38) & 0x100)) {
        func_L01_0045B908(m, w);
    }
    old = *(vu0_v4 *)(m + 0x10);
    last = *(s32 *)(w + 0xBC);
    if (D_L40_0024112C[0] - last >= 2 || last == 0) {
        func_L01_0045B6C8(m, w, 0.0f);
        *(f32 *)(w + 0xB4) = 0.0f;
        *(u8 *)(w + 0xEA) = 0xFF;
        *(s32 *)(w + 0x9C) &= ~2;
        qzero(w + 0xA0);
        *(s32 *)(w + 0x80) = 0;
    }
    *(s32 *)(w + 0xBC) = D_L40_0024112C[0];
    func_L40_0040D7D0(m, w, target, yaw, &a, &b);
    func_L01_0045AF28(m, w);
    func_L01_0045B110(m, w, target);
    func_L01_0045BB60(m, w, yaw);
    func_L01_0045C240();
    return *(s32 *)(w + 0x94);
}
/* localdecomp:end func_L40_0040D678 */
