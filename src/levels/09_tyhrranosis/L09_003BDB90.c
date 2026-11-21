#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BD360.c, which this file was cut from */
extern u8 *D_L09_0021E640[];

/* localdecomp:start func_L09_003BDB90 */
typedef struct {
    s8 b[8];
} S_003BDB90;

typedef struct {
    s8 n0[4];
    u8 f0[4];
    s8 n1[4];
    u8 f1[4];
} H_003BDB90;

typedef struct {
    s32 n;
    s32 pad[3];
    vu0_v4 p[1];
} P_003BDB90;

extern u8 D_001A4C60[];
__asm__(".extern D_001A4C60, 16");
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L09_003BC7F0(u8 *, S_003BDB90 *, S_003BDB90 *, s32 *, s32, H_003BDB90 *, s32 *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);

void func_L09_003BDB90(u8 *obj, s32 *a1, s32 a2, H_003BDB90 *a3) {
    S_003BDB90 b0;
    S_003BDB90 b1[10];
    vu0_v4 v;
    s32 cnt;
    u8 *p = *(u8 **)(obj + 0x68);
    P_003BDB90 *t;
    s32 h;

    cnt = 0;
    func_L09_003BC7F0(obj, &b0, b1, a1, a2, a3, &cnt, D_001A4C60);
    t = (P_003BDB90 *)D_L09_0021E640[a1[b0.b[0]]];
    h = *(s16 *)(p + 0x25A);
    if ((h == 0 || h == t->n - 1) &&
        func_0038CF38(obj + 0x10, &t->p[h]) <= *(f32 *)(p + 0x1C4)) {
        s8 *nb;
        u8 *fb;
        s32 k;
        s32 i;
        s32 j;
        s32 fl;
        s32 n;
        s32 c;
        s8 e;

        vec_sub_ba(&v, &t->p[b1[0].b[3]], obj + 0x10);
        v.z = 0.0f;
        k = func_0038CE68(obj + 0xC0, &v) < 0.0f;
        e = b1[k].b[3];
        j = -1;
        c = b1[k ^ 1].b[3] > e;
        nb = c ? a3[b0.b[0]].n0 : a3[b0.b[0]].n1;
        if (c) {
            fb = a3[b0.b[0]].f0;
        } else {
            fb = a3[b0.b[0]].f1;
        }
        for (i = 0; i < 4; i++) {
            if (nb[i] == b0.b[0]) {
                j = i + 2 > 3 ? i - 2 : i + 2;
                fl = fb[i + 2 > 3 ? i - 2 : i + 2] != 0;
                break;
            }
        }
        n = nb[j];
        if (n == -1) {
            return;
        }
        t = (P_003BDB90 *)D_L09_0021E640[a1[n]];
        func_L01_0045C150(obj, t, fl ? t->n - 1 : 0, fl ? 0 : t->n - 1);
    } else {
        vec_sub_ba(&v, &((P_003BDB90 *)D_L09_0021E640[a1[b0.b[0]]])->p[b1[0].b[3]], obj + 0x10);
        v.z = 0.0f;
        if (func_0038CE68(obj + 0xC0, &v) > 0.0f) {
            P_003BDB90 *q = (P_003BDB90 *)D_L09_0021E640[a1[b0.b[0]]];
            s32 m;
            if (b1[0].b[3] < b1[1].b[3]) {
                m = 0;
            } else {
                m = q->n - 1;
            }
            func_L01_0045C150(obj, q, m, *(s16 *)(p + 0x258));
        } else {
            P_003BDB90 *q = (P_003BDB90 *)D_L09_0021E640[a1[b0.b[0]]];
            s32 m;
            if (b1[1].b[3] < b1[0].b[3]) {
                m = 0;
            } else {
                m = q->n - 1;
            }
            func_L01_0045C150(obj, q, m, *(s16 *)(p + 0x258));
        }
    }
}
/* localdecomp:end func_L09_003BDB90 */

/* localdecomp:start func_L09_003BDED0 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(f32, void *, s32, void *, void *);

void func_L09_003BDED0(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 w[6];
    u8 *s;
    s32 i;
    s32 j;
    f32 ang;

    s = *(u8 **)(a0 + 0x68);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            func_003C2F58(a0, i * 5 + 0x28 + j, &pos);
            ang = func_0038D160(pos.x - *(f32 *)(a0 + 0x10), pos.y - *(f32 *)(a0 + 0x14));
            off.x = func_0038D098(ang) * 3.0f;
            ang = func_0038D160(pos.x - *(f32 *)(a0 + 0x10), pos.y - *(f32 *)(a0 + 0x14));
            off.y = func_0038D0B0(ang) * 3.0f;
            off.z = 0.5f;
            off.w = 5627.9248f;
            func_L01_00446760(w, a0, 0x10001, &off, (f32)s[0x44]);
            func_003D4D00(1.5f - (f32)j * 0.2f, &pos, 0, a0, w);
        }
    }
    pos = *(vu0_v4 *)(a0 + 0x10);
    off.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 1.3f;
    off.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 1.3f;
    off.z = 1.5f;
    vec_add_ab(&pos, &pos, &off);
    w[0].x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 3.0f;
    w[0].y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 3.0f;
    w[0].z = 0.5f;
    w[0].w = 5627.9248f;
    func_L01_00446760(&w[3], a0, 0x10001, w, (f32)s[0x44]);
    func_003D4D00(3.0f, &pos, 0, a0, &w[3]);
}
/* localdecomp:end func_L09_003BDED0 */

/* localdecomp:start func_L09_003BE168 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_00446748(void *, void *, s32, f32);
extern s32 func_003D4D00(f32, void *, s32, void *, void *);

void func_L09_003BE168(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 loc[3];
    u8 *s;

    pos = *(vu0_v4 *)(a0 + 0x10);
    s = *(u8 **)(a0 + 0x68);
    off.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 2.0f;
    off.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 2.0f;
    off.z = 1.5f;
    vec_add_ab(&pos, &pos, &off);
    func_L01_00446748(loc, a0, 0x10001, (f32)s[0x44]);
    func_003D4D00(3.0f, &pos, 0, a0, loc);
}
/* localdecomp:end func_L09_003BE168 */
