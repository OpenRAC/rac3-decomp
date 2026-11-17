#include "common.h"

/* NTSC-U counterpart of func_L30_004CF4B0 (src/levels/shared/L30_004CF4B0.c) */
/* localdecomp:start func_L30_004CB6E0 */
/* func_L30_004CB6E0: hero state entry, the vidcomic levels' copy (L30-L36, 7 places) (family C, docs/prep/FAMILIES.md; root
   func_L08_004DD0C0, src/levels/08_aquatos/L08_004DD0C0.c). Opus family C, 2026-11-08: the root's C with
   this level's data, callee names and jump-table order, corrected case by case against retail.
   Build needs, as the root: "-mvu0-use-vf0-vf2 ... @ps2as" on this file, its config/levels/divs_nops.txt
   row, include/vu0.h (vec_add_ab, qzero, fabs_asm) and the two .data core externs (docs/GLOBALS.md).
   The root's last fixes carry over (func_L01_004E5630 takes one argument; the 7-group's parameter-block
   order; the head's zero stores before f[0x135]; 0x11's 7.0 limit as a local).
   Corrected from retail: state 1's animation in a fresh local, 0xA7's f[0x135] = f[0x13c] = 0.028
   chain, 0xA2's f[0x128] = f[0x127] chain, 0x9D's switch on h[0x5EE] with its frame count an int (n = 2),
   and the store orders of 0x9D, 0xA3 and the 0x3E/0x4E clear.
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
extern s32 func_0039FE80(s32, s32, u8 *);
extern void func_00388440(unsigned int *, unsigned int, int);
extern u8 D_L30_001DBD08[8];
extern u8 D_L30_001DBD28[8];
extern s32 D_L30_002F4C30[][11];
extern s32 D_L30_001D6740_004CB6E0;
extern f32 D_L30_001DBBE8;
extern f32 D_L30_001DBBEC;
extern f32 D_L30_002F4DC0[][25];
extern s32 D_L30_002F4C30[][11];
extern void func_L01_00472C40(s32, f32 *, s32 *, f32 *, s32, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_L01_00440918(f32, f32);
extern void *func_L01_00444358(void *, u32, s32);
extern void func_003BF640(float *, float);
extern s32 func_L01_004DC1A0(s32);
extern void func_L01_004E29F8(void);
extern u32 func_L01_004E5438(s32);
extern s32 func_L01_004E5540(void);
extern f32 func_L01_004E5630(s32);
extern void func_L01_004E6CB0(void);
extern s32 func_L01_004EA1D8(u8 *);
extern void func_L01_004ED3B8(f32);
extern void func_L01_004E9828(void);
extern void func_L01_004F10F0(void);
extern void func_L01_00510000(void);
extern f32 func_L01_004F1018(void *, int);
extern int func_L01_004F1068(int, int);
extern int func_L01_004FB758(void);
extern void func_L01_0050BEE0(s32, s32);
extern f32 func_L01_0050D430(char *);
extern void func_L01_0050D530(V4_F6a70b950 *, V4_F6a70b950 *, float);
extern int func_L01_003EFFE0(unsigned int, int);
extern void func_L01_004E3EC0(void);
extern void func_L01_0044B090(void *, char *);
extern void func_L01_0044B0B8(List_F66766f2b *, int, int, float);
extern void func_L01_0044B4B8(void *);
extern void func_L30_004D0840(int);
extern void func_003886E8(void *, void *, f32);
extern f32 func_003887A0(void *);
extern f32 func_003887C8(void *, void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00389468(f32, f32);
extern void func_003BE4F0(void *, int, int, int);
/* These calls use side effects only; their original scalar return contracts remain unqualified. */
extern void func_L01_004C2BF8(void *, s32, u32, f32, f32, f32, f32);
extern void func_L01_004DC1C0(int);
extern void func_L01_004DD4B0(int, int, int, int);
extern void func_L01_004DD850(void);
extern void func_L01_004E20F0(int, int, int);
extern void func_L01_004E6868(int, int);
extern void func_L30_004B8E30(int, f32);
extern void func_L01_004EEA78(f32, f32, f32);
extern s32 func_L01_0050DA08(s32);
extern int func_L01_00503310(void);
extern void func_L01_0050BB98(int, int, f32);
extern s32 func_L30_004A9D20(int);
extern s32 D_001D4C38;
extern u8 *D_L30_001E0790_004CB6E0;
extern s32 D_L30_001E0798_004CB6E0;
extern u32 D_001D545C;
typedef struct { u16 count; u16 pad; u32 maximum; u32 levels; } Statistics;
extern Statistics D_001A7C10[];
extern s32 D_L30_001DBD00[2];
extern f32 D_L30_002F4DC0[][25];
typedef struct { u8 pad0[8]; f32 f8; u8 padC[0x450 - 0xC]; s32 i450; } L19State_1B9900;
extern s32 func_L01_004FC400(s32, s32);
extern void func_L01_004FC2D0(void);
extern void func_L01_003F0020(s32);
extern L19State_1B9900 D_L30_001E22C0_004CB6E0;



/* All resident fields below are views of the single player-state object. */
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero;
extern Hero D_001A4BE0;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
extern f32 D_L30_001DBBB0, D_L30_001DBBB4, D_L30_001DBBB8, D_L30_001DBBE8, D_L30_001DBBEC;
__asm__(".extern D_L30_001DBBB0, 4");
__asm__(".extern D_L30_001DBBB4, 4");
__asm__(".extern D_L30_001DBBB8, 4");
__asm__(".extern D_L30_001DBBE8, 4");
__asm__(".extern D_L30_001DBBEC, 4");
extern u8 D_L30_001DBD08[8];
__asm__(".extern D_L30_001DBD08, 8");
extern u8 D_L30_001DBD28[8];
__asm__(".extern D_L30_001DBD28, 8");
extern s32 D_L30_001D6740_004CB6E0;
__asm__(".extern D_L30_001D6740_004CB6E0, 4");
extern u8 D_001439F4 __attribute__((section(".data")));
extern s32 D_00143950 __attribute__((section(".data")));
extern u8 D_001D545C_b[] __attribute__((section(".sdata")));
extern void func_L01_0045D318(s32);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern s32 D_L30_001DDAA4_004CB6E0;
extern void func_L01_0050D8F8(s32, s32);
extern void func_L01_004F1CE0(void);
extern void func_L01_004F1A08(void);
extern void func_L01_00441E00(u8 *, s32, s32, s32, s32);
extern s32 func_L01_004FC388(s32, s32);
extern u8 D_00142660[];
extern s32 func_L30_004E2EC8(s32);
extern s32 D_L30_001DBD00[2];
__asm__(".extern D_L30_001DBD00, 8");
extern s32 func_L01_004DC080(void);
extern void func_L01_00410840(void *, V4 *, f32, u8 *, f32);
extern void func_L01_004109B0(void *, V4 *, f32, f32);


