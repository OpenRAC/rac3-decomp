#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L21_003FD638 */
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

extern G_003FD638 D_L21_001E5A40;
extern O_003FD638 *D_L21_002380B0[];
__asm__(".extern D_L21_002380B0, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_L21_001D6AE0[4];
__asm__(".extern D_L21_001D6AE0, 4");
extern u8 D_L21_001D6AE4;
__asm__(".extern D_L21_001D6AE4, 16");
extern u8 D_L21_001D6AE8;
__asm__(".extern D_L21_001D6AE8, 16");
extern f32 D_L21_001DE6D8;
__asm__(".extern D_L21_001DE6D8, 4");

extern void func_L01_00423AB8();
extern void func_003A58C0();
extern void func_L01_00404A10();
extern void func_003A7AF8();
extern void func_L01_00451DB8(void *, void *, unsigned, unsigned, float);
extern void func_L01_00404808();
extern void func_L01_00424168();
extern void func_L21_003FC9A8();
extern void func_L03_00411778();
extern void func_L03_00411F50();
extern void func_L08_004070C0(s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L08_00406AB0(void *, s32, s32, s32, f32, f32, f32);
extern O_003FD638 *func_L10_00406780(s32);
extern void func_003C4C18(void *, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);

void func_L21_003FD638(void) {
    int i;
    O_003FD638 *o;
    int j;

    func_L01_00423AB8();
    for (i = 0; i < D_L21_001E5A40.n; i++) {
        o = D_L21_001E5A40.list[i];
        if (o != 0 && o->id == 0xE29) o->flags |= 0x800;
        if (o->id == 0xD54) {
            o->b63 = 0;
            for (j = 0; D_L21_002380B0[j] != 0; j++) {
                if (D_L21_002380B0[j]->b63 != 0) D_L21_002380B0[j]->b63 = 1;
            }
            func_003A58C0(o, 0);
            func_L01_00404A10(func_003A7AF8, o);
        }
        if (o != 0) {
            if (o->id == 0xFA0) {
                if (o->p68 != 0)
                    func_L01_00451DB8(o, (void *)(o->p68 + 12), 0x80AAAAD2, 0x80396464, 0.0733038336f);
            } else if (o->id == 0x1DEE || o->id == 0x19BC) {
                func_L01_00451DB8(o, D_L21_001D6AE0, 0x80505080, 0x80404038, 0.0383972451f);
            } else if (o->id == 0x1977) {
                func_L01_00451DB8(o, &D_L21_001D6AE4, 0x8080AAAA, 0x80464646, 0.0453785658f);
            } else if (o->id == 0x1766) {
                func_L01_00451DB8(o, &D_L21_001D6AE8, 0x80AAAAFF, 0x80646496, 0.132645041f);
            } else if (o->id == 0x195B || o->id == 0x1B58 || o->id == 0x195C || o->id == 0x175A) {
                func_L01_00404808(func_L01_00424168, o);
            }
        }
    }
    if (D_001D545C == 0x15) {
        G_003FD638 *g = &D_L21_001E5A40;
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
            p.ac = 0.008f;
            if (g->v34 == 0x7C7) {
                vu0_v4 u;
                *(vu0_q *)&u = 0;
                u.z = 1.0f;
                func_L08_004070C0(0, &u, 0xF, 5, 0x3C, 0x1E, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
            if ((u32)(g->v34 - 0x183) < 0x379) {
                func_L01_00404808(func_L21_003FC9A8, 0);
            }
            {
                s32 n = abs_asm(g->v34 - 0x43B);
                if (n < 5) {
                    f32 r = (f32)n * 0.25f;
                    if (1.0f < r) {
                        r = 1.0f;
                    } else if (r < 0.0f) {
                        r = 0.0f;
                    }
                    D_L21_001DE6D8 = 1.0f - r;
                    s = func_L10_00406780(0x1F32);
                    if (s != 0) {
                        int k;
                        p.bc = 200;
                        for (k = 0; k < p.bc; k++) {
                            qzero(&w);
                            func_003C4C18(&w, p.ac * 0.5f);
                            *(vu0_q *)&q = s->pos;
                            qq = &q;
                            func_003C4C18(qq, 2.0f);
                            func_L01_0046C470(qq, &w, p.b4, func_003824E0(p.a8, p.a4),
                                              (s32)func_003824E0((f32)p.a2, (f32)p.a0), func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
                        }
                    }
                }
            }
            {
            G_003FD638 *h = &D_L21_001E5A40;
            if (h->v34 == 0x43E) {
                int a;
                int b;
                int nx;
                O_003FD638 *e = h->l1B0;
                func_L08_00406AB0(e, p.b4, p.b4, 10, 4.0f, 8.0f, 3.0f);
                for (a = 0; a < 5; a = nx) {
                    nx = a + 1;
                    for (b = 9; b >= 0; b--) {
                        func_003C2F58(e, a, &q);
                        func_003C4C18(&q, 0.05f);
                        qzero(&w);
                        func_003C4C18(&w, p.ac * 0.1f);
                        w.z = w.z + p.ac * 0.2f;
                        func_L01_0046C470(&q, &w, p.b4, func_003824E0(p.a8, p.a4) * 3.0f,
                                          (s32)func_003824E0((f32)p.a2, (f32)p.a0) * 2, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
                    }
                }
            }
            }
            {
            G_003FD638 *h = &D_L21_001E5A40;
            if ((u32)(h->v34 - 0x383) < 0x6D && func_00382468(0x514) > 0x514 - h->v34) {
                s = func_L10_00406780(0x1BD2);
                if (s != 0 && func_00382468(2) == 0) {
                    int k;
                    p.bc = h->v34 >> 7;
                    for (k = 0; k < p.bc; k++) {
                        qzero(&w);
                        func_003C4C18(&w, p.ac);
                        *(vu0_q *)&q = s->pos;
                        vec_add_ba(&q, &q, &c);
                        func_0038CE20(&t, &w, 60.0f);
                        vec_add_ab(&q, &q, &t);
                        func_0038CE20(&w, &w, -1.0f);
                        func_L01_0046C470(&q, &w, p.b4, func_003824E0(p.a8, p.a4),
                                          (s32)func_003824E0((f32)p.a2, (f32)p.a0), func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
                    }
                }
            }
            }
            func_L03_00411778(0x74C, 0x8CE);
        } else if (g->v30 == 1) {
            if (g->v34 == 0x3D) {
                *(vu0_q *)&q = 0;
                q.z = 1.0f;
                func_L08_004070C0(0, &q, 0xF, 5, 0x64, 0x32, 0x20208000, 0x20408020, 0x50408020, 1.0f, 1.0f);
            }
        } else if (g->v30 == 2) {
            func_L03_00411778(0xF8, 0x184);
            if (g->v34 >= 0) {
                O_003FD638 *s = g->l1B0;
                if (s != 0) {
                    func_L03_00411F50(s, 0);
                    func_L03_00411F50(s, 1);
                }
            }
        }
    }
}
/* localdecomp:end func_L21_003FD638 */
