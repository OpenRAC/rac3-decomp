#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct Vars_3E9BA8 {
    f32 f0;
    f32 f4;
    u8 pad8[0x2C - 0x8];
    f32 f2C;
    u8 pad30[0xC50 - 0x30];
    vu0_v4 vecs[12];
    f32 rot[12];
    f32 fD40;
} Vars_3E9BA8;

INCLUDE_ASM("asm/levels", func_L20_003E6150);

INCLUDE_ASM("asm/levels", func_L20_003E6378);

INCLUDE_ASM("asm/levels", func_L20_003E6D30);

INCLUDE_ASM("asm/levels", func_L20_003E6F88);

/* localdecomp:start func_L20_003E7988 */
extern f32 func_0038CF38(f32 *, f32 *);
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 D_L20_001DF168;
__asm__(".extern D_L20_001DF168, 4");
extern void func_L20_003E6150(u8 *, f32);

void func_L20_003E7988(u8 *p) {
    f32 len = func_0038CF38((f32 *)(p + 0x10), D_L20_001E2E80);

    if (len <= 2.0f && 1.0f < len) {
        func_003C4138(&D_L20_001DF168, 0.5f, 0.2f);
    } else if (len <= 1.0f) {
        func_003C4138(&D_L20_001DF168, 0.0f, 0.2f);
    } else {
        func_003C4138(&D_L20_001DF168, 2.0f, 0.1f);
    }
    func_L20_003E6150(p, D_L20_001DF168);
}
/* localdecomp:end func_L20_003E7988 */

/* localdecomp:start func_L20_003E7A70 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003E5C28.c */
#include "vu0.h"

extern f32 D_L20_001DF178;
__asm__(".extern D_L20_001DF178, 4");
extern s32 D_L20_001DF170;
__asm__(".extern D_L20_001DF170, 4");
extern s32 D_L20_001DF174;
__asm__(".extern D_L20_001DF174, 4");
extern f32 D_L20_001DF17C;
__asm__(".extern D_L20_001DF17C, 4");
extern f32 D_L20_001DF180;
__asm__(".extern D_L20_001DF180, 4");
extern f32 D_L20_001DF184;
__asm__(".extern D_L20_001DF184, 4");
extern u32 D_L20_001DF188;
__asm__(".extern D_L20_001DF188, 4");
extern u32 D_L20_001DF18C;
__asm__(".extern D_L20_001DF18C, 4");
extern u8 D_L20_001E2E00[];
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 e, f32 f, f32 g);

void func_L20_003E7A70(u8 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *p;
    s32 col;
    s32 i;
    f32 nb;
    f32 pf;

    p = *(u8 **)(a0 + 0x68);
    col = func_0038DBD8(D_L20_001DF170, D_L20_001DF174, func_0038D0B0(D_L20_001DF178) * 0.5f + 0.5f);
    nb = func_0038DAB8(D_L20_001DF178, func_003824E0(D_L20_001DF17C, D_L20_001DF180) * 0.017453292f * 0.020000001f);
    pf = *(f32 *)p;
    D_L20_001DF178 = nb;
    func_003D9508(a0 + 0x10, 0x43, col, 1, 2.25f, -0.1f, pf);
    func_003D9508(a0 + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -*(f32 *)(p + 4));
    func_003D9508(a0 + 0x10, 0x4B, 0x7FFFFFFF, 3, 2.0f, 0.025f, -*(f32 *)p);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(d, D_L20_001E2E00, a0 + 0x10);
        func_0038D890(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, d, *(f32 *)(p + 0xD10 + i * 4));
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) + 0.03f;
        if (*(f32 *)(p + 0x2C) > 2.5f) {
            *(f32 *)(p + 0x2C) = 2.5f;
        }
        func_0038CF68(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, *(f32 *)(p + 0x2C));
        vec_add_ab(e, p + 0xC50 + i * 0x10, a0 + 0x10);
        *(u128_t *)g = *(u128_t *)(a0 + 0x10);
        func_L01_0040A8C0((u128_t *)e, (u128_t *)g, 0x12, 1, D_L20_001DF188, D_L20_001DF188, D_L20_001DF18C, D_L20_001DF18C, D_L20_001DF184, 3.0f, *(f32 *)(p + 0xD40));
    }
    *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) - func_003824E0(0.025f, 0.035f);
    if (*(f32 *)(p + 0xD40) <= -8.0f) {
        *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) + 8.0f;
    }
}
/* localdecomp:end func_L20_003E7A70 */

