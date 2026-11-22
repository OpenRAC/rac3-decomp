#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;
typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;
typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;
typedef struct { u8 b[16]; } V16_48DCD8;

/* declared by functions of L01_0048B738.c, which this file was cut from */
extern char *func_00381FF0(s32 id);
extern s32 func_003BB118(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);

/* localdecomp:start func_L01_004903F0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 type;
    s32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    s32 f20;
    s32 f24;
    f32 f28;
    s32 f2C;
} E_004903F0;
extern s32 func_L01_00518D40_004903F0(s32);
extern void func_L01_00518590(s32, s32, s32);
extern void func_L01_00516470_004903F0(s32, f32, f32);
extern void func_L01_00517538_004903F0(s32, f32, f32);
extern void func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern void func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E90B8(s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_00516728(s32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00518670(s32, s32, s32);
extern void func_L01_00516B90_004903F0(s32, s32, s32);
extern void func_003E8630(s32, s32);
extern s32 func_00381FF0_004903F0(s32);

void func_L01_004903F0(E_004903F0 *tbl) {
    s32 a = 3;
    s32 b = 3;
    s32 i = 0;
    E_004903F0 *e;

    while (tbl[i].f0 != 0) {
        e = &tbl[i];
        switch (e->type) {
        case 0:
            func_L01_00518D40_004903F0(e->f0);
            if (e->f2C & 1) {
                func_L01_00518590(e->f0, 1, 1);
                func_L01_00516470_004903F0(e->f0, e->f10, e->f14);
                func_L01_00517538_004903F0(e->f0, e->f18, e->f1C);
            }
            break;
        case 1:
            func_003E8EF0(e->f0, e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.0f);
            break;
        case 2:
            func_003E9138(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f24);
            break;
        case 3:
            func_003E9270(e->f0, e->fC, e->f10, e->f14, e->f18, e->f1C, e->f28, e->f28);
            break;
        case 4:
            func_003E90B8(e->f0, (e->f2C & 4) ? func_00381FF0_004903F0(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 0.005f, 0.005f);
            break;
        case 5:
            func_003E9358(e->f0, (e->f2C & 4) ? func_00381FF0_004903F0(e->f24) : e->f24, e->fC, e->f10, e->f14, e->f18, e->f1C, 1.0f);
            func_L01_00516818(e->f0, e->f28);
            func_L01_00516728(e->f0, e->f28 * 0.005f, e->f28 * 0.005f);
            func_L01_00516AA0(e->f0, 0x40, 1);
            if (e->f2C & 8) func_L01_00518670(e->f0, 1, 1);
            break;
        }
        if (e->f20 != 0) {
            if (e->f20 & 1) a = 1;
            else if (e->f20 & 2) a = 2;
            if (e->f20 & 8) b = 1;
            else if (e->f20 & 0x10) b = 2;
            func_L01_00516B90_004903F0(e->f0, a, b);
        }
        if (e->f2C & 2) func_L01_00516AA0(e->f0, 1, 0);
        if (e->f4 != 0) func_003E8630(e->f4, e->f0);
        i++;
    }
}
/* localdecomp:end func_L01_004903F0 */

/* localdecomp:start func_L01_004906D0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
} S_004906D0;
extern s32 D_L01_001D8D60;
extern f32 D_L01_001D8D7C;
extern f32 D_L01_001D8D80;
extern f32 D_L01_001D8D84;
extern f32 D_L01_001D8D88;
extern f32 D_L01_001D8D8C;
extern f32 D_L01_001D8D90;
__asm__(".extern D_L01_001D8D60, 4");
__asm__(".extern D_L01_001D8D7C, 4");
__asm__(".extern D_L01_001D8D80, 4");
__asm__(".extern D_L01_001D8D84, 4");
__asm__(".extern D_L01_001D8D88, 4");
__asm__(".extern D_L01_001D8D8C, 4");
__asm__(".extern D_L01_001D8D90, 4");
extern s32 func_L01_0047DAE0(void);
extern s32 *func_003B9BD0(s32);
extern void func_003B9C68(s32 *, void *);
extern void func_003BABB0(s32 *, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32 *, f32, f32, f32, f32);
extern void func_003BA4E0(s32 *, s32, f32, f32, f32);
extern void func_003BA358(s32 *, s32, s32, s32);
extern void func_L01_00490A50(void);

void func_L01_004906D0(void) {
    S_004906D0 d;
    s32 n;
    s32 x;

    n = 7;
    D_L01_001D8D60 = n;
    d.f0 = func_L01_0047DAE0();
    d.f4 = func_003BB118(0);
    x = D_L01_001D8D60;
    n = x < 9 ? x : 8;
    d.f18 = 1.0f;
    d.f1C = D_L01_001D8D7C;
    d.f8 = 0x14;
    D_L01_001D8D84 = (f32)(x + 1) * 0.0532f / (f32)x;
    d.f20 = D_L01_001D8D84;
    d.f24 = D_L01_001D8D88;
    d.f28 = D_L01_001D8D8C;
    d.f2C = 1.0f;
    d.f30 = 1.0f;
    d.f34 = D_L01_001D8D90;
    d.f10 = n;
    d.f14 = 2;
    d.fC = x;
    d.f38 = d.f28 - d.f24 - d.f34;
    d.f3C = 0;
    d.f40 = 0;
    d.f44 = 0;
    d.f48 = 0;
    d.f4C = 0;
    d.f50 = 0;
    func_003B9C68(func_003B9BD0(0), &d);
    func_003BABB0(func_003B9BD0(0), 0, 0.5f, 0.817342f, 0.045f, 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), 0.5f, 0.632204f, 0.817342f, 0.439128f);
    func_003BA4E0(func_003B9BD0(0), 1, D_L01_001D8D80, 0.00666f, 0.03f);
    func_003BA358(func_003B9BD0(0), 0, 1, 3);
    func_003BA358(func_003B9BD0(0), 1, 2, 3);
    func_L01_00490A50();
}
/* localdecomp:end func_L01_004906D0 */
