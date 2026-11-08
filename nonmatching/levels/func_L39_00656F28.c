/* func_L39_00656F28: Opus handoff (prep by Sonnet worker w7, 2026-11-08)
   Size: 24952 bytes, places: 15 levels (39 40 41 42 43 44 45 46 47 48 49 50 51 52 53), file: src/levels/shared/L39_00656DB0.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division
   Step 0: ONE function (prologue addiu sp,-0xA0, saves s0-s7/fp/ra/f20/f21, one jr $ra at 0x65D098), a single multiplayer-game state machine: prologue/epilogue change detector, then switch(Dec(s+0x19E4)) via jtbl_0047B090 (0x91 = 145 entries) at 0x65776C. The table has only 31 DISTINCT targets (case value(s) in hex after the colon): 0065778C:0 00657F04:39,69,7F,81 00657F58:7E 00657F64:90 00658390:14 00658670:13,15 00658B00:85 00658CA4:79 00658CC4:2,2E,72 006592C8:7D 00659670:64 0065970C:65 0065972C:66 006597BC:7A 006597F0:6F 00659834:3 00659A98:4 00659D84:2B 00659DF0:17 00659E24:18 0065A17C:19,1A 0065A3EC:78 0065A470:6,2C 0065ACF8:76 0065AD1C:7,9,A,B,C,D,E,F,10,11,12,1B,38,68,70,83 0065C984:16 0065CAC4:8E 0065CB10:1,1D 0065CE14:1F 0065CE60:22 0065CF40:5,8,1C,1E,20,21,23,24,25,26,27,28,29,2A,2D,2F,30,31,32,33,34,35,36,37,3A,3B,3C,3D,3E,3F,40,41,42,43,44,45,46,47,48,49,4A,4B,4C,4D,4E,4F,50,51,52,53,54,55,56,57,58,59,5A,5B,5C,5D,5E,5F,60,61,62,63,67,6A,6B,6C,6D,6E,71,73,74,75,77,7B,7C,80,82,84,86,87,88,89,8A,8B,8C,8D,8F. 16+ states share 0065AD1C and ~95 share 0065CF40 (= the epilogue/default), so the real body is about 29 distinct blocks, not 145..
   Twin: none. rac2 best func_L07_002C3CC0 0.34 (index), callfp: 1 callee mapped; corpus: rac3:func_L39_00624658 0.21, func_L39_00648C20 0.19. Multiplayer-menu code with no rac2 equivalent (rac2 has no such obfuscated-variable system).
   Mapping: Anti-tamper 'obfuscated variable': 72 inline reads of the 8-byte table D_L39_004997E0 (u8[8*255]); the prior API job's `Dec_00656F28`/`DecF_00656F28` (rac3-api/jobs/func_L39_00656F28/func.c) reproduces the loop body instruction for instruction. The draft below is that job's func.c: it covers the prologue, the first ~700 insns and the epilogue and compiles; the rest is a TODO. s+0x19E4 = state (obfuscated u8 key -> value), s+0x19E5/0x19E6 other obfuscated bytes, s+0x14 -> vtable with f34(s, newstate, 1, 0, 1) = 'change state' (retail 0x65CEE4: a2=1; a3=0; t0=1; jalr), s+0x2524 -> player object (+0x43 compared in the epilogue), s+0x2476 = obfuscated f32.
   Identical / changed / added / removed: n/a. Retail case blocks start at the 31 addresses above; many end with the common change-state call at 0065CEE4 and `b tail`. m2c's output for the body is fenced in #if 0 below (it recovers the switch and the 31 blocks but not the decoder as a helper: the 72 decoder expansions are inline and make the m2c text huge; replace each by a Dec() call).
   VU0: 3 vadd.xyz/vsub.xyz ops in the retail asm; inline-asm VU0 is banned since 2026-11-06 (Matching-Patterns), so this function cannot reach MATCH unless the ops come from plain C; the lq/sq copies are fine (u128_t).
   Draft: compiles (prefix of the previous API job (prologue + first ~700 insns + epilogue, compiles); body = m2c text in #if 0); 5949 diff; opcode-equal 447 of 6239 (mine 606), ratio 0.13.
     Retail rows yours=606 retail=6239 equalrows=290.
   Left for Opus:
     1. Replace the m2c decoder expansions with Dec_00656F28() calls (regex-able: `*sp = T[...]; sp0 ^ ...; var = sp4 ^ ...` is always one Dec).
     2. Then fill the 29 distinct case blocks from the #if 0 text into the switch in the prefix; many blocks end `set_state(...)` through the vtable and jump to `tail`.
     3. Retail spills the first two Dec results to 0x38($sp)/0x3C($sp), the draft keeps them in s-regs (the prior job's observation): will likely resolve itself in the full function.
     4. Mind the inlined decoder preheader order (lui; addiu table; move a3,sp; addiu t2,n,1; move a2,0; subu v0,p,n; andi).
     5. 3 VU0 ops (418AA0, 418B9C, 41A2A8 file offsets): near miss only.
*/
typedef struct Game_00656F28 Game_00656F28;

extern u8 D_L39_004997E0[];
extern s32 func_L39_00626D38(void *, s32);
extern void func_L32_004F8B00(void *);
extern s32 func_L39_0065D0A0(void *);
extern s32 func_L39_0065F1A8(void *);

/* obfuscated value reader: 8 bytes scattered in a table, xored with the address */
static __inline__ u32 Dec_00656F28(u8 *p)
{
    u32 w[2];
    u8 *b = (u8 *)w;
    s32 k;
    s32 n = *p;
    u32 h;
    s32 n1;
    if (n == 0) {
        return 0;
    }
    h = ((u32)p - n) & 7;
    n1 = n + 1;
    for (k = 0; k < 40; k += 5) {
        *b++ = D_L39_004997E0[n1 + ((h + k) & 7) * 255];
    }
    w[0] ^= (u32)p;
    w[1] ^= w[0];
    return w[1];
}

static __inline__ f32 DecF_00656F28(u8 *p)
{
    u32 w[2];
    u8 *b = (u8 *)w;
    s32 k;
    s32 n = *p;
    u32 h;
    s32 n1;
    if (n == 0) {
        return 0.0f;
    }
    h = ((u32)p - n) & 7;
    n1 = n + 1;
    for (k = 0; k < 40; k += 5) {
        *b++ = D_L39_004997E0[n1 + ((h + k) & 7) * 255];
    }
    w[0] ^= (u32)p;
    w[1] ^= w[0];
    return *(f32 *)&w[1];
}

typedef struct VT_00656F28 {
    u8 pad[0x34];
    void (*f34)(void *, s32, s32, s32, s32);
} VT_00656F28;

extern void func_00393348(s32, s32, void *, void *, void *, s32, s32);
extern void func_L39_00675830(void);
extern void func_L39_00675908(void);
extern void func_L39_006761D0(void);
extern void func_L39_0063D0F8(void *);
extern void func_L39_0063D2A8(void *);
extern void func_L39_0063A0F0(void *);
extern s32 D_001E0434;
extern f32 D_L39_0024BC30[];
extern u8 D_L39_004840A0[];

void func_L39_00656F28(u8 *s)
{
    u32 a, b;
    u8 fp;
    f32 f;
    u8 *s23 = *(u8 **)(s + 0x2524);
    u32 st;
    u8 *o;
    s32 flag;

    a = Dec_00656F28(s + 0x19E6);
    b = Dec_00656F28(s + 0x19E5);
    fp = s23[0x43];
    if (func_L39_00626D38(s, 1) != 0) {
        goto tail;
    }
    func_L32_004F8B00(s);
    f = DecF_00656F28(s + 0x2476);
    if (f <= 0.0f) {
        st = Dec_00656F28(s + 0x19E4);
        if (st == 0 || (st = Dec_00656F28(s + 0x19E4)) == 2 ||
            (st = Dec_00656F28(s + 0x19E4)) == 0x7D) {
            (*(VT_00656F28 **)(s + 0x14))->f34(s, 0x39, 1, 0, 1);
            goto tail;
        }
    }
    if (func_L39_0065D0A0(s) != 0) {
        goto tail;
    }
    if (func_L39_0065F1A8(s) != 0) {
        goto tail;
    }
    o = *(u8 **)(s + 0x2534);
    if ((*(u32 *)(o + 0x1A4) & 0x10) || (*(u32 *)(o + 0x1C4) & 0x10)) {
        if (s[0x46C] != 2 &&
            *(s32 *)(D_L39_004840A0 + *(s32 *)(s + 0x2544) * 0x1C) == 0 &&
            D_001E0434 >= 8) {
            flag = 0;
            st = Dec_00656F28(s + 0x19E4);
            if (st == 1 || (st = Dec_00656F28(s + 0x19E4)) == 0x1D ||
                s[0x24FE] != 0 || s[0x2500] != 0) {
                flag = 1;
            }
            if (!flag) {
                st = Dec_00656F28(s + 0x19E6);
                if (st != 0x14 && s[0x1A13] == 0 &&
                    !(s[0x1A0C] != 0 && *(s16 *)(s + 0x30A) == 0) &&
                    !(s[0x1A0E] != 0 && *(s16 *)(s + 0x30A) == 0)) {
                    *(s16 *)(s + 0x24A4) = *(s16 *)(s + 0x24A8) ? 0x16 : 0xC;
                    func_00393348((s[0x24C9] + 8) | 0x20, 0, func_L39_00675830,
                                  func_L39_00675908, func_L39_006761D0, 0, 0);
                    *(s32 *)(s + 0x2514) = 300;
                }
            }
        }
    }
    func_L39_0063D0F8(s);
    func_L39_0063D2A8(s);
    if (*(f32 *)(s + 0xA8) < D_L39_0024BC30[0] && 2.0f < *(f32 *)(s + 0x2AC) &&
        s[0x1A15] == 0) {
        st = Dec_00656F28(s + 0x19E4);
        if (st != 0x76 && (st = Dec_00656F28(s + 0x19E4)) != 0x90) {
            (*(VT_00656F28 **)(s + 0x14))->f34(s, 0x76, 1, 0, 1);
            goto tail;
        }
    }
    st = Dec_00656F28(s + 0x19E4);
    if (st > 0x90) {
        goto tail;
    }
    /* TODO: switch (st) via jtbl_0047B090 (0x91 cases), 0x65778C..0x65CEE4:
       see RESULTS.md */
tail:
    if (a != Dec_00656F28(s + 0x19E6)) {
        func_L39_0063A0F0(s);
    }
    if (b != Dec_00656F28(s + 0x19E5)) {
        *(s32 *)(s + 0x2F8) = 0;
    }
    if (fp != s23[0x43]) {
        *(s32 *)(s + 0x2FC) = 0;
    }
}

