#include "common.h"

/* declared by functions of L39_005066C0.c, which this file was cut from */
extern u8 D_L39_00507B18[];

/* localdecomp:start func_L39_00507878 */
/* log: v1 type-check then forward through the vtable */
typedef struct V_00507878 V_00507878;
typedef struct {
    u8 _p0[0xC];
    V_00507878 *vt;
} O_00507878;
struct V_00507878 {
    u8 _p0[0x10];
    s32 (*f10)(O_00507878 *, s32, s32, s32, s32, s32, s32, s32);
};
typedef struct {
    u8 _p0[0x28];
    O_00507878 *inner;
} S_00507878;

extern void func_L39_00507B18(void);
extern s32 func_L39_004F5D60(void *, void (*)(void));

s32 func_L39_00507878(S_00507878 *arg0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    s32 r = func_L39_004F5D60(arg0, func_L39_00507B18);
    if (r == 0) {
        r = arg0->inner->vt->f10(arg0->inner, a1, a2, a3, a4, a5, a6, a7);
    }
    return r;
}
/* localdecomp:end func_L39_00507878 */

INCLUDE_ASM("asm/levels", func_L39_00507930);

INCLUDE_ASM("asm/levels", func_L39_005079E8);

INCLUDE_ASM("asm/levels", func_L39_00507A80);

INCLUDE_ASM("asm/levels", func_L39_00507B18);

INCLUDE_ASM("asm/levels", func_L39_00507B3C);

/* localdecomp:start func_L39_00507B48 */
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_00507B48(void *arg0, void *arg1, u32 *arg2) {
    u32 *buf;
    s32 r;
    if (arg2[0] > 0x10 || arg2[1] > 0xFF || arg2[2] != 0x40) {
        return 0x21D;
    }
    r = func_L39_004F6060(arg1, &buf, 0x10);
    if (r != 0) {
        return r;
    }
    buf[0] = arg2[0];
    buf[1] = arg2[1];
    buf[2] = arg2[2];
    return func_L39_004F5EA0(arg1, arg0, buf);
}
/* localdecomp:end func_L39_00507B48 */

INCLUDE_ASM("asm/levels", func_L39_00507BFC);

INCLUDE_ASM("asm/levels", func_L39_00507C20);

/* localdecomp:start func_L39_00507C80 */
extern s32 func_L39_004F5F38(void *, void *, void *);
extern s32 func_L39_00506700(s32, void *, void *, s32, void *, void *, s32, s32);
extern u8 D_L39_0046D6F8[];

s32 func_L39_00507C80(void *arg0, void *arg1) {
    void *buf;

    if (func_L39_004F5F38(arg1, &buf, arg0) != 0) {
        return 0;
    }
    return func_L39_00506700(0, (u8 *)arg1 + 0x14, arg0, 0, D_L39_0046D6F8, buf, 0, 3);
}
/* localdecomp:end func_L39_00507C80 */

INCLUDE_ASM("asm/levels", func_L39_00507CF4);

INCLUDE_ASM("asm/levels", func_L39_00507D00);

LINKER_REMNANT("asm/levels", func_L39_00507DC8);

/* localdecomp:start func_L39_00507DD0 */
void func_L39_004F7510(void *, void *, s32);

s32 func_L39_00507DD0(void *arg0, void *arg1, void *arg2) {
    if (!(*(s32 *)((u8 *)arg1 + 0x2C) & 2)) {
        return 0x203;
    }
    func_L39_004F7510((u8 *)*(void **)((u8 *)arg1 + 0x28) + 0x34, arg2, 8);
    *(void **)((u8 *)*(void **)((u8 *)arg1 + 0x28) + 0x30) = arg1;
    return 0;
}
/* localdecomp:end func_L39_00507DD0 */

LINKER_REMNANT("asm/levels", func_L39_00507E20);

/* localdecomp:start func_L39_00507E28 */
typedef struct A_00507E28 { s32 f0; s32 f4; s32 f8; } A_00507E28;
typedef struct B_00507E28 { void *f0; void *f4; } B_00507E28;
s32 func_L39_004F6060(void *, void *, s32);
s32 func_L39_004F60D8(void *, void *, s32, s32);
s32 func_L39_004F5EA0(void *, void *, void *);
s32 func_L39_005070D0();
extern u8 D_L39_0046EF40[];

s32 func_L39_00507E28(void *arg0, void *arg1, A_00507E28 *arg2) {
    A_00507E28 *a;
    B_00507E28 *b;
    s32 ret;

    ret = func_L39_004F6060(arg1, &a, 12);
    if (ret != 0) {
        return ret;
    }
    ret = func_L39_004F60D8(arg1, a, arg2->f0, arg2->f4);
    if (ret != 0) {
        return ret;
    }
    a->f4 = arg2->f4;
    a->f8 = arg2->f8;
    ret = func_L39_004F6060(arg1, &b, 8);
    if (ret != 0) {
        return ret;
    }
    b->f0 = a;
    b->f4 = func_L39_005070D0;
    ret = func_L39_004F5EA0(arg1, D_L39_0046EF40, b);
    if (ret != 0) {
        return ret;
    }
    return func_L39_004F5EA0(arg1, arg0, a);
}
/* localdecomp:end func_L39_00507E28 */

