/* near miss (level 3, Starship Phoenix): 6 differences: the jump table (cases 0,2,4,3,5 in retail block order, case 1 and default sharing a tail through gotos) and the lui forms match; in three beq delay-slot groups retail emits `move $a0` before `addiu $a1,N`, the C the reverse; two alias externs for the same $gp slot are needed or gcc cross-jumps the two calls; a different argument variable, typed prototype and moving the assignment did not change it */
#include "common.h"

/* localdecomp:start func_L03_003B28D0 */
typedef struct S_003B28D0 { char pad[0x128]; s32 f128; s32 f12C; } S_003B28D0;
typedef struct O_003B28D0 { char p0[0x20]; u8 k20; char p1[0x10]; u8 k31; char p2[2]; u16 f34; char p3[0x0D]; u8 k43; char p4[0x1C]; u8 k60; char p5[7]; S_003B28D0 *p68; } O_003B28D0;
extern u8 D_00142CBE[];
__asm__(".extern D_00142CBE, 16");
extern s32 D_L03_001D6694;
__asm__(".extern D_L03_001D6694, 16");
extern s32 D_001D6694_sda_003B28D0;
extern s32 D_001D6694_sdb_003B28D0;
__asm__(".extern D_001D6694_sdb_003B28D0, 4");
__asm__(".extern D_001D6694_sda_003B28D0, 4");
void func_003C3A10();
void func_L01_004450F0();
void func_003C2880();
s32 func_L01_004561B8();
s32 func_00382498();
s32 func_0038CAD0();
s32 func_L01_004BA800();
void func_L03_003B2B30();

void func_L03_003B28D0(O_003B28D0 *o) {
    S_003B28D0 *p = o->p68;
    s32 v;
    s32 r;
    switch (o->k20) {
    case 0:
        if (p->f12C != 0 || D_00142CBE[0] == 0) {
            if (o->k43 != 1) func_003C3A10(o, 1, 0, 8);
            func_L01_004450F0(o, 2, -1);
            goto c2;
        } else {
            func_003C2880(o);
            return;
        }
    case 2:
    c2:
        if (func_L01_004561B8(o) != 0) {
            if (o->k43 != 1) func_003C3A10(o, 1, 0, 8);
            r = func_00382498(0x226, 0x352);
            p->f128 = (r * 5 + 2) / 6;
        }
        if (func_0038CAD0(&p->f128) != 0) {
            r = func_00382498(0x226, 0x352);
            p->f128 = (r * 5 + 2) / 6;
            if (o->k43 == 2) goto def;
            r = 2;
            goto call11;
        } else {
            if ((o->k60 & 2) == 0) goto def;
            if (o->k43 == 1) goto def;
            r = 1;
        call11:
            func_003C3A10(o, r, 0, 0x11);
        }
        v = D_001D6694_sdb_003B28D0;
        goto tail;
    case 4:
        if (func_L01_004561B8(o) == 0) goto def;
        if (o->k43 == 3) goto def;
        r = 3;
        goto call8;
    case 3:
        if (func_L01_004561B8(o) == 0) goto def;
        if (o->k43 == 4) goto def;
        r = 4;
    call8:
        func_003C3A10(o, r, 0, 8);
        v = D_001D6694_sda_003B28D0;
        goto tail;
    case 5:
        if (func_L01_004561B8(o) == 0) goto def;
        if (o->k43 == 5) goto def;
        func_003C3A10(o, 5, 0, 8);
    default:
    case 1:
    def:
        v = D_L03_001D6694;
    tail:
        if (v == 2) {
            o->k31 = 0;
            o->f34 |= 1;
        } else {
            if (func_L01_004BA800() == 0) {
                o->k31 = 1;
                o->f34 &= 0xFFFE;
            }
            func_L03_003B2B30(o);
        }
    }
}
/* localdecomp:end func_L03_003B28D0 */
