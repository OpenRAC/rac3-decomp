#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006D4ED8);

INCLUDE_ASM("asm/levels", func_L39_006D50F0);

INCLUDE_ASM("asm/levels", func_L39_006D5208);

INCLUDE_ASM("asm/levels", func_L39_006D5238);

INCLUDE_ASM("asm/levels", func_L39_006D52D0);

INCLUDE_ASM("asm/levels", func_L39_006D5440);

INCLUDE_ASM("asm/levels", func_L39_006D5460);

INCLUDE_ASM("asm/levels", func_L39_006D55C0);

INCLUDE_ASM("asm/levels", func_L39_006D55E0);

INCLUDE_ASM("asm/levels", func_L39_006D59D8);

INCLUDE_ASM("asm/levels", func_L39_006D5AB8);

INCLUDE_ASM("asm/levels", func_L39_006D5B40);

INCLUDE_ASM("asm/levels", func_L39_006D5B68);

INCLUDE_ASM("asm/levels", func_L39_006D5B88);

INCLUDE_ASM("asm/levels", func_L39_006D5BF0);

/* localdecomp:start func_L39_006D5CE0 */
s32 func_12DCB0(void *);
long func_130760(s32, long);
void func_L39_006D5D68(void *);

s32 func_L39_006D5CE0(u8 *arg0) {
    s32 ret = 1;

    if (arg0[0] != 0) {
        if (arg0[8] != 0) {
            s32 t = func_130760(func_12DCB0(arg0), 0x24000);

            if (t - *(s32 *)(arg0 + 0xC) >= 0x3A99) {
                arg0[8] = 0;
                func_L39_006D5D68(arg0);
                ret = 0;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006D5CE0 */

INCLUDE_ASM("asm/levels", func_L39_006D5D68);

INCLUDE_ASM("asm/levels", func_L39_006D5DF8);

INCLUDE_ASM("asm/levels", func_L39_006D6210);

INCLUDE_ASM("asm/levels", func_L39_006D6378);

INCLUDE_ASM("asm/levels", func_L39_006D6398);

INCLUDE_ASM("asm/levels", func_L39_006D6500);

INCLUDE_ASM("asm/levels", func_L39_006D6520);

INCLUDE_ASM("asm/levels", func_L39_006D6548);

INCLUDE_ASM("asm/levels", func_L39_006D6568);

INCLUDE_ASM("asm/levels", func_L39_006D65D0);

INCLUDE_ASM("asm/levels", func_L39_006D66B8);

INCLUDE_ASM("asm/levels", func_L39_006D6750);

INCLUDE_ASM("asm/levels", func_L39_006D6808);

INCLUDE_ASM("asm/levels", func_L39_006D6868);

INCLUDE_ASM("asm/levels", func_L39_006D68C0);

INCLUDE_ASM("asm/levels", func_L39_006D6CF8);

/* localdecomp:start func_L39_006D6E30 */
void func_00196510(s32, s32);

void func_L39_006D6E30(s32 arg0, s32 arg1, s32 arg2) {
    func_00196510(arg1, arg2);
}
/* localdecomp:end func_L39_006D6E30 */

/* localdecomp:start func_L39_006D6E50 */
void func_00196D08(s32, s32, s32);

void func_L39_006D6E50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00196D08(arg1, arg2, arg3);
}
/* localdecomp:end func_L39_006D6E50 */

INCLUDE_ASM("asm/levels", func_L39_006D6E78);

INCLUDE_ASM("asm/levels", func_L39_006D6F60);

INCLUDE_ASM("asm/levels", func_L39_006D6F80);

INCLUDE_ASM("asm/levels", func_L39_006D7018);

INCLUDE_ASM("asm/levels", func_L39_006D7138);

INCLUDE_ASM("asm/levels", func_L39_006D7810);

INCLUDE_ASM("asm/levels", func_L39_006D7838);

INCLUDE_ASM("asm/levels", func_L39_006D78B8);

INCLUDE_ASM("asm/levels", func_L39_006D78F8);

INCLUDE_ASM("asm/levels", func_L39_006D7930);

/* localdecomp:start func_L39_006D8060 */
extern s32 D_0022F280[];
void func_11D534(s32 *, s32, s32);
void func_1974D8(s32);
void func_L39_006D8938(void *);
void func_L01_004D3BD0(void *);

void func_L39_006D8060(void *arg0, s32 arg1) {
    func_11D534(D_0022F280, 0, 0x148);
    func_1974D8(0);
    func_L39_006D8938(arg0);
    if (arg1 & 1) {
        func_L01_004D3BD0(arg0);
    }
}
/* localdecomp:end func_L39_006D8060 */

INCLUDE_ASM("asm/levels", func_L39_006D80C8);

/* localdecomp:start func_L39_006D80F8 */
void func_L39_006CCC88(s32);
void func_L39_006CD568(s32);
void func_L39_006CDF38(s32);
void func_L39_006D3490(s32);
void func_L39_006D5208(s32);
void func_L39_006D5B68(s32);
void func_L39_006D6548(s32);
void func_L39_006D6F60(s32);
void func_L39_006D80C8();
void func_L39_006D9318(s32);
void func_L39_006DA038(s32);
void func_L39_006DC7A8(s32);
void func_L39_006DD438(s32);

void func_L39_006D80F8(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;

    func_L39_006D80C8();
    func_L39_006CCC88((*(s32 *)((u8 *)arg0 + 0x30)));
    func_L39_006CD568((*(s32 *)((u8 *)arg0 + 0x34)));
    func_L39_006CDF38((*(s32 *)((u8 *)arg0 + 0x38)));
    temp_a0 = *(s32 *)((u8 *)arg0 + 0x70);
    if (temp_a0 != 0) {
        func_L39_006D5208(temp_a0);
    }
    func_L39_006D3490((*(s32 *)((u8 *)arg0 + 0x3C)));
    func_L39_006D5B68((*(s32 *)((u8 *)arg0 + 0x40)));
    func_L39_006D6548((*(s32 *)((u8 *)arg0 + 0x44)));
    temp_a0_2 = *(s32 *)((u8 *)arg0 + 0x78);
    if (temp_a0_2 != 0) {
        func_L39_006D6F60(temp_a0_2);
    }
    func_L39_006D9318((*(s32 *)((u8 *)arg0 + 0x48)));
    func_L39_006DA038((*(s32 *)((u8 *)arg0 + 0x4C)));
    func_L39_006DC7A8((*(s32 *)((u8 *)arg0 + 0x50)));
    func_L39_006DD438((*(s32 *)((u8 *)arg0 + 0x54)));
}
/* localdecomp:end func_L39_006D80F8 */

/* localdecomp:start func_L39_006D8198 */
s32 func_L01_00521C90(s32, s32);
s32 func_L39_006D6E78(s32, s32, s32);
s32 func_L39_006D6F80(s32);

s32 func_L39_006D8198(void *arg0, s32 arg1) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x7C)) == 0) {
        temp_s0 = func_L39_006D6F80((*(s32 *)((u8 *)arg0 + 0x2C)));
        *(s32 *)((u8 *)arg0 + 0x78) = func_L39_006D6E78(func_L01_00521C90(0x28, (*(s32 *)((u8 *)arg0 + 0x2C))), temp_s0, arg1);
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_s0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_s0);
        *(u8 *)((u8 *)arg0 + 0x7C) = 1U;
    }
    return (*(s32 *)((u8 *)arg0 + 0x78));
}
/* localdecomp:end func_L39_006D8198 */