/* m2c body of the whole function (cleaned by tools/post.py; does not compile: irregular switch labels, decoder expansions): */
#if 0
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38();
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_0038CB00(void *);
extern s32 func_003C4BB0(void *, f32);
extern s32 func_003D3CB0();
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L01_004FF5D8(void);
extern s32 func_L39_005C42E8(s32, s32);
extern s32 func_L39_00632D78(void *, s32, f32);
extern s32 func_L39_00648960(u8 *, u8 *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_00393348();
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_L39_00632558(void *, void *, void *, f32);
extern void func_L39_0063A030(u8 *a0, s32 a1, s32 a2);
f32 func_0038CE20();  /* K&R: prototype dropped, mismatch with m2c calls */
f32 func_0038DAB8();  /* K&R: prototype dropped, mismatch with m2c calls */
s32 func_19D500(u8);                            /* extern */
s32 func_L01_00412FE0(void *, s32 *, f32, s32); /* extern */
s32 func_L32_004F8B00(void *);                  /* extern */
f32 func_L32_004FD190(void *, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_L39_005C2F50(void *);                      /* extern */
f32 func_L39_005CF720(void *, s32 *, s32 *, void *, s32); /* extern */
s32 func_L39_006212E8(void *);                      /* extern */
s32 func_L39_00622288(void *);                  /* extern */
s16 func_L39_006223B0(void *, s32);             /* extern */
s32 func_L39_006233A8(void *, s32 *, void *, s32); /* extern */
s32 func_L39_00626D38(void *, s32, s32, void *, s32, s32, s32); /* extern */
f32 func_L39_00628038(void *, s32);             /* extern */
f32 func_L39_00628428(void *);                      /* extern */
s32 func_L39_00629DE0(void *);                      /* extern */
f32 func_L39_0062B4A8(void *, s16, s32, s32, f32); /* extern */
s32 func_L39_0062B718(void *);                  /* extern */
f32 func_L39_0062B728(void *, s32);             /* extern */
f32 func_L39_0062B740(void *, f32, f32, f32, s32); /* extern */
s32 func_L39_0062D7C8(void *, s32, s32);        /* extern */
f32 func_L39_0062DA30(void *);                      /* extern */
s32 func_L39_00632458(void *, void *, void *, s32 *, f32); /* extern */
f32 func_L39_00632678(void *, void *);              /* extern */
s32 func_L39_00632C48(void *, s32);             /* extern */
s32 func_L39_00634E58(void *, s32, s32, s32); /* extern */
f32 func_L39_00638848(void *);                      /* extern */
s32 func_L39_00638C28(void *);                      /* extern */
s32 func_L39_00638DF0(void *);                      /* extern */
s32 func_L39_00638F50(void *);                      /* extern */
f32 func_L39_0063A0F0(void *);                      /* extern */
s32 func_L39_0063A2E8(void *);                  /* extern */
s32 func_L39_0063A4E0(void *, u8, s32, s32, s32); /* extern */
s32 func_L39_0063B5E0(void *, s32);         /* extern */
f32 func_L39_0063BA40(void *);                      /* extern */
s32 func_L39_0063BE00(void *, s32);             /* extern */
s32 func_L39_0063C000(void *, s32, f32, s32); /* extern */
s16 func_L39_0063D0F0(void *, u8);                  /* extern */
s32 func_L39_0063D0F8(void *);                  /* extern */
f32 func_L39_0063D240(void *, s32);             /* extern */
s32 func_L39_0063D2A8(void *);                  /* extern */
s32 func_L39_006475C0(void *);                  /* extern */
f32 func_L39_00647FE0(void *, s32, s32, s32); /* extern */
s32 func_L39_00648840(void *, s32);             /* extern */
s32 func_L39_00656DB0(void *);                  /* extern */
s32 func_L39_0065D0A0(void *);                      /* extern */
s32 func_L39_0065F1A8(void *);                      /* extern */
extern s32 D_1A5810;
extern s32 D_L39_002429C0;
extern f32 D_L39_00246004;
extern f32 D_L39_00246010;
extern s32 D_L39_00246018;
extern s32 D_L39_0024B9C8;
extern f32 D_L39_0024BC30;
extern s32 D_L39_0047A8A8;
extern u8 D_L39_00480760;
extern u8 D_L39_00480761;
extern s32 D_L39_004840A0;
extern u8 D_L39_004997E0;
extern u8 D_L39_004997E1;
extern s32 D_L39_0049C890;
extern s32 func_L39_00675830;
extern s32 func_L39_00675908;
extern s32 func_L39_006761D0;

extern s32 D_001D5BCC;
extern void * D_001D5F30;
extern s8 D_001D6D98;
extern s32 D_L39_001E0434;
extern f32 D_L39_0047B090[];  /* rodata table m2c took for a jump table */

f32 func_L39_00656F28(void *arg0, s32 arg2, void *arg3, s32 arg5, s32 arg6) {
    s32 sp[8]; /* m2c: stack-slot base, size unknown */
    s32 sp0;                                        /* compiler-managed */
    u32 sp4;                                        /* compiler-managed */
    s32 sp10;
    s32 sp14;
    s32 sp20;
    s32 sp30;
    s32 sp34;
    u32 sp38;
    u32 sp3C;
    s32 *var_16_2;
    s32 *var_19;
    s32 var_5;
    s32 var_5_8;
    s32 var_6_2;
    s32 var_6_5;
    s32 var_f12_2;
    s32 var_f13;
    s32 var_4_2;
    f32 temp_3_8;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f1_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_ret_16;
    f32 temp_ret_24;
    f32 temp_ret_33;
    f32 var_f0;
    f32 var_f0_3;
    f32 var_f12;
    f32 var_f12_3;
    f32 var_f12_4;
    f32 var_f13_2;
    f32 var_f1;
    f32 var_f21;
    s16 temp_16;
    s16 temp_16_12;
    s16 temp_2_162;
    s16 temp_4;
    s16 temp_4_13;
    s16 temp_f1_2;
    s16 temp_ret_37;
    s16 var_2_10;
    s16 var_2_11;
    s16 var_2_3;
    s16 var_5_4;
    s32 *temp_4_17;
    s32 temp_11;
    s32 temp_16_10;
    s32 temp_16_11;
    s32 temp_16_4;
    s32 temp_16_5;
    s32 temp_16_9;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_2_101;
    s32 temp_2_103;
    s32 temp_2_105;
    s32 temp_2_108;
    s32 temp_2_10;
    s32 temp_2_110;
    s32 temp_2_112;
    s32 temp_2_115;
    s32 temp_2_118;
    s32 temp_2_120;
    s32 temp_2_123;
    s32 temp_2_125;
    s32 temp_2_127;
    s32 temp_2_129;
    s32 temp_2_12;
    s32 temp_2_131;
    s32 temp_2_133;
    s32 temp_2_137;
    s32 temp_2_139;
    s32 temp_2_141;
    s32 temp_2_143;
    s32 temp_2_145;
    s32 temp_2_147;
    s32 temp_2_149;
    s32 temp_2_14;
    s32 temp_2_151;
    s32 temp_2_153;
    s32 temp_2_155;
    s32 temp_2_157;
    s32 temp_2_159;
    s32 temp_2_161;
    s32 temp_2_165;
    s32 temp_2_167;
    s32 temp_2_16;
    s32 temp_2_18;
    s32 temp_2_20;
    s32 temp_2_22;
    s32 temp_2_23;
    s32 temp_2_25;
    s32 temp_2_27;
    s32 temp_2_29;
    s32 temp_2_2;
    s32 temp_2_31;
    s32 temp_2_33;
    s32 temp_2_35;
    s32 temp_2_45;
    s32 temp_2_48;
    s32 temp_2_4;
    s32 temp_2_50;
    s32 temp_2_53;
    s32 temp_2_55;
    s32 temp_2_57;
    s32 temp_2_58;
    s32 temp_2_60;
    s32 temp_2_62;
    s32 temp_2_65;
    s32 temp_2_67;
    s32 temp_2_69;
    s32 temp_2_6;
    s32 temp_2_71;
    s32 temp_2_76;
    s32 temp_2_78;
    s32 temp_2_80;
    s32 temp_2_82;
    s32 temp_2_84;
    s32 temp_2_86;
    s32 temp_2_88;
    s32 temp_2_8;
    s32 temp_2_90;
    s32 temp_2_92;
    s32 temp_2_94;
    s32 temp_2_96;
    s32 temp_2_97;
    s32 temp_2_99;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_13;
    s32 temp_3_14;
    s32 temp_3_15;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_7;
    s32 temp_3_9;
    s32 temp_4_14;
    s32 temp_f1;
    s32 temp_ret;
    s32 temp_ret_10;
    s32 temp_ret_11;
    s32 temp_ret_12;
    s32 temp_ret_13;
    s32 temp_ret_14;
    s32 temp_ret_15;
    s32 temp_ret_17;
    s32 temp_ret_18;
    s32 temp_ret_19;
    s32 temp_ret_20;
    s32 temp_ret_21;
    s32 temp_ret_22;
    s32 temp_ret_23;
    s32 temp_ret_25;
    s32 temp_ret_26;
    s32 temp_ret_27;
    s32 temp_ret_28;
    s32 temp_ret_29;
    s32 temp_ret_2;
    s32 temp_ret_30;
    s32 temp_ret_31;
    s32 temp_ret_32;
    s32 temp_ret_34;
    s32 temp_ret_35;
    s32 temp_ret_36;
    s32 temp_ret_38;
    s32 temp_ret_3;
    s32 temp_ret_4;
    s32 temp_ret_5;
    s32 temp_ret_6;
    s32 temp_ret_7;
    s32 temp_ret_8;
    s32 temp_ret_9;
    s32 var_10;
    s32 var_12;
    s32 var_12_3;
    s32 var_16;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_19_2;
    s32 var_2;
    s32 var_2_12;
    s32 var_2_13;
    s32 var_2_14;
    s32 var_2_2;
    s32 var_2_5;
    s32 var_2_9;
    s32 var_3_29;
    s32 var_4;
    s32 var_5_3;
    s32 var_5_9;
    s32 var_6;
    s32 var_6_4;
    s32 var_9;
    u16 temp_2_51;
    u16 var_2_6;
    u16 var_2_7;
    u16 var_2_8;
    u32 temp_2_135;
    u32 temp_2_38;
    u32 temp_2_40;
    u32 temp_2_42;
    u32 temp_2_73;
    u32 temp_3;
    u32 temp_3_2;
    u32 temp_4_16;
    u32 temp_4_3;
    u32 temp_4_4;
    u32 temp_4_5;
    u32 temp_4_9;
    u32 temp_6;
    u32 var_3;
    u32 var_3_10;
    u32 var_3_11;
    u32 var_3_12;
    u32 var_3_13;
    u32 var_3_14;
    u32 var_3_15;
    u32 var_3_16;
    u32 var_3_17;
    u32 var_3_18;
    u32 var_3_19;
    u32 var_3_20;
    u32 var_3_21;
    u32 var_3_22;
    u32 var_3_23;
    u32 var_3_24;
    u32 var_3_25;
    u32 var_3_26;
    u32 var_3_27;
    u32 var_3_28;
    u32 var_3_2;
    u32 var_3_30;
    u32 var_3_31;
    u32 var_3_32;
    u32 var_3_33;
    u32 var_3_34;
    u32 var_3_35;
    u32 var_3_36;
    u32 var_3_37;
    u32 var_3_38;
    u32 var_3_39;
    u32 var_3_3;
    u32 var_3_40;
    u32 var_3_41;
    u32 var_3_42;
    u32 var_3_43;
    u32 var_3_44;
    u32 var_3_45;
    u32 var_3_46;
    u32 var_3_47;
    u32 var_3_48;
    u32 var_3_49;
    u32 var_3_4;
    u32 var_3_50;
    u32 var_3_51;
    u32 var_3_52;
    u32 var_3_53;
    u32 var_3_54;
    u32 var_3_55;
    u32 var_3_56;
    u32 var_3_57;
    u32 var_3_58;
    u32 var_3_59;
    u32 var_3_5;
    u32 var_3_60;
    u32 var_3_61;
    u32 var_3_62;
    u32 var_3_6;
    u32 var_3_7;
    u32 var_3_8;
    u32 var_3_9;
    u32 var_4_3;
    u32 var_4_4;
    u32 var_f0_2;
    u32 var_f0_4;
    u32 var_f0_5;
    u8 *var_12_2;
    u8 *var_17;
    u8 *var_22;
    u8 *var_5_2;
    u8 *var_5_5;
    u8 *var_5_6;
    u8 *var_5_7;
    u8 temp_16_2;
    u8 temp_2;
    u8 temp_2_100;
    u8 temp_2_102;
    u8 temp_2_104;
    u8 temp_2_106;
    u8 temp_2_107;
    u8 temp_2_109;
    u8 temp_2_111;
    u8 temp_2_113;
    u8 temp_2_114;
    u8 temp_2_116;
    u8 temp_2_117;
    u8 temp_2_119;
    u8 temp_2_11;
    u8 temp_2_121;
    u8 temp_2_122;
    u8 temp_2_124;
    u8 temp_2_126;
    u8 temp_2_128;
    u8 temp_2_130;
    u8 temp_2_132;
    u8 temp_2_134;
    u8 temp_2_136;
    u8 temp_2_138;
    u8 temp_2_13;
    u8 temp_2_140;
    u8 temp_2_142;
    u8 temp_2_144;
    u8 temp_2_146;
    u8 temp_2_148;
    u8 temp_2_150;
    u8 temp_2_152;
    u8 temp_2_154;
    u8 temp_2_156;
    u8 temp_2_158;
    u8 temp_2_15;
    u8 temp_2_160;
    u8 temp_2_163;
    u8 temp_2_164;
    u8 temp_2_166;
    u8 temp_2_17;
    u8 temp_2_19;
    u8 temp_2_21;
    u8 temp_2_24;
    u8 temp_2_26;
    u8 temp_2_28;
    u8 temp_2_30;
    u8 temp_2_32;
    u8 temp_2_34;
    u8 temp_2_37;
    u8 temp_2_39;
    u8 temp_2_3;
    u8 temp_2_41;
    u8 temp_2_43;
    u8 temp_2_44;
    u8 temp_2_46;
    u8 temp_2_47;
    u8 temp_2_49;
    u8 temp_2_52;
    u8 temp_2_54;
    u8 temp_2_56;
    u8 temp_2_59;
    u8 temp_2_5;
    u8 temp_2_61;
    u8 temp_2_63;
    u8 temp_2_64;
    u8 temp_2_66;
    u8 temp_2_68;
    u8 temp_2_70;
    u8 temp_2_72;
    u8 temp_2_74;
    u8 temp_2_75;
    u8 temp_2_77;
    u8 temp_2_79;
    u8 temp_2_7;
    u8 temp_2_81;
    u8 temp_2_83;
    u8 temp_2_85;
    u8 temp_2_87;
    u8 temp_2_89;
    u8 temp_2_91;
    u8 temp_2_93;
    u8 temp_2_95;
    u8 temp_2_98;
    u8 temp_2_9;
    u8 temp_3_12;
    u8 temp_3_16;
    u8 temp_3_6;
    u8 temp_4_10;
    u8 temp_4_12;
    u8 temp_4_15;
    u8 temp_4_6;
    u8 temp_4_7;
    u8 temp_5;
    u8 temp_fp;
    u8 var_6_3;
    u8 *temp_10;
    u8 *temp_11_10;
    u8 *temp_11_11;
    u8 *temp_11_12;
    u8 *temp_11_13;
    u8 *temp_11_14;
    u8 *temp_11_2;
    u8 *temp_11_3;
    u8 *temp_11_4;
    u8 *temp_11_5;
    u8 *temp_11_6;
    u8 *temp_11_7;
    u8 *temp_11_8;
    u8 *temp_11_9;
    u8 *temp_16_3;
    u8 *temp_16_6;
    u8 *temp_16_7;
    u8 *temp_16_8;
    u8 *temp_19;
    u8 *temp_19_2;
    u8 *temp_23;
    u8 *temp_2_36;
    u8 *temp_3_3;
    u8 *temp_4_11;
    u8 *temp_4_18;
    u8 *temp_4_2;
    u8 *temp_4_8;
    u8 *var_11;
    u8 *var_2_4;
    u8 *var_7;

    var_6 = arg2;
    var_7 = arg3;
    var_9 = arg5;
    var_10 = arg6;
    temp_11 = arg0 + 0x19E6;
    temp_2 = (*(u8 *)((u8 *)(arg0) + 0x19E6));
    temp_23 = (*(void **)((u8 *)(arg0) + 0x2524));
    if (temp_2 == 0) {
        sp38 = 0;
        var_22 = arg0 + 0x19E5;
    } else {
        var_10 = temp_2 + 1;
        var_22 = arg0 + 0x19E5;
        var_9 = (temp_11 - temp_2) & 7;
        var_6 = 5;
        *sp = (u8) (&D_L39_004997E0)[var_10 + ((var_9 & 7) * 0xFF)];
        var_7 = sp + 1;
        temp_2_2 = sp0 ^ temp_11;
        temp_3 = sp4 ^ temp_2_2;
        sp0 = temp_2_2;
        sp4 = temp_3;
        sp38 = temp_3;
    }
    temp_2_3 = (*(u8 *)((u8 *)(arg0) + 0x19E5));
    if (temp_2_3 == 0) {
        sp3C = 0;
    } else {
        var_10 = temp_2_3 + 1;
        var_9 = (var_22 - temp_2_3) & 7;
        var_6 = 5;
        *sp = (u8) (&D_L39_004997E0)[var_10 + ((var_9 & 7) * 0xFF)];
        var_7 = sp + 1;
        temp_2_4 = sp0 ^ (s32) var_22;
        temp_3_2 = sp4 ^ temp_2_4;
        sp0 = temp_2_4;
        sp4 = temp_3_2;
        sp3C = temp_3_2;
    }
    temp_fp = (*(u8 *)((u8 *)(temp_23) + 0x43));
    temp_ret = func_L39_00626D38(arg0, 1, var_6, var_7, var_9, var_10, temp_11);
    var_f0 = (f32)(temp_ret);
    if (temp_ret == 0) {
        func_L32_004F8B00(arg0);
        temp_11_2 = arg0 + 0x2476;
        temp_2_5 = (*(u8 *)((u8 *)(arg0) + 0x2476));
        if (temp_2_5 == 0) {
            var_f0_2 = 0;
        } else {
            *sp = (u8) (&D_L39_004997E0)[temp_2_5 + 1 + (((temp_11_2 - temp_2_5) & 7 & 7) * 0xFF)];
            temp_2_6 = sp0 ^ (s32) temp_11_2;
            sp0 = temp_2_6;
            sp4 ^= temp_2_6;
            var_f0_2 = sp4;
        }
        var_2 = 1;
        if (!((f32)(var_f0_2) <= 0.0f)) {
            var_2 = 0;
        }
        temp_11_3 = arg0 + 0x19E4;
        if (var_2 & 0xFF) {
            temp_2_7 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
            if (temp_2_7 == 0) {
                var_3 = 0;
            } else {
                *sp = (u8) (&D_L39_004997E0)[temp_2_7 + 1 + (((temp_11_3 - temp_2_7) & 7 & 7) * 0xFF)];
                temp_2_8 = sp0 ^ (s32) temp_11_3;
                var_3 = sp4 ^ temp_2_8;
                sp0 = temp_2_8;
                sp4 = var_3;
            }
            if (var_3 != 0) {
                temp_2_9 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                if (temp_2_9 == 0) {
                    var_3_2 = 0;
                } else {
                    *sp = (u8) (&D_L39_004997E0)[temp_2_9 + 1 + (((temp_11_3 - temp_2_9) & 7 & 7) * 0xFF)];
                    temp_2_10 = sp0 ^ (s32) temp_11_3;
                    var_3_2 = sp4 ^ temp_2_10;
                    sp0 = temp_2_10;
                    sp4 = var_3_2;
                }
                if ((var_3_2 ^ 2) != 0) {
                    temp_2_11 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                    if (temp_2_11 == 0) {
                        var_3_3 = 0;
                    } else {
                        *sp = (u8) (&D_L39_004997E0)[temp_2_11 + 1 + (((temp_11_3 - temp_2_11) & 7 & 7) * 0xFF)];
                        temp_2_12 = sp0 ^ (s32) temp_11_3;
                        var_3_3 = sp4 ^ temp_2_12;
                        sp0 = temp_2_12;
                        sp4 = var_3_3;
                    }
                    if ((var_3_3 ^ 0x7D) == 0) {
                        goto block_25;
                    }
                    goto block_26;
                }
                goto block_25;
            }
block_25:
            var_5 = 0x39;
            goto block_1027;
        }
block_26:
        temp_ret_2 = func_L39_0065D0A0(arg0);
        var_f0 = (f32)(temp_ret_2);
        if ((temp_ret_2 == 0) && (temp_ret_3 = func_L39_0065F1A8(arg0), var_f0 = (f32)(temp_ret_3), (temp_ret_3 == 0))) {
            temp_3_3 = (*(void **)((u8 *)(arg0) + 0x2534));
            if (((*(s32 *)((u8 *)(temp_3_3) + 0x1A4)) & 0x10) || (var_17 = arg0 + 0x19E4, (((*(s32 *)((u8 *)(temp_3_3) + 0x1C4)) & 0x10) != 0))) {
                var_17 = arg0 + 0x19E4;
                if (((*(u8 *)((u8 *)(arg0) + 0x46C)) != 2) && (*(((*(s32 *)((u8 *)(arg0) + 0x2544)) * 0x1C) + &D_L39_004840A0) == 0) && (D_L39_001E0434 >= 8)) {
                    temp_2_13 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                    if (temp_2_13 == 0) {
                        var_3_4 = 0;
                    } else {
                        *sp = (u8) (&D_L39_004997E0)[temp_2_13 + 1 + (((var_17 - temp_2_13) & 7 & 7) * 0xFF)];
                        temp_2_14 = sp0 ^ (s32) var_17;
                        var_3_4 = sp4 ^ temp_2_14;
                        sp0 = temp_2_14;
                        sp4 = var_3_4;
                    }
                    if ((var_3_4 ^ 1) != 0) {
                        temp_2_15 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                        if (temp_2_15 == 0) {
                            var_3_5 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_15 + 1 + (((var_17 - temp_2_15) & 7 & 7) * 0xFF)];
                            temp_2_16 = sp0 ^ (s32) var_17;
                            var_3_5 = sp4 ^ temp_2_16;
                            sp0 = temp_2_16;
                            sp4 = var_3_5;
                        }
                        if (((var_3_5 ^ 0x1D) == 0) || ((*(u8 *)((u8 *)(arg0) + 0x24FE)) != 0) || (var_2_2 = 0 & 0xFF, ((*(u8 *)((u8 *)(arg0) + 0x2500)) != 0))) {
                            goto block_43;
                        }
                    } else {
block_43:
                        var_2_2 = 1 & 0xFF;
                    }
                    temp_11_4 = arg0 + 0x19E6;
                    if (var_2_2 == 0) {
                        temp_2_17 = (*(u8 *)((u8 *)(arg0) + 0x19E6));
                        if (temp_2_17 == 0) {
                            var_3_6 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_17 + 1 + (((temp_11_4 - temp_2_17) & 7 & 7) * 0xFF)];
                            temp_2_18 = sp0 ^ (s32) temp_11_4;
                            var_3_6 = sp4 ^ temp_2_18;
                            sp0 = temp_2_18;
                            sp4 = var_3_6;
                        }
                        if (((var_3_6 ^ 0x14) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x1A13)) == 0) && (((*(u8 *)((u8 *)(arg0) + 0x1A0C)) == 0) || ((*(s16 *)((u8 *)(arg0) + 0x30A)) != 0)) && (((*(u8 *)((u8 *)(arg0) + 0x1A0E)) == 0) || ((*(s16 *)((u8 *)(arg0) + 0x30A)) != 0))) {
                            var_2_3 = 0x16;
                            if ((*(s16 *)((u8 *)(arg0) + 0x24A8)) == 0) {
                                var_2_3 = 0xC;
                            }
                            (*(s16 *)((u8 *)(arg0) + 0x24A4)) = var_2_3;
                            func_00393348();
                            (*(s32 *)((u8 *)(arg0) + 0x2514)) = 0x12C;
                        }
                    }
                }
            }
            func_L39_0063D0F8(arg0);
            func_L39_0063D2A8(arg0);
            var_f1 = (*(f32 *)((u8 *)(arg0) + 0xA8));
            var_f0 = D_L39_0024BC30;
            if (var_f1 < var_f0) {
                var_f1 = (*(f32 *)((u8 *)(arg0) + 0x2AC));
                var_f0 = 2.0f;
                if (var_f1 > 2.0f) {
                    temp_2_19 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                    if ((*(u8 *)((u8 *)(arg0) + 0x1A15)) == 0) {
                        if (temp_2_19 == 0) {
                            var_3_7 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_19 + 1 + (((var_17 - temp_2_19) & 7 & 7) * 0xFF)];
                            temp_2_20 = sp0 ^ (s32) var_17;
                            var_3_7 = sp4 ^ temp_2_20;
                            sp0 = temp_2_20;
                            sp4 = var_3_7;
                        }
                        temp_2_21 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                        if ((var_3_7 ^ 0x76) != 0) {
                            if (temp_2_21 == 0) {
                                var_3_8 = 0;
                            } else {
                                *sp = (u8) (&D_L39_004997E0)[temp_2_21 + 1 + (((var_17 - temp_2_21) & 7 & 7) * 0xFF)];
                                temp_2_22 = sp0 ^ (s32) var_17;
                                var_3_8 = sp4 ^ temp_2_22;
                                sp0 = temp_2_22;
                                sp4 = var_3_8;
                            }
                            if ((var_3_8 ^ 0x90) != 0) {
                                var_5 = 0x76;
                                goto block_1027;
                            }
                            goto block_69;
                        }
                        goto block_70;
                    }
                    goto block_70;
                }
            }
