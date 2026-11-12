#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* localdecomp:start func_L39_006818D0 */
extern u8 D_L39_0047BA80[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006818D0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BA80;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_006818D0 */

/* localdecomp:start func_L39_006818F8 */
extern s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_006818F8(void *arg0, f32 fa, f32 fb) {
    u8 *base = (u8 *)arg0 + 0x10000;
    s32 r = 0;

    if (*(s32 *)(base + 0x170) != -1) {
        r = func_L01_00517538(*(s32 *)(base + 0x170), fa, fb);
    }
    if (*(s32 *)(base + 0x174) != -1) {
        r |= func_L01_00517538(*(s32 *)(base + 0x174), fa, fb);
    }
    if (*(s32 *)(base + 0x178) != -1) {
        r |= func_L01_00517538(*(s32 *)(base + 0x178), fa, fb);
    }
    return r != 0;
}
/* localdecomp:end func_L39_006818F8 */

/* localdecomp:start func_L39_00681998 */
s32 func_L39_00681998(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x1059C) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00681998 */

/* localdecomp:start func_L39_006819B0 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_006819B0(void *arg0, s32 arg1) {
    s32 r;

    r = 0;
    if (*(s32 *)((u8 *)arg0 + 0x10170) != -1) {
        r = func_003E7F20(*(s32 *)((u8 *)arg0 + 0x10170), arg1);
    }
    if (*(s32 *)((u8 *)arg0 + 0x10174) != -1) {
        r |= func_003E7F20(*(s32 *)((u8 *)arg0 + 0x10174), arg1);
    }
    if (*(s32 *)((u8 *)arg0 + 0x10178) != -1) {
        r |= func_003E7F20(*(s32 *)((u8 *)arg0 + 0x10178), arg1);
    }
    return r != 0;
}
/* localdecomp:end func_L39_006819B0 */

/* localdecomp:start func_L39_00681A40 */
s32 func_L39_00688340(s32, s32, s32);

s32 func_L39_00681A40(u8 *arg0, s32 arg1)
{
    s32 cur = *(s32 *)(arg0 + 0x10168);

    *(s32 *)(arg0 + 0x1016C) = cur;
    if (*(u8 *)(arg0 + 0x10585) == 1) {
        *(u8 *)(arg0 + 0x10584) = 1;
        if (arg1 == 1) {
            if (cur > 0) {
                func_L39_00688340(3, 0, 0);
                *(s32 *)(arg0 + 0x10168) -= 1;
            }
            return 1;
        }
        if (arg1 == 2) {
            if (cur < *(s32 *)(arg0 + 0x64) - 1) {
                func_L39_00688340(3, 0, 0);
                *(s32 *)(arg0 + 0x10168) += 1;
            }
            return 1;
        }
        if (arg1 == 11) {
            *(s32 *)(arg0 + 0x10168) = cur - (*(s32 *)(arg0 + 0x1057C) - 1);
            if (*(s32 *)(arg0 + 0x10168) < 0) {
                func_L39_00688340(3, 0, 0);
                *(s32 *)(arg0 + 0x10168) = 0;
            }
            return 1;
        }
        if (arg1 == 12) {
            *(s32 *)(arg0 + 0x10168) = cur + (*(s32 *)(arg0 + 0x1057C) - 1);
            if (*(s32 *)(arg0 + 0x64) - 1 < *(s32 *)(arg0 + 0x10168)) {
                func_L39_00688340(3, 0, 0);
                *(s32 *)(arg0 + 0x10168) = *(s32 *)(arg0 + 0x64) - 1;
            }
            return 1;
        }
        return 0;
    }
    if (*(u8 *)(arg0 + 0x10584) == 0) {
        if (arg1 == 7) {
            func_L39_00688340(4, 0, 0);
            *(u8 *)(arg0 + 0x10584) = 1;
            return 1;
        }
        return 0;
    }
    if (arg1 == 7) {
        *(u8 *)(arg0 + 0x10584) = 0;
    } else if (arg1 == 1) {
        if (cur > 0) {
            func_L39_00688340(3, 0, 0);
            *(s32 *)(arg0 + 0x10168) -= 1;
        }
        return 1;
    } else if (arg1 == 2) {
        if (cur < *(s32 *)(arg0 + 0x64) - 1) {
            func_L39_00688340(3, 0, 0);
            *(s32 *)(arg0 + 0x10168) += 1;
        }
        return 1;
    } else if (arg1 == 11) {
        *(s32 *)(arg0 + 0x10168) = cur - (*(s32 *)(arg0 + 0x1057C) - 1);
        if (*(s32 *)(arg0 + 0x10168) < 0) {
            func_L39_00688340(3, 0, 0);
            *(s32 *)(arg0 + 0x10168) = 0;
        }
        return 1;
    } else if (arg1 == 12) {
        *(s32 *)(arg0 + 0x10168) = cur + (*(s32 *)(arg0 + 0x1057C) - 1);
        if (*(s32 *)(arg0 + 0x64) - 1 < *(s32 *)(arg0 + 0x10168)) {
            func_L39_00688340(3, 0, 0);
            *(s32 *)(arg0 + 0x10168) = *(s32 *)(arg0 + 0x64) - 1;
        }
        return 1;
    } else if (arg1 == 5) {
        *(u8 *)(arg0 + 0x10584) = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00681A40 */

/* localdecomp:start func_L39_00681CA8 */
typedef void (*Fn_00681CA8)(void *, s32);
extern s32 func_L39_0067EF00(void *, s32);

s32 func_L39_00681CA8(void *arg0, s32 arg1, s32 arg2) {
    s32 r = func_L39_0067EF00(arg0, arg1);
    u8 *base = (u8 *)arg0 + 0x10000;

    if (base[0x585] == 1) {
        if (r != 4 && arg1 == 4) {
            if (arg2 == 1) {
                (*(Fn_00681CA8 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x88))(arg0, -2);
            } else if (arg2 == 2 || *(s32 *)(base + 0x168) < 0) {
                (*(Fn_00681CA8 *)(*(u8 **)((u8 *)arg0 + 0x60) + 0x88))(arg0, -1);
            }
        }
    } else if (arg1 < 4) {
        base[0x584] = 0;
    }
    return r;
}
/* localdecomp:end func_L39_00681CA8 */

INCLUDE_ASM("asm/levels", func_L39_00681D78);

/* localdecomp:start func_L39_00682018 */
void func_L39_00682018(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x1057C) = arg1;
}
/* localdecomp:end func_L39_00682018 */

/* localdecomp:start func_L39_00682028 */
void func_L39_00682028(void *arg0, s32 arg1) {
    if (arg1 == -1) {
        *(s32 *)((u8 *)arg0 + 0x10168) = 0;
    } else if (arg1 == -2) {
        *(s32 *)((u8 *)arg0 + 0x10168) = *(s32 *)((u8 *)arg0 + 0x64) - 1;
    } else if (arg1 >= 0 && arg1 <= *(s32 *)((u8 *)arg0 + 0x64)) {
        *(s32 *)((u8 *)arg0 + 0x10168) = arg1;
    }
    *(s32 *)((u8 *)arg0 + 0x1016C) = *(s32 *)((u8 *)arg0 + 0x10168);
}
/* localdecomp:end func_L39_00682028 */

/* localdecomp:start func_L39_00682098 */
extern s32 func_L39_00611CA0(s32);
s32 func_L39_00682098(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x10178);
    if (v != -1) {
        return func_L39_00611CA0(v);
    }
    return 0;
}
/* localdecomp:end func_L39_00682098 */

/* localdecomp:start func_L39_006820D0 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_006820D0(void *arg0, s32 arg1, s32 arg2) {
    if (*(s32 *)((u8 *)arg0 + 0x10178) != -1) {
        return func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x10178), arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_006820D0 */

/* localdecomp:start func_L39_00682108 */
extern s32 func_L01_00516818(s32);

s32 func_L39_00682108(void *arg0, f32 fa) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x10178);

    if (v != -1) {
        *(f32 *)((u8 *)arg0 + 0x105A0) = fa;
        return func_L01_00516818(v);
    }
    return 0;
}
/* localdecomp:end func_L39_00682108 */

