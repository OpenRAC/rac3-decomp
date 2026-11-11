#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3B9B00;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3B9B00 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3B9B00;
typedef struct { u8 b[256]; } C_3B9B00;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3B9D08;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3B9D08 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3B9D08;
typedef struct { u8 b[256]; } C_3B9D08;
typedef struct {
    u8 pad0[28];
    f32 f28;
    u8 pad1[104];
    f32 f136;
    u8 pad2[28];
    s32 i168;
    u8 pad3[4];
    u8 v176[16];
} V_003B9F08;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 b33;
    u8 pad1[15];
    u8 b49;
    u8 pad2[2];
    u16 h52;
    u8 pad3[50];
    V_003B9F08 *vars;
    u8 pad4[62];
    s16 oclass;
    u8 pad5[84];
} M_003B9F08;
typedef struct {
    u8 pad0[28];
    f32 f28;
    u8 pad1[104];
    f32 f136;
    u8 pad2[28];
    s32 i168;
    u8 pad3[4];
    u8 v176[16];
} V_003BA0F8;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 b33;
    u8 pad1[15];
    u8 b49;
    u8 pad2[2];
    u16 h52;
    u8 pad3[50];
    V_003BA0F8 *vars;
    u8 pad4[62];
    s16 oclass;
    u8 pad5[84];
} M_003BA0F8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA2E8;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA2E8 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA2E8;
typedef struct { u8 b[256]; } C_3BA2E8;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA4F0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA4F0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA4F0;
typedef struct { u8 b[256]; } C_3BA4F0;
typedef struct {
    u8 pad0[0x1C];
    f32 f1C;
    u8 pad20[0x88 - 0x20];
    f32 f88;
    u8 pad8C[0xA8 - 0x8C];
    int iA8;
    u8 padAC[0xB0 - 0xAC];
    u8 bB0[1];
} V_3BA6D0;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 b21;
    u8 pad22[0x31 - 0x22];
    u8 b31;
    u8 pad32[2];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    V_3BA6D0 *vars;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_3BA6D0;
typedef struct { u8 b[256]; } C_3BA6D0;
typedef struct {
    u8 pad0[28];
    f32 phase;
    u8 pad20[136 - 32];
    f32 size;
    u8 pad8C[168 - 140];
    s32 range;
    u8 padAC[4];
    u8 trail0[32];
    u8 trail1[32];
} Vars_003BA8B0;
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 group;
    u8 pad22[49 - 34];
    u8 visible;
    u8 pad32[2];
    u16 flags;
    u8 pad36[104 - 54];
    Vars_003BA8B0 *vars;
    u8 pad6C[170 - 108];
    s16 oclass;
    u8 padAC[84];
} Moby_003BA8B0;
typedef struct {
    u8 pad[0x1C];
    f32 f1C;
    u8 pad2[0x88 - 0x20];
    f32 f88;
    u8 pad3[0xA8 - 0x8C];
    int xA8;
    u8 pad4[0xB0 - 0xAC];
    u8 xB0[4];
} S_3BAAD8v;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 b21;
    u8 pad2[0x31 - 0x22];
    u8 b31;
    u8 pad3[0x34 - 0x32];
    u16 h34;
    u8 pad4[0x68 - 0x36];
    S_3BAAD8v *v;
    u8 pad5[0xAA - 0x6C];
    s16 hAA;
} S_3BAAD8m;

typedef struct {
    u8 pad[0x24];
    f32 f24;
} P_003B8B50;
typedef struct {
    u8 pad[0xC];
    s32 iC;
    u8 pad2[0xAC - 0x10];
    s16 hAC;
} V_003B8B50;
typedef struct {
    u8 pad[0x20];
    u8 b20;
    u8 b21;
    u8 pad2[0x24 - 0x22];
    P_003B8B50 *p24;
    u8 pad3[0x2C - 0x28];
    f32 f2C;
    u8 pad4[0x34 - 0x30];
    u16 h34;
    u8 pad5[0x68 - 0x36];
    V_003B8B50 *v;
    u8 pad6[0xAA - 0x6C];
    s16 hAA;
} M_003B8B50;

typedef struct {
    u8 pad0[0x84];
    s16 h84;
    u8 pad86[0x9C - 0x86];
    s32 i9C;
} V_003BB258;
typedef struct {
    u8 pad0[0x68];
    V_003BB258 *vars;
    u8 pad6C[0x78 - 0x6C];
    s32 i78;
    u8 pad7C[0xAA - 0x7C];
    s16 hAA;
} M_003BB258;


INCLUDE_ASM("asm/levels", func_L01_003BC530);

INCLUDE_ASM("asm/levels", func_L01_003BC658);

INCLUDE_ASM("asm/levels", func_L01_003BC668);

INCLUDE_ASM("asm/levels", func_L01_003BC7D0);

INCLUDE_ASM("asm/levels", func_L01_003BC920);

INCLUDE_ASM("asm/levels", func_L01_003BC978);