block_69:
block_70:
            if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                temp_2_23 = sp0 ^ (s32) var_17;
                var_3_9 = sp4 ^ temp_2_23;
                sp0 = temp_2_23;
                sp4 = var_3_9;
            } else {
                var_3_9 = 0;
            }
            if (var_3_9 < 0x91U) {
                var_4 = D_L39_0047B090[var_3_9];
                switch (var_3_9) {
                case 0x0:
                    if (((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(4, (*(s32 *)((u8 *)(arg0) + 0x2544)))) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) > 0) && ((var_5_2 = (u8 *)2, ((*(u8 *)((u8 *)((&D_1A5810 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) != 2)) || ((*(s32 *)((u8 *)(arg0) + 0x478)) == 3))) {
                        temp_11_5 = arg0 + 0x19E6;
                        if ((*(u8 *)((u8 *)(arg0) + 0x19E6)) == 0) {
                            var_3_10 = 0;
                        } else {
                            temp_2_24 = (*(u8 *)((u8 *)(arg0) + 0x19E6));
                            var_5_2 = &D_L39_004997E0;
                            *sp = (u8) (&D_L39_004997E0)[temp_2_24 + 1 + (((temp_11_5 - temp_2_24) & 7 & 7) * 0xFF)];
                            temp_2_25 = sp0 ^ (s32) temp_11_5;
                            var_3_10 = sp4 ^ temp_2_25;
                            sp0 = temp_2_25;
                            sp4 = var_3_10;
                        }
                        if (((var_3_10 ^ 0x14) != 0) && ((*(s32 (**)(void *, u8 *))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x44))(arg0, var_5_2) == 0)) {
                            var_5 = 1;
                            goto block_1027;
                        }
                        goto block_89;
                    }
block_89:
                    func_L39_0062B718(arg0);
                    (*(s8 *)((u8 *)(arg0) + 0x3E6)) = 0;
                    temp_16 = func_L39_0063D0F0(arg0, (*(u8 *)((u8 *)(temp_23) + 0x43)));
                    if (temp_16 != func_L39_006223B0(arg0, 0)) {
                        if ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) {
                            var_5_3 = 0;
                            if (((*(u8 *)((u8 *)(arg0) + 0x1A07)) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x1A05)) != 0) && (((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2524))) + 0x43)) == (*(s32 *)((u8 *)(arg0) + 0x2448))) || ((*(s32 *)((u8 *)(arg0) + 0x748)) != 0))) {
                                var_5_3 = 1;
                            }
                            if (var_5_3 == 0) {
                                (*(u8 *)((u8 *)(arg0) + 0x1A07)) = 0U;
                                func_L39_0062B4A8(arg0, func_L39_006223B0(arg0, 0), 0, 0, -2.0f);
                            }
                        }
                    }
                    if (((*(u8 *)((u8 *)(arg0) + 0x1A07)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x61C)) == 0) && ((*(u8 *)((u8 *)(arg0) + 0x1A05)) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x1A08)) == 0)) {
                        var_16 = -1;
                        if ((*(s32 *)((u8 *)(arg0) + 0x474)) == 2) {
                            var_16 = (*(s32 *)((u8 *)(arg0) + 0x478));
                        }
                        if (var_16 != (*(s32 *)((u8 *)(arg0) + 0x244C))) {
                            func_L39_00622288(arg0);
                        } else {
                            if (func_L39_00648AE0(arg0, var_16) != 0) {
                                var_2_4 = ((*(s8 *)((u8 *)(((var_16 << 7) + &D_L39_0049C890)) + 0x21)) << 7) + &D_L39_0049C890;
                            } else {
                                var_2_4 = (var_16 << 7) + &D_L39_0049C890;
                            }
                            temp_4 = (*(s16 *)((u8 *)(var_2_4) + 0xC));
                            if ((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2524))) + 0x43)) != temp_4) {
                                if ((*(s32 *)((u8 *)(arg0) + 0x748)) != 0) {
                                    (*(s32 *)((u8 *)(arg0) + 0x754)) = 1;
                                }
                                (*(s32 *)((u8 *)(arg0) + 0x2448)) = (s32) temp_4;
                                func_L39_0062B4A8(arg0, temp_4, 0, 0, -4.0f);
                            }
                        }
                    }
                    var_f0 = func_L39_00632D78(arg0, 0, 1.0f);
                    if ((*(u8 *)((u8 *)(arg0) + 0x378)) == 0) {
                        goto block_121;
                    }
                    if ((*(s16 *)((u8 *)(arg0) + 0x2DC)) != 0) {
block_121:
                        if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) < 4) {
                            goto block_133;
                        }
                        var_f0 = 0.4f;
                        if (!((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 0.4f)) {
block_133:
                            if ((*(s16 *)((u8 *)(arg0) + 0x320)) == 0) {
                                temp_11_6 = arg0 + 0x19E7;
                                temp_2_26 = (*(u8 *)((u8 *)(arg0) + 0x19E7));
                                var_12 = 1;
                                if (temp_2_26 == 0) {
                                    var_3_11 = 0;
                                } else {
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_26 + 1 + (((temp_11_6 - temp_2_26) & 7 & 7) * 0xFF)];
                                    temp_2_27 = sp0 ^ (s32) temp_11_6;
                                    var_3_11 = sp4 ^ temp_2_27;
                                    sp0 = temp_2_27;
                                    sp4 = var_3_11;
                                }
                                if ((var_3_11 ^ 1) != 0) {
                                    temp_2_28 = (*(u8 *)((u8 *)(arg0) + 0x19E7));
                                    if (temp_2_28 == 0) {
                                        var_3_12 = 0;
                                    } else {
                                        *sp = (u8) (&D_L39_004997E0)[temp_2_28 + 1 + (((temp_11_6 - temp_2_28) & 7 & 7) * 0xFF)];
                                        temp_2_29 = sp0 ^ (s32) temp_11_6;
                                        var_3_12 = sp4 ^ temp_2_29;
                                        sp0 = temp_2_29;
                                        sp4 = var_3_12;
                                    }
                                    if ((var_3_12 ^ 0x1D) == 0) {
                                        goto block_142;
                                    }
                                } else {
block_142:
                                    var_12 = ((*(s32 *)((u8 *)(arg0) + 0x2F0)) <= 3) ? 0 : 1;
                                }
                                if (var_12 != 0) {
                                    if ((*(s16 *)((u8 *)(arg0) + 0x2D8)) != 1) {
                                        temp_ret_4 = func_L39_0062D7C8(arg0, ((*(s16 *)((u8 *)(arg0) + 0x32C)) != 0) ? 1 : 6, 0);
                                        var_f0 = (f32)(temp_ret_4);
                                        if (temp_ret_4 == 0) {
                                            goto block_146;
                                        }
                                    } else {
                                        goto block_147;
                                    }
                                } else {
block_146:
                                    if ((*(s16 *)((u8 *)(arg0) + 0x2D8)) == 1) {
block_147:
                                        if (D_L39_002429C0 == 0) {
                                            if (func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 6, 0, (*(void **)((u8 *)(arg0) + 0x2534))) != 0) {
                                                var_5 = 0x70;
                                                goto block_1027;
                                            }
                                            goto block_150;
                                        }
                                        goto block_151;
                                    }
block_150:
block_151:
                                    temp_4_2 = (*(void **)((u8 *)(arg0) + 0x2534));
                                    if (((*(s32 *)((u8 *)(temp_4_2) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) && !(func_L39_005C2F50(temp_4_2) & 0x10) && ((*(s32 *)((u8 *)(arg0) + 0x2D0)) != 0) && (((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2524))) + 0x43)) != 0x1A) || !((*(f32 *)((u8 *)(arg0) + 0x628)) < 108.0f))) {
                                        var_5 = 4;
                                        goto block_1027;
                                    }
                                    if ((*(u8 *)((u8 *)(arg0) + 0x19E7)) != 0) {
                                        temp_2_30 = (*(u8 *)((u8 *)(arg0) + 0x19E7));
                                        *sp = (u8) (&D_L39_004997E0)[temp_2_30 + 1 + (((temp_11_6 - temp_2_30) & 7 & 7) * 0xFF)];
                                        temp_2_31 = sp0 ^ (s32) temp_11_6;
                                        var_3_13 = sp4 ^ temp_2_31;
                                        sp0 = temp_2_31;
                                        sp4 = var_3_13;
                                    } else {
                                        var_3_13 = 0;
                                    }
                                    if ((var_3_13 ^ 1) != 0) {
                                        temp_2_32 = (*(u8 *)((u8 *)(arg0) + 0x19E7));
                                        if (temp_2_32 == 0) {
                                            var_3_14 = 0;
                                        } else {
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_32 + 1 + (((temp_11_6 - temp_2_32) & 7 & 7) * 0xFF)];
                                            temp_2_33 = sp0 ^ (s32) temp_11_6;
                                            var_3_14 = sp4 ^ temp_2_33;
                                            sp0 = temp_2_33;
                                            sp4 = var_3_14;
                                        }
                                        if ((var_3_14 ^ 0x1D) == 0) {
                                            goto block_167;
                                        }
                                    } else {
block_167:
                                        if (((*(s32 *)((u8 *)(arg0) + 0x2F0)) < 0x14) && ((*(s16 *)((u8 *)(arg0) + 0x2D8)) != 1)) {
                                            func_L39_00632D78(arg0, 0, 1.0f);
                                        }
                                    }
                                    if ((func_L39_0063BE00(arg0, 0x3E32B8C2) != 0) || (var_f0 = 0.22f, ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.22f))) {
                                        temp_16_2 = (*(u8 *)((u8 *)(arg0) + 0x37B));
                                        func_L39_0063A4E0(arg0, temp_16_2, 0, 0, 0x1E);
                                        func_L39_0063A4E0(arg0, temp_16_2, 1, 0, 0x1E);
                                        var_5 = 2;
                                        goto block_1027;
                                    }
                                }
                            }
                        } else {
                            temp_2_34 = (*(u8 *)((u8 *)(arg0) + 0x19E7));
                            temp_11_7 = arg0 + 0x19E7;
                            if (temp_2_34 == 0) {
                                var_3_15 = 0;
                            } else {
                                *sp = (u8) (&D_L39_004997E0)[temp_2_34 + 1 + (((temp_11_7 - temp_2_34) & 7 & 7) * 0xFF)];
                                temp_2_35 = sp0 ^ (s32) temp_11_7;
                                var_3_15 = sp4 ^ temp_2_35;
                                sp0 = temp_2_35;
                                sp4 = var_3_15;
                            }
                            if (((var_3_15 ^ 8) != 0) || ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0xC)) {
                                var_5 = 6;
                                goto block_1027;
                            }
                        }
                    } else {
                        var_5 = 0x78;
block_1027:
                        var_6_2 = 1;
block_1028:
                        var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, var_5, var_6_2, 0, 1);
                    }
                    goto block_1031;
                case 0x39:
                case 0x69:
                case 0x7F:
                case 0x81:
                    if (((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) || ((*(u8 *)((u8 *)(arg0) + 0x1A0F)) != 0)) {
                        if ((*(s16 *)((u8 *)(arg0) + 0x344)) != 0) {
                            (*(f32 *)((u8 *)(arg0) + 0x610)) = 0.0f;
                            (*(u8 *)((u8 *)(arg0) + 0x1A0F)) = 1U;
                            var_f0 = func_0038CB00(arg0 + 0x344);
                        } else {
                            var_f0 = func_L39_00628038(arg0, 0);
                        }
                    } else {
                        goto block_1031;
                    }
                    break;
                case 0x7E:
                    var_2_5 = (*(s32 *)((u8 *)(arg0) + 0x2F0)) < 0xB8;
block_639:
                    if (var_2_5 == 0) {
block_641:
                        var_f0 = func_L39_00628038(arg0, 1);
                    } else {
                        goto block_1031;
                    }
                    break;
                case 0x90:
                    temp_2_36 = D_001D5F30;
                    if ((*(u8 *)((u8 *)(arg0) + 0x1A14)) != 0) {
                        var_12_2 = arg0 + 0x31C;
                        if ((temp_2_36 != 0) && ((*(s8 *)((u8 *)(temp_2_36) + 0x18F)) != 0) && (((s32) D_001D5BCC % 10) < 6)) {
                            temp_ret_5 = func_L39_00648840(arg0, 0x24);
                            var_f0 = (f32)(temp_ret_5);
                            var_12_2 = arg0 + 0x31C;
                            if (temp_ret_5 == 0) {
                                var_f0 = func_L39_00648960(arg0, 0x24);
                                var_12_2 = arg0 + 0x31C;
                            }
                        }
                        temp_2_37 = (*(u8 *)((u8 *)(arg0) + 0x31C));
                        if (temp_2_37 == 0) {
                            var_2_6 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_37 + 1 + (((var_12_2 - temp_2_37) & 7 & 7) * 0xFF)];
                            temp_3_4 = sp0 ^ (s32) var_12_2;
                            temp_2_38 = sp4 ^ temp_3_4;
                            sp0 = temp_3_4;
                            temp_4_3 = temp_2_38 >> 0x10;
                            sp4 = temp_4_3 / (u32) (((temp_2_38 ^ temp_4_3) << 0x10) + 1);
                            var_2_6 = (u16) sp4;
                        }
                        if ((var_2_6 << 0x10) == 0) {
                            if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A4)) & 0x40) {
                                func_L39_006475C0(arg0);
                                var_f0 = func_L39_00628428(arg0);
                            }
                        } else {
                            temp_2_39 = (*(u8 *)((u8 *)(arg0) + 0x31C));
                            if (temp_2_39 == 0) {
                                var_2_7 = 0;
                            } else {
                                *sp = (u8) (&D_L39_004997E0)[temp_2_39 + 1 + (((var_12_2 - temp_2_39) & 7 & 7) * 0xFF)];
                                temp_3_5 = sp0 ^ (s32) var_12_2;
                                temp_2_40 = sp4 ^ temp_3_5;
                                sp0 = temp_3_5;
                                temp_4_4 = temp_2_40 >> 0x10;
                                sp4 = temp_4_4 / (u32) (((temp_2_40 ^ temp_4_4) << 0x10) + 1);
                                var_2_7 = (u16) sp4;
                            }
                            temp_2_41 = (*(u8 *)((u8 *)(arg0) + 0x31C));
                            if ((var_2_7 << 0x10) > 0) {
                                if (temp_2_41 != 0) {
                                    temp_3_6 = (*(u8 *)((u8 *)(arg0) + 0x31C));
                                    *sp = (u8) (&D_L39_004997E0)[temp_3_6 + 1 + (((var_12_2 - temp_3_6) & 7 & 7) * 0xFF)];
                                    temp_3_7 = sp0 ^ (s32) var_12_2;
                                    temp_2_42 = sp4 ^ temp_3_7;
                                    sp0 = temp_3_7;
                                    temp_4_5 = temp_2_42 >> 0x10;
                                    sp4 = temp_4_5 / (u32) (((temp_2_42 ^ temp_4_5) << 0x10) + 1);
                                    var_2_8 = (u16) sp4;
                                } else {
                                    var_2_8 = 0;
                                }
                                if (*var_12_2 == 0) {
                                    temp_2_43 = D_L39_004997E0 + 1;
                                    D_L39_004997E0 = temp_2_43;
                                    *var_12_2 = temp_2_43;
                                } else {
                                    temp_4_6 = *var_12_2;
                                    *var_12_2 = D_L39_004997E1;
                                    D_L39_004997E1 = temp_4_6;
                                }
                                sp4 = (s16) ((s32) ((var_2_8 << 0x10) + 0xFFFF0000) >> 0x10);
                                temp_2_44 = *var_12_2;
                                temp_2_45 = *((((u32) ((s32) var_12_2 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
                                sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_45;
                                sp0 = (s32) var_12_2 ^ temp_2_45;
                                (&D_L39_004997E0)[temp_2_44 + 1 + (((var_12_2 - temp_2_44) & 7 & 7) * 0xFF)] = *sp;
                            } else {
                                if (temp_2_41 == 0) {
                                    temp_2_46 = D_L39_004997E0 + 1;
                                    D_L39_004997E0 = temp_2_46;
                                    (*(u8 *)((u8 *)(arg0) + 0x31C)) = temp_2_46;
                                } else {
                                    temp_4_7 = (*(u8 *)((u8 *)(arg0) + 0x31C));
                                    (*(u8 *)((u8 *)(arg0) + 0x31C)) = (u8) D_L39_004997E1;
                                    D_L39_004997E1 = temp_4_7;
                                }
                                sp4 = 0;
                                temp_2_47 = *var_12_2;
                                temp_2_48 = *((((u32) ((s32) var_12_2 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
                                sp4 = (((s32) sp4 & 0xFFFF) | ((s32) sp4 << 0x10)) ^ temp_2_48;
                                sp0 = (s32) var_12_2 ^ temp_2_48;
                                (&D_L39_004997E0)[temp_2_47 + 1 + (((var_12_2 - temp_2_47) & 7 & 7) * 0xFF)] = *sp;
                            }
                        }
                    }
                    break;
                case 0x14:
                    temp_2_49 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                    if (temp_2_49 == 0) {
                        var_3_16 = 0;
                        var_16_2 = (s32 *)0x480000;
                    } else {
                        var_16_2 = &D_L39_0047A8A8;
                        *sp = (u8) (&D_L39_004997E0)[temp_2_49 + 1 + (((var_17 - temp_2_49) & 7 & 7) * 0xFF)];
                        temp_2_50 = sp0 ^ (s32) var_17;
                        var_3_16 = sp4 ^ temp_2_50;
                        sp0 = temp_2_50;
                        sp4 = var_3_16;
                    }
                    if ((var_3_16 ^ 0x14) == 0) {
                        func_L39_0063C000(arg0, 0x42700000, 0.052f, 0xBF800000);
                        temp_f1 = 0 /* second half of f64 */;
                        if (((*(s16 *)((u8 *)(arg0) + 0x2DE)) == 0) || (var_f0 = 0.01f, ((temp_f1 < 0x10) != 0))) {
                            temp_f0 = (*(f32 *)((u8 *)(arg0) + 0x1080));
                            if (temp_f0 == 0.0f) {
                                var_f0 = 0.33f;
                                goto block_231;
                            }
                            temp_2_51 = (u16) (*(s16 *)((u8 *)(arg0) + 0x2DE));
                            if (temp_f0 != 0.0f) {
                                if (temp_2_51 != 0) {
                                    var_2_9 = temp_2_51 << 0x10;
                                    if ((temp_f1 != 0) && (temp_f12 = (f32) 0x1A, ((temp_f12 - (*(f32 *)((u8 *)(arg0) + 0x628))) > 1.0f))) {
                                        func_L39_0062B740(arg0, temp_f12, (f32) temp_f1, 0.5f, 0xBF800000);
                                        var_f0 = 0.7f;
                                        if ((*(f32 *)((u8 *)(arg0) + 0x2AC)) < 0.7f) {
                                            var_f0 = (*(f32 *)((u8 *)(arg0) + 0x610));
                                            if (var_f0 < 0.75f) {
                                                (*(f32 *)((u8 *)(arg0) + 0x610)) = 0.75f;
                                            }
                                        }
                                    } else {
                                        goto block_228;
                                    }
                                } else {
                                    goto block_229;
                                }
                            } else {
                                var_2_9 = temp_2_51 << 0x10;
block_228:
                                if (var_2_9 == 0) {
block_229:
                                    var_f0 = 2.0f;
                                    if (!((*(f32 *)((u8 *)(arg0) + 0x628)) < (f32) 0x1A)) {
                                        goto block_230;
                                    }
                                } else {
block_230:
                                    var_f0 = 1.0f;
                                }
                                goto block_231;
                            }
                        } else {
block_231:
                            (*(f32 *)((u8 *)(arg0) + 0x610)) = var_f0;
                        }
                    }
                    temp_3_8 = var_f0;
                    temp_16_3 = ((*(s16 *)((u8 *)(arg0) + 0x107C)) * 0x2C) + var_16_2;
                    var_f0 = (f32) (*(s32 *)((u8 *)(temp_16_3) + 0x14));
                    temp_17 = ((s32)(temp_3_8) - (*(s32 *)((u8 *)(temp_16_3) + 0xC))) * 2;
                    if (var_f0 < (*(f32 *)((u8 *)(arg0) + 0x628))) {
                        if ((*(s32 *)((u8 *)(arg0) + 0x61C)) == 0) {
                            temp_ret_6 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), temp_17, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                            var_f0 = (f32)(temp_ret_6);
                            if (temp_ret_6 != 0) {
                                if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) {
                                    temp_ret_7 = func_L39_00638C28(arg0);
                                    var_f0 = (f32)(temp_ret_7);
                                    if (temp_ret_7 == 0) {
                                        goto block_237;
                                    }
                                } else {
block_1025:
block_1026:
                                    var_5 = 7;
                                    goto block_1027;
                                }
                            } else {
                                goto block_237;
                            }
                        }
                    } else {
block_237:
                        if ((*(s32 *)((u8 *)(arg0) + 0x61C)) == 0) {
                            var_f0 = (*(f32 *)((u8 *)(arg0) + 0x628));
                            if ((f32) (*(s32 *)((u8 *)(temp_16_3) + 0x18)) < var_f0) {
                                var_5 = 0;
                                var_6_2 = 0;
                                goto block_1028;
                            }
                        }
                    }
                    goto block_1031;
                case 0x13:
                case 0x15:
                    var_f0 = (*(f32 *)((u8 *)(arg0) + 0x628));
                    var_6_3 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                    temp_19 = ((*(s16 *)((u8 *)(arg0) + 0x107C)) * 0x2C) + &D_L39_0047A8A8;
                    if (var_6_3 == 0) {
                        var_3_17 = 0;
                    } else {
                        temp_2_52 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                        var_6_3 = 5;
                        *sp = (u8) (&D_L39_004997E0)[temp_2_52 + 1 + (((var_17 - temp_2_52) & 7 & 7) * 0xFF)];
                        temp_2_53 = sp0 ^ (s32) var_17;
                        var_3_17 = sp4 ^ temp_2_53;
                        sp0 = temp_2_53;
                        sp4 = var_3_17;
                    }
                    temp_16_4 = ((var_3_17 ^ 0x15) == 0) ? 7 : (((s32)(var_f1) - (*(s32 *)((u8 *)(temp_19) + 0xC))) * 2);
                    if (((*(u8 *)((u8 *)(arg0) + 0x24FE)) == 0) && (var_f0 = (*(f32 *)((u8 *)(arg0) + 0x628)), ((f32) (*(s32 *)((u8 *)(temp_19) + 0x14)) < var_f0))) {
                        temp_2_54 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                        if ((*(s32 *)((u8 *)(arg0) + 0x61C)) == 0) {
                            if (temp_2_54 == 0) {
                                var_3_18 = 0;
                            } else {
                                var_6_3 = 5;
                                *sp = (u8) (&D_L39_004997E0)[temp_2_54 + 1 + (((var_17 - temp_2_54) & 7 & 7) * 0xFF)];
                                temp_2_55 = sp0 ^ (s32) var_17;
                                var_3_18 = sp4 ^ temp_2_55;
                                sp0 = temp_2_55;
                                sp4 = var_3_18;
                            }
                            if ((((var_3_18 ^ 0x15) != 0) || ((*(s16 *)((u8 *)(arg0) + 0x2D8)) != 1)) && (temp_ret_8 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), temp_16_4, 0, (*(void **)((u8 *)(arg0) + 0x2534))), var_f0 = (f32)(temp_ret_8), (temp_ret_8 != 0))) {
                                if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) {
                                    temp_ret_9 = func_L39_00638C28(arg0);
                                    var_f0 = (f32)(temp_ret_9);
                                    if (temp_ret_9 == 0) {
                                        goto block_254;
                                    }
                                } else {
                                    goto block_1025;
                                }
                            } else {
                                goto block_254;
                            }
                        } else {
                            goto block_278;
                        }
                    } else {
block_254:
                        temp_3_9 = (*(s32 *)((u8 *)(arg0) + 0x61C));
                        if (temp_3_9 != 0) {
                            goto block_278;
                        }
                        var_f0 = (*(f32 *)((u8 *)(arg0) + 0x628));
                        temp_f2 = var_f0;
                        if (var_f0 > 34.0f) {
                            if ((*(u8 *)((u8 *)(arg0) + 0x24FE)) != 0) {
                                var_5 = 1;
                                goto block_1027;
                            }
                            var_f0 = 0.9f;
                            if ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.9f) {
                                (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 2, 0, 0, 1);
                                if ((*(u8 *)((u8 *)(arg0) + 0x19E5)) != 0) {
                                    temp_2_56 = (*(u8 *)((u8 *)(arg0) + 0x19E5));
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_56 + 1 + (((var_22 - temp_2_56) & 7 & 7) * 0xFF)];
                                    temp_2_57 = sp0 ^ (s32) var_22;
                                    var_3_19 = sp4 ^ temp_2_57;
                                    sp0 = temp_2_57;
                                    sp4 = var_3_19;
                                } else {
                                    var_3_19 = 0;
                                }
                                var_f12 = 11.0f;
                                var_6_4 = *((var_3_19 * 4) + &D_L39_00246018);
                                var_5_4 = 3;
block_480:
                                var_f0 = func_L39_0062B4A8(arg0, var_5_4, var_6_4, 0, var_f12);
                            } else {
                                goto block_267;
                            }
                        } else {
block_267:
                            if (temp_3_9 != 0) {
                                goto block_278;
                            }
                            temp_2_58 = (*(s32 *)((u8 *)(temp_19) + 0x18));
                            var_f0 = (f32) temp_2_58;
                            if (!(var_f0 < temp_f2)) {
block_278:
                                if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                    temp_2_59 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_59 + 1 + (((var_17 - temp_2_59) & 7 & 7) * 0xFF)];
                                    temp_2_60 = sp0 ^ (s32) var_17;
                                    var_3_20 = sp4 ^ temp_2_60;
                                    sp0 = temp_2_60;
                                    sp4 = var_3_20;
                                } else {
                                    var_3_20 = 0;
                                }
                                if (((var_3_20 ^ 0x15) == 0) && ((*(s32 *)((u8 *)(arg0) + 0x478)) != 0xA)) {
                                    var_5 = 0;
                                    goto block_1027;
                                }
                                if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                    temp_2_61 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_61 + 1 + (((var_17 - temp_2_61) & 7 & 7) * 0xFF)];
