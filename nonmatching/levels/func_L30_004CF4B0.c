/* func_L30_004CF4B0: hero state entry, the vidcomic levels (L30-L36, 7 places)'s copy (family C, docs/prep/FAMILIES.md). Near miss, Opus family C
   passes of 2026-11-08: the root's C (nonmatching/levels/func_L08_004DD0C0.c) ported with this level's data
   and callee names and its jump-table order, then corrected against retail.
   5234 of retail's 5239 instructions; aligned, 4928 lines (94.06%) and 5218 opcodes (99.60%) equal.
   Needs what the root needs: "-O2 -G8 -fopt-stack -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as"
   on its file, its divs_nops row "func_L30_004CF4B0 2 2 2" (committed), include/vu0.h (vec_add_ab, vec_sub_ab where the
   vector states have them, qzero, fabs_asm at every abs.s this C has), and D_001439F4/D_00143950 declared
   with __attribute__((section(".data"))) as in the root.
   This pass wrote the 7-group states 0x38, 0x28, 0x29, 0xA2, 0xAC and 0xA7 and their animation entries from
   retail, the vector states 0x27/0x76/0xAD with vec_sub_ab and the length test (func_0038CEA8, 0xAD
   rewritten like 0x76), state 1's vector in dir (retail's frame has no separate V4), and fixed the callee
   names (func_L30_004AD910, func_L30_004D4690, func_L30_004BCB20).
   The draft-derived states were corrected against retail: state 0 redirects to 0x2E when b[0x1474] is set
   and the speed of the 0x160 vector is above 0.01, state 3 whenever b[0x1474] is set, state 2's 0x2E
   branch and frame counts are retail's (the root's counts), 0x81 has no uh[0xf8] store, clamps at -0.14
   and plays animation 0x5B, and the 0x23/0x24/0x25/0x2B/0x2C (and where they differ 0x37/0x6A/0x7D)
   bodies are L04's, which retail shares.
   It inherits the root's remaining differences (0xB's shared constant 1, 0xE's two stores, the 7-group
   head's f[0x135] store, 0x11's f[0xa18] load). The states that came from the prep draft keep its
   constants where retail's differ; the per-level 7-group order is retail's (blocks a level lacks are
   left out, the ones only it has are written in its place).
*/
#include "vu0.h"
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
extern s32 D_L30_002F4C70[][11];
extern s32 D_L22_001A9010;
extern s32 D_L30_001D6740;
extern f32 D_L30_001DBBA8;
extern f32 D_L30_001DBBAC;
extern f32 D_L30_002F4E00[][25];
extern s32 D_L30_002F4C70[][11];
extern f32 func_00282C48(f32);
extern void func_L01_00476498(s32, f32 *, s32 *, f32 *, s32, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void *func_L01_00447490(void *, u32, s32);
extern void func_003C4BB0(float *, float);
extern s32 func_L01_004DFE80(s32);
extern void func_L01_004E67C0(void);
extern u32 func_L01_004E9200(s32);
extern s32 func_L01_004E9308(void);
extern f32 func_L01_004E93F8(int, int);
extern void func_L01_004EAA80(void);
extern s32 func_L01_004EDFA8(u8 *);
extern void func_L01_004F1190(f32);
extern void func_L01_004ED5F8(void);
extern void func_L01_004F4EF8(void);
extern void func_L01_00513FD8(void);
extern f32 func_L01_004F4E20(void *, int);
extern int func_L01_004F4E70(int, int);
extern int func_L01_004FF610(void);
extern void func_L01_0050FE88(s32, s32);
extern f32 func_L01_00511408(char *);
extern void func_L01_00511508(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern int func_L01_003F1F20(unsigned int, int);
extern void func_L01_004E7C88(void);
extern void func_L01_0044E318(void *, char *);
extern void func_L01_0044E340(List_F66766f2b *, int, int, float);
extern void func_L01_0044E740(void *);
extern int func_L00_0035F5A0(int, int, int);
extern void func_L30_004D4690(int);
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
extern void func_L30_004BCB20(int, f32);
extern void func_L01_004F2880(f32, f32, f32);
extern s32 func_L01_005119E0(s32);
extern int func_L01_00507268(void);
extern void func_L01_0050FB40(int, int, f32);
extern void func_L00_0041E958(f32, f32, f32);
extern s32 func_L30_004AD910(int);
extern s32 D_001D4C38;
extern s32 D_001A7B90;
extern u8 D_001D5464[8];
extern u8 *D_L30_001E0790;
extern s32 D_L30_001E0798;
extern u32 D_001D545C;
typedef struct { u16 count; u16 pad; u32 maximum; u32 levels; } Statistics;
extern Statistics D_001A7C10[];
extern s32 D_L30_001DBCC0[2];
extern f32 D_L30_002F4E00[][25];
extern u8 D_L22_0025FD30[];
typedef struct { u8 pad0[8]; f32 f8; u8 padC[0x450 - 0xC]; s32 i450; } L19State_1B9900;
extern s32 func_L01_005002B8(s32, s32);
extern void func_L01_00500188(void);
extern void func_L01_003F1F60(s32);
extern L19State_1B9900 D_L30_001E22C0;



/* All resident fields below are views of the single player-state object. */
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
extern Hero D_001A4BE0;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern f32 D_L30_001DBB70, D_L30_001DBB74, D_L30_001DBB78, D_L30_001DBBA8, D_L30_001DBBAC;
__asm__(".extern D_L30_001DBB70, 4");
__asm__(".extern D_L30_001DBB74, 4");
__asm__(".extern D_L30_001DBB78, 4");
__asm__(".extern D_L30_001DBBA8, 4");
__asm__(".extern D_L30_001DBBAC, 4");
extern u8 D_L30_001DBCC8[8];
__asm__(".extern D_L30_001DBCC8, 8");
extern u8 D_L30_001DBCE8[8];
__asm__(".extern D_L30_001DBCE8, 8");
extern s32 D_L30_001D6740;
__asm__(".extern D_L30_001D6740, 4");
extern u8 D_001439F4 __attribute__((section(".data")));
extern s32 D_00143950 __attribute__((section(".data")));
extern u8 D_001D545C_b[] __attribute__((section(".sdata")));
extern void func_L01_004606A8(s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 D_L30_001DDA64;
extern void func_L01_005118D0(s32, s32);
extern void func_L01_004F5AE8(void);
extern void func_L01_004F5810(void);
extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
extern f32 D_L30_001DBCCC;
__asm__(".extern D_L30_001DBCCC, 4");
extern s32 func_L01_00500240(s32, s32);
extern u8 D_00142660[];
extern s32 func_L30_004E6DC8(s32);
extern s32 D_L30_001DBCC0[2];
__asm__(".extern D_L30_001DBCC0, 8");
extern s32 func_L01_004DFD60(void);
extern void func_L01_00412E70(void *, V4 *, f32, u8 *, f32);
extern void func_L01_00412FE0(void *, V4 *, f32, f32);


/* Changes the player's action, initializes its movement parameters and selects animation. */
s32 func_L30_004CF4B0(s32 action, s32 animate) {
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
    case 0xaf:
        D_001A4BE0.b[0x25e4] = 0;
        goto finish;
    case 0x0:
        D_001A4BE0.i[0x973] = 0;
        D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x48a] == 0x27) func_L01_004EAA80();
        D_001A4BE0.b[0x2877] = 0;
        D_001A4BE0.i[0x460] = func_00382498(0x2a, 0x53);
        func_L01_004E67C0();
        if (D_001A4BE0.b[0x25e4]) { func_L30_004D4690(0); return 1; }
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.b[0x1474] && func_0038CED8(D_001A4BE0.b + 0x160) > 0.010000001f) { func_L30_004CF4B0(0x2e, 1); return 0; }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CF4B0(0x7b, 1); return 0; }
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L30_004AD910(0) == 0x4a) func_L01_0050FB40(func_L30_004AD910(0), 0, 15.0f); else func_L01_0050FB40(func_L30_004AD910(0), 0, -1.0f);
        goto finish;
    case 0x68:
        D_001A4BE0.i[0x973] = 0;
        qzero(D_001A4BE0.b + 0x160);
        D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.0f);
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L30_004AD910(0) == 0x4a) func_L01_0050FB40(func_L30_004AD910(0), 0, 15.0f); else func_L01_0050FB40(func_L30_004AD910(0), 0, -1.0f);
        goto finish;
    case 0x3d:
        func_L01_0050FB40(func_L30_004AD910(0), 0, 7.0f);
        if (D_001A4BE0.ptr[0x681]) func_003C3A10(D_001A4BE0.ptr[0x681], 0, 0, 7);
        goto finish;
    case 0x39:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x40, 0, 10.0f); goto finish;
    case 0x82:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0xa14] = 0; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        func_003C4BB0((f32 *)(D_001A4BE0.b + 0x160), 0.0583333373069f);
        if (!animate) goto finish;
        func_L01_0050FB40(0x75, 0, 12.0f); goto finish;
    case 0xb1:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004ED5F8();
        func_L01_004F4EF8();
        if (!animate) goto finish;
        func_L01_0050FB40(0x63, 0, 10.0f); goto finish;
    case 0x81:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x1cb] = D_001A4BE0.f[0xd4] - 0.37f; D_001A4BE0.i[0xa14] = 0;
        D_001A4BE0.f[0x1c9] = D_001A4BE0.f[0x46] * 0.2f;
        if (D_001A4BE0.f[0x1c9] < -0.14000002f) D_001A4BE0.f[0x1c9] = -0.14000002f;
        D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.f[0x1c8] = D_001A4BE0.f[0x22] - D_001A4BE0.f[0x1cb]; D_001A4BE0.u[0x1cc] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x5b, 0, 9.0f); goto finish;
    case 0x50:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.uh[0xf8] = 10000; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x1cb] = D_001A4BE0.f[0xd4] - 0.15f; D_001A4BE0.i[0xa14] = 0;
        D_001A4BE0.f[0x1c9] = D_001A4BE0.f[0x46] * 0.2f;
        if (D_001A4BE0.f[0x1c9] < -0.14000002f) D_001A4BE0.f[0x1c9] = -0.14000002f;
        D_001A4BE0.u[0x1cc] = 0; D_001A4BE0.f[0x1c8] = D_001A4BE0.f[0x22] - D_001A4BE0.f[0x1cb];
        if (!animate) goto finish;
        func_L01_0050FB40(0x23, 0, 9.0f); goto finish;
    case 0x32: {
        s32 n;
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0x26f] = 0;
        if (D_001A4BE0.i[0x975] == 0x12) { func_L01_004F4E70(3, 0); D_001A4BE0.i[0x972] = 1; }
        else D_001A4BE0.i[0x26d] = 37;
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0x268] = 0;
        n = 10;
        if (!animate) goto finish;
        func_L01_0050FB40(0x36, 0, n); goto finish; }
    case 0x34: {
        s32 f;
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x26d] = 50;
        if (D_001A4BE0.i[0x975] == 0x12) { func_L01_004F4E70(3, 0); D_001A4BE0.i[0x972] = 1; }
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0x268] = 0;
        f = D_001A4BE0.i[0x974] == 0x32 ? 12 : 9;
        if (animate) func_L01_0050FB40(0x38, 0, f);
        goto finish;
    }
    case 0x33:
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.i[0x45a] = 0x68;
        selected_8 = D_001A4BE0.i[0x974] == 0x34 ? -2 : 29;
        if (!animate) goto finish;
        func_L01_0050FB40(0x37, 0, (f32)selected_8); goto finish;
    case 0x36:
        D_001A4BE0.i[0x973] = 18; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.uh[0x4e5] = 0;
        if (D_001A4BE0.i[0x975] == 0x11) {
            func_L01_004E5EB8(3, 10, 0);
            if (D_L30_001E0790) func_L01_004C67A0(D_L30_001E0790, D_L30_001E0798, 0, D_001A4BE0.f[0x20], D_001A4BE0.f[0x21], 0.4f, 0.3f);
        } else if (D_001A4BE0.f[0x46] < -0.010000001f) {
            selected_9 = (s32)(fabs_asm(D_001A4BE0.f[0x46]) * 300.0f);
            if (selected_9 > 40) selected_9 = 40;
            func_L01_004E5EB8(3, selected_9, 1);
            if (D_L30_001E0790) func_L01_004C67A0(D_L30_001E0790, D_L30_001E0798, 0, D_001A4BE0.f[0x20], D_001A4BE0.f[0x21], 0.5f, -0.4f);
            D_001A4BE0.uh[0x4e5] = 62;
        }
        D_001A4BE0.f[0x1c9] = D_001A4BE0.f[0x46] * 0.37f; D_001A4BE0.i[0x1ca] = 0;
        if (D_001A4BE0.f[0x1c9] < -0.14000002f) D_001A4BE0.f[0x1c9] = -0.14000002f;
        D_001A4BE0.f[0x1cb] = D_001A4BE0.f[0xd4]; D_001A4BE0.u[0x1cc] = 0;
        D_001A4BE0.f[0x1c8] = (D_001A4BE0.f[0x22] - D_001A4BE0.f[0xd4]) - -0.12f;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.f[0x5a] = 0;
        func_003C4BB0((f32 *)(D_001A4BE0.b + 0x160), 0.11000001f);
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x35, 0, 18.0f); goto finish;
    case 0x77: case 0x78:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.5f); D_001A4BE0.b[0x25e8] = 1; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        hit_10 = func_L01_00447490(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_10) func_L01_004DFEA0((s32)(*(f32 *)(hit_10 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 64;
        if (animate) {
            if (D_001A4BE0.i[0x971] == 0x77) func_L01_0050FB40(0x57, 3, -3.0f);
            else func_L01_0050FB40(0x56, 3, -3.0f);
            *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4E00[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
            goto finish;
        }
        goto finish;
    case 0x35:
        D_001A4BE0.i[0x973] = 18; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.u[0x26f] = 0;
        D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x1ca] = 37; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x52, 0, 14.0f); goto finish;
    case 0x6c:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.h[0x4e7] > 42 && D_001A7C10[12].count < 0xFFFF) D_001A7C10[12].count++;
        if (D_001A7C10[12].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[12].maximum = (D_001D4C38 * 5 + 2) / 6;
        D_001A7C10[12].levels = (D_001A7C10[12].levels | (1u << D_001D545C)) | 0x80000000u;
        if (D_001A4BE0.i[0x274] > 2 && D_001A7C10[29].count < 0xFFFF) D_001A7C10[29].count++;
        if (D_001A7C10[29].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[29].maximum = (D_001D4C38 * 5 + 2) / 6;
        D_001A7C10[29].levels = (D_001A7C10[29].levels | (1u << D_001D545C)) | 0x80000000u;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x4f, 0, 8.0f); goto finish;
    case 0x84:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x64, 0, 8.0f); goto finish;
    case 0x1:
        D_001A4BE0.u[0xa03] = 4;
        D_001A4BE0.i[0x973] = 0;
        if (D_001A4BE0.b[0x25e4]) {
            func_0038CF68(dir, D_001A4BE0.b + 0x20, D_001A4BE0.f[0x5b3]);
            vec_add_ab(dir, dir, D_001A4BE0.b + 0x80);
            func_L01_00412E70(D_001A4BE0.b + 0x1540, (V4 *)dir, D_001A4BE0.f[0x26], D_001A4BE0.ptr[0x970], 0.0f);
            func_L01_00412FE0(D_001A4BE0.b + 0x1540, (V4 *)dir, D_001A4BE0.f[0x26], 0.0f);
            func_L01_00513FD8();
        }
        if (D_001A4BE0.b[0x25eb]) goto finish;
        animation_16 = func_L30_004AD910(1);
        if (D_001A4BE0.ptr[0x970][0x43] == animation_16 || !animate) goto finish;
        func_L01_0050FB40(animation_16, 0, 15.0f); goto finish;
    case 0x2f:
        D_001A4BE0.i[0x973] = 8; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x110)); D_001A4BE0.u[0xa03] = 0;
        func_L01_0050FB40(func_L30_004AD910(0), 0, 4.0f); D_001A4BE0.uh[0xf6] = 6;
        goto finish;
    case 0x2: case 0x2e: case 0x75:
        D_001A4BE0.i[0x973] = 1;
        D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x975] != 0x4 && D_001A4BE0.i[0x978] != 0x4) D_001A4BE0.f[0x6d] = func_L01_00511408((char *)(D_001A4BE0.b + 0x120));
        (*(u128_t *)(D_001A4BE0.b + 0x3d0) = *(u128_t *)(D_001A4BE0.b + 0x0));
        D_001A4BE0.u[0xfc] = 0;
        D_001A4BE0.f[0xfa] = D_001A4BE0.f[0x26];
        if (D_001A4BE0.f[0x6d] > 0.11666667461395264f) D_001A4BE0.f[0x6d] = 0.11666667461395264f;
        D_001A4BE0.b[0x3ef] = 0;
        func_L30_004BCB20(0, 1.0f);
        value_18 = func_0038DBA0(D_001A4BE0.f[0x26], D_001A4BE0.f[0x68]);
        if (value_18 > 1.5707964897155762f &&
            (D_001A4BE0.i[0x975] == 0x4 || D_001A4BE0.i[0x974] == 0x3 || D_001A4BE0.i[0x977] == 0x3)) D_001A4BE0.f[0x6d] = 0;
        D_001A4BE0.i[0x45a] = 0x68;
        if (D_001A4BE0.b[0x147c]) {
            if (D_001A4BE0.h[0x1b6] == 0 || D_001A4BE0.f[0xcf] < 0.3f) { func_L30_004CF4B0(0x7b, 1); return 0; }
        }
        if (D_001A4BE0.b[0x1474] || D_001A4BE0.i[0x971] == 0x2e) {
            if (D_001A4BE0.f[0x6d] > 0.15400001f) D_001A4BE0.f[0x6d] = 0.15400001f;
            D_001A4BE0.u[0x3e] = 0;
            func_003C4BB0((f32 *)(D_001A4BE0.b + 0xf0), 0.15400001f);
            D_001A4BE0.i[0x971] = 0x2e; D_001A4BE0.u[0xf9] = 0;
            if ((D_001A4BE0.h[0xa1a] || (D_001A4BE0.i[0x5ac] == 1 && func_L01_004606E8(0x28, 2, 0, 0))) && D_001A4BE0.b[0x1436]) func_L01_0050FB40(0x7b, 0, 7.0f);
            else func_L01_0050FB40(0x32, 0, 7.0f);
            goto finish;
        }
        if (D_001A4BE0.b[0x25ea] || D_001A4BE0.i[0x971] == 0x75) {
            D_001A4BE0.i[0x971] = 0x75;
            func_L01_0050FB40(!*(s32 *)(*(u8 **)(D_001A4BE0.ptr[0x970] + 0x24) + 0x188) ? 3 : 0x50, 0, 7.0f); goto finish;
        }
        D_001A4BE0.i[0x972] = 0;
        D_001A4BE0.b[0x3ec] = 0; D_001A4BE0.b[0x3ee] = 0;
        if (!animate) goto finish;
        selected_18 = 7;
        if (func_L01_004DFD60()) selected_18 = 10;
        if (D_001A4BE0.i[0x977] == 0x22 || D_001A4BE0.i[0x974] == 0x22) selected_18 = 12;
        if (D_001A4BE0.i[0x977] == 0x88 || D_001A4BE0.i[0x974] == 0x88) selected_18 = 12;
        if (D_001A4BE0.i[0x974] == 0x13) selected_18 = 11;
        if (D_001A4BE0.i[0x977] == 0x6 || D_001A4BE0.i[0x977] == 0x2c) selected_18 = 15;
        if (D_001A4BE0.i[0x978] == 0x4 && D_001A4BE0.b[0x46c] > 4) selected_18 = 11;
        func_L01_0050FB40(D_001A4BE0.i[0x972] + 3, D_L30_001DBCC0[D_001A4BE0.i[0x972]], (f32)selected_18); goto finish;
    case 0x80: {
        s32 n;
        D_001A4BE0.i[0x973] = 28; D_001A4BE0.i[0x45a] = 0x68; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110)); D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.i[0x261] = 0;
        if (D_001A4BE0.i[0x49e] != 0x1d) { D_001A4BE0.i[0x98d] = D_001A4BE0.i[0x49e]; D_001A4BE0.i[0x97f] = 0x1d; }
        n = -2;
        if (!animate) goto finish;
        func_L01_0050FB40(0x69, 0, n); goto finish; }
    case 0x66:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        D_001A4BE0.b[0x25ed] = 1;
        if (!D_001A4BE0.b[0x25e4]) func_L01_004EAA80();
        if (!animate) goto finish;
        if (D_001A4BE0.b[0x25e4] == 3) { func_L01_0050FB40(5, 0, 7.0f); goto finish; }
        if (D_001A4BE0.b[0x25e4] == 1) { func_L01_0050FB40(0x19, 0, 7.0f); goto finish; }
        if (D_001A4BE0.b[0x25e4] != 0) goto finish;
        func_L01_0050FB40(D_001A4BE0.i[0x972] + 3, D_L30_001DBCC0[D_001A4BE0.i[0x972]], 7.0f); goto finish;
    case 0x30:
        D_001A4BE0.i[0x973] = 16; D_001A4BE0.u[0xa03] = 3; D_001A4BE0.b[0x25e8] = 1;
        func_0038CB78((unsigned int *)(D_001A4BE0.b + 0xac0), 0, 0x20);
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(0x5D, 0, 15.0f); goto finish;
    case 0x3:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.b[0x1474]) { func_L30_004CF4B0(0x2e, 1); return 0; }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CF4B0(0x7b, 1); return 0; }
        if (func_L01_00507268()) return 0;
        if (func_L30_004AD910(0) == 0x4a) {
            if (!animate) goto finish;
            if (func_L30_004CF4B0(0x0, 0)) func_L01_0050FB40(func_L30_004AD910(0), 0, 15.0f);
            return 0;
        }
        if (!animate) goto finish;
        animation_21 = objectSnapshot[0x42];
        {
            value_21 = D_001A4BE0.f[0x306]; selected_21 = 6;
            if (func_L01_004DFE80(animation_21) == 4 && value_21 > 3.0f && value_21 < 16.0f) selected_21 = 5;
            func_L01_0050FB40(selected_21, 4, 7.0f);
            goto finish;
        }
    case 0x67:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_L01_00511408((char *)(D_001A4BE0.b + 0x120)); (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        animation_22 = objectSnapshot[0x42]; {
            value_22 = D_001A4BE0.f[0x306]; selected_22 = 6;
            if (func_L01_004DFE80(animation_22) == 4 && value_22 > 3.0f && value_22 < 16.0f) selected_22 = 5;
            func_L01_0050FB40(selected_22, 4, 7.0f);
            goto finish;
        }
    case 0x4:
        D_001A4BE0.i[0x973] = 12; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.f[0x6d] > 0.14000002f) D_001A4BE0.f[0x6d] = 0.14000002f;
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CF4B0(0x7b, 1); return 0; }
        D_001A4BE0.i[0x45a] = 0x68;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        func_003C4BB0((float *)(D_001A4BE0.b + 0x160), 0.14000002f);
        if (D_001A4BE0.f[0x5e] > 0.07000001f) func_L01_004F4E70(9, 0);
        if (animate) {
            if (D_001A4BE0.ptr[0x970][0x42] == func_L30_004AD910(0)) func_L01_0050FB40(13, 2, 7.0f);
            else func_L01_0050FB40(13, 2, 12.0f);
            func_L01_0050FE88(3, 18);
        }
        goto finish;
    case 0x8f:
        D_001A4BE0.i[0x973] = 33; D_001A4BE0.u[0xa03] = 0;
        
        D_001A4BE0.f[0x68] = func_0038D160(*(f32 *)(D_001A4BE0.ptr[0x2a4] + 0x10) - D_001A4BE0.f[0x20],
                                    *(f32 *)(D_001A4BE0.ptr[0x2a4] + 0x14) - D_001A4BE0.f[0x21]);
        D_001A4BE0.u[0x2a7] = 0; { if (animate) { func_L01_0050FB40(0x2F, 2, 5.0f); func_L01_0050FE88(10, 14); } goto finish; }
    case 0x90:
        D_001A4BE0.i[0x973] = 33; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        goto finish;
    case 0x23:
        D_001A4BE0.i[0x973] = 13; D_001A4BE0.u[0xa03] = 7;
        
        D_001A4BE0.f[0x68] = func_0038D160(*(f32 *)(D_001A4BE0.ptr[0x289] + 0x10) - D_001A4BE0.f[0x20],
                                    *(f32 *)(D_001A4BE0.ptr[0x289] + 0x14) - D_001A4BE0.f[0x21]);
        if (D_001A4BE0.i[0x974] == 0x28) (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0xf0));
        { if (animate) { func_L01_0050FB40(0x2F, 2, 5.0f); func_L01_0050FE88(10, 14); } goto finish; }
    case 0x24:
        D_001A4BE0.i[0x973] = 13;
        D_001A4BE0.u[0xa03] = 7;
        D_001A4BE0.i[0x288] = 0;
        D_001A4BE0.i[0x28d] = 0;
        D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x2b, 0, 8.0f); goto finish;
    case 0x25:
        D_001A4BE0.i[0x973] = 13; D_001A4BE0.u[0xa03] = 7; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.i[0x288] = 0; D_001A4BE0.i[0x28d] = 0;
        D_001A4BE0.f[0x28f] = func_0038CF00(D_001A4BE0.b + 0x80, D_001A4BE0.ptr[0x289] + 0x10);
        if (!animate) goto finish;
        func_L01_0050FB40(0x2b, 1, 4.0f); goto finish;
    case 0x2b: {
        u8 *p = D_001A4BE0.ptr[0x294], *q; f32 t;
        D_001A4BE0.u[0x29a] = 0; D_001A4BE0.i[0x973] = 14; D_001A4BE0.u[0xa03] = 7; D_001A4BE0.ptr[0x295] = p; D_001A4BE0.uh[0x52e] = 0;
        D_001A4BE0.uh[0x53e] = 0; D_001A4BE0.uh[0x53f] = 1; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0x29d] = 0; D_001A4BE0.u[0x29e] = 0;
        q = *(u8 **)(p + 0x68);
        D_001A4BE0.f[0x298] = *(f32 *)(q + 4);
        if (*(f32 *)(q + 0x10) == D_001A4BE0.f[0x29a]) *(f32 *)(q + 0x14) = *(f32 *)(q + 0xc); else *(f32 *)(q + 0x14) = *(f32 *)(q + 0x10);
        D_001A4BE0.f[0x2a1] = 0.036000002f; D_001A4BE0.f[0x2a2] = 0.47520003f; qzero(D_001A4BE0.b + 0xa0); D_001A4BE0.f[0x2a3] = 0.22000001f;
        D_001A4BE0.uh[0x103] = 0x21;
        if (*(f32 *)(q + 0x24) != 0.0f) D_001A4BE0.f[0x2a1] = *(f32 *)(q + 0x24);
        if (*(f32 *)(q + 0x28) != 0.0f) D_001A4BE0.f[0x2a2] = *(f32 *)(q + 0x28);
        if (*(f32 *)(q + 0x2c) != 0.0f) D_001A4BE0.f[0x2a3] = *(f32 *)(q + 0x2c);
        D_001A4BE0.f[0x29b] = func_0038D160(*(f32 *)(D_001A4BE0.ptr[0x295] + 0x10) - D_001A4BE0.f[0x20], *(f32 *)(D_001A4BE0.ptr[0x295] + 0x14) - D_001A4BE0.f[0x21]);
        D_001A4BE0.f[0x299] = func_0038CF00(D_001A4BE0.b + 0x80, D_001A4BE0.ptr[0x295] + 0x10);
        D_001A4BE0.f[0x29c] = 0.0108f;
        if (D_001A4BE0.i[0x975] == 4) D_001A4BE0.f[0x29c] = D_001A4BE0.f[0x13c];
        else if (D_001A4BE0.i[0x975] == 2) D_001A4BE0.f[0x29c] = D_001A4BE0.f[0x280];
        if (!animate) goto finish;
        func_L01_0050FB40(0x2f, 0, 9.0f); D_001A4BE0.f[0x300] = 0.7f;
        goto finish; }
    case 0x2c:
        D_001A4BE0.i[0x973] = 2; qzero(D_001A4BE0.b + 0xa0); D_001A4BE0.u[0xa03] = 7; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0xb, 0, 12.0f); goto finish;
    case 0x27: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0.i[0x973] = 15; D_001A4BE0.u[0xa03] = 3; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.i[0x17a] = 1; D_001A4BE0.f[0x17e] = -1.57079649f; D_001A4BE0.i[0x178] = 0; D_001A4BE0.i[0x19a] = 0; D_001A4BE0.i[0x17f] = 0;
        if (D_001A4BE0.i[0x975] != 0xf) { D_001A4BE0.i[0x185] = 0; D_001A4BE0.i[0x187] = -1; D_001A4BE0.f[0x188] = 0.0f; }
        start = D_001A4BE0.f[0x176]; D_001A4BE0.i[0x194] = 0; D_001A4BE0.i[0x195] = 0; D_001A4BE0.uh[0x32f] = 0; D_001A4BE0.i[0x189] = 0; D_001A4BE0.i[0x18a] = 0; D_001A4BE0.uh[0x316] = 0; D_001A4BE0.i[0x18c] = 0; count = D_001A4BE0.i[0x175]; value = start;
        func_L01_00476498(D_001A4BE0.i[0x174], pos, &count, &value, D_001A4BE0.i[0x17d], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0.b + 0x80);
        if (func_0038CEA8(dir) > 0.001f) {
            func_0038CF68(dir, dir, 1.0f);
            if (D_001A4BE0.i[0x975] != 0xf) D_001A4BE0.f[0x188] = func_0038CE68((D_001A4BE0.b + 0x110), dir);
        }
        if (D_001A4BE0.ptr[0x192]) {
            f32 toward = func_0038D160(*(f32 *)(D_001A4BE0.ptr[0x192] + 0x10) - D_001A4BE0.f[0x20], *(f32 *)(D_001A4BE0.ptr[0x192] + 0x14) - D_001A4BE0.f[0x21]);
            if (func_0038DBA0(toward, func_0038DAB8(D_001A4BE0.f[0x17e], func_0038D160(dir[0], dir[1]))) > 1.57079649f) {
                D_001A4BE0.f[0x17e] = 1.57079649f; D_001A4BE0.i[0x17f] = 1;
            }
        }
        if (!animate) goto finish;
        func_L01_0050FB40(D_001A4BE0.i[0x17f] + 0x31, 0, 6.0f); goto finish; }
    case 0x76: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0.i[0x973] = 26; D_001A4BE0.u[0xa03] = 3; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.i[0x1a8] = 0; D_001A4BE0.i[0x1ae] = 0;
        start = D_001A4BE0.f[0x1a2]; count = D_001A4BE0.i[0x1a1]; value = start;
        func_L01_00476498(D_001A4BE0.i[0x1a0], pos, &count, &value, D_001A4BE0.i[0x1ab], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0.b + 0x80);
        if (func_0038CEA8(dir) > 0.001f) {
            func_0038CF68(dir, dir, 1.0f);
            D_001A4BE0.f[0x1a9] = func_0038CE68((D_001A4BE0.b + 0x110), dir);
        }
        D_001A4BE0.f[0x1a9] = D_001A4BE0.f[0x1a9] * 0.5f;
        if (D_001A4BE0.f[0x1a9] < 0.0f) D_001A4BE0.f[0x1a9] = 0.0f;
        func_L01_0050FB40(0x6C, 0, 8.0f); goto finish; }
    case 0x17:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.f[0x14b] = 0.0088f; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x22];
        if (D_001A4BE0.i[0x975] == 0x4) { D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c]; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x118]; }
        D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        if (D_001A4BE0.f[0x5d] > 0.07000001f) func_L01_0050FB40(0x20, 0, 7.0f);
        else func_L01_0050FB40(0x20, 1, 9.0f);
        goto finish;
    case 0x18:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x21, 0, 5.0f); goto finish;
    case 0x19:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x24, 0, 5.0f); goto finish;
    case 0x1a:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050FB40(0x25, 0, 5.0f); goto finish;
    case 0x7b:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, 10.0f); goto finish;
    case 0x6: case 0x79:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x971] == 0x79) D_001A4BE0.i[0x973] = 0x14;
        D_001A4BE0.f[0x280] = 0.0088f;
        D_001A4BE0.f[0x281] = 0.0028000001f;
        if (D_001A4BE0.i[0x971] == 0x79) {
            if (!D_001A4BE0.b[0x25e4]) D_001A4BE0.uh[0x142d] = func_L01_004F4E70(14, 0x20);
            D_001A4BE0.f[0x284] = func_L01_00443A18(0.06283186f, 0.08726647f);
            D_001A4BE0.f[0x285] = func_L01_00443A18(0.06283186f, 0.08726647f);
        }
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.i[0x972] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        if (D_001A4BE0.b[0x25e4] == 1) { func_L01_0050FB40(4, 0, 7.0f); return 1; }
        if (D_001A4BE0.b[0x25e4] == 3) { func_L01_0050FB40(0x15, 0, 7.0f); return 1; }
        if (D_001A4BE0.f[0xcf] > 1.75f) { func_L01_0050FB40(11, 0, 10.0f); D_001A4BE0.i[0x972] = 1; goto finish; }
        func_L01_0050FB40(10, 0, 8.0f); goto finish;
    case 0xb0:
        D_001A4BE0.i[0x973] = 0x25; qzero(D_001A4BE0.b + 0xf0); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x7a, 0, 6.0f); goto finish;
    case 0x8: {
        s32 n = -2;
        D_001A4BE0.i[0x973] = 5; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.f[0x5c] > 0.09f) func_L01_004F1190(0.09f / D_001A4BE0.f[0x5c]);
        D_001A4BE0.i[0xa13] = 0; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(0x13, 0, n); goto finish; }
    case 0x7: case 0x9: case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11: case 0x12: case 0x1b: case 0x28: case 0x29: case 0x38: case 0x45: case 0x48: case 0x54: case 0x5f: case 0x69: case 0x6b: case 0x73: case 0x86: case 0xa2: case 0xa7: case 0xac:
        if (D_001A4BE0.i[0x971] != 0x86 && D_001A4BE0.ptr[0xd7] &&
            (*(s16 *)(D_001A4BE0.ptr[0xd7] + 0xAA) == 0x9B9 || *(s16 *)(D_001A4BE0.ptr[0xd7] + 0xAA) == 0xF05)) {
            func_L30_004CF4B0(0x86, 1); return 0;
        }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x101] < 12) {
            if (D_001A4BE0.h[0x1b6] == 0 || D_001A4BE0.f[0xcf] < 1.0f) { func_L30_004CF4B0(0x7b, 1); return 0; }
        }
        if (D_001A4BE0.i[0x971] != 0x73 && D_001A4BE0.h[0x1b4] == 1 && action != 0xe &&
            action != 0x38 && !D_L30_001D6740) { func_L30_004CF4B0(0x73, 1); return 0; }
        if (D_001A4BE0.i[0x974] == 0x11 && !D_001A4BE0.b[0x285e]) D_001A4BE0.b[0x285f]++;
        else D_001A4BE0.b[0x285f] = 0;
        if (D_001A4BE0.h[0x109]) {
            D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x972] = oldStep; D_001A4BE0.i[0x6e] = D_001A4BE0.i[0x976];
            return 0;
        }
        D_001A4BE0.i[0x973] = 4;
        if ((u32)(action - 0x28) < 2) D_001A4BE0.u[0xa03] = 3; else D_001A4BE0.u[0xa03] = 0x50;
        if (D_001A4BE0.i[0x971] == 0x7 || D_001A4BE0.i[0x971] == 0xf || D_001A4BE0.i[0x971] == 0xd ||
            (D_001A4BE0.i[0x971] == 0xb && D_001A4BE0.i[0x975] != 0x4) || D_001A4BE0.i[0x971] == 0x69) {
            oldWeapon = D_001A4BE0.b[0x147f];
            func_L01_004E11C0(oldWeapon, 0, 0, 30);
            func_L01_004E11C0(oldWeapon, 1, 0, 30);
        }
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.i[0x971] != 0x12 && D_001A4BE0.b[0x1476] && D_001A4BE0.f[0x22] < D_001A4BE0.f[0xd4] + 0.5f)
            func_L01_004E5EB8(3, 0x10, 0);
        if (D_001A4BE0.i[0x971] == 0x6b) func_L01_004F4E70(8, 0);
        D_001A4BE0.f[0x118] = D_001A4BE0.f[0x22]; D_001A4BE0.f[0x13c] = 0.011880001f; D_001A4BE0.i[0x106] = -1; D_001A4BE0.f[0x134] = 0.008f;
        D_001A4BE0.f[0x135] = 0.0044f; D_001A4BE0.f[0x138] = 2.5f; D_001A4BE0.uh[0x27c] = D_001A4BE0.b[0x1474]; D_001A4BE0.uh[0x275] = 0x43;
        D_001A4BE0.b[0x46e] = 0; D_001A4BE0.b[0x46c] = 0; D_001A4BE0.u[0x120] = 0; D_001A4BE0.u[0x121] = 0; D_001A4BE0.b[0x46d] = 0;
        D_001A4BE0.uh[0x27a] = 0; D_001A4BE0.b[0x4fc] = 0; D_001A4BE0.b[0x4fe] = 0; D_001A4BE0.b[0x4ff] = 0; D_001A4BE0.uh[0x27d] = 0x3a;
        D_001A4BE0.uh[0x27b] = 0; D_001A4BE0.f[0x139] = 0.5f; D_001A4BE0.f[0x11d] = 0.12340001f; D_001A4BE0.f[0x119] = 0.30019665f;
        D_001A4BE0.f[0x11c] = 1.0000001f; D_001A4BE0.f[0x10a] = 0.0f; D_001A4BE0.b[0x46f] = 0; D_001A4BE0.uh[0x142e] = 0;
        if (D_001A4BE0.i[0x971] == 0x7 || D_001A4BE0.i[0x971] == 0x69) {
            D_001A4BE0.f[0x11e] = 1.42f; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f;
            D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 2.7f; D_001A4BE0.f[0x136] = 1.42f; D_001A4BE0.uh[0x274] = 14; D_001A4BE0.h[0x23e] = 1;
            D_001A4BE0.b[0x4fc] = 1; D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.b[0x4ff] = 1;
            if (D_001D545C == 0) {
                D_001A4BE0.f[0x136] = D_L30_001DBB70; D_001A4BE0.uh[0x27b] = 0x8e; D_001A4BE0.uh[0x27d] = 0x8e; D_001A4BE0.f[0x137] = D_L30_001DBB74;
                D_001A4BE0.f[0x11e] = D_L30_001DBB70; D_001A4BE0.f[0x13c] = D_L30_001DBB78 * 0.00040000002f; D_001A4BE0.u[0xa03] = 0;
            }
            D_001A4BE0.f[0x10a] = D_001A4BE0.f[0x13c] * 1.17f;
        }
        else if (D_001A4BE0.i[0x971] == 0x86) {
            D_001A4BE0.f[0x11e] = D_L30_001DBBA8; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = D_L30_001DBBA8 + 0.5f;
            D_001A4BE0.f[0x136] = D_L30_001DBBA8; D_001A4BE0.uh[0x274] = 14; D_001A4BE0.uh[0x275] = 333; D_001A4BE0.f[0x138] = 300.0f;
            D_001A4BE0.f[0x13c] = D_L30_001DBBAC * 0.00040000002f; D_001A4BE0.uh[0x27b] = 1000; D_001A4BE0.uh[0x27d] = 1000;
            D_001A4BE0.f[0x11d] = 0.14000002f;
            if (D_001439F4 != 2) {
                func_L01_0044E318(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 70, 2, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 35, 4, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 17, 6, 0.0f);
            }
        }
        else if (D_001A4BE0.i[0x971] == 0x12) {
            D_001A4BE0.f[0x11e] = 0.1f; D_001A4BE0.h[0x23e] = 2; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 28.0f;
            D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 0.2f; D_001A4BE0.f[0x136] = 0.1f; D_001A4BE0.uh[0x274] = 8; D_001A4BE0.b[0x4ff] = 1;
            if (D_001A4BE0.f[0xa12] < 1.25f) {
                D_001A4BE0.f[0x136] = 1.95f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x137] = 1.98f; D_001A4BE0.f[0x11e] = D_001A4BE0.f[0x136];
            } else {
                func_L01_00511508((V4_F6a70b950 *)(D_001A4BE0.b + 0xf0), (V4_F6a70b950 *)(D_001A4BE0.b + 0xf0), D_001A4BE0.f[0x120]);
                D_001A4BE0.f[0x136] = 1.95f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x137] = 1.98f; D_001A4BE0.f[0x11e] = D_001A4BE0.f[0x136];
            }
            D_001A4BE0.b[0x25e8] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x38) {
            D_001A4BE0.f[0x11e] = 5.5f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 26.0f; D_001A4BE0.f[0x128] = 13.0f; D_001A4BE0.f[0x137] = 5.55f; D_001A4BE0.f[0x136] = 5.5f;
            D_001A4BE0.uh[0x274] = 2; D_001A4BE0.uh[0x275] = 100; D_001A4BE0.b[0x46f] = 1;
            func_L01_004DFEA0(1);
            D_00142660[0x5a] = 0; D_00142660[0x5b] = 0;
            if (func_L01_00500240(0x38, 100) || D_001A4BE0.i[0xa14] == 0) {
                D_001A4BE0.i[0x6dc]++;
                if (D_001A4BE0.i[0x6dc] > 2 || D_001A4BE0.i[0xa14] == 0) {
                    if (*(s32 *)(*(u8 **)(D_001A4BE0.ptr[0x970] + 0x24) + 0x1A8)) func_L30_004CF4B0(0x7e, 1);
                    else func_L30_004CF4B0(0x39, 1);
                    return 0;
                }
            } else D_001A4BE0.i[0x6dc] = 0;
            D_001A4BE0.uh[0x27d] = 125; D_001A4BE0.f[0x13c] = 0.006f; D_001A4BE0.uh[0x276] = 4; D_001A4BE0.uh[0x277] = 3;
        }
        else if (D_001A4BE0.i[0x971] == 0x6b) {
            f32 height;
            D_001A4BE0.i[0x973] = 25;
            if (D_001A4BE0.f[0x22] < D_001A4BE0.f[0xd5]) height = D_001A4BE0.f[0xd5] - D_001A4BE0.f[0x22]; else height = D_001A4BE0.f[0x120];
            D_001A4BE0.f[0x11e] = height + 1.7f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f;
            D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = height + 1.75f; D_001A4BE0.f[0x136] = height + 1.7f; D_001A4BE0.uh[0x274] = 16; D_001A4BE0.b[0x46f] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x28) {
            D_001A4BE0.f[0x11e] = 2.4f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 28.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 2.45f; D_001A4BE0.f[0x136] = 2.4f;
            D_001A4BE0.uh[0x274] = 14; D_001A4BE0.i[0x973] = 15; D_001A4BE0.f[0x13c] = 0.0108f; D_001A4BE0.i[0x18d] = 0;
        }
        else if (D_001A4BE0.i[0x971] == 0x29) {
            D_001A4BE0.f[0x11e] = 2.5f; D_001A4BE0.h[0x23e] = 2; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 31.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 2.55f; D_001A4BE0.f[0x136] = 2.5f;
            D_001A4BE0.uh[0x274] = 8; D_001A4BE0.i[0x973] = 15; D_001A4BE0.f[0x13c] = 0.0096f; D_001A4BE0.i[0x18d] = 0;
        }
        else if (D_001A4BE0.i[0x971] == 0x9) {
            D_001A4BE0.f[0x11e] = 1.42f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 29.0f; D_001A4BE0.f[0x128] = 11.0f; D_001A4BE0.f[0x137] = 2.7f; D_001A4BE0.f[0x136] = 1.42f;
            D_001A4BE0.uh[0x274] = 14; D_001A4BE0.f[0x11d] = 0.12340001f;
            if (D_001D545C == 0) {
                D_001A4BE0.f[0x136] = D_L30_001DBB70; D_001A4BE0.uh[0x27b] = 0x8e; D_001A4BE0.uh[0x27d] = 0x8e; D_001A4BE0.f[0x137] = D_L30_001DBB74;
                D_001A4BE0.f[0x11e] = D_L30_001DBB70; D_001A4BE0.f[0x13c] = D_L30_001DBB78 * 0.00040000002f;
            }
            D_001A4BE0.b[0x4fc] = 1;
            D_001A4BE0.b[0x4fe] = 1;
            D_001A4BE0.b[0x4ff] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x73) {
            D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 2.75f; D_001A4BE0.f[0x11e] = 2.7f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x136] = 2.7f; D_001A4BE0.uh[0x274] = 4; D_001A4BE0.b[0x4fc] = 1; D_001A4BE0.b[0x46f] = 1; D_001A4BE0.b[0x4fe] = 0; D_001A4BE0.b[0x4ff] = 0;
            if (D_001D545C == 0x15) {
                D_001A4BE0.f[0x11d] = 0.070338f;
                if (D_001A4BE0.f[0x6d] > 0.070338f) D_001A4BE0.f[0x6d] = 0.070338f;
            }
        }
        else if (D_001A4BE0.i[0x971] == 0x45) {
            D_001A4BE0.f[0x11e] = 1.8f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 15.0f; D_001A4BE0.f[0x127] = 22.0f;
            D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 1.85f; D_001A4BE0.f[0x136] = 1.8f; D_001A4BE0.uh[0x274] = 12;
            D_001A4BE0.f[0x13c] = 0.0076f;
            func_L01_004606A8(0);
            D_001A4BE0.f[0x135] = 0.020000001f; D_001A4BE0.f[0x11d] = 0.06600001f;
        }
        else if (D_001A4BE0.i[0x971] == 0x54) {
            D_001A4BE0.f[0x11e] = 2.7f; D_001A4BE0.f[0x127] = 20.0f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.5f; D_001A4BE0.f[0x126] = 15.5f;
            D_001A4BE0.f[0x128] = 20.0f; D_001A4BE0.f[0x137] = 2.75f; D_001A4BE0.f[0x136] = 2.7f; D_001A4BE0.uh[0x274] = 8;
            D_001A4BE0.f[0x13c] = 0.010000001f; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x135] = 0.020000001f; D_001A4BE0.f[0x11d] = 0.10000001f;
        }
        else if (D_001A4BE0.i[0x971] == 0xa2) {
            D_001A4BE0.f[0x11e] = 3.5f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 1.2f; D_001A4BE0.f[0x126] = 13.0f;
            D_001A4BE0.f[0x127] = 18.0f; D_001A4BE0.f[0x128] = 18.0f; D_001A4BE0.f[0x137] = 7.5f; D_001A4BE0.f[0x136] = 3.5f;
            D_001A4BE0.uh[0x274] = 19; D_001A4BE0.f[0x13c] = 0.0388f; D_001A4BE0.f[0x11c] = 0.6f; D_001A4BE0.f[0x139] = 1.0f;
            func_L01_004F4E70(12, 0);
            D_001A4BE0.f[0x135] = 0.028f; D_001A4BE0.f[0x11d] = 0.18f;
        }
        else if (D_001A4BE0.i[0x971] == 0xac) {
            D_001A4BE0.f[0x11e] = 7.5f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 1.2f; D_001A4BE0.f[0x126] = 14.0f;
            D_001A4BE0.f[0x127] = 20.0f; D_001A4BE0.f[0x128] = 20.0f; D_001A4BE0.f[0x137] = 7.7f; D_001A4BE0.f[0x136] = 7.5f;
            D_001A4BE0.uh[0x274] = 2; D_001A4BE0.f[0x13c] = 0.020000001f; D_001A4BE0.f[0x11c] = 0.6f; D_001A4BE0.f[0x139] = 1.0f;
            D_001A4BE0.f[0x135] = 0.028f; D_001A4BE0.f[0x11d] = 0.18f;
        }
        else if (D_001A4BE0.i[0x971] == 0xa7) {
            D_001A4BE0.f[0x11e] = 7.7f; D_001A4BE0.h[0x23e] = 8; D_001A4BE0.f[0x122] = 1.2f; D_001A4BE0.f[0x126] = 13.0f;
            D_001A4BE0.f[0x127] = 22.0f; D_001A4BE0.f[0x128] = 35.0f; D_001A4BE0.f[0x137] = 7.75f; D_001A4BE0.f[0x136] = 7.7f;
            D_001A4BE0.uh[0x274] = 4; D_001A4BE0.f[0x11c] = 0.6f; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x135] = 0.028f;
            D_001A4BE0.h[0xd95] = 30; D_001A4BE0.i[0x6cb] = D_001A4BE0.h[0xd94]; D_001A4BE0.f[0x13c] = 0.028f;
            D_001A4BE0.f[0x12e] = func_0038DAB8(D_001A4BE0.f[0x26], 3.1415927f);
            D_001A4BE0.f[0x11d] = 0.18f;
        }
        else if (D_001A4BE0.i[0x971] == 0xa) {
            D_001A4BE0.f[0x11e] = 1.9f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 29.0f;
            D_001A4BE0.f[0x128] = 10.0f; D_001A4BE0.f[0x137] = 1.95f; D_001A4BE0.f[0x136] = 1.9f; D_001A4BE0.uh[0x274] = 12;
            D_001A4BE0.f[0x13c] = 0.0044f; D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.uh[0x275] = 100; D_001A4BE0.uh[0x27d] = 75;
            D_001A4BE0.uh[0x27b] = 0x3a;
        }
        else if (D_001A4BE0.i[0x971] == 0x10) {
            D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x11e] = 1.5f; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f;
            D_001A4BE0.f[0x128] = 11.0f; D_001A4BE0.f[0x137] = 1.55f; D_001A4BE0.f[0x136] = 1.5f; D_001A4BE0.uh[0x274] = 1;
            func_L01_003F1F20(20, 0);
            D_001A4BE0.f[0x137] = 0.9f; D_001A4BE0.f[0x11e] = 0.4f; D_001A4BE0.f[0x136] = 0.4f;
            if (D_001A4BE0.f[0x61] < 0.40000004f && D_001439F4 != 2) {
                func_L01_0044E318(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 40, 2, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 20, 4, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 10, 6, 0.0f);
            }
            D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.f[0x109] = 0.23000002f; D_001A4BE0.f[0x13c] = 0.0034000003f; D_001A4BE0.f[0x134] = 0.0176f;
            D_001A4BE0.f[0x135] = 0.020000001f;
        }
        else if (D_001A4BE0.i[0x971] == 0x1b) {
            D_001A4BE0.f[0x11e] = 2.0f; D_001A4BE0.h[0x23e] = 3; D_001A4BE0.f[0x122] = 0.85f; D_001A4BE0.f[0x126] = 20.0f;
            D_001A4BE0.f[0x127] = 29.0f; D_001A4BE0.f[0x128] = 19.0f; D_001A4BE0.f[0x137] = 2.05f; D_001A4BE0.f[0x136] = 2.0f;
            D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x13c] = 0.010000001f; D_001A4BE0.uh[0x274] = 1; D_001A4BE0.i[0x123] = 0;
            D_001A4BE0.b[0x46f] = 1; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.b[0x4fe] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x48) {
            D_001A4BE0.f[0x11e] = 1.55f; D_001A4BE0.f[0x127] = 14.0f; D_001A4BE0.h[0x23e] = 11; D_001A4BE0.f[0x122] = 0.85f;
            D_001A4BE0.f[0x126] = 8.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 1.59f; D_001A4BE0.f[0x136] = 1.55f;
            D_001A4BE0.uh[0x274] = 1; D_001A4BE0.i[0x123] = 0; D_001A4BE0.f[0x13c] = 0.0112000005f;
        }
        else if (D_001A4BE0.i[0x971] == 0x11) {
            D_001A4BE0.h[0x23e] = 7; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 12.0f; D_001A4BE0.f[0x127] = 20.0f;
            D_001A4BE0.f[0x128] = 10.0f; D_001A4BE0.uh[0x274] = 10;
            if (D_001A4BE0.b[0x285e]) {
                f32 w = D_001A4BE0.f[0xa18];
                D_001A4BE0.f[0x11a] = 0.09800001f; D_001A4BE0.f[0x137] = 3.35f; D_001A4BE0.f[0x136] = 3.3f;
                if (w > 7.0f) {
                    f32 t = (w - 7.0f) / 4.2f;
                    if (t > 0.7f) t = 0.7f;
                    t += 1.0f;
                    D_001A4BE0.f[0x11a] = t * 0.09800001f;
                }
            } else {
                D_001A4BE0.f[0x11a] = 0.034f; D_001A4BE0.f[0x137] = 1.85f; D_001A4BE0.f[0x136] = 1.8f;
            }
            D_001A4BE0.b[0x46f] = 1; D_001A4BE0.f[0x11e] = D_001A4BE0.f[0x136];
            func_L01_003F1F20(0x1b, 0);
            D_001A4BE0.uh[0x27d] = 0x43; D_001A4BE0.f[0x13c] = 0.011600001f; (*(u128_t *)(D_001A4BE0.b + 0x4c0) = *(u128_t *)(D_001A4BE0.b + 0x4b0));
            D_001A4BE0.uh[0x142e] = 1; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x4fc] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0xd) {
            D_001A4BE0.h[0x23e] = 7; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 26.0f; D_001A4BE0.f[0x127] = 38.0f;
            D_001A4BE0.f[0x128] = 18.0f; D_001A4BE0.f[0x137] = 4.07f; D_001A4BE0.uh[0x274] = 12; D_001A4BE0.f[0x11e] = 4.0f;
            D_001A4BE0.f[0x136] = 4.0f;
            func_L01_003F1F20(20, 0);
            D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x275] = 100; D_001A4BE0.f[0x11d] = 0.038000003f; D_001A4BE0.uh[0x27b] = 31;
            if (D_001A4BE0.f[0x61] < 0.40000004f && D_001439F4 != 2) {
                func_L01_0044E318(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 40, 3, 0.0f);
                func_L01_0044E340((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 20, 5, 0.0f);
            }
            D_001A4BE0.b[0x4fe] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0xf) {
            D_001A4BE0.f[0x11e] = 1.65f; D_001A4BE0.h[0x23e] = 7; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 50.0f;
            D_001A4BE0.f[0x127] = 64.0f; D_001A4BE0.f[0x128] = 28.0f; D_001A4BE0.f[0x137] = 1.7f; D_001A4BE0.f[0x136] = 1.65f;
            D_001A4BE0.uh[0x274] = 4; D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x275] = 0x6c; D_001A4BE0.f[0x11d] = 0.06600001f;
            D_001A4BE0.uh[0x27b] = 0x47; D_001A4BE0.uh[0xe8] = 0x3a; D_001A4BE0.b[0x46d] = 1;
            if (D_00143950) D_001A4BE0.i[0x100] = 0x1c; else D_001A4BE0.i[0x100] = 0x1d;
            D_001A4BE0.i[0x101] = D_001A4BE0.i[0x100] + 0x1e;
            D_001A4BE0.f[0x102] = 29.0f;
            D_001A4BE0.f[0x103] = 50.0f;
            D_001A4BE0.u[0x104] = 0x48;
            D_001A4BE0.ptr[0x105] = D_L30_001DBCE8;
            D_001A4BE0.b[0x4fe] = 1;

        }
        else if (D_001A4BE0.i[0x971] == 0xe) {
            f32 h = D_001A4BE0.f[0xcf], v = 0.7f;
            if (h < 2.0f) v = (2.5f - h) * 0.5f + v;
            D_001A4BE0.f[0x11e] = v; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 32.0f; D_001A4BE0.f[0x127] = 43.0f;
            D_001A4BE0.f[0x128] = 19.0f; D_001A4BE0.f[0x137] = v + 0.05f; D_001A4BE0.f[0x136] = v; D_001A4BE0.h[0x23e] = -1;
            D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x11d] = 0.095000006f; D_001A4BE0.uh[0x274] = 12; D_001A4BE0.uh[0x27b] = 0x19;
        }
        else if (D_001A4BE0.i[0x971] == 0xb) {
            D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x127] = 31.0f; D_001A4BE0.f[0x136] = 3.2f; D_001A4BE0.uh[0x274] = 12; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.uh[0x27d] = 0x2a; D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.f[0x128] = 24.0f; D_001A4BE0.f[0x137] = 3.25f; D_001A4BE0.b[0x46f] = 1; D_001A4BE0.f[0x11e] = 3.2f; D_001A4BE0.f[0x139] = 1.0f;
            D_001A4BE0.f[0x125] = func_L01_004E93F8(8, 1);
            (*(u128_t *)(D_001A4BE0.b + 0x450) = *(u128_t *)(D_001A4BE0.b + 0x0));
            D_001A4BE0.i[0x129] = func_L01_004FF610();
            D_001A4BE0.f[0x124] = D_001A4BE0.f[0x68];
            (*(u128_t *)(D_001A4BE0.b + 0x440) = *(u128_t *)(D_001A4BE0.b + 0x190));
            if (D_001A4BE0.f[0x5d] > 0.030000001f) D_001A4BE0.f[0x12a] = D_001A4BE0.f[0x5d];
            else D_001A4BE0.f[0x12a] = 0.0f;
            D_001A4BE0.u[0x12b] = 0;
            D_001A4BE0.b[0x4fc] = 1;
            if ((D_001A4BE0.h[0xa1a] || (D_001A4BE0.i[0x5ac] == 1 && func_L01_004606E8(0x28, 2, 0, 0))) && D_001A4BE0.f[0xa0e] > 0.3f) {
                func_L30_004BCB20(0, D_001A4BE0.f[0x6c]);

                D_001A4BE0.f[0x124] = D_001A4BE0.f[0x68];
                (*(u128_t *)(D_001A4BE0.b + 0x440) = *(u128_t *)(D_001A4BE0.b + 0x1420));
                D_001A4BE0.f[0x12b] = 0.10000001f;
                D_001A4BE0.b[0x4fd] = 1;
            } else D_001A4BE0.b[0x4fd] = 0;
            D_001A4BE0.b[0x4fe] = 1;
        }
        if (D_001A4BE0.f[0x138] == 0.0f) D_001A4BE0.f[0x138] = D_001A4BE0.f[0x11e] * 1.5f;
        if (!animate) goto finish;
        if (D_001A4BE0.i[0x971] == 0x7 || D_001A4BE0.i[0x971] == 0x69) func_L01_0050FB40(7, 1, -4.0f);
        else if (D_001A4BE0.i[0x971] == 0x73) func_L01_0050FB40(7, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x86) func_L01_0050FB40(7, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x12) func_L01_0050FB40(0x59, 1, -4.0f);
        else if (D_001A4BE0.i[0x971] == 0x38) func_L01_0050FB40(0x3e, 0, 3.0f);
        else if (D_001A4BE0.i[0x971] == 0x6b) func_L01_0050FB40(7, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x28) func_L01_0050FB40(0x48, 4, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x29) {
            s32 turn = 0x1e;
            if (func_0038DBA0(D_001A4BE0.f[0x26], func_0038D160(D_001A4BE0.f[0x15c] - D_001A4BE0.f[0x16c], D_001A4BE0.f[0x15d] - D_001A4BE0.f[0x16d])) > 1.5707964f) turn = 0x1f;
            func_L01_0050FB40(turn, 0, 4.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0x9) {
            index = (s32)D_001A4BE0.f[0x306];
            animation_41 = 8;
            if (func_L01_004DFE80(objectSnapshot[0x42]) == 4) animation_41 = D_L30_001DBCC8[index];
            func_L01_0050FB40(animation_41, 0, 4.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0x45) func_L01_0050FB40(0x16, 5, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x54) func_L01_0050FB40(3, 5, 2.0f);
        else if (D_001A4BE0.i[0x971] == 0xa2) {
            if (D_001A4BE0.i[0x975] == 1) {
                D_001A4BE0.f[0x128] = 20.0f; D_001A4BE0.f[0x126] = 14.0f; D_001A4BE0.f[0x127] = 20.0f;
                func_L01_0050FB40(func_L30_004E6DC8(0x3c), 5, 3.0f);
            } else func_L01_0050FB40(func_L30_004E6DC8(0x2c), 4, 2.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0xac) func_L01_0050FB40(0x41, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0xa7) func_L01_0050FB40(0x32, 6, 3.0f);
        else if (D_001A4BE0.i[0x971] == 0xa) func_L01_0050FB40(0x12, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x10) {
            if (D_001A4BE0.i[0x975] == 4 || (D_001A4BE0.i[0x974] == 4 && D_001A4BE0.i[0x6e] < 6)) {
                func_L01_0050FB40(0x26, 0, 7.0f);
                D_001A4BE0.uh[0x23e] += 2;
            } else func_L01_0050FB40(0x26, 0, 4.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0x1b) func_L01_0050FB40(0x22, 2, 2.0f);
        else if (D_001A4BE0.i[0x971] == 0x48) func_L01_0050FB40(9, 0, 3.0f);
        else if (D_001A4BE0.i[0x971] == 0x11) func_L01_0050FB40(0x23, 2, 6.0f);
        else if (D_001A4BE0.i[0x971] == 0xd) func_L01_0050FB40(0x11, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0xe) { func_L01_0050FB40(0x16, 3, 6.0f); D_001A4BE0.f[0x300] = 0.96000004f; }
        else if (D_001A4BE0.i[0x971] == 0xf) func_L01_0050FB40(0x15, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0xb) {
            s32 a = D_001A4BE0.i[0x129] + 0x1c;
            if (D_001D545C_b[0xd]) {
                if (a == 0x1c) a = 0x1d;
                else if (a == 0x1d) a = 0x1c;
            }
            if (D_001A4BE0.i[0x975] == 4) { func_L01_0050FB40(a, 1, 3.0f); D_001A4BE0.h[0x23e] = 1; }
            else func_L01_0050FB40(a, 0, 4.0f);
        }
        goto finish;
    case 0x13: case 0x14: case 0x15: case 0x22: case 0x4d: case 0x88:
        if (D_001A4BE0.h[0x1445] && D_001A4BE0.i[0x971] == 0x15) {
            D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x972] = oldStep; D_001A4BE0.i[0x6e] = D_001A4BE0.i[0x976];
            return 0;
        }
        D_001A4BE0.i[0x973] = 6;
        if (D_001A4BE0.i[0x5ac] == 2 && (u32)(D_001A4BE0.i[0x971] - 0x13) < 3) {
            if (D_001A7C10[1].count < 0xFFFF) D_001A7C10[1].count++;
            if (D_001A7C10[1].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[1].maximum = (D_001D4C38 * 5 + 2) / 6;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C)) | 0x80000000u;
            if (D_001A4BE0.i[0x48a] == 0x7f && func_L01_005119E0(-1)) func_L01_004F5AE8();
            else func_L01_004F5810();
            D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x973] = D_001A4BE0.i[0x975];
            return 0;
        }
        if (D_001A4BE0.i[0x48a] == 0x7f && !func_L01_005119E0(-1)) {
            D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x973] = D_001A4BE0.i[0x975];
            return 0;
        }
        if (action != 0x88) D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x2f5] = 1.0f; D_001A4BE0.i[0x2f2] = 0; D_001A4BE0.u[0x2f1] = 0; D_001A4BE0.uh[0x5ef] = 0;
        switch (D_001A4BE0.i[0x971]) {
        case 0x14:
            if (D_001A7C10[0].count < 0xFFFF) D_001A7C10[0].count++;
            if (D_001A7C10[0].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[0].maximum = (D_001D4C38 * 5 + 2) / 6;
            D_001A7C10[0].levels = (D_001A7C10[0].levels | (1u << D_001D545C)) | 0x80000000u;
            D_001A4BE0.u[0xa03] = 0x50; D_001A4BE0.h[0x5ee] = 4; D_001A4BE0.i[0x98c] = 0;
            func_L01_004F2880(8.0f, 1.0471976f, -1.0f); D_001A4BE0.u[0x2f8] = 0;
            if (animate) {
                selected_14 = D_001A4BE0.i[0x974] == 0xb && D_001A4BE0.i[0x976] < 35 ? 14 : 9;
                func_L01_005118D0(-1, 1);
                D_L30_001DDA64 = 1;
                func_L01_0050FB40(0x28, 4, (f32)selected_14);
                animation_14 = func_L01_004E9200(0);
                if (func_L01_004EDFA8((u8 *)animation_14)) func_003C3A10((u8 *)animation_14, 10, 4, selected_14 + 2);
            }
            goto finish;
        case 0x15:
            if (D_001A7C10[1].count < 0xFFFF) D_001A7C10[1].count++;
            if (D_001A7C10[1].maximum < (D_001D4C38 * 5 + 2) / 6) D_001A7C10[1].maximum = (D_001D4C38 * 5 + 2) / 6;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C)) | 0x80000000u;
            D_001A4BE0.h[0x5ee] = 3; D_001A4BE0.i[0x98c] = 0;
            func_L01_004F2880(14.0f, 0.5235988f, -1.0f);
            D_001A4BE0.u[0x2fb] = D_001A4BE0.u[0x2fb] == 0;
            if (D_001A4BE0.h[0xa1a] || (D_001A4BE0.i[0x5ac] == 1 && func_L01_004606E8(0x28, 2, 0, 0))) {
                D_001A4BE0.i[0x2f2] = 1; D_001A4BE0.f[0x2f3] = D_001A4BE0.f[0x26];
            }
            if (animate) {
                selected_15 = D_001A4BE0.ptr[0x970][0x43] == 0x1A ? 2 : 4;
                if (D_001A4BE0.i[0x974] == 0x1) selected_15 = 14;
                func_L01_0050FB40(0x1A, 0, (f32)selected_15); func_L01_0050FE88(6, 21);
            }
            goto finish;
        case 0x88:
            D_001A4BE0.h[0x5ee] = 3;
            if (animate) {
                selected_83 = D_001A4BE0.ptr[0x970][0x43] == 0x1A ? 2 : 8;
                if (D_001A4BE0.i[0x974] == 0x1) selected_83 = 14;
                func_L01_0050FB40(0x1A, 0, (f32)selected_83);
            }
            goto finish;
        case 0x13:
        {
        s32 *entry = D_L30_002F4C70[D_001A4BE0.h[0x5ee]];
        D_001A4BE0.i[0x98c] = 0; mode = 0;
        if ((D_001A4BE0.i[0x974] == 0x13 && (f32)entry[2] > D_001A4BE0.f[0x306]) ||
            (D_001A4BE0.i[0x977] == 0x13 && D_001A4BE0.i[0x6e] + D_001A4BE0.i[0x976] < 22)) mode = (entry[1] + 1) % 3;
        }
        D_001A4BE0.h[0x5ee] = mode;
        func_L01_004F2880(5.0f, 0.7853982f, 0.7853982f);
        if (animate) {
            current = 0;
            if (mode == 0) { func_L01_005118D0(-1, 1); selected_13 = 4; D_L30_001DDA64 = 1; }
            else if (mode == 1) { func_L01_005118D0(-1, 1); current = 2; D_L30_001DDA64 = 1; selected_13 = 6; }
            else { func_L01_005118D0(-1, 1); current = 4; D_L30_001DDA64 = 1; selected_13 = 6; }
            if (D_001A4BE0.i[0x2f2] && mode < 2) {
                if (D_001A4BE0.b[0x25f4]) angle_13 = func_L01_004F4E20((D_001A4BE0.b + 0xba0), 0);
                else angle_13 = func_0038DBA0(D_001A4BE0.f[0x2f3], D_001A4BE0.f[0x26]);
                selected_13 += (s32)(angle_13 * 1.5f);
            }
            current /= 2;
            func_L01_0050FB40(mode + 0x17, current, (f32)selected_13);
            animation_13 = func_L01_004E9200(0);
            if (func_L01_004EDFA8((u8 *)animation_13)) func_L01_00444F38((u8 *)animation_13, mode + 3, current, selected_13, 0x10);
        }
        goto finish;
        case 0x4d: {
            s32 m4d;
            s32 *row = D_L30_002F4C70[D_001A4BE0.h[0x5ee]];
            m4d = 0;
            if ((D_001A4BE0.i[0x975] == 0x6 || (D_001A4BE0.i[0x978] == 0x6 && (u32)(D_001A4BE0.ptr[0x970][0x43] - 15) < 2)) &&
                row[0] == 0 && (f32)row[2] > D_001A4BE0.f[0x306]) m4d = (row[1] + 1) % 2;
            D_001A4BE0.h[0x5ee] = m4d + 7;
            func_L01_004F2880(5.0f, 0.7853982f, 0.7853982f);
            if (animate) func_L01_0050FB40(m4d + 0xF, 2, 3.0f);
            goto finish; }
        case 0x22:
            if (animate) func_L01_0050FB40(0x29, 7, 7.0f);
            goto finish;
        }
        goto finish;
    case 0x72:
        D_001A4BE0.i[0x973] = 6; D_001A4BE0.uh[0x5ef] = 0;
        if (D_001A4BE0.i[0x974] == 0x72) D_001A4BE0.h[0x5ee] = D_L30_002F4C70[D_001A4BE0.h[0x5ee]][1] == 0 ? 6 : 5;
        else D_001A4BE0.h[0x5ee] = 5;
        {
            s32 kind = D_L30_002F4C70[D_001A4BE0.h[0x5ee]][1];
            s32 still;
            u32 object;
            if (!animate) goto finish;
            still = kind == 0;
            func_L01_0050FB40(kind + 0x17, still, 5.0f);
            object = func_L01_004E9200(0);
            if (func_L01_004EDFA8((u8 *)object)) func_003C3A10((u8 *)object, kind + 0xC, still, 5);
        }
        goto finish;
    case 0x2a:
        D_001A4BE0.i[0x973] = 15; D_001A4BE0.uh[0x5ef] = 0;
        if (D_001A4BE0.i[0x974] == 0x2a) D_001A4BE0.h[0x5ee] = D_001A4BE0.h[0x5ee] == 0; else D_001A4BE0.h[0x5ee] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(D_001A4BE0.h[0x5ee] + 0x4B, 0, 4.0f);
        {
            u32 object = func_L01_004E9200(0);
            if (func_L01_004EDFA8((u8 *)object)) func_003C3A10((u8 *)object, D_001A4BE0.h[0x5ee] + 0xC, 0, 4);
        }
        goto finish;
    case 0x7c:
        D_001A4BE0.i[0x973] = 10; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x2f4] = func_0038DAB8(D_001A4BE0.f[0x26], 3.1415927f);
        func_0038CE20((D_001A4BE0.b + 0xbb0), (D_001A4BE0.b + 0x0), -1.0f); D_001A4BE0.f[0x6d] = 0.18f;
        if (!animate) goto finish;
        func_L01_0050FB40(0x27, 5, 7.0f); goto finish;
    case 0x16:
        D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x973] = 7;
        func_L01_004F1190(0.5f); func_L01_003F1F20(18, 0);
        D_001A4BE0.uh[0x107] = 0x25; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0.b + 0xf0), 0.14000002f);
        hit_44 = func_L01_00447490(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_44) func_L01_004DFEA0((s32)(*(f32 *)(hit_44 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 64;
        if (!animate) goto finish;
        func_L01_0050FB40(0x10, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4E00[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x91:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0; func_L01_004F1190(0.5f);
        D_001A4BE0.b[0x25ed] = 1; func_L01_003F1F20(18, 0);
        hit_45 = func_L01_00447490(D_001A4BE0.ptr[0x970], 8, 0);
        if (hit_45) func_L01_004DFEA0((s32)(*(f32 *)(hit_45 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 64;
        if (!animate) goto finish;
        func_L01_0050FB40(0x74, 1, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4E00[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x6a:
        D_001A4BE0.i[0x973] = 0x19; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x6dc]++;
        func_L01_004F4E70(7, 0);
        D_001A4BE0.i[0xf0] = 0; D_001A4BE0.u[0x6c] = 0; D_001A4BE0.u[0x6d] = 0; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x58, 0, 7.0f); goto finish;
    case 0x7d:
        D_001A4BE0.i[0x973] = 0x19; D_001A4BE0.uh[0xf8] = 10000; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F4E70(7, 0);
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050FB40(0x58, 0, 7.0f); goto finish;
    case 0x7e:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.f[0xd5] = D_001A4BE0.f[0xce]; D_001A4BE0.uh[0xf8] = 10000;
        D_001A4BE0.i[0xa14] = 0; D_001A4BE0.u[0xa03] = 0; func_L01_004F4E70(7, 0);
        if (!animate) goto finish;
        func_L01_0050FB40(0x6A, 0, 8.0f); goto finish;
    case 0x7f:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.uh[0xf8] = 10000; D_001A4BE0.f[0xd5] = D_001A4BE0.f[0xce];
        D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0xa14] = 0;
        { u8 *moby = D_001A4BE0.ptr[0x2fe]; *(u128_t *)(moby + 0x10) = *(u128_t *)(D_001A4BE0.b + 0x80);
        func_003A52A0(7, 0, moby); }
        if (!animate) goto finish;
        func_L01_0050FB40(0x11, 0, 8.0f); goto finish;
    case 0x3f:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CF4B0(0x4e, 1); return 0; }
        if (!animate) goto finish;
        func_L01_0050FB40(func_L30_004AD910(0), 0, 7.0f); goto finish;
    case 0x4b:
        D_001A4BE0.i[0x973] = 5; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.f[0x5c] > 0.09f) func_L01_004F1190(0.09f / D_001A4BE0.f[0x5c]);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050FB40(14, 0, 10.0f); goto finish;
    case 0x4f:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0; qzero(D_001A4BE0.b + 0xf0);
        if (!animate) goto finish;
        func_L01_0050FB40(0x20, 2, 3.0f); goto finish;
    case 0x41:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.f[0x281] = 0.0028000001f; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 7.0f); goto finish;
    case 0x44:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 7.0f); goto finish;
    case 0x4e:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(4, 0, 10.0f); goto finish;
    case 0x42:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.5f);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0.b + 0xf0), 0.10000001f);
        hit_52 = func_L01_00447490(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_52) func_L01_004DFEA0((s32)(*(f32 *)(hit_52 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0x107] = 0x25;
        if (D_001A4BE0.i[0xa14] <= 0) { func_L30_004CF4B0(0x43, 1); func_L01_003F1F20(18, 0); return 0; }
        func_L01_003F1F20(18, 0);
        D_001A4BE0.uh[0xee] = 0x2a;
        if (!animate) goto finish;
        func_L01_0050FB40(6, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4E00[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x40:
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CF4B0(0x4e, 1); return 0; }
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.i[0x974] == 0x3) D_001A4BE0.u[0x6d] = 0;
        if (D_001A4BE0.i[0x975] == 0x0) D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x160));
        D_001A4BE0.b[0x3ec] = 0; D_001A4BE0.b[0x3ef] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x19, 0, 7.0f); goto finish;
    case 0x43:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.i[0xa14] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(5, 2, 3.0f); goto finish;
    case 0x46:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.f[0x14b] = 0.0048f; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x22];
        if (D_001A4BE0.i[0x975] == 0x4) { D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c]; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x118]; }
        if (!animate) goto finish;
        func_L01_0050FB40(8, 14, 6.0f); goto finish;
    case 0x47:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(10, 0, 5.0f); goto finish;
    case 0x49:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, 5.0f); goto finish;
    case 0x4a:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050FB40(12, 0, 5.0f); goto finish;
    case 0x9d: {
        s32 a = 0x21, b = 0x13, m = 0;
        D_001A4BE0.i[0x973] = 6; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x6e] = 0;
        if (func_L01_00500240(0x9d, 8)) {
            if (D_001A4BE0.h[0x5ee] == 0) { a = 0x22; b = 9; m = 1; }
            else if (D_001A4BE0.h[0x5ee] == 1) { a = 0x23; b = 5; m = 2; }
        }
        D_001A4BE0.h[0x5ee] = m;
        func_L01_004606A8(0);
        if (animate) func_L01_0050FB40(a, b, 2);
        goto finish; }
    case 0xab:
        D_001A4BE0.i[0x973] = 0x24; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x37, 0, 7.0f); goto finish;
    case 0xad: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0.i[0x973] = 0x1a; D_001A4BE0.i[0x1a8] = 0; D_001A4BE0.i[0x1ae] = 0;
        start = D_001A4BE0.f[0x1a6]; count = D_001A4BE0.i[0x1a5]; value = start;
        func_L01_00476498(D_001A4BE0.i[0x1a4], pos, &count, &value, D_001A4BE0.i[0x1ab], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0.b + 0x80);
        if (func_0038CEA8(dir) > 0.001f) {
            func_0038CF68(dir, dir, 1.0f);
            D_001A4BE0.f[0x1a9] = func_0038CE68((D_001A4BE0.b + 0x110), dir);
        }
        D_001A4BE0.f[0x1a9] = D_001A4BE0.f[0x1a9] * 0.7f;
        if (D_001A4BE0.f[0x1a9] < 0.0f) D_001A4BE0.f[0x1a9] = 0.0f;
        func_L01_0050FB40(0x45, 4, 4.0f); D_001A4BE0.f[0x300] = 0.7f;
        goto finish; }
    case 0xa8:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.f[0x14b] = 0.0228f; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x975] == 4) D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c];
        D_001A4BE0.h[0xd95] = 8; D_001A4BE0.i[0x6cb] = D_001A4BE0.h[0xd94];
        if (animate) func_L01_0050FB40(0x34, 8, 3.0f);
        goto finish;
    case 0xa9:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.i[0x6cb] = D_001A4BE0.h[0xd94]; D_001A4BE0.h[0xd95] = 8; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x33, 0, 4.0f); goto finish;
    case 0xa3:
        D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x973] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x10, 0, -4.0f); goto finish;
    case 0x9e:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.0f); func_L01_003F1F20(18, 0);
        hit_45 = func_L01_00447490(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_45) func_L01_004DFEA0((s32)(*(f32 *)(hit_45 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 0x53;
        if (!animate) goto finish;
        func_L01_0050FB40(0x27, 2, 4.0f); goto finish;
    case 0x9a:
        D_001A4BE0.uh[0x104] = 0x3a; D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(func_L30_004E6DC8(1), 0, 7.0f); goto finish;
    case 0x9b:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        D_001A4BE0.i[0x6e] = 0;
        animation_16 = func_L30_004E6DC8(7);
        if (func_L01_00500240(0xa2, 6)) func_L01_0050FB40(animation_16, 0, -4.0f);
        else func_L01_0050FB40(animation_16, 0, 4.0f);
        goto finish;
    case 0xa6:
        D_001A4BE0.i[0x973] = 0x23; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        D_001A4BE0.uh[0xd91] = 0; D_001A4BE0.uh[0xd90] = 0;
        func_L01_004606A8(0);
        D_001A4BE0.i[0x4e] = 0; D_001A4BE0.i[0x3e] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x20, 0, 6.0f); goto finish;
    case 0x9c: case 0xa1:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.f[0x280] = 0.0228f; D_001A4BE0.f[0x281] = 0.0028000001f; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.uh[0xd9f] = 0;
        if (D_001A4BE0.i[0x971] == 0xa1) func_L01_004F4E70(0x21, 0);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x2d, 0, 8.0f); goto finish;
    case 0x9f:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; func_L01_004F1190(0.0f);
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x28, 0, 6.0f); goto finish;
    case 0xa0:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; func_L01_004F1190(0.0f);
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x2d, 0, 6.0f); goto finish;
    case 0x51:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(1, 0, 12.0f); goto finish;
    case 0x59:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x12, 0, 6.0f); func_L01_0050FE88(12, 19); goto finish;
    case 0x57:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x15, 0, 10.0f); goto finish;
    case 0x58:
        D_001A4BE0.i[0x973] = 9; qzero(D_001A4BE0.b + 0xf0); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(1, 0, 6.0f); goto finish;
    case 0x53:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.f[0x280] = 0.0088f; D_001A4BE0.f[0x281] = 0.0028000001f;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050FB40(0x15, 0, 6.0f); goto finish;
    case 0x52:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_0038CED8((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.f[0x6d] > 0.10000001f) D_001A4BE0.f[0x6d] = 0.10000001f;
        D_001A4BE0.b[0x3ec] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(5, 0, 7.0f); goto finish;
    case 0x56:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050FB40(0x14, 0, 10.0f); goto finish;
    case 0x55:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1190(0.5f);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003C4BB0((f32 *)(D_001A4BE0.b + 0xf0), 0.10000001f);
        hit_29 = func_L01_00447490(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_29) func_L01_004DFEA0((s32)(*(f32 *)(hit_29 + 0x2C)));
        else func_L01_004DFEA0(1);
        D_001A4BE0.uh[0xee] = 64;
        if (!animate) goto finish;
        func_L01_0050FB40(0x13, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4E00[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x3e:
        D_001A4BE0.i[0x973] = 15; D_001A4BE0.u[0xa03] = 0;
        if (!D_001A4BE0.i[0x178]) {
            if (D_001A4BE0.ptr[0x199]) { func_L01_004DFEA0((s32)(*(f32 *)(D_001A4BE0.ptr[0x199] + 0x2C))); D_001A4BE0.ptr[0x199] = 0; }
            else func_L01_004DFEA0(1);
        }
        func_L01_004F4E70(20, 0);
        if (D_001A4BE0.i[0xa14] < 1) {
            angle_53 = func_0038DAB8(func_0038D160(D_001A4BE0.f[0x3c], D_001A4BE0.f[0x3d]), 3.1415927f);
            angle_53 = func_0038DAB8(angle_53, func_L01_00443A18(0.5235988f, 0.61086524f));
            D_001A4BE0.f[0x48] = func_0038D098(angle_53) * (D_001A4BE0.f[0x179] * 0.7f);
            D_001A4BE0.f[0x49] = func_0038D0B0(angle_53) * (D_001A4BE0.f[0x179] * 0.7f); D_001A4BE0.f[0x4a] = 0.09f;
            if (D_001A4BE0.i[0x178] > 12 && D_001A4BE0.i[0xa14] < 2) D_001A4BE0.i[0xa14] = 2;
            D_001A4BE0.ptr[0x970][0xA8] = 255; func_L30_004CF4B0(0x16, 1); D_001A4BE0.uh[0xfa] = 0x7d; D_001A4BE0.uh[0xe8] = 0x3a;
            return 0;
        }
        D_001A4BE0.uh[0xee] = 64; D_001A4BE0.f[0x18f] = 0.050000004f;
        if (D_001A4BE0.f[0x188] > 0.050000004f) D_001A4BE0.f[0x188] = 0.050000004f;
        qzero(D_001A4BE0.b + 0xf0); D_001A4BE0.u[0x185] = 0; qzero(D_001A4BE0.b + 0x110);
        D_001A4BE0.f[0x3e] = 0.22000001f; D_001A4BE0.f[0x4a] = 0.22000001f;
        if (!animate) goto finish;
        func_L01_0050FB40(0x10, 2, -3.0f); goto finish;
    case 0x1c:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        func_L01_0050FB40(func_L30_004AD910(0), 0, 8.0f); goto finish;
    case 0x1d:
        D_001A4BE0.u[0xa03] = 0x51; D_001A4BE0.i[0x973] = 0;
        if (func_L01_004DFE80(D_001A4BE0.ptr[0x970][0x42]) == func_L30_004AD910(0)) goto finish;
        func_L01_0050FB40(func_L30_004AD910(0), 0, 4.0f); goto finish;
    case 0x1e:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0;
        func_L01_0050FB40(func_L30_004AD910(0), 0, 8.0f); goto finish;
    case 0x74:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        func_L01_004EAA80();
        if (!animate) goto finish;
        func_L01_0050FB40(func_L30_004AD910(0), 0, 8.0f); goto finish;
    case 0x31:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.b[0x25e8] = 1;
        D_001A4BE0.b[0x25ee] = 1; D_001A4BE0.b[0x25ed] = 1; func_L01_0044E740((void *)(D_001A4BE0.b + 0x1ce0));
        if (!animate) goto finish;
        func_L01_0050FB40(func_L30_004AD910(0), 0, -1.0f); goto finish;
    case 0x7a:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x25ed] = 1; qzero(D_001A4BE0.b + 0xf0);
        if (!animate) goto finish;
        func_L01_0050FB40(11, 0, -1.0f); goto finish;
    case 0x37:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x25ed] = 1;
        func_L01_0050FB40(0x3f, 2, 7.0f);
        { u8 *a = D_001A4BE0.ptr[0x480]; if (func_L01_004EDFA8(a)) func_003C3A10(a, 11, 2, 11); }
        goto finish;
    case 0x64: case 0x65:
        D_001A4BE0.i[0x973] = 24; D_001A4BE0.b[0x25ed] = 1;
        func_L01_0044E740((void *)(D_001A4BE0.b + 0x1ce0)); func_L01_004EAA80();
        if (animate) func_L01_0050FB40(func_L30_004AD910(0), 0, -1.0f);
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
        (D_001A4BE0.f[0xd4] < D_L30_001E22C0.f8 || D_001A4BE0.i[0x973] == 0)) D_L30_001E22C0.i450 = 0;
    if (D_001A4BE0.i[0x973] != D_001A4BE0.i[0x975]) func_L01_004E1560();
    D_001A4BE0.i[0x6e] = 0;
    D_001A4BE0.u[0x70] = 0;
    if (D_001A4BE0.i[0x973] != D_001A4BE0.i[0x975]) D_001A4BE0.u[0x6f] = 0;
    D_001A4BE0.u[0x71] = 0;
    return 1;
}
