#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0068C4E0);

LINKER_REMNANT("asm/levels", func_L39_0068C708);

/* localdecomp:start func_L39_0068C718 */
typedef struct O_0068C718 O_0068C718;
typedef struct {
    u8 pad0[0x1C];
    void (*setFlags)(O_0068C718 *, s32, s32);
    u8 pad20[0x8];
    void (*setPos)(O_0068C718 *, f32, f32);
    void (*setSize)(O_0068C718 *, f32, f32);
    u8 pad30[0x10];
    void (*f40)(O_0068C718 *, s32);
    u8 pad44[0x4];
    void (*f48)(O_0068C718 *, s32, s32);
    void (*f4C)(O_0068C718 *, s32, s32);
} V_0068C718;
struct O_0068C718 {
    u8 pad0[0x60];
    V_0068C718 *vt;
};
typedef struct {
    f32 a, b, c, d;
    s32 e;
    s32 pad;
} A_0068C718;
typedef struct {
    s32 a;
    f32 b, c, d, e;
    s32 f;
} B_0068C718;
typedef struct {
    f32 x, y, w, h;
    s32 pad;
    f32 step;
} C_0068C718;

extern A_0068C718 D_L39_004AE2F0;
extern f32 D_L39_004AE308[];
extern A_0068C718 D_L39_004AE320;
extern B_0068C718 D_L39_004AE338;
extern C_0068C718 D_L39_004AE350;
extern f32 D_L39_004AE388[];
extern s32 D_001A5CD0[];
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, s32);
extern void func_L39_0068A4A8(void *, s32, s32, s32, f32, f32, f32, f32);
extern void func_L39_00689B58(void);
extern void func_L39_00689B80(void);

void func_L39_0068C718(void *arg0)
{
    O_0068C718 **objs = (O_0068C718 **)((u8 *)arg0 + 0x110);
    f32 y;
    s32 i;
    s32 n;

    func_L39_0068A6D0(arg0, 0, D_L39_004AE2F0.a, D_L39_004AE2F0.b, D_L39_004AE2F0.c, D_L39_004AE2F0.d, D_L39_004AE2F0.e);
    objs[0]->vt->setPos(objs[0], D_L39_004AE308[0], D_L39_004AE308[1]);
    objs[0]->vt->setSize(objs[0], D_L39_004AE308[2], D_L39_004AE308[3]);
    objs[0]->vt->setFlags(objs[0], 1, 0);
    func_L39_0068A6D0(arg0, 1, D_L39_004AE320.a, D_L39_004AE320.b, D_L39_004AE320.c, D_L39_004AE320.d, D_L39_004AE320.e);
    ((void (*)(void *, s32, s32, f32, f32, f32, f32, s32))func_L39_0068A4A8)(arg0, 0, D_L39_004AE338.a, D_L39_004AE338.b, D_L39_004AE338.c, D_L39_004AE338.d, D_L39_004AE338.e, D_L39_004AE338.f);
    y = D_L39_004AE350.y;
    i = 0;
    do {
        n = i + 1;
        (*(O_0068C718 **)((u8 *)objs + (n << 2)))->vt->setPos((*(O_0068C718 **)((u8 *)objs + (n << 2))), D_L39_004AE350.x, y);
        (*(O_0068C718 **)((u8 *)objs + (n << 2)))->vt->setSize((*(O_0068C718 **)((u8 *)objs + (n << 2))), D_L39_004AE350.w, D_L39_004AE350.h);
        (*(O_0068C718 **)((u8 *)objs + (n << 2)))->vt->f40((*(O_0068C718 **)((u8 *)objs + (n << 2))), 1);
        (*(O_0068C718 **)((u8 *)objs + (n << 2)))->vt->f4C((*(O_0068C718 **)((u8 *)objs + (n << 2))), 0x40, 1);
        (*(O_0068C718 **)((u8 *)objs + (n << 2)))->vt->f48((*(O_0068C718 **)((u8 *)objs + (n << 2))), 3, 3);
        y += D_L39_004AE350.step;
        i = n;
    } while (i < 6);
    if (D_001A5CD0[0x174 / 4] == 0) {
        ((void (*)(void *, f32, f32))func_L39_00689B58)(arg0, D_L39_004AE388[0], D_L39_004AE388[1]);
    } else {
        ((void (*)(void *))func_L39_00689B80)(arg0);
    }
}
/* localdecomp:end func_L39_0068C718 */

/* localdecomp:start func_L39_0068C918 */
typedef struct O_0068C918 O_0068C918;
typedef struct {
    u8 pad0[0x1C];
    s32 (*setFlags)(O_0068C918 *, s32, s32);
    u8 pad20[0x4];
    void (*setText)(O_0068C918 *, void *);
    u8 pad28[0x8];
    void (*getPos)(O_0068C918 *, f32 *, f32 *);
    u8 pad34[0x1C];
    void (*setColor)(O_0068C918 *, u32);
} V_0068C918;
struct O_0068C918 {
    u8 pad0[0x60];
    V_0068C918 *vt;
};
typedef struct {
    u8 pad0[0x1D];
    u8 key[0xCF];
    u8 active;
    u8 pad1[0x1F0 - 0xED];
} S_0068C918;
typedef struct {
    u8 pad0[0x8];
    s32 state;
    u8 pad1[0x15C - 0xC];
    s32 f15C;
    u8 pad2[0x4];
    s32 f164;
} M_0068C918;
typedef struct {
    u8 pad0[0x8];
    f32 w, h, x, y, a, b;
} R_0068C918;

