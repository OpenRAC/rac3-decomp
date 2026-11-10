/* func_L08_004DD0C0: Opus handoff (prep by Sonnet worker w5, 2026-11-08)
   Size: 15200 bytes (3800 instr), places: 1 level (08), file: src/levels/08_aquatos/L08_004DD0C0.c, flags: -O2 -G8 -fopt-stack -mno-check-zero-division (+ the check needs --as ps2as, see below)
   Step 0: one function, a switch on the new state id: jtbl_002BD960. Same routine as the family seed func_L30_004CF4B0 (hero state entry), a subset of it.
   rac2 twin: func_L12_002C8BD0 0.7011 / 2855; func_L19_002C44F8 0.7004; func_L04_002E7C08 0.6977 (weakest; the seed draft is the real twin, see below).
     Closest by far is the rac3 seed: opcode ratio 0.8364 vs func_L30_004CF4B0, 99% of this function's opcodes are found in the seed (see out/func_L30_004CF4B0.c for mapping, offsets, renames).
   Mapping: as the seed (hero object D_001A4BE0, state fields +0x25C4.., same offsets and state ids); callee/data names renamed from the seed by aligned jal and %hi/%lo pairs (tools: out/w5-tools/sib.py).
   Identical / changed / added / removed relative to the seed (retail address ranges; B = seed, A = this function):
     states of the seed that this function lacks (default here): 0x23 0x24 0x25 0x27 0x2a 0x2b 0x2c 0x2e 0x30 0x37 0x50 0x6a 0x72 0x76 0x7d 0x7e 0x7f 0x81 0x82 0x8f 0x90 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f 0xa0 0xa1 0xa3 0xa6 0xa8 0xa9 0xab 0xad 0xb0
     states only this function has (not drafted; 0xB2/0xB3 are table padding): 0xb2 0xb3
       insert  A 004DD27C-004DD27C (   0)  B 004CF670-004CF6A8 (  14)
       insert  A 004DD3B8-004DD3B8 (   0)  B 004CF7DC-004CF82C (  20)
       insert  A 004DD3EC-004DD3EC (   0)  B 004CF860-004CF978 (  70)
       insert  A 004DDBB0-004DDBB0 (   0)  B 004D013C-004D01A0 (  25)
       replace A 004DDBB8-004DDBBC (   1)  B 004D01A8-004D01F4 (  19)
       insert  A 004DDDBC-004DDDBC (   0)  B 004D03F4-004D043C (  18)
       insert  A 004DE048-004DE048 (   0)  B 004D06D0-004D0C78 ( 362)
       insert  A 004DE304-004DE304 (   0)  B 004D0F34-004D0F5C (  10)
       insert  A 004DE960-004DE960 (   0)  B 004D15D4-004D18B0 ( 183)
       insert  A 004DEC20-004DEC20 (   0)  B 004D1B78-004D1DC0 ( 146)
       insert  A 004DF5D8-004DF5D8 (   0)  B 004D2784-004D2830 (  43)
       insert  A 004DF648-004DF648 (   0)  B 004D28A0-004D2948 (  42)
       insert  A 004DFF48-004DFF48 (   0)  B 004D3248-004D3398 (  84)
       insert  A 004E00E4-004E00E4 (   0)  B 004D3534-004D3664 (  76)
       insert  A 004E048C-004E048C (   0)  B 004D3A0C-004D3EA0 ( 293)
       insert  A 004E0A18-004E0A18 (   0)  B 004D442C-004D4484 (  22)
   Draft: compiles with the file's flags under `chk.sh --as ps2as`: 3880 instr (15520 bytes) vs 3800 (15200), equal opcodes 3122 of 3800 (82.2%).
     The diff count is meaningless at this size (everything after the first insertion shifts), so measure with opcode alignment (out/w5-tools/meas.py, evalcases.py, blocks.py).
     Without ps2as the share drops by ~7 points: retail builds float constants inline (lui/ori/mtc1); the file's text_parts line has no @ps2as, so this file needs `@ps2as` (as w6 found for func_L39_0065D0A0) before it can match.
   Left for Opus: this draft is the seed draft with the states above deleted and names re-pointed, so every fix of the seed applies here too. Measured gaps are the same as the seed's (shared 7-group parameter blocks, 13-group, 2/2E/75 group, small per-state constants);
     any state listed as "only this function has" must be written from retail asm (r3asm.py func_L08_004DD0C0). Needs @ps2as on the file line.
*/
typedef int u128_t __attribute__((mode(TI)));



typedef u128_t V4_F6a70b950;
typedef struct {
    char pad0[35];        /* 0   */
    unsigned char f35;    /* 35  */
    char pad36[8];        /* 36  */
    float f44;            /* 44  */
    unsigned char f48;    /* 48  */
    unsigned char f49;    /* 49  */
    unsigned short f50;   /* 50  */
    unsigned short f52;   /* 52  */
    char pad54[2];        /* 54  */
    long long f56;        /* 56  */
    char pad64[34];       /* 64  */
    unsigned char f98;    /* 98  */
    char pad99[21];       /* 99  */
    int f120;             /* 120 */
    unsigned short f124;  /* 124 */
    char pad126[26];      /* 126 */
    int f152;             /* 152 */
    char pad156[14];      /* 156 */
    short f170;           /* 170 */
} Src_F66766f2b;

