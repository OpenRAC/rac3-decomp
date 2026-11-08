/* near miss (level 3, Starship Phoenix): 29 differences, all in the last stretch: retail fills the delay slot of the beqz after func_L03_0032F660 with `addiu $v0,$s4,lo(D_001A4BE0)`, reloads lbu 0xF1 in the then-arm and sets v0=9 in the else-arm; the C puts `addiu $a0,9` there and never hoists the base address; ternary, if/else in both orders and a hoisted gp load tried */
#include "common.h"

/* localdecomp:start func_L03_0032CBD8 */
typedef struct S_0032CBD8 { u8 p0[0x1200]; s32 f1200; u8 p1[0x24]; s32 f1228; u8 p2[0x25CC-0x122C]; s32 f25CC; u8 p3[0x2824-0x25D0]; f32 f2824; u8 p4[0x28C9-0x2828]; u8 f28C9; } S_0032CBD8;
extern S_0032CBD8 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_L03_002AE4D0_0032CBD8[];
extern s32 D_001D4C38_sda;
__asm__(".extern D_001D4C38_sda, 4");
extern s32 D_L03_001D7C20;
__asm__(".extern D_L03_001D7C20, 16");
extern s32 D_L03_001DFA98;
__asm__(".extern D_L03_001DFA98, 16");
void func_L03_0032CE38(void *a);
s32 func_L01_004AAC98(s32 a, s32 b, void *c, s32 d);
void func_L03_00330380(void *a);
s32 func_0038CAD0(void *a);
void func_L03_0032D228(void *a);
void func_L01_00452560(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_L01_0044CD60(s32 a);
s32 func_L03_0032E0D8(void *a, s32 b);
void func_L01_00404808(void *a, void *b);
void func_L03_003307D0(void *a);
s32 func_L03_0032F660(void *a);
void func_L01_003F1760(void);

void func_L03_0032CBD8(u8 *arg0) {
    u8 *s3 = *(u8 **)(arg0 + 0x68);
    s32 v, q, r;
    func_L03_0032CE38(arg0);
    if ((u8)(arg0[0x20] - 5) < 4) {
        v = *(s32 *)(s3 + 0xEC);
        if (v != -1) {
            q = v / 50;
            r = v % 50;
            if (r == 0) {
                if (q == 5) func_L01_004AAC98(2, 0, arg0, 0x1936);
                else if (q == 4) func_L01_004AAC98(3, 0, arg0, 0x1936);
                else if (q == 3) func_L01_004AAC98(4, 0, arg0, 0x1936);
                else if (q == 2) func_L01_004AAC98(5, 0, arg0, 0x1936);
                else if (q == 1) func_L01_004AAC98(6, 0, arg0, 0x1936);
                func_L03_00330380(arg0);
            }
            if (func_0038CAD0(s3 + 0xEC)) {
                *(s32 *)(s3 + 0x104) = func_L01_004AAC98(6, 0, arg0, 0x1936);
                *(s32 *)(s3 + 0xEC) = 0x11;
                func_L03_0032D228(arg0);
            }
        }
    }
    if ((u8)(arg0[0x20] - 4) < 5) {
        
        u8 *t = D_L03_002AE4D0_0032CBD8 + s3[0xF1] * 0x28;
        if (*(s32 *)(t + 0x18) != -1) {
            func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
            if (D_001A4BE0.f1200 == 0 || D_001A4BE0.f1228 != *(s32 *)(t + 0x18)) {
                func_L01_0044CD60(*(s32 *)(t + 0x18));
                D_001A4BE0.f28C9 = 0;
            } else {
                D_001A4BE0.f28C9 = 1;
            }
            if (func_L03_0032E0D8(arg0, *(s32 *)(t + 0x18))) func_L03_0032D228(arg0);
        }
        D_001A4BE0.f2824 = 25.0f;
    }
    if (arg0[0x20] >= 2) func_L01_00404808(func_L03_003307D0, arg0);
    if (func_L03_0032F660(arg0)) {
        s32 w = D_001D4C38_sda;
        s32 k;
        if (s3[0xF1] >= 9) k = 9; else k = s3[0xF1];
        D_L03_001D7C20 = k;
        D_L03_001DFA98 = w;
    }
    if (D_001A4BE0.f25CC == 0x14 && s3[0xF5] == 0) {
        s3[0xF5] = 1;
        func_L01_003F1760();
    }
}
/* localdecomp:end func_L03_0032CBD8 */