block_302:
                                    temp_2_62 = sp0 ^ (s32) var_17;
                                    var_3_21 = sp4 ^ temp_2_62;
                                    sp0 = temp_2_62;
                                    sp4 = var_3_21;
                                } else {
block_300:
                                    var_3_21 = 0;
                                }
block_303:
                                if (((var_3_21 ^ 0x15) == 0) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x54) && ((*(s32 *)((u8 *)(arg0) + 0x634)) < 0xD)) {
                                    var_f0 = func_L39_0062B728(arg0, 2);
                                    (*(s32 *)((u8 *)(arg0) + 0x634)) = 0xD;
                                }
                            } else {
                                if ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.8f) {
                                    var_5 = 2;
                                    goto block_1027;
                                }
                                var_f0 = (f32) (temp_2_58 + 5);
                                if ((var_f0 < temp_f2) || ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2)) {
                                    var_5 = 0;
                                    var_6_2 = 0;
                                    goto block_1028;
                                }
                            }
                        }
                    }
                    goto block_1031;
                case 0x85:
                    var_f0 = 37.0f;
                    if ((*(f32 *)((u8 *)(arg0) + 0x628)) > 37.0f) {
                        if ((*(s32 *)((u8 *)(arg0) + 0x61C)) == 0) {
                            temp_ret_10 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 6, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                            var_f0 = (f32)(temp_ret_10);
                            if (temp_ret_10 != 0) {
                                if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) {
                                    temp_ret_11 = func_L39_00638C28(arg0);
                                    var_f0 = (f32)(temp_ret_11);
                                    if (temp_ret_11 == 0) {
                                        goto block_293;
                                    }
                                } else {
                                    goto block_1025;
                                }
                            } else {
block_293:
                                goto block_294;
                            }
                        } else {
                            goto block_297;
                        }
                    } else {
block_294:
                        if ((*(s32 *)((u8 *)(arg0) + 0x61C)) == 0) {
                            var_f0 = 37.0f;
                            if ((*(f32 *)((u8 *)(arg0) + 0x628)) > 37.0f) {
                                (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 0, 0, 1);
                                var_2_10 = func_L39_006223B0(arg0, 0);
                                var_f12 = 12.0f;
block_479:
                                var_5_4 = var_2_10;
                                var_6_4 = 0;
                                goto block_480;
                            }
                        }
block_297:
                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                            temp_2_63 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                            *sp = (u8) (&D_L39_004997E0)[temp_2_63 + 1 + (((var_17 - temp_2_63) & 7 & 7) * 0xFF)];
                            goto block_302;
                        }
                        goto block_300;
                        goto block_303;
                    }
                    goto block_1031;
                case 0x79:
                    if ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) {
                        var_5 = 0;
                        goto block_1027;
                    }
                    goto block_1031;
                case 0x2:
                case 0x2E:
                case 0x72:
                    if (((*(u8 *)((u8 *)(arg0) + 0x142E)) != 0) && (((*(f32 *)((u8 *)(temp_23) + 0x44)) > 0.9f) || ((*(u8 *)((u8 *)(temp_23) + 0x42)) != 0xFF))) {
                        (*(u8 *)((u8 *)(arg0) + 0x142E)) = 0U;
                    }
                    if ((*(u8 *)((u8 *)(arg0) + 0x378)) == 0) {
                        goto block_320;
                    }
                    if ((*(s16 *)((u8 *)(arg0) + 0x2DC)) != 0) {
block_320:
                        temp_19_2 = arg0 + 0x19E6;
                        if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) >= 6) {
                            temp_2_64 = (*(u8 *)((u8 *)(arg0) + 0x19E8));
                            temp_11_8 = arg0 + 0x19E8;
                            if (temp_2_64 == 0) {
                                var_3_22 = 0;
                            } else {
                                *sp = (u8) (&D_L39_004997E0)[temp_2_64 + 1 + (((temp_11_8 - temp_2_64) & 7 & 7) * 0xFF)];
                                temp_2_65 = sp0 ^ (s32) temp_11_8;
                                var_3_22 = sp4 ^ temp_2_65;
                                sp0 = temp_2_65;
                                sp4 = var_3_22;
                            }
                            if ((((var_3_22 ^ 0x12) != 0) || ((*(u8 *)((u8 *)(arg0) + 0x1A09)) == 0)) && ((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 1.35f) && (func_L39_00638F50(arg0) == 0)) {
                                var_5 = 6;
                                goto block_1027;
                            }
                            goto block_329;
                        }
block_329:
                        temp_16_5 = ((*(s16 *)((u8 *)(arg0) + 0x32C)) != 0) ? 1 : 7;
                        temp_ret_12 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), temp_16_5, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                        var_f0 = (f32)(temp_ret_12);
                        if (temp_ret_12 != 0) {
                            if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) >= 7) {
                                if ((*(s16 *)((u8 *)(arg0) + 0x330)) == 0) {
                                    goto block_347;
                                }
                                goto block_334;
                            }
block_334:
                            func_L39_00632D78(arg0, 0, 1.0f);
                            temp_ret_13 = func_L39_0062D7C8(arg0, temp_16_5, 1);
                            var_f0 = (f32)(temp_ret_13);
                            if (temp_ret_13 == 0) {
                                if ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.85f) {
                                    if (((*(s16 *)((u8 *)(arg0) + 0x3E4)) != 0) || (((*(s32 *)((u8 *)(arg0) + 0x1310)) == 1) && (func_L01_004606E8(0x28, 2, 0, (*(void **)((u8 *)(arg0) + 0x2534))) != 0) && (func_L39_006212E8(arg0) != 0xA))) {
                                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                            temp_2_66 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_66 + 1 + (((var_17 - temp_2_66) & 7 & 7) * 0xFF)];
                                            temp_2_67 = sp0 ^ (s32) var_17;
                                            var_3_23 = sp4 ^ temp_2_67;
                                            sp0 = temp_2_67;
                                            sp4 = var_3_23;
                                        } else {
                                            var_3_23 = 0;
                                        }
                                        if ((var_3_23 ^ 0x10) == 0) {
                                            goto block_346;
                                        }
                                        goto block_1026;
                                    }
