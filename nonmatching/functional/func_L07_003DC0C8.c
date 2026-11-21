/* functional: high. Rewritten for PAL from the NTSC-U twin draft, re-read line by line against the PAL asm: PAL divides the age by 17.0 and clamps the damping below 17 (NTSC-U: 20), takes the rope parameters from func_L07_003DC598 (dst, a, b, t) and uses PAL callees; control flow, vectors and loops follow the asm. Bytes may differ in VU scheduling. */
#include "common.h"
#include "vu0.h"

typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
    u8 pad[8];
} Rope_003DC0C8;

typedef struct {
    vu0_v4 link[8];
    vu0_v4 prev[8];
    vu0_v4 v100;
    s32 w110;
    s32 w114;
    s32 w118;
    u8 pad11C[12];
    f32 f128;
} Priv_003DC0C8;

extern void func_L07_003DC598(void *, void *, void *, f32);
extern void func_L07_003DC4C8(void *, void *, s32, s32, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003DC0C8(void *obj_) {
    u8 *obj = obj_;
    Rope_003DC0C8 prm;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    Priv_003DC0C8 *p;
    f32 d;
    f32 t;
    s32 i, j, k, m, jn;
    vu0_v4 *pl, *pp, *pa, *pb, *pq;
    u8 *anchor;

    p = *(Priv_003DC0C8 **)(obj + 0x68);
    func_L07_003DC598(&prm, (void *)p->w110, (void *)p->w114, (f32)*(u16 *)(obj + 0x96) / 17.0f);
    if (*(u16 *)(obj + 0x96) < 0x11) {
        prm.f08 = 1.0f;
    }
    *(vu0_q *)&v30 = 0;
    v30.z = prm.f04;
    anchor = (u8 *)p + 0x100;
    v20 = v30;
    func_L01_0044FD88(*(void **)(obj + 0xB8), obj_, p->w118, 0);
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) & 0xFFFD;
    *(vu0_q *)&p->link[0] = *(vu0_q *)(obj + 0x10);
    *(vu0_q *)&p->prev[0] = *(vu0_q *)(obj + 0x10);
    func_0038CF68(&v30, obj + 0xC0, prm.f00);
    for (i = 1; i < prm.b15; i++) {
        vec_add_ab(&p->link[i], &p->link[i - 1], &v30);
        *(vu0_q *)&p->prev[i] = *(vu0_q *)&p->link[i];
    }
    pl = &p->link[prm.b15];
    pp = &p->prev[prm.b15];
    for (j = prm.b15; j < 8; j++) {
        *(vu0_q *)&v40 = *(vu0_q *)pl;
        vec_sub_ba(&v50, pl, pp);
        func_0038CE20(&v50, &v50, prm.f08);
        vec_add_ab(pl, pl, &v50);
        vec_add_ab(pl, pl, &v20);
        *(vu0_q *)pp = *(vu0_q *)&v40;
        pl++;
        pp++;
    }
    for (k = 0; k < prm.b14; k++) {
        pa = &p->link[0];
        for (j = 0; j < 7; j = jn) {
            jn = j + 1;
            pb = pa + 1;
            for (m = 1, pq = pb; m <= prm.b17 && j + m < 8; m++, pq++) {
                func_L07_003DC4C8(pa, pq, j >= prm.b15, j + m >= prm.b15, ((f32)m * prm.f00) * ((f32)m * prm.f00));
            }
            pa = pb;
        }
    }
    func_0038D000(&v40, anchor, *(u8 **)(obj + 0xB8) + 0xC0);
    vec_add_ab(&v40, &v40, *(u8 **)(obj + 0xB8) + 0x10);
    pl = &p->link[0];
    for (j = 0; j < 8; j++, pl++) {
        if (pl->z < prm.f0C + p->f128) {
            pl->z = prm.f0C + p->f128;
        }
        if (j < prm.b16) {
            continue;
        }
        vec_sub_ab(&v50, &v40, pl);
        d = prm.f10 * prm.f10;
        t = d / (func_L01_0040E4C0(&v50) + d) - 0.5f;
        if (t > 0.0f) {
            func_0038CE20(&v60, &v50, t + t);
            vec_sub_ab(pl, pl, &v60);
        }
        if (pl->z < v40.z) {
            v50.z = 0.0f;
            t = d / (func_L01_0040E4C0(&v50) + d) - 0.5f;
            if (t > 0.0f) {
                func_0038CE20(&v60, &v50, t + t);
                vec_sub_ab(pl, pl, &v60);
            }
        }
    }
}
