/* func_L17_003C6DA0 (Claude wave 14 r72, 2026-11-28). First draft kept here. */
/* PAL near miss (wave 14 r72, 2026-11-28): func_L17_003C6DA0 (2580 B, level 17 only), the path camera's update,
 * the per-frame partner of func_L17_003C6910 (same E/R/P/T records): mode 0 follows the hero's path position,
 * mode 2 maps the hero's path index onto a second path (wrap-aware segment search, distance sum, speed ramp),
 * other modes project the hero onto the path (func_L01_00476B98), then the look-at target, the pitch ramp
 * (func_00382C58) and the basis rebuild (cross products, func_0038D890). First draft, fresh entry, written from the
 * retail assembly: 630 diff with the file's line and the divs row `func_L17_003C6DA0 2 2 0` (two nops before the
 * first two div.s, none before the last; check with --divs 2,2,0). The control flow, the calls and their
 * arguments follow retail; most of the count is positional: this C keeps one more float in a saved register
 * ($f26, frame 0x150 against 0x140) and allocates self/g one register later ($s4/$s5 against $s3/$s4), which shifts
 * every slot and register after the prologue. */
#include "common.h"

/* localdecomp:start func_L17_003C6DA0 */
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
extern u8 D_L17_001E19E0[];
extern void func_L01_00476498(void *, void *, s32 *, f32 *, s32, f32);
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);

