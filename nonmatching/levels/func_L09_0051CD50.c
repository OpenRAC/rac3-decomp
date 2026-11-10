/* func_L09_0051CD50: Opus handoff (prep by Sonnet worker w4, 2026-11-08), dossier relative to the seed func_L04_00513880
   Size: 22344 bytes, places: 1 level (09), file: src/levels/09_tyhrranosis/L09_0051CD50.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function; main switch on hero state +0x25C4 via jtbl_002BE9A0, 178 entries, default 005223F8.
   Twin: family member of the rac3 decider seed (see out/func_L04_00513880.c for the full dossier, offset/callee/global mapping and tools).
     Similarity: 0.8586 to the seed (5120 of 5586), 0.9864 to func_L02_004DA1D0; rac2 donor per index func_L08_002D90C8 0.814.
   State differences vs the seed (retail jump tables): seed-only (default here): 0x3F-0x42 0x44-0x4B 0x4D-0x4F 0x72; sibling-only: 0x50 0x81 (no donor in the seed draft).
   Mapping vs the seed: hero offsets identical (the aligned loads/stores agree), pad/remap layer identical; only level-specific symbols
     change (rename map from rac3/rac3 alignment: data D_L04_xxxx -> D_L09_xxxx at the per-level address, e.g. D_L04_002F4BB0 -> its L09 address;
     level-local functions func_L04_0050CB28 -> its L09 address; shared func_L01_* stay). L09 and L02 differ by 69 instructions: finish L02, then diff the two and port.
   Draft: compiles with the file's flags; it is the seed draft with those renames and this level's own state set (cases the jump table sends to default are dropped,
     cases only this level has are NOT in the draft). Measured: 17304 vs 22344 B (4326 vs 5586 instr), 5324 diff rows, ratio 0.783 (frame/registers differ as in the seed).
   Left for Opus: land the seed (or func_L27_004D7CD8, 0.977 to the seed) first, then port: diff this function's asm against the matched member by align.py ranges,
     rename, add the sibling-only states. Do not start from this draft before the seed's rac3-only states exist.
   Draft status: study aid until the seed's open items (rac3-only states, prologue locals, unmapped callees) are closed. */
/* func_L09_0051CD50, Yeedil's hero state decider, a member of func_L00_002CB3A8's family
 * (src/levels/shared/L00_002CB3A8-decider.c); drafted on branch match/compose-1
 * (nonmatching/levels/func_L09_0051CD50.c).  The probe loop is written as in func_L00_002CB3A8
 * (see its header).  Its own file for the decider profile in config/cflags.txt. */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef u128_t s128;
