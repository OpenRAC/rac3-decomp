#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

INCLUDE_ASM("asm/levels", func_L39_0067FAE8);

INCLUDE_ASM("asm/levels", func_L39_0067FB28);

INCLUDE_ASM("asm/levels", func_L39_0067FB50);

INCLUDE_ASM("asm/levels", func_L39_0067FB80);

INCLUDE_ASM("asm/levels", func_L39_0067FBB0);

INCLUDE_ASM("asm/levels", func_L39_0067FBF0);

INCLUDE_ASM("asm/levels", func_L39_0067FC20);

INCLUDE_ASM("asm/levels", func_L39_0067FC50);

/* localdecomp:start func_L39_0067FCD8 */
s32 func_003E5360(s32);
s32 func_003E8630(s32, s32);
s32 func_L39_0067F1B0(void);
extern s32 D_001DBC5C;

void func_L39_0067FCD8(void *arg0) {
    s32 temp_v0;

    if ((*(s32 *)((u8 *)arg0 + 0x64)) == -1) {
        temp_v0 = func_L39_0067F1B0();
        *(s32 *)((u8 *)arg0 + 0x64) = temp_v0;
        func_003E5360(temp_v0);
        func_003E8630(D_001DBC5C, (*(s32 *)((u8 *)arg0 + 0x64)));
    }
}
/* localdecomp:end func_L39_0067FCD8 */

/* localdecomp:start func_L39_0067FD28 */
void func_L39_0067FD28(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
}
/* localdecomp:end func_L39_0067FD28 */

INCLUDE_ASM("asm/levels", func_L39_0067FD38);

LINKER_REMNANT("asm/levels", func_L39_0067FE70);

INCLUDE_ASM("asm/levels", func_L39_0067FE78);

INCLUDE_ASM("asm/levels", func_L39_0067FEC0);

/* localdecomp:start func_L39_0067FEE8 */
s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_0067FEE8(void *arg0, f32 fparg0, f32 fparg1) {
    s32 ret = 0;
    s32 temp;

    temp = *(s32 *)((u8 *)arg0 + 0x68);
    if (temp != -1) {
        ret = func_L01_00517538(temp, fparg0, fparg1);
    }
    temp = *(s32 *)((u8 *)arg0 + 0x6C);
    if (temp != -1) {
        ret |= func_L01_00517538(temp, fparg0, fparg1);
    }
    temp = *(s32 *)((u8 *)arg0 + 0x70);
    if (temp != -1) {
        ret |= func_L01_00517538(temp, fparg0, fparg1);
    }
    return ret != 0;
}
/* localdecomp:end func_L39_0067FEE8 */

/* localdecomp:start func_L39_0067FF80 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_0067FF80(u8 *arg0, s32 arg1) {
    s32 r = 0;

    if (*(s32 *)(arg0 + 0x68) != -1) {
        r = func_003E7F20(*(s32 *)(arg0 + 0x68), arg1);
    }
    if (*(s32 *)(arg0 + 0x6C) != -1) {
        r |= func_003E7F20(*(s32 *)(arg0 + 0x6C), arg1);
    }
    if (*(s32 *)(arg0 + 0x70) != -1) {
        r |= func_003E7F20(*(s32 *)(arg0 + 0x70), arg1);
    }
    return r != 0;
}
/* localdecomp:end func_L39_0067FF80 */

INCLUDE_ASM("asm/levels", func_L39_00680010);

INCLUDE_ASM("asm/levels", func_L39_00680098);

/* localdecomp:start func_L39_00680100 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00680100(void *arg0, s32 arg1, s32 arg2) {
    s32 ret;

    ret = 0;
    if ((*(s32 *)((u8 *)arg0 + 0x68)) != -1) {
        ret = func_L01_00516AA0((*(s32 *)((u8 *)arg0 + 0x68)), arg1, arg2);
    }
    if ((*(s32 *)((u8 *)arg0 + 0x6C)) != -1) {
        ret |= func_L01_00516AA0((*(s32 *)((u8 *)arg0 + 0x6C)), arg1, arg2);
    }
    if ((*(s32 *)((u8 *)arg0 + 0x70)) != -1) {
        ret |= func_L01_00516AA0((*(s32 *)((u8 *)arg0 + 0x70)), arg1, arg2);
    }
    return ret != 0;
}
/* localdecomp:end func_L39_00680100 */

/* localdecomp:start func_L39_00680198 */
s32 func_L01_00516C78(s32, s32, s32);