block_346:
                                    var_5 = 9;
                                } else {
                                    goto block_1025;
                                }
                                goto block_1027;
                            }
                        } else {
block_347:
                            if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) == 0) {
                                if ((*(u8 *)((u8 *)(arg0) + 0x372)) == 0) {
                                    goto block_353;
                                }
                                if (((*(f32 *)((u8 *)(arg0) + 0x1A4)) < 0.040000003f) && ((*(f32 *)((u8 *)(arg0) + 0x2B0)) < 0.08726646f)) {
block_353:
                                    if (((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(4, (*(s32 *)((u8 *)(arg0) + 0x2544)))) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) > 0) && ((var_5_5 = (u8 *)2, ((*(u8 *)((u8 *)((&D_1A5810 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) != 2)) || ((*(s32 *)((u8 *)(arg0) + 0x478)) == 3))) {
                                        if ((*(u8 *)((u8 *)(arg0) + 0x19E6)) != 0) {
                                            temp_2_68 = (*(u8 *)((u8 *)(arg0) + 0x19E6));
                                            var_5_5 = &D_L39_004997E0;
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_68 + 1 + (((temp_19_2 - temp_2_68) & 7 & 7) * 0xFF)];
                                            temp_2_69 = sp0 ^ (s32) temp_19_2;
                                            var_3_24 = sp4 ^ temp_2_69;
                                            sp0 = temp_2_69;
                                            sp4 = var_3_24;
                                        } else {
                                            var_3_24 = 0;
                                        }
                                        if (((var_3_24 ^ 0x14) != 0) && ((*(s32 (**)(void *, u8 *))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x44))(arg0, var_5_5) == 0)) {
                                            var_5 = 1;
                                            goto block_1027;
                                        }
                                        goto block_365;
                                    }
block_365:
                                    goto block_366;
                                }
block_366:
                                temp_4_8 = (*(void **)((u8 *)(arg0) + 0x2534));
                                if (((*(s32 *)((u8 *)(temp_4_8) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) && !(func_L39_005C2F50(temp_4_8) & 0x10)) {
                                    var_5 = 4;
                                    goto block_1027;
                                }
                                temp_ret_14 = func_L39_0063BE00(arg0, 0x3D0EFA35);
                                var_f0 = (f32)(temp_ret_14);
                                temp_2_70 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                if (temp_2_70 == 0) {
                                    var_3_25 = 0;
                                } else {
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_70 + 1 + (((var_17 - temp_2_70) & 7 & 7) * 0xFF)];
                                    temp_2_71 = sp0 ^ (s32) var_17;
                                    var_3_25 = sp4 ^ temp_2_71;
                                    sp0 = temp_2_71;
                                    sp4 = var_3_25;
                                }
                                if ((var_3_25 ^ 2) == 0) {
                                    if ((((*(f32 *)((u8 *)(arg0) + 0x2468)) < 0.17f) || ((*(s16 *)((u8 *)(arg0) + 0x320)) != 0)) && (temp_ret_14 == 0) && (((*(s32 *)((u8 *)(arg0) + 0x1430)) == 0) || (fabsf((*(f32 *)((u8 *)(arg0) + 0xFD8))) < 0.017453292f))) {
                                        temp_ret_15 = func_L39_00638DF0(arg0);
                                        var_f0 = (f32)(temp_ret_15);
                                        if (temp_ret_15 == 0) {
                                            if (((*(u8 *)((u8 *)(arg0) + 0x1A07)) == 0) || ((*(s32 *)((u8 *)(arg0) + 0x3FC)) >= 3)) {
                                                temp_ret_16 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 0, 0, 1);
                                                var_f0 = temp_ret_16;
                                                if ((s32)(temp_ret_16) != 0) {
                                                    func_003C4BB0(arg0 + 0x190, 0.0300000012f);
                                                    if ((*(f32 *)((u8 *)(arg0) + 0xFB4)) > 0.030000001f) {
                                                        (*(f32 *)((u8 *)(arg0) + 0xFB4)) = 0.030000001f;
                                                    }
                                                    var_2_10 = func_L39_006223B0(arg0, 1);
                                                    var_f12 = -1.0f;
                                                    goto block_479;
                                                }
                                            } else {
                                                goto block_411;
                                            }
                                        }
                                    } else {
block_411:
                                        var_f0 = func_L39_0062DA30(arg0);
                                    }
                                }
                            }
                        }
                    } else {
                        var_5 = 0x78;
                        goto block_1027;
                    }
                    goto block_1031;
                case 0x7D:
                    temp_5 = (*(u8 *)((u8 *)(arg0) + 0x1A07));
                    if (((temp_5 != 0) ? 1 : (((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x33) ? 1 : (((*(s16 *)((u8 *)(arg0) + 0x2D8)) == 0) ? 0 : 1))) == 0) {
                        var_4_2 = 0 /* unknown instruction: por $a0, $zero, $zero */;
                        if ((*(u8 *)((u8 *)(arg0) + 0x216)) != 0) {
                            temp_f20 = func_0038CEA8(arg0 + 0x140);
                            if ((temp_f20 < (func_0038CEA8(arg0 + 0x120) * 0.75f)) || (func_L39_00634E58(arg0, 0, 0x3F800000, 0x3FA00000) != 0)) {
                                if ((*(u8 *)((u8 *)((&D_1A5810 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) == 1) {
                                    func_0038CF68(sp, arg0 + 0x40, (*(f32 *)((u8 *)(arg0) + 0x132C)));
                                    0 /* unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                                    func_L01_00412FE0(arg0 + 0x11A0, sp, (*(f32 *)((u8 *)(arg0) + 0xB8)), 0);
                                }
                                var_5 = 0x79;
                                goto block_1027;
                            }
                            var_4_2 = 0 /* unknown instruction: por $a0, $zero, $zero */;
                            goto block_406;
                        }
block_406:
                        sp20 = var_4_2;
                        sp20 = 0xBDCCCCCE;
                        func_003C2F58((*(void **)((u8 *)(arg0) + 0x2524)), 0x16, sp);
                        func_003C2F58((*(void **)((u8 *)(arg0) + 0x2524)), 0x17, &sp10);
                        func_L39_005CF720((*(void **)((u8 *)(arg0) + 0x2524)), sp, &sp20, saved_reg_gp - 0x1E30, 1);
                        func_L39_005CF720((*(void **)((u8 *)(arg0) + 0x2524)), sp, &sp20, saved_reg_gp - 0x1E20, 1);
                        func_L39_005CF720((*(void **)((u8 *)(arg0) + 0x2524)), &sp10, &sp20, saved_reg_gp - 0x1E30, 1);
                        var_f0 = func_L39_005CF720((*(void **)((u8 *)(arg0) + 0x2524)), &sp10, &sp20, saved_reg_gp - 0x1E20, 1);
                    } else {
                        temp_2_72 = (*(u8 *)((u8 *)(arg0) + 0x1A26));
                        temp_10 = arg0 + 0x1A26;
                        if (temp_2_72 == 0) {
                            var_4_3 = 0;
                            var_19 = (s32 *)0x1A0000;
                        } else {
                            var_19 = &D_1A5810;
                            *sp = (u8) (&D_L39_00480760)[(((temp_10 - temp_2_72) & 7 & 7) * 0xC1) + (temp_2_72 + 1)];
                            temp_3_10 = sp0 ^ (s32) temp_10;
                            temp_2_73 = sp4 ^ temp_3_10;
                            sp0 = temp_3_10;
                            temp_4_9 = temp_2_73 >> 0x10;
                            var_4_3 = temp_4_9 / (u32) (((temp_2_73 ^ temp_4_9) << 0x10) + 1);
                            sp4 = var_4_3;
                        }
                        temp_11_9 = arg0 + 0x1A2C;
                        if (var_4_3 != 0) {
                            if ((*(u8 *)((u8 *)(arg0) + 0x1A2C)) == 0) {
                                temp_2_74 = D_L39_00480760 + 1;
                                D_L39_00480760 = temp_2_74;
                                (*(u8 *)((u8 *)(arg0) + 0x1A2C)) = temp_2_74;
                            } else {
                                temp_4_10 = (*(u8 *)((u8 *)(arg0) + 0x1A2C));
                                (*(u8 *)((u8 *)(arg0) + 0x1A2C)) = (u8) D_L39_00480761;
                                D_L39_00480761 = temp_4_10;
                            }
                            temp_2_75 = (*(u8 *)((u8 *)(arg0) + 0x1A2C));
                            temp_2_76 = *((((u32) ((s32) temp_11_9 * D_L39_0024B9C8) % 386U) * 4) + &D_L39_00480760);
                            sp4 = ((1 << 0x10) | 1) ^ temp_2_76;
                            sp0 = (s32) temp_11_9 ^ temp_2_76;
                            (&D_L39_00480760)[(((temp_11_9 - temp_2_75) & 7 & 7) * 0xC1) + (temp_2_75 + 1)] = *sp;
                        }
                        if ((*(u8 *)((u8 *)((var_19 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) == 1) {
                            func_0038CF68(sp, arg0 + 0x40, (*(f32 *)((u8 *)(arg0) + 0x132C)));
                            0 /* unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                            func_L01_00412FE0(arg0 + 0x11A0, sp, (*(f32 *)((u8 *)(arg0) + 0xB8)), 0);
                        }
                        func_L39_0063A030(arg0, 9, 0);
                        (*(s16 *)((u8 *)(arg0) + 0x320)) = 0x19;
                        (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 3, 0, 0, 1);
                        var_f12 = 9.0f;
                        var_5_4 = 6;
                        var_6_4 = 4;
                        goto block_480;
                    }
                    goto block_1031;
                case 0x64:
                    if (func_0038CF38() < 0.2f) {
                        var_f0 = 0.054000005f;
                        if ((*(f32 *)((u8 *)(arg0) + 0x1A0)) < 0.054000005f) {
                            var_f0 = func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xB8)), (*(f32 *)((u8 *)(arg0) + 0x13CC)));
                            if (var_f0 < 0.034906585f) {
                                var_5 = 0x66;
                                goto block_1027;
                            }
                        }
                    } else {
                        goto block_411;
                    }
                    goto block_1031;
                case 0x65:
                    if ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) {
                        var_5 = 0x64;
                        goto block_1027;
                    }
                    goto block_1031;
                case 0x66:
                    if ((*(s32 *)((u8 *)(arg0) + 0x13D4)) == 0) {
                        if (((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) || ((*(s32 *)((u8 *)(arg0) + 0x13D0)) != 0)) {
                            var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 1, 0, 1);
                        }
                        if ((*(s32 *)((u8 *)(arg0) + 0x13D4)) == 0) {
                            var_f0 = func_0038CF38();
                            if (var_f0 > 0.2f) {
                                var_5 = 0x64;
                                goto block_1027;
                            }
                        }
                    }
                    goto block_1031;
                case 0x7A:
                    var_f0 = (*(f32 *)((u8 *)(arg0) + 0x2C4)) - 1.2f;
                    if (!((*(f32 *)((u8 *)(arg0) + 0xA8)) < var_f0)) {
                        var_2_5 = (*(s32 *)((u8 *)(arg0) + 0x2F0)) < 0x7E;
                        goto block_639;
                    }
                    goto block_641;
                case 0x6F:
                    var_f0 = (f32) (*(s32 *)((u8 *)((&D_L39_0047A8A8 + ((*(s16 *)((u8 *)(arg0) + 0x107C)) * 0x2C))) + 0x18));
                    if (var_f0 < (*(f32 *)((u8 *)(arg0) + 0x628))) {
                        var_5 = 0;
                        goto block_1027;
                    }
                    goto block_1031;
                case 0x3:
                    if (((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(4, (*(s32 *)((u8 *)(arg0) + 0x2544)))) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) > 0) && ((var_5_6 = (u8 *)2, ((*(u8 *)((u8 *)((&D_1A5810 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) != 2)) || ((*(s32 *)((u8 *)(arg0) + 0x478)) == 3))) {
                        temp_11_10 = arg0 + 0x19E6;
                        if ((*(u8 *)((u8 *)(arg0) + 0x19E6)) == 0) {
                            var_3_26 = 0;
                        } else {
                            temp_2_77 = (*(u8 *)((u8 *)(arg0) + 0x19E6));
                            var_5_6 = &D_L39_004997E0;
                            *sp = (u8) (&D_L39_004997E0)[temp_2_77 + 1 + (((temp_11_10 - temp_2_77) & 7 & 7) * 0xFF)];
                            temp_2_78 = sp0 ^ (s32) temp_11_10;
                            var_3_26 = sp4 ^ temp_2_78;
                            sp0 = temp_2_78;
                            sp4 = var_3_26;
                        }
                        if (((var_3_26 ^ 0x14) != 0) && ((*(s32 (**)(void *, u8 *))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x44))(arg0, var_5_6) == 0)) {
                            var_5 = 1;
                            goto block_1027;
                        }
                        goto block_435;
                    }
block_435:
                    if ((*(s16 *)((u8 *)(arg0) + 0x320)) != 0) {
                        goto block_449;
                    }
                    if (!((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A4)) & func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))))) {
                        if ((*(s16 *)((u8 *)(arg0) + 0x320)) != 0) {
                            goto block_449;
                        }
                        temp_4_11 = (*(void **)((u8 *)(arg0) + 0x2534));
                        if (!((*(s32 *)((u8 *)(temp_4_11) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544))))) {
                            goto block_449;
                        }
                        if (func_L39_005C2F50(temp_4_11) & 0x10) {
block_449:
                            if (((*(s16 *)((u8 *)(arg0) + 0x2DE)) >= 8) && ((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 0.3f)) {
                                var_5 = 6;
                                goto block_1027;
                            }
                            if ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) {
                                var_5 = 0;
                                goto block_1027;
                            }
                            temp_f2_2 = (*(f32 *)((u8 *)(arg0) + 0x2468));
                            var_f0 = 0.2f;
                            if ((temp_f2_2 > 0.2f) && ((*(s16 *)((u8 *)(arg0) + 0x320)) == 0)) {
                                if ((*(f32 *)((u8 *)(arg0) + 0xFB4)) == 0.0f) {
                                    var_5 = 0;
                                    var_6_2 = 0;
                                    goto block_1028;
                                }
                                var_f0 = 0.5f;
                                if (temp_f2_2 > 0.5f) {
                                    var_5 = 2;
                                    goto block_1027;
                                }
                            }
                        } else {
                            var_5 = 4;
                            goto block_1027;
                        }
                    } else {
                        goto block_1025;
                    }
                    goto block_1031;
                case 0x4:
                    if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(4, (*(s32 *)((u8 *)(arg0) + 0x2544)))) {
                        if (((*(s32 *)((u8 *)(arg0) + 0x2F0)) > 0) && ((var_5_7 = (u8 *)2, ((*(u8 *)((u8 *)((&D_1A5810 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) != 2)) || ((*(s32 *)((u8 *)(arg0) + 0x478)) == 3))) {
                            temp_11_11 = arg0 + 0x19E6;
                            if ((*(u8 *)((u8 *)(arg0) + 0x19E6)) == 0) {
                                var_3_27 = 0;
                            } else {
                                temp_2_79 = (*(u8 *)((u8 *)(arg0) + 0x19E6));
                                var_5_7 = &D_L39_004997E0;
                                *sp = (u8) (&D_L39_004997E0)[temp_2_79 + 1 + (((temp_11_11 - temp_2_79) & 7 & 7) * 0xFF)];
                                temp_2_80 = sp0 ^ (s32) temp_11_11;
                                var_3_27 = sp4 ^ temp_2_80;
                                sp0 = temp_2_80;
                                sp4 = var_3_27;
                            }
                            if (((var_3_27 ^ 0x14) != 0) && ((*(s32 (**)(void *, u8 *))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x44))(arg0, var_5_7) == 0)) {
                                var_5 = 1;
                                var_6_2 = 0;
                                goto block_1028;
                            }
                            goto block_470;
                        }
block_470:
                        goto block_471;
                    }
block_471:
                    if ((*(s32 *)((u8 *)(arg0) + 0x2F0)) < 0xA) {
                        goto block_481;
                    }
                    if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) {
                        if ((*(s16 *)((u8 *)(arg0) + 0x320)) == 0) {
block_481:
                            if (((*(u8 *)((u8 *)(arg0) + 0x378)) != 0) && ((*(s16 *)((u8 *)(arg0) + 0x2DC)) == 0)) {
                                var_5 = 0x78;
                                goto block_1027;
                            }
                            temp_ret_17 = func_L39_00638C28(arg0);
                            var_f0 = (f32)(temp_ret_17);
                            if (temp_ret_17 == 0) {
                                temp_ret_18 = func_L01_004606E8(0x80, 0xC, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                                var_f0 = (f32)(temp_ret_18);
                                if ((temp_ret_18 != 0) && ((*(u8 *)((u8 *)(arg0) + 0x46A)) == 0) && ((*(s32 *)((u8 *)(arg0) + 0x478)) == 0xA)) {
                                    if ((*(s32 *)((u8 *)(arg0) + 0x251C)) != 0) {
                                        var_f0 = func_L39_0063D240(arg0, 0);
                                    } else {
                                        var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0x15, 1, 0, 1);
                                    }
                                }
                                if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) >= 8) {
                                    temp_2_81 = (*(u8 *)((u8 *)(arg0) + 0x19E7));
                                    temp_11_12 = arg0 + 0x19E7;
                                    if (temp_2_81 == 0) {
                                        var_3_28 = 0;
                                    } else {
                                        *sp = (u8) (&D_L39_004997E0)[temp_2_81 + 1 + (((temp_11_12 - temp_2_81) & 7 & 7) * 0xFF)];
                                        temp_2_82 = sp0 ^ (s32) temp_11_12;
                                        var_3_28 = sp4 ^ temp_2_82;
                                        sp0 = temp_2_82;
                                        sp4 = var_3_28;
                                    }
                                    if (((var_3_28 ^ 8) != 0) || ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0xC)) {
                                        var_5 = 6;
                                        goto block_1027;
                                    }
                                }
                            }
                        } else {
                            goto block_478;
                        }
                    } else {
block_478:
                        (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 0, 0, 1);
                        var_2_10 = func_L39_006223B0(arg0, 0);
                        var_f12 = -2.0f;
                        goto block_479;
                    }
                    goto block_1031;
                case 0x2B:
                    if (!((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & (*(s32 *)((u8 *)(arg0) + 0x460))) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 9)) {
                        (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0x2C, 1, 0, 1);
                        var_f0 = 0.0028000001f;
                        (*(s32 *)((u8 *)(arg0) + 0x15C4)) = 0x3B378035;
                        (*(f32 *)((u8 *)(arg0) + 0x15C0)) = 0.0108f;
                    }
                    goto block_1031;
                case 0x17:
                    var_f0 = 13.5f;
                    if ((*(f32 *)((u8 *)(arg0) + 0x628)) > 13.5f) {
                        var_5 = 0x18;
                        var_6_2 = 0;
                        goto block_1028;
                    }
                    goto block_1031;
                case 0x18:
                    if (((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) && ((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2524))) + 0x43)) == 0x20)) {
                        func_L39_0062B4A8(arg0, 0x21, 0, 0, 5.0f);
                    }
                    temp_16_6 = arg0 + 0xB0;
                    func_L39_00632D78(arg0, 0, 1.0f);
                    if (func_L39_006233A8(arg0, arg0 + 0xA0, temp_16_6, 0) != 0) {
                        if ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.5f) {
                            if ((func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 7, 0, (*(void **)((u8 *)(arg0) + 0x2534))) == 0) || !(func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xFD0)), (*(f32 *)((u8 *)(arg0) + 0xB8))) > 2.3561945f)) {
                                goto block_514;
                            }
                            goto block_517;
                        }
block_514:
                        if (!((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A4)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544))))) {
                            if (func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 0xE, 0, (*(void **)((u8 *)(arg0) + 0x2534))) != 0) {
                                var_5 = 0x1B;
                                goto block_1027;
                            }
                            var_f0 = 0.5f;
                            if ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.5f) {
                                if (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xFD0)), func_0038DAB8(arg0, (*(f32 *)((u8 *)(arg0) + 0xB8)), 1.5707964f)) < 0.7853982f) {
                                    sp0 = (*(s32 *)((u8 *)(arg0) + 0xA0));
                                    sp0 = (f32)(sp0) + (func_0038D098(func_0038DAB8((void *)((*(f32 *)((u8 *)(arg0) + 0xB8))), 1.5707964f)) * 0.3f);
                                    sp4 = (f32)(sp4) + (func_0038D0B0(func_0038DAB8((void *)((*(f32 *)((u8 *)(arg0) + 0xB8))), 1.5707964f)) * 0.3f);
                                    temp_ret_19 = func_L39_006233A8(arg0, sp, temp_16_6, 0);
                                    var_f0 = (f32)(temp_ret_19);
                                    if (temp_ret_19 != 0) {
                                        var_5 = 0x19;
                                        goto block_1027;
                                    }
                                } else {
                                    var_f0 = 0.5f;
                                    if ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.5f) {
                                        var_f0 = func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xFD0)), func_0038DAB8((void *)((*(f32 *)((u8 *)(arg0) + 0xB8))), -1.5707964f));
                                        if (var_f0 < 0.7853982f) {
                                            sp0 = (*(s32 *)((u8 *)(arg0) + 0xA0));
                                            sp0 = (f32)(sp0) + (func_0038D098(func_0038DAB8((void *)((*(f32 *)((u8 *)(arg0) + 0xB8))), -1.5707964f)) * 0.3f);
                                            sp4 += func_0038D0B0(func_0038DAB8((void *)((*(f32 *)((u8 *)(arg0) + 0xB8))), -1.5707964f)) * 0.3f;
                                            temp_ret_20 = func_L39_006233A8(arg0, sp, temp_16_6, 0);
                                            var_f0 = (f32)(temp_ret_20);
                                            if (temp_ret_20 != 0) {
                                                var_5 = 0x1A;
                                                goto block_1027;
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
block_517:
                            var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 6, 1, 0, 1);
                            var_2_11 = 8;
block_542:
                            (*(s8 *)((u8 *)(arg0) + 0x1A0B)) = 1;
                            (*(s16 *)((u8 *)(arg0) + 0x308)) = var_2_11;
                        }
                    } else {
                        var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 6, 1, 0, 1);
                        (*(s16 *)((u8 *)(arg0) + 0x308)) = 8;
                    }
                    goto block_1031;
                case 0x19:
                case 0x1A:
                    var_f21 = 1.5707964f;
                    sp0 = (*(s32 *)((u8 *)(arg0) + 0xA0));
                    if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) == 0) {
                        var_3_29 = 0;
                    } else {
                        temp_2_83 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                        var_4 = 5 < 0x28;
                        sp10 = (u8) (&D_L39_004997E0)[temp_2_83 + 1 + (((var_17 - temp_2_83) & 7 & 7) * 0xFF)];
                        temp_2_84 = sp10 ^ (s32) var_17;
                        var_3_29 = sp14 ^ temp_2_84;
                        sp10 = temp_2_84;
                        sp14 = var_3_29;
                    }
                    if ((var_3_29 ^ 0x1A) == 0) {
                        var_f21 = -1.5707964f;
                    }
                    sp0 = (f32)(sp0) + (func_0038D098(func_0038DAB8((void *) var_4, (*(f32 *)((u8 *)(arg0) + 0xB8)), var_f21)) * 0.3f);
                    sp4 += func_0038D0B0(func_0038DAB8((void *)((*(f32 *)((u8 *)(arg0) + 0xB8))), var_f21)) * 0.3f;
                    func_L39_00632D78(arg0, 0, 1.0f);
                    if ((((*(f32 *)((u8 *)(arg0) + 0x2468)) < 0.5f) || (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xFD0)), func_0038DAB8((void *)((*(f32 *)((u8 *)(arg0) + 0xB8))), var_f21)) > 0.7853982f) || (func_L39_006233A8(arg0, sp, arg0 + 0xB0, 0) == 0)) && ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2)) {
                        var_5 = 0x18;
                        goto block_1027;
                    }
                    if ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.5f) {
                        if ((func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 7, 0, (*(void **)((u8 *)(arg0) + 0x2534))) != 0) && (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xFD0)), (*(f32 *)((u8 *)(arg0) + 0xB8))) > 2.3561945f)) {
                            var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 6, 1, 0, 1);
                            var_2_11 = 0x21;
                            goto block_542;
                        }
                        goto block_544;
                    }
block_544:
                    temp_ret_21 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 7, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                    var_f0 = (f32)(temp_ret_21);
                    if (temp_ret_21 != 0) {
                        var_5 = 0x1B;
                        goto block_1027;
                    }
                    goto block_1031;
                case 0x78:
                    if (((*(u8 *)((u8 *)(arg0) + 0x1A14)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0xFB)) {
                        func_L39_0063B5E0(arg0, 0xF);
                        (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0x76, 0, 0, 0);
                        var_f0 = func_L39_00628038(arg0, 1);
                    }
                    if ((*(u8 *)((u8 *)(arg0) + 0x378)) == 0) {
                        if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) != 0) {
                            var_5 = 6;
                        } else {
                            var_5 = 0;
                        }
                        goto block_1027;
                    }
                    goto block_1031;
                case 0x6:
                case 0x2C:
                    temp_2_85 = (*(u8 *)((u8 *)(arg0) + 0x19E5));
                    if (temp_2_85 == 0) {
                        var_3_30 = 0;
                    } else {
                        *sp = (u8) (&D_L39_004997E0)[temp_2_85 + 1 + (((var_22 - temp_2_85) & 7 & 7) * 0xFF)];
                        temp_2_86 = (s32)(sp0) ^ (s32) var_22;
                        var_3_30 = (s32)(sp4) ^ temp_2_86;
                        sp0 = temp_2_86;
                        sp4 = var_3_30;
                    }
                    if ((var_3_30 == 0) && (((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0xF) || ((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 1.75f))) {
                        func_L39_0062B4A8(arg0, 0xB, 0, 0, 13.0f);
                        if ((*(u8 *)((u8 *)(arg0) + 0x19E5)) == 0) {
                            temp_2_87 = D_L39_004997E0 + 1;
                            D_L39_004997E0 = temp_2_87;
                            (*(u8 *)((u8 *)(arg0) + 0x19E5)) = temp_2_87;
                        } else {
                            temp_4_12 = (*(u8 *)((u8 *)(arg0) + 0x19E5));
                            (*(u8 *)((u8 *)(arg0) + 0x19E5)) = (u8) D_L39_004997E1;
                            D_L39_004997E1 = temp_4_12;
                        }
                        temp_3_11 = *((((u32) ((s32) var_22 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
                        sp4 = temp_3_11 ^ 1;
                        sp0 = (s32) var_22 ^ temp_3_11;
                        (&D_L39_004997E0)[*var_22 + 1 + (((var_22 - *var_22) & 7 & 7) * 0xFF)] = *sp;
                        var_3_31 = 0;
                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                            temp_3_12 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                            *sp = (u8) (&D_L39_004997E0)[temp_3_12 + 1 + (((var_17 - temp_3_12) & 7 & 7) * 0xFF)];
                            temp_2_88 = sp0 ^ (s32) var_17;
                            var_3_31 = sp4 ^ temp_2_88;
                            sp0 = temp_2_88;
                            sp4 = var_3_31;
                        }
                        if ((var_3_31 ^ 0x2C) != 0) {
                            (*(s32 *)((u8 *)(arg0) + 0x2450)) = 0;
                        } else {
                            (*(s32 *)((u8 *)(arg0) + 0x2450)) = 7;
                        }
                    }
                    if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) != 0) {
                        if ((*(u8 *)((u8 *)(arg0) + 0x2476)) != 0) {
                            temp_2_89 = (*(u8 *)((u8 *)(arg0) + 0x2476));
                            *sp = (u8) (&D_L39_004997E0)[temp_2_89 + 1 + (((temp_11_2 - temp_2_89) & 7 & 7) * 0xFF)];
                            temp_2_90 = sp0 ^ (s32) temp_11_2;
                            sp0 = temp_2_90;
                            sp4 ^= temp_2_90;
                            var_f0 = (f32)(sp4);
                        } else {
                            var_f0 = 0.0f;
                        }
                        var_2_12 = 1;
                        if (!(var_f0 <= 0.0f)) {
                            var_2_12 = 0;
                        }
                        if (!(var_2_12 & 0xFF)) {
                            if ((*(s16 *)((u8 *)(arg0) + 0x330)) >= 0x12) {
                                temp_ret_22 = func_L39_0062D7C8(arg0, ((*(s16 *)((u8 *)(arg0) + 0x32C)) == 0) ? 5 : 1, 0);
                                var_f0 = (f32)(temp_ret_22);
                                if (temp_ret_22 == 0) {
                                    if ((*(u8 *)((u8 *)(arg0) + 0x1A14)) != 0) {
                                        var_16_3 = 0;
loop_631:
                                        func_19D500((*(u8 *)((u8 *)(arg0) + 0x44ED)));
                                        if (var_16_3 < 4) {
                                            var_f0_3 = (f32) var_16_3 * 1.5707964f;
                                        } else {
                                            var_f0_3 = func_L39_005B44C8();
                                        }
                                        func_0038D890(sp, arg0 + 0x20, arg0 + 0x40, var_f0_3);
                                        func_0038CF68(sp, sp, 0.3f);
                                        func_0038CF68(&sp10, sp, 0.75f);
                                        0 /* unknown instruction: vadd.xyz $vf2, $vf2, $vf1 */;
                                        temp_ret_23 = func_003D3CB0();
                                        var_f0 = (f32)(temp_ret_23);
                                        var_16_3 += 1;
                                        if (temp_ret_23 != 0) {
                                            if (var_16_3 < 0xA) {
                                                goto loop_631;
                                            }
                                        } else {
                                            var_f0 = func_0038CE20(sp, sp, 0xBF800000);
                                            (*(s32 *)((u8 *)(arg0) + 0x15A0)) = sp0;
                                        }
                                    }
                                    goto block_636;
                                }
                            } else {
block_636:
                                if ((*(s32 *)((u8 *)(arg0) + 0x1568)) != 0) {
                                    var_5 = 0x17;
                                    goto block_1027;
                                }
                            }
                        }
                    } else {
                        func_L39_0063A2E8(arg0);
                        if ((*(f32 *)((u8 *)(arg0) + 0x148)) < -0.18f) {
                            (*(f32 *)((u8 *)(arg0) + 0x148)) = -0.18f;
                        }
                        if ((*(f32 *)((u8 *)(arg0) + 0x128)) < -0.18f) {
                            (*(f32 *)((u8 *)(arg0) + 0x128)) = -0.18f;
                        }
                        temp_2_91 = (*(u8 *)((u8 *)(arg0) + 0x2476));
                        if (temp_2_91 == 0) {
                            var_f0_4 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_91 + 1 + (((temp_11_2 - temp_2_91) & 7 & 7) * 0xFF)];
                            temp_2_92 = sp0 ^ (s32) temp_11_2;
                            sp0 = temp_2_92;
                            sp4 ^= temp_2_92;
                            var_f0_4 = sp4;
                        }
                        var_2_13 = 1;
                        if (!((f32)(var_f0_4) <= 0.0f)) {
                            var_2_13 = 0;
                        }
                        if (var_2_13 & 0xFF) {
                            var_5 = 0x39;
                            goto block_1027;
                        }
                        temp_17_2 = (*(s32 *)((u8 *)(arg0) + 0x2CC)) == 0;
                        if ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x4B) {
                            if ((s32)((*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 0, 0, 1)) != 0) {
                                func_L39_0062B4A8(arg0, 0xC, 4, 0, 5.0f);
                            }
                            if (temp_17_2 != 0) {
                                (*(s16 *)((u8 *)(arg0) + 0x320)) = 0x12;
                            }
                            var_f12_2 = 0x3CB43958;
                            var_f13 = 0x3B83126F;
                            var_5_8 = 0xA;
                            var_6_5 = 4;
                            goto block_617;
                        }
                        temp_2_93 = (*(u8 *)((u8 *)(arg0) + 0x19E5));
                        if (temp_2_93 == 0) {
                            var_3_32 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_93 + 1 + (((var_22 - temp_2_93) & 7 & 7) * 0xFF)];
                            temp_2_94 = sp0 ^ (s32) var_22;
                            var_3_32 = sp4 ^ temp_2_94;
                            sp0 = temp_2_94;
                            sp4 = var_3_32;
                        }
                        if ((var_3_32 ^ 1) != 0) {
                            if (!((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.5f)) {
                                goto block_612;
                            }
                            if ((*(s16 *)((u8 *)(arg0) + 0x320)) != 0) {
block_612:
                                if ((*(f32 *)((u8 *)(arg0) + 0x1A4)) > 0.060000002f) {
                                    temp_ret_24 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 3, 0, 0, 1);
                                    var_f0 = temp_ret_24;
                                    if ((s32)(temp_ret_24) != 0) {
                                        func_L39_0062B4A8(arg0, 6, 0, 0, 10.0f);
                                        var_f0 = func_003C4BB0(arg0 + 0x190, 0.154000014f);
                                    }
                                } else {
                                    (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 1, 0, 1);
                                    var_f12_2 = 0x3C83126F;
                                    var_f13 = 0x3B03126F;
                                    var_5_8 = 5;
                                    goto block_616;
                                }
                            } else {
                                (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 2, 1, 0, 1);
                                var_f12_2 = 0x3C83126F;
                                var_f13 = 0x3B03126F;
                                var_5_8 = 7;
                                goto block_616;
                            }
                        } else {
                            if ((s32)((*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 0, 0, 1)) != 0) {
                                func_L39_0062B4A8(arg0, 0xC, 9, 0, -1.0f);
                            }
                            temp_16_7 = arg0 + 0x190;
                            func_L39_00632558(arg0, temp_16_7, temp_16_7, 0);
                            func_003C4BB0(temp_16_7, 0.140000015f);
                            temp_11_13 = arg0 + 0x19E7;
                            (*(s16 *)((u8 *)(arg0) + 0x320)) = 6;
                            if ((*(u8 *)((u8 *)(arg0) + 0x19E7)) == 0) {
                                var_3_33 = 0;
                            } else {
                                temp_2_95 = (*(u8 *)((u8 *)(arg0) + 0x19E7));
                                *sp = (u8) (&D_L39_004997E0)[temp_2_95 + 1 + (((temp_11_13 - temp_2_95) & 7 & 7) * 0xFF)];
                                temp_2_96 = sp0 ^ (s32) temp_11_13;
                                var_3_33 = sp4 ^ temp_2_96;
                                sp0 = temp_2_96;
                                sp4 = var_3_33;
                            }
                            if ((var_3_33 ^ 0x2C) == 0) {
                                (*(s16 *)((u8 *)(arg0) + 0x320)) = 8;
                            }
                            if ((temp_17_2 != 0) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x2B)) {
                                (*(s16 *)((u8 *)(arg0) + 0x320)) = 0xF;
                            }
                            var_f12_2 = 0x3C9BA5E3;
                            var_f13 = 0x3B03126F;
                            var_5_8 = 0xA;
block_616:
                            var_6_5 = 2;
block_617:
                            var_f0 = func_L32_004FD190(arg0, var_5_8, var_6_5, 0, 1, var_f12_2, var_f13);
                        }
                    }
                    goto block_1031;
                case 0x76:
                    var_2_5 = (*(s32 *)((u8 *)(arg0) + 0x2F0)) < 0x65;
                    goto block_639;
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
                case 0x68:
                case 0x70:
                case 0x83:
                    if ((*(u8 *)((u8 *)(arg0) + 0x153E)) != 0) {
                        temp_ret_25 = func_L01_004FF5D8();
                        temp_2_97 = temp_ret_25;
                        var_f0 = (f32)(temp_ret_25);
                        var_f1 = 0 /* second half of f64 */;
                        if ((temp_2_97 > 0) && (((*(s32 *)((u8 *)(arg0) + 0x2F0)) < temp_2_97) || ((*(u8 *)((u8 *)(arg0) + 0x14AC)) != 0))) {
                            temp_2_98 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                            if ((*(s32 *)((u8 *)(arg0) + 0x2D0)) != 0) {
                                if (temp_2_98 == 0) {
                                    var_3_34 = 0;
                                } else {
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_98 + 1 + (((var_17 - temp_2_98) & 7 & 7) * 0xFF)];
                                    temp_2_99 = sp0 ^ (s32) var_17;
                                    var_3_34 = sp4 ^ temp_2_99;
                                    sp0 = temp_2_99;
                                    sp4 = var_3_34;
                                }
                                if (((var_3_34 ^ 0xB) != 0) || (temp_ret_26 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 6, 0, (*(void **)((u8 *)(arg0) + 0x2534))), var_f0 = (f32)(temp_ret_26), var_f1 = 0 /* second half of f64 */, (temp_ret_26 != 0))) {
                                    var_16_4 = 1;
                                    if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) == 0) {
                                        var_3_35 = 0;
                                    } else {
                                        temp_2_100 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                        *sp = (u8) (&D_L39_004997E0)[temp_2_100 + 1 + (((var_17 - temp_2_100) & 7 & 7) * 0xFF)];
                                        temp_2_101 = sp0 ^ (s32) var_17;
                                        var_3_35 = sp4 ^ temp_2_101;
                                        sp0 = temp_2_101;
                                        sp4 = var_3_35;
                                    }
                                    if (((var_3_35 ^ 0x1B) == 0) || ((*(u8 *)((u8 *)(arg0) + 0x14AC)) != 0)) {
                                        temp_ret_27 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 6, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                                        var_f0 = (f32)(temp_ret_27);
                                        var_f1 = 0 /* second half of f64 */;
                                        var_16_4 = (temp_ret_27 == 0) ? 0 : 1;
                                    }
                                    if ((*(u8 *)((u8 *)((&D_1A5810 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) == 2) {
                                        var_16_4 = (((*(u8 *)((u8 *)(arg0) + 0x3E7)) ^ 3) == 0) ? 0 : var_16_4;
                                    }
                                    if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                        temp_2_102 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                        *sp = (u8) (&D_L39_004997E0)[temp_2_102 + 1 + (((var_17 - temp_2_102) & 7 & 7) * 0xFF)];
                                        temp_2_103 = sp0 ^ (s32) var_17;
                                        var_3_36 = sp4 ^ temp_2_103;
                                        sp0 = temp_2_103;
                                        sp4 = var_3_36;
                                    } else {
                                        var_3_36 = 0;
                                    }
                                    if ((var_3_36 ^ 0xB) == 0) {
                                        var_16_4 = ((*(u8 *)((u8 *)(arg0) + 0x14AC)) == 0) ? 0 : var_16_4;
                                    }
                                    if (var_16_4 != 0) {
                                        temp_ret_28 = func_L01_004606E8(0x1F000, 4, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                                        var_f0 = (f32)(temp_ret_28);
                                        var_f1 = 0 /* second half of f64 */;
                                        if (temp_ret_28 != 0) {
                                            temp_ret_29 = func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)));
                                            var_f0 = (f32)(temp_ret_29);
                                            var_f1 = 0 /* second half of f64 */;
                                            if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & temp_ret_29) {
                                                var_5 = 0xB;
                                                goto block_1027;
                                            }
                                        }
                                    }
                                    goto block_671;
                                }
                                goto block_672;
                            }
                            goto block_672;
                        }
                    }
