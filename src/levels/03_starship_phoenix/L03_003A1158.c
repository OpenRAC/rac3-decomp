#include "common.h"
#include "vu0.h"
void func_L03_003A1158(void *, s32);

typedef struct S_003A1158 { u8 pad0[0x34]; u16 h34; u8 pad36[0xD]; u8 b43; u8 pad44[0x24]; s32 *p68; u8 pad6c[0x50]; u8 bBC; } S_003A1158;
typedef struct Q_003A1158 { u8 pad[0x20]; f32 f20; f32 f24; f32 f28; u8 pad2c[0xC]; s32 w38; } Q_003A1158;
typedef struct P_003A1158 { u8 pad[0x150]; f32 pad150[8]; f32 f170; f32 f174; f32 f178; s32 w188; } P_003A1158;

INCLUDE_ASM("asm/levels", func_L03_003A1158);
