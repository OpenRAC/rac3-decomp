#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005051E0);

/* localdecomp:start func_L39_005051F0 */
/* FAILED: 16-byte sd save slots (library-code signature); prototypes/body below are a draft */
extern u8 D_L39_00453D48[];
extern void func_L39_004DFB38(void *);
extern void func_L39_004DFB88(void *, void *, void *);
extern void func_L39_004E00C8(void *, void *);
extern void func_0011D534(void *, s32, s32);

void *func_L39_005051F0(void *arg0, void *arg1, void *arg2) {
    u8 local[0x5C];
    if (arg2 == 0) {
        arg2 = D_L39_00453D48;
    }
    func_L39_004DFB38(local);
    func_L39_004DFB88(local, arg0, arg1);
    func_L39_004E00C8(arg2, local);
    func_0011D534(local, 0, 0x5C);
    return arg2;
}
/* localdecomp:end func_L39_005051F0 */

/* localdecomp:start func_L39_00505270 */
typedef struct {
    u8 pad0[0xC];
    void *fC;
} S_00505270;
extern S_00505270 *D_0019D880 __attribute__((section(".data")));
extern u8 D_L39_004795B8[];
extern u8 D_L39_004795D0[];
extern void *func_L39_0050C218(void);
extern s32 func_L39_0050C230(void *, s32, void *, s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern s32 func_00120884(void *);
extern void func_0011AF90(void *, void *, s32);

s32 func_L39_00505270(void *arg0, s32 arg1, s32 arg2) {
    void *p;
    s32 r;

    p = func_L39_0050C218();
    if (p == 0) {
        p = D_L39_004795B8;
    }
    while (1) {
        if (func_L39_0050C230(arg0, arg1, p, arg2) != 0) {
            func_L39_004BC6C8(9, 0x77, 0x6D, 0, 0);
            func_0011D534(arg0, 0, arg1);
            return -1;
        }
        r = func_00120884(arg0);
        if (r >= 4) {
            return r;
        }
        func_0011AF90(D_0019D880->fC, D_L39_004795D0, 4);
    }
}
/* localdecomp:end func_L39_00505270 */

/* localdecomp:start func_L39_00505360 */
typedef struct {
    void *f0;
    void *f4;
    void *f8;
    int (*fC)(void *, int, int, int, int, int, int, int);
} Type1;
typedef struct {
    Type1 *f0;
} Type2;

/* from rac4-decomp's func_L00_0051EC00, renamed, constants adapted */
int func_L39_00505360(Type2 *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6) {
    return arg0->f0->fC(arg0, 10, arg1, arg2, arg3, arg4, arg5, arg6);
}
/* localdecomp:end func_L39_00505360 */

INCLUDE_ASM("asm/levels", func_L39_005053AC);

INCLUDE_ASM("asm/levels", func_L39_005053BC);

INCLUDE_ASM("asm/levels", func_L39_00505508);

/* localdecomp:start func_L39_00505620 */
extern s32 func_00120884(void *);
extern void *func_0011D380(void *, const void *, u32);

s32 func_L39_00505620(u8 *buf, s32 *out, s32 size, u8 *str, void *data, s32 len) {
    s32 n;
    s32 total;
    s32 l2;
    u8 *q;
    s32 hdr;

    n = func_00120884(str);
    hdr = len + 8;
    total = n + hdr;
    *out = total + 2;
    if (size < *out) {
        return 1;
    }
    l2 = total - 4;
    buf[0] = 0x30;
    buf[1] = total;
    buf[2] = 0x30;
    total = l2 - len;
    buf[3] = total;
    buf[4] = 6;
    buf[5] = n;
    func_0011D380(buf + 6, str, n);
    q = buf + 6 + n;
    q[0] = 5;
    q[1] = 0;
    q[2] = 4;
    q[3] = len;
    func_0011D380(q + 4, data, len);
    return 0;
}
/* localdecomp:end func_L39_00505620 */

/* localdecomp:start func_L39_00505718 */
/* Library code (Sony ee-gcc 2.9: 16-byte save slots): the file's flags are @ee29 -O2 -G8 -fno-strict-aliasing.
   From rac4-decomp's func_L00_00541528 (the same wrapper). In NTSC-U this call goes to another copy of
   func_L39_00505BB8 (jal 0x5059b8, where the catalogue's place resolves to 0x4c2258), so it is called through an alias
   named for this function's address (docs/build/levels.md, "an alias of one of these"). */
extern s32 func_L39_00505BB8_00505718(void);
extern s32 func_L39_0050C338(s32, s32, s32, s32, s32, s32);

s32 func_L39_00505718(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    return func_L39_0050C338(0, func_L39_00505BB8_00505718(), arg0, arg1, arg2, arg3);
}
/* localdecomp:end func_L39_00505718 */

/* localdecomp:start func_L39_00505780 */
typedef struct {
    s32 pad[5];
    s32 f14;
} S_505780;

extern void *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);

S_505780 *func_L39_00505780(void) {
    S_505780 *p = func_L39_004BEED8(0x18);
    if (p == 0) {
        return 0;
    }
    func_0011D534(p, 0, 0x18);
    p->f14 = 1;
    return p;
}
/* localdecomp:end func_L39_00505780 */

/* localdecomp:start func_L39_005057D0 */
s32 func_L39_004E4578(void *, s32, s32, s32, s32, s32);

