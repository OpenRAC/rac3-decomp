#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BB948(s32);
/* --- end of declarations from other files --- */

/* declarations of 3BB3B8.c's earlier functions (tools/port_from_us.py) */
extern s32 D_0037FA44[];
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;
extern TargetStruct_0037BA20 D_0037F9D0;
extern s32 D_0037FA44[];
extern s8 D_001D8BF0[1];
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037F9D0_003BB538[];
extern u8 D_002D0040[];
extern void func_0038CF58();
typedef struct { u32 a; u32 b; } E_3B5D10;
extern E_3B5D10 D_001DA1B0_003BB5A8[1];
extern u8 D_001D5BDC;
extern u8 D_00280FC0[];
extern void *D_001DA1B0[];
extern u32 D_001DA1B4[];
extern s32 func_003BB8E8(s32);
extern void func_0038CF58();
typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
extern E_3B5F88 D_001DA1B0_003BB820[1];
extern s32 D_001DA1B4_003BB820[2];
extern s32 D_001DA1B4_003B5F88b[2];
extern S_3B5F88 D_1CCFD0_003BB820[];
extern void func_003A2958();
extern s32 D_001DA1B0_003BB8E8[];
extern s32 D_001DA1B4_003BB8E8[];

/* localdecomp:start func_003BB948 */
extern f32 D_001D8C2C;
extern s32 func_0038DFB8(f32, s32, s32);
extern s32 func_003E8128(s32, s32);
void func_003BB948(s32 a) {
    func_003E8128(a, ((s32 (*)(s32, s32, f32))func_0038DFB8)(0x20000000, 0x402299DE, D_001D8C2C));
}
/* localdecomp:end func_003BB948 */
