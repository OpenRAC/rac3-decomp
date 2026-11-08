/* func_L39_00624658: Opus handoff (prep by Sonnet worker w8, 2026-11-08)
   Size: 8888 bytes, places: 15 levels, file: src/levels/shared/L39_00622990.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: one function (one prologue addiu sp,-0xD0), 2210 instr, only 34 jal (20 distinct), no switch; 127 reads/writes of D_L39_004997E0 and 51 of D_L39_004997E1 (a byte array, indexed [i + 1 + ((p-i)&7)*0xFF]: a ring of 8 rows of 255 bytes), 34 of D_L39_0024B9C8.
   rac2 twin: none. part3 best func_L15_003DBB08 at 0.12; callees map to no rac2 twin. It is multiplayer-menu code (timer_tick_short x13, damage_queue_add x2, pad_pressed_within, vec_set_length, vec_rotate_by_matrix, local L39 helpers 0062FE58, 00634F38, 0061D7B0, 00648840, 00648960, 006212E8): per-frame 8-entry history/ring buffer with 255-byte records plus movement of a player object. Probably the multiplayer player-update (buffers one input record per frame).
   Mapping: n/a. Signature (m2c): void f(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, u8 *arg6) (a 5th stack-passed arg6).
   Identical / changed / added / removed: not applicable (no twin).
   Draft: raw m2c (switch-free, 1015 lines) saved at embedded below: it treats the sp slots as pointers and mis-types the ring buffer; it needs the buffer rewritten as a struct array (rows of 0xFF bytes) before it compiles (19 errors, all "invalid operands to binary &").
   Left for Opus: define `typedef struct { u8 d[0xFF]; } Row;` and a `Row D_L39_004997E0[8]`-style extern (check the size hint: it is an 8x255 array), type the sp slots as locals, then compile; this one has few calls so it is the most tractable of the no-twin slate (15 places share it, NTSC-U carried).
*/
/* raw m2c output (with the jump-table kit extension), does not compile as is */
#if 0
M2C_UNK func_0038CAD0(void *);                      /* extern * /
M2C_UNK func_0038CB00(void *, s32, s32, u8 *, M2C_UNK, void *, s32, u8 *); /* extern * /
M2C_UNK func_0038CE20(u8 *, u8 *, s32, s32, s32, M2C_UNK, f32); /* extern * /
f32 func_0038CEA8(u8 *);                            /* extern * /
M2C_UNK func_0038CF68(u8 *, u8 *, M2C_UNK);         /* extern * /
M2C_UNK func_0038D000(u8 *, u8 *, void *);          /* extern * /
M2C_UNK func_003C5060(void *, u8 *, u8 *, M2C_UNK); /* extern * /
M2C_UNK func_L01_0040E050(void *, u8, s32, u8 *, M2C_UNK, void *, s32, u8 *); /* extern * /
M2C_UNK func_L01_00446A70(s32, s32, M2C_UNK, void *, u8 *, f32, s32, void *, M2C_UNK); /* extern * /
s32 func_L01_004606E8(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern * /
void *func_L39_0061D7B0(void *);                    /* extern * /
s32 func_L39_006212E8(void *);                      /* extern * /
M2C_UNK func_L39_00628038(void *, M2C_UNK);         /* extern * /
M2C_UNK func_L39_00629958(void *);                  /* extern * /
M2C_UNK func_L39_0062FE58(void *, s32, void *, s32, s32, void *, u8 *); /* extern * /
M2C_UNK func_L39_00632180(void *, void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern * /
f32 func_L39_00632678(void *, void *);              /* extern * /
M2C_UNK func_L39_00634F38(void *);                  /* extern * /
s32 func_L39_00648840(void *, M2C_UNK);             /* extern * /
M2C_UNK func_L39_00648960(void *, M2C_UNK);         /* extern * /
extern s32 D_L39_0024B9C8;
extern u8 D_L39_004997E0;
extern u8 D_L39_004997E1;

void func_L39_00624658(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, u8 *arg6) {
    s32 sp0;
    u32 sp4;                                        /* compiler-managed * /
    s32 sp8;
    s32 sp10;
    s16 sp14;                                       /* compiler-managed * /
    void *sp20;
    void *sp24;
    void *sp28;
    void *sp2C;
    void *sp30;
    void *sp34;
    void *sp38;
    void *sp3C;
    void *sp40;
    void *sp44;
    void *sp48;
    void *sp4C;
    void *sp50;
    void *sp54;
    void *sp58;
    void *sp5C;
    void *sp60;
    void *sp64;
    f32 temp_f20;
    f32 var_f1_2;
    s16 temp_19;
    s32 temp_10;
    s32 temp_2_14;
    s32 temp_2_16;
    s32 temp_2_21;
    s32 temp_2_23;
    s32 temp_2_28;
    s32 temp_2_30;
    s32 temp_2_35;
    s32 temp_2_37;
    s32 temp_2_42;
    s32 temp_2_44;
    s32 temp_2_49;
    s32 temp_2_51;
    s32 temp_2_56;
    s32 temp_2_58;
    s32 temp_2_59;
    s32 temp_2_60;
    s32 temp_2_65;
    s32 temp_2_66;
    s32 temp_2_67;
    s32 temp_2_68;
    s32 temp_2_7;
    s32 temp_2_9;
    s32 temp_3;
    s32 temp_3_11;
    s32 temp_3_13;
    s32 temp_3_15;
    s32 temp_3_17;
    s32 temp_3_19;
    s32 temp_3_21;
    s32 temp_3_23;
    s32 temp_3_25;
    s32 temp_3_27;
    s32 temp_3_29;
    s32 temp_3_31;
    s32 temp_3_33;
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_7;
    s32 temp_3_9;
    s32 temp_5;
    s32 temp_6;
    s32 temp_6_2;
    s32 temp_7_2;
    s32 var_10_2;
    s32 var_10_3;
    s32 var_10_4;
    s32 var_10_5;
    s32 var_10_6;
    s32 var_10_7;
    s32 var_12;
    s32 var_5;
    s32 var_6_2;
    s32 var_6_3;
    s32 var_6_4;
    s32 var_6_5;
    s32 var_6_6;
    s32 var_6_7;
    s32 var_7;
    s32 var_8;
    s32 var_8_2;
    u16 var_2_10;
    u16 var_2_11;
    u16 var_2_12;
    u16 var_2_13;
    u16 var_2_14;
    u16 var_2_15;
    u16 var_2_16;
    u16 var_2_17;
    u16 var_2_2;
    u16 var_2_3;
    u16 var_2_4;
    u16 var_2_5;
    u16 var_2_6;
    u16 var_2_7;
    u16 var_2_8;
    u16 var_2_9;
    u32 temp_2_10;
    u32 temp_2_12;
    u32 temp_2_17;
    u32 temp_2_19;
    u32 temp_2_24;
    u32 temp_2_26;
    u32 temp_2_2;
    u32 temp_2_31;
    u32 temp_2_33;
    u32 temp_2_38;
    u32 temp_2_3;
    u32 temp_2_40;
    u32 temp_2_45;
    u32 temp_2_47;
    u32 temp_2_52;
    u32 temp_2_54;
    u32 temp_2_5;
    u32 temp_4;
    u32 temp_4_10;
    u32 temp_4_11;
    u32 temp_4_14;
    u32 temp_4_15;
    u32 temp_4_18;
    u32 temp_4_19;
    u32 temp_4_22;
    u32 temp_4_23;
    u32 temp_4_26;
    u32 temp_4_27;
    u32 temp_4_2;
    u32 temp_4_30;
    u32 temp_4_31;
    u32 temp_4_3;
    u32 temp_4_6;
    u32 temp_4_7;
    u32 var_3;
    u32 var_3_2;
    u32 var_3_3;
    u32 var_3_4;
    u32 var_f1;
    u8 *temp_7;
    u8 *var_10;
    u8 *var_17;
    u8 *var_18;
    u8 *var_19;
    u8 *var_20;
    u8 *var_21;
    u8 *var_22;
    u8 *var_23;
    u8 *var_fp;
    u8 temp_2;
    u8 temp_2_11;
    u8 temp_2_13;
    u8 temp_2_15;
    u8 temp_2_18;
    u8 temp_2_20;
    u8 temp_2_22;
    u8 temp_2_25;
    u8 temp_2_27;
    u8 temp_2_29;
    u8 temp_2_32;
    u8 temp_2_34;
    u8 temp_2_36;
    u8 temp_2_39;
    u8 temp_2_41;
    u8 temp_2_43;
    u8 temp_2_46;
    u8 temp_2_48;
    u8 temp_2_4;
    u8 temp_2_50;
    u8 temp_2_53;
    u8 temp_2_55;
    u8 temp_2_57;
    u8 temp_2_64;
    u8 temp_2_6;
    u8 temp_2_8;
    u8 temp_3_10;
    u8 temp_3_12;
    u8 temp_3_14;
    u8 temp_3_16;
    u8 temp_3_18;
    u8 temp_3_20;
    u8 temp_3_22;
    u8 temp_3_24;
    u8 temp_3_26;
    u8 temp_3_28;
    u8 temp_3_2;
    u8 temp_3_30;
    u8 temp_3_32;
    u8 temp_3_34;
    u8 temp_3_35;
    u8 temp_3_36;
    u8 temp_3_37;
    u8 temp_3_4;
    u8 temp_3_6;
    u8 temp_3_8;
    u8 temp_4_12;
    u8 temp_4_13;
    u8 temp_4_16;
    u8 temp_4_17;
    u8 temp_4_20;
    u8 temp_4_21;
    u8 temp_4_24;
    u8 temp_4_25;
    u8 temp_4_28;
    u8 temp_4_29;
    u8 temp_4_32;
    u8 temp_4_33;
    u8 temp_4_34;
    u8 temp_4_4;
    u8 temp_4_5;
    u8 temp_4_8;
    u8 temp_4_9;
    u8 var_2;
    void *temp_11;
    void *temp_17;
    void *temp_2_61;
    void *temp_2_62;
    void *temp_2_63;
    void *temp_9;
    void *temp_9_2;
    void *temp_9_3;
    void *var_6;
    void *var_9;
    void *var_9_2;
    void *var_9_3;
    void *var_9_4;
    void *var_9_5;
    void *var_9_6;

    var_5 = arg1;
    var_6 = arg2;
    var_7 = arg3;
    var_8 = arg4;
    var_10 = arg6;
    temp_2 = M2C_FIELD(arg0, u8 *, 0x1A18);
    temp_9 = arg0 + 0x1A18;
    if (temp_2 == 0) {
        sp2C = arg0 + 0x320;
        var_2 = 0;
        sp24 = arg0 + 0x30A;
        sp20 = arg0 + 0x308;
        sp3C = arg0 + 0x332;
        sp30 = arg0 + 0x328;
        sp34 = arg0 + 0x32C;
        sp40 = arg0 + 0x334;
        sp44 = arg0 + 0x336;
        sp38 = arg0 + 0x32E;
        sp48 = arg0 + 0x33E;
        sp4C = arg0 + 0x340;
        sp50 = arg0 + 0x342;
        sp54 = arg0 + 0x348;
        sp58 = arg0 + 0x34A;
        sp5C = arg0 + 0x35C;
        sp60 = arg0 + 0x360;
        var_17 = arg0 + 0x311;
        var_18 = arg0 + 0x31B;
        var_23 = arg0 + 0x313;
        var_19 = arg0 + 0x316;
        var_20 = arg0 + 0x318;
        var_21 = arg0 + 0x314;
        var_22 = arg0 + 0x31A;
        var_fp = arg0 + 0x312;
        sp28 = arg0 + 0x19E6;
        sp64 = arg0 + 0xE0;
    } else {
        var_10 = &D_L39_004997E0;
        var_8 = temp_2 + 1;
        sp2C = arg0 + 0x320;
        var_7 = (temp_9 - temp_2) & 7;
        sp20 = arg0 + 0x308;
        sp24 = arg0 + 0x30A;
        sp3C = arg0 + 0x332;
        sp30 = arg0 + 0x328;
        sp34 = arg0 + 0x32C;
        sp40 = arg0 + 0x334;
        sp44 = arg0 + 0x336;
        sp38 = arg0 + 0x32E;
        sp48 = arg0 + 0x33E;
        sp4C = arg0 + 0x340;
        sp50 = arg0 + 0x342;
        sp54 = arg0 + 0x348;
        sp58 = arg0 + 0x34A;
        sp5C = arg0 + 0x35C;
        sp60 = arg0 + 0x360;
        sp28 = arg0 + 0x19E6;
        sp64 = arg0 + 0xE0;
        var_17 = arg0 + 0x311;
        var_18 = arg0 + 0x31B;
        var_23 = arg0 + 0x313;
        var_19 = arg0 + 0x316;
        var_20 = arg0 + 0x318;
        var_21 = arg0 + 0x314;
        var_22 = arg0 + 0x31A;
        var_fp = arg0 + 0x312;
        var_5 = 3;
        *sp = (&D_L39_004997E0)[var_8 + ((var_7 & 7) * 0xFF)];
        var_6 = sp + 1;
        temp_3 = sp0 ^ (s32) temp_9;
        temp_2_2 = sp4 ^ temp_3;
        sp0 = temp_3;
        temp_4 = temp_2_2 >> 0x10;
        sp4 = temp_4 / (u32) (((temp_2_2 ^ temp_4) << 0x10) + 1);
        var_2 = (u8) sp4;
    }
    if (var_2 == 0) {
        func_L39_0062FE58(arg0, var_5, var_6, var_7, var_8, temp_9, var_10);
    }
    temp_5 = M2C_FIELD(arg0, s32 *, 0x2F0) + 1;
    temp_6 = M2C_FIELD(arg0, s32 *, 0x2F4) + 1;
    temp_7 = M2C_FIELD(arg0, u8 **, 0x2F8) + 1;
    M2C_FIELD(arg0, s32 *, 0x2FC) = (s32) (M2C_FIELD(arg0, s32 *, 0x2FC) + 1);
    M2C_FIELD(arg0, s32 *, 0x2F0) = temp_5;
    M2C_FIELD(arg0, s32 *, 0x2F4) = temp_6;
    M2C_FIELD(arg0, u8 **, 0x2F8) = temp_7;
    M2C_FIELD(arg0, u16 *, 0x31E) = (u16) (M2C_FIELD(arg0, u16 *, 0x31E) + 1);
    func_0038CB00(sp2C, temp_5, temp_6, temp_7);
    temp_3_2 = M2C_FIELD(arg0, u8 *, 0x311);
    if (temp_3_2 == 0) {
        var_2_2 = 0;
    } else {
        *sp = (&D_L39_004997E0)[temp_3_2 + 1 + (((var_17 - temp_3_2) & 7 & 7) * 0xFF)];
        temp_3_3 = sp0 ^ (s32) var_17;
        temp_2_3 = sp4 ^ temp_3_3;
        sp0 = temp_3_3;
        temp_4_2 = temp_2_3 >> 0x10;
        sp4 = temp_4_2 / (u32) (((temp_2_3 ^ temp_4_2) << 0x10) + 1);
        var_2_2 = (u16) sp4;
    }
    temp_2_4 = M2C_FIELD(arg0, u8 *, 0x311);
    if ((var_2_2 << 0x10) > 0) {
        if (temp_2_4 != 0) {
            temp_3_4 = M2C_FIELD(arg0, u8 *, 0x311);
            *sp = (&D_L39_004997E0)[temp_3_4 + 1 + (((var_17 - temp_3_4) & 7 & 7) * 0xFF)];
            temp_3_5 = sp0 ^ (s32) var_17;
            temp_2_5 = sp4 ^ temp_3_5;
            sp0 = temp_3_5;
            temp_4_3 = temp_2_5 >> 0x10;
            sp4 = temp_4_3 / (u32) (((temp_2_5 ^ temp_4_3) << 0x10) + 1);
            var_2_3 = (u16) sp4;
        } else {
            var_2_3 = 0;
        }
        if (*var_17 == 0) {
            temp_2_6 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_6;
            *var_17 = temp_2_6;
        } else {
            temp_4_4 = *var_17;
            *var_17 = D_L39_004997E1;
            D_L39_004997E1 = temp_4_4;
        }
        sp4 = (s16) ((s32) ((var_2_3 << 0x10) + 0xFFFF0000) >> 0x10);
        var_10_2 = (var_17 - *var_17) & 7;
        temp_2_7 = *((((u32) ((s32) var_17 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_7;
        sp0 = (s32) var_17 ^ temp_2_7;
        var_6_2 = *var_17 + 1;
        var_9 = sp + 1;
        (&D_L39_004997E0)[var_6_2 + ((var_10_2 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_4 == 0) {
            temp_2_8 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_8;
            M2C_FIELD(arg0, u8 *, 0x311) = temp_2_8;
        } else {
            temp_4_5 = M2C_FIELD(arg0, u8 *, 0x311);
            M2C_FIELD(arg0, u8 *, 0x311) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_5;
        }
        sp4 = 0;
        var_10_2 = (var_17 - *var_17) & 7;
        temp_2_9 = *((((u32) ((s32) var_17 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_9;
        sp0 = (s32) var_17 ^ temp_2_9;
        var_6_2 = *var_17 + 1;
        var_9 = sp + 1;
        (&D_L39_004997E0)[var_6_2 + ((var_10_2 & 7) * 0xFF)] = *sp;
    }
    func_0038CB00(sp24, (s32) *sp, var_6_2, &D_L39_004997E0, 3, var_9, var_10_2, &D_L39_004997E0);
    temp_3_6 = M2C_FIELD(arg0, u8 *, 0x31B);
    if (temp_3_6 == 0) {
        var_2_4 = 0;
    } else {
        *sp = (&D_L39_004997E0)[temp_3_6 + 1 + (((var_18 - temp_3_6) & 7 & 7) * 0xFF)];
        temp_3_7 = sp0 ^ (s32) var_18;
        temp_2_10 = sp4 ^ temp_3_7;
        sp0 = temp_3_7;
        temp_4_6 = temp_2_10 >> 0x10;
        sp4 = temp_4_6 / (u32) (((temp_2_10 ^ temp_4_6) << 0x10) + 1);
        var_2_4 = (u16) sp4;
    }
    temp_2_11 = M2C_FIELD(arg0, u8 *, 0x31B);
    if ((var_2_4 << 0x10) > 0) {
        if (temp_2_11 != 0) {
            temp_3_8 = M2C_FIELD(arg0, u8 *, 0x31B);
            *sp = (&D_L39_004997E0)[temp_3_8 + 1 + (((var_18 - temp_3_8) & 7 & 7) * 0xFF)];
            temp_3_9 = sp0 ^ (s32) var_18;
            temp_2_12 = sp4 ^ temp_3_9;
            sp0 = temp_3_9;
            temp_4_7 = temp_2_12 >> 0x10;
            sp4 = temp_4_7 / (u32) (((temp_2_12 ^ temp_4_7) << 0x10) + 1);
            var_2_5 = (u16) sp4;
        } else {
            var_2_5 = 0;
        }
        if (*var_18 == 0) {
            temp_2_13 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_13;
            *var_18 = temp_2_13;
        } else {
            temp_4_8 = *var_18;
            *var_18 = D_L39_004997E1;
            D_L39_004997E1 = temp_4_8;
        }
        sp4 = (s16) ((s32) ((var_2_5 << 0x10) + 0xFFFF0000) >> 0x10);
        var_10_3 = (var_18 - *var_18) & 7;
        temp_2_14 = *((((u32) ((s32) var_18 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_14;
        sp0 = (s32) var_18 ^ temp_2_14;
        var_6_3 = *var_18 + 1;
        var_9_2 = sp + 1;
        (&D_L39_004997E0)[var_6_3 + ((var_10_3 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_11 == 0) {
            temp_2_15 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_15;
            M2C_FIELD(arg0, u8 *, 0x31B) = temp_2_15;
        } else {
            temp_4_9 = M2C_FIELD(arg0, u8 *, 0x31B);
            M2C_FIELD(arg0, u8 *, 0x31B) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_9;
        }
        sp4 = 0;
        var_10_3 = (var_18 - *var_18) & 7;
        temp_2_16 = *((((u32) ((s32) var_18 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_16;
        sp0 = (s32) var_18 ^ temp_2_16;
        var_6_3 = *var_18 + 1;
        var_9_2 = sp + 1;
        (&D_L39_004997E0)[var_6_3 + ((var_10_3 & 7) * 0xFF)] = *sp;
    }
    func_0038CB00(sp20, (s32) *sp, var_6_3, &D_L39_004997E0, 3, var_9_2, var_10_3, &D_L39_004997E0);
    func_0038CB00(sp3C);
    temp_3_10 = M2C_FIELD(arg0, u8 *, 0x313);
    if (temp_3_10 == 0) {
        var_2_6 = 0;
    } else {
        *sp = (&D_L39_004997E0)[temp_3_10 + 1 + (((var_23 - temp_3_10) & 7 & 7) * 0xFF)];
        temp_3_11 = sp0 ^ (s32) var_23;
        temp_2_17 = sp4 ^ temp_3_11;
        sp0 = temp_3_11;
        temp_4_10 = temp_2_17 >> 0x10;
        sp4 = temp_4_10 / (u32) (((temp_2_17 ^ temp_4_10) << 0x10) + 1);
        var_2_6 = (u16) sp4;
    }
    temp_2_18 = M2C_FIELD(arg0, u8 *, 0x313);
    if ((var_2_6 << 0x10) > 0) {
        if (temp_2_18 != 0) {
            temp_3_12 = M2C_FIELD(arg0, u8 *, 0x313);
            *sp = (&D_L39_004997E0)[temp_3_12 + 1 + (((var_23 - temp_3_12) & 7 & 7) * 0xFF)];
            temp_3_13 = sp0 ^ (s32) var_23;
            temp_2_19 = sp4 ^ temp_3_13;
            sp0 = temp_3_13;
            temp_4_11 = temp_2_19 >> 0x10;
            sp4 = temp_4_11 / (u32) (((temp_2_19 ^ temp_4_11) << 0x10) + 1);
            var_2_7 = (u16) sp4;
        } else {
            var_2_7 = 0;
        }
        if (*var_23 == 0) {
            temp_2_20 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_20;
            *var_23 = temp_2_20;
        } else {
            temp_4_12 = *var_23;
            *var_23 = D_L39_004997E1;
            D_L39_004997E1 = temp_4_12;
        }
        sp4 = (s16) ((s32) ((var_2_7 << 0x10) + 0xFFFF0000) >> 0x10);
        var_10_4 = (var_23 - *var_23) & 7;
        temp_2_21 = *((((u32) ((s32) var_23 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_21;
        sp0 = (s32) var_23 ^ temp_2_21;
        var_6_4 = *var_23 + 1;
        var_9_3 = sp + 1;
        (&D_L39_004997E0)[var_6_4 + ((var_10_4 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_18 == 0) {
            temp_2_22 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_22;
            M2C_FIELD(arg0, u8 *, 0x313) = temp_2_22;
        } else {
            temp_4_13 = M2C_FIELD(arg0, u8 *, 0x313);
            M2C_FIELD(arg0, u8 *, 0x313) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_13;
        }
        sp4 = 0;
        var_10_4 = (var_23 - *var_23) & 7;
        temp_2_23 = *((((u32) ((s32) var_23 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_23;
        sp0 = (s32) var_23 ^ temp_2_23;
        var_6_4 = *var_23 + 1;
        var_9_3 = sp + 1;
        (&D_L39_004997E0)[var_6_4 + ((var_10_4 & 7) * 0xFF)] = *sp;
    }
    func_L01_0040E050(sp30, *sp, var_6_4, &D_L39_004997E0, 3, var_9_3, var_10_4, &D_L39_004997E0);
    func_0038CB00(sp34);
    func_0038CB00(sp40);
    temp_3_14 = M2C_FIELD(arg0, u8 *, 0x316);
    if (temp_3_14 == 0) {
        var_2_8 = 0;
    } else {
        *sp = (&D_L39_004997E0)[temp_3_14 + 1 + (((var_19 - temp_3_14) & 7 & 7) * 0xFF)];
        temp_3_15 = sp0 ^ (s32) var_19;
        temp_2_24 = sp4 ^ temp_3_15;
        sp0 = temp_3_15;
        temp_4_14 = temp_2_24 >> 0x10;
        sp4 = temp_4_14 / (u32) (((temp_2_24 ^ temp_4_14) << 0x10) + 1);
        var_2_8 = (u16) sp4;
    }
    temp_2_25 = M2C_FIELD(arg0, u8 *, 0x316);
    if ((var_2_8 << 0x10) > 0) {
        if (temp_2_25 != 0) {
            temp_3_16 = M2C_FIELD(arg0, u8 *, 0x316);
            *sp = (&D_L39_004997E0)[temp_3_16 + 1 + (((var_19 - temp_3_16) & 7 & 7) * 0xFF)];
            temp_3_17 = sp0 ^ (s32) var_19;
            temp_2_26 = sp4 ^ temp_3_17;
            sp0 = temp_3_17;
            temp_4_15 = temp_2_26 >> 0x10;
            sp4 = temp_4_15 / (u32) (((temp_2_26 ^ temp_4_15) << 0x10) + 1);
            var_2_9 = (u16) sp4;
        } else {
            var_2_9 = 0;
        }
        if (*var_19 == 0) {
            temp_2_27 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_27;
            *var_19 = temp_2_27;
        } else {
            temp_4_16 = *var_19;
            *var_19 = D_L39_004997E1;
            D_L39_004997E1 = temp_4_16;
        }
        sp4 = (s16) ((s32) ((var_2_9 << 0x10) + 0xFFFF0000) >> 0x10);
        var_10_5 = (var_19 - *var_19) & 7;
        temp_2_28 = *((((u32) ((s32) var_19 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_28;
        sp0 = (s32) var_19 ^ temp_2_28;
        var_6_5 = *var_19 + 1;
        var_9_4 = sp + 1;
        (&D_L39_004997E0)[var_6_5 + ((var_10_5 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_25 == 0) {
            temp_2_29 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_29;
            M2C_FIELD(arg0, u8 *, 0x316) = temp_2_29;
        } else {
            temp_4_17 = M2C_FIELD(arg0, u8 *, 0x316);
            M2C_FIELD(arg0, u8 *, 0x316) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_17;
        }
        sp4 = 0;
        var_10_5 = (var_19 - *var_19) & 7;
        temp_2_30 = *((((u32) ((s32) var_19 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_30;
        sp0 = (s32) var_19 ^ temp_2_30;
        var_6_5 = *var_19 + 1;
        var_9_4 = sp + 1;
        (&D_L39_004997E0)[var_6_5 + ((var_10_5 & 7) * 0xFF)] = *sp;
    }
    func_0038CB00(sp44, (s32) *sp, var_6_5, &D_L39_004997E0, 3, var_9_4, var_10_5, &D_L39_004997E0);
    temp_3_18 = M2C_FIELD(arg0, u8 *, 0x318);
    if (temp_3_18 == 0) {
        var_2_10 = 0;
    } else {
        *sp = (&D_L39_004997E0)[temp_3_18 + 1 + (((var_20 - temp_3_18) & 7 & 7) * 0xFF)];
        temp_3_19 = sp0 ^ (s32) var_20;
        temp_2_31 = sp4 ^ temp_3_19;
        sp0 = temp_3_19;
        temp_4_18 = temp_2_31 >> 0x10;
        sp4 = temp_4_18 / (u32) (((temp_2_31 ^ temp_4_18) << 0x10) + 1);
        var_2_10 = (u16) sp4;
    }
    temp_2_32 = M2C_FIELD(arg0, u8 *, 0x318);
    if ((var_2_10 << 0x10) > 0) {
        if (temp_2_32 != 0) {
            temp_3_20 = M2C_FIELD(arg0, u8 *, 0x318);
            *sp = (&D_L39_004997E0)[temp_3_20 + 1 + (((var_20 - temp_3_20) & 7 & 7) * 0xFF)];
            temp_3_21 = sp0 ^ (s32) var_20;
            temp_2_33 = sp4 ^ temp_3_21;
            sp0 = temp_3_21;
            temp_4_19 = temp_2_33 >> 0x10;
            sp4 = temp_4_19 / (u32) (((temp_2_33 ^ temp_4_19) << 0x10) + 1);
            var_2_11 = (u16) sp4;
        } else {
            var_2_11 = 0;
        }
        if (*var_20 == 0) {
            temp_2_34 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_34;
            *var_20 = temp_2_34;
        } else {
            temp_4_20 = *var_20;
            *var_20 = D_L39_004997E1;
            D_L39_004997E1 = temp_4_20;
        }
        sp4 = (s16) ((s32) ((var_2_11 << 0x10) + 0xFFFF0000) >> 0x10);
        temp_2_35 = *((((u32) ((s32) var_20 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_35;
        sp0 = (s32) var_20 ^ temp_2_35;
        (&D_L39_004997E0)[*var_20 + 1 + (((var_20 - *var_20) & 7 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_32 == 0) {
            temp_2_36 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_36;
            M2C_FIELD(arg0, u8 *, 0x318) = temp_2_36;
        } else {
            temp_4_21 = M2C_FIELD(arg0, u8 *, 0x318);
            M2C_FIELD(arg0, u8 *, 0x318) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_21;
        }
        sp4 = 0;
        temp_2_37 = *((((u32) ((s32) var_20 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_37;
        sp0 = (s32) var_20 ^ temp_2_37;
        (&D_L39_004997E0)[*var_20 + 1 + (((var_20 - *var_20) & 7 & 7) * 0xFF)] = *sp;
    }
    if (M2C_FIELD(arg0, u8 *, 0x314) != 0) {
        temp_3_22 = M2C_FIELD(arg0, u8 *, 0x314);
        *sp = (&D_L39_004997E0)[temp_3_22 + 1 + (((var_21 - temp_3_22) & 7 & 7) * 0xFF)];
        temp_3_23 = sp0 ^ (s32) var_21;
        temp_2_38 = sp4 ^ temp_3_23;
        sp0 = temp_3_23;
        temp_4_22 = temp_2_38 >> 0x10;
        sp4 = temp_4_22 / (u32) (((temp_2_38 ^ temp_4_22) << 0x10) + 1);
        var_2_12 = (u16) sp4;
    } else {
        var_2_12 = 0;
    }
    temp_2_39 = M2C_FIELD(arg0, u8 *, 0x314);
    if ((var_2_12 << 0x10) > 0) {
        if (temp_2_39 != 0) {
            temp_3_24 = M2C_FIELD(arg0, u8 *, 0x314);
            *sp = (&D_L39_004997E0)[temp_3_24 + 1 + (((var_21 - temp_3_24) & 7 & 7) * 0xFF)];
            temp_3_25 = sp0 ^ (s32) var_21;
            temp_2_40 = sp4 ^ temp_3_25;
            sp0 = temp_3_25;
            temp_4_23 = temp_2_40 >> 0x10;
            sp4 = temp_4_23 / (u32) (((temp_2_40 ^ temp_4_23) << 0x10) + 1);
            var_2_13 = (u16) sp4;
        } else {
            var_2_13 = 0;
        }
        if (*var_21 == 0) {
            temp_2_41 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_41;
            *var_21 = temp_2_41;
        } else {
            temp_4_24 = *var_21;
            *var_21 = D_L39_004997E1;
            D_L39_004997E1 = temp_4_24;
        }
        sp4 = (s16) ((s32) ((var_2_13 << 0x10) + 0xFFFF0000) >> 0x10);
        var_10_6 = (var_21 - *var_21) & 7;
        temp_2_42 = *((((u32) ((s32) var_21 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_42;
        sp0 = (s32) var_21 ^ temp_2_42;
        var_6_6 = *var_21 + 1;
        var_9_5 = sp + 1;
        (&D_L39_004997E0)[var_6_6 + ((var_10_6 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_39 == 0) {
            temp_2_43 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_43;
            M2C_FIELD(arg0, u8 *, 0x314) = temp_2_43;
        } else {
            temp_4_25 = M2C_FIELD(arg0, u8 *, 0x314);
            M2C_FIELD(arg0, u8 *, 0x314) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_25;
        }
        sp4 = 0;
        var_10_6 = (var_21 - *var_21) & 7;
        temp_2_44 = *((((u32) ((s32) var_21 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_44;
        sp0 = (s32) var_21 ^ temp_2_44;
        var_6_6 = *var_21 + 1;
        var_9_5 = sp + 1;
        (&D_L39_004997E0)[var_6_6 + ((var_10_6 & 7) * 0xFF)] = *sp;
    }
    func_0038CB00(sp38, (s32) *sp, var_6_6, &D_L39_004997E0, 3, var_9_5, var_10_6, &D_L39_004997E0);
    func_0038CB00(sp48);
    func_0038CB00(sp4C);
    func_0038CB00(sp50);
    temp_3_26 = M2C_FIELD(arg0, u8 *, 0x31A);
    if (temp_3_26 == 0) {
        var_2_14 = 0;
    } else {
        *sp = (&D_L39_004997E0)[temp_3_26 + 1 + (((var_22 - temp_3_26) & 7 & 7) * 0xFF)];
        temp_3_27 = sp0 ^ (s32) var_22;
        temp_2_45 = sp4 ^ temp_3_27;
        sp0 = temp_3_27;
        temp_4_26 = temp_2_45 >> 0x10;
        sp4 = temp_4_26 / (u32) (((temp_2_45 ^ temp_4_26) << 0x10) + 1);
        var_2_14 = (u16) sp4;
    }
    temp_2_46 = M2C_FIELD(arg0, u8 *, 0x31A);
    if ((var_2_14 << 0x10) > 0) {
        if (temp_2_46 != 0) {
            temp_3_28 = M2C_FIELD(arg0, u8 *, 0x31A);
            *sp = (&D_L39_004997E0)[temp_3_28 + 1 + (((var_22 - temp_3_28) & 7 & 7) * 0xFF)];
            temp_3_29 = sp0 ^ (s32) var_22;
            temp_2_47 = sp4 ^ temp_3_29;
            sp0 = temp_3_29;
            temp_4_27 = temp_2_47 >> 0x10;
            sp4 = temp_4_27 / (u32) (((temp_2_47 ^ temp_4_27) << 0x10) + 1);
            var_2_15 = (u16) sp4;
        } else {
            var_2_15 = 0;
        }
        if (*var_22 == 0) {
            temp_2_48 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_48;
            *var_22 = temp_2_48;
        } else {
            temp_4_28 = *var_22;
            *var_22 = D_L39_004997E1;
            D_L39_004997E1 = temp_4_28;
        }
        sp4 = (s16) ((s32) ((var_2_15 << 0x10) + 0xFFFF0000) >> 0x10);
        temp_2_49 = *((((u32) ((s32) var_22 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_49;
        sp0 = (s32) var_22 ^ temp_2_49;
        (&D_L39_004997E0)[*var_22 + 1 + (((var_22 - *var_22) & 7 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_46 == 0) {
            temp_2_50 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_50;
            M2C_FIELD(arg0, u8 *, 0x31A) = temp_2_50;
        } else {
            temp_4_29 = M2C_FIELD(arg0, u8 *, 0x31A);
            M2C_FIELD(arg0, u8 *, 0x31A) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_29;
        }
        sp4 = 0;
        temp_2_51 = *((((u32) ((s32) var_22 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_51;
        sp0 = (s32) var_22 ^ temp_2_51;
        (&D_L39_004997E0)[*var_22 + 1 + (((var_22 - *var_22) & 7 & 7) * 0xFF)] = *sp;
    }
    if (M2C_FIELD(arg0, u8 *, 0x312) != 0) {
        temp_3_30 = M2C_FIELD(arg0, u8 *, 0x312);
        *sp = (&D_L39_004997E0)[temp_3_30 + 1 + (((var_fp - temp_3_30) & 7 & 7) * 0xFF)];
        temp_3_31 = sp0 ^ (s32) var_fp;
        temp_2_52 = sp4 ^ temp_3_31;
        sp0 = temp_3_31;
        temp_4_30 = temp_2_52 >> 0x10;
        sp4 = temp_4_30 / (u32) (((temp_2_52 ^ temp_4_30) << 0x10) + 1);
        var_2_16 = (u16) sp4;
    } else {
        var_2_16 = 0;
    }
    temp_2_53 = M2C_FIELD(arg0, u8 *, 0x312);
    if ((var_2_16 << 0x10) > 0) {
        if (temp_2_53 != 0) {
            temp_3_32 = M2C_FIELD(arg0, u8 *, 0x312);
            *sp = (&D_L39_004997E0)[temp_3_32 + 1 + (((var_fp - temp_3_32) & 7 & 7) * 0xFF)];
            temp_3_33 = sp0 ^ (s32) var_fp;
            temp_2_54 = sp4 ^ temp_3_33;
            sp0 = temp_3_33;
            temp_4_31 = temp_2_54 >> 0x10;
            sp4 = temp_4_31 / (u32) (((temp_2_54 ^ temp_4_31) << 0x10) + 1);
            var_2_17 = (u16) sp4;
        } else {
            var_2_17 = 0;
        }
        if (*var_fp == 0) {
            temp_2_55 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_55;
            *var_fp = temp_2_55;
        } else {
            temp_4_32 = *var_fp;
            *var_fp = D_L39_004997E1;
            D_L39_004997E1 = temp_4_32;
        }
        sp4 = (s16) ((s32) ((var_2_17 << 0x10) + 0xFFFF0000) >> 0x10);
        var_10_7 = (var_fp - *var_fp) & 7;
        temp_2_56 = *((((u32) ((s32) var_fp * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_56;
        sp0 = (s32) var_fp ^ temp_2_56;
        var_6_7 = *var_fp + 1;
        var_9_6 = sp + 1;
        (&D_L39_004997E0)[var_6_7 + ((var_10_7 & 7) * 0xFF)] = *sp;
    } else {
        if (temp_2_53 == 0) {
            temp_2_57 = D_L39_004997E0 + 1;
            D_L39_004997E0 = temp_2_57;
            M2C_FIELD(arg0, u8 *, 0x312) = temp_2_57;
        } else {
            temp_4_33 = M2C_FIELD(arg0, u8 *, 0x312);
            M2C_FIELD(arg0, u8 *, 0x312) = (u8) D_L39_004997E1;
            D_L39_004997E1 = temp_4_33;
        }
        sp4 = 0;
        var_10_7 = (var_fp - *var_fp) & 7;
        temp_2_58 = *((((u32) ((s32) var_fp * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
        sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_58;
        sp0 = (s32) var_fp ^ temp_2_58;
        var_6_7 = *var_fp + 1;
        var_9_6 = sp + 1;
        (&D_L39_004997E0)[var_6_7 + ((var_10_7 & 7) * 0xFF)] = *sp;
    }
    func_0038CB00(sp54, (s32) *sp, var_6_7, &D_L39_004997E0, 3, var_9_6, var_10_7, &D_L39_004997E0);
    func_0038CB00(sp58);
    func_0038CAD0(sp5C);
    func_0038CAD0(sp60);
    temp_3_34 = M2C_FIELD(arg0, u8 *, 0x19E6);
    if (temp_3_34 == 0) {
        var_3 = 0;
    } else {
        *sp = (&D_L39_004997E0)[temp_3_34 + 1 + (((sp28 - temp_3_34) & 7 & 7) * 0xFF)];
        temp_2_59 = sp0 ^ (s32) sp28;
        var_3 = sp4 ^ temp_2_59;
        sp0 = temp_2_59;
        sp4 = var_3;
    }
    temp_9_2 = arg0 + 0x19E4;
    if ((var_3 ^ 0x14) != 0) {
        var_3_2 = 0;
        if (M2C_FIELD(arg0, u8 *, 0x19E4) != 0) {
            temp_3_35 = M2C_FIELD(arg0, u8 *, 0x19E4);
            *sp = (&D_L39_004997E0)[temp_3_35 + 1 + (((temp_9_2 - temp_3_35) & 7 & 7) * 0xFF)];
            temp_2_60 = sp0 ^ (s32) temp_9_2;
            var_3_2 = sp4 ^ temp_2_60;
            sp0 = temp_2_60;
            sp4 = var_3_2;
        }
        if ((var_3_2 ^ 0x7A) != 0) {
            M2C_FIELD(arg0, s32 *, 0x350) = (s32) (M2C_FIELD(arg0, s32 *, 0x350) + 1);
        } else {
            goto block_153;
        }
    } else {
block_153:
        M2C_FIELD(arg0, s32 *, 0x350) = 0;
    }
    func_L39_00634F38(arg0);
    if (M2C_FIELD(arg0, u8 *, 0x1A07) == 0) {
        M2C_FIELD(arg0, s32 *, 0x30C) = 0;
    } else {
        M2C_FIELD(arg0, s32 *, 0x30C) = (s32) (M2C_FIELD(arg0, s32 *, 0x30C) + 1);
    }
    temp_17 = M2C_FIELD(arg0, void **, 0x1FC);
    if (temp_17 != NULL) {
        temp_19 = M2C_FIELD(temp_17, s16 *, 0xAA);
        if ((temp_19 == 0x107C) && ((M2C_FIELD(arg0, s32 *, 0x360) == 0) || (M2C_FIELD(arg0, s32 *, 0x2578) != temp_17))) {
            temp_2_61 = func_L39_0061D7B0(temp_17);
            temp_f20 = fabsf(M2C_FIELD(temp_2_61, f32 *, 0x310));
            if (temp_f20 > 0.10000001f) {
                M2C_ERROR(/* unknown instruction: vsub.xyz $vf2, $vf2, $vf1 * /);
                func_003C5060(temp_17, sp, sp, 0);
                sp0 = 0;
                var_f1 = 0x3F800000;
                if (M2C_BITWISE(f32, sp4) < M2C_BITWISE(f32, sp0)) {
                    var_f1 = 0xBF800000;
                }
                sp4 = var_f1;
                sp8 = sp0;
                func_0038D000(sp, sp, temp_17 + 0xC0);
                func_0038CF68(sp, sp, 0x3E4CCCCE);
                sp8 = 0x3DA3D70B;
                temp_2_62 = M2C_FIELD(temp_2_61, void **, 0x2D8);
                var_12 = 0;
                if (temp_2_62 != NULL) {
                    var_12 = M2C_FIELD(temp_2_62, s32 *, 0x2524);
                }
                if ((M2C_FIELD(arg0, s32 *, 0x2D0) >= 9) && ((temp_2_63 = M2C_FIELD(arg0, void **, 0x2CC), (temp_2_63 == NULL)) || (M2C_FIELD(temp_2_63, s16 *, 0xAA) != temp_19))) {
                    if (M2C_FIELD(temp_2_61, f32 *, 0x310) > 0.34000003f) {
                        if (M2C_FIELD(arg0, u8 *, 0x313) == 0) {
                            temp_2_64 = D_L39_004997E0 + 1;
                            D_L39_004997E0 = temp_2_64;
                            M2C_FIELD(arg0, u8 *, 0x313) = temp_2_64;
                        } else {
                            temp_4_34 = M2C_FIELD(arg0, u8 *, 0x313);
                            M2C_FIELD(arg0, u8 *, 0x313) = (u8) D_L39_004997E1;
                            D_L39_004997E1 = temp_4_34;
                        }
                        sp14 = 0x3E8;
                        temp_10 = (var_23 - *var_23) & 7;
                        temp_11 = arg0 + 0x1D0;
                        temp_2_65 = *((((u32) ((s32) var_23 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
                        sp14 = (((s32) sp14 & 0xFFFF) | ((s32) sp14 << 0x10)) ^ temp_2_65;
                        sp10 = (s32) var_23 ^ temp_2_65;
                        (&D_L39_004997E0)[*var_23 + 1 + ((temp_10 & 7) * 0xFF)] = sp10;
                        func_L01_00446A70(M2C_FIELD(arg0, s32 *, 0x2524), var_12, 8, temp_11, sp, 4e-45f, temp_10, temp_11, 0x41A00000);
                    } else {
                        goto block_176;
                    }
                } else {
block_176:
                    var_f1_2 = temp_f20 / 0.34000003f;
                    if (var_f1_2 > 1.0f) {
                        var_f1_2 = 1.0f;
                    }
                    func_L01_00446A70(M2C_FIELD(arg0, s32 *, 0x2524), var_12, 1, arg0 + 0x1D0, sp, (var_f1_2 * 4.0f) + 2.0f);
                }
            }
        }
    }
    if ((M2C_FIELD(arg0, u8 *, 0x1A06) == 1) && (func_L39_00648840(arg0, 0xB) == 0)) {
        func_L39_00648960(arg0, 0xB);
    }
    if (M2C_FIELD(arg0, u8 *, 0x1A06) != 0) {
        if (M2C_FIELD(arg0, u8 *, 0x19E6) == 0) {
            var_3_3 = 0;
        } else {
            temp_3_36 = M2C_FIELD(arg0, u8 *, 0x19E6);
            *sp = (&D_L39_004997E0)[temp_3_36 + 1 + (((sp28 - temp_3_36) & 7 & 7) * 0xFF)];
            temp_2_66 = sp0 ^ (s32) sp28;
            var_3_3 = sp4 ^ temp_2_66;
            sp0 = temp_2_66;
            sp4 = var_3_3;
        }
        if ((var_3_3 == 0) && (M2C_FIELD(arg0, s32 *, 0x2D0) != 0) && (M2C_FIELD(arg0, f32 *, 0x1A0) < 0.002f) && (M2C_FIELD(arg0, f32 *, 0x1B4) < 0.002f)) {

        }
    }
    if (M2C_FIELD(arg0, s16 *, 0x3E4) == 0) {
        if (M2C_FIELD(arg0, s32 *, 0x1310) != 1) {
            goto block_206;
        }
        if (func_L01_004606E8(0x28, 2, 0, M2C_FIELD(arg0, s32 *, 0x2534)) == 0) {
            goto block_206;
        }
        if (func_L39_006212E8(arg0) == 0xA) {
            goto block_206;
        }
        goto block_200;
    }
block_200:
    temp_9_3 = arg0 + 0x19E4;
    var_3_4 = 0;
    if (M2C_FIELD(arg0, u8 *, 0x19E4) != 0) {
        temp_3_37 = M2C_FIELD(arg0, u8 *, 0x19E4);
        *sp = (&D_L39_004997E0)[temp_3_37 + 1 + (((temp_9_3 - temp_3_37) & 7 & 7) * 0xFF)];
        temp_2_67 = sp0 ^ (s32) temp_9_3;
        var_3_4 = sp4 ^ temp_2_67;
        sp0 = temp_2_67;
        sp4 = var_3_4;
    }
    if ((var_3_4 ^ 0x10) == 0) {
block_206:
        M2C_FIELD(arg0, s32 *, 0x324) = (s32) (M2C_FIELD(arg0, s32 *, 0x324) + 1);
    } else {
        M2C_FIELD(arg0, s32 *, 0x324) = 0;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x2DE) != 0) && (func_L39_00632678(arg0, arg0 + 0x120) < 0.0f)) {
        if (M2C_FIELD(arg0, s32 *, 0x234C) == 0x20) {
            var_8_2 = 0;
loop_211:
            temp_2_68 = M2C_FIELD(arg0, s32 *, 0x2348) - var_8_2;
            temp_6_2 = temp_2_68 + 0x1F;
            temp_7_2 = temp_2_68 + 0x1E;
            M2C_ERROR(/* unknown instruction: vsub.xyz $vf2, $vf2, $vf1 * /);
            var_8_2 += 1;
            M2C_ERROR(/* unknown instruction: vadd.xyz $vf1, $vf1, $vf2 * /);
            if (var_8_2 < 8) {
                goto loop_211;
            }
            func_0038CE20(sp, sp, temp_6_2, temp_7_2, var_8_2, -1, 1.0f / (f32) 8);
            if (func_0038CEA8(sp) < 0.020000001f) {
                M2C_FIELD(arg0, u16 *, 0x330) = (u16) (M2C_FIELD(arg0, u16 *, 0x330) + 1);
            } else {
                goto block_216;
            }
        }
    } else {
block_216:
        M2C_FIELD(arg0, u16 *, 0x330) = 0U;
    }
    func_L39_00629958(arg0);
    func_L39_00632180(arg0, sp64, 1, 0, 0, 0x3F333333);
    if (M2C_FIELD(arg0, f32 *, 0xA8) < 1.0f) {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), M2C_UNK (**)(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK), 0x34)(arg0, 0x76, 1, 0, 1);
        func_L39_00628038(arg0, 0);
    }
}


#endif
