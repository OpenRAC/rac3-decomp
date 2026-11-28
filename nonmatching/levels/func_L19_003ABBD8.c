/* func_L19_003ABBD8 (Claude wave 14 r52, 2026-11-28). First draft kept here. */
/* func_L19_003ABBD8 (r52, wave 14): first PAL draft, written from retail on the functional C's structure; 651 diff at
 * level 19 (p10/check.py, file flags; positional count, the function is 709 words). From retail: part 1 fills the packet
 * pa (texture 0x16, uv) before the three sprites (it is not dead: pa is read later); the abs of 20 - t % 40 and 10 - t % 20
 * is abs_asm (blezl/neg); the three vector adds are VU0 blocks (the file's line has no -mvu0-use-vf0-vf2, so one block
 * each with vf1/vf2 clobbered); part 3's velocity/acceleration/position are pb's rows 0-2 (retail's 0xF0/0x100/0x110
 * overlap the part-2 packet); the zeroed vectors are qzero; (q * 25) / 4 is a signed divide. Still differs: the frame
 * (0x230 here, 0x240 retail: retail keeps 0.2f and 1.0f of the second ribbon loop in f30/f31), obj is spilled here
 * (retail keeps it in s7 and spills the two part-3 vector addresses), so most registers and the scheduling differ. */
#include "common.h"

/* localdecomp:start func_L19_003ABBD8 */
#include "vu0.h"
typedef int Q_003ABBD8 __attribute__((mode(TI)));
typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    f32 uv[4][2];
    long zero, tex, prim, mode;
} Pkt_003ABBD8;
extern s32 D_L19_001DF240;
extern f32 D_L19_002BDC30[][4];
extern f32 D_L19_001DE568[];
__asm__(".extern D_L19_001DE568, 4");

