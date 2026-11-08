/* func_L03_003AAD60: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 6916 bytes, places: 6 levels, file: src/levels/shared/L03_003AAD60.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as
   Step 0: one function (one prologue addiu sp,-0xD0), 1672 instr, 189 jal (81 distinct), jump table jtbl_002BE270 (20 entries, 20 distinct targets, selector read as an index from a0); 57 $gp operations.
   rac2 twin: none. part3 best func_L02_003C26F0 at 0.19; 4 callees map to rac2 twins, no rac2 function shares 3. It is the Starship Phoenix (L03) enemy/object update: local L03_00348C18 x14, L03_003AD8C8 x7, L03_003AD580 x7, L03_003ADE98 x5, L03_003AE5F0 x5, L03_003AD740 x4, moby_point_position x6, moby_remove x6, moby_set_state x6, vec_rotate_by_matrix x4. Globals: D_1A4BE0 x10, D_1BBE90 x9, D_L03_001DF2D0 x8, D_L03_001E24C0 x7, D_L03_001DF364/365/370/374 x6 each (gp-addressed small variables).
   Mapping: n/a.
   Identical / changed / added / removed: not applicable (no twin).
   Draft: raw m2c with jump table (951 lines, embedded below), after adding my jtbl labels: it runs, and with `sp*` stack slots declared it compiles up to prototype conflicts with the file context (too few arguments to fe_func_003C2880, fe_func_0038D000 types): the file context already declares func_003C2880 as 1-argument and func_0038D000 with typed pointer arguments, so drop those m2c externs and fix the call sites. Not measured.
   Left for Opus: generate the m2c again with the kit extension in out/w8-m2cj.py (jump table + label injection; the lead may want it in the kit: `python3 m2cj.py FUNC`), delete externs the context already has, fix 4-5 argument counts, then the 20-case dispatch is straightforward.
*/
/* raw m2c output (with the jump-table kit extension), does not compile as is */
#if 0
s32 func_00382468(M2C_UNK);                         /* extern * /
s32 func_00382498(u8, u8, u8);                      /* extern * /
M2C_UNK func_00382810(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern * /
f32 func_0038CF00(f32 *, f32 *);                    /* extern * /
f32 func_0038CF38(f32 *, f32 *);                    /* extern * /
M2C_UNK func_0038CF68(f32 *, f32 *, f32);           /* extern * /
M2C_UNK func_0038D000(f32 *, f32 *, M2C_UNK *);     /* extern * /
f32 func_0038D160(f32, f32);                        /* extern * /
f32 func_0038DAB8(f32, M2C_UNK);                    /* extern * /
f32 func_0038DBA0(f32, f32);                        /* extern * /
M2C_UNK func_0039AA38(s32);                         /* extern * /
s32 func_0039AC08(s32, s32);                        /* extern * /
s32 func_003A0EC0(M2C_UNK, M2C_UNK, void *, M2C_UNK, M2C_UNK); /* extern * /
M2C_UNK func_003A0F98(M2C_UNK, M2C_UNK);            /* extern * /
M2C_UNK func_003A4F28(s32, s32);                    /* extern * /
M2C_UNK func_003A52A0(M2C_UNK, M2C_UNK, void *);    /* extern * /
M2C_UNK func_003C2880(void *, f32);                 /* extern * /
M2C_UNK func_003C2F58(void *, M2C_UNK, f32 *);      /* extern * /
M2C_UNK func_003C4138(void *, M2C_UNK, f32);        /* extern * /
M2C_UNK func_003C4BB0(void *, M2C_UNK);             /* extern * /
s32 func_003D3CB0(f32 *, f32 *, M2C_UNK, void *, M2C_UNK); /* extern * /
M2C_UNK func_13C1A0(M2C_UNK);                       /* extern * /
M2C_UNK func_13C1D0(M2C_UNK);                       /* extern * /
M2C_UNK func_13D3D0(s32, s32, s32);                 /* extern * /
M2C_UNK func_L01_003EB350(M2C_UNK, f32 *);          /* extern * /
M2C_UNK func_L01_003EB3C0(M2C_UNK, f32 *);          /* extern * /
M2C_UNK func_L01_003EB438(M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern * /
M2C_UNK func_L01_003EB5E0(M2C_UNK, M2C_UNK);        /* extern * /
M2C_UNK func_L01_003F1740(void *);                  /* extern * /
M2C_UNK func_L01_00404808(M2C_UNK *, void *);       /* extern * /
M2C_UNK func_L01_004048D0(M2C_UNK *, void *);       /* extern * /
s32 func_L01_0041A5B0(M2C_UNK, M2C_UNK);            /* extern * /
M2C_UNK func_L01_0041A6E0(s64);                     /* extern * /
M2C_UNK func_L01_004450F0(void *, M2C_UNK, M2C_UNK); /* extern * /
M2C_UNK func_L01_00448690(void *, M2C_UNK, f32, M2C_UNK); /* extern * /
M2C_UNK func_L01_0044E850(void *, void *, M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern * /
M2C_UNK func_L01_00452560(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern * /
s32 func_L01_004561B8(void *);                      /* extern * /
M2C_UNK func_L01_00456230(void *, M2C_UNK);         /* extern * /
M2C_UNK func_L01_0045F1E8(s32, s32);                /* extern * /
M2C_UNK func_L01_004606A8(void *);                  /* extern * /
M2C_UNK func_L01_00479200(f32 *);                   /* extern * /
M2C_UNK func_L01_00479280();                        /* extern * /
M2C_UNK func_L01_0047B3D8();                        /* extern * /
M2C_UNK func_L01_0047B420();                        /* extern * /
M2C_UNK func_L01_0047B948(void *);                  /* extern * /
M2C_UNK func_L01_0047B990();                        /* extern * /
M2C_UNK func_L01_005003D0(M2C_UNK, M2C_UNK);        /* extern * /
M2C_UNK func_L01_00504E38(M2C_UNK, s32);            /* extern * /
M2C_UNK func_L01_0050FB40(M2C_UNK, M2C_UNK, M2C_UNK); /* extern * /
M2C_UNK func_L01_00511A40(f32 *, M2C_UNK, f32);     /* extern * /
s32 func_L01_00511A98();                            /* extern * /
void *func_L03_00348B88(void *);                    /* extern * /
M2C_UNK func_L03_00348C18(void *, s32 *, M2C_UNK *, M2C_UNK, s32, s32); /* extern * /
void *func_L03_003AC868(void *, f32);               /* extern * /
void *func_L03_003AC998(void *, void *, s32);       /* extern * /
void *func_L03_003ACAD0(void *, void *);            /* extern * /
M2C_UNK func_L03_003ACB68(void *);                  /* extern * /
s32 func_L03_003AD098(void *, M2C_UNK);             /* extern * /
M2C_UNK func_L03_003AD580();                        /* extern * /
M2C_UNK func_L03_003AD740(M2C_UNK, M2C_UNK);        /* extern * /
M2C_UNK func_L03_003AD8C8(void *, s32, void *);     /* extern * /
M2C_UNK func_L03_003AD910(void *, s32, u8, u8, u8); /* extern * /
M2C_UNK func_L03_003ADA98(void *, u16, s32);        /* extern * /
M2C_UNK func_L03_003ADB80(void *);                  /* extern * /
M2C_UNK func_L03_003ADBC8(void *);                  /* extern * /
M2C_UNK func_L03_003ADC00(void *);                  /* extern * /
M2C_UNK func_L03_003ADC48();                        /* extern * /
M2C_UNK func_L03_003ADCD8(void *);                  /* extern * /
M2C_UNK func_L03_003ADDA0(void *);                  /* extern * /
M2C_UNK func_L03_003ADE98(void *, M2C_UNK, M2C_UNK, void *); /* extern * /
M2C_UNK func_L03_003ADF58(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern * /
M2C_UNK func_L03_003AE480(M2C_UNK);                 /* extern * /
M2C_UNK func_L03_003AE4C0(M2C_UNK);                 /* extern * /
M2C_UNK func_L03_003AE5F0(M2C_UNK);                 /* extern * /
M2C_UNK func_L03_003AE810(void *, void *);          /* extern * /
M2C_UNK func_L03_003AE880(void *);                  /* extern * /
M2C_UNK func_L03_003AE9A0(void *);                  /* extern * /
M2C_UNK func_L03_003AEA48(void *);                  /* extern * /
M2C_UNK func_L03_003AEB98(void *);                  /* extern * /
s32 func_L03_0043F5D0(M2C_UNK, M2C_UNK, s32, f32);  /* extern * /
extern M2C_UNK D_1425C0;
extern M2C_UNK D_1A30B0;
extern M2C_UNK D_1A4BE0;
extern f32 D_1A4C60;
extern M2C_UNK D_1A7E18;
extern M2C_UNK D_1BBE90;
extern M2C_UNK D_1CCFD0;
extern M2C_UNK D_L03_001DE630;
extern M2C_UNK D_L03_001DE640;
extern M2C_UNK D_L03_001DE650;
extern M2C_UNK D_L03_001DE668;
extern M2C_UNK D_L03_001DE678;
extern M2C_UNK D_L03_001DE688;
extern M2C_UNK D_L03_001DE698;
extern M2C_UNK D_L03_001DE6A8;
extern M2C_UNK D_L03_001DE6B8;
extern M2C_UNK D_L03_001DE6C8;
extern M2C_UNK D_L03_001DE6D8;
extern M2C_UNK D_L03_001DE6E8;
extern M2C_UNK D_L03_001DE6F8;
extern M2C_UNK D_L03_001DE708;
extern f32 D_L03_001DF2D0;
extern u8 D_L03_001DF364;
extern u8 D_L03_001DF365;
extern u8 D_L03_001DF366;
extern f32 D_L03_001DF370;
extern f32 D_L03_001DF374;
extern s32 D_L03_001DF4C0;
extern M2C_UNK D_L03_001E24C0;
extern f32 D_L03_001E28E4;
extern M2C_UNK D_L03_001E9220;
extern M2C_UNK D_L03_00235A00;
extern M2C_UNK D_L03_002C49C0;
extern M2C_UNK D_L03_002E52F0;
extern M2C_UNK func_L03_003AE8E0;
extern M2C_UNK func_L03_003AEB30;
extern M2C_UNK func_L03_003AEC58;

void func_L03_003AAD60(void *arg0) {
    f32 sp8;
    f32 sp10;
    f32 sp18;
    f32 sp20;
    f32 sp24;
    f32 sp28;
    f32 sp30;
    f32 sp40;
    s32 sp50;
    s32 *sp54;
    s32 *sp58;
    s32 *sp5C;
    s32 *sp60;
    M2C_UNK *var_4_3;
    M2C_UNK var_5_2;
    M2C_UNK var_5_4;
    f32 *temp_2_3;
    f32 temp_f12;
    s16 var_2_3;
    s32 *temp_5_10;
    s32 *temp_5_5;
    s32 *temp_5_6;
    s32 *temp_5_7;
    s32 *temp_5_8;
    s32 *temp_5_9;
    s32 *var_16;
    s32 *var_17;
    s32 *var_20;
    s32 *var_21;
    s32 *var_22;
    s32 *var_23;
    s32 *var_fp;
    s32 temp_2;
    s32 temp_2_10;
    s32 temp_2_11;
    s32 temp_2_13;
    s32 temp_2_18;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_9;
    s32 temp_4_2;
    s32 temp_4_4;
    s32 temp_4_5;
    s32 temp_4_7;
    s32 temp_4_8;
    s32 temp_5;
    s32 temp_5_4;
    s32 temp_6;
    s32 temp_6_2;
    s32 temp_8;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_lo;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_4;
    s32 var_5_3;
    u16 temp_2_12;
    u16 temp_3_10;
    u16 temp_3_6;
    u16 temp_4;
    u16 var_5;
    u8 *var_4_2;
    u8 temp_2_2;
    u8 temp_2_4;
    u8 temp_2_5;
    u8 temp_3;
    u8 temp_3_12;
    u8 temp_3_4;
    u8 temp_3_7;
    u8 temp_3_8;
    u8 temp_5_2;
    u8 temp_6_3;
    u8 var_2;
    u8 var_4;
    void *temp_16;
    void *temp_16_2;
    void *temp_18;
    void *temp_2_14;
    void *temp_2_15;
    void *temp_2_16;
    void *temp_2_17;
    void *temp_2_8;
    void *temp_2_9;
    void *temp_3_11;
    void *temp_3_5;
    void *temp_4_10;
    void *temp_4_3;
    void *temp_4_6;
    void *temp_4_9;
    void *temp_5_3;
    void *temp_7;
    void *var_2_2;
    void *var_3_3;

    temp_3 = M2C_FIELD(arg0, u8 *, 0x20);
    temp_18 = M2C_FIELD(arg0, void **, 0x68);
    switch (temp_3) {
    case 0:
        M2C_FIELD(temp_18, s32 *, 0x48) = 0;
        func_L03_003ADC00(arg0);
        var_5 = M2C_FIELD(arg0, u16 *, 0xB2);
        temp_6 = var_5 << 0x10;
        if (M2C_FIELD((&D_L03_00235A00 + (s16) var_5), u8 *, 0x464) == 0) {
            temp_2 = temp_6 >> 0x11;
            var_5 &= 1;
            temp_2_2 = *(temp_2 + (M2C_FIELD(saved_reg_gp, s32 *, -0x7454) << 0xA) + &D_1BBE90);
            if (var_5 != 0) {
                if (!(((s32) temp_2_2 >> 4) & 7)) {

                } else {
                    goto block_7;
                }
            } else if (temp_2_2 & 7) {
                goto block_7;
            }
        } else {
block_7:
            func_L03_003ADA98(arg0, var_5, temp_6);
        }
        func_L03_003AEB98(arg0);
        sp18 += 1.0f;
        sp8 -= 1.0f;
        if (func_003D3CB0(&sp10, sp, 2, arg0, 0) != 0) {
            M2C_FIELD(arg0, f32 *, 0x18) = (f32) M2C_FIELD(&D_L03_001E9220, f32 *, 8);
        }
        M2C_FIELD(temp_18, s32 *, 0x2C) = 0;
        M2C_FIELD(temp_18, s32 *, 0x18) = -1;
        if (M2C_FIELD(temp_18, s32 *, 0x24) == -1) {
            M2C_FIELD(temp_18, s32 *, 0x24) = func_00382468(0x3E8);
        }
        M2C_FIELD(temp_18, s32 *, 0x834) = 0;
block_201:
        var_5_2 = 1;
block_202:
        func_L01_004450F0(arg0, var_5_2, -1);
        var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
block_214:
        temp_hi = var_3 % 359;
        M2C_FIELD(temp_18, f32 *, 0xD0) = (f32) ((f32) temp_hi * 0.017453292f);
        func_L01_0044E850(arg0, temp_18 + 0x70, 3, temp_hi, 0x3D30F27C, 0x3EDD2F1C);
        if (M2C_FIELD(arg0, u8 *, 0x31) != 0) {
            temp_hi_2 = (s32) M2C_FIELD(saved_reg_gp, s32 *, 0x2C10) % 100;
            M2C_FIELD(arg0, s32 *, 0x78) = func_L03_0043F5D0(0x404040, 0x202020, temp_hi_2, (((f32) temp_hi_2 * 6.2831855f) / (f32) 0x64) - 3.1415927f);
        }
        M2C_FIELD(arg0, u16 *, 0x96) = (u16) (M2C_FIELD(arg0, u16 *, 0x96) + 1);
        return;
    case 1:
        temp_2_3 = &D_1A4C60 - 0x80;
        if ((func_0038CF38(&D_1A4C60, arg0 + 0x10) <= 2.5f) && (func_0038DBA0(M2C_FIELD(arg0, f32 *, 0xF8), func_0038D160(M2C_FIELD(temp_2_3, f32 *, 0x80) - M2C_FIELD(arg0, f32 *, 0x10), M2C_FIELD(temp_2_3, f32 *, 0x84) - M2C_FIELD(arg0, f32 *, 0x14))) < 1.5707964f) && (*(u8 *)0x142CB4 != 0)) {
            temp_4 = M2C_FIELD(arg0, u16 *, 0xB2);
            if (M2C_FIELD((&D_L03_00235A00 + (s16) temp_4), u8 *, 0x464) == 0) {
                temp_4_2 = *(s32 *)0x1D545C;
                temp_2_4 = *(((s32) (temp_4 << 0x10) >> 0x11) + (temp_4_2 << 0xA) + &D_1BBE90);
                if (temp_4 & 1) {
                    var_5_3 = temp_4 << 0x10;
                    if (!(((s32) temp_2_4 >> 4) & 7)) {
                        goto block_30;
                    }
                    goto block_21;
                }
                var_5_3 = temp_4 << 0x10;
                if (temp_2_4 & 7) {
block_21:
                    if (M2C_FIELD((&D_L03_00235A00 + (var_5_3 >> 0x10)), u8 *, 0x464) == 0) {
                        temp_2_5 = *((var_5_3 >> 0x11) + (temp_4_2 << 0xA) + &D_1BBE90);
                        if (temp_4 & 1) {
                            if (!(((s32) temp_2_5 >> 4) & 7)) {
                                var_3_2 = M2C_FIELD(saved_reg_gp, s32 *, -0x7454);
                                goto block_28;
                            }
                            goto block_26;
                        }
                        if (temp_2_5 & 7) {
                            goto block_26;
                        }
                        goto block_27;
                    }
                    goto block_26;
                }
                goto block_30;
            }
block_26:
            if (!(M2C_FIELD(M2C_FIELD(saved_reg_gp, void **, -0x75B4), s32 *, 0x1A0) & 8)) {
block_27:
                var_3_2 = *(void *)0x1D545C;
block_28:
                var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
                if (var_3_2 == 0x18) {
                    var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
                    if (M2C_FIELD(temp_18, s32 *, 0x68) == 1) {
block_30:
                        goto block_31;
                    }
                }
            } else {
block_31:
                func_L01_00452560(0, 0xD, 0x87A, 1, 0, 0, 0);
                if ((*(void *)0x1D545C == 0x18) && (M2C_FIELD(temp_18, s32 *, 0x64) == 1)) {
                    func_L01_004048D0(&func_L03_003AE8E0, arg0);
                }
                temp_4_3 = M2C_FIELD(saved_reg_gp, void **, -0x75B4);
                if (func_0039AC08(M2C_FIELD(((M2C_FIELD(&D_1425C0, u8 *, 0x14) * 0xF0) + &D_L03_002C49C0), s32 *, 0x10)) == 0) {
                    func_0039AA38(M2C_FIELD(((M2C_FIELD(&D_1425C0, u8 *, 0x14) * 0xF0) + &D_L03_002C49C0), s32 *, 0x10));
                    func_L01_0047B948();
                    var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
                } else {
                    temp_3_2 = M2C_FIELD(saved_reg_gp, s32 *, -0x7454);
                    if (M2C_FIELD(temp_4_3, s32 *, 0x1A4) & 0x10) {
                        if (temp_3_2 == 0x18) {
                            M2C_FIELD(temp_18, s32 *, 0x838) = 0;
                        } else if (M2C_FIELD(temp_4_3, s32 *, 0x1A0) & 8) {
                            M2C_FIELD(temp_18, s32 *, 0x838) = 0;
                        } else {
                            M2C_FIELD(temp_18, s32 *, 0x838) = 1;
                        }
                        M2C_FIELD(temp_18, s32 *, 0x4C) = (s32) M2C_FIELD(&D_1A4BE0, s32 *, 0x1228);
                        M2C_FIELD(&D_1A4BE0, s32 *, 0x25F8) = 0x14;
                        func_L01_0047B948(temp_4_3);
                        M2C_FIELD(&D_1A4BE0, s32 *, 0x238) = 0x25;
                        var_5_2 = 0xD;
                        goto block_202;
                    }
                    var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
                    if (temp_3_2 == 0x18) {
                        temp_3_3 = M2C_FIELD(temp_4_3, s32 *, 0x1A0);
                        if ((temp_3_3 & 1) && (temp_3_3 & 2)) {
                            var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
                            if (M2C_FIELD(temp_18, s32 *, 0x64) == 1) {
                                var_5_2 = 0xA;
                                goto block_202;
                            }
                        } else {
                            goto block_213;
                        }
                    }
                }
            }
        } else {
        default:
block_213:
            var_3 = D_L03_001DF4C0;
        }
        goto block_214;
    case 4:
        temp_16 = temp_18 + ((M2C_FIELD(temp_18, s32 *, 0x2C) << 5) + 0x1F0);
        var_3_3 = M2C_FIELD(saved_reg_gp, void **, -0x75B4);
        if (func_L01_004561B8(arg0) != 0) {
            M2C_FIELD(temp_16, s32 *, 8) = (s32) M2C_FIELD(temp_16, s32 *, 0x10);
            M2C_FIELD(temp_16, f32 *, 0xC) = (f32) M2C_FIELD(temp_16, f32 *, 0);
            var_3_3 = *(void **)0x1D52FC;
        }
        if (!(M2C_FIELD(var_3_3, s32 *, 0x1A4) & 0x800)) {
            temp_4_4 = M2C_FIELD(temp_18, s32 *, 0x24);
            temp_5 = M2C_FIELD(temp_18, s32 *, 0x2C);
            temp_2_6 = M2C_FIELD(temp_16, s32 *, 4);
            temp_6_2 = ~temp_2_6;
            temp_4_5 = temp_4_4 + temp_5 + (M2C_FIELD(temp_18, s32 *, 0x54) * temp_4_4);
            func_13D3D0((temp_6_2 != 0) ? (temp_4_5 + temp_2_6) : temp_4_5, temp_5, temp_6_2);
            temp_4_6 = M2C_FIELD(temp_18, void **, 0);
            M2C_FIELD(temp_4_6, u16 *, 0x34) = (u16) (M2C_FIELD(temp_4_6, u16 *, 0x34) & 0xFF7F);
            if (M2C_FIELD(*(void *)0x1D52FC, s32 *, 0x1A4) & 0x10) {
                var_5_2 = 9;
                goto block_202;
            }
            temp_5_2 = M2C_FIELD(temp_16, u8 *, 0x17);
            if (temp_5_2 != 0) {
                temp_4_7 = M2C_FIELD(temp_18, s32 *, 0x54);
                if (temp_5_2 == 1) {
                    if ((temp_4_7 % (s32) M2C_FIELD(temp_16, s32 *, 0x10)) == temp_5_2) {
                        temp_6_3 = M2C_FIELD(temp_16, u8 *, 0x18);
                        temp_lo = temp_4_7 / (s32) M2C_FIELD(temp_16, s32 *, 0x1C);
                        if ((s32) temp_6_3 >= temp_lo) {
                            temp_3_4 = M2C_FIELD(temp_16, u8 *, 0x19);
                            var_4 = (temp_lo < (s32) temp_3_4) ? temp_3_4 : (u8) temp_lo;
                        } else {
                            var_4 = temp_6_3;
                        }
                        func_L03_003AD910(arg0, func_00382498(var_4 - 1, var_4, temp_6_3), M2C_FIELD(temp_16, u8 *, 0x14), M2C_FIELD(temp_16, u8 *, 0x15), M2C_FIELD(temp_16, u8 *, 0x16));
                    }
                } else {
                    goto block_67;
                }
            } else {
block_67:
                if ((M2C_FIELD(temp_18, s32 *, 0x54) % (s32) M2C_FIELD(temp_16, s32 *, 8)) == 1) {
                    func_L03_003AD910(arg0, func_00382498(M2C_FIELD(temp_16, u8 *, 0x19), M2C_FIELD(temp_16, u8 *, 0x18)), M2C_FIELD(temp_16, u8 *, 0x14), M2C_FIELD(temp_16, u8 *, 0x15), M2C_FIELD(temp_16, u8 *, 0x16));
                }
                if (((s32) M2C_FIELD(temp_18, s32 *, 0x54) % (s32) M2C_FIELD(temp_16, s32 *, 0x1C)) == 1) {
                    temp_2_7 = M2C_FIELD(temp_16, s32 *, 8) - 0x14;
                    M2C_FIELD(temp_16, s32 *, 8) = temp_2_7;
                    if (temp_2_7 < 0x3C) {
                        M2C_FIELD(temp_16, s32 *, 8) = 0x3C;
                    }
                }
            }
            if ((M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_18, void **, 0), void **, 0x68), s32 *, 8) == 4) || (func_L03_003AD098(arg0, 4) != 0)) {
                func_L03_003ACB68(arg0);
            }
            func_L03_003AD8C8(M2C_FIELD(temp_18, void **, 0x1C), M2C_FIELD(temp_18, s32 *, 0x2C));
            func_L03_003AD580();
            func_L03_003ADE98(arg0, 0x604040, 0x403030);
            M2C_FIELD(temp_18, s32 *, 0x54) = (s32) (M2C_FIELD(temp_18, s32 *, 0x54) + 1);
            func_L03_003AE9A0(arg0);
            var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
            if (M2C_FIELD(temp_18, s32 *, 0x50) >= (s32) M2C_FIELD(temp_16, u8 *, 0x1A)) {
                var_5_2 = 5;
                goto block_202;
            }
        } else {
            func_L03_003ADCD8(arg0);
            var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        }
        goto block_214;
    case 16:
        if (func_L01_004561B8(arg0) != 0) {
            func_L03_003AE480(0);
            temp_2_8 = func_L03_003AC868(arg0, (f32) (M2C_FIELD(saved_reg_gp, s32 *, 0x1D24) * 2));
            M2C_FIELD(temp_18, void **, 0x38) = temp_2_8;
            M2C_FIELD(temp_18, void **, 0x40) = func_L03_003ACAD0(arg0, temp_2_8);
            M2C_FIELD(temp_18, void **, 0x3C) = func_L03_003AC998(arg0, M2C_FIELD(temp_18, void **, 0x38), M2C_FIELD(temp_18, s32 *, 4));
            M2C_FIELD(temp_18, s32 *, 0x44) = 0x55200000;
            M2C_FIELD(temp_18, s32 *, 4) = 0x20;
            func_L03_003AD740(0, 0x20);
        }
        func_003C2F58(M2C_FIELD(temp_18, void **, 0x38), 0x42, &sp10);
        func_0038CF68(&sp20, M2C_FIELD(temp_18, void **, 0x38) + 0xC0, (f32) M2C_FIELD(saved_reg_gp, s32 *, 0x1D24));
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        temp_f12 = M2C_FIELD(saved_reg_gp, f32 *, 0x1D2C);
        if (func_0038CF00(&sp10, sp) <= 0.5f) {
            func_003C2880(M2C_FIELD(temp_18, void **, 0), temp_f12);
            func_003C2880(M2C_FIELD(temp_18, void **, 0x30));
            func_003C2880(M2C_FIELD(temp_18, void **, 0x1C));
            temp_5_3 = M2C_FIELD(temp_18, void **, 0x3C);
            temp_2_9 = M2C_FIELD(temp_18, void **, 0x38);
            temp_3_5 = M2C_FIELD(temp_18, void **, 0x40);
            M2C_FIELD(temp_18, void **, 0x38) = NULL;
            M2C_FIELD(temp_18, void **, 0x40) = NULL;
            M2C_FIELD(temp_18, void **, 0x3C) = NULL;
            M2C_FIELD(temp_18, s32 *, 0x54) = 0;
            M2C_FIELD(temp_18, s32 *, 0x50) = 0;
            M2C_FIELD(temp_18, void **, 0x1C) = temp_5_3;
            M2C_FIELD(temp_18, void **, 0) = temp_2_9;
            M2C_FIELD(temp_18, void **, 0x30) = temp_3_5;
            func_L03_003AE810(arg0, temp_5_3);
            func_L03_003AE480(1);
            var_5_2 = 4;
            goto block_202;
        }
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf2, $vf2, $vf1 * /);
        func_0038CF68(&sp30, &sp30, temp_f12 * 0.020000001f);
        func_0038CF68(&sp40, &sp30, (M2C_FIELD(saved_reg_gp, f32 *, 0x1D2C) + 2.0f) * 0.020000001f);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        func_L03_003AD8C8(M2C_FIELD(temp_18, void **, 0x1C), M2C_FIELD(temp_18, s32 *, 0x2C) - 1);
        func_L03_003AD8C8(M2C_FIELD(temp_18, void **, 0x3C), M2C_FIELD(temp_18, s32 *, 0x2C));
        func_L03_003AD580();
        var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        goto block_214;
    case 5:
        if (func_L01_004561B8(arg0) != 0) {
            func_003A52A0(8, 0, arg0);
            func_L01_00456230(M2C_FIELD(temp_18, void **, 0x30), 1);
            func_L03_003ADC48();
            M2C_FIELD(temp_18, s32 *, 0x2C) = (s32) (M2C_FIELD(temp_18, s32 *, 0x2C) + 1);
            func_L03_003AE880(arg0);
            if (M2C_FIELD(temp_18, s32 *, 0x2C) < M2C_FIELD(temp_18, s32 *, 0x28)) {
                if (M2C_FIELD(temp_18, s32 *, 0x838) == 1) {
                    M2C_FIELD(temp_18, s32 *, 0x834) = 0;
                }
                var_5_4 = 0x10;
            } else {
                temp_3_6 = M2C_FIELD(arg0, u16 *, 0xB2);
                temp_4_8 = M2C_FIELD(saved_reg_gp, s32 *, -0x7454);
                if (temp_3_6 & 1) {
                    var_4_2 = ((s32) (temp_3_6 << 0x10) >> 0x11) + (temp_4_8 << 0xA) + &D_1BBE90;
                    temp_3_7 = *var_4_2;
                    var_2 = temp_3_7 + 0x10;
                    if (((temp_3_7 >> 4) & 7) != 7) {
                        goto block_90;
                    }
                } else {
                    var_4_2 = ((s32) (temp_3_6 << 0x10) >> 0x11) + (temp_4_8 << 0xA) + &D_1BBE90;
                    temp_3_8 = *var_4_2;
                    var_2 = temp_3_8 + 1;
                    if ((temp_3_8 & 7) != 7) {
block_90:
                        *var_4_2 = var_2;
                    }
                }
                func_L03_003ADA98(arg0, 7U);
                var_5_4 = 6;
            }
            func_L01_004450F0(arg0, var_5_4, -1);
            return;
        }
        if (M2C_FIELD(*(void *)0x1D52FC, s32 *, 0x1A4) & 0x10) {
            var_5_2 = 9;
            goto block_202;
        }
        func_L03_003AD8C8(M2C_FIELD(temp_18, void **, 0x1C), M2C_FIELD(temp_18, s32 *, 0x2C), arg0);
        func_L03_003AD580();
block_104:
        func_L03_003ADE98(arg0, 0x406040, 0x304030);
        var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        goto block_214;
    case 6:
        if (func_L01_004561B8(arg0) != 0) {
            func_L03_003AE480(0);
            func_L03_003AD740(0);
        }
        func_003C2F58(M2C_FIELD(temp_18, void **, 0), 0x40, &sp10);
        if (func_0038CF00(&sp10, sp) <= M2C_ERROR(/* Read from unset register $at * /)) {
            func_L01_004450F0(arg0, 9, -1);
        } else {
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 * /);
            func_0038CF68(&sp20, &sp20, 2.0f * M2C_FIELD(saved_reg_gp, f32 *, 0x1D2C) * 0.020000001f);
            M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
            M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
            M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
            func_L03_003AD580();
        }
        goto block_104;
    case 19:
        if (func_L01_004561B8(arg0) != 0) {
            func_L03_003AEA48(arg0);
        }
        func_003C2F58(M2C_FIELD(temp_18, void **, 0), 0x41, sp);
        func_L01_00404808(&func_L03_003AEB30, arg0);
        var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        goto block_214;
    case 7:
        if (func_L01_004561B8(arg0) != 0) {
            func_003A52A0(9, 0, arg0);
            func_L03_003AE4C0(1);
            var_3_4 = M2C_FIELD(saved_reg_gp, s32 *, -0x7454);
            if (M2C_FIELD(temp_18, s32 *, 0x838) == 1) {
                temp_3_9 = M2C_FIELD(temp_18, s32 *, 0x834) + 0xA;
                M2C_FIELD(temp_18, s32 *, 0x834) = temp_3_9;
                if (temp_3_9 >= 0x33) {
                    M2C_FIELD(temp_18, s32 *, 0x834) = 0x32;
                } else if (temp_3_9 < 0) {
                    M2C_FIELD(temp_18, s32 *, 0x834) = 0;
                }
                var_3_4 = *(void *)0x1D545C;
            }
            var_2_2 = M2C_FIELD(saved_reg_gp, void **, -0x75B4);
            if (var_3_4 == 3) {
                if (M2C_FIELD(saved_reg_gp, s32 *, 0x1D14) >= 3) {
                    func_L01_0041A5B0(0x10A9, 0xE6);
                    M2C_FIELD(saved_reg_gp, M2C_UNK32 *, 0x2A20) = 0x3F000000;
                    func_L03_003AE5F0(1);
                    M2C_FIELD(saved_reg_gp, s32 *, 0x1D14) = 0;
                    goto block_120;
                }
                var_2_2 = M2C_FIELD(saved_reg_gp, void **, -0x75B4);
                if (M2C_FIELD(saved_reg_gp, s32 *, 0x1D10) >= 3) {
                    func_L01_0041A5B0(0x10A8, 0xE5);
                    M2C_FIELD(saved_reg_gp, M2C_UNK32 *, 0x2A20) = 0x3F000000;
                    func_L03_003AE5F0(1);
                    M2C_FIELD(saved_reg_gp, s32 *, 0x1D10) = 0;
                    goto block_120;
                }
            }
        } else {
block_120:
            var_2_2 = *(void *)0x1D52FC;
        }
        temp_2_10 = M2C_FIELD(var_2_2, s32 *, 0x1A4);
        if (temp_2_10 & 0x10) {
            func_L01_0041A6E0();
            var_5_2 = 9;
            goto block_202;
        }
        if (!(temp_2_10 & 0x40)) {
            func_L03_003AD8C8(M2C_FIELD(temp_18, void **, 0x1C), M2C_FIELD(temp_18, s32 *, 0x2C));
            func_L03_003AD580();
            func_L01_00404808(&func_L03_003AEC58, arg0);
            func_L03_003ADE98(arg0, 0x202060, 0x202040);
            var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        } else {
            func_L01_0041A6E0();
            func_L03_003AE5F0(0);
            M2C_FIELD(saved_reg_gp, M2C_UNK32 *, 0x2A20) = 0;
            func_L03_003AD740(0);
            func_L03_003ADB80(arg0);
            temp_16_2 = M2C_FIELD(M2C_FIELD(temp_18, void **, 0), void **, 0x68);
            M2C_FIELD(temp_16_2, s32 *, 8) = func_00382468(2);
            func_L01_004606A8(*(void *)0x1D52FC);
            func_L03_003AE4C0(0);
            var_5_2 = 8;
            goto block_202;
        }
        goto block_214;
    case 8:
        if (func_L03_003AD098(arg0) != 0) {
            func_003C4138(temp_18 + 0x14, 0x3F800000, M2C_FIELD(saved_reg_gp, f32 *, 0x1D50) * 0.020000001f);
            D_L03_001DF2D0 = M2C_FIELD(temp_18, f32 *, 0x14);
            if (M2C_FIELD(temp_18, f32 *, 0x14) >= 1.0f) {
                func_L03_003ADBC8(arg0);
                func_L01_004450F0(arg0, 3, -1);
            }
        }
        func_L03_003AD8C8(M2C_FIELD(temp_18, void **, 0x1C), M2C_FIELD(temp_18, s32 *, 0x2C));
        func_L03_003AD580();
        func_L03_003ADE98(arg0, 0x604040, 0x403030);
        var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        goto block_214;
    case 9:
        func_L03_003ADC00(arg0);
        M2C_FIELD(arg0, s8 *, 0x30) = 0x40;
        D_L03_001DF370 = M2C_FIELD(temp_18, f32 *, 0x58);
        D_L03_001DF374 = M2C_FIELD(temp_18, f32 *, 0x5C);
        D_L03_001DF364 = M2C_FIELD(temp_18, u8 *, 0x60);
        D_L03_001DF365 = M2C_FIELD(temp_18, u8 *, 0x61);
        D_L03_001DF366 = M2C_FIELD(temp_18, u8 *, 0x62);
        M2C_FIELD(temp_18, s32 *, 0x2C) = 0;
        func_L03_003AE880(arg0);
        func_L03_003AD740(1);
        func_L01_00504E38(0);
        func_003C2F58(arg0, 0, &D_1A4C60);
        if (M2C_FIELD(temp_18, s32 *, 0x18) >= 0x34) {
            M2C_FIELD(temp_18, s32 *, 0x18) = -1;
        }
        temp_5_4 = M2C_FIELD(temp_18, s32 *, 0x18);
        if (temp_5_4 != -1) {
            temp_4_9 = (temp_5_4 << 7) + &D_1A30B0;
            if ((M2C_FIELD(temp_4_9, s32 *, 0xDC) == arg0) && (M2C_FIELD(temp_4_9, u8 *, 0xD0) != 0)) {
                func_003A4F28(temp_5_4, temp_5_4);
            }
        }
        M2C_FIELD(temp_18, s32 *, 0x18) = -1;
        func_003C2880(M2C_FIELD(temp_18, void **, 0));
        func_003C2880(M2C_FIELD(temp_18, void **, 0x1C));
        func_003C2880(M2C_FIELD(temp_18, void **, 0x30));
        M2C_FIELD(saved_reg_gp, s32 *, 0x1D14) = 0;
        *(s32 *)0x1A71D8 = M2C_FIELD(temp_18, s32 *, 0x4C);
        M2C_FIELD(saved_reg_gp, s32 *, 0x1D10) = 0;
        func_L01_003F1740(arg0);
        func_L01_0045F1E8(M2C_FIELD(temp_18, s32 *, 0x848), M2C_FIELD(temp_18, s32 *, 0x844));
        func_13C1D0(0x4D);
        var_5_2 = 0xB;
        goto block_202;
    case 11:
        func_003A0F98(0, 0);
        func_L01_0047B420();
        func_L01_0047B990();
        func_L01_00479280();
        goto block_201;
    case 13:
        M2C_FIELD(&D_1A4BE0, s32 *, 0x238) = 0x25;
        if (func_L01_004561B8(arg0) != 0) {
            func_0038D000(sp, saved_reg_gp + 0x1D60, arg0 + 0xC0);
            M2C_ERROR(/* unknown instruction: vadd.xyz $vf2, $vf2, $vf1 * /);
            func_L01_00511A40(sp, 0, func_0038DAB8(M2C_FIELD(arg0, f32 *, 0xF8), 0x40490FDB));
        }
        temp_2_11 = func_L01_00511A98();
        if (temp_2_11 != 2) {
            goto block_152;
        }
        if (M2C_FIELD(M2C_FIELD(&D_1A4BE0, void **, 0x25C0), u8 *, 0x42) != M2C_FIELD(M2C_FIELD(&D_1A4BE0, void **, 0x25C0), u8 *, 0x43)) {
block_152:
            M2C_FIELD(arg0, u16 *, 0x96) = (u16) (M2C_FIELD(arg0, u16 *, 0x96) + 1);
            if (M2C_FIELD(arg0, u16 *, 0x96) >= 0xFBU) {
                func_L01_00504E38(0, temp_2_11);
                var_5_2 = 1;
                M2C_FIELD(&D_1A4BE0, s32 *, 0x25F8) = (s32) M2C_FIELD(temp_18, s32 *, 0x4C);
                goto block_202;
            }
            var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
            if (temp_2_11 == 0) {
                var_5_2 = 1;
                M2C_FIELD(&D_1A4BE0, s32 *, 0x25F8) = (s32) M2C_FIELD(temp_18, s32 *, 0x4C);
                goto block_202;
            }
        } else {
            if (func_0039AC08(M2C_FIELD(((M2C_FIELD(&D_1425C0, u8 *, 0x14) * 0xF0) + &D_L03_002C49C0), s32 *, 0x10), temp_2_11) == 0) {
                func_0039AA38(M2C_FIELD(((M2C_FIELD(&D_1425C0, u8 *, 0x14) * 0xF0) + &D_L03_002C49C0), s32 *, 0x10));
            }
            M2C_FIELD(&D_1A4BE0, s32 *, 0x25F8) = 0x14;
            func_L01_0047B948();
            var_5_2 = 0xE;
            goto block_202;
        }
        goto block_214;
    case 14:
        M2C_FIELD(&D_1A4BE0, s32 *, 0x238) = 0x25;
        if (func_L01_004561B8(arg0) != 0) {
            func_L01_00479200(sp);
            func_L01_0047B948();
            func_L01_0047B3D8();
            func_L01_005003D0(0x74, 1);
            func_L01_0050FB40(0x4B, 0, 0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, %lo(D_L03_001E24C0)($s0) * /);
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 * /);
            func_0038D000(sp, sp, &D_1A4BE0 + 0x40);
            func_L01_003EB438(0, &D_L03_001E24C0, &D_L03_001E24C0, 3, 0x64, 0);
            func_003A52A0(0xC, 0, arg0);
            M2C_FIELD(temp_18, f32 *, 0x14) = 0.0f;
        }
        func_0038D000(sp, saved_reg_gp + 0x1D60, arg0 + 0xC0);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        M2C_ERROR(/* unknown instruction: vsub.xyz $vf1, $vf1, $vf2 * /);
        M2C_FIELD(&D_1A4BE0, s32 *, 0x108) = 0;
        func_003C4BB0(&D_1A4BE0 + 0x100, 0x3C75C290);
        func_L01_00448690(&D_1A4BE0 + 0x98, 0, func_0038DAB8(M2C_FIELD(arg0, f32 *, 0xF8), 0x40490FDB), 0x3CAB92A7);
        M2C_FIELD(&D_1A4BE0, s16 *, 0x222) = 3;
        if (M2C_FIELD(&D_1A4BE0, s32 *, 0xC08) & 2) {
            func_L01_0050FB40(0x4C, 0, 0x40C00000);
        }
        if (M2C_FIELD(&D_1A4BE0, s32 *, 0x25C4) != 0x74) {
            func_L01_003EB5E0(0, 3);
            M2C_FIELD(&D_1A4BE0, s32 *, 0x25F8) = (s32) M2C_FIELD(temp_18, s32 *, 0x4C);
            func_L01_004450F0(arg0, 1, -1);
        }
        func_0038D000(&sp10, saved_reg_gp + 0x1D70, &D_1A4BE0);
        M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
        func_003C2F58(arg0, 1, &sp30);
        sp28 = func_0038D160(sp30 - sp10, sp34 - sp14);
        sp24 = -func_0038D160(func_0038CF38(&sp10, &sp30), sp38 - sp18);
        func_L01_003EB350(0, &sp10);
        func_L01_003EB3C0(0, &sp20);
        temp_2_12 = M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(arg0, u16 *, 0x96) = (u16) (temp_2_12 + 1);
        if (temp_2_12 >= 0x33U) {
            var_5_2 = 0xF;
            goto block_202;
        }
        goto block_213;
        goto block_214;
    case 15:
        M2C_FIELD(&D_1A4BE0, s32 *, 0x238) = 0x25;
        func_003C2F58(arg0, 0, sp);
        if (M2C_FIELD(&D_1A4BE0, s32 *, 0xC08) & 2) {
            func_L01_0050FB40(0x4C, 0, 0);
        }
        if (func_L01_004561B8(arg0) != 0) {
            D_L03_001E28E4 = 0.017453292f;
            func_00382810(0, 0x21, 1, 0x3C8EFA35, 0x3BA3D70A, 0x3E4CCCCD, 0);
        }
        M2C_FIELD(&D_1A4BE0, s16 *, 0x222) = 3;
        temp_3_10 = M2C_FIELD(arg0, u16 *, 0x96);
        M2C_FIELD(arg0, u16 *, 0x96) = (u16) (temp_3_10 + 1);
        if (temp_3_10 >= 0x12U) {
            func_003C4138(temp_18 + 0x14, 0x3F800000, 0.14000002f);
            D_L03_001DF2D0 = M2C_FIELD(temp_18, f32 *, 0x14);
            var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
            if ((u16) M2C_FIELD(arg0, u16 *, 0x96) >= 0x22U) {
                D_L03_001E28E4 = 1.1100293f;
                func_00382810(0, 1, 0, 0x3F8E1571, 0x3BA3D70A, 0x3E4CCCCD, 0);
                func_L01_003EB5E0(0, 3);
                var_5_2 = 2;
                goto block_202;
            }
        } else {
            goto block_213;
        }
        goto block_214;
    case 3:
        if (func_L01_004561B8(arg0) != 0) {
            M2C_FIELD(temp_18, s32 *, 0x830) = 0;
            if ((u32) (M2C_FIELD(&D_1CCFD0, u16 *, 0x76) - 6) >= 2U) {
                M2C_FIELD(&D_1CCFD0, u16 *, 0x76) = 5U;
            }
            if ((u32) (M2C_FIELD(&D_1CCFD0, u16 *, 0x9E) - 6) >= 2U) {
                M2C_FIELD(&D_1CCFD0, u16 *, 0x9E) = 5U;
            }
            func_L01_0041A6E0();
        }
        temp_7 = M2C_FIELD(temp_18, void **, 0);
        M2C_FIELD(temp_7, u16 *, 0x34) = (u16) (M2C_FIELD(temp_7, u16 *, 0x34) & 0xFF7F);
        temp_3_11 = M2C_FIELD(temp_18, void **, 0x1C);
        M2C_FIELD(temp_3_11, u16 *, 0x34) = (u16) (M2C_FIELD(temp_3_11, u16 *, 0x34) & 0xFF7F);
        func_L03_003ADE98(arg0, 0x604040, 0x403030, temp_7);
        func_L03_003AD8C8(M2C_FIELD(temp_18, void **, 0x1C), M2C_FIELD(temp_18, s32 *, 0x2C));
        func_L03_003AD580();
        func_003C4138(temp_18 + 0x14, 0, M2C_FIELD(saved_reg_gp, f32 *, 0x1D50) * 0.020000001f);
        D_L03_001DF2D0 = M2C_FIELD(temp_18, f32 *, 0x14);
        if (M2C_FIELD(temp_18, f32 *, 0x14) == 0.0f) {
            if (M2C_FIELD(saved_reg_gp, s32 *, -0x7454) == 3) {
                var_5_2 = 4;
                if (M2C_FIELD(&D_1A7E18, u16 *, 0xE04) == 0) {
                    if (*(u16 *)0x143954 != 0) {
                        if (func_L01_0041A5B0(0x15D6, 0x12B) != 0) {
                            if (M2C_FIELD(&D_1A7E18, u16 *, 0x10608) == 0) {
                                M2C_FIELD(&D_1A7E18, u16 *, 0x10608) = 1U;
                            }
                            func_L03_003AE5F0(1);
                            var_5_2 = 0x11;
                            goto block_202;
                        }
                        temp_2_13 = M2C_FIELD(temp_18, s32 *, 0x830) + 1;
                        M2C_FIELD(temp_18, s32 *, 0x830) = temp_2_13;
                        if (temp_2_13 >= 0x1A) {
                            var_5_2 = 4;
                            goto block_202;
                        }
                        goto block_213;
                    }
                    goto block_188;
                }
                goto block_202;
            }
block_188:
            var_5_2 = 4;
            goto block_202;
        }
        goto block_213;
        goto block_214;
    case 17:
        var_4_3 = &D_L03_002E52F0;
        if (((M2C_FIELD(&D_L03_002E52F0, s32 *, 0) == 0) && (M2C_FIELD(&D_L03_002E52F0, s32 *, 0x24) == -1)) || (var_4_3 = (M2C_UNK *) (0xF000 << 0x18), var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10), ((M2C_FIELD(*(void *)0x1D52FC, s64 *, 0x1A0) & (s32) var_4_3) != 0))) {
            func_L01_0041A6E0((s64) var_4_3);
            func_L01_004606A8(M2C_FIELD(saved_reg_gp, void **, -0x75B4));
            func_L03_003AE5F0(0);
            D_L03_001DF2D0 = 0.0f;
            var_5_2 = 4;
            goto block_202;
        }
        goto block_214;
    case 2:
        if (func_003A0EC0(7, 1, arg0, 4, 0) != 0) {
            M2C_FIELD(saved_reg_gp, M2C_UNK32 *, 0x2A20) = 0;
            goto block_201;
        }
        M2C_FIELD(arg0, s8 *, 0x30) = 0xFF;
        M2C_FIELD(arg0, u16 *, 0x34) = (u16) (M2C_FIELD(arg0, u16 *, 0x34) & 0xFF7F);
        temp_2_14 = func_L03_003AC868(arg0, (f32) M2C_FIELD(saved_reg_gp, s32 *, 0x1D24));
        M2C_FIELD(temp_18, void **, 0) = temp_2_14;
        temp_2_15 = func_L03_003ACAD0(arg0, temp_2_14);
        M2C_FIELD(temp_18, s32 *, 4) = 0x20;
        M2C_FIELD(temp_18, void **, 0x30) = temp_2_15;
        temp_2_16 = func_L03_003AC998(arg0, M2C_FIELD(temp_18, void **, 0), 0x20);
        M2C_FIELD(temp_18, f32 *, 0x58) = (f32) D_L03_001DF370;
        M2C_FIELD(temp_18, f32 *, 0x5C) = (f32) D_L03_001DF374;
        M2C_FIELD(temp_18, void **, 0x1C) = temp_2_16;
        D_L03_001DF370 = 100.0f;
        D_L03_001DF374 = 255.0f;
        M2C_FIELD(temp_18, u8 *, 0x60) = (u8) D_L03_001DF364;
        M2C_FIELD(temp_18, u8 *, 0x61) = (u8) D_L03_001DF365;
        M2C_FIELD(temp_18, u8 *, 0x62) = (u8) D_L03_001DF366;
        D_L03_001DF364 = 0x3C;
        D_L03_001DF365 = 0x3F;
        M2C_FIELD(saved_reg_gp, s8 *, 0x2AB6) = 0x41;
        func_L03_003ADF58(arg0, 0x41, 0x3F, 0x3C);
        if (M2C_FIELD(&D_1CCFD0, s16 *, 0x3C) == -1) {
            var_2_3 = M2C_FIELD(&D_1CCFD0, s16 *, 0x48);
        } else {
            var_2_3 = M2C_FIELD(&D_1CCFD0, s16 *, 0x3C);
        }
        M2C_FIELD(temp_18, s32 *, 0x848) = (s32) var_2_3;
        func_L01_0045F1E8(M2C_FIELD(temp_18, s32 *, 0x840), M2C_FIELD(temp_18, s32 *, 0x844));
        func_13C1A0(0x4D);
        var_5_2 = 3;
        goto block_202;
    case 18:
        var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        if (M2C_FIELD(*(void *)0x1D52FC, s32 *, 0x1A4) & 0x800) {
            func_L03_003ADDA0(arg0);
            var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10);
        }
        goto block_214;
    case 10:
        if (func_L01_004561B8(arg0) != 0) {
            var_fp = temp_18 + 0x207;
            temp_2_17 = func_L03_00348B88(arg0);
            var_23 = temp_18 + 0x206;
            M2C_FIELD(temp_18, void **, 0x34) = temp_2_17;
            var_22 = temp_18 + 0x205;
            func_L03_00348C18(temp_2_17, temp_18 + 0x24, &D_L03_001DE630, 0, 1, 0xF4240);
            var_21 = temp_18 + 0x204;
            var_20 = temp_18 + 0x1F4;
            func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), temp_18 + 0x28, &D_L03_001DE640, 0, 1, 4);
            var_16 = temp_18 + 0x200;
            sp54 = temp_18 + 0x20C;
            var_17 = temp_18 + 0x1F0;
            sp58 = temp_18 + 0x20A;
            sp5C = temp_18 + 0x209;
            sp60 = temp_18 + 0x208;
            sp50 = 3;
            do {
                temp_8 = *var_16;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), var_16, &D_L03_001DE650, 4, temp_8, temp_8);
                temp_5_5 = var_17;
                temp_2_18 = sp50 - 1;
                sp50 = temp_2_18;
                var_17 += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), temp_5_5, &D_L03_001DE668, 1, 1, 4);
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), var_20, &D_L03_001DE678, 0, -1, 0xF4240);
                var_20 += 0x20;
                temp_5_6 = var_16;
                var_16 += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), temp_5_6, &D_L03_001DE688, 0, 1, 0x3E8);
                temp_5_7 = var_21;
                var_21 += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), temp_5_7, &D_L03_001DE698, 2, 0, 0x64);
                temp_5_8 = var_22;
                var_22 += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), temp_5_8, &D_L03_001DE6A8, 2, 0xA, 0x64);
                temp_5_9 = var_23;
                var_23 += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), temp_5_9, &D_L03_001DE6B8, 2, 0, 0x64);
                temp_5_10 = var_fp;
                var_fp += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), temp_5_10, &D_L03_001DE6C8, 2, 0, 1);
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), sp60, &D_L03_001DE6D8, 2, 1, 8);
                sp60 += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), sp5C, &D_L03_001DE6E8, 2, 0, 7);
                sp5C += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), sp58, &D_L03_001DE6F8, 2, 0, 0x64);
                sp58 += 0x20;
                func_L03_00348C18(M2C_FIELD(temp_18, void **, 0x34), sp54, &D_L03_001DE708, 0, 0, 0x3E8);
                sp54 += 0x20;
            } while (temp_2_18 >= 0);
        }
        func_L01_00452560(0, 1, 0, 1, 0, 0, 0);
        temp_4_10 = M2C_FIELD(temp_18, void **, 0x34);
        if ((temp_4_10 == NULL) || (M2C_FIELD(temp_4_10, s16 *, 0xAA) != 0x118A) || (temp_3_12 = M2C_FIELD(temp_4_10, u8 *, 0x20), (temp_3_12 == 0xFE)) || (var_3 = M2C_FIELD(saved_reg_gp, s32 *, 0x2C10), (temp_3_12 == 0xFD))) {
            func_L01_004450F0(arg0, 1, -1);
            goto block_213;
        }
        goto block_214;
    }
}


#endif
