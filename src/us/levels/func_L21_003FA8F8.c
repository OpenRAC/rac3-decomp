#include "common.h"

/* NTSC-U counterpart of func_L21_003FD638 (src/levels/21_obani_draco/L21_003FD638.c) */
#include "vu0.h"

/* localdecomp:start func_L21_003FA8F8 */
typedef struct O_003FD638 {
    u8 pad0[0x10];
    vu0_q pos;
    u8 pad20[0x14];
    u16 flags;
    u8 pad36[0x2D];
    u8 b63;
    u8 pad64[4];
    s32 p68;
    u8 pad6C[0x3E];
    s16 id;
} O_003FD638;
typedef struct G_003FD638 {
    u8 pad0[0x30];
    s32 v30;
    s32 v34;
    u8 pad38[0xC];
    s16 n;
    u8 pad46[0x15A];
    O_003FD638 *list[2];
    O_003FD638 *l1A8;
    O_003FD638 *l1AC;
    O_003FD638 *l1B0;
} G_003FD638;
typedef struct {
    s16 a0;
    s16 a2;
    f32 a4;
    f32 a8;
    f32 ac;
    f32 b0;
    s32 b4;
    s32 b8;
    s32 bc;
} P_003FD638;

extern G_003FD638 D_L21_001E5AC0;
extern O_003FD638 *D_L21_00238130[];
__asm__(".extern D_L21_00238130, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L21_001D6AE0_003FA8F8[4];
__asm__(".extern D_L21_001D6AE0_003FA8F8, 4");
extern u8 D_L21_001D6AE4_003FA8F8;
__asm__(".extern D_L21_001D6AE4_003FA8F8, 16");
extern u8 D_L21_001D6AE8_003FA8F8;
__asm__(".extern D_L21_001D6AE8_003FA8F8, 16");
extern f32 D_L21_001DE758;
__asm__(".extern D_L21_001DE758, 4");

extern void func_L01_00420D88();
extern void func_003A04A0();
extern void func_L01_004026A0();
extern void func_003A26D0();
extern void func_L01_0044EB38(void *, void *, unsigned, unsigned, float);
extern void func_L01_00402498();
extern void func_L01_00421438();
extern void func_L21_003F9CD0();
extern void func_L03_0040E698();
extern void func_L03_0040EE18();
extern void func_L08_00403E80(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L08_004038A8(void *, s32, s32, s32, f32, f32, f32);
extern O_003FD638 *func_L10_00403490(s32);
extern void func_003BF6A8(void *, f32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);

void func_L21_003FA8F8(void) {
    int i;
    O_003FD638 *o;
    int j;

    func_L01_00420D88();
    for (i = 0; i < D_L21_001E5AC0.n; i++) {
        o = D_L21_001E5AC0.list[i];
        if (o != 0 && o->id == 0xE29) o->flags |= 0x800;
        if (o->id == 0xD54) {
            o->b63 = 0;
            for (j = 0; D_L21_00238130[j] != 0; j++) {
                if (D_L21_00238130[j]->b63 != 0) D_L21_00238130[j]->b63 = 1;
            }
            func_003A04A0(o, 0);
            func_L01_004026A0(func_003A26D0, o);
        }
        if (o != 0) {
            if (o->id == 0xFA0) {
                if (o->p68 != 0)
                    func_L01_0044EB38(o, (void *)(o->p68 + 12), 0x80AAAAD2, 0x80396464, 0.061086528f);
            } else if (o->id == 0x1DEE || o->id == 0x19BC) {
                func_L01_0044EB38(o, D_L21_001D6AE0_003FA8F8, 0x80505080, 0x80404038, 0.031997703f);
            } else if (o->id == 0x1977) {
                func_L01_0044EB38(o, &D_L21_001D6AE4_003FA8F8, 0x8080AAAA, 0x80464646, 0.03781547f);
            } else if (o->id == 0x1766) {
                func_L01_0044EB38(o, &D_L21_001D6AE8_003FA8F8, 0x80AAAAFF, 0x80646496, 0.110537529f);
            } else if (o->id == 0x195B || o->id == 0x1B58 || o->id == 0x195C || o->id == 0x175A) {
                func_L01_00402498(func_L01_00421438, o);
            }
        }
    }
    if (D_001D545C == 0x15) {
        G_003FD638 *g = &D_L21_001E5AC0;
        vu0_v4 q;
        if (g->v30 == 0) {
            vu0_v4 w;
            vu0_v4 c;
            vu0_v4 t;
            P_003FD638 p;
            O_003FD638 *s;
            vu0_v4 *qq;
            *(vu0_q *)&c = 0;
            c.x = 0.1f;
            c.z = 1.4f;
            p.b4 = 0xC0505080;
            p.a0 = 0x3C;
            p.a2 = 0x32;
            p.a4 = 0.15f;
            p.a8 = 0.005f;
            p.ac = 0.0066666672f;
            if (g->v34 == 0x956) {
                vu0_v4 u;
                *(vu0_q *)&u = 0;
                u.z = 1.0f;
                func_L08_00403E80(0, &u, 0xF, 5, 0x3C, 0x1E, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
            if ((u32)(g->v34 - 0x1D1) < 0x42A) {
                func_L01_00402498(func_L21_003F9CD0, 0);
            }
            {
                s32 n = abs_asm(g->v34 - 0x514);
                if (n < 5) {
                    f32 r = (f32)n * 0.25f;
                    if (1.0f < r) {
                        r = 1.0f;
                    } else if (r < 0.0f) {
                        r = 0.0f;
                    }
                    D_L21_001DE758 = 1.0f - r;
                    s = func_L10_00403490(0x1F32);
                    if (s != 0) {
                        int k;
                        p.bc = 200;
                        for (k = 0; k < p.bc; k++) {
                            qzero(&w);
                            func_003BF6A8(&w, p.ac * 0.5f);
                            *(vu0_q *)&q = s->pos;
                            qq = &q;
                            func_003BF6A8(qq, 2.0f);
                            func_L01_00468DC0(qq, &w, p.b4, func_0037E250(p.a8, p.a4),
                                              (s32)func_0037E250((f32)p.a2, (f32)p.a0), func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
                        }
                    }
                }
            }
            {
            G_003FD638 *h = &D_L21_001E5AC0;
            if (h->v34 == 0x517) {
                int a;
                int b;
                int nx;
                O_003FD638 *e = h->l1B0;
                func_L08_004038A8(e, p.b4, p.b4, 10, 4.0f, 8.0f, 3.0f);
                for (a = 0; a < 5; a = nx) {
                    nx = a + 1;
                    for (b = 9; b >= 0; b--) {
                        func_003BDA38(e, a, &q);
                        func_003BF6A8(&q, 0.05f);
                        qzero(&w);
                        func_003BF6A8(&w, p.ac * 0.1f);
                        w.z = w.z + p.ac * 0.2f;
                        func_L01_00468DC0(&q, &w, p.b4, func_0037E250(p.a8, p.a4) * 3.0f,
                                          (s32)func_0037E250((f32)p.a2, (f32)p.a0) * 2, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
                    }
                }
            }
            }
            {
            G_003FD638 *h = &D_L21_001E5AC0;
            if ((u32)(h->v34 - 0x437) < 0x83 && func_0037E1D8(0x514) > 0x514 - h->v34) {
                s = func_L10_00403490(0x1BD2);
                if (s != 0 && func_0037E1D8(2) == 0) {
                    int k;
                    p.bc = h->v34 >> 7;
                    for (k = 0; k < p.bc; k++) {
                        qzero(&w);
                        func_003BF6A8(&w, p.ac);
                        *(vu0_q *)&q = s->pos;
                        vec_add_ba(&q, &q, &c);
                        func_003886E8(&t, &w, 60.0f);
                        vec_add_ab(&q, &q, &t);
                        func_003886E8(&w, &w, -1.0f);
                        func_L01_00468DC0(&q, &w, p.b4, func_0037E250(p.a8, p.a4),
                                          (s32)func_0037E250((f32)p.a2, (f32)p.a0), func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
                    }
                }
            }
            }
            func_L03_0040E698(0x74C, 0x8CE);
        } else if (g->v30 == 1) {
            if (g->v34 == 0x4B) {
                *(vu0_q *)&q = 0;
                q.z = 1.0f;
                func_L08_00403E80(0, &q, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
        } else if (g->v30 == 2) {
            func_L03_0040E698(0xF8, 0x184);
            if (g->v34 >= 0) {
                O_003FD638 *s = g->l1B0;
                if (s != 0) {
                    func_L03_0040EE18(s, 0);
                    func_L03_0040EE18(s, 1);
                }
            }
        }
    }
}
/* localdecomp:end func_L21_003FA8F8 */
