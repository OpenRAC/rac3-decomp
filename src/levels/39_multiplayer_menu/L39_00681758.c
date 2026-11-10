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

INCLUDE_ASM("asm/levels", func_L39_00681758);

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

INCLUDE_ASM("asm/levels", func_L39_00681A40);

INCLUDE_ASM("asm/levels", func_L39_00681CA8);

INCLUDE_ASM("asm/levels", func_L39_00681D78);

/* localdecomp:start func_L39_00682018 */
void func_L39_00682018(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x1057C) = arg1;
}
/* localdecomp:end func_L39_00682018 */

INCLUDE_ASM("asm/levels", func_L39_00682028);

INCLUDE_ASM("asm/levels", func_L39_00682098);

INCLUDE_ASM("asm/levels", func_L39_006820D0);

INCLUDE_ASM("asm/levels", func_L39_00682108);

INCLUDE_ASM("asm/levels", func_L39_00682148);

INCLUDE_ASM("asm/levels", func_L39_00682180);

/* localdecomp:start func_L39_006821C0 */
void func_L39_006821C0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x4C) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x48) = 1;
}
/* localdecomp:end func_L39_006821C0 */

INCLUDE_ASM("asm/levels", func_L39_006821D0);

/* localdecomp:start func_L39_006822E8 */
void func_L39_006822E8(void *arg0)
{
    *(s32 *)((u8 *)arg0 + 0x10170) = -1;
    *(s32 *)((u8 *)arg0 + 0x10174) = -1;
    *(s32 *)((u8 *)arg0 + 0x10178) = -1;
}
/* localdecomp:end func_L39_006822E8 */

INCLUDE_ASM("asm/levels", func_L39_00682308);

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

INCLUDE_ASM("asm/levels", func_L39_00682840);

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

INCLUDE_ASM("asm/levels", func_L39_00682B80);

/* localdecomp:start func_L39_00682C88 */
s32 func_L01_00516C78(s32, s32, s32);

void func_L39_00682C88(void *arg0, s32 arg1) {
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
    if ((*(s32 *)((u8 *)arg0 + 0xA8)) != -1) {
        func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0xA8)), var_a1, 3);
    }
}
/* localdecomp:end func_L39_00682C88 */

/* localdecomp:start func_L39_00682CE8 */
typedef struct S_682CE8 {
    char _p0[0xA0];
    s32 fA0;
    s32 fA4;
    s32 fA8;
} S_682CE8;

/* from rac4-decomp's func_L00_0053BEF0 */
void func_L39_00682CE8(S_682CE8 *arg0) {
    arg0->fA0 = -1;
    arg0->fA4 = -1;
    arg0->fA8 = -1;
}
/* localdecomp:end func_L39_00682CE8 */

INCLUDE_ASM("asm/levels", func_L39_00682D00);

/* localdecomp:start func_L39_00682F90 */
void func_L39_00682F90(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
}
/* localdecomp:end func_L39_00682F90 */

/* localdecomp:start func_L39_00682F98 */
s32 func_L39_00682F98(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64));
}
/* localdecomp:end func_L39_00682F98 */

/* localdecomp:start func_L39_00682FA0 */
s32 func_L39_00682FA0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x64)) != *(s32 *)((u8 *)arg0 + 0x68);
}
/* localdecomp:end func_L39_00682FA0 */

LINKER_REMNANT("asm/levels", func_L39_00682FB8);

INCLUDE_ASM("asm/levels", func_L39_00682FC0);

