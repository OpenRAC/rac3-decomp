/* func_L01_003C8E98: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 6036 bytes, places: 9 levels (01, 04, 06, 09, 12, 18, 20, 26, 29), file: src/levels/shared/L01_003C8DE8.c (@ps2as)
   flags: the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); retail has 107 mtc1 (inline float constants) and 6 lq/sq:
     ps2as already set.
   Step 0: one function; 1 jump table (jtbl_002BF0B0), state switch on moby+0x20 (29 cases: `if (state < 0x1D) switch (state)`). a walker-enemy moby update shared by 9 levels (func_L01_00335F38 x27, func_L01_003CABE8 x24, L01_004561B8 x24, anim_frame_reached x10, atan2, walker_set_params x6).
   rac2 twin: none: best opcode 0.215 (func_L01_003B5878); rac3 sibling candidates func_L04_003CD2C0 0.16/0.22 and func_L08_00399978 0.15/0.37 (read first: L08_00399978 is a 0.37 opcode relative, worth an align.py pass).
   Mapping / identical / changed: no twin to map. Hot callees have names in config/names.tsv (moby_set_state, moby_anim_blend,
     vec_set_length, angle_add/sub, atan2, rand_*), so the m2c is readable as moby-AI code.
   VU0 note: 8 COP2 instructions: with the 2026-11-06 rule (no VU0 inline asm in matched C) this cannot be a MATCH unless a
     TI-mode/scalar-C form produces them; keep as a near miss.
   Draft: no compiling draft (m2c converted (600 lines). Compiles after dropping conflicting prototypes except for one VU0 sequence (`lqc2/vadd.xyz/sqc2`-style, M2C_ERROR) next to func_0038CE20(&sp90, &spD0, 0.2f) and float arguments printed as hex words (func_L01_0045BD78(arg0, 0x3B378035, ...) etc. are f32 params: write 0.0027f ...).). The fenced block is the mechanically converted m2c (M2C_FIELD ->
     byte-offset casts, M2C_UNK -> s32, s128 -> u128_t TI typedef). Not measured.
   Left for Opus: (1) type the object (moby: pos +0x10, state +0x20 u8, class ptr +0x24, flags +0x34 u16; the +0x68 pointer is the
     per-moby vars block); (2) turn float-hex arguments back into f32; (3) get it to compile, measure, then register/scheduling work.
   Tool note: tools in out/tools-w6/ (m2c2.py: restores the `.word`-hidden lq/sq and appends the jump tables so m2c runs at all;
     conv.py: M2C_FIELD -> casts; iter.py: compile loop dropping conflicting prototypes).
*/
#if 0 /* does not compile yet: m2c2 draft mechanically converted (tools in worker w6 scratch), prototypes unverified */
typedef int u128_t __attribute__((mode(TI)));
s32 func_00382498(s32, s32);                /* extern */
f32 func_003824E0(s32, s32);                /* extern */
s32 func_0038CE20(s32 *, s32 *, s32 *, s32); /* extern */
s32 func_0038CF68(s32 *, s32 *, s32); /* extern */
f32 func_0038D098(f32);                             /* extern */
f32 func_0038D0B0(f32);                             /* extern */
f32 func_0038D160(f32, f32);                        /* extern */
f32 func_0038DB00(f32, f32);                        /* extern */
f32 func_0038DBA0(f32, f32);                        /* extern */
s32 func_003A52A0(s32, s32, void *);    /* extern */
s32 func_003C2EC0(void *, s32, s32 *);  /* extern */
s32 func_003C2F58(void *, s32, s32 *);  /* extern */
s32 func_003C3A10(void *, u8, u8, s32);         /* extern */
s32 func_13D3E0();                                  /* extern */
s32 func_L01_003303B8(s32 *, s32, s32, s32, s32, u32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_00335F38(void *, s32);         /* extern */
s32 func_L01_003362B0(void *, s32);         /* extern */
s32 func_L01_00362610(s32 *, s32 *, s32, s32, s32); /* extern */
s32 func_L01_003CAA80();                        /* extern */
s32 func_L01_003CABE8(void *, s32, s32, s32, f32); /* extern */
s32 func_L01_003CAC78(void *);                  /* extern */
s32 func_L01_003CBB40(void *, void *);          /* extern */
s32 func_L01_003CC808(void *, void *);          /* extern */
s32 func_L01_00404A10(s32 *, void *);       /* extern */
f32 func_L01_004395E0(void *);                      /* extern */
f32 func_L01_00443A18(s32, s32);            /* extern */
f32 func_L01_00447878(s32 *, void *, s32, s32, s32); /* extern */
s32 func_L01_00448890(void *, void *, s32, f32, f32, f32, f32); /* extern */
u8 func_L01_0044E1B8(void *, s32);              /* extern */
s32 func_L01_00451FE0(void *, s32, s32 *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L01_00454370(void *, void *);              /* extern */
s32 func_L01_004561B8(void *);                      /* extern */
s32 func_L01_0045A9F0(void *);                  /* extern */
s32 func_L01_0045BD78(void *, s32, s32, s32, s32); /* extern */
s32 func_L01_0045C2A0(void *, s32, s32, s32); /* extern */
s32 func_L01_004AA760(s32, void *);         /* extern */
s32 func_L01_004AA7E8(void *, s32);         /* extern */
s32 func_L01_004BA800();                            /* extern */
extern s32 D_L01_001D6694;
extern s32 D_001D545C;
extern s32 D_L01_001D66B0;
extern s32 D_L01_001DFB40;
extern s32 func_L01_003CBEF0;

void func_L01_003C8E98(void *arg0) {
    s32 sp90;
    f32 sp98;
    s32 spA0;
    s32 spB0;
    s32 spC0;
    s32 spD0;
    s32 *temp_6;
    s32 var_5;
    s32 var_f12;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f20;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f1;
    f32 var_f1_2;
    s32 temp_16;
    s32 temp_2_2;
    s32 var_17;
    s32 var_21;
    s32 var_2;
    u16 temp_3_3;
    u8 temp_3_2;
    u8 var_2_2;
    void *temp_17;
    void *temp_17_2;
    void *temp_19;
    void *temp_20;
    void *temp_2;
    void *temp_3;
    void *temp_3_4;
    void *temp_4;
    void *temp_4_2;
    void *temp_4_3;
    void *temp_4_4;
    void *temp_4_5;
    void *temp_4_6;
    void *temp_4_7;
    void *temp_4_8;
    void *temp_5;

    func_L01_003CAA80();
    temp_19 = (*(void **)((u8 *)(arg0) + 0x68));
    if ((D_L01_001D6694 == 2) && ((*(u8 *)((u8 *)(arg0) + 0x20)) != 3)) {
        (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
        (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x41) & 0xEFFF);
        func_L01_004AA7E8(arg0, 1);
        temp_3 = (*(void **)((u8 *)(temp_19) + 0x550));
        if (temp_3 != ((void *)0)) {
            (*(u16 *)((u8 *)(temp_3) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3) + 0x34)) | 0x41);
            temp_4 = (*(void **)((u8 *)(temp_19) + 0x550));
            (*(u16 *)((u8 *)(temp_4) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4) + 0x34)) & 0xEFFF);
            (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x98)) = 0;
            func_L01_004AA7E8((*(void **)((u8 *)(temp_19) + 0x550)), 1);
            func_L01_004AA760(1, (*(void **)((u8 *)(temp_19) + 0x550)));
        }
    } else {
        temp_3_2 = (*(u8 *)((u8 *)(arg0) + 0x20));
        if (func_L01_004BA800() == 0) {
            var_2 = temp_3_2 < 0x1DU;
            if (temp_3_2 != 3) {
                temp_4_2 = (*(void **)((u8 *)(arg0) + 0x24));
                temp_3_3 = (*(u16 *)((u8 *)(arg0) + 0x34)) & 0xFFBE;
                (*(u16 *)((u8 *)(arg0) + 0x34)) = temp_3_3;
                (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (temp_3_3 | ((*(u16 *)((u8 *)(temp_4_2) + 0x44)) & 0x1000));
                (*(s32 *)((u8 *)(arg0) + 0x98)) = (s32) (*(s32 *)((u8 *)(temp_4_2) + 0x10));
                temp_3_4 = (*(void **)((u8 *)(temp_19) + 0x550));
                if (temp_3_4 != ((void *)0)) {
                    (*(u16 *)((u8 *)(temp_3_4) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_3_4) + 0x34)) & 0xFFBE);
                    temp_4_3 = (*(void **)((u8 *)(temp_19) + 0x550));
                    (*(u16 *)((u8 *)(temp_4_3) + 0x34)) = (u16) ((*(u16 *)((u8 *)(temp_4_3) + 0x34)) | ((*(u16 *)((u8 *)((*(void **)((u8 *)(temp_4_3) + 0x24))) + 0x44)) & 0x1000));
                    temp_5 = (*(void **)((u8 *)(temp_19) + 0x550));
                    (*(s32 *)((u8 *)(temp_5) + 0x98)) = (s32) (*(s32 *)((u8 *)((*(void **)((u8 *)(temp_5) + 0x24))) + 0x10));
                }
                goto block_9;
            }
        } else {
block_9:
            var_2 = (*(u8 *)((u8 *)(arg0) + 0x20)) < 0x1DU;
        }
        if (var_2 != 0) {
            switch ((*(u8 *)((u8 *)(arg0) + 0x20))) {
            case 0:
                (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                (*(u16 *)((u8 *)(arg0) + 0x34)) = (u16) (((*(u16 *)((u8 *)(arg0) + 0x34)) | 0x43) & 0xEFFF);
                func_L01_004AA7E8(arg0, 1);
                var_5 = 1;
block_186:
                func_L01_004450F0(arg0, var_5, -1);
                break;
            case 2:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0, 0, 0, 1.0f);
                }
                break;
            case 3:
                (*(s32 *)((u8 *)(arg0) + 0x98)) = 0;
                break;
            case 4:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), func_003824E0(0x3F400000, 0x3F800000));
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
block_187:
                    if (var_2_2 != 0) {
block_188:
                        func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 1);
                    }
                }
                break;
            case 5:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    if ((*(u8 *)((u8 *)(temp_19) + 0x559)) != 0) {
                        func_L01_003CABE8(arg0, 0, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), func_003824E0(0x3F400000, 0x3F800000));
                    } else {
                        func_L01_003CABE8(arg0, 1, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), func_003824E0(0x3F400000, 0x3F800000));
                    }
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 6:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 5, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 7:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0xA, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 8:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 4, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 9:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_0045BD78(arg0, 0x3B378035, 0x3D4CCCCE, 0x3CA4B5BF, 0x4000ADFD);
                    func_L01_003CABE8(arg0, 6, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                var_f1 = (*(f32 *)((u8 *)(temp_19) + 0x240)) / (*(f32 *)((u8 *)(temp_19) + 0x1B8));
                if (var_f1 < 0.7f) {
                    var_f1 = 0.7f;
                }
                temp_f0 = var_f1 * 1.1f;
                (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x48)) = temp_f0;
                (*(f32 *)((u8 *)(arg0) + 0x48)) = temp_f0;
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 10:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_0045BD78(arg0, 0x3C1D4952, 0x3E19999A, 0x3CA4B5BF, 0x4000ADFD);
                    func_L01_003CABE8(arg0, 7, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                var_f1_2 = (*(f32 *)((u8 *)(temp_19) + 0x240)) / (*(f32 *)((u8 *)(temp_19) + 0x1B8));
                if (var_f1_2 < 0.7f) {
                    var_f1_2 = 0.7f;
                }
                temp_f0_2 = var_f1_2 * 0.9f;
                (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x48)) = temp_f0_2;
                (*(f32 *)((u8 *)(arg0) + 0x48)) = temp_f0_2;
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 11:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_0045BD78(arg0, 0x3C1D4952, 0x3E19999A, 0x3BA4B5BF, 0x3F00ADFD);
                    func_L01_003CABE8(arg0, 6, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                temp_17 = (*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0xB8))) + 0x68));
                if ((*(u8 *)((u8 *)(temp_19) + 0x558)) == 0) {
                    func_L01_0045A9F0(arg0);
                }
                func_L01_00448890(arg0 + 0xF8, temp_17 + 0x74, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x1A4)), (*(f32 *)((u8 *)(temp_19) + 0x1A8)), (*(f32 *)((u8 *)(temp_19) + 0x1AC)));
                temp_f1 = ((*(f32 *)((u8 *)(temp_17) + 0x74)) / (*(f32 *)((u8 *)(temp_19) + 0x1AC))) * 6.0f;
                (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x48)) = temp_f1;
                (*(f32 *)((u8 *)(arg0) + 0x48)) = temp_f1;
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 12:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 2, 1, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x558)) == 0) {
                    func_L01_0045A9F0(arg0);
                }
                if (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x550)), 0) != 0) {
                    func_L01_003CAC78(arg0);
                }
                if ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2) {
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = (f32) (func_L01_00443A18(0, 0x3E800000) + 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 14:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_0045BD78(arg0, 0x3C1D4952, 0x3E19999A, 0x3BA4B5BF, 0x3F00ADFD);
                    (*(f32 *)((u8 *)(temp_19) + 0x478)) = 0.0f;
                    (*(f32 *)((u8 *)(temp_19) + 0x474)) = (f32) (*(f32 *)((u8 *)(arg0) + 0xF8));
                }
                var_17 = 0;
                var_21 = 0;
                func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                temp_20 = (*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0xB8))) + 0x68));
                if ((*(u8 *)((u8 *)(temp_19) + 0x558)) == 0) {
                    func_L01_0045A9F0(arg0);
                }
                (*(f32 *)((u8 *)(temp_19) + 0x478)) = func_0038DB00(func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x474)));
                if (func_0038DBA0(func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x474))) > 1.0471976f) {
                    var_17 = 1;
                }
                if (var_17 == 0) {
                    temp_4_4 = (*(void **)((u8 *)(temp_19) + 0x550));
                    (*(f32 *)((u8 *)(temp_19) + 0x538)) = (f32) (*(f32 *)((u8 *)(temp_19) + 0x478));
                    if (((*(u8 *)((u8 *)(temp_4_4) + 0x43)) != 2) || (func_L01_0044E1B8(temp_4_4, 0x40C00000) != 0)) {
                        var_21 = 1;
                        func_003C3A10((*(void **)((u8 *)(temp_19) + 0x550)), 2U, 0U, (*(s32 *)((u8 *)(temp_19) + 0x47C)));
                    }
                    var_f0 = 0.5f;
                } else {
                    temp_4_5 = (*(void **)((u8 *)(temp_19) + 0x550));
                    (*(f32 *)((u8 *)(temp_19) + 0x538)) = func_0038DB00(func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(arg0) + 0xF8)));
                    if (((*(u8 *)((u8 *)(temp_4_5) + 0x60)) & 2) && ((*(u8 *)((u8 *)(temp_4_5) + 0x43)) != 0)) {
                        func_003C3A10(temp_4_5, 0U, 0U, (*(s32 *)((u8 *)(temp_19) + 0x47C)));
                    }
                    var_f0 = 1.0f;
                }
                (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x48)) = var_f0;
                if (var_17 != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) != 6) {
                        func_003C3A10(arg0, 6U, 0U, (*(s32 *)((u8 *)(temp_19) + 0x47C)));
                    }
                    if (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) > 0.08726646f) {
                        func_L01_00448890(arg0 + 0xF8, temp_20 + 0x74, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x1A4)), (*(f32 *)((u8 *)(temp_19) + 0x1A8)), (*(f32 *)((u8 *)(temp_19) + 0x1AC)));
                    } else {
                        (*(f32 *)((u8 *)(temp_19) + 0x474)) = (f32) (*(f32 *)((u8 *)(arg0) + 0xF8));
                    }
                    var_f0_2 = ((*(f32 *)((u8 *)(temp_20) + 0x74)) / (*(f32 *)((u8 *)(temp_19) + 0x1AC))) * 6.0f;
                } else {
                    if (((*(u8 *)((u8 *)(arg0) + 0x43)) != 2) || (func_L01_0044E1B8(arg0, 0x40C00000) != 0)) {
                        var_21 = 1;
                        func_003C3A10(arg0, 2U, (*(u8 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x41)), (*(s32 *)((u8 *)(temp_19) + 0x47C)));
                    }
                    var_f0_2 = (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x48));
                }
                (*(f32 *)((u8 *)(arg0) + 0x48)) = var_f0_2;
                if ((var_17 == 0) && (func_L01_0044E1B8((*(void **)((u8 *)(temp_19) + 0x550)), 0) != 0)) {
                    func_L01_003CAC78(arg0);
                }
                if (((*(u8 *)((u8 *)(arg0) + 0x43)) != 2) && ((*(u8 *)((u8 *)(arg0) + 0x60)) & 2)) {
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = (f32) (func_L01_00443A18(0, 0x3E800000) + 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    if ((*(u8 *)((u8 *)(arg0) + 0x43)) == 2) {
                        if (var_21 != 0) {
                            goto block_188;
                        }
                    } else {
                        goto block_188;
                    }
                }
                break;
            case 15:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_0045BD78(arg0, 0x3C1D4952, 0x3E19999A, 0x3BA4B5BF, 0x3F00ADFD);
                    func_L01_003CABE8(arg0, 9, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                    temp_6 = temp_19 + 0x230;
                    var_f12 = 0x3E23D70B;
                    if ((*(s32 *)0x1D545C == 1) && ((*(s16 *)((u8 *)((*(void **)((u8 *)(arg0) + 0xB8))) + 0xB2)) == 0x1A)) {
                        var_f12 = 0x3E75C290;
                    }
                    func_0038CE20(temp_6, arg0 + 0xC0, temp_6, var_f12);
                    var_f0_3 = 0.6f;
                    if ((D_001D545C == 1) && ((*(s16 *)((u8 *)((*(void **)((u8 *)(arg0) + 0xB8))) + 0xB2)) == 0x1A)) {
                        var_f0_3 = 0.66f;
                    }
                    (*(f32 *)((u8 *)(temp_19) + 0x238)) = var_f0_3;
                    (*(s32 *)((u8 *)(temp_19) + 0x268)) = -1;
                    (*(u128_t *)((u8 *)(temp_19) + 0x1E0)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x220)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x218)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 0;
                }
                temp_f1_2 = (*(f32 *)((u8 *)(temp_19) + 0x238)) - 0.012f;
                (*(f32 *)((u8 *)(temp_19) + 0x238)) = temp_f1_2;
                (*(f32 *)((u8 *)(temp_19) + 0x230)) = (f32) ((*(f32 *)((u8 *)(temp_19) + 0x230)) * 0.99f);
                (*(f32 *)((u8 *)(temp_19) + 0x234)) = (f32) ((*(f32 *)((u8 *)(temp_19) + 0x234)) * 0.99f);
                if (temp_f1_2 < -0.8000001f) {
                    (*(f32 *)((u8 *)(temp_19) + 0x238)) = -0.8000001f;
                }
                if ((*(f32 *)((u8 *)(arg0) + 0x18)) < (*(f32 *)((u8 *)((*(void **)((u8 *)((*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0xB8))) + 0xB8))) + 0x68))) + 0x88))) {
                    func_L01_004450F0(arg0, 0x1C, -1);
                }
                if (func_L01_0045C2A0(arg0, 0x41200000, 0x41880000, 0x41B00000) != 0) {
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = 1.0f;
                    if ((*(u8 *)((u8 *)(temp_19) + 0x558)) != 0) {
                        var_2_2 = (*(u8 *)((u8 *)(temp_19) + 0x490));
                    } else {
                        func_L01_0045A9F0(arg0);
                        var_2_2 = (*(u8 *)((u8 *)(temp_19) + 0x490));
                    }
                    goto block_187;
                }
                break;
            case 16:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    temp_f1_3 = (*(f32 *)((u8 *)(temp_19) + 0x484)) + func_003824E0(0xBDB2B8C2, 0x3DB2B8C2);
                    (*(f32 *)((u8 *)(temp_19) + 0x484)) = temp_f1_3;
                    (*(f32 *)((u8 *)(temp_19) + 0x230)) = (f32) (func_0038D098(temp_f1_3) * 0.20000002f);
                    temp_f0_3 = func_0038D0B0((*(f32 *)((u8 *)(temp_19) + 0x484))) * 0.20000002f;
                    (*(s32 *)((u8 *)(temp_19) + 0x220)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x218)) = 0;
                    (*(u128_t *)((u8 *)(temp_19) + 0x1E0)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x21C)) = 0;
                    (*(f32 *)((u8 *)(temp_19) + 0x234)) = temp_f0_3;
                    (*(f32 *)((u8 *)(temp_19) + 0x238)) = 0.16000001f;
                    (*(s32 *)((u8 *)(temp_19) + 0x268)) = -1;
                    func_L01_003CABE8(arg0, 0xE, 2, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                func_L01_003CBB40(arg0, temp_19);
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = func_L01_0044E1B8(arg0, 0x41200000);
                    goto block_187;
                }
                break;
            case 17:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0xF, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                func_L01_003CBB40(arg0, temp_19);
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 18:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    (*(s32 *)((u8 *)(temp_19) + 0x554)) = 0;
                    func_L01_003CABE8(arg0, 0x10, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), func_003824E0(0x3F000000, 0x3F19999A));
                }
                func_L01_003CBB40(arg0, temp_19);
                if (func_L01_004395E0(arg0) > 8.0f) {
                    func_L01_00404A10(&func_L01_003CBEF0, arg0);
                    (*(s32 *)((u8 *)(temp_19) + 0x554)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x554)) + 1);
                }
                func_L01_003CC808(arg0, temp_19);
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = func_L01_0044E1B8(arg0, 0x41800000);
                    goto block_187;
                }
                break;
            case 19:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0x11, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                func_L01_003CBB40(arg0, temp_19);
                func_L01_00404A10(&func_L01_003CBEF0, arg0);
                func_L01_003CC808(arg0, temp_19);
                break;
            case 20:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    (*(s32 *)((u8 *)(temp_19) + 0x554)) = 0;
                    (*(s32 *)((u8 *)(temp_19) + 0x1C8)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x1C8)) & ~1);
                    func_L01_003CABE8(arg0, 0x12, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x558)) == 0) {
                    func_L01_0045A9F0(arg0);
                }
                func_L01_00404A10(&func_L01_003CBEF0, arg0);
                (*(s32 *)((u8 *)(temp_19) + 0x554)) = (s32) ((*(s32 *)((u8 *)(temp_19) + 0x554)) + 1);
                func_L01_003CC808(arg0, temp_19);
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = func_L01_0044E1B8(arg0, 0x41300000);
                    goto block_187;
                }
                break;
            case 21:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0xB, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = func_L01_0044E1B8(arg0, 0x40E00000);
                    goto block_187;
                }
                break;
            case 22:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0xC, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 23:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    func_L01_003CABE8(arg0, 0xD, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                }
                if ((*(u8 *)((u8 *)(temp_19) + 0x490)) != 0) {
                    var_2_2 = func_L01_0044E1B8(arg0, 0x40E00000);
                    goto block_187;
                }
                break;
            case 24:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    if ((*(u8 *)((u8 *)(arg0) + 0xBC)) != 0) {
                        func_L01_003CABE8(arg0, 3, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                    } else {
                        func_L01_0045BD78(arg0, 0x3C1D4952, 0x3E19999A, 0x3BA4B5BF, 0x3F00ADFD);
                        func_L01_003CABE8(arg0, 6, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                    }
                }
                if ((*(u8 *)((u8 *)(arg0) + 0xBC)) == 0) {
                    temp_17_2 = (*(void **)((u8 *)((*(void **)((u8 *)(arg0) + 0xB8))) + 0x68));
                    if ((*(u8 *)((u8 *)(temp_19) + 0x558)) == 0) {
                        func_L01_0045A9F0(arg0);
                    }
                    func_L01_00448890(arg0 + 0xF8, temp_17_2 + 0x74, 0, func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14))), (*(f32 *)((u8 *)(temp_19) + 0x1A4)), (*(f32 *)((u8 *)(temp_19) + 0x1A8)), (*(f32 *)((u8 *)(temp_19) + 0x1AC)));
                    temp_f1_4 = ((*(f32 *)((u8 *)(temp_17_2) + 0x74)) / (*(f32 *)((u8 *)(temp_19) + 0x1AC))) * 6.0f;
                    (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_19) + 0x550))) + 0x48)) = temp_f1_4;
                    (*(f32 *)((u8 *)(arg0) + 0x48)) = temp_f1_4;
                    if (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xF8)), func_0038D160((*(f32 *)((u8 *)(temp_19) + 0x4A0)) - (*(f32 *)((u8 *)(arg0) + 0x10)), (*(f32 *)((u8 *)(temp_19) + 0x4A4)) - (*(f32 *)((u8 *)(arg0) + 0x14)))) <= 0.034906585f) {
                        (*(u8 *)((u8 *)(arg0) + 0xBC)) = 1U;
                        var_5 = 0x18;
                        goto block_186;
                    }
                } else {
                    if (func_L01_0044E1B8(arg0, 0x41700000) != 0) {
                        func_003C2F58((*(void **)((u8 *)(temp_19) + 0x550)), 1, &spA0);
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x10($s2) */;
                        0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0x4a0($s3) */;
                        0 /* M2C_ERROR unknown instruction: vsub.xyz $vf1, $vf1, $vf2 */;
                        0 /* M2C_ERROR unknown instruction: sqc2 $vf1, 0xb0($sp) */;
                        func_0038CF68(&sp90, &spB0, 0x3EB851EC);
                        sp98 = func_L01_00447878(&spA0, temp_19 + 0x4A0, 0, 0x3EB851EC, 0xBB902DE0);
                        func_L01_00362610(&spA0, &sp90, 0, 0, 1);
                    }
                    var_2_2 = (*(u8 *)((u8 *)(arg0) + 0x60)) & 2;
                    goto block_187;
                }
                break;
            case 25:
                temp_4_6 = (*(void **)((u8 *)(arg0) + 0xB8));
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38(temp_4_6, 0);
                    func_L01_003CABE8(arg0, 0x13, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                    (*(s32 *)((u8 *)(temp_19) + 0x55C)) = (s32) (D_L01_001DFB40 + func_00382498(0xC, 0x19));
                } else {
                    func_L01_00335F38(temp_4_6, 1);
                }
                if ((*(s32 *)((u8 *)(temp_19) + 0x55C)) < D_L01_001DFB40) {
                    func_003C2EC0((*(void **)((u8 *)(temp_19) + 0x550)), 0, &spC0);
                    func_0038CE20(&sp90, &spD0, 0.2f);
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf2, 0x90($sp) */;
                    0 /* M2C_ERROR unknown instruction: lqc2 $vf1, 0xf0($sp) */;
                    0 /* M2C_ERROR unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                    0 /* M2C_ERROR unknown instruction: sqc2 $vf2, 0x90($sp) */;
                    temp_f20 = func_003824E0(0x3E19999A, 0x3E99999A);
                    temp_16 = func_00382498(0, 1);
                    func_L01_003303B8(&sp90, 0, temp_16, 2, 0, (u32) (func_13D3E0() & 2) >> 1, 2, 0, temp_f20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430, 0x7FFFA060, 0x280000FF, 0x3064FF, 0);
                    (*(s32 *)((u8 *)(temp_19) + 0x55C)) = (s32) (D_L01_001DFB40 + func_00382498(5, 0x15));
                }
                break;
            case 26:
                temp_4_7 = (*(void **)((u8 *)(arg0) + 0xB8));
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38(temp_4_7, 0);
                    func_L01_003CABE8(arg0, 0x14, 0, (*(s32 *)((u8 *)(temp_19) + 0x47C)), 1.0f);
                } else {
                    func_L01_00335F38(temp_4_7, 1);
                }
                temp_2 = (*(void **)((u8 *)(arg0) + 0xB8));
                (*(u128_t *)((u8 *)(arg0) + 0x10)) = (u128_t) (*(u128_t *)((u8 *)(temp_2) + 0x10));
                (*(u128_t *)((u8 *)(arg0) + 0xF0)) = (u128_t) (*(u128_t *)((u8 *)(temp_2) + 0xF0));
                break;
            case 27:
                if (func_L01_004561B8(arg0) != 0) {
                    func_L01_00335F38((*(void **)((u8 *)(arg0) + 0xB8)), 0);
                    temp_4_8 = (*(void **)((u8 *)(temp_19) + 0x550));
                    if (temp_4_8 != ((void *)0)) {
                        func_003C3A10(temp_4_8, (*(u8 *)((u8 *)(arg0) + 0x43)), (*(u8 *)((u8 *)(arg0) + 0x41)), (*(s32 *)((u8 *)(temp_19) + 0x47C)));
                    }
                }
                temp_2_2 = func_L01_00454370(arg0, temp_19 + 0xD0);
                if ((temp_2_2 & 1) || (var_2_2 = temp_2_2 & 2, ((*(f32 *)((u8 *)(temp_19) + 0x30)) <= 0.0f))) {
                    var_5 = 0x1C;
                    goto block_186;
                }
                goto block_187;
            case 28:
                func_L01_00451FE0(arg0, 0xF, &D_L01_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0x40400000, 0x40C00000, 0x40400000, 0x40C00000, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0, 3);
                func_L01_00451FE0((*(void **)((u8 *)(temp_19) + 0x550)), 0xF, &D_L01_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0x40400000, 0x40C00000, 0x40400000, 0x40C00000, 0xBF800000, 0xBF800000, 0x3F800000, 0x3F800000, 0, 3);
                func_003A52A0(5, 0, (*(void **)((u8 *)(temp_19) + 0x550)));
                func_L01_003303B8(arg0 + 0x10, 0, 0x19, 0x14, 0x14, 0x14U, 0x2D, 0, 1.0f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
                func_L01_003362B0((*(void **)((u8 *)(arg0) + 0xB8)), 1);
                break;
            }
        }
    }
}


#endif