block_671:
block_672:
                    if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                        temp_2_104 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                        *sp = (u8) (&D_L39_004997E0)[temp_2_104 + 1 + (((var_17 - temp_2_104) & 7 & 7) * 0xFF)];
                        temp_2_105 = sp0 ^ (s32) var_17;
                        var_3_37 = sp4 ^ temp_2_105;
                        sp0 = temp_2_105;
                        sp4 = var_3_37;
                    } else {
                        var_3_37 = 0;
                    }
                    if (((var_3_37 ^ 0x1B) == 0) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x12)) {
                        var_f1 = (*(f32 *)((u8 *)(arg0) + 0x208));
                        var_f0 = 0.7f;
                        if (var_f1 > 0.7f) {
                            (*(s8 *)((u8 *)(arg0) + 0x1A0B)) = 0;
                            (*(u8 *)((u8 *)(arg0) + 0x1A0C)) = 0U;
                        }
                    }
                    temp_2_106 = (*(u8 *)((u8 *)(arg0) + 0x14AC));
                    if ((*(s16 *)((u8 *)(arg0) + 0x152A)) < (*(s32 *)((u8 *)(arg0) + 0x2F0))) {
                        if (temp_2_106 == 0) {
                            var_5 = 6;
                            goto block_1027;
                        }
                        goto block_700;
                    }
                    temp_2_107 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                    if (temp_2_106 == 0) {
                        if (temp_2_107 == 0) {
                            var_3_38 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_107 + 1 + (((var_17 - temp_2_107) & 7 & 7) * 0xFF)];
                            temp_2_108 = sp0 ^ (s32) var_17;
                            var_3_38 = sp4 ^ temp_2_108;
                            sp0 = temp_2_108;
                            sp4 = var_3_38;
                        }
                        if ((var_3_38 ^ 0xA) != 0) {
                            temp_2_109 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                            if (temp_2_109 == 0) {
                                var_3_39 = 0;
                            } else {
                                *sp = (u8) (&D_L39_004997E0)[temp_2_109 + 1 + (((var_17 - temp_2_109) & 7 & 7) * 0xFF)];
                                temp_2_110 = sp0 ^ (s32) var_17;
                                var_3_39 = sp4 ^ temp_2_110;
                                sp0 = temp_2_110;
                                sp4 = var_3_39;
                            }
                            if ((var_3_39 ^ 0x10) == 0) {
                                goto block_693;
                            }
                            goto block_700;
                        }
block_693:
                        var_f1 = (*(f32 *)((u8 *)(arg0) + 0x208));
                        var_f0 = 0.9f;
                        if (var_f1 < 0.9f) {
                            temp_16_8 = arg0 + 0x120;
                            if ((*(u8 *)((u8 *)(arg0) + 0x216)) != 0) {
                                var_f0 = func_0038CEA8(temp_16_8);
                                var_f1 = 0.14000002f;
                                if (var_f0 > 0.14000002f) {
                                    temp_f20_2 = func_0038CEA8(arg0 + 0x140);
                                    var_f1 = 0.5f;
                                    var_f0 = func_0038CEA8(temp_16_8) * 0.5f;
                                    if ((temp_f20_2 < var_f0) && ((*(s32 *)((u8 *)(arg0) + 0x1568)) == 0)) {
                                        var_f1 = (*(f32 *)((u8 *)(arg0) + 0x2AC));
                                        var_f0 = 2.0f;
                                        if (var_f1 < 2.0f) {
                                            var_5 = 0x79;
                                            goto block_1027;
                                        }
                                    }
                                }
                            }
                        }
block_700:
                        goto block_701;
                    }
