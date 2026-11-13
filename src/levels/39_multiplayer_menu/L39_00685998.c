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

/* declared by functions of L39_00681758.c, which this file was cut from */
extern void func_L39_0067EEC8(u8 *, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516818(s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);
s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
s32 func_L01_00517538(s32, f32, f32);

/* declared by functions of L39_00684488.c, which this file was cut from */
void func_0011D534(s32, s32, s32);
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern void func_L39_0067EEC8(u8 *, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L39_0067F1B0(void);
extern void func_003E8630(s32, s32);
extern s32 D_001DBC5C_sda;
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);
void func_00120D28(s32, s32, s32);
extern void func_00120D28(s32, s32, s32);

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

/* localdecomp:start func_L39_006859E8 */
extern void func_00120D28(s32, s32, s32);
extern void func_0011D534(s32, s32, s32);
extern s32 func_00120884(s32);
extern void func_001202F4(s32, void *);
extern u8 D_00247790[];

void func_L39_006859E8(s32 arg0, s32 arg1) {
    s32 n;
    s32 i;

    func_00120D28(arg0 + 0x64, arg1, 0xC8);
    *(u8 *)(arg0 + 0x12B) = 0;
    func_0011D534(arg0 + 0x3DC, 0, 0xC8);
    n = func_00120884(arg0 + 0x64);
    for (i = 0; i < n; i++) {
        func_001202F4(arg0 + 0x3DC, D_00247790);
    }
    *(s32 *)(arg0 + 0x234) = 0;
}
/* localdecomp:end func_L39_006859E8 */

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

/* localdecomp:start func_L39_00685AE0 */
void func_L39_00685AE0(u8 *obj, u8 *str) {
    u8 *p;

    if (str != 0 && *str != 0) {
        p = str;
        do {
            (*(void (**)(u8 *, s32))(*(u8 **)(obj + 0x60) + 0xC8))(obj, *p);
            p++;
        } while (str != 0 && *p != 0);
    }
}
/* localdecomp:end func_L39_00685AE0 */

/* localdecomp:start func_L39_00685B50 */
void func_L39_00685B50(u8 *obj, u8 *str) {
    u8 *p;

    if (str != 0 && *str != 0) {
        p = str;
        do {
            (*(void (**)(u8 *, s32))(*(u8 **)(obj + 0x60) + 0xCC))(obj, *p);
            p++;
        } while (str != 0 && *p != 0);
    }
}
/* localdecomp:end func_L39_00685B50 */

LINKER_REMNANT("asm/levels", func_L39_00685BC0);

/* localdecomp:start func_L39_00685BC8 */
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern u8 D_L39_0047C118[];

void *func_L39_00685BC8(void *arg0, void *arg1) {
    func_L39_0067EE40(arg0, arg1);
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
    *(void **)((u8 *)arg0 + 0x60) = D_L39_0047C118;
    *(f32 *)((u8 *)arg0 + 0x74) = *(f32 *)((u8 *)arg1 + 0x48);
    *(f32 *)((u8 *)arg0 + 0x7C) = *(f32 *)((u8 *)arg1 + 0x50);
    *(f32 *)((u8 *)arg0 + 0x78) = *(f32 *)((u8 *)arg1 + 0x4C);
    *(f32 *)((u8 *)arg0 + 0x80) = *(f32 *)((u8 *)arg1 + 0x54);
    *(s32 *)((u8 *)arg0 + 0x68) = *(s32 *)((u8 *)arg1 + 0x58);
    *(s32 *)((u8 *)arg0 + 0x6C) = *(s32 *)((u8 *)arg1 + 0x5C);
    *(s32 *)((u8 *)arg0 + 0x70) = 0;
    return arg0;
}
/* localdecomp:end func_L39_00685BC8 */

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

/* localdecomp:start func_L39_00685C70 */
typedef struct S_00685C70 {
    u8 pad0[0x50];
    f32 f50;
    f32 f54;
    f32 f58;
    f32 f5C;
    u8 pad60[4];
    s32 f64;
    s32 f68;
    u8 pad6C[4];
    f32 f70;
} S_00685C70;

extern s32 func_L39_0067F1B0(void);
extern s32 func_003E9138_00685C70(s32, s32, f32, f32, f32, f32, s32);
extern void func_L01_005168F0(s32);
extern void func_003E8630(s32, s32);
extern s32 D_001DBC5C_sda;

void func_L39_00685C70(void *arg0) {
    S_00685C70 *self = (S_00685C70 *)arg0;

    if (self->f64 == -1) {
        self->f64 = func_L39_0067F1B0();
        func_003E9138_00685C70(self->f64, 0x80808080, self->f50, self->f54, self->f58, self->f5C, self->f68);
        ((void (*)(s32, f32))func_L01_005168F0)(self->f64, self->f70);
        func_003E8630(D_001DBC5C_sda, self->f64);
    }
}
/* localdecomp:end func_L39_00685C70 */

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
