/* functional: high. Builds a camera/mover path state from the two path tables (D_0021F6C0 entries at base+0x20 and base+0x24): measures each segment length (func_0038CF00), accumulates the totals in ps+8 / ps+0xC, records the in-range points (0 < len, big ones clamped to 2*D_001E7580 angle * 57.2958 deg) in arr1/arr2, derives base+0x3C speed, resets rotation data and copies the pose from the player's target; plays sound 0x74 unless base+0x41 is set */
#include "vu0.h"
extern u8 D_001E7580[];
extern u8 *D_0021F6C0[];
extern u8 D_001D667B;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_005003D0(s32, s32);
void func_L01_003ECDD0(u8 *a0) {
    u8 *base = *(u8 **)(D_L01_001DF804 + *(s16 *)(a0 + 0x84) * 32 + 28);
    u8 *data;
    u8 *ps;
    u8 *e;
    u8 *path;
    u8 *arr1 = base + 0x60;
    u8 *arr2 = base + 0x80;
    u8 *p;
    s32 v5, v4, m, n, i, j, cnt, k;
    f32 f, tmp;
    f32 *w;
    s32 *w2;

    base[0x38] = 1;
    data = *(u8 **)(a0 + 0x70);
    *(s32 *)(data + 0x40) = 0;
    ps = data + 0x40;
    *(s32 *)(ps + 4) = 0;
    *(s32 *)(ps + 8) = 0;
    *(s32 *)(ps + 0xC) = 0;
    *(s32 *)(ps + 0x10) = 0;
    *(s16 *)(ps + 0x14) = 0;
    v5 = *(s32 *)(base + 0x48);
    if (v5 == 0 && *(s16 *)(base + 0x46) == -1) {
        m = *(s16 *)(base + 0x3A);
    } else {
        v4 = *(s16 *)(base + 0x46);
        if (v4 == -1 || v5 < v4) m = v5;
        else m = v4;
    }
    *(s16 *)(ps + 0x16) = (m * 5 + 2) / 6;
    p = *(u8 **)(a0 + 0x70) + 0x58;
    for (i = 7; i >= 0; i--) {
        *(s32 *)(arr1 + i * 4) = 0;
        *(s32 *)(arr2 + i * 4) = -1;
    }
    cnt = 0;
    f = func_0038D160(1.0f, *(f32 *)(D_001E7580 + 0xB0));
    *(f32 *)(p + 0x30) = f + f;
    if (base[0x44] == 0) {
        s32 pi = *(s32 *)(base + 0x20);
        if (pi >= 0) {
            path = D_0021F6C0[pi];
            n = *(s32 *)path;
            if (n > 0) {
                w = (f32 *)arr1;
                i = 0;
                do {
                    f = *(f32 *)(path + i * 16 + 0x1C);
                    if (0.0f < f) {
                        *w = f;
                        if (180.0f < f) *w = *(f32 *)(p + 0x30) * 57.295776f;
                        w++;
                        *(s32 *)(arr2 + cnt * 4) = i;
                        cnt++;
                    }
                    j = (i + 1) % *(s32 *)path;
                    f = func_0038CF00(path + i * 16 + 0x10, path + j * 16 + 0x10);
                    *(f32 *)(path + i * 16 + 0x1C) = f;
                    if (i < *(s32 *)path - 1) *(f32 *)(ps + 8) = *(f32 *)(ps + 8) + f;
                    i = i + 1;
                } while (i < *(s32 *)path);
            }
        }
        D_001D667B = 1;
        k = *(s16 *)(base + 0x3A);
    } else {
        k = *(s16 *)(base + 0x3A);
    }
    if (k > 0) {
        *(f32 *)(base + 0x3C) = *(f32 *)(ps + 8) / (f32)((k * 5 + 2) / 6) * 60.0f;
    }
    if (*(s32 *)(base + 0x24) >= 0) {
        path = D_0021F6C0[*(s32 *)(base + 0x24)];
        n = *(s32 *)path;
        if (n > 0) {
            i = 0;
            do {
                j = (i + 1) % n;
                f = func_0038CF00(path + i * 16 + 0x10, path + j * 16 + 0x10);
                *(f32 *)(path + i * 16 + 0x1C) = f;
                if (i < *(s32 *)path - 1) *(f32 *)(ps + 0xC) = *(f32 *)(ps + 0xC) + f;
                n = *(s32 *)path;
                i = i + 1;
            } while (i < n);
        }
    }
    data = *(u8 **)(a0 + 0x70);
    qzero(data + 0x10);
    *(f32 *)(data + 0) = 0.03f;
    *(f32 *)(data + 4) = 0.2f;
    data = *(u8 **)(a0 + 0x70);
    qzero(data + 0x30);
    *(f32 *)(data + 0x20) = 0.03f;
    *(f32 *)(data + 0x24) = 0.2f;
    e = (u8 *)D_L01_001E2A40 + *(s32 *)(a0 + 0x94) * 0x460;
    *(vu0_q *)(a0 + 0x30) = *(vu0_q *)(*(u8 **)(e + 0x54) + 0x30);
    *(vu0_q *)(a0 + 0x00) = *(vu0_q *)(*(u8 **)(e + 0x54) + 0x00);
    *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(*(u8 **)(e + 0x54) + 0x10);
    *(vu0_q *)(a0 + 0x20) = *(vu0_q *)(*(u8 **)(e + 0x54) + 0x20);
    if (base[0x41] == 0) func_L01_005003D0(0x74, 1);
    base[0x44] = 1;
}