INCLUDE_ASM("asm/levels", func_L39_00507EFC);

INCLUDE_ASM("asm/levels", func_L39_00507F5C);

/* localdecomp:start func_L39_00507F68 */
extern u8 D_L39_0046EEE0[];
extern u8 D_L39_0046EEF0[];
s32 func_L39_004F5F38(void *, void *, void *);
s32 func_L39_004F6060(void *, void *, s32);
s32 func_L39_004F60D8(void *, void *, s32, s32);
s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_00507F68(void *arg0, void *arg1, s32 *arg2) {
    void *a;
    s32 *b;
    s32 *c;
    s32 r;

    r = func_L39_004F5F38(arg1, &a, D_L39_0046EEE0);
    if (r != 0) {
        r = func_L39_004F5F38(arg1, &b, D_L39_0046EEF0);
        if (r != 0) {
            return 0x203;
        }
        r = func_L39_004F6060(arg1, &c, 8);
        if (r == 0) {
            c[1] = arg2[1];
            *b = (s32)c;
            r = func_L39_004F60D8(arg1, c, arg2[0], c[1]);
            if (r == 0) {
                *(s32 *)((u8 *)arg1 + 0x2C) &= ~4;
                r = func_L39_004F5EA0(arg1, arg0, c);
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_00507F68 */

INCLUDE_ASM("asm/levels", func_L39_0050803C);

/* localdecomp:start func_L39_00508080 */
typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
} S_00508080;

S_00508080 *func_L39_0050C878(s32, void *);

S_00508080 *func_L39_00508080(void *arg0, u8 *arg1) {
    S_00508080 *p;

    p = func_L39_0050C878(0, arg1 + 0x14);
    if (p != 0) {
        p->unk2C = 0xF1;
    }
    return p;
}
/* localdecomp:end func_L39_00508080 */

LINKER_REMNANT("asm/levels", func_L39_005080B0);

INCLUDE_ASM("asm/levels", func_L39_005080B8);

/* localdecomp:start func_L39_00508128 */
typedef struct S_00508128 S_00508128;
typedef struct E_00508128 {
    s32 f0;
    s32 f4;
    void *f8;
    s32 fC;
} E_00508128;
struct S_00508128 {
    s32 f0;
    s32 f4;
    s32 pad8;
    s32 (*fC)(S_00508128 *, void *, void *, E_00508128 *, s32, void *);
};
extern s32 func_L39_005084A8(void *, void **, void *);

s32 func_L39_00508128(s32 *ctx, S_00508128 *obj, s32 type, void *key, void *arg4, E_00508128 **list, void *arg6) {
    void *tmp;
    s32 last;
    s32 r;

    last = 0x221;
    for (; *list != 0; list++) {
        if ((*list)->f0 != obj->f4) {
            continue;
        }
        if ((*list)->f4 != type) {
            continue;
        }
        if ((*list)->f8 != 0) {
            r = func_L39_005084A8(key, &tmp, (*list)->f8);
            if (r != 0) {
                if (r == 0x206 || r == 0x20B || r == 0x207) {
                    return r;
                }
                last = r;
                continue;
            }
        } else {
            tmp = 0;
        }
        r = obj->fC(obj, tmp, arg4, *list, ctx[1], arg6);
        if (r != 0) {
            if (r == 0x206 || r == 0x20B || r == 0x207) {
                return r;
            }
            last = r;
            continue;
        }
        obj->f0 = (*list)->fC;
        return r;
    }
    return last;
}
/* localdecomp:end func_L39_00508128 */

INCLUDE_ASM("asm/levels", func_L39_00508278);

/* localdecomp:start func_L39_00508340 */
u32 func_L39_00508A98(s32, s32);

s32 func_L39_00508340(s32 *arg0, s32 *arg1) {
    if (func_L39_00508A98(arg1[0], arg1[1]) > 0x800) {
        return 7;
    }
    *arg0 = 0x40;
    return 0;
}
/* localdecomp:end func_L39_00508340 */

/* localdecomp:start func_L39_00508388 */
extern void func_L39_00508E58(void **p, void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6);
extern void func_L39_005090B8(void *, void *);
void func_L39_00508388(void *a0, void *a1) {
    func_L39_00508E58((void **)((u8 *)a0 + 0x24), 0, 0, 0, 0, 0, 0, 0);
    func_L39_005090B8(a0, a1);
}
/* localdecomp:end func_L39_00508388 */

/* localdecomp:start func_L39_005083E0 */
void func_L39_005091E8();

void func_L39_005083E0() {
    func_L39_005091E8();
}
/* localdecomp:end func_L39_005083E0 */

/* localdecomp:start func_L39_005083F8 */
void func_L39_00509388(s32, s32, s32 *);

void func_L39_005083F8(s32 arg0, s32 arg1, s32 *arg2) {
    *arg2 = 0;
    func_L39_00509388(arg0, arg1, arg2);
}
/* localdecomp:end func_L39_005083F8 */

/* localdecomp:start func_L39_00508410 */
s32 func_L39_00508410(u32 *arg0, u32 *arg1, u32 arg2) {
    u32 a = *arg0;
    if (arg2 % a != 0) {
        arg2 += a - arg2 % a;
    }
    *arg1 = arg2;
    return 0;
}
/* localdecomp:end func_L39_00508410 */
