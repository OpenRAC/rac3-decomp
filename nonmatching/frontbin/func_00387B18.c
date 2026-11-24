/* func_00387B18 (PAL frontbin, src/frontbin/382380.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as), written from the assembly 2026-11-21; on 2026-11-22 replaced by
   the wording of its boot_elf twin's draft (nonmatching/boot_elf/func_00387EF8.c) with frontbin's
   callees. Near miss: 72 differences (tools/check.py, PAL; also 72 with --no-context), down from
   153 for the first wording and 74 for the twin's. NTSC-U has no twin of it (config/us/map.tsv:
   its code differs there). The two else branches store 0x118000 to .f8 first, D_00142360 /
   D_001422F0 are arrays, and D_00143950 is `extern s32 D_00143950[]` read as [0], as elsewhere in
   382380.c (74 -> 72: retail loads it into $v1). What still differs is the same as in the boot_elf
   twin: the bases of D_001A1ED0 and D_00225900 swap $t1/$t2 (and h $t4/$t3 follows), and the block
   of global stores after the branches is scheduled in another order (retail stores [4] right after
   D_001D4BDC, then [10], f10, D_001D4BC0-CC, f240/f248, [2], [6], [8]). Tried at 72: D_001A1ED0 or
   D_00225900 as arrays, a pointer to D_001A1ED0, base read before scr, the two globals declared in
   the other order, and five orders of the store block (moving [4], f10, [2]/[6]/[8] or f240/f248);
   [10] right after [4] gives 77. Retried 2026-11-22 (13 more compiles, none below 72): five orders of the locals' declarations and dropping the unused `long gs` (72 each); the f10 store moved to five earlier places (72 each: the compiler places it after [8] wherever the source has it, so the store order is set by the scheduler, not the source order, and retail's stores follow the source order exactly); [2] = [4] (72); the [4]/[2] value in a local computed after base (79); w >> 6 read from the struct (80). When it matches: its delay slot (0x387EE8, `addiu $sp, $sp,
   0xB0`) is marked LINKER_REMNANT(func_00387EE8), but config/inventory.tsv gives the function 980
   bytes, that word included: drop the remnant line. */
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
    long gs;
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
    D_00225900_00387B18.f24C = h - 1;
    D_00142120_00387B18[12] = (long)D_001D4BD0_00387B18 | ((long)D_001D4BD4_00387B18 << 32);
    D_001A1ED0_00387B18.f14 = base + 0x1000;
    D_001A1ED0_00387B18.f18 = base + 0x1400;
    D_001A1ED0_00387B18.f1C = base + 0x1800;
    D_001A1ED0_00387B18.f20 = base + 0x1C00;
    D_001D4BD8_00387B18 = ((w >> 1) + 0x800) << 4;
    D_001D4BDC_00387B18 = ((h >> 1) + 0x800) << 4;
    D_00142120_00387B18[4] = ((long)D_001A1ED0_00387B18.f4 >> 13) | ((long)(w >> 6) << 16);
    D_00142120_00387B18[10] = (long)D_001D4BD0_00387B18 | ((long)D_001D4BD4_00387B18 << 32);
    D_001A1ED0_00387B18.f10 = base;
    D_001D4BC0_00387B18 = w;
    D_001D4BC4_00387B18 = h;
    D_001D4BC8_00387B18 = (w >> 1);
    D_001D4BCC_00387B18 = (h >> 1);
    D_00225900_00387B18.f240 = 0;
    D_00225900_00387B18.f248 = 0;
    D_00142120_00387B18[2] = ((long)D_001A1ED0_00387B18.f4 >> 13) | ((long)(w >> 6) << 16);
    D_00142120_00387B18[6] = (D_001A1ED0_00387B18.f8 >> 13) | 0x1000000;
    D_00142120_00387B18[8] = (D_001A1ED0_00387B18.f8 >> 13) | 0x1000000;
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
