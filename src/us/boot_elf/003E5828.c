#include "common.h"

/* NTSC-U version of func_003E5970 (boot_elf): 750 -> 900 */

extern void func_U_003E5828(void);

typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3DBEC8;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x7C - 0x64];
    s16 f7C, f7E;
    s32 f80;
    u8 pad84[0x98 - 0x84];
} S_3DBEC8;
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_11B2E8();
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
typedef struct { u8 pad[0xAA]; s16 xAA; } M_3DE8F0;
typedef struct { f32 f0; s16 h4; } R_3DE8F0;
typedef struct {
    u8 pad0[0x19E0];
    M_3DE8F0 *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 x25E4;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 x2850;
} W_3DE8F0;
typedef struct { u8 pad[0x20]; u8 x20; } F_3DE8F0;
extern W_3DE8F0 D_1A4BE0[];
extern F_3DE8F0 D_142CA0[];
extern void func_11B2E8(void *, char *, s32);
typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;
typedef struct { u8 b[16]; } V16_3DF9E0;
typedef struct { u8 pad[8]; s32 (*f8)(); s32 (*fC)(); } VT_3DFE10;
typedef struct { VT_3DFE10 *vt; } O_3DFE10;
typedef struct { u8 pad[8]; VT_3DFE10 *vt; } D_3E5718;
/* localdecomp:start func_U_003E5828 */
__asm__(".extern D_U_001D9608_003E5970, 4");
__asm__(".extern D_001D4C38_gp_003E0068, 4");
__asm__(".extern D_001D545C_003E5970, 4");
extern u8 *D_001D52FC_003E5970;
extern s32 D_U_001D9608_003E5970;
extern s32 D_001D4C38_gp_003E0068;
extern s32 D_001D4C38_003E5970;
extern s32 D_001D545C_003E5970;
extern s32 D_U_001D9D80_003E5970;
extern s32 D_U_001D5BC4_003E5970;
extern s32 D_U_001DA600_003E5970;
extern s32 D_U_001D9140_003E5970;
extern s32 D_001A91E8_003E5970[];
void func_U_003E5828(void) {
    u8 *o = D_001D52FC_003E5970;
    s32 *c;
    if (*(s32 *)(o + 0x1A0) != 0) {
        D_U_001D9608_003E5970 = 0;
    } else if (*(f32 *)(o + 0x108) != 0.0f) {
        D_U_001D9608_003E5970 = 0;
    } else if (*(f32 *)(o + 0x10C) != 0.0f) {
        D_U_001D9608_003E5970 = 0;
    } else if (*(f32 *)(o + 0x100) != 0.0f) {
        D_U_001D9608_003E5970 = 0;
    } else if (*(f32 *)(o + 0x104) != 0.0f) {
        D_U_001D9608_003E5970 = 0;
    } else {
        D_U_001D9608_003E5970 = D_U_001D9608_003E5970 + 1;
    }
    D_U_001D9D80_003E5970 += 1;
    D_001D4C38_gp_003E0068 = D_001D4C38_003E5970 + 1;
    if (D_U_001D5BC4_003E5970 != 0 && D_U_001D9608_003E5970 < 0x384) {
        c = &D_001A91E8_003E5970[D_001D545C_003E5970];
        *c += 1;
    }
    if (D_U_001DA600_003E5970 != D_001D4C38_003E5970 - 1) {
        D_U_001D9140_003E5970 = -1;
    }
}
/* localdecomp:end func_U_003E5828 */
TEXT_PADDING(2);