s32 func_L39_00680198(S_00680198 *self, s32 a1, s32 a2) {
    s32 r = 0;

    if (self->f68 != -1) {
        r = func_L01_00516C78(self->f68, a1, a2);
    }
    if (self->f6C != -1) {
        r |= func_L01_00516C78(self->f6C, a1, a2);
    }
    if (self->f70 != -1) {
        r |= func_L01_00516C78(self->f70, a1, a2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00680198 */

INCLUDE_ASM("asm/levels", func_L39_00680230);

/* localdecomp:start func_L39_00680330 */
s32 func_L01_00516C78(s32, s32, s32);

void func_L39_00680330(void *arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1;
    switch (var_a1) {                               /* irregular */
    case -1:
        var_a1 = 1;
        break;
    case 1:
        var_a1 = 2;
        break;
    case 0:
        var_a1 = 3;
        break;
    }
    if ((*(s32 *)((u8 *)arg0 + 0x70)) != -1) {
        func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0x70)), var_a1, 3);
    }
}
/* localdecomp:end func_L39_00680330 */

INCLUDE_ASM("asm/levels", func_L39_00680390);

INCLUDE_ASM("asm/levels", func_L39_006803A8);

/* localdecomp:start func_L39_00680578 */
void func_L39_00680578(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
}
/* localdecomp:end func_L39_00680578 */

/* localdecomp:start func_L39_00680580 */
u8 func_L39_00680580(void *arg0, u8 arg1) {
    u8 temp_v0;

    temp_v0 = *(u8 *)((u8 *)arg0 + 0x64);
    *(u8 *)((u8 *)arg0 + 0x64) = arg1;
    return temp_v0;
}
/* localdecomp:end func_L39_00680580 */

/* localdecomp:start func_L39_00680590 */
u8 func_L39_00680590(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00680590 */

LINKER_REMNANT("asm/levels", func_L39_00680598);

INCLUDE_ASM("asm/levels", func_L39_006805A0);

INCLUDE_ASM("asm/levels", func_L39_00680688);

/* localdecomp:start func_L39_006806B0 */
s32 func_L01_00516C78(s32, s32, s32);

s32 func_L39_006806B0(void *arg0, s32 arg1, s32 arg2) {
    s32 r;

    r = 0;
    if ((*(s32 *)((u8 *)arg0 + 0x1470)) != -1) {
        r = func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0x1470)), arg1, arg2);
    }
    if ((*(s32 *)((u8 *)arg0 + 0x1474)) != -1) {
        r |= func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0x1474)), arg1, arg2);
    }
    if ((*(s32 *)((u8 *)arg0 + 0x1478)) != -1) {
        r |= func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0x1478)), arg1, arg2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_006806B0 */

/* localdecomp:start func_L39_00680748 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00680748(void *arg0, s32 arg1, s32 arg2) {
    s32 ret;

    ret = 0;
    if (*(s32 *)((u8 *)arg0 + 0x1470) != -1) {
        ret = func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x1470), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x1474) != -1) {
        ret |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x1474), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x1478) != -1) {
        ret |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x1478), arg1, arg2);
    }
    return ret != 0;
}
/* localdecomp:end func_L39_00680748 */

/* localdecomp:start func_L39_006807E0 */
s32 func_003E7F20(s32, s32);

s32 func_L39_006807E0(void *arg0, s32 arg1) {
    s32 r = 0;

    if (*(s32 *)((u8 *)arg0 + 0x1470) != -1) {
        r = func_003E7F20(*(s32 *)((u8 *)arg0 + 0x1470), arg1);
    }
    if (*(s32 *)((u8 *)arg0 + 0x1474) != -1) {
        r |= func_003E7F20(*(s32 *)((u8 *)arg0 + 0x1474), arg1);
    }
    if (*(s32 *)((u8 *)arg0 + 0x1478) != -1) {
        r |= func_003E7F20(*(s32 *)((u8 *)arg0 + 0x1478), arg1);
    }
    return r != 0;
}
/* localdecomp:end func_L39_006807E0 */

INCLUDE_ASM("asm/levels", func_L39_00680870);

INCLUDE_ASM("asm/levels", func_L39_006808F0);

/* localdecomp:start func_L39_00680988 */
s32 func_L39_00688340(s32, s32, s32);