INCLUDE_ASM("asm/levels", func_L20_003E7D00);

INCLUDE_ASM("asm/levels", func_L20_003E8288);

INCLUDE_ASM("asm/levels", func_L20_003E84B0);

INCLUDE_ASM("asm/levels", func_L20_003E8E68);

INCLUDE_ASM("asm/levels", func_L20_003E90C0);

INCLUDE_ASM("asm/levels", func_L20_003E9AC0);

/* localdecomp:start func_L20_003E9BA8 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003E7C98.c */
#include "vu0.h"

extern f32 D_L20_001DF220;
__asm__(".extern D_L20_001DF220, 4");
extern s32 D_L20_001DF218;
__asm__(".extern D_L20_001DF218, 4");
extern s32 D_L20_001DF21C;
__asm__(".extern D_L20_001DF21C, 4");
extern f32 D_L20_001DF224;
__asm__(".extern D_L20_001DF224, 4");
extern f32 D_L20_001DF228;
__asm__(".extern D_L20_001DF228, 4");
extern f32 D_L20_001DF22C;
__asm__(".extern D_L20_001DF22C, 4");
extern u32 D_L20_001DF230;
__asm__(".extern D_L20_001DF230, 4");
extern u32 D_L20_001DF234;
__asm__(".extern D_L20_001DF234, 4");
extern u8 D_L20_001E2E00[];
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 e, f32 f, f32 g);

void func_L20_003E9BA8(u8 *obj) {
    vu0_v4 w;
    vu0_v4 p;
    vu0_v4 q;
    Vars_3E9BA8 *vars;
    s32 i;
    s32 col;

    vars = *(Vars_3E9BA8 **)(obj + 0x68);
    col = func_0038DBD8(D_L20_001DF218, D_L20_001DF21C, func_0038D0B0(D_L20_001DF220) * 0.5f + 0.5f);
    D_L20_001DF220 = func_0038DAB8(D_L20_001DF220, func_003824E0(D_L20_001DF224, D_L20_001DF228) * 0.017453292f * 0.020000001f);
    func_003D9508(obj + 0x10, 0x43, col, 1, 2.25f, -0.1f, vars->f0);
    func_003D9508(obj + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -vars->f4);
    func_003D9508(obj + 0x10, 0x4B, 0xDFFFFFFF, 3, 2.0f, 0.025f, -vars->f0);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(&w, &D_L20_001E2E00, obj + 0x10);
        func_0038D890(&vars->vecs[i], &vars->vecs[i], &w, vars->rot[i]);
        vars->f2C = vars->f2C + 0.03f;
        if (vars->f2C > 2.5f) {
            vars->f2C = 2.5f;
        }
        func_0038CF68(&vars->vecs[i], &vars->vecs[i], vars->f2C);
        vec_add_ab(&p, &vars->vecs[i], obj + 0x10);
        q = *(vu0_v4 *)(obj + 0x10);
        func_L01_0040A8C0(&p, &q, 0x12, 1, D_L20_001DF230, D_L20_001DF230, D_L20_001DF234, D_L20_001DF234, D_L20_001DF22C, 3.0f, vars->fD40);
    }
    vars->fD40 = vars->fD40 - func_003824E0(0.025f, 0.035f);
    if (vars->fD40 <= -8.0f) {
        vars->fD40 = vars->fD40 + 8.0f;
    }
}
/* localdecomp:end func_L20_003E9BA8 */

INCLUDE_ASM("asm/levels", func_L20_003E9E38);