extern s32 D_001A5E44 __attribute__((section(".data")));
extern M_0068C918 D_001A43E0;
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern S_0068C918 D_001FC6B0_0068C918[];
extern u8 D_L39_00247B20[];
extern R_0068C918 D_L39_004AE368;
extern char *func_00381FF0(s32);
extern void func_L39_00689E58(void *, char *, u32, f32, f32);
extern void func_00195010(void);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

typedef struct {
    u8 pad0[0x110];
    O_0068C918 *objs[7];
    u8 pad12C[0x290 - 0x12C];
    s32 sel;
    u8 pad294[0x334 - 0x294];
    s32 count;
} P_0068C918;

void func_L39_0068C918(P_0068C918 *arg0)
{
    u8 buf[0x20];
    f32 x, y;
    s32 i;
    s32 sel;
    s32 mode;

    if (D_001A5E44 == 0) {
        func_L39_00689E58(arg0, func_00381FF0(0x185C), 0x706EC8FF, 1.0f, 1.0f);
    }
    if (D_001A43E0.state != 2 || (D_001A43E0.f15C < 3 && D_001A43E0.f164 < 0 && D_L39_002403F8 != 1)) {
        func_00195010();
    }
    arg0->count = 0;
    for (i = 0; i < 6; i++) {
        if ((&D_001FC6B0_0068C918[i])->active == 1) {
            arg0->objs[i + 1]->vt->setFlags(arg0->objs[i + 1], 3, 0);
            func_00120048(buf, D_L39_00247B20, D_001FC6B0_0068C918[i].key);
            arg0->objs[i + 1]->vt->setText(arg0->objs[i + 1], buf);
            (arg0->count)++;
        } else {
            arg0->objs[i + 1]->vt->setFlags(arg0->objs[i + 1], 0, 0);
        }
    }
    if (arg0->count < 6) {
        arg0->objs[arg0->count + 1]->vt->setText(arg0->objs[arg0->count + 1], func_00381FF0(0x10C8));
        arg0->objs[arg0->count + 1]->vt->setFlags(arg0->objs[arg0->count + 1], 3, 0);
        arg0->objs[arg0->count + 1]->vt->setColor(arg0->objs[arg0->count + 1], 0x80CCCCCC);
    }
    mode = 0;
    sel = arg0->sel;
    if (arg0->count > 0) {
        if (sel == 0) {
            mode = 2;
        } else if (arg0->count == sel || sel == 5) {
            mode = 1;
        } else {
            mode = 3;
        }
    }
    arg0->objs[sel]->vt->getPos(arg0->objs[sel], &x, &y);
    func_L39_00689F00(arg0, mode, 3, 3, x + D_L39_004AE368.x, y + D_L39_004AE368.y,
                      D_L39_004AE368.w, D_L39_004AE368.h, D_L39_004AE368.a, D_L39_004AE368.b);
}
/* localdecomp:end func_L39_0068C918 */

/* localdecomp:start func_L39_0068CBE8 */
typedef struct {
    u8 pad0[0xEC];
    u8 active;
    u8 pad1[0x1F0 - 0xED];
} S_0068CBE8;

extern S_0068CBE8 D_001FC6B0[];
extern u8 D_001D82EC_sda;
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_001DC3F4_sda;

s32 func_L39_0068CBE8(void *arg0, s32 arg1)
{
    s32 i;
    s32 j;
    S_0068CBE8 *p;
    S_0068CBE8 *q;

    (arg1 + D_001FC6B0)->active = 0;
    for (i = 0; i < 5; i = j) {
        j = i + 1;
        p = &D_001FC6B0[i];
        if (p->active == 0) {
            *p = (D_001FC6B0 + 1)[i];
            q = &D_001FC6B0[j];
            q->active = 0;
        }
    }
    D_001D82EC_sda = 1;
    if (D_L39_002403F8 == 1) {
        D_001DC3F4_sda = 6;
    }
    return 1;
}
/* localdecomp:end func_L39_0068CBE8 */

/* localdecomp:start func_L39_0068CD28 */
void func_00120D28(s32, s32, s32);

void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    if (arg1 != 0) {
        func_00120D28(arg0 + 4, arg1, 0x33);
        *(s8 *)(arg0 + 0x37) = 0;
    } else {
        *(s8 *)(arg0 + 4) = 0;
    }
    *(f32 *)(arg0 + 0x38) = arg2;
    *(f32 *)(arg0 + 0x3C) = arg3;
    *(f32 *)(arg0 + 0x40) = arg4;
    *(f32 *)(arg0 + 0x44) = arg5;
}
/* localdecomp:end func_L39_0068CD28 */
