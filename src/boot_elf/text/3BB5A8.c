#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BB5A8(s32);
extern s32 func_003BB760(s32);
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

/* localdecomp:start func_003BB5A8 */
typedef struct { u32 a; u32 b; } E_3B5D10;
extern E_3B5D10 D_001DA1B0_003BB5A8[1];
extern u8 D_001D5BDC;
extern u8 D_00280FC0[];
void func_003BB5A8(s32 arg) {
    s32 A, B, C, D, i, e;
    u32 p = (u32)D_00280FC0;
    u32 q = 0;
    if (D_001D5BDC != 0) {
        A = 0; B = 0; C = 1; D = 0;
    } else if (arg == 0) {
        A = 1; B = 1; C = 0; D = 0;
    } else {
        A = 3; B = 1; C = 2; D = 1;
    }
    i = 0;
    e = A;
    for (; i < e; i++) {
        D_001DA1B0_003BB5A8[i].a = p;
        D_001DA1B0_003BB5A8[i].b = 0;
        p += 0x12C00;
    }
    e += B;
    for (; i < e; i++) {
        D_001DA1B0_003BB5A8[i].a = q;
        D_001DA1B0_003BB5A8[i].b = 0;
        q += 0x12C00;
    }
    e += C;
    for (; i < e; i++) {
        D_001DA1B0_003BB5A8[i].a = p;
        D_001DA1B0_003BB5A8[i].b = 1;
        p += 0x4F000;
    }
    e += D;
    for (; i < e; i++) {
        D_001DA1B0_003BB5A8[i].a = q;
        D_001DA1B0_003BB5A8[i].b = 1;
        q += 0x4F000;
    }
    for (; i < 7; i++) {
        D_001DA1B0_003BB5A8[i].b = 0;
        D_001DA1B0_003BB5A8[i].a = 0;
    }
}
/* localdecomp:end func_003BB5A8 */

extern void *D_001DA1B0[];
extern u32 D_001DA1B4[];
extern s32 func_003BB8E8(s32);
extern void func_0038CF58();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BB760);

/* localdecomp:start func_003BB820 */
typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
/* 8-byte (small) aliases: Ps2EeAs builds each address with one adjacent lui/addiu, as retail. */
extern E_3B5F88 D_001DA1B0_003BB820[1];
extern s32 D_001DA1B4_003BB820[2];
extern s32 D_001DA1B4_003B5F88b[2];
extern S_3B5F88 D_1CCFD0_003BB820[];
extern void func_003A2958();
s32 func_003BB820(s32 id) {
    s32 i;
    s32 fb = (s32)D_001DA1B4_003BB820;
    for (i = 0; i < 7; i++) {
        if (D_001DA1B0_003BB820[i].id == id) {
            s32 *t = D_001DA1B4_003B5F88b;
            s32 f = *(s32 *)(fb + i * 8);
            if (f & 2) {
                if (f & 4) {
                    *(s32 *)(fb + i * 8) = f ^ 4;
                    if (D_1CCFD0_003BB820->f4 != 0) func_003A2958();
                }
                t[i * 2] &= ~2;
                return 0;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003BB820 */
