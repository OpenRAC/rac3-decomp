#include "common.h"

typedef struct Loc_006DA090 {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 f30[0x40];
} Loc_006DA090;
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;

/* localdecomp:start func_L39_006D8E90 */
__asm__(".extern D_L39_0024D760, 16");
extern Obj_006DA090 *D_L39_0024D760;

/* from rac4-decomp's func_L00_00774AE0 */
void func_L39_006D8E90(void) {
    void (*cb)(void) = *(void (**)(void))(((u8 *)D_L39_0024D760) + 0x20);
    if (cb) cb();
}
/* localdecomp:end func_L39_006D8E90 */

/* localdecomp:start func_L39_006D8EC0 */
typedef struct {
    char pad0[0x24];
    void (*f24)(void);
} S_6D8EC0;

__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00774AE0 */
void func_L39_006D8EC0(void) {
    if (((S_6D8EC0 *)D_L39_0024D760)->f24 != 0) {
        ((S_6D8EC0 *)D_L39_0024D760)->f24();
    }
}
/* localdecomp:end func_L39_006D8EC0 */

/* localdecomp:start func_L39_006D8EF0 */
s32 func_L01_00521C90(s32, s32);
void *func_L39_006CCC58(void *arg0);

void *func_L39_006D8EF0(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x134, (s32) r);
    return func_L39_006CCC58(p);
}
/* localdecomp:end func_L39_006D8EF0 */

/* localdecomp:start func_L39_006D8F30 */
s32 func_L39_006D8F30(u32 arg0) {
    u32 align = 4;
    u32 result = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        result = arg0 + (align - rem);
    }
    return result - arg0 + 0x134;
}
/* localdecomp:end func_L39_006D8F30 */

/* localdecomp:start func_L39_006D8F58 */
void *func_L39_006CD540(void *arg0);

/* same shape as func_L39_006D8EF0 */
void *func_L39_006D8F58(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x48, (s32) r);
    return func_L39_006CD540(p);
}
/* localdecomp:end func_L39_006D8F58 */

/* localdecomp:start func_L39_006D8F98 */
u32 func_L39_006D8F98(u32 arg0);
u32 func_L39_006D8F98(u32 arg0) {
    u32 align = 4;
    u32 aligned = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        aligned = arg0 + (align - rem);
    }
    return aligned - arg0 + 0x48;
}
/* localdecomp:end func_L39_006D8F98 */

/* localdecomp:start func_L39_006D8FC0 */
void *func_L39_006CE930(void *arg0);

/* same shape as func_L39_006D8EF0 */
void *func_L39_006D8FC0(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x54C, (s32) r);
    return func_L39_006CE930(p);
}
/* localdecomp:end func_L39_006D8FC0 */

/* localdecomp:start func_L39_006D9000 */
/* same shape as func_L39_006D8F98: align arg0 up to 4, return the pad plus a constant */
u32 func_L39_006D9000(u32 arg0);
u32 func_L39_006D9000(u32 arg0) {
    u32 align = 4;
    u32 aligned = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        aligned = arg0 + (align - rem);
    }
    return aligned - arg0 + 0x54C;
}
/* localdecomp:end func_L39_006D9000 */

/* localdecomp:start func_L39_006D9028 */
s32 func_L01_00521C90(s32, s32);
void *func_L39_006D3440(void *arg0);

void *func_L39_006D9028(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x1F68, (s32) r);
    return func_L39_006D3440(p);
}
/* localdecomp:end func_L39_006D9028 */

/* localdecomp:start func_L39_006D9068 */
/* same shape as func_L39_006D8F98: align arg0 up to 4, return the pad plus a constant */
u32 func_L39_006D9068(u32 arg0);
u32 func_L39_006D9068(u32 arg0) {
    u32 align = 4;
    u32 aligned = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        aligned = arg0 + (align - rem);
    }
    return aligned - arg0 + 0x1F68;
}
/* localdecomp:end func_L39_006D9068 */

/* localdecomp:start func_L39_006D9090 */
s32 func_L01_00521C90(s32, s32);
void *func_L39_006D6520(void *arg0);

void *func_L39_006D9090(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x88, (s32) r);
    return func_L39_006D6520(p);
}
/* localdecomp:end func_L39_006D9090 */

