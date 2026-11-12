/* near miss (level 3, Starship Phoenix): 23 differences, register choices only (default assembler; the instruction sequence is retail's): retail keeps the entry pointer e in $a2 and the flag value v in $a3 (i's register while i is dead in case 1), the C puts e in $a3 and v in $a0, and in case 0 retail builds the 0x18 stride in $v1 where the C uses $v0. What got it from 91 to 23: a while loop (retail's duplicated exit test carries the %hi of D_L03_002EBD18 into the loop top), one flag value stored once per case (reorg copies the store into a beql slot), the $gp global read once before the inner loop, a separate mask statement (sllv/and instead of srav/andi), D_00142693 through %hi/%lo, j = 0 before the inner test, and e as a pointer (array indexing everywhere gives retail's registers but an extra copy of e before the inner loop, whose .p2align then pads a nop: 91). Tried: statement order of case 1 (12 orders), declaration orders, the || expression form, for loops reading the global directly. */
#include "common.h"

typedef struct {
    s32 p0;
    s32 pad4;
    s32 pad8;
    u32 *list;
    u32 type;
    u8 flag;
    u8 pad15[3];
} S_0048B918;
extern S_0048B918 D_L03_002EBD18[];
extern s32 D_00142BA0[];
extern u8 D_00142693 __attribute__((section(".data")));
extern s32 D_001D9518;
__asm__(".extern D_001D9518, 4");
void func_L03_0048B918(void) {
    s32 i = 0;
    s32 n;
    s32 j;
    s32 g;
    s32 m;
    u32 id;
    S_0048B918 *e;
    while (D_L03_002EBD18[i].p0 != 0) {
        switch (D_L03_002EBD18[i].type) {
        case 1:
            e = &D_L03_002EBD18[i];
            e->flag = 1;
            n = i + 1;
            j = 0;
            if (D_L03_002EBD18[i].list[0] != 0) {
                g = D_001D9518;
                do {
                    s32 v = 0;
                    if (e->flag != 0) {
                        id = D_L03_002EBD18[i].list[j];
                        m = 1 << (id & 0x1F);
                        if (D_00142BA0[id >> 2] & m) goto set1;
                    }
                    if (g != 0) {
                    set1:
                        v = 1;
                    }
                    e->flag = v;
                    j++;
                } while (D_L03_002EBD18[i].list[j] != 0);
            }
            break;
        case 0:
        case 2:
            id = (u32)D_L03_002EBD18[i].list;
            m = 1 << (id & 0x1F);
            D_L03_002EBD18[i].flag = (D_00142BA0[id >> 2] & m) || D_001D9518 != 0;
            n = i + 1;
            break;
        case 3:
            D_L03_002EBD18[i].flag = D_00142693 != 0 || D_001D9518 != 0;
            n = i + 1;
            break;
        case 4:
        default:
            D_L03_002EBD18[i].flag = 1;
            n = i + 1;
            break;
        }
        i = n;
    }
}
