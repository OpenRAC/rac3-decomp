/* func_L19_004F9D80: Opus handoff (prep by Sonnet worker w3, 2026-11-08)
   Size: 29004 bytes, places: 1 level (19), file: src/levels/19_thran_asteroid_belt/L19_004F9D80.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu $sp,-0x140, one jr $31). One dispatcher: switch on the hero state (hero+0x25C4, u32, sltiu 0xB2 = 178 table entries, one jr $4 jump table); all four 0x110-family members share it.
   rac2 twin: func_L20_002DEBE0 (rac2-decomp src/levels/20_yeedil/L20_002DEBE0-decider.c, matched), opcode similarity 0.8131 vs the L20 twin (L22_002D0C98 0.8045, L00_002CB3A8 0.7966, L13_002D5ED8 0.7932); 0.9660 vs the rac3 seed func_L01_00507AF8 (7225 of 7251 opcodes).
   Family: seed func_L01_00507AF8 (30,828 B); L19_004F9D80 0.966, L23_004EAE60 0.949, L30_004D7368 0.920 to it. Work the seed first, derive the others from it.
   Mapping (hero base D_001A4BE0 in rac3, D_00189E20 in rac2; offsets are a step function, not a constant shift):
     delta by rac2 offset (votes from opcode-aligned load/store pairs of seed vs L20 twin, noisy under 0x278): 0x0:+128 0xC:+0 0x50:+92 0x60:+0 0x134:-20 0x170:+0 0x278:+32 0x40E:-32 0x430:-48 0x578:-80 0x5D8:-96 0xA80:-128 0xBFC:-32 0x1492:-30 0x1500:-728 0x2290:+816 0x22B7:+817 0x2320:+816 0x2434:+864 0x24A0:+876 0x24B0:+896 0x24C4:+900 0x24EC:+904
     e.g. state 0x2294 -> 0x25C4, cur object 0x2290 -> 0x25C0, 0x229C -> 0x25CC, 0x2298 -> 0x25C8, 0x123C -> 0x121C, 0x22B4 -> 0x25E4. Objects reached through hero pointers (obj+0x43 etc.) are unchanged.
     pad: rac2 reads D_00138180 as a struct; rac3 reads a pointer, `extern u8 *D_001D52FC;` then pad[0x1A0] etc (retail lui 0x1d + lw 0x52fc). rac2 `pad[0x1A0] & M` (M = 4, 8, 0x40) is `pad[0x1A0] & func_003A3BB8(M, 0)` in rac3, and for most M == 4 sites `& func_L01_00512DF8(func_003A3BB8(4, 0))` (7 of 8 flagged by alignment). rac2 `func_L00_0032EF10(M, a, b)` (button-mask test) is `func_L01_004606E8(M, a, b, 0)` in rac3; M = 0x40 and 8 come as `func_003A3BB8(M, 0)` first, 0x80 / 0xA / 0x1F000 / 0x28 direct (verified against the retail call sites).
     64-bit: rac3 plain C needs `long` / `unsigned long` (EE long is 64-bit), `long long` hits "unsupported wide integer operation". rac2 s64 -> long, LL -> L.
     128-bit: qcopy/qzero -> `*(s128 *)d = *(s128 *)s;` with `typedef int u128_t __attribute__((mode(TI))); typedef u128_t s128;`. `*(s128 *)v = 0` compiles (a bare `sq $zero` cannot be forced; not yet compared).
     abs.s helper func_00282C48 -> __builtin_fabsf, cvt.w.s helper func_00283CF0 -> (s32)(x). Both rac2 core leaf asm functions have no rac3 callee at those places.
     callee renames from opcode-aligned jal / %hi %lo pairs (kit p3.py): 104 of them, e.g. func_L20_002D7730 (set state) -> func_L01_005003D0, func_L20_002B7A48 -> func_L01_004DFDB0, func_L00_002D2168 -> func_L01_0050FB40, func_L00_0032EF10 -> func_L01_004606E8; the full list is applied in the code below (names in rac3 level space are the catalogue names, shared functions keep their func_L01_ spelling). Still unresolved (stay as rac2 names or were folded): func_00282CC0 (vector op, 2 uses), func_L20_002DC390, func_L18_002C4000, func_00117650.
   Relative to the seed: Versus the seed (align.py rac3 rac3): 29 non-equal blocks, only 3 of 12+ instr. The big one: the seed has 399 extra instructions at seed 0x5087D0-0x508E0C (case blocks {32,34}, {33}, {36}, {35}, i.e. the 0x32-0x36 states) that L19 does not have; L19 has 22 + 29 instructions of its own at seed 0x50A304-0x50A42C (case {66} area). Everything else is the seed with different constants/offsets. So: finish the seed, delete the 0x32-0x36 case bodies, adjust case 66.
   Draft here is the same mechanical port as the seed (donor func_L20_002DEBE0), NOT built from the seed draft; once the seed matches, redo the port from the matched seed C (align.py against the seed gives 0.92-0.97 and the block list above).
   Draft: compiles with the file's flags; 6976 diff rows (chk.sh, level 19), compiled 26272 bytes vs retail 29004, equal opcodes 4778 of 7251 (ratio 0.692); retail frame -0x140.
     Register allocation diverges from retail everywhere: retail keeps only %hi(D_001A4BE0) in $s3 and re-forms `addiu $x,$s3,0x4BE0` at each use (hero base rematerialised, plain offsets after), while the draft keeps the full base in one callee-saved register (`u8 *hero = D_001A4BE0;` at the top, which is the closest form found; `D_001A4BE0 + off` folds the offset into the %lo and is wrong; a typed struct global gave the same single-register result in a small test).
   Left for Opus: (1) the seed first; then the sibling-only blocks listed above; (2) the base-pointer rematerialisation above and the -0x140/-0x150 frame (retail spills the four entry values to $sp+0xA8..0xB4 first, as the draft does with sp74..sp80; the aligned(16) vector locals v10/v20/v30 probably move); (3) the 1-5 instruction changes per case, found by `chk.sh --keep-object` + kit gaps.py/opc.py after each batch; (4) callees whose prototypes were guessed from rac2 (return types of func_L01_004606E8 (s32), func_003A3BB8 (s32, s32), func_L01_00512DF8 (long)). The 0x32-0x36 case group has a hand translation in ~/RACSwarm/rac3-api/jobs/func_L01_00507AF8/func.c (17 of ~60 blocks, older, partial) as a cross-check.
   Tools: ~/RACSwarm/plans/rac3-large/out/w3-kit/ (all.sh runs port + chk + opcode/jal/gap measures for the four; p3.py = port.py with opcode-level alignment; conv.py/build.py = FLD/offset/pad conversion).
*/
/* ported from rac2-decomp func_L20_002DEBE0 (src/levels/20_yeedil/L20_002DEBE0-decider.c) */


typedef int u128_t __attribute__((mode(TI)));
typedef u128_t s128;

extern u8 *D_001D52FC;

extern char D_001425C0[];

extern char D_001A30B0[];

extern char D_001A4BE0[];

extern u8 D_00143A05[];

extern u8 D_00142CA0[];

extern s32 D_00142B98;

extern f32 D_L19_001DBD44[][4];

extern s32 D_L19_001DBD74;

extern s32 D_L19_001D6780;

extern f32 D_L19_001DF330;

extern s32 D_L19_002D4030;

extern s32 D_L19_001DF248;

extern s32 D_L19_002D3AC4;

extern u8 D_L19_001DBC10[16] ;

extern u8 D_L19_001DBC20[16] ;

extern s32 D_L19_001DBD70[2] ;

extern char D_L19_002F6C30[];

extern char D_L19_002F6E40[];

typedef struct { s32 w[11]; } Rec2C;

extern Rec2C D_L19_002F8BD0[];

extern char D_L19_002C8040[];

extern char D_L19_001E2100[];

s32 func_003D3CB0(void *, void *, s32, void *, s32);

s32 func_L01_003FB640(void *, s32, void *, f32);

s32 func_0038CAD0(void *);

s32 func_0038CB00(s16 *);


void func_00282CC0(void *, void *, void *);

void func_0038CE20(void *, void *, f32);

f32 func_0038CEA8(void *);

f32 func_0038CED8(void *);

f32 func_0038CF00(void *, void *);

f32 func_0038CF38(void *, void *);

void func_0038CF68(void *, void *, f32);

f32 func_0038D098(f32);

f32 func_0038D0B0(f32);

f32 func_0038DAB8(f32 a0, f32 a1);

f32 func_0038DBA0(f32 a0, f32 a1);


void func_00393348(s32, s32, void *, void *, void *, s32, s32);

void func_00393BE8(u8 *object);

void func_00393C40(s8 *);

s32 func_00394620(s8 *);

void func_00394F48(void *a0);

void func_00394F90(u8 *object);

void func_00395478();

void func_003C2F58(s8 *a0, s32 a1, s8 *a2);

void func_003C3A10(u8 *object, s32 animation, s32 frame, s32 rate);

s32 func_00382498(s32 a0, s32 a1);

f32 func_003824E0(f32 a0, f32 a1);

f32 func_003C4138(f32 *value, f32 target, f32 step);

void func_003C4BB0(f32 *, f32);

void func_003A4F28(s32 a0);

s32 func_L01_004DFDB0(s32 arg);

u32 func_L01_004DFE80(u32 param_1);

void func_L01_004E1180(void);

void func_L01_004E11C0(s32 kind, s32 side, s32 play_sound, s32 duration);

void func_L01_004E1560(void);