/* Changes the player's action, initializes its movement parameters and selects animation. */
s32 func_L30_004CB6E0(s32 action, s32 animate) {
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
    if (!func_L01_004FC400(action, animate)) return 0;
    objectSnapshot = D_001A4BE0.ptr[0x970];
    func_L01_004FC2D0();
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
        func_L01_0044B4B8((void *)(D_001A4BE0.b + 0x1b90));
    }
    if (D_001A4BE0.h[0xfd] == 0) func_L01_003F0020(0);
    if (D_001A4BE0.b[0x25e4] == 3 && (u32)(D_001A4BE0.i[0x971] - 0x51) >= 9 && (u32)(D_001A4BE0.i[0x971] - 0x66) >= 4 &&
        D_001A4BE0.i[0x971] != 0 && D_001A4BE0.i[0x971] != 1) { func_L01_004E3EC0(); D_001A4BE0.i[0x971] = action; }
    func_L01_004E6868(D_001A4BE0.i[0x974], D_001A4BE0.i[0x971]);
    D_001A4BE0.i[0x45a] = 0;
    switch (action) {
    case 0xaf:
        D_001A4BE0.b[0x25e4] = 0;
        goto finish;
    case 0x0:
        D_001A4BE0.i[0x973] = 0;
        D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x48a] == 0x27) func_L01_004E6CB0();
        D_001A4BE0.b[0x2877] = 0;
        D_001A4BE0.i[0x460] = func_0037E208(0x32, 0x64);
        func_L01_004E29F8();
        if (D_001A4BE0.b[0x25e4]) { func_L30_004D0840(0); return 1; }
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.b[0x1474] && func_003887A0(D_001A4BE0.b + 0x160) > 0.008333334f) { func_L30_004CB6E0(0x2e, 1); return 0; }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CB6E0(0x7b, 1); return 0; }
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L30_004A9D20(0) == 0x4a) func_L01_0050BB98(func_L30_004A9D20(0), 0, 18.0f); else func_L01_0050BB98(func_L30_004A9D20(0), 0, -1.0f);
        goto finish;
    case 0x68:
        D_001A4BE0.i[0x973] = 0;
        qzero(D_001A4BE0.b + 0x160);
        D_001A4BE0.u[0xa03] = 0;
        func_L01_004ED3B8(0.0f);
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        if (func_L30_004A9D20(0) == 0x4a) func_L01_0050BB98(func_L30_004A9D20(0), 0, 18.0f); else func_L01_0050BB98(func_L30_004A9D20(0), 0, -1.0f);
        goto finish;
    case 0x3d:
        func_L01_0050BB98(func_L30_004A9D20(0), 0, 9.0f);
        if (D_001A4BE0.ptr[0x681]) func_003BE4F0(D_001A4BE0.ptr[0x681], 0, 0, 9);
        goto finish;
    case 0x39:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x40, 0, 12.0f); goto finish;
    case 0x82:
        func_L01_004E3EC0();
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0xa14] = 0; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        func_003BF640((f32 *)(D_001A4BE0.b + 0x160), 0.058333337f);
        if (!animate) goto finish;
        func_L01_0050BB98(0x63, 0, 12.0f); goto finish;
    case 0xb1:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004E9828();
        func_L01_004F10F0();
        if (!animate) goto finish;
        func_L01_0050BB98(0x63, 0, 12.0f); goto finish;
    case 0x81:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x1cb] = D_001A4BE0.f[0xd4] - 0.37f; D_001A4BE0.i[0xa14] = 0;
        D_001A4BE0.f[0x1c9] = D_001A4BE0.f[0x46] * 0.2f;
        if (D_001A4BE0.f[0x1c9] < -0.116666675f) D_001A4BE0.f[0x1c9] = -0.116666675f;
        D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.f[0x1c8] = D_001A4BE0.f[0x22] - D_001A4BE0.f[0x1cb]; D_001A4BE0.u[0x1cc] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x5b, 0, 11.0f); goto finish;
    case 0x50:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.uh[0xf8] = 10000; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x1cb] = D_001A4BE0.f[0xd4] - 0.15f; D_001A4BE0.i[0xa14] = 0;
        D_001A4BE0.f[0x1c9] = D_001A4BE0.f[0x46] * 0.2f;
        if (D_001A4BE0.f[0x1c9] < -0.116666675f) D_001A4BE0.f[0x1c9] = -0.116666675f;
        D_001A4BE0.u[0x1cc] = 0; D_001A4BE0.f[0x1c8] = D_001A4BE0.f[0x22] - D_001A4BE0.f[0x1cb];
        if (!animate) goto finish;
        func_L01_0050BB98(0x23, 0, 11.0f); goto finish;
    case 0x32: {
        s32 n;
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0x26f] = 0;
        if (D_001A4BE0.i[0x975] == 0x12) { func_L01_004F1068(3, 0); D_001A4BE0.i[0x972] = 1; }
        else D_001A4BE0.i[0x26d] = 45;
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0x268] = 0;
        n = 12;
        if (!animate) goto finish;
        func_L01_0050BB98(0x36, 0, n); goto finish; }
    case 0x34: {
        s32 f;
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x26d] = 60;
        if (D_001A4BE0.i[0x975] == 0x12) { func_L01_004F1068(3, 0); D_001A4BE0.i[0x972] = 1; }
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0x268] = 0;
        f = D_001A4BE0.i[0x974] == 0x32 ? 15 : 11;
        if (animate) func_L01_0050BB98(0x38, 0, f);
        goto finish;
    }
    case 0x33:
        D_001A4BE0.i[0x973] = 17; D_001A4BE0.u[0xa03] = 11; D_001A4BE0.b[0x25e8] = 1;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.i[0x45a] = 0x68;
        selected_8 = D_001A4BE0.i[0x974] == 0x34 ? -2 : 35;
        if (!animate) goto finish;
        func_L01_0050BB98(0x37, 0, (f32)selected_8); goto finish;
    case 0x36:
        D_001A4BE0.i[0x973] = 18; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.uh[0x4e5] = 0;
        if (D_001A4BE0.i[0x975] == 0x11) {
            func_L01_004E20F0(3, 10, 0);
            if (D_L30_001E0790_004CB6E0) func_L01_004C2BF8(D_L30_001E0790_004CB6E0, D_L30_001E0798_004CB6E0, 0, D_001A4BE0.f[0x20], D_001A4BE0.f[0x21], 0.4f, 0.3f);
        } else if (D_001A4BE0.f[0x46] < -0.008333334f) {
            selected_9 = (s32)(fabs_asm(D_001A4BE0.f[0x46]) * 300.0f);
            if (selected_9 > 40) selected_9 = 40;
            func_L01_004E20F0(3, selected_9, 1);
            if (D_L30_001E0790_004CB6E0) func_L01_004C2BF8(D_L30_001E0790_004CB6E0, D_L30_001E0798_004CB6E0, 0, D_001A4BE0.f[0x20], D_001A4BE0.f[0x21], 0.5f, -0.4f);
            D_001A4BE0.uh[0x4e5] = 75;
        }
        D_001A4BE0.f[0x1c9] = D_001A4BE0.f[0x46] * 0.37f; D_001A4BE0.i[0x1ca] = 0;
        if (D_001A4BE0.f[0x1c9] < -0.116666675f) D_001A4BE0.f[0x1c9] = -0.116666675f;
        D_001A4BE0.f[0x1cb] = D_001A4BE0.f[0xd4]; D_001A4BE0.u[0x1cc] = 0;
        D_001A4BE0.f[0x1c8] = (D_001A4BE0.f[0x22] - D_001A4BE0.f[0xd4]) - -0.12f;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.f[0x5a] = 0;
        func_003BF640((f32 *)(D_001A4BE0.b + 0x160), 0.09166667f);
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050BB98(0x35, 0, 22.0f); goto finish;
    case 0x77: case 0x78:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004ED3B8(0.5f); D_001A4BE0.b[0x25e8] = 1; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        hit_10 = func_L01_00444358(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_10) func_L01_004DC1C0((s32)(*(f32 *)(hit_10 + 0x2C)));
        else func_L01_004DC1C0(1);
        D_001A4BE0.uh[0xee] = 77;
        if (animate) {
            if (D_001A4BE0.i[0x971] == 0x77) func_L01_0050BB98(0x57, 3, -3.0f);
            else func_L01_0050BB98(0x56, 3, -3.0f);
            *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4DC0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
            goto finish;
        }
        goto finish;
    case 0x35:
        D_001A4BE0.i[0x973] = 18; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.u[0x26f] = 0;
        D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x1ca] = 45; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050BB98(0x52, 0, 17.0f); goto finish;
    case 0x6c:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.h[0x4e7] > 50 && D_001A7C10[12].count < 0xFFFF) D_001A7C10[12].count++;
        if (D_001A7C10[12].maximum < D_001D4C38) D_001A7C10[12].maximum = D_001D4C38;
        D_001A7C10[12].levels = (D_001A7C10[12].levels | (1u << D_001D545C)) | 0x80000000u;
        if (D_001A4BE0.i[0x274] > 2 && D_001A7C10[29].count < 0xFFFF) D_001A7C10[29].count++;
        if (D_001A7C10[29].maximum < D_001D4C38) D_001A7C10[29].maximum = D_001D4C38;
        D_001A7C10[29].levels = (D_001A7C10[29].levels | (1u << D_001D545C)) | 0x80000000u;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050BB98(0x4f, 0, 1e+01f); goto finish;
    case 0x84:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x64, 0, 1e+01f); goto finish;
    case 0x1:
        D_001A4BE0.u[0xa03] = 4;
        D_001A4BE0.i[0x973] = 0;
        if (D_001A4BE0.b[0x25e4]) {
            func_00388830(dir, D_001A4BE0.b + 0x20, D_001A4BE0.f[0x5b3]);
            vec_add_ab(dir, dir, D_001A4BE0.b + 0x80);
            func_L01_00410840(D_001A4BE0.b + 0x1540, (V4 *)dir, D_001A4BE0.f[0x26], D_001A4BE0.ptr[0x970], 0.0f);
            func_L01_004109B0(D_001A4BE0.b + 0x1540, (V4 *)dir, D_001A4BE0.f[0x26], 0.0f);
            func_L01_00510000();
        }
        if (D_001A4BE0.b[0x25eb]) goto finish;
        {
            u32 animation = func_L30_004A9D20(1);
            if (D_001A4BE0.ptr[0x970][0x43] == animation || !animate) goto finish;
            func_L01_0050BB98(animation, 0, 18.0f); goto finish;
        }
    case 0x2f:
        D_001A4BE0.i[0x973] = 8; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x110)); D_001A4BE0.u[0xa03] = 0;
        func_L01_0050BB98(func_L30_004A9D20(0), 0, 5.0f); D_001A4BE0.uh[0xf6] = 7;
        goto finish;
    case 0x2: case 0x2e: case 0x75:
        D_001A4BE0.i[0x973] = 1;
        D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x975] != 0x4 && D_001A4BE0.i[0x978] != 0x4) D_001A4BE0.f[0x6d] = func_L01_0050D430((char *)(D_001A4BE0.b + 0x120));
        (*(u128_t *)(D_001A4BE0.b + 0x3d0) = *(u128_t *)(D_001A4BE0.b + 0x0));
        D_001A4BE0.u[0xfc] = 0;
        D_001A4BE0.f[0xfa] = D_001A4BE0.f[0x26];
        if (D_001A4BE0.f[0x6d] > 0.116666675f) D_001A4BE0.f[0x6d] = 0.116666675f;
        D_001A4BE0.b[0x3ef] = 0;
        func_L30_004B8E30(0, 1.0f);
        value_18 = func_00389468(D_001A4BE0.f[0x26], D_001A4BE0.f[0x68]);
        if (value_18 > 1.5707964f &&
            (D_001A4BE0.i[0x975] == 0x4 || D_001A4BE0.i[0x974] == 0x3 || D_001A4BE0.i[0x977] == 0x3)) D_001A4BE0.f[0x6d] = 0;
        D_001A4BE0.i[0x45a] = 0x68;
        if (D_001A4BE0.b[0x147c]) {
            if (D_001A4BE0.h[0x1b6] == 0 || D_001A4BE0.f[0xcf] < 0.3f) { func_L30_004CB6E0(0x7b, 1); return 0; }
        }
        if (D_001A4BE0.b[0x1474] || D_001A4BE0.i[0x971] == 0x2e) {
            if (D_001A4BE0.f[0x6d] > 0.12833333f) D_001A4BE0.f[0x6d] = 0.12833333f;
            D_001A4BE0.u[0x3e] = 0;
            func_003BF640((f32 *)(D_001A4BE0.b + 0xf0), 0.12833333f);
            D_001A4BE0.i[0x971] = 0x2e; D_001A4BE0.u[0xf9] = 0;
            if ((D_001A4BE0.h[0xa1a] || (D_001A4BE0.i[0x5ac] == 1 && func_L01_0045D358(0x28, 2, 0, 0))) && D_001A4BE0.b[0x1436]) func_L01_0050BB98(0x7b, 0, 8.0f);
            else func_L01_0050BB98(0x32, 0, 8.0f);
            goto finish;
        }
        if (D_001A4BE0.b[0x25ea] || D_001A4BE0.i[0x971] == 0x75) {
            D_001A4BE0.i[0x971] = 0x75;
            func_L01_0050BB98(!*(s32 *)(*(u8 **)(D_001A4BE0.ptr[0x970] + 0x24) + 0x188) ? 3 : 0x50, 0, 8.0f); goto finish;
        }
        D_001A4BE0.i[0x972] = 0;
        D_001A4BE0.b[0x3ec] = 0; D_001A4BE0.b[0x3ee] = 0;
        if (!animate) goto finish;
        selected_18 = 8;
        if (func_L01_004DC080()) selected_18 = 12;
        if (D_001A4BE0.i[0x977] == 0x22 || D_001A4BE0.i[0x974] == 0x22) selected_18 = 15;
        if (D_001A4BE0.i[0x977] == 0x88 || D_001A4BE0.i[0x974] == 0x88) selected_18 = 15;
        if (D_001A4BE0.i[0x974] == 0x13) selected_18 = 13;
        if (D_001A4BE0.i[0x977] == 0x6 || D_001A4BE0.i[0x977] == 0x2c) selected_18 = 18;
        if (D_001A4BE0.i[0x978] == 0x4 && D_001A4BE0.b[0x46c] > 5) selected_18 = 13;
        func_L01_0050BB98(D_001A4BE0.i[0x972] + 3, D_L30_001DBD00[D_001A4BE0.i[0x972]], (f32)selected_18); goto finish;
    case 0x80: {
        s32 n;
        D_001A4BE0.i[0x973] = 28; D_001A4BE0.i[0x45a] = 0x68; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110)); D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.i[0x261] = 0;
        if (D_001A4BE0.i[0x49e] != 0x1d) { D_001A4BE0.i[0x98d] = D_001A4BE0.i[0x49e]; D_001A4BE0.i[0x97f] = 0x1d; }
        n = -2;
        if (!animate) goto finish;
        func_L01_0050BB98(0x69, 0, n); goto finish; }
    case 0x66:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.f[0x6d] = func_003887A0((D_001A4BE0.b + 0x120));
        D_001A4BE0.b[0x25ed] = 1;
        if (!D_001A4BE0.b[0x25e4]) func_L01_004E6CB0();
        if (!animate) goto finish;
        if (D_001A4BE0.b[0x25e4] == 3) { func_L01_0050BB98(5, 0, 8.0f); goto finish; }
        if (D_001A4BE0.b[0x25e4] == 1) { func_L01_0050BB98(0x19, 0, 8.0f); goto finish; }
        if (D_001A4BE0.b[0x25e4] != 0) goto finish;
        func_L01_0050BB98(D_001A4BE0.i[0x972] + 3, D_L30_001DBD00[D_001A4BE0.i[0x972]], 8.0f); goto finish;
    case 0x30:
        D_001A4BE0.i[0x973] = 16; D_001A4BE0.u[0xa03] = 3; D_001A4BE0.b[0x25e8] = 1;
        func_00388440((unsigned int *)(D_001A4BE0.b + 0xb20), 0, 0x20);
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050BB98(0x51, 0, 15.0f); goto finish;
    case 0x3:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.b[0x1474]) { func_L30_004CB6E0(0x2e, 1); return 0; }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CB6E0(0x7b, 1); return 0; }
        if (func_L01_00503310()) return 0;
        if (func_L30_004A9D20(0) == 0x4a) {
            if (!animate) goto finish;
            if (func_L30_004CB6E0(0x0, 0)) func_L01_0050BB98(func_L30_004A9D20(0), 0, 18.0f);
            return 0;
        }
        if (!animate) goto finish;
        animation_21 = objectSnapshot[0x42];
        {
            value_21 = D_001A4BE0.f[0x306]; selected_21 = 6;
            if (func_L01_004DC1A0(animation_21) == 4 && value_21 > 3.0f && value_21 < 16.0f) selected_21 = 5;
            func_L01_0050BB98(selected_21, 4, 9.0f);
            goto finish;
        }
    case 0x67:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_L01_0050D430((char *)(D_001A4BE0.b + 0x120)); (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        animation_22 = objectSnapshot[0x42]; {
            value_22 = D_001A4BE0.f[0x306]; selected_22 = 6;
            if (func_L01_004DC1A0(animation_22) == 4 && value_22 > 3.0f && value_22 < 16.0f) selected_22 = 5;
            func_L01_0050BB98(selected_22, 4, 9.0f);
            goto finish;
        }
    case 0x4:
        D_001A4BE0.i[0x973] = 12; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_003887A0((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.f[0x6d] > 0.116666675f) D_001A4BE0.f[0x6d] = 0.116666675f;
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CB6E0(0x7b, 1); return 0; }
        D_001A4BE0.i[0x45a] = 0x68;
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        func_003BF640((float *)(D_001A4BE0.b + 0x160), 0.116666675f);
        if (D_001A4BE0.f[0x5e] > 0.058333337f) func_L01_004F1068(9, 0);
        if (animate) {
            if (D_001A4BE0.ptr[0x970][0x42] == func_L30_004A9D20(0)) func_L01_0050BB98(13, 2, 9.0f);
            else func_L01_0050BB98(13, 2, 14.0f);
            func_L01_0050BEE0(3, 18);
        }
        goto finish;
    case 0x8f:
        D_001A4BE0.i[0x973] = 33; D_001A4BE0.u[0xa03] = 0;
        
        D_001A4BE0.f[0x68] = func_00388A28(*(f32 *)(D_001A4BE0.ptr[0x2a4] + 0x10) - D_001A4BE0.f[0x20],
                                    *(f32 *)(D_001A4BE0.ptr[0x2a4] + 0x14) - D_001A4BE0.f[0x21]);
        D_001A4BE0.u[0x2a7] = 0; { if (animate) { func_L01_0050BB98(0x2a, 2, 5.0f); func_L01_0050BEE0(10, 14); } goto finish; }
    case 0x90:
        D_001A4BE0.i[0x973] = 33; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        goto finish;
    case 0x23:
        D_001A4BE0.i[0x973] = 13; D_001A4BE0.u[0xa03] = 7;
        
        D_001A4BE0.f[0x68] = func_00388A28(*(f32 *)(D_001A4BE0.ptr[0x289] + 0x10) - D_001A4BE0.f[0x20],
                                    *(f32 *)(D_001A4BE0.ptr[0x289] + 0x14) - D_001A4BE0.f[0x21]);
        if (D_001A4BE0.i[0x974] == 0x28) (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0xf0));
        { if (animate) { func_L01_0050BB98(0x2a, 2, 5.0f); func_L01_0050BEE0(10, 14); } goto finish; }
    case 0x24:
        D_001A4BE0.i[0x973] = 13;
        D_001A4BE0.u[0xa03] = 7;
        D_001A4BE0.i[0x288] = 0;
        D_001A4BE0.i[0x28d] = 0;
        D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050BB98(0x2b, 0, 10.0f); goto finish;
    case 0x25:
        D_001A4BE0.i[0x973] = 13; D_001A4BE0.u[0xa03] = 7; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.i[0x288] = 0; D_001A4BE0.i[0x28d] = 0;
        D_001A4BE0.f[0x28f] = func_003887C8(D_001A4BE0.b + 0x80, D_001A4BE0.ptr[0x289] + 0x10);
        if (!animate) goto finish;
        func_L01_0050BB98(0x2b, 1, 5.0f); goto finish;
    case 0x2b: {
        u8 *p = D_001A4BE0.ptr[0x294], *q; f32 t;
        D_001A4BE0.u[0x29a] = 0; D_001A4BE0.i[0x973] = 14; D_001A4BE0.u[0xa03] = 7; D_001A4BE0.ptr[0x295] = p; D_001A4BE0.uh[0x52e] = 0;
        D_001A4BE0.uh[0x53e] = 0; D_001A4BE0.uh[0x53f] = 1; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0x29d] = 0; D_001A4BE0.u[0x29e] = 0;
        q = *(u8 **)(p + 0x68);
        D_001A4BE0.f[0x298] = *(f32 *)(q + 4);
        if (*(f32 *)(q + 0x10) == D_001A4BE0.f[0x29a]) *(f32 *)(q + 0x14) = *(f32 *)(q + 0xc); else *(f32 *)(q + 0x14) = *(f32 *)(q + 0x10);
        D_001A4BE0.f[0x2a1] = 0.025f; D_001A4BE0.f[0x2a2] = 0.33f; qzero(D_001A4BE0.b + 0xa0); D_001A4BE0.f[0x2a3] = 0.18333334f;
        D_001A4BE0.uh[0x103] = 0x28;
        if (*(f32 *)(q + 0x24) != 0.0f) D_001A4BE0.f[0x2a1] = *(f32 *)(q + 0x24);
        if (*(f32 *)(q + 0x28) != 0.0f) D_001A4BE0.f[0x2a2] = *(f32 *)(q + 0x28);
        if (*(f32 *)(q + 0x2c) != 0.0f) D_001A4BE0.f[0x2a3] = *(f32 *)(q + 0x2c);
        D_001A4BE0.f[0x29b] = func_00388A28(*(f32 *)(D_001A4BE0.ptr[0x295] + 0x10) - D_001A4BE0.f[0x20], *(f32 *)(D_001A4BE0.ptr[0x295] + 0x14) - D_001A4BE0.f[0x21]);
        D_001A4BE0.f[0x299] = func_003887C8(D_001A4BE0.b + 0x80, D_001A4BE0.ptr[0x295] + 0x10);
        D_001A4BE0.f[0x29c] = 0.0075000003f;
        if (D_001A4BE0.i[0x975] == 4) D_001A4BE0.f[0x29c] = D_001A4BE0.f[0x13c];
        else if (D_001A4BE0.i[0x975] == 2) D_001A4BE0.f[0x29c] = D_001A4BE0.f[0x280];
        if (!animate) goto finish;
        func_L01_0050BB98(0x2f, 0, 11.0f); D_001A4BE0.f[0x300] = 0.7f;
        goto finish; }
    case 0x2c:
        D_001A4BE0.i[0x973] = 2; qzero(D_001A4BE0.b + 0xa0); D_001A4BE0.u[0xa03] = 7; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050BB98(0xb, 0, 15.0f); goto finish;
    case 0x27: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0.i[0x973] = 15; D_001A4BE0.u[0xa03] = 3; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.i[0x17a] = 1; D_001A4BE0.f[0x17e] = -1.5707964f; D_001A4BE0.i[0x178] = 0; D_001A4BE0.i[0x19a] = 0; D_001A4BE0.i[0x17f] = 0;
        if (D_001A4BE0.i[0x975] != 0xf) { D_001A4BE0.i[0x185] = 0; D_001A4BE0.i[0x187] = -1; D_001A4BE0.f[0x188] = 0.0f; }
        start = D_001A4BE0.f[0x176]; D_001A4BE0.i[0x194] = 0; D_001A4BE0.i[0x195] = 0; D_001A4BE0.uh[0x32f] = 0; D_001A4BE0.i[0x189] = 0; D_001A4BE0.i[0x18a] = 0; D_001A4BE0.uh[0x316] = 0; D_001A4BE0.i[0x18c] = 0; count = D_001A4BE0.i[0x175]; value = start;
        func_L01_00472C40(D_001A4BE0.i[0x174], pos, &count, &value, D_001A4BE0.i[0x17d], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0.b + 0x80);
        if (func_00388770(dir) > 0.001f) {
            func_00388830(dir, dir, 1.0f);
            if (D_001A4BE0.i[0x975] != 0xf) D_001A4BE0.f[0x188] = func_00388730((D_001A4BE0.b + 0x110), dir);
        }
        if (D_001A4BE0.ptr[0x192]) {
            f32 toward = func_00388A28(*(f32 *)(D_001A4BE0.ptr[0x192] + 0x10) - D_001A4BE0.f[0x20], *(f32 *)(D_001A4BE0.ptr[0x192] + 0x14) - D_001A4BE0.f[0x21]);
            if (func_00389468(toward, func_00389380(D_001A4BE0.f[0x17e], func_00388A28(dir[0], dir[1]))) > 1.5707964f) {
                D_001A4BE0.f[0x17e] = 1.5707964f; D_001A4BE0.i[0x17f] = 1;
            }
        }
        if (!animate) goto finish;
        func_L01_0050BB98(D_001A4BE0.i[0x17f] + 0x2c, 0, 6.0f); goto finish; }
    case 0x76: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0.i[0x973] = 26; D_001A4BE0.u[0xa03] = 3; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.i[0x1a8] = 0; D_001A4BE0.i[0x1ae] = 0;
        start = D_001A4BE0.f[0x1a6]; count = D_001A4BE0.i[0x1a5]; value = start;
        func_L01_00472C40(D_001A4BE0.i[0x1a4], pos, &count, &value, D_001A4BE0.i[0x1ab], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0.b + 0x80);
        if (func_00388770(dir) > 0.001f) {
            func_00388830(dir, dir, 1.0f);
            D_001A4BE0.f[0x1a9] = func_00388730((D_001A4BE0.b + 0x110), dir);
        }
        D_001A4BE0.f[0x1a9] = D_001A4BE0.f[0x1a9] * 0.5f;
        if (D_001A4BE0.f[0x1a9] < 0.0f) D_001A4BE0.f[0x1a9] = 0.0f;
        func_L01_0050BB98(0x5a, 0, 8.0f); goto finish; }
    case 0x17:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.f[0x14b] = 0.0061111115f; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x22];
        if (D_001A4BE0.i[0x975] == 0x4) { D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c]; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x118]; }
        D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        if (D_001A4BE0.f[0x5d] > 0.058333337f) func_L01_0050BB98(0x20, 0, 9.0f);
        else func_L01_0050BB98(0x20, 1, 11.0f);
        goto finish;
    case 0x18:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050BB98(0x21, 0, 6.0f); goto finish;
    case 0x19:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050BB98(0x24, 0, 6.0f); goto finish;
    case 0x1a:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1;
        if (!animate) goto finish;
        func_L01_0050BB98(0x25, 0, 6.0f); goto finish;
    case 0x7b:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(11, 0, 12.0f); goto finish;
    case 0x6: case 0x79:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x971] == 0x79) D_001A4BE0.i[0x973] = 0x14;
        D_001A4BE0.f[0x280] = 0.0061111115f;
        D_001A4BE0.f[0x281] = 0.0019444445f;
        if (D_001A4BE0.i[0x971] == 0x79) {
            if (!D_001A4BE0.b[0x25e4]) D_001A4BE0.uh[0x142d] = func_L01_004F1068(14, 0x20);
            D_001A4BE0.f[0x284] = func_L01_00440918(0.052359883f, 0.072722055f);
            D_001A4BE0.f[0x285] = func_L01_00440918(0.052359883f, 0.072722055f);
        }
        D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.i[0x972] = 0;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        if (D_001A4BE0.b[0x25e4] == 1) { func_L01_0050BB98(4, 0, 8.0f); return 1; }
        if (D_001A4BE0.b[0x25e4] == 3) { func_L01_0050BB98(0x15, 0, 8.0f); return 1; }
        if (D_001A4BE0.f[0xcf] > 1.75f) { func_L01_0050BB98(11, 0, 12.0f); D_001A4BE0.i[0x972] = 1; goto finish; }
        func_L01_0050BB98(10, 0, 10.0f); goto finish;
    case 0xb0:
        D_001A4BE0.i[0x973] = 0x25; qzero(D_001A4BE0.b + 0xf0); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x7a, 0, 7.0f); goto finish;
    case 0x8: {
        s32 n = -2;
        D_001A4BE0.i[0x973] = 5; D_001A4BE0.i[0x45a] = 0x68; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.f[0x5c] > 0.075f) func_L01_004ED3B8(0.075f / D_001A4BE0.f[0x5c]);
        D_001A4BE0.i[0xa13] = 0; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050BB98(0x13, 0, n); goto finish; }
    case 0x7: case 0x9: case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11: case 0x12: case 0x1b: case 0x28: case 0x29: case 0x38: case 0x45: case 0x48: case 0x54: case 0x5f: case 0x69: case 0x6b: case 0x73: case 0x86: case 0xa2: case 0xa7: case 0xac:
        if (D_001A4BE0.i[0x971] != 0x86 && D_001A4BE0.ptr[0xd7] &&
            (*(s16 *)(D_001A4BE0.ptr[0xd7] + 0xAA) == 0x9B9 || *(s16 *)(D_001A4BE0.ptr[0xd7] + 0xAA) == 0xF05)) {
            func_L30_004CB6E0(0x86, 1); return 0;
        }
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x101] < 15) {
            if (D_001A4BE0.h[0x1b6] == 0 || D_001A4BE0.f[0xcf] < 1.0f) { func_L30_004CB6E0(0x7b, 1); return 0; }
        }
        if (D_001A4BE0.i[0x971] != 0x73 && D_001A4BE0.h[0x1b4] == 1 && action != 0xe &&
            action != 0x38 && !D_L30_001D6740_004CB6E0) { func_L30_004CB6E0(0x73, 1); return 0; }
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
            func_L01_004DD4B0(oldWeapon, 0, 0, 30);
            func_L01_004DD4B0(oldWeapon, 1, 0, 30);
        }
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (D_001A4BE0.i[0x971] != 0x12 && D_001A4BE0.b[0x1476] && D_001A4BE0.f[0x22] < D_001A4BE0.f[0xd4] + 0.5f)
            func_L01_004E20F0(3, 0x10, 0);
        if (D_001A4BE0.i[0x971] == 0x6b) func_L01_004F1068(8, 0);
        D_001A4BE0.f[0x118] = D_001A4BE0.f[0x22]; D_001A4BE0.f[0x13c] = 0.00825f; D_001A4BE0.i[0x106] = -1; D_001A4BE0.f[0x134] = 0.0055555557f; D_001A4BE0.b[0x46e] = 0; D_001A4BE0.b[0x46c] = 0; D_001A4BE0.u[0x120] = 0; D_001A4BE0.u[0x121] = 0; D_001A4BE0.b[0x46d] = 0; D_001A4BE0.f[0x135] = 0.0030555557f; D_001A4BE0.f[0x138] = 2.5f; D_001A4BE0.uh[0x27c] = D_001A4BE0.b[0x1474]; D_001A4BE0.uh[0x275] = 0x50; D_001A4BE0.uh[0x27a] = 0; D_001A4BE0.b[0x4fc] = 0; D_001A4BE0.b[0x4fe] = 0; D_001A4BE0.b[0x4ff] = 0; D_001A4BE0.uh[0x27d] = 0x46; D_001A4BE0.uh[0x27b] = 0; D_001A4BE0.f[0x139] = 0.5f; D_001A4BE0.f[0x11d] = 0.10283334f; D_001A4BE0.f[0x119] = 0.25016388f; D_001A4BE0.f[0x11c] = 0.8333334f; D_001A4BE0.f[0x10a] = 0.0f; D_001A4BE0.b[0x46f] = 0; D_001A4BE0.uh[0x142e] = 0;
        if (D_001A4BE0.i[0x971] == 0x7 || D_001A4BE0.i[0x971] == 0x69) {
            D_001A4BE0.f[0x11e] = 1.42f; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f;
            D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 2.7f; D_001A4BE0.f[0x136] = 1.42f; D_001A4BE0.uh[0x274] = 17; D_001A4BE0.h[0x23e] = 1;
            D_001A4BE0.b[0x4fc] = 1; D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.b[0x4ff] = 1;
            if (D_001D545C == 0) {
                D_001A4BE0.f[0x136] = D_L30_001DBBB0; D_001A4BE0.uh[0x27b] = 0xaa; D_001A4BE0.uh[0x27d] = 0xaa; D_001A4BE0.f[0x137] = D_L30_001DBBB4;
                D_001A4BE0.f[0x11e] = D_L30_001DBBB0; D_001A4BE0.f[0x13c] = D_L30_001DBBB8 * 0.00027777778f; D_001A4BE0.u[0xa03] = 0;
            }
            D_001A4BE0.f[0x10a] = D_001A4BE0.f[0x13c] * 1.17f;
        }
        else if (D_001A4BE0.i[0x971] == 0x86) {
            D_001A4BE0.f[0x11e] = D_L30_001DBBE8; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = D_L30_001DBBE8 + 0.5f;
            D_001A4BE0.f[0x136] = D_L30_001DBBE8; D_001A4BE0.uh[0x274] = 17; D_001A4BE0.uh[0x275] = 400; D_001A4BE0.f[0x138] = 300.0f;
            D_001A4BE0.f[0x13c] = D_L30_001DBBEC * 0.00027777778f; D_001A4BE0.uh[0x27b] = 1200; D_001A4BE0.uh[0x27d] = 1200;
            D_001A4BE0.f[0x11d] = 0.116666675f;
            if (D_001439F4 != 2) {
                func_L01_0044B090(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 70, 2, 0.0f);
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 35, 4, 0.0f);
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 17, 6, 0.0f);
            }
        }
        else if (D_001A4BE0.i[0x971] == 0x12) {
            D_001A4BE0.f[0x11e] = 0.1f; D_001A4BE0.h[0x23e] = 2; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 28.0f;
            D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 0.2f; D_001A4BE0.f[0x136] = 0.1f; D_001A4BE0.uh[0x274] = 10; D_001A4BE0.b[0x4ff] = 1;
            if (D_001A4BE0.f[0xa12] < 1.25f) {
                D_001A4BE0.f[0x136] = 1.95f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x137] = 1.98f; D_001A4BE0.f[0x11e] = D_001A4BE0.f[0x136];
            } else {
                func_L01_0050D530((V4_F6a70b950 *)(D_001A4BE0.b + 0xf0), (V4_F6a70b950 *)(D_001A4BE0.b + 0xf0), D_001A4BE0.f[0x120]);
                D_001A4BE0.f[0x136] = 1.95f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x137] = 1.98f; D_001A4BE0.f[0x11e] = D_001A4BE0.f[0x136];
            }
            D_001A4BE0.b[0x25e8] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x38) {
            D_001A4BE0.f[0x11e] = 5.5f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 26.0f; D_001A4BE0.f[0x128] = 13.0f; D_001A4BE0.f[0x137] = 5.55f; D_001A4BE0.f[0x136] = 5.5f;
            D_001A4BE0.uh[0x274] = 2; D_001A4BE0.uh[0x275] = 120; D_001A4BE0.b[0x46f] = 1;
            func_L01_004DC1C0(1);
            D_00142660[0x5a] = 0; D_00142660[0x5b] = 0;
            if (func_L01_004FC388(0x38, 120) || D_001A4BE0.i[0xa14] == 0) {
                D_001A4BE0.i[0x6dc]++;
                if (D_001A4BE0.i[0x6dc] > 2 || D_001A4BE0.i[0xa14] == 0) {
                    if (*(s32 *)(*(u8 **)(D_001A4BE0.ptr[0x970] + 0x24) + 0x1A8)) func_L30_004CB6E0(0x7e, 1);
                    else func_L30_004CB6E0(0x39, 1);
                    return 0;
                }
            } else D_001A4BE0.i[0x6dc] = 0;
            D_001A4BE0.uh[0x27d] = 150; D_001A4BE0.f[0x13c] = 0.004166667f; D_001A4BE0.uh[0x276] = 5; D_001A4BE0.uh[0x277] = 4;
        }
        else if (D_001A4BE0.i[0x971] == 0x6b) {
            f32 height;
            D_001A4BE0.i[0x973] = 25;
            if (D_001A4BE0.f[0x22] < D_001A4BE0.f[0xd5]) height = D_001A4BE0.f[0xd5] - D_001A4BE0.f[0x22]; else height = D_001A4BE0.f[0x120];
            D_001A4BE0.f[0x11e] = height + 1.7f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f;
            D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = height + 1.75f; D_001A4BE0.f[0x136] = height + 1.7f; D_001A4BE0.uh[0x274] = 19; D_001A4BE0.b[0x46f] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x28) {
            D_001A4BE0.f[0x11e] = 2.4f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 28.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 2.45f; D_001A4BE0.f[0x136] = 2.4f;
            D_001A4BE0.uh[0x274] = 17; D_001A4BE0.i[0x973] = 15; D_001A4BE0.f[0x13c] = 0.0075000003f; D_001A4BE0.i[0x18d] = 0;
        }
        else if (D_001A4BE0.i[0x971] == 0x29) {
            D_001A4BE0.f[0x11e] = 2.5f; D_001A4BE0.h[0x23e] = 2; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 31.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 2.55f; D_001A4BE0.f[0x136] = 2.5f;
            D_001A4BE0.uh[0x274] = 10; D_001A4BE0.i[0x973] = 15; D_001A4BE0.f[0x13c] = 0.006666667f; D_001A4BE0.i[0x18d] = 0;
        }
        else if (D_001A4BE0.i[0x971] == 0x9) {
            D_001A4BE0.f[0x11e] = 1.42f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f;
            D_001A4BE0.f[0x127] = 29.0f; D_001A4BE0.f[0x128] = 11.0f; D_001A4BE0.f[0x137] = 2.7f; D_001A4BE0.f[0x136] = 1.42f;
            D_001A4BE0.uh[0x274] = 17; D_001A4BE0.f[0x11d] = 0.10283334f;
            if (D_001D545C == 0) {
                D_001A4BE0.f[0x136] = D_L30_001DBBB0; D_001A4BE0.uh[0x27b] = 0xaa; D_001A4BE0.uh[0x27d] = 0xaa; D_001A4BE0.f[0x137] = D_L30_001DBBB4;
                D_001A4BE0.f[0x11e] = D_L30_001DBBB0; D_001A4BE0.f[0x13c] = D_L30_001DBBB8 * 0.00027777778f;
            }
            D_001A4BE0.b[0x4fc] = 1;
            D_001A4BE0.b[0x4fe] = 1;
            D_001A4BE0.b[0x4ff] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x73) {
            D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f; D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 2.75f; D_001A4BE0.f[0x11e] = 2.7f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x136] = 2.7f; D_001A4BE0.uh[0x274] = 5; D_001A4BE0.b[0x4fc] = 1; D_001A4BE0.b[0x46f] = 1; D_001A4BE0.b[0x4fe] = 0; D_001A4BE0.b[0x4ff] = 0;
            if (D_001D545C == 0x15) {
                D_001A4BE0.f[0x11d] = 0.058615003f;
                if (D_001A4BE0.f[0x6d] > 0.058615003f) D_001A4BE0.f[0x6d] = 0.058615003f;
            }
        }
        else if (D_001A4BE0.i[0x971] == 0x45) {
            D_001A4BE0.f[0x11e] = 1.8f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 15.0f; D_001A4BE0.f[0x127] = 22.0f;
            D_001A4BE0.f[0x128] = 12.0f; D_001A4BE0.f[0x137] = 1.85f; D_001A4BE0.f[0x136] = 1.8f; D_001A4BE0.uh[0x274] = 14;
            D_001A4BE0.f[0x13c] = 0.005277778f;
            func_L01_0045D318(0);
            D_001A4BE0.f[0x135] = 0.013888889f; D_001A4BE0.f[0x11d] = 0.055000003f;
        }
        else if (D_001A4BE0.i[0x971] == 0x54) {
            D_001A4BE0.f[0x11e] = 2.7f; D_001A4BE0.f[0x127] = 20.0f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.5f; D_001A4BE0.f[0x126] = 15.5f;
            D_001A4BE0.f[0x128] = 20.0f; D_001A4BE0.f[0x137] = 2.75f; D_001A4BE0.f[0x136] = 2.7f; D_001A4BE0.uh[0x274] = 10;
            D_001A4BE0.f[0x13c] = 0.0069444445f; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x135] = 0.013888889f; D_001A4BE0.f[0x11d] = 0.083333336f;
        }
        else if (D_001A4BE0.i[0x971] == 0xa2) {
            D_001A4BE0.f[0x11e] = 3.5f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 1.2f; D_001A4BE0.f[0x126] = 13.0f;
            D_001A4BE0.f[0x127] = 18.0f; D_001A4BE0.f[0x128] = 18.0f; D_001A4BE0.f[0x137] = 7.5f; D_001A4BE0.f[0x136] = 3.5f;
            D_001A4BE0.uh[0x274] = 23; D_001A4BE0.f[0x13c] = 0.026944445f; D_001A4BE0.f[0x11c] = 0.5f; D_001A4BE0.f[0x139] = 1.0f;
            func_L01_004F1068(12, 0);
            D_001A4BE0.f[0x135] = 0.019444445f; D_001A4BE0.f[0x11d] = 0.15f;
        }
        else if (D_001A4BE0.i[0x971] == 0xac) {
            D_001A4BE0.f[0x11e] = 7.5f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 1.2f; D_001A4BE0.f[0x126] = 14.0f;
            D_001A4BE0.f[0x127] = 20.0f; D_001A4BE0.f[0x128] = 20.0f; D_001A4BE0.f[0x137] = 7.7f; D_001A4BE0.f[0x136] = 7.5f;
            D_001A4BE0.uh[0x274] = 3; D_001A4BE0.f[0x13c] = 0.013888889f; D_001A4BE0.f[0x11c] = 0.5f; D_001A4BE0.f[0x139] = 1.0f;
            D_001A4BE0.f[0x135] = 0.019444445f; D_001A4BE0.f[0x11d] = 0.15f;
        }
        else if (D_001A4BE0.i[0x971] == 0xa7) {
            D_001A4BE0.f[0x11e] = 7.7f; D_001A4BE0.h[0x23e] = 10; D_001A4BE0.f[0x122] = 1.2f; D_001A4BE0.f[0x126] = 13.0f;
            D_001A4BE0.f[0x127] = 22.0f; D_001A4BE0.f[0x128] = 35.0f; D_001A4BE0.f[0x137] = 7.75f; D_001A4BE0.f[0x136] = 7.7f;
            D_001A4BE0.uh[0x274] = 5; D_001A4BE0.f[0x11c] = 0.5f; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x135] = D_001A4BE0.f[0x13c] = 0.019444445f;
            D_001A4BE0.h[0xd95] = 37; D_001A4BE0.i[0x6cb] = D_001A4BE0.h[0xd94];
            D_001A4BE0.f[0x12e] = func_00389380(D_001A4BE0.f[0x26], 3.1415927f);
            D_001A4BE0.f[0x11d] = 0.15f;
        }
        else if (D_001A4BE0.i[0x971] == 0xa) {
            D_001A4BE0.f[0x11e] = 1.9f; D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 29.0f;
            D_001A4BE0.f[0x128] = 10.0f; D_001A4BE0.f[0x137] = 1.95f; D_001A4BE0.f[0x136] = 1.9f; D_001A4BE0.uh[0x274] = 14;
            D_001A4BE0.f[0x13c] = 0.0030555557f; D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.uh[0x275] = 120; D_001A4BE0.uh[0x27d] = 90;
            D_001A4BE0.uh[0x27b] = 0x46;
        }
        else if (D_001A4BE0.i[0x971] == 0x10) {
            D_001A4BE0.h[0x23e] = 5; D_001A4BE0.f[0x11e] = 1.5f; D_001A4BE0.f[0x122] = 0.8f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 30.0f;
            D_001A4BE0.f[0x128] = 11.0f; D_001A4BE0.f[0x137] = 1.55f; D_001A4BE0.f[0x136] = 1.5f; D_001A4BE0.uh[0x274] = 1;
            func_L01_003EFFE0(20, 0);
            D_001A4BE0.f[0x137] = 0.9f; D_001A4BE0.f[0x11e] = 0.4f; D_001A4BE0.f[0x136] = 0.4f;
            if (D_001A4BE0.f[0x61] < 0.33333334f && D_001439F4 != 2) {
                func_L01_0044B090(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 40, 2, 0.0f);
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 20, 4, 0.0f);
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 10, 6, 0.0f);
            }
            D_001A4BE0.b[0x4fe] = 1; D_001A4BE0.f[0x109] = 0.19166668f; D_001A4BE0.f[0x13c] = 0.002361111f; D_001A4BE0.f[0x134] = 0.012222223f;
            D_001A4BE0.f[0x135] = 0.013888889f;
        }
        else if (D_001A4BE0.i[0x971] == 0x1b) {
            D_001A4BE0.f[0x11e] = 2.0f; D_001A4BE0.h[0x23e] = 4; D_001A4BE0.f[0x122] = 0.85f; D_001A4BE0.f[0x126] = 20.0f;
            D_001A4BE0.f[0x127] = 29.0f; D_001A4BE0.f[0x128] = 19.0f; D_001A4BE0.f[0x137] = 2.05f; D_001A4BE0.f[0x136] = 2.0f;
            D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x13c] = 0.0069444445f; D_001A4BE0.uh[0x274] = 1; D_001A4BE0.i[0x123] = 0;
            D_001A4BE0.b[0x46f] = 1; D_001A4BE0.b[0x25f0] = 1; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.b[0x4fe] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0x48) {
            D_001A4BE0.f[0x11e] = 1.55f; D_001A4BE0.f[0x127] = 14.0f; D_001A4BE0.h[0x23e] = 13; D_001A4BE0.f[0x122] = 0.85f;
            D_001A4BE0.f[0x126] = 8.0f; D_001A4BE0.f[0x128] = 14.0f; D_001A4BE0.f[0x137] = 1.59f; D_001A4BE0.f[0x136] = 1.55f;
            D_001A4BE0.uh[0x274] = 1; D_001A4BE0.i[0x123] = 0; D_001A4BE0.f[0x13c] = 0.007777778f;
        }
        else if (D_001A4BE0.i[0x971] == 0x11) {
            D_001A4BE0.h[0x23e] = 9; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 12.0f; D_001A4BE0.f[0x127] = 20.0f;
            D_001A4BE0.f[0x128] = 10.0f; D_001A4BE0.uh[0x274] = 12;
            if (D_001A4BE0.b[0x285e]) {
                f32 lim = 7.0f, w = D_001A4BE0.f[0xa18];
                D_001A4BE0.f[0x11a] = 0.08166667f; D_001A4BE0.f[0x137] = 3.35f; D_001A4BE0.f[0x136] = 3.3f;
                if (w > lim) {
                    f32 t = (w - lim) / 4.2f;
                    if (t > 0.7f) t = 0.7f;
                    t += 1.0f;
                    D_001A4BE0.f[0x11a] = t * 0.08166667f;
                }
            } else {
                D_001A4BE0.f[0x11a] = 0.028333336f; D_001A4BE0.f[0x137] = 1.85f; D_001A4BE0.f[0x136] = 1.8f;
            }
            D_001A4BE0.b[0x46f] = 1; D_001A4BE0.f[0x11e] = D_001A4BE0.f[0x136];
            func_L01_003EFFE0(0x1b, 0);
            D_001A4BE0.uh[0x27d] = 0x50; D_001A4BE0.f[0x13c] = 0.008055556f; (*(u128_t *)(D_001A4BE0.b + 0x4c0) = *(u128_t *)(D_001A4BE0.b + 0x4b0));
            D_001A4BE0.uh[0x142e] = 1; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x4fc] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0xd) {
            D_001A4BE0.h[0x23e] = 9; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 26.0f; D_001A4BE0.f[0x127] = 38.0f;
            D_001A4BE0.f[0x128] = 18.0f; D_001A4BE0.f[0x137] = 4.07f; D_001A4BE0.f[0x11e] = 4.0f;
            D_001A4BE0.f[0x136] = 4.0f; D_001A4BE0.uh[0x274] = 14;
            func_L01_003EFFE0(20, 0);
            D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x275] = 120; D_001A4BE0.f[0x11d] = 0.031666666f; D_001A4BE0.uh[0x27b] = 37;
            if (D_001A4BE0.f[0x61] < 0.33333334f && D_001439F4 != 2) {
                func_L01_0044B090(D_001A4BE0.ptr[0x970], (char *)(D_001A4BE0.b + 0x1b90));
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 40, 3, 0.0f);
                func_L01_0044B0B8((List_F66766f2b *)(D_001A4BE0.b + 0x1b90), 20, 5, 0.0f);
            }
            D_001A4BE0.b[0x4fe] = 1;
        }
        else if (D_001A4BE0.i[0x971] == 0xf) {
            D_001A4BE0.f[0x11e] = 1.65f; D_001A4BE0.h[0x23e] = 9; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 50.0f;
            D_001A4BE0.f[0x127] = 64.0f; D_001A4BE0.f[0x128] = 28.0f; D_001A4BE0.f[0x137] = 1.7f; D_001A4BE0.f[0x136] = 1.65f;
            D_001A4BE0.uh[0x274] = 5; D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x275] = 0x82; D_001A4BE0.f[0x11d] = 0.055000003f;
            D_001A4BE0.uh[0x27b] = 0x55; D_001A4BE0.uh[0xe8] = 0x46; D_001A4BE0.b[0x46d] = 1;
            if (D_00143950) D_001A4BE0.i[0x100] = 0x22; else D_001A4BE0.i[0x100] = 0x23;
            D_001A4BE0.i[0x101] = D_001A4BE0.i[0x100] + 0x24;
            D_001A4BE0.f[0x102] = 29.0f;
            D_001A4BE0.f[0x103] = 50.0f;
            D_001A4BE0.u[0x104] = 0x56;
            D_001A4BE0.ptr[0x105] = D_L30_001DBD28;
            D_001A4BE0.b[0x4fe] = 1;

        }
        else if (D_001A4BE0.i[0x971] == 0xe) {
            f32 h = D_001A4BE0.f[0xcf], v = 0.7f;
            if (h < 2.0f) v = (2.5f - h) * 0.5f + v;
            D_001A4BE0.f[0x11e] = v; D_001A4BE0.h[0x23e] = -1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 32.0f; D_001A4BE0.f[0x127] = 43.0f; D_001A4BE0.f[0x128] = 19.0f; D_001A4BE0.f[0x137] = v + 0.05f; D_001A4BE0.f[0x136] = v; D_001A4BE0.uh[0x274] = 14; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.f[0x11d] = 0.07916667f; D_001A4BE0.uh[0x27b] = 0x1e;
        }
        else if (D_001A4BE0.i[0x971] == 0xb) {
            D_001A4BE0.f[0x11e] = 3.2f; D_001A4BE0.h[0x23e] = 1; D_001A4BE0.f[0x122] = 0.6f; D_001A4BE0.f[0x126] = 18.0f; D_001A4BE0.f[0x127] = 31.0f; D_001A4BE0.f[0x128] = 24.0f; D_001A4BE0.f[0x137] = 3.25f; D_001A4BE0.f[0x136] = 3.2f; D_001A4BE0.uh[0x274] = 14; D_001A4BE0.f[0x138] = 4.5f; D_001A4BE0.uh[0x27d] = 0x32; D_001A4BE0.f[0x139] = 1.0f; D_001A4BE0.b[0x46f] = 1;
            D_001A4BE0.f[0x125] = func_L01_004E5630(10);
            (*(u128_t *)(D_001A4BE0.b + 0x450) = *(u128_t *)(D_001A4BE0.b + 0x0));
            D_001A4BE0.i[0x129] = func_L01_004FB758();
            D_001A4BE0.f[0x124] = D_001A4BE0.f[0x68];
            (*(u128_t *)(D_001A4BE0.b + 0x440) = *(u128_t *)(D_001A4BE0.b + 0x190));
            if (D_001A4BE0.f[0x5d] > 0.025000002f) D_001A4BE0.f[0x12a] = D_001A4BE0.f[0x5d];
            else D_001A4BE0.f[0x12a] = 0.0f;
            D_001A4BE0.u[0x12b] = 0;
            D_001A4BE0.b[0x4fc] = 1;
            if ((D_001A4BE0.h[0xa1a] || (D_001A4BE0.i[0x5ac] == 1 && func_L01_0045D358(0x28, 2, 0, 0))) && D_001A4BE0.f[0xa0e] > 0.3f) {
                func_L30_004B8E30(0, D_001A4BE0.f[0x6c]);

                D_001A4BE0.f[0x124] = D_001A4BE0.f[0x68];
                (*(u128_t *)(D_001A4BE0.b + 0x440) = *(u128_t *)(D_001A4BE0.b + 0x1420));
                D_001A4BE0.f[0x12b] = 0.083333336f;
                D_001A4BE0.b[0x4fd] = 1;
            } else D_001A4BE0.b[0x4fd] = 0;
            D_001A4BE0.b[0x4fe] = 1;
        }
        if (D_001A4BE0.f[0x138] == 0.0f) D_001A4BE0.f[0x138] = D_001A4BE0.f[0x11e] * 1.5f;
        if (!animate) goto finish;
        if (D_001A4BE0.i[0x971] == 0x7 || D_001A4BE0.i[0x971] == 0x69) func_L01_0050BB98(7, 1, -4.0f);
        else if (D_001A4BE0.i[0x971] == 0x73) func_L01_0050BB98(7, 0, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0x86) func_L01_0050BB98(7, 0, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0x12) func_L01_0050BB98(0x59, 1, -4.0f);
        else if (D_001A4BE0.i[0x971] == 0x38) func_L01_0050BB98(0x3e, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x6b) func_L01_0050BB98(7, 0, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0x28) func_L01_0050BB98(0x48, 4, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0x29) {
            s32 turn = 0x1e;
            if (func_00389468(D_001A4BE0.f[0x26], func_00388A28(D_001A4BE0.f[0x15c] - D_001A4BE0.f[0x16c], D_001A4BE0.f[0x15d] - D_001A4BE0.f[0x16d])) > 1.5707964f) turn = 0x1f;
            func_L01_0050BB98(turn, 0, 5.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0x9) {
            index = (s32)D_001A4BE0.f[0x306];
            animation_41 = 8;
            if (func_L01_004DC1A0(objectSnapshot[0x42]) == 4) animation_41 = D_L30_001DBD08[index];
            func_L01_0050BB98(animation_41, 0, 5.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0x45) func_L01_0050BB98(0x16, 5, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0x54) func_L01_0050BB98(3, 5, 3.0f);
        else if (D_001A4BE0.i[0x971] == 0xa2) {
            if (D_001A4BE0.i[0x975] == 1) {
                D_001A4BE0.f[0x126] = 14.0f; D_001A4BE0.f[0x128] = D_001A4BE0.f[0x127] = 20.0f;
                func_L01_0050BB98(func_L30_004E2EC8(0x3c), 5, 4.0f);
            } else func_L01_0050BB98(func_L30_004E2EC8(0x2c), 4, 3.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0xac) func_L01_0050BB98(0x41, 0, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0xa7) func_L01_0050BB98(0x32, 6, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0xa) func_L01_0050BB98(0x12, 0, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0x10) {
            if (D_001A4BE0.i[0x975] == 4 || (D_001A4BE0.i[0x974] == 4 && D_001A4BE0.i[0x6e] < 7)) {
                func_L01_0050BB98(0x26, 0, 8.0f);
                D_001A4BE0.uh[0x23e] += 3;
            } else func_L01_0050BB98(0x26, 0, 5.0f);
        }
        else if (D_001A4BE0.i[0x971] == 0x1b) func_L01_0050BB98(0x22, 2, 3.0f);
        else if (D_001A4BE0.i[0x971] == 0x48) func_L01_0050BB98(9, 0, 4.0f);
        else if (D_001A4BE0.i[0x971] == 0x11) func_L01_0050BB98(0x23, 2, 7.0f);
        else if (D_001A4BE0.i[0x971] == 0xd) func_L01_0050BB98(0x11, 0, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0xe) { func_L01_0050BB98(0x16, 3, 7.0f); D_001A4BE0.f[0x300] = 0.8f; }
        else if (D_001A4BE0.i[0x971] == 0xf) func_L01_0050BB98(0x15, 0, 5.0f);
        else if (D_001A4BE0.i[0x971] == 0xb) {
            s32 a = D_001A4BE0.i[0x129] + 0x1c;
            if (D_001D545C_b[0xd]) {
                if (a == 0x1c) a = 0x1d;
                else if (a == 0x1d) a = 0x1c;
            }
            if (D_001A4BE0.i[0x975] == 4) { func_L01_0050BB98(a, 1, 4.0f); D_001A4BE0.h[0x23e] = 1; }
            else func_L01_0050BB98(a, 0, 5.0f);
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
            if (D_001D4C38 > D_001A7C10[1].maximum) D_001A7C10[1].maximum = D_001D4C38;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C)) | 0x80000000u;
            if (D_001A4BE0.i[0x48a] == 0x7f && func_L01_0050DA08(-1)) func_L01_004F1CE0();
            else func_L01_004F1A08();
            D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x973] = D_001A4BE0.i[0x975];
            return 0;
        }
        if (D_001A4BE0.i[0x48a] == 0x7f && !func_L01_0050DA08(-1)) {
            D_001A4BE0.i[0x971] = D_001A4BE0.i[0x974]; D_001A4BE0.i[0x973] = D_001A4BE0.i[0x975];
            return 0;
        }
        if (action != 0x88) D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x2f5] = 1.0f; D_001A4BE0.i[0x2f2] = 0; D_001A4BE0.u[0x2f1] = 0; D_001A4BE0.uh[0x5ef] = 0;
        switch (D_001A4BE0.i[0x971]) {
        case 0x14:
            if (D_001A7C10[0].count < 0xFFFF) D_001A7C10[0].count++;
            if (D_001D4C38 > D_001A7C10[0].maximum) D_001A7C10[0].maximum = D_001D4C38;
            D_001A7C10[0].levels = (D_001A7C10[0].levels | (1u << D_001D545C)) | 0x80000000u;
            D_001A4BE0.u[0xa03] = 0x50; D_001A4BE0.h[0x5ee] = 4; D_001A4BE0.i[0x98c] = 0;
            func_L01_004EEA78(8.0f, 1.0471976f, -1.0f); D_001A4BE0.u[0x2f8] = 0;
            if (animate) {
                selected_14 = D_001A4BE0.i[0x974] == 0xb && D_001A4BE0.i[0x976] < 42 ? 17 : 11;
                func_L01_0050D8F8(-1, 1);
                D_L30_001DDAA4_004CB6E0 = 1;
                func_L01_0050BB98(0x28, 4, (f32)selected_14);
                animation_14 = func_L01_004E5438(0);
                if (func_L01_004EA1D8((u8 *)animation_14)) func_003BE4F0((u8 *)animation_14, 10, 4, selected_14 + 2);
            }
            goto finish;
        case 0x15:
            if (D_001A7C10[1].count < 0xFFFF) D_001A7C10[1].count++;
            if (D_001D4C38 > D_001A7C10[1].maximum) D_001A7C10[1].maximum = D_001D4C38;
            D_001A7C10[1].levels = (D_001A7C10[1].levels | (1u << D_001D545C)) | 0x80000000u;
            D_001A4BE0.h[0x5ee] = 3; D_001A4BE0.i[0x98c] = 0;
            func_L01_004EEA78(14.0f, 0.5235988f, -1.0f);
            D_001A4BE0.u[0x2fb] = D_001A4BE0.u[0x2fb] == 0;
            if (D_001A4BE0.h[0xa1a] || (D_001A4BE0.i[0x5ac] == 1 && func_L01_0045D358(0x28, 2, 0, 0))) {
                D_001A4BE0.i[0x2f2] = 1; D_001A4BE0.f[0x2f3] = D_001A4BE0.f[0x26];
            }
            if (animate) {
                selected_15 = D_001A4BE0.ptr[0x970][0x43] == 0x1A ? 3 : 5;
                if (D_001A4BE0.i[0x974] == 0x1) selected_15 = 17;
                func_L01_0050BB98(0x1A, 0, (f32)selected_15); func_L01_0050BEE0(6, 21);
            }
            goto finish;
        case 0x88:
            D_001A4BE0.h[0x5ee] = 3;
            if (animate) {
                selected_83 = D_001A4BE0.ptr[0x970][0x43] == 0x1A ? 3 : 10;
                if (D_001A4BE0.i[0x974] == 0x1) selected_83 = 17;
                func_L01_0050BB98(0x1A, 0, (f32)selected_83);
            }
            goto finish;
        case 0x13:
        {
        s32 *entry = D_L30_002F4C30[D_001A4BE0.h[0x5ee]];
        D_001A4BE0.i[0x98c] = 0; mode = 0;
        if ((D_001A4BE0.i[0x974] == 0x13 && (f32)entry[2] > D_001A4BE0.f[0x306]) ||
            (D_001A4BE0.i[0x977] == 0x13 && D_001A4BE0.i[0x6e] + D_001A4BE0.i[0x976] < 27)) mode = (entry[1] + 1) % 3;
        }
        D_001A4BE0.h[0x5ee] = mode;
        func_L01_004EEA78(5.0f, 0.7853982f, 0.7853982f);
        if (animate) {
            current = 0;
            if (mode == 0) { func_L01_0050D8F8(-1, 1); selected_13 = 5; D_L30_001DDAA4_004CB6E0 = 1; }
            else if (mode == 1) { func_L01_0050D8F8(-1, 1); current = 2; D_L30_001DDAA4_004CB6E0 = 1; selected_13 = 7; }
            else { func_L01_0050D8F8(-1, 1); current = 4; D_L30_001DDAA4_004CB6E0 = 1; selected_13 = 7; }
            if (D_001A4BE0.i[0x2f2] && mode < 2) {
                if (D_001A4BE0.b[0x25f4]) angle_13 = func_L01_004F1018((D_001A4BE0.b + 0xba0), 0);
                else angle_13 = func_00389468(D_001A4BE0.f[0x2f3], D_001A4BE0.f[0x26]);
                selected_13 += (s32)(angle_13 * 1.5f);
            }
            current /= 2;
            func_L01_0050BB98(mode + 0x17, current, (f32)selected_13);
            animation_13 = func_L01_004E5438(0);
            if (func_L01_004EA1D8((u8 *)animation_13)) func_L01_00441E00((u8 *)animation_13, mode + 3, current, selected_13, 0x10);
        }
        goto finish;
        case 0x4d: {
            s32 m4d;
            s32 *row = D_L30_002F4C30[D_001A4BE0.h[0x5ee]];
            m4d = 0;
            if ((D_001A4BE0.i[0x975] == 0x6 || (D_001A4BE0.i[0x978] == 0x6 && (u32)(D_001A4BE0.ptr[0x970][0x43] - 15) < 2)) &&
                row[0] == 0 && (f32)row[2] > D_001A4BE0.f[0x306]) m4d = (row[1] + 1) % 2;
            D_001A4BE0.h[0x5ee] = m4d + 7;
            func_L01_004EEA78(5.0f, 0.7853982f, 0.7853982f);
            if (animate) func_L01_0050BB98(m4d + 0xF, 2, 4.0f);
            goto finish; }
        case 0x22:
            if (animate) func_L01_0050BB98(0x29, 7, 9.0f);
            goto finish;
        }
        goto finish;
    case 0x72:
        D_001A4BE0.i[0x973] = 6; D_001A4BE0.uh[0x5ef] = 0;
        if (D_001A4BE0.i[0x974] == 0x72) D_001A4BE0.h[0x5ee] = D_L30_002F4C30[D_001A4BE0.h[0x5ee]][1] == 0 ? 6 : 5;
        else D_001A4BE0.h[0x5ee] = 5;
        {
            s32 kind = D_L30_002F4C30[D_001A4BE0.h[0x5ee]][1];
            s32 still;
            u32 object;
            if (!animate) goto finish;
            still = kind == 0;
            func_L01_0050BB98(kind + 0x17, still, 5.0f);
            object = func_L01_004E5438(0);
            if (func_L01_004EA1D8((u8 *)object)) func_003BE4F0((u8 *)object, kind + 0xC, still, 5);
        }
        goto finish;
    case 0x2a:
        D_001A4BE0.i[0x973] = 15; D_001A4BE0.uh[0x5ef] = 0;
        if (D_001A4BE0.i[0x974] == 0x2a) D_001A4BE0.h[0x5ee] = D_001A4BE0.h[0x5ee] == 0; else D_001A4BE0.h[0x5ee] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(D_001A4BE0.h[0x5ee] + 0x46, 0, 4.0f);
        {
            u32 object = func_L01_004E5438(0);
            if (func_L01_004EA1D8((u8 *)object)) func_003BE4F0((u8 *)object, D_001A4BE0.h[0x5ee] + 0xC, 0, 4);
        }
        goto finish;
    case 0x7c:
        D_001A4BE0.i[0x973] = 10; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x2f4] = func_00389380(D_001A4BE0.f[0x26], 3.1415927f);
        func_003886E8((D_001A4BE0.b + 0xbb0), (D_001A4BE0.b + 0x0), -1.0f); D_001A4BE0.f[0x6d] = 0.15f;
        if (!animate) goto finish;
        func_L01_0050BB98(0x27, 5, 8.0f); goto finish;
    case 0x16:
        D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x973] = 7;
        func_L01_004ED3B8(0.5f); func_L01_003EFFE0(18, 0);
        D_001A4BE0.uh[0x107] = 0x2d; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003BF640((f32 *)(D_001A4BE0.b + 0xf0), 0.116666675f);
        hit_44 = func_L01_00444358(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_44) func_L01_004DC1C0((s32)(*(f32 *)(hit_44 + 0x2C)));
        else func_L01_004DC1C0(1);
        D_001A4BE0.uh[0xee] = 77;
        if (!animate) goto finish;
        func_L01_0050BB98(0x10, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4DC0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x91:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0; func_L01_004ED3B8(0.5f);
        D_001A4BE0.b[0x25ed] = 1; func_L01_003EFFE0(18, 0);
        hit_45 = func_L01_00444358(D_001A4BE0.ptr[0x970], 8, 0);
        if (hit_45) func_L01_004DC1C0((s32)(*(f32 *)(hit_45 + 0x2C)));
        else func_L01_004DC1C0(1);
        D_001A4BE0.uh[0xee] = 77;
        if (!animate) goto finish;
        func_L01_0050BB98(0x74, 1, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4DC0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x6a:
        D_001A4BE0.i[0x973] = 0x19; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x6dc]++;
        func_L01_004F1068(7, 0);
        D_001A4BE0.i[0xf0] = 0; D_001A4BE0.u[0x6c] = 0; D_001A4BE0.u[0x6d] = 0; D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050BB98(0x58, 0, 8.0f); goto finish;
    case 0x7d:
        D_001A4BE0.i[0x973] = 0x19; D_001A4BE0.uh[0xf8] = 10000; D_001A4BE0.u[0xa03] = 0;
        func_L01_004F1068(7, 0);
        D_001A4BE0.i[0x45a] = 0x68;
        if (!animate) goto finish;
        func_L01_0050BB98(0x58, 0, 8.0f); goto finish;
    case 0x7e:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.f[0xd5] = D_001A4BE0.f[0xce]; D_001A4BE0.uh[0xf8] = 10000;
        D_001A4BE0.i[0xa14] = 0; D_001A4BE0.u[0xa03] = 0; func_L01_004F1068(7, 0);
        if (!animate) goto finish;
        func_L01_0050BB98(0x58, 0, 8.0f); goto finish;
    case 0x7f:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.uh[0xf8] = 10000; D_001A4BE0.f[0xd5] = D_001A4BE0.f[0xce];
        D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0xa14] = 0;
        *(u128_t *)(D_001A4BE0.ptr[0x2fe] + 0x10) = *(u128_t *)(D_001A4BE0.b + 0x80);
        func_0039FE80(7, 0, D_001A4BE0.ptr[0x2fe]);
        if (!animate) goto finish;
        func_L01_0050BB98(0x11, 0, 8.0f); goto finish;
    case 0x3f:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CB6E0(0x4e, 1); return 0; }
        if (!animate) goto finish;
        func_L01_0050BB98(func_L30_004A9D20(0), 0, 9.0f); goto finish;
    case 0x4b:
        D_001A4BE0.i[0x973] = 5; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.f[0x5c] > 0.075f) func_L01_004ED3B8(0.075f / D_001A4BE0.f[0x5c]);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x110));
        if (!animate) goto finish;
        func_L01_0050BB98(14, 0, 12.0f); goto finish;
    case 0x4f:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0; qzero(D_001A4BE0.b + 0xf0);
        if (!animate) goto finish;
        func_L01_0050BB98(0x20, 2, 4.0f); goto finish;
    case 0x41:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.f[0x281] = 0.0019444445f; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(4, 0, 8.0f); goto finish;
    case 0x44:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(4, 0, 8.0f); goto finish;
    case 0x4e:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(4, 0, 12.0f); goto finish;
    case 0x42:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004ED3B8(0.5f);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003BF640((f32 *)(D_001A4BE0.b + 0xf0), 0.083333336f);
        hit_52 = func_L01_00444358(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_52) func_L01_004DC1C0((s32)(*(f32 *)(hit_52 + 0x2C)));
        else func_L01_004DC1C0(1);
        D_001A4BE0.uh[0x107] = 0x2d;
        if (D_001A4BE0.i[0xa14] <= 0) { func_L30_004CB6E0(0x43, 1); func_L01_003EFFE0(18, 0); return 0; }
        func_L01_003EFFE0(18, 0);
        D_001A4BE0.uh[0xee] = 0x32;
        if (!animate) goto finish;
        func_L01_0050BB98(6, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4DC0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x40:
        if (D_001A4BE0.b[0x147c] && D_001A4BE0.h[0x1b6] == 0) { func_L30_004CB6E0(0x4e, 1); return 0; }
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_003887A0((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.i[0x974] == 0x3) D_001A4BE0.u[0x6d] = 0;
        if (D_001A4BE0.i[0x975] == 0x0) D_001A4BE0.f[0x6d] = func_003887A0((D_001A4BE0.b + 0x160));
        D_001A4BE0.b[0x3ec] = 0; D_001A4BE0.b[0x3ef] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x19, 0, 8.0f); goto finish;
    case 0x43:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.i[0xa14] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(5, 2, 4.0f); goto finish;
    case 0x46:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        D_001A4BE0.f[0x14b] = 0.0033333334f; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x22];
        if (D_001A4BE0.i[0x975] == 0x4) { D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c]; D_001A4BE0.f[0x14c] = D_001A4BE0.f[0x118]; }
        if (!animate) goto finish;
        func_L01_0050BB98(8, 14, 7.0f); goto finish;
    case 0x47:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050BB98(10, 0, 6.0f); goto finish;
    case 0x49:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050BB98(11, 0, 6.0f); goto finish;
    case 0x4a:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.u[0xa03] = 13;
        if (!animate) goto finish;
        func_L01_0050BB98(12, 0, 6.0f); goto finish;
    case 0x9d: {
        s32 a, b, m, n = 2;
        D_001A4BE0.i[0x973] = 6; D_001A4BE0.u[0xa03] = 0; a = 0x21; b = 0x13; m = 0; D_001A4BE0.i[0x6e] = 0;
        if (func_L01_004FC388(0x9d, 10)) {
            switch (D_001A4BE0.h[0x5ee]) {
            case 0: a = 0x22; b = 9; m = 1; break;
            case 1: a = 0x23; b = 5; m = 2; break;
            }
        }
        D_001A4BE0.h[0x5ee] = m;
        func_L01_0045D318(0);
        if (animate) func_L01_0050BB98(a, b, n);
        goto finish; }
    case 0xab:
        D_001A4BE0.i[0x973] = 0x24; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x37, 0, 9.0f); goto finish;
    case 0xad: {
        s32 count;
        f32 value;
        f32 start;
        D_001A4BE0.i[0x973] = 0x1a; D_001A4BE0.i[0x1a8] = 0; D_001A4BE0.i[0x1ae] = 0;
        start = D_001A4BE0.f[0x1a6]; count = D_001A4BE0.i[0x1a5]; value = start;
        func_L01_00472C40(D_001A4BE0.i[0x1a4], pos, &count, &value, D_001A4BE0.i[0x1ab], 1.0f);
        vec_sub_ab(dir, pos, D_001A4BE0.b + 0x80);
        if (func_00388770(dir) > 0.001f) {
            func_00388830(dir, dir, 1.0f);
            D_001A4BE0.f[0x1a9] = func_00388730((D_001A4BE0.b + 0x110), dir);
        }
        D_001A4BE0.f[0x1a9] = D_001A4BE0.f[0x1a9] * 0.7f;
        if (D_001A4BE0.f[0x1a9] < 0.0f) D_001A4BE0.f[0x1a9] = 0.0f;
        func_L01_0050BB98(0x45, 4, 5.0f); D_001A4BE0.f[0x300] = 0.7f;
        goto finish; }
    case 0xa8:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.f[0x14b] = 0.015833333f; D_001A4BE0.u[0xa03] = 0;
        if (D_001A4BE0.i[0x975] == 4) D_001A4BE0.f[0x14b] = D_001A4BE0.f[0x13c];
        D_001A4BE0.h[0xd95] = 10; D_001A4BE0.i[0x6cb] = D_001A4BE0.h[0xd94];
        if (animate) func_L01_0050BB98(0x34, 8, 4.0f);
        goto finish;
    case 0xa9:
        D_001A4BE0.i[0x973] = 3; D_001A4BE0.i[0x6cb] = D_001A4BE0.h[0xd94]; D_001A4BE0.h[0xd95] = 10; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x33, 0, 5.0f); goto finish;
    case 0xa3:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x10, 0, -4.0f); goto finish;
    case 0x9e:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004ED3B8(0.0f); func_L01_003EFFE0(18, 0);
        hit_45 = func_L01_00444358(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_45) func_L01_004DC1C0((s32)(*(f32 *)(hit_45 + 0x2C)));
        else func_L01_004DC1C0(1);
        D_001A4BE0.uh[0xee] = 0x64;
        if (!animate) goto finish;
        func_L01_0050BB98(0x27, 2, 5.0f); goto finish;
    case 0x9a:
        D_001A4BE0.uh[0x104] = 0x46; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.i[0x973] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(func_L30_004E2EC8(1), 0, 9.0f); goto finish;
    case 0x9b:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_003887A0((D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        D_001A4BE0.i[0x6e] = 0;
        animation_16 = func_L30_004E2EC8(7);
        if (func_L01_004FC388(0xa2, 7)) func_L01_0050BB98(animation_16, 0, -4.0f);
        else func_L01_0050BB98(animation_16, 0, 5.0f);
        goto finish;
    case 0xa6:
        D_001A4BE0.i[0x973] = 0x23; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_003887A0((D_001A4BE0.b + 0x120));
        D_001A4BE0.uh[0xd91] = 0; D_001A4BE0.uh[0xd90] = 0;
        func_L01_0045D318(0);
        D_001A4BE0.i[0x3e] = 0; D_001A4BE0.i[0x4e] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x20, 0, 7.0f); goto finish;
    case 0x9c: case 0xa1:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.f[0x280] = 0.015833333f; D_001A4BE0.f[0x281] = 0.0019444445f; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.uh[0xd9f] = 0;
        if (D_001A4BE0.i[0x971] == 0xa1) func_L01_004F1068(0x21, 0);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050BB98(0x2d, 0, 1e+01f); goto finish;
    case 0x9f:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; func_L01_004ED3B8(0.0f);
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050BB98(0x28, 0, 7.0f); goto finish;
    case 0xa0:
        D_001A4BE0.i[0x973] = 20; D_001A4BE0.u[0xa03] = 0; func_L01_004ED3B8(0.0f);
        (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050BB98(0x2d, 0, 7.0f); goto finish;
    case 0x51:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(1, 0, 14.0f); goto finish;
    case 0x59:
        D_001A4BE0.i[0x973] = 0; D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x12, 0, 7.0f); func_L01_0050BEE0(12, 19); goto finish;
    case 0x57:
        D_001A4BE0.i[0x973] = 2; (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x15, 0, 12.0f); goto finish;
    case 0x58:
        D_001A4BE0.i[0x973] = 9; qzero(D_001A4BE0.b + 0xf0); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(1, 0, 7.0f); goto finish;
    case 0x53:
        D_001A4BE0.i[0x973] = 2; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.f[0x280] = 0.0061111115f; D_001A4BE0.f[0x281] = 0.0019444445f;
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120));
        if (!animate) goto finish;
        func_L01_0050BB98(0x15, 0, 7.0f); goto finish;
    case 0x52:
        D_001A4BE0.i[0x973] = 1; D_001A4BE0.u[0xa03] = 0;
        D_001A4BE0.f[0x6d] = func_003887A0((D_001A4BE0.b + 0x120));
        if (D_001A4BE0.f[0x6d] > 0.083333336f) D_001A4BE0.f[0x6d] = 0.083333336f;
        D_001A4BE0.b[0x3ec] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(5, 0, 8.0f); goto finish;
    case 0x56:
        D_001A4BE0.i[0x973] = 20; (*(u128_t *)(D_001A4BE0.b + 0x160) = *(u128_t *)(D_001A4BE0.b + 0x120)); D_001A4BE0.u[0xa03] = 0;
        if (!animate) goto finish;
        func_L01_0050BB98(0x14, 0, 12.0f); goto finish;
    case 0x55:
        D_001A4BE0.i[0x973] = 7; D_001A4BE0.u[0xa03] = 0;
        func_L01_004ED3B8(0.5f);
        (*(u128_t *)(D_001A4BE0.b + 0xf0) = *(u128_t *)(D_001A4BE0.b + 0x120)); func_003BF640((f32 *)(D_001A4BE0.b + 0xf0), 0.083333336f);
        hit_29 = func_L01_00444358(D_001A4BE0.ptr[0x970], 1, 0);
        if (hit_29) func_L01_004DC1C0((s32)(*(f32 *)(hit_29 + 0x2C)));
        else func_L01_004DC1C0(1);
        D_001A4BE0.uh[0xee] = 77;
        if (!animate) goto finish;
        func_L01_0050BB98(0x13, 3, -3.0f);
        *(f32 *)(D_001A4BE0.ptr[0x970] + 0x44) = D_L30_002F4DC0[D_001A4BE0.i[0x304]][D_001A4BE0.i[0x305]++];
        goto finish;
    case 0x3e:
        D_001A4BE0.i[0x973] = 15; D_001A4BE0.u[0xa03] = 0;
        if (!D_001A4BE0.i[0x178]) {
            if (D_001A4BE0.ptr[0x199]) { func_L01_004DC1C0((s32)(*(f32 *)(D_001A4BE0.ptr[0x199] + 0x2C))); D_001A4BE0.ptr[0x199] = 0; }
            else func_L01_004DC1C0(1);
        }
        func_L01_004F1068(20, 0);
        if (D_001A4BE0.i[0xa14] < 1) {
            angle_53 = func_00389380(func_00388A28(D_001A4BE0.f[0x3c], D_001A4BE0.f[0x3d]), 3.1415927f);
            angle_53 = func_00389380(angle_53, func_L01_00440918(0.5235988f, 0.61086524f));
            D_001A4BE0.f[0x48] = func_00388960(angle_53) * (D_001A4BE0.f[0x179] * 0.7f);
            D_001A4BE0.f[0x49] = func_00388978(angle_53) * (D_001A4BE0.f[0x179] * 0.7f); D_001A4BE0.f[0x4a] = 0.075f;
            if (D_001A4BE0.i[0x178] > 15 && D_001A4BE0.i[0xa14] < 2) D_001A4BE0.i[0xa14] = 2;
            D_001A4BE0.ptr[0x970][0xA8] = 255; func_L30_004CB6E0(0x16, 1); D_001A4BE0.uh[0xfa] = 0x96; D_001A4BE0.uh[0xe8] = 0x46;
            return 0;
        }
        D_001A4BE0.uh[0xee] = 77; D_001A4BE0.f[0x18f] = 0.041666668f;
        if (D_001A4BE0.f[0x188] > 0.041666668f) D_001A4BE0.f[0x188] = 0.041666668f;
        qzero(D_001A4BE0.b + 0xf0); D_001A4BE0.u[0x185] = 0; qzero(D_001A4BE0.b + 0x110);
        D_001A4BE0.f[0x3e] = 0.18333334f; D_001A4BE0.f[0x4a] = 0.18333334f;
        if (!animate) goto finish;
        func_L01_0050BB98(0x10, 2, -3.0f); goto finish;
    case 0x1c:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        func_L01_0050BB98(func_L30_004A9D20(0), 0, 10.0f); goto finish;
    case 0x1d:
        D_001A4BE0.u[0xa03] = 0x51; D_001A4BE0.i[0x973] = 0;
        if (func_L01_004DC1A0(D_001A4BE0.ptr[0x970][0x42]) == func_L30_004A9D20(0)) goto finish;
        func_L01_0050BB98(func_L30_004A9D20(0), 0, 5.0f); goto finish;
    case 0x1e:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0;
        func_L01_0050BB98(func_L30_004A9D20(0), 0, 10.0f); goto finish;
    case 0x74:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25ed] = 1; D_001A4BE0.u[0xa03] = 0;
        func_L01_004E6CB0();
        if (!animate) goto finish;
        func_L01_0050BB98(func_L30_004A9D20(0), 0, 10.0f); goto finish;
    case 0x31:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.b[0x25e8] = 1;
        D_001A4BE0.b[0x25ee] = 1; D_001A4BE0.b[0x25ed] = 1; func_L01_0044B4B8((void *)(D_001A4BE0.b + 0x1ce0));
        if (!animate) goto finish;
        func_L01_0050BB98(func_L30_004A9D20(0), 0, -1.0f); goto finish;
    case 0x7a:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.u[0xa03] = 0; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x25ed] = 1; qzero(D_001A4BE0.b + 0xf0);
        if (!animate) goto finish;
        func_L01_0050BB98(11, 0, -1.0f); goto finish;
    case 0x37:
        D_001A4BE0.i[0x973] = 9; D_001A4BE0.b[0x25e8] = 1; D_001A4BE0.b[0x25ed] = 1;
        func_L01_0050BB98(0x3f, 2, 8.0f);
        { u8 *a = D_001A4BE0.ptr[0x480]; if (func_L01_004EA1D8(a)) func_003BE4F0(a, 11, 2, 13); }
        goto finish;
    case 0x64: case 0x65:
        D_001A4BE0.i[0x973] = 24; D_001A4BE0.b[0x25ed] = 1;
        func_L01_0044B4B8((void *)(D_001A4BE0.b + 0x1ce0)); func_L01_004E6CB0();
        if (animate) func_L01_0050BB98(func_L30_004A9D20(0), 0, -1.0f);
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
    if (D_001A4BE0.i[0x973] == 20) { func_L01_004E6CB0(); D_001A4BE0.b[0x25ed] = 1; }
    if ((!func_L01_004E5540() || D_001A4BE0.i[0x973] == 18) &&
        (D_001A4BE0.f[0xd4] < D_L30_001E22C0_004CB6E0.f8 || D_001A4BE0.i[0x973] == 0)) D_L30_001E22C0_004CB6E0.i450 = 0;
    if (D_001A4BE0.i[0x973] != D_001A4BE0.i[0x975]) func_L01_004DD850();
    D_001A4BE0.i[0x6e] = 0;
    D_001A4BE0.u[0x70] = 0;
    if (D_001A4BE0.i[0x973] != D_001A4BE0.i[0x975]) D_001A4BE0.u[0x6f] = 0;
    D_001A4BE0.u[0x71] = 0;
    return 1;
}
/* localdecomp:end func_L30_004CB6E0 */