block_701:
                    var_19_2 = 0;
                    if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) == 0) {
                        var_3_40 = 0;
                    } else {
                        temp_2_111 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                        *sp = (u8) (&D_L39_004997E0)[temp_2_111 + 1 + (((var_17 - temp_2_111) & 7 & 7) * 0xFF)];
                        temp_2_112 = sp0 ^ (s32) var_17;
                        var_3_40 = sp4 ^ temp_2_112;
                        sp0 = temp_2_112;
                        sp4 = var_3_40;
                    }
                    if ((var_3_40 ^ 0xE) == 0) {
                        var_f1 = (*(f32 *)((u8 *)(arg0) + 0x628));
                        var_f0 = 35.0f;
                        if (var_f1 < 35.0f) {
                            var_19_2 = 1;
                        }
                    }
                    temp_4_13 = (*(s16 *)((u8 *)(arg0) + 0x14BC));
                    temp_3_13 = (*(s32 *)((u8 *)(arg0) + 0x2F0));
                    if (temp_4_13 < temp_3_13) {
                        temp_2_113 = (*(u8 *)((u8 *)(arg0) + 0x14AD));
                        if (temp_3_13 == (temp_4_13 + 1)) {
                            if (temp_2_113 == 0) {
                                if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                    temp_2_114 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_114 + 1 + (((var_17 - temp_2_114) & 7 & 7) * 0xFF)];
                                    temp_2_115 = sp0 ^ (s32) var_17;
                                    var_3_41 = sp4 ^ temp_2_115;
                                    sp0 = temp_2_115;
                                    sp4 = var_3_41;
                                } else {
                                    var_3_41 = 0;
                                }
                                if ((var_3_41 ^ 0xE) != 0) {
                                    func_L39_00632458(arg0, arg0 + 0xA0, arg0 + 0x120, &sp30, (*(f32 *)((u8 *)(arg0) + 0x1530)));
                                    func_L39_0062B740(arg0, (*(f32 *)((u8 *)(arg0) + 0x14D8)), (f32) sp30, (*(f32 *)((u8 *)(arg0) + 0x1524)), 0xBF800000);
                                    var_f0 = (*(f32 *)((u8 *)(arg0) + 0x610));
                                    if (var_f0 > 1.5f) {
                                        (*(f32 *)((u8 *)(arg0) + 0x610)) = 1.5f;
                                    }
                                }
                            } else {
                                var_f0 = 0.0f;
                                var_f13_2 = (f32) ((*(s32 *)((u8 *)(arg0) + 0x1440)) - temp_3_13);
                                if (var_f13_2 > 0.0f) {
                                    var_f12_3 = (*(f32 *)((u8 *)(arg0) + 0x1448));
                                    goto block_735;
                                }
                            }
                        } else {
                            if (temp_2_113 == 0) {
                                goto block_736;
                            }
                            temp_4_14 = (*(s32 *)((u8 *)(arg0) + 0x1440));
                            if (temp_3_13 < temp_4_14) {
                                goto block_736;
                            }
                            if (temp_3_13 >= (*(s32 *)((u8 *)(arg0) + 0x1444))) {
block_736:
                                if ((*(s32 *)((u8 *)(arg0) + 0x2C8)) == 1) {
                                    var_f0 = func_L39_00647FE0(arg0, 3, 0x18, 1);
                                    var_f1 = 0 /* second half of f64 */;
                                }
                                temp_2_116 = (*(u8 *)((u8 *)(arg0) + 0x14AC));
                                if (temp_2_116 != 0) {
                                    (*(u8 *)((u8 *)(arg0) + 0x14AC)) = (u8) (temp_2_116 + 1);
                                } else if (((*(s16 *)((u8 *)(arg0) + 0x2DE)) == 0) && ((*(u8 *)((u8 *)(arg0) + 0x14AE)) != 0) && (var_19_2 == 0)) {
                                    func_L39_0063A2E8(arg0);
                                    (*(u8 *)((u8 *)(arg0) + 0x14AC)) = 1U;
                                    if (((*(f32 *)((u8 *)(arg0) + 0x2468)) < 0.2f) && ((*(f32 *)((u8 *)(arg0) + 0xFB4)) > 0.050000004f)) {
                                        (*(f32 *)((u8 *)(arg0) + 0xFB4)) = 0.050000004f;
                                    }
                                    var_f0 = func_L32_004FD190(arg0, 5, 2, 0, 1, 0x3C83126F, 0x3B03126F);
                                    var_f1 = 0 /* second half of f64 */;
                                    if (var_19_2 == 0) {
                                        var_f1 = 1.5f;
                                        var_f0 = (*(f32 *)((u8 *)(arg0) + 0x14DC)) - 1.5f;
                                        if ((*(f32 *)((u8 *)(arg0) + 0x628)) < var_f0) {
                                            var_f0 = func_L39_0062B4A8(arg0, func_L39_0063D0F0(arg0, (*(u8 *)((u8 *)(temp_23) + 0x43))), 0x3FC00002, 0, 6.0f);
                                            var_f1 = 0 /* second half of f64 */;
                                        }
                                    }
                                }
                                if ((*(u8 *)((u8 *)(arg0) + 0x14AC)) == 0) {
                                    if ((*(u8 *)((u8 *)(arg0) + 0x14AE)) != 0) {
                                        temp_2_117 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                        if ((s32) (*(u8 *)((u8 *)(temp_23) + 0x41)) < (s32)(var_f1)) {
                                            if (temp_2_117 == 0) {
                                                var_3_42 = 0;
                                            } else {
                                                *sp = (u8) (&D_L39_004997E0)[temp_2_117 + 1 + (((var_17 - temp_2_117) & 7 & 7) * 0xFF)];
                                                temp_2_118 = sp0 ^ (s32) var_17;
                                                var_3_42 = sp4 ^ temp_2_118;
                                                sp0 = temp_2_118;
                                                sp4 = var_3_42;
                                            }
                                            if (((var_3_42 ^ 0xE) == 0) && ((*(f32 *)((u8 *)(arg0) + 0x628)) < 37.0f)) {
                                                func_003C4138(arg0 + 0x610, 1.0f, 0.216000021f);
                                            } else {
                                                func_L39_0063C000(arg0, 0x42700000, (*(f32 *)((u8 *)(arg0) + 0x1530)), 0xBF800000);
                                                temp_f1_2 = 0 /* second half of f64 */;
                                                (*(s16 *)((u8 *)(arg0) + 0x14BE)) = temp_f1_2;
                                                func_L39_0062B740(arg0, (*(f32 *)((u8 *)(arg0) + 0x14DC)), (f32) temp_f1_2, (*(f32 *)((u8 *)(arg0) + 0x1524)), 0x3E9374BD);
                                            }
                                            if ((var_19_2 == 0) && ((*(f32 *)((u8 *)(arg0) + 0x610)) > 1.8f)) {
                                                func_L39_0062B4A8(arg0, func_L39_0063D0F0(arg0, (*(u8 *)((u8 *)(temp_23) + 0x43))), 0 /* Read from unset register $f3 */ + 2, 0, (f32) ((*(s16 *)((u8 *)(arg0) + 0x14BE)) + 3));
                                            }
                                            if ((*(f32 *)((u8 *)(arg0) + 0x610)) < 0.2f) {
                                                (*(f32 *)((u8 *)(arg0) + 0x610)) = 0.2f;
                                            }
                                            if ((*(f32 *)((u8 *)(arg0) + 0x610)) > 2.7f) {
                                                (*(f32 *)((u8 *)(arg0) + 0x610)) = 2.7f;
                                            }
                                        }
                                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                            temp_2_119 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_119 + 1 + (((var_17 - temp_2_119) & 7 & 7) * 0xFF)];
                                            temp_2_120 = sp0 ^ (s32) var_17;
                                            var_3_43 = sp4 ^ temp_2_120;
                                            sp0 = temp_2_120;
                                            sp4 = var_3_43;
                                        } else {
                                            var_3_43 = 0;
                                        }
                                        if (((var_3_43 ^ 9) == 0) && (((*(f32 *)((u8 *)(arg0) + 0x14DC)) - (*(f32 *)((u8 *)(arg0) + 0x628))) > 6.0f) && ((func_L39_0063D0F0(arg0, (*(u8 *)((u8 *)(temp_23) + 0x42))) == 8) || (func_L39_0063D0F0(arg0, (*(u8 *)((u8 *)(temp_23) + 0x42))) == 9)) && ((*(u8 *)((u8 *)(temp_23) + 0x42)) == (*(u8 *)((u8 *)(temp_23) + 0x43))) && ((*(f32 *)((u8 *)(arg0) + 0xFB0)) < (D_L39_00246010 * 0.020000001f * 0.1f)) && ((*(f32 *)((u8 *)(arg0) + 0x1A4)) < 0.050000004f)) {
                                            temp_f1_3 = (*(f32 *)((u8 *)(arg0) + 0x610));
                                            var_f12_4 = 7.0f / temp_f1_3;
                                            if (var_f12_4 > 8.0f) {
                                                var_f12_4 = 8.0f;
                                            }
                                            temp_6 = (s32)(temp_f1_3) + 4;
                                            func_L39_0062B4A8(arg0, 7, (s32) (temp_6 + (temp_6 >> 0x1F)) >> 1, 0, var_f12_4);
                                            if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) == 0) {
                                                temp_2_121 = D_L39_004997E0 + 1;
                                                D_L39_004997E0 = temp_2_121;
                                                (*(u8 *)((u8 *)(arg0) + 0x19E4)) = temp_2_121;
                                            } else {
                                                temp_4_15 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                                (*(u8 *)((u8 *)(arg0) + 0x19E4)) = (u8) D_L39_004997E1;
                                                D_L39_004997E1 = temp_4_15;
                                            }
                                            temp_3_14 = *((((u32) ((s32) var_17 * D_L39_0024B9C8) % 510U) * 4) + &D_L39_004997E0);
                                            sp4 = temp_3_14 ^ 7;
                                            sp0 = (s32) var_17 ^ temp_3_14;
                                            (&D_L39_004997E0)[*var_17 + 1 + (((var_17 - *var_17) & 7 & 7) * 0xFF)] = *sp;
                                        }
                                        var_f0 = (*(f32 *)((u8 *)(arg0) + 0x628));
                                        if (0 /* Read from unset register $f2 */ == (s32)(var_f0)) {
                                            (*(f32 *)((u8 *)(arg0) + 0x610)) = 0.0f;
                                        }
                                    }
                                } else {
                                    var_f0 = 1.0f;
                                    (*(f32 *)((u8 *)(arg0) + 0x610)) = 1.0f;
                                }
                                if ((*(u8 *)((u8 *)(arg0) + 0x14AC)) == 0) {
                                    goto block_835;
                                }
                                temp_2_122 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                if (temp_2_122 == 0) {
                                    var_3_44 = 0;
                                } else {
                                    *sp = (u8) (&D_L39_004997E0)[temp_2_122 + 1 + (((var_17 - temp_2_122) & 7 & 7) * 0xFF)];
                                    temp_2_123 = sp0 ^ (s32) var_17;
                                    var_3_44 = sp4 ^ temp_2_123;
                                    sp0 = temp_2_123;
                                    sp4 = var_3_44;
                                }
                                if ((var_3_44 ^ 0xA) != 0) {
                                    if ((*(u8 *)((u8 *)(arg0) + 0x14AC)) == 0) {
                                        goto block_835;
                                    }
                                    if ((*(u8 *)((u8 *)(arg0) + 0x378)) != 0) {
                                        goto block_835;
                                    }
                                    if ((*(s16 *)((u8 *)(arg0) + 0x320)) != 0) {
                                        goto block_835;
                                    }
                                    temp_ret_30 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 7, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                                    var_f0 = (f32)(temp_ret_30);
                                    if (temp_ret_30 == 0) {
                                        goto block_835;
                                    }
                                    if ((*(s16 *)((u8 *)(arg0) + 0x2DE)) >= 3) {
block_835:
                                        if ((*(u8 *)((u8 *)(arg0) + 0x14AC)) < 2U) {
                                            goto block_845;
                                        }
                                        temp_2_124 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                        if (temp_2_124 == 0) {
                                            var_3_45 = 0;
                                        } else {
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_124 + 1 + (((var_17 - temp_2_124) & 7 & 7) * 0xFF)];
                                            temp_2_125 = sp0 ^ (s32) var_17;
                                            var_3_45 = sp4 ^ temp_2_125;
                                            sp0 = temp_2_125;
                                            sp4 = var_3_45;
                                        }
                                        if ((var_3_45 ^ 0xA) == 0) {
block_845:
                                            if (((*(u8 *)((u8 *)(arg0) + 0x14AE)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= (*(s16 *)((u8 *)(arg0) + 0x153A)))) {
                                                var_f0 = (*(f32 *)((u8 *)(arg0) + 0x1520));
                                                if (var_f0 < (*(f32 *)((u8 *)(arg0) + 0x2AC))) {
                                                    var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 6, 1, 0, 1);
                                                }
                                            }
                                        } else {
                                            var_f0 = func_L39_00638848(arg0);
                                        }
                                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                            temp_2_126 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_126 + 1 + (((var_17 - temp_2_126) & 7 & 7) * 0xFF)];
                                            temp_2_127 = sp0 ^ (s32) var_17;
                                            var_3_46 = sp4 ^ temp_2_127;
                                            sp0 = temp_2_127;
                                            sp4 = var_3_46;
                                        } else {
                                            var_3_46 = 0;
                                        }
                                        if (((var_3_46 ^ 0x10) == 0) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x33)) {
                                            var_f0 = 1.5f;
                                            if ((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 1.5f) {
                                                var_5 = 6;
                                                goto block_1027;
                                            }
                                        }
                                        var_12_3 = 0;
                                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) == 0) {
                                            var_3_47 = 0;
                                            var_11 = arg0 + 0x310;
                                        } else {
                                            temp_2_128 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            var_11 = arg0 + 0x310;
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_128 + 1 + (((var_17 - temp_2_128) & 7 & 7) * 0xFF)];
                                            temp_2_129 = sp0 ^ (s32) var_17;
                                            var_3_47 = sp4 ^ temp_2_129;
                                            sp0 = temp_2_129;
                                            sp4 = var_3_47;
                                        }
                                        if ((var_3_47 ^ 7) != 0) {
                                            temp_2_130 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            if (temp_2_130 == 0) {
                                                var_3_48 = 0;
                                            } else {
                                                *sp = (u8) (&D_L39_004997E0)[temp_2_130 + 1 + (((var_17 - temp_2_130) & 7 & 7) * 0xFF)];
                                                temp_2_131 = sp0 ^ (s32) var_17;
                                                var_3_48 = sp4 ^ temp_2_131;
                                                sp0 = temp_2_131;
                                                sp4 = var_3_48;
                                            }
                                            if ((var_3_48 ^ 9) != 0) {
                                                temp_2_132 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                                if (temp_2_132 == 0) {
                                                    var_3_49 = 0;
                                                } else {
                                                    *sp = (u8) (&D_L39_004997E0)[temp_2_132 + 1 + (((var_17 - temp_2_132) & 7 & 7) * 0xFF)];
                                                    temp_2_133 = sp0 ^ (s32) var_17;
                                                    var_3_49 = sp4 ^ temp_2_133;
                                                    sp0 = temp_2_133;
                                                    sp4 = var_3_49;
                                                }
                                                if ((var_3_49 ^ 0x11) == 0) {
                                                    goto block_870;
                                                }
                                            } else {
                                                goto block_870;
                                            }
                                        } else {
block_870:
                                            var_12_3 = 1;
                                        }
                                        if ((*(u8 *)((u8 *)(arg0) + 0x310)) != 0) {
                                            temp_2_134 = (*(u8 *)((u8 *)(arg0) + 0x310));
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_134 + 1 + (((var_11 - temp_2_134) & 7 & 7) * 0xFF)];
                                            temp_3_15 = sp0 ^ (s32) var_11;
                                            temp_2_135 = sp4 ^ temp_3_15;
                                            sp0 = temp_3_15;
                                            temp_4_16 = temp_2_135 >> 0x10;
                                            var_4_4 = temp_4_16 / (u32) (((temp_2_135 ^ temp_4_16) << 0x10) + 1);
                                            sp4 = var_4_4;
                                        } else {
                                            var_4_4 = 0;
                                        }
                                        if (var_4_4 != 0) {
                                            temp_2_136 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            if (((*(u8 *)((u8 *)(arg0) + 0x14AC)) == 0) && (var_12_3 != 0)) {
                                                if (temp_2_136 == 0) {
                                                    var_3_50 = 0;
                                                } else {
                                                    *sp = (u8) (&D_L39_004997E0)[temp_2_136 + 1 + (((var_17 - temp_2_136) & 7 & 7) * 0xFF)];
                                                    temp_2_137 = sp0 ^ (s32) var_17;
                                                    var_3_50 = sp4 ^ temp_2_137;
                                                    sp0 = temp_2_137;
                                                    sp4 = var_3_50;
                                                }
                                                if (((var_3_50 ^ 0x11) != 0) || ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x16)) {
                                                    if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) == 0) {
                                                        var_3_51 = 0;
                                                    } else {
                                                        temp_2_138 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                                        *sp = (u8) (&D_L39_004997E0)[temp_2_138 + 1 + (((var_17 - temp_2_138) & 7 & 7) * 0xFF)];
                                                        temp_2_139 = sp0 ^ (s32) var_17;
                                                        var_3_51 = sp4 ^ temp_2_139;
                                                        sp0 = temp_2_139;
                                                        sp4 = var_3_51;
                                                    }
                                                    temp_ret_31 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), ((var_3_51 ^ 0x11) == 0) ? 6 : 6, &sp34, (*(void **)((u8 *)(arg0) + 0x2534)));
                                                    var_f0 = (f32)(temp_ret_31);
                                                    if ((temp_ret_31 != 0) && (sp34 < (*(s32 *)((u8 *)(arg0) + 0x2F0)))) {
                                                        var_5 = 0x11;
                                                        goto block_1027;
                                                    }
                                                    goto block_890;
                                                }
                                                goto block_891;
                                            }
                                            goto block_891;
                                        }