/* localdecomp:start func_L39_006D90D0 */
/* same shape as func_L39_006D8F98: align arg0 up to 4, return the pad plus a constant */
u32 func_L39_006D90D0(u32 arg0);
u32 func_L39_006D90D0(u32 arg0) {
    u32 align = 4;
    u32 aligned = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        aligned = arg0 + (align - rem);
    }
    return aligned - arg0 + 0x88;
}
/* localdecomp:end func_L39_006D90D0 */

/* localdecomp:start func_L39_006D90F8 */
s32 func_L01_00521C90(s32, s32);
void *func_L39_006D5B40(void *arg0);

void *func_L39_006D90F8(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x48, (s32) r);
    return func_L39_006D5B40(p);
}
/* localdecomp:end func_L39_006D90F8 */

/* localdecomp:start func_L39_006D9138 */
/* same shape as func_L39_006D8F98: align arg0 up to 4, return the pad plus a constant */
u32 func_L39_006D9138(u32 arg0);
u32 func_L39_006D9138(u32 arg0) {
    u32 align = 4;
    u32 aligned = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        aligned = arg0 + (align - rem);
    }
    return aligned - arg0 + 0x48;
}
/* localdecomp:end func_L39_006D9138 */

/* localdecomp:start func_L39_006D9160 */
s32 func_L01_00521C90(s32, s32);
void *func_L39_006D9300(void *);

void *func_L39_006D9160(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x1E4, (s32) r);
    return func_L39_006D9300(p);
}
/* localdecomp:end func_L39_006D9160 */

/* localdecomp:start func_L39_006D91A0 */
/* same shape as func_L39_006D8F98: align arg0 up to 4, return the pad plus a constant */
u32 func_L39_006D91A0(u32 arg0);
u32 func_L39_006D91A0(u32 arg0) {
    u32 align = 4;
    u32 aligned = arg0;
    u32 rem = arg0 % align;
    if (rem != 0) {
        aligned = arg0 + (align - rem);
    }
    return aligned - arg0 + 0x1E4;
}
/* localdecomp:end func_L39_006D91A0 */

INCLUDE_ASM("asm/levels", func_L39_006D91C8);

/* localdecomp:start func_L39_006D9208 */
u32 func_L39_006D9208(u32 a0) {
    u32 align = 4;
    u32 r = a0;
    u32 rem = a0 % align;
    if (rem != 0) {
        r = a0 + (align - rem);
    }
    return r - a0 + 0x1D4;
}
/* localdecomp:end func_L39_006D9208 */

/* localdecomp:start func_L39_006D9230 */
s32 func_L01_00521C90(s32, s32);
void *func_L39_006DC788(void *arg0);

void *func_L39_006D9230(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0xEC, (s32) r);
    return func_L39_006DC788(p);
}
/* localdecomp:end func_L39_006D9230 */

/* localdecomp:start func_L39_006D9270 */
u32 func_L39_006D9270(u32 a0) {
    u32 align = 4;
    u32 r = a0;
    u32 rem = a0 % align;
    if (rem != 0) {
        r = a0 + (align - rem);
    }
    return r - a0 + 0xEC;
}
/* localdecomp:end func_L39_006D9270 */

/* localdecomp:start func_L39_006D9298 */
s32 func_L01_00521C90(s32, s32);
s32 func_L39_006DD400(s32);

s32 func_L39_006D9298(s32 arg0) {
    u32 align = 4;
    u32 rem = arg0 % align;
    s32 temp_v0;
    if (rem != 0) {
        arg0 += align - rem;
    }
    temp_v0 = func_L01_00521C90(0x30A8, arg0);
    return func_L39_006DD400(temp_v0);
}
/* localdecomp:end func_L39_006D9298 */

/* localdecomp:start func_L39_006D92D8 */
u32 func_L39_006D92D8(u32 a0) {
    u32 align = 4;
    u32 r = a0;
    u32 rem = a0 % align;
    if (rem != 0) {
        r = a0 + (align - rem);
    }
    return r - a0 + 0x30A8;
}
/* localdecomp:end func_L39_006D92D8 */

