/* func_00387EF8 (PAL boot_elf, src/boot_elf/text/3877A0.c, flags -mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division @ps2as): the boot_elf twin of frontbin's func_00387B18
   (nonmatching/frontbin/func_00387B18.c), ported to boot_elf's callees. Near miss: 74 differences
   (tools/check.py, PAL; the same on NTSC-U at 0x00387ED0). From the frontbin draft's 153: the two
   else branches store 0x118000 to .f8 first (so reorg puts the shared `lui $v0, 0x11` in the
   beqz delay slot, as retail does), and D_00142360 / D_001422F0 are arrays (retail builds their
   %hi in a register, not in $at). What still differs: the load of D_00143950 goes to $v0 (retail
   $v1); the bases of D_001A1ED0 and D_00225900 swap $t1/$t2; and the block of global stores after
   the branches is scheduled in another order (retail stores [4] before [10] and f10 after them).
   Three wordings (a pointer to D_00225900, a pointer to D_001A1ED0, w>>1/h>>1 as locals) all give
   74. When it matches: drop LINKER_REMNANT(func_003882C8), its delay slot (inventory.tsv gives the
   function 980 bytes, that word included). */
typedef struct { s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20; } S_1A1ED0_387B18;
typedef struct { u8 p0[0x150]; u16 f150, f152; u8 p154[4]; s16 f158, f15A; } S_1CFEC0_387B18;
typedef struct { u8 p0[0x240]; s32 f240, f244, f248, f24C; } S_225900_387B18;
extern S_1A1ED0_387B18 D_001A1ED0_00387EF8;
extern S_1CFEC0_387B18 D_001CFEC0_00387EF8;
extern S_225900_387B18 D_00225900_00387EF8;
extern s32 D_00143950_00387EF8;
extern s32 D_001D5520;
extern s32 D_001D4BB0_00387EF8, D_001D4BB4_00387EF8;
extern s32 D_001D4BC0_00387EF8, D_001D4BC4_00387EF8, D_001D4BC8_00387EF8, D_001D4BCC_00387EF8;
extern s32 D_001D4BD0_00387EF8, D_001D4BD4_00387EF8, D_001D4BD8_00387EF8, D_001D4BDC_00387EF8;
extern long D_00142120_00387EF8[];
extern long D_00142360[];
extern long D_001422F0[];
extern long D_001D5330_00387EF8[];
extern u8 D_002276C0[];
extern void func_11F0A0(s32);
extern s32 func_12A9F0(s32, s32);
extern void func_00391A58(s32, s32, s32, s32, s32, s32);
extern void func_00392698(void);
extern void func_00392730(s32);
extern void func_00392670(void);
extern void func_0038CF58(void *, s32, s32);
extern void func_12C9A0(void *, s16, s32, s32, s32, s32, s32, s32);
extern void func_12CCC8(void *, void *);
extern void func_003D96F0(void);
void func_00387EF8(s32 load) {
    u8 buf[0x60];
    s32 w, h, base, n, i;
    long gs;
    S_1CFEC0_387B18 *scr;
    func_11F0A0(0);
    if (D_00143950_00387EF8 != 0) {
        D_001A1ED0_00387EF8.f8 = 0x100000;
        D_001A1ED0_00387EF8.f4 = 0x1E0000;
        D_001A1ED0_00387EF8.fC = 0x2C0000;
        D_001A1ED0_00387EF8.f0 = 0;
        func_00391A58(0x200, 0x1C0, 0x200, 0x200, 4, 0);
    } else if (D_001D5520 != 0) {
        D_001A1ED0_00387EF8.f8 = 0x118000;
        D_001A1ED0_00387EF8.f4 = 0x1E8000;
        D_001A1ED0_00387EF8.fC = 0x2C0000;
        D_001A1ED0_00387EF8.f0 = 0;
        func_00391A58(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        D_001A1ED0_00387EF8.f8 = 0x118000;
        D_001A1ED0_00387EF8.f4 = 0x1E8000;
        D_001A1ED0_00387EF8.fC = 0x2C0000;
        D_001A1ED0_00387EF8.f0 = 0;
        func_00391A58(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    scr = &D_001CFEC0_00387EF8;
    w = (s16)scr->f150;
    h = (s16)scr->f152;
    base = D_001A1ED0_00387EF8.fC;
    D_001D4BD4_00387EF8 = (0x800 - (h >> 1)) << 4;
    D_001D4BD0_00387EF8 = (0x800 - (w >> 1)) << 4;
    D_00225900_00387EF8.f244 = w - 1;
    D_00225900_00387EF8.f24C = h - 1;
    D_00142120_00387EF8[12] = (long)D_001D4BD0_00387EF8 | ((long)D_001D4BD4_00387EF8 << 32);
    D_001A1ED0_00387EF8.f14 = base + 0x1000;
    D_001A1ED0_00387EF8.f18 = base + 0x1400;
    D_001A1ED0_00387EF8.f1C = base + 0x1800;
    D_001A1ED0_00387EF8.f20 = base + 0x1C00;
    D_001D4BD8_00387EF8 = ((w >> 1) + 0x800) << 4;
    D_001D4BDC_00387EF8 = ((h >> 1) + 0x800) << 4;
    D_00142120_00387EF8[4] = ((long)D_001A1ED0_00387EF8.f4 >> 13) | ((long)(w >> 6) << 16);
    D_00142120_00387EF8[10] = (long)D_001D4BD0_00387EF8 | ((long)D_001D4BD4_00387EF8 << 32);
    D_001A1ED0_00387EF8.f10 = base;
    D_001D4BC0_00387EF8 = w;
    D_001D4BC4_00387EF8 = h;
    D_001D4BC8_00387EF8 = (w >> 1);
    D_001D4BCC_00387EF8 = (h >> 1);
    D_00225900_00387EF8.f240 = 0;
    D_00225900_00387EF8.f248 = 0;
    D_00142120_00387EF8[2] = ((long)D_001A1ED0_00387EF8.f4 >> 13) | ((long)(w >> 6) << 16);
    D_00142120_00387EF8[6] = (D_001A1ED0_00387EF8.f8 >> 13) | 0x1000000;
    D_00142120_00387EF8[8] = (D_001A1ED0_00387EF8.f8 >> 13) | 0x1000000;
    D_001D5330_00387EF8[2] = ((long)D_00225900_00387EF8.f244 << 16) | ((long)D_00225900_00387EF8.f24C << 48);
    D_00142360[0] = ((D_001A1ED0_00387EF8.f8 >> 13) | 0x1000000) | 0x100000000L;
    D_001422F0[0] = (D_001A1ED0_00387EF8.f8 >> 13) | 0x1000000;
    D_001D5330_00387EF8[4] = ((long)D_00225900_00387EF8.f244 << 16) | ((long)D_00225900_00387EF8.f24C << 48);
    if (load != 0) {
        D_001D4BB0_00387EF8 = base;
        D_001D4BB4_00387EF8 = base;
        func_11F0A0(0);
        func_12A9F0(0, 0);
        func_11F0A0(0);
        func_00392698();
        func_00392730(0);
        func_11F0A0(0);
        func_12A9F0(0, 0);
        func_00392670();
        func_0038CF58(D_002276C0, 0, 0x1000);
        n = (scr->f158 * scr->f15A) >> 10;
        for (i = 0; i < n; i++) {
            func_12C9A0(buf, i << 4, 1, 0, 0, 0, 0x20, 0x20);
            func_11F0A0(0);
            func_12CCC8(buf, D_002276C0);
            func_12A9F0(0, 0);
        }
    }
    func_003D96F0();
}
