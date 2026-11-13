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

/* localdecomp:start func_L39_006D91C8 */
s32 func_L01_00521C90(s32, s32);
void *func_L39_006D9FD8_006D91C8(void *);

void *func_L39_006D91C8(u32 arg0) {
    u32 align = 4;
    u32 r = arg0;
    u32 rem = arg0 % align;
    void *p;
    if (rem != 0) {
        r = arg0 + (align - rem);
    }
    p = (void *) func_L01_00521C90(0x1D4, (s32) r);
    return func_L39_006D9FD8_006D91C8(p);
}
/* localdecomp:end func_L39_006D91C8 */

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

/* localdecomp:start func_L39_006D98C8 */
typedef struct {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 pad30[0x20];
} Loc_006D98C8;
typedef struct {
    u8 pad00[0x14C];
    u8 f14C;
    u8 pad14D[3];
    u8 f150[0x18];
    s32 f168;
} S_006D98C8;
typedef struct {
    u8 pad00;
    u8 f1;
    u8 pad02[6];
    s32 f8;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} G_006D98C8;
typedef struct {
    u8 pad00[0x2DC];
    s32 f2DC;
} P_006D98C8;

s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017EBB8(void *, void *, s32);
void func_001961E8(void *);
s32 func_001961F8(void);
void func_00195410(void);
extern s32 func_L39_006D8AD8(void *);
extern u8 D_001A5CD0_006D98C8[];
__asm__(".extern D_L39_0024D760, 16");
extern u16 D_L39_00249EE8[];
extern u8 D_00197D30[];

void *func_L39_006D98C8(S_006D98C8 *arg0, s32 arg1) {
    Loc_006D98C8 loc;
    G_006D98C8 *g;
    P_006D98C8 *p;
    s32 r;
    s32 x;
    void *ret;

    g = (G_006D98C8 *)D_L39_0024D760;
    x = g->f50;
    loc.f00 = D_L39_00249EE8[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f2C = arg1;
    loc.f28 = 0;
    arg0->f14C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EBB8(&loc, D_00197D30, 0));
    p = (P_006D98C8 *)D_001A5CD0_006D98C8;
    while (arg0->f14C != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f14C = 0;
    ret = 0;
    if (r != 0) {
        if (arg0->f168 == -0x3DD) {
            g->f10 = 0x3D;
            if (g->f14 == 0) {
                g->f14 = 0x3D;
            }
            r = 0;
        } else if (arg0->f168 != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
            }
            r = 0;
        }
        ret = r ? arg0->f150 : 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006D98C8 */

/* localdecomp:start func_L39_006D9A40 */
typedef struct {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 pad30[0x20];
} Loc_006D9A40;
typedef struct {
    u8 pad00[0x14C];
    u8 f14C;
    u8 pad14D[3];
    u8 f150[0x18];
    s32 f168;
} S_006D9A40;
typedef struct {
    u8 pad00;
    u8 f1;
    u8 pad02[6];
    s32 f8;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} G_006D9A40;
typedef struct {
    u8 pad00[0x2DC];
    s32 f2DC;
} P_006D9A40;

s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017EBB8(void *, void *, s32);
void func_001961E8(void *);
s32 func_001961F8(void);
void func_00195410(void);
void func_L39_005958A0(void *, void *, s32);
extern s32 func_L39_006D8AD8(void *);
extern u8 D_001A5CD0_006D9A40[];
__asm__(".extern D_L39_0024D760, 16");
extern u16 D_L39_00249EE8[];
extern u8 D_00197D30[];

void *func_L39_006D9A40(S_006D9A40 *arg0, void *arg1) {
    Loc_006D9A40 loc;
    G_006D9A40 *g;
    P_006D9A40 *p;
    s32 r;
    s32 x;
    void *ret;

    g = (G_006D9A40 *)D_L39_0024D760;
    x = g->f50;
    loc.f00 = D_L39_00249EE8[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = 1;
    func_L39_005958A0((u8 *)&loc + 0x30, arg1, 0x20);
    arg0->f14C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EBB8(&loc, D_00197D30, 0));
    p = (P_006D9A40 *)D_001A5CD0_006D9A40;
    while (arg0->f14C != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f14C = 0;
    ret = 0;
    if (r != 0) {
        if (arg0->f168 == -0x3DD) {
            g->f10 = 0x3D;
            if (g->f14 == 0) {
                g->f14 = 0x3D;
            }
            r = 0;
        } else if (arg0->f168 != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
            }
            r = 0;
        }
        ret = r ? arg0->f150 : 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006D9A40 */

/* localdecomp:start func_L39_006D9BC0 */
extern Obj_006DA090 *D_L39_0024D760 __attribute__((section(".data")));
typedef struct { u8 b[0x70]; } Blob_006D9BC0;

void func_L39_006D9BC0(Blob_006D9BC0 *src) {
    u8 *dst = *(u8 **)((u8 *)D_L39_0024D760 + 0x48);
    dst[0x14C] = 0;
    *(Blob_006D9BC0 *)(dst + 0x150) = *src;
}
/* localdecomp:end func_L39_006D9BC0 */

/* localdecomp:start func_L39_006D9C90 */
typedef struct {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 pad30[0x20];
} Loc_006D9C90;
typedef struct {
    u8 pad00[0x1C0];
    u8 f1C0;
    u8 pad1C1[3];
    u8 f1C4[0x1C];
    s32 f1E0;
} S_006D9C90;
typedef struct {
    u8 pad00;
    u8 f1;
    u8 pad02[6];
    s32 f8;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} G_006D9C90;
typedef struct {
    u8 pad00[0x2DC];
    s32 f2DC;
} P_006D9C90;

s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017F468(void *, void *, s32);
void func_001961E8(void *);
s32 func_001961F8(void);
void func_00195410(void);
void func_L39_005958A0(void *, void *, s32);
extern s32 func_L39_006D8AD8(void *);
extern u8 D_001A5CD0_006D9C90[];
__asm__(".extern D_L39_0024D760, 16");
extern u16 D_L39_00249EE8[];
extern u8 D_00197650[];

void *func_L39_006D9C90(S_006D9C90 *arg0, void *arg1) {
    Loc_006D9C90 loc;
    G_006D9C90 *g;
    P_006D9C90 *p;
    s32 r;
    s32 x;
    void *ret;

    g = (G_006D9C90 *)D_L39_0024D760;
    x = g->f50;
    loc.f00 = D_L39_00249EE8[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    func_L39_005958A0((u8 *)&loc + 0x26, arg1, 0x20);
    arg0->f1C0 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017F468(&loc, D_00197650, 0));
    p = (P_006D9C90 *)D_001A5CD0_006D9C90;
    while (arg0->f1C0 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f1C0 = 0;
    ret = 0;
    if (r != 0) {
        if (arg0->f1E0 == -0x3DD) {
            g->f10 = 0x3D;
            if (g->f14 == 0) {
                g->f14 = 0x3D;
            }
            r = 0;
        } else if (arg0->f1E0 != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
            }
            r = 0;
        }
        ret = r ? arg0->f1C4 : 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006D9C90 */

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
