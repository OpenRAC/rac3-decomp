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

INCLUDE_ASM("asm/levels", func_L39_0067FC50);

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

INCLUDE_ASM("asm/levels", func_L39_0067FD38);

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

INCLUDE_ASM("asm/levels", func_L39_00680010);

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

/* localdecomp:start func_L39_00680390 */
typedef struct {
    char _p0[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_680390;

/* from rac4-decomp's func_L00_0053BEF0 */
void func_L39_00680390(S_680390 *arg0) {
    arg0->f68 = -1;
    arg0->f6C = -1;
    arg0->f70 = -1;
}
/* localdecomp:end func_L39_00680390 */

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

/* localdecomp:start func_L39_006805A0 */
typedef struct E_006805A0 {
    char name[0x50];
} E_006805A0;
typedef struct S_006805A0 {
    u8 pad[0x60];
    void *vtbl;
    s32 count;
    E_006805A0 items[0x40];
    s32 f1468;
    s32 f146C;
    s32 f1470;
    s32 f1474;
    s32 f1478;
    s32 f147C;
} S_006805A0;
typedef struct A_006805A0 {
    u8 pad[0x48];
    s32 count;
    void **src;
    s32 f50;
} A_006805A0;

extern u8 D_L39_0047B8A0[];
extern void *func_L39_0067EE40(void *, void *);
extern void func_00120D28(void *, void *, s32);

S_006805A0 *func_L39_006805A0(S_006805A0 *self, A_006805A0 *a) {
    s32 i;
    s32 n;

    func_L39_0067EE40(self, a);
    self->vtbl = D_L39_0047B8A0;
    n = a->count;
    self->count = n;
    self->f1470 = -1;
    self->f1474 = -1;
    self->f1478 = -1;
    self->f147C = 0;
    if (n > 0x40) {
        self->count = 0x40;
    }
    for (i = 0; i < self->count; i++) {
        if (a->src[i] != 0) {
            func_00120D28(self->items[i].name, a->src[i], 0x50);
            self->items[i].name[0x4F] = 0;
        } else {
            self->items[i].name[0] = 0;
        }
    }
    self->f1468 = a->f50;
    return self;
}
/* localdecomp:end func_L39_006805A0 */

/* localdecomp:start func_L39_00680688 */
extern u8 D_L39_0047B8A0[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00680688(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047B8A0;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00680688 */

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

/* localdecomp:start func_L39_006808F0 */
s32 func_L01_00517538(s32, f32, f32);

s32 func_L39_006808F0(void *arg0, f32 fparg0, f32 fparg1) {
    s32 ret = 0;
    s32 temp;

    temp = *(s32 *)((u8 *)arg0 + 0x1470);
    if (temp != -1) {
        ret = func_L01_00517538(temp, fparg0, fparg1);
    }
    temp = *(s32 *)((u8 *)arg0 + 0x1474);
    if (temp != -1) {
        ret |= func_L01_00517538(temp, fparg0, fparg1);
    }
    temp = *(s32 *)((u8 *)arg0 + 0x1478);
    if (temp != -1) {
        ret |= func_L01_00517538(temp, fparg0, fparg1);
    }
    return ret != 0;
}
/* localdecomp:end func_L39_006808F0 */

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

/* localdecomp:start func_L39_00680A20 */
typedef struct E_00680A20 {
    char name[0x50];
} E_00680A20;
typedef struct S_00680A20 {
    u8 pad[0x64];
    s32 count;
    E_00680A20 items[0x40];
    s32 f1468;
    s32 f146C;
} S_00680A20;

extern void func_00120D28(void *, void *, s32);

s32 func_L39_00680A20(S_00680A20 *self, s32 count, void **src) {
    s32 i;

    self->count = count;
    if (count > 0x40) {
        self->count = 0x40;
    }
    for (i = 0; i < self->count; i++) {
        if (src[i] != 0) {
            func_00120D28(self->items[i].name, src[i], 0x50);
            self->items[i].name[0x4F] = 0;
        } else {
            self->items[i].name[0] = 0;
        }
    }
    if (self->count > 0) {
        self->f1468 = 0;
    } else {
        self->f1468 = -1;
    }
    self->f146C = self->f1468;
    return self->count;
}
/* localdecomp:end func_L39_00680A20 */

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

/* localdecomp:start func_L39_00680C78 */
typedef struct {
    char _p0[0x1470];
    s32 f1470;
    s32 f1474;
    s32 f1478;
} S1_00680C78;

/* from rac4-decomp's func_L00_0053BEF0 */
void func_L39_00680C78(S1_00680C78 *arg0) {
    arg0->f1470 = -1;
    arg0->f1474 = -1;
    arg0->f1478 = -1;
}
/* localdecomp:end func_L39_00680C78 */

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

/* localdecomp:start func_L39_00680F08 */
typedef struct {
    u8 pad[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    u8 f6C;
    s32 f70;
    s32 f74;
    u8 f78;
    s32 f7C;
    s32 f80;
} S_00680F08;
typedef struct {
    u8 pad[0x48];
    u8 f48;
    s32 f4C;
} S_00680F08_b;
extern u8 D_L39_0047B990[];
void *func_L39_0067EE40(void *, void *);

void *func_L39_00680F08(u8 *a0, u8 *a1) {
    S_00680F08 *arg0 = (S_00680F08 *)a0;
    S_00680F08_b *arg1 = (S_00680F08_b *)a1;
    func_L39_0067EE40(a0, a1);
    arg0->f64 = -1;
    arg0->f60 = D_L39_0047B990;
    arg0->f68 = -1;
    arg0->f7C = arg1->f4C;
    arg0->f70 = -1;
    arg0->f6C = arg1->f48;
    arg0->f80 = 0x80808080;
    arg0->f74 = 0;
    arg0->f78 = 0;
    return a0;
}
/* localdecomp:end func_L39_00680F08 */

/* localdecomp:start func_L39_00680F80 */
extern u8 D_L39_0047B990[];
extern void func_L39_0067EEC8(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00680F80(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047B990;
    func_L39_0067EEC8(object, flags);
}
/* localdecomp:end func_L39_00680F80 */

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

/* localdecomp:start func_L39_00681130 */
void func_L39_00681330(void *);

void func_L39_00681130(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
    *(s32 *)((u8 *)arg0 + 0x68) = -1;
    func_L39_00681330(arg0);
}
/* localdecomp:end func_L39_00681130 */

INCLUDE_ASM("asm/levels", func_L39_00681158);

INCLUDE_ASM("asm/levels", func_L39_00681330);

/* localdecomp:start func_L39_006813F8 */
__asm__(".extern D_L39_0024B9C8, 16");
__asm__(".extern D_L39_00247514, 16");
__asm__(".extern D_L39_0024CAD8, 16");
extern s32 D_L39_0025F680[];
extern s32 D_L39_0024B9C8;
extern s32 D_L39_00247514;
extern s32 D_L39_0024CAD8;
extern s32 D_001DBE00_sda;
extern s32 D_001DBE10_sda;
void func_003A92F0(s32);
void func_003A9108(void);
s32 func_00139E08(s32);

void func_L39_006813F8(void) {
    func_003A92F0(1);
    func_00139E08(0);
    D_L39_0024B9C8++;
    D_001DBE00_sda = D_L39_0025F680[3] + 0x80000;
    D_L39_00247514 = D_001DBE00_sda + 0x40000;
    D_001DBE10_sda = D_L39_0025F680[4] + 0x80000;
    D_L39_0024CAD8 = 0x80000;
    func_003A9108();
}
/* localdecomp:end func_L39_006813F8 */

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
