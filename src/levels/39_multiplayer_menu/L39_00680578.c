#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
extern void *func_L39_0067EE40(void *, void *);
extern void func_L39_0067EEC8(u8 *, s32);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

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

/* localdecomp:start func_L39_00680870 */
s32 func_L01_00518010(s32, s32);
s32 func_003E8898(s32, f32, f32);

s32 func_L39_00680870(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    if (*(s32 *)((u8 *)arg0 + 0x1478) != -1 && func_L01_00518010(*(s32 *)((u8 *)arg0 + 0x1478), arg1)) {
        if (arg1 != 0) {
            func_003E8898(*(s32 *)((u8 *)arg0 + 0x1478), arg2, arg3);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00680870 */

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