/* localdecomp:start func_L39_00683038 */
extern u8 D_L39_0047BC68[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00683038(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BC68;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00683038 */

INCLUDE_ASM("asm/levels", func_L39_00683060);

/* localdecomp:start func_L39_00683180 */
typedef struct S_00683180 {
    u8 pad0[0x64];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683180;

void func_L39_00683180(S_00683180 *arg0) {
    arg0->f6C = -1;
    arg0->f70 = -1;
    arg0->f74 = -1;
    arg0->f64 = -1;
    arg0->f68 = -1;
}
/* localdecomp:end func_L39_00683180 */

/* localdecomp:start func_L39_006831A0 */
s32 func_L39_00688340(s32, s32, s32);

s32 func_L39_006831A0(void *arg0, s32 arg1) {
    s32 r = 0;
    s32 cur;

    if (arg1 == 4 || arg1 == 7) {
        r = 1;
        *(s32 *)((u8 *)arg0 + 0x80) += *(s32 *)((u8 *)arg0 + 0x84);
        func_L39_00688340(3, 0, 0);
    } else if (arg1 == 3) {
        r = 1;
        *(s32 *)((u8 *)arg0 + 0x80) -= *(s32 *)((u8 *)arg0 + 0x84);
        func_L39_00688340(3, 0, 0);
    }
    cur = *(s32 *)((u8 *)arg0 + 0x80);
    if (*(s32 *)((u8 *)arg0 + 0x7C) < cur) {
        *(s32 *)((u8 *)arg0 + 0x80) = *(s32 *)((u8 *)arg0 + 0x7C);
    } else if (cur < *(s32 *)((u8 *)arg0 + 0x78)) {
        *(s32 *)((u8 *)arg0 + 0x80) = *(s32 *)((u8 *)arg0 + 0x78);
    }
    return r;
}
/* localdecomp:end func_L39_006831A0 */

INCLUDE_ASM("asm/levels", func_L39_00683268);

/* localdecomp:start func_L39_00683420 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_00683420(u8 *arg0, s32 arg1) {
    s32 mode = 2;

    if (arg1 == 1) {
        mode = 1;
    }
    if (*(s32 *)(arg0 + 0x64) != -1) {
        func_003E7F20(*(s32 *)(arg0 + 0x64), mode);
    }
    if (*(s32 *)(arg0 + 0x68) != -1) {
        func_003E7F20(*(s32 *)(arg0 + 0x68), mode);
    }
    return 1;
}
/* localdecomp:end func_L39_00683420 */

/* localdecomp:start func_L39_00683490 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00683490(void *arg0, s32 arg1, s32 arg2) {
    s32 r = 0;

    if (*(s32 *)((u8 *)arg0 + 0x64) != -1) {
        r = func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x64), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0x68) != -1) {
        r |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x68), arg1, arg2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00683490 */

/* localdecomp:start func_L39_00683510 */
void func_L39_00683510(void *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = *(s32 *)((u8 *)arg0 + 0x7C);
    *(s32 *)((u8 *)arg0 + 0x80) = arg1;
    if ((var_v1 < arg1) || (var_v1 = (*(s32 *)((u8 *)arg0 + 0x78)), ((arg1 < var_v1) != 0))) {
        *(s32 *)((u8 *)arg0 + 0x80) = var_v1;
    }
}
/* localdecomp:end func_L39_00683510 */

/* localdecomp:start func_L39_00683540 */
s32 func_L39_00683540(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x80));
}
/* localdecomp:end func_L39_00683540 */

LINKER_REMNANT("asm/levels", func_L39_00683548);

/* localdecomp:start func_L39_00683550 */
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern u8 D_L39_0047BD58[];

S_00683550 *func_L39_00683550(S_00683550 *self, T_00683550 *o) {
    func_L39_0067EE40(self, o);
    self->f60 = D_L39_0047BD58;
    self->f64 = -1;
    self->f68 = -1;
    self->f6C = -1;
    self->f70 = -1;
    self->f74 = o->f48;
    return self;
}
/* localdecomp:end func_L39_00683550 */

/* localdecomp:start func_L39_006835B0 */
extern u8 D_L39_0047BD58[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006835B0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BD58;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_006835B0 */

INCLUDE_ASM("asm/levels", func_L39_006835D8);

/* localdecomp:start func_L39_00683718 */
typedef struct {
    char _p0[0x64];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
} S_683718;

/* from rac4-decomp's func_L00_004F7328 */
void func_L39_00683718(S_683718 *arg0) {
    arg0->f64 = -1;
    arg0->f68 = -1;
    arg0->f6C = -1;
    arg0->f70 = -1;
}
/* localdecomp:end func_L39_00683718 */

/* localdecomp:start func_L39_00683730 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_00683730(void *arg0, s32 arg1) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x64);

    if (v != -1) {
        return func_003E7F20(v, arg1);
    }
    return 0;
}
/* localdecomp:end func_L39_00683730 */

INCLUDE_ASM("asm/levels", func_L39_00683760);

INCLUDE_ASM("asm/levels", func_L39_006837E8);

/* localdecomp:start func_L39_00683818 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00683818(void *arg0, s32 arg1, s32 arg2) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x64);

    if (v != -1) {
        return func_L01_00516AA0(v, arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_00683818 */

INCLUDE_ASM("asm/levels", func_L39_00683848);

INCLUDE_ASM("asm/levels", func_L39_00683A30);

/* localdecomp:start func_L39_00683A90 */
extern u8 D_L39_0047BE48[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00683A90(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BE48;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00683A90 */

/* localdecomp:start func_L39_00683AB8 */
extern s32 func_L01_00516C78(s32, s32, s32);

s32 func_L39_00683AB8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_s2 = 0;

    if (*(s32 *)((u8 *)arg0 + 0xB4) != -1) {
        var_s2 = func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0xB4), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xB8) != -1) {
        var_s2 |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0xB8), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xBC) != -1) {
        var_s2 |= func_L01_00516C78(*(s32 *)((u8 *)arg0 + 0xBC), arg1, arg2);
    }
    return var_s2 != 0;
}
/* localdecomp:end func_L39_00683AB8 */

