/* func_L01_003AC000 (Claude wave 14 r60, 2026-11-28). First draft kept here. */
#include "common.h"

/* func_L01_003AC000 (fresh entry, first draft; sibling of func_L05_0032A4D8, whose draft it follows).
 * Under the file's line and context: 428 positional differences (p10/check.py, level 01), but only 78
 * rows LCS-aligned. Part of that is a prototype the file has wrong: func_L01_003ABE88 (defined earlier in
 * this file) takes a fifth f32 that it passes through in $f12 to func_0038CDF8 (its body never touches
 * $f12, so the matched definition still matches with `f32 t` added and passed on); retail sets $f12 for
 * both calls here (u = g - seg, 1.0 on the end path, h - seg), and with the file's 4-argument prototype
 * those computations are dead. With the 5-argument prototype (tools/check.py --no-context, same C) it is
 * 64 aligned rows, and what is left is register allocation: o/o+0x10 in s4/s3 where retail has s3/s4,
 * path/path+0x10 in s1/s2 where retail has s2/s1, the speed term in $f4 instead of $f5, and g kept in
 * $f12 with a copy in $f2 in retail. Structure that matched: the mode selection as a goto chain (retail
 * has no mode variable: st == 5 jumps straight to the check or to the end-of-path aiming), the clamp
 * limits written inline (D * 0.017453292f, negated in place), 0.00040000002f (0x39D1B718), fabs_asm,
 * the three vec_sub helpers in retail's load orders. */