/* localdecomp:start func_L39_00682148 */
extern s32 func_L01_00518670(s32, s32, s32);

s32 func_L39_00682148(void *arg0, s32 arg1, s32 arg2) {
    if (*(s32 *)((u8 *)arg0 + 0x10178) != -1) {
        return func_L01_00518670(*(s32 *)((u8 *)arg0 + 0x10178), arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_00682148 */

INCLUDE_ASM("asm/levels", func_L39_00682180);

/* localdecomp:start func_L39_006821C0 */
void func_L39_006821C0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x4C) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x48) = 1;
}
/* localdecomp:end func_L39_006821C0 */

/* localdecomp:start func_L39_006821D0 */
extern s32 func_L39_0067F1B0(void);
extern void func_003E5360(s32);
extern void func_003E8630(s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, u8 *);
extern void func_003EA778(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 D_0024736C;
__asm__(".extern D_0024736C, 16");
extern u8 D_00247388;
__asm__(".extern D_00247388, 16");
extern s32 D_001DBC5C_sda;

void func_L39_006821D0(u8 *arg0)
{
    u8 *base = arg0 + 0x10000;

    if (*(s32 *)(base + 0x170) == -1) {
        *(s32 *)(base + 0x170) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)(base + 0x170));
        func_003E8630(D_0024736C, *(s32 *)(base + 0x170));
        func_L01_00516C78(*(s32 *)(base + 0x170), 1, 3);
    }
    if (*(s32 *)(base + 0x174) == -1) {
        *(s32 *)(base + 0x174) = func_L39_0067F1B0();
        func_003E5360(*(s32 *)(base + 0x174));
        func_L01_00516FD8(*(s32 *)(base + 0x174), &D_00247388);
        func_003E8630(D_0024736C, *(s32 *)(base + 0x174));
        func_L01_00516C78(*(s32 *)(base + 0x174), 1, 3);
    }
    if (*(s32 *)(base + 0x178) == -1) {
        *(s32 *)(base + 0x178) = func_L39_0067F1B0();
        func_003EA778(*(s32 *)(base + 0x178));
        func_L01_00516470(*(s32 *)(base + 0x178), *(f32 *)(arg0 + 0x50), *(f32 *)(arg0 + 0x54));
        func_L01_00517538(*(s32 *)(base + 0x178), *(f32 *)(arg0 + 0x58), *(f32 *)(arg0 + 0x5C));
        func_003E8630(D_001DBC5C_sda, *(s32 *)(base + 0x178));
    }
}
/* localdecomp:end func_L39_006821D0 */

