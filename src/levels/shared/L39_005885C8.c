#include "common.h"

/* localdecomp:start func_L39_005885C8 */
typedef int u128_005885C8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005885C8;
typedef struct { u8 pad[0x34]; u16 flags; } O_005885C8;
typedef struct {
    u128_005885C8 q0;
    f32 rx, ry, rz;
    u8 pad1C[4];
    u128_005885C8 *verts;
    f32 su, sv;
    s32 count;
    s32 x30;
    u8 pad34[0xC];
    O_005885C8 *objs[4];
} S_005885C8;
typedef struct { u8 pad[0x50]; S_005885C8 *s; } G_005885C8;
typedef struct { u128_005885C8 q[4]; } M_005885C8;
typedef struct { u128_005885C8 q; } M1_005885C8;
typedef struct { u128_005885C8 q; u8 pad[0x10]; M_005885C8 m; } C_005885C8;
typedef struct { u8 pad[0xB0]; f32 xB0; } F_005885C8;
typedef struct { u128_005885C8 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_005885C8;
typedef struct { u8 b[0x100]; } B_005885C8;
typedef struct { M_005885C8 m; u128_005885C8 q; } SV_005885C8;

extern G_005885C8 D_L39_0025CEC0;
extern C_005885C8 D_L39_0024DE00;
extern F_005885C8 D_L39_0025D6C0;
extern M_005885C8 D_L39_00266740;
extern long D_L39_00240380_005885C8;
extern void *D_L39_0024BF5C;
__asm__(".extern D_001D6EB0_sda, 8");
__asm__(".extern D_001D6EC0_sda, 8");
__asm__(".extern D_001D6ED0_sda, 8");
__asm__(".extern D_001D6EE0_sda, 8");
__asm__(".extern D_001D6E88_sda, 8");
__asm__(".extern D_001D6E98_sda, 8");
extern u128_005885C8 D_001D6EB0_sda __attribute__((section(".sdata")));
extern u128_005885C8 D_001D6EC0_sda __attribute__((section(".sdata")));
extern u128_005885C8 D_001D6ED0_sda __attribute__((section(".sdata")));
extern u128_005885C8 D_001D6EE0_sda __attribute__((section(".sdata")));
extern f32 D_001D6E88_sda[4] __attribute__((section(".sdata")));
extern f32 D_001D6E98_sda[4] __attribute__((section(".sdata")));
__asm__(".extern D_001D6F00_sda, 4");
extern s32 D_001D6F00_sda;

extern void func_L01_003EA9B8_005885C8(void);
extern void func_L01_003EBF38_005885C8(void);
extern void func_003C36C0(void);
extern void func_003C3638(void);
extern void func_003C3660(void);
extern void func_003C3690(void);
extern void func_003C3800(void);
extern void func_003C3860(void);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_L39_005ABFE8(void *, s32);
extern void func_0038CD28(void *, void *, s32);
extern void func_003881B0(s32, s32);
extern void func_0013D5C0(void *);
extern void func_0013D708(void *, void *, f32);
extern void func_0013D7B0(void *, void *, f32);
extern void func_0013D660(void *, void *, f32);
extern void func_003861F0(void);
extern void func_L01_00423040_005885C8(void);
extern void func_L39_005872D8(void);
extern void func_003A9440(s32, unsigned long);
extern void func_L01_004C5D68(void);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00388258(S_005885C8 *, u128_005885C8 *, long);

void func_L39_005885C8(void) {
    B_005885C8 bufs[4];
    SV_005885C8 saved;
    M_005885C8 m;
    P_005885C8 prim;
    S_005885C8 *s;
    O_005885C8 *o;
    B_005885C8 *dst;
    f32 f;
    s32 n;
    s32 i;
    s32 k;
    s32 j;
    s32 r;
    s32 q;

    func_L01_003EA9B8_005885C8();
    s = D_L39_0025CEC0.s;
    if (s != 0) {
        n = 0;
        func_003C36C0();
        func_003C3638();
        func_003C3660();
        for (i = 0; i < 4; i++) {
            o = s->objs[i];
            if (o != 0) {
                func_003C6F90(o, 0x404040, 14, 0, 0);
                n++;
                o->flags |= 1;
            } else {
                break;
            }
        }
        func_L39_005ABFE8(D_L39_0024BF5C, -1);
        for (i = 0; i < 4; i++) {
            o = s->objs[i];
            if (o != 0) {
                o->flags &= ~1;
            } else {
                break;
            }
        }
        func_0038CD28(&saved.m, &D_L39_0024DE00.m, 0x40);
        saved.q = D_L39_0024DE00.q;
        f = D_L39_0025D6C0.xB0;
        ((void (*)(s32, s32, f32))func_003881B0)(8, 8, 1.0f);
        func_0013D5C0(&m);
        func_0013D708(&m, &m, s->rx);
        func_0013D7B0(&m, &m, s->ry);
        func_0013D660(&m, &m, s->rz);
        func_0038CD28(&D_L39_0024DE00.m, &m, 0x40);
        D_L39_0024DE00.q = s->q0;
        func_003861F0();
        D_L39_00266740.q[0] = D_001D6EB0_sda;
        D_L39_00266740.q[2] = D_001D6EC0_sda;
        D_L39_00266740.q[1] = D_001D6ED0_sda;
        D_L39_00266740.q[3] = D_001D6EE0_sda;
        if (n == 1) {
            func_L39_005ABFE8(s->objs[0], 1);
        } else {
            dst = bufs;
            for (i = 0; i < 4; i++) {
                o = s->objs[i];
                if (o != 0) {
                    func_0038CD28(dst, o, 0x100);
                    dst++;
                }
            }
            func_L39_005ABFE8(bufs, n);
        }
        func_L01_00423040_005885C8();
        D_L39_0025D6C0.xB0 = f;
        func_L39_005872D8();
        func_0038CD28(&D_L39_0024DE00.m, &saved.m, 0x40);
        D_L39_0024DE00.q = saved.q;
        func_003861F0();
        func_003A9440(0x42, 0x8000000044UL);
        func_003A9440(8, 5);
        func_L01_004C5D68();
        func_003C3690();
        func_003C3800();
        r = 0;
        j = 0;
        if (D_L39_0025CEC0.s->count > 0) {
            do {
                prim.c = 0xFF9000000260UL;
                prim.tex = D_L39_00240380_005885C8;
                prim.a = 5;
                prim.d = 0x8000000044UL;
                prim.rgba[3] = D_001D6F00_sda;
                prim.rgba[2] = D_001D6F00_sda;
                prim.rgba[1] = D_001D6F00_sda;
                prim.rgba[0] = D_001D6F00_sda;
                for (k = 0, q = 0; k < 4; k++, q++) {
                    prim.uv[k][0] = s->su * D_001D6E88_sda[k] + 0.5f;
                    prim.uv[k][1] = s->sv * D_001D6E98_sda[k] + 0.5f;
                    *(prim.pos + k) = s->verts[j + q];
                }
                func_003D2DA0(&prim, 0, 0);
                if (s->x30 != 0) {
                    func_00388258(s, &s->verts[j], D_L39_00240380_005885C8);
                }
                r++;
                j += 4;
            } while (r < D_L39_0025CEC0.s->count);
        }
    } else {
        func_003C3860();
    }
    func_L01_003EBF38_005885C8();
}
/* localdecomp:end func_L39_005885C8 */