/* localdecomp:start func_L39_00683B50 */
s32 func_L39_00683B50(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0xCC) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00683B50 */

INCLUDE_ASM("asm/levels", func_L39_00683B60);

/* localdecomp:start func_L39_00683BA8 */
s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_00683BA8(void *arg0, f32 fa, f32 fb) {
    s32 r;

    r = 0;
    if (*(s32 *)((u8 *)arg0 + 0xB4) != -1) {
        r = func_L01_00517538(*(s32 *)((u8 *)arg0 + 0xB4), fa, fb);
    }
    if (*(s32 *)((u8 *)arg0 + 0xB8) != -1) {
        r |= func_L01_00517538(*(s32 *)((u8 *)arg0 + 0xB8), fa, fb);
    }
    if (*(s32 *)((u8 *)arg0 + 0xBC) != -1) {
        r |= func_L01_00517538(*(s32 *)((u8 *)arg0 + 0xBC), fa, fb);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00683BA8 */

/* localdecomp:start func_L39_00683C40 */
s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_00683C40(void *arg0, s32 arg1, s32 arg2) {
    s32 r;

    r = 0;
    if (*(s32 *)((u8 *)arg0 + 0xB4) != -1) {
        r = func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB4), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xB8) != -1) {
        r |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xB8), arg1, arg2);
    }
    if (*(s32 *)((u8 *)arg0 + 0xBC) != -1) {
        r |= func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0xBC), arg1, arg2);
    }
    return r != 0;
}
/* localdecomp:end func_L39_00683C40 */

/* localdecomp:start func_L39_00683CD8 */
s32 func_L39_00683CD8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0xC8) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00683CD8 */

INCLUDE_ASM("asm/levels", func_L39_00683CE8);

INCLUDE_ASM("asm/levels", func_L39_00683EB8);

INCLUDE_ASM("asm/levels", func_L39_00683FF8);

INCLUDE_ASM("asm/levels", func_L39_00684130);

INCLUDE_ASM("asm/levels", func_L39_00684190);

/* localdecomp:start func_L39_00684218 */
typedef struct {
    char _p0[0xB4];
    s32 fB4;
    s32 fB8;
    s32 fBC;
} S_684218;

/* from rac4-decomp's func_L00_0053BEF0 */
void func_L39_00684218(S_684218 *arg0) {
    arg0->fB4 = -1;
    arg0->fB8 = -1;
    arg0->fBC = -1;
}
/* localdecomp:end func_L39_00684218 */

INCLUDE_ASM("asm/levels", func_L39_00684230);

/* localdecomp:start func_L39_00684488 */
void func_0011D534(s32, s32, s32);

void func_L39_00684488(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0x50);
}
/* localdecomp:end func_L39_00684488 */

/* localdecomp:start func_L39_006844B0 */
void func_L39_006844B0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
    *(s32 *)((u8 *)arg0 + 0xC0) = 1;
}
/* localdecomp:end func_L39_006844B0 */

/* localdecomp:start func_L39_006844C0 */
void func_L39_006844C0(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x4C) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x48) = 1;
}
/* localdecomp:end func_L39_006844C0 */