/* localdecomp:start func_L01_003AC000 */
#include "vu0.h"
extern u8 *D_L01_0021F6C0[];
extern u8 *D_L01_001E0100;
extern f32 D_L01_001DE3C4 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3C4, 4");
__asm__(".extern D_L01_001DE3C8, 4");
extern f32 D_L01_001DE3C8;
__asm__(".extern D_L01_001DE3D0, 4");
extern f32 D_L01_001DE3D0;
__asm__(".extern D_L01_001DE3D4, 4");
extern f32 D_L01_001DE3D4;
__asm__(".extern D_L01_001DE3D8, 4");
extern f32 D_L01_001DE3D8;
__asm__(".extern D_L01_001DE3DC, 4");
extern f32 D_L01_001DE3DC;
__asm__(".extern D_L01_001DE3E0, 4");
extern f32 D_L01_001DE3E0;
__asm__(".extern D_L01_001DE3E4, 4");
extern f32 D_L01_001DE3E4;
__asm__(".extern D_L01_001DE3E8, 4");
extern f32 D_L01_001DE3E8;
__asm__(".extern D_L01_001DE3EC, 4");
extern f32 D_L01_001DE3EC;
__asm__(".extern D_L01_001DE3F0, 4");
extern f32 D_L01_001DE3F0;
__asm__(".extern D_L01_001DE3F4, 4");
extern f32 D_L01_001DE3F4;
__asm__(".extern D_L01_001DE3F8, 4");
extern f32 D_L01_001DE3F8;
__asm__(".extern D_L01_001DE3FC, 4");
extern f32 D_L01_001DE3FC;
__asm__(".extern D_L01_001DE400, 4");
extern f32 D_L01_001DE400;
__asm__(".extern D_L01_001DE404, 4");
extern f32 D_L01_001DE404;
__asm__(".extern D_L01_001DE408, 4");
extern f32 D_L01_001DE408;
__asm__(".extern D_L01_001DE40C, 4");
extern f32 D_L01_001DE40C;
__asm__(".extern D_L01_001DE410, 4");
extern f32 D_L01_001DE410;
extern void func_0038CF68(u8 *, Vec4 *, f32);
extern f32 func_0038CE68(Vec4 *, u8 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C41A0(void *, void *, f32, f32, f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_L01_003ABD10(u8 *object, u8 *state, f32 value);
extern f32 func_L01_003ABD60(u8 *object, Path_003ABD60 *path, s32 *index, f32 position, f32 distance);
extern void func_L01_003ABE88(u8 *object, Points_003ABE88 *points, s32 index, void *out);
extern void func_L01_003ABF48(u8 *obj, s32 unused, Vec4 *a2, f32 *out1, f32 *out2);

s32 func_L01_003AC000(u8 *o, u8 *s) {
    extern f32 func_0038CED8(void *);
    extern f32 func_0038CF00(void *, void *);
    Vec4 dir;
    Vec4 pos;
    Vec4 rot;
    Vec4 tgt;
    Vec4 d2;
    f32 tmp;
    s32 seg;
    Path_003ABD60 *path;
    u8 *t;
    f32 f;
    f32 g;
    f32 h;
    f32 dot;
    f32 lim;
    f32 sp;
    f32 ac;
    f32 k;
    f32 u;
    s32 r;
    s32 end;

    path = (Path_003ABD60 *)D_L01_0021F6C0[*(s32 *)(s + 0xD10)];
    t = D_L01_001E0100 + (*(s32 *)(s + 0xC80 + *(s32 *)(s + 0xD0C) * 4) << 7);
    pos.q = *(u128_t *)(o + 0x10);
    f = func_L01_003ABD10(o, s, D_L01_001DE3C8 * *(f32 *)(s + 0xC6C));
    if (*(f32 *)(s + 0xD14) < 0.0f) {
        vec_sub_ba(&dir, &path->pts[0], s + 0xD60);
    } else {
        seg = *(f32 *)(s + 0xD14);
        if (seg == path->count - 1) {
            vec_sub_ba(&dir, s + 0xD70, &path->pts[seg]);
        } else {
            vec_sub_ba(&dir, &path->pts[seg + 1], &path->pts[seg]);
        }
    }
    func_0038CF68((u8 *)&dir, &dir, 1.0f);
    dot = func_0038CE68(&dir, o + 0xC0);
    if (dot <= 0.0f) {
        sp = D_L01_001DE3D4;
        ac = D_L01_001DE3DC;
    } else {
        dot = dot * D_L01_001DE3D0;
        if (1.0f < dot) {
            dot = 1.0f;
        }
        sp = D_L01_001DE3D4 + (D_L01_001DE3C8 - D_L01_001DE3D4) * dot;
        ac = D_L01_001DE3DC + (D_L01_001DE3D8 - D_L01_001DE3DC) * dot;
    }
    k = *(f32 *)(s + 0xC6C);
    sp = sp * k;
    ac = ac * (((k + 1.0f) + k) * 0.33333334f);
    tmp = 0.0f;
    func_003C41A0(&tmp, s + 0xD18, f, ac * 0.00040000002f, ac * 0.00040000002f, sp * 0.020000001f);
    r = 0;
    g = func_L01_003ABD60(s, path, &seg, *(f32 *)(s + 0xD14), *(f32 *)(s + 0xD18));
    *(f32 *)(s + 0xD14) = g;
    end = 0;
    if (seg >= path->count - 1) {
        seg = path->count - 1;
        end = 1;
    }
    u = g - seg;
    if (end && 1.0f <= u) {
        if (o[0x20] == 5 && *(s32 *)(s + 0xC54) != 0) {
            if (func_0038CF00(o + 0x10, &path->pts[0]) < D_L01_001DE3C4) {
                *(f32 *)(s + 0xD14) = *(f32 *)(s + 0xD14) - (f32)(path->count - 1);
                *(u128_t *)(s + 0xD60) = *(u128_t *)&path->pts[0];
                *(f32 *)(s + 0xD6C) = -1.0f;
            } else {
                *(f32 *)(s + 0xD14) = *(f32 *)(s + 0xD14) - (f32)path->count;
                *(u128_t *)(s + 0xD60) = *(u128_t *)(o + 0x10);
                *(f32 *)(s + 0xD6C) = func_0038CF00(o + 0x10, &path->pts[0]);
            }
            seg = *(f32 *)(s + 0xD14);
            u = *(f32 *)(s + 0xD14) - seg;
        } else {
            r = 2;
            u = 1.0f;
            *(f32 *)(s + 0xD14) = g - *(f32 *)(s + 0xD18) / path->pts[seg].v[3];
        }
    }
    func_L01_003ABE88(s, (Points_003ABE88 *)path, seg, o + 0x10);
    if (*(s32 *)(s + 0xC4C) != 0 && *(s16 *)(s + 0x44) == 1) {
        vec_sub_ba(&dir, s + 0x30, o + 0x10);
        func_L01_003ABF48(o, (s32)s, &pos, &rot.f[0], &rot.f[1]);
        rot.f[1] = func_0038DAB8(rot.f[1], -func_0038D160(func_0038CED8(&dir), dir.f[2]));
        if (D_L01_001DE3F0 * 0.017453292f < rot.f[1]) {
            rot.f[1] = D_L01_001DE3F0 * 0.017453292f;
        } else if (rot.f[1] < -(D_L01_001DE3F0 * 0.017453292f)) {
            rot.f[1] = -(D_L01_001DE3F0 * 0.017453292f);
        }
        rot.f[2] = func_0038D160(dir.f[0], dir.f[1]);
    } else {
        if (o[0x20] == 5) {
            if (*(s32 *)(s + 0xC58) != 0) {
                goto mode1;
            }
            goto check;
        }
        if (seg >= path->count - *(s32 *)(s + 0xCA0 + *(s32 *)(s + 0xD0C) * 4)) {
            func_L01_003ABF48(o, (s32)s, &pos, &rot.f[0], &rot.f[1]);
            rot.f[0] = -rot.f[0];
            rot.f[1] = -rot.f[1];
            rot.f[0] = func_0038DAB8(rot.f[0], *(f32 *)(t + 0x70));
            if (D_L01_001DE3F0 * 0.017453292f < rot.f[1]) {
                rot.f[1] = D_L01_001DE3F0 * 0.017453292f;
            } else if (rot.f[1] < -(D_L01_001DE3F0 * 0.017453292f)) {
                rot.f[1] = -(D_L01_001DE3F0 * 0.017453292f);
            }
            rot.f[1] = func_0038DAB8(rot.f[1], *(f32 *)(t + 0x74));
            rot.f[2] = *(f32 *)(t + 0x78);
        } else {
check:
            if (((0.0f < *(f32 *)(s + 0xD6C) && seg == -1) || (*(f32 *)(s + 0xD6C) < 0.0f && seg == 0))
                && !(o[0x20] == 5 && *(s32 *)(s + 0xC70) == -1 && seg == -1)) {
mode1:
                func_L01_003ABF48(o, (s32)s, &pos, &rot.f[0], &rot.f[1]);
                rot.f[0] = func_0038DAB8(rot.f[0], *(f32 *)(t + 0x70));
                if (D_L01_001DE3F0 * 0.017453292f < rot.f[1]) {
                    rot.f[1] = D_L01_001DE3F0 * 0.017453292f;
                } else if (rot.f[1] < -(D_L01_001DE3F0 * 0.017453292f)) {
                    rot.f[1] = -(D_L01_001DE3F0 * 0.017453292f);
                }
                rot.f[1] = func_0038DAB8(rot.f[1], *(f32 *)(t + 0x74));
                rot.f[2] = *(f32 *)(o + 0xF8);
            } else {
                lim = *(f32 *)(s + 0xD18) * D_L01_001DE3E0;
                if (D_L01_001DE3E4 < lim) {
                    lim = D_L01_001DE3E4;
                } else if (lim < D_L01_001DE3E8) {
                    lim = D_L01_001DE3E8;
                }
                h = func_L01_003ABD60(s, path, &seg, *(f32 *)(s + 0xD14), lim);
                seg = h;
                func_L01_003ABE88(s, (Points_003ABE88 *)path, seg, &tgt);
                vec_sub_ab(&d2, &tgt, o + 0x10);
                rot.f[0] = 0.0f;
                rot.f[1] = -func_0038D160(func_0038CED8(&d2), d2.f[2]);
                if (D_L01_001DE3F0 * 0.017453292f < rot.f[1]) {
                    rot.f[1] = D_L01_001DE3F0 * 0.017453292f;
                } else if (rot.f[1] < -(D_L01_001DE3F0 * 0.017453292f)) {
                    rot.f[1] = -(D_L01_001DE3F0 * 0.017453292f);
                }
                rot.f[2] = func_0038D160(d2.f[0], d2.f[1]);
            }
        }
    }
    func_L01_00448890(o + 0xF4, rot.f[1], s + 0xD54, D_L01_001DE3F4 * 0.017453292f * 0.00040000002f,
                      D_L01_001DE3F4 * 0.017453292f * 0.00040000002f, D_L01_001DE3F8 * 0.017453292f * 0.020000001f, 0);
    func_L01_00448890(o + 0xF8, rot.f[2], s + 0xD58, D_L01_001DE3FC * 0.017453292f * 0.00040000002f,
                      D_L01_001DE3FC * 0.017453292f * 0.00040000002f, D_L01_001DE400 * 0.017453292f * 0.020000001f, 0);
    rot.f[0] = func_0038DAB8(rot.f[0], *(f32 *)(s + 0xD58) * *(f32 *)(s + 0xD18) * D_L01_001DE410);
    if (D_L01_001DE404 * 0.017453292f < rot.f[0]) {
        rot.f[0] = D_L01_001DE404 * 0.017453292f;
    } else if (rot.f[0] < -(D_L01_001DE404 * 0.017453292f)) {
        rot.f[0] = -(D_L01_001DE404 * 0.017453292f);
    }
    func_L01_00448890(o + 0xF0, rot.f[0], s + 0xD50, D_L01_001DE40C * 0.017453292f * 0.00040000002f,
                      D_L01_001DE40C * 0.017453292f * 0.00040000002f, D_L01_001DE408 * 0.017453292f * 0.020000001f, 0);
    rot.q = *(u128_t *)(t + 0x70);
    if (r == 2) {
        if (D_L01_001DE3EC < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF0), rot.f[0]))
            || D_L01_001DE3EC < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF4), rot.f[1]))
            || D_L01_001DE3EC < fabs_asm(func_0038DBA0(*(f32 *)(o + 0xF8), rot.f[2]))) {
            r = 1;
        }
    }
    return r;
}
/* localdecomp:end func_L01_003AC000 */