/* localdecomp:start func_L39_006822E8 */
void func_L39_006822E8(void *arg0)
{
    *(s32 *)((u8 *)arg0 + 0x10170) = -1;
    *(s32 *)((u8 *)arg0 + 0x10174) = -1;
    *(s32 *)((u8 *)arg0 + 0x10178) = -1;
}
/* localdecomp:end func_L39_006822E8 */

/* localdecomp:start func_L39_00682308 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E7F20(s32, s32);
extern void func_L39_00611728(s32, void *, s16, s16, s32);
extern void func_L01_005170B8(s32, s32);

void func_L39_00682308(u8 *arg0) {
    u8 *b = arg0 + 0x10000;
    u8 *b2;
    s32 color;
    s32 color2;
    s32 hlcolor;
    s32 hl;
    s32 count;
    s32 i;
    s32 idx;
    s32 mode;
    s32 x;
    s32 y;

    if (*(s32 *)(b + 0x170) == -1) {
        return;
    }
    if (*(s32 *)(arg0 + 0x64) - 1 < *(s32 *)(b + 0x168)) {
        *(s32 *)(b + 0x168) = *(s32 *)(arg0 + 0x64) - 1;
    }
    if (*(s32 *)(arg0 + 0x64) - *(s32 *)(b + 0x57C) < *(s32 *)(b + 0x580)) {
        *(s32 *)(b + 0x580) = *(s32 *)(arg0 + 0x64) - *(s32 *)(b + 0x57C);
    }
    if (*(s32 *)(b + 0x580) > *(s32 *)(b + 0x168)) {
        *(s32 *)(b + 0x580) = *(s32 *)(b + 0x168);
    }
    if (*(s32 *)(b + 0x580) < *(s32 *)(b + 0x168) + (1 - *(s32 *)(b + 0x57C))) {
        *(s32 *)(b + 0x580) = *(s32 *)(b + 0x168) + (1 - *(s32 *)(b + 0x57C));
    }
    if (*(s32 *)(b + 0x580) < 0) {
        *(s32 *)(b + 0x580) = 0;
    }
    if (*(s32 *)(arg0 + 4) == 0) {
        func_L01_00516AA0(*(s32 *)(b + 0x170), 1, 0);
        func_L01_00516AA0(*(s32 *)(b + 0x174), 1, 0);
        func_L01_00516AA0(*(s32 *)(b + 0x178), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)(b + 0x170), 1, 1);
    func_L01_00516AA0(*(s32 *)(b + 0x174), 1, 1);
    func_L01_00516AA0(*(s32 *)(b + 0x178), 1, 1);
    mode = *(s32 *)(arg0 + 4);
    if (*(s32 *)(arg0 + 4) == 2) {
        color = 0x80808080;
    } else if (mode == 3) {
        color = 0x8066CCFF;
    } else if (mode == 4) {
        color = 0x66D6EEFA;
    } else if (mode == 5) {
        color = 0x66D6EEFA;
    } else {
        color = 0x8066CCFF;
    }
    ((void (*)(void *, s32 *, s32 *))(*(s32 *)((u8 *)*(void **)(arg0 + 0x60) + 0x30)))(arg0, &x, &y);
    b2 = arg0 + 0x10000;
    func_L01_00516AA0(*(s32 *)(b2 + 0x170), 1, 0);
    func_L01_00516AA0(*(s32 *)(b2 + 0x174), 1, 0);
    if (*(s32 *)(b2 + 0x59C) != -1) {
        func_003E7F20(*(s32 *)(b2 + 0x178), *(s32 *)(b2 + 0x59C));
    }
    if (*(s32 *)(arg0 + 0x64) == 0) {
        *(u8 **)(b2 + 0x17C) = arg0 + 0x10068;
        func_L39_00611728(*(s32 *)(b2 + 0x178), arg0 + 0x1017C, 1, -1, 0);
        func_L01_005170B8(*(s32 *)(b2 + 0x178), color);
        return;
    }
    hl = -1;
    hlcolor = 0x80808080;
    color2 = 0x80808080;
    count = 0;
    for (i = 0; i < *(s32 *)(arg0 + 0x1057C); i++) {
        idx = *(s32 *)(arg0 + 0x10580) + i;
        if (idx < *(s32 *)(arg0 + 0x64)) {

            if (*(s32 *)(arg0 + 4) == 1) {
                color2 = 0x8066CCFF;
            } else if (*(s32 *)(arg0 + 4) == 2) {
                color2 = 0x80808080;
            } else if (*(u8 *)(arg0 + 0x10584) == 1 && *(s32 *)(arg0 + 4) >= 4 && idx == *(s32 *)(arg0 + 0x10168)) {
                hl = (s16)i;
                hlcolor = 0x66D6EEFA;
            } else {
                color2 = 0x8066CCFF;
            }
            count++;
            ((u8 **)(arg0 + 0x1017C))[i] = arg0 + (((*(s32 *)(arg0 + 0x10580) + i) << 8) + 0x68);
        } else {
            ((u8 **)(arg0 + 0x1017C))[i] = 0;
        }
    }
    func_L39_00611728(*(s32 *)(arg0 + 0x10178), arg0 + 0x1017C, count, hl, hlcolor);
    func_L01_005170B8(*(s32 *)(arg0 + 0x10178), color2);
}
/* localdecomp:end func_L39_00682308 */