/* localdecomp:start func_L39_006D8228 */
s32 func_L01_00521C90(s32, s32);
s32 func_L39_006D50F0(s32, s32, s32);
s32 func_L39_006D5238(s32);

s32 func_L39_006D8228(void *arg0, s32 arg1) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x74)) == 0) {
        temp_s0 = func_L39_006D5238((*(s32 *)((u8 *)arg0 + 0x2C)));
        *(s32 *)((u8 *)arg0 + 0x70) = func_L39_006D50F0(func_L01_00521C90(0x4C, (*(s32 *)((u8 *)arg0 + 0x2C))), temp_s0, arg1);
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_s0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_s0);
        *(u8 *)((u8 *)arg0 + 0x74) = 1U;
    }
    return (*(s32 *)((u8 *)arg0 + 0x70));
}
/* localdecomp:end func_L39_006D8228 */

/* localdecomp:start func_L39_006D82B8 */
s32 func_L39_006DD468(s32);
void func_L39_006DD4D0(s32, s32, s32, s32);

void func_L39_006D82B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x58)) == 0) {
        temp_v0 = func_L39_006DD468((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006DD4D0((*(s32 *)((u8 *)arg0 + 0x54)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x58) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D82B8 */

/* localdecomp:start func_L39_006D8338 */
s32 func_L39_006CD588(s32);
void func_L39_006CD5F0(s32, s32, s32, s32);

void func_L39_006D8338(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x59)) == 0) {
        temp_v0 = func_L39_006CD588((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CD5F0((*(s32 *)((u8 *)arg0 + 0x34)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x59) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8338 */

/* localdecomp:start func_L39_006D83B8 */
s32 func_L39_006D5B88(s32);
void func_L39_006D5BF0(s32, s32, s32, s32);

void func_L39_006D83B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x61)) == 0) {
        temp_v0 = func_L39_006D5B88((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006D5BF0((*(s32 *)((u8 *)arg0 + 0x40)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x61) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D83B8 */

/* localdecomp:start func_L39_006D8438 */
s32 func_L39_006D6568(s32);
void func_L39_006D65D0(s32, s32, s32, s32);

void func_L39_006D8438(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x62)) == 0) {
        temp_v0 = func_L39_006D6568((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006D65D0((*(s32 *)((u8 *)arg0 + 0x44)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x62) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8438 */

/* localdecomp:start func_L39_006D84B8 */
s32 func_L39_006CE000(s32);
void func_L39_006CE068(s32, s32, s32, s32);

void func_L39_006D84B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5A)) == 0) {
        temp_v0 = func_L39_006CE000((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE068((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5A) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D84B8 */

/* localdecomp:start func_L39_006D8538 */
s32 func_L39_006CE150(s32);
void func_L39_006CE1B8(s32, s32, s32, s32);

void func_L39_006D8538(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5B)) == 0) {
        temp_v0 = func_L39_006CE150((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE1B8((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5B) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8538 */

/* localdecomp:start func_L39_006D85B8 */
s32 func_L39_006CE2A0(s32);
void func_L39_006CE308(s32, s32, s32, s32);

void func_L39_006D85B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5C)) == 0) {
        temp_v0 = func_L39_006CE2A0((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE308((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5C) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D85B8 */

/* localdecomp:start func_L39_006D8638 */
s32 func_L39_006CE3F0(s32);
void func_L39_006CE458(s32, s32, s32, s32);

void func_L39_006D8638(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5D)) == 0) {
        temp_v0 = func_L39_006CE3F0((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE458((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5D) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8638 */

/* localdecomp:start func_L39_006D86B8 */
s32 func_L39_006CE540(s32);
void func_L39_006CE5A8(s32, s32, s32, s32);

void func_L39_006D86B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5E)) == 0) {
        temp_v0 = func_L39_006CE540((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE5A8((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5E) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D86B8 */

/* localdecomp:start func_L39_006D8738 */
s32 func_L39_006CE690(s32);
void func_L39_006CE6F8(s32, s32, s32, s32);

void func_L39_006D8738(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5F)) == 0) {
        temp_v0 = func_L39_006CE690((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE6F8((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5F) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8738 */

/* localdecomp:start func_L39_006D87B8 */
s32 func_L39_006CE7E0(s32);
void func_L39_006CE848(s32, s32, s32, s32);

void func_L39_006D87B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x60)) == 0) {
        temp_v0 = func_L39_006CE7E0((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE848((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x60) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D87B8 */

/* localdecomp:start func_L39_006D8838 */
s32 func_L39_006DA158(s32);
void func_L39_006DA1C0(s32, s32, s32, s32);

void func_L39_006D8838(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x63)) == 0) {
        temp_v0 = func_L39_006DA158((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006DA1C0((*(s32 *)((u8 *)arg0 + 0x4C)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x63) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8838 */

/* localdecomp:start func_L39_006D88B8 */
s32 func_L39_006DA2A8(s32);
void func_L39_006DA310(s32, s32, s32, s32);

void func_L39_006D88B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x64)) == 0) {
        temp_v0 = func_L39_006DA2A8((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006DA310((*(s32 *)((u8 *)arg0 + 0x4C)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x64) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D88B8 */

INCLUDE_ASM("asm/levels", func_L39_006D8938);

/* localdecomp:start func_L39_006D8AD8 */
extern s32 func_001961F8(void *);
extern s32 func_0012DCB0(void);
extern long func_00130760(s32, long);

s32 func_L39_006D8AD8(u8 *arg0) {
    s32 r = 1;
    s32 v;
    s32 diff;

    if (func_001961F8(arg0) != 0) {
        v = 8;
    } else {
        if (*(u8 *)((u8 *)arg0 + 0x1) == 0) {
            goto done;
        }
        if (*(s32 *)((u8 *)arg0 + 0x8) == 0) {
            goto done;
        }
        if (*(s32 *)((u8 *)arg0 + 0xC) <= 0) {
            goto done;
        }
        diff = (s32)func_00130760(func_0012DCB0(), 0x24000) - *(s32 *)((u8 *)arg0 + 0x8);
        if (*(s32 *)((u8 *)arg0 + 0xC) < diff) {
            v = 2;
        } else {
            goto done;
        }
    }
    *(s32 *)((u8 *)arg0 + 0x10) = v;
    if (*(s32 *)((u8 *)arg0 + 0x14) == 0) {
        *(s32 *)((u8 *)arg0 + 0x14) = v;
    }
    r = 0;
done:
    return r;
}
/* localdecomp:end func_L39_006D8AD8 */

INCLUDE_ASM("asm/levels", func_L39_006D8B88);

/* localdecomp:start func_L39_006D8D80 */
extern u8 D_198028[];
extern u8 D_198050[];
extern u8 D_198078[];
extern u8 D_1A5CD0[];

s32 func_17DE30(void *, void *);
s32 func_1961E8(s32);
s32 func_1961F8(void);
void func_19B6D8(s32);
void func_19B5B8(s32);

s32 func_L39_006D8D80(void *arg0) {
    s32 loc[16];
    u8 *p;
    s32 v;

    loc[0] = (s32)D_198028;
    loc[4] = 0;
    loc[6] = (s32)D_198050;
    loc[8] = (s32)D_198078;
    func_1961E8(func_17DE30(loc, &loc[12]));
    if (func_1961F8() != 0) {
        v = *(s32 *)((u8 *)arg0 + 0x14);
        *(s32 *)((u8 *)arg0 + 0x10) = 5;
        if (v == 0) {
            *(s32 *)((u8 *)arg0 + 0x14) = 5;
        }
        return 0;
    }
    p = D_1A5CD0;
    *(u8 *)(p + 0x2E6) = 0;
    *(s32 *)(p + 0x2E8) = 0;
    *(u8 *)(p + 0x2E4) = 1;
    func_19B6D8(1);
    func_19B5B8(-1);
    return 1;
}
/* localdecomp:end func_L39_006D8D80 */

INCLUDE_ASM("asm/levels", func_L39_006D8E30);
