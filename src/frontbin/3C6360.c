#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003C6360);

typedef int Q_3C0E10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C0E10;
typedef struct { u8 p0[0x10]; V_3C0E10 pos; } O_3C0E10;
typedef struct { u8 p0[0x46]; u8 b46; } P_3C0E10;
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; u8 p18[0xC]; P_3C0E10 *f24; } E_3C0E10;
extern E_3C0E10 *D_0022B6C0[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern s32 func_003C4B50();
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(f32 *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
s32 func_003C6368(void *, f32 *, f32 *, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C6368);

LINKER_REMNANT("asm/remnants", func_003C65C0);