block_890:
block_891:
                                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                            temp_2_140 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_140 + 1 + (((var_17 - temp_2_140) & 7 & 7) * 0xFF)];
                                            temp_2_141 = sp0 ^ (s32) var_17;
                                            var_3_52 = sp4 ^ temp_2_141;
                                            sp0 = temp_2_141;
                                            sp4 = var_3_52;
                                        } else {
                                            var_3_52 = 0;
                                        }
                                        if ((var_3_52 ^ 0xA) != 0) {
                                            temp_2_142 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            if (temp_2_142 == 0) {
                                                var_3_53 = 0;
                                            } else {
                                                *sp = (u8) (&D_L39_004997E0)[temp_2_142 + 1 + (((var_17 - temp_2_142) & 7 & 7) * 0xFF)];
                                                temp_2_143 = sp0 ^ (s32) var_17;
                                                var_3_53 = sp4 ^ temp_2_143;
                                                sp0 = temp_2_143;
                                                sp4 = var_3_53;
                                            }
                                            if ((var_3_53 ^ 0x10) == 0) {
                                                goto block_901;
                                            }
                                        } else {
block_901:
                                            if (((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x16) && ((*(s16 *)((u8 *)(arg0) + 0x2DA)) != 0)) {
                                                (*(s16 *)((u8 *)(arg0) + 0x1536)) = 0x11;
                                            }
                                        }
                                        if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                            temp_2_144 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_144 + 1 + (((var_17 - temp_2_144) & 7 & 7) * 0xFF)];
                                            temp_2_145 = sp0 ^ (s32) var_17;
                                            sp0 = temp_2_145;
                                            sp4 ^= temp_2_145;
                                        }
                                        temp_2_146 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                        if (temp_2_146 == 0) {
                                            var_3_54 = 0;
                                        } else {
                                            *sp = (u8) (&D_L39_004997E0)[temp_2_146 + 1 + (((var_17 - temp_2_146) & 7 & 7) * 0xFF)];
                                            temp_2_147 = sp0 ^ (s32) var_17;
                                            var_3_54 = sp4 ^ temp_2_147;
                                            sp0 = temp_2_147;
                                            sp4 = var_3_54;
                                        }
                                        if ((var_3_54 ^ 0xE) == 0) {
                                            var_f0 = 4.0f;
                                            if ((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 4.0f) {
                                                if ((*(u8 *)((u8 *)(arg0) + 0x14AE)) == 0) {
                                                    var_f0 = (*(f32 *)((u8 *)(arg0) + 0x610));
                                                    if (var_f0 < 1.3f) {
                                                        var_f0 = func_003C4138(arg0 + 0x610, 1.29999995f, 0.120000005f);
                                                    }
                                                }
                                                (*(s16 *)((u8 *)(arg0) + 0x1536)) = 0xE;
                                            }
                                        }
                                        temp_16_9 = (*(s32 *)((u8 *)(arg0) + 0x2F0)) - 4;
                                        temp_16_10 = (temp_16_9 <= 1) ? 2 : temp_16_9;
                                        temp_16_11 = (temp_16_10 >= 0x1A) ? 0x19 : temp_16_10;
                                        if (!((*(s64 *)((u8 *)(arg0) + 0x14A8)) & (((0xFF00 << 0x18) | 0xFF00) << 0x18))) {
                                            temp_ret_32 = func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), temp_16_11, 0, (*(void **)((u8 *)(arg0) + 0x2534)));
                                            var_f0 = (f32)(temp_ret_32);
                                            temp_2_148 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            if (temp_ret_32 == 0) {
                                                if (temp_2_148 == 0) {
                                                    var_3_55 = 0;
                                                } else {
                                                    *sp = (u8) (&D_L39_004997E0)[temp_2_148 + 1 + (((var_17 - temp_2_148) & 7 & 7) * 0xFF)];
                                                    temp_2_149 = sp0 ^ (s32) var_17;
                                                    var_3_55 = sp4 ^ temp_2_149;
                                                    sp0 = temp_2_149;
                                                    sp4 = var_3_55;
                                                }
                                                temp_2_150 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                                if ((var_3_55 ^ 0xE) != 0) {
                                                    if (temp_2_150 == 0) {
                                                        var_3_56 = 0;
                                                    } else {
                                                        *sp = (u8) (&D_L39_004997E0)[temp_2_150 + 1 + (((var_17 - temp_2_150) & 7 & 7) * 0xFF)];
                                                        temp_2_151 = sp0 ^ (s32) var_17;
                                                        var_3_56 = sp4 ^ temp_2_151;
                                                        sp0 = temp_2_151;
                                                        sp4 = var_3_56;
                                                    }
                                                    temp_2_152 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                                    if ((var_3_56 ^ 0xF) != 0) {
                                                        if (temp_2_152 == 0) {
                                                            var_3_57 = 0;
                                                        } else {
                                                            *sp = (u8) (&D_L39_004997E0)[temp_2_152 + 1 + (((var_17 - temp_2_152) & 7 & 7) * 0xFF)];
                                                            temp_2_153 = sp0 ^ (s32) var_17;
                                                            var_3_57 = sp4 ^ temp_2_153;
                                                            sp0 = temp_2_153;
                                                            sp4 = var_3_57;
                                                        }
                                                        if ((var_3_57 ^ 0xD) == 0) {
                                                            goto block_930;
                                                        }
                                                    } else {
                                                        goto block_930;
                                                    }
                                                } else {
                                                    goto block_930;
                                                }
                                            } else {
block_930:
                                                if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                                    temp_2_154 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                                    *sp = (u8) (&D_L39_004997E0)[temp_2_154 + 1 + (((var_17 - temp_2_154) & 7 & 7) * 0xFF)];
                                                    temp_2_155 = sp0 ^ (s32) var_17;
                                                    var_3_58 = sp4 ^ temp_2_155;
                                                    sp0 = temp_2_155;
                                                    sp4 = var_3_58;
                                                } else {
                                                    var_3_58 = 0;
                                                }
                                                if (((var_3_58 ^ 0xE) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x1A07)) == 0) && (((*(u8 *)((u8 *)(arg0) + 0x378)) == 0) || (var_f0 = 0.4f, !((*(f32 *)((u8 *)(arg0) + 0x2AC)) < 0.4f))) && ((*(u8 *)((u8 *)(arg0) + 0x153F)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0xD) && (((*(u8 *)((u8 *)(arg0) + 0x14AE)) == 0) || ((var_f0 = 0.7f, ((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 0.7f)) && (var_f0 = fabsf(func_L39_00632678(arg0, arg0 + 0x120)), (var_f0 < 0.11600001f))))) {
                                                    var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0xE, 1, 0, 1);
                                                }
                                            }
                                        }
                                        if ((*(s32 *)((u8 *)(arg0) + 0x1568)) != 0) {
                                            temp_2_156 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                            if (temp_2_156 == 0) {
                                                var_3_59 = 0;
                                            } else {
                                                *sp = (u8) (&D_L39_004997E0)[temp_2_156 + 1 + (((var_17 - temp_2_156) & 7 & 7) * 0xFF)];
                                                temp_2_157 = sp0 ^ (s32) var_17;
                                                var_3_59 = sp4 ^ temp_2_157;
                                                sp0 = temp_2_157;
                                                sp4 = var_3_59;
                                            }
                                            if ((var_3_59 ^ 0xB) != 0) {
                                                var_5 = 0x17;
                                                goto block_1027;
                                            }
                                        }
                                    } else {
                                        if (((*(s16 *)((u8 *)(arg0) + 0x3E4)) != 0) || (((*(s32 *)((u8 *)(arg0) + 0x1310)) == 1) && (func_L01_004606E8(0x28, 2, 0, (*(void **)((u8 *)(arg0) + 0x2534))) != 0) && (func_L39_006212E8(arg0) != 0xA))) {
                                            if ((*(u8 *)((u8 *)(arg0) + 0x19E4)) != 0) {
                                                temp_2_158 = (*(u8 *)((u8 *)(arg0) + 0x19E4));
                                                *sp = (u8) (&D_L39_004997E0)[temp_2_158 + 1 + (((var_17 - temp_2_158) & 7 & 7) * 0xFF)];
                                                temp_2_159 = sp0 ^ (s32) var_17;
                                                var_3_60 = sp4 ^ temp_2_159;
                                                sp0 = temp_2_159;
                                                sp4 = var_3_60;
                                            } else {
                                                var_3_60 = 0;
                                            }
                                            if (((var_3_60 ^ 0x10) != 0) && ((*(f32 *)((u8 *)(arg0) + 0x2468)) > 0.9f) && (func_L39_00629DE0(arg0) != 2) && (((*(u8 *)((u8 *)((&D_1A5810 + (*(s32 *)((u8 *)(arg0) + 0x2544)))) + 0xA4)) != 2) || ((*(u8 *)((u8 *)(arg0) + 0x3E7)) != 3))) {
                                                var_5 = 0xB;
                                            } else {
                                                goto block_831;
                                            }
                                        } else {
block_831:
                                            if ((D_L39_00246004 < (*(f32 *)((u8 *)(arg0) + 0xFB0))) && (func_0038DBA0((*(f32 *)((u8 *)(arg0) + 0xFD0)), (*(f32 *)((u8 *)(arg0) + 0xB8))) < 1.0471976f) && ((D_L39_00246010 * 0.020000001f * 0.85f) < (*(f32 *)((u8 *)(arg0) + 0x1A4)))) {
                                                var_5 = 9;
                                            } else {
                                                goto block_1025;
                                            }
                                        }
                                        goto block_1027;
                                    }
                                } else {
                                    temp_ret_33 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 3, 0, 0, 1);
                                    var_f0 = temp_ret_33;
                                    if ((s32)(temp_ret_33) != 0) {
                                        func_L39_0062B4A8(arg0, 5, 0, 0, -2.0f);
                                        temp_4_17 = arg0 + 0x190;
                                        var_f0 = func_0038CE20(temp_4_17, temp_4_17, 0x3F4CCCCD);
                                    }
                                }
                            } else {
                                var_f0 = 0.0f;
                                var_f13_2 = (f32) ((*(s32 *)((u8 *)(arg0) + 0x1450)) - temp_4_14);
                                if (var_f13_2 > 0.0f) {
                                    var_f12_3 = (*(f32 *)((u8 *)(arg0) + 0x14D8));
block_735:
                                    var_f0 = func_L39_0062B740(arg0, var_f12_3, var_f13_2, (*(f32 *)((u8 *)(arg0) + 0x1524)), 0xBF800000);
                                }
                            }
                        }
                    }
                    goto block_1031;
                case 0x16:
                    var_f0 = 12.5f;
                    if (((*(f32 *)((u8 *)(arg0) + 0x628)) > 12.5f) && ((*(s16 *)((u8 *)(arg0) + 0x2DE)) != 0)) {
                        var_f0 = 1.0f;
                        if ((*(f32 *)((u8 *)(arg0) + 0x2AC)) > 1.0f) {
                            var_5 = 6;
                            goto block_1027;
                        }
                    }
                    if ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x17) {
                        temp_2_160 = (*(u8 *)((u8 *)(arg0) + 0x2476));
                        if (temp_2_160 == 0) {
                            var_f0_5 = 0;
                        } else {
                            *sp = (u8) (&D_L39_004997E0)[temp_2_160 + 1 + (((temp_11_2 - temp_2_160) & 7 & 7) * 0xFF)];
                            temp_2_161 = sp0 ^ (s32) temp_11_2;
                            sp0 = temp_2_161;
                            sp4 ^= temp_2_161;
                            var_f0_5 = sp4;
                        }
                        var_2_14 = 1;
                        if (!((f32)(var_f0_5) <= 0.0f)) {
                            var_2_14 = 0;
                        }
                        if (var_2_14 & 0xFF) {
                            var_5 = 0x39;
                            goto block_1027;
                        }
                        var_5 = 0x1D;
                        if ((*(u8 *)((u8 *)(arg0) + 0x2500)) != 0) {
                            goto block_1027;
                        }
                        var_5 = 0;
                        var_6_2 = 0;
                        goto block_1028;
                    }
                    goto block_1031;
                case 0x8E:
                    if ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2) {
                        var_f0 = func_L39_0062B4A8(arg0, 0x41, 0, 0, 2.0f);
                    }
                    if ((*(s32 *)((u8 *)(arg0) + 0x2F0)) >= 0x33) {
                        var_f0 = func_L39_00628038(arg0, 0);
                    }
                    goto block_1031;
                case 0x1:
                case 0x1D:
                    if ((*(u8 *)((u8 *)(arg0) + 0x24FE)) == 0) {
                        temp_16_12 = func_L39_0063D0F0(arg0, (*(u8 *)((u8 *)(temp_23) + 0x43)));
                        if ((temp_16_12 != func_L39_006223B0(arg0, 0)) && ((*(s32 *)((u8 *)(arg0) + 0x618)) & 2)) {
                            var_5_9 = 0;
                            if (((*(u8 *)((u8 *)(arg0) + 0x1A07)) != 0) && ((*(u8 *)((u8 *)(arg0) + 0x1A05)) != 0) && (((*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2524))) + 0x43)) == (*(s32 *)((u8 *)(arg0) + 0x2448))) || ((*(s32 *)((u8 *)(arg0) + 0x748)) != 0))) {
                                var_5_9 = 1;
                            }
                            if (var_5_9 == 0) {
                                (*(u8 *)((u8 *)(arg0) + 0x1A07)) = 0U;
                                if ((*(u8 *)((u8 *)(arg0) + 0x24FD)) != 0) {
                                    func_L39_0062B4A8(arg0, 0xD, 0, 0, 7.0f);
                                } else {
                                    func_L39_0062B4A8(arg0, func_L39_006223B0(arg0, 0), 0, 0, -2.0f);
                                }
                            }
                        }
                        if (((*(u8 *)((u8 *)(arg0) + 0x1A05)) == 0) || ((*(u8 *)((u8 *)(arg0) + 0x1A0A)) != 0)) {
                            if ((*(u8 *)((u8 *)(arg0) + 0x24FD)) == 0) {
                                if (((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) && ((*(s16 *)((u8 *)(arg0) + 0x320)) == 0)) {
                                    func_L39_0062B4A8(arg0, 0xD, 0, 0, 7.0f);
                                    (*(u8 *)((u8 *)(arg0) + 0x24FD)) = 1U;
                                    func_L39_00656DB0(arg0);
                                } else {
                                    goto block_996;
                                }
                            } else {
block_996:
                                if (!((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(8, 0 /*m2c missing*/))) {
                                    temp_3_16 = (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2524))) + 0x43));
                                    if ((temp_3_16 != 0) && (temp_3_16 != 3)) {
                                        (*(u8 *)((u8 *)(arg0) + 0x24FD)) = 0U;
                                    }
                                }
                            }
                        }
                        temp_ret_34 = func_L39_005C42E8(4, (*(s32 *)((u8 *)(arg0) + 0x2544)));
                        var_f0 = (f32)(temp_ret_34);
                        if (!((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & temp_ret_34)) {
                            temp_4_18 = (*(void **)((u8 *)(arg0) + 0x2534));
                            if (!((*(s32 *)((u8 *)(temp_4_18) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544))))) {
                                goto block_1007;
                            }
                            if (!(func_L39_005C2F50(temp_4_18) & 0x10) && ((*(s16 *)((u8 *)(arg0) + 0x320)) == 0)) {
                                var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 4, 1, 0, 1);
                                D_001D6D98 = 0;
                            } else {
block_1007:
                                (*(s32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 0, 0, 1);
                                if ((*(u8 *)((u8 *)(arg0) + 0x1A07)) != 0) {
                                    temp_ret_35 = func_L39_006212E8(arg0);
                                    var_f0 = (f32)(temp_ret_35);
                                    if (temp_ret_35 == 6) {
                                        D_001D6D98 = 0;
                                    } else {
                                        temp_ret_36 = func_L39_006212E8(arg0);
                                        var_f0 = (f32)(temp_ret_36);
                                        if (temp_ret_36 != 0xC) {
                                            goto block_1012;
                                        }
                                        goto block_1014;
                                    }
                                } else {
block_1012:
                                    temp_ret_37 = func_L39_006223B0(arg0, 1);
                                    temp_2_162 = temp_ret_37;
                                    var_f0 = (f32)(temp_ret_37);
                                    temp_2_163 = (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2524))) + 0x43));
                                    if (temp_2_163 != temp_2_162) {
                                        var_f0 = func_L39_0062B4A8(arg0, temp_2_162, 0, 0, (f32) (((temp_2_163 ^ 0x1A) == 0) ? 0xA : 7));
                                    }
block_1014:
                                    D_001D6D98 = 0;
                                }
                            }
                        }
                    } else {
                        var_f0 = 34.0f;
                        if ((*(f32 *)((u8 *)(arg0) + 0x628)) > 34.0f) {
                            (*(u8 *)((u8 *)(arg0) + 0x24FE)) = 0U;
                        }
                        if ((*(u8 *)((u8 *)(arg0) + 0x1A14)) != 0) {
                            temp_ret_38 = func_L39_00632C48(arg0, 0x42000000);
                            var_f0 = (f32)(temp_ret_38);
                            if (temp_ret_38 != 0) {
                                var_f0 = func_L39_0063BA40(arg0);
                            }
                        }
                    }
                    goto block_1031;
                case 0x1F:
                    if (((*(s32 *)((u8 *)(arg0) + 0x450)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x61C)) == 0)) {
                        var_f0 = 20.0f;
                        if ((*(f32 *)((u8 *)(arg0) + 0x628)) > 20.0f) {
                            var_5 = 0;
                            var_6_2 = 0;
                            goto block_1028;
                        }
                    }
                    goto block_1031;
                case 0x22:
                    if ((*(f32 *)((u8 *)(arg0) + 0x628)) > 19.0f) {
                        if (func_L01_004606E8(func_L39_005C42E8(0x40, (*(s32 *)((u8 *)(arg0) + 0x2544))), 9, 0, (*(void **)((u8 *)(arg0) + 0x2534))) == 0) {
                            goto block_1029;
                        }
                        if ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x2534))) + 0x1A0)) & func_L39_005C42E8(8, (*(s32 *)((u8 *)(arg0) + 0x2544)))) {
                            var_f0 = (f32)(func_L39_00638C28(arg0));
                        } else {
                            goto block_1025;
                        }
                    } else {
block_1029:
                        var_f0 = 21.0f;
                        if ((*(f32 *)((u8 *)(arg0) + 0x628)) >= 21.0f) {
                            var_f0 = (*(f32 (**)(void *, s32, s32, s32, s32))((u8 *)((*(void **)((u8 *)(arg0) + 0x14))) + 0x34))(arg0, 0, 0, 0, 1);
                        }
                    }
                    goto block_1031;
                }
            } else {
                goto block_1031;
            }
        } else {
            goto block_1031;
        }
    } else {
    case 0x5:
    case 0x8:
    case 0x1C:
    case 0x1E:
    case 0x20:
    case 0x21:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2D:
    case 0x2F:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x3A:
    case 0x3B:
    case 0x3C:
    case 0x3D:
    case 0x3E:
    case 0x3F:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4A:
    case 0x4B:
    case 0x4C:
    case 0x4D:
    case 0x4E:
    case 0x4F:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5A:
    case 0x5B:
    case 0x5C:
    case 0x5D:
    case 0x5E:
    case 0x5F:
    case 0x60:
    case 0x61:
    case 0x62:
    case 0x63:
    case 0x67:
    case 0x6A:
    case 0x6B:
    case 0x6C:
    case 0x6D:
    case 0x6E:
    case 0x71:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x77:
    case 0x7B:
    case 0x7C:
    case 0x80:
    case 0x82:
    case 0x84:
    case 0x86:
    case 0x87:
    case 0x88:
    case 0x89:
    case 0x8A:
    case 0x8B:
    case 0x8C:
    case 0x8D:
    case 0x8F:
block_1031:
        temp_11_14 = arg0 + 0x19E6;
        if ((*(u8 *)((u8 *)(arg0) + 0x19E6)) == 0) {
            var_3_61 = 0;
        } else {
            temp_2_164 = (*(u8 *)((u8 *)(arg0) + 0x19E6));
            *sp = (u8) (&D_L39_004997E0)[temp_2_164 + 1 + (((temp_11_14 - temp_2_164) & 7 & 7) * 0xFF)];
            temp_2_165 = sp0 ^ (s32) temp_11_14;
            var_3_61 = sp4 ^ temp_2_165;
            sp0 = temp_2_165;
            sp4 = var_3_61;
        }
        if (sp38 != var_3_61) {
            var_f0 = func_L39_0063A0F0(arg0);
        }
        if ((*(u8 *)((u8 *)(arg0) + 0x19E5)) != 0) {
            temp_2_166 = (*(u8 *)((u8 *)(arg0) + 0x19E5));
            *sp = (u8) (&D_L39_004997E0)[temp_2_166 + 1 + (((var_22 - temp_2_166) & 7 & 7) * 0xFF)];
            temp_2_167 = sp0 ^ (s32) var_22;
            var_3_62 = sp4 ^ temp_2_167;
            sp0 = temp_2_167;
            sp4 = var_3_62;
        } else {
            var_3_62 = 0;
        }
        if (sp3C != var_3_62) {
            (*(s32 *)((u8 *)(arg0) + 0x2F8)) = 0;
        }
        if (temp_fp != (*(u8 *)((u8 *)(temp_23) + 0x43))) {
            (*(s32 *)((u8 *)(arg0) + 0x2FC)) = 0;
        }
    }
    return var_f0;
}

#endif
