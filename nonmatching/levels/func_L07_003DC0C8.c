/* NTSC-U draft (Claude wave C4): C of func_L07_003DA448, the NTSC-U twin of func_L07_003DC0C8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 56 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L07_003DA448", whose code is not the PAL one).
 * Worker's note: flags: needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (vec helpers + lui/ori float constants; the PAL file has neither); 56 aligned diff words of 255 (116 at the first draft); levers: struct return func_L07_003DA918 (Rope params ...
 */
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
} Rope_003DA448;

typedef struct {
    vu0_v4 link[8];
    vu0_v4 prev[8];
    vu0_v4 v100;
    s32 w110;
    s32 w114;
    s32 w118;
    u8 pad11C[12];
    f32 f128;
} Priv_003DA448;

/* localdecomp:start func_L07_003DA448 */
extern Rope_003DA448 func_L07_003DA918(f32, s32, s32);
extern void func_L01_0044CB08(void *, void *, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L07_003DA848(void *, void *, s32, s32, f32);
extern void func_003888C8(void *, void *, void *);
extern f32 func_L01_0040BF90(void *);

void func_L07_003DA448(u8 *obj) {
    Rope_003DA448 prm;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    Priv_003DA448 *p;
    f32 d;
    f32 t;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 jn;
    vu0_v4 *pl;
    vu0_v4 *pp;
    vu0_v4 *pa;
    vu0_v4 *pb;
    vu0_v4 *pq;
    u8 *anchor;
    vu0_v4 *pv40;

    p = *(Priv_003DA448 **)(obj + 0x68);
    prm = func_L07_003DA918((f32)*(u16 *)(obj + 0x96) / 20.0f, p->w110, p->w114);
    if (*(u16 *)(obj + 0x96) < 0x14) {
        prm.f08 = 1.0f;
    }
    *(vu0_q *)&v30 = 0;
    v30.z = prm.f04;
    anchor = (u8 *)p + 0x100;
    v20 = v30;
    func_L01_0044CB08(*(u8 **)(obj + 0xB8), obj, p->w118, 0);
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) & 0xFFFD;
    *(vu0_q *)&p->link[0] = *(vu0_q *)(obj + 0x10);
    *(vu0_q *)&p->prev[0] = *(vu0_q *)(obj + 0x10);
    func_00388830(&v30, obj + 0xC0, prm.f00);
    pv40 = &v40;
    for (i = 1; i < prm.b15; i++) {
        vec_add_ab(&p->link[i], &p->link[i - 1], &v30);
        *(vu0_q *)&p->prev[i] = *(vu0_q *)&p->link[i];
    }
    pl = &p->link[prm.b15];
    pp = &p->prev[prm.b15];
    for (j = prm.b15; j < 8; j++) {
        *(vu0_q *)&v40 = *(vu0_q *)pl;
        vec_sub_ba(&v50, pl, pp);
        func_003886E8(&v50, &v50, prm.f08);
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
                func_L07_003DA848(pa, pq, j >= prm.b15, j + m >= prm.b15, ((f32)m * prm.f00) * ((f32)m * prm.f00));
            }
            pa = pb;
        }
    }
    func_003888C8(pv40, anchor, *(u8 **)(obj + 0xB8) + 0xC0);
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
        t = d / (func_L01_0040BF90(&v50) + d) - 0.5f;
        if (t > 0.0f) {
            func_003886E8(&v60, &v50, t + t);
            vec_sub_ab(pl, pl, &v60);
        }
        if (pl->z < v40.z) {
            v50.z = 0.0f;
            t = d / (func_L01_0040BF90(&v50) + d) - 0.5f;
            if (t > 0.0f) {
                func_003886E8(&v60, &v50, t + t);
                vec_sub_ab(pl, pl, &v60);
            }
        }
    }
}
/* localdecomp:end func_L07_003DA448 */
