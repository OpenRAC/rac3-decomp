/* near miss (level 3, Starship Phoenix): 1 real difference (check.py counts 63 because the missing nop shifts every later line): all eight cases of the jump-table switch are in retail order (case 1 empty, case 3 falling into case 4, shared tails with goto); retail has `bnez $v0, end; nop` before the shared ECA0(a,8) tail, the C puts `move $a0,$s0` in that delay slot; five structural variants (goto, label placement, duplicated call, done-label) tried; its jump table must also be adjacent to the file's other C tables */
#include "common.h"

/* localdecomp:start func_L03_0039E470 */
s32 func_L01_004561B8(void *);
s32 func_0038CB00(void *);
void func_L01_0045A9F0(void *);
s32 func_L01_00454370(void *, void *);
s32 func_L03_0032D598(s32, void *);
s32 func_L03_0032D640(s32, void *);
s32 func_00382468(s32);
void func_L01_00451DF8(void *, void *, s32, s32, f32);
void func_L03_0039E748(void *);
void func_L03_0039E8F0(void *);
void func_L03_0039EE10(void *, f32);
s32 func_L03_0039EEE8(void *);
void func_L03_0039ECA0(void *, s32);

typedef struct {
    u8 pad0[0x70]; u8 a70[0xD4]; s16 s144; u8 pad146[0x250 - 0x146]; s32 i250;
    u8 pad254[0x268 - 0x254]; s16 s268; u8 pad26A[0x270 - 0x26A]; u8 a270[0x3C];
    u8 pad2AC[0x300 - 0x2AC]; u8 *p300; u8 pad304[5]; u8 b309; s16 s30A; f32 f30C; u8 b310;
} P_0039E470;

void func_L03_0039E470(u8 *a) {
    P_0039E470 *q;
    func_L03_0039E748(a);
    func_L03_0039E8F0(a);
    q = *(P_0039E470 **)(a + 0x68);
    switch (a[0x20]) {
    case 1:
        break;
    case 2:
        if (func_L01_004561B8(a)) {
            q->f30C = 1.0f / q->s268;
        }
        a[0x23] = (1.0f - q->f30C * q->s268) * 128.0f;
        if (func_0038CB00(&q->s268)) {
            a[0x23] = 0x80;
            func_L03_0039ECA0(a, 3);
        }
        if (q->p300 != 0) {
            q->p300[0x23] = a[0x23];
        }
        break;
    case 3:
        func_L01_0045A9F0(a);
        func_L03_0039ECA0(a, 5);
    case 4:
        if (func_L01_00454370(a, q->a70) & 2) {
            func_L03_0039ECA0(a, 5);
        }
        break;
    case 5:
        func_L01_0045A9F0(a);
        if (func_0038CB00(&q->s30A)) {
            if (q->s144 == 1) {
                if (func_L03_0032D598(q->i250, a) != 0) goto l6b8;
                goto l670;
            }
        }
        break;
    case 6:
        if (q->p300 != 0) {
            if (q->b309 < 255) q->b309++;
            if (func_L03_0039EEE8(a)) q->b310 = 1;
        }
        func_L03_0039EE10(a, 3.0f);
        if (q->b310 != 0 && q->b309 >= 25) func_L03_0039ECA0(a, 7);
        if (q->s144 != 1) {
            func_L03_0032D640(q->i250, a);
            func_L03_0039ECA0(a, 5);
        } else if (func_L03_0032D598(q->i250, a) == 0) {
l670:
            func_L03_0039ECA0(a, 8);
        }
        break;
    case 7:
        func_L03_0039EE10(a, 3.0f);
        if (a[0x60] & 2) {
            q->s30A = func_00382468(25) + 50;
l6b8:
            func_L03_0039ECA0(a, 6);
        }
        break;
    case 8:
        func_L03_0039EE10(a, 5.0f);
        if (q->s144 != 1) {
            func_L03_0039ECA0(a, 5);
        } else if (func_L03_0032D598(q->i250, a)) {
            func_L03_0039ECA0(a, 6);
        }
        break;
    }
    func_L01_00451DF8(a, q->a270, 2, 1, 1.5f);
}
/* localdecomp:end func_L03_0039E470 */
