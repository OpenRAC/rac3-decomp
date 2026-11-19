/* functional: medium. Per-frame state machine of a scripted camera-path mover (ps = obj->p70+0x40, state ps.h14 0..6): fades D_001DF950, starts/ends the path run (states 0, 2, 5, 6 set up timers, sounds, overlays and fire the target's callback), and in the running states advances along the path table D_0021F6C0[base.w20] via func_L01_00476498, interpolates the roll keyframes (arr60 by arr80 indices) and rebuilds the orientation basis (obj, obj+0x10, obj+0x20). Mirrors retail branch by branch; unclear: meaning of base[0x40]/[0x54..0x56] flags (named by use only). */
#include "vu0.h"
extern char *D_L01_001DF804;
extern s32 D_001DFD38;
extern f32 D_001DF950;
extern s32 D_001DF95C;
extern u8 D_001D667B;
extern u8 *D_001E001C;
extern u8 D_001E2DC0[];
extern u8 D_001E7580[];
extern f32 D_001E7630;
extern u8 D_001A4EC0[];
extern u8 *D_0021F6C0[];
extern void func_003873C0();
extern s32 func_0038CB00(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_L01_003EC9E0(s32);
extern void func_L01_003ECB58(void);
extern void func_L01_003F5498(s32, f32);
extern void func_L01_003F55D0(s32, s32, f32, f32);
extern void func_L01_00404AD8(void *, void *);
extern s32 (**func_L01_0043B568(s32, s32, s32))(void *);
extern s32 func_L01_00476498(void *, void *, void *, void *, s32, f32);
extern void func_L01_005003D0(s32, s32);

void func_L01_003ED1F8(u8 *a0) {
    f32 vA[4] __attribute__((aligned(16)));
    f32 vB[4] __attribute__((aligned(16)));
    f32 vC[4] __attribute__((aligned(16)));
    f32 vD[4] __attribute__((aligned(16)));
    f32 vE[4] __attribute__((aligned(16)));
    f32 vF[4] __attribute__((aligned(16)));
    f32 tail[2];
    u8 *base = *(u8 **)(D_L01_001DF804 + *(s16 *)(a0 + 0x84) * 32 + 28);
    u8 *data = *(u8 **)(a0 + 0x70);
    u8 *ps = data + 0x40;
    u8 *p58 = data + 0x58;
    s16 st;
    f32 f0, f20, f21, f1, f14, f2;
    s32 r, k, v3, w5C, n;
    u8 *path, *tbl, *objc, *arr60, *arr80;
    s32 (**cb)(void *);

    D_001DFD38 = 1;
    st = *(s16 *)(ps + 0x14);
    if (st == 0) {
        f0 = D_001DF950;
        if (base[0x54] == 0) {
            D_001DF950 = f0 + 0.05f;
            f0 = D_001DF950;
        }
        if (!(1.0f <= f0) && base[0x54] == 0) return;
        path = D_0021F6C0[*(s32 *)(base + 0x20)];
        tbl = D_0021F6C0[*(s32 *)(base + 0x24)];
        D_001DF950 = 1.0f;
        D_001DF95C = (base[0x56] == 0);
        *(s16 *)(ps + 0x14) = 1;
        *(vu0_q *)(a0 + 0x30) = *(vu0_q *)(path + 0x10);
        if (*(s32 *)(base + 0x28) >= 0) {
            vB[0] = *(f32 *)(base + 0x2C);
            vB[1] = *(f32 *)(base + 0x30);
            vB[2] = *(f32 *)(base + 0x34);
            vB[3] = 0.0f;
            objc = D_001E001C + (*(s32 *)(base + 0x28) << 8);
            func_0038D000(vB, vB, D_001E2DC0 + *(s32 *)(a0 + 0x94) * 0x460);
            vec_add_ba(vC, objc + 0x10, vB);
            vec_copy(vF, a0 + 0x30);
            vec_sub_ab(vA, vC, vF);
        } else {
            vec_sub_ab(vA, tbl + 0x10, a0 + 0x30);
        }
        func_0038CE20(vB, D_001A4EC0, -1.0f);
        func_0038CF68((f32 *)a0, vA, 1.0f);
        func_0038CE90(a0 + 0x10, a0, vB);
        func_0038CF68((f32 *)(a0 + 0x10), (f32 *)(a0 + 0x10), 1.0f);
        func_0038CE90(a0 + 0x20, a0 + 0x10, a0);
        return;
    }
    if (st == 2) {
        f0 = D_001DF950;
        if (base[0x55] == 0) {
            D_001DF950 = f0 + 0.05f;
            f0 = D_001DF950;
        }
        if (1.0f <= f0 || base[0x55] != 0) {
            if (base[0x55] == 0) D_001DF950 = 1.0f;
            *(s16 *)(ps + 0x14) = 3;
            f20 = *(f32 *)(p58 + 0x30) * 0.5f;
            f21 = func_0038D0B0(f20);
            f21 = f21 / func_0038D098(f20);
            D_001E7630 = f21;
            func_003873C0();
            base[0x39] = 1;
            *(s16 *)(a0 + 0x7E) = 4;
            if (base[0x41] == 0) func_L01_005003D0(0, 1);
            if (*(s16 *)(base + 0x46) != -1) func_003A0EC0(0, 2, 0, 0, 0);
            D_001D667B = 0;
            if (*(s32 *)(base + 0x4C) != -1) {
                func_L01_003EC9E0(*(s32 *)(base + 0x4C));
            } else {
                if (base[0x55] == 0) func_L01_003F5498(0, 12.0f);
                D_001DF95C = 0;
            }
            if (base[0x55] != 0) {
                if (*(s32 *)(base + 0x58) != 0) func_L01_003F55D0(0, 1, 3.0f, 10.0f);
            }
        }
        if (base[0x45] != 0) func_L01_00404AD8(func_L01_003ECB58, 0);
        if (base[0x40] == 0) return;
        goto tail_path;
    }
    if (st == 3) return;
    if (st == 1) {
        f0 = D_001DF950;
        if (base[0x54] == 0) {
            D_001DF950 = f0 - 0.05f;
            f0 = D_001DF950;
        }
        if (f0 < 0.0f) D_001DF950 = 0.0f;
        n = *(s32 *)(base + 0x48);
        if (n == 0 && *(s16 *)(base + 0x46) == -1) goto tail_path;
        v3 = *(s16 *)(base + 0x46);
        if (v3 == -1 || n < v3) *(s16 *)(ps + 0x14) = 5;
        else *(s16 *)(ps + 0x14) = 6;
        goto tail_path;
    }
    if (st == 5) {
        f0 = D_001DF950;
        if (base[0x54] == 0) {
            D_001DF950 = f0 - 0.05f;
            f0 = D_001DF950;
        }
        if (f0 < 0.0f) D_001DF950 = 0.0f;
        if (func_0038CB00(data + 0x56) != 0) {
            v3 = *(s16 *)(base + 0x46);
            if (v3 == -1 || v3 < *(s32 *)(base + 0x48)) {
                *(s16 *)(ps + 0x14) = 4;
                *(s16 *)(ps + 0x16) = (*(s16 *)(base + 0x3A) * 5 + 2) / 6;
            } else {
                *(s16 *)(ps + 0x14) = 6;
                *(s16 *)(ps + 0x16) = ((v3 - *(s32 *)(base + 0x48)) * 5 + 2) / 6;
            }
        }
        if (base[0x45] != 0) func_L01_00404AD8(func_L01_003ECB58, 0);
        goto callback;
    }
    if (st != 6) goto tail_path;
    f0 = D_001DF950;
    if (base[0x54] == 0) {
        D_001DF950 = f0 - 0.05f;
        f0 = D_001DF950;
    }
    if (f0 < 0.0f) D_001DF950 = 0.0f;
    if (func_0038CB00(data + 0x56) != 0) {
        func_L01_003F55D0(0, 1, 3.0f, 10.0f);
        func_003A0EC0(4, 2, 0xC, 0, 0);
        if (*(s32 *)(base + 0x48) < *(s16 *)(base + 0x46)) {
            *(s16 *)(ps + 0x14) = 4;
            v3 = *(s16 *)(base + 0x3A);
        } else {
            *(s16 *)(ps + 0x14) = 1;
            v3 = *(s32 *)(base + 0x48) - *(s16 *)(base + 0x46);
        }
        *(s16 *)(ps + 0x16) = (v3 * 5 + 2) / 6;
    }
    if (base[0x45] != 0) func_L01_00404AD8(func_L01_003ECB58, 0);
    if (!(*(s16 *)(base + 0x46) < *(s32 *)(base + 0x48))) goto tail_path;
    goto callback;

tail_path:
    vec_copy(vA, a0 + 0x30);
    path = D_0021F6C0[*(s32 *)(base + 0x20)];
    r = func_L01_00476498(path, a0 + 0x30, ps, ps + 4, 0, *(f32 *)(base + 0x3C) * 0.02f);
    if (*(s16 *)(ps + 0x16) != 0) {
        if (func_0038CB00(ps + 0x16) != 0) {
            r = 1;
        } else if (base[0x40] != 0 && !(0x10 < *(s16 *)(ps + 0x16))) {
            r = 1;
        }
    }
    if (base[0x39] != 0) r = 1;
    if (r != 0) {
        *(s16 *)(ps + 0x14) = 2;
        if (base[0x40] == 0) return;
    }
    if (*(s32 *)(base + 0x80) >= 0 && *(s32 *)(base + 0x84) >= 0) {
        arr80 = base + 0x80;
        arr60 = base + 0x60;
        k = 0;
        for (;;) {
            s32 cur = *(s32 *)ps;
            s32 lo = *(s32 *)(arr80 + k * 4);
            s32 hi;
            if (!(cur < lo)) {
                hi = *(s32 *)(arr80 + (k + 1) * 4);
                if (cur < hi) {
                    f14 = 0.0f;
                    f2 = *(f32 *)(ps + 4);
                    if (lo < cur) {
                        for (n = lo; n < cur; n++) f14 = f14 + *(f32 *)(path + n * 16 + 0x1C);
                    }
                    f1 = f14;
                    f14 = f14 + f2;
                    if (cur < hi) {
                        for (n = cur; n < hi; n++) f1 = f1 + *(f32 *)(path + n * 16 + 0x1C);
                    }
                    f14 = f14 / f1;
                    f20 = func_003C3BE8(*(f32 *)(arr60 + k * 4), *(f32 *)(arr60 + (k + 1) * 4), f14);
                    f20 = f20 * 0.017453292f;
                    f20 = f20 * 0.5f;
                    f21 = func_0038D0B0(f20);
                    f21 = f21 / func_0038D098(f20);
                    *(f32 *)(D_001E7580 + 0xB0) = f21;
                    func_003873C0();
                }
            }
            if (!(k + 1 < 7)) break;
            k = k + 1;
            if (*(s32 *)(arr80 + k * 4) < 0) break;
            if (*(s32 *)(arr80 + (k + 1) * 4) < 0) break;
        }
    }
    f1 = *(f32 *)(ps + 0x10) + func_0038CF00(vA, a0 + 0x30);
    *(f32 *)(ps + 0x10) = f1;
    if (*(s32 *)(base + 0x28) >= 0) {
        vC[0] = *(f32 *)(base + 0x2C);
        vC[1] = *(f32 *)(base + 0x30);
        vC[2] = *(f32 *)(base + 0x34);
        vC[3] = 0.0f;
        objc = D_001E001C + (*(s32 *)(base + 0x28) << 8);
        func_0038D000(vC, vC, D_001E2DC0 + *(s32 *)(a0 + 0x94) * 0x460);
        vec_add_ba(vD, objc + 0x10, vC);
        vec_copy(vF, a0 + 0x30);
        vec_sub_ab(vB, vD, vF);
    } else {
        f0 = *(f32 *)(ps + 0xC);
        f1 = f1 / *(f32 *)(ps + 8);
        tail[0] = 0.0f;
        tail[1] = 0.0f;
        func_L01_00476498(D_0021F6C0[*(s32 *)(base + 0x24)], vC, tail, tail + 1, 0, f1 * f0);
        vec_sub_ab(vB, vC, a0 + 0x30);
    }
    func_0038CE20(vC, D_001A4EC0, -1.0f);
    func_0038CF68((f32 *)a0, vB, 1.0f);
    func_0038CE90(a0 + 0x10, a0, vC);
    func_0038CF68((f32 *)(a0 + 0x10), (f32 *)(a0 + 0x10), 1.0f);
    func_0038CE90(a0 + 0x20, a0 + 0x10, a0);
    if (base[0x45] != 0) func_L01_00404AD8(func_L01_003ECB58, 0);
callback:
    w5C = *(s32 *)(base + 0x5C);
    if (w5C != -1) {
        objc = D_001E001C + (w5C << 8);
        cb = func_L01_0043B568(*(s16 *)(objc + 0xAA), 0, 4);
        if (cb != 0) (*cb)(objc);
    }
}