/* localdecomp:start func_L39_00682640 */
extern s32 func_L39_00611E50(s32, s32, s32);

s32 func_L39_00682640(void *arg0, s32 arg1, s32 arg2) {
    s32 a;
    s32 b;

    ((void (*)(void *, s32, s32))(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x60) + 0x30)))(arg0, arg1, arg2);
    ((void (*)(void *, s32 *, s32 *))(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x60) + 0x34)))(arg0, &a, &b);
    if (*(s32 *)((u8 *)arg0 + 0x10178) != -1) {
        func_L39_00611E50(*(s32 *)((u8 *)arg0 + 0x10178), arg1, arg2);
    }
    return 1;
}
/* localdecomp:end func_L39_00682640 */

/* localdecomp:start func_L39_006826C0 */
extern s32 func_L39_00611D78(s32, s32);


s32 func_L39_006826C0(void *arg0, s32 arg1, s32 arg2) {
    void *p = *(void **)((u8 *)arg0 + 0x60);

    (*(FnVcall_006826C0 *)((u8 *)p + 0x34))(arg0, arg1, arg2);
    if (*(s32 *)((u8 *)arg0 + 0x10178) != -1) {
        func_L39_00611D78(*(s32 *)((u8 *)arg0 + 0x10178), arg2);
    }
    return 1;
}
/* localdecomp:end func_L39_006826C0 */

