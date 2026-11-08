/* func_L23_004D8188: Opus handoff (prep by Sonnet worker w1, 2026-11-08)
   Size: 38108 bytes, places: 23, file: src/levels/23_holostar_studios_clank/L23_004D8188.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: ONE function, same hero state handler as func_L01_004F5E98 (the family seed, see out/func_L01_004F5E98.c),
     switch on 0x25C4(D_001A4BE0), sltiu 0xB2, jump table jtbl_002BF000 (178 entries, default 004E15F8).
   rac2 twin: the seed's twin func_L00_002BA7D8 (not used directly). Closest family member: func_L01_004F5E98 (opcode
     similarity 0.950, 8655 of 8692 seed opcodes equal); the draft is the seed draft re-targeted by out/w1-kit/sib.py: callee names are the
     catalogue's (shared callees keep their name), level data D_L01_xxxxxxxx renamed through the aligned instructions,
     case labels moved by jump-table target.
   Mapping: hero offsets and D_001A4BE0 unchanged from the seed; no new field offsets.
   Identical / changed / added / removed vs the seed (align.py rac3 func_L01_004F5E98 rac3 func_L23_004D8188, A = seed, B = this):
       replace A 004F645C-004F6460 (   1)  B 004D874C-004D8750 (   1)
       replace A 004F7EE8-004F7EEC (   1)  B 004DA1D8-004DA1DC (   1)
       replace A 004F8DE4-004F8DEC (   2)  B 004DB0D4-004DB0DC (   2)
       replace A 004F8DF0-004F8DF4 (   1)  B 004DB0E0-004DB0E4 (   1)
       insert  A 004FC26C-004FC26C (   0)  B 004DE55C-004DE570 (   5)
       replace A 004FC314-004FC318 (   1)  B 004DE618-004DE61C (   1)
       replace A 004FC69C-004FC6B0 (   5)  B 004DE9A0-004DE9A4 (   1)
       replace A 004FC6B8-004FC6BC (   1)  B 004DE9AC-004DE9B0 (   1)
       replace A 004FC8C0-004FC8C4 (   1)  B 004DEBB4-004DEBB8 (   1)
       replace A 004FD004-004FD008 (   1)  B 004DF2F8-004DF2FC (   1)
       delete  A 004FD08C-004FD090 (   1)  B 004DF380-004DF380 (   0)
       delete  A 004FDC20-004FDC74 (  21)  B 004DFF10-004DFF10 (   0)
       insert  A 004FDFF4-004FDFF4 (   0)  B 004E0290-004E0294 (   1)
       insert  A 004FE264-004FE264 (   0)  B 004E0504-004E125C ( 854)
       replace A 004FE34C-004FE350 (   1)  B 004E1344-004E1348 (   1)
       insert  A 004FE4D4-004FE4D4 (   0)  B 004E14CC-004E14D0 (   1)
     Case-level (draft script log; relabel = same body, different state numbers; drop = seed body absent here;
       extra = states with a body here and none in the seed, NOT drafted, stubbed as `case..: break;`):
       jtbl default target 004E15F8
       ('relabel', ['0x4e'], ['0x4f'])
       ('relabel', ['0x51', '0x52', '0x53', '0x55', '0x56', '0x57', '0x58', '0x59', '0x7b'], ['0x61'])
       extra [('004E09AC', ['0x62']), ('004E0AA4', ['0x5c']), ('004E0B70', ['0x5b']), ('004E1088', ['0x5d', '0x5e']), ('004E11A8', ['0x51', '0x56', '0x59']), ('004E124C', ['0x4e', '0x57', '0x7b'])]
   Note: +854 instructions of new bodies at 004E0504-004E125C (states 0x4E/0x4F shuffle, 0x51-0x62 group), minus the seed's 004FDC20-004FDC74 (21 instr, state 0x4F in the seed).
   Draft: compiles; at its own level: 8703 diff rows, 26704 bytes vs 38108 expected, opcode-equal 5063 of 9527.
   Left for Opus: everything the seed's header lists applies (VU0 inline code, 0x1B0 vs 0x1C0 frame, undrafted
     state bodies); do this function after the seed is settled so the shared parts are fixed once. Verify the
     relabelled case numbers against the jump table (the alignment can mispair small blocks).
*/
/* func_L23_004D8188: the hero's per-frame state handler, the twin of func_L20_002CD928 (see
   src/levels/20_yeedil/L20_002CD928.c for what each flag in this unit's config/cflags.txt line is for).
   One function: one prologue, one return, a switch on the state at 0x2294. */

typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s8 c[0x2600]; s16 h[0x1300]; u16 uh[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; void *ptr[0x980]; long d[0x4C0]; u128_t q[0x260]; } Hero;
typedef struct { s32 x0[7]; s32 x1C; u8 x20[0xC0]; } LevelInfo;
typedef struct { s32 w[11]; } Rec2C;
extern char D_00138180[];
extern u8 D_001D52FC[];
extern f32 D_L20_00298970[];
extern u8 D_00138354[];
extern u8 D_001425C0[];
extern u8 D_001A30B0[];
extern char D_001A4BE0[];
extern char D_001A4CD0[];
extern char D_001A7C10[];
extern u8 D_001A7F08[];
extern u32 D_001D4C38 ;
extern s32 D_001D545C ;
extern u8 D_001A7B08[0x40] ;
extern u8 D_00142CBA ;
extern f32 D_L20_001A7DAC[][4] ;
extern s32 D_L23_001D673C ;
extern u8 D_L20_001ACEE8[];
extern s32 D_L20_001AFF00 ;
extern s32 D_L23_001DEC40 ;
extern s32 D_L23_001E01D0 ;
extern s32 D_L23_001E01D8 ;
extern u8 D_L23_001E1A40[];
extern u8 D_L23_001E1A58[];
extern u8 D_L20_001BA248[];
extern u8 D_L23_001EC800[];
extern u8 D_L23_002F5540[];
extern u8 D_L23_002F55A0[];
extern u8 D_L23_002F55A4[];
extern Rec2C D_L23_002F72D0[];
extern u8 D_L23_002F75F0[];
extern u8 D_L23_002C6740[];
extern s32 func_003D3CB0(s32, s32, s32, s32, s32);
extern s32 func_003D4D00(f32, s32, s32, s32, s32);
extern void func_0027D330(s32);
extern s32 func_0038CAD0(s32);
extern s32 func_0038CB00(s32);
extern f32 func_00282C10(f32);
extern f32 func_00282C48(f32);
extern void func_00282C88(s32);
extern void func_00282CC0(s32, s32, s32);
extern void func_00282CF0(s32, s32, s32);
extern void func_0038CE20(s32, s32, f32);
extern f32 func_0038CE68(s32, s32);
extern void func_0038CE90(s32, s32, s32);
extern f32 func_0038CEA8(s32);
extern f32 func_0038CED8(s32);
extern f32 func_0038CF00(s32, s32);
extern f32 func_0038CF38(s32, s32);
extern void func_0038CF68(s32, s32, f32);
extern void func_0038CFB8(s32, s32, f32);
extern void func_0038D000(s32, s32, s32);
extern void func_0038D028(s32, s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_00283410(s32, s32);
extern void func_00283698(s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_00283CF0(f32);
extern void func_00290010(s32, s32, s32, f32);
extern s32 func_003C24B0(s32);
extern void func_003C2F58(s32, s32, s32);
extern void func_003C7C38(s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_002A88A0(s32, s32, f32, f32, f32);
extern void func_L01_00446760(s32, s32, s32, f32, s32);
extern void func_L01_00446780(s32, s32, s32, f32, f32, f32, s32, s32, s32);
extern void func_L01_00446A70(s32, s32, s32, s32, s32, f32);
extern f32 func_003C4138(s32, f32, f32);
extern f32 func_L01_004482A0(s32, s32, f32, f32, f32, f32);
extern f32 func_L01_00448340(s32, s32, s32, f32, f32, f32);
extern f32 func_L01_004485E0(s32, f32, f32);
extern void func_L01_00448690(s32, s32, f32, f32);
extern f32 func_L01_00448728(s32, f32, s32, f32, f32, f32, s32);
extern s32 func_003C4B50(s32);
extern void func_002AC9F8(s32, f32);
extern void func_00382760(s32, f32, f32, f32);
extern void func_L01_00466F50(s32, s32, s32, f32);
extern s32 func_L01_00468678(s32, s32, f32, f32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, s32);
extern void func_L01_004C67A0(s32, s32, void *, f32, f32, f32, f32);
extern void func_L01_004E4F30(s32, s32, f32);
extern void func_L01_004E5030(f32, f32, f32, f32);
extern f32 func_L01_004E5130(s32, s32);
extern void func_L01_004E5290(f32, f32, f32);
extern void func_L01_004E5748(s32, s32);
extern void func_L01_004E5840(s32, s32);
extern void func_L01_004E5A20(s32, s32);
extern void func_L01_004E5C08(s32, s32, s32);
extern void func_L01_004E5EB8(s32, s32, s32);
extern void func_L01_004E60E8(void);
extern void func_L01_004E6390(f32, f32);
extern void func_L01_004E63A8(f32, f32);
extern void func_L01_004E63C0(f32, f32);
extern void func_L01_004E63D8(f32, f32);
extern void func_L01_004E7780(void);
extern s32 func_L01_004E8318(s32, s32, s32);
extern s32 func_L01_004E9238(s32);
extern void func_L01_004EE400(void);
extern s32 func_L01_004EE7F8(f32);
extern void func_L01_004EE850(f32, s32);
extern void func_L01_004EEBA8(void);
extern void func_L01_004EEC98(f32, f32, f32);
extern void func_L01_004EEDD0(s32, f32, f32, f32);
extern void func_L01_004EEEC0(void);
extern void func_L01_004EF128(f32, f32);
extern void func_L01_004EF178(f32);
extern void func_L01_004EF238(s32);
extern void func_L01_004EF268(void);
extern void func_L01_004F0558(f32, f32);
extern f32 func_L01_004F05F0(s32);
extern void func_L01_004F1220(f32);
extern void func_L01_004F1638(void);
extern void func_L01_004F1C88(void);
extern void func_L01_004F2880(f32, f32, f32);
extern void func_L01_004F2E68(void);
extern void func_L01_004F3BE0(void);
extern void func_L01_004F3F40(void);
extern void func_L00_002B8F00(s32, s32, s32, f32, f32, f32);
extern void func_L01_004F4730(f32);
extern void func_L00_002B9598(void);
extern f32 func_L01_004F4E20(s32, s32);
extern s32 func_L01_004F4E70(s32, s32);
extern void func_L01_004F4F18(s32, s32, s32);
extern void func_L01_004F52E0(f32, f32, f32);
extern void func_L00_002BA138(s32, s32);
extern void func_L00_002BA220(void);
extern void func_L00_002BA508(void);
extern void func_L01_00505380(void);
extern s32 func_L01_00507268(void);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L01_00510F08(s32, s32, f32);
extern void func_L01_005110E8(s32, s32, f32, f32, f32);
extern void func_L01_00511158(s32, s32, f32);
extern void func_L01_00511178(s32, s32, f32);
extern void func_L01_00511280(s32, s32, f32);
extern void func_L01_00511320(s32, s32);
extern f32 func_L01_00511408(s32);
extern f32 func_L01_005114B0(s32);
extern void func_L01_00511508(s32, s32, f32);
extern void func_L01_00511588(s32, s32, f32);
extern s32 func_L01_003F1F20(s32);
extern s32 func_L01_0040E728(s32, s32, f32);
extern s32 func_L00_0031D620(s32, s32, f32);
extern void func_L00_00322A98(s32, s32);
extern void func_L00_00322AC0(s32, s32, s32, f32);
extern void func_L01_0044E468(s32, s32);
extern void func_L01_0044FB80(s32, s32, f32, f32, f32);
extern s32 func_L00_00325FC8(s32, s32, s32, f32);
extern f32 func_L01_00460818(s32);
extern s32 func_L01_0046ADE0(s32, s32, f32);
extern s32 func_L01_00476440(s32, s32, s32, s32);
extern s32 func_L01_00476498(s32, s32, s32, s32, s32, f32);
extern s32 func_L01_00476B98(s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L00_0041E958(f32, f32, f32);
extern void func_L18_002C4000(void);
extern s32 func_L18_00428738(s32);
extern s32 func_L20_002B7A48(s32);
extern void func_L20_002C5A48(s32);
extern void func_L20_002C7588(s32);
extern void func_L20_002D7730(s32, s32);
extern s32 ref_L00_002BA7D8_00 ;
extern void func_L01_004E9090(f32 *);
void func_L23_004D8188(void) {
    Hero *hp71;
    s32 idx71;
    s32 cnt71;
    f32 temp_f20_71;
    f32 temp_f21_71;
    f32 temp_f0_71;
    f32 speed62;
    s32 lim67;
    s32 *cnt32;
    Hero *hp32;
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    f32 v50[4] __attribute__((aligned(16)));
    f32 v60[4] __attribute__((aligned(16)));
    f32 m70[16] __attribute__((aligned(16)));
    f32 vB0[4] __attribute__((aligned(16)));
    f32 vC0[4] __attribute__((aligned(16)));
    f32 vD0[4] __attribute__((aligned(16)));
    f32 stick_turn;
    f32 k03;
    s32 anim2F;
    s32 blend2F;
    f32 k005;
    void *pA60;
    void* var_v0_3_u2;
    void* var_s1_5_u2;
    f32 var_f12_16_u2;
    void* var_a1_5_u2;
    s32 var_a0_2_u2;
    void* var_s0_3_u2;
    s32 var_v0_8_u2;
    s32 var_v1_4_u2;
    void* var_a0_13_u2;
    s32 var_a0_2_u3;
    void* var_s0_3_u3;
    s32 lim;
    s32 lim2;
    s32 lim3;
    s32 sel1F;
    f32 k02;
    s32 cntA40;

    f32 spE0;
    f32 spE4;
    f32 spE8;
    f32 spEC;
    f32 spF0;
    f32 spF4;
    f32 spF8;
    s32 spFC;
    f32 sp100;
    s32 sp104;
    f32 sp108;
    f32 sp10C;
    f32 spN71;
    f32 sp114;
    s32 sp118;
    s32 sp11C;
    s32 sp120;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_16;
    f32 temp_f0_17;
    f32 temp_f0_18;
    f32 temp_f0_19;
    f32 temp_f0_20;
    f32 temp_f0_21;
    f32 temp_f0_22;
    f32 temp_f0_23;
    f32 temp_f0_24;
    f32 temp_f0_25;
    f32 temp_f0_26;
    f32 temp_f0_27;
    f32 temp_f0_28;
    f32 temp_f0_29;
    f32 temp_f0_2;
    f32 temp_f0_30;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_3;
    f32 temp_f12_4;
    f32 temp_f12_5;
    f32 temp_f12_6;
    f32 temp_f12_7;
    f32 temp_f1;
    f32 temp_f1_10;
    f32 temp_f1_11;
    f32 temp_f1_12;
    f32 temp_f1_13;
    f32 temp_f1_14;
    f32 temp_f1_15;
    f32 temp_f1_16;
    f32 temp_f1_17;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f1_9;
    f32 temp_f20;
    f32 temp_f20_10;
    f32 temp_f20_11;
    f32 temp_f20_12;
    f32 temp_f20_13;
    f32 temp_f20_14;
    f32 temp_f20_15;
    f32 temp_f20_16;
    f32 temp_f20_17;
    f32 temp_f20_18;
    f32 temp_f20_19;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f24;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f0_10;
    f32 var_f0_11;
    f32 var_f0_12;
    f32 var_f0_13;
    f32 var_f0_14;
    f32 var_f0_15;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f0_5;
    f32 var_f0_6;
    f32 var_f0_7;
    f32 var_f0_8;
    f32 var_f0_9;
    f32 var_f12;
    f32 var_f12_10;
    f32 var_f12_11;
    f32 var_f12_13;
    f32 var_f12_14;
    f32 var_f12_15;
    f32 var_f12_16;
    f32 var_f12_17;
    f32 var_f12_18;
    f32 var_f12_19;
    f32 var_f12_20;
    f32 var_f12_21;
    f32 var_f12_22;
    f32 var_f12_4;
    f32 var_f12_5;
    f32 var_f12_6;
    f32 var_f12_7;
    f32 var_f12_8;
    f32 var_f12_9;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f1_3;
    f32 var_f1_4;
    f32 var_f1_5;
    f32 var_f20;
    f32 var_f20_10;
    f32 var_f20_11;
    f32 var_f20_12;
    f32 var_f20_13;
    f32 var_f20_2;
    f32 var_f20_3;
    f32 var_f20_4;
    f32 var_f20_5;
    f32 var_f20_6;
    f32 var_f20_7;
    f32 var_f20_8;
    f32 var_f20_9;
    f32 var_f21;
    f32 var_f21_2;
    f32 var_f21_3;
    f32 var_f21_4;
    f32 var_f21_5;
    f32 var_f21_6;
    f32 var_f21_7;
    f32 var_f22;
    f32 var_f22_2;
    f32 var_f23;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f2_4;
    f32 var_f2_5;
    s16 temp_a2_5;
    s32 temp_v0_4;
    s16 temp_v0_8;
    s32 temp_v1_10;
    s32 temp_v1_9;
    s32 temp_a0_21;
    s32 temp_a0_3;
    s32 temp_a0_5;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_a1_7;
    s32 temp_a1_8;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_s0_5;
    s32 temp_s0_9;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_16;
    s32 temp_v0_17;
    s32 temp_v0_2;
    s32 temp_v1_12;
    s32 temp_v1_14;
    s32 temp_v1_16;
    s32 temp_v1_18;
    s32 temp_v1_20;
    s32 temp_v1_21;
    s32 temp_v1_22;
    s32 temp_v1_23;
    s32 temp_v1_24;
    s32 temp_v1_26;
    s32 temp_v1_34;
    s32 temp_v1_35;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_a0_10;
    s32 var_a0_11;
    s32 var_a0_12;
    s32 var_a0_2;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_8;
    s32 var_a0_9;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32* var_s1_4;
    s32* var_s1_6;
    u16 temp_v0_3;
    u16 temp_v1_11;
    u16 temp_v1_2;
    u32 temp_a0;
    u32 temp_v1;
    u32 temp_v1_13;
    u32 temp_v1_27;
    u32 temp_v1_28;
    u32 temp_v1_29;
    u32 temp_v1_30;
    u32 temp_v1_31;
    u32 temp_v1_33;
    u32 temp_v1_36;
    u32 temp_v1_3;
    u32 var_a1_3;
    u8 temp_a0_14;
    u8 temp_a0_2;
    u8 temp_v1_25;
    u8 var_a0_6;
    void* temp_a0_10;
    void* temp_a0_11;
    void* temp_a0_12;
    void* temp_a0_13;
    void* temp_a0_15;
    void* temp_a0_16;
    void* temp_a0_17;
    void* temp_a0_4;
    void* temp_a0_6;
    void* temp_a1;
    void* temp_a1_2;
    void* temp_a1_6;
    void* temp_fp;
    void* hero7C;
    f32 turn24;
    f32 ang82;
    f32 min2B;
    void* heroA30;
    void* temp_s0;
    void* temp_s0_2;
    void* temp_s0_3;
    void* temp_s0_4;
    void* temp_s0_6;
    void* temp_s0_7;
    void* temp_s0_8;
    void* temp_s1;
    void* temp_s1_2;
    void* temp_s1_3;
    void* temp_s1_4;
    void* temp_s1_5;
    void* temp_s1_6;
    void* temp_s1_7;
    void* temp_s1_8;
    void* temp_s2;
    void* temp_s2_2;
    void* temp_s2_3;
    void* temp_s2_4;
    void* temp_s2_5;
    void* temp_s4;
    void* temp_s4_2;
    void* temp_s5;
    void* temp_v0_10;
    void* temp_v0_5;
    void* temp_v0_6;
    void* temp_v0_7;
    void* temp_v0_9;
    void* temp_v1_15;
    void* temp_v1_17;
    void* temp_v1_32;
    void* temp_v1_37;
    void* temp_v1_38;
    void* temp_v1_39;
    void* var_a0_13;
    void* var_a0_7;
    void* var_a1_5;
    void* var_s0_3;
    void* var_s1_5;
    void* var_v0_3;

    sp118 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
    temp_fp = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
    sp11C = (s32) (*(u8*)((s8 *)(temp_fp) + 0x43));
    switch (((Hero *)D_001A4BE0)->u[0x25C4/4]) {                              /* switch 1 */
    case 0x0:                                      /* switch 1 */
    case 0x1:                                      /* switch 1 */
    case 0x3:                                      /* switch 1 */
    case 0x4:                                      /* switch 1 */
    case 0x1C:                                      /* switch 1 */
    case 0x1D:                                      /* switch 1 */
    case 0x1E:                                      /* switch 1 */
    case 0x39:                                      /* switch 1 */
    case 0x72:                                      /* switch 1 */
    case 0x74:                                      /* switch 1 */
    case 0x82:                                      /* switch 1 */
        if (((Hero *)D_001A4BE0)->b[0x25EA] != 0) {
            func_L01_004E5748(0xF, 0x1E);
        }
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_L01_004F0558(0.7f, 0.0f);
        } else {
            func_L01_004F0558(0.5f, 0.033333335f);
        }
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L01_004EE850(1.0f, 0);
        temp_v1 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((temp_v1 == 1) || (temp_v1 == 0x1D)) {
            if (((Hero *)D_001A4BE0)->b[0x25E5] != 0) {
                (*(u128_t*)v0) = 0;
                v0[0] = 1.0f;
                func_0038D000((s32) (((void*)D_001A4BE0) + 0x190), (s32)((u128_t*)v0), (s32)&D_L23_001E1A58[0x218]);
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_L23_001E1A58)->f[0x0];
                func_L01_004EEDD0(0, 1.0f, 0.0f, 2.9088826f);
                if ((((Hero *)D_001A4BE0)->b[0x25EC] != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] == 0x78)) {
                    if (((Hero *)D_001A7C10)->uh[0xD8/2] < 0xFFFF) {
                        ((Hero *)D_001A7C10)->uh[0xD8/2]++;
                    }
                    if (D_001D4C38 > ((Hero *)D_001A7C10)->u[0xDC/4]) {
                        ((Hero *)D_001A7C10)->u[0xDC/4] = D_001D4C38;
                    }
                    ((Hero *)D_001A7C10)->u[0xE0/4] = ((Hero *)D_001A7C10)->u[0xE0/4] | (1 << D_001D545C) | 0x80000000;
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 3) {
            if (func_L01_00507268() != 0) {
                break;
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
            if ((((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) || (temp_a0_2 = (*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)), (temp_a0_2 == 0xE)) || (temp_a0_2 == 0xF)) {
                if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 4) {
                    func_L01_004EEDD0(0, 0.002f, 0.07f, 0.1163553f);
                }
                if (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A4/4]) > 0.0058177654f) {
                    temp_a0_3 = ((Hero *)D_001A4BE0)->f[0x1A4/4] < 0.0f;
                    temp_a0_3 += 0xE;
                    if ((*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) != temp_a0_3) {
                        func_L01_0050FB40(temp_a0_3, 0, 5.0f);
                    }
                    temp_f0 = func_00282C48(((Hero *)D_001A4BE0)->f[0x1A4/4]) * 18.093401f;
                    ((Hero *)D_001A4BE0)->f[0xC00/4] = temp_f0;
                    if (temp_f0 < 0.55f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.55f;
                    }
                    if (((Hero *)D_001A4BE0)->f[0xC00/4] > 2.5f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 2.5f;
                    }
                } else if (((Hero *)D_001A4BE0)->f[0x1A4/4] == 0.0f) {
                    if ((*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) != 0xD) {
                        func_L01_0050FB40(0xD, 0, 7.0f);
                    }
                }
            }
        }
            temp_v1_3 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            if (temp_v1_3 == 3) {
                var_f12 = ((Hero *)D_001A4BE0)->f[0x17C/4] + 1.0f;
                if (var_f12 > 1.0f) {
                    var_f12 = 1.0f;
                }
                temp_a0_4 = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
                var_f20 = var_f12 * 0.0075000003f;
                ((Hero *)D_001A4BE0)->f[0x282C/4] = var_f20;
                if ((*(u8*)((s8 *)(temp_a0_4) + 0x42)) == (*(u8*)((s8 *)(temp_a0_4) + 0x43))) {
                    var_f1 = ((Hero *)D_001A4BE0)->f[0x174/4] / var_f20;
                    if ((var_f1 > 5.0f) && ((f32) (*(u8*)((s8 *)(temp_a0_4) + 0x41)) < 5.5f)) {
                        func_L01_004E5030(13.0f, var_f1, 0.5f, -1.0f);
                        if (((Hero *)D_001A4BE0)->f[0xC00/4] > 1.1f) {
                            ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.1f;
                        }
                    } else if ((f32) (*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x41)) > 6.5f) {
                        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.0f;
                    }
                }
            } else if (temp_v1_3 == 4) {
                var_f20 = 0.0075000003f;
                if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
                    var_f20 = 0.00047222225f;
                }
            } else {
                var_f20 = 0.004916667f;
            }
            func_L01_004EF128(0.0f, var_f20);
            func_00282C88((s32)(D_001A4BE0 + 0xF0));
            func_L01_004F4730(var_f20);
            if ((((Hero *)D_001A4BE0)->b[0x1479] != 0) && (D_001A7B08[3] != 0)) {
                var_a0_2 = (s32)(D_001A4BE0 + 0xF0);
                if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.2f) {
                    func_L01_00510F08(var_a0_2, var_a0_2 + 0x30, 0.0061111115f);
                } else {
                    func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
                    if (((Hero *)D_001A4BE0)->i[0x35C/4] != 0) {
                        qcopy(&((Hero *)D_001A4BE0)->q[0x80/16], &((Hero *)D_001A4BE0)->q[0x0/16]);
                        ((Hero *)D_001A4BE0)->f[0x33C/4] = 0.0f;
                        ((Hero *)D_001A4BE0)->h[0x36E/2] = 0;
                    }
                }
            } else {
                func_L20_002C7588(0);
                if (((Hero *)D_001A4BE0)->h[0x36E/2] == 0) {
                    func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.015000001f);
                } else {
                    func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x130, 0.0069444445f);
                    func_L01_004EF268();
                }
            }
        break;
    case 0x81:                                      /* switch 1 */
        hero7C = (void*)D_001A4BE0;
        if (((Hero *)hero7C)->i[0x734/4] == 0) {
            temp_v0 = func_003C24B0(0x52A);
            ((Hero *)hero7C)->i[0x734/4] = temp_v0;
            if (((Hero *)hero7C)->i[0x734/4] != 0) {
            qcopy((u8 *)temp_v0 + 0x10, &((Hero *)hero7C)->q[0x80/16]);
            qcopy((u8 *)temp_v0 + 0xF0, &((Hero *)hero7C)->q[0x90/16]);
            (*(s16*)((s8 *)(temp_v0) + 0x32)) = 0x40;
            (*(s8*)((s8 *)(((Hero *)hero7C)->i[0x734/4]) + 0x31)) = 1;
            (*(s8*)((s8 *)(((Hero *)hero7C)->i[0x734/4]) + 0x30)) = 0;
            (*(u8*)((s8 *)(((Hero *)hero7C)->i[0x734/4]) + 0x23)) = 0U;
            temp_v1_4 = ((Hero *)hero7C)->i[0x734/4];
            (*(u16*)((s8 *)(temp_v1_4) + 0x34)) = (u16) ((*(u16*)((s8 *)(temp_v1_4) + 0x34)) | 0x800);
            func_003C7C38(((Hero *)hero7C)->i[0x734/4]);
            func_003A52A0(0, 0, ((Hero *)hero7C)->i[0x734/4]);
            }
        }
        if (((Hero *)hero7C)->i[0x734/4] != 0) {
        (*(u8*)((s8 *)(((Hero *)hero7C)->i[0x734/4]) + 0x23)) += func_00283CF0(5.0f);
        temp_v1_6 = ((Hero *)hero7C)->i[0x734/4];
        if ((u8) (*(u8*)((s8 *)(temp_v1_6) + 0x23)) >= 0x81U) {
            (*(u8*)((s8 *)(temp_v1_6) + 0x23)) = 0x80U;
        }
        temp_a0_5 = ((Hero *)hero7C)->i[0x734/4];
        temp_a1 = ((Hero *)hero7C)->ptr[0x25C0/4];
        *(u128_t *)((u8 *)temp_a0_5 + 0x10) = *(u128_t *)((u8 *)temp_a1 + 0x10);
        *(u128_t *)((u8 *)temp_a0_5 + 0xF0) = *(u128_t *)((u8 *)temp_a1 + 0xF0);
        func_003C7C38(temp_a0_5);
        }
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_L01_0040E728((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), func_0038CED8((s32)(D_001A4BE0 + 0xF0)) * 0.92f);
        func_L01_00505380();
        break;
    case 0x50:                                      /* rac3-only state 0x50 body at 004F64FC-004F663C: TODO not drafted */
        break;
    case 0x32:                                      /* switch 1 */
    case 0x33:                                      /* switch 1 */
    case 0x34:                                      /* switch 1 */
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x47) {
                (*(u16*)&D_001A7F08) = 0xFFFF;
            }
            func_L01_004F4F18(5, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xF);
            func_L01_003F1F20(0x16);
        } else {
            temp_a2 = ((Hero *)D_001A4BE0)->i[0x27A0/4];
            if (temp_a2 != -1) {
                temp_a0_6 = (temp_a2 * 0x70) + (s32)D_001A30B0;
                if ((*(s32*)((s8 *)(temp_a0_6) + 0x88)) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) {
                    if ((*(u8*)((s8 *)(temp_a0_6) + 0x74)) != 0) {
                        func_003A4F28(temp_a2);
                    }
                }
            }
            ((Hero *)D_001A4BE0)->i[0x27A0/4] = -1;
        }
        if (((Hero *)D_001A4BE0)->h[0x9CA/2] != 0) {
            func_0038CB00((s32) (((void*)D_001A4BE0) + 0x9CA));
            temp_a0_7 = (s32) ((u16) ((Hero *)D_001A4BE0)->h[0x9CA/2] << 0x10) >> 0x12;
            func_L01_004E5C08((temp_a0_7 >= 9) ? 8 : temp_a0_7, 0, 0);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x32) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0)) {
            temp_f1_2 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if (temp_f1_2 > 0.0f) {
                if (temp_f1_2 < 10.0f) {
                    func_L01_004E5C08(4, 1, 0);
                }
            }
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x33) {
            if (((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) {
                temp_v1_7 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                if (temp_v1_7 < 0xF) {
                    func_L01_004E5C08(((s32) (0x14 - temp_v1_7) / 3) + 1, 1, 0);
                }
            }
        }
        temp_v1_8 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
        if (temp_v1_8 == 1) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == temp_v1_8) {
                func_L01_004E5EB8(3, 0x10, 0);
                if (D_L23_001E01D0 != 0) {
                    func_L01_004C67A0(D_L23_001E01D0, D_L23_001E01D8, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, -0.3f);
                }
                ((Hero *)D_001A4BE0)->h[0x9CA/2] = 0x46;
            }
            temp_v0_2 = ((Hero *)D_001A4BE0)->i[0x9A0/4] + 1;
            ((Hero *)D_001A4BE0)->i[0x9A0/4] = temp_v0_2;
            if (temp_v0_2 >= 0x29) {
                ((Hero *)D_001A4BE0)->i[0x25C8/4] = 0;
            }
        }
        stick_turn = 0.011635531f;
        stick_turn += (((Hero *)D_00138180)->f[0x12C/4] > ((Hero *)D_00138180)->f[0x128/4] ? ((Hero *)D_00138180)->f[0x12C/4] : ((Hero *)D_00138180)->f[0x128/4]) * 0.008726647f;
        var_f12_4 = 0.0f;
        k02 = 0.2f;
        if ((((((Hero *)D_00138180)->d[0x1A0/8] & 0xC0) == 0x80)) || (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1)) {
            var_f12_6 = ((Hero *)D_00138180)->f[0x12C/4] * 1.5f;
            if (var_f12_6 > 1.0f) {
                var_f12_6 = 1.0f;
            }
            if (var_f12_6 < k02) {
                var_f12_6 = k02;
            }
            if (((Hero *)D_00138180)->i[0x1DC/4] != 0x79) {
                temp_v1_9 = ((Hero *)D_001A4BE0)->uh[0x9C2/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9C0/2] = 0U;
                var_f12_6 = ((f32) (s16) temp_v1_9 * 0.025f) + 0.5f;
                ((Hero *)D_001A4BE0)->uh[0x9C2/2] = (u16) temp_v1_9;
                if (var_f12_6 > 1.0f) {
                    var_f12_6 = 1.0f;
                }
            }
            if ((((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) && (var_f12_6 < 0.35f)) {
                var_f12_6 = 0.35f;
            }
            var_f12_4 = var_f12_6 * 1.361357f;
        } else if ((s32) ((Hero *)D_00138180)->d[0x1A0/8] & 0x40) {
            var_f12_5 = ((Hero *)D_00138180)->f[0x128/4] * 1.5f;
            if (var_f12_5 > 1.0f) {
                var_f12_5 = 1.0f;
            }
            if (var_f12_5 < k02) {
                var_f12_5 = k02;
            }
            if (((Hero *)D_00138180)->i[0x1DC/4] != 0x79) {
                cntA40 = ((Hero *)D_001A4BE0)->uh[0x9C0/2] + 1;
                ((Hero *)D_001A4BE0)->uh[0x9C2/2] = 0U;
                ((Hero *)D_001A4BE0)->h[0x9C0/2] = cntA40;
                var_f12_5 = ((f32) (s16) cntA40 * 0.025f) + 0.5f;
                if (var_f12_5 > 1.0f) {
                    var_f12_5 = 1.0f;
                }
            }
            if ((f32) ((Hero *)D_001A4BE0)->i[0x2840/4] < 1500.0f) {
                var_f12_5 = 1.0f;
            }
            var_f12_4 = var_f12_5 * -1.361357f;
        } else {
            ((Hero *)D_001A4BE0)->uh[0x9C0/2] = 0U;
            ((Hero *)D_001A4BE0)->uh[0x9C2/2] = 0U;
        }
        if ((s32) ((Hero *)D_00138180)->d[0x1A0/8] & 0x40) {
            ((Hero *)D_001A4BE0)->uh[0x9CE/2] = (u16) (((Hero *)D_001A4BE0)->uh[0x9CE/2] + 1);
            if (((Hero *)D_00138180)->f[0x128/4] > 0.75f) {
                temp_v1_10 = ((Hero *)D_001A4BE0)->uh[0x9CC/2] + 1;
                ((Hero *)D_001A4BE0)->h[0x9CC/2] = temp_v1_10;
                if ((s16) temp_v1_10 >= 0x5B) {
                    temp_v1_11 = ((Hero *)D_001A7C10)->uh[0x84/2];
                    if (temp_v1_11 <= 0xFFFEU) {
                        ((Hero *)D_001A7C10)->uh[0x84/2] = (u16) (temp_v1_11 + 1);
                    }
                }
                temp_v1_12 = (*(s32*)&D_001D4C38);
                if ((u32) ((Hero *)D_001A7C10)->u[0x88/4] < (u32) temp_v1_12) {
                    ((Hero *)D_001A7C10)->u[0x88/4] = (u32) temp_v1_12;
                }
                ((Hero *)D_001A7C10)->i[0x8C/4] = (s32) (((Hero *)D_001A7C10)->i[0x8C/4] | (1 << (*(s32*)&D_001D545C)) | 0x80000000);
            } else {
                ((Hero *)D_001A4BE0)->uh[0x9CC/2] = 0U;
            }
        } else {
            ((Hero *)D_001A4BE0)->uh[0x9CE/2] = 0U;
            ((Hero *)D_001A4BE0)->uh[0x9CC/2] = 0U;
        }
        if (((Hero *)D_00138180)->i[0x1A4/4] & 0x40) {
            hp32 = (Hero *)D_001A4BE0;
            if ((D_L23_001DEC40 - hp32->i[0xA54/4]) < 0x46) {
                hp32->i[0xA50/4]++;
            }
            hp32->i[0xA54/4] = D_L23_001DEC40;
        }
        if ((s16) ((Hero *)D_001A4BE0)->uh[0x9CE/2] >= 0x47) {
            ((Hero *)D_001A4BE0)->i[0x9D0/4] = 0;
        }
        if ((s32) ((Hero *)D_00138180)->d[0x1A0/8] & 0x80) {
            ((Hero *)D_001A4BE0)->i[0x9D0/4] = 0;
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x33) {
            var_f12_4 = 0.0f;
        }
        temp_f20 = ((Hero *)D_001A4BE0)->f[0x94/4];
        func_L01_00448728((s32) (((void*)D_001A4BE0) + 0x94), var_f12_4, (s32) (((void*)D_001A4BE0) + 0x9A8), 0.015f, 0.2f, stick_turn, 0);
        temp_f22 = func_0038DB00(((Hero *)D_001A4BE0)->f[0x94/4], temp_f20);
        func_L01_004EE850(1.0f, 0);
        func_L01_004EEDD0(0, 0.007f, 0.08f, 0.087266475f);
        ((Hero *)D_001A4BE0)->f[0x9AC/4] = (f32) ((Hero *)D_001A4BE0)->f[0x1A4/4];
        func_0038CAD0((s32) (((void*)D_001A4BE0) + 0x9B4));
        if (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.10000001f;
        } else if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if ((s32) ((Hero *)D_00138180)->d[0x1A0/8] & 0xA) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.116666675f;
            } else {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.04666667f;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.050000004f;
        }
        var_f2 = ((Hero *)D_001A4BE0)->f[0x2838/4];
        if (((s32) ((Hero *)D_00138180)->d[0x1A0/8] & 0xC0) || (((Hero *)D_001A4BE0)->i[0x25C8/4] == 1)) {
            if (var_f2 < 1.0f) {
                var_f2 = 1.0f;
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.15f) {
            var_f0_2 = 0.35f;
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
                var_f0_2 = 0.4f;
            }
            if (var_f2 < var_f0_2) {
                var_f2 = var_f0_2;
            }
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] != 0x34) || !((s32) ((Hero *)D_00138180)->d[0x1A0/8] & 0xA)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = (f32) (((Hero *)D_001A4BE0)->f[0x1B0/4] * var_f2);
        }
        if (func_0038CAD0((s32)(D_001A4BE0 + 0xA30)) != 0) {
            heroA30 = (void*)D_001A4BE0;
            func_003C2F58((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 4, (s32)((u128_t*)v0));
            (*(u128_t*)v20) = 0;
            v20[0] = 0.4f;
            func_0038D000((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
            func_00282CC0((s32)((u128_t*)v0), (s32)((u128_t*)v0), (s32) ((u128_t*)v20));
            qcopy(v10, &((Hero *)D_001A4BE0)->q[0x110/16]);
            func_0038CF68((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), 0.025000002f);
            func_00282CC0((s32) ((u128_t*)v10), (s32) ((u128_t*)v10), (s32) ((u128_t*)v20));
            v10[2] += 0.033333335f;
            func_L01_00468678((s32)((u128_t*)v0), (s32) ((u128_t*)v10), 25200.0f, -1.0f);
            if ((f32) func_00382468(0x64) < 40.0f) {
                var_a0_4 = 4;
                var_a1_2 = 0xB;
            } else {
                var_a0_4 = 0x28;
                var_a1_2 = 0x5A;
            }
            ((Hero *)heroA30)->i[0x9B0/4] = func_00382498(var_a0_4, var_a1_2);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
            if (func_0038CB00((s32) (((void*)D_001A4BE0) + 0x9B8)) != 0) {
                temp_s4 = ((Hero *)D_001A4BE0)->ptr[0x12F0/4];
                if (temp_s4 != 0) {
                    if ((*(s16*)((s8 *)(temp_s4) + 0xAA)) == 0x261) {
                        for (var_s1 = 0; var_s1 < 4; var_s1++) {
                            func_003C2F58((s32) temp_s4, var_s1 % 2, (s32)((u128_t*)v0));
                            (*(u128_t*)v20) = 0;
                            v20[0] = -0.15f;
                            func_0038D000((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), (s32) (((Hero *)D_001A4BE0)->ptr[0x25C0/4] + 0xC0));
                            func_00282CC0((s32)((u128_t*)v0), (s32)((u128_t*)v0), (s32) ((u128_t*)v20));
                            v0[0] += func_003824E0(0.0f, 0.03f);
                            v0[1] += func_003824E0(0.0f, 0.03f);
                            v0[2] += func_003824E0(0.0f, 0.03f);
                            qcopy(v10, &((Hero *)D_001A4BE0)->q[0x110/16]);
                            func_L01_0044FB80((s32) ((u128_t*)v10), (s32) ((u128_t*)v10), -0.012500001f, ((Hero *)D_001A4BE0)->f[0x98/4], ((Hero *)D_001A4BE0)->f[0x94/4]);
                            ((Hero *)D_001A4BE0)->h[0x9B8/2] = func_00283CF0((0.116666675f - ((Hero *)D_001A4BE0)->f[0x1B4/4]) * 42.85714f);
                            func_L01_00468678((s32)((u128_t*)v0), (s32) ((u128_t*)v10), func_003824E0(6300.0f, 9450.0f), -1.0f);
                        }
                    }
                }
            }
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x34) {
                func_L01_004EF128(0.003611111f, 0.0022222223f);
            } else {
                goto block_198;
            }
        } else {
block_198:
            func_L01_004EF128(0.0019444445f, 0.0011111111f);
        }
        temp_f21 = func_0038DAB8(-((Hero *)D_001A4BE0)->f[0x94/4], 0.0f);
        temp_v1_13 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if (temp_v1_13 == 0x34) {
            func_00382760((s32) (((void*)D_001A4BE0) + 0xF0), ((Hero *)D_001A4BE0)->f[0x1B4/4], ((Hero *)D_001A4BE0)->f[0x98/4], temp_f21);
        } else if (temp_v1_13 == 0x32) {
            var_f12_7 = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_L01_004E5130((s32)D_L23_002F75F0, 0x1E) * 5.0f;
            if ((((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xF) && (var_f12_7 < 0.075f)) {
                var_f12_7 = 0.075f;
            }
            func_00382760((s32)(D_001A4BE0 + 0xF0), var_f12_7, ((Hero *)D_001A4BE0)->f[0x98/4], temp_f21);
        } else if (temp_v1_13 == 0x33) {
            spE0 = func_0038CEA8((s32) (((void*)D_001A4BE0) + 0x160));
            if (((Hero *)D_001A4BE0)->i[0x25D0/4] == 0x34) {
                func_003C4138((s32) &spE0, 0.0f, 0.0022222223f);
            } else {
                func_003C4138((s32) &spE0, 0.0f, 0.0011111111f);
            }
            func_0038CF68((s32)(D_001A4BE0 + 0x160), (s32)(D_001A4BE0 + 0x160), spE0);
            qcopy(&((Hero *)D_001A4BE0)->q[0xF0/16], &((Hero *)D_001A4BE0)->q[0x160/16]);
        }
        func_L20_002C7588(0);
        temp_f21_2 = ((Hero *)D_001A4BE0)->f[0x9AC/4] * func_0038D098(temp_f21) * -7.0f;
        func_L01_00448728((s32) (((void*)D_001A4BE0) + 0x90), temp_f21_2, (s32) (((void*)D_001A4BE0) + 0x9A4), 0.007f, 0.17f, 0.020362178f, 0);
        func_L01_004E63A8(0.009f, 0.22f);
        func_L01_004E63C0(0.04f, 0.2f);
        func_L01_004E63D8(0.02f, 0.2f);
        temp_f2 = temp_f22 * 47.0f;
        ((Hero *)D_L23_002F5540)->f[0x114/4] = temp_f2;
        ((Hero *)D_L23_002F5540)->f[0x118/4] = (f32) (temp_f21_2 * 1.5f);
        ((Hero *)D_L23_002F5540)->f[0x110/4] = (f32) (temp_f21_2 * 1.4f);
        if (temp_f2 > 0.8726647f) {
            ((Hero *)D_L23_002F5540)->f[0x114/4] = 0.8726647f;
        } else if (temp_f2 < -0.8726647f) {
            ((Hero *)D_L23_002F5540)->f[0x114/4] = -0.8726647f;
        }
        temp_f1_3 = temp_f22 * 40.0f;
        temp_f0_2 = temp_f21_2 * 1.1f;
        ((Hero *)D_L23_002F5540)->f[0x364/4] = 0.03f;
        ((Hero *)D_L23_002F5540)->f[0x368/4] = 0.22f;
        ((Hero *)D_L23_002F5540)->f[0x324/4] = temp_f1_3;
        ((Hero *)D_L23_002F5540)->f[0x328/4] = temp_f0_2;
        ((Hero *)D_L23_002F5540)->f[0x414/4] = 0.03f;
        ((Hero *)D_L23_002F5540)->f[0x418/4] = 0.22f;
        ((Hero *)D_L23_002F5540)->f[0x3D4/4] = temp_f1_3;
        ((Hero *)D_L23_002F5540)->f[0x3D8/4] = temp_f0_2;
        break;
    case 0x78:                                      /* switch 1 */
        temp_a0_8 = 0xA - ((s32) ((Hero *)D_001A4BE0)->i[0x1B8/4] / 3);
        temp_s1 = ((void*)D_001A4BE0) + 0xF0;
        func_L01_004E5C08((temp_a0_8 >= 9) ? 8 : temp_a0_8, 0, 0);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_L01_0040E728((s32) temp_s1, (s32) temp_s1, func_0038CED8((s32) temp_s1) * 0.92f);
        func_L20_002C7588(0);
        break;
    case 0x77:                                      /* switch 1 */
        func_L01_004E5748(0xF, 0x1E);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
        func_L01_0040E728((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), func_0038CED8((s32)(D_001A4BE0 + 0xF0)) * 0.92f);
        func_L20_002C7588(0);
        func_L01_00505380();
        break;
    case 0x6C:                                      /* switch 1 */
    case 0x84:                                      /* switch 1 */
        spE4 = func_0038CEA8((s32)(D_001A4BE0 + 0x160));
        func_003C4138((s32) &spE4, 0.0f, 0.0011111111f);
        func_0038CF68((s32)(D_001A4BE0 + 0x160), (s32)(D_001A4BE0 + 0x160), spE4);
        qcopy(&((Hero *)D_001A4BE0)->q[0xF0/16], &((Hero *)D_001A4BE0)->q[0x160/16]);
        if (func_0038CAD0((s32) (((void*)(D_001A4BE0 + 0x160)) + 0x8D0)) == 2) {
            temp_s2 = ((void*)(D_001A4BE0 + 0x160)) - 0x160;
            func_003C2F58((*(s32*)((s8 *)(temp_s2) + 0x2290)), 4, (s32)((u128_t*)v0));
            (*(u128_t*)v20) = 0;
            v20[0] = 0.4f;
            func_0038D000((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), (*(s32*)((s8 *)(temp_s2) + 0x2290)) + 0xC0);
            func_00282CC0((s32)((u128_t*)v0), (s32)((u128_t*)v0), (s32) ((u128_t*)v20));
            qcopy(v10, &((Hero *)D_001A4BE0)->q[0x110/16]);
            func_0038CF68((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), 0.025000002f);
            func_00282CC0((s32) ((u128_t*)v10), (s32) ((u128_t*)v10), (s32) ((u128_t*)v20));
            v10[2] += 0.033333335f;
            func_L01_00468678((s32)((u128_t*)v0), (s32) ((u128_t*)v10), 25200.0f, -1.0f);
            temp_v1_14 = (*(s32*)((s8 *)(temp_s2) + 0x1B8));
            if (temp_v1_14 < 0x28) {
                lim67 = 5;
                var_v0_2 = func_00382498(2, lim67) + ((s32) (*(s32*)((s8 *)(temp_s2) + 0x1B8)) / lim67);
                goto block_224;
            }
            if (temp_v1_14 >= 0x47) {
                var_v0_2 = func_00382498(0xA, 0x14);
block_224:
                (*(s32*)((s8 *)(temp_s2) + 0xA30)) = var_v0_2;
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x9BC/4] > 0.0f) {
            ((Hero *)D_001A4BE0)->f[0x9BC/4] = 0.0f;
        }
        func_003C4138((s32) (((void*)D_001A4BE0) + 0x9BC), -0.025000002f, 0.00041666668f);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = (f32) ((Hero *)D_001A4BE0)->f[0x9BC/4];
        break;
    case 0x35:                                      /* switch 1 */
    case 0x36:                                      /* switch 1 */
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x36) {
            func_L01_004E5748(0xF, 0x1E);
        }
        if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.025000002f) {
            func_L01_004E5A20(4, 0xC);
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) && (((Hero *)D_001A4BE0)->f[0x174/4] > 0.016666668f)) {
            func_L01_004E5840(0, 1);
        }
        if (((Hero *)D_001A4BE0)->h[0x9CA/2] != 0) {
            ((Hero *)D_001A4BE0)->h[0x9CA/2] -= 1;
            temp_a0_9 = ((Hero *)D_001A4BE0)->h[0x9CA/2] >> 3;
            func_L01_004E5C08((temp_a0_9 >= 7) ? 6 : temp_a0_9, 0, 0);
        }
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.6f;
        func_L01_004EE850(0.050000004f, 0);
        if ((((Hero *)D_00138180)->i[0x1D4/4] == 0) && (((Hero *)D_001A4BE0)->f[0x1B0/4] < 0.025000002f)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.025000002f;
        }
        func_L01_004EEDD0(0, 0.007f, 0.08f, 0.087266475f);
        func_0038CAD0((s32)(D_001A4BE0 + 0x798));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) {
            if ((((Hero *)D_00138180)->i[0x1D4/4] != 0) && (((Hero *)D_001A4BE0)->i[0x728/4] != 0)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.050000004f;
            }
            if (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 0.78539824f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            }
            func_L01_004EF128(0.0011111111f, 0.0013888889f);
            temp_f20_2 = ((Hero *)D_001A4BE0)->f[0x1B4/4] * func_L01_004E5130((s32)D_L23_002F75F0, 0x1E) * 5.5f;
            ((Hero *)D_001A4BE0)->f[0xF0/4] = (f32) (func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * temp_f20_2);
            temp_f0_3 = func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * temp_f20_2;
            ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
            ((Hero *)D_001A4BE0)->f[0xF4/4] = temp_f0_3;
        } else {
            ((Hero *)D_001A4BE0)->f[0x1B4/4] = 0.0f;
            func_00282C88((s32)(D_001A4BE0 + 0xF0));
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x35) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0)) {
            temp_f1_4 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((temp_f1_4 > 0.0f) && (temp_f1_4 < 10.0f)) {
                func_L01_004E5C08(4, 1, 0);
            }
        }
        func_L01_004F4730(0.0011666666f);
        func_L20_002C7588(0);
        func_L01_00505380();
        break;
    /* rac2 states 0x85: no code in rac3 (dropped) */
    /* rac2 states 0x86: no code in rac3 (dropped) */
    case 0x2F:                                      /* switch 1 */
        anim2F = -1;
        blend2F = 0;
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_L01_004F0558(0.7f, 0.0f);
        } else {
            func_L01_004F0558(0.5f, 0.033333335f);
        }
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L01_004EE850(1.0f, 0);
        func_L01_004EF128(0.004916667f, 0.004916667f);
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.004916667f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32) (((void*)(D_001A4BE0 + 0xF0)) + 0x20), 0.0069444445f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
        }
        if ((anim2F != -1) && ((*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x42)) != 0x36)) {
            func_L01_0050FB40(anim2F, 0, (f32) blend2F);
        } else {
            temp_v1_15 = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
            if (((*(u8*)((s8 *)(temp_v1_15) + 0x60)) & 2) && ((*(u8*)((s8 *)(temp_v1_15) + 0x42)) == 0x36)) {
                func_L01_0050FB40(func_L20_002B7A48(0), 0, 5.0f);
            }
        }
        break;
    case 0x8F:                                      /* switch 1 */
    case 0x90:                                      /* switch 1 */
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.004916667f, 0.004916667f);
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.004916667f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32) (((void*)D_001A4BE0) + 0x120), 0.0061111115f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
        }
        var_v0_3 = ((Hero *)D_001A4BE0)->ptr[0xA90/4];
        if (var_v0_3 != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160((*(f32*)((s8 *)(var_v0_3) + 0x10)) - (*(f32*)((s8 *)(temp_fp) + 0x10)), (*(f32*)((s8 *)(var_v0_3) + 0x14)) - (*(f32*)((s8 *)(temp_fp) + 0x14)));
            func_L01_004EEDD0(0, 0.02f, 0.15f, 0.10471977f);
        }
        break;
    case 0x23:                                      /* switch 1 */
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.004916667f, 0.004916667f);
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.004916667f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32) (((void*)D_001A4BE0) + 0x120), 0.0061111115f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.015000001f);
        }
        var_v0_3_u2 = ((Hero *)D_001A4BE0)->ptr[0xA24/4];
        if (var_v0_3_u2 != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160((*(f32*)((s8 *)(var_v0_3_u2) + 0x10)) - (*(f32*)((s8 *)(temp_fp) + 0x10)), (*(f32*)((s8 *)(var_v0_3_u2) + 0x14)) - (*(f32*)((s8 *)(temp_fp) + 0x14)));
            func_L01_004EEDD0(0, 0.02f, 0.15f, 0.10471977f);
        }
        break;
    case 0x24:                                      /* switch 1 */
        qcopy(v0, (u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10);
        temp_f0_4 = func_0038CF00((s32) (((void*)D_001A4BE0) + 0x80), (s32)((u128_t*)v0));
        ((Hero *)D_001A4BE0)->f[0xA30/4] = temp_f0_4;
        ((Hero *)D_001A4BE0)->f[0xA2C/4] = 60.0f;
        if (((Hero *)D_001A4BE0)->f[0xA20/4] > 0.0f) {
            ((Hero *)D_001A4BE0)->f[0xA2C/4] = (f32) (temp_f0_4 / ((Hero *)D_001A4BE0)->f[0x170/4]);
        }
        temp_v1_16 = ((Hero *)D_001A4BE0)->i[0x25C8/4];
        if (temp_v1_16 == 0) {
            func_003C4138((s32) (((void*)D_001A4BE0) + 0xA20), 0.45000002f, 0.022222223f);
            temp_v0_5 = ((Hero *)D_001A4BE0)->ptr[0xA24/4];
            var_f20_2 = func_0038D160((*(f32*)((s8 *)(temp_v0_5) + 0x10)) - (*(f32*)((s8 *)(temp_fp) + 0x10)), (*(f32*)((s8 *)(temp_v0_5) + 0x14)) - (*(f32*)((s8 *)(temp_fp) + 0x14)));
            if (((Hero *)D_001A4BE0)->i[0x3C0/4] != 0) {
                if (func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], var_f20_2) > 1.5707964f) {
                    var_f20_2 = func_0038DAB8(var_f20_2, 3.1415927f);
                }
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = var_f20_2;
            func_L01_004EEDD0(0, 0.03f, 0.15f, 0.12217307f);
        } else if (temp_v1_16 == 1) {
            func_003C4138((s32) (((void*)D_001A4BE0) + 0xA20), 0.0f, 0.011666667f);
        }
        if ((func_002A88A0((s32) &spE8, (s32) &spEC, -0.0058333334f, ((Hero *)D_001A4BE0)->f[0xA20/4], 1.9f - ((Hero *)D_001A4BE0)->f[0xA30/4]) > 0) && (spE8 > 0.0f)) {
            ((Hero *)D_001A4BE0)->f[0xA2C/4] = spE8;
            ((Hero *)D_001A4BE0)->i[0x25C8/4] = 1;
        }
        ((Hero *)D_001A4BE0)->h[0x226/2] = 3;
        if (((Hero *)D_001A4BE0)->f[0xA2C/4] < 20.0f) {
            ((Hero *)D_001A4BE0)->i[0xA34/4] = 1;
        }
        if (((Hero *)D_001A4BE0)->i[0xA34/4] != 0) {
            func_L01_00448690((s32) (((void*)D_001A4BE0) + 0x94), 0, 0.0f, 0.06399541f);
        } else {
            turn24 = func_0038DAB8(-func_0038D160(func_0038CF38((s32) (((void*)D_001A4BE0) + 0x80), (s32)((u128_t*)v0)), v0[2] - ((Hero *)D_001A4BE0)->f[0x88/4]), 1.5707965f);
            func_L01_00448690((s32) (((void*)D_001A4BE0) + 0x94), 0, turn24, 0.10762865f);
        }
        v20[0] = func_0038D098(func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707965f)) * -0.57f;
        temp_f0_5 = func_0038D0B0(func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707965f)) * -0.57f;
        v20[2] = 0;
        v20[1] = temp_f0_5;
        func_00282CC0((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), (s32) (((void*)D_001A4BE0) + 0x80));
        func_00282CF0((s32) ((u128_t*)v10), (s32) (((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10), (s32) ((u128_t*)v20));
        func_0038CF68((s32) (((void*)D_001A4BE0) + 0xF0), (s32) ((u128_t*)v10), ((Hero *)D_001A4BE0)->f[0xA20/4]);
        temp_f0_6 = ((Hero *)D_001A4BE0)->f[0xA2C/4];
        if (temp_f0_6 < 30.0f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF8/4] - ((30.0f - temp_f0_6) * 0.008055556f));
        }
        break;
    case 0x25:                                      /* switch 1 */
        func_003C4138((s32)(D_001A4BE0 + 0xABC), ((Hero *)D_001A4BE0)->f[0xA40/4], 0.16666667f);
        qcopy(&((Hero *)D_001A4BE0)->q[0xF0/16], &((Hero *)D_001A4BE0)->q[0x110/16]);
        func_0038CE20((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.9f);
        ((Hero *)D_001A4BE0)->f[0xF8/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF8/4] - 0.004166667f);
        qcopy(v0, (u8 *)((Hero *)D_001A4BE0)->ptr[0xA24/4] + 0x10);
        ((Hero *)D_001A4BE0)->f[0xA30/4] = func_0038CF00((s32)(D_001A4BE0 + 0x80), (s32)((u128_t*)v0));
        func_00282CC0((s32) ((u128_t*)v10), (s32)(D_001A4BE0 + 0x80), (s32)(D_001A4BE0 + 0xF0));
        func_00282CF0((s32) ((u128_t*)v30), (s32) ((u128_t*)v10), (s32)((u128_t*)v0));
        func_0038CF68((s32) ((u128_t*)v30), (s32) ((u128_t*)v30), ((Hero *)D_001A4BE0)->f[0xA3C/4]);
        func_00282CC0((s32) ((u128_t*)v20), (s32)((u128_t*)v0), (s32) ((u128_t*)v30));
        func_00282CF0((s32)(D_001A4BE0 + 0xF0), (s32) ((u128_t*)v20), (s32)(D_001A4BE0 + 0x80));
        break;
    case 0x2B:                                      /* switch 1 */
        if ((((Hero *)D_001A4BE0)->i[0xC08/4] & 2) && ((*(u8*)((s8 *)(temp_fp) + 0x43)) == 0x34)) {
            func_L01_0050FB40(0x35, 0xA, 12.0f);
            ((Hero *)D_001A4BE0)->f[0xC00/4] = 0.3f;
        }
        temp_v1_17 = ((Hero *)D_001A4BE0)->ptr[0xA54/4];
        temp_f24 = ((Hero *)D_001A4BE0)->f[0xF8/4];
        if (temp_v1_17 != 0) {
            temp_v0_6 = (*(void**)((s8 *)(temp_v1_17) + 0x68));
            if ((temp_v0_6 != 0) && ((*(s32*)((s8 *)(temp_v0_6) + 0x34)) != 0)) {
                var_f20_3 = (*(f32*)((s8 *)(temp_v1_17) + 0xF8));
                if (func_0038DBA0(var_f20_3, ((Hero *)D_001A4BE0)->f[0x98/4]) > 90.0f) {
                    var_f20_3 = func_0038DAB8(var_f20_3, 3.1415927f);
                }
                func_L01_00448728((s32) (((void*)D_001A4BE0) + 0xA6C), var_f20_3, (s32) (((void*)D_001A4BE0) + 0xA78), 0.02f, 0.3f, 0.0f, 0);
            }
        }
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0xA6C/4];
        func_L01_004EEDD0(0, 0.02f, 0.3f, 0.078539826f);
        func_00282CF0((s32)((u128_t*)v0), (s32) (((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10), (s32) (((void*)D_001A4BE0) + 0x80));
        func_0038CF68((s32)((u128_t*)v0), (s32)((u128_t*)v0), 1.0f);
        if (v0[2] < 0.23f) {
            v0[2] = 0.23f;
        }
        func_00282C88((s32) ((u128_t*)v60));
        v60[2] = ((Hero *)D_001A4BE0)->f[0x98/4];
        func_00283410((s32) ((u128_t*)v20), (s32) ((u128_t*)v60));
        func_00283698((s32) ((u128_t*)m70), (s32) ((u128_t*)v20));
        func_0038D028((s32)((u128_t*)v0), (s32)((u128_t*)v0), (s32) ((u128_t*)m70));
        v10[0] = -func_0038D160(func_00282C10((v0[0] * v0[0]) + (v0[2] * v0[2])), v0[1]);
        temp_f0_7 = func_0038D160(v0[2], v0[0]);
        v10[1] = temp_f0_7;
        func_L01_00448728((s32) (((void*)D_001A4BE0) + 0x94), temp_f0_7, (s32) (((void*)D_001A4BE0) + 0xA4), 0.04f, 0.2f, 0.15998854f, 0);
        func_L01_00448728((s32) (((void*)D_001A4BE0) + 0x90), v10[0], (s32) (((void*)D_001A4BE0) + 0xA0), 0.04f, 0.2f, 0.15998854f, 0);
        var_s7 = ((Hero *)D_001A4BE0)->f[0x88/4] < (*(f32*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0xA54/4]) + 0x18));
        if (((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) {
            if ((var_s7 != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x29) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.25f)) {
                func_L01_004EE850(1.0f, 0);
                var_f20_4 = ((Hero *)D_001A4BE0)->f[0x2838/4] * 0.0035f;
                if (var_f20_4 > 0.083333336f) {
                    var_f20_4 = 0.083333336f;
                }
                vB0[0] = func_0038D098(((Hero *)D_001A4BE0)->f[0x1A0/4]) * var_f20_4;
                temp_f0_8 = func_0038D0B0(((Hero *)D_001A4BE0)->f[0x1A0/4]) * var_f20_4;
                temp_a0_10 = ((void*)D_001A4BE0) + 0xF0;
                (*(s32*)&vB0[2]) = 0;
                vB0[1] = temp_f0_8;
                func_00282CC0((s32) temp_a0_10, (s32) temp_a0_10, (s32) ((u128_t*)vB0));
            }
            if (((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) {
                temp_s2_2 = ((void*)D_001A4BE0) + 0x80;
                if ((func_0038CF38((s32) temp_s2_2, (s32) (((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10)) < (((Hero *)D_001A4BE0)->f[0xA60/4] * 1.57f)) || (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.5f)) {
                    temp_s1_2 = ((void*)D_001A4BE0) + 0xF0;
                    func_L01_00510F08((s32) temp_s1_2, (s32) (((void*)D_001A4BE0) + 0x110), 0.011111111f);
                    if ((((Hero *)D_001A4BE0)->h[0xA7E/2] != 0) && (func_L01_005114B0((s32) temp_s1_2) > 0.0f)) {
                        func_00282CF0((s32) ((u128_t*)vB0), (s32) temp_s2_2, (s32) (((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10));
                        func_L01_00510F08((s32) temp_s1_2, (s32) temp_s1_2, 0.015833333f);
                    }
                }
                temp_f20_3 = func_0038CEA8((s32)(D_001A4BE0 + 0xF0)) * 0.00025f;
                func_0038CE20((s32) ((u128_t*)vB0), (s32)(D_001A4BE0 + 0xF0), -1.0f);
                func_0038CF68((s32) ((u128_t*)vB0), (s32) ((u128_t*)vB0), temp_f20_3);
                func_00282CC0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (s32) ((u128_t*)vB0));
            }
        }
        temp_v0_7 = ((Hero *)D_001A4BE0)->ptr[0xA54/4];
        if (temp_v0_7 != 0) {
            temp_s0 = (*(void**)((s8 *)(temp_v0_7) + 0x68));
            temp_s1_3 = ((void*)D_001A4BE0) + 0xF0;
            if (temp_s0 != 0) {
                temp_f0_9 = func_0038CEA8((s32) temp_s1_3);
                temp_f12 = (*(f32*)((s8 *)(temp_s0) + 0xC));
                spF0 = temp_f0_9;
                if (temp_f12 < temp_f0_9) {
                    func_003C4138((s32) &spF0, temp_f12, 0.004166667f);
                    func_0038CF68((s32) temp_s1_3, (s32) temp_s1_3, spF0);
                }
            }
        }
        temp_f0_10 = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], -1.5707965f);
        temp_s5 = ((void*)D_001A4BE0) + 0x80;
        temp_s4_2 = ((void*)D_001A4BE0) + 0xF0;
        vD0[0] = func_0038D098(temp_f0_10) * 0.15f;
        temp_f0_11 = func_0038D0B0(temp_f0_10) * 0.15f;
        (*(s32*)&vD0[2]) = 0;
        vD0[1] = temp_f0_11;
        func_00282CC0((s32) &vD0[0], (s32) &vD0[0], (s32) temp_s5);
        func_00282CC0((s32) ((u128_t*)vB0), (s32) &vD0[0], (s32) temp_s4_2);
        func_00282CF0((s32) ((u128_t*)vC0), (s32) ((u128_t*)vB0), (s32) (((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10));
        func_0038CF68((s32) ((u128_t*)vC0), (s32) ((u128_t*)vC0), ((Hero *)D_001A4BE0)->f[0xA64/4]);
        func_00282CC0((s32) ((u128_t*)vB0), (s32) (((Hero *)D_001A4BE0)->ptr[0xA54/4] + 0x10), (s32) ((u128_t*)vC0));
        func_00282CF0((s32) temp_s4_2, (s32) ((u128_t*)vB0), (s32) &vD0[0]);
        temp_f20_4 = ((Hero *)D_001A4BE0)->f[0xA64/4];
        func_L01_004482A0((s32) (((void*)D_001A4BE0) + 0xA64), (s32) (((void*)D_001A4BE0) + 0xA68), ((Hero *)D_001A4BE0)->f[0xA60/4], ((Hero *)D_001A4BE0)->f[0xA84/4], ((Hero *)D_001A4BE0)->f[0xA88/4], ((Hero *)D_001A4BE0)->f[0xA8C/4]);
        temp_f20_5 = ((Hero *)D_001A4BE0)->f[0xA64/4] - temp_f20_4;
        if (((Hero *)D_001A4BE0)->f[0xA64/4] < func_0038CEA8((s32) ((u128_t*)vC0))) {
            func_0038CF68((s32) ((u128_t*)vC0), (s32) ((u128_t*)vC0), temp_f20_5);
            func_00282CC0((s32) temp_s5, (s32) temp_s5, (s32) ((u128_t*)vC0));
        }
        if ((((Hero *)D_001A4BE0)->h[0xA7E/2] != 0) && (var_s7 != 0)) {
            min2B = 0.23333335f;
            temp_f0_12 = func_0038CED8((s32) temp_s4_2);
            spF4 = temp_f0_12;
            if (temp_f0_12 < min2B) {
                func_L01_004482A0((s32) &spF4, (s32) (((void*)D_001A4BE0) + 0xA74), min2B, 0.047f, 0.3f, 0.0f);
                vB0[0] = func_0038D098(((Hero *)D_001A4BE0)->f[0xA6C/4]) * ((Hero *)D_001A4BE0)->f[0xA74/4];
                temp_f0_13 = func_0038D0B0(((Hero *)D_001A4BE0)->f[0xA6C/4]);
                vB0[2] = 0.0f;
                vB0[1] = temp_f0_13 * ((Hero *)D_001A4BE0)->f[0xA74/4];
                func_00282CC0((s32) temp_s4_2, (s32) temp_s4_2, (s32) ((u128_t*)vB0));
            }
        }
        if ((((Hero *)D_001A4BE0)->h[0xA5C/2] != 0) && (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) && (((temp_f24 < 0.0f) && (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f)) || (((Hero *)D_001A4BE0)->h[0xA7C/2] != 0))) {
            ((Hero *)D_001A4BE0)->h[0xA7E/2] = 0;
            temp_f20_6 = func_00282C10(((Hero *)D_001A4BE0)->f[0xA60/4] / ((Hero *)D_001A4BE0)->f[0xA70/4]) * 3.1415927f;
            temp_v0_8 = ((Hero *)D_001A4BE0)->h[0xA7C/2];
            if (temp_v0_8 != 0) {
                var_v0_4 = temp_v0_8 == 1;
            } else {
                (*(u128_t*)vB0) = ((Hero *)D_001A4BE0)->q[0x110/16];
                var_v0_4 = func_L01_004F05F0((s32) ((u128_t*)vB0)) > 0.0f;
            }
            if (var_v0_4 != 0) {
                if ((*(u8*)((s8 *)(temp_fp) + 0x43)) != 0x35) {
                    func_L01_0050FB40(0x35, 6, 17.0f);
                    ((Hero *)D_001A4BE0)->h[0xA7C/2] = 1;
                } else {
                    temp_v0_9 = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
                    if ((*(u8*)((s8 *)(temp_v0_9) + 0x42)) == (*(u8*)((s8 *)(temp_v0_9) + 0x43))) {
                        func_L01_004E5030(42.0f, temp_f20_6, 0.5f, -1.0f);
                        ((Hero *)D_001A4BE0)->h[0xA7C/2] = 0;
                    }
                }
            } else if ((*(u8*)((s8 *)(temp_fp) + 0x43)) != 0x35) {
                func_L01_0050FB40(0x35, 0x15, 9.0f);
                ((Hero *)D_001A4BE0)->h[0xA7C/2] = 2;
            } else {
                temp_v0_10 = ((Hero *)D_001A4BE0)->ptr[0x25C0/4];
                if ((*(u8*)((s8 *)(temp_v0_10) + 0x42)) == (*(u8*)((s8 *)(temp_v0_10) + 0x43))) {
                    func_L01_004E5030(12.0f, temp_f20_6, 0.5f, -1.0f);
                    ((Hero *)D_001A4BE0)->h[0xA7C/2] = 0;
                }
            }
        }
        break;
    case 0x14:                                      /* switch 1 */
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L23_002F72D0[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            temp_a1_3 = ((Hero *)D_001A4BE0)->i[0xBC4/4];
            if (temp_a1_3 != 0) {
                temp_f1_5 = func_0038CF38((s32) (((void*)D_001A4BE0) + 0x80), temp_a1_3 + 0x10);
                var_v1_2 = 0;
                if ((((Hero *)D_001A4BE0)->b[0x1478] != 0) || (((Hero *)D_001A4BE0)->b[0x147D] != 0) || (((Hero *)D_001A4BE0)->b[0x1477] != 0)) {
                    var_v1_2 = 1;
                }
                if (((temp_f1_5 > 2.0f) && (temp_f1_5 < 5.0f)) || (var_v1_2 != 0)) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.075f;
                }
                func_L01_004EF128(0.0011111111f, 0.0011111111f);
                ((Hero *)D_001A4BE0)->f[0xF0/4] = (f32) (func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4]);
                ((Hero *)D_001A4BE0)->f[0xF4/4] = (f32) (func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            } else {
                func_L01_004EF128(0.00055555557f, 0.00055555557f);
                temp_a0_11 = ((void*)D_001A4BE0) + 0xF0;
                func_L01_00511588((s32) temp_a0_11, (s32) temp_a0_11, ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            }
        } else {
            var_s1_2 = 0;
            if ((((Hero *)D_001A4BE0)->d[0x1470/8] & (0xFFFFULL << 40)) || (((Hero *)D_001A4BE0)->b[0x147D] != 0) || (((Hero *)D_001A4BE0)->f[0x33C/4] > 4.0f)) {
                var_s1_2 = 1;
            }
            temp_a1_4 = ((Hero *)D_001A4BE0)->i[0xBC4/4];
            if (temp_a1_4 != 0) {
                func_00282CF0((s32)((u128_t*)v0), temp_a1_4 + 0x10, (s32) (((void*)D_001A4BE0) + 0x80));
                temp_f0_14 = func_L01_00511408((s32)((u128_t*)v0));
                if (((temp_f0_14 > 2.0f) && (temp_f0_14 < 5.0f)) || (var_s1_2 != 0)) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.075f;
                }
                func_L01_004EF128(0.0069444445f, 0.0069444445f);
                func_0038CF68((s32) ((u128_t*)v10), (s32)D_001A4BE0, ((Hero *)D_001A4BE0)->f[0x1B4/4]);
                func_L01_00511588((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
                func_00282CC0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), (s32) ((u128_t*)v10));
            } else {
                if ((var_s1_2 != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x46)) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.075f;
                }
                func_L01_004EF128(0.004166667f, 0.004166667f);
                func_L01_00511588((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            }
        }
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0xBCC/4];
            qcopy(&((Hero *)D_001A4BE0)->q[0x190/16], &((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EEDD0(0, 0.05f, 0.2f, 0.2821616f);
        } else if (((Hero *)D_001A4BE0)->f[0xC18/4] < 25.0f) {
            func_L01_004F2880(8.0f, 1.0471977f, 1.0471977f);
        }
        temp_f1_6 = ((Hero *)D_001A4BE0)->f[0x33C/4];
        var_f21 = 0.12833333f;
        if (temp_f1_6 > 2.25f) {
            var_f21 = 0.064166665f;
        } else if (temp_f1_6 > 1.8f) {
            var_f21 = 0.08983333f;
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 23.5f) && (((Hero *)D_001A4BE0)->f[0x118/4] < 0.0f) && (((Hero *)D_001A4BE0)->h[0x36E/2] != 0)) {
            qcopy(v0, &((Hero *)D_001A4BE0)->q[0x80/16]);
            func_L01_00511158((s32)((u128_t*)v0), (s32)((u128_t*)v0), -0.5f);
            func_0038CF68((s32) &v40[0], (s32)D_001A4BE0, 2.0f);
            func_L01_00446760((s32) ((u128_t*)v10), (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, 2.0f, (s32) &v40[0]);
            v10[3] = 5627.925f;
            (*(u8*)((u8*)v20+9)) = 1;
            (*(u16*)((u8*)v20+10)) = 0x47;
            (*(u8*)((u8*)v20+8)) = 0;
            func_003D4D00(0.4f, (s32)((u128_t*)v0), 0x10, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], (s32) ((u128_t*)v10));
        }
        if (func_L01_004EE7F8(25.7f) != 0) {
            func_L01_003F1F20(0x19);
            ((Hero *)D_001A4BE0)->h[0x1FA/2] = 0x32;
            if (D_00142CBA != 0) {
                ((Hero *)D_L23_001E1A40)->f[0x40/4] = 0.1f;
                ((Hero *)D_L23_001E1A40)->i[0x48/4] = 0x1E;
                ((Hero *)D_001A4BE0)->h[0x224/2] = 0x23;
                ((Hero *)D_L23_001E1A40)->i[0x2C/4] = 0;
            }
        }
        temp_v1_18 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        lim3 = 0xE;
        if (temp_v1_18 < 9) {
            temp_s0_2 = ((void*)D_001A4BE0) + 0xF0;
            spF8 = func_L01_005114B0((s32) temp_s0_2);
            func_003C4138((s32) &spF8, var_f21, 0.041666668f);
            func_L01_00511508((s32) temp_s0_2, (s32) temp_s0_2, spF8);
        } else if (temp_v1_18 > lim3) {
            temp_s1_4 = ((void*)D_001A4BE0) + 0xF0;
            func_L01_00510F08((s32) temp_s1_4, (s32) temp_s1_4, 0.036111113f);
            if (func_L01_005114B0((s32) temp_s1_4) < 0.0f) {
                ((Hero *)D_001A4BE0)->f[0xBE0/4] = 1.0f;
            }
            var_f20_5 = -0.6166667f;
            if (D_L23_001D673C != 0) {
                var_f20_5 = -1.1666667f;
            }
            if (func_L01_005114B0((s32) temp_s1_4) < var_f20_5) {
                func_L01_00511508((s32) temp_s1_4, (s32) temp_s1_4, var_f20_5);
            }
        }
        break;
    case 0x15:                                      /* switch 1 */
    case 0x88:                                      /* switch 1 */
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L23_002F72D0[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x18/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        var_a0_8 = (((Hero *)D_001A4BE0)->i[0x25D0/4] == 1) && (((Hero *)D_001A4BE0)->i[0x25D8/4] >= 0x15);
        if (var_a0_8 == 0) {
            if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
                var_s1_3 = 0;
                if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                    temp_s0_3 = ((void*)D_001A4BE0) + 0xBA0;
                    var_f20_6 = func_L01_004F4E20((s32) temp_s0_3, 0);
                    var_f0_3 = func_L01_004F4E20((s32) temp_s0_3, 1);
                } else {
                    var_f20_6 = func_0038DB00(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
                    var_f0_3 = func_L01_004485E0(1, ((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
                }
                if (var_f0_3 < 4.3633237f) {
                    var_s1_3 = 1;
                }
                if (var_f20_6 > 0.0f) {
                    ((Hero *)D_001A4BE0)->f[0xC00/4] = (f32) (1.0f / (var_f0_3 + 1.0f));
                }
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0xBCC/4];
                qcopy(&((Hero *)D_001A4BE0)->q[0x190/16], &((Hero *)D_001A4BE0)->q[0xBA0/16]);
                if (var_s1_3 != 0) {
                    func_L01_004EEDD0(1, 0.057f, 0.2f, 0.2821616f);
                } else {
                    func_L01_004EEDD0(0, 0.057f, 0.2f, 0.2821616f);
                }
            } else {
                    var_a0_9 = 1;
                    if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x83) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0xC)) {
                        var_a0_9 = 0;
                    } else if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 6.0f)) {
                        var_a0_9 = 0;
                    }
                    if (var_a0_9 != 0) {
                        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x15) {
                            func_L01_004F2880(14.0f, 0.52359885f, 0.78539824f);
                        } else {
                            func_L00_0041E958(64.0f, 0.17453295f, 0.3490659f);
                        }
                    }
                }
        }
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && ((*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) == 0x1A) && (func_L01_004EE7F8(33.0f) != 0)) {
            if ((((Hero *)D_001A4BE0)->b[0x1474] != 0) && (((Hero *)D_001A4BE0)->f[0x170/4] < 0.033333335f)) {
                {
                    ((Hero *)D_001A4BE0)->f[0xF0/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF0/4] + (func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * 0.021666666f));
                    ((Hero *)D_001A4BE0)->f[0xF4/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF4/4] + (func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * 0.021666666f));
                    qcopy(&((Hero *)D_001A4BE0)->q[0x140/16], &((Hero *)D_001A4BE0)->q[0xF0/16]);
                }
            }
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x15) {
                func_L00_002BA508();
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            if (func_L01_004EE7F8(84.0f) != 0) {
                var_f21_2 = 0.041666668f;
                temp_f20_7 = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x98/4], 3.1415927f);
                if ((*(s32*)&D_001D52FC) & 8) {
                    var_f21_2 = 0.050000004f;
                }
                ((Hero *)D_001A4BE0)->f[0xF0/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF0/4] + (func_0038D098(temp_f20_7) * var_f21_2));
                ((Hero *)D_001A4BE0)->f[0xF4/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF4/4] + (func_0038D0B0(temp_f20_7) * var_f21_2));
                qcopy(&((Hero *)D_001A4BE0)->q[0x140/16], &((Hero *)D_001A4BE0)->q[0xF0/16]);
            }
            func_L00_002B9598();
        } else {
            func_L01_004EF128(0.010277778f, 0.007777778f);
            func_L01_004EF178(99999.0f);
            if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
                func_L01_00510F08((s32) (((void*)D_001A4BE0) + 0xF0), (s32) ((void*)D_001A4BE0) + 0x130, 0.0069444445f);
            } else {
                func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.015000001f);
                break;
            }
        }
        break;
    case 0x13:                                      /* switch 1 */
        if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < (f32) D_L23_002F72D0[((Hero *)D_001A4BE0)->h[0xBDC/2]].w[0x20/4])) {
            ((Hero *)D_001A4BE0)->c[0x1219] = 2;
        }
        if (((Hero *)D_001A4BE0)->b[0x1474] != 0) {
            func_L00_002B9598();
            break;
        }
        temp_a1_5 = ((Hero *)D_001A4BE0)->i[0xBC4/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        temp_s2_3 = (((Hero *)D_001A4BE0)->h[0xBDC/2] * 0x2C) + (s32)D_L23_002F72D0;
        if ((temp_a1_5 != 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 4)) {
            temp_s1_5 = ((void*)D_001A4BE0) + 0x80;
            var_f12_13 = func_0038CF38(temp_a1_5 + 0x10, (s32) temp_s1_5);
            if ((*(s32*)&D_L23_001D673C) != 0) {
                var_f12_13 = func_0038CF00(((Hero *)D_001A4BE0)->i[0xBC4/4] + 0x10, (s32) temp_s1_5);
            }
            var_f12_13 = var_f12_13 - 0.5f;
            if (var_f12_13 < 0.0f) {
                var_f12_13 = 0.0f;
            }
            temp_v1_20 = (*(s32*)((s8 *)(temp_s2_3) + 4));
            if (temp_v1_20 == 0) {
                var_f0_4 = 0.75f;
                var_f21_3 = 0.8f;
                var_f22 = 4.0f;
            } else if (temp_v1_20 == 1) {
                var_f0_4 = 0.6f;
                var_f21_3 = 1.7f;
                var_f22 = 4.0f;
            } else {
                var_f0_4 = 1.3f;
                var_f21_3 = 1.7f;
                var_f22 = 1.9f;
            }
            temp_f20_8 = var_f12_13 - var_f0_4;
            if (func_00282C48(temp_f20_8) < (var_f21_3 + 3.0f)) {
                var_f12_15 = temp_f20_8 * 1.1111112f;
                if (var_f22 < var_f12_15) {
                    var_f12_15 = var_f22;
                }
                if (var_f12_15 > 1.0f) {
                    ((Hero *)D_001A4BE0)->f[0xBD4/4] = var_f12_15;
                }
            }
        }
        temp_v1_21 = (*(s32*)((s8 *)(temp_s2_3) + 4));
        switch (temp_v1_21) {
        case 0:
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 18.0f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.07333334f;
            }
            break;
        case 1:
            temp_f1_7 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (temp_f1_7 < 9.0f)) {
                if (temp_f1_7 > 8.0f) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.050000004f;
                } else if (temp_f1_7 > 7.0f) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.075f;
                } else {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.095f;
                }
            }
            break;
        case 2:
            if ((((Hero *)D_001A4BE0)->i[0xC0C/4] != 0) || (((Hero *)D_001A4BE0)->f[0xC18/4] < 12.0f)) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = ((Hero *)D_001A4BE0)->f[0xBD4/4] * 0.06166667f;
            }
            break;
        }
        func_003C4138((s32)(D_001A4BE0 + 0xC20), 1.0f, 0.2f);
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
        if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
            var_f0_5 = func_L01_004F4E20((s32)(D_001A4BE0 + 0xBC0), 0);
        } else {
            var_f0_5 = func_0038DB00(((Hero *)D_001A4BE0)->f[0xBCC/4], ((Hero *)D_001A4BE0)->f[0x98/4]);
        }
        temp_f1_8 = func_00282C48(var_f0_5);
        if (((*(s32*)((s8 *)(temp_s2_3) + 4)) == 1) && (var_f0_5 > 0.0f)) {
            ((Hero *)D_001A4BE0)->f[0xC00/4] = (f32) (1.0f / (temp_f1_8 + 1.0f));
        }
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0xBCC/4];
        qcopy(&((Hero *)D_001A4BE0)->q[0x190/16], &((Hero *)D_001A4BE0)->q[0xBA0/16]);
        func_L01_004EEDD0(0, 0.05f, 0.2f, 0.2821616f);
    } else {
        var_v1_3 = 1;
        if (((*(s32*)((s8 *)(temp_s2_3) + 4)) == 1) && (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) && (((Hero *)D_001A4BE0)->f[0xC18/4] > 7.0f)) {
            var_v1_3 = 0;
        }
        if (var_v1_3 != 0) {
            func_L01_004F2880(5.0f, 0.78539824f, 0.78539824f);
        }
    }
        func_L01_004EF128(0.010277778f, 0.007777778f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] != 0) {
                func_L01_004EF238((s32) (((void*)D_001A4BE0) + 0xBA0));
            } else {
                func_L01_004EF178(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_L01_004EF178(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32) (((void*)D_001A4BE0) + 0xF0), (s32) (((void*)D_001A4BE0) + 0x130), 0.0069444445f);
        } else {
            temp_a0_12 = ((void*)D_001A4BE0) + 0xF0;
            func_L01_00510F08((s32) temp_a0_12, (s32) temp_a0_12, 0.015000001f);
        }
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
            break;
    case 0x7C:                                      /* switch 1 */
        func_003C4138((s32)(D_001A4BE0 + 0x1B4), 0.0f, 0.006666667f);
        if ((*(s32*)&D_L23_001D673C) != 0) {
            func_0038CF68((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xBD0), ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.0f) {
                func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x130), 0.0069444445f);
            } else {
                func_L01_00511508((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.0f);
            }
            func_0038CE20((s32)(D_001A4BE0 + 0x190), (s32)(D_001A4BE0 + 0xBD0), -1.0f);
        } else {
            ((Hero *)D_001A4BE0)->f[0xF0/4] = (f32) (func_0038D098(((Hero *)D_001A4BE0)->f[0xBD0/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            ((Hero *)D_001A4BE0)->f[0xF4/4] = (f32) (func_0038D0B0(((Hero *)D_001A4BE0)->f[0xBD0/4]) * ((Hero *)D_001A4BE0)->f[0x1B4/4]);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 0.0f) {
                ((Hero *)D_001A4BE0)->f[0xF8/4] = (f32) (((Hero *)D_001A4BE0)->f[0x128/4] - 0.0069444445f);
            } else {
                ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038DAB8(((Hero *)D_001A4BE0)->f[0xBD0/4], 3.1415927f);
        }
        func_L01_004EEDD0(0, 0.05f, 0.2f, 0.2821616f);
        break;
    /* rac2 states 0x1f: no code in rac3 (dropped) */
    case 0x22:                                      /* switch 1 */
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0xBCC/4];
            qcopy(&((Hero *)D_001A4BE0)->q[0x190/16], &((Hero *)D_001A4BE0)->q[0xBA0/16]);
            func_L01_004EEDD0(0, 0.04f, 0.2f, 0.2821616f);
        } else {
            func_L01_004F2880(11.0f, 0.8726647f, -1.0f);
        }
        func_L01_004EF128(0.008333334f, 0.009722223f);
        func_L01_004EF178(99999.0f);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x110, 0.015000001f);
            func_L01_004EF268();
            break;
        }
        func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.015000001f);
        break;
    case 0x2:                                      /* switch 1 */
    case 0x75:                                      /* switch 1 */
        var_a0_11 = 0;
        if ((((Hero *)D_001A4BE0)->b[0x1476] != 0) && (((Hero *)D_001A4BE0)->f[0x2848/4] < 0.25f)) {
            var_a0_11 = 1;
        }
        if ((((Hero *)D_001A4BE0)->b[0x25EA] != 0) || (var_a0_11 != 0)) {
            if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.016666668f) {
                func_L01_004E5840(0, 2);
            }
            if (((Hero *)D_001A4BE0)->f[0x174/4] > 0.008333334f) {
                func_L01_004E5A20(2, 4);
            }
            func_L01_004E5C08(5, 2, 0);
        }
        if (((Hero *)D_001A4BE0)->h[0x1434/2] == 0) {
            if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.028333336f) {
                ((Hero *)D_001A4BE0)->b[0x3EC] = 1U;
                if ((func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 2.0943954f) && (((Hero *)D_001A4BE0)->f[0x2838/4] == 1.0f)) {
                    ((Hero *)D_001A4BE0)->b[0x3EF] = 1U;
                }
            }
            temp_f20_9 = func_L01_00460818(1);
            if ((func_0038DBA0(temp_f20_9, func_L01_00460818(7)) > 1.9198624f) && (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.2217306f) && (((Hero *)D_001A4BE0)->f[0x2838/4] == 1.0f)) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1U;
                ((Hero *)D_001A4BE0)->b[0x3EC] = 1U;
            }
            if (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.087266475f) {
                ((Hero *)D_001A4BE0)->b[0x3EC] = 0U;
            }
        }
        if ((((Hero *)D_001A4BE0)->b[0x3EF] != 0) && (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.06981318f)) {
            ((Hero *)D_001A4BE0)->b[0x3EF] = 0U;
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] < 0.2f) {
            if (((Hero *)D_001A4BE0)->i[0x3F0/4] != 0) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1U;
            }
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
            qcopy(&((Hero *)D_001A4BE0)->q[0x190/16], &((Hero *)D_001A4BE0)->q[0x410/16]);
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0x3E8/4];
        } else {
            func_L01_004EEBA8();
            if ((func_L01_004E9238(0) == 0xA) && ((((Hero *)D_001A4BE0)->f[0x283C/4] == 1.0f) || (((Hero *)D_001A4BE0)->i[0x3F0/4] != 0)) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                qcopy(&((Hero *)D_001A4BE0)->q[0x410/16], &((Hero *)D_001A4BE0)->q[0x190/16]);
                ((Hero *)D_001A4BE0)->i[0x3F0/4] = 1;
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x1A0/4];
            } else {
                qcopy(&((Hero *)D_001A4BE0)->q[0x410/16], &((Hero *)D_001A4BE0)->q[0x0/16]);
                ((Hero *)D_001A4BE0)->f[0x3E8/4] = ((Hero *)D_001A4BE0)->f[0x98/4];
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x9F0/4] > 0.0f) {
            pA60 = ((void*)D_001A4BE0) + 0x9E0;
            func_L01_004F0558(0.7f, 0.0f);
            (*(u128_t*)v0) = ((Hero *)D_001A4BE0)->q[0x9E0/16];
            temp_f1_9 = ((Hero *)D_001A4BE0)->f[0x1B0/4] + func_L01_004F05F0((s32)((u128_t*)v0));
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = temp_f1_9;
            if (temp_f1_9 < 0.011666667f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.011666667f;
            }
            func_00282C88((s32) pA60);
        }
        var_f20_7 = 1.0f;
        if (((Hero *)D_001A4BE0)->h[0x1434/2] != 0) {
            func_L01_004EE400();
        } else {
            ((Hero *)D_001A4BE0)->f[0x1438/4] = (f32) ((Hero *)D_001A4BE0)->f[0x98/4];
            qcopy(&((Hero *)D_001A4BE0)->q[0x1420/16], &((Hero *)D_001A4BE0)->q[0x0/16]);
            if ((((Hero *)D_001A4BE0)->i[0x25C8/4] == 1) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0) && (((Hero *)D_001A4BE0)->b[0x25EB] == 0)) {
                func_L01_004EEDD0(0, 0.02f, 0.17f, 0.16580631f);
            } else {
                temp_f2_2 = func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]);
                if (((((Hero *)D_001A4BE0)->f[0x2838/4] < 0.9f) || ((((Hero *)D_001A4BE0)->b[0x25EB] != 0) && (((Hero *)D_001A4BE0)->b[0x3EF] == 0))) && (temp_f2_2 > 0.78539824f)) {
                    var_f20_7 = 0.0f;
                }
                func_L01_004EEEC0();
            }
        }
        func_L01_004F2E68();
        func_L01_004F3F40();
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            var_f2_2 = 0.09916667f - (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) * 0.029178405f);
            if (var_f2_2 < 0.0f) {
                var_f2_2 = 0.0f;
            }
            if (var_f2_2 < ((Hero *)D_001A4BE0)->f[0x1B0/4]) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = var_f2_2;
            }
        }
        k005 = var_f20_7 * 0.005f;
        var_f20_8 = 0.0055555557f;
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            var_f1_2 = 2.617994f - ((Hero *)D_001A4BE0)->f[0x1A8/4];
            if (var_f1_2 > 1.0f) {
                var_f1_2 = 1.0f;
            }
            if (var_f1_2 < 0.2f) {
                var_f1_2 = 0.2f;
            }
            var_f20_8 = 0.004722222f;
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = (f32) (((Hero *)D_001A4BE0)->f[0x1B0/4] * var_f1_2);
        }
        temp_f2_3 = func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]);
        if ((((Hero *)D_001A4BE0)->f[0x2838/4] < 0.75f) && (temp_f2_3 > 0.6108653f)) {
            var_f1_3 = 1.0f - (temp_f2_3 * 0.4f);
            if (var_f1_3 < 0.0f) {
                var_f1_3 = 0.0f;
            }
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = (f32) (((Hero *)D_001A4BE0)->f[0x1B0/4] * var_f1_3);
        }
        func_L01_004EF128(k005, var_f20_8);
        if ((((Hero *)D_001A4BE0)->b[0x3EC] != 0) || (((Hero *)D_001A4BE0)->h[0x1434/2] != 0)) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 0) {
                if (((Hero *)D_001A4BE0)->h[0x1434/2] != 0) {
                    func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1438/4]);
                } else {
                    func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1A0/4]);
                }
            } else if (((Hero *)D_001A4BE0)->h[0x1434/2] != 0) {
                func_L01_004EF238((s32) (((void*)D_001A4BE0) + 0x1420));
            } else {
                func_L01_004EF238((s32) (((void*)D_001A4BE0) + 0x190));
            }
        } else {
            func_L01_004EF178(99999.0f);
        }
        func_L20_002C7588(1);
        if (((Hero *)D_001A4BE0)->h[0x214/2] != 0) {
            func_L01_004F52E0(5.0f, 0.2f, 0.35f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x130, 0.0069444445f);
            func_L01_004EF268();
            break;
        }
        func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.015000001f);
        break;
    case 0x80:                                      /* switch 1 */
        func_L01_004F4F18(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
        func_L01_004EE850(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.19166668f;
        func_L01_004E4F30((s32)((u128_t*)v0), (s32) (((void*)D_001A4BE0) + 0x970), 0.17f);
        var_f21_4 = (((Hero *)D_001A4BE0)->f[0x2838/4] * 0.020362178f) * v0[0];
        if ((*(s32*)&D_L23_001D673C) == 0) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x3C) {
                var_f21_4 *= 0.1f;
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.5f;
            }
        }
        if (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) {
            func_L01_004EEC98(0.0f, 0.0f, var_f21_4);
        }
        func_L01_004EF128(0.027777778f, 0.004166667f);
        func_L01_004EF178(99999.0f);
        if ((*(s32*)&D_L23_001D673C) != 0) {
            qcopy(v10, &((Hero *)D_001A4BE0)->q[0x0/16]);
            func_L01_00511158((s32) ((u128_t*)v10), (s32) ((u128_t*)v10), 0.17f);
            func_L01_00448340((s32) (((void*)D_001A4BE0) + 0x80), (s32) ((u128_t*)v10), (s32) (((void*)D_001A4BE0) + 0x980), 0.04f, 0.3f, 0.125f);
        } else {
            func_L01_004482A0((s32) (((void*)D_001A4BE0) + 0x88), (s32) (((void*)D_001A4BE0) + 0x980), ((Hero *)D_001A4BE0)->f[0x338/4] + 0.17f, 0.04f, 0.3f, 0.125f);
        }
        func_0038CE20((s32) ((u128_t*)v10), (s32)(D_001A4BE0 + 0x110), 3.0f);
        func_00282CC0((s32) ((u128_t*)v10), (s32) ((u128_t*)v10), (s32)(D_001A4BE0 + 0xE0));
        temp_v0_12 = func_003D4D00(0.57f, (s32) ((u128_t*)v10), 0, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        if (temp_v0_12 != 0) {
            func_0038CE20((s32) ((u128_t*)v20), (s32)(D_001A4BE0 + 0x110), 7.0f);
            for (var_s0 = 0; var_s0 < temp_v0_12; var_s0++) {
                if (func_003C4B50(((s32 *)D_L23_001EC800)[var_s0]) != 0) {
                    func_L01_00446A70(((s32 *)D_L23_001EC800)[var_s0], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32) (((void*)D_001A4BE0) + 0x80), (s32) ((u128_t*)v20), 1.0f);
                }
            }
        }
        func_L01_004E6390(0.017f, 0.3f);
        func_L01_004E63C0(0.025f, 0.3f);
        func_L01_004E63D8(0.03f, 0.27f);
        var_f2_3 = var_f21_4 * 27.0f;
        if (var_f2_3 > 1.7f) {
            var_f2_3 = 1.7f;
        } else if (var_f2_3 < -1.7f) {
            var_f2_3 = -1.7f;
        }
        temp_f0_20 = var_f2_3 * 0.5f;
        ((Hero *)D_L23_002F5540)->f[0x60/4] = (f32) -var_f2_3;
        ((Hero *)D_L23_002F5540)->f[0x278/4] = temp_f0_20;
        ((Hero *)D_L23_002F5540)->f[0x1C8/4] = temp_f0_20;
        break;
    case 0x2E:                                      /* switch 1 */
        func_L00_002B9598();
        func_L01_004E6390(0.04f, 0.2f);
        func_L01_004E63A8(0.04f, 0.2f);
        func_L01_004E63C0(0.04f, 0.2f);
        func_L01_004E63D8(0.02f, 0.2f);
        temp_v1_25 = (*(u8*)((s8 *)(temp_fp) + 0x43));
        if (temp_v1_25 == 0x37) {
            var_f0_6 = 1.4f;
            var_f20_9 = ((Hero *)D_001A4BE0)->f[0x1A8/4];
            if ((var_f20_9 > 1.4f) || (var_f0_6 = -1.4f, (var_f20_9 < -1.4f))) {
                var_f20_9 = var_f0_6;
            }
            ((Hero *)D_L23_002F5540)->f[0x60/4] = (f32) (var_f20_9 * -0.14f);
            ((Hero *)D_L23_002F5540)->f[0x118/4] = (f32) (var_f20_9 * 0.3f);
            ((Hero *)D_L23_002F5540)->f[0x1C0/4] = (f32) (var_f20_9 * -0.22f);
            ((Hero *)D_L23_002F5540)->f[0x278/4] = (f32) (var_f20_9 * 0.4f);
            ((Hero *)D_L23_002F5540)->f[0x274/4] = (f32) (func_00282C48(var_f20_9) * -0.09f);
            ((Hero *)D_L23_002F5540)->f[0x270/4] = (f32) (func_00282C48(var_f20_9) * 0.08f);
        } else if (temp_v1_25 == 0x66) {
            temp_f22_3 = func_0038DAB8(func_0038DB00(func_0038D160(((Hero *)D_001A4BE0)->f[0x110/4], ((Hero *)D_001A4BE0)->f[0x114/4]), ((Hero *)D_001A4BE0)->f[0x98/4]), 3.1415927f);
            var_f21_5 = ((Hero *)D_001A4BE0)->f[0x174/4] * 6.9813175f;
            if (var_f21_5 > 0.43633235f) {
                var_f21_5 = 0.43633235f;
            }
            temp_f20_10 = func_0038D098(temp_f22_3) * var_f21_5;
            temp_f0_21 = -func_0038D0B0(temp_f22_3);
            ((Hero *)D_L23_002F5540)->f[0x114/4] = temp_f20_10;
            ((Hero *)D_L23_002F5540)->f[0x110/4] = (f32) (temp_f0_21 * var_f21_5);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            var_f12_16 = 0.0069444445f;
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32) (((void*)D_001A4BE0) + 0x110), var_f12_16);
        } else {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = 0.0f;
            func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.041666668f);
            break;
        }
        break;
    case 0x30:                                      /* switch 1 */
        temp_v1_26 = (*(s32*)&D_001D545C);
        if (temp_v1_26 == 0) {
            func_L01_004F4F18(2, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x13);
            var_v0_6 = D_001D545C;
        } else {
            if (temp_v1_26 != 1) {
                func_L01_004F4F18(2, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 6);
            }
            var_v0_6 = (*(s32*)&D_001D545C);
        }
        if ((u32) var_v0_6 < 2U) {
            func_L01_004E5C08(4, 2, 1);
        } else {
            func_L01_004E5C08(4, 2, 0);
            v0[0] = ((Hero *)D_001A4BE0)->f[0x80/4] + func_003824E0(-0.25f, 0.25f);
            v0[1] = ((Hero *)D_001A4BE0)->f[0x84/4] + func_003824E0(-0.25f, 0.25f);
            v0[2] = ((Hero *)D_001A4BE0)->f[0x88/4] + func_003824E0(-0.1f, 0.4f);
            func_0038CE20((s32) ((u128_t*)v10), (s32) (((void*)D_001A4BE0) + 0x110), 0.9f);
            v10[0] += func_003824E0(-0.011666667f, 0.011666667f);
            v10[1] += func_003824E0(-0.011666667f, 0.011666667f);
            v10[2] = ((f32)(v10[2])) + func_003824E0(0.016666668f, 0.033333335f);
            func_L01_0046ADE0((s32)((u128_t*)v0), (s32) ((u128_t*)v10), func_003824E0(37800.0f, 75600.0f));
        }
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0xAC0/4];
        temp_f20_11 = ((Hero *)D_001A4BE0)->f[0x98/4];
        func_L01_004EEDD0(0, 0.033f, 0.3f, 0.069813184f);
        var_f21_6 = func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], temp_f20_11);
        func_00282C88((s32) (((void*)D_001A4BE0) + 0xF0));
        func_L01_004F4730(0.0019444445f);
        temp_f0_22 = ((Hero *)D_001A4BE0)->f[0x118/4] - 0.013888889f;
        ((Hero *)D_001A4BE0)->f[0xF8/4] = temp_f0_22;
        if (temp_f0_22 > -0.011111111f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.011111111f;
        }
        if (var_f21_6 > 0.023271061f) {
            var_f21_6 = 0.023271061f;
        }
        temp_f20_12 = var_f21_6 * 9.0f;
        func_L01_00448728((s32) (((void*)D_001A4BE0) + 0x90), temp_f20_12 * 0.5f, (s32) (((void*)D_001A4BE0) + 0xAD4), 0.007f, 0.17f, 0.020362178f, 0);
        func_L01_00448728((s32) (((void*)D_001A4BE0) + 0x94), -((Hero *)D_001A4BE0)->f[0xAC4/4], (s32) (((void*)D_001A4BE0) + 0xAD8), 0.035f, 0.3f, 0.031997707f, 0);
        func_L01_004E63A8(0.009f, 0.22f);
        func_L01_004E63C0(0.04f, 0.2f);
        func_L01_004E63D8(0.02f, 0.2f);
        ((Hero *)D_L23_002F5540)->f[0x118/4] = (f32) (temp_f20_12 * 2.1f);
        ((Hero *)D_L23_002F5540)->f[0x110/4] = (f32) (temp_f20_12 * 3.5f);
        break;
    case 0x27:                                      /* switch 1 */
    case 0x28:                                      /* switch 1 */
    case 0x29:                                      /* switch 1 */
    case 0x2A:                                      /* switch 1 */
    case 0x3E:                                      /* switch 1 */
        temp_v1_27 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if (((u32) (temp_v1_27 - 0x28) >= 2U) && (temp_v1_27 != 0x3E)) {
            func_L01_004F4F18(0, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
        } else {
            temp_a2_2 = ((Hero *)D_001A4BE0)->i[0x278C/4];
            if (temp_a2_2 != -1) {
                temp_a0_13 = (temp_a2_2 * 0x70) + (s32)D_001A30B0;
                if ((*(s32*)((s8 *)(temp_a0_13) + 0x88)) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) {
                    if ((*(u8*)((s8 *)(temp_a0_13) + 0x74)) != 0) {
                        func_003A4F28(temp_a2_2);
                    }
                }
            }
            ((Hero *)D_001A4BE0)->i[0x278C/4] = -1;
        }
        temp_v1_28 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((temp_v1_28 == 0x27) || (temp_v1_28 == 0x2A)) {
            qcopy(v0, &((Hero *)D_001A4BE0)->q[0x80/16]);
            temp_f20_13 = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x5EC/4], func_L01_00443A18(0.0f, 0.52359885f));
            temp_f21_3 = func_003824E0(0.06666667f, 0.116666675f);
            v10[0] = func_0038D098(temp_f20_13) * temp_f21_3;
            temp_f0_23 = func_0038D0B0(temp_f20_13) * temp_f21_3;
            v10[2] = 0.0f;
            v10[1] = temp_f0_23;
            v10[2] = func_003824E0(0.050000004f, 0.083333336f);
            v10[3] = -0.008333334f;
            func_L01_00466F50((s32)((u128_t*)v0), (s32) ((u128_t*)v10), 0, -1.0f);
        }
        temp_a1_6 = ((Hero *)D_001A4BE0)->ptr[0x1228/4];
        sp120 = 0;
        temp_s7 = (((LevelInfo *)D_L23_002C6740)[D_001425C0[(s32)temp_a1_6]].x1C != 0);
        if ((s32)temp_a1_6 == 0xD) {
            temp_s7 = 0;
        }
        if (temp_s7 != 0) {
            sp120 = ((Hero *)D_001A4BE0)->b[0x25EB] != 0;
        }
        temp_s1_7 = ((void*)D_001A4BE0) + 0x80;
        func_L01_00476B98(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32) temp_s1_7, (s32) (((void*)D_001A4BE0) + 0x570), (s32) (((void*)D_001A4BE0) + 0x5D4), (s32) (((void*)D_001A4BE0) + 0x5D8), ((Hero *)D_001A4BE0)->i[0x5F4/4], 999.0f, 2.0f, 2.5f);
        if (((Hero *)D_001A4BE0)->i[0x600/4] != 0) {
            func_L01_00476B98(((Hero *)D_001A4BE0)->i[0x604/4], (s32) temp_s1_7, (s32) (((void*)D_001A4BE0) + 0x5B0), (s32) (((void*)D_001A4BE0) + 0x608), (s32) (((void*)D_001A4BE0) + 0x60C), ((Hero *)D_001A4BE0)->i[0x610/4], 999.0f, 2.0f, 2.5f);
        }
        var_a2 = 0;
        if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.0699999f) {
            temp_v1_29 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
            if ((temp_v1_29 != 0x28) && (temp_v1_29 != 0x3E) && (((Hero *)D_001A4BE0)->i[0x600/4] == 0)) {
                var_a2 = ((Hero *)D_001A4BE0)->i[0x1BC/4] >= 0x1F;
            }
        }
        if (var_a2 != 0) {
            ((Hero *)D_001A4BE0)->i[0x668/4] = (s32) (((Hero *)D_001A4BE0)->i[0x668/4] + 1);
        } else {
            ((Hero *)D_001A4BE0)->i[0x668/4] = 0;
        }
        temp_v0_13 = ((Hero *)D_001A4BE0)->i[0x5E0/4];
        if (((temp_v0_13 != 0) && ((((Hero *)D_001A4BE0)->i[0x5E0/4] = temp_v0_13 + 1) != 0)) || (var_a2 != 0)) {
            qcopy(&((Hero *)D_001A4BE0)->q[0xF0/16], &((Hero *)D_001A4BE0)->q[0x120/16]);
            temp_v1_32 = ((void*)(D_001A4BE0 + 0xF0)) - 0xF0;
            if ((u32) ((*(s32*)((s8 *)(temp_v1_32) + 0x2294)) - 0x28) < 2U) {
                func_L01_004F1638();
            } else {
                (*(f32*)((s8 *)(temp_v1_32) + 0xF8)) = (f32) ((*(f32*)((s8 *)(temp_v1_32) + 0xF8)) - 0.0061111115f);
            }
        } else {
            temp_f1_10 = (f32) ((Hero *)D_001A4BE0)->i[0x5E8/4];
            var_f20_10 = ((Hero *)D_001A4BE0)->f[0x5E4/4] * temp_f1_10;
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x3E) {
                var_f20_10 = ((Hero *)D_001A4BE0)->f[0x63C/4] * temp_f1_10;
            }
            func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32)((u128_t*)v0), (s32) (((void*)D_001A4BE0) + 0x5D4), (s32) (((void*)D_001A4BE0) + 0x5D8), ((Hero *)D_001A4BE0)->i[0x5F4/4], var_f20_10);
            if (((Hero *)D_001A4BE0)->i[0x600/4] != 0) {
                func_L01_00476498(((Hero *)D_001A4BE0)->i[0x604/4], (s32) ((u128_t*)v10), (s32) (((void*)D_001A4BE0) + 0x608), (s32) (((void*)D_001A4BE0) + 0x60C), ((Hero *)D_001A4BE0)->i[0x610/4], var_f20_10);
            }
            if (((Hero *)D_001A4BE0)->i[0x1BC/4] >= 0x5B) {
                temp_f20_14 = ((Hero *)D_001A4BE0)->f[0x170/4] * 30.0f;
                qcopy(v20, &((Hero *)D_001A4BE0)->q[0x80/16]);
                spFC = ((Hero *)D_001A4BE0)->i[0x5D4/4];
                sp100 = ((Hero *)D_001A4BE0)->f[0x5D8/4];
                temp_s0_5 = func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32) ((u128_t*)v20), (s32) &spFC, (s32) &sp100, ((Hero *)D_001A4BE0)->i[0x5F4/4], temp_f20_14);
                qcopy(v30, &((Hero *)D_001A4BE0)->q[0x80/16]);
                spFC = ((Hero *)D_001A4BE0)->i[0x5D4/4];
                sp100 = ((Hero *)D_001A4BE0)->f[0x5D8/4];
                if ((((temp_s0_5 | func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32) ((u128_t*)v30), (s32) &spFC, (s32) &sp100, ((Hero *)D_001A4BE0)->i[0x5F4/4], temp_f20_14 + 0.1f)) == 0) || (((Hero *)D_001A4BE0)->i[0x5F4/4] != 0)) && (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x27)) {
                    var_f20_11 = func_0038DB00(((Hero *)D_001A4BE0)->f[0x5EC/4], func_0038D160(v30[0] - v20[0], v30[1] - v20[1])) * 0.47f;
                    if (var_f20_11 > 0.78539824f) {
                        var_f20_11 = 0.78539824f;
                    }
                    if (var_f20_11 < -0.78539824f) {
                        var_f20_11 = -0.78539824f;
                    }
                    func_L01_004E6390(0.03f, 0.2f);
                    if (((Hero *)D_001A4BE0)->i[0x5FC/4] != 0) {
                        (*(f32*)&D_L23_002F55A4) = -var_f20_11;
                    } else {
                        (*(f32*)&D_L23_002F55A4) = var_f20_11;
                    }
                }
            }
            temp_v1_30 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
            if ((temp_v1_30 != 0x28) && (temp_v1_30 != 0x3E) && (temp_v1_30 != 0x29)) {
                (*(f32*)&D_L23_002F55A0) = func_0038D160(func_0038CED8((s32) (((void*)D_001A4BE0) + 0x110)), ((Hero *)D_001A4BE0)->f[0x118/4]);
            }
            if (temp_s7 != 0) {
                k03 = 0.3f;
                func_L01_004E63D8(0.017f, k03);
                func_L01_004E63A8(0.027f, k03);
                func_L01_004E63C0(0.027f, k03);
                temp_a1_7 = ((Hero *)D_001A4BE0)->i[0x648/4];
                if (temp_a1_7 != 0) {
                    func_00282CF0((s32) ((u128_t*)v20), temp_a1_7 + 0x10, (s32) (((void*)D_001A4BE0) + 0x80));
                    func_0038D000((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), (s32) (((void*)D_001A4BE0) + 0x40));
                    temp_f12_2 = func_0038D160(v20[0], v20[1]);
                    if ((*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x42)) == 0x31) {
                        temp_f12_2 = func_0038DB00(temp_f12_2, 1.5707965f);
                        var_f1_4 = 0.2f;
                    } else {
                        temp_f12_2 = func_0038DB00(temp_f12_2, -1.5707965f);
                        var_f1_4 = 0.5f;
                    }
                    ((Hero *)D_L23_002F5540)->f[0x1C8/4] = (f32) (temp_f12_2 * var_f1_4);
                    ((Hero *)D_L23_002F5540)->f[0x278/4] = (f32) (temp_f12_2 * k03);
                } else {
                    temp_a0_14 = (*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43));
                    if (temp_a0_14 == 0x31) {
                        var_f21_7 = 0.58823526f;
                        var_f0_8 = func_0038DAB8(-0.8203048f, ((Hero *)D_001A4BE0)->f[0x640/4]);
                        var_f20_12 = 0.73303837f;
                        ((Hero *)D_L23_002F5540)->f[0x278/4] = var_f0_8;
                        ((Hero *)D_L23_002F5540)->f[0x118/4] = func_0038DAB8(var_f20_12, ((Hero *)D_001A4BE0)->f[0x640/4] * var_f21_7);
                        ((Hero *)D_L23_002F5540)->f[0x1C8/4] = func_0038DAB8(var_f20_12, ((Hero *)D_001A4BE0)->f[0x640/4] * var_f21_7);
                    } else if (temp_a0_14 == 0x48) {
                        var_f21_7 = 0.5f;
                        var_f0_8 = func_0038DAB8(0.13962635f, ((Hero *)D_001A4BE0)->f[0x640/4]);
                        var_f20_12 = -0.06981318f;
                        ((Hero *)D_L23_002F5540)->f[0x278/4] = var_f0_8;
                        ((Hero *)D_L23_002F5540)->f[0x118/4] = func_0038DAB8(var_f20_12, ((Hero *)D_001A4BE0)->f[0x640/4] * var_f21_7);
                        ((Hero *)D_L23_002F5540)->f[0x1C8/4] = func_0038DAB8(var_f20_12, ((Hero *)D_001A4BE0)->f[0x640/4] * var_f21_7);
                    } else if (temp_a0_14 == 0x47) {
                        var_f21_7 = 0.58823526f;
                        var_f0_8 = func_0038DAB8(-0.8203048f, ((Hero *)D_001A4BE0)->f[0x640/4]);
                        var_f20_12 = 0.73303837f;
                        ((Hero *)D_L23_002F5540)->f[0x278/4] = var_f0_8;
                        ((Hero *)D_L23_002F5540)->f[0x118/4] = func_0038DAB8(var_f20_12, ((Hero *)D_001A4BE0)->f[0x640/4] * var_f21_7);
                        ((Hero *)D_L23_002F5540)->f[0x1C8/4] = func_0038DAB8(var_f20_12, ((Hero *)D_001A4BE0)->f[0x640/4] * var_f21_7);
                    }
                }
            }
            temp_v0_15 = func_L01_00476440(((Hero *)D_001A4BE0)->i[0x5D0/4], ((Hero *)D_001A4BE0)->i[0x5D4/4], ((Hero *)D_001A4BE0)->i[0x5E8/4], ((Hero *)D_001A4BE0)->i[0x5F4/4]);
            func_00282CF0((s32) ((u128_t*)v20), (s32) &((u128_t *)((Hero *)D_001A4BE0)->ptr[0x5D0/4])[temp_v0_15 + 1], (s32)((u128_t*)v0));
            if (func_0038CEA8((s32) ((u128_t*)v20)) < 0.001f) {
                if (((Hero *)D_001A4BE0)->i[0x5D4/4] == temp_v0_15) {
                    ((Hero *)D_001A4BE0)->i[0x5E0/4] = 1;
                } else {
                    goto block_807;
                }
            } else {
                ((Hero *)D_001A4BE0)->f[0x5EC/4] = func_0038D160(v20[0], v20[1]);
                ((Hero *)D_001A4BE0)->f[0x5F0/4] = func_0038D160(func_0038CED8((s32) ((u128_t*)v20)), ((f32)(v20[2])));
block_807:
                ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x5EC/4], ((Hero *)D_001A4BE0)->f[0x5F8/4]);
                func_L01_004EEDD0(0, 0.015f, 0.15f, 0.10471977f);
                temp_v1_31 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
                if ((((u32) (temp_v1_31 - 0x28) < 2U) && (((Hero *)D_001A4BE0)->b[0x46C] == 0)) || (temp_v1_31 == 0x3E)) {
                    if (((Hero *)D_001A4BE0)->i[0x634/4] != 0) {
                        temp_f0_27 = func_0038D160(((Hero *)D_001A4BE0)->f[0x5C0/4] - ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x5C4/4] - ((Hero *)D_001A4BE0)->f[0x84/4]);
                        if (func_0038DBA0(((Hero *)D_001A4BE0)->f[0x98/4], temp_f0_27) < 1.5707965f) {
                            ((Hero *)D_001A4BE0)->f[0x1A0/4] = temp_f0_27;
                            func_L01_004EEDD0(0, 0.04f, 0.2f, 0.10471977f);
                        }
                    }
                    if ((((Hero *)D_001A4BE0)->i[0x600/4] != 0) && (((Hero *)D_001A4BE0)->i[0x618/4] < 0x31)) {
                        func_00282CF0((s32) ((u128_t*)v20), (s32)((u128_t*)v0), (s32) ((u128_t*)v10));
                        temp_v0_16 = ((Hero *)D_001A4BE0)->i[0x618/4] + 1;
                        ((Hero *)D_001A4BE0)->i[0x618/4] = temp_v0_16;
                        func_0038CE20((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), (f32) temp_v0_16 * 0.020833334f);
                        temp_f20_15 = (f32) (((Hero *)D_001A4BE0)->i[0x618/4] - 1) * 0.020833334f;
                        func_00282CF0((s32) ((u128_t*)v30), (s32)((u128_t*)v0), (s32) ((u128_t*)v10));
                        func_0038CE20((s32) ((u128_t*)v30), (s32) ((u128_t*)v30), temp_f20_15);
                        ((Hero *)D_001A4BE0)->f[0x88/4] = (f32) (((Hero *)D_001A4BE0)->f[0x88/4] + (((f32)(v20[2])) - v30[2]));
                        func_00282CC0((s32) ((u128_t*)v30), (s32) ((u128_t*)v10), (s32) ((u128_t*)v20));
                        func_00282CF0((s32) ((u128_t*)v20), (s32) ((u128_t*)v30), (s32) (((void*)D_001A4BE0) + 0x80));
                        ((Hero *)D_001A4BE0)->f[0xF0/4] = v20[0];
                        ((Hero *)D_001A4BE0)->f[0xF4/4] = v20[1];
                        func_00282CF0((s32) ((u128_t*)v20), (s32)((u128_t*)v0), (s32) (((void*)D_001A4BE0) + 0x570));
                        temp_f2_5 = ((Hero *)D_001A4BE0)->f[0x578/4];
                        temp_f1_11 = ((Hero *)D_001A4BE0)->f[0x88/4] + ((f32)(v20[2]));
                        ((Hero *)D_001A4BE0)->f[0x88/4] = temp_f1_11;
                        if (temp_f1_11 < temp_f2_5) {
                            if (((Hero *)D_001A4BE0)->i[0x618/4] < 0x31) {
                                if (temp_f1_11 < temp_f2_5) {
                                    ((Hero *)D_001A4BE0)->f[0x88/4] = temp_f2_5;
                                }
                            }
                        }
                    } else {
                        func_00282CF0((s32) ((u128_t*)v20), (s32)((u128_t*)v0), (s32)(D_001A4BE0 + 0x5D0));
                        ((Hero *)D_001A4BE0)->f[0xF0/4] = v20[0];
                        ((Hero *)D_001A4BE0)->f[0xF4/4] = v20[1];
                        ((Hero *)D_001A4BE0)->f[0x88/4] = (f32) (((Hero *)D_001A4BE0)->f[0x88/4] + ((f32)(v20[2])));
                        func_00282CF0((s32) ((u128_t*)v30), (s32)(D_001A4BE0 + 0x5D0), (s32)(D_001A4BE0 + 0x80));
                        v30[2] = 0.0f;
                        if (func_0038CEA8((s32) ((u128_t*)v30)) > 0.016666668f) {
                            func_0038CF68((s32) ((u128_t*)v30), (s32) ((u128_t*)v30), 0.016666668f);
                        }
                        ((Hero *)D_001A4BE0)->f[0x80/4] = (f32) (((Hero *)D_001A4BE0)->f[0x80/4] + v30[0]);
                        ((Hero *)D_001A4BE0)->f[0x84/4] = (f32) (((Hero *)D_001A4BE0)->f[0x84/4] + v30[1]);
                    }
                    if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x3E) {
                        ((Hero *)D_001A4BE0)->f[0xF8/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF8/4] - 0.006388889f);
                    } else {
                        func_L01_004F1638();
                    }
                } else {
                    ((Hero *)D_001A4BE0)->i[0x600/4] = 0;
                    var_f0_9 = 0.0f;
                    if ((((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f) && (sp120 != 0)) {
                        func_L01_004EE850(1.0f, 0);
                        var_f0_9 = func_0038DB00(((Hero *)D_001A4BE0)->f[0x1A0/4], ((Hero *)D_001A4BE0)->f[0x5EC/4]);
                        if (var_f0_9 > 0.78539824f) {
                            var_f0_9 = 0.78539824f;
                        } else if (var_f0_9 < -0.78539824f) {
                            var_f0_9 = -0.78539824f;
                        }
                    }
                    func_L01_00448728((s32)(D_001A4BE0 + 0x6A0), var_f0_9, (s32)(D_001A4BE0 + 0x6A4), 0.015f, 0.3f, 0.0f, 0);
                    func_003C4138((s32)(D_001A4BE0 + 0x680), 0.20000002f, 0.004166667f);
                    sp104 = ((Hero *)D_001A4BE0)->i[0x5D4/4];
                    sp108 = ((Hero *)D_001A4BE0)->f[0x5D8/4];
                    qcopy(v20, &((Hero *)D_001A4BE0)->q[0x80/16]);
                    func_L01_00476498(((Hero *)D_001A4BE0)->i[0x5D0/4], (s32) ((u128_t*)v20), (s32) &sp104, (s32) &sp108, ((Hero *)D_001A4BE0)->i[0x5F4/4], 0.3f);
                    temp_f0_24 = func_0038D160(func_0038CF38((s32)(D_001A4BE0 + 0x5D0), (s32) ((u128_t*)v20)), ((f32)(v20[2])) - ((Hero *)D_001A4BE0)->f[0x578/4]);
                    if (temp_f0_24 > 0.0f) {
                        var_f12_17 = temp_f0_24 * -0.07957746f;
                        if (temp_f0_24 > 0.26179942f) {
                            ((Hero *)D_001A4BE0)->i[0x61C/4] = 0;
                        } else if ((temp_f0_24 < 0.13962635f) && (((Hero *)D_001A4BE0)->i[0x61C/4] == 0)) {
                            ((Hero *)D_001A4BE0)->i[0x61C/4] = -1;
                        }
                    } else {
                        var_f12_17 = -temp_f0_24 * 0.38197184f;
                        if (temp_f0_24 < -0.19198623f) {
                            ((Hero *)D_001A4BE0)->i[0x61C/4] = 1;
                        } else if ((temp_f0_24 > -0.122173056f) && (((Hero *)D_001A4BE0)->i[0x61C/4] == 1)) {
                            ((Hero *)D_001A4BE0)->i[0x61C/4] = -1;
                        }
                    }
                    if (((Hero *)D_001A4BE0)->f[0x614/4] < var_f12_17) {
                        func_003C4138((s32) (((void*)D_001A4BE0) + 0x614), var_f12_17, 0.0022222223f);
                    } else {
                        func_003C4138((s32) (((void*)D_001A4BE0) + 0x614), var_f12_17, 0.00055555557f);
                    }
                    if (((Hero *)D_001A4BE0)->f[0x614/4] > 0.20000002f) {
                        ((Hero *)D_001A4BE0)->f[0x614/4] = 0.20000002f;
                    }
                    if (((Hero *)D_001A4BE0)->f[0x614/4] < -0.041666668f) {
                        ((Hero *)D_001A4BE0)->f[0x614/4] = -0.041666668f;
                    }
                    temp_f0_25 = ((Hero *)D_001A4BE0)->f[0x620/4] + ((Hero *)D_001A4BE0)->f[0x614/4];
                    ((Hero *)D_001A4BE0)->f[0x5E4/4] = temp_f0_25;
                    if (temp_f0_25 < 0.0f) {
                        ((Hero *)D_001A4BE0)->f[0x5E4/4] = 0.0f;
                    }
                    temp_s0_6 = ((void*)D_001A4BE0) + 0x570;
                    func_00282CF0((s32) (((void*)D_001A4BE0) + 0xF0), (s32)((u128_t*)v0), (s32) temp_s0_6);
                    temp_s2_5 = ((void*)D_001A4BE0) + 0x80;
                    func_00282CF0((s32) ((u128_t*)v20), (s32) temp_s0_6, (s32) temp_s2_5);
                    sp10C = -func_0038CEA8((s32) ((u128_t*)v20));
                    func_L01_004482A0((s32) &sp10C, (s32) (((void*)D_001A4BE0) + 0x64C), 0.0f, 0.03f, 0.3f, 0.116666675f);
                    temp_f0_26 = func_0038CEA8((s32) ((u128_t*)v20));
                    if (temp_f0_26 < ((Hero *)D_001A4BE0)->f[0x64C/4]) {
                        ((Hero *)D_001A4BE0)->f[0x64C/4] = temp_f0_26;
                    }
                    temp_f12_3 = ((Hero *)D_001A4BE0)->f[0x64C/4];
                    if (temp_f12_3 < temp_f0_26) {
                        func_0038CF68((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), temp_f12_3);
                    }
                    func_00282CC0((s32) temp_s2_5, (s32) temp_s2_5, (s32) ((u128_t*)v20));
                    temp_f3 = ((Hero *)D_001A4BE0)->f[0x88/4];
                    temp_f2_4 = ((Hero *)D_001A4BE0)->f[0x578/4];
                    if (temp_f3 < temp_f2_4) {
                        if (((Hero *)D_001A4BE0)->f[0x33C/4] < 1.0f) {
                            if (temp_f3 < temp_f2_4) {
                                ((Hero *)D_001A4BE0)->f[0x88/4] = temp_f2_4;
                            }
                        }
                    }
                }
                if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x2A) {
                    if (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0x14) {
                        temp_f0_28 = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x5EC/4], func_L01_00443A18(0.3490659f, 0.6108653f));
                        v50[0] = func_0038D098(temp_f0_28);
                        v50[1] = func_0038D0B0(temp_f0_28);
                        v50[2] = 0.0f;
                        func_L01_00446760((s32) ((u128_t*)v20), (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, 1.0f, (s32) &v50[0]);
                        qcopy(v60, &((Hero *)D_001A4BE0)->q[0x80/16]);
                        v60[2] += 0.6f;
                        func_003D4D00(1.0f, (s32) ((u128_t*)v60), 0x10, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], (s32) ((u128_t*)v20));
                    }
                }
            }
        }
        break;
    case 0x76:                                      /* switch 1 */
        func_L01_004E9090(v0);
        hp71 = (Hero *)D_001A4BE0;
        if ((*(u8*)((s8 *)(hp71->ptr[0x2290/4]) + 0x43)) == 0x5F) {
            func_L01_004F4F18(0, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
            if (ref_L00_002BA7D8_00 & 1) {
                *(u128_t *)(v10) = *(u128_t *)(v0);
                func_0038CE20((s32) ((u128_t*)v20), (s32) (((void*)D_001A4BE0) + 0x110), 0.4f);
                temp_f20_71 = func_0038DAB8(((Hero *)D_001A4BE0)->f[0x6B0/4], func_L01_00443A18(0.0f, 0.52359885f));
                temp_f21_71 = func_003824E0(0.0f, 0.06666667f);
                v20[0] += func_0038D098(temp_f20_71) * temp_f21_71;
                v20[1] += func_0038D0B0(temp_f20_71) * temp_f21_71;
                v20[2] = func_003824E0(0.050000004f, 0.083333336f);
                v20[3] = -0.009722223f;
                func_L01_00466F50((s32) ((u128_t*)v10), (s32) ((u128_t*)v20), 0, -1.0f);
            }
        }
        func_L01_00476B98(((Hero *)D_001A4BE0)->i[0x690/4], (s32) ((u128_t*)v0), (s32) (((void*)D_001A4BE0) + 0x670), (s32) (((void*)D_001A4BE0) + 0x694), (s32) (((void*)D_001A4BE0) + 0x698), ((Hero *)D_001A4BE0)->i[0x6AC/4], 999.0f, 8.0f, 2.5f);
        cnt71 = ((Hero *)D_001A4BE0)->i[0x6A0/4];
        if (cnt71 != 0) {
            qcopy(&((Hero *)D_001A4BE0)->q[0xF0/16], &((Hero *)D_001A4BE0)->q[0x120/16]);
            ((Hero *)D_001A4BE0)->i[0x6A0/4] = cnt71 + 1;
            ((Hero *)D_001A4BE0)->f[0xF8/4] = ((Hero *)D_001A4BE0)->f[0xF8/4] - 0.0061111115f;
        } else {
            temp_f0_71 = ((Hero *)D_001A4BE0)->f[0x6A4/4];
            /* retail evaluates the float (fifth) argument first */
            ((s32 (*)(s32, s32, s32, s32, f32, s32))func_L01_00476498)(((Hero *)D_001A4BE0)->i[0x690/4], (s32) ((u128_t*)v10), (s32) (((void*)D_001A4BE0) + 0x694), (s32) (((void*)D_001A4BE0) + 0x698), temp_f0_71, ((Hero *)D_001A4BE0)->i[0x6AC/4]);
            idx71 = func_L01_00476440(((Hero *)D_001A4BE0)->i[0x690/4], ((Hero *)D_001A4BE0)->i[0x694/4], 1, ((Hero *)D_001A4BE0)->i[0x6AC/4]);
            func_00282CF0((s32) ((u128_t*)v20), (s32)((u8 *)((Hero *)D_001A4BE0)->ptr[0x690/4] + (idx71 * 16 + 0x10)), (s32) ((u128_t*)v10));
            if (func_0038CEA8((s32) ((u128_t*)v20)) < 0.001f) {
                if (((Hero *)D_001A4BE0)->i[0x694/4] == idx71) {
                    ((Hero *)D_001A4BE0)->i[0x6A0/4] = 1;
                    break;
                }
            } else {
                ((Hero *)D_001A4BE0)->f[0x6B0/4] = func_0038D160(v20[0], v20[1]);
                ((Hero *)D_001A4BE0)->f[0x6B4/4] = func_0038D160(func_0038CED8((s32) ((u128_t*)v20)), v20[2]);
            }
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = ((Hero *)D_001A4BE0)->f[0x6B0/4];
            func_L01_004EEDD0(0, 0.018f, 0.2f, 0.10762865f);
            func_003C4138((s32) (((void*)D_001A4BE0) + 0x6A4), 0.23333335f, 0.0025f);
            func_00282CF0((s32) (((void*)D_001A4BE0) + 0xF0), (s32) ((u128_t*)v10), (s32) (((void*)D_001A4BE0) + 0x670));
            func_00282CF0((s32) ((u128_t*)v20), (s32) (((void*)D_001A4BE0) + 0x670), (s32) ((u128_t*)v0));
            spN71 = -func_0038CEA8((s32) ((u128_t*)v20));
            func_L01_004482A0((s32) &spN71, (s32) (((void*)D_001A4BE0) + 0x6B8), 0.0f, 0.05f, 0.3f, 0.16666667f);
            temp_f0_71 = func_0038CEA8((s32) ((u128_t*)v20));
            if (temp_f0_71 < ((Hero *)D_001A4BE0)->f[0x6B8/4]) {
                ((Hero *)D_001A4BE0)->f[0x6B8/4] = temp_f0_71;
            }
            if (((Hero *)D_001A4BE0)->f[0x6B8/4] < temp_f0_71) {
                func_0038CF68((s32) ((u128_t*)v20), (s32) ((u128_t*)v20), ((Hero *)D_001A4BE0)->f[0x6B8/4]);
            }
            func_00282CC0((s32) (((void*)D_001A4BE0) + 0x80), (s32) (((void*)D_001A4BE0) + 0x80), (s32) ((u128_t*)v20));
        }
        break;
    case 0x17:                                      /* switch 1 */
    case 0x18:                                      /* switch 1 */
        func_00282CF0((s32)(D_001A4BE0 + 0x190), (s32)(D_001A4BE0 + 0x560), (s32)(D_001A4BE0 + 0x550));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EEDD0(0, 0.04f, 0.2f, 0.10471977f);
        if (((Hero *)D_001A4BE0)->b[0x25F4] != 2) {
            func_L01_00448690((s32)(D_001A4BE0 + 0x94), 0, 0.0f, 0.078539826f);
        }
        func_00282CF0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x550), (s32)(D_001A4BE0 + 0x80));
        func_002AC9F8((s32)(D_001A4BE0 + 0xF0), 0.06666667f);
        func_003C4138((s32)(D_001A4BE0 + 0x580), ((Hero *)D_001A4BE0)->f[0x88/4], 0.050000004f);
        break;
    case 0x46:                                      /* switch 1 */
    case 0x47:                                      /* switch 1 */
        func_00282CF0((s32)(D_001A4BE0 + 0x190), (s32)(D_001A4BE0 + 0x560), (s32)(D_001A4BE0 + 0x550));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EEDD0(0, 0.02f, 0.2f, 0.078539826f);
        func_00282CF0((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0x550), (s32)(D_001A4BE0 + 0x80));
        func_002AC9F8((s32)(D_001A4BE0 + 0xF0), 0.028333336f);
        func_003C4138((s32)(D_001A4BE0 + 0x580), ((Hero *)D_001A4BE0)->f[0x88/4], 0.050000004f);
        break;
    case 0x19:                                      /* switch 1 */
    case 0x1A:                                      /* switch 1 */
        func_00282CF0((s32)(D_001A4BE0 + 0x190), (s32)(D_001A4BE0 + 0x560), (s32)(D_001A4BE0 + 0x550));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EEDD0(0, 0.02f, 0.2f, 0.078539826f);
        func_00282CF0((s32) ((u128_t*)v60), (s32)(D_001A4BE0 + 0x560), (s32)(D_001A4BE0 + 0x550));
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x19) {
            func_0038CE90((s32) &v40[0], (s32)(D_001A4BE0 + 0x2C0), (s32) ((u128_t*)v60));
        } else {
            func_0038CE90((s32) &v40[0], (s32) ((u128_t*)v60), (s32)(D_001A4BE0 + 0x2C0));
        }
        func_0038CF68((s32) &v40[0], (s32) &v40[0], 0.2f);
        func_00282CC0((s32) &v50[0], (s32)(D_001A4BE0 + 0x80), (s32) &v40[0]);
        if ((func_L01_004E8318((s32)(D_001A4BE0 + 0x80), (s32)(D_001A4BE0 + 0x90), 0) != 0) && (func_L01_004E8318((s32) &v50[0], (s32)(D_001A4BE0 + 0x90), (s32)((u128_t*)v0)) != 0)) {
            func_00282CF0((s32)(D_001A4BE0 + 0xF0), (s32)((u128_t*)v0), (s32)(D_001A4BE0 + 0x80));
            var_v0_8 = func_00283CF0(((Hero *)D_001A4BE0)->f[0xC18/4]) * 4;
            var_v1_4 = (s32)D_L20_001ACEE8;
            func_0038CF68((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), *(f32*)(var_v0_8 + var_v1_4) * 0.5f);
        }
        break;
    /* rac2 states 0x76: no code in rac3 (dropped) */
    case 0x6:                                      /* switch 1 */
    case 0x2C:                                      /* switch 1 */
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x2C) {
            var_f12_18 = 0.0f;
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 4.0f) {
                var_f12_18 = 0.43633235f;
            }
            qcopy(v0, &((Hero *)D_001A4BE0)->q[0x90/16]);
            func_L01_00448728((s32) &v0[1], var_f12_18, (s32) (((void*)D_001A4BE0) + 0xA4), 0.02f, 0.3f, 0.043633237f, 0);
            func_L01_00448728((s32)((u128_t*)v0), 0.0f, (s32) (((void*)D_001A4BE0) + 0xA0), 0.02f, 0.3f, 0.043633237f, 0);
            func_L01_004E5290(((Hero *)D_001A4BE0)->f[0xA0/4], ((Hero *)D_001A4BE0)->f[0xA4/4], 0.0f);
            if (((Hero *)D_001A4BE0)->f[0x33C/4] > 1.0f) {
                ((Hero *)D_001A4BE0)->i[0x25C8/4] = 1;
            }
        }
        func_L01_004EEBA8();
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L01_004F1C88();
        }
        var_s1_5 = ((void*)D_001A4BE0) + 0xF0;
        func_L01_004F2E68();
        func_L01_004F0558(0.7f, 0.0f);
        func_L01_00510F08((s32) var_s1_5, (s32) var_s1_5, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_L01_005114B0((s32) var_s1_5) < -0.8333334f) {
            func_L01_00511508((s32) var_s1_5, (s32) var_s1_5, -0.8333334f);
        }
        break;
    case 0x79:                                      /* switch 1 */
        ((Hero *)D_001A4BE0)->c[0x25ED] = 1;
        var_s1_5_u2 = ((void*)D_001A4BE0) + 0xF0;
        func_003C4138((s32) (((void*)D_001A4BE0) + 0xA08), ((Hero *)D_001A4BE0)->f[0xA10/4], 0.0024240687f);
        func_003C4138((s32) (((void*)D_001A4BE0) + 0xA0C), ((Hero *)D_001A4BE0)->f[0xA14/4], 0.0024240687f);
        func_L01_004E5290(((Hero *)D_001A4BE0)->f[0xA08/4], ((Hero *)D_001A4BE0)->f[0xA0C/4], 0.0f);
        func_L01_0040E728((s32) var_s1_5_u2, (s32) var_s1_5_u2, func_0038CED8((s32) var_s1_5_u2) * 0.9f);
        func_L01_00510F08((s32) var_s1_5_u2, (s32) var_s1_5_u2, ((Hero *)D_001A4BE0)->f[0xA00/4]);
        if (func_L01_005114B0((s32) var_s1_5_u2) < -0.8333334f) {
            func_L01_00511508((s32) var_s1_5_u2, (s32) var_s1_5_u2, -0.8333334f);
        }
        break;
    case 0xB0:                                      /* rac3-only state 0xB0 body at 004FC324-004FC6BC: TODO not drafted */
        break;
    /* rac2 states 0x82: no code in rac3 (dropped) */
    case 0x8:                                      /* switch 1 */
        if (func_L01_004E9238(3) == 2) {
            temp_a2_3 = ((Hero *)D_001A4BE0)->i[0x279C/4];
            if (temp_a2_3 != -1) {
                temp_a0_16 = (temp_a2_3 * 0x70) + (s32)D_001A30B0;
                if (((*(s32*)((s8 *)(temp_a0_16) + 0x88)) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && ((*(u8*)((s8 *)(temp_a0_16) + 0x74)) != 0)) {
                    func_003A4F28(temp_a2_3);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x279C/4] = -1;
            func_L01_004F4F18(3, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 2);
        } else {
            temp_a2_4 = ((Hero *)D_001A4BE0)->i[0x2798/4];
            if (temp_a2_4 != -1) {
                temp_a0_17 = (temp_a2_4 * 0x70) + (s32)D_001A30B0;
                if (((*(s32*)((s8 *)(temp_a0_17) + 0x88)) == ((Hero *)D_001A4BE0)->ptr[0x25C0/4]) && ((*(u8*)((s8 *)(temp_a0_17) + 0x74)) != 0)) {
                    func_003A4F28(temp_a2_4);
                }
            }
            ((Hero *)D_001A4BE0)->i[0x2798/4] = -1;
            func_L01_004F4F18(4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0xD);
        }
        var_f22_2 = 0.050000004f;
        if (((Hero *)D_001A4BE0)->i[0x1318/4] == 3) {
            var_f22_2 = 0.083333336f;
        }
        var_f23 = 0.72f;
        temp_f1_12 = ((Hero *)D_001A4BE0)->f[0x284C/4];
        if (((Hero *)D_001A4BE0)->b[0x2873] != 0) {
            var_f22_2 = 0.12833333f;
            var_f23 = 0.98640007f;
        }
        if (temp_f1_12 != 0.0f) {
            var_f23 = temp_f1_12;
        }
        temp_s0_7 = ((void*)D_001A4BE0) + 0xF0;
        sp114 = func_L01_005114B0((s32) temp_s0_7);
        func_L01_004EE850(var_f22_2, 0);
        func_L01_004EEDD0(0, 0.025f, 0.3f, 0.20943955f);
        func_L01_004EF128(0.004166667f, 0.0019444445f);
        func_L01_004EF178(99999.0f);
        func_L01_004F2E68();
        func_L01_00511320((s32) temp_s0_7, (s32) temp_s0_7);
        func_L01_004482A0((s32) &sp114, (s32) (((void*)D_001A4BE0) + 0xA18), -var_f22_2 * var_f23, 0.025f, 0.3f, 0.28333336f);
        func_L01_00510F08((s32) temp_s0_7, (s32) temp_s0_7, -sp114);
        temp_f12_5 = ((Hero *)D_001A4BE0)->f[0x88/4];
        if (temp_f12_5 < ((Hero *)D_001A4BE0)->f[0x460/4]) {
            func_003C4138((s32) (((void*)D_001A4BE0) + 0x460), temp_f12_5, 0.06666667f);
        }
        func_L01_004E7780();
        break;
    case 0x7:                                      /* switch 1 */
    case 0x9:                                      /* switch 1 */
    case 0xA:                                      /* switch 1 */
    case 0xB:                                      /* switch 1 */
    case 0xC:                                      /* switch 1 */
    case 0xD:                                      /* switch 1 */
    case 0xE:                                      /* switch 1 */
    case 0xF:                                      /* switch 1 */
    case 0x10:                                      /* switch 1 */
    case 0x11:                                      /* switch 1 */
    case 0x12:                                      /* switch 1 */
    case 0x1B:                                      /* switch 1 */
    case 0x38:                                      /* switch 1 */
    case 0x45:                                      /* switch 1 */
    case 0x48:                                      /* switch 1 */
    case 0x54:                                      /* switch 1 */
    case 0x5F:                                      /* switch 1 */
    case 0x69:                                      /* switch 1 */
    case 0x6B:                                      /* switch 1 */
    case 0x73:                                      /* switch 1 */
    case 0x86:                                      /* switch 1 */
    case 0xA2:                                      /* switch 1 */
    case 0xA7:                                      /* switch 1 */
    case 0xAC:                                      /* switch 1 */
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x1B) && (((Hero *)D_001A4BE0)->h[0x2884/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1318/4] == 3)) {
            if (func_L01_004EE7F8(10.0f) != 0) {
                func_L01_004F4E70(4, 0);
            }
        }
        if ((((Hero *)D_001A4BE0)->h[0x4F8/2] != 0) && (((Hero *)D_001A4BE0)->b[0x1474] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = (f32) ((Hero *)D_001A4BE0)->f[0x1B4/4];
        } else {
            if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                func_L01_004EE850(0.09916667f, 0);
            }
            func_L01_004EE850(((Hero *)D_001A4BE0)->f[0x474/4], 0);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x12) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] == 0x14) {
                func_L01_004E5EB8(3, 0x10, 1);
                if (D_L23_001E01D0 != 0) {
                    func_L01_004C67A0(D_L23_001E01D0, D_L23_001E01D8, 0, ((Hero *)D_001A4BE0)->f[0x80/4], ((Hero *)D_001A4BE0)->f[0x84/4], 0.4f, 0.35f);
                }
            }
            temp_f1_13 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((temp_f1_13 >= 4.0f) && (temp_f1_13 <= 7.0f)) {
                func_L01_004E5C08(7, 0, 0);
            }
        }
        temp_a2_5 = ((Hero *)D_001A4BE0)->h[0x47C/2];
        temp_a1_8 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
        if (temp_a1_8 == temp_a2_5) {
            qcopy(&((Hero *)D_001A4BE0)->q[0x430/16], &((Hero *)D_001A4BE0)->q[0x80/16]);
        }
        if ((((Hero *)D_001A4BE0)->b[0x46C] != 0) || ((temp_a1_8 < temp_a2_5) && (temp_v1_33 = ((Hero *)D_001A4BE0)->u[0x25C4/4], (temp_v1_33 != 0xB)) && (temp_v1_33 != 0x10) && (temp_v1_33 != 0xC) && (temp_v1_33 != 0x11) && (temp_v1_33 != 0x1B) && (temp_v1_33 != 0x89) && (temp_v1_33 != 0x48))) {
            if (((Hero *)D_001A4BE0)->h[0x4F8/2] != 0) {
                func_L00_002B9598();
                if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0xA) && (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xA) && (((Hero *)D_001A4BE0)->f[0x178/4] < 0.116666675f)) {
                    ((Hero *)D_001A4BE0)->f[0xF0/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF0/4] + (func_0038D098(((Hero *)D_001A4BE0)->f[0x98/4]) * 0.011666667f));
                    ((Hero *)D_001A4BE0)->f[0xF4/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF4/4] + (func_0038D0B0(((Hero *)D_001A4BE0)->f[0x98/4]) * 0.011666667f));
                    qcopy(&((Hero *)D_001A4BE0)->q[0x140/16], &((Hero *)D_001A4BE0)->q[0xF0/16]);
                }
            } else {
                func_L01_004EEDD0(0, 0.015f, 0.2f, 0.2501639f);
                temp_f20_16 = ((Hero *)D_001A4BE0)->f[0x1B4/4];
                if ((u8) ((Hero *)D_001A4BE0)->b[0x46C] >= 2U) {
                    ((Hero *)D_001A4BE0)->f[0x1B4/4] = (f32) (temp_f20_16 * 0.4f);
                }
                if (((Hero *)D_001A4BE0)->h[0x1434/2] != 0) {
                    func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1438/4]);
                } else {
                    func_L01_004EF178(99999.0f);
                }
                ((Hero *)D_001A4BE0)->f[0x1B4/4] = temp_f20_16;
                if (((Hero *)D_001A4BE0)->b[0x46C] != 1) {
                    func_L01_004EF128(((Hero *)D_001A4BE0)->f[0x4D0/4], ((Hero *)D_001A4BE0)->f[0x4D4/4]);
                }
                if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                    if ((*(s32*)&D_00138354) != 0) {
                        if (((Hero *)D_001A4BE0)->h[0x36A/2] != 0) {
                            ((Hero *)D_001A4BE0)->f[0x1B4/4] = 0.0f;
                        }
                    }
                    if (((Hero *)D_001A4BE0)->b[0x46C] != 0) {
                        func_L01_004F4730(((Hero *)D_001A4BE0)->f[0x4D4/4]);
                    }
                }
                func_L01_004F0558(0.5f, 0.033333335f);
                if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 9) {
                    temp_v1_34 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                    if (temp_v1_34 < (((Hero *)D_001A4BE0)->h[0x47C/2] + 4)) {
                        func_L01_00511178((s32) (((void*)D_001A4BE0) + 0xF0), (s32) (((void*)D_001A4BE0) + 0xF0), (f32) temp_v1_34 * 0.0044444446f);
                    }
                }
                if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0xA) {
                    temp_v1_35 = ((Hero *)D_001A4BE0)->i[0x1B8/4];
                    if (temp_v1_35 < 0x22) {
                        func_L01_00511178((s32) (((void*)D_001A4BE0) + 0xF0), (s32) (((void*)D_001A4BE0) + 0xF0), (f32) temp_v1_35 * 0.014722222f);
                    }
                }
                if ((((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xA) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.2f)) {
                    qcopy(v0, &((Hero *)D_001A4BE0)->q[0x80/16]);
                    func_L01_00511280((s32)((u128_t*)v0), (s32)((u128_t*)v0), 0.5f);
                    func_L01_00511178((s32) ((u128_t*)v10), (s32)((u128_t*)v0), 0.95f);
                    if (func_003D3CB0((s32)((u128_t*)v0), (s32) ((u128_t*)v10), 4, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0) != 0) {
                        ((Hero *)D_001A4BE0)->h[0x4F4/2] = 1;
                    }
                }
            }
        } else {
            func_L01_004F1C88();
            if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x12) {
                temp_s0_8 = ((void*)D_001A4BE0) + 0xF0;
                var_f0_11 = func_0038CED8((s32) temp_s0_8);
                if (var_f0_11 > 0.06166667f) {
                    var_f0_11 = 0.06166667f;
                }
                func_0038CFB8((s32) temp_s0_8, (s32) temp_s0_8, var_f0_11);
            }
        }
        temp_f1_14 = ((Hero *)D_001A4BE0)->f[0x338/4];
        temp_f2_7 = ((Hero *)D_001A4BE0)->f[0x460/4];
        if (temp_f2_7 < temp_f1_14) {
            temp_f0_29 = temp_f2_7 + 0.10000001f;
            ((Hero *)D_001A4BE0)->f[0x460/4] = temp_f0_29;
            if (temp_f1_14 < temp_f0_29) {
                ((Hero *)D_001A4BE0)->f[0x460/4] = temp_f1_14;
            }
        }
        temp_f1_15 = ((Hero *)D_001A4BE0)->f[0x88/4];
        if (temp_f1_15 < ((Hero *)D_001A4BE0)->f[0x460/4]) {
            ((Hero *)D_001A4BE0)->f[0x460/4] = temp_f1_15;
        }
        if ((((Hero *)D_001A4BE0)->h[0x47C/2] < ((Hero *)D_001A4BE0)->i[0x1B8/4]) && (func_L01_005114B0((s32) (((void*)D_001A4BE0) + 0xF0)) < 0.001f) && ((((Hero *)D_001A4BE0)->b[0x46D] == 0) || (((Hero *)D_001A4BE0)->i[0x1B8/4] > ((Hero *)D_001A4BE0)->i[0x404/4])) && ((((Hero *)D_001A4BE0)->u[0x25C4/4] != 0xE) || (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0x12))) {
            temp_f1_16 = ((Hero *)D_001A4BE0)->f[0x428/4];
            ((Hero *)D_001A4BE0)->b[0x46E] = 1U;
            if (temp_f1_16 != 0.0f) {
                ((Hero *)D_001A4BE0)->f[0x4F0/4] = temp_f1_16;
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004F2E68();
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_L01_004F3BE0();
        }
        temp_v1_36 = ((Hero *)D_001A4BE0)->u[0x25C4/4];
        if ((temp_v1_36 == 0x10) || (temp_v1_36 == 0xD)) {
            func_L01_0044E468((s32) (((void*)D_001A4BE0) + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xD) ? 0 : 2);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x81) {
            func_L01_0044E468((s32) (((void*)D_001A4BE0) + 0x1B90), (((Hero *)D_001A4BE0)->i[0x1B8/4] < 0xE) ? 0 : 2);
        }
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x10) {
            if (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 9) {
                if (((Hero *)D_001A4BE0)->f[0xC18/4] < 28.0f) {
                    func_L01_005110E8((s32)((u128_t*)v0), 1, 0.8f, 0.0f, 0.3f);
                    temp_v0_17 = func_003D4D00(0.9f, (s32)((u128_t*)v0), 0, (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0);
                    if (temp_v0_17 != 0) {
                        func_0038CE20((s32) ((u128_t*)v10), (s32) (((void*)D_001A4BE0) + 0x110), 7.0f);
                        for (var_s0_2 = 0; var_s0_2 < temp_v0_17; var_s0_2++) {
                            if (func_003C4B50(((s32 *)D_L23_001EC800)[var_s0_2]) != 0) {
                                func_L01_00446A70(((s32 *)D_L23_001EC800)[var_s0_2], (s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], 0x10000, (s32) (((void*)D_001A4BE0) + 0x80), (s32) ((u128_t*)v10), 1.0f);
                            }
                        }
                    }
                }
            }
        }
        if ((((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x38) && (((Hero *)D_001A4BE0)->b[0x46E] == 0) && (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.025000002f)) {
            func_L01_004E60E8();
        }
        func_L01_004F1638();
        func_L01_004E7780();
        break;
    case 0x16:                                      /* switch 1 */
    case 0xB1:                                      /* switch 1 */
        var_f20_13 = func_L01_00511408((s32)(D_001A4BE0 + 0xF0));
        var_f0_12 = 0.0011111111f;
        if ((((Hero *)D_001A4BE0)->h[0x36E/2] == 0) && (((Hero *)D_001A4BE0)->i[0x1B8/4] >= 0xB)) {
            var_f0_12 = 0.0027777778f;
        }
        var_f20_13 = var_f20_13 - var_f0_12;
        if (var_f20_13 < 0.0f) {
            var_f20_13 = 0.0f;
        }
        if (((Hero *)D_001A4BE0)->b[0x1479] != 0) {
            func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        }
        var_s0_3 = ((void*)D_001A4BE0) + 0xF0;
        func_L01_00511588((s32) var_s0_3, (s32) var_s0_3, var_f20_13);
        func_L01_00510F08((s32) var_s0_3, (s32) var_s0_3, 0.004f);
        break;
    case 0x91:                                      /* switch 1 */
        *(u128_t *)(D_001A4CD0) = 0;
        ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.38333336f;
        break;
    case 0x66:                                      /* switch 1 */
        func_00282CF0((s32)((u128_t*)v0), (s32)(D_001A4BE0 + 0x18A0), (s32)(D_001A4BE0 + 0x80));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(v0[0], v0[1]);
        temp_f0_30 = func_0038CED8((s32)((u128_t*)v0));
        if (temp_f0_30 > 0.2f) {
            hp32 = (Hero *)D_001A4BE0;
            hp32->f[0x24B8/4] = 1.0f;
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(v0[0], v0[1]);
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = temp_f0_30;
            if (temp_f0_30 < D_L20_001A7DAC[0][2]) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = D_L20_001A7DAC[0][1] * 0.016666668f;
            } else {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = D_L20_001A7DAC[1][1] * 0.016666668f;
            }
            if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.015000001f;
            }
        } else {
            ((Hero *)D_001A4BE0)->f[0x2838/4] = 1.0f;
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0x1B4C/4];
            ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        }
        speed62 = 1.0f;
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 3) {
            func_L01_004EEDD0(0, 0.03f, 0.3f, 0.093084246f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 1) {
            func_L01_004EEDD0(0, 0.03f, 0.3f, 0.13089971f);
        } else if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004EEDD0(0, 0.03f, 0.3f, 0.13089971f);
        }
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L01_004F2E68();
        }
        func_L01_004EF128(speed62 * 0.005f, 0.0055555557f);
        func_L01_004EF178(99999.0f);
        if (((Hero *)D_001A4BE0)->b[0x25E4] == 0) {
            func_L20_002C7588(1);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x110, 0.0069444445f);
            func_L01_004EF268();
            break;
        }
        func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.015000001f);
        break;
    case 0x67:                                      /* switch 1 */
        func_00282CF0((s32)((u128_t*)v0), (s32)(D_001A4BE0 + 0x18A0), (s32)(D_001A4BE0 + 0x80));
        if (func_0038CE68((s32)((u128_t*)v0), (s32)(D_001A4BE0 + 0x160)) < 0.0f) {
            func_00282C88((s32)(D_001A4BE0 + 0x160));
        }
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        func_L01_004F4730(0.0075000003f);
        func_L20_002C7588(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32) ((void*)(D_001A4BE0 + 0xF0)), (s32) ((void*)(D_001A4BE0 + 0x18A0)) - 0x1790, 0.0069444445f);
            func_L01_004EF268();
            break;
        }
        func_L01_00510F08((s32) ((void*)(D_001A4BE0 + 0xF0)), (s32) ((void*)(D_001A4BE0 + 0xF0)), 0.015000001f);
        break;
    case 0x68:                                      /* switch 1 */
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        break;
    case 0x6A:                                      /* switch 1 */
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        if (((f32) ((Hero *)D_001A4BE0)->i[0x1B60/4] * 0.5f) < (((Hero *)D_001A4BE0)->f[0x354/4] - ((Hero *)D_001A4BE0)->f[0x88/4])) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.004166667f;
        } else {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.016666668f;
        }
        break;
    case 0x7E:                                      /* switch 1 */
        func_L00_002BA220();
        /* fallthrough */
    case 0x7D:                                      /* switch 1 */
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        (*(f32*)((s8 *)(((void*)(D_001A4BE0 + 0xF0))) + 8)) = -0.016666668f;
        break;
    case 0x7F:                                      /* switch 1 */
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        (*(f32*)((s8 *)(((void*)(D_001A4BE0 + 0xF0))) + 8)) = -0.0058333334f;
        break;
    case 0x3F:                                      /* switch 1 */
    case 0x43:                                      /* switch 1 */
        func_L01_004F52E0(3.7f, 0.0f, 0.35f);
        func_L01_004EE850(1.0f, 0);
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        func_L01_004EF128(0.0f, 0.0035f);
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        func_L20_002C7588(0);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32) ((void*)(D_001A4BE0 + 0xF0)), (s32) ((void*)D_001A4BE0) + 0x130, 0.0069444445f);
            func_L01_004EF268();
            break;
        }
        func_L01_00510F08((s32) ((void*)(D_001A4BE0 + 0xF0)), (s32) ((void*)(D_001A4BE0 + 0xF0)), 0.015000001f);
        break;
    case 0x4D:                                      /* switch 1 */
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.0f;
        temp_v1_37 = (s32) &D_L23_002F72D0[((Hero *)D_001A4BE0)->h[0xBDC/2]];
        temp_a0_21 = (*(s32*)((s8 *)(temp_v1_37) + 4));
        switch (temp_a0_21) {
        case 0:
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 5.5f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.058333337f;
            }
            break;
        case 1:
            if (((Hero *)D_001A4BE0)->f[0xC18/4] < 5.5f) {
                ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.058333337f;
            }
            break;
        }
        if (((Hero *)D_001A4BE0)->i[0xC0C/4] == 0) {
            temp_f1_17 = ((Hero *)D_001A4BE0)->f[0xC18/4];
            if ((f32) (*(s32*)((s8 *)(temp_v1_37) + 0x1C)) <= temp_f1_17) {
                if (temp_f1_17 <= (f32) (*(s32*)((s8 *)(temp_v1_37) + 0x20))) {
                    temp_s0_9 = (((*(s32*)((s8 *)(temp_v1_37) + 4)) ^ 1) == 0) ? 0 : 2;
                    func_003C2F58((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], temp_s0_9, (s32) ((u128_t*)v10));
                    func_003C2F58((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], temp_s0_9 | 1, (s32) ((u128_t*)v20));
                    func_00282CC0((s32)((u128_t*)v0), (s32) ((u128_t*)v10), (s32) ((u128_t*)v20));
                    func_0038CE20((s32)((u128_t*)v0), (s32)((u128_t*)v0), 0.5f);
                    func_L01_00446780((s32) ((Hero *)D_001A4BE0)->ptr[0x25C0/4], (s32)((u128_t*)v0), 0x10000, 0.25f, 1.0f, 1.0f, 0, 1, 0);
                }
            }
        }
        func_003C4138((s32)(D_001A4BE0 + 0xC20), 1.0f, 0.2f);
        if ((((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) || (((Hero *)D_001A4BE0)->i[0xBC4/4] != 0)) {
            ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0xBCC/4];
            func_L01_004EEDD0(0, 0.05f, 0.2f, 0.2821616f);
        } else {
            func_L01_004F2880(5.0f, 0.78539824f, 0.78539824f);
        }
        func_L01_004EF128(0.010277778f, 0.007777778f);
        if (((Hero *)D_001A4BE0)->i[0xBC8/4] != 0) {
            if (((Hero *)D_001A4BE0)->b[0x25F4] == 2) {
                func_L01_004EF238((s32) (((void*)D_001A4BE0) + 0xBA0));
            } else {
                func_L01_004EF178(((Hero *)D_001A4BE0)->f[0xBCC/4]);
            }
        } else {
            func_L01_004EF178(99999.0f);
        }
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = (f32) (((Hero *)D_001A4BE0)->f[0x118/4] - 0.0069444445f);
            func_L01_004EF268();
        } else {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = (f32) (((Hero *)D_001A4BE0)->f[0xF8/4] - 0.015000001f);
        }
        func_L01_004F52E0(0.7f, 0.0f, 0.3f);
        break;
    case 0x4B:                                      /* switch 1 */
        func_L01_004EE850(0.033333335f, 0);
        func_L01_004EEDD0(0, 0.04f, 0.2f, 0.14544412f);
        func_L01_004EF128(0.004166667f, 0.0019444445f);
        func_L01_004EF178(99999.0f);
        func_L01_00511320((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0));
        func_L01_00510F08((s32) ((void*)(D_001A4BE0 + 0xF0)), (s32) ((void*)(D_001A4BE0 + 0xF0)), 0.024000002f);
        break;
    case 0x4F:                                      /* switch 1 */
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = (f32) ((Hero *)D_001A4BE0)->f[0x34C/4];
        ((Hero *)D_001A4BE0)->f[0x1B0/4] = 0.09166667f;
        func_L01_004F1220(0.0069444445f);
        var_f12_16_u2 = 0.005f;
        var_a1_5_u2 = ((void*)D_001A4BE0) + 0x130;
        func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32) var_a1_5_u2, var_f12_16_u2);
        break;
    case 0x4F:                                      /* rac3-only state 0x4F body at 004FDC74-004FDC98: TODO not drafted */
        break;
    case 0x41:                                      /* switch 1 */
        func_L01_004EE850(0.050000004f, 0);
        if (((Hero *)D_001A4BE0)->h[0x1E0/2] == 0) {
            func_L01_004F1C88();
        }
        func_L01_00510F08((s32) (((void*)D_001A4BE0) + 0xF0), (s32) (((void*)D_001A4BE0) + 0xF0), 0.0033333334f);
        if (((Hero *)D_001A4BE0)->f[0xF8/4] < -0.16666667f) {
            ((Hero *)D_001A4BE0)->f[0xF8/4] = -0.16666667f;
        }
        break;
    case 0x44:                                      /* switch 1 */
        if (((Hero *)D_001A4BE0)->f[0xF8/4] > 0.0f) {
            func_L01_004E5290(0.0f, 0.20943955f, 0.0f);
        }
        func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.0055555557f);
        break;
    case 0x40:                                      /* switch 1 */
    case 0x4C:                                      /* switch 1 */
        func_L01_004EE850(0.050000004f, 0);
        var_f14 = 0.16580631f;
        var_f12_21 = 0.033f;
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            var_f14 = 0.19489513f;
            var_f12_21 = 0.037f;
        }
        func_L01_004EEDD0(0, var_f12_21, 0.15f, var_f14);
        func_L01_004EF128(0.005f, 0.0055555557f);
        if (((Hero *)D_001A4BE0)->f[0x174/4] < 0.011666667f) {
            ((Hero *)D_001A4BE0)->b[0x3EC] = 1U;
            if ((func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.7453294f) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 1U;
            }
        }
        temp_f20_18 = func_L01_00460818(0);
        if ((func_0038DBA0(temp_f20_18, func_L01_00460818(2)) > 2.617994f) && (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) > 1.2217306f) && (((Hero *)D_001A4BE0)->f[0x2838/4] > 0.8f)) {
            ((Hero *)D_001A4BE0)->b[0x3EF] = 1U;
            ((Hero *)D_001A4BE0)->b[0x3EC] = 1U;
        }
        if (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.087266475f) {
            ((Hero *)D_001A4BE0)->b[0x3EC] = 0U;
        }
        if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
            if (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) < 0.06981318f) {
                ((Hero *)D_001A4BE0)->b[0x3EF] = 0U;
            }
            if (((Hero *)D_001A4BE0)->b[0x3EF] != 0) {
                var_f2_4 = 0.050000004f - (func_00282C48(((Hero *)D_001A4BE0)->f[0x1A8/4]) * 0.02122066f);
                if (var_f2_4 < 0.0f) {
                    var_f2_4 = 0.0f;
                }
                if (var_f2_4 < ((Hero *)D_001A4BE0)->f[0x1B0/4]) {
                    ((Hero *)D_001A4BE0)->f[0x1B0/4] = var_f2_4;
                }
            }
        }
        if (((Hero *)D_001A4BE0)->b[0x3EC] != 0) {
            func_L01_004EF178(((Hero *)D_001A4BE0)->f[0x1A0/4]);
        } else {
            func_L01_004EF178(99999.0f);
        }
        func_L20_002C7588(1);
        if (((Hero *)D_001A4BE0)->h[0x36E/2] != 0) {
            func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0x130, 0.0069444445f);
            func_L01_004EF268();
        } else {
            func_L01_00510F08((s32) ((void*)D_001A4BE0) + 0xF0, (s32) ((void*)D_001A4BE0) + 0xF0, 0.015000001f);
        }
        break;
    case 0x42:                                      /* switch 1 */
        temp_f12_6 = func_0038CED8((s32)(D_001A4BE0 + 0xF0));
        if (*(s16 *)(D_001A4BE0 + 0x34E) != 0) {
            temp_f12_6 = temp_f12_6 * 0.99f;
        } else {
            temp_f12_6 = temp_f12_6 * 0.92f;
        }
        func_L01_0040E728((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), temp_f12_6);
        temp_v1_38 = ((void*)(D_001A4BE0 + 0xF0)) - 0xF0;
        (*(s32*)((s8 *)(temp_v1_38) + 0xF8)) = 0;
        if ((*(s16*)((s8 *)(temp_v1_38) + 0x34E)) != 0) {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0) + 0x30, 0.0061111115f);
        } else {
            func_L01_00510F08((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), 0.004f);
        }
        break;
    case 0x49:                                      /* switch 1 */
    case 0x4A:                                      /* switch 1 */
        ((Hero *)D_001A4BE0)->f[0xC00/4] = 1.3f;
        func_00282CF0((s32)(D_001A4BE0 + 0x190), (s32)(D_001A4BE0 + 0x560), (s32)(D_001A4BE0 + 0x550));
        ((Hero *)D_001A4BE0)->f[0x1A0/4] = func_0038D160(((Hero *)D_001A4BE0)->f[0x190/4], ((Hero *)D_001A4BE0)->f[0x194/4]);
        func_L01_004EEDD0(0, 0.02f, 0.2f, 0.078539826f);
        func_00282CF0((s32) ((u128_t*)v60), (s32)(D_001A4BE0 + 0x560), (s32)(D_001A4BE0 + 0x550));
        func_00282C88((s32) (((void*)D_001A4BE0) + 0xF0));
        if (((Hero *)D_001A4BE0)->u[0x25C4/4] == 0x49) {
            func_0038CE90((s32) &v40[0], (s32) (((void*)D_001A4BE0) + 0x2E0), (s32) ((u128_t*)v60));
        } else {
            func_0038CE90((s32) &v40[0], (s32) ((u128_t*)v60), (s32) (((void*)D_001A4BE0) + 0x2E0));
        }
        func_0038CF68((s32) &v40[0], (s32) &v40[0], 0.2f);
        func_00282CC0((s32) &v50[0], (s32)(D_001A4BE0 + 0x80), (s32) &v40[0]);
        if ((func_L01_004E8318((s32)(D_001A4BE0 + 0x80), (s32)(D_001A4BE0 + 0x90), 0) != 0) && (func_L01_004E8318((s32) &v50[0], (s32)(D_001A4BE0 + 0x90), (s32)((u128_t*)v0)) != 0)) {
            func_00282CF0((s32)(D_001A4BE0 + 0xF0), (s32)((u128_t*)v0), (s32)(D_001A4BE0 + 0x80));
            func_0038CF68((s32)(D_001A4BE0 + 0xF0), (s32)(D_001A4BE0 + 0xF0), D_L20_00298970[func_00283CF0(((Hero *)D_001A4BE0)->f[0xC18/4])] * 0.5f);
            break;
        }
        break;
    case 0x37:                                      /* switch 1 */
        if ((*(u8*)((s8 *)(((Hero *)D_001A4BE0)->ptr[0x25C0/4]) + 0x43)) == 0x44) {
            func_L01_004EEDD0(0, 0.137f, 0.25f, 0.20362177f);
        } else {
            func_L01_004EEDD0(0, 1.0f, 0.1f, 0.40724355f);
        }
        break;
    case 0x3C:                                      /* switch 1 */
    case 0x64:                                      /* switch 1 */
    case 0x65:                                      /* switch 1 */
        func_00282C88((s32)(D_001A4BE0 + 0xF0));
        break;
    case 0x61:                                      /* switch 1 */
        /* TODO rac3-only states: 0x51/0x56/0x59 at 004FE1B0, 0x57/0x7B at 004FE254, 0x58 at 004FE2A0, 0x53 at 004FE2B4, 0x52 at 004FE35C, 0x55 at 004FE4CC (not drafted) */
        break;
    case 0x4E:                                      /* switch 1 */
    case 0x51:                                      /* switch 1 */
    case 0x56:                                      /* switch 1 */
    case 0x57:                                      /* switch 1 */
    case 0x59:                                      /* switch 1 */
    case 0x5B:                                      /* switch 1 */
    case 0x5C:                                      /* switch 1 */
    case 0x5D:                                      /* switch 1 */
    case 0x5E:                                      /* switch 1 */
    case 0x62:                                      /* switch 1 */
    case 0x7B:                                      /* switch 1 */
        /* TODO states without a seed counterpart: 0x62 at 004E09AC, 0x5c at 004E0AA4, 0x5b at 004E0B70, 0x5d/0x5e at 004E1088, 0x51/0x56/0x59 at 004E11A8, 0x4e/0x57/0x7b at 004E124C (not drafted) */
        break;
    }
    if (sp118 != ((Hero *)D_001A4BE0)->i[0x25C8/4]) {
        ((Hero *)D_001A4BE0)->i[0x1C0/4] = 0;
    }
    if (sp11C != (*(u8*)((s8 *)(temp_fp) + 0x43))) {
        ((Hero *)D_001A4BE0)->i[0x1C4/4] = 0;
    }
}