void func_L01_004E5030(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

void func_L01_004E5EB8(s32 dust, s32 debris, s32 model);

s32 func_L01_004E63F0(f32 *out, f32 scale, f32 amount);

s32 func_L01_004E8318(s8 *, s8 *, s8 *);

s32 func_L01_004E9238(s32 index);

void func_L01_004EAA80(void);

void func_L01_004EDE10(void);

s32 func_L01_004EDFA8(u8 *object);

s32 func_L01_004EDFC8(f32 x);

void func_L01_004EE850(s32, f32);

void func_L01_004EEBA8(void);

s32 func_L01_004F4E70(s32 index, s32 flags);

s32 func_L01_004FF5D8(void);

s32 func_L19_004F32A0(s32, s32);

void func_L20_002DC390(s32 a0);

s32 func_L00_002C8C00(void);

s32 func_L00_002C8CB0(void);

s32 func_L01_00504EC0(void);

s32 func_L01_005055A0(void);

s32 func_L01_00506298(s32 arg0, s32 arg1);

void func_L01_005063E8(void);

void func_L01_00506820(void);

s32 func_L01_00506888(s32 *selected);

void func_L01_00506BB0(void);

s32 func_L01_00506E30(void);

s32 func_L01_005070E0(void);

s32 func_L01_00507268(void);

void func_L01_00507380(void);

void func_L01_005075D8(void);

void func_L01_00507738(void);

void func_L01_0050F368(void);

void func_L01_0050FB40(s32 a0, s32 a1, f32 f12);

void func_L01_0050FED0(void);

void func_L01_0050FEE8(s32 value);

f32 func_L19_00501FE0(f32 time, f32 acceleration, f32 height);

void func_L01_00510CA0(s16, u8, u8, u8, f32, f32);

void func_0038D000(f32 *p, s32 flag, f32 x, f32 y, f32 z);

f32 func_L01_005114B0(s8 *in);

void func_L01_00511508(void *dst, void *src, f32 k);

f32 func_L01_00511748(f32 *a0, f32 *a1, s32 *out, f32 scale);

void func_003E54E0(s32 argument);

void func_003E4D10(s32 argument);

f32 func_L01_00445EE0(f32 *a0, f32 *a1, s32 *a2, f32 factor);

f32 func_L01_00447878(f32 *a, f32 *b, f32 *out, f32 d, f32 e);

void func_L01_00456230(u8 *entity, s32 enabled);

s32 func_L01_004606E8(s32, s32, void *, s32);
s32 func_003A3BB8(s32, s32);

void *func_L01_0046E078(s8 *object,void *position,f32 *velocity,s32 *config,s32 flag);

s32 func_L01_00476498(void *path, void *out, s32 *index, f32 *offset, s32 wrap, f32 step);

s32 func_L01_00476B98(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);

s32 func_L01_003EB2D8(void);

s32 func_L19_004E1D60(s32);

s32 func_L01_004E8BC8(s8 *, void **, s128 *, void *, void *, s32 *, void *, s32, s32);


void func_L18_002C4000(void);

void func_L19_004F9D80(void) {
    u8 *hero = D_001A4BE0;
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    s32 sp40;
    s32 sp44;
    s32 sp48;
    f32 sp4C;
    void *sp50;
    void *sp54;
    void *sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    s32 sp6C;
    s32 sp70;
    s32 sp74w;
    void *sp74;
    s32 sp78;
    s32 sp7C;
    s32 sp80;
    s32 temp_a0_11;
    s32 temp_a0_31;
    s32 pad3C;

    sp74 = (*(void * *)(hero + 0x25c0));
    sp78 = (*(s32 *)(hero + 0xa8));
    sp7C = (*(s32 *)(hero + 0x25c8));
    sp80 = (*(u8 *)((u8 *)sp74 + 0x43));
    if (func_L19_004E1D60(1) != 0) {
        goto end;
    }
    func_L01_00507380();
    if ((*(s32 *)(hero + 0x2850)) <= 0) {
        if (((*(u32 *)(hero + 0x25c4)) == 0) || ((*(u32 *)(hero + 0x25c4)) == 2)) {
            func_L19_004F32A0(0x39, 1);
            goto end;
        }
    }
    if (func_L01_005055A0() != 0) {
        goto end;
    }
    if ((func_L01_00504EC0() != 0) || (func_L00_002C8CB0() != 0) || (func_L00_002C8C00() != 0)) {
        goto end;
    }
    if ((((*(s32 *)(D_001D52FC + 0x1A4)) & 0x10) || ((*(s32 *)(D_001D52FC + 0x1C4)) & 0x10)) && ((*(u8 *)(hero + 0x121c)) != 2) && (D_L19_002D4030 == 0) && (D_00143A05[1] == 0) && (D_L19_001DF248 >= 8)) {
        if ((((*(u8 *)(hero + 0x25ed)) == 0) || ((*(u8 *)(hero + 0x25e4)) == 1) || ((*(s16 *)(hero + 0x1d2)) != 0))
            && (((*(u8 *)(hero + 0x25e7)) == 0) || ((*(u8 *)(hero + 0x25e4)) == 1) || ((*(s16 *)(hero + 0x1d2)) != 0))) {
            switch ((*(u8 *)(hero + 0x25e4))) {
            case 0:
            case 3:
                if ((*(s16 *)(hero + 0x2882)) != 0) {
                    (*(s16 *)(hero + 0x287e)) = 0x1B;
                } else {
                    (*(s16 *)(hero + 0x287e)) = 0xF;
                }
                func_00393348(0x23, 0, func_00393BE8, func_00393C40, func_00394620, 0, 0);
                func_003E4D10(0x168);
                func_003E54E0(0xB4);
                break;
            case 1:
                func_00393348(0x23, 0, func_00394F48, func_00394F90, func_00395478, 0, 0);
                break;
            }
        }
    }
    func_L01_005075D8();
    func_L01_00507738();
    if ((*(f32 *)(hero + 0x88)) < D_L19_001DF330) {
        if (((*(f32 *)(hero + 0x33c)) > 2.0f) && ((*(u8 *)(hero + 0x25e4)) != 2) && ((*(u32 *)(hero + 0x25c4)) != 0x74)) {
            if ((*(u8 *)(hero + 0x25e4)) == 4) {
                func_L19_004F32A0(0x91, 1);
                goto end;
            }
            func_L19_004F32A0(0x74, 1);
            goto end;
        }
    }
    if (((*(u8 *)(hero + 0x25e4)) == 4) && ((*(f32 *)(hero + 0x88)) < (*(f32 *)((u8 *)(*(void * *)((u8 *)(*(void * *)(hero + 0x25c0)) + 0x68)) + 0x3EC)))) {
        func_L19_004F32A0(0x91, 1);
    }
    switch ((*(u32 *)(hero + 0x25c4))) {
    case 0x0:
    {
        s32 notcrouch;
        s32 anim;
        u8 *obj;
        if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ((*(s32 *)(hero + 0x1228)) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        func_L01_0050FED0();
        if ((*(u8 *)(hero + 0x2877)) != 0) {
            func_L19_004F32A0(0x82, 1);
            break;
        }
        notcrouch = (*(u8 *)(hero + 0x1474)) == 0;
        {
        s32 one = 1;
        (*(s8 *)(hero + 0x1436)) = 0;
        if ((*(s32 *)(hero + 0x1314)) == 2) {
            obj = (*(u8 * *)(hero + 0x12f0));
            if ((obj != 0) && ((*(u8 *)((u8 *)obj + 0x60)) & 2) && ((*(u8 *)((u8 *)obj + 0x43)) != one)) {
                func_003C3A10(obj, one, 0, 7);
            }
            obj = (*(u8 * *)(hero + 0x12f4));
            if ((obj != 0) && ((*(u8 *)((u8 *)obj + 0x60)) & 2) && ((*(u8 *)((u8 *)obj + 0x43)) != 1)) {
                func_003C3A10(obj, 1, 0, 7);
            }
        }
        }
        if (((*(f32 *)((u8 *)D_L19_002F6E40 + 0x258)) > 0.6108653f) || ((*(f32 *)((u8 *)D_L19_002F6E40 + 0x254)) > 0.43633235f)) {
            obj = (*(u8 * *)(hero + 0x12f0));
            if ((obj != 0) && ((*(u8 *)((u8 *)obj + 0x43)) != 1)) {
                func_003C3A10(obj, 1, 0, 0xC);
            }
            obj = (*(u8 * *)(hero + 0x12f4));
            if ((obj != 0) && ((*(u8 *)((u8 *)obj + 0x43)) != 1)) {
                func_003C3A10(obj, 1, 0, 0xC);
            }
        }
        anim = func_L01_004DFE80((*(u8 *)((u8 *)sp74 + 0x43)));
        if ((anim == func_L01_004DFDB0(0)) && notcrouch) {
            if (func_L01_00506888(&sp40) != 0) {
                u8 *rec;
                (*(s16 *)(hero + 0x208)) = 0x78;
                (*(s32 *)(hero + 0x27ec)) = sp40;
                rec = D_L19_002F6C30 + sp40 * 0x70;
                (*(s32 *)((u8 *)rec + 0x60)) = (*(f32 *)((u8 *)rec + 0x5C)) * 60.0f;
                if ((*(s32 *)((u8 *)rec + 0x44)) != 0) {
                    func_L19_004F32A0(0x3C, 1);
                } else {
                    func_L01_0050FB40((*(s32 *)((u8 *)rec + 0x48)), 0, 12.0f);
                }
            }
        } else if ((*(s32 *)(hero + 0xc08)) & 2) {
            s32 keep = 0;
            if (((*(u8 *)(hero + 0x25e9)) != 0) && ((*(u8 *)(hero + 0x25eb)) != 0) && (((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == (*(s32 *)(hero + 0x2830))) || ((*(s32 *)(hero + 0xe78)) != 0))) {
                keep = 1;
            }
            if (keep == 0) {
                (*(s8 *)(hero + 0x25e9)) = 0;
                if (func_L01_004DFDB0(0) == 0x51) {
                    func_L01_0050FB40(func_L01_004DFDB0(0), 0, 18.0f);
                } else {
                    func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
                }
            }
        }
        if ((*(s32 *)(hero + 0x1b8)) >= 0xB) {
            u8 *o2 = (*(u8 * *)(hero + 0x12f4));
            if ((o2 != 0) && ((*(u8 *)((u8 *)o2 + 0x43)) == 1) && (func_0038CAD0(hero + 0x286c) != 0) && ((*(f32 *)((u8 *)D_L19_002F6E40 + 0x258)) < 0.5585054f) && ((*(f32 *)((u8 *)D_L19_002F6E40 + 0x254)) < 0.3490659f) && ((*(s32 *)(hero + 0x1314)) == 2)) {
                (*(s32 *)(hero + 0x286c)) = func_00382498(0x6E, 0x10E);
                func_L01_0050F368();
            }
        }
        if (((*(u8 *)(hero + 0x25e9)) != 0) && ((*(s32 *)(hero + 0xc0c)) == 0) && ((*(u8 *)(hero + 0x25eb)) != 0) && ((*(s16 *)(hero + 0x2874)) == 0)) {
            s32 slot = func_L01_004E9238(0);
            if (slot != (*(s32 *)(hero + 0x2834))) {
                func_L01_004EAA80();
            } else {
                s32 want = (*(s32 *)((u8 *)D_L19_002C8040 + ((u8 *)D_001425C0)[slot] * 0xE0 + 0x28));
                if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != want) {
                    if ((*(s32 *)(hero + 0xe78)) != 0) {
                        (*(s32 *)(hero + 0xe84)) = 1;
                    }
                    (*(s32 *)(hero + 0x2830)) = want;
                    func_L01_0050FB40(want, 0, -4.0f);
                }
            }
        }
        func_L01_004EE850(0, 1.0f);
        if (((*(u8 *)(hero + 0x147c)) != 0) && ((*(s16 *)(hero + 0x36c)) == 0)) {
            func_L19_004F32A0(0x76, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) >= 5) && ((*(f32 *)(hero + 0x33c)) > 0.4f)) {
            if (((*(s32 *)(hero + 0x25d0)) != 8) || ((*(s32 *)(hero + 0x1b8)) >= 0xF)) {
                func_L19_004F32A0(6, 1);
            }
            break;
        }
        if ((*(s16 *)(hero + 0x1e0)) != 0) {
            break;
        }
        {
            s32 ok = 1;
            if (((*(s32 *)(hero + 0x25d0)) == 1) || ((*(s32 *)(hero + 0x25d0)) == 0x1D)) {
                if ((*(s32 *)(hero + 0x1b8)) <= 4) {
                    ok = 0;
                }
            }
            if (ok && ((*(s16 *)(hero + 0x368)) != 1)) {
                if (func_L01_00506298(((*(s16 *)(hero + 0x1ee)) != 0) ? 1 : 7, 0) != 0) {
                    break;
                }
            }
        }
        if (((*(s16 *)(hero + 0x368)) == 1) && (D_L19_001D6780 == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0)) {
            func_L19_004F32A0(0x6E, 1);
            break;
        }
        if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) && ((*(s32 *)(hero + 0x360)) != 0)) {
            if (((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != 0x1A) || ((*(f32 *)(hero + 0xc18)) >= 108.0f)) {
                func_L19_004F32A0(4, 1);
                break;
            }
        }
        if ((*(s32 *)(hero + 0x5dc)) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        if (((*(u8 *)(hero + 0x1474)) != 0) && ((*(f32 *)(hero + 0x340)) > 0.087266475f)) {
            func_L19_004F32A0(0x2E, 1);
            break;
        }
        {
            s32 go = 1;
            s32 turned;
            if ((((*(s32 *)(hero + 0x25d0)) == 1) || ((*(s32 *)(hero + 0x25d0)) == 0x1D)) && ((*(s32 *)(hero + 0x1b8)) < 0x18) && ((*(s16 *)(hero + 0x368)) != 1)) {
                func_L01_004EE850(0, 1.0f);
                if ((func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)((u8 *)D_L19_001E2100 + 0x158))) > 1.2217306f) && (func_0038CF00(hero + 0x80, D_L19_001E2100 + 0x140) < 2.5f)) {
                    go = 0;
                }
            }
            turned = func_L01_004EDFC8(0.17453295f);
            if (go == 0) {
                break;
            }
            if ((turned != 0) || ((*(f32 *)(hero + 0x2838)) > 0.22f)) {
                s32 side = (*(u8 *)(hero + 0x147f));
                func_L01_004E11C0(side, 0, 0, 0x1E);
                func_L01_004E11C0(side, 1, 0, 0x1E);
                func_L19_004F32A0(2, 1);
            }
        }
        break;
    }
    case 0x3C:
        if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ((*(s32 *)(hero + 0x1228)) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) != 0) || ((pad3C = (*(s32 *)(D_001D52FC + 0x1A0))) & 0x40) || (pad3C & 8)) {
            func_L19_004F32A0(0x3D, 1);
            break;
        }
        func_L01_004EEBA8();
        if ((*(f32 *)(hero + 0x1b0)) > 0.0f) {
            func_L19_004F32A0(0x3D, 1);
            break;
        }
        if ((*(s32 *)(hero + 0xc08)) & 2) {
            func_L01_00506820();
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x3D:
        if ((*(s32 *)(hero + 0x1b8)) < 9) {
            break;
        }
        func_L01_00506820();
        if ((*(s16 *)(hero + 0x36e)) != 0) {
            func_L19_004F32A0(6, 1);
            break;
        }
        if (func_L01_00506298(7, 0) != 0) {
            break;
        }
        if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
            func_L19_004F32A0(4, 1);
            break;
        }
        func_L01_004EEBA8();
        if ((*(f32 *)(hero + 0x1b0)) > 0.0f) {
            func_L19_004F32A0(2, 1);
            break;
        }
        func_L19_004F32A0(0, 1);
        break;
    case 0x39:
    case 0x43:
    case 0x5F:
    case 0x67:
    case 0x7D:
    case 0x7F:
        if (((*(s32 *)(hero + 0xc08)) & 2) || ((*(u8 *)(hero + 0x25f1)) != 0)) {
            if ((*(s16 *)(hero + 0x21e)) != 0) {
                (*(u8 *)(hero + 0x25f1)) = 1;
                (*(s32 *)(hero + 0xc00)) = 0;
                func_0038CB00(hero + 0x21e);
                return;
            }
            func_L01_004EDE10();
            return;
        }
        break;
    case 0x7C:
        if ((*(s32 *)(hero + 0x1b8)) < 0xDD) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x32:
    case 0x34:
    {
        u32 st = (*(u32 *)(hero + 0x25c4));
        if (st == 0x32) {
            f32 h;
            (*(f32 *)(hero + 0xc00)) = (*(f32 *)(hero + 0x1b4)) * 15.0f;
            if ((*(f32 *)(hero + 0xc00)) < 0.25f) {
                (*(f32 *)(hero + 0xc00)) = 0.25f;
            }
            if ((*(f32 *)(hero + 0xc00)) > 0.75f) {
                (*(f32 *)(hero + 0xc00)) = 0.75f;
            }
            if (((*(u32 *)(hero + 0x25c4)) == st) && !((*(s32 *)(D_001D52FC + 0x1A0)) & 0xC0) && ((h = (*(f32 *)(hero + 0xc18))) > 9.0f) && (h < 19.0f) && ((*(s32 *)(hero + 0x25c8)) != 1) && ((*(f32 *)(hero + 0x2838)) < 0.1f) && ((*(f32 *)(hero + 0x1b4)) < 0.033333335f)) {
                func_L19_004F32A0(0x33, 1);
                break;
            }
        }
        if (((*(s16 *)(hero + 0x2884)) == 0) && ((*(s32 *)(D_001D52FC + 0x1A0)) & 0xA)) {
            if (((*(u32 *)(hero + 0x25c4)) == 0x32) && ((*(s32 *)(hero + 0x1b8)) >= 0x15)) {
                func_L19_004F32A0(0x34, 1);
                break;
            }
        } else if ((*(u32 *)(hero + 0x25c4)) == 0x34) {
            if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
                func_L19_004F32A0(0x32, 1);
                break;
            }
        }
        if ((*(u32 *)(hero + 0x25c4)) == 0x34) {
            s32 pad = (*(s32 *)(D_001D52FC + 0x1A0));
            if (!(pad & 0xC0) && ((*(s32 *)(hero + 0x25c8)) != 1) && ((*(f32 *)(hero + 0x2838)) < 0.7f) && !(pad & 0xA)) {
                func_L19_004F32A0(0x33, 1);
            }
        }
        break;
    }
    case 0x33:
    {
        s32 pad;
        if (((*(s32 *)(hero + 0xc08)) & 2) && ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != 0x3C)) {
            func_L01_0050FB40(0x3C, 0, 11.0f);
        }
        if (((*(f32 *)(hero + 0x2838)) > 0.2f) || ((pad = (*(s32 *)(D_001D52FC + 0x1A0))) & 0xC0) || (((*(s16 *)(hero + 0x2884)) == 0) && (pad & 0xA))) {
            if ((*(s16 *)(hero + 0x2884)) != 0) {
                func_L19_004F32A0(0x32, 1);
            } else if ((*(s32 *)(D_001D52FC + 0x1A0)) & 0xA) {
                func_L19_004F32A0(0x34, 1);
            } else {
                func_L19_004F32A0(0x32, 1);
            }
        }
        break;
    }
    case 0x36:
        if (((*(s16 *)(hero + 0x1f8)) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) && ((*(s32 *)(hero + 0x1b8)) >= 0xB)) {
            func_L19_004F32A0(0x12, 1);
            break;
        }
        (*(u8 *)(hero + 0x25e7)) = 1;
        if (((*(s16 *)(hero + 0x1fe)) == 0) && ((*(s32 *)((u8 *)(*(u8 * *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x24)) + 0x134)) != 0)) {
            if ((func_L01_004606E8(0x80, 7, 0, 0) != 0) || (((*(s16 *)(hero + 0x2884)) == 0) && (func_L01_004606E8(0xA, 7, 0, 0) != 0))) {
                if ((*(s16 *)(hero + 0x2884)) != 0) {
                    func_L19_004F32A0(0x32, 1);
                } else if ((*(s32 *)(D_001D52FC + 0x1A0)) & 0xA) {
                    func_L19_004F32A0(0x34, 1);
                } else {
                    func_L19_004F32A0(0x32, 1);
                }
                break;
            }
        }
        if (((*(u8 *)(hero + 0x25ea)) != 0) && ((*(f32 *)(hero + 0x2844)) < 0.4f) && (func_L19_004F32A0(0, 0) != 0)) {
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, 18.0f);
        }
        if (((*(f32 *)(hero + 0x2838)) > 0.2f) && ((*(s32 *)(hero + 0x1b8)) >= 0xB)) {
            func_L19_004F32A0(0x35, 1);
        }
        break;
    case 0x35:
        if (((*(s16 *)(hero + 0x1f8)) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0)) {
            func_L19_004F32A0(0x12, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x1fe)) == 0) && ((*(s32 *)((u8 *)(*(u8 * *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x24)) + 0x134)) != 0) && (func_L01_004606E8(0x80, 7, 0, 0) != 0)) {
            if ((*(s16 *)(hero + 0x2884)) != 0) {
                func_L19_004F32A0(0x32, 1);
            } else if ((*(s32 *)(D_001D52FC + 0x1A0)) & 0xA) {
                func_L19_004F32A0(0x34, 1);
            } else {
                func_L19_004F32A0(0x32, 1);
            }
            break;
        }
        if (((*(u8 *)(hero + 0x25ea)) != 0) && ((*(f32 *)(hero + 0x2844)) < 0.7f)) {
            func_L19_004F32A0(0x70, 0);
            func_L01_0050FB40(0x59, 0, 17.0f);
            (*(s32 *)(hero + 0xf8)) = 0;
            (*(s32 *)(hero + 0x118)) = 0;
        }
        if (((*(f32 *)(hero + 0x2838)) < 0.1f) && ((*(f32 *)(hero + 0x1b4)) == 0.0f) && ((*(s32 *)(hero + 0x738)) == 0)) {
            func_L19_004F32A0(0x36, 1);
        }
        break;
    case 0x73:
        if ((*(s32 *)(hero + 0x2850)) <= 0) {
            func_L19_004F32A0(0x67, 1);
            func_L01_0050FB40(0x58, 0x28, 18.0f);
        } else if ((*(s32 *)(hero + 0xc08)) & 2) {
            func_L19_004F32A0(0x33, 1);
        } else if ((*(s32 *)(hero + 0x1b8)) >= 0x33) {
            func_L19_004F32A0(0x33, 0);
        }
        break;
    case 0x72:
        if ((*(s32 *)(hero + 0x2850)) <= 0) {
            func_L19_004F32A0(0x67, 1);
            func_L01_0050FB40(0x58, 0x25, 18.0f);
        } else if ((*(s32 *)(hero + 0x1b8)) >= 0x33) {
            func_L19_004F32A0(0x36, 0);
        }
        break;
    case 0x1:
    {
        u8 *p;
        s32 ok;
        s32 late;
        s32 anim;
        if (((*(u8 *)(hero + 0x25e4)) == 0) && (((*(u8 *)(hero + 0x25eb)) == 0) || ((*(u8 *)(hero + 0x25e5)) != 0))) {
            if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 8.0f);
            } else {
                s32 a = func_L01_004DFDB0(1);
                if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != a) {
                    func_L01_0050FB40(a, 0, 8.0f);
                }
            }
        }
        p = (*(u8 * *)(hero + 0x1200));
        ok = 1;
        if ((p != 0) && (func_L01_004EDFA8(p) != 0)) {
            if ((*(u8 *)((u8 *)p + 0x20)) != 0) {
                ok = 0;
            }
        }
        late = 0;
        if ((*(u8 *)(hero + 0x25e5)) == 0) {
            late = (*(s32 *)(hero + 0x1b8)) >= 0x1F;
        }
        if ((!((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ok) || late) {
            if ((*(u8 *)(hero + 0x25e4)) != 0) {
                func_L20_002DC390(0);
            } else if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
                func_L19_004F32A0(4, 1);
            } else {
                func_L19_004F32A0(0, 0);
                anim = func_L01_004DFDB0(1);
                if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != anim) {
                    func_L01_0050FB40(anim, 0, 8.0f);
                }
            }
        }
        break;
    }
    case 0x2F:
        if (!((*(s32 *)(D_001D52FC + 0x1A0)) & (*(s32 *)(hero + 0x1210))) && ((*(s16 *)(hero + 0x1ec)) == 0)) {
            if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 0x36) {
                func_L19_004F32A0(0, 0);
            } else {
                func_L19_004F32A0(0, 1);
            }
        }
        break;
    case 0x14:
    {
        u8 *rec;
        s32 frames;
        if ((*(u32 *)(hero + 0x25c4)) == 0x14) {
            s32 n = (s32)(func_L19_00501FE0(60.0f, 0.036111113f, -1.0f));
            f32 c00 = (*(f32 *)(hero + 0xbe0));
            s32 top = 0x1A;
            if (c00 == 0.0f) {
                (*(f32 *)(hero + 0xc00)) = 0.33f;
            } else if ((c00 != 0.0f) && ((*(s16 *)(hero + 0x36e)) != 0) && (n != 0) && (((f32)top - (*(f32 *)(hero + 0xc18))) > 1.0f)) {
                func_L01_004E5030((f32)top, (f32)n, 0.5f, -1.0f);
                if (((*(f32 *)(hero + 0x33c)) < 0.7f) && ((*(f32 *)(hero + 0xc00)) < 0.75f)) {
                    (*(f32 *)(hero + 0xc00)) = 0.75f;
                }
            } else if (((*(s16 *)(hero + 0x36e)) == 0) && ((*(f32 *)(hero + 0xc18)) < (f32)top)) {
                (*(f32 *)(hero + 0xc00)) = 2.0f;
            } else {
                (*(f32 *)(hero + 0xc00)) = 1.0f;
            }
        }
        rec = (u8 *)&D_L19_002F8BD0[(*(s16 *)(hero + 0xbdc))];
        frames = ((s32)((*(f32 *)(hero + 0xc18))) - (*(s32 *)((u8 *)rec + 0xC))) * 2;
        if ((f32)(*(s32 *)((u8 *)rec + 0x14)) < (*(f32 *)(hero + 0xc18))) {
            if ((*(s32 *)(hero + 0xc0c)) != 0) {
                break;
            }
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                if (!((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0))) {
                    func_L19_004F32A0(7, 1);
                    break;
                }
                if (func_L01_00506E30() != 0) {
                    break;
                }
            }
        }
        if (((*(s32 *)(hero + 0xc0c)) == 0) && ((f32)(*(s32 *)((u8 *)rec + 0x18)) < (*(f32 *)(hero + 0xc18)))) {
            func_L19_004F32A0(0, 0);
        }
        break;
    }
    case 0x13:
    case 0x15:
    {
        u8 *rec = (u8 *)&D_L19_002F8BD0[(*(s16 *)(hero + 0xbdc))];
        s32 frames = ((s32)((*(f32 *)(hero + 0xc18))) - (*(s32 *)((u8 *)rec + 0xC))) * 2;
        u32 st = (*(u32 *)(hero + 0x25c4));
        s32 lim;
        f32 h;
        if (st == 0x15) {
            frames = 8;
        }
        if ((f32)(*(s32 *)((u8 *)rec + 0x14)) < (*(f32 *)(hero + 0xc18))) {
            if ((*(s32 *)(hero + 0xc0c)) != 0) {
                goto tail13;
            }
            if ((st != 0x15) || ((*(s16 *)(hero + 0x368)) != 1)) {
                if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                    if (!((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0))) {
                        func_L19_004F32A0(7, 1);
                        break;
                    }
                    if (func_L01_00506E30() != 0) {
                        break;
                    }
                }
            }
        }
        if ((*(s32 *)(hero + 0xc0c)) != 0) {
            goto tail13;
        }
        if (((*(f32 *)(hero + 0xc18)) > 34.0f) && ((*(f32 *)(hero + 0x2838)) > 0.9f)) {
            func_L19_004F32A0(2, 0);
            func_L01_0050FB40(3, D_L19_001DBD70[(*(s32 *)(hero + 0x25c8))], 13.0f);
            break;
        }
        if ((*(s32 *)(hero + 0xc0c)) != 0) {
            goto tail13;
        }
        lim = (*(s32 *)((u8 *)rec + 0x18));
        h = (*(f32 *)(hero + 0xc18));
        if ((f32)lim < h) {
            if ((*(f32 *)(hero + 0x2838)) > 0.8f) {
                func_L19_004F32A0(2, 1);
                break;
            }
            if ((f32)(lim + 5) < h) {
                func_L19_004F32A0(0, 0);
                break;
            }
            if ((*(s32 *)(hero + 0xc08)) & 2) {
                func_L19_004F32A0(0, 0);
            }
            break;
        }
    tail13:
        if ((*(u32 *)(hero + 0x25c4)) == 0x15) {
            if ((*(s32 *)(hero + 0x1228)) != 0xA) {
                func_L19_004F32A0(0, 1);
                break;
            }
            if (((*(s32 *)(hero + 0x1b8)) >= 0x65) && ((*(s32 *)(hero + 0xc24)) < 0x1A)) {
                func_L01_0050FEE8(2);
                (*(s32 *)(hero + 0xc24)) = 0x1A;
            }
        }
        break;
    }
    case 0x83:
        if ((*(f32 *)(hero + 0xc18)) > 37.0f) {
            if ((*(s32 *)(hero + 0xc0c)) != 0) {
                goto tail83;
            }
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
                if (!((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0))) {
                    func_L19_004F32A0(7, 1);
                    break;
                }
                if (func_L01_00506E30() != 0) {
                    break;
                }
            }
        }
        if (((*(s32 *)(hero + 0xc0c)) == 0) && ((*(f32 *)(hero + 0xc18)) > 37.0f)) {
            func_L19_004F32A0(0, 0);
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, 15.0f);
            break;
        }
    tail83:
        if (((*(u32 *)(hero + 0x25c4)) == 0x15) && ((*(s32 *)(hero + 0x1b8)) >= 0x65) && ((*(s32 *)(hero + 0xc24)) < 0x1A)) {
            func_L01_0050FEE8(2);
            (*(s32 *)(hero + 0xc24)) = 0x1A;
        }
        break;
    case 0x77:
        if ((*(s32 *)(hero + 0xc08)) & 2) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x2:
    case 0x2E:
    case 0x70:
    {
        s32 n;
        s32 turned;
        u32 st;
        if (((*(u8 *)(hero + 0x3ee)) != 0) && (((*(f32 *)((u8 *)sp74 + 0x44)) > 0.9f) || ((*(u8 *)((u8 *)sp74 + 0x42)) != 0xFF))) {
            (*(u8 *)(hero + 0x3ee)) = 0;
        }
        if (((*(u8 *)(hero + 0x147c)) != 0) && ((*(s16 *)(hero + 0x36c)) == 0)) {
            func_L19_004F32A0(0x76, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) >= 5) && (((*(s32 *)(hero + 0x25d4)) != 0x12) || ((*(u8 *)(hero + 0x25ea)) == 0)) && ((*(f32 *)(hero + 0x33c)) > 1.35f) && (func_L01_005070E0() == 0)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        n = 9;
        if ((*(s16 *)(hero + 0x1ee)) != 0) {
            n = 1;
        }
        if ((func_L01_004606E8(func_003A3BB8(0x40, 0), n, 0, 0) != 0) && (((*(s16 *)(hero + 0x36e)) < 5) || ((*(s16 *)(hero + 0x202)) != 0))) {
            func_L01_004EE850(0, 1.0f);
            if (func_L01_00506298(n, 1) != 0) {
                break;
            }
            if ((*(f32 *)(hero + 0x2838)) > 0.85f) {
                if ((*(s16 *)(hero + 0x1434)) == 0) {
                    func_L19_004F32A0(9, 1);
                } else {
                    func_L19_004F32A0(7, 1);
                }
            } else {
                func_L19_004F32A0(7, 1);
            }
            break;
        }
        if ((*(s16 *)(hero + 0x36e)) != 0) {
            break;
        }
        if ((((*(u8 *)(hero + 0x1474)) == 0) || (((*(f32 *)(hero + 0x174)) < 0.033333335f) && ((*(f32 *)(hero + 0x340)) < 0.087266475f))) && ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ((*(s32 *)(hero + 0x1228)) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
            func_L19_004F32A0(4, 1);
            break;
        }
        if (((*(u8 *)(hero + 0x1474)) != 0) && ((*(u32 *)(hero + 0x25c4)) == 0x2E)) {
            f32 speed = func_0038CED8(hero + 0x110);
            s32 anim;
            if (((*(f32 *)(hero + 0x2838)) < 0.17f) && (((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 0x37) || (((anim = (*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43))) == func_L01_004DFDB0(0)) && ((*(f32 *)(hero + 0x340)) > 0.087266475f))) && ((*(s32 *)(hero + 0x1cc)) >= 9) && ((*(s32 *)(hero + 0xc0c)) == 0)) {
                func_L01_0050FB40(0x66, 0, 14.0f);
            } else if (((*(f32 *)(hero + 0x2838)) > 0.3f) && ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != 0x37) && ((*(s32 *)(hero + 0xc0c)) == 0)) {
                func_L01_0050FB40(0x37, 0, 14.0f);
            } else if (((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 0x66) && ((*(s32 *)(hero + 0xc0c)) == 0) && ((*(f32 *)(hero + 0x2838)) < 0.17f) && ((*(f32 *)(hero + 0x340)) < 0.087266475f) && (speed < 0.028333336f)) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 20.0f);
            }
        }
        st = (*(u32 *)(hero + 0x25c4));
        if ((st == 2) || (st == 0x7B)) {
            if ((*(u8 *)(hero + 0x1474)) != 0) {
                func_L19_004F32A0(0x2E, 1);
            }
        } else if (st == 0x2E) {
            if ((*(u8 *)(hero + 0x1474)) == 0) {
                func_L19_004F32A0(2, 1);
            }
        }
        st = (*(u32 *)(hero + 0x25c4));
        if (st == 2) {
            if ((*(u8 *)(hero + 0x25ea)) != 0) {
                func_L19_004F32A0(0x70, 1);
            }
        } else if (st == 0x70) {
            if ((*(u8 *)(hero + 0x25ea)) == 0) {
                func_L19_004F32A0(2, 1);
            }
        }
        if ((*(s32 *)(hero + 0x5dc)) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        turned = func_L01_004EDFC8(0.03490659f);
        st = (*(u32 *)(hero + 0x25c4));
        if (st == 2) {
            if ((((*(f32 *)(hero + 0x2838)) < 0.17f) || ((*(s16 *)(hero + 0x1e0)) != 0)) && (turned == 0) && (((*(s32 *)(hero + 0x3f0)) == 0) || (__builtin_fabsf((*(f32 *)(hero + 0x1a8))) < 0.017453294f))) {
                s32 anim;
                if (func_L01_00507268() != 0) {
                    break;
                }
                if (func_L19_004F32A0(0, 0) == 0) {
                    break;
                }
                func_003C4BB0(hero + 0x160, 0.025000002f);
                if ((*(f32 *)(hero + 0x1b4)) > 0.025000002f) {
                    (*(f32 *)(hero + 0x1b4)) = 0.025000002f;
                }
                anim = func_L01_004DFDB0(1);
                if (anim == 0x51) {
                    func_L01_0050FB40(0x51, 0, 15.0f);
                } else {
                    func_L01_0050FB40(anim, 0, -1.0f);
                }
            } else {
                func_L01_005063E8();
            }
        } else if (st == 0x2E) {
            if (((*(s32 *)(D_001D52FC + 0x1D4)) != 0) && (func_0038CED8(hero + 0xf0) < 0.0008333334f) && ((*(f32 *)(hero + 0x340)) < 0.087266475f) && (func_L19_004F32A0(0, 0) != 0)) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 17.0f);
            }
            if ((*(u8 *)((u8 *)sp74 + 0x43)) == 0x37) {
                (*(f32 *)(hero + 0xc00)) = (1.0f - (*(f32 *)(hero + 0x420))) * 2.0f;
                if ((*(f32 *)(hero + 0xc00)) > 1.7f) {
                    (*(f32 *)(hero + 0xc00)) = 1.7f;
                }
                if ((*(f32 *)(hero + 0xc00)) < 0.75f) {
                    (*(f32 *)(hero + 0xc00)) = 0.75f;
                }
            } else if ((*(u8 *)((u8 *)sp74 + 0x43)) == 0x66) {
                (*(f32 *)(hero + 0xc00)) = (*(f32 *)(hero + 0x170)) * 10.0f;
                if ((*(f32 *)(hero + 0xc00)) > 1.1f) {
                    (*(f32 *)(hero + 0xc00)) = 1.1f;
                }
                if ((*(f32 *)(hero + 0xc00)) < 0.3f) {
                    (*(f32 *)(hero + 0xc00)) = 0.3f;
                }
            }
        } else if (st == 0x70) {
            if (((*(s32 *)(D_001D52FC + 0x1D4)) != 0) && (func_0038CED8(hero + 0xf0) < 0.05333334f) && (func_L19_004F32A0(0, 0) != 0)) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 17.0f);
            }
            (*(f32 *)(hero + 0xc00)) = (*(f32 *)(hero + 0x170)) * 35.0f;
            if ((*(f32 *)(hero + 0xc00)) < 0.6f) {
                (*(f32 *)(hero + 0xc00)) = 0.6f;
            }
            if ((*(f32 *)(hero + 0xc00)) > 1.05f) {
                (*(f32 *)(hero + 0xc00)) = 1.05f;
            }
        }
        break;
    }
    case 0x7B:
    {
        s32 one = 1;
        s32 flag = 0;
        if ((*(s16 *)(hero + 0x368)) != 0) {
            flag = 1;
        }
        if (!((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0))) {
            if ((*(s32 *)(hero + 0x1b8)) >= 0x3D) {
                flag = one;
            }
        }
        if ((*(u8 *)(hero + 0x25e9)) != 0) {
            flag = one;
        }
        if (flag != 0) {
            if ((*(s32 *)(hero + 0x2635)) != 0) {
                (*(s32 *)(hero + 0x2650)) = one;
            }
            func_L01_004F4E70(9, 0);
            (*(s16 *)(hero + 0x1e0)) = 0x1E;
            func_L19_004F32A0(3, 0);
            func_L01_0050FB40(6, 4, 11.0f);
        } else {
            if ((*(u8 *)(hero + 0x2a7)) != 0) {
                f32 a = func_0038CEA8(hero + 0x110);
                if (a < func_0038CEA8(hero + 0xf0) * 0.75f) {
                    func_L19_004F32A0(0x77, 1);
                    break;
                }
                if (func_L01_004E63F0(0, 1.0f, 1.25f) != 0) {
                    func_L19_004F32A0(0x77, 1);
                    break;
                }
            }
            *(s128 *)v30 = 0;
            v30[0] = -0.083333336f;
            func_003C2F58((*(s8 * *)(hero + 0x25c0)), 0x16, (s8 *)v10);
            func_003C2F58((*(s8 * *)(hero + 0x25c0)), 0x17, (s8 *)v20);
            func_L01_0046E078((*(s8 * *)(hero + 0x25c0)), v10, v30, (s32 *)D_L19_001DBC10, 1);
            func_L01_0046E078((*(s8 * *)(hero + 0x25c0)), v10, v30, (s32 *)D_L19_001DBC20, 1);
            func_L01_0046E078((*(s8 * *)(hero + 0x25c0)), v20, v30, (s32 *)D_L19_001DBC10, 1);
            func_L01_0046E078((*(s8 * *)(hero + 0x25c0)), v20, v30, (s32 *)D_L19_001DBC20, 1);
        }
        break;
    }
    case 0x62:
        if (func_0038CF38(hero + 0x80, hero + 0x15c8) < 0.2f) {
            if (((*(f32 *)(hero + 0x170)) < 0.045f) && (func_0038DBA0((*(f32 *)(hero + 0x98)), (*(f32 *)(hero + 0x15d4))) < 0.03490659f)) {
                func_L19_004F32A0(0x64, 1);
                break;
            }
            if (((*(u8 *)(hero + 0x25e4)) != 0) && ((*(f32 *)(hero + 0x170)) >= 0.045f)) {
                func_L19_004F32A0(0x63, 1);
            }
        } else {
            func_L01_005063E8();
        }
        break;
    case 0x63:
        if ((*(s32 *)(hero + 0xc08)) & 2) {
            func_L19_004F32A0(0x62, 1);
        }
        break;
    case 0x64:
        if (((*(s32 *)(hero + 0xc08)) & 2) || ((*(s32 *)(hero + 0x15d8)) != 0)) {
            func_L19_004F32A0(0, 1);
        }
        if (func_0038CF38(hero + 0x80, hero + 0x15c8) > 0.2f) {
            func_L19_004F32A0(0x62, 1);
        }
        break;
                case 0x65:                          /* switch 2 */
                    temp_a0_11 = (*(s32 *)(hero + 0x15e8));
                    if ((temp_a0_11 < 3) && (((temp_a0_11 * 7) + 0xA) < (*(s32 *)(hero + 0x1b8))) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, &sp44, 0) != 0)) {
                        func_L19_004F32A0(0x66, 1);
                    }
                    if ((*(f32 *)(hero + 0x88)) < ((*(f32 *)(hero + 0x354)) - 1.2f)) {
                        func_L01_004EDE10();
                        return;
                    }
                    if ((*(s32 *)(hero + 0x1b8)) < 0xAB) {
                        break;
                    }
                    func_L01_004EDE10();
                    return;
                case 0x78:                          /* switch 2 */
                    if ((*(f32 *)(hero + 0x88)) < ((*(f32 *)(hero + 0x354)) - 1.2f)) {
                        func_L01_004EDE10();
                        return;
                    }
                    if ((*(s32 *)(hero + 0x1b8)) < 0x97) {
                        break;
                    }
                    func_L01_004EDE10();
                    return;
                case 0x79:                          /* switch 2 */
                    if ((*(f32 *)(hero + 0x88)) < ((*(f32 *)(hero + 0x354)) - 1.2f)) {
                        func_L01_004EDE10();
                        return;
                    }
                    if ((*(s32 *)(hero + 0x1b8)) < 0x65) {
                        break;
                    }
                    func_L01_004EDE10();
                    return;
                case 0x7A:                          /* switch 2 */
                    if ((*(f32 *)(hero + 0x88)) < ((*(f32 *)(hero + 0x354)) - 0.8f)) {
                        func_L01_004EDE10();
                        return;
                    }
                    if ((*(s32 *)(hero + 0x1b8)) < 0x97) {
                        break;
                    }
                    func_L01_004EDE10();
                    return;
    case 0x6D:
        if ((f32)D_L19_002F8BD0[(*(s16 *)(hero + 0xbdc))].w[6] < (*(f32 *)(hero + 0xc18))) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x30:
        if ((((*(u8 *)(hero + 0x1475)) == 0) && ((*(s16 *)(hero + 0x200)) == 0)) || ((*(f32 *)(hero + 0x33c)) > 1.0f)) {
            s32 slot = (*(s32 *)(hero + 0x2794));
            if (slot != -1) {
                u8 *ent = D_001A30B0 + slot * 0x70;
                if (((*(s32 *)((u8 *)ent + 0x88)) == (*(s32 *)(hero + 0x25c0))) && ((*(u8 *)((u8 *)ent + 0x74)) != 0)) {
                    func_003A4F28(slot);
                }
            }
            (*(s32 *)(hero + 0x2794)) = -1;
            if (func_L19_004F32A0(0, 0) != 0) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 17.0f);
                (*(s128 *)(hero + 0x160)) = (*(s128 *)(hero + 0x150));
            }
        }
        break;
    case 0x3:
        if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ((*(s32 *)(hero + 0x1228)) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if ((*(s16 *)(hero + 0x1e0)) == 0) {
            if ((*(s32 *)(D_001D52FC + 0x1A4)) & 0x40) {
                func_L19_004F32A0(7, 1);
                break;
            }
            if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
                func_L19_004F32A0(4, 1);
                break;
            }
        }
        if (((*(s16 *)(hero + 0x36e)) >= 9) && ((*(f32 *)(hero + 0x33c)) > 0.3f)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        if ((*(s32 *)(hero + 0xc08)) & 2) {
            func_L19_004F32A0(0, 1);
            break;
        }
        if ((*(s32 *)(hero + 0x5dc)) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        if (!((*(f32 *)(hero + 0x2838)) > 0.2f) || ((*(s16 *)(hero + 0x1e0)) != 0)) {
            break;
        }
        if (func_L01_004DFDB0(0) != 0x51) {
            if ((*(f32 *)(hero + 0x1b4)) == 0.0f) {
                func_L19_004F32A0(0, 0);
                break;
            }
        } else if (((*(f32 *)(hero + 0xc18)) > 10.0f) && (func_L19_004F32A0(0, 0) != 0)) {
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, 17.0f);
        }
        if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
            func_L19_004F32A0(2, 1);
        }
        break;
    case 0x4:
        if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ((*(s32 *)(hero + 0x1228)) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if (((*(s32 *)(hero + 0x1b8)) >= 0xC) && !((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0))) {
            func_L19_004F32A0(0, 0);
            func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
            break;
        }
        if (((*(u8 *)(hero + 0x147c)) != 0) && ((*(s16 *)(hero + 0x36c)) == 0)) {
            func_L19_004F32A0(0x76, 1);
            break;
        }
        if (func_L01_00506E30() != 0) {
            break;
        }
        if ((func_L01_004606E8(0x80, 0xF, 0, 0) != 0) && ((*(u8 *)(hero + 0x121a)) == 0) && ((*(s32 *)(hero + 0x1228)) == 0xA)) {
            func_L19_004F32A0(0x15, 1);
        }
        if ((*(s16 *)(hero + 0x36e)) >= 9) {
            if (((*(s32 *)(hero + 0x25d0)) != 8) || ((*(s32 *)(hero + 0x1b8)) >= 0xF)) {
                func_L19_004F32A0(6, 1);
            }
        }
        break;
    case 0x8A:
        if ((*(s32 *)(hero + 0x1228)) != 0xD) {
            func_L19_004F32A0(0, 1);
            break;
        }
        if ((*(s32 *)(hero + 0xa9c)) != 0) {
            u8 *obj = (*(u8 * *)(hero + 0xa90));
            if (obj != 0) {
                func_L01_00456230(obj, 1);
            }
            func_L19_004F32A0(0x8B, 1);
        }
        break;
    case 0x8B:
        if ((*(s32 *)(hero + 0x1b8)) >= 0x5B) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x23:
        if ((*(s32 *)(hero + 0x1228)) != 0xD) {
            func_L19_004F32A0(0, 1);
        }
        break;
    case 0x24:
    {
        s32 go;
        func_L01_004E5030(10.0f, (*(f32 *)(hero + 0xa2c)), 0.5f, -1.0f);
        if (((*(f32 *)(hero + 0xa2c)) < 22.0f) && ((*(f32 *)(hero + 0xa2c)) < 30.0f)) {
            func_L01_0050FB40(0xA, 0, 16.0f);
        }
        go = 0;
        if (!((*(s32 *)(D_001D52FC + 0x1A0)) & (*(s32 *)(hero + 0x1210)))) {
            if ((*(f32 *)(hero + 0xa2c)) > 25.0f) {
                (*(s32 *)(hero + 0xa48)) = 1;
            }
            go = 1;
        }
        if (((*(s32 *)(hero + 0x25c8)) == 1) && ((*(f32 *)(hero + 0xa20)) < 0.06666667f)) {
            go = 1;
        }
        if (go != 0) {
            (*(f32 *)(hero + 0x1b4)) = (*(f32 *)(hero + 0xa20));
            if ((*(f32 *)(hero + 0x1b4)) > 0.116666675f) {
                (*(f32 *)(hero + 0x1b4)) = 0.116666675f;
            }
            if ((*(f32 *)(hero + 0x33c)) < 0.3f) {
                func_L19_004F32A0(0, 0);
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 30.0f);
                break;
            }
            if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 0xA) {
                func_L19_004F32A0(6, 0);
            } else {
                func_L19_004F32A0(6, 0);
                func_L01_0050FB40(0xA, 0, 17.0f);
            }
            (*(f32 *)(hero + 0xa04)) = 0.011666667f;
            (*(f32 *)(hero + 0xa00)) = 0.008055556f;
            (*(s32 *)(hero + 0x280c)) = 0;
        }
        break;
    }
    case 0x25:
        if (!((*(s32 *)(D_001D52FC + 0x1A0)) & (*(s32 *)(hero + 0x1210)))) {
            (*(f32 *)(hero + 0x1b4)) = (*(f32 *)(hero + 0xa20));
            if ((*(f32 *)(hero + 0x1b4)) > 0.116666675f) {
                (*(f32 *)(hero + 0x1b4)) = 0.116666675f;
            }
            if ((*(f32 *)(hero + 0x33c)) < 0.4f) {
                func_L19_004F32A0(0, 1);
            } else {
                func_L19_004F32A0(6, 1);
                (*(s32 *)(hero + 0x280c)) = 0;
            }
        }
        break;
    case 0x2B:
        if (!((*(s32 *)(D_001D52FC + 0x1A0)) & (*(s32 *)(hero + 0x1210)))) {
            s32 t = (*(s32 *)(hero + 0x1b8));
            if (t >= 0xB) {
                if (t < 0x28) {
                    (*(s32 *)(hero + 0xa48)) = 1;
                }
                func_L19_004F32A0(0x2C, 1);
                (*(f32 *)(hero + 0xa04)) = 0.0019444445f;
                (*(f32 *)(hero + 0xa00)) = 0.0075000003f;
            }
        }
        break;
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x3E:
    {
        u32 st;
        if ((*(u32 *)(hero + 0x25c4)) == 0x3E) {
            (*(s16 *)(hero + 0x62e)) = 0;
        }
        if ((*(u32 *)(hero + 0x25c4)) == 0x2A) {
            (*(s8 *)(hero + 0x1219)) = 2;
        }
        if ((*(u32 *)(hero + 0x25c4)) != 0x3E) {
            s32 hit = 0;
            if ((*(u8 *)(hero + 0x2a7)) != 0) {
                f32 half = 0.5f;
                f32 up = 0.02f;
                if ((u32)((*(u32 *)(hero + 0x25c4)) - 0x28) < 2) {
                    up = 0.45f;
                }
                func_0038D000(v10, 1, 0.25f, 0.0f, up + half);
                hit = func_L01_003FB640(v10, 2, 0, half) != 0;
            }
            if ((hit != 0) || ((*(s16 *)(hero + 0x62e)) != 0)) {
                s32 clear = 1;
                s32 level;
                if ((*(u8 *)(hero + 0x2a7)) != 0) {
                    *(s128 *)(v10) = *(s128 *)(hero + 0x580);
                    v10[2] += 1.5f;
                    v20[0] = func_0038D098((*(f32 *)(hero + 0x5ec))) * 5.0f;
                    v20[1] = func_0038D0B0((*(f32 *)(hero + 0x5ec))) * 5.0f;
                    v20[2] = 0.0f;
                    func_00282CC0(v20, v20, v10);
                    if (func_003D3CB0(v10, v20, 2, 0, 0) != 0) {
                        clear = 0;
                    }
                }
                level = D_00142B98;
                (*(s16 *)(hero + 0x62e)) = 0;
                if (((level == 0xD) || (level == 0x12)) && (clear == 0)) {
                    func_0038CF68(hero + 0x120, hero + 0x10, 0.21666668f);
                    (*(f32 *)(hero + 0x128)) = 0.16666667f;
                    func_L19_004F32A0(0x16, 1);
                    (*(s16 *)(hero + 0x1f4)) = 0x46;
                    (*(s16 *)(hero + 0x1d0)) = 0x46;
                } else {
                    func_L19_004F32A0(0x3E, 1);
                }
                break;
            }
        }
        st = (*(u32 *)(hero + 0x25c4));
        if (st == 0x27) {
            s32 a;
            s32 b;
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) {
                if ((*(s32 *)(hero + 0x628)) != 0) {
                    (*(s32 *)(hero + 0x630)) = 1;
                } else {
                    func_L19_004F32A0(0x28, 1);
                }
                break;
            }
            a = (*(s32 *)(hero + 0x5e0));
            if ((a >= 6) || ((b = (*(s32 *)(hero + 0x668))) >= 6)) {
                if ((*(f32 *)(hero + 0x33c)) > 8.0f) {
                    (*(s16 *)(hero + 0x1e0)) = 0x46;
                }
                (*(s16 *)(hero + 0x1d0)) = 0x46;
                if ((D_00142B98 == 0xD) && ((*(f32 *)(hero + 0x33c)) > 4.0f)) {
                    func_L19_004F32A0(0x74, 1);
                } else {
                    func_L19_004F32A0(6, 1);
                }
                (*(s16 *)(hero + 0x1f4)) = 8;
                (*(s16 *)(hero + 0x1d0)) = 0x46;
                break;
            }
            if ((a == 0) && (b == 0) && (func_L01_004606E8(0x80, 0xA, 0, 0) != 0)) {
                func_L19_004F32A0(0x2A, 1);
                break;
            }
            if ((*(s32 *)(hero + 0x61c)) == -1) {
                s32 anim = (*(s32 *)(hero + 0x5fc)) + 0x31;
                if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != anim) {
                    func_L01_0050FB40(anim, 0, 12.0f);
                }
            } else {
                s32 anim = (*(s32 *)(hero + 0x61c)) + 0x47;
                if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != anim) {
                    func_L01_0050FB40(anim, 0, 12.0f);
                }
            }
            if (((*(s16 *)(hero + 0x62c)) != 0) && ((*(s32 *)(hero + 0x630)) != 0)) {
                f32 h;
                f32 t;
                func_L19_004F32A0(0x28, 1);
                (*(s32 *)(hero + 0x634)) = 1;
                h = func_L01_00447878((f32 *)(hero + 0x80), (f32 *)(hero + 0x5c0), 0, (*(f32 *)(hero + 0x174)), -(*(f32 *)(hero + 0x4f0)));
                *(s128 *)v20 = 0;
                v20[2] = h;
                *(s128 *)v10 = 0;
                t = func_L01_00445EE0(v10, v20, 0, (*(f32 *)(hero + 0x4f0)));
                (*(f32 *)(hero + 0x4d8)) = t;
                (*(f32 *)(hero + 0x4f0)) = (*(f32 *)(hero + 0x638));
                (*(f32 *)(hero + 0x478)) = t;
                (*(f32 *)(hero + 0x4dc)) = t + 0.05f;
            }
            (*(s32 *)(hero + 0x628)) = 0;
            (*(s16 *)(hero + 0x62c)) = 0;
        } else if (st == 0x2A) {
            s32 top;
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), 5, 0, 0) != 0) && ((f32)D_L19_002F8BD0[(*(s16 *)(hero + 0xbdc))].w[5] <= (*(f32 *)(hero + 0xc18)))) {
                func_L19_004F32A0(0x28, 1);
                break;
            }
            top = 0xE;
            if ((*(s16 *)(hero + 0xbdc)) == 0) {
                top = 0x17;
            }
            if (((*(s32 *)(hero + 0x5e0)) == 0) && ((*(s32 *)(hero + 0x668)) == 0) && (func_L01_004606E8(0x80, 0xA, 0, 0) != 0)) {
                if ((f32)top < (*(f32 *)(hero + 0xc18))) {
                    func_L19_004F32A0(0x2A, 1);
                }
                break;
            }
            if ((f32)D_L19_002F8BD0[(*(s16 *)(hero + 0xbdc))].w[6] < (*(f32 *)(hero + 0xc18))) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
            if (((*(s32 *)(hero + 0x5e0)) >= 6) || ((*(s32 *)(hero + 0x668)) >= 6)) {
                if ((D_00142B98 == 0xD) && ((*(f32 *)(hero + 0x33c)) > 4.0f)) {
                    func_L19_004F32A0(0x74, 1);
                } else {
                    func_L19_004F32A0(6, 1);
                }
                (*(s16 *)(hero + 0x1f4)) = 8;
                (*(s16 *)(hero + 0x1d0)) = 0x46;
            }
        } else if ((u32)(st - 0x28) < 2) {
            s32 lo;
            s32 now;
            if ((((*(s32 *)(hero + 0x5e0)) >= 6) || ((*(s32 *)(hero + 0x634)) != 0)) && ((*(s32 *)(hero + 0x5dc)) != 0) && (((*(f32 *)(hero + 0x88)) - (*(f32 *)(hero + 0x578))) < 0.35f)) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
            if (((*(u32 *)(hero + 0x25c4)) == 0x28) && ((*(s32 *)(hero + 0x1b8)) < 0xA) && ((*(u8 *)(hero + 0x46e)) == 0) && ((*(f32 *)(hero + 0x2838)) > 0.5f) && ((*(s32 *)(hero + 0x600)) == 0)) {
                func_L01_004EE850(0, 1.0f);
                if (func_0038DBA0(func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x5ec))), 1.5707965f) < 1.2217306f) {
                    f32 ang;
                    f32 d;
                    f32 lim;
                    ang = func_0038DAB8((*(f32 *)(hero + 0x5ec)), 1.5707965f);
                    if (func_0038DBA0((*(f32 *)(hero + 0x1a0)), ang) > 1.5707965f) {
                        ang = func_0038DAB8((*(f32 *)(hero + 0x5ec)), -1.5707965f);
                    }
                    lim = 4.5f;
                    for (d = 2.0f; d <= lim; d += 0.75f) {
                        char *pos = hero + 0x80;
                        *(s128 *)v10 = *(s128 *)pos;
                        sp48 = (*(s32 *)(hero + 0x5d4));
                        sp4C = (*(f32 *)(hero + 0x5d8));
                        if (func_L01_00476498((*(void * *)(hero + 0x5d0)), v10, &sp48, &sp4C, (*(s32 *)(hero + 0x5f4)), 0.0f) != 0) {
                            func_0038CE20(v20, hero + 0x110, 48.0f);
                            func_00282CC0(v10, pos, v20);
                        }
                        v10[0] += func_0038D098(ang) * d;
                        v10[1] += func_0038D0B0(ang) * d;
                        if (func_L01_004E8BC8((s8 *)v10, &sp50, (s128 *)v20, &sp54, &sp58, &sp5C, (*(void * *)(hero + 0x5d0)), 0, 1) != 0) {
                            (*(void * *)(hero + 0x604)) = (*(void * *)(hero + 0x5d0));
                            (*(s32 *)(hero + 0x608)) = (*(s32 *)(hero + 0x5d4));
                            (*(f32 *)(hero + 0x60c)) = (*(f32 *)(hero + 0x5d8));
                            (*(s32 *)(hero + 0x610)) = (*(s32 *)(hero + 0x5f4));
                            *(s128 *)(hero + 0x5b0) = *(s128 *)(hero + 0x580);
                            (*(void * *)(hero + 0x5d0)) = sp50;
                            (*(s32 *)(hero + 0x5f4)) = sp5C;
                            func_L01_00476B98(sp50, pos, hero + 0x580, (s32 *)(hero + 0x5d4), (f32 *)(hero + 0x5d8), sp5C, 999.0f, 2.0f, 0.0f);
                            (*(s32 *)(hero + 0x600)) = 1;
                            (*(s32 *)(hero + 0x618)) = 0;
                            func_L19_004F32A0(0x29, 1);
                            break;
                        }
                    }
                }
            }
            if (((*(s16 *)(hero + 0x47c)) < (*(s32 *)(hero + 0x1b8))) && (func_L01_005114B0((s8 *)(hero + 0xf0)) < 0.001f)) {
                (*(s8 *)(hero + 0x46e)) = 1;
            }
            lo = (*(s16 *)(hero + 0x47c));
            now = (*(s32 *)(hero + 0x1b8));
            if ((now >= lo + 1) && (now < lo + 9) && ((*(u8 *)(hero + 0x46e)) == 0) && ((*(s32 *)(hero + 0xc0c)) == 0)) {
                func_L01_00511748((f32 *)(hero + 0x80), (f32 *)(hero + 0xf0), &sp60, (*(f32 *)(hero + 0x4f0)));
                func_L01_004E5030((*(f32 *)(hero + 0x498)), (f32)sp60, 0.5f, 0.25f);
                if ((*(s32 *)(hero + 0x600)) != 0) {
                    if ((*(f32 *)(hero + 0xc00)) > 2.0f) {
                        (*(f32 *)(hero + 0xc00)) = 2.0f;
                    }
                    if ((*(f32 *)(hero + 0xc00)) < 0.5f) {
                        (*(f32 *)(hero + 0xc00)) = 0.5f;
                    }
                }
            } else if (((*(u8 *)(hero + 0x46e)) != 0) && ((*(u8 *)(hero + 0x46c)) == 0)) {
                (*(s16 *)(hero + 0x47e)) = 0x1E;
                if ((*(s32 *)(hero + 0x5e0)) == 0) {
                    (*(s16 *)(hero + 0x47e)) = (s32)(func_L19_00501FE0(60.0f, (*(f32 *)(hero + 0x4f0)), (*(f32 *)(hero + 0x578))));
                }
                if ((*(s16 *)(hero + 0x47e)) != 0) {
                    func_L01_004E5030((*(f32 *)(hero + 0x49c)), (f32)(*(s16 *)(hero + 0x47e)), 0.5f, 0.25f);
                }
                if ((*(s32 *)(hero + 0x600)) != 0) {
                    if ((*(f32 *)(hero + 0xc00)) > 2.0f) {
                        (*(f32 *)(hero + 0xc00)) = 2.0f;
                    }
                    if ((*(f32 *)(hero + 0xc00)) < 0.5f) {
                        (*(f32 *)(hero + 0xc00)) = 0.5f;
                    }
                }
                if (((*(s32 *)(hero + 0x5e0)) == 0) && ((*(s32 *)(hero + 0x668)) == 0) && ((*(f32 *)(hero + 0x33c)) < 0.5f)) {
                    f32 y = (*(f32 *)(hero + 0x88));
                    f32 func_00117650 = (*(f32 *)(hero + 0x578));
                    if (y + (*(f32 *)(hero + 0xf8)) < func_00117650) {
                        (*(u8 *)(hero + 0x46c)) = 1;
                        (*(f32 *)(hero + 0xf8)) = func_00117650 - y;
                        (*(f32 *)(hero + 0xc00)) = 1.0f;
                    }
                }
                if (((*(f32 *)(hero + 0x88)) - (*(f32 *)(hero + 0x578))) < -2.5f) {
                    func_L19_004F32A0(6, 1);
                    (*(s16 *)(hero + 0x1e0)) = 0x46;
                    (*(s16 *)(hero + 0x1f4)) = 8;
                    (*(s16 *)(hero + 0x1d0)) = 0x46;
                    break;
                }
            }
            if ((*(s32 *)(hero + 0x68c)) != 0) {
                func_L19_004F32A0(0x71, 1);
                break;
            }
            {
                if ((*(u8 *)(hero + 0x46c)) != 0) {
                    if (++(*(u8 *)(hero + 0x46c)) >= 3) {
                        (*(s32 *)(hero + 0x25c4)) = 0x27;
                        func_L01_0050FB40((*(s32 *)(hero + 0x5fc)) + 0x31, 0, 7.0f);
                        break;
                    }
                }
            }
            if (((*(s32 *)(hero + 0x5e0)) != 0) && ((*(s16 *)(hero + 0x36e)) == 0) && (func_L19_004F32A0(0, 0) != 0)) {
                func_L01_0050FB40(0xC, 4, 6.0f);
            }
        } else if (st == 0x3E) {
            if ((*(f32 *)(hero + 0xf8)) > 0.0f) {
                func_L01_00511748((f32 *)(hero + 0x80), (f32 *)(hero + 0xf0), &sp64, 0.006388889f);
                func_L01_004E5030(9.0f, (f32)sp64, 0.5f, -1.0f);
            }
            if ((*(s32 *)(hero + 0xc08)) & 2) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
            if (((*(f32 *)(hero + 0xf8)) < 0.0f) && (__builtin_fabsf((*(f32 *)(hero + 0x88)) - (*(f32 *)(hero + 0x578))) < 0.3f)) {
                func_L19_004F32A0(0x27, 1);
            }
        }
        break;
    }
    case 0x17:
        if ((*(f32 *)(hero + 0xc18)) > 13.5f) {
            func_L19_004F32A0(0x18, 0);
        }
        break;
    case 0x18:
        if (((*(s32 *)(hero + 0xc08)) & 2) && ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 0x20)) {
            func_L01_0050FB40(0x21, 0, 6.0f);
        }
        func_L01_004EE850(0, 1.0f);
        if (func_L01_004E8318((s8 *)(hero + 0x80), (s8 *)(hero + 0x90), 0) == 0) {
            func_L19_004F32A0(6, 1);
            (*(s16 *)(hero + 0x1d0)) = 0xA;
            break;
        }
        if ((((*(f32 *)(hero + 0x2838)) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) && (func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) > 2.3561947f)) || ((*(s32 *)(D_001D52FC + 0x1A4)) & 8)) {
            func_L19_004F32A0(6, 1);
            (*(s8 *)(hero + 0x25f0)) = 1;
            (*(s16 *)(hero + 0x1d0)) = 0xA;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 0x11, 0, 0) != 0) {
            func_L19_004F32A0(0x1B, 1);
            break;
        }
        if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
            if (func_0038DBA0((*(f32 *)(hero + 0x1a0)), func_0038DAB8((*(f32 *)(hero + 0x98)), 1.5707965f)) < 0.78539824f) {
                *(s128 *)(v10) = *(s128 *)(hero + 0x80);
                v10[0] += func_0038D098(func_0038DAB8((*(f32 *)(hero + 0x98)), 1.5707965f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8((*(f32 *)(hero + 0x98)), 1.5707965f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v10, (s8 *)(hero + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x19, 1);
                }
                break;
            }
        }
        if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
            if (func_0038DBA0((*(f32 *)(hero + 0x1a0)), func_0038DAB8((*(f32 *)(hero + 0x98)), -1.5707965f)) < 0.78539824f) {
                *(s128 *)(v10) = *(s128 *)(hero + 0x80);
                v10[0] += func_0038D098(func_0038DAB8((*(f32 *)(hero + 0x98)), -1.5707965f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8((*(f32 *)(hero + 0x98)), -1.5707965f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v10, (s8 *)(hero + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x1A, 1);
                }
            }
        }
        break;
    case 0x19:
    case 0x1A:
    {
        f32 side;
        *(s128 *)v10 = (*(s128 *)(hero + 0x80 + 0));
        side = 1.5707965f;
        if ((*(u32 *)(hero + 0x25c4)) == 0x1A) {
            side = -1.5707965f;
        }
        v10[0] += func_0038D098(func_0038DAB8((*(f32 *)(hero + 0x98)), side)) * 0.3f;
        v10[1] += func_0038D0B0(func_0038DAB8((*(f32 *)(hero + 0x98)), side)) * 0.3f;
        func_L01_004EE850(0, 1.0f);
        if (((*(f32 *)(hero + 0x2838)) < 0.5f) || (func_0038DBA0((*(f32 *)(hero + 0x1a0)), func_0038DAB8((*(f32 *)(hero + 0x98)), side)) > 0.78539824f) || (func_L01_004E8318((s8 *)v10, (s8 *)(hero + 0x90), 0) == 0)) {
            if ((*(s32 *)(hero + 0xc08)) & 2) {
                func_L19_004F32A0(0x18, 1);
                break;
            }
        }
        if (((*(f32 *)(hero + 0x2838)) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) && (func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) > 2.3561947f)) {
            func_L19_004F32A0(6, 1);
            (*(s8 *)(hero + 0x25f0)) = 1;
            (*(s16 *)(hero + 0x1d0)) = 0x28;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) {
            func_L19_004F32A0(0x1B, 1);
        }
        break;
    }
    case 0x76:
        if ((*(s32 *)(hero + 0x1b8)) >= 0x12D) {
            func_L01_004EDE10();
        }
        if ((*(u8 *)(hero + 0x147c)) == 0) {
            if ((*(s16 *)(hero + 0x36e)) != 0) {
                func_L19_004F32A0(6, 1);
            } else {
                func_L19_004F32A0(0, 1);
            }
        }
        break;
    case 0x6:
    case 0x2C:
        if (((*(s32 *)(hero + 0x25c8)) == 0) && (((*(s32 *)(hero + 0x1b8)) >= 0x12) || ((*(f32 *)(hero + 0x33c)) > 1.75f))) {
            func_L01_0050FB40(0xB, 0, 16.0f);
            (*(s32 *)(hero + 0x25c8)) = 1;
            if ((*(u32 *)(hero + 0x25c4)) == 0x2C) {
                (*(s32 *)(hero + 0x280c)) = 7;
            } else {
                (*(s32 *)(hero + 0x280c)) = 0;
            }
        }
        if ((*(s16 *)(hero + 0x36e)) == 0) {
            func_L01_004E1180();
            if ((*(f32 *)(hero + 0x118)) < -0.15f) {
                (*(f32 *)(hero + 0x118)) = -0.15f;
            }
            if ((*(f32 *)(hero + 0xf8)) < -0.15f) {
                (*(f32 *)(hero + 0xf8)) = -0.15f;
            }
            if ((*(s32 *)(hero + 0x2850)) <= 0) {
                func_L19_004F32A0(0x39, 1);
            } else {
                s32 one = 1;
                s32 low = (*(s32 *)(hero + 0x35c)) == 0;
                if ((*(s32 *)(hero + 0x1b8)) >= 0x5A) {
                    if (func_L19_004F32A0(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 4, 6.0f);
                    }
                    if (low != 0) {
                        (*(s16 *)(hero + 0x1e0)) = 0x16;
                    }
                    func_L01_00510CA0(0xA, 4, 0, 1, 0.022f, 0.004f);
                } else if ((*(s32 *)(hero + 0x25c8)) == one) {
                    if (func_L19_004F32A0(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 9, -1.0f);
                    }
                    func_L01_00511508(hero + 0x160, hero + 0x160, 0.0f);
                    func_003C4BB0((f32 *)(hero + 0x160), 0.116666675f);
                    (*(s16 *)(hero + 0x1e0)) = 7;
                    if ((*(s32 *)(hero + 0x25d0)) == 0x2C) {
                        (*(s16 *)(hero + 0x1e0)) = 0xA;
                    }
                    if ((low != 0) && ((*(s32 *)(hero + 0x1b8)) >= 0x33)) {
                        (*(s16 *)(hero + 0x1e0)) = 0x12;
                    }
                    func_L01_00510CA0(0xA, 2, 0, 1, 0.019f, 0.002f);
                } else if (((*(f32 *)(hero + 0x2838)) > 0.5f) && ((*(s16 *)(hero + 0x1e0)) == 0)) {
                    func_L19_004F32A0(2, 1);
                    func_L01_00510CA0(7, 2, 0, 1, 0.016f, 0.002f);
                } else if ((*(f32 *)(hero + 0x174)) > 0.050000004f) {
                    if (func_L19_004F32A0(3, 0) != 0) {
                        func_L01_0050FB40(6, 0, 12.0f);
                        func_003C4BB0((f32 *)(hero + 0x160), 0.12833333f);
                    }
                } else {
                    func_L19_004F32A0(0, 1);
                    func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                }
            }
        } else if ((*(s32 *)(hero + 0x2850)) > 0) {
            if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(0x40, 0)) && (D_00142CA0[2] != 0) && (func_L01_004E9238(3) != 4) && ((*(s16 *)(hero + 0x2884)) == 0) && ((*(s16 *)(hero + 0x1e0)) == 0) && ((*(f32 *)(hero + 0x33c)) > 0.6f)) {
                func_L19_004F32A0(8, 1);
                break;
            }
            if (((*(s16 *)(hero + 0x202)) >= 0x15) && (func_L01_00506298(((*(s16 *)(hero + 0x1ee)) != 0) ? 1 : 6, 0) != 0)) {
                break;
            }
            if ((*(s32 *)(hero + 0x528)) != 0) {
                func_L19_004F32A0(0x17, 1);
                break;
            }
            if ((*(s32 *)(hero + 0x5dc)) != 0) {
                func_L19_004F32A0(0x27, 1);
                break;
            }
        }
        break;
    case 0x74:
        if (D_00142B98 == 0xD) {
            f32 y = (*(f32 *)(hero + 0x88));
            if (((*(s32 *)(hero + 0x25d4)) == 0x1E) || ((*(s32 *)(hero + 0x25e0)) == 0x1E)) {
                s32 t = (*(s32 *)(hero + 0x1b8));
                if (((y < 51.0f) && (t >= 0x1F)) || (t >= 0x1F) && ((*(u8 *)(hero + 0x2a7)) != 0) && (((*(f32 *)(hero + 0x118)) >= 0.0f) || ((*(u8 *)(hero + 0x147d)) != 0))) {
                    func_L01_004EDE10();
                    return;
                }
            } else if ((y < 89.0f) || (((*(s32 *)(hero + 0x1b8)) >= 0x15) && ((*(u8 *)(hero + 0x2a7)) != 0) && ((*(f32 *)(hero + 0x118)) >= 0.0f))) {
                func_L01_004EDE10();
                return;
            }
        }
        if ((*(s32 *)(hero + 0x1b8)) < 0x79) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x82:
    {
        u8 *p = hero + 0xf0;
        if (func_L01_005114B0((s8 *)p) < 0.0f) {
            p -= 0xF0;
            if ((*(s32 *)((u8 *)p + 0x340)) != 0) {
                u8 *q = (*(u8 * *)((u8 *)p + 0x33C));
                if ((q == 0) || ((*(s16 *)((u8 *)q + 0xAA)) == 0x8E2)) {
                    if (func_L19_004F32A0(0, 0) != 0) {
                        (*(s8 *)((u8 *)p + 0x24EF)) = 0;
                        func_L01_0050FB40(7, 0x17, 9.0f);
                        func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                    }
                }
            }
        }
        if ((*(f32 *)(hero + 0x560)) == 0.0f) {
            if ((D_00142B98 == 0xD) && ((*(f32 *)(hero + 0x338)) < 69.0f)) {
                func_L19_004F32A0(0x74, 1);
            } else {
                func_L19_004F32A0(6, 1);
            }
        }
        break;
    }
    case 0x8:
        if (((*(s32 *)(hero + 0x1d4)) != 0) && ((*(s32 *)(hero + 0x1b8)) < 9)) {
            s32 prev = (*(s32 *)(hero + 0x25d0));
            s32 ok = 0;
            if ((prev == 7) || (prev == 9) || (prev == 0xE) || (prev == 0x11)) {
                ok = 1;
            }
            if (ok != 0) {
                func_L19_004F32A0(0x11, 1);
            }
            break;
        }
        if (((*(s32 *)(hero + 0x1b8)) >= 0x1F) && !((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(0x40, 0)) && !((*(s32 *)(D_001D52FC + 0x1C0)) & 0x40)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        if ((*(s32 *)(hero + 0x528)) != 0) {
            func_L19_004F32A0(0x17, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) != 0) && !((*(f32 *)(hero + 0x33c)) < 0.4f)) {
            break;
        }
        if ((*(s32 *)(hero + 0x1b8)) < 0xA) {
            (*(s16 *)(hero + 0x1ee)) = 0xC - (*(u16 *)(hero + 0x1b8));
        }
        func_L01_004EE850(0, 1.0f);
        if (((*(s32 *)(hero + 0x25d0)) == 0x10) && ((*(s32 *)(hero + 0x1b8)) < 4)) {
            if (func_L19_004F32A0(3, 0) != 0) {
                func_L01_0050FB40(5, 0, -1.0f);
                (*(s16 *)(hero + 0x1e0)) = 0x22;
            }
            break;
        }
        if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
            func_L19_004F32A0(4, 1);
            func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            break;
        }
        if ((D_L19_001DBD44[0][2] < (*(f32 *)(hero + 0x1b0))) && (func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) < 1.5707964f)) {
            if (((*(u8 *)(hero + 0x1474)) != 0) || ((*(u8 *)(hero + 0x25ea)) != 0)) {
                func_L19_004F32A0(2, 1);
                break;
            }
            func_L19_004F32A0(2, 0);
            if ((*(u32 *)(hero + 0x25c4)) == 2) {
                (*(s32 *)(hero + 0x25c8)) = 1;
                func_L01_0050FB40(4, 2, 8.0f);
                (*(s8 *)(hero + 0x3ee)) = 1;
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (D_L19_001DBD44[0][2] < (*(f32 *)(hero + 0x1b0))) {
            if (((*(u8 *)(hero + 0x1474)) != 0) || ((*(u8 *)(hero + 0x25ea)) != 0)) {
                func_L19_004F32A0(2, 1);
                break;
            }
            func_L19_004F32A0(2, 0);
            if ((*(u32 *)(hero + 0x25c4)) == 2) {
                (*(s32 *)(hero + 0x25c8)) = 1;
                func_L01_0050FB40(4, D_L19_001DBD74, 12.0f);
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if ((*(s16 *)(hero + 0x36e)) == 0) {
            if (func_L19_004F32A0(0, 0) != 0) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, -2.0f);
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            }
        } else if (func_L19_004F32A0(0, 0) != 0) {
            func_L01_0050FB40(7, 0x17, 9.0f);
            func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
        }
        break;
    case 0x7:
    case 0x9:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x1B:
    case 0x38:
    case 0x66:
    case 0x6E:
    case 0x81:
    case 0x89:
    {
        s32 near;
        s16 lo;
        s32 now;
        u32 st;
        u32 sa;
        u32 sb;
        u32 sc;
        s32 lim;
        s32 frames;
        if ((*(u8 *)(hero + 0x4fe)) != 0) {
            s32 n = func_L01_004FF5D8();
            if ((n > 0) && (((*(s32 *)(hero + 0x1b8)) < n) || ((*(u8 *)(hero + 0x46c)) != 0)) && ((*(s32 *)(hero + 0x360)) != 0)) {
                if (((*(u32 *)(hero + 0x25c4)) != 0xB) || (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0)) {
                    s32 go = 1;
                    if (((*(u32 *)(hero + 0x25c4)) == 0x1B) || ((*(u8 *)(hero + 0x46c)) != 0)) {
                        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) == 0) {
                            go = 0;
                        }
                    }
                    if ((*(u32 *)(hero + 0x25c4)) == 0xB) {
                        if ((*(u8 *)(hero + 0x46c)) == 0) {
                            go = 0;
                        }
                    }
                    if ((go != 0) && (func_L01_004606E8(0x1F000, 5, 0, 0) != 0) && ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0))) {
                        func_L19_004F32A0(0xB, 1);
                        break;
                    }
                }
            }
        }
        if (((*(s16 *)(hero + 0x1f2)) != 0) && (((*(u32 *)(hero + 0x25c4)) == 7) || ((*(u32 *)(hero + 0x25c4)) == 9)) && ((*(s32 *)(hero + 0x1b8)) < 0x14)) {
            func_L19_004F32A0(0x82, 1);
            break;
        }
        if (((*(u32 *)(hero + 0x25c4)) == 0x1B) && ((*(s32 *)(hero + 0x1b8)) >= 0x15) && ((*(f32 *)(hero + 0x298)) > 0.7f)) {
            (*(s8 *)(hero + 0x25f0)) = 0;
            (*(s8 *)(hero + 0x25ed)) = 0;
        }
        if (((*(s32 *)(hero + 0x1b8)) < 7) && (func_L01_004606E8(func_003A3BB8(8, 0), 2, 0, 0) != 0) && ((sa = (*(u32 *)(hero + 0x25c4))) != 0x10) && (sa != 0xA) && (sa != 0x12) && (sa != 0x38) && (sa != 0x11) && (sa != 0xE) && (sa != 0x66)) {
            if ((func_L01_004E9238(3) == 2) && (D_00142CA0[2] != 0) && ((*(s16 *)(hero + 0x2884)) == 0) && ((*(f32 *)(hero + 0x178)) > 0.015000001f)) {
                func_L19_004F32A0(0xA, 1);
            } else if ((func_L01_004E9238(3) == 3) && ((*(s16 *)(hero + 0x2884)) == 0) && ((*(f32 *)(hero + 0x178)) > 0.015000001f) && ((*(s16 *)(hero + 0x1e4)) == 0)) {
                func_L19_004F32A0(0x10, 1);
            }
        }
        if ((*(s32 *)(hero + 0x5dc)) != 0) {
            func_L19_004F32A0(0x27, 1);
            break;
        }
        {
            if ((*(s16 *)(hero + 0x4ea)) < (*(s32 *)(hero + 0x1b8))) {
                if ((*(u8 *)(hero + 0x46c)) == 0) {
                    func_L19_004F32A0(6, 1);
                    break;
                }
            } else if (((*(u8 *)(hero + 0x46c)) == 0) && (((*(u32 *)(hero + 0x25c4)) == 0xA) || ((*(u32 *)(hero + 0x25c4)) == 0x10)) && ((*(f32 *)(hero + 0x298)) < 0.9f) && ((*(u8 *)(hero + 0x2a7)) != 0) && (func_0038CEA8(hero + 0xf0) > 0.116666675f)) {
                f32 a = func_0038CEA8(hero + 0x110);
                if ((a < func_0038CEA8(hero + 0xf0) * 0.5f) && ((*(s32 *)(hero + 0x528)) == 0) && ((*(f32 *)(hero + 0x33c)) < 2.0f)) {
                    func_L19_004F32A0(0x77, 1);
                    break;
                }
            }
        }
        near = 0;
        if (((*(u32 *)(hero + 0x25c4)) == 0xE) && ((*(f32 *)(hero + 0xc18)) < 35.0f)) {
            near = 1;
        }
        lo = (*(s16 *)(hero + 0x47c));
        now = (*(s32 *)(hero + 0x1b8));
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            if ((*(u8 *)(hero + 0x46d)) != 0) {
                f32 left = (f32)((*(s32 *)(hero + 0x400)) - now);
                if (left > 0.0f) {
                    func_L01_004E5030((*(f32 *)(hero + 0x408)), left, (*(f32 *)(hero + 0x4e4)), -1.0f);
                }
            } else if ((*(u32 *)(hero + 0x25c4)) != 0xE) {
                func_L01_00511748((f32 *)(hero + 0x80), (f32 *)(hero + 0xf0), &sp68, (*(f32 *)(hero + 0x4f0)));
                func_L01_004E5030((*(f32 *)(hero + 0x498)), (f32)sp68, (*(f32 *)(hero + 0x4e4)), -1.0f);
                if ((*(f32 *)(hero + 0xc00)) > 1.5f) {
                    (*(f32 *)(hero + 0xc00)) = 1.5f;
                }
            }
            break;
        }
        if (((*(u8 *)(hero + 0x46d)) != 0) && (now >= (*(s32 *)(hero + 0x400))) && (now < (*(s32 *)(hero + 0x404)))) {
            f32 left = (f32)((*(s32 *)(hero + 0x410)) - (*(s32 *)(hero + 0x400)));
            if (left > 0.0f) {
                func_L01_004E5030((*(f32 *)(hero + 0x498)), left, (*(f32 *)(hero + 0x4e4)), -1.0f);
            }
            break;
        }
        if ((*(s32 *)(hero + 0x358)) == 1) {
            func_L01_004F4E70(0xC, 0);
            func_L01_004E5EB8(3, 0x18, 1);
        }
        {
            u8 c = (*(u8 *)(hero + 0x46c));
            if (c != 0) {
                (*(u8 *)(hero + 0x46c)) = c + 1;
            } else if (((*(s16 *)(hero + 0x36e)) == 0) && ((*(u8 *)(hero + 0x46e)) != 0) && (near == 0)) {
                func_L01_004E1180();
                (*(u8 *)(hero + 0x46c)) = 1;
                (*(s8 *)(hero + 0x285f)) = 0;
                if (((*(f32 *)(hero + 0x2838)) < 0.2f) && ((*(f32 *)(hero + 0x1b4)) > 0.041666668f)) {
                    (*(f32 *)(hero + 0x1b4)) = 0.041666668f;
                }
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                if (near == 0) {
                    s32 k = (s32)((*(f32 *)(hero + 0x4a0))) + 2;
                    if ((*(f32 *)(hero + 0xc18)) < (*(f32 *)(hero + 0x49c)) - 1.5f) {
                        func_L01_0050FB40(func_L01_004DFE80((*(u8 *)((u8 *)sp74 + 0x43))), k, 7.0f);
                    }
                }
            }
        }
        if ((*(u8 *)(hero + 0x46c)) != 0) {
            (*(f32 *)(hero + 0xc00)) = 1.0f;
        } else if ((*(u8 *)(hero + 0x46e)) != 0) {
            s32 cur;
            if ((s32)(*(u8 *)((u8 *)sp74 + 0x41)) < (s32)((*(f32 *)(hero + 0x4a0)))) {
                if (((*(u32 *)(hero + 0x25c4)) == 0xE) && ((*(f32 *)(hero + 0xc18)) < 37.0f)) {
                    func_003C4138((f32 *)(hero + 0xc00), 1.0f, 0.15f);
                } else {
                    (*(s16 *)(hero + 0x47e)) = (s32)(func_L19_00501FE0(60.0f, (*(f32 *)(hero + 0x4f0)), -1.0f));
                    func_L01_004E5030((*(f32 *)(hero + 0x49c)), (f32)(*(s16 *)(hero + 0x47e)), (*(f32 *)(hero + 0x4e4)), 0.2f);
                }
                if (near == 0) {
                    s32 k = (s32)((*(f32 *)(hero + 0x4a0))) + 2;
                    if ((*(f32 *)(hero + 0xc00)) > 1.8f) {
                        func_L01_0050FB40(func_L01_004DFE80((*(u8 *)((u8 *)sp74 + 0x43))), k, (f32)((*(s16 *)(hero + 0x47e)) + 3));
                    }
                }
                if ((*(f32 *)(hero + 0xc00)) < 0.2f) {
                    (*(f32 *)(hero + 0xc00)) = 0.2f;
                }
                if ((*(f32 *)(hero + 0xc00)) > 2.7f) {
                    (*(f32 *)(hero + 0xc00)) = 2.7f;
                }
            }
            cur = (*(u32 *)(hero + 0x25c4));
            if ((cur == 9) && (((*(f32 *)(hero + 0x49c)) - (*(f32 *)(hero + 0xc18))) > 6.0f) && ((func_L01_004DFE80((*(u8 *)((u8 *)sp74 + 0x42))) == 8) || (func_L01_004DFE80((*(u8 *)((u8 *)sp74 + 0x42))) == cur)) && ((*(u8 *)((u8 *)sp74 + 0x42)) == (*(u8 *)((u8 *)sp74 + 0x43))) && ((*(f32 *)(hero + 0x1b0)) < D_L19_001DBD44[1][1] * 0.0016666668f) && ((*(f32 *)(hero + 0x174)) < 0.041666668f)) {
                f32 rate = 9.0f / (*(f32 *)(hero + 0xc00));
                s32 at;
                if (rate > 10.0f) {
                    rate = 10.0f;
                }
                at = (s32)((*(f32 *)(hero + 0xc18))) + 4;
                func_L01_0050FB40(7, at / 2, rate);
                (*(s32 *)(hero + 0x25c4)) = 7;
            }
            {
                s32 a = (s32)((*(f32 *)(hero + 0xc18)));
                if (a == (s32)((*(f32 *)(hero + 0x49c)))) {
                    (*(s32 *)(hero + 0xc00)) = 0;
                }
            }
        }
        if ((*(u8 *)(hero + 0x46c)) != 0) {
            if ((*(u32 *)(hero + 0x25c4)) == 0xA) {
                if (func_L19_004F32A0(3, 0) != 0) {
                    func_L01_0050FB40(5, 0, -2.0f);
                    func_0038CE20(hero + 0x160, hero + 0x160, 0.8f);
                }
                break;
            }
            if (((*(u8 *)(hero + 0x147c)) == 0) && ((*(s16 *)(hero + 0x1e0)) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) && ((*(s16 *)(hero + 0x36e)) < 4)) {
                if (!((*(f32 *)(hero + 0x1b0)) > D_L19_001DBD44[0][2])) {
                    func_L19_004F32A0(7, 1);
                } else if (!(func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) < 1.0471976f)) {
                    func_L19_004F32A0(7, 1);
                } else if (D_L19_001DBD44[1][1] * 0.014166668f < (*(f32 *)(hero + 0x174))) {
                    func_L19_004F32A0(9, 1);
                } else {
                    func_L19_004F32A0(7, 1);
                }
                break;
            }
        }
        if (((*(u8 *)(hero + 0x46c)) >= 2) && ((*(u32 *)(hero + 0x25c4)) != 0xA)) {
            func_L01_00506BB0();
        } else if (((*(u8 *)(hero + 0x46e)) != 0) && ((*(s32 *)(hero + 0x1b8)) >= (*(s16 *)(hero + 0x4fa))) && ((*(f32 *)(hero + 0x33c)) > (*(f32 *)(hero + 0x4e0)))) {
            func_L19_004F32A0(6, 1);
        }
        if (((*(u32 *)(hero + 0x25c4)) == 0x10) && ((*(s32 *)(hero + 0x1b8)) >= 0x3D) && ((*(f32 *)(hero + 0x33c)) > 1.5f)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        {
            u32 s = (*(u32 *)(hero + 0x25c4));
            s32 ok = 0;
            if ((s == 7) || (s == 9) || (s == 0x11)) {
                ok = 1;
            }
            if (((*(s32 *)(hero + 0x1d4)) != 0) && ((*(u8 *)(hero + 0x46c)) == 0) && (ok != 0) && (((*(u32 *)(hero + 0x25c4)) != 0x11) || ((*(s32 *)(hero + 0x1b8)) >= 0x1A)) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, &sp6C, 0) != 0) && (sp6C < (*(s32 *)(hero + 0x1b8)))) {
                func_L19_004F32A0(0x11, 1);
                break;
            }
        }
        if ((((*(u32 *)(hero + 0x25c4)) == 0xA) || ((*(u32 *)(hero + 0x25c4)) == 0x10)) && ((*(s32 *)(hero + 0x1b8)) >= 0x1A) && ((*(s16 *)(hero + 0x36a)) != 0)) {
            (*(s16 *)(hero + 0x4f6)) = 0x14;
        }
        sc = (*(u32 *)(hero + 0x25c4));
        lim = 0x14;
        if (sc == 0x10) {
            lim = 8;
        }
        if ((sc == 0xE) && ((*(f32 *)(hero + 0x33c)) > 4.0f)) {
            if (((*(u8 *)(hero + 0x46e)) == 0) && ((*(f32 *)(hero + 0xc00)) < 1.3f)) {
                func_003C4138((f32 *)(hero + 0xc00), 1.3f, 0.1f);
            }
            lim = 0x11;
            (*(s16 *)(hero + 0x4f6)) = lim;
        }
        frames = (*(s32 *)(hero + 0x1b8)) - 4;
        if (frames <= 1) {
            frames = 2;
        }
        if (frames >= 0x1F) {
            frames = 0x1E;
        }
        if (!((*(long *)(hero + 0x468)) & 0xFF0000FF00000000L)) {
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) || ((*(u32 *)(hero + 0x25c4)) == 0xE) || ((*(u32 *)(hero + 0x25c4)) == 0xF) || ((*(u32 *)(hero + 0x25c4)) == 0xD)) {
                if (((*(u32 *)(hero + 0x25c4)) != 0xE) && ((*(u8 *)(hero + 0x25e9)) == 0) && (((*(u8 *)(hero + 0x147c)) == 0) || ((*(f32 *)(hero + 0x33c)) >= 0.4f)) && ((*(u8 *)(hero + 0x4ff)) != 0) && ((*(s32 *)(hero + 0x1b8)) >= 0xF) && (((*(u8 *)(hero + 0x46e)) == 0) || (((*(f32 *)(hero + 0x33c)) > 0.7f) && (__builtin_fabsf(func_L01_005114B0((s8 *)(hero + 0xf0))) < 0.09666667f)))) {
                    func_L19_004F32A0(0xE, 1);
                } else if ((D_00142CA0[2] != 0) && (func_L01_004E9238(3) != 4) && ((*(s16 *)(hero + 0x2884)) == 0) && ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(0x40, 0)) && (lim < (*(s32 *)(hero + 0x1b8))) && ((*(s16 *)(hero + 0x4f6)) < (*(s32 *)(hero + 0x1b8)))) {
                    f32 need = 0.6f;
                    if (((*(u32 *)(hero + 0x25c4)) == 9) || ((*(u32 *)(hero + 0x25c4)) == 7)) {
                        need = 1.0f;
                    }
                    if ((*(u32 *)(hero + 0x25c4)) == 0xE) {
                        need = 1.5f;
                    }
                    if (need < (*(f32 *)(hero + 0x33c))) {
                        func_L19_004F32A0(8, 1);
                    }
                }
            }
        }
        if (((*(s32 *)(hero + 0x528)) != 0) && ((*(u32 *)(hero + 0x25c4)) != 0xB)) {
            func_L19_004F32A0(0x17, 1);
        }
        break;
    }
    case 0x16:
        if (((*(f32 *)(hero + 0xc18)) > 12.5f) && ((*(u8 *)(hero + 0x2877)) == 0) && ((*(s16 *)(hero + 0x36e)) != 0) && ((*(f32 *)(hero + 0x33c)) > 1.0f)) {
            func_L19_004F32A0(6, 1);
            break;
        }
        if ((*(s32 *)(hero + 0x1b8)) >= 0x1C) {
            if ((*(s32 *)(hero + 0x2850)) <= 0) {
                if ((*(u8 *)(hero + 0x1477)) != 0) {
                    func_L19_004F32A0(0x79, 1);
                } else {
                    func_L19_004F32A0(0x39, 1);
                }
            } else if ((*(u8 *)(hero + 0x2877)) != 0) {
                func_L19_004F32A0(0x82, 1);
            } else {
                func_L19_004F32A0(0, 0);
            }
        }
        break;
    case 0x8C:
        if ((*(s32 *)(hero + 0xc08)) & 2) {
            func_L01_0050FB40(0x97, 0, 2.0f);
        }
        if (((*(s32 *)(hero + 0x1b8)) >= 0x33) && ((*(s16 *)(hero + 0x1e0)) == 0)) {
            if ((*(s32 *)(hero + 0x2850)) <= 0) {
                func_L19_004F32A0(0x39, 1);
            } else if (func_L19_004F32A0(0, 0) != 0) {
                func_L01_0050FB40(func_L01_004DFDB0(0), 0, 13.0f);
            }
        }
        break;
    case 0x85:
        if (((*(s32 *)(hero + 0x1b8)) >= 4) && ((*(s32 *)(D_001D52FC + 0x1A4)) & 0x10)) {
            func_L20_002DC390(0);
        }
        break;
    case 0x3F:
    {
        s16 t = (*(s16 *)(hero + 0x28a8));
        if (t >= 0x2B) {
            func_L01_0050FB40(0x12, 0, 10.0f);
            break;
        }
        if ((t == 0) && ((*(s32 *)(hero + 0xc08)) & 2)) {
            if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != 0) {
                func_L01_0050FB40(0, 0, 12.0f);
            } else if (func_003824E0(0.0f, 1.0f) < 0.5f) {
                func_L01_0050FB40(1, 0, 8.0f);
            }
        }
        if ((*(u8 *)(hero + 0x147c)) != 0) {
            func_L19_004F32A0(0x4E, 1);
            break;
        }
        if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ((*(s32 *)(hero + 0x1228)) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if ((*(s16 *)(hero + 0x36e)) != 0) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) {
            func_L19_004F32A0(0x45, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 9, 0, 0) != 0) {
            func_L19_004F32A0(0x4D, 1);
            break;
        }
        func_L01_004EE850(0, 1.0f);
        if (((*(f32 *)(hero + 0x2838)) > 0.2f) && ((*(f32 *)(hero + 0x1b0)) > 0.0f)) {
            func_L19_004F32A0(0x40, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x28a8)) == 0) && ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 0x12)) {
            func_L01_0050FB40(0, 0, 12.0f);
        }
        break;
    }
    case 0x4D:
    {
        u8 *rec;
        s32 frames;
        if ((*(u8 *)(hero + 0x147c)) != 0) {
            func_L19_004F32A0(0x4E, 1);
            break;
        }
        rec = (u8 *)&D_L19_002F8BD0[(*(s16 *)(hero + 0xbdc))];
        if ((*(s32 *)(hero + 0xc0c)) == 0) {
            s32 busy;
            if ((f32)(*(s32 *)((u8 *)rec + 0x18)) < (*(f32 *)(hero + 0xc18))) {
                func_L19_004F32A0(0x3F, 0);
            }
            busy = (*(s32 *)(hero + 0xc0c));
            if ((busy == 0) && ((f32)(*(s32 *)((u8 *)rec + 0x10)) <= (*(f32 *)(hero + 0xc18)))) {
                s32 n = (s32)((*(f32 *)(hero + 0xc18))) - (*(s32 *)((u8 *)rec + 0xC));
                if (n < 1) {
                    n = 1;
                }
                if (func_L01_004606E8(0x80, (n < 0x10) ? n : 0xF, 0, 0) != 0) {
                    func_L19_004F32A0(0x4D, 1);
                }
            }
        }
        frames = ((s32)((*(f32 *)(hero + 0xc18))) - (*(s32 *)((u8 *)rec + 0xC))) * 2;
        if (((f32)(*(s32 *)((u8 *)rec + 0x14)) < (*(f32 *)(hero + 0xc18))) && ((*(s32 *)(hero + 0xc0c)) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0)) {
            func_L19_004F32A0(0x45, 1);
        }
        break;
    }
    case 0x45:
    case 0x48:
    {
        s16 lo = (*(s16 *)(hero + 0x47c));
        s32 now = (*(s32 *)(hero + 0x1b8));
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            func_L01_00511748((f32 *)(hero + 0x80), (f32 *)(hero + 0xf0), &sp70, (*(f32 *)(hero + 0x4f0)));
            func_L01_004E5030((*(f32 *)(hero + 0x498)), (f32)sp70, (*(f32 *)(hero + 0x4e4)), -1.0f);
            break;
        }
        if (((*(u8 *)(hero + 0x46d)) != 0) && (now >= (*(s32 *)(hero + 0x400))) && (now < (*(s32 *)(hero + 0x404)))) {
            f32 left = (f32)((*(s32 *)(hero + 0x410)) - (*(s32 *)(hero + 0x400)));
            if (left > 0.0f) {
                func_L01_004E5030((*(f32 *)(hero + 0x498)), left, (*(f32 *)(hero + 0x4e4)), -1.0f);
            }
            break;
        }
        {
            u8 c = (*(u8 *)(hero + 0x46c));
            if (c != 0) {
                (*(u8 *)(hero + 0x46c)) = c + 1;
            } else if (((*(s16 *)(hero + 0x36e)) == 0) && ((*(u8 *)(hero + 0x46e)) != 0)) {
                s32 k;
                (*(u8 *)(hero + 0x46c)) = 1;
                k = (s32)((*(f32 *)(hero + 0x4a0))) + 3;
                if ((*(f32 *)(hero + 0xc18)) < (*(f32 *)(hero + 0x49c))) {
                    func_L01_0050FB40((*(u8 *)((u8 *)sp74 + 0x43)), k, 6.0f);
                }
            }
        }
        if ((*(u8 *)(hero + 0x46c)) != 0) {
            (*(f32 *)(hero + 0xc00)) = 1.0f;
        } else if ((*(u8 *)(hero + 0x46e)) != 0) {
            s32 a;
            if ((s32)(*(u8 *)((u8 *)sp74 + 0x41)) < (s32)((*(f32 *)(hero + 0x4a0)))) {
                s32 k;
                (*(s16 *)(hero + 0x47e)) = (s32)(func_L19_00501FE0(60.0f, (*(f32 *)(hero + 0x4f0)), -1.0f));
                func_L01_004E5030((*(f32 *)(hero + 0x49c)), (f32)(*(s16 *)(hero + 0x47e)), (*(f32 *)(hero + 0x4e4)), -1.0f);
                k = (s32)((*(f32 *)(hero + 0x4a0))) + 1;
                if ((*(f32 *)(hero + 0xc00)) > 1.8f) {
                    func_L01_0050FB40((*(u8 *)((u8 *)sp74 + 0x43)), k, (f32)((*(s16 *)(hero + 0x47e)) + 2));
                }
                if ((*(f32 *)(hero + 0xc00)) < 0.2f) {
                    (*(f32 *)(hero + 0xc00)) = 0.2f;
                }
                if ((*(f32 *)(hero + 0xc00)) > 2.7f) {
                    (*(f32 *)(hero + 0xc00)) = 2.7f;
                }
            }
            a = (s32)((*(f32 *)(hero + 0xc18)));
            if (a == (s32)((*(f32 *)(hero + 0x49c)))) {
                (*(s32 *)(hero + 0xc00)) = 0;
            }
        }
        if (((*(u8 *)(hero + 0x46c)) != 0) && ((*(s16 *)(hero + 0x1e0)) == 0) && ((*(u8 *)(hero + 0x147c)) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 4, 0, 0) != 0) && ((*(s16 *)(hero + 0x36e)) < 4)) {
            func_L01_004EE850(0, 1.0f);
            func_L19_004F32A0(0x45, 1);
            break;
        }
        if ((*(u8 *)(hero + 0x46c)) >= 2) {
            (*(s32 *)(hero + 0x280c)) = 0;
            func_L01_004EE850(0, 1.0f);
            if (((*(f32 *)(hero + 0x1b0)) > D_L19_001DBD44[0][2]) && ((*(f32 *)(hero + 0x2838)) > 0.5f) && ((*(u8 *)(hero + 0x147c)) == 0) && ((*(s16 *)(hero + 0x1e0)) == 0) && (func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) < 1.5707964f)) {
                func_L19_004F32A0(0x40, 1);
            } else if ((*(u8 *)(hero + 0x46c)) >= 0xD) {
                func_L19_004F32A0(0x3F, 1);
            }
        }
        if (((*(f32 *)(hero + 0x33c)) > 2.0f) && ((*(u8 *)(hero + 0x46e)) != 0) && ((*(s32 *)(hero + 0x1b8)) >= 0x29)) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if (((*(u8 *)(hero + 0x46e)) != 0) && ((*(f32 *)(hero + 0x33c)) < 0.2f) && (func_L01_004606E8(0x80, 5, 0, 0) != 0)) {
            func_L19_004F32A0(0x4D, 1);
            break;
        }
        if ((*(s32 *)(hero + 0x528)) != 0) {
            func_L19_004F32A0(0x46, 1);
            break;
        }
        if (((*(u32 *)(hero + 0x25c4)) != 0x48) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 5, 0, 0) != 0) && ((*(f32 *)(hero + 0x33c)) > 0.55f)) {
            func_L19_004F32A0(0x4B, 1);
        }
        break;
    }
    case 0x4B:
        if (((*(s32 *)(hero + 0x1b8)) >= 0x1F) && !((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(0x40, 0))) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if ((*(s32 *)(hero + 0x528)) != 0) {
            func_L19_004F32A0(0x46, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) != 0) && !(((*(f32 *)(hero + 0x88)) - (*(f32 *)(hero + 0x338))) < 0.0f)) {
            break;
        }
        if ((*(s32 *)(hero + 0x1b8)) < 0xA) {
            (*(s16 *)(hero + 0x1ee)) = 0xC - (*(u16 *)(hero + 0x1b8));
        }
        if ((*(f32 *)(hero + 0x2838)) > 0.3f) {
            func_L19_004F32A0(0x40, 1);
            break;
        }
        if ((*(s16 *)(hero + 0x36e)) == 0) {
            func_L19_004F32A0(0x3F, 1);
        }
        break;
    case 0x41:
        if ((*(s16 *)(hero + 0x36e)) == 0) {
            if ((*(f32 *)(hero + 0x118)) < -0.15f) {
                (*(f32 *)(hero + 0x118)) = -0.15f;
            }
            if ((*(f32 *)(hero + 0xf8)) < -0.15f) {
                (*(f32 *)(hero + 0xf8)) = -0.15f;
            }
            if ((*(s32 *)(hero + 0x2850)) <= 0) {
                func_L19_004F32A0(0x43, 1);
            } else if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
                if ((*(s16 *)(hero + 0x1e0)) == 0) {
                    func_L19_004F32A0(0x40, 1);
                } else {
                    func_L19_004F32A0(0x3F, 1);
                }
            } else {
                func_L19_004F32A0(0x3F, 1);
            }
        } else if ((*(s32 *)(hero + 0x2850)) > 0) {
            if ((*(s32 *)(hero + 0x528)) != 0) {
                func_L19_004F32A0(0x46, 1);
                break;
            }
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), 5, 0, 0) != 0) && ((*(f32 *)(hero + 0x33c)) > 0.6f)) {
                func_L19_004F32A0(0x4B, 1);
            }
        }
        break;
    case 0x44:
        if (((*(f32 *)(hero + 0xf8)) < 0.0f) && ((*(s32 *)(hero + 0x360)) != 0)) {
            func_L19_004F32A0(0x3F, 1);
        }
        break;
    case 0x4E:
        if ((*(s32 *)(hero + 0x1b8)) >= 0x12D) {
            func_L01_004EDE10();
        }
        if ((*(u8 *)(hero + 0x147c)) == 0) {
            if ((*(s16 *)(hero + 0x36e)) != 0) {
                func_L19_004F32A0(0x41, 1);
            } else {
                func_L19_004F32A0(0x3F, 1);
            }
        }
        break;
    case 0x40:
    {
        f32 speed;
        u8 *o;
        s32 anim;
        if ((*(u8 *)(hero + 0x147c)) != 0) {
            func_L19_004F32A0(0x4E, 1);
            break;
        }
        if (((*(s32 *)(hero + 0xc0c)) == 0) && ((*(f32 *)(hero + 0x170)) < 0.025000002f) && ((*(u8 *)((u8 *)o = (*(u8 * *)(hero + 0x25c0)) + 0x43)) != 2)) {
            u8 *info = (*(u8 * *)((u8 *)o + 0x24));
            s32 n = (*(u8 *)((u8 *)(*(u8 * *)((u8 *)info + 0x50)) + 0x10));
            func_L01_0050FB40(2, ((*(u8 *)((u8 *)o + 0x41)) * n / (*(u8 *)((u8 *)(*(u8 * *)((u8 *)info + 0x54)) + 0x10)) + 1) % n, 8.0f);
        } else if (((*(s32 *)(hero + 0xc0c)) == 0) && ((*(f32 *)(hero + 0x170)) > 0.030000003f) && ((*(u8 *)((u8 *)o = (*(u8 * *)(hero + 0x25c0)) + 0x43)) != 3)) {
            u8 *info = (*(u8 * *)((u8 *)o + 0x24));
            s32 n = (*(u8 *)((u8 *)(*(u8 * *)((u8 *)info + 0x54)) + 0x10));
            func_L01_0050FB40(3, ((*(u8 *)((u8 *)o + 0x41)) * n / (*(u8 *)((u8 *)(*(u8 * *)((u8 *)info + 0x50)) + 0x10)) + 7) % n, 8.0f);
        }
        speed = (*(f32 *)(hero + 0x170));
        if ((*(u8 *)(hero + 0x3ef)) != 0) {
            speed = 0.050000004f;
        }
        anim = (*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43));
        if (anim == 2) {
            (*(f32 *)(hero + 0xc00)) = speed * 90.0f;
        } else if (anim == 3) {
            (*(f32 *)(hero + 0xc00)) = speed * 20.0f;
        }
        if ((*(f32 *)(hero + 0xc00)) < 0.57f) {
            (*(f32 *)(hero + 0xc00)) = 0.57f;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) {
            func_L19_004F32A0(0x45, 1);
            break;
        }
        if (func_L01_004606E8(0x80, 9, 0, 0) != 0) {
            func_L19_004F32A0(0x4D, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) >= 5) && (((*(f32 *)(hero + 0x33c)) > 0.8f) || ((*(f32 *)(hero + 0x340)) > 0.8726647f))) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) == 0) && ((*(f32 *)(hero + 0x2838)) < 0.17f)) {
            func_L19_004F32A0(0x3F, 1);
        }
        break;
    }
    case 0x42:
        if (((*(s32 *)(hero + 0x1b8)) >= 0x20) && ((*(s16 *)(hero + 0x36e)) != 0) && ((*(f32 *)(hero + 0x33c)) > 1.0f)) {
            func_L19_004F32A0(0x41, 1);
            break;
        }
        if ((*(s32 *)(hero + 0x1b8)) >= 0x24) {
            if ((*(s32 *)(hero + 0x2850)) <= 0) {
                func_L19_004F32A0(0x43, 1);
            } else {
                func_L19_004F32A0(0x3F, 0);
            }
        }
        break;
    case 0x46:
        if ((*(s32 *)(hero + 0xc08)) & 2) {
            func_L19_004F32A0(0x47, 1);
        }
        break;
    case 0x47:
        func_L01_004EE850(0, 1.0f);
        *(s128 *)v10 = (*(s128 *)(hero + 0x80 + 0));
        if (func_L01_004E8318((s8 *)v10, (s8 *)(hero + 0x90), 0) == 0) {
            func_L19_004F32A0(0x41, 1);
            (*(s16 *)(hero + 0x1d0)) = 0xA;
            break;
        }
        if ((((*(f32 *)(hero + 0x2838)) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) && (func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) > 2.3561947f)) || ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0))) {
            func_L19_004F32A0(0x41, 1);
            (*(s16 *)(hero + 0x1d0)) = 0xA;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) {
            func_L19_004F32A0(0x48, 1);
            break;
        }
        if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
            if (func_0038DBA0((*(f32 *)(hero + 0x1a0)), func_0038DAB8((*(f32 *)(hero + 0x98)), 1.5707965f)) < 0.78539824f) {
                *(s128 *)(v20) = *(s128 *)(hero + 0x80);
                v20[0] += func_0038D098(func_0038DAB8((*(f32 *)(hero + 0x98)), 1.5707965f)) * 0.3f;
                v20[1] += func_0038D0B0(func_0038DAB8((*(f32 *)(hero + 0x98)), 1.5707965f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v20, (s8 *)(hero + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x49, 1);
                }
                break;
            }
        }
        if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
            if (func_0038DBA0((*(f32 *)(hero + 0x1a0)), func_0038DAB8((*(f32 *)(hero + 0x98)), -1.5707965f)) < 0.78539824f) {
                *(s128 *)(v20) = *(s128 *)(hero + 0x80);
                v20[0] += func_0038D098(func_0038DAB8((*(f32 *)(hero + 0x98)), -1.5707965f)) * 0.3f;
                v20[1] += func_0038D0B0(func_0038DAB8((*(f32 *)(hero + 0x98)), -1.5707965f)) * 0.3f;
                if (func_L01_004E8318((s8 *)v20, (s8 *)(hero + 0x90), 0) != 0) {
                    func_L19_004F32A0(0x4A, 1);
                }
            }
        }
        break;
    case 0x49:
    case 0x4A:
    {
        f32 side;
        *(s128 *)v10 = (*(s128 *)(hero + 0x80 + 0));
        side = 1.5707965f;
        if ((*(u32 *)(hero + 0x25c4)) == 0x4A) {
            side = -1.5707965f;
        }
        v10[0] += func_0038D098(func_0038DAB8((*(f32 *)(hero + 0x98)), side)) * 0.3f;
        v10[1] += func_0038D0B0(func_0038DAB8((*(f32 *)(hero + 0x98)), side)) * 0.3f;
        func_L01_004EE850(0, 1.0f);
        if (((*(f32 *)(hero + 0x2838)) < 0.5f) || (func_0038DBA0((*(f32 *)(hero + 0x1a0)), func_0038DAB8((*(f32 *)(hero + 0x98)), side)) > 0.78539824f) || (func_L01_004E8318((s8 *)v10, (s8 *)(hero + 0x90), 0) == 0)) {
            if ((*(s32 *)(hero + 0xc08)) & 2) {
                func_L19_004F32A0(0x47, 1);
                break;
            }
        }
        if (((*(f32 *)(hero + 0x2838)) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) && (func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) > 2.3561947f)) {
            func_L19_004F32A0(0x41, 1);
            (*(s16 *)(hero + 0x1d0)) = 0x28;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) {
            func_L19_004F32A0(0x48, 1);
        }
        break;
    }
    case 0x8D:
    {
        s32 turned;
        if (((*(s32 *)(hero + 0xc08)) & 2) && ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != 0xD)) {
            func_L01_0050FB40(0xD, 0, 12.0f);
        }
        if ((*(u8 *)(hero + 0x147c)) != 0) {
            func_L19_004F32A0(0x94, 1);
            break;
        }
        if (((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0)) && ((*(s32 *)(hero + 0x1228)) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L19_004F32A0(1, 1);
            break;
        }
        if ((*(s16 *)(hero + 0x36e)) != 0) {
            func_L19_004F32A0(0x8F, 1);
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) {
            func_L19_004F32A0(0x92, 1);
            break;
        }
        if (((*(s16 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0xAA)) != 0xEE1) && (func_L01_004606E8(0x80, 9, 0, 0) != 0)) {
            func_L19_004F32A0(0x93, 1);
            break;
        }
        func_L01_004EE850(0, 1.0f);
        turned = func_L01_004EDFC8(0.17453295f);
        if (((*(f32 *)(hero + 0x2838)) > 0.2f) || (turned != 0)) {
            func_L19_004F32A0(0x8E, 1);
        }
        break;
    }
    case 0x93:
        if ((*(u8 *)(hero + 0x147c)) != 0) {
            func_L19_004F32A0(0x94, 1);
        }
        break;
    case 0x92:
    {
        s32 lo;
        s32 now;
        func_L18_002C4000();
        lo = (*(s16 *)(hero + 0x47c));
        now = (*(s32 *)(hero + 0x1b8));
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 6) {
                func_L01_00511748((f32 *)(hero + 0x80), (f32 *)(hero + 0xf0), &sp74w, (*(f32 *)(hero + 0x4f0)));
                func_L01_004E5030((*(f32 *)(hero + 0x498)), (f32)sp74w, 0.5f, -1.0f);
            }
            break;
        }
        {
            u8 c = (*(u8 *)(hero + 0x46c));
            if (c != 0) {
                (*(u8 *)(hero + 0x46c)) = c + 1;
            } else if (((*(s16 *)(hero + 0x36e)) == 0) && ((*(u8 *)(hero + 0x46e)) != 0)) {
                (*(u8 *)(hero + 0x46c)) = 1;
                if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != 6) {
                    goto after_pose;
                }
                {
                    s32 k = (s32)((*(f32 *)(hero + 0x4a0))) + 3;
                    if ((*(f32 *)(hero + 0xc18)) < (*(f32 *)(hero + 0x49c))) {
                        func_L01_0050FB40((*(u8 *)((u8 *)sp74 + 0x43)), k, 6.0f);
                    }
                }
            }
        }
        if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) == 6) {
            if ((*(u8 *)(hero + 0x46c)) != 0) {
                (*(f32 *)(hero + 0xc00)) = 1.0f;
            } else if ((*(u8 *)(hero + 0x46e)) != 0) {
                s32 a;
                if ((s32)(*(u8 *)((u8 *)sp74 + 0x41)) < (s32)((*(f32 *)(hero + 0x4a0)))) {
                    s32 k;
                    (*(s16 *)(hero + 0x47e)) = (s32)(func_L19_00501FE0(60.0f, (*(f32 *)(hero + 0x4f0)), -1.0f));
                    func_L01_004E5030((*(f32 *)(hero + 0x49c)), (f32)(*(s16 *)(hero + 0x47e)), 0.5f, -1.0f);
                    k = (s32)((*(f32 *)(hero + 0x4a0))) + 1;
                    if ((*(f32 *)(hero + 0xc00)) > 1.8f) {
                        func_L01_0050FB40((*(u8 *)((u8 *)sp74 + 0x43)), k, (f32)((*(s16 *)(hero + 0x47e)) + 2));
                    }
                    if ((*(f32 *)(hero + 0xc00)) < 0.2f) {
                        (*(f32 *)(hero + 0xc00)) = 0.2f;
                    }
                    if ((*(f32 *)(hero + 0xc00)) > 2.7f) {
                        (*(f32 *)(hero + 0xc00)) = 2.7f;
                    }
                }
                a = (s32)((*(f32 *)(hero + 0xc18)));
                if (a == (s32)((*(f32 *)(hero + 0x49c)))) {
                    (*(s32 *)(hero + 0xc00)) = 0;
                }
            }
        }
    after_pose:
        if (((*(u8 *)(hero + 0x46c)) != 0) && ((*(s16 *)(hero + 0x1e0)) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 4, 0, 0) != 0) && ((*(s16 *)(hero + 0x36e)) < 4)) {
            func_L01_004EE850(0, 1.0f);
            func_L19_004F32A0(0x92, 1);
            break;
        }
        if ((*(u8 *)(hero + 0x46c)) >= 2) {
            (*(s32 *)(hero + 0x280c)) = 0;
            func_L01_004EE850(0, 1.0f);
            if (((*(f32 *)(hero + 0x1b0)) > D_L19_001DBD44[0][2]) && ((*(f32 *)(hero + 0x2838)) > 0.5f) && ((*(u8 *)(hero + 0x147c)) == 0) && ((*(s16 *)(hero + 0x1e0)) == 0) && (func_0038DBA0((*(f32 *)(hero + 0x1a0)), (*(f32 *)(hero + 0x98))) < 1.5707964f)) {
                func_L19_004F32A0(0x8E, 1);
            } else if ((*(u8 *)(hero + 0x46c)) >= 0xD) {
                func_L19_004F32A0(0x8D, 1);
            }
        }
        if (((*(f32 *)(hero + 0x33c)) > 2.0f) && ((*(u8 *)(hero + 0x46e)) != 0) && ((*(s32 *)(hero + 0x1b8)) >= 0x29)) {
            func_L19_004F32A0(0x8F, 1);
        }
        break;
    }
    case 0x8F:
        if ((*(s16 *)(hero + 0x36e)) == 0) {
            if ((*(f32 *)(hero + 0x118)) < -0.15f) {
                (*(f32 *)(hero + 0x118)) = -0.15f;
            }
            if ((*(f32 *)(hero + 0xf8)) < -0.15f) {
                (*(f32 *)(hero + 0xf8)) = -0.15f;
            }
            if ((*(s32 *)(hero + 0x2850)) <= 0) {
                func_L19_004F32A0(0x91, 1);
            } else if ((*(f32 *)(hero + 0x2838)) > 0.5f) {
                if ((*(s16 *)(hero + 0x1e0)) == 0) {
                    func_L19_004F32A0(0x8E, 1);
                } else {
                    func_L19_004F32A0(0x8D, 1);
                }
            } else {
                func_L19_004F32A0(0x8D, 1);
            }
        }
        break;
    case 0x94:
        if ((*(s32 *)(hero + 0x1b8)) >= 0x12D) {
            func_L01_004EDE10();
        }
        if ((*(u8 *)(hero + 0x147c)) == 0) {
            if ((*(s16 *)(hero + 0x36e)) != 0) {
                func_L19_004F32A0(0x8F, 1);
            } else {
                func_L19_004F32A0(0x8D, 1);
            }
        }
        break;
    case 0x8E:
        if ((*(u8 *)(hero + 0x147c)) != 0) {
            func_L19_004F32A0(0x94, 1);
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) {
            func_L19_004F32A0(0x92, 1);
            break;
        }
        if (((*(s16 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0xAA)) != 0xEE1) && (func_L01_004606E8(0x80, 9, 0, 0) != 0)) {
            func_L19_004F32A0(0x93, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) >= 5) && (((*(f32 *)(hero + 0x33c)) > 0.8f) || ((*(f32 *)(hero + 0x340)) > 0.8726647f))) {
            func_L19_004F32A0(0x8F, 1);
            break;
        }
        if (((*(s16 *)(hero + 0x36e)) == 0) && ((*(f32 *)(hero + 0x2838)) < 0.17f) && ((*(s16 *)(hero + 0x1434)) == 0)) {
            func_L19_004F32A0(0x8D, 1);
        }
        break;
    case 0x90:
        if (((*(s32 *)(hero + 0x1b8)) >= 0x20) && ((*(s16 *)(hero + 0x36e)) != 0) && ((*(f32 *)(hero + 0x33c)) > 1.0f)) {
            func_L19_004F32A0(0x8F, 1);
            break;
        }
        if (((*(s32 *)(hero + 0xc08)) & 2) || ((*(s32 *)(hero + 0x1b8)) >= 0x24)) {
            if ((*(s32 *)(hero + 0x2850)) <= 0) {
                func_L19_004F32A0(0x91, 1);
            } else {
                func_L19_004F32A0(0x8D, 0);
            }
        }
        break;
    case 0x1D:
        if (((*(u8 *)(hero + 0x25e4)) == 0) && (((*(u8 *)(hero + 0x25eb)) == 0) || ((*(u8 *)(hero + 0x25e5)) != 0))) {
            if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 8.0f);
            } else {
                func_L01_0050FB40(func_L01_004DFDB0(1), 0, 8.0f);
            }
        }
        if (!((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(4, 0))) {
            if ((*(u32 *)(hero + 0x25c4)) == 0x1D) {
                s32 anim;
                func_L19_004F32A0(0, 0);
                anim = func_L01_004DFDB0(1);
                if ((*(u8 *)((u8 *)(*(u8 * *)(hero + 0x25c0)) + 0x43)) != anim) {
                    func_L01_0050FB40(anim, 0, 8.0f);
                }
            }
            D_L19_002D3AC4 = 0;
        }
        break;
    case 0x1F:
        if (((*(s32 *)(hero + 0x1200)) != 0) && ((*(s32 *)(hero + 0xc0c)) == 0) && ((*(f32 *)(hero + 0xc18)) > 20.0f)) {
            func_L19_004F32A0(0, 0);
        }
        break;
    case 0x22:
        if ((*(f32 *)(hero + 0xc18)) > 19.0f) {
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 0xB, 0, 0) != 0) {
                if ((*(s32 *)(D_001D52FC + 0x1A0)) & func_003A3BB8(8, 0)) {
                    func_L01_00506E30();
                    break;
                }
                func_L19_004F32A0(7, 1);
                break;
            }
        }
        if ((*(f32 *)(hero + 0xc18)) >= 21.0f) {
            func_L19_004F32A0(0, 0);
        }
        break;
    default:
        break;
    }
end:
    if (sp78 != (*(s32 *)(hero + 0xa8))) {
        func_L01_004E1560();
    }
    temp_a0_31 = (*(s32 *)(hero + 0x25d0));
    if (((temp_a0_31 == 0x3C) && ((*(s32 *)(hero + 0x25c4)) != 0x3D)) || ((temp_a0_31 == 0x3D) && ((*(s32 *)(hero + 0x157c)) != 0))) {
        func_L01_00506820();
    }
    if (sp7C != (*(s32 *)(hero + 0x25c8))) {
        (*(s32 *)(hero + 0x1c0)) = 0;
    }
    if (sp80 != (*(u8 *)((u8 *)sp74 + 0x43))) {
        (*(s32 *)(hero + 0x1c4)) = 0;
    }
}
