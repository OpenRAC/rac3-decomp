#include "common.h"

/* localdecomp:start func_L39_005F1470 */
typedef struct { s32 cur[8]; s32 prev[8]; u8 pad40[0x1B20 - 0x40]; s32 f1B20; } S_005F1470;
extern u8 D_001FE020[];
extern s32 D_001A5810[];
extern void func_0038CD28(void *, void *, s32);

void func_L39_005F1470(void) {
    s32 i;
    func_0038CD28(((S_005F1470 *)D_001FE020)->prev, ((S_005F1470 *)D_001FE020)->cur, 0x20);
    ((S_005F1470 *)D_001FE020)->cur[0] = D_001A5810[4] * 7 / 10;
    ((S_005F1470 *)D_001FE020)->cur[1] = D_001A5810[3];
    ((S_005F1470 *)D_001FE020)->cur[2] = D_001A5810[4];
    ((S_005F1470 *)D_001FE020)->cur[3] = D_001A5810[4] * 6 / 10;
    ((S_005F1470 *)D_001FE020)->cur[4] = D_001A5810[4] * 6 / 10;
    ((S_005F1470 *)D_001FE020)->cur[5] = D_001A5810[4] * 25 / 32;
    {
        s32 *p = ((S_005F1470 *)D_001FE020)->prev;
        s32 *q = ((S_005F1470 *)D_001FE020)->cur;
        for (i = 0; i < 6; i++) {
            s32 bit = 1;
            if (*p++ == *q++) {
                bit = 0;
            }
            ((S_005F1470 *)D_001FE020)->f1B20 |= bit << i;
        }
    }
}
/* localdecomp:end func_L39_005F1470 */

/* localdecomp:start func_L39_005F1560 */
#include "vu0.h"
typedef struct { s32 a; s32 b; s32 c; s32 d; s32 e; } S_005F1560;
extern u8 D_001FE020[];
extern s32 D_001A5810[];
extern void func_00193368(s32);
extern void func_00193C60(s32);
extern void func_00193CE8(s32);
extern void func_00193CA8(s32, s32, s32);
extern void func_00193BB0(s32, s32);
extern void func_00193BE8(s32, S_005F1560 *);
extern void func_003A5620(void);
extern void func_L39_005F1470(void);

void func_L39_005F1560(void) {
    s32 i;
    S_005F1560 sp;
    for (i = 0; i < 4; i++) {
        qzero(D_001FE020 + 0x50 + i * 16);
    }
    {
        u8 *p = D_001FE020;
        u8 *q;
        *(s32 *)(p + 0x48) = 0;
        *(s32 *)(p + 0x4C) = 0;
        q = p;
        for (i = 0; i < 52; i++) {
            *(s32 *)(q + 0xC0) = 0;
            *(u8 *)(q + 0xD0) = 0;
            q += 0x80;
        }
    }
    func_00193368(2);
    func_00193C60(D_001A5810[2] == 0);
    func_00193CE8(1);
    func_00193CA8(1, 0x18, 0x2F);
    func_00193CA8(2, 0x18, 0x2F);
    func_00193CA8(4, 0x18, 0x2F);
    func_00193CA8(5, 0x18, 0x2F);
    func_00193CA8(6, 0x18, 0x2F);
    func_L39_005F1470();
    func_00193BB0(0, *(s32 *)D_001FE020);
    func_00193BB0(1, *(s32 *)(D_001FE020 + 4));
    func_00193BB0(2, *(s32 *)(D_001FE020 + 8));
    func_00193BB0(3, *(s32 *)(D_001FE020 + 0xC));
    func_00193BB0(4, *(s32 *)(D_001FE020 + 0x10));
    func_00193BB0(5, *(s32 *)(D_001FE020 + 0x14));
    func_00193BB0(6, *(s32 *)(D_001FE020 + 8));
    sp.a = 6;
    sp.b = 0x3B;
    sp.c = 0x6666;
    sp.d = 0x8000;
    sp.e = 0x8000;
    func_00193BE8(0, &sp);
    func_003A5620();
}
/* localdecomp:end func_L39_005F1560 */

/* localdecomp:start func_L39_005F16F0 */
void func_00194C08(s32, s32);
extern s32 D_001F83AC[];

void func_L39_005F16F0(void) {
    func_00194C08(2, D_001F83AC[0]);
}
/* localdecomp:end func_L39_005F16F0 */

INCLUDE_ASM("asm/levels", func_L39_005F1718);

INCLUDE_ASM("asm/levels", func_L39_005F26E8);

/* localdecomp:start func_L39_005F2FA0 */
extern u8 D_001FE020[];

s32 func_L39_005F2FA0(s32 arg0, s32 arg1) {
    u8 temp_a0;
    void *temp_v0;

    if (arg1 >= 0) {
        temp_v0 = (arg1 << 7) + D_001FE020;
        if (((*(s32 *)((u8 *)temp_v0 + 0xDC)) == arg0) && ((temp_a0 = (*(u8 *)((u8 *)temp_v0 + 0xD0)), (((u32) (temp_a0 - 1) < 2U) != 0)) || (temp_a0 == 7))) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_005F2FA0 */
