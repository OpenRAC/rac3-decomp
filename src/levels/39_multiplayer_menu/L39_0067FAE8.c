#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* localdecomp:start func_L39_0067FAE8 */
extern u8 D_L39_0047B6C0[];
extern void *func_L39_0067EE40(void *, void *);

void *func_L39_0067FAE8(void *self, void *o) {
    func_L39_0067EE40(self, o);
    *(u8 **)((u8 *)self + 0x60) = D_L39_0047B6C0;
    *(s32 *)((u8 *)self + 0x64) = -1;
    *(s32 *)((u8 *)self + 0x68) = 0;
    return self;
}
/* localdecomp:end func_L39_0067FAE8 */

/* localdecomp:start func_L39_0067FB28 */
extern u8 D_L39_0047B6C0[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0067FB28(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047B6C0;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_0067FB28 */

/* localdecomp:start func_L39_0067FB50 */
s32 func_L01_00516C78(s32, s32, s32);

s32 func_L39_0067FB50(u8 *arg0) {
    s32 t = *(s32 *)(arg0 + 0x64);
    if (t != -1) {
        return ((s32 (*)(s32))func_L01_00516C78)(t);
    }
    return 0;
}
/* localdecomp:end func_L39_0067FB50 */

/* localdecomp:start func_L39_0067FB80 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_0067FB80(u8 *arg0) {
    s32 t = *(s32 *)(arg0 + 0x64);
    if (t != -1) {
        return ((s32 (*)(s32))func_L01_00516AA0)(t);
    }
    return 0;
}
/* localdecomp:end func_L39_0067FB80 */

/* localdecomp:start func_L39_0067FBB0 */
s32 func_L01_005170B8(s32, s32);

s32 func_L39_0067FBB0(u8 *arg0, s32 arg1) {
    s32 cur = *(s32 *)((u8 *)arg0 + 0x64);

    if (cur == -1) {
        return 0;
    }
    *(s32 *)((u8 *)arg0 + 0x68) = arg1;
    if (arg1 == 0) {
        return 1;
    }
    return func_L01_005170B8(cur, arg1);
}
/* localdecomp:end func_L39_0067FBB0 */

/* localdecomp:start func_L39_0067FBF0 */
s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_0067FBF0(u8 *arg0) {
    s32 t = *(s32 *)(arg0 + 0x64);
    if (t != -1) {
        return ((s32 (*)(s32))func_L01_00517538)(t);
    }
    return 0;
}
/* localdecomp:end func_L39_0067FBF0 */

/* localdecomp:start func_L39_0067FC20 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_0067FC20(u8 *arg0) {
    s32 t = *(s32 *)(arg0 + 0x64);
    if (t != -1) {
        return ((s32 (*)(s32))func_003E7F20)(t);
    }
    return 0;
}
/* localdecomp:end func_L39_0067FC20 */

/* localdecomp:start func_L39_0067FC50 */
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);

s32 func_L39_0067FC50(u8 *arg0, s32 arg1, f32 a, f32 b) {
    if (*(s32 *)(arg0 + 0x64) != -1) {
        if (func_L01_00518010(*(s32 *)(arg0 + 0x64), arg1) != 0) {
            if (arg1 != 0) {
                return func_003E8898(*(s32 *)(arg0 + 0x64), a, b);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0067FC50 */

/* localdecomp:start func_L39_0067FCD8 */
s32 func_003E5360(s32);
s32 func_003E8630(s32, s32);
s32 func_L39_0067F1B0(void);
extern s32 D_001DBC5C_sda;

void func_L39_0067FCD8(void *arg0) {
    s32 temp_v0;

    if ((*(s32 *)((u8 *)arg0 + 0x64)) == -1) {
        temp_v0 = func_L39_0067F1B0();
        *(s32 *)((u8 *)arg0 + 0x64) = temp_v0;
        func_003E5360(temp_v0);
        func_003E8630(D_001DBC5C_sda, (*(s32 *)((u8 *)arg0 + 0x64)));
    }
}
/* localdecomp:end func_L39_0067FCD8 */

/* localdecomp:start func_L39_0067FD28 */
void func_L39_0067FD28(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
}
/* localdecomp:end func_L39_0067FD28 */

/* localdecomp:start func_L39_0067FD38 */
s32 func_L01_00516FD8(s32, void *);
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
u32 func_003825F8(u32, u32, s32, s32, s32, s32);
s32 func_L01_00516470(s32, f32, f32);

void func_L39_0067FD38(void *arg0) {
    u8 *p = arg0;
    u32 color;
    f32 x, y;
    u32 base;
    s32 st;

    if (*(s32 *)(p + 0x64) == -1) {
        return;
    }
    color = 0x8066CCFF;
    func_L01_00516FD8(*(s32 *)(p + 0x64), p + 0x14);
    if (*(s32 *)(p + 0x4) == 0) {
        func_L01_00516AA0(*(s32 *)(p + 0x64), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)(p + 0x64), 1, 1);
    base = *(u32 *)(p + 0x68);
    st = *(s32 *)(p + 0x4);
    if (base == 0) {
        if (st == 2) {
            color = 0x80808080;
        } else if (st == 3) {
            /* keeps the default colour */
        } else if (st == 4) {
            color = func_003825F8(0x8066CCFF, 0x66D6EEFA, 0x25, 1, 0, 1);
        } else if (st == 5) {
            color = 0x66D6EEFA;
        }
    } else if (st == 4) {
        color = func_003825F8(base, 0x66D6EEFA, 0x25, 1, 0, 1);
    } else {
        color = base;
    }
    func_L01_005170B8(*(s32 *)(p + 0x64), color);
    (*(void (**)(void *, f32 *, f32 *))(*(u8 **)(p + 0x60) + 0x30))(p, &x, &y);
    func_L01_00516470(*(s32 *)(p + 0x64), x, y);
}
/* localdecomp:end func_L39_0067FD38 */

LINKER_REMNANT("asm/levels", func_L39_0067FE70);

/* localdecomp:start func_L39_0067FE78 */
extern u8 D_L39_0047B7B0[];
extern void *func_L39_0067EE40(void *, void *);

void *func_L39_0067FE78(void *self, void *o) {
    func_L39_0067EE40(self, o);
    *(u8 **)((u8 *)self + 0x60) = D_L39_0047B7B0;
    *(s32 *)((u8 *)self + 0x68) = -1;
    *(s32 *)((u8 *)self + 0x6C) = -1;
    *(s32 *)((u8 *)self + 0x70) = -1;
    return self;
}
/* localdecomp:end func_L39_0067FE78 */

/* localdecomp:start func_L39_0067FEC0 */
extern u8 D_L39_0047B7B0[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0067FEC0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047B7B0;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_0067FEC0 */

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

/* localdecomp:start func_L39_00680010 */
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);

s32 func_L39_00680010(u8 *arg0, s32 arg1, f32 a, f32 b) {
    if (*(s32 *)(arg0 + 0x68) != -1) {
        if (func_L01_00518010(*(s32 *)(arg0 + 0x68), arg1) != 0) {
            if (arg1 != 0) {
                return func_003E8898(*(s32 *)(arg0 + 0x68), a, b);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00680010 */

/* localdecomp:start func_L39_00680098 */
s32 func_L39_00688340(s32, s32, s32);

s32 func_L39_00680098(u8 *arg0, s32 arg1) {
    u8 *self = arg0;
    s32 r = 0;

    if ((arg1 >= 3 && arg1 < 5) || arg1 == 7) {
        func_L39_00688340(3, 0, 0);
        self[0xC] = 1;
        self[0x64] = self[0x64] ^ 1;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L39_00680098 */

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
