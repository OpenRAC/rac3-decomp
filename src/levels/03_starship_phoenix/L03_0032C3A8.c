#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;

typedef struct Ext_0032C3A8 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x60 - 0x1C];
    s32 q60[8];
    u8 pad2[0xCC - 0x80];
    s32 fCC;
    u8 pad3[0xDC - 0xD0];
    s32 fDC;
    u8 pad4[0xEC - 0xE0];
    u8 bEC[4];
    u8 bF0;
    u8 bF1;
    u16 hF2;
    u8 bF4;
    u8 pad5;
    u8 bF6;
    u8 pad6;
    s32 fF8;
    u8 pad7[0x104 - 0xFC];
    s32 f104;
} Ext_0032C3A8;
typedef struct Act_0032C3A8 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[0x20 - 0x1C];
    u8 b20;
    u8 pad2[0x68 - 0x21];
    Ext_0032C3A8 *p68;
    u8 pad3[0x100 - 0x6C];
} Act_0032C3A8;
typedef struct Ent_0032C3A8 {
    s16 h0;
    u8 pad2[2];
    u32 *p4;
    u8 b8;
    u8 pad9[0x28 - 9];
} Ent_0032C3A8;
typedef struct Glob_0032C3A8 {
    u8 pad[0x2824];
    f32 f2824;
    u8 pad1[0x2850 - 0x2828];
    s32 f2850;
} Glob_0032C3A8;

INCLUDE_ASM("asm/levels", func_L03_0032C3A8);
