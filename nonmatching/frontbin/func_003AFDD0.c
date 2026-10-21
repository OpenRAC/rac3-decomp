/* Near miss of func_003AFDD0 with its file's own flags: tools/check.py reports 34 diff
   (the US draft it started from: 80).
   What differs: retail splits every function address (the %hi and %lo halves of func_003B0FF0,
   func_003B1108, func_003B0D60, func_003B0F50 and func_003B27C8 are separated, and
   func_003B0D60's addiu sits in the jal's delay slot), while the file's own -mno-split-
   addresses makes GCC materialize each of them as one adjacent lui+addiu pair before the call;
   the two func_003B2580 calls, the struct setup and the func_003B2BF8/func_11EB30/func_11F9A8
   tail therefore keep a different instruction order, and func_12D4D8 gets a nop in its delay
   slot (one word too many)
*/

/* US draft of func_003AFDD0 (rac3-uya-decomp func_003AA828, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AFDD0 */
/* Retail reaches most of these globals with lui/lw, not through $gp: they are
   declared without a size (the "_r" spellings) so GCC cannot place them in
   small data.  The three retail reaches through $gp keep their size: the
   argument of func_003B1308 and the argument of func_003B2478 and the store
   to D_001DA0C8 all sit in a branch delay slot, where a lui/lw pair cannot go. */
extern s32 D_001DA08C_r[];
extern s32 D_001DA090_r[];
extern s32 D_001DA094_r[];
extern s32 D_001DA098_r[];
extern s32 D_001DA09C_r1[];
extern s32 D_001DA09C_r2[];
extern s32 D_001DA0A0_r[];
extern s32 D_001DA0A8_r[];
extern s32 D_001DA0AC_r[];
extern s32 D_001DA088_r[];
extern s32 D_001DA0B0_r[];
extern s32 D_001DA0B4_r1[];
extern s32 D_001DA0B4_r2[];
extern s32 D_001DA0B4_r3[];
extern s32 D_001DA0B4_r4[];
extern s32 D_001DA0B4_r5[];
extern u8 D_001DC8B0_r[];
extern void func_003B1308();
extern void func_135B50();
extern s32 func_003B2478(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003B0070_003AFDD0();
extern void func_003B2580_003AFDD0();
extern void func_003B0FF0_003AFDD0();
extern void func_003B1108_003AFDD0();
extern void func_003B2BF8();
extern void func_003B27C8();
extern s32 func_11EC20();
extern void func_11FD40();
extern void func_003B1400_003AFDD0();
extern void func_12D4D8();
extern void func_003B0D60();
extern s32 func_11EB30();
extern void func_003B0F50();
extern void func_11F9A8();
typedef struct { s32 f0; void *f4; s32 f8; s32 fC; void *f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 pad[3]; } S_3AA828;
void func_003AFDD0(s32 a, s32 b, s32 c) {
    S_3AA828 s;
    s32 t;
    *(volatile u32 *)0x1000E000 |= 3;
    *(volatile u32 *)0x1000E010 = 4;
    func_003B1308(D_001DA09C_003AFDD0);
    func_135B50();
    func_003B2478(D_001DA0B4_r1[0], D_001DA098_r[0], 0xEC800, D_001DA0A4, D_001DA094_r[0], 0x100, D_001DA0AC_r[0], 0x200);
    func_003B0070_003AFDD0(D_001DA0B8[0], D_001DA0A0_r[0], 0xC000, 3);
    func_003B2580_003AFDD0(D_001DA0B4_r2[0], 0, 0, func_003B0FF0_003AFDD0, D_001DA09C_r1[0]);
    func_003B2580_003AFDD0(D_001DA0B4_r3[0], 3, c, func_003B1108_003AFDD0, D_001DA09C_r2[0]);
    func_003B2BF8(D_001DA088_r[0], (D_001DA08C_r[0] & 0xFFFFFFF) | 0x20000000, D_001DA090_r[0], 2);
    s.f4 = func_003B27C8;
    s.fC = 0x4000;
    s.f14 = 1;
    s.f10 = D_001DC8B0_r;
    s.f20 = 0;
    s.f8 = D_001DA0A8_r[0];
    t = func_11EC20(&s);
    D_001DA0C8_003AFDD0 = t;
    func_11FD40(t, D_001DA0B4_r4[0]);
    func_003B1400_003AFDD0(D_001DA0B0_r[0], a, b);
    func_12D4D8(func_003B0D60);
    t = func_11EB30(2, func_003B0F50, 0);
    *(s32 *)(D_001DA0B4_r5[0] + 0xB0) = t;
    func_11F9A8(2);
}
/* localdecomp:end func_003AFDD0 */
