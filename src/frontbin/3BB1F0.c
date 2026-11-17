#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad0[0x44]; u32 f44; s16 f48; s16 f4A; s16 f4C; s16 f4E; u8 pad50[4]; s16 f54; u8 pad56[2]; s32 f58; s32 f5C; } S_1CCFD0_0039C7B0;
extern S_1CCFD0_0039C7B0 D_1CCFD0_003A1838;
typedef struct {
    u32 h; s16 a; s16 b; s16 c; s16 st; s16 fl; u8 pE[2]; s16 f10; u8 p12[2]; s32 f14; s32 f18; u8 p1C[4]; s32 f20; s32 f24;
} E_39CEA8;
typedef struct {
    u8 p0[4]; s16 h4; u8 b6; u8 b7; s32 f8; u8 pC[4]; s32 f10; s32 f14;
    void (*f18)(s32, s32); s32 f1C; u8 p20[4]; s32 f24; s32 f28; s16 f2C; u8 p2E[2];
    s32 f30; s32 f34; s32 f38; s16 f3C; s16 f3E; u8 p40[4];
    E_39CEA8 e[4];
} S_39CEA8;
#define D (*(S_39CEA8 *)&D_1CCFD0_003A1838)
#undef D
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003BB1F0(s32);
extern s32 func_003BB3A8(s32);
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;


typedef struct { u32 a; u32 b; } E_3B5D10;
extern E_3B5D10 D_001DA1B0_003BB1F0[1];
extern u8 D_001D5BDC;
extern u8 D_00280FC0[];
/* localdecomp:start func_003BB1F0 */
extern TargetStruct_0037BA20 D_0037F9D0_003BB1F0;
extern s32 D_0037FA44_003BB1F0[];
extern s8 D_001D8BF0_003BB1F0[1];
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0_003BB1F0;
extern S_3B5CA0_003BB1F0 D_0037F9D0_003BB538[];
extern u8 D_002D0040[];
extern void func_0038CF58();

typedef struct { u32 a; u32 b; } E_3B5D10_003BB1F0;
extern E_3B5D10_003BB1F0 D_001DA1B0_003BB1F0_003BB1F0[1];
extern u8 D_001D5BDC_003BB1F0;
extern u8 D_00280FC0_003BB1F0[];
void func_003BB1F0(s32 arg) {
    s32 A, B, C, D, i, e;
    u32 p = (u32)D_00280FC0_003BB1F0;
    u32 q = 0;
    if (D_001D5BDC_003BB1F0 != 0) {
        A = 0; B = 0; C = 1; D = 0;
    } else if (arg == 0) {
        A = 1; B = 1; C = 0; D = 0;
    } else {
        A = 3; B = 1; C = 2; D = 1;
    }
    i = 0;
    e = A;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0_003BB1F0[i].a = p;
        D_001DA1B0_003BB1F0_003BB1F0[i].b = 0;
        p += 0x12C00;
    }
    e += B;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0_003BB1F0[i].a = q;
        D_001DA1B0_003BB1F0_003BB1F0[i].b = 0;
        q += 0x12C00;
    }
    e += C;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0_003BB1F0[i].a = p;
        D_001DA1B0_003BB1F0_003BB1F0[i].b = 1;
        p += 0x4F000;
    }
    e += D;
    for (; i < e; i++) {
        D_001DA1B0_003BB1F0_003BB1F0[i].a = q;
        D_001DA1B0_003BB1F0_003BB1F0[i].b = 1;
        q += 0x4F000;
    }
    for (; i < 7; i++) {
        D_001DA1B0_003BB1F0_003BB1F0[i].b = 0;
        D_001DA1B0_003BB1F0_003BB1F0[i].a = 0;
    }
}
/* localdecomp:end func_003BB1F0 */

extern void *D_001DA1B0[];
extern u32 D_001DA1B4[];
extern s32 func_003BB530(s32);
extern void func_0038CB78();
INCLUDE_ASM("asm/nonmatchings/text", func_003BB3A8);

typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
extern E_3B5F88 D_001DA1B0_003BB468[1];
extern s32 D_001DA1B4_003BB468[2];
extern s32 D_001DA1B4_003B5F88b[2];
extern S_3B5F88 D_1CCFD0_003BB468[];
extern void func_003A2558();
/* localdecomp:start func_003BB468 */
typedef struct { s32 id; s32 fl; } E_3B5F88_003BB468;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88_003BB468;
/* 8-byte (small) aliases: Ps2EeAs builds each address with one adjacent lui/addiu, as retail. */
extern E_3B5F88_003BB468 D_001DA1B0_003BB468_003BB468[1];
extern s32 D_001DA1B4_003BB468_003BB468[2];
extern s32 D_001DA1B4_003B5F88b_003BB468[2];
extern S_3B5F88_003BB468 D_1CCFD0_003BB820[];
extern void func_003A2558_003BB468();
s32 func_003BB468(s32 id) {
    s32 i;
    s32 fb = (s32)D_001DA1B4_003BB468_003BB468;
    for (i = 0; i < 7; i++) {
        if (D_001DA1B0_003BB468_003BB468[i].id == id) {
            s32 *t = D_001DA1B4_003B5F88b_003BB468;
            s32 f = *(s32 *)(fb + i * 8);
            if (f & 2) {
                if (f & 4) {
                    *(s32 *)(fb + i * 8) = f ^ 4;
                    if (D_1CCFD0_003BB820->f4 != 0) func_003A2558_003BB468();
                }
                t[i * 2] &= ~2;
                return 0;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003BB468 */