void func_L17_003C6DA0(u8 *self) {
    vu0_v4 out;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    s32 i70;
    f32 t74;
    s32 i78;
    f32 t7C;
    s32 i80;
    f32 t84;
    s32 i88;
    f32 t8C;
    u8 *g;
    u8 *h;
    u8 *g30;
    u8 *g80;
    u8 *g150;
    E_3C6910 *e;
    P_3C6910 *hp;
    P_3C6910 *a;
    P_3C6910 *b;
    P_3C6910 *c;
    P_3C6910 *d;
    P_3C6910 *pa;
    s32 hidx;
    f32 ht;
    f32 sp24;
    f32 s;
    f32 r;
    f32 x;
    f32 ang;
    f32 f;
    s32 i, k, cur, prev, j, start, n, m;
    f32 sum;

    g = *(u8 **)(self + 0x70);
    e = D_L17_001DE884[*(s16 *)(self + 0x84)].f1C;
    g30 = g + 0x30;
    g80 = g + 0x80;
    g150 = g + 0x150;
    s = 0.01f;
    sp24 = *(f32 *)e;
    if (e->b3C) {
        h = D_001A4BE0;
        hp = *(P_3C6910 **)(h + 0x690);
        ht = *(f32 *)(h + 0x698);
        hidx = *(s32 *)(h + 0x694);
    } else {
        h = D_001A4BE0;
        hp = *(P_3C6910 **)(h + 0x5D0);
        ht = *(f32 *)(h + 0x5D8);
        hidx = *(s32 *)(h + 0x5D4);
    }
    if (e->mode == 0) {
        i78 = hidx;
        t7C = ht;
        *(f32 *)(g150 + 4) = ht;
        *(s32 *)(g150 + 0) = hidx;
        func_L01_00476498(D_L17_0021CD80[e->path], &out, (s32 *)g150, (f32 *)(g150 + 4), 0, 1.0f);
        *(vu0_q *)g80 = *(vu0_q *)&out;
        pa = D_L17_0021CD80[e->path];
        f = t7C / hp->pts[i78].w;
        vec_sub_ba(&v50, &pa->pts[i78 + 1], &pa->pts[i78]);
        func_0038CF68(&v40, &v50, pa->pts[i78].w * f);
        vec_add_ba(&v60, &pa->pts[i78], &v40);
        *(f32 *)(self + 0x30) = func_00382BC8((f32 *)(g + 0), *(f32 *)(self + 0x30), v60.x, 0.01f, 0.175f, 0.0f);
        *(f32 *)(self + 0x34) = func_00382BC8((f32 *)(g + 4), *(f32 *)(self + 0x34), v60.y, 0.01f, 0.175f, 0.0f);
        *(f32 *)(self + 0x38) = func_00382BC8((f32 *)(g + 8), *(f32 *)(self + 0x38), v60.z, 0.01f, 0.175f, 0.0f);
    } else if (e->mode == 2) {
        b = D_L17_0021CD80[e->path];
        d = D_L17_001DED10[e->f24].f10;
        a = D_L17_0021CD80[e->f28];
        c = D_L17_0021CD80[e->f2C];
        for (i = 0, k = c->count - 1; i < c->count; k = i, i++) {
            cur = (s32)c->pts[i].w;
            prev = (s32)c->pts[k].w;
            if (cur < prev) {
                if (hidx >= prev || hidx < cur) {
                    break;
                }
            } else if (hidx >= prev && hidx < cur) {
                break;
            }
        }
        *(s32 *)(g150 + 0x10) = i;
        sum = 0.0f;
        j = (i + c->count - 1) % c->count;
        if (c->pts[j].x != sum) {
            sp24 = c->pts[j].x;
        }
        start = (s32)c->pts[j].w;
        n = hidx - start;
        if (n < 0) {
            n += d->count;
        }
        for (m = 0; m < n; m++) {
            sum += d->pts[(start + m) % d->count].w;
        }
        i70 = (s32)a->pts[j].w;
        t74 = 0.0f;
        func_L01_00476498(b, &v40, &i70, &t74, 1, a->pts[i].y * ((sum + ht) / c->pts[i].y));
        x = a->pts[j].x;
        if (x > 0.0f) {
            s = s * x;
            r = x * 0.01f;
        } else {
            r = 0.01f;
        }
        if (fabs_asm(*(f32 *)(g + 0x10) - r) < 0.00015f) {
            *(f32 *)(g + 0x10) = r;
        } else if (*(f32 *)(g + 0x10) < r) {
            *(f32 *)(g + 0x10) = *(f32 *)(g + 0x10) + 0.00015f;
        } else {
            *(f32 *)(g + 0x10) = *(f32 *)(g + 0x10) - 0.00015f;
        }
        *(f32 *)(self + 0x30) = func_00382BC8((f32 *)(g + 0), *(f32 *)(self + 0x30), v40.x, *(f32 *)(g + 0x10), 0.175f, 0.0f);
        *(f32 *)(self + 0x34) = func_00382BC8((f32 *)(g + 4), *(f32 *)(self + 0x34), v40.y, *(f32 *)(g + 0x10), 0.175f, 0.0f);
        *(f32 *)(self + 0x38) = func_00382BC8((f32 *)(g + 8), *(f32 *)(self + 0x38), v40.z, *(f32 *)(g + 0x10), 0.175f, 0.0f);
    } else {
        pa = D_L17_0021CD80[e->path];
        if (e->f24 < 0) {
            func_L01_00476B98(pa, D_001A4BE0 + 0x80, &v30, &i78, &t7C, 0, 20.0f, 1.0f, 0.0f);
            if (*(s16 *)((u8 *)e + 0x36) == 1) {
                f = -(*(f32 *)((u8 *)e + 0x38) * 4.0f);
            } else {
                f = *(f32 *)((u8 *)e + 0x38);
            }
            func_L01_00476498(pa, &v30, &i78, &t7C, 1, f);
            out = v30;
        } else {
            i80 = hidx;
            t84 = ht;
            func_L01_00476498(hp, &v30, &i80, &t84, 1, *(f32 *)((u8 *)e + 0x38));
            func_L01_00476B98(pa, &v30, &out, &i78, &t7C, 0, 20.0f, 1.0f, 0.0f);
        }
        *(f32 *)(self + 0x30) = func_00382BC8((f32 *)(g + 0), *(f32 *)(self + 0x30), out.x, 0.01f, 0.175f, 0.0f);
        *(f32 *)(self + 0x34) = func_00382BC8((f32 *)(g + 4), *(f32 *)(self + 0x34), out.y, 0.01f, 0.175f, 0.0f);
        *(f32 *)(self + 0x38) = func_00382BC8((f32 *)(g + 8), *(f32 *)(self + 0x38), out.z, 0.01f, 0.175f, 0.0f);
    }
    if (e->f24 < 0) {
        pa = D_L17_0021CD80[e->path];
        func_L01_00476B98(pa, D_001A4BE0 + 0x80, &v40, &i78, &t7C, 0, 20.0f, 1.0f, 0.0f);
        if (D_001D545C == 14 && e->mode == 0) {
            func_L01_00476498(pa, &v50, &i78, &t7C, 0, sp24);
        } else {
            func_L01_00476498(pa, &v50, &i78, &t7C, 1, sp24);
        }
        vec_sub_ba(&v50, &v50, &v40);
        vec_add_ab(&v40, D_001A4BE0 + 0x80, &v50);
    } else {
        i88 = hidx;
        t8C = ht;
        func_L01_00476498(hp, &v40, &i88, &t8C, 1, sp24);
    }
    func_0038CF68(&v10, D_L17_001E19E0 + *(s32 *)(self + 0x94) * 0x460 + 0x20, *(f32 *)(g80 + 0x4C));
    vec_add_ba(&v30, &v10, &v40);
    vec_sub_ba(&v20, &v30, self + 0x30);
    f = func_0038CEA8(&v20);
    ang = 0.0f;
    if (f != ang) {
        func_0038CE20(&v20, &v20, 1.0f / f);
        ang = 1.5707964f - func_0038D0C8(func_0038CE68(&v20, self));
    }
    if (fabs_asm(*(f32 *)(g30 + 0x20) - s) < 0.00015f) {
        *(f32 *)(g30 + 0x20) = s;
    } else if (*(f32 *)(g30 + 0x20) < s) {
        *(f32 *)(g30 + 0x20) = *(f32 *)(g30 + 0x20) + 0.00015f;
    } else {
        *(f32 *)(g30 + 0x20) = *(f32 *)(g30 + 0x20) - 0.00015f;
    }
    f = func_00382C58(g30 + 0x34, 0.0f, ang, *(f32 *)(g30 + 0x20), 0.175f, 0.0f);
    func_0038CE90(&v50, &v20, self + 0x40);
    func_0038D890(self, self + 0x40, &v50, f);
    func_0038CF68(self + 0x40, self, 1.0f);
    func_0038CF68(self, self, 1.0f);
    func_0038CE90(self + 0x10, self, D_L17_001E19E0 + *(s32 *)(self + 0x94) * 0x460 + 0x20);
    func_0038CF68(self + 0x10, self + 0x10, 1.0f);
    func_0038CE90(self + 0x20, self + 0x10, self);
}
/* localdecomp:end func_L17_003C6DA0 */