#define NULL ((void *)0)
#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
#define M2C_ERROR(d) (0)
#define M2C_UNK s32
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern char D_001425C0[];
extern char D_00188660[];
extern char D_001A4BE0[];
extern char D_00189F10[];
extern u8 D_00143A06;
__asm__(".extern D_00143A06, 16");
extern u8 D_00142CA2;
__asm__(".extern D_00142CA2, 16");
extern s32 D_001A79F0;
extern f32 D_L09_001DBDC4[][4];
extern s32 D_L09_001DBDF4;
extern s32 D_L09_001D6740;
extern f32 D_L09_001DFCB0;
extern s32 D_L09_002D1E30[];
extern s32 D_L09_001DF948;
extern u8 D_001D60F8;
extern u8 D_L09_001DBB50[16];
extern u8 D_L09_001DBB60[16];
extern s32 D_L09_001DBCB0[2];
extern char D_L09_002F4B70[];
extern char D_L09_002F4D80[];
typedef struct { s32 w[11]; } Rec2C;
extern Rec2C D_L09_002F6B10[];
extern char D_L09_002C5E40[];
extern char D_L09_001E2B80[];
s32 func_002761F8(void *, void *, s32, void *, s32);
s32 func_00277258(void *, s32, void *, f32);
s32 func_0038CAD0(void *);
s32 func_0038CB00(s16 *);
void func_00282CC0(void *, void *, void *);
void func_0038CE20(void *, void *, f32);
f32 func_0038CEA8(void *);
f32 func_00282E20(void *);
f32 func_0038CF00(void *, void *);
f32 func_0038CF38(void *, void *);
void func_00282F20(void *, void *, f32);
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
s32 func_003A3BB8(s32 a0, s32 a1);
s32 func_L01_00512DF8(s32 a0);
s32 func_L02_004B6308(s32 arg);
u32 func_L01_004DFE80(u32 param_1);
void func_L01_004E1180(void);
void func_L01_004E11C0(s32 kind, s32 side, s32 play_sound, s32 duration);
void func_L01_004E1560(void);
void func_L01_004E5030(f32 arg0, f32 arg1, f32 arg2, f32 arg3);
void func_L01_004E5EB8(s32 dust, s32 debris, s32 model);
s32 func_L01_004E63F0(f32 *out, f32 scale, f32 amount);
s32 func_L02_004BDFD8(s8 *, s8 *, s8 *);
s32 func_L01_004E9238(s32 index);
void func_L01_004EAA80(void);
void func_L01_004EDE10(void);
s32 func_L01_004EDFA8(u8 *object);
s32 func_L01_004EDFC8(f32 x);
s32 func_L00_002B3998(f32 value);
void func_L01_004EE850(s32, f32);
void func_L01_004EEBA8(void);
s32 func_L01_004F4E70(s32 index, s32 flags);
s32 func_L01_004FF5D8(void);
s32 func_L09_005164C0(s32, s32);
void func_L20_002DC390(s32 a0);
s32 func_L01_00504EC0(void);
s32 func_L01_00504F70(void);
s32 func_L01_00504FE0(void);
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
f32 func_L01_00510478(f32 time, f32 acceleration, f32 height);
void func_L01_00510CA0(s16, u8, u8, u8, f32, f32);
void func_L00_002D36E0(f32 *p, s32 flag, f32 x, f32 y, f32 z);
f32 func_L01_005114B0(s8 *in);
void func_L01_00511508(void *dst, void *src, f32 k);
f32 func_L01_00511748(f32 *a0, f32 *a1, s32 *out, f32 scale);
void func_003E54E0(s32 argument);
void func_003E4D10(s32 argument);
f32 func_L00_0031B9F8(f32 *a0, f32 *a1, s32 *a2, f32 factor);
f32 func_L00_0031CDD0(f32 *a, f32 *b, f32 *out, f32 d, f32 e);
void func_L01_00456230(u8 *entity, s32 enabled);
s32 func_L01_004606E8(s32 mask, s32 arg1, s32 a2, s32 a3);
void func_002E59F8(s32 a0);
void *func_L01_0046E078(s8 *object,void *position,f32 *velocity,s32 *config,s32 flag);
s32 func_L00_00341820(void *path, void *out, s32 *index, f32 *offset, s32 wrap, f32 step);
s32 func_L00_00341FA8(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
void func_L00_0038B888(void *position,s32 count);
s32 func_L01_003EB2D8(void);
s32 func_L02_004C2ED8(s32);
s32 func_L00_002AD868(s8 *, void **, s128 *, void *, void *, s32 *, void *, s32, s32);

void func_L18_002C4000(void);
void func_L09_0051CD50(void) {
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

    sp74 = FLD(D_001A4BE0, void *, 0x25C0);
    sp78 = FLD(D_001A4BE0, s32, 0x25CC);
    sp7C = FLD(D_001A4BE0, s32, 0x25C8);
    sp80 = FLD(sp74, u8, 0x43);
    if (FLD(D_001A4BE0, s32, 0x234) != 0) {
        func_L02_004C2ED8(0);
    } else if (func_L02_004C2ED8(1) != 0) {
        goto end;
    }
    func_L01_00507380();
    if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0) || (FLD(D_001A4BE0, u32, 0x25C4) == 2)) {
            func_L09_005164C0(0x39, 1);
            goto end;
        }
    }
    if (func_L01_005055A0() != 0) {
        goto end;
    }
    if ((func_L01_00504FE0() != 0) || (func_L01_00504F70() != 0) || (func_L01_00504EC0() != 0)) {
        goto end;
    }
    if (((FLD(D_001D52FC, s32, 0x1A4) & 0x10) || (FLD(D_001D52FC, s32, 0x1C4) & 0x10)) && (FLD(D_001A4BE0, u8, 0x121C) != 2) && (D_L09_002D1E30[0] == 0) && (D_00143A06 == 0) && (D_L09_001DF948 >= 8)) {
        if (((FLD(D_001A4BE0, u8, 0x25ED) == 0) || (FLD(D_001A4BE0, u8, 0x25E4) == 1) || (FLD(D_001A4BE0, s16, 0x1D2) != 0))
            && ((FLD(D_001A4BE0, u8, 0x25E8) == 0) || (FLD(D_001A4BE0, u8, 0x25E4) == 1) || (FLD(D_001A4BE0, s16, 0x1D2) != 0))) {
            switch (FLD(D_001A4BE0, u8, 0x25E4)) {
            case 0:
            case 3:
                if (FLD(D_001A4BE0, s16, 0x2882) != 0) {
                    FLD(D_001A4BE0, s16, 0x287E) = 0x1B;
                } else {
                    FLD(D_001A4BE0, s16, 0x287E) = 0xF;
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
    if (FLD(D_001A4BE0, f32, 0x88) < D_L09_001DFCB0) {
        if ((FLD(D_001A4BE0, f32, 0x33C) > 2.0f) && (FLD(D_001A4BE0, u8, 0x25E4) != 2) && (FLD(D_001A4BE0, u32, 0x25C4) != 0x74)) {
            if (FLD(D_001A4BE0, u8, 0x25E4) == 4) {
                func_L09_005164C0(0x91, 1);
                goto end;
            }
            func_L09_005164C0(0x74, 1);
            goto end;
        }
    }
    if ((FLD(D_001A4BE0, u8, 0x25E4) == 4) && (FLD(D_001A4BE0, f32, 0x88) < FLD(FLD(FLD(D_001A4BE0, void *, 0x25C0), void *, 0x68), f32, 0x3EC))) {
        func_L09_005164C0(0x91, 1);
    }
    switch (FLD(D_001A4BE0, u32, 0x25C4)) {
    case 0x0:
    {
        s32 notcrouch;
        s32 anim;
        u8 *obj;
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && (FLD(D_001A4BE0, s32, 0x14E2) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L09_005164C0(1, 1);
            break;
        }
        func_L01_0050FED0();
        if (FLD(D_001A4BE0, u8, 0x2877) != 0) {
            func_L09_005164C0(0x82, 1);
            break;
        }
        notcrouch = FLD(D_001A4BE0, u8, 0x1474) == 0;
        {
        s32 one = 1;
        FLD(D_001A4BE0, s8, 0x1436) = 0;
        if (FLD(D_001A4BE0, s32, 0x1314) == 2) {
            obj = FLD(D_001A4BE0, u8 *, 0x12F0);
            if ((obj != NULL) && (FLD(obj, u8, 0x60) & 2) && (FLD(obj, u8, 0x43) != one)) {
                func_003C3A10(obj, one, 0, 7);
            }
            obj = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((obj != NULL) && (FLD(obj, u8, 0x60) & 2) && (FLD(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 7);
            }
        }
        }
        if ((FLD(D_L09_002F4D80, f32, 0x258) > 0.6108653f) || (FLD(D_L09_002F4D80, f32, 0x254) > 0.43633235f)) {
            obj = FLD(D_001A4BE0, u8 *, 0x12F0);
            if ((obj != NULL) && (FLD(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 0xC);
            }
            obj = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((obj != NULL) && (FLD(obj, u8, 0x43) != 1)) {
                func_003C3A10(obj, 1, 0, 0xC);
            }
        }
        anim = func_L01_004DFE80(FLD(sp74, u8, 0x43));
        if ((anim == func_L02_004B6308(0)) && notcrouch) {
            if (func_L01_00506888(&sp40) != 0) {
                u8 *rec;
                FLD(D_001A4BE0, s16, 0x208) = 0x78;
                FLD(D_001A4BE0, s32, 0x27BC) = sp40;
                rec = D_L09_002F4B70 + sp40 * 0x70;
                FLD(rec, s32, 0x60) = FLD(rec, f32, 0x5C) * 60.0f;
                if (FLD(rec, s32, 0x44) != 0) {
                    func_L09_005164C0(0x3C, 1);
                } else {
                    func_L01_0050FB40(FLD(rec, s32, 0x48), 0, 12.0f);
                }
            }
        } else if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            s32 keep = 0;
            if ((FLD(D_001A4BE0, u8, 0x25E9) != 0) && (FLD(D_001A4BE0, u8, 0x25EB) != 0) && ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == FLD(D_001A4BE0, s32, 0x2830)) || (FLD(D_001A4BE0, s32, 0xE78) != 0))) {
                keep = 1;
            }
            if (keep == 0) {
                FLD(D_001A4BE0, s8, 0x25E9) = 0;
                if (func_L02_004B6308(0) == 0x51) {
                    func_L01_0050FB40(func_L02_004B6308(0), 0, 18.0f);
                } else {
                    func_L01_0050FB40(func_L02_004B6308(0), 0, -2.0f);
                }
            }
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0xB) {
            u8 *o2 = FLD(D_001A4BE0, u8 *, 0x12F4);
            if ((o2 != NULL) && (FLD(o2, u8, 0x43) == 1) && (func_0038CAD0(D_001A4BE0 + 0x24E8) != 0) && (FLD(D_L09_002F4D80, f32, 0x258) < 0.5585054f) && (FLD(D_L09_002F4D80, f32, 0x254) < 0.3490659f) && (FLD(D_001A4BE0, s32, 0x1314) == 2)) {
                FLD(D_001A4BE0, s32, 0x2870) = func_00382498(0x6E, 0x10E);
                func_L01_0050F368();
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x25E9) != 0) && (FLD(D_001A4BE0, s32, 0xC0C) == 0) && (FLD(D_001A4BE0, u8, 0x25EB) != 0) && (FLD(D_001A4BE0, s16, 0x2874) == 0)) {
            s32 slot = func_L01_004E9238(0);
            if (slot != FLD(D_001A4BE0, s32, 0x2834)) {
                func_L01_004EAA80();
            } else {
                s32 want = FLD(D_L09_002C5E40 + ((u8 *)D_001425C0)[slot] * 0xE0, s32, 0x28);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != want) {
                    if (FLD(D_001A4BE0, s32, 0xE78) != 0) {
                        FLD(D_001A4BE0, s32, 0xE84) = 1;
                    }
                    FLD(D_001A4BE0, s32, 0x2830) = want;
                    func_L01_0050FB40(want, 0, -4.0f);
                }
            }
        }
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, u8, 0x147C) != 0) && (FLD(D_001A4BE0, s16, 0x36C) == 0)) {
            func_L09_005164C0(0x76, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 5) && (FLD(D_001A4BE0, f32, 0x33C) > 0.4f)) {
            if ((FLD(D_001A4BE0, s32, 0x25D0) != 8) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0xF)) {
                func_L09_005164C0(6, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) != 0) {
            break;
        }
        {
            s32 ok = 1;
            if ((FLD(D_001A4BE0, s32, 0x25D0) == 1) || (FLD(D_001A4BE0, s32, 0x25D0) == 0x1D)) {
                if (FLD(D_001A4BE0, s32, 0x1B8) <= 4) {
                    ok = 0;
                }
            }
            if (ok && (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                if (func_L01_00506298((FLD(D_001A4BE0, s16, 0x1EE) != 0) ? 1 : 7, 0) != 0) {
                    break;
                }
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x368) == 1) && (D_L09_001D6740 == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0)) {
            func_L09_005164C0(0x6E, 1);
            break;
        }
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) && (FLD(D_001A4BE0, s32, 0x360) != 0)) {
            if ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x1A) || (FLD(D_001A4BE0, f32, 0xC18) >= 108.0f)) {
                func_L09_005164C0(4, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, s32, 0x5EC) != 0) {
            func_L09_005164C0(0x27, 1);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x1474) != 0) && (FLD(D_001A4BE0, f32, 0x340) > 0.087266475f)) {
            func_L09_005164C0(0x2E, 1);
            break;
        }
        {
            s32 go = 1;
            s32 turned;
            if (((FLD(D_001A4BE0, s32, 0x25D0) == 1) || (FLD(D_001A4BE0, s32, 0x25D0) == 0x1D)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x18) && (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                func_L01_004EE850(0, 1.0f);
                if ((func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_L09_001E2B80, f32, 0x158)) > 1.2217306f) && (func_0038CF00(D_001A4BE0 + 0x80, D_L09_001E2B80 + 0x140) < 2.5f)) {
                    go = 0;
                }
            }
            turned = func_L01_004EDFC8(0.17453295f);
            if (go == 0) {
                break;
            }
            if ((turned != 0) || (FLD(D_001A4BE0, f32, 0x2838) > 0.22f)) {
                s32 side = FLD(D_001A4BE0, u8, 0x147F);
                func_L01_004E11C0(side, 0, 0, 0x1E);
                func_L01_004E11C0(side, 1, 0, 0x1E);
                func_L09_005164C0(2, 1);
            }
        }
        break;
    }
    case 0x3C:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && (FLD(D_001A4BE0, s32, 0x14E2) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L09_005164C0(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) != 0) || ((pad3C = FLD(D_001D52FC, s32, 0x1A0)) & 0x40) || (pad3C & 8)) {
            func_L09_005164C0(0x3D, 1);
            break;
        }
        func_L01_004EEBA8();
        if (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f) {
            func_L09_005164C0(0x3D, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L01_00506820();
            func_L09_005164C0(0, 1);
        }
        break;
    case 0x3D:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 9) {
            break;
        }
        func_L01_00506820();
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            func_L09_005164C0(6, 1);
            break;
        }
        if (func_L01_00506298(7, 0) != 0) {
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L09_005164C0(4, 1);
            break;
        }
        func_L01_004EEBA8();
        if (FLD(D_001A4BE0, f32, 0x1B0) > 0.0f) {
            func_L09_005164C0(2, 1);
            break;
        }
        func_L09_005164C0(0, 1);
        break;
    case 0x39:
    case 0x43:
    case 0x67:
    case 0x7D:
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) || (FLD(D_001A4BE0, u8, 0x25F1) != 0)) {
            if (FLD(D_001A4BE0, s16, 0x21E) != 0) {
                FLD(D_001A4BE0, u8, 0x25F1) = 1;
                FLD(D_001A4BE0, s32, 0xC00) = 0;
                func_0038CB00(D_001A4BE0 + 0x21E);
                return;
            }
            func_L01_004EDE10();
            return;
        }
        break;
    case 0x7C:
        if (FLD(D_001A4BE0, s32, 0x1B8) < 0xDD) {
            break;
        }
        func_L01_004EDE10();
        return;
    case 0x32:
    case 0x34:
    {
        u32 st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 0x32) {
            f32 h;
            FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x1B4) * 15.0f;
            if (FLD(D_001A4BE0, f32, 0xC00) < 0.25f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.25f;
            }
            if (FLD(D_001A4BE0, f32, 0xC00) > 0.75f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
            }
            if ((FLD(D_001A4BE0, u32, 0x25C4) == st) && !(FLD(D_001D52FC, s32, 0x1A0) & 0xC0) && ((h = FLD(D_001A4BE0, f32, 0xC18)) > 9.0f) && (h < 19.0f) && (FLD(D_001A4BE0, s32, 0x25C8) != 1) && (FLD(D_001A4BE0, f32, 0x2838) < 0.1f) && (FLD(D_001A4BE0, f32, 0x1B4) < 0.033333335f)) {
                func_L09_005164C0(0x33, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & 0xA)) {
            if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x32) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x15)) {
                func_L09_005164C0(0x34, 1);
                break;
            }
        } else if (FLD(D_001A4BE0, u32, 0x25C4) == 0x34) {
            if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
                func_L09_005164C0(0x32, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x34) {
            s32 pad = FLD(D_001D52FC, s32, 0x1A0);
            if (!(pad & 0xC0) && (FLD(D_001A4BE0, s32, 0x25C8) != 1) && (FLD(D_001A4BE0, f32, 0x2838) < 0.7f) && !(pad & 0xA)) {
                func_L09_005164C0(0x33, 1);
            }
        }
        break;
    }
    case 0x33:
    {
        s32 pad;
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x3C)) {
            func_L01_0050FB40(0x3C, 0, 11.0f);
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.2f) || ((pad = FLD(D_001D52FC, s32, 0x1A0)) & 0xC0) || ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (pad & 0xA))) {
            if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                func_L09_005164C0(0x32, 1);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                func_L09_005164C0(0x34, 1);
            } else {
                func_L09_005164C0(0x32, 1);
            }
        }
        break;
    }
    case 0x36:
        if ((FLD(D_001A4BE0, s16, 0x1F8) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0xB)) {
            func_L09_005164C0(0x12, 1);
            break;
        }
        FLD(D_001A4BE0, u8, 0x25E8) = 1;
        if ((FLD(D_001A4BE0, s16, 0x1FE) == 0) && (FLD(FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8 *, 0x24), s32, 0x134) != 0)) {
            if ((func_L01_004606E8(0x80, 7, 0, 0) != 0) || ((FLD(D_001A4BE0, s16, 0x2884) == 0) && (func_L01_004606E8(0xA, 7, 0, 0) != 0))) {
                if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                    func_L09_005164C0(0x32, 1);
                } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                    func_L09_005164C0(0x34, 1);
                } else {
                    func_L09_005164C0(0x32, 1);
                }
                break;
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x25EA) != 0) && (FLD(D_001A4BE0, f32, 0x2848) < 0.4f) && (func_L09_005164C0(0, 0) != 0)) {
            func_L01_0050FB40(func_L02_004B6308(0), 0, 18.0f);
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.2f) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0xB)) {
            func_L09_005164C0(0x35, 1);
        }
        break;
    case 0x35:
        if ((FLD(D_001A4BE0, s16, 0x1F8) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0)) {
            func_L09_005164C0(0x12, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x1FE) == 0) && (FLD(FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8 *, 0x24), s32, 0x134) != 0) && (func_L01_004606E8(0x80, 7, 0, 0) != 0)) {
            if (FLD(D_001A4BE0, s16, 0x2884) != 0) {
                func_L09_005164C0(0x32, 1);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & 0xA) {
                func_L09_005164C0(0x34, 1);
            } else {
                func_L09_005164C0(0x32, 1);
            }
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x25EA) != 0) && (FLD(D_001A4BE0, f32, 0x2848) < 0.7f)) {
            func_L09_005164C0(0x70, 0);
            func_L01_0050FB40(0x59, 0, 17.0f);
            FLD(D_001A4BE0, s32, 0xF8) = 0;
            FLD(D_001A4BE0, s32, 0x118) = 0;
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) < 0.1f) && (FLD(D_001A4BE0, f32, 0x1B4) == 0.0f) && (FLD(D_001A4BE0, s32, 0x728) == 0)) {
            func_L09_005164C0(0x36, 1);
        }
        break;
    case 0x73:
        if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
            func_L09_005164C0(0x67, 1);
            func_L01_0050FB40(0x58, 0x28, 18.0f);
        } else if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_005164C0(0x33, 1);
        } else if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x33) {
            func_L09_005164C0(0x33, 0);
        }
        break;
    case 0x1:
    {
        u8 *p;
        s32 ok;
        s32 late;
        s32 anim;
        if ((FLD(D_001A4BE0, u8, 0x25E4) == 0) && ((FLD(D_001A4BE0, u8, 0x25EB) == 0) || (FLD(D_001A4BE0, u8, 0x25E5) != 0))) {
            if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 8.0f);
            } else {
                s32 a = func_L02_004B6308(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != a) {
                    func_L01_0050FB40(a, 0, 8.0f);
                }
            }
        }
        p = FLD(D_001A4BE0, u8 *, 0x1200);
        ok = 1;
        if ((p != NULL) && (func_L01_004EDFA8(p) != 0)) {
            if (FLD(p, u8, 0x20) != 0) {
                ok = 0;
            }
        }
        late = 0;
        if (FLD(D_001A4BE0, u8, 0x25E5) == 0) {
            late = FLD(D_001A4BE0, s32, 0x1B8) >= 0x1F;
        }
        if ((!(FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && ok) || late) {
            if (FLD(D_001A4BE0, u8, 0x25E4) != 0) {
                func_L20_002DC390(0);
            } else if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L09_005164C0(4, 1);
            } else {
                func_L09_005164C0(0, 0);
                anim = func_L02_004B6308(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 8.0f);
                }
            }
        }
        break;
    }
    case 0x2F:
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210)) && (FLD(D_001A4BE0, s16, 0x1EC) == 0)) {
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x36) {
                func_L09_005164C0(0, 0);
            } else {
                func_L09_005164C0(0, 1);
            }
        }
        break;
    case 0x14:
    {
        u8 *rec;
        s32 frames;
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x14) {
            s32 n = (s32)(func_L01_00510478(60.0f, 0.036111113f, -1.0f));
            f32 c00 = FLD(D_001A4BE0, f32, 0xBE0);
            s32 top = 0x1A;
            if (c00 == 0.0f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.33f;
            } else if ((c00 != 0.0f) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (n != 0) && (((f32)top - FLD(D_001A4BE0, f32, 0xC18)) > 1.0f)) {
                func_L01_004E5030((f32)top, (f32)n, 0.5f, -1.0f);
                if ((FLD(D_001A4BE0, f32, 0x33C) < 0.7f) && (FLD(D_001A4BE0, f32, 0xC00) < 0.75f)) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
                }
            } else if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, f32, 0xC18) < (f32)top)) {
                FLD(D_001A4BE0, f32, 0xC00) = 2.0f;
            } else {
                FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
            }
        }
        rec = (u8 *)&D_L09_002F6B10[FLD(D_001A4BE0, s16, 0xBDC)];
        frames = ((s32)(FLD(D_001A4BE0, f32, 0xC18)) - FLD(rec, s32, 0xC)) * 2;
        if ((f32)FLD(rec, s32, 0x14) < FLD(D_001A4BE0, f32, 0xC18)) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                break;
            }
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                    func_L09_005164C0(7, 1);
                    break;
                }
                if (func_L01_00506E30() != 0) {
                    break;
                }
            }
        }
        if ((FLD(D_001A4BE0, s32, 0xC0C) == 0) && ((f32)FLD(rec, s32, 0x18) < FLD(D_001A4BE0, f32, 0xC18))) {
            func_L09_005164C0(0, 0);
        }
        break;
    }
    case 0x13:
    case 0x15:
    {
        u8 *rec = (u8 *)&D_L09_002F6B10[FLD(D_001A4BE0, s16, 0xBDC)];
        s32 frames = ((s32)(FLD(D_001A4BE0, f32, 0xC18)) - FLD(rec, s32, 0xC)) * 2;
        u32 st = FLD(D_001A4BE0, u32, 0x25C4);
        s32 lim;
        f32 h;
        if (st == 0x15) {
            frames = 8;
        }
        if ((f32)FLD(rec, s32, 0x14) < FLD(D_001A4BE0, f32, 0xC18)) {
            if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
                goto tail13;
            }
            if ((st != 0x15) || (FLD(D_001A4BE0, s16, 0x368) != 1)) {
                if (func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) {
                    if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                        func_L09_005164C0(7, 1);
                        break;
                    }
                    if (func_L01_00506E30() != 0) {
                        break;
                    }
                }
            }
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            goto tail13;
        }
        if ((FLD(D_001A4BE0, f32, 0xC18) > 34.0f) && (FLD(D_001A4BE0, f32, 0x2838) > 0.9f)) {
            func_L09_005164C0(2, 0);
            func_L01_0050FB40(3, D_L09_001DBCB0[FLD(D_001A4BE0, s32, 0x25C8)], 13.0f);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC0C) != 0) {
            goto tail13;
        }
        lim = FLD(rec, s32, 0x18);
        h = FLD(D_001A4BE0, f32, 0xC18);
        if ((f32)lim < h) {
            if (FLD(D_001A4BE0, f32, 0x2838) > 0.8f) {
                func_L09_005164C0(2, 1);
                break;
            }
            if ((f32)(lim + 5) < h) {
                func_L09_005164C0(0, 0);
                break;
            }
            if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
                func_L09_005164C0(0, 0);
            }
            break;
        }
    tail13:
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x15) {
            if (FLD(D_001A4BE0, s32, 0x1228) != 0xA) {
                func_L09_005164C0(0, 1);
                break;
            }
            if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x65) && (FLD(D_001A4BE0, s32, 0xC24) < 0x1A)) {
                func_L01_0050FEE8(2);
                FLD(D_001A4BE0, s32, 0xC24) = 0x1A;
            }
        }
        break;
    }
    case 0x77:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_005164C0(0, 1);
        }
        break;
    case 0x2:
    case 0x2E:
    {
        s32 n;
        s32 turned;
        u32 st;
        if ((FLD(D_001A4BE0, u8, 0x3EE) != 0) && ((FLD(sp74, f32, 0x44) > 0.9f) || (FLD(sp74, u8, 0x42) != 0xFF))) {
            FLD(D_001A4BE0, u8, 0x3EE) = 0;
        }
        if ((FLD(D_001A4BE0, u8, 0x147C) != 0) && (FLD(D_001A4BE0, s16, 0x36C) == 0)) {
            func_L09_005164C0(0x76, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 5) && ((FLD(D_001A4BE0, s32, 0x25D4) != 0x12) || (FLD(D_001A4BE0, u8, 0x25EA) == 0)) && (FLD(D_001A4BE0, f32, 0x33C) > 1.35f) && (func_L01_005070E0() == 0)) {
            func_L09_005164C0(6, 1);
            break;
        }
        n = 9;
        if (FLD(D_001A4BE0, s16, 0x1EE) != 0) {
            n = 1;
        }
        if ((func_L01_004606E8(func_003A3BB8(0x40, 0), n, 0, 0) != 0) && ((FLD(D_001A4BE0, s16, 0x36E) < 5) || (FLD(D_001A4BE0, s16, 0x202) != 0))) {
            func_L01_004EE850(0, 1.0f);
            if (func_L01_00506298(n, 1) != 0) {
                break;
            }
            if (FLD(D_001A4BE0, f32, 0x2838) > 0.85f) {
                if (FLD(D_001A4BE0, s16, 0x1434) == 0) {
                    func_L09_005164C0(9, 1);
                } else {
                    func_L09_005164C0(7, 1);
                }
            } else {
                func_L09_005164C0(7, 1);
            }
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x36E) != 0) {
            break;
        }
        if (((FLD(D_001A4BE0, u8, 0x1474) == 0) || ((FLD(D_001A4BE0, f32, 0x174) < 0.033333335f) && (FLD(D_001A4BE0, f32, 0x340) < 0.087266475f))) && (FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && (FLD(D_001A4BE0, s32, 0x14E2) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L09_005164C0(1, 1);
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L09_005164C0(4, 1);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x1474) != 0) && (FLD(D_001A4BE0, u32, 0x25C4) == 0x2E)) {
            f32 speed = func_00282E20(D_001A4BE0 + 0x110);
            s32 anim;
            if ((FLD(D_001A4BE0, f32, 0x2838) < 0.17f) && ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x37) || (((anim = FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43)) == func_L02_004B6308(0)) && (FLD(D_001A4BE0, f32, 0x340) > 0.087266475f))) && (FLD(D_001A4BE0, s32, 0x1CC) >= 9) && (FLD(D_001A4BE0, s32, 0xC0C) == 0)) {
                func_L01_0050FB40(0x66, 0, 14.0f);
            } else if ((FLD(D_001A4BE0, f32, 0x2838) > 0.3f) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != 0x37) && (FLD(D_001A4BE0, s32, 0xC0C) == 0)) {
                func_L01_0050FB40(0x37, 0, 14.0f);
            } else if ((FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x66) && (FLD(D_001A4BE0, s32, 0xC0C) == 0) && (FLD(D_001A4BE0, f32, 0x2838) < 0.17f) && (FLD(D_001A4BE0, f32, 0x340) < 0.087266475f) && (speed < 0.028333336f)) {
                func_L01_0050FB40(func_L02_004B6308(0), 0, 20.0f);
            }
        }
        st = FLD(D_001A4BE0, u32, 0x25C4);
        if ((st == 2) || (st == 0x7B)) {
            if (FLD(D_001A4BE0, u8, 0x1474) != 0) {
                func_L09_005164C0(0x2E, 1);
            }
        } else if (st == 0x2E) {
            if (FLD(D_001A4BE0, u8, 0x1474) == 0) {
                func_L09_005164C0(2, 1);
            }
        }
        st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 2) {
            if (FLD(D_001A4BE0, u8, 0x25EA) != 0) {
                func_L09_005164C0(0x70, 1);
            }
        } else if (st == 0x70) {
            if (FLD(D_001A4BE0, u8, 0x25EA) == 0) {
                func_L09_005164C0(2, 1);
            }
        }
        if (FLD(D_001A4BE0, s32, 0x5EC) != 0) {
            func_L09_005164C0(0x27, 1);
            break;
        }
        turned = func_L01_004EDFC8(0.03490659f);
        st = FLD(D_001A4BE0, u32, 0x25C4);
        if (st == 2) {
            if (((FLD(D_001A4BE0, f32, 0x2838) < 0.17f) || (FLD(D_001A4BE0, s16, 0x1E0) != 0)) && (turned == 0) && ((FLD(D_001A4BE0, s32, 0x3F0) == 0) || (__builtin_fabsf(FLD(D_001A4BE0, f32, 0x1A8)) < 0.017453294f))) {
                s32 anim;
                if (func_L01_00507268() != 0) {
                    break;
                }
                if (func_L09_005164C0(0, 0) == 0) {
                    break;
                }
                func_003C4BB0(D_001A4BE0 + 0x160, 0.025000002f);
                if (FLD(D_001A4BE0, f32, 0x1B4) > 0.025000002f) {
                    FLD(D_001A4BE0, f32, 0x1B4) = 0.025000002f;
                }
                anim = func_L02_004B6308(1);
                if (anim == 0x51) {
                    func_L01_0050FB40(0x51, 0, 15.0f);
                } else {
                    func_L01_0050FB40(anim, 0, -1.0f);
                }
            } else {
                func_L01_005063E8();
            }
        } else if (st == 0x2E) {
            if ((FLD(D_001D52FC, s32, 0x1D4) != 0) && (func_00282E20(D_001A4BE0 + 0xF0) < 0.0008333334f) && (FLD(D_001A4BE0, f32, 0x340) < 0.087266475f) && (func_L09_005164C0(0, 0) != 0)) {
                func_L01_0050FB40(func_L02_004B6308(0), 0, 17.0f);
            }
            if (FLD(sp74, u8, 0x43) == 0x37) {
                FLD(D_001A4BE0, f32, 0xC00) = (1.0f - FLD(D_001A4BE0, f32, 0x420)) * 2.0f;
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.7f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 1.7f;
                }
                if (FLD(D_001A4BE0, f32, 0xC00) < 0.75f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.75f;
                }
            } else if (FLD(sp74, u8, 0x43) == 0x66) {
                FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x170) * 10.0f;
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.1f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 1.1f;
                }
                if (FLD(D_001A4BE0, f32, 0xC00) < 0.3f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.3f;
                }
            }
        } else if (st == 0x70) {
            if ((FLD(D_001D52FC, s32, 0x1D4) != 0) && (func_00282E20(D_001A4BE0 + 0xF0) < 0.05333334f) && (func_L09_005164C0(0, 0) != 0)) {
                func_L01_0050FB40(func_L02_004B6308(0), 0, 17.0f);
            }
            FLD(D_001A4BE0, f32, 0xC00) = FLD(D_001A4BE0, f32, 0x170) * 35.0f;
            if (FLD(D_001A4BE0, f32, 0xC00) < 0.6f) {
                FLD(D_001A4BE0, f32, 0xC00) = 0.6f;
            }
            if (FLD(D_001A4BE0, f32, 0xC00) > 1.05f) {
                FLD(D_001A4BE0, f32, 0xC00) = 1.05f;
            }
        }
        break;
    }
    case 0x7B:
    {
        s32 one = 1;
        s32 flag = 0;
        if (FLD(D_001A4BE0, s16, 0x368) != 0) {
            flag = 1;
        }
        if (!(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x3D) {
                flag = one;
            }
        }
        if (FLD(D_001A4BE0, u8, 0x25E9) != 0) {
            flag = one;
        }
        if (flag != 0) {
            if (FLD(D_001A4BE0, s32, 0x2634) != 0) {
                FLD(D_001A4BE0, s32, 0x2650) = one;
            }
            func_L01_004F4E70(9, 0);
            FLD(D_001A4BE0, s16, 0x1E0) = 0x1E;
            func_L09_005164C0(3, 0);
            func_L01_0050FB40(6, 4, 11.0f);
        } else {
            if (FLD(D_001A4BE0, u8, 0x2A7) != 0) {
                f32 a = func_0038CEA8(D_001A4BE0 + 0x110);
                if (a < func_0038CEA8(D_001A4BE0 + 0xF0) * 0.75f) {
                    func_L09_005164C0(0x77, 1);
                    break;
                }
                if (func_L01_004E63F0(NULL, 1.0f, 1.25f) != 0) {
                    func_L09_005164C0(0x77, 1);
                    break;
                }
            }
            *(s128 *)v30 = 0;
            v30[0] = -0.083333336f;
            func_003C2F58(FLD(D_001A4BE0, s8 *, 0x25C0), 0x16, (s8 *)v10);
            func_003C2F58(FLD(D_001A4BE0, s8 *, 0x25C0), 0x17, (s8 *)v20);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v10, v30, (s32 *)D_L09_001DBB50, 1);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v10, v30, (s32 *)D_L09_001DBB60, 1);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v20, v30, (s32 *)D_L09_001DBB50, 1);
            func_L01_0046E078(FLD(D_001A4BE0, s8 *, 0x25C0), v20, v30, (s32 *)D_L09_001DBB60, 1);
        }
        break;
    }
    case 0x63:
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_005164C0(0x62, 1);
        }
        break;
    case 0x3:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && (FLD(D_001A4BE0, s32, 0x14E2) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L09_005164C0(1, 1);
            break;
        }
        if (FLD(D_001A4BE0, s16, 0x1E0) == 0) {
            if (FLD(D_001D52FC, s32, 0x1A4) & func_003A3BB8(0x40, 0)) {
                func_L09_005164C0(7, 1);
                break;
            }
            if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L09_005164C0(4, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) >= 9) && (FLD(D_001A4BE0, f32, 0x33C) > 0.3f)) {
            func_L09_005164C0(6, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
            func_L09_005164C0(0, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x5EC) != 0) {
            func_L09_005164C0(0x27, 1);
            break;
        }
        if (!(FLD(D_001A4BE0, f32, 0x2838) > 0.2f) || (FLD(D_001A4BE0, s16, 0x1E0) != 0)) {
            break;
        }
        if (func_L02_004B6308(0) != 0x51) {
            if (FLD(D_001A4BE0, f32, 0x1B4) == 0.0f) {
                func_L09_005164C0(0, 0);
                break;
            }
        } else if ((FLD(D_001A4BE0, f32, 0xC18) > 10.0f) && (func_L09_005164C0(0, 0) != 0)) {
            func_L01_0050FB40(func_L02_004B6308(0), 0, 17.0f);
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            func_L09_005164C0(2, 1);
        }
        break;
    case 0x4:
        if ((FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0))) && (FLD(D_001A4BE0, s32, 0x14E2) == 0) && (func_L01_003EB2D8() == 0)) {
            func_L09_005164C0(1, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0xC) && !(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
            func_L09_005164C0(0, 0);
            func_L01_0050FB40(func_L02_004B6308(0), 0, -2.0f);
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x147C) != 0) && (FLD(D_001A4BE0, s16, 0x36C) == 0)) {
            func_L09_005164C0(0x76, 1);
            break;
        }
        if (func_L01_00506E30() != 0) {
            break;
        }
        if ((func_L01_004606E8(0x80, 0xF, 0, 0) != 0) && (FLD(D_001A4BE0, u8, 0x121A) == 0) && (FLD(D_001A4BE0, s32, 0x1228) == 0xA)) {
            func_L09_005164C0(0x15, 1);
        }
        if (FLD(D_001A4BE0, s16, 0x36E) >= 9) {
            if ((FLD(D_001A4BE0, s32, 0x25D0) != 8) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0xF)) {
                func_L09_005164C0(6, 1);
            }
        }
        break;
    case 0x23:
        if (FLD(D_001A4BE0, s32, 0x1228) != 0xD) {
            func_L09_005164C0(0, 1);
        }
        break;
    case 0x24:
    {
        s32 go;
        func_L01_004E5030(10.0f, FLD(D_001A4BE0, f32, 0xA2C), 0.5f, -1.0f);
        if ((FLD(D_001A4BE0, f32, 0xA2C) < 22.0f) && (FLD(D_001A4BE0, f32, 0xA2C) < 30.0f)) {
            func_L01_0050FB40(0xA, 0, 16.0f);
        }
        go = 0;
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210))) {
            if (FLD(D_001A4BE0, f32, 0xA2C) > 25.0f) {
                FLD(D_001A4BE0, s32, 0xA48) = 1;
            }
            go = 1;
        }
        if ((FLD(D_001A4BE0, s32, 0x25C8) == 1) && (FLD(D_001A4BE0, f32, 0xA20) < 0.06666667f)) {
            go = 1;
        }
        if (go != 0) {
            FLD(D_001A4BE0, f32, 0x1B4) = FLD(D_001A4BE0, f32, 0xA20);
            if (FLD(D_001A4BE0, f32, 0x1B4) > 0.116666675f) {
                FLD(D_001A4BE0, f32, 0x1B4) = 0.116666675f;
            }
            if (FLD(D_001A4BE0, f32, 0x33C) < 0.3f) {
                func_L09_005164C0(0, 0);
                func_L01_0050FB40(func_L02_004B6308(0), 0, 30.0f);
                break;
            }
            if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0xA) {
                func_L09_005164C0(6, 0);
            } else {
                func_L09_005164C0(6, 0);
                func_L01_0050FB40(0xA, 0, 17.0f);
            }
            FLD(D_001A4BE0, f32, 0xA04) = 0.011666667f;
            FLD(D_001A4BE0, f32, 0xA00) = 0.008055556f;
            FLD(D_001A4BE0, s32, 0x280C) = 0;
        }
        break;
    }
    case 0x25:
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210))) {
            FLD(D_001A4BE0, f32, 0x1B4) = FLD(D_001A4BE0, f32, 0xA20);
            if (FLD(D_001A4BE0, f32, 0x1B4) > 0.116666675f) {
                FLD(D_001A4BE0, f32, 0x1B4) = 0.116666675f;
            }
            if (FLD(D_001A4BE0, f32, 0x33C) < 0.4f) {
                func_L09_005164C0(0, 1);
            } else {
                func_L09_005164C0(6, 1);
                FLD(D_001A4BE0, s32, 0x280C) = 0;
            }
        }
        break;
    case 0x2B:
        if (!(FLD(D_001D52FC, s32, 0x1A0) & FLD(D_001A4BE0, s32, 0x1210))) {
            s32 t = FLD(D_001A4BE0, s32, 0x1B8);
            if (t >= 0xB) {
                if (t < 0x28) {
                    FLD(D_001A4BE0, s32, 0xA48) = 1;
                }
                func_L09_005164C0(0x2C, 1);
                FLD(D_001A4BE0, f32, 0xA04) = 0.0019444445f;
                FLD(D_001A4BE0, f32, 0xA00) = 0.0075000003f;
            }
        }
        break;
    case 0x17:
        if (FLD(D_001A4BE0, f32, 0xC18) > 13.5f) {
            func_L09_005164C0(0x18, 0);
        }
        break;
    case 0x18:
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) && (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) == 0x20)) {
            func_L01_0050FB40(0x21, 0, 6.0f);
        }
        func_L01_004EE850(0, 1.0f);
        if (func_L02_004BDFD8((s8 *)(D_001A4BE0 + 0x80), (s8 *)(D_001A4BE0 + 0x90), NULL) == 0) {
            func_L09_005164C0(6, 1);
            FLD(D_001A4BE0, s16, 0x1D0) = 0xA;
            break;
        }
        if (((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561947f)) || (FLD(D_001D52FC, s32, 0x1A4) & func_003A3BB8(8, 0))) {
            func_L09_005164C0(6, 1);
            FLD(D_001A4BE0, s8, 0x25F0) = 1;
            FLD(D_001A4BE0, s16, 0x1D0) = 0xA;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 0x11, 0, 0) != 0) {
            func_L09_005164C0(0x1B, 1);
            break;
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.5707965f)) < 0.78539824f) {
                *(s128 *)v10 = *(s128 *)(D_001A4BE0 + 0x80);
                v10[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.5707965f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), 1.5707965f)) * 0.3f;
                if (func_L02_004BDFD8((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L09_005164C0(0x19, 1);
                }
                break;
            }
        }
        if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
            if (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.5707965f)) < 0.78539824f) {
                *(s128 *)v10 = *(s128 *)(D_001A4BE0 + 0x80);
                v10[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.5707965f)) * 0.3f;
                v10[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), -1.5707965f)) * 0.3f;
                if (func_L02_004BDFD8((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) != 0) {
                    func_L09_005164C0(0x1A, 1);
                }
            }
        }
        break;
    case 0x19:
    case 0x1A:
    {
        f32 side;
        *(s128 *)v10 = FLD(D_001A4BE0 + 0x80, s128, 0);
        side = 1.5707965f;
        if (FLD(D_001A4BE0, u32, 0x25C4) == 0x1A) {
            side = -1.5707965f;
        }
        v10[0] += func_0038D098(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        v10[1] += func_0038D0B0(func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) * 0.3f;
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, f32, 0x2838) < 0.5f) || (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), func_0038DAB8(FLD(D_001A4BE0, f32, 0x98), side)) > 0.78539824f) || (func_L02_004BDFD8((s8 *)v10, (s8 *)(D_001A4BE0 + 0x90), NULL) == 0)) {
            if (FLD(D_001A4BE0, s32, 0xC08) & 2) {
                func_L09_005164C0(0x18, 1);
                break;
            }
        }
        if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) > 2.3561947f)) {
            func_L09_005164C0(6, 1);
            FLD(D_001A4BE0, s8, 0x25F0) = 1;
            FLD(D_001A4BE0, s16, 0x1D0) = 0x28;
            break;
        }
        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 9, 0, 0) != 0) {
            func_L09_005164C0(0x1B, 1);
        }
        break;
    }
    case 0x6:
    case 0x2C:
        if ((FLD(D_001A4BE0, s32, 0x25C8) == 0) && ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x12) || (FLD(D_001A4BE0, f32, 0x33C) > 1.75f))) {
            func_L01_0050FB40(0xB, 0, 16.0f);
            FLD(D_001A4BE0, s32, 0x25C8) = 1;
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0x2C) {
                FLD(D_001A4BE0, s32, 0x280C) = 7;
            } else {
                FLD(D_001A4BE0, s32, 0x280C) = 0;
            }
        }
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            func_L01_004E1180();
            if (FLD(D_001A4BE0, f32, 0x118) < -0.15f) {
                FLD(D_001A4BE0, f32, 0x118) = -0.15f;
            }
            if (FLD(D_001A4BE0, f32, 0xF8) < -0.15f) {
                FLD(D_001A4BE0, f32, 0xF8) = -0.15f;
            }
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_005164C0(0x39, 1);
            } else {
                s32 one = 1;
                s32 low = FLD(D_001A4BE0, s32, 0x35C) == 0;
                if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x5A) {
                    if (func_L09_005164C0(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 4, 6.0f);
                    }
                    if (low != 0) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 0x16;
                    }
                    func_L01_00510CA0(0xA, 4, 0, 1, 0.022f, 0.004f);
                } else if (FLD(D_001A4BE0, s32, 0x25C8) == one) {
                    if (func_L09_005164C0(0, 0) != 0) {
                        func_L01_0050FB40(0xC, 9, -1.0f);
                    }
                    func_L01_00511508(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.0f);
                    func_003C4BB0((f32 *)(D_001A4BE0 + 0x160), 0.116666675f);
                    FLD(D_001A4BE0, s16, 0x1E0) = 7;
                    if (FLD(D_001A4BE0, s32, 0x25D0) == 0x2C) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 0xA;
                    }
                    if ((low != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x33)) {
                        FLD(D_001A4BE0, s16, 0x1E0) = 0x12;
                    }
                    func_L01_00510CA0(0xA, 2, 0, 1, 0.019f, 0.002f);
                } else if ((FLD(D_001A4BE0, f32, 0x2838) > 0.5f) && (FLD(D_001A4BE0, s16, 0x1E0) == 0)) {
                    func_L09_005164C0(2, 1);
                    func_L01_00510CA0(7, 2, 0, 1, 0.016f, 0.002f);
                } else if (FLD(D_001A4BE0, f32, 0x174) > 0.050000004f) {
                    if (func_L09_005164C0(3, 0) != 0) {
                        func_L01_0050FB40(6, 0, 12.0f);
                        func_003C4BB0((f32 *)(D_001A4BE0 + 0x160), 0.12833333f);
                    }
                } else {
                    func_L09_005164C0(0, 1);
                    func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                }
            }
        } else if (FLD(D_001A4BE0, s32, 0x2850) > 0) {
            if ((FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && (D_00142CA2 != 0) && (func_L01_004E9238(3) != 4) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (FLD(D_001A4BE0, f32, 0x33C) > 0.6f)) {
                func_L09_005164C0(8, 1);
                break;
            }
            if ((FLD(D_001A4BE0, s16, 0x202) >= 0x15) && (func_L01_00506298((FLD(D_001A4BE0, s16, 0x1EE) != 0) ? 1 : 6, 0) != 0)) {
                break;
            }
            if (FLD(D_001A4BE0, s32, 0x528) != 0) {
                func_L09_005164C0(0x17, 1);
                break;
            }
            if (FLD(D_001A4BE0, s32, 0x5EC) != 0) {
                func_L09_005164C0(0x27, 1);
                break;
            }
        }
        break;
    case 0x82:
    {
        u8 *p = D_001A4BE0 + 0xF0;
        if (func_L01_005114B0((s8 *)p) < 0.0f) {
            p -= 0xF0;
            if (FLD(p, s32, 0x340) != 0) {
                u8 *q = FLD(p, u8 *, 0x33C);
                if ((q == NULL) || (FLD(q, s16, 0xAA) == 0x8E2)) {
                    if (func_L09_005164C0(0, 0) != 0) {
                        FLD(p, s8, 0x24EF) = 0;
                        func_L01_0050FB40(7, 0x17, 9.0f);
                        func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                    }
                }
            }
        }
        if (FLD(D_001A4BE0, f32, 0x560) == 0.0f) {
            if ((D_001A79F0 == 0xD) && (FLD(D_001A4BE0, f32, 0x338) < 69.0f)) {
                func_L09_005164C0(0x74, 1);
            } else {
                func_L09_005164C0(6, 1);
            }
        }
        break;
    }
    case 0x8:
        if ((FLD(D_001A4BE0, s32, 0x1D4) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) < 9)) {
            s32 prev = FLD(D_001A4BE0, s32, 0x25D0);
            s32 ok = 0;
            if ((prev == 7) || (prev == 9) || (prev == 0xE) || (prev == 0x11)) {
                ok = 1;
            }
            if (ok != 0) {
                func_L09_005164C0(0x11, 1);
            }
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x1F) && !(FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && !(FLD(D_001D52FC, s32, 0x1C0) & func_003A3BB8(0x40, 0))) {
            func_L09_005164C0(6, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x528) != 0) {
            func_L09_005164C0(0x17, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s16, 0x36E) != 0) && !(FLD(D_001A4BE0, f32, 0x33C) < 0.4f)) {
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) < 0xA) {
            FLD(D_001A4BE0, s16, 0x1EE) = 0xC - FLD(D_001A4BE0, u16, 0x1B8);
        }
        func_L01_004EE850(0, 1.0f);
        if ((FLD(D_001A4BE0, s32, 0x25D0) == 0x10) && (FLD(D_001A4BE0, s32, 0x1B8) < 4)) {
            if (func_L09_005164C0(3, 0) != 0) {
                func_L01_0050FB40(5, 0, -1.0f);
                FLD(D_001A4BE0, s16, 0x1E0) = 0x22;
            }
            break;
        }
        if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
            func_L09_005164C0(4, 1);
            func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            break;
        }
        if ((D_L09_001DBDC4[0][2] < FLD(D_001A4BE0, f32, 0x1B0)) && (func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.5707964f)) {
            if ((FLD(D_001A4BE0, u8, 0x1474) != 0) || (FLD(D_001A4BE0, u8, 0x25EA) != 0)) {
                func_L09_005164C0(2, 1);
                break;
            }
            func_L09_005164C0(2, 0);
            if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                FLD(D_001A4BE0, s32, 0x25C8) = 1;
                func_L01_0050FB40(4, 2, 8.0f);
                FLD(D_001A4BE0, s8, 0x3EE) = 1;
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (D_L09_001DBDC4[0][2] < FLD(D_001A4BE0, f32, 0x1B0)) {
            if ((FLD(D_001A4BE0, u8, 0x1474) != 0) || (FLD(D_001A4BE0, u8, 0x25EA) != 0)) {
                func_L09_005164C0(2, 1);
                break;
            }
            func_L09_005164C0(2, 0);
            if (FLD(D_001A4BE0, u32, 0x25C4) == 2) {
                FLD(D_001A4BE0, s32, 0x25C8) = 1;
                func_L01_0050FB40(4, D_L09_001DBDF4, 12.0f);
            }
            func_L01_00510CA0(5, 2, 1, 0, 0.016f, 0.002f);
        } else if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            if (func_L09_005164C0(0, 0) != 0) {
                func_L01_0050FB40(func_L02_004B6308(0), 0, -2.0f);
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
            }
        } else if (func_L09_005164C0(0, 0) != 0) {
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
        if (FLD(D_001A4BE0, u8, 0x4FE) != 0) {
            s32 n = func_L01_004FF5D8();
            if ((n > 0) && ((FLD(D_001A4BE0, s32, 0x1B8) < n) || (FLD(D_001A4BE0, u8, 0x46C) != 0)) && (FLD(D_001A4BE0, s32, 0x360) != 0)) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) != 0xB) || (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0)) {
                    s32 go = 1;
                    if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x1B) || (FLD(D_001A4BE0, u8, 0x46C) != 0)) {
                        if (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) == 0) {
                            go = 0;
                        }
                    }
                    if (FLD(D_001A4BE0, u32, 0x25C4) == 0xB) {
                        if (FLD(D_001A4BE0, u8, 0x46C) == 0) {
                            go = 0;
                        }
                    }
                    if ((go != 0) && (func_L01_004606E8(0x1F000, 5, 0, 0) != 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0))) {
                        func_L09_005164C0(0xB, 1);
                        break;
                    }
                }
            }
        }
        if ((FLD(D_001A4BE0, s16, 0x1F2) != 0) && ((FLD(D_001A4BE0, u32, 0x25C4) == 7) || (FLD(D_001A4BE0, u32, 0x25C4) == 9)) && (FLD(D_001A4BE0, s32, 0x1B8) < 0x14)) {
            func_L09_005164C0(0x82, 1);
            break;
        }
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x1B) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x15) && (FLD(D_001A4BE0, f32, 0x298) > 0.7f)) {
            FLD(D_001A4BE0, s8, 0x25F0) = 0;
            FLD(D_001A4BE0, s8, 0x25ED) = 0;
        }
        if ((FLD(D_001A4BE0, s32, 0x1B8) < 7) && (func_L01_004606E8(func_003A3BB8(8, 0), 2, 0, 0) != 0) && ((sa = FLD(D_001A4BE0, u32, 0x25C4)) != 0x10) && (sa != 0xA) && (sa != 0x12) && (sa != 0x38) && (sa != 0x11) && (sa != 0xE) && (sa != 0x66)) {
            if ((func_L01_004E9238(3) == 2) && (D_00142CA2 != 0) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, f32, 0x178) > 0.015000001f)) {
                func_L09_005164C0(0xA, 1);
            } else if ((func_L01_004E9238(3) == 3) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001A4BE0, f32, 0x178) > 0.015000001f) && (FLD(D_001A4BE0, s16, 0x1E4) == 0)) {
                func_L09_005164C0(0x10, 1);
            }
        }
        if (FLD(D_001A4BE0, s32, 0x5EC) != 0) {
            func_L09_005164C0(0x27, 1);
            break;
        }
        {
            if (FLD(D_001A4BE0, s16, 0x4EA) < FLD(D_001A4BE0, s32, 0x1B8)) {
                if (FLD(D_001A4BE0, u8, 0x46C) == 0) {
                    func_L09_005164C0(6, 1);
                    break;
                }
            } else if ((FLD(D_001A4BE0, u8, 0x46C) == 0) && ((FLD(D_001A4BE0, u32, 0x25C4) == 0xA) || (FLD(D_001A4BE0, u32, 0x25C4) == 0x10)) && (FLD(D_001A4BE0, f32, 0x298) < 0.9f) && (FLD(D_001A4BE0, u8, 0x2A7) != 0) && (func_0038CEA8(D_001A4BE0 + 0xF0) > 0.116666675f)) {
                f32 a = func_0038CEA8(D_001A4BE0 + 0x110);
                if ((a < func_0038CEA8(D_001A4BE0 + 0xF0) * 0.5f) && (FLD(D_001A4BE0, s32, 0x528) == 0) && (FLD(D_001A4BE0, f32, 0x33C) < 2.0f)) {
                    func_L09_005164C0(0x77, 1);
                    break;
                }
            }
        }
        near = 0;
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0xE) && (FLD(D_001A4BE0, f32, 0xC18) < 35.0f)) {
            near = 1;
        }
        lo = FLD(D_001A4BE0, s16, 0x47C);
        now = FLD(D_001A4BE0, s32, 0x1B8);
        if (!(lo < now)) {
            break;
        }
        if (now == lo + 1) {
            if (FLD(D_001A4BE0, u8, 0x46D) != 0) {
                f32 left = (f32)(FLD(D_001A4BE0, s32, 0x400) - now);
                if (left > 0.0f) {
                    func_L01_004E5030(FLD(D_001A4BE0, f32, 0x408), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                }
            } else if (FLD(D_001A4BE0, u32, 0x25C4) != 0xE) {
                func_L01_00511748((f32 *)(D_001A4BE0 + 0x80), (f32 *)(D_001A4BE0 + 0xF0), &sp68, FLD(D_001A4BE0, f32, 0x4F0));
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x4E4), (f32)sp68, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
                if (FLD(D_001A4BE0, f32, 0xC00) > 1.5f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 1.5f;
                }
            }
            break;
        }
        if ((FLD(D_001A4BE0, u8, 0x46D) != 0) && (now >= FLD(D_001A4BE0, s32, 0x400)) && (now < FLD(D_001A4BE0, s32, 0x404))) {
            f32 left = (f32)(FLD(D_001A4BE0, s32, 0x410) - FLD(D_001A4BE0, s32, 0x400));
            if (left > 0.0f) {
                func_L01_004E5030(FLD(D_001A4BE0, f32, 0x4E4), left, FLD(D_001A4BE0, f32, 0x4E4), -1.0f);
            }
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x358) == 1) {
            func_L01_004F4E70(0xC, 0);
            func_L01_004E5EB8(3, 0x18, 1);
        }
        {
            u8 c = FLD(D_001A4BE0, u8, 0x46C);
            if (c != 0) {
                FLD(D_001A4BE0, u8, 0x46C) = c + 1;
            } else if ((FLD(D_001A4BE0, s16, 0x36E) == 0) && (FLD(D_001A4BE0, u8, 0x46E) != 0) && (near == 0)) {
                func_L01_004E1180();
                FLD(D_001A4BE0, u8, 0x46C) = 1;
                FLD(D_001A4BE0, s8, 0x285F) = 0;
                if ((FLD(D_001A4BE0, f32, 0x2838) < 0.2f) && (FLD(D_001A4BE0, f32, 0x1B4) > 0.041666668f)) {
                    FLD(D_001A4BE0, f32, 0x1B4) = 0.041666668f;
                }
                func_L01_00510CA0(5, 2, 0, 1, 0.016f, 0.002f);
                if (near == 0) {
                    s32 k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 2;
                    if (FLD(D_001A4BE0, f32, 0xC18) < FLD(D_001A4BE0, f32, 0x49C) - 1.5f) {
                        func_L01_0050FB40(func_L01_004DFE80(FLD(sp74, u8, 0x43)), k, 7.0f);
                    }
                }
            }
        }
        if (FLD(D_001A4BE0, u8, 0x46C) != 0) {
            FLD(D_001A4BE0, f32, 0xC00) = 1.0f;
        } else if (FLD(D_001A4BE0, u8, 0x46E) != 0) {
            s32 cur;
            if ((s32)FLD(sp74, u8, 0x41) < (s32)(FLD(D_001A4BE0, f32, 0x4A0))) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) == 0xE) && (FLD(D_001A4BE0, f32, 0xC18) < 37.0f)) {
                    func_003C4138((f32 *)(D_001A4BE0 + 0xC20), 1.0f, 0.15f);
                } else {
                    FLD(D_001A4BE0, s16, 0x47E) = (s32)(func_L01_00510478(60.0f, FLD(D_001A4BE0, f32, 0x4F0), -1.0f));
                    func_L01_004E5030(FLD(D_001A4BE0, f32, 0x49C), (f32)FLD(D_001A4BE0, s16, 0x47E), FLD(D_001A4BE0, f32, 0x4E4), 0.2f);
                }
                if (near == 0) {
                    s32 k = (s32)(FLD(D_001A4BE0, f32, 0x4A0)) + 2;
                    if (FLD(D_001A4BE0, f32, 0xC00) > 1.8f) {
                        func_L01_0050FB40(func_L01_004DFE80(FLD(sp74, u8, 0x43)), k, (f32)(FLD(D_001A4BE0, s16, 0x47E) + 3));
                    }
                }
                if (FLD(D_001A4BE0, f32, 0xC00) < 0.2f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 0.2f;
                }
                if (FLD(D_001A4BE0, f32, 0xC00) > 2.7f) {
                    FLD(D_001A4BE0, f32, 0xC00) = 2.7f;
                }
            }
            cur = FLD(D_001A4BE0, u32, 0x25C4);
            if ((cur == 9) && ((FLD(D_001A4BE0, f32, 0x49C) - FLD(D_001A4BE0, f32, 0xC18)) > 6.0f) && ((func_L01_004DFE80(FLD(sp74, u8, 0x42)) == 8) || (func_L01_004DFE80(FLD(sp74, u8, 0x42)) == cur)) && (FLD(sp74, u8, 0x42) == FLD(sp74, u8, 0x43)) && (FLD(D_001A4BE0, f32, 0x1B0) < D_L09_001DBDC4[1][1] * 0.0016666668f) && (FLD(D_001A4BE0, f32, 0x174) < 0.041666668f)) {
                f32 rate = 9.0f / FLD(D_001A4BE0, f32, 0xC00);
                s32 at;
                if (rate > 10.0f) {
                    rate = 10.0f;
                }
                at = (s32)(FLD(D_001A4BE0, f32, 0xC18)) + 4;
                func_L01_0050FB40(7, at / 2, rate);
                FLD(D_001A4BE0, s32, 0x25C4) = 7;
            }
            {
                s32 a = (s32)(FLD(D_001A4BE0, f32, 0xC18));
                if (a == (s32)(FLD(D_001A4BE0, f32, 0x49C))) {
                    FLD(D_001A4BE0, s32, 0xC00) = 0;
                }
            }
        }
        if (FLD(D_001A4BE0, u8, 0x46C) != 0) {
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0xA) {
                if (func_L09_005164C0(3, 0) != 0) {
                    func_L01_0050FB40(5, 0, -2.0f);
                    func_0038CE20(D_001A4BE0 + 0x160, D_001A4BE0 + 0x160, 0.8f);
                }
                break;
            }
            if ((FLD(D_001A4BE0, u8, 0x147C) == 0) && (FLD(D_001A4BE0, s16, 0x1E0) == 0) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 8, 0, 0) != 0) && (FLD(D_001A4BE0, s16, 0x36E) < 4)) {
                if (!(FLD(D_001A4BE0, f32, 0x1B0) > D_L09_001DBDC4[0][2])) {
                    func_L09_005164C0(7, 1);
                } else if (!(func_0038DBA0(FLD(D_001A4BE0, f32, 0x1A0), FLD(D_001A4BE0, f32, 0x98)) < 1.0471976f)) {
                    func_L09_005164C0(7, 1);
                } else if (D_L09_001DBDC4[1][1] * 0.014166668f < FLD(D_001A4BE0, f32, 0x174)) {
                    func_L09_005164C0(9, 1);
                } else {
                    func_L09_005164C0(7, 1);
                }
                break;
            }
        }
        if ((FLD(D_001A4BE0, u8, 0x46C) >= 2) && (FLD(D_001A4BE0, u32, 0x25C4) != 0xA)) {
            func_L01_00506BB0();
        } else if ((FLD(D_001A4BE0, u8, 0x46E) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= FLD(D_001A4BE0, s16, 0x4FA)) && (FLD(D_001A4BE0, f32, 0x33C) > FLD(D_001A4BE0, f32, 0x4E0))) {
            func_L09_005164C0(6, 1);
        }
        if ((FLD(D_001A4BE0, u32, 0x25C4) == 0x10) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x3D) && (FLD(D_001A4BE0, f32, 0x33C) > 1.5f)) {
            func_L09_005164C0(6, 1);
            break;
        }
        {
            u32 s = FLD(D_001A4BE0, u32, 0x25C4);
            s32 ok = 0;
            if ((s == 7) || (s == 9) || (s == 0x11)) {
                ok = 1;
            }
            if ((FLD(D_001A4BE0, s32, 0x1D4) != 0) && (FLD(D_001A4BE0, u8, 0x46C) == 0) && (ok != 0) && ((FLD(D_001A4BE0, u32, 0x25C4) != 0x11) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0x1A)) && (func_L01_004606E8(func_003A3BB8(0x40, 0), 7, 0, 0) != 0) && (sp6C < FLD(D_001A4BE0, s32, 0x1B8))) {
                func_L09_005164C0(0x11, 1);
                break;
            }
        }
        if (((FLD(D_001A4BE0, u32, 0x25C4) == 0xA) || (FLD(D_001A4BE0, u32, 0x25C4) == 0x10)) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0x1A) && (FLD(D_001A4BE0, s16, 0x36A) != 0)) {
            FLD(D_001A4BE0, s16, 0x4F6) = 0x14;
        }
        sc = FLD(D_001A4BE0, u32, 0x25C4);
        lim = 0x14;
        if (sc == 0x10) {
            lim = 8;
        }
        if ((sc == 0xE) && (FLD(D_001A4BE0, f32, 0x33C) > 4.0f)) {
            if ((FLD(D_001A4BE0, u8, 0x46E) == 0) && (FLD(D_001A4BE0, f32, 0xC00) < 1.3f)) {
                func_003C4138((f32 *)(D_001A4BE0 + 0xC20), 1.3f, 0.1f);
            }
            lim = 0x11;
            FLD(D_001A4BE0, s16, 0x4F6) = lim;
        }
        frames = FLD(D_001A4BE0, s32, 0x1B8) - 4;
        if (frames <= 1) {
            frames = 2;
        }
        if (frames >= 0x1F) {
            frames = 0x1E;
        }
        if (!(FLD(D_001A4BE0, long, 0x468) & 0xFF0000FF00000000L)) {
            if ((func_L01_004606E8(func_003A3BB8(0x40, 0), frames, 0, 0) != 0) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xE) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xF) || (FLD(D_001A4BE0, u32, 0x25C4) == 0xD)) {
                if ((FLD(D_001A4BE0, u32, 0x25C4) != 0xE) && (FLD(D_001A4BE0, u8, 0x25E9) == 0) && ((FLD(D_001A4BE0, u8, 0x147C) == 0) || (FLD(D_001A4BE0, f32, 0x33C) >= 0.4f)) && (FLD(D_001A4BE0, u8, 0x4FF) != 0) && (FLD(D_001A4BE0, s32, 0x1B8) >= 0xF) && ((FLD(D_001A4BE0, u8, 0x46E) == 0) || ((FLD(D_001A4BE0, f32, 0x33C) > 0.7f) && (__builtin_fabsf(func_L01_005114B0((s8 *)(D_001A4BE0 + 0xF0))) < 0.09666667f)))) {
                    func_L09_005164C0(0xE, 1);
                } else if ((D_00142CA2 != 0) && (func_L01_004E9238(3) != 4) && (FLD(D_001A4BE0, s16, 0x2884) == 0) && (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(0x40, 0)) && (lim < FLD(D_001A4BE0, s32, 0x1B8)) && (FLD(D_001A4BE0, s16, 0x4F6) < FLD(D_001A4BE0, s32, 0x1B8))) {
                    f32 need = 0.6f;
                    if ((FLD(D_001A4BE0, u32, 0x25C4) == 9) || (FLD(D_001A4BE0, u32, 0x25C4) == 7)) {
                        need = 1.0f;
                    }
                    if (FLD(D_001A4BE0, u32, 0x25C4) == 0xE) {
                        need = 1.5f;
                    }
                    if (need < FLD(D_001A4BE0, f32, 0x33C)) {
                        func_L09_005164C0(8, 1);
                    }
                }
            }
        }
        if ((FLD(D_001A4BE0, s32, 0x528) != 0) && (FLD(D_001A4BE0, u32, 0x25C4) != 0xB)) {
            func_L09_005164C0(0x17, 1);
        }
        break;
    }
    case 0x16:
        if ((FLD(D_001A4BE0, f32, 0xC18) > 12.5f) && (FLD(D_001A4BE0, u8, 0x2877) == 0) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 1.0f)) {
            func_L09_005164C0(6, 1);
            break;
        }
        if (FLD(D_001A4BE0, s32, 0x1B8) >= 0x1C) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                if (FLD(D_001A4BE0, u8, 0x1477) != 0) {
                    func_L09_005164C0(0x79, 1);
                } else {
                    func_L09_005164C0(0x39, 1);
                }
            } else if (FLD(D_001A4BE0, u8, 0x2877) != 0) {
                func_L09_005164C0(0x82, 1);
            } else {
                func_L09_005164C0(0, 0);
            }
        }
        break;
    case 0x8F:
        if (FLD(D_001A4BE0, s16, 0x36E) == 0) {
            if (FLD(D_001A4BE0, f32, 0x118) < -0.15f) {
                FLD(D_001A4BE0, f32, 0x118) = -0.15f;
            }
            if (FLD(D_001A4BE0, f32, 0xF8) < -0.15f) {
                FLD(D_001A4BE0, f32, 0xF8) = -0.15f;
            }
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_005164C0(0x91, 1);
            } else if (FLD(D_001A4BE0, f32, 0x2838) > 0.5f) {
                if (FLD(D_001A4BE0, s16, 0x1E0) == 0) {
                    func_L09_005164C0(0x8E, 1);
                } else {
                    func_L09_005164C0(0x8D, 1);
                }
            } else {
                func_L09_005164C0(0x8D, 1);
            }
        }
        break;
    case 0x90:
        if ((FLD(D_001A4BE0, s32, 0x1B8) >= 0x20) && (FLD(D_001A4BE0, s16, 0x36E) != 0) && (FLD(D_001A4BE0, f32, 0x33C) > 1.0f)) {
            func_L09_005164C0(0x8F, 1);
            break;
        }
        if ((FLD(D_001A4BE0, s32, 0xC08) & 2) || (FLD(D_001A4BE0, s32, 0x1B8) >= 0x24)) {
            if (FLD(D_001A4BE0, s32, 0x2850) <= 0) {
                func_L09_005164C0(0x91, 1);
            } else {
                func_L09_005164C0(0x8D, 0);
            }
        }
        break;
    case 0x1D:
        if ((FLD(D_001A4BE0, u8, 0x25E4) == 0) && ((FLD(D_001A4BE0, u8, 0x25EB) == 0) || (FLD(D_001A4BE0, u8, 0x25E5) != 0))) {
            if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                func_L01_0050FB40(0xD, 0, 8.0f);
            } else {
                func_L01_0050FB40(func_L02_004B6308(1), 0, 8.0f);
            }
        }
        if (!(FLD(D_001D52FC, s32, 0x1A0) & func_L01_00512DF8(func_003A3BB8(4, 0)))) {
            if (FLD(D_001A4BE0, u32, 0x25C4) == 0x1D) {
                s32 anim;
                func_L09_005164C0(0, 0);
                anim = func_L02_004B6308(1);
                if (FLD(FLD(D_001A4BE0, u8 *, 0x25C0), u8, 0x43) != anim) {
                    func_L01_0050FB40(anim, 0, 8.0f);
                }
            }
            D_001D60F8 = 0;
        }
        break;
    case 0x22:
        if (FLD(D_001A4BE0, f32, 0xC18) > 19.0f) {
            if (func_L01_004606E8(func_003A3BB8(0x40, 0), 0xB, 0, 0) != 0) {
                if (FLD(D_001D52FC, s32, 0x1A0) & func_003A3BB8(8, 0)) {
                    func_L01_00506E30();
                    break;
                }
                func_L09_005164C0(7, 1);
                break;
            }
        }
        if (FLD(D_001A4BE0, f32, 0xC18) >= 21.0f) {
            func_L09_005164C0(0, 0);
        }
        break;
    default:
        break;
    }
end:
    if (sp78 != FLD(D_001A4BE0, s32, 0x25CC)) {
        func_L01_004E1560();
    }
    temp_a0_31 = FLD(D_001A4BE0, s32, 0x25D0);
    if (((temp_a0_31 == 0x3C) && (FLD(D_001A4BE0, s32, 0x25C4) != 0x3D)) || ((temp_a0_31 == 0x3D) && (FLD(D_001A4BE0, s32, 0x1836) != 0))) {
        func_L01_00506820();
    }
    if (sp7C != FLD(D_001A4BE0, s32, 0x25C8)) {
        FLD(D_001A4BE0, s32, 0x1C0) = 0;
    }
    if (sp80 != FLD(sp74, u8, 0x43)) {
        FLD(D_001A4BE0, s32, 0x1C4) = 0;
    }
}