typedef struct {
    char pad0[256];       /* 0   */
    int a[4];             /* 256 */
    int b[4];             /* 272 */
    Src_F66766f2b *c[4];            /* 288 */
    float d[4];           /* 304 */
    int pad320;           /* 320 */
    Src_F66766f2b *src;             /* 324 */
    int count;            /* 328 */
} List_F66766f2b;
extern char D_00189F30[];
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_0038CB78(unsigned int *, unsigned int, int);
extern u8 D_L30_001DBCC8[8];
extern u8 D_L30_001DBCE8[8];
extern s32 D_L08_002F5A50[][11];
extern s32 D_L22_001A9010;
extern s32 D_L30_001D6740;
extern f32 D_L30_001DBBA8;
extern f32 D_L30_001DBBAC;
extern f32 D_L08_002F5BE0[][25];
extern s32 D_L08_002F5A50[][11];
extern f32 func_00282C48(f32);
extern void func_L01_00476498(s32, f32 *, s32 *, f32 *, s32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_00282DF0(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void *func_L01_00447490(void *, u32, s32);
extern void func_003C4BB0(float *, float);
extern s32 func_L01_004DFE80(s32);
extern void func_L01_004E67C0(void);
extern u32 func_L01_004E9200(s32);
extern s32 func_L01_004E9308(void);
extern f32 func_L01_004E93F8(int);
extern void func_L01_004EAA80(void);
extern s32 func_L01_004EDFA8(u8 *);
extern void func_L01_004F1190(f32);
extern f32 func_L01_004F4E20(void *, int);
extern int func_L01_004F4E70(int, int);
extern int func_L01_004FF610(void);
extern void func_L01_0050FE88(s32, s32);
extern f32 func_L01_00511408(char *);
extern void func_L01_00511508(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern int func_L01_003F1F20(unsigned int);
extern void func_L01_004E7C88(void);
extern void func_L01_0044E318(void *, char *);
extern void func_L01_0044E340(List_F66766f2b *, int, int, float);
extern void func_L01_0044E740(void *);
extern int func_L00_0035F5A0(int, int, int);
extern void func_L01_00504E38(int);
extern void func_0038CEA8(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C3A10(void *, int, int, int);
/* These calls use side effects only; their original scalar return contracts remain unqualified. */
extern void func_L01_004C67A0(void *, s32, u32, f32, f32, f32, f32);
extern void func_L01_004DFEA0(int);
extern void func_L01_004E11C0(int, int, int, int);
extern void func_L01_004E1560(void);
extern void func_L01_004E5EB8(int, int, int);
extern void func_L01_004EA638(int, int);
extern void func_L01_004EE850(int, f32);
extern void func_L01_004F2880(f32, f32, f32);
extern void func_L01_005119E0(void);
extern int func_L01_00507268(void);
extern void func_L01_0050FB40(int, int, f32);
extern void func_L00_0041E958(f32, f32, f32);
extern s32 func_L04_004EFEC0(int);
extern u32 D_001D4C38;
extern s32 D_001A7B90;
extern u8 D_001D5464[8];
extern u8 *D_L08_001E0290;
extern s32 D_L08_001E0298;
extern u32 D_001D545C;
typedef struct { u16 count; u16 pad; u32 maximum; u32 levels; } Statistics;
extern Statistics D_001A7C10[];
extern s32 D_L30_001DBCC0[2];
extern f32 D_L08_002F5BE0[][25];
extern u8 D_L22_0025FD30[];
typedef struct { u8 pad0[8]; f32 f8; u8 padC[0x450 - 0xC]; s32 i450; } L19State_1B9900;
extern s32 func_L01_005002B8(s32, s32);
extern void func_L01_00500188(void);
extern void func_L01_003F1F60(s32);
extern L19State_1B9900 D_L08_001E1D40;



/* All resident fields below are views of the single player-state object. */
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
extern Hero D_001A4BE0;

/* Changes the player's action, initializes its movement parameters and selects animation. */
s32 func_L08_004DD0C0(s32 action, s32 animate) {
    f32 dir[4];
    f32 pos[4];
    u8 *objectSnapshot;
    u8 *hit_10, *hit_29, *hit_44, *hit_45, *hit_52;
    s32 oldStep;
    u8 wasGliding;
    u8 oldWeapon;
    s32 current, mode, index;
    f32 angle_13;
    u32 animation_13;
    u32 animation_14;
    s32 selected_13;
    s32 selected_14;
    s32 selected_15;
    s32 selected_83;
    s32 selected_8, selected_9, selected_18, selected_21, selected_22, selected_52;
    u32 animation_16, animation_21, animation_22, animation_41, animation_43, animation_53;
    f32 frames;
    f32 angle_53;
    f32 value_18, value_21, value_22, value_37;
    u8 wasFlag;
    if (!func_L01_005002B8(action, animate)) return 0;
    objectSnapshot = D_001A4BE0.ptr[0x970];
    func_L01_00500188();
    oldStep = D_001A4BE0.i[0x972];
    wasGliding = D_001A4BE0.b[0x25e8];
    wasFlag = D_001A4BE0.b[0x25e7];
    D_001A4BE0.i[0x971] = action;
    D_001A4BE0.i[0x972] = 0;
    if (D_001A4BE0.b[0x25e5] == 1) D_001A4BE0.b[0x25e5] = 0;
    D_001A4BE0.b[0x25ed] = 0;
    if (D_001A4BE0.b[0x25e4] == 0) {
        *(s32 *)(D_001A4BE0.ptr[0x970] + 0x9C) = 0;
        D_001A4BE0.b[0x25ee] = 0;
        D_001A4BE0.b[0x25e8] = 0;
        D_001A4BE0.b[0x25f3] = 0;
        D_001A4BE0.b[0x25f0] = 0;
        if (D_001A4BE0.i[0xd8]) D_001A4BE0.b[0x25e7] = 0;
        func_L01_0044E740((void *)(D_001A4BE0.b + 0x1b90));
    }
    if (D_001A4BE0.h[0xfd] == 0) func_L01_003F1F60(0);
    if (D_001A4BE0.b[0x25e4] == 3 && (u32)(D_001A4BE0.i[0x971] - 0x51) >= 9 && (u32)(D_001A4BE0.i[0x971] - 0x66) >= 4 &&
        D_001A4BE0.i[0x971] != 0 && D_001A4BE0.i[0x971] != 1) { func_L01_004E7C88(); D_001A4BE0.i[0x971] = action; }
    func_L01_004EA638(D_001A4BE0.i[0x974], D_001A4BE0.i[0x971]);
    D_001A4BE0.i[0x45a] = 0;
    switch (action) {
    case 0x0:
        D_001A4BE0.i[0x973] = 0;
        D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x48a] == 0x1A) func_L01_004EAA80();
        D_001A4BE0.b[0x2877] = 0;
        D_001A4BE0.i[0x460] = func_00382498(50, 100);
        func_L01_004E67C0();
        if (D_001A4BE0.b[0x25e4]) { func_L01_00504E38(0); return 1; }
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.b[0x1474] && func_0038CED8((D_001A4BE0.b + 0x160)) > 0.00833333377f) { func_L08_004DD0C0(0x2e, 1); return 0; }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L08_004DD0C0(0x7b, 1); return 0; }
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L04_004EFEC0(0) == 0x51) func_L01_0050FB40(func_L04_004EFEC0(0), 0, 18.0f); else func_L01_0050FB40(func_L04_004EFEC0(0), 0, -1.0f);
        goto finish;
    case 0x68:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        *(u128_t *)(D_001A4BE0.b + 0x160) = 0; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L04_004EFEC0(0) == 0x51) func_L01_0050FB40(func_L04_004EFEC0(0), 0, 18.0f); else func_L01_0050FB40(func_L04_004EFEC0(0), 0, -1.0f);
        goto finish;
    case 0x3d:
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, 9.0f);
        if (D_001A4BE0.ptr[0x6c1]) func_003C3A10(D_001A4BE0.ptr[0x6c1], 0, 0, 9);
        goto finish;
    case 0x39:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x45, 0, 12.0f); goto finish;
    case 0x32: {
        s32 n;
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0x26f] = 0;
        if (D_001A4BE0.i[0x975] == 0x12) { func_L01_004F4E70(3, 0); D_001A4BE0.i[0x972] = 1; }
        else D_001A4BE0.i[0x26d] = 45;
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0x268] = 0;
        n = 12;
        if (!animate) goto finish;
        func_L01_0050FB40(0x3B, 0, n); goto finish; }
    case 0x34: {
        s32 f; s32 n;
        D_001A4BE0.i[0x973] = 17; n = 11; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x26d] = 60; D_001A4BE0.u[0xa03] = n;
        if (D_001A4BE0.i[0x975] == 0x12) { func_L01_004F4E70(3, 0); D_001A4BE0.i[0x972] = 1; }
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0x268] = 0;
        f = D_001A4BE0.i[0x974] == 0x32 ? 15 : n;
        if (animate) func_L01_0050FB40(0x3D, 0, f);
        goto finish;
    }
    case 0x33:
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.i[0x45a] = 0x68;
        selected_8 = D_001A4BE0.i[0x974] == 0x34 ? -2 : 35;
        if (!animate) goto finish;
        func_L01_0050FB40(0x3C, 0, (f32)selected_8); goto finish;
    case 0x36:
        D_001A4BE0.i[0x973] = 18; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.uh[0x4e5] = 0;
        if (D_001A4BE0.i[0x975] == 0x11) {
            func_L01_004E5EB8(3, 10, 0);
            if (D_L08_001E0290) func_L01_004C67A0(D_L08_001E0290, D_L08_001E0298, 0, D_001A4BE0.f[0x20], D_001A4BE0.f[0x21], 0.4f, 0.3f);
        } else if (D_001A4BE0.f[0x46] < -0.00833333376795f) {
            selected_9 = (s32)(func_00282C48(D_001A4BE0.f[0x46]) * 300.0f);
            if (selected_9 > 40) selected_9 = 40;
            func_L01_004E5EB8(3, selected_9, 1);
            if (D_L08_001E0290) func_L01_004C67A0(D_L08_001E0290, D_L08_001E0298, 0, D_001A4BE0.f[0x20], D_001A4BE0.f[0x21], 0.5f, -0.4f);
            D_001A4BE0.uh[0x4e5] = 75;
        }
        D_001A4BE0.f[0x1c9] = D_001A4BE0.f[0x46] * 0.37f; D_001A4BE0.i[0x1ca] = 0;
        if (D_001A4BE0.f[0x1c9] < -0.116666674614f) D_001A4BE0.f[0x1c9] = -0.116666674614f;
        D_001A4BE0.f[0x1cb] = D_001A4BE0.f[0xd4]; D_001A4BE0.u[0x1cc] = 0;
        D_001A4BE0.f[0x1c8] = (D_001A4BE0.f[0x22] - D_001A4BE0.f[0xd4]) - -0.12f;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.f[0x5a] = 0;
        func_003C4BB0((f32 *)(D_001A4BE0.b + 0x160), 0.0916666686535f);
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x3A, 0, 22.0f); goto finish;
    case 0x77: case 0x78:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.5f); D_001A4BE0.b[0x25e8] = 1; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        hit_10 = func_L01_00447490(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_10) func_L01_004DFEA0((s32)(*(f32 *)(hit_10 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 77;
        if (animate) {
            if (D_001A4BE0.i[0x971] == 0x77) func_L01_0050FB40(0x69, 3, -3.0f);
            else func_L01_0050FB40(0x68, 3, -3.0f);
            *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L08_002F5BE0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
            goto finish;
        }
        goto finish;
    case 0x35:
        D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x973] = 18; D_001A4BE0.u[0x26f] = 0;
        D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x1ca] = 45; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x5E, 0, 17.0f); goto finish;
    case 0x6c:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.h[0x4e7] > 50 && D_001A7C10[12].count < 0xFFFF) D_001A7C10[12].count++;
        if (D_001D4C38 > D_001A7C10[12].maximum) D_001A7C10[12].maximum = D_001D4C38;
        D_001A7C10[12].levels = (D_001A7C10[12].levels | (1u << D_001D545C)) | 0x80000000u;
        if (D_001A4BE0.i[0x274] > 2 && D_001A7C10[29].count < 0xFFFF) D_001A7C10[29].count++;
        if (D_001D4C38 > D_001A7C10[29].maximum) D_001A7C10[29].maximum = D_001D4C38;
        D_001A7C10[29].levels = (D_001A7C10[29].levels | (1u << D_001D545C)) | 0x80000000u;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x58, 0, 10.0f); goto finish;
    case 0x84:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x79, 0, 10.0f); goto finish;
    case 0x1:
        D_001A4BE0.u[0xa03] = 4;
        D_001A4BE0.i[0x973] = 0;
        if (D_001A4BE0.b[0x25eb]) goto finish;
        animation_16 = func_L04_004EFEC0(1);
        if (D_001A4BE0.ptr[0x970][0x43] == animation_16 || !animate) goto finish;
        func_L01_0050FB40(animation_16, 0, 18.0f); goto finish;
    case 0x2f:
        D_001A4BE0.i[0x973] = 8; D_001A4BE0.u[0xa03] = 0; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x110));
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, 5.0f); D_001A4BE0.uh[0xf6] = 7;
        goto finish;
    case 0x2: case 0x75:
        D_001A4BE0.i[0x973] = 1;
        D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x975] != 0x4 && D_001A4BE0.i[0x978] != 0x4) D_001A4BE0.f[0x6d] = func_L01_00511408((char *)(D_001A4BE0.b + 0x120));
        (*(u128_t *)(D_001A4BE0.b + 0x3d0) = *(u128_t *)(D_001A4BE0.b + 0x0));
        D_001A4BE0.u[0xfc] = 0;
        D_001A4BE0.f[0xfa] = D_001A4BE0.f[0x26];
        if (D_001A4BE0.f[0x6d] > 0.11666667461395264f) D_001A4BE0.f[0x6d] = 0.11666667461395264f;
        D_001A4BE0.b[0x3ef] = 0;
        func_L01_004EE850(0, 1.0f);
        value_18 = func_0038DBA0(D_001A4BE0.f[0x26], D_001A4BE0.f[0x68]);
        if (value_18 > 1.5707964897155762f &&
            (D_001A4BE0.i[0x975] == 0x4 || D_001A4BE0.i[0x974] == 0x3 || D_001A4BE0.i[0x977] == 0x3)) D_001A4BE0.f[0x6d] = 0;
        D_001A4BE0.i[0x45a] = 0x68;
        if (D_001A4BE0.b[0x147c]) {
            if (D_001A4BE0.h[0x1b6] == 0 || D_001A4BE0.f[0xcf] < 0.3f) { func_L08_004DD0C0(0x7b, 1); return 0; }
        }
        if (D_001A4BE0.b[0x1474] || D_001A4BE0.i[0x971] == 0x2e) {
            if (D_001A4BE0.f[0x6d] > 0.128333330f) D_001A4BE0.f[0x6d] = 0.128333330f;
            D_001A4BE0.u[0x3e] = 0;
            func_003C4BB0((f32 *)(D_001A4BE0.b + 0xf0), 0.128333330f);
            D_001A4BE0.i[0x971] = 0x2e; D_001A4BE0.u[0xf9] = 0;
            func_L01_0050FB40(0x37, 0, 8.0f); goto finish;
        }
        if (D_001A4BE0.b[0x25ea] || D_001A4BE0.i[0x971] == 0x75) {
            D_001A4BE0.i[0x971] = 0x75; func_L01_0050FB40(0x59, 0, 8.0f); goto finish;
        }
        D_001A4BE0.i[0x972] = 0;
        D_001A4BE0.b[0x3ec] = 0; D_001A4BE0.b[0x3ee] = 0;
        if (!animate) goto finish;
        selected_18 = D_001A4BE0.i[0xa14] == 1 ? 12 : 8;
        if (D_001A4BE0.i[0x977] == 0x22 || D_001A4BE0.i[0x974] == 0x22) selected_18 = 15;
        if (D_001A4BE0.i[0x977] == 0x88 || D_001A4BE0.i[0x974] == 0x88) selected_18 = 15;
        if (D_001A4BE0.i[0x974] == 0x13) selected_18 = 13;
        if (D_001A4BE0.i[0x977] == 0x6 || D_001A4BE0.i[0x977] == 0x2c) selected_18 = 18;
        if (D_001A4BE0.i[0x978] == 0x4 && D_001A4BE0.b[0x46c] > 5) selected_18 = 13;
        func_L01_0050FB40(D_001A4BE0.i[0x972] + 3, D_L30_001DBCC0[D_001A4BE0.i[0x972]], (f32)selected_18); goto finish;
    case 0x80: {
        s32 n = -2;
        D_001A4BE0.i[0x973] = 28; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (D_001A4BE0.i[0x49e] != 0x36) { D_001A4BE0.i[0x98d] = D_001A4BE0.i[0x49e]; D_001A4BE0.i[0x97f] = 0x36; }
        if (!animate) goto finish;
        func_L01_0050FB40(0x8B, 0, n); goto finish; }
    case 0x66:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        D_001A4BE0.b[0x25ed] = 1;
        if (!D_001A4BE0.b[0x25e4]) func_L01_004EAA80();
        if (!animate) goto finish;
        if (D_001A4BE0.b[0x25e4] == 1) { func_L01_0050FB40(2, 0, 8.0f); goto finish; }
        if (D_001A4BE0.b[0x25e4] != 0) goto finish;
        func_L01_0050FB40(D_001A4BE0.i[0x972] + 3, D_L30_001DBCC0[D_001A4BE0.i[0x972]], 8.0f); goto finish;
    case 0x3:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.b[0x1474]) { func_L08_004DD0C0(0x2e, 1); return 0; }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L08_004DD0C0(0x7b, 1); return 0; }
        if (func_L01_00507268()) return 0;
        if (func_L04_004EFEC0(0) == 0x51) {
            if (!animate) goto finish;
            if (func_L08_004DD0C0(0x0, 0)) func_L01_0050FB40(func_L04_004EFEC0(0), 0, 18.0f);
            return 0;
        }
        if (!animate) goto finish;
        animation_21 = objectSnapshot[0x42];
        {
            value_21 = D_001A4BE0.f[0x306]; selected_21 = 6;
            if (func_L01_004DFE80(animation_21) == 4 && value_21 > 3.0f && value_21 < 16.0f) selected_21 = 5;
            func_L01_0050FB40(selected_21, 4, 9.0f);
            goto finish;
        }
    case 0x67:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_L01_00511408((char *)(D_001A4BE0.b + 0x120)); (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        animation_22 = objectSnapshot[0x42]; {
            value_22 = D_001A4BE0.f[0x306]; selected_22 = 6;
            if (func_L01_004DFE80(animation_22) == 4 && value_22 > 3.0f && value_22 < 16.0f) selected_22 = 5;
            func_L01_0050FB40(selected_22, 4, 9.0f);
            goto finish;
        }
    case 0x4:
        D_001A4BE0.i[0x973] = 12; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.f[0x6d] > 0.11666667461395264f) D_001A4BE0.f[0x6d] = 0.11666667461395264f;
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L08_004DD0C0(0x7b, 1); return 0; }
        D_001A4BE0.i[0x45a] = 0x68;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        func_003C4BB0((float *)(D_001A4BE0.b + 0x160), 0.11666667461395264f);
        if (D_001A4BE0.f[0x5e] > 0.05833333730697632f) func_L01_004F4E70(9, 0);
        if (animate) {
            if (D_001A4BE0.ptr[0x970][0x42] == func_L04_004EFEC0(0)) func_L01_0050FB40(13, 2, 9.0f);
            else func_L01_0050FB40(13, 2, 14.0f);
            func_L01_0050FE88(3, 18);
        }
        goto finish;
    case 0x17:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.f[0x14b] = 0.0061111114919f; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x22];
        if (D_001A4BE0.i[0x975] == 0x4) { D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c]; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x118]; }
        D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        if (D_001A4BE0.f[0x5d] > 0.0583333373069f) func_L01_0050FB40(0x20, 0, 9.0f);
        else func_L01_0050FB40(0x20, 1, 11.0f);
        goto finish;
    case 0x18:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x21, 0, 6.0f); goto finish;
    case 0x19:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x24, 0, 6.0f); goto finish;
    case 0x1a:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x25, 0, 6.0f); goto finish;
    case 0x7b:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, 12.0f); goto finish;
    case 0x6: case 0x79:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x971] == 0x79) {
            D_001A4BE0.i[0x973] = 0x14;
            if (D_001A4BE0.b[0x25e4] == 1) {
                if (D_001D545C == 3) func_L00_0035F5A0(17, 0, (s32)D_001A4BE0.ptr[0x970]);
                else if (D_001D545C == 14) func_L00_0035F5A0(21, 0, (s32)D_001A4BE0.ptr[0x970]);
            }
        }
        D_001A4BE0.f[0x280] = 0.006111111491918564f;
        D_001A4BE0.f[0x281] = 0.0019444444915279746f;
        if (D_001A4BE0.i[0x971] == 0x79) {
            if (!D_001A4BE0.b[0x25e4]) D_001A4BE0.uh[0x142d] = func_L01_004F4E70(14, 0x20);
            D_001A4BE0.f[0x284] = func_L01_00443A18(0.05235988646745682f, 0.07272206246852875f);
            D_001A4BE0.f[0x285] = func_L01_00443A18(0.05235988646745682f, 0.07272206246852875f);
        }
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.i[0x972] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        if (D_001A4BE0.b[0x25e4] == 1) { func_L01_0050FB40(4, 0, 8.0f); return 1; }
        if (D_001A4BE0.f[0xcf] > 1.75f) { func_L01_0050FB40(11, 0, 12.0f); D_001A4BE0.i[0x972] = 1; goto finish; }
        func_L01_0050FB40(10, 0, 10.0f); goto finish;
    case 0x8: {
        s32 n = -2;
        D_001A4BE0.i[0x973] = 5; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.f[0x5c] > 0.075f) func_L01_004F1190(0.075f / D_001A4BE0.f[0x5c]);
        D_001A4BE0.i[0xa13] = 0; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(0x13, 0, n); goto finish; }
    case 0x7: case 0x9: case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11: case 0x12: case 0x1b: case 0x28: case 0x29: case 0x38: case 0x45: case 0x48: case 0x6b: case 0x73: case 0x86:
        if (D_001A4BE0.i[0x971] != 0x86 && D_001A4BE0.ptr[0xd7] &&
            (*(s16 *)(D_001A4BE0.ptr[0xd7] + 0xAA) == 0x9B9 || *(s16 *)(D_001A4BE0.ptr[0xd7] + 0xAA) == 0xF05)) {
            func_L08_004DD0C0(0x86, 1); return 0;
        }
        if (D_001A4BE0.i[0x971] != 0x73 && D_001A4BE0.h[0x1b4] == 1 && action != 0xe &&
            action != 0x38 && !D_L30_001D6740) { func_L08_004DD0C0(0x73, 1); return 0; }
        if (D_001A4BE0.i[0x974] == 0x11 && !D_001A4BE0.b[0x285e]) D_001A4BE0.b[0x285f]++;
        else D_001A4BE0.b[0x285f] = 0;
        if (D_001A4BE0.h[0xf9]) { func_L08_004DD0C0(0x87, 1); return 0; }
        if (D_001A4BE0.h[0x109]) {
            D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x972] = oldStep; D_001A4BE0.i[0x6e] = D_001A4BE0.i[0x976];
            return 0;
        }
        D_001A4BE0.i[0x973] = 4;
        if ((u32)(action - 0x28) < 2) D_001A4BE0.u[0xa03] = 3; else D_001A4BE0.u[0xa03] = 0x50;
        if (D_001A4BE0.i[0x971] == 0x7 || D_001A4BE0.i[0x971] == 0xf || D_001A4BE0.i[0x971] == 0xd ||
            (D_001A4BE0.i[0x971] == 0xb && D_001A4BE0.i[0x975] != 0x4)) {
            oldWeapon = D_001A4BE0.b[0x147f];
            func_L01_004E11C0(oldWeapon, 0, 0, 30);
            func_L01_004E11C0(oldWeapon, 1, 0, 30);
        }
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.i[0x971] != 0x12 && D_001A4BE0.b[0x1476] && D_001A4BE0.f[0x22] < D_001A4BE0.f[0xd4] + 0.5f)
            func_L01_004E5EB8(3, 0x10, 0);
        if (D_001A4BE0.i[0x971] == 0x6b) func_L01_004F4E70(8, 0);
        {
        f32 c510, c514, c4A4;
        D_001A4BE0.f[0x118] = D_001A4BE0.f[0x22];
        D_001A4BE0.f[0x13c] = 0.00825f;
        D_001A4BE0.i[0x106] = -1;
        D_001A4BE0.f[0x134] = 0.0055555556900799274f;
        D_001A4BE0.f[0x135] = 0.0030555557459592819f;
        c510 = 2.5f;
        D_001A4BE0.uh[0x27c] = D_001A4BE0.b[0x1474];
        c514 = 0.5f;
        c4A4 = 0.099166668951511383f;
        D_001A4BE0.uh[0x275] = 80; D_001A4BE0.uh[0x27d] = 70; D_001A4BE0.f[0x119] = 0.25016391277313232f;
        D_001A4BE0.f[0x11c] = 0.83333337306976318f; D_001A4BE0.b[0x46e] = 0; D_001A4BE0.b[0x46c] = 0;
        D_001A4BE0.u[0x120] = 0;
        D_001A4BE0.u[0x121] = 0; D_001A4BE0.b[0x46d] = 0; D_001A4BE0.f[0x138] = c510; D_001A4BE0.uh[0x27a] = 0; D_001A4BE0.b[0x4fc] = 0;
        D_001A4BE0.b[0x4fe] = 0; D_001A4BE0.b[0x4ff] = 0;
        D_001A4BE0.uh[0x27b] = 0; D_001A4BE0.f[0x139] = c514; D_001A4BE0.f[0x11d] = c4A4;
        D_001A4BE0.f[0x10a] = 0.0f; D_001A4BE0.b[0x46f] = 0;
        D_001A4BE0.u[0x151] = 0; D_001A4BE0.uh[0x142e] = 0;
        }

        if (D_001A4BE0.i[0x971] == 0x7) {
            D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 2.3f; D_001A4BE0.f[0x11e] = 1.28f; D_001A4BE0.f[0x136] = 1.28f; D_001A4BE0.b[0x4fc] = 1; D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.uh[0x274] = 15; D_001A4BE0.b[0x4ff] = 1; D_001A4BE0.f[0x10a] = 0.0096525000408291817f;

        }
        else if (D_001A4BE0.i[0x971] == 0x86) {
            D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x11e] = D_L30_001DBBA8; D_001A4BE0.f[0x137] = D_L30_001DBBA8 + 0.5f; D_001A4BE0.f[0x136] = D_L30_001DBBA8; D_001A4BE0.uh[0x274] = 15; D_001A4BE0.uh[0x275] = 400; D_001A4BE0.f[0x138] = 300.0f; D_001A4BE0.f[0x13c] = D_L30_001DBBAC * 0.0002777777845f; D_001A4BE0.uh[0x27b] = 1200; D_001A4BE0.uh[0x27d] = 1200; D_001A4BE0.f[0x11d] = 0.11666667461395264f;
            if (D_001D545C == 16) D_001A4BE0.f[0x11d] = 0.0f;
            func_L01_0044E318(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
            func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 70, 2, 0.0f);
            func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 35, 4, 0.0f);
            func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 17, 6, 0.0f);

        }
        else if (D_001A4BE0.i[0x971] == 0x12) {
            f32 frames18;
            D_001A4BE0.h[0x23e] = 2; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x11e] = 0.1f; frames18 = 18.0f; D_001A4BE0.f[0x126] = frames18; D_001A4BE0.f[0x127] = 28.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 0.2f; D_001A4BE0.f[0x136] = 0.1f; D_001A4BE0.uh[0x274] = 10;
            if (D_001A4BE0.f[0xa12] < 1.25f) {
                D_001A4BE0.h[0x23e] = 15; D_001A4BE0.f[0x137] = 1.98f;
                D_001A4BE0.f[0x136] = 1.95f; D_001A4BE0.f[0x11e] = 1.95f;
            } else {
                f32 step = D_001A4BE0.f[0x120];
                func_L01_00511508((V4_F6a70b950 *)(D_001A4BE0.b + 0xf0), (V4_F6a70b950 *)(D_001A4BE0.b + 0xf0), step);
                D_001A4BE0.b[0x46d] = 1; D_001A4BE0.i[0x100] = 2;
                D_001A4BE0.i[0x101] = 0x25; D_001A4BE0.f[0x102] = step; D_001A4BE0.f[0x103] = frames18;
                D_001A4BE0.u[0x104] = 0x28; D_001A4BE0.ptr[0x105] = D_L22_0025FD30;
            }
            D_001A4BE0.b[0x46f] = 1; D_001A4BE0.b[0x25e8] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x38) {
            D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f;
            D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 26.0f; D_001A4BE0.f[0x128] = 13.0f;
            D_001A4BE0.f[0x137] = 5.55f; D_001A4BE0.f[0x11e] = 5.5f;
            D_001A4BE0.f[0x136] = 5.5f; D_001A4BE0.uh[0x274] = 2; D_001A4BE0.uh[0x275] = 120; D_001A4BE0.b[0x46f] = 1;
            func_L01_004DFEA0(1);
            if (D_001A4BE0.i[0x974] == 0x38 || D_001A4BE0.i[0x977] == 0x38 || D_001A4BE0.i[0xa14] == 0) {
                D_001A4BE0.i[0x6dc]++;
                if (D_001A4BE0.i[0x6dc] > 2 || D_001A4BE0.i[0xa14] == 0) {
                    if (D_001D545C == 2 && D_L22_001A9010) func_L08_004DD0C0(0x82, 1);
                    else if (*(s32 *)(*(u8 **)(D_001A4BE0.ptr[0x970] + 0x24) + 0x1F0) != 0) func_L08_004DD0C0(0x7e, 1);
                    else func_L08_004DD0C0(0x39, 1);
                    return 0;
                }
            } else D_001A4BE0.i[0x6dc] = 0;
            D_001A4BE0.uh[0x27d] = 150; D_001A4BE0.f[0x13c] = 0.004166666884f;
            D_001A4BE0.uh[0x276] = 5; D_001A4BE0.uh[0x277] = 4;

        }
        else if (D_001A4BE0.i[0x971] == 0x6b) {
            f32 height;
            D_001A4BE0.i[0x973] = 25;
            if (D_001A4BE0.f[0x22] < D_001A4BE0.f[0xd5]) height = D_001A4BE0.f[0xd5] - D_001A4BE0.f[0x22]; else height = D_001A4BE0.f[0x120];
            D_001A4BE0.f[0x11e] = height + 1.7f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = height + 1.75f; D_001A4BE0.f[0x136] = height + 1.7f; D_001A4BE0.uh[0x274] = 19; D_001A4BE0.b[0x46f] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x28) {
            D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 28.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x11e] = 2.4f; D_001A4BE0.f[0x137] = 2.45f; D_001A4BE0.f[0x136] = 2.4f; D_001A4BE0.uh[0x274] = 17; D_001A4BE0.i[0x973] = 15; D_001A4BE0.f[0x13c] = 0.00750000030f; D_001A4BE0.i[0x18d] = 0;
            if (D_001A4BE0.b[0x147a]) {
                *(u128_t *)dir = 0;
                D_001A4BE0.f[0x11e] = 7.1f; D_001A4BE0.f[0x136] = 7.1f; D_001A4BE0.f[0x137] = 7.14999962f; D_001A4BE0.f[0x13c] = 0.00388888898f;
                dir[0] = 331.0f; dir[1] = 104.0f; dir[2] = 145.0f;
                if (func_0038CF00((D_001A4BE0.b + 0x80), dir) < 10.0f) {
                    D_001A4BE0.f[0x11e] += 0.7f; D_001A4BE0.f[0x136] += 0.7f; D_001A4BE0.f[0x137] += 0.7f;
                }
            }
        }
        else if (D_001A4BE0.i[0x971] == 0x29) {
            D_001A4BE0.f[0x11e] = 2.5f; D_001A4BE0.h[0x23e] = 2; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 31.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 2.55f; D_001A4BE0.f[0x136] = 2.5f; D_001A4BE0.uh[0x274] = 10; D_001A4BE0.i[0x973] = 15; D_001A4BE0.f[0x13c] = 0.00666666683f; D_001A4BE0.i[0x18d] = 0;
        }
        else if (D_001A4BE0.i[0x971] == 0x9) {
            D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x11e] = 1.0f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 29.0f; D_001A4BE0.f[0x128] = 11.0f; D_001A4BE0.f[0x137] = 2.7f; D_001A4BE0.f[0x136] = 1.0f; D_001A4BE0.uh[0x274] = 15; D_001A4BE0.f[0x11d] = 0.099166668951511383f; D_001A4BE0.b[0x4fc] = 1; D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.b[0x4ff] = 1;

        }
        else if (D_001A4BE0.i[0x971] == 0x73) {
            D_001A4BE0.f[0x11e] = 2.7f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.b[0x4fc] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 2.75f; D_001A4BE0.f[0x136] = 2.7f; D_001A4BE0.uh[0x274] = 5; D_001A4BE0.b[0x46f] = 1; D_001A4BE0.b[0x4fe] = 0; D_001A4BE0.b[0x4ff] = 0; D_001A4BE0.f[0x11d] = 0.11602500081062317f;

        }
        else if (D_001A4BE0.i[0x971] == 0x5b) {
            D_001A4BE0.h[0x23e] = 12; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x11e] = 4.2f; D_001A4BE0.f[0x126] = 17.0f; D_001A4BE0.f[0x127] = 22.0f; D_001A4BE0.f[0x128] = 40.0f; D_001A4BE0.f[0x137] = 120.0f; D_001A4BE0.f[0x136] = 4.2f; D_001A4BE0.uh[0x274] = 90; D_001A4BE0.f[0x13c] = 0.010277778f; D_001A4BE0.f[0x119] = 0.078539826f; D_001A4BE0.f[0x10a] = 0.019444445f;
            D_001A4BE0.f[0x11c] = func_00282C48(-0.95000005f); D_001A4BE0.f[0x139] = 2.0f; D_001A4BE0.f[0x11d] = 0.29500002f;
        }
        else if (D_001A4BE0.i[0x971] == 0x45) {
            D_001A4BE0.f[0x11e] = 1.3f; D_001A4BE0.h[0x23e] = 3; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 15.0f; D_001A4BE0.f[0x127] = 24.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 1.35f; D_001A4BE0.f[0x136] = 1.3f; D_001A4BE0.uh[0x274] = 14; D_001A4BE0.f[0x13c] = 0.0069444445f; D_001A4BE0.f[0x135] = 0.013888889f; D_001A4BE0.f[0x11d] = 0.033333335f;
        }
        else if (D_001A4BE0.i[0x971] == 0xa) {
            D_001A4BE0.f[0x11e] = 1.9f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f;
            D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 29.0f; D_001A4BE0.f[0x128] = 10.0f;
            D_001A4BE0.f[0x137] = 1.95f; D_001A4BE0.f[0x136] = 1.9f; D_001A4BE0.uh[0x274] = 14;
            D_001A4BE0.f[0x13c] = 0.003055555746f; D_001A4BE0.b[0x4fe] = 1;
            D_001A4BE0.uh[0x275] = 120; D_001A4BE0.uh[0x27d] = 90; D_001A4BE0.uh[0x27b] = 70;

        }
        else if (D_001A4BE0.i[0x971] == 0x10) {
            D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.8f;
            D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 11.0f; D_001A4BE0.f[0x11e] = 1.5f;
            D_001A4BE0.f[0x137] = 1.55f; D_001A4BE0.f[0x136] = 1.5f; D_001A4BE0.uh[0x274] = 1;
            func_L01_003F1F20(20);
            D_001A4BE0.f[0x137] = 0.9f; D_001A4BE0.f[0x11e] = 0.4f; D_001A4BE0.f[0x136] = 0.4f;
            if (D_001A4BE0.f[0x61] < 0.3333333433f) {
                func_L01_0044E318(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 40, 2, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 20, 4, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 10, 6, 0.0f);
            }
            D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.f[0x109] = 0.19166667759418488f;
            if (D_001A4BE0.f[0xcf] > 1.4f) D_001A4BE0.f[0x109] = 0.094999998807907104f;
            D_001A4BE0.f[0x13c] = 0.00236111111f; D_001A4BE0.f[0x134] = 0.012222222983837128f; D_001A4BE0.f[0x135] = 0.013888888992369175f;

        }
        else if (D_001A4BE0.i[0x971] == 0x1b) {
            D_001A4BE0.h[0x23e] = 10; D_001A4BE0.f[0x11e] = 2.0f; D_001A4BE0.f[0x122] = 0.85f;
            D_001A4BE0.f[0x126] = 20.0f; D_001A4BE0.f[0x127] = 29.0f; D_001A4BE0.f[0x128] = 19.0f;
            D_001A4BE0.f[0x137] = 2.05f; D_001A4BE0.f[0x136] = 2.0f; D_001A4BE0.f[0x139] = 1.0f;
            D_001A4BE0.f[0x13c] = 0.006944444496f; D_001A4BE0.uh[0x274] = 1; D_001A4BE0.u[0x123] = 0;
            D_001A4BE0.b[0x46f] = 1; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.b[0x4fe] = 1;

        }
        else if (D_001A4BE0.i[0x971] == 0x48) {
            D_001A4BE0.h[0x23e] = 13; D_001A4BE0.f[0x11e] = 1.55f; D_001A4BE0.f[0x122] = 0.85f; D_001A4BE0.f[0x126] = 8.0f; D_001A4BE0.f[0x127] = 14.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 1.59f; D_001A4BE0.f[0x136] = 1.55f; D_001A4BE0.uh[0x274] = 1; D_001A4BE0.u[0x123] = 0; D_001A4BE0.f[0x13c] = 0.007777778f;
        }
        else if (D_001A4BE0.i[0x971] == 0x11) {
            D_001A4BE0.h[0x23e] = 9; D_001A4BE0.f[0x122] = 0.6f;
            D_001A4BE0.f[0x126] = 12.0f; D_001A4BE0.f[0x127] = 20.0f; D_001A4BE0.f[0x128] = 10.0f; D_001A4BE0.uh[0x274] = 12;
            if (D_001A4BE0.b[0x285e]) { D_001A4BE0.f[0x11a] = 0.081666670739650726f; D_001A4BE0.f[0x137] = 3.35f; D_001A4BE0.f[0x136] = 3.3f; }
            else { D_001A4BE0.f[0x11a] = 0.028333336114883423f; D_001A4BE0.f[0x137] = 1.85f; D_001A4BE0.f[0x136] = 1.8f; }
            D_001A4BE0.b[0x46f] = 1; D_001A4BE0.f[0x11e] = D_001A4BE0.f[0x136]; func_L01_003F1F20(27);
            D_001A4BE0.uh[0x27d] = 80; D_001A4BE0.f[0x13c] = 0.008055555634f;
            (*(u128_t *)(D_001A4BE0.b + 0x4c0) = *(u128_t *)(D_001A4BE0.b + 0x4b0)); D_001A4BE0.uh[0x142e] = 1; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x4fc] = 1;

        }
        else if (D_001A4BE0.i[0x971] == 0xd) {
            D_001A4BE0.f[0x11e] = 4.0f; D_001A4BE0.f[0x126] = 26.0f; D_001A4BE0.h[0x23e] = 9;
            D_001A4BE0.f[0x127] = 38.0f; D_001A4BE0.f[0x128] = 18.0f; D_001A4BE0.f[0x137] = 4.07f;
            D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x136] = 4.0f; D_001A4BE0.uh[0x274] = 14;
            func_L01_003F1F20(20); D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x275] = 120;
            D_001A4BE0.f[0x11d] = 0.031666666269302368f; D_001A4BE0.uh[0x27b] = 37;
            if (D_001A4BE0.f[0x61] < 0.3333333433f) {
                func_L01_0044E318(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 40, 3, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 20, 5, 0.0f);
            }
            D_001A4BE0.b[0x4fe] = 1;

        }
        else if (D_001A4BE0.i[0x971] == 0xf) {
            D_001A4BE0.f[0x11e] = 1.65f; D_001A4BE0.h[0x23e] = 9;
            D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 50.0f; D_001A4BE0.f[0x127] = 64.0f;
            D_001A4BE0.f[0x128] = 28.0f; D_001A4BE0.f[0x137] = 1.7f; D_001A4BE0.f[0x136] = 1.65f;
            D_001A4BE0.uh[0x274] = 5; D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x275] = 130;
            D_001A4BE0.f[0x11d] = 0.055000003427267075f; D_001A4BE0.uh[0x27b] = 85; D_001A4BE0.uh[0xe8] = 70; D_001A4BE0.b[0x46d] = 1;
            if (D_001A7B90) D_001A4BE0.i[0x100] = 34; else D_001A4BE0.i[0x100] = 35;
            D_001A4BE0.i[0x101] = D_001A4BE0.i[0x100] + 36; D_001A4BE0.f[0x102] = 29.0f;
            D_001A4BE0.f[0x103] = 50.0f; D_001A4BE0.u[0x104] = 86; D_001A4BE0.ptr[0x105] = (u8 *)D_L30_001DBCE8;
            D_001A4BE0.b[0x4fe] = 1;

        }
        else if (D_001A4BE0.i[0x971] == 0xe) {
            f32 run = 0.7f;
            if (D_001A4BE0.f[0xcf] < 2.0f) run = (2.5f - D_001A4BE0.f[0xcf]) * 0.5f + 0.7f;
            D_001A4BE0.h[0x23e] = -1; D_001A4BE0.f[0x122] = 0.6f;
            D_001A4BE0.f[0x126] = 32.0f; D_001A4BE0.f[0x127] = 43.0f; D_001A4BE0.f[0x128] = 19.0f; D_001A4BE0.f[0x11e] = run;
            D_001A4BE0.f[0x137] = run + 0.05f; D_001A4BE0.f[0x136] = run;
            D_001A4BE0.uh[0x274] = 14; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x11d] = 0.079166673123836517f; D_001A4BE0.uh[0x27b] = 30;

        }
        else if (D_001A4BE0.i[0x971] == 0xb) {
            D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x11e] = 3.2f; D_001A4BE0.f[0x127] = 31.0f; D_001A4BE0.f[0x128] = 24.0f;
            D_001A4BE0.f[0x137] = 3.25f; D_001A4BE0.f[0x136] = 3.2f; D_001A4BE0.uh[0x274] = 14;
            D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x27d] = 50; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.b[0x46f] = 1;
            D_001A4BE0.f[0x125] = func_L01_004E93F8(10); (*(u128_t *)(D_001A4BE0.b + 0x450) = *(u128_t *)(D_001A4BE0.b + 0x0));
            D_001A4BE0.i[0x129] = func_L01_004FF610(); D_001A4BE0.f[0x124] = D_001A4BE0.f[0x68]; (*(u128_t *)(D_001A4BE0.b + 0x440) = *(u128_t *)(D_001A4BE0.b + 0x190));
            if (D_001A4BE0.f[0x5d] > 0.025000002f) D_001A4BE0.f[0x12a] = D_001A4BE0.f[0x5d]; else D_001A4BE0.f[0x12a] = 0.0f;
            D_001A4BE0.f[0x12b] = 0.0f; D_001A4BE0.b[0x4fc] = 1;
            if (D_001A4BE0.h[0xa1a] && D_001A4BE0.f[0xa09] > 0.3f) {
                D_001A4BE0.f[0x124] = D_001A4BE0.f[0x50e]; (*(u128_t *)(D_001A4BE0.b + 0x440) = *(u128_t *)(D_001A4BE0.b + 0x1420));
                D_001A4BE0.b[0x4fd] = 1; D_001A4BE0.f[0x12b] = 0.083333335816860199f;
            } else D_001A4BE0.b[0x4fd] = 0;
            D_001A4BE0.b[0x4fe] = 1;

        }
        if (D_001A4BE0.f[0x138] == 0.0f) D_001A4BE0.f[0x138] = D_001A4BE0.f[0x11e] * 1.5f;
        if (!animate) goto finish;
        if (D_001A4BE0.i[0x971] == 0x7) { func_L01_0050FB40(7, 0, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x73) { func_L01_0050FB40(7, 0, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x86) { func_L01_0050FB40(7, 0, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x12) { func_L01_0050FB40(0x6B, 1, -1.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x38) { func_L01_0050FB40(0x43, 0, 4.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x6b) { func_L01_0050FB40(7, 0, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x28) { func_L01_0050FB40(0x4D, 4, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x29) {
            s32 turn = 0x1E;
            if (func_0038DBA0(D_001A4BE0.f[0x26], func_0038D160(D_001A4BE0.f[0x15c] - D_001A4BE0.f[0x16c], D_001A4BE0.f[0x15d] - D_001A4BE0.f[0x16d])) > 1.57079649f) turn = 0x1F;
            func_L01_0050FB40(turn, 0, 5.0f); goto finish;
        }
        else if (D_001A4BE0.i[0x971] == 0x9) {
            animation_41 = 8; index = (s32)(D_001A4BE0.f[0x306]);
            if (func_L01_004DFE80(objectSnapshot[0x42]) == 4) animation_41 = D_L30_001DBCC8[index];
            func_L01_0050FB40(animation_41, 0, 5.0f); goto finish;
        }
        else if (D_001A4BE0.i[0x971] == 0x5b) { func_L01_0050FB40(4, 3, 7.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x45) { func_L01_0050FB40(7, 5, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0xa) { func_L01_0050FB40(18, 0, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x10) {
            if (D_001A4BE0.i[0x975] == 0x4 || (D_001A4BE0.i[0x974] == 0x4 && D_001A4BE0.i[0x6e] < 7)) {
                func_L01_0050FB40(0x26, 0, 8.0f); D_001A4BE0.h[0x23e] += 3; goto finish;
            }
            func_L01_0050FB40(0x26, 0, 5.0f); goto finish;
        } else if (D_001A4BE0.i[0x971] == 0x1b) { func_L01_0050FB40(0x22, 0, 4.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x8e) { func_L01_0050FB40(0x7D, 11, 9.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x48) { func_L01_0050FB40(9, 0, 4.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0x11) { frames = 7.0f; animation_41 = 0x23; { func_L01_0050FB40(animation_41, 2, frames); goto finish; } }
        else if (D_001A4BE0.i[0x971] == 0xd) { func_L01_0050FB40(17, 0, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0xe) { func_L01_0050FB40(0x16, 3, 7.0f); D_001A4BE0.f[0x300] = 0.8f; goto finish; }
        else if (D_001A4BE0.i[0x971] == 0xf) { func_L01_0050FB40(21, 0, 5.0f); goto finish; }
        else if (D_001A4BE0.i[0x971] == 0xb) {
            s32 anim = D_001A4BE0.i[0x129] + 28;
            if (D_001D5464[5]) { if (anim == 28) anim = 29; else if (anim == 29) anim = 28; }
            if (D_001A4BE0.i[0x975] == 0x4) { func_L01_0050FB40(anim, 1, 4.0f); D_001A4BE0.h[0x23e] = 1; goto finish; }
            func_L01_0050FB40(anim, 0, 5.0f); goto finish;
        }
        goto finish;
    case 0x13: case 0x14: case 0x15: case 0x22: case 0x4d: case 0x88:
        D_001A4BE0.i[0x973] = 6;
        if (D_001A4BE0.i[0x538] && (u32)(D_001A4BE0.i[0x971] - 0x13) < 3) {
            if (D_001A7C10[1].count < 0xFFFF) D_001A7C10[1].count++;
            if (D_001D4C38 > D_001A7C10[1].maximum) D_001A7C10[1].maximum = D_001D4C38;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C)) | 0x80000000u;
            
            func_L01_005119E0(); D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x973] = D_001A4BE0.i[0x975];
            goto finish;
        }
        if (action != 0x88) D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x2f5] = 1.0f; D_001A4BE0.i[0x2f2] = 0; D_001A4BE0.u[0x2f1] = 0; D_001A4BE0.uh[0x5ef] = 0;
        switch (D_001A4BE0.i[0x971]) {
        case 0x14:
            if (D_001A7C10[0].count < 0xFFFF) D_001A7C10[0].count++;
            if (D_001D4C38 > D_001A7C10[0].maximum) D_001A7C10[0].maximum = D_001D4C38;
            D_001A7C10[0].levels = (D_001A7C10[0].levels | (1u << D_001D545C)) | 0x80000000u;
            D_001A4BE0.u[0xa03] = 0x50; D_001A4BE0.h[0x5ee] = 4; D_001A4BE0.i[0x98c] = 0;
            func_L01_004F2880(8.0f, 1.047197699546814f, -1.0f); D_001A4BE0.u[0x2f8] = 0;
            if (animate) {
                selected_14 = D_001A4BE0.i[0x974] == 0xb && D_001A4BE0.i[0x976] < 42 ? 17 : 11;
                func_L01_0050FB40(0x2B, 4, (f32)selected_14);
                animation_14 = func_L01_004E9200(0);
                if (func_L01_004EDFA8((u8 *)animation_14)) func_003C3A10((u8 *)animation_14, 10, 4, selected_14 + 2);
            }
            goto finish;
        case 0x15:
            if (D_001A7C10[1].count < 0xFFFF) D_001A7C10[1].count++;
            if (D_001D4C38 > D_001A7C10[1].maximum) D_001A7C10[1].maximum = D_001D4C38;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C)) | 0x80000000u;
            
            D_001A4BE0.h[0x5ee] = 3; D_001A4BE0.i[0x98c] = 0;
            func_L01_004F2880(14.0f, 0.523598849773407f, -1.0f);
            D_001A4BE0.u[0x2fb] = D_001A4BE0.u[0x2fb] == 0;
            if (animate) {
                selected_15 = D_001A4BE0.ptr[0x970][0x43] == 0x1A ? 3 : 10;
                if (D_001A4BE0.i[0x974] == 0x1) selected_15 = 17;
                func_L01_0050FB40(0x1A, 0, (f32)selected_15); func_L01_0050FE88(6, 21);
            }
            goto finish;
        case 0x88:
            D_001A4BE0.h[0x5ee] = 3;
            func_L00_0041E958(64.0f, 0.174532949924469f, 0.349065899848938f);
            if (animate) {
                selected_83 = D_001A4BE0.ptr[0x970][0x43] == 0x1A ? 3 : 10;
                if (D_001A4BE0.i[0x974] == 0x1) selected_83 = 17;
                func_L01_0050FB40(0x1A, 0, (f32)selected_83);
            }
            goto finish;
        case 0x1f:
            if (D_001A4BE0.i[0x480]) {
                func_L01_003F1F20(19);
                if (animate) {
                    func_L01_0050FB40(0x60, 4, -1.0f);
                    func_003C3A10(D_001A4BE0.ptr[0x480], 3, 4, -1);
                }
                func_L01_004F2880(11.0f, 0.8726646900177002f, -1.0f);
            }
            goto finish;
        case 0x13:
        
        {
        s32 *entry = D_L08_002F5A50[D_001A4BE0.h[0x5ee]];
        mode = 0; D_001A4BE0.i[0x98c] = 0;
        if ((D_001A4BE0.i[0x974] == 0x13 && (f32)entry[2] > D_001A4BE0.f[0x306]) ||
            (D_001A4BE0.i[0x977] == 0x13 && D_001A4BE0.i[0x6e] + D_001A4BE0.i[0x976] < 27)) mode = (entry[1] + 1) % 3;
        }
        D_001A4BE0.h[0x5ee] = mode;
        func_L01_004F2880(5.0f, 0.785398244857788f, 0.785398244857788f);
        if (animate) {
            current = 0;
            if (mode == 0) selected_13 = 5;
            else if (mode == 1) { current = 2; selected_13 = 7; }
            else { current = 4; selected_13 = 7; }
            if (D_001A4BE0.i[0x2f2] && mode < 2) {
                if (D_001A4BE0.b[0x25f4]) angle_13 = func_L01_004F4E20((D_001A4BE0.b + 0xba0), 0);
                else angle_13 = func_0038DBA0(D_001A4BE0.f[0x2f3], D_001A4BE0.f[0x26]);
                selected_13 += (s32)(angle_13 * 1.5f);
            }
            current /= 2;
            func_L01_0050FB40(mode + 0x17, current, (f32)selected_13);
            animation_13 = func_L01_004E9200(0);
            if (func_L01_004EDFA8((u8 *)animation_13)) func_003C3A10((u8 *)animation_13, mode + 3, current, selected_13);
        }
        goto finish;
        case 0x4d: {
            s32 m4d;
            f32 rate = 5.0f;
            s32 *row = D_L08_002F5A50[D_001A4BE0.h[0x5ee]];
            m4d = 0;
            if ((D_001A4BE0.i[0x975] == 0x6 || (D_001A4BE0.i[0x978] == 0x6 && (u32)(D_001A4BE0.ptr[0x970][0x43] - 15) < 2)) &&
                row[0] == 0 && (f32)row[2] > D_001A4BE0.f[0x306]) m4d = (row[1] + 1) % 2;
            D_001A4BE0.h[0x5ee] = m4d + 7;
            func_L01_004F2880(rate, 0.785398244857788f, 0.785398244857788f);
            if (animate) func_L01_0050FB40(m4d + 0xF, 1, rate);
            goto finish; }
        case 0x22:
            if (animate) func_L01_0050FB40(0x2C, 7, 9.0f);
            if (D_001A4BE0.i[0x48a] == 12 && D_001A4BE0.ptr[0x2f0]) {
                D_001A4BE0.i[0x2f2] = 1;
                D_001A4BE0.f[0x2f3] = func_0038D160(*(f32 *)(D_001A4BE0.ptr[0x2f0] + 0x10) - D_001A4BE0.f[0x20],
                                            *(f32 *)(D_001A4BE0.ptr[0x2f0] + 0x14) - D_001A4BE0.f[0x21]);
                func_0038CEA8((D_001A4BE0.b + 0xba0), D_001A4BE0.ptr[0x2f0] + 0x10, (D_001A4BE0.b + 0x80));
            }
            goto finish;
        }
        goto finish;
    case 0x7c:
        D_001A4BE0.i[0x973] = 10; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x2f4] = func_0038DAB8(D_001A4BE0.f[0x26], 3.14159297943f);
        func_0038CE20((D_001A4BE0.b + 0xbb0), (D_001A4BE0.b + 0x0), -1.0f); D_001A4BE0.f[0x6d] = 0.15f;
        if (!animate) goto finish;
        frames = 8.0f; animation_43 = 0x29; { func_L01_0050FB40(animation_43, 5, frames); goto finish; }
    case 0x16:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.5f); func_L01_003F1F20(18); D_001A4BE0.uh[0x107] = 45;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0.b + 0xf0), 0.1166666746f);
        hit_44 = func_L01_00447490(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_44) func_L01_004DFEA0((s32)(*(f32 *)(hit_44 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 77;
        if (!animate) goto finish;
        func_L01_0050FB40(0x10, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L08_002F5BE0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x91:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0; func_L01_004F1190(0.5f);
        D_001A4BE0.b[0x25ed] = 1; func_L01_003F1F20(18);
        hit_45 = func_L01_00447490(D_001A4BE0.ptr[0x970], 8, 0);
        if (hit_45) func_L01_004DFEA0((s32)(*(f32 *)(hit_45 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 77;
        if (!animate) goto finish;
        func_L01_0050FB40(0x96, 1, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L08_002F5BE0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x3f:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L08_004DD0C0(0x4e, 1); return 0; }
        if (!animate) goto finish;
        func_L01_0050FB40(0, 0, 9.0f); goto finish;
    case 0x4b:
        D_001A4BE0.i[0x973] = 5; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.f[0x5c] > 0.075f) func_L01_004F1190(0.075f / D_001A4BE0.f[0x5c]);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(14, 0, 12.0f); goto finish;
    case 0x41:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.f[0x281] = 0.0019444445f; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 8.0f); goto finish;
    case 0x44:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 8.0f); goto finish;
    case 0x4e:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 12.0f); goto finish;
    case 0x42:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.5f);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0.b + 0xf0), 0.083333336f);
        func_L01_004DFEA0(1);
        D_001A4BE0.uh[0x107] = 45; D_001A4BE0.uh[0xee] = 50;
        if (!animate) goto finish;
        func_L01_0050FB40(6, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L08_002F5BE0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x40:
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L08_004DD0C0(0x4e, 1); return 0; }
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.i[0x974] == 0x3) D_001A4BE0.u[0x6d] = 0;
        if (D_001A4BE0.i[0x975] == 0x0) D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x160));
        D_001A4BE0.b[0x3ec] = 0; D_001A4BE0.b[0x3ef] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(2, 0, 8.0f); goto finish;
    case 0x43:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0xa14] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(5, 0, 12.0f); goto finish;
    case 0x46:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.f[0x14b] = 0.0033333334f; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x22];
        if (D_001A4BE0.i[0x975] == 0x4) { D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c]; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x118]; }
        if (!animate) goto finish;
        func_L01_0050FB40(8, 14, 7.0f); goto finish;
    case 0x47:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(10, 0, 6.0f); goto finish;
    case 0x49:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, 6.0f); goto finish;
    case 0x4a:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(12, 0, 6.0f); goto finish;
    case 0x56:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0, 0, 15.0f); goto finish;
    case 0x58:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.f[0x280] = 0.006111111491918564f; D_001A4BE0.f[0x281] = 0.0019444444915279746f; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        if (D_001A4BE0.f[0xcf] > 2.5f) { func_L01_0050FB40(14, 0, 8.0f); goto finish; }
        func_L01_0050FB40(0, 0, 11.0f); goto finish;
    case 0x57:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120)); D_001A4BE0.b[0x3ec] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(3, 0x12, 8.0f); goto finish;
    case 0x5f:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(7, 0, 12.0f); goto finish;
    case 0x59:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        *(u128_t *)(D_001A4BE0.b + 0xf0) = 0; /* TODO: second quadword clear of D_00189F30 (rac2 qzero_nc) not mapped to rac3 */
        D_001A4BE0.uh[0xee] = 60;
        if (!animate) goto finish;
        func_L01_0050FB40(6, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L08_002F5BE0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x3e:
        D_001A4BE0.i[0x973] = 15; D_001A4BE0.u[0xa03] = 0;
        if (!D_001A4BE0.i[0x178]) {
            if (D_001A4BE0.ptr[0x199]) { func_L01_004DFEA0((s32)(*(f32 *)(D_001A4BE0.ptr[0x199] + 0x2C))); D_001A4BE0.ptr[0x199] = 0; }
            else func_L01_004DFEA0(1);
        }
        func_L01_004F4E70(20, 0);
        if (D_001A4BE0.i[0xa14] < 1) {
            angle_53 = func_0038DAB8(func_0038D160(D_001A4BE0.f[0x3c], D_001A4BE0.f[0x3d]), 3.14159297943f);
            angle_53 = func_0038DAB8(angle_53, func_L01_00443A18(0.523598849774f, 0.610865294933f));
            D_001A4BE0.f[0x48] = func_0038D098(angle_53) * D_001A4BE0.f[0x179] * 0.7f;
            D_001A4BE0.f[0x49] = func_0038D0B0(angle_53) * D_001A4BE0.f[0x179] * 0.7f; D_001A4BE0.f[0x4a] = 0.075f;
            if (D_001A4BE0.i[0x178] > 15 && D_001A4BE0.i[0xa14] < 2) D_001A4BE0.i[0xa14] = 2;
            D_001A4BE0.ptr[0x970][0xA8] = 255; func_L08_004DD0C0(0x16, 1); D_001A4BE0.uh[0xfa] = 150; D_001A4BE0.uh[0xe8] = 70;
            return 0;
        }
        D_001A4BE0.uh[0xee] = 77; D_001A4BE0.f[0x18f] = 0.041666667908430099f;
        if (D_001A4BE0.f[0x188] > 0.0416666679084f) D_001A4BE0.f[0x188] = 0.0416666679084f;
        D_001A4BE0.u[0x185] = 0; *(u128_t *)(D_001A4BE0.b + 0xf0) = 0; *(u128_t *)(D_001A4BE0.b + 0x110) = 0;
        D_001A4BE0.f[0x3e] = 0.1833333373f;
        if (!animate) goto finish;
        frames = -3.0f; animation_53 = 16; { func_L01_0050FB40(animation_53, 2, frames); goto finish; }
    case 0x1c:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, 10.0f); goto finish;
    case 0x1d:
        D_001A4BE0.u[0xa03] = 0x51; D_001A4BE0.i[0x973] = 0;
        if (func_L01_004DFE80(D_001A4BE0.ptr[0x970][0x42]) == func_L04_004EFEC0(0)) goto finish;
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, 5.0f); goto finish;
    case 0x1e:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0;
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, 10.0f); goto finish;
    case 0x74:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        func_L01_004EAA80();
        if (!animate) goto finish;
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, 10.0f); goto finish;
    case 0x31:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.b[0x25e8] = 1;
        D_001A4BE0.b[0x25ee] = 1; D_001A4BE0.b[0x25ed] = 1; func_L01_0044E740((void *)(D_001A4BE0.b + 0x1ce0));
        if (!animate) goto finish;
        func_L01_0050FB40(func_L04_004EFEC0(0), 0, -1.0f); goto finish;
    case 0x7a:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x25ed] = 1;
        *(u128_t *)(D_001A4BE0.b + 0xf0) = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, -1.0f); goto finish;
    case 0x64: case 0x65:
        D_001A4BE0.i[0x973] = 24; D_001A4BE0.b[0x25ed] = 1;
        func_L01_0044E740((void *)(D_001A4BE0.b + 0x1ce0)); func_L01_004EAA80();
        if (animate) func_L01_0050FB40(func_L04_004EFEC0(0), 0, -1.0f);
        goto finish;
    default:
        goto finish;
    }