/* localdecomp:start func_L39_006844D0 */
s32 func_L39_006844D0(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_006844D0 */

LINKER_REMNANT("asm/levels", func_L39_006844D8);

INCLUDE_ASM("asm/levels", func_L39_006844E0);

/* localdecomp:start func_L39_00684528 */
extern u8 D_L39_0047BF38[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00684528(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047BF38;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00684528 */

/* localdecomp:start func_L39_00684550 */
void func_L39_00684550(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x464) = arg1;
}
/* localdecomp:end func_L39_00684550 */

/* localdecomp:start func_L39_00684558 */
s32 func_L39_00684558(void *arg0, f32 fa, f32 fb) {
    if (*(s32 *)((u8 *)arg0 + 0x468) != -1) {
        *(f32 *)((u8 *)arg0 + 0x58) = fa;
        *(f32 *)((u8 *)arg0 + 0x5C) = fb;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00684558 */

/* localdecomp:start func_L39_00684580 */
void func_L39_00684580(void *arg0, f32 fa, f32 fb) {
    if (*(s32 *)((u8 *)arg0 + 0x468) != -1) {
        *(f32 *)((u8 *)arg0 + 0x50) = fa;
        *(f32 *)((u8 *)arg0 + 0x54) = fb;
    }
}
/* localdecomp:end func_L39_00684580 */

/* localdecomp:start func_L39_006845A0 */
extern s32 func_L01_00516818(s32);

s32 func_L39_006845A0(void *arg0) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x468);

    if (v != -1) {
        return func_L01_00516818(v);
    }
    return 0;
}
/* localdecomp:end func_L39_006845A0 */

/* localdecomp:start func_L39_006845D0 */
extern s32 func_L01_00516AA0(s32, s32, s32);

s32 func_L39_006845D0(void *arg0, s32 arg1, s32 arg2) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x468);

    if (v != -1) {
        return func_L01_00516AA0(v, arg1, arg2);
    }
    return 0;
}
/* localdecomp:end func_L39_006845D0 */

/* localdecomp:start func_L39_00684600 */
extern s32 func_L01_00518670(s32);

s32 func_L39_00684600(void *arg0) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x468);

    if (v != -1) {
        return func_L01_00518670(v);
    }
    return 0;
}
/* localdecomp:end func_L39_00684600 */

/* localdecomp:start func_L39_00684630 */
s32 func_L39_00610CA8(s32);

s32 func_L39_00684630(void *arg0) {
    s32 temp_a0;
    s32 var_v1;

    temp_a0 = *(s32 *)((u8 *)arg0 + 0x468);
    var_v1 = 0;
    if (temp_a0 != -1) {
        var_v1 = func_L39_00610CA8(temp_a0);
    }
    return var_v1;
}
/* localdecomp:end func_L39_00684630 */

INCLUDE_ASM("asm/levels", func_L39_00684668);

INCLUDE_ASM("asm/levels", func_L39_006846B0);

/* localdecomp:start func_L39_00684728 */
void func_L39_00684728(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x468) = -1;
}
/* localdecomp:end func_L39_00684728 */

/* localdecomp:start func_L39_00684738 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);

void func_L39_00684738(void *arg0) {
    f32 v[2];
    f32 fb;

    if (*(s32 *)((u8 *)arg0 + 0x468) == -1) {
        return;
    }
    if (*(s32 *)((u8 *)arg0 + 0x4) == 0) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x468), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x468), 1, 1);
    (*(s32 (**)(void *, void *, void *))((u8 *)(*(void **)((u8 *)arg0 + 0x60)) + 0x30))(arg0, v, &v[1]);
    if (*(s32 *)((u8 *)arg0 + 0x464) != 0) {
        func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0x468), *(s32 *)((u8 *)arg0 + 0x464));
    } else {
        func_L01_00516FD8(*(s32 *)((u8 *)arg0 + 0x468), (s32)((u8 *)arg0 + 0x64));
    }
    func_L01_00517538(*(s32 *)((u8 *)arg0 + 0x468), *(f32 *)((u8 *)arg0 + 0x58), *(f32 *)((u8 *)arg0 + 0x5C));
    fb = v[1];
    func_L01_00516470(*(s32 *)((u8 *)arg0 + 0x468), v[0], fb);
    func_L01_005170B8(*(s32 *)((u8 *)arg0 + 0x468), 0x8066CCFF);
}
/* localdecomp:end func_L39_00684738 */

/* localdecomp:start func_L39_006847F8 */
void func_0011D534(s32, s32, s32);

void func_L39_006847F8(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0x400);
}
/* localdecomp:end func_L39_006847F8 */

/* localdecomp:start func_L39_00684820 */
void func_00120D28(s32, s32, s32);
void func_L39_00684820(void *arg0, s32 arg1) {
    func_00120D28(arg0 + 0x64, arg1, 0x400);
    *(s8 *)((u8 *)arg0 + 0x463) = 0;
}
/* localdecomp:end func_L39_00684820 */

