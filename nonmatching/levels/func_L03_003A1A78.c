/* near miss (level 3, Starship Phoenix): 2 differences: retail builds the last global read as `lui $v1,%hi(D_L03_00235A00); lw $v0,%lo($v1)`, the C puts the lui in $v0; hints 4/16, u32/u8 types, unsized array and callee return types give the same 2 (or worse) */
#include "common.h"

/* localdecomp:start func_L03_003A1A78 */
extern u8 D_00142CA0[];
extern u8 D_00142D40[];
__asm__(".extern D_00142D40, 16");
__asm__(".extern D_00142CA0, 16");
__asm__(".extern D_00142765, 16");
extern u8 D_00142765[];
extern s32 D_L03_00235A00;
__asm__(".extern D_L03_00235A00, 16");
extern f32 D_L03_001DF5B0;
typedef struct { u8 pad[0x20]; u8 f20; u8 pad2[0x47]; f32 *p68; } S_003A1A78;
void func_0039EF28(void);
void func_L03_0040F9E8(s32);
void func_L03_004F54E0(s32);
void func_L01_0044CD60(s32);
void func_L01_004450F0(void *, s32, s32);

void func_L03_003A1A78(S_003A1A78 *a) {
    u8 *t;
    if (a->f20 == 0) {
        a->p68[3] = D_L03_001DF5B0;
        t = D_00142CA0;
        if ((t[0xB] != 0 || t[0x14] != 0) && D_00142765[0] == 0) {
            t[0xB] = 0;
            D_00142D40[0xB] = 0;
            func_0039EF28();
            func_L03_0040F9E8(0xB);
            func_L03_004F54E0(0xB);
            t[0x14] = 0;
            D_00142D40[0x14] = 0;
            func_0039EF28();
            func_L03_0040F9E8(0x14);
            func_L03_004F54E0(0x14);
            func_L01_0044CD60(9);
            if (D_L03_00235A00 != 0) {
                func_L01_004450F0(a, 5, -1);
                return;
            }
        }
        func_L01_004450F0(a, 1, -1);
    }
}
/* localdecomp:end func_L03_003A1A78 */