/* localdecomp:start func_L39_00682720 */
typedef struct S_682720_B S_682720_B;
typedef struct S_682720_A {
    char _p0[0x6C];
    void (*f6C)(S_682720_B *arg0, s32 arg1, s32 arg2);
} S_682720_A;
struct S_682720_B {
    char _p0[0x60];
    S_682720_A *f60;
};

/* from rac4-decomp's func_L00_007131A8 */
void func_L39_00682720(S_682720_B *arg0) {
    arg0->f60->f6C(arg0, 0, 0);
}
/* localdecomp:end func_L39_00682720 */

/* localdecomp:start func_L39_00682748 */
s32 func_L39_00682748(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00682748 */

/* localdecomp:start func_L39_00682750 */
s32 func_L39_00682750(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x1057C));
}
/* localdecomp:end func_L39_00682750 */

/* localdecomp:start func_L39_00682760 */
s32 func_L39_00682760(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10168));
}
/* localdecomp:end func_L39_00682760 */

/* localdecomp:start func_L39_00682770 */
s32 func_L39_00682770(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10580));
}
/* localdecomp:end func_L39_00682770 */

/* localdecomp:start func_L39_00682780 */
/* from rac4-decomp's func_L00_007142A8, renamed, constants adapted */
s32 func_L39_00682780(void *object, s32 index) {
    if (index < *(s32 *)((u8 *)object + 0x64)) {
        return (s32)((u8 *)object + ((index << 8) + 0x68));
    }
    return 0;
}
/* localdecomp:end func_L39_00682780 */

/* localdecomp:start func_L39_006827A8 */
void *func_L39_006827A8(void *arg0) {
    return arg0 + (((*(s32 *)((u8 *)arg0 + 0x10168)) << 8) + 0x68);
}
/* localdecomp:end func_L39_006827A8 */

/* localdecomp:start func_L39_006827C8 */
s32 func_L39_006827C8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x10168)) != *(s32 *)((u8 *)arg0 + 0x1016C);
}
/* localdecomp:end func_L39_006827C8 */

/* localdecomp:start func_L39_006827E8 */
u8 func_L39_006827E8(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x10584));
}
/* localdecomp:end func_L39_006827E8 */

/* localdecomp:start func_L39_006827F8 */
/* from rac4-decomp's func_L00_00714320, renamed, constants adapted */
void func_L39_006827F8(u8 *owner, s32 value)
{
    u8 *state = (u8 *)((u32)owner + 0x10000);
    if (!state[0x585])
        state[0x584] = value;
}
/* localdecomp:end func_L39_006827F8 */

/* localdecomp:start func_L39_00682818 */
/* from rac4-decomp's func_L00_00714340, renamed, constants adapted */
void func_L39_00682818(u8 *owner, s32 value)
{
    u8 *state = (u8 *)((u32)owner + 0x10000);
    state[0x585] = value;
    if (value == 1)
        state[0x584] = value;
}
/* localdecomp:end func_L39_00682818 */

LINKER_REMNANT("asm/levels", func_L39_00682838);

/* localdecomp:start func_L39_00682840 */
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern u8 D_L39_0047BB78[];

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
    u8 pad78[0xA0 - 0x78];
    s32 fA0;
    s32 fA4;
    s32 fA8;
    s32 fAC;
    s32 fB0;
    s32 fB4;
} S_00682840;

typedef struct {
    u8 pad0[0x48];
    s32 f48;
    s32 f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
} T_00682840;

S_00682840 *func_L39_00682840(S_00682840 *self, T_00682840 *o) {
    s32 v;

    func_L39_0067EE40(self, o);
    self->f60 = D_L39_0047BB78;
    self->fA0 = -1;
    self->fA4 = -1;
    self->fA8 = -1;
    v = o->f48;
    self->f64 = v;
    self->f68 = v + 1;
    self->f6C = o->f4C;
    self->f70 = o->f50;
    self->f74 = o->f54;
    self->fAC = o->f58;
    self->fB0 = o->f5C;
    self->fB4 = o->f60;
    return self;
}
/* localdecomp:end func_L39_00682840 */

