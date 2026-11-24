/* func_00387B18 (PAL frontbin, src/frontbin/382380.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as), written from the assembly 2026-11-21, then the wording of its
   boot_elf twin (nonmatching/boot_elf/func_00387EF8.c) with frontbin's callees. Near miss: 15
   differences (tools/check.py --target frontbin, PAL; also 15 with --no-context), down from 72 on
   2026-11-23. NTSC-U has no twin of it (config/us/map.tsv).

   What took it from 72 to 15 is only the order of the global stores after the screen-mode
   branches. In gcc's first scheduling pass (sched1, -dS dump), a store whose value or base
   register dies there (a REG_DEAD note, register weight -1) is picked before a store whose value
   stays live (weight 0), and only then by insn order; so the store order follows those deaths,
   not the source order. With f240/f248/[2]/[6]/[8] before [4]/[10]/f10 in the source, the
   D_001A1ED0/D_00225900 bases also land in retail's $t1/$t2 (109 differences, with the bases
   right); single-statement moves from there (a greedy search over every move and swap, about
   1,100 compiles) gave the order below at 15. Locals for the [2]/[4] or [6]/[8] values (s32 or
   long) give 15; one long local reused for the [2] and [6] values gives 167; reading f8 into a
   local any earlier than the [6] store gives 79 or more. The unused `long gs` of the old draft
   is gone (15 either way).

   What still differs (15 words, in the block before the [12] store and at the end of the store
   block): retail loads .f8 before .f4 and puts `dsll $v1, $v1, 0x10` and `lui $v0, 0x100` between
   the loads; ours loads .f4 first and does the ALU work after (sched1 takes the .f4 load first by
   insn order, and the order sched2 leaves differs); and retail stores f240, f248, [2], ours
   [2], f248, f240 (putting f240/f248 before [2] in the source makes the rest worse).

   When it matches: its delay slot (0x387EE8, `addiu $sp, $sp, 0xB0`) is marked
   LINKER_REMNANT(func_00387EE8), but config/inventory.tsv gives the function 980 bytes, that word
   included: drop the remnant line.

   CLOSEOUT attempt 1 of 2 (2026-11-24): no improvement, still 15. Both orders are decided in
   gcc's first scheduling pass by insn order (luid), not by priority: in block 5 of sched1 the
   .f4 load (insn 282) and the .f8 load (insn 310) tie (priority 12, two dependents each) and
   the .f4 load is expanded first; in sched2 they tie again (priority 20, 18 dependents each).
   Expanding any .f8 reader before the [2] statement does put the .f8 load first, but it also
   moves that store forward and swaps $t5/$t6 ([6] statement first: 24; [6] and [8]: 25; the
   D_001422F0 or D_00142360 statement first: 125 to 147). Writing f240, f248 before [2] gives
   retail's store order but swaps $t5/$t6 between the [2]/[4] value and the f244 value (20);
   a greedy move search from that order (676 single moves per round) leads back to the order
   below (15). The .f8 value in a local, at any position: 68 (long) or 79 (s32); the .f8 field
   read into a local: 79 or 82. The [2]/[4] value as ((long)w >> 6) << 16, or without the cast
   on .f4: 15 (the same code); with + for |: 16; operands swapped: 64. Retail also issues the
   $v0 move (insn 390) before the 0x4BD4 load (insn 358), against sched2's priorities here (19
   against 21), so its dependences there differ, not only a tie. */
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20; } S_1A1ED0_387B18;
typedef struct { u8 p0[0x150]; u16 f150, f152; u8 p154[4]; s16 f158, f15A; } S_1CFEC0_387B18;
typedef struct { u8 p0[0x240]; s32 f240, f244, f248, f24C; } S_225900_387B18;
extern S_1A1ED0_387B18 D_001A1ED0_00387B18;
extern S_1CFEC0_387B18 D_001CFEC0_00387B18;
extern S_225900_387B18 D_00225900_00387B18;
extern s32 D_00143950[];
extern s32 D_001D5520;
extern s32 D_001D4BB0_00387B18, D_001D4BB4_00387B18;
extern s32 D_001D4BC0_00387B18, D_001D4BC4_00387B18, D_001D4BC8_00387B18, D_001D4BCC_00387B18;
extern s32 D_001D4BD0_00387B18, D_001D4BD4_00387B18, D_001D4BD8_00387B18, D_001D4BDC_00387B18;
extern long D_00142120_00387B18[];
extern long D_00142360[];
extern long D_001422F0[];
extern long D_001D5330_00387B18[];
extern u8 D_002276C0[];
extern void func_11F0A0(s32);
extern s32 func_12A9F0(s32, s32);
extern void func_00391678(s32, s32, s32, s32, s32, s32);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_00392290(void);
extern void func_0038CB78(void *, s32, s32);
extern void func_12C9A0(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_12CCC8(void *, void *);
extern void func_003D9338(void);
void func_00387B18(s32 load) {
    u8 buf[0x60];
    s32 w, h, base, n, i;
    S_1CFEC0_387B18 *scr;
    func_11F0A0(0);
    if (D_00143950[0] != 0) {
        D_001A1ED0_00387B18.f8 = 0x100000;
        D_001A1ED0_00387B18.f4 = 0x1E0000;
        D_001A1ED0_00387B18.fC = 0x2C0000;
        D_001A1ED0_00387B18.f0 = 0;
        func_00391678(0x200, 0x1C0, 0x200, 0x200, 4, 0);
    } else if (D_001D5520 != 0) {
        D_001A1ED0_00387B18.f8 = 0x118000;
        D_001A1ED0_00387B18.f4 = 0x1E8000;
        D_001A1ED0_00387B18.fC = 0x2C0000;
        D_001A1ED0_00387B18.f0 = 0;
        func_00391678(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        D_001A1ED0_00387B18.f8 = 0x118000;
        D_001A1ED0_00387B18.f4 = 0x1E8000;
        D_001A1ED0_00387B18.fC = 0x2C0000;
        D_001A1ED0_00387B18.f0 = 0;
        func_00391678(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    scr = &D_001CFEC0_00387B18;
    w = (s16)scr->f150;
    h = (s16)scr->f152;
    base = D_001A1ED0_00387B18.fC;
    D_001D4BD4_00387B18 = (0x800 - (h >> 1)) << 4;
    D_001D4BD0_00387B18 = (0x800 - (w >> 1)) << 4;
    D_00225900_00387B18.f244 = w - 1;
    D_001D4BC8_00387B18 = (w >> 1);
    D_001D4BCC_00387B18 = (h >> 1);
    D_00225900_00387B18.f24C = h - 1;
    D_001A1ED0_00387B18.f14 = base + 0x1000;
    D_001A1ED0_00387B18.f18 = base + 0x1400;
    D_001A1ED0_00387B18.f1C = base + 0x1800;
    D_001A1ED0_00387B18.f20 = base + 0x1C00;
    D_001D4BD8_00387B18 = ((w >> 1) + 0x800) << 4;
    D_001D4BDC_00387B18 = ((h >> 1) + 0x800) << 4;
    D_00142120_00387B18[2] = ((long)D_001A1ED0_00387B18.f4 >> 13) | ((long)(w >> 6) << 16);
    D_00225900_00387B18.f248 = 0;
    D_00225900_00387B18.f240 = 0;
    D_00142120_00387B18[6] = (D_001A1ED0_00387B18.f8 >> 13) | 0x1000000;
    D_00142120_00387B18[8] = (D_001A1ED0_00387B18.f8 >> 13) | 0x1000000;
    D_00142120_00387B18[4] = ((long)D_001A1ED0_00387B18.f4 >> 13) | ((long)(w >> 6) << 16);
    D_00142120_00387B18[10] = (long)D_001D4BD0_00387B18 | ((long)D_001D4BD4_00387B18 << 32);
    D_00142120_00387B18[12] = (long)D_001D4BD0_00387B18 | ((long)D_001D4BD4_00387B18 << 32);
    D_001A1ED0_00387B18.f10 = base;
    D_001D4BC0_00387B18 = w;
    D_001D4BC4_00387B18 = h;
    D_001D5330_00387B18[2] = ((long)D_00225900_00387B18.f244 << 16) | ((long)D_00225900_00387B18.f24C << 48);
    D_00142360[0] = ((D_001A1ED0_00387B18.f8 >> 13) | 0x1000000) | 0x100000000L;
    D_001422F0[0] = (D_001A1ED0_00387B18.f8 >> 13) | 0x1000000;
    D_001D5330_00387B18[4] = ((long)D_00225900_00387B18.f244 << 16) | ((long)D_00225900_00387B18.f24C << 48);
    if (load != 0) {
        D_001D4BB0_00387B18 = base;
        D_001D4BB4_00387B18 = base;
        func_11F0A0(0);
        func_12A9F0(0, 0);
        func_11F0A0(0);
        func_003922B8();
        func_00392350(0);
        func_11F0A0(0);
        func_12A9F0(0, 0);
        func_00392290();
        func_0038CB78(D_002276C0, 0, 0x1000);
        n = (scr->f158 * scr->f15A) >> 10;
        for (i = 0; i < n; i++) {
            func_12C9A0(buf, i << 4, 1, 0, 0, 0, 0x20, 0x20);
            func_11F0A0(0);
            func_12CCC8(buf, D_002276C0);
            func_12A9F0(0, 0);
        }
    }
    func_003D9338();
}