void func_L19_003ABBD8(u8 *obj) {
    extern long func_00389598(s32);
    extern void func_003C2F58(void *, s32, void *);
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern void func_003D2DA0(void *, void *, s32);
    extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
    u8 *pv = *(u8 **)(obj + 0x68);
    Pkt_003ABBD8 pa;
    vu0_v4 mtx[4];
    vu0_v4 pos;
    Pkt_003ABBD8 pb;
    f32 strength, zero;
    s32 i, t, col;
    long tex;

    if (*(s32 *)(pv + 0x274) != 0) {
        tex = func_00389598(0x16);
        pa.tex = tex;
        pa.prim = 0xFF9000000260L;
        pa.zero = 4;
        pa.mode = 0x8000000048L;
        pa.uv[3][1] = 1.0f;
        pa.uv[0][0] = 0.0f;
        pa.uv[0][1] = 0.0f;
        pa.uv[1][0] = 0.0f;
        pa.uv[1][1] = 1.0f;
        pa.uv[2][0] = 1.0f;
        pa.uv[2][1] = 0.0f;
        pa.uv[3][0] = 1.0f;
        for (i = 3; i < 6; i++) {
            func_003C2F58(obj, i, &mtx[0]);
            t = abs_asm(20 - D_L19_001DF240 % 40);
            func_003D9508(&mtx[0], 6, 0x40000080, 1, (f32)t * 0.02f + 0.1f, 0.08f, 0.0f);
        }
    }
    strength = 1.0f;
    if (obj[0x95] != 2) {
        strength = 1.0f - (f32)*(s32 *)(pv + 0x27C) / 50.333332f;
    }
    if (1.0f < strength) {
        strength = 1.0f;
    } else if (strength < 0.0f) {
        strength = 0.0f;
    }
    zero = 0.0f;
    if (zero < strength) {
        func_003C2EC0(obj, 0, &mtx[1]);
        func_0038CE20(&mtx[0], &mtx[1], 0.7f);
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(pos) : "m"(pos), "m"(mtx[0]) : "vf1", "vf2");
        func_003D9508(&pos, 0xB, func_0038DBD8(0x7F7F7F, 0x7F7F7F7F, strength), 1, 0.5f, zero, zero);
    }
    if (zero < strength) {
        s32 m;
        func_003C2EC0(obj, 0, &mtx[0]);
        func_0038CE20(&pos, &mtx[0], 0.43f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(mtx[3]) : "m"(mtx[3]), "m"(pos) : "vf1", "vf2");
        tex = func_00389598(0x16);
        pb.prim = 0xFF9000000260L;
        pb.zero = 4;
        pb.tex = tex;
        pb.mode = 0x8000000048L;
        pb.v[0].z = -0.25f;
        pb.uv[0][0] = 0.0f;
        pb.uv[0][1] = 0.0f;
        pb.uv[1][0] = 0.0f;
        pb.uv[1][1] = 1.0f;
        pb.uv[2][0] = 1.0f;
        pb.uv[2][1] = 0.0f;
        pb.uv[3][0] = 1.0f;
        pb.uv[3][1] = 1.0f;
        pb.v[0].x = 0.0f;
        pb.v[0].y = 0.0f;
        pb.v[0].w = 1.0f;
        pb.v[2].y = 0.0f;
        pb.v[2].x = *(f32 *)(pv + 0x258) - 1.30395f;
        pb.v[1].x = 0.0f;
        pb.v[3].w = 1.0f;
        pb.v[2].w = 1.0f;
        pb.v[1].w = 1.0f;
        pb.v[2].z = -(*(f32 *)(pv + 0x25C) * 0.5f);
        col = func_0038DBD8(0x508080, 0x30508080, strength);
        pb.col[1] = col;
        pb.col[0] = col;
        pb.col[3] = 0x508080;
        pb.col[2] = 0x508080;
        for (m = 0; m < 16; m++) {
            f32 h, x;
            x = D_L19_001DE568[(m * 3) % 16] * 0.05f + 1.1f;
            h = *(f32 *)(pv + 0x25C) * 0.5f * x;
            pb.v[1].y = D_L19_001DE568[(m + 12) % 16] * 0.25f;
            pb.v[1].z = D_L19_001DE568[m] * 0.25f;
            pb.v[3].x = (*(f32 *)(pv + 0x258) - 1.30395f) * x;
            pb.v[3].z = D_L19_001DE568[m] * h;
            pb.v[3].y = D_L19_001DE568[(m + 12) % 16] * h;
            func_003D2DA0(&pb, &mtx[0], 0);
            *(Q_003ABBD8 *)&pb.v[0] = *(Q_003ABBD8 *)&pb.v[1];
            *(Q_003ABBD8 *)&pb.v[2] = *(Q_003ABBD8 *)&pb.v[3];
        }
        {
            s32 j = 0;
            f32 a, b, c, d, e, f, s, w, *T;
            for (m = 0; m < 8; m++) {
                T = D_L19_002BDC30[m];
                a = func_0038DB48((f32)m * 0.89759785f);
                t = j % 5 + 2;
                j += 17;
                b = func_0038DB48(a + (f32)t * 0.17453292f);
                c = (f32)(m * 2);
                a = c + a;
                b = c + b;
                d = func_0038D0B0(func_0038DB48(a + (f32)((D_L19_001DF240 >> 1) % 60) * 6.0f * 0.017453292f)) * 0.25f + 1.0f;
                e = func_0038D0B0(func_0038DB48(b + (f32)((D_L19_001DF240 >> 1) % 60) * 6.0f * 0.017453292f)) * 0.25f + 1.0f;
                f = func_0038D098(func_0038DB48(a));
                s = func_0038D0B0(func_0038DB48(b));
                w = *(f32 *)(pv + 0x25C) * 0.5f * (f * 0.2f + 0.7f);
                f = (*(f32 *)(pv + 0x258) - 1.30395f) * (s * 0.2f + 0.7f);
                pb.v[0].y = T[0] * 0.25f;
                pb.v[0].z = T[1] * 0.25f;
                pb.v[3].x = f * e;
                pb.v[3].z = T[3] * w * e;
                pb.v[2].z = T[1] * w * d;
                pb.v[2].y = T[0] * w * d;
                pb.v[3].y = T[2] * w * e;
                pb.v[2].x = f * d;
                pb.v[1].y = T[2] * 0.25f;
                pb.v[1].z = T[3] * 0.25f;
                func_003D2DA0(&pb, &mtx[0], 0);
            }
        }
    }
    tex = func_00389598(8);
    pa.prim = 0xFF9000000260L;
    pa.tex = tex;
    pa.zero = 4;
    pa.mode = 0x8000000048L;
    pa.uv[0][0] = 0.0f;
    pa.uv[0][1] = 0.0f;
    pa.uv[1][0] = 0.0f;
    pa.uv[1][1] = 1.0f;
    pa.uv[2][0] = 1.0f;
    pa.uv[2][1] = 0.0f;
    pa.uv[3][0] = 1.0f;
    pa.uv[3][1] = 1.0f;
    for (i = 1; i < 3; i++) {
        s32 q;
        func_003C2EC0(obj, i, &mtx[0]);
        for (q = 0; q < 4; q++) {
            f32 ff, h;
            ff = (f32)((D_L19_001DF240 + (q * 25) / 4) % 25) / 25.0f;
            pos.x = 0.0f;
            pos.y = 0.0f;
            pos.w = 1.0f;
            pos.z = -ff + 0.4f;
            col = ((s32)((1.0f - ff) * 128.0f) << 24) | 0x804000;
            h = 0.5f - ff * 0.3f;
            *(Q_003ABBD8 *)&pa.v[0] = *(Q_003ABBD8 *)&pos;
            *(Q_003ABBD8 *)&pa.v[3] = *(Q_003ABBD8 *)&pos;
            *(Q_003ABBD8 *)&pa.v[2] = *(Q_003ABBD8 *)&pos;
            *(Q_003ABBD8 *)&pa.v[1] = *(Q_003ABBD8 *)&pos;
            pa.v[0].x -= h;
            pa.v[1].y -= h;
            pa.v[2].y += h;
            pa.v[3].x += h;
            pa.col[0] = col;
            pa.col[3] = col;
            pa.col[2] = col;
            pa.col[1] = col;
            func_003D2DA0(&pa, &mtx[0], 0);
        }
        t = abs_asm(10 - D_L19_001DF240 % 20);
        pos = mtx[3];
        func_003D9508(&pos, 6, 0x40804000, 1, (f32)t * 0.01f + 0.05f, 0.08f, 0.0f);
        pos = mtx[3];
        pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
        for (q = 1; q >= 0; q--) {
            f32 angle;
            angle = func_003824E0(-3.1415927f, 3.1415927f);
            qzero(&pb.v[0]);
            pb.v[0].x = func_003824E0(0.05f, 0.1f) * func_0038D098(angle);
            pb.v[0].y = func_003824E0(0.05f, 0.1f) * func_0038D0B0(angle);
            pb.v[0].z = func_003824E0(0.005f, 0.015f);
            qzero(&pb.v[1]);
            pb.v[0].w = 0.2f;
            pb.v[1].y = pb.v[0].y * 0.5f;
            pb.v[1].x = pb.v[0].x * 0.5f;
            pb.v[1].w = 0.25f;
            pb.v[1].z = 0.01f;
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(pb.v[2]) : "m"(pos), "m"(pb.v[0]) : "vf1", "vf2");
            pb.v[2].x += func_0038D098(angle) * 0.5f;
            pb.v[2].y += func_0038D0B0(angle) * 0.5f;
            func_L01_00463378(&pb.v[2], &pb.v[0], &pb.v[1], 0x30808080, 0x20808080, 4, 8, 8, -1);
        }
    }
}
/* localdecomp:end func_L19_003ABBD8 */