/* localdecomp:start func_L39_006828D0 */
extern u8 D_L39_0047BB78[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006828D0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BB78;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_006828D0 */

/* localdecomp:start func_L39_006828F8 */
extern s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_006828F8(void *arg0, f32 fparg0, f32 fparg1) {
    s32 r = 0;
    s32 v;

    v = *(s32 *)((u8 *)arg0 + 0xA0);
    if (v != -1) {
        r = func_L01_00517538(v, fparg0, fparg1);
    }
    v = *(s32 *)((u8 *)arg0 + 0xA4);
    if (v != -1) {
        r |= func_L01_00517538(v, fparg0, fparg1);
    }
    v = *(s32 *)((u8 *)arg0 + 0xA8);
    if (v != -1) {
        r |= func_L01_00517538(v, fparg0, fparg1);
    }
    return r != 0;
}
/* localdecomp:end func_L39_006828F8 */

/* localdecomp:start func_L39_00682990 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_00682990(void *arg0, s32 arg1) {
    s32 r;

    r = 0;
    if (*(s32 *)((u8 *)arg0 + 0xA0) != -1) {
        r = func_003E7F20(*(s32 *)((u8 *)arg0 + 0xA0), arg1);
    }
    if (*(s32 *)((u8 *)arg0 + 0xA4) != -1) {
        r |= func_003E7F20(*(s32 *)((u8 *)arg0 + 0xA4), arg1);
    }
    if (*(s32 *)((u8 *)arg0 + 0xA8) != -1) {
        r |= func_003E7F20(*(s32 *)((u8 *)arg0 + 0xA8), arg1);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00682990 */

/* localdecomp:start func_L39_00682A20 */
s32 func_L39_00688340(s32, s32, s32);

s32 func_L39_00682A20(void *arg0, s32 arg1) {
    s32 ret = 0;

    if (arg1 == 4 || arg1 == 7) {
        s32 t = *(s32 *)((u8 *)arg0 + 0x64) + *(s32 *)((u8 *)arg0 + 0x74);
        *(s32 *)((u8 *)arg0 + 0x64) = t;
        if (*(s32 *)((u8 *)arg0 + 0x70) < t) {
            *(s32 *)((u8 *)arg0 + 0x64) = *(s32 *)((u8 *)arg0 + 0x6C);
        }
    } else if (arg1 == 3) {
        s32 t = *(s32 *)((u8 *)arg0 + 0x64) - *(s32 *)((u8 *)arg0 + 0x74);
        *(s32 *)((u8 *)arg0 + 0x64) = t;
        if (t < *(s32 *)((u8 *)arg0 + 0x6C)) {
            *(s32 *)((u8 *)arg0 + 0x64) = *(s32 *)((u8 *)arg0 + 0x70);
        }
    } else {
        goto done;
    }
    func_L39_00688340(3, 0, 0);
    ret = 1;
done:
    return ret;
}
/* localdecomp:end func_L39_00682A20 */

/* localdecomp:start func_L39_00682AB8 */
void func_L39_00682AB8(void *arg0, s32 arg1) {
    s32 lo = *(s32 *)((u8 *)arg0 + 0x70);

    if (lo < arg1) {
        *(s32 *)((u8 *)arg0 + 0x64) = lo;
        return;
    }
    lo = *(s32 *)((u8 *)arg0 + 0x6C);
    if (arg1 < lo) {
        *(s32 *)((u8 *)arg0 + 0x64) = lo;
        return;
    }
    *(s32 *)((u8 *)arg0 + 0x64) = arg1;
}
/* localdecomp:end func_L39_00682AB8 */

/* localdecomp:start func_L39_00682AE8 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00682AE8(void *arg0, s32 arg1, s32 arg2) {
    s32 r = 0;
    s32 v;

    v = *(s32 *)((u8 *)arg0 + 0xA0);
    if (v != -1) {
        r = func_L01_00516AA0(v, arg1, arg2);
    }
    v = *(s32 *)((u8 *)arg0 + 0xA4);
    if (v != -1) {
        r |= func_L01_00516AA0(v, arg1, arg2);
    }
    v = *(s32 *)((u8 *)arg0 + 0xA8);
    if (v != -1) {
        r |= func_L01_00516AA0(v, arg1, arg2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00682AE8 */