/* localdecomp:start func_L39_006D9300 */
void *func_L39_006D9300(void *arg0) {
    (*(s8 *)arg0) = 0;
    *(s8 *)((u8 *)arg0 + 0x14C) = 0;
    *(s8 *)((u8 *)arg0 + 0x1C0) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D9300 */

/* localdecomp:start func_L39_006D9318 */
typedef struct { u8 f0; u8 pad[0x14B]; u8 f14C; u8 pad2[0x73]; u8 f1C0; } S_006D9318;
void func_L39_006D9318(S_006D9318 *arg0) {
    arg0->f0 = 0;
    arg0->f14C = 0;
    arg0->f1C0 = 0;
}
/* localdecomp:end func_L39_006D9318 */

INCLUDE_ASM("asm/levels", func_L39_006D9328);

/* localdecomp:start func_L39_006D9808 */
__asm__(".extern D_L39_0024D760, 16");
extern Obj_006DA090 *D_L39_0024D760;
typedef struct { s32 w[0x52]; } S_006D9808;

void func_L39_006D9808(S_006D9808 *arg0) {
    u8 *obj = *(u8 **)((u8 *)D_L39_0024D760 + 0x48);
    obj[0] = 0;
    *(S_006D9808 *)(obj + 4) = *arg0;
}
/* localdecomp:end func_L39_006D9808 */

INCLUDE_ASM("asm/levels", func_L39_006D98C8);

INCLUDE_ASM("asm/levels", func_L39_006D9A40);

/* localdecomp:start func_L39_006D9BC0 */
extern Obj_006DA090 *D_L39_0024D760 __attribute__((section(".data")));
typedef struct { u8 b[0x70]; } Blob_006D9BC0;

void func_L39_006D9BC0(Blob_006D9BC0 *src) {
    u8 *dst = *(u8 **)((u8 *)D_L39_0024D760 + 0x48);
    dst[0x14C] = 0;
    *(Blob_006D9BC0 *)(dst + 0x150) = *src;
}
/* localdecomp:end func_L39_006D9BC0 */

INCLUDE_ASM("asm/levels", func_L39_006D9C90);

/* localdecomp:start func_L39_006D9E10 */
typedef struct { unsigned char bytes[32]; } __attribute__((packed)) Block_6D9E10;
typedef struct { char pad[0x1c0]; char flag; char pad2[3]; Block_6D9E10 block; } Target_6D9E10;
typedef struct { char pad[0x48]; Target_6D9E10 *target; } Context_6D9E10;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00776E88 */
void func_L39_006D9E10(Block_6D9E10 *source) {
    Target_6D9E10 *target = ((Context_6D9E10 *)D_L39_0024D760)->target;
    target->flag = 0;
    target->block = *source;
}
/* localdecomp:end func_L39_006D9E10 */

INCLUDE_ASM("asm/levels", func_L39_006D9E68);

/* localdecomp:start func_L39_006D9FD8 */
typedef struct {
 int f0; char f4; char pad5[0xBB]; char fC0; char padC1[0x23];
 char fE4; char padE5[7]; char fEC; char padED[7]; char fF4;
 char padF5[0x67]; char f15C, f15D; char pad15E[2]; int f160, f164;
 char f168; char pad169[3]; int f16C, f170; char pad174[0x24];
 char f198, f199; char pad19A[2]; int f19C, f1A0; char f1A4;
 char pad1A5[3]; int f1A8, f1AC;
} Type1;

/* from rac4-decomp's func_L00_007770F0, renamed */
Type1 *func_L39_006D9FD8(Type1 *p) {
 p->f0 = -1;
 p->f4 = 0; p->fC0 = 0; p->fE4 = 0; p->fEC = 0; p->fF4 = 0;
 p->f15C = 0; p->f15D = 0; p->f160 = -1; p->f164 = -1;
 p->f168 = 0; p->f16C = 10000; p->f170 = -1;
 p->f198 = 0; p->f199 = 0; p->f19C = -1; p->f1A0 = -1; p->f1A4 = 0; p->f1AC = -1; p->f1A8 = 10000;
 return p;
}
/* localdecomp:end func_L39_006D9FD8 */

/* localdecomp:start func_L39_006DA038 */
void func_L39_006DA038(Type1 *p) {
    p->f0 = -1;
    p->f4 = 0;
    p->fC0 = 0;
    p->fE4 = 0;
    p->fEC = 0;
    p->fF4 = 0;
    p->f15D = 0;
    p->f160 = -1;
    p->f164 = -1;
    p->f168 = 0;
    p->f16C = 10000;
    p->f170 = -1;
    p->f199 = 0;
    p->f19C = -1;
    p->f1A0 = -1;
    p->f1A4 = 0;
    p->f1AC = -1;
    p->f1A8 = 10000;
}
/* localdecomp:end func_L39_006DA038 */

/* localdecomp:start func_L39_006DA090 */
s32 func_L39_006DD608(s32, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005958A0(void *, void *, s32);
void *func_0017EC38(void *);
void func_001961E8(void *);
s32 func_001961F8(void);
__asm__(".extern D_L39_0024D760, 16");
extern u16 D_L39_00249F40[];

s32 func_L39_006DA090(s32 a0, void *a1) {
    Loc_006DA090 loc;
    Obj_006DA090 *p;
    s32 r;
    s32 x;

    p = D_L39_0024D760;
    x = p->f50;
    r = func_L39_006DD608(p->f54, a1, 0);
    if (r != 0) {
        loc.f00 = D_L39_00249F40[0];
        func_001206F4((u8 *)&loc + 0x15, x);
        loc.f28 = 0;
        loc.f2C = -1;
        func_L39_005958A0(loc.f30, a1, 0x40);
        func_001961E8(func_0017EC38(&loc));
        if (func_001961F8() != 0) {
            p->f10 = 0x49;
            if (p->f14 == 0) {
                p->f14 = 0x49;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DA090 */

/* localdecomp:start func_L39_006DA158 */
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006DA158(u32 arg0, s32 arg1) {
    u32 p = arg0 + func_L39_006E16A0((void *)arg0, arg1 * 2, 0xD0, 4);
    {
        u32 a = 4;
        p = (p % a) ? p + (a - p % a) : p;
    }
    p += arg1 * 8;
    return p - arg0;
}
/* localdecomp:end func_L39_006DA158 */

/* localdecomp:start func_L39_006DA1C0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Q_006DA1C0;
typedef struct {
    u8 pad0[0x15C];
    u8 f15C;
    u8 f15D;
    u8 pad15E[0x16];
    s32 f174;
    Q_006DA1C0 f178;
    Q_006DA1C0 f184;
    s32 f190;
    s32 f194;
} S_006DA1C0;
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);

void func_L39_006DA1C0(S_006DA1C0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 r;
    s32 n;
    Q_006DA1C0 *q;
    Q_006DA1C0 *q2;

    if (arg0->f15C == 0) {
        arg0->f15D = 0;
        arg0->f174 = arg3;
        arg0->f15C = 1;
        r = arg1;
        n = func_L39_006E16A0((void *)arg1, arg3 * 2, 0xD0, 4);
        arg0->f190 = func_L39_006E1648(r, n, 0xD0, 4);
        r += n;
        {
            u32 align = 4;
            u32 t = r;
            u32 rem = r % align;
            if (rem != 0) {
                t = r + (align - rem);
            }
            r = t;
        }
        arg0->f194 = r;
        func_0011D534(r, 0, arg0->f174 * 8);
        q = &arg0->f178;
        q->f0 = 0;
        q->f8 = arg0->f194;
        q->f4 = 0;
        q2 = &arg0->f184;
        q2->f0 = 0;
        q2->f8 = arg0->f174 * 4 + arg0->f194;
        q2->f4 = 0;
    }
}
/* localdecomp:end func_L39_006DA1C0 */

/* localdecomp:start func_L39_006DA2A8 */
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006DA2A8(u32 arg0, s32 arg1) {
    u32 p = arg0 + func_L39_006E16A0((void *)arg0, arg1 * 2, 0x80, 4);
    {
        u32 a = 4;
        p = (p % a) ? p + (a - p % a) : p;
    }
    p += arg1 * 8;
    return p - arg0;
}
/* localdecomp:end func_L39_006DA2A8 */

/* localdecomp:start func_L39_006DA310 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Q_006DA310;
typedef struct {
    u8 pad0[0x198];
    u8 f198;
    u8 f199;
    u8 pad19A[0x16];
    s32 f1B0;
    Q_006DA310 f1B4;
    Q_006DA310 f1C0;
    s32 f1CC;
    s32 f1D0;
} S_006DA310;
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);

void func_L39_006DA310(S_006DA310 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 r;
    s32 n;
    Q_006DA310 *q;
    Q_006DA310 *q2;

    if (arg0->f198 == 0) {
        arg0->f199 = 0;
        arg0->f1B0 = arg3;
        arg0->f198 = 1;
        r = arg1;
        n = func_L39_006E16A0((void *)arg1, arg3 * 2, 0x80, 4);
        arg0->f1CC = func_L39_006E1648(r, n, 0x80, 4);
        r += n;
        {
            u32 align = 4;
            u32 t = r;
            u32 rem = r % align;
            if (rem != 0) {
                t = r + (align - rem);
            }
            r = t;
        }
        arg0->f1D0 = r;
        func_0011D534(r, 0, arg0->f1B0 * 8);
        q = &arg0->f1B4;
        q->f0 = 0;
        q->f8 = arg0->f1D0;
        q->f4 = 0;
        q2 = &arg0->f1C0;
        q2->f0 = 0;
        q2->f8 = arg0->f1B0 * 4 + arg0->f1D0;
        q2->f4 = 0;
    }
}
/* localdecomp:end func_L39_006DA310 */

INCLUDE_ASM("asm/levels", func_L39_006DA3F8);

/* localdecomp:start func_L39_006DA628 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char bytes[32]; } Block_6DA628;
typedef struct { char pad[0xc0]; unsigned char fC0; char pad2[3]; Block_6DA628 fC4; } Type1_6DA628;
typedef struct { char pad[0x4c]; Type1_6DA628 *f4C; } Type2_6DA628;

/* from rac4-decomp's func_L00_00777750 */
void func_L39_006DA628(Block_6DA628 *arg0) {
    Type1_6DA628 *p = ((Type2_6DA628 *)D_L39_0024D760)->f4C;
    p->fC0 = 0;
    p->fC4 = *arg0;
}
/* localdecomp:end func_L39_006DA628 */

INCLUDE_ASM("asm/levels", func_L39_006DA680);

/* localdecomp:start func_L39_006DA878 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char bytes[0xB8]; } Block_006DA878;
typedef struct { char pad[4]; unsigned char f4; char pad2[3]; Block_006DA878 f8; } Type1_006DA878;
typedef struct { char pad[0x4c]; Type1_006DA878 *f4C; } Type2_006DA878;

void func_L39_006DA878(Block_006DA878 *arg0) {
    Type1_006DA878 *p = ((Type2_006DA878 *)D_L39_0024D760)->f4C;
    p->f4 = 0;
    p->f8 = *arg0;
}
/* localdecomp:end func_L39_006DA878 */

INCLUDE_ASM("asm/levels", func_L39_006DA958);

INCLUDE_ASM("asm/levels", func_L39_006DAB18);

INCLUDE_ASM("asm/levels", func_L39_006DABF0);

/* localdecomp:start func_L39_006DAFC8 */
typedef struct {
    u16 f00;
    u8 pad02[0x14];
    u16 f16;
    u16 f18;
    u8 pad1A[6];
    u8 f20[0x10];
} Loc_006DAFC8;
typedef struct {
    u8 pad00[0x199];
    u8 f199;
    s32 f19C;
    u8 pad1A0[0x10];
    u16 f1B0;
} Obj_006DAFC8;
typedef struct {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
} Dst_006DAFC8;

extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern void *func_0017F948(void *, void *, s32);
extern void func_001961E8(void *);
extern s32 func_001961F8(void);
extern u16 D_L39_00249F40[];
extern u8 D_00197E20[];
extern Dst_006DAFC8 *D_001E2050_sda;

s32 func_L39_006DAFC8(Obj_006DAFC8 *arg0) {
    Loc_006DAFC8 loc;
    s32 ret = 1;
    Dst_006DAFC8 *d = D_001E2050_sda;

    if (arg0->f199 == 0) {
        loc.f00 = D_L39_00249F40[0];
        loc.f18 = arg0->f1B0;
        loc.f16 = 1;
        arg0->f199 = 1;
        arg0->f19C = func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(loc.f20);
        func_001961E8(func_0017F948(&loc, D_00197E20, 0));
        if (func_001961F8() != 0) {
            d->f10 = 0x48;
            if (d->f14 == 0) {
                d->f14 = 0x48;
            }
            ret = 0;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006DAFC8 */

INCLUDE_ASM("asm/levels", func_L39_006DB098);

INCLUDE_ASM("asm/levels", func_L39_006DB450);

/* localdecomp:start func_L39_006DB5B0 */
typedef struct {
    u8 pad0[0xE4];
    s8 fE4;
    u8 pad1[3];
    s32 fE8;
} S_6DB5B0_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6DB5B0_C;

__asm__(".extern D_L39_0024D760, 16");
/* D_L39_0024D760 is already declared (with .extern size 16) as Obj_006DA090 * in this file.
   Landing: give Obj_006DA090 a field `S_6DB5B0_B *f4C` (split pad18 into pad18[0x34] + f4C) and use p = D_L39_0024D760->f4C. */
/* from rac4-decomp's func_L00_00778848 */
void func_L39_006DB5B0(S_6DB5B0_C *arg0) {
    S_6DB5B0_B *p = *(S_6DB5B0_B **)((u8 *)D_L39_0024D760 + 0x4C);
    p->fE4 = 0;
    p->fE8 = arg0->f18;
}
/* localdecomp:end func_L39_006DB5B0 */

INCLUDE_ASM("asm/levels", func_L39_006DB5D0);

/* localdecomp:start func_L39_006DB730 */
extern Obj_006DA090 *D_L39_0024D760 __attribute__((section(".data")));

void func_L39_006DB730(void *arg0) {
    u8 *temp_v1 = *(u8 **)((u8 *)D_L39_0024D760 + 0x4C);
    *(s8 *)(temp_v1 + 0xEC) = 0;
    *(s32 *)(temp_v1 + 0xF0) = *(s32 *)((u8 *)arg0 + 0x18);
}
/* localdecomp:end func_L39_006DB730 */

/* localdecomp:start func_L39_006DB750 */
typedef struct {
    u16 f00;
    u8 pad02[0x26];
    s32 f28;
    u8 pad2C[4];
} Loc_006DB750;
typedef struct {
    u8 pad00[0xF4];
    u8 fF4;
    u8 padF5[3];
    u8 fF8[0x18];
    s32 f110;
} Obj_006DB750;
typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[6];
    s32 f08;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} P_006DB750;
typedef struct {
    u8 pad[0x2DC];
    s32 f2DC;
} G_006DB750;

extern s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_0017EB38(void *, void *, s32);
extern void func_001961E8(void *);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(void *);
extern u16 D_L39_00249F40[];
extern u8 D_00197DA8[];
extern G_006DB750 D_001A5CD0;

void *func_L39_006DB750(Obj_006DB750 *arg0, s32 arg1) {
    Loc_006DB750 loc;
    P_006DB750 *p = (P_006DB750 *)D_L39_0024D760;
    s32 ok;
    s32 x;
    void *r;

    x = p->f50;
    loc.f00 = D_L39_00249F40[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = arg1;
    arg0->fF4 = 1;
    p->f01 = 1;
    ok = 1;
    p->f08 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EB38(&loc, D_00197DA8, 0));
    while (arg0->fF4 != 0) {
        if (func_001961F8() != 0 || D_001A5CD0.f2DC != 0) {
            p->f10 = 0x4A;
            if (p->f14 == 0) {
                p->f14 = 0x4A;
            }
            ok = 0;
            break;
        }
        p->f1C = 1;
        func_00195410();
        p->f1C = 0;
        if (func_L39_006D8AD8(p) == 0) {
            ok = 0;
            break;
        }
    }
    p->f01 = 0;
    arg0->fF4 = 0;
    r = 0;
    if (ok != 0) {
        r = arg0->f110 != 0 ? 0 : arg0->fF8;
    }
    return r;
}
/* localdecomp:end func_L39_006DB750 */

/* localdecomp:start func_L39_006DB890 */
typedef struct { s32 w[0x19]; } S_006DB890;

void func_L39_006DB890(S_006DB890 *arg0) {
    u8 *obj = *(u8 **)((u8 *)D_L39_0024D760 + 0x4C);
    obj[0xF4] = 0;
    *(S_006DB890 *)(obj + 0xF8) = *arg0;
}
/* localdecomp:end func_L39_006DB890 */

INCLUDE_ASM("asm/levels", func_L39_006DB948);

INCLUDE_ASM("asm/levels", func_L39_006DBD58);

INCLUDE_ASM("asm/levels", func_L39_006DBEE0);

/* localdecomp:start func_L39_006DC148 */
void func_L39_006DB450(s32, s32, s32, s32, s32, s32);

void func_L39_006DC148(s32 arg0, s32 arg1) {
    s32 lo = 0;
    s32 hi = 0;
    arg1 -= 0x28;
    if (arg1 < 32) {
        lo = (s32)(1L << arg1);
    } else if (arg1 < 64) {
        hi = (s32)(1L << (arg1 - 32));
    }
    func_L39_006DB450(arg0, 1, 1, lo, hi, 0);
}
/* localdecomp:end func_L39_006DC148 */