/* localdecomp:start func_L39_00684850 */
s32 func_L39_00684850(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_00684850 */

LINKER_REMNANT("asm/levels", func_L39_00684858);

INCLUDE_ASM("asm/levels", func_L39_00684860);

/* localdecomp:start func_L39_00684A68 */
extern u8 D_L39_0047C028[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00684A68(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C028;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00684A68 */

INCLUDE_ASM("asm/levels", func_L39_00684A90);

/* localdecomp:start func_L39_00684B58 */
s32 func_L39_00684B58(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x248) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00684B58 */

INCLUDE_ASM("asm/levels", func_L39_00684B68);

/* localdecomp:start func_L39_00684C30 */
extern s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_00684C30(void *arg0, f32 fparg0, f32 fparg1) {
    s32 v = *(s32 *)((u8 *)arg0 + 0x138);

    if (v != -1) {
        return func_L01_00517538(v, fparg0, fparg1);
    }
    return 0;
}
/* localdecomp:end func_L39_00684C30 */

INCLUDE_ASM("asm/levels", func_L39_00684C60);

INCLUDE_ASM("asm/levels", func_L39_00684D28);

INCLUDE_ASM("asm/levels", func_L39_006850F8);

/* localdecomp:start func_L39_006852C8 */
extern s32 func_003E7F20(s32, s32);

s32 func_L39_006852C8(void *arg0, s32 arg1) {
    s32 v;

    *(s32 *)((u8 *)arg0 + 0x240) = arg1;
    v = 2;
    if (arg1 == 1) {
        v = 1;
    }
    if (*(s32 *)((u8 *)arg0 + 0x130) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x130), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x134) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x134), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x138) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x138), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x13C) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x13C), v);
    }
    if (*(s32 *)((u8 *)arg0 + 0x140) != -1) {
        func_003E7F20(*(s32 *)((u8 *)arg0 + 0x140), v);
    }
    return 1;
}
/* localdecomp:end func_L39_006852C8 */

/* localdecomp:start func_L39_00685378 */
void func_L39_00685378(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x130) = -1;
    *(s32 *)((u8 *)arg0 + 0x134) = -1;
    *(s32 *)((u8 *)arg0 + 0x138) = -1;
    *(s32 *)((u8 *)arg0 + 0x13C) = -1;
    *(s32 *)((u8 *)arg0 + 0x140) = -1;
}
/* localdecomp:end func_L39_00685378 */

INCLUDE_ASM("asm/levels", func_L39_00685398);

/* localdecomp:start func_L39_00685998 */
void func_L39_00685998(void *arg0, f32 fparg0) {
    *(f32 *)((u8 *)arg0 + 0x58) = fparg0;
    *(s32 *)((u8 *)arg0 + 0x23C) = 1;
}
/* localdecomp:end func_L39_00685998 */

/* localdecomp:start func_L39_006859A8 */
void func_0011D534(s32, s32, s32);

void func_L39_006859A8(s32 arg0) {
    func_0011D534(arg0 + 0x64, 0, 0xC8);
    func_0011D534(arg0 + 0x3DC, 0, 0xC8);
}
/* localdecomp:end func_L39_006859A8 */

INCLUDE_ASM("asm/levels", func_L39_006859E8);

/* localdecomp:start func_L39_00685A78 */
s32 func_L39_00685A78(s32 arg0) {
    return arg0 + 0x64;
}
/* localdecomp:end func_L39_00685A78 */

/* localdecomp:start func_L39_00685A80 */
typedef struct Type1 {
    char _p0[0x144];
    u8 f144[32];
} Type1;

/* from rac4-decomp's func_L00_00717A08 */
void func_L39_00685A80(Type1 *arg0, u8 arg1) {
    arg0->f144[arg1 >> 3] |= 1 << (arg1 & 7);
}
/* localdecomp:end func_L39_00685A80 */

/* localdecomp:start func_L39_00685AB0 */
typedef struct {
    char _p0[0x144];
    u8 flags[32];
} S_685AB0;

/* from rac4-decomp's func_L00_00717A38 */
void func_L39_00685AB0(S_685AB0 *arg0, u8 arg1) {
    arg0->flags[arg1 >> 3] &= ~(1 << (arg1 & 7));
}
/* localdecomp:end func_L39_00685AB0 */