/* localdecomp:start func_L20_003EA258 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003E8318.c */
#include "vu0.h"

extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern f32 D_L20_001DF240;
__asm__(".extern D_L20_001DF240, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L20_003EA488(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);
extern void func_L01_00404808(void (*)(void *), void *);
extern u8 *func_00382348(s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);

void func_L20_003EA258(u8 *obj) {
    u8 buf[0x30];
    vu0_v4 q;
    vu0_v4 r;
    u8 *vars;
    u8 *e;
    f32 ang;
    f32 k;
    f32 sc;
    s32 i;

    vars = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        *(vu0_q *)vars = *(vu0_q *)(obj + 0x10);
        obj[0x20] = 3;
        *(s32 *)(vars + 0x18) = 17;
        break;
    case 3:
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(obj, 1);
        if (*(f32 *)(vars + 0x1C) > D_L20_001DF23C) {
            func_003C2880(obj);
            return;
        }
        func_L01_00404808(func_L20_003EA488, obj);
        k = D_L20_001DF240 * 0.020000001f;
        *(f32 *)(vars + 0x1C) = *(f32 *)(vars + 0x1C) + k;
        *(f32 *)(vars + 0x20) = *(f32 *)(vars + 0x20) + k;
        sc = 2.0f;
        if (*(s32 *)(obj + 0xB8) != 0) {
            e = func_00382348(*(s32 *)(obj + 0xB8));
            if (e != 0) {
                sc = (f32)e[0x16];
            }
        }
        func_L01_00446760(buf, obj, 0x08000001, &D_L20_001D66B0, sc);
        ang = 0.0f;
        q.x = func_0038D098(ang) * *(f32 *)(vars + 0x1C);
        q.y = func_0038D0B0(ang) * *(f32 *)(vars + 0x1C);
        q.z = 0.0f;
        ang = 0.5235988f;
        vec_add_ba(&q, &q, obj + 0x10);
        for (i = 11; i >= 0; i--) {
            r.x = func_0038D098(ang) * *(f32 *)(vars + 0x1C);
            r.y = func_0038D0B0(ang) * *(f32 *)(vars + 0x1C);
            r.z = 0.0f;
            vec_add_ba(&r, &r, obj + 0x10);
            func_003D3CB0(&q, &r, 9, obj, buf);
            ang = func_0038DAB8(ang, 0.5235988f);
            q = r;
        }
        break;
    }
}
/* localdecomp:end func_L20_003EA258 */

INCLUDE_ASM("asm/levels", func_L20_003EA488);

INCLUDE_ASM("asm/levels", func_L20_003EAA70);

INCLUDE_ASM("asm/levels", func_L20_003EABD8);

INCLUDE_ASM("asm/levels", func_L20_003EB388);

INCLUDE_ASM("asm/levels", func_L20_003EB4E0);

/* localdecomp:start func_L20_003EB838 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 d; f32 k0, k1, k2; } Loc38;

extern f32 func_003824E0(f32 a, f32 b);
extern s32 D_L20_001DFD40;
extern void func_L01_0046E078(void *a0, void *a1, void *a2, void *a3, s32 a4);

void func_L20_003EB838(u8 *arg0, u8 *arg1) {
    Loc38 loc;

    loc.k0 = func_003824E0(-1.0f, -0.9f) * *(f32 *)(arg1 + 0x8);
    loc.k1 = func_003824E0(-0.05f, 0.05f) * *(f32 *)(arg1 + 0x8);
    loc.k2 = func_003824E0(-0.05f, 0.05f) * *(f32 *)(arg1 + 0x8);
    vec_sub_ab(&loc.d, arg0 + 0x10, arg1 + 0x10);
    if ((D_L20_001DFD40 & 3) == (((s32)arg0 >> 8) & 3)) {
        func_L01_0046E078(arg0, &loc.d, &loc.k0, arg1 + 0x30, 1);
    }
}
/* localdecomp:end func_L20_003EB838 */
