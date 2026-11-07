/* Level 01. 6 diff (one instruction position): retail emits "ori $v0,$v0,0x8ef7" (finishing 0x388EF7) after "sw $a1,0x30($sp)", right before "sw $v0,0x40($sp)"; this C emits it earlier. Default level flags. Needs the .extern D_001E001C, 16 hint. */
#include "common.h"
extern void func_004AA878(s32);
extern void func_004AABF0(s32, s32, void *);
extern void func_L01_003B0D48(void *);
extern void func_L01_003B0BD8(void *);
extern void func_00439300(void *);
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
typedef struct { u8 p[0x80]; } E80;
extern E80 D_001A30B0[];
extern u8 *D_0021DE20[];
extern u8 *D_001E001C;
__asm__(".extern D_001E001C, 16");
extern u8 *D_001E001C_sda;
extern s32 D_001E0058_sda;
void func_L01_003B1128(u8 *o) {
    u8 *u = *(u8 **)(o + 0x68);
    s32 i = *(s32 *)(u + 0x334);
    s32 n;
    s16 *p;
    if (i != -1) {
        u8 *e = (u8 *)&D_001A30B0[i];
        if (*(u8 **)(e + 0xDC) == o && *(e + 0xD0) != 0) {
            func_004AA878(i);
        }
    }
    n = -1;
    *(s32 *)(u + 0x334) = n;
    func_004AABF0(4, 0, o);
    *(s32 *)(o + 0x98) = 0;
    func_L01_003B0D48(o);
    if (*(s32 *)(u + 0x2E0) != n) {
        func_00439300(D_001E001C_sda + *(s32 *)(u + 0x2E0) * 256);
    }
    p = (s16 *)D_0021DE20[*(s32 *)(u + 0x2E4)];
    while ((*(s32 *)(u + 0x2E4) & 0xFF) != 0xFF && D_001E0058_sda >= *(s32 *)(u + 0x2E4) && p != 0
           && (p[-1] >= 0 || (u8 *)p == D_0021DE20[*(s32 *)(u + 0x2E4)])) {
        u8 *q = D_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
        if (q == 0) break;
        p += 1;
        func_00439300(q);
    }
    func_L01_003B0BD8(o);
    func_L01_003303B8(o + 16, 0, 25, 20, 20, 20, 20, 0, 1.25f, 0.0f, 10.0f, 5.0f,
                      0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    func_00439300(o);
}