INCLUDE_ASM("asm/levels", func_L39_00685AE0);

INCLUDE_ASM("asm/levels", func_L39_00685B50);

LINKER_REMNANT("asm/levels", func_L39_00685BC0);

INCLUDE_ASM("asm/levels", func_L39_00685BC8);

/* localdecomp:start func_L39_00685C48 */
extern u8 D_L39_0047C118[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00685C48(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C118;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00685C48 */

INCLUDE_ASM("asm/levels", func_L39_00685C70);

/* localdecomp:start func_L39_00685CE8 */
void func_L39_00685CE8(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
}
/* localdecomp:end func_L39_00685CE8 */

/* localdecomp:start func_L39_00685CF8 */
extern void func_L01_005168F0(s32);

void func_L39_00685CF8(void *arg0, f32 fparg0) {
    s32 v;

    *(f32 *)((u8 *)arg0 + 0x70) = fparg0;
    v = *(s32 *)((u8 *)arg0 + 0x64);
    if (v >= 0) {
        func_L01_005168F0(v);
    }
}
/* localdecomp:end func_L39_00685CF8 */

/* localdecomp:start func_L39_00685D28 */
s32 func_L39_00685D28(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x68) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00685D28 */

/* localdecomp:start func_L39_00685D38 */
s32 func_L39_00685D38(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)arg0 + 0x6C) = arg1;
    return 1;
}
/* localdecomp:end func_L39_00685D38 */

/* localdecomp:start func_L39_00685D48 */
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00517190(s32, s32);


void func_L39_00685D48(void *arg0) {
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x3;

    if (*(s32 *)((u8 *)arg0 + 0x64) == -1) {
        return;
    }
    if (*(s32 *)((u8 *)arg0 + 0x4) == 0) {
        func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x64), 1, 0);
        return;
    }
    func_L01_00516AA0(*(s32 *)((u8 *)arg0 + 0x64), 1, 1);
    (*(Vt_00685D48 **)((u8 *)arg0 + 0x60))->f30(arg0, &x0, &x1);
    func_L01_00516470(*(s32 *)((u8 *)arg0 + 0x64), x0, x1);
    (*(Vt_00685D48 **)((u8 *)arg0 + 0x60))->f34(arg0, &x2, &x3);
    func_L01_00517538(*(s32 *)((u8 *)arg0 + 0x64), x2, x3);
    func_L01_005170B8(*(s32 *)((u8 *)arg0 + 0x64), *(s32 *)((u8 *)arg0 + 0x6C));
    func_L01_00517190(*(s32 *)((u8 *)arg0 + 0x64), *(s32 *)((u8 *)arg0 + 0x68));
}
/* localdecomp:end func_L39_00685D48 */

/* localdecomp:start func_L39_00685E08 */
extern u8 D_L39_0047C208[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00685E08(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C208;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00685E08 */

INCLUDE_ASM("asm/levels", func_L39_00685E30);

INCLUDE_ASM("asm/levels", func_L39_00685FF0);

INCLUDE_ASM("asm/levels", func_L39_00686048);

INCLUDE_ASM("asm/levels", func_L39_00686138);

INCLUDE_ASM("asm/levels", func_L39_006862D0);

/* localdecomp:start func_L39_00686768 */
void func_L39_00686768(void *arg0) {
    S_00686768 *s = arg0;
    u8 *self = arg0;
    s32 i;
    s32 n = *(s32 *)(self + 0x270);
    if (n >= 0) {
        u8 *o = s->arr[n];
        u8 *vt = *(u8 **)(o + 0x60);
        Fn_00686768 f = *(Fn_00686768 *)(vt + 0x18);
        f(o);
    }
    for (i = *(s32 *)(self + 0x270) + 1; i <= *(s32 *)(self + 0x274); i++) {
        u8 *o = ((u8 **)(self + 0x110))[i];
        u8 *vt = *(u8 **)(o + 0x60);
        Fn_00686768 f = *(Fn_00686768 *)(vt + 0x18);
        f(o);
    }
}
/* localdecomp:end func_L39_00686768 */

INCLUDE_ASM("asm/levels", func_L39_00686810);

INCLUDE_ASM("asm/levels", func_L39_00686E40);

INCLUDE_ASM("asm/levels", func_L39_00687268);

INCLUDE_ASM("asm/levels", func_L39_006872E8);