void func_L39_005057D0(void *arg0, void *arg1, s32 arg2) {
    s32 var_a5;
    if (((*(s32 *)((u8 *)(arg1) + 0x14)) & 2) || (var_a5 = 0, ((arg2 & 2) != 0))) {
        var_a5 = 2;
    }
    func_L39_004E4578(arg0, (*(s32 *)((u8 *)(arg1) + 0)), (*(s32 *)((u8 *)(arg1) + 4)), (*(s32 *)((u8 *)(arg1) + 0xC)), (*(s32 *)((u8 *)(arg1) + 0x10)), var_a5);
    (*(s32 *)((u8 *)(arg0) + 8)) = (s32) (*(s32 *)((u8 *)(arg1) + 8));
}
/* localdecomp:end func_L39_005057D0 */

/* localdecomp:start func_L39_00505838 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 *fC;
    s32 f10;
    s32 f14;
} Item_00505838;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    Item_00505838 **fC;
    u8 *f10;
} S_00505838;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern void *func_0011D380(void *, const void *, u32);

s32 func_L39_00505838(s32 a0, s32 a1) {
    S_00505838 *arg0 = (S_00505838 *)a0;
    s32 total = 0;
    Item_00505838 **arr = arg0->fC;
    Item_00505838 *it;
    u8 *base;
    u8 *cur;
    s32 i;

    for (i = 0; i < arg0->f4; i++) {
        if (arr[i]->fC != 0) {
            total += arr[i]->f10;
        }
    }
    cur = func_L39_004BEED8(total);
    if (cur == 0) {
        return 2;
    }
    base = cur;
    for (i = 0; i < arg0->f4; i++) {
        it = arr[i];
        if (it->fC != 0 && it->f10 != 0) {
            func_0011D380(cur, it->fC, it->f10);
            if (it->f14 & 2) {
                func_L39_004BEF28(it->fC);
            }
            it->fC = cur;
            it->f14 &= ~2;
            cur += it->f10;
        }
    }
    if (arg0->f10 != 0) {
        func_L39_004BEF28(arg0->f10);
    }
    arg0->f10 = base;
    return 0;
}
/* localdecomp:end func_L39_00505838 */

INCLUDE_ASM("asm/levels", func_L39_00505974);

/* localdecomp:start func_L39_00505980 */
extern s32 D_L39_00453D58[];
extern s32 D_L39_00453D5C[];
extern s32 D_L39_00453D60[];
extern u32 D_L39_0046EBD0[];

s32 func_L39_00505980(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 < (u32) D_L39_0046EBD0[0]) {
        D_L39_0046EBD0[0] = arg0;
        D_L39_00453D60[0] = arg1;
        D_L39_00453D58[0] = arg2;
        D_L39_00453D5C[0] = arg3;
    }
    return 0;
}
/* localdecomp:end func_L39_00505980 */

/* localdecomp:start func_L39_005059C0 */
typedef struct {
    s32 f0;
    void *f4;
    void *f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} S_005059C0;

extern void *func_L39_004BEED8(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void *func_L39_004E47A8(void);
extern s32 func_L39_004E5090(void);
extern void func_L39_004E48A8(void *, s32, s32, s32, s32, s32, s32);
extern void func_L39_004E47F8(void *);
extern void func_L39_004BEF28(void *);

S_005059C0 *func_L39_005059C0(void *arg0) {
    S_005059C0 *p;
    S_005059C0 *ret = 0;

    if (arg0 == 0) {
        func_L39_004BC6C8(4, 0x6B, 0xE, 0, 0);
        return 0;
    }
    p = func_L39_004BEED8(0x1C);
    if (p == 0) {
        func_L39_004BC6C8(4, 0x6B, 0x21, 0, 0);
        return 0;
    }
    func_0011D534(p, 0, 0x1C);
    p->f8 = arg0;
    p->f10 = 1;
    p->fC = 0;
    p->f18 = 0;
    p->f4 = func_L39_004E47A8();
    if (p->f4 != 0) {
        p->f10 = 1;
        func_L39_004E48A8(p->f4, 1, 2, 0, func_L39_004E5090(), 0, 0);
        func_L39_004E48A8(p->f4, 1, 3, 0, 0, 0, 0);
        ret = p;
        p = 0;
    }
    if (p != 0) {
        if (p->f4 != 0) {
            func_L39_004E47F8(p->f4);
        }
        func_L39_004BEF28(p);
    }
    return ret;
}
/* localdecomp:end func_L39_005059C0 */

/* localdecomp:start func_L39_00505AE8 */
typedef struct {
    s32 f0;
    s32 f4;
} S_00505AE8;
extern S_00505AE8 *func_L39_004EA4A8(void);
extern s32 func_L39_0050C430(s32, s32, s32, void *);
extern s32 func_L39_00505838(s32, s32);
extern void func_L39_004EA410(S_00505AE8 *);

S_00505AE8 *func_L39_00505AE8(S_00505AE8 **arg0, s32 *arg1, s32 arg2) {
    S_00505AE8 *s = 0;
    s32 local;

    if (arg0 != 0) {
        s = *arg0;
    }
    if (s == 0) {
        s = func_L39_004EA4A8();
        if (s == 0) {
            goto out;
        }
    }
    if (func_L39_0050C430(s->f4, *arg1, arg2, &local) != 0 || func_L39_00505838(s->f4, 0) != 0) {
        if (arg0 == 0 || s != *arg0) {
            func_L39_004EA410(s);
        }
        s = 0;
    }
out:
    if (arg0 != 0 && s != 0) {
        *arg0 = s;
    }
    return s;
}
/* localdecomp:end func_L39_00505AE8 */
