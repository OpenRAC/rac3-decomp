#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003DCB60);

INCLUDE_ASM("asm/levels", func_L07_003DCFF8);

INCLUDE_ASM("asm/levels", func_L07_003DD3C8);

INCLUDE_ASM("asm/levels", func_L07_003DD5D8);

/* localdecomp:start func_L07_003DD6D8 */
typedef struct {
    u8 pad_0[8];
    u8 x8;              /* 0x8 */
    u8 pad_9[0x60 - 0x9];
    void *x60;          /* 0x60 */
    f32 x64;            /* 0x64 */
} S_3DD6D8_OBJ;

typedef struct {
    u8 pad_0[0x68];
    S_3DD6D8_OBJ *obj;  /* 0x68 */
    u8 pad_6C[0xF0 - 0x6C];
    f32 xF0;            /* 0xF0 */
} S_3DD6D8;

typedef struct {
    u8 pad_0[0xF0];
    f32 xF0;            /* 0xF0 */
} S_3DD6D8_XF0;

extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003DD6D8(S_3DD6D8 *arg0)
{
    S_3DD6D8_OBJ *o = arg0->obj;
    f32 v;

    o->x64 = 0;
    v = func_003C3BE8(3.1415927f, o->x64, o->x64);
    arg0->xF0 = v;
    ((S_3DD6D8_XF0 *)o->x60)->xF0 = v;
    func_003C7C38(o->x60);
    o->x8 = 1;
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003DD6D8 */

/* localdecomp:start func_L07_003DD750 */
/* Vec4f, declared locally: the owning source file includes only common.h. */
typedef struct {
    f32 x, y, z, w;
} V4_3DD750;

typedef struct {
    u8 pad_0[0x10];
    V4_3DD750 v10;      /* 0x10 */
} S_3DD750;

typedef struct {
    u8 pad_0[0x80];
    V4_3DD750 pos;      /* 0x80 */
    u8 pad_90[0x25C0 - 0x90];
    void *moby;         /* 0x25C0 */
} S_3DD750_HERO;

extern S_3DD750_HERO D_001A4BE0;
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern f32 D_001DA978;
extern f32 D_002F3630[];
extern u8 D_L07_001D66B0[8];

extern f32 func_L01_0040E570(void *a, void *b);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446A70(void *a, void *b, s32 c, void *d, void *e, f32 f);

void func_L07_003DD750(S_3DD750 *arg0)
{
    S_3DD750_HERO *h = &D_001A4BE0;

    if (fabsf(arg0->v10.z - h->pos.z) < 0.5f) {
        if (func_L01_0040E570(&arg0->v10, &h->pos) <= 4.0f) {
            f32 v;
            if (func_L01_0041A4F0()) {
                s32 id = D_001D545C;
                if (id == 7 && D_0014275B[0] != 0) v = D_001DA978;
                else v = D_002F3630[id];
            } else {
                v = 1.0f;
            }
            func_L01_00446A70(h->moby, arg0, 1, D_L07_001D66B0,
                          D_L07_001D66B0, v);
        }
    }
}
/* localdecomp:end func_L07_003DD750 */

INCLUDE_ASM("asm/levels", func_L07_003DD838);

/* localdecomp:start func_L07_003DDA38 */
typedef struct {
    u8 pad_0[0x68];
    u8 *obj;            /* 0x68 */
    u8 pad_6C[0x78 - 0x6C];
    void *x78;          /* 0x78 */
    u8 pad_7C[0xF0 - 0x7C];
    s32 xF0;            /* 0xF0 */
} S_3DDA38;

typedef struct {
    s32 x0;             /* 0x0 */
    s32 x4;             /* 0x4 */
    u8 x8[0x8];         /* 0x8 */
    s32 x10;            /* 0x10 */
    u8 pad_14[4];
    f32 x18;            /* 0x18 */
    u8 x1C;             /* 0x1C */
} T_3DDA38;

extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_001DE964_sda;
__asm__(".extern D_001DE964_sda, 4");
extern void *D_001DE968_sda;
__asm__(".extern D_001DE968_sda, 4");

extern void func_L01_004AA760(s32, void *);
extern void func_L07_003B2870(u8 *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003DDA38(void *arg0, u8 arg1)
{
    S_3DDA38 *a = arg0;
    T_3DDA38 *s = (T_3DDA38 *)a->obj;
    s32 st;

    s->x1C = arg1;
    s->x10 = 0;
    a->x78 = D_001DE968_sda;
    a->xF0 = 0;
    func_L01_004AA760(0, arg0);
    func_L07_003B2870(D_L07_001DF41C + (s->x0 << 8));
    func_L07_003B2870(D_L07_001DF41C + (s->x4 << 8));
    s->x18 = (f32)D_001DE964_sda * 3.1415927f * 2.0f;
    st = s->x8[arg1];
    if (st == 1) {
        s->x18 = s->x18 + 4.1887903f;
        func_L01_004450F0(arg0, 2, -1);
    } else if (st == 2) {
        s->x18 = s->x18 + 2.0943952f;
        func_L01_004450F0(arg0, 2, -1);
    } else {
        func_L01_004450F0(arg0, 1, -1);
    }
}
/* localdecomp:end func_L07_003DDA38 */
