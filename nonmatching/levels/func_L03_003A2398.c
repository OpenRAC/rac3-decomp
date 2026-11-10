/* near miss (level 3, Starship Phoenix): 126 differences (one cause) with @ps2as needed for the inline float constants (L03_003A20E0.c has none; 231 diff with the default assembler): the six-entry jump-table switch is written in retail block order; in case 3's bit-clear branch retail puts `move $a2,$s1` (arg0 of func_L01_00456230) in the delay slot of the bnez on D_00142C1C & 0x40000000, the C puts `move $a0,$zero` there, so every later instruction of case 3 is one slot off; the inverted if/else (149) and a split result declaration tried; not tried: other argument orders or types for the result */
#include "common.h"

/* localdecomp:start func_L03_003A2398 */
typedef struct S_003A2398 {
    char pad0[0x24];
    s16 timer;
} S_003A2398;
typedef struct T_003A2398 {
    char pad0[0x35C];
    void *owner;
    s32 flag;
    char pad1[0x25C0 - 0x364];
    char *cur;
} T_003A2398;
extern T_003A2398 D_001A4BE0;
extern s32 D_L03_002A1420[];
extern s32 D_L03_002D09B0[]; __asm__(".extern D_L03_002D09B0, 16");
extern s32 D_001A71A0[]; __asm__(".extern D_001A71A0, 16");
extern s32 D_001DF99C_sda; __asm__(".extern D_001DF99C_sda, 4");
extern s32 D_L03_001DF99C; __asm__(".extern D_L03_001DF99C, 16");
extern s32 D_001DE3F0_sda[]; __asm__(".extern D_001DE3F0_sda, 4");
extern char *D_001D52FC;
extern u8 D_00142765[]; __asm__(".extern D_00142765, 16");
extern u32 D_00142C1C[]; __asm__(".extern D_00142C1C, 16");

s32 func_0038CB00(char *);
f32 func_0038D0B0(f32);
s32 func_0038DBD8(f32, u32, u32);
void func_L02_003BAAB0();
s32 func_L01_004BA800();
void func_L01_00452560();
void func_L01_004450F0();
void func_0039EF28();
void func_L01_00456230();
void func_003A52A0(s32, s32);
f32 func_00382538(char *, s32);
void func_L01_00511A40(f32);
void func_L01_00446780(char *, char *, s32, s32, s32, s32, f32, f32, f32);
void func_L03_003A2BB8();
void func_L03_003A2A10();
void func_L03_003A2790();
s32 func_L01_00511A98();
void func_L01_005003D0();
void func_L03_003A1B70();
void func_L01_004AAC98();

void func_L03_003A2398(char *arg0) {
    char *p = *(char **)(arg0 + 0x68);
    f32 f;
    if (func_0038CB00(p + 0x24) != 0) {
        *(s16 *)(p + 0x24) = 50;
    }
    f = func_0038D0B0((f32)*(s16 *)(p + 0x24) * 6.2831855f / 50.0f);
    *(s32 *)(arg0 + 0x78) = func_0038DBD8(f * 0.5f + 0.5f, 0x80B0B0B0, 0x80505050);
    switch (*(u8 *)(arg0 + 0x20)) {
    case 0:
        func_L02_003BAAB0(D_001A71A0[0], D_L03_002A1420);
        func_L01_004450F0(arg0, 2, -1);
        break;
    case 1:
        break;
    case 2:
        if (D_001A4BE0.flag != 0 && D_001A4BE0.owner == arg0) {
            if (func_L01_004BA800() == 0) {
                func_L01_004450F0(arg0, 3, -1);
            }
        }
        break;
    case 3:
        func_L01_00452560(0, 12, 0xA27, 1, 0, 0, 0);
        if (D_001A4BE0.flag == 0 || D_001A4BE0.owner != arg0) {
            func_L01_004450F0(arg0, 2, -1);
        }
        if (D_L03_002D09B0[0] == 12) {
            char *s = D_001D52FC;
            if (*(s32 *)(s + 0x1A4) & 0x10) {
                D_00142765[0] = 1;
                func_0039EF28();
                if ((D_00142C1C[0] & 0x40000000) == 0) {
                    char *r = (char *)D_L03_001DF99C + (*(s32 *)(p + 8) << 8);
                    func_L01_00456230(r, 1, arg0);
                    *(u8 *)(r + 0x30) = 0xFF;
                    (*(void (**)(char *))(r + 0x64))(r);
                    func_L01_004450F0(arg0, 2, -1);
                } else {
                    f32 g;
                    f32 one = 1.0f;
                    func_003A52A0(0, 0);
                    *(u16 *)(D_001A4BE0.cur + 0x34) |= 0x2000;
                    g = func_00382538(arg0 + 0x10, 0);
                    *(f32 *)(p + 0x18) = g;
                    *(f32 *)(p + 0x10) = 0.3f;
                    *(f32 *)(p + 0x14) = 0.034906585f;
                    *(f32 *)(p + 0x20) = 0.8f;
                    *(f32 *)(p + 0x1C) = 0.8f;
                    *(f32 *)(p + 0xC) = one;
                    func_L01_00511A40(*(f32 *)(arg0 + 0xF8));
                    func_L01_00446780(arg0, arg0 + 0x10, 0x10000, 0, 1, 0, 1.5f, 20.0f, one);
                    func_L01_004450F0(arg0, 4, -1);
                }
            }
        }
        break;
    case 4:
        func_L03_003A2BB8(arg0);
        func_L03_003A2A10(-1);
        func_L03_003A2790(arg0, D_001DE3F0_sda);
        *(u16 *)(arg0 + 0x34) &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(char **)(arg0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(char **)(arg0 + 0x24) + 0x10);
        if (func_L01_00511A98() == 2) {
            func_L01_005003D0(0x74, 1);
            func_L01_004450F0(arg0, 5, -1);
        }
        break;
    case 5: {
        char *q;
        *(u16 *)(arg0 + 0x34) &= 0xFFBE;
        *(u16 *)(arg0 + 0x34) |= *(u16 *)(*(char **)(arg0 + 0x24) + 0x44) & 0x1000;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(*(char **)(arg0 + 0x24) + 0x10);
        q = D_001A4BE0.cur;
        if ((u8)q[0x23] < 0xD) {
            func_L03_003A2A10(-1);
            func_L03_003A2790(arg0, D_001DE3F0_sda);
            func_L03_003A2BB8(arg0);
        } else {
            char *w = (char *)D_001DF99C_sda + (*(s32 *)p << 8);
            *((u8 *)&D_001A4BE0 + 0x25E5) = 1;
            func_L03_003A1B70(w, 1);
            func_L01_004AAC98(1, 0, w, 0x19CD);
            func_L01_004450F0(arg0, 2, -1);
        }
        break;
    }
    }
}
/* localdecomp:end func_L03_003A2398 */