s32 func_L39_00680988(void *arg0, s32 arg1) {
    s32 cur;
    s32 next;

    cur = *(s32 *)((u8 *)arg0 + 0x1468);
    *(s32 *)((u8 *)arg0 + 0x146C) = cur;
    if (arg1 == 3) {
        *(u8 *)((u8 *)arg0 + 0xC) = 1;
        if (cur > 0) {
            next = cur - 1;
        } else {
            next = *(s32 *)((u8 *)arg0 + 0x64) - 1;
        }
        *(s32 *)((u8 *)arg0 + 0x1468) = next;
    } else if (arg1 == 4 || arg1 == 7) {
        s32 lt;

        lt = cur < *(s32 *)((u8 *)arg0 + 0x64) - 1;
        *(u8 *)((u8 *)arg0 + 0xC) = 1;
        if (lt) {
            *(s32 *)((u8 *)arg0 + 0x1468) = cur + 1;
        } else {
            *(s32 *)((u8 *)arg0 + 0x1468) = 0;
        }
    } else {
        return 0;
    }
    func_L39_00688340(3, 0, 0);
    return 1;
}
/* localdecomp:end func_L39_00680988 */

INCLUDE_ASM("asm/levels", func_L39_00680A20);

/* localdecomp:start func_L39_00680AF0 */
void func_L39_00680AF0(void *arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < (*(s32 *)((u8 *)arg0 + 0x64)))) {
        *(s32 *)((u8 *)arg0 + 0x1468) = arg1;
    }
    *(s32 *)((u8 *)arg0 + 0x146C) = (s32) (*(s32 *)((u8 *)arg0 + 0x1468));
}
/* localdecomp:end func_L39_00680AF0 */

INCLUDE_ASM("asm/levels", func_L39_00680B18);

/* localdecomp:start func_L39_00680C18 */
s32 func_L01_00516C78(s32, s32, s32);

void func_L39_00680C18(void *arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1;
    switch (var_a1) {                               /* irregular */
    case -1:
        var_a1 = 1;
        break;
    case 1:
        var_a1 = 2;
        break;
    case 0:
        var_a1 = 3;
        break;
    }
    if ((*(s32 *)((u8 *)arg0 + 0x1478)) != -1) {
        func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0x1478)), var_a1, 3);
    }
}
/* localdecomp:end func_L39_00680C18 */

INCLUDE_ASM("asm/levels", func_L39_00680C78);

INCLUDE_ASM("asm/levels", func_L39_00680C90);

/* localdecomp:start func_L39_00680EB8 */
void func_L39_00680EB8(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x147C) = 1;
}
/* localdecomp:end func_L39_00680EB8 */

/* localdecomp:start func_L39_00680EC8 */
s32 func_L39_00680EC8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x1468));
}
/* localdecomp:end func_L39_00680EC8 */

/* localdecomp:start func_L39_00680ED0 */
void *func_L39_00680ED0(void *arg0) {
    return arg0 + (((*(s32 *)((u8 *)arg0 + 0x1468)) * 0x50) + 0x68);
}
/* localdecomp:end func_L39_00680ED0 */

/* localdecomp:start func_L39_00680EE8 */
s32 func_L39_00680EE8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x1468)) != *(s32 *)((u8 *)arg0 + 0x146C);
}
/* localdecomp:end func_L39_00680EE8 */

/* localdecomp:start func_L39_00680F00 */
s32 func_L39_00680F00(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00680F00 */

INCLUDE_ASM("asm/levels", func_L39_00680F08);

INCLUDE_ASM("asm/levels", func_L39_00680F80);

/* localdecomp:start func_L39_00680FA8 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00680FA8(void *arg0, s32 arg1, s32 arg2) {
    if (*(s32 *)((u8 *)arg0 + 0x64) != -1) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x64), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x68) != -1) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x68), arg1, arg2);
    }
    return 1;
}
/* localdecomp:end func_L39_00680FA8 */

INCLUDE_ASM("asm/levels", func_L39_00681018);

INCLUDE_ASM("asm/levels", func_L39_00681130);

INCLUDE_ASM("asm/levels", func_L39_00681158);

INCLUDE_ASM("asm/levels", func_L39_00681330);

INCLUDE_ASM("asm/levels", func_L39_006813F8);

INCLUDE_ASM("asm/levels", func_L39_00681470);

INCLUDE_ASM("asm/levels", func_L39_006814B0);

/* localdecomp:start func_L39_00681598 */
s32 func_L01_005170B8(s32, s32);

s32 func_L39_00681598(void *arg0, s32 arg1) {
    s32 *p;
    s32 *base;

    base = (s32 *)((u8 *)arg0 + 0x64);
    p = base + *(s32 *)((u8 *)arg0 + 0x74);
    if (*p == -1) {
        return 0;
    }
    *(s32 *)((u8 *)arg0 + 0x80) = arg1;
    return func_L01_005170B8(*p, arg1);
}
/* localdecomp:end func_L39_00681598 */

INCLUDE_ASM("asm/levels", func_L39_006815F0);

INCLUDE_ASM("asm/levels", func_L39_0068168C);
