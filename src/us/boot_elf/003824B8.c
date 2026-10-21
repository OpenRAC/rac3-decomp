#include "common.h"

/* NTSC-U version of func_00382498 (boot_elf): 8 -> 10 */

typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern void func_11A264(s32, s32, s32);
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; u8 p10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_37D200;
typedef struct { u8 p0[0x18]; u8 *f18; u8 p1C[0x5C]; s32 f78; } S_227600_37D200;
typedef struct { u8 p0[7]; u8 f7; u8 p8[0x1C]; s32 f24; u8 p28[0x14]; s16 f3C; u8 p3E[2]; u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; u8 p48[6]; s16 f4E; u8 p50[0x1C]; s32 f6C; u8 p70[6]; s16 f76; u8 p78[0x44]; s32 fBC; u8 pC0[6]; s16 fC6; } S_1CCFD0_37D200;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x38]; s32 f688; s32 f68C; } S_160C40_37D200;
typedef struct { s32 f0; u8 p4[0xB3]; u8 fB7; } S_143950_37D200;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_37D200;
typedef struct { u8 p0[0x2C]; s32 f2C; } S_318CC0_37D200;
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } S_pad_37D200;
typedef struct { s32 a; s32 b; } E_37D200;
typedef struct { s32 off; s32 size; } H_37D200;
extern s32 D_U_001D5680;
extern s32 func_12C908(s32);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_381CC0;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s16 h18; u8 p1A[0x15C - 0x1A]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; } S_142430_381CC0;
typedef struct { u8 p0[0x1A4]; s32 f1A4; } S_1D52FC_381CC0;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern s32 D_U_001D5680;
/* localdecomp:start func_U_003824B8 */
extern s32 D_U_001D5680;
void func_U_003824B8(void) { D_U_001D5680 = 10; }
/* localdecomp:end func_U_003824B8 */
