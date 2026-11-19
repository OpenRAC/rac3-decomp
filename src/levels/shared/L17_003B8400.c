#include "common.h"

/* localdecomp:start func_L17_003B8400 */
#include "vu0.h"

extern void func_0038D308(void *, void *);
extern f32 func_0038CEA8(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00404A10(void *, void *);
extern s32 func_L01_00424B88(void *, s32, f32, f32);
extern void func_L17_003B8658(u8 *);
extern void func_L17_003B8748(u8 *);
extern void func_L17_003B8B18(u8 *);
extern s32 D_001D545C;
extern f32 D_L17_001DE5C4;
__asm__(".extern D_L17_001DE5C4, 4");
extern s32 D_L17_001DE560;
__asm__(".extern D_L17_001DE560, 4");
extern s32 D_L17_001DE5A8;
__asm__(".extern D_L17_001DE5A8, 4");
extern s32 D_L17_001DE5A4;
__asm__(".extern D_L17_001DE5A4, 4");
typedef int Q_003B8400 __attribute__((mode(TI)));
static __inline__ void qcopy_003B8400(void *d, void *s) { *(Q_003B8400 *)d = *(Q_003B8400 *)s; }
extern u8 D_L17_002A3270[];

void func_L17_003B8400(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *t;
    s32 i;
    vu0_v4 v;
    vu0_v4 w;

    func_0038D308(a0 + 0xC0, a0 + 0xF0);
    *(vu0_v4 *)(st + 0x10) = *(vu0_v4 *)st = *(vu0_v4 *)(a0 + 0x10);
    t = *(u8 **)(a0 + 0xB8);
    if (t != 0 && *(s16 *)(t + 0xAA) == 0x1AF1) {
        vec_sub_ba(&v, *(u8 **)(t + 0x68) + 0xD50, t + 0x10);
        D_L17_001DE5C4 = func_0038CEA8(&v) / 15.0f;
    }
    *(f32 *)(st + 0x20) += (6.0f - *(f32 *)(st + 0x20)) * 0.084000006f + 12.0f;
    v.x = 0.0f;
    v.y = *(f32 *)(st + 0x20);
    v.z = 0.0f;
    vec_add_ab(st + 0x10, st, &v);
    v = *(vu0_v4 *)(st + 0x10);
    if (*(u8 **)(a0 + 0xB8) != 0 && *(s16 *)(*(u8 **)(a0 + 0xB8) + 0xAA) == 0x1AF1) {
        D_L17_001DE560 = func_00382498(0xD, 0x14);
        D_L17_001DE5A8 = 0x800030;
        D_L17_001DE5A4 = 0x7F007F;
    } else {
        switch (D_001D545C) {
        default:
            D_L17_001DE560 = func_00382468(20);
            break;
        case 4:
            D_L17_001DE560 = 20;
            break;
        case 11:
            D_L17_001DE560 = 20;
            break;
        }
    }
    func_L17_003B8658(a0);
    func_L17_003B8748(a0);
    for (i = D_L17_001DE560 - 4; i < D_L17_001DE560; i++) {
        func_0038CF68(&w, a0 + 0xC0, D_L17_001DE5C4 * (f32)i);
        vec_add_ab(&w, &w, a0 + 0x10);
        qcopy_003B8400(D_L17_002A3270 + *(s32 *)(st + 0x38) * 0x280 + i * 16, &w);
    }
    func_L01_00404A10(func_L17_003B8B18, a0);
    if (a0[0x20] == 0) {
        *(s32 *)(st + 0x24) = func_L01_00424B88(st, 0, 0.0f, 0.0f);
        a0[0x20] = 1;
        *(s32 *)(st + 0x2C) = D_L17_001DE560;
        *(s32 *)(st + 0x30) = -1;
    }
}
/* localdecomp:end func_L17_003B8400 */

/* localdecomp:start func_L17_003B8658 */
#include "vu0.h"
extern s32 D_L17_001DE560;
__asm__(".extern D_L17_001DE560, 4");
extern s32 D_L17_001DE564;
__asm__(".extern D_L17_001DE564, 4");
extern f32 D_L17_001DE568;
__asm__(".extern D_L17_001DE568, 4");
extern s32 D_L17_001DE56C;
__asm__(".extern D_L17_001DE56C, 4");
extern s32 D_L17_001DE570;
__asm__(".extern D_L17_001DE570, 4");
extern s32 D_L17_001DE580;
__asm__(".extern D_L17_001DE580, 4");
extern u8 D_L17_002A3270[];
extern void func_0038CF68(void *, void *, f32);

void func_L17_003B8658(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 step;
    s32 i;
    u32 a;

    if (D_L17_001DE564 != 0) {
        D_L17_001DE564 = 0;
        vec_sub_ab(&d, s + 0x10, s);
        func_0038CF68(&step, &d, D_L17_001DE568 / (f32)D_L17_001DE560);
        a = *(s32 *)(s + 0x38) * 640;
        a += (u32)D_L17_002A3270;
        *(vu0_q *)a = *(vu0_q *)s;
        for (i = 1; i < D_L17_001DE560; i++) {
            vec_add_ba(&((vu0_v4 *)(D_L17_002A3270 + *(s32 *)(s + 0x38) * 640))[i],
                       &((vu0_v4 *)(D_L17_002A3270 + *(s32 *)(s + 0x38) * 640))[i - 1], &step);
        }
        D_L17_001DE56C = 0;
        D_L17_001DE570 = 0;
        D_L17_001DE580 = 0;
    }
}
/* localdecomp:end func_L17_003B8658 */

/* localdecomp:start func_L17_003B8748 */
#include "vu0.h"
extern f32 func_00382538(void);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_L01_0044AE78(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern u8 D_001D66B0;
extern f32 D_L17_001DE574;
__asm__(".extern D_L17_001DE574, 4");
extern f32 D_L17_001DE578;
__asm__(".extern D_L17_001DE578, 4");
extern f32 D_L17_001DE57C;
__asm__(".extern D_L17_001DE57C, 4");
extern f32 D_L17_001DE584;
__asm__(".extern D_L17_001DE584, 4");
extern f32 D_L17_001DE588;
__asm__(".extern D_L17_001DE588, 4");
extern f32 D_L17_001DE594;
__asm__(".extern D_L17_001DE594, 4");
extern f32 D_L17_001DE598;
__asm__(".extern D_L17_001DE598, 4");
__asm__(".extern D_L17_001DE560, 4");
__asm__(".extern D_L17_001DE568, 4");
__asm__(".extern D_L17_001DE56C, 4");
__asm__(".extern D_L17_001DE570, 4");
__asm__(".extern D_L17_001DE580, 4");
__asm__(".extern D_L17_001DE5C4, 4");
typedef struct { vu0_v4 v; u8 p10[8]; u8 b18; u8 b19; u16 h1A; u8 p1C[0x14]; } H_003B8748;
typedef struct { vu0_v4 a[20]; vu0_v4 b[20]; } R_003B8748;
extern R_003B8748 D_L17_002A3270_003B8748[];
static __inline__ void qcopy_003B8748(void *d, void *s) { *(vu0_q *)d = *(vu0_q *)s; }

void func_L17_003B8748(u8 *a0) {
    u8 *st;
    vu0_v4 zero;
    vu0_v4 dir;
    vu0_v4 seg;
    vu0_v4 step;
    vu0_v4 off;
    vu0_v4 pos;
    H_003B8748 hit;
    f32 k;
    s32 i;
    f32 fi;
    f32 dz, dx, dy;
    f32 phase, amp, ang, rad;

    k = D_L17_001DE568 / (f32)D_L17_001DE560;
    st = *(u8 **)(a0 + 0x68);
    *(f32 *)&D_L17_001DE56C = func_00382538();
    *(f32 *)&D_L17_001DE570 = func_00382538();
    *(f32 *)&D_L17_001DE580 = func_0038DAB8(*(f32 *)&D_L17_001DE580, D_L17_001DE584);
    qzero(&zero);
    *(s32 *)(st + 0x2C) = D_L17_001DE560;
    vec_sub_ba(&dir, st + 0x10, st);
    func_0038CF68(&dir, &dir, 1.0f);
    func_0038CE20(&step, &dir, k);
    qcopy_003B8748(&D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[0], a0 + 0x10);
    qcopy_003B8748(&D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].b[0], a0 + 0x10);
    for (i = 1; i < D_L17_001DE560; i++) {
        fi = (f32)i;
        func_0038CF68(&pos, a0 + 0xC0, D_L17_001DE5C4 * fi);
        vec_add_ab(&pos, &pos, a0 + 0x10);
        dz = func_L01_00443A18(D_L17_001DE594, D_L17_001DE598);
        dx = func_L01_00443A18(D_L17_001DE594, D_L17_001DE598);
        dy = func_L01_00443A18(D_L17_001DE594, D_L17_001DE598);
        qcopy_003B8748(&D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[i], &pos);
        D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[i].z += dz;
        D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[i].x += dx;
        D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[i].y += dy;
        vec_sub_ba(&seg, &D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[i],
                   &D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[i - 1]);
        phase = func_L01_0044AE78(*(f32 *)&D_L17_001DE570 + fi * D_L17_001DE574);
        amp = D_L17_001DE578 * func_0038D0B0(func_L01_0044AE78(*(f32 *)&D_L17_001DE580 + fi * D_L17_001DE588));
        qcopy_003B8748(&D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].b[i],
                       &D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].a[i]);
        dz = amp * func_0038D0B0(phase) + func_L01_00443A18(0.0f, 0.1f);
        D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].b[i].z += dz;
        ang = func_0038DAB8(func_0038D160(seg.x, seg.y), 1.5707964f);
        rad = D_L17_001DE57C * func_0038D098(phase);
        off.x = func_0038D098(ang) * rad;
        off.y = func_0038D0B0(ang) * rad;
        off.z = 0.0f;
        vec_add_ba(&D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].b[i],
                   &D_L17_002A3270_003B8748[*(s32 *)(st + 0x38)].b[i], &off);
        if (i >= 2 && (i == D_L17_001DE560 - 1 || (i & 1) == 0)) {
            func_L01_00446760(&hit, a0, 1, &D_001D66B0, 10.0f);
            hit.h1A = *(u16 *)(a0 + 0xAA);
        }
    }
}
/* localdecomp:end func_L17_003B8748 */