finish:
    if (wasGliding && !D_001A4BE0.b[0x25e8]) D_001A4BE0.i[0x993] = 1;
    if (wasFlag && !D_001A4BE0.b[0x25e7]) D_001A4BE0.i[0x993] = 1;
    if (D_001A4BE0.i[0x975] == 0x1A && D_001A4BE0.i[0x973] != D_001A4BE0.i[0x975] && D_001A4BE0.i[0x98d]) D_001A4BE0.i[0x993] = 1;
    if (D_001A4BE0.h[0x1b4] == 0 && D_001A4BE0.i[0x49e] == 0xD && D_001A4BE0.i[0x98d]) D_001A4BE0.i[0x994] = 1;
    if ((u32)(D_001A4BE0.i[0x973] - 13) > 2 && (D_001A4BE0.i[0x971] != 6 || D_001A4BE0.i[0x974] != 0x24) &&
        D_001A4BE0.i[0x49e] == 0xE && D_001A4BE0.i[0x98d]) D_001A4BE0.i[0x994] = 1;
    if (D_001A4BE0.i[0x973] == 20) { func_L01_004EAA80(); D_001A4BE0.b[0x25ed] = 1; }
    if ((!func_L01_004E9308() || D_001A4BE0.i[0x973] == 18) &&
        (D_001A4BE0.f[0xd4] < D_L08_001E1D40.f8 || D_001A4BE0.i[0x973] == 0)) D_L08_001E1D40.i450 = 0;
    if (D_001A4BE0.i[0x973] != D_001A4BE0.i[0x975]) func_L01_004E1560();
    D_001A4BE0.i[0x6e] = 0;
    D_001A4BE0.u[0x70] = 0;
    if (D_001A4BE0.i[0x973] != D_001A4BE0.i[0x975]) D_001A4BE0.u[0x6f] = 0;
    D_001A4BE0.u[0x71] = 0;
    return 1;
}
