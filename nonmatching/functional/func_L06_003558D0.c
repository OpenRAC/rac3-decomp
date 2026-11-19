/* functional: high. Same calls, args and order as retail; differs only in block layout (retail cross-jumps the 0x12 call into the 0x36C call). Callees frontbin func_0038CF38 (dist) and func_0038CAD0 (timer tick). */
#include "vu0.h"
#include "common.h"
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 t0);
extern f32 func_0038CF38(void *, void *);
extern s32 func_0038CAD0(void *);
extern void func_L06_00351728(u8 *, u8 *, void *, s32 *, f32 *);
extern s32 func_L06_00351508(u8 *, u8 *, s32, f32);
extern void func_L06_003552F8(u8 *a0, u8 *v, s32 a2, s32 a3);
extern void func_L06_00355610(u8 *a0, u8 *v, s32 a2, s32 a3);
extern s32 func_L06_00352500(u8 *, u8 *);
extern void func_L06_003523B0(u8 *, u8 *);
extern void func_L06_003519D0(u8 *, u8 *, s32, s32, s32);
extern s32 func_L06_003523F0(u8 *, u8 *);
extern void func_L06_00352370(u8 *, u8 *);

s32 func_L06_003558D0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 k;
    s32 n;
    f32 h;
    f32 dist;
    s32 near;
    s32 st;
    s32 s;

    if (a0[0x20] == 15) {
        s = *(s32 *)(v + 0x36C);
        if (s == 0x17) {
            if (func_0038CF38(a0 + 0x10, v + 0x220) < *(f32 *)(v + 0x318) * 0.75f) {
                func_L01_004450F0(a0, 0x12, -1);
                *(s32 *)(v + 0x36C) = 0;
                return 1;
            }
            func_L01_004450F0(a0, *(s32 *)(v + 0x36C), -1);
            *(s32 *)(v + 0x36C) = 0;
            return 1;
        }
        if (s != 0) {
            func_L01_004450F0(a0, s, -1);
            *(s32 *)(v + 0x36C) = 0;
            return 1;
        }
        func_L01_004450F0(a0, 1, -1);
    }
    st = a0[0x20];
    if ((st & 0xFF) == 1 || (st & 0xFF) == 0x16 || (st & 0xFF) == 0x1D) {
        if (!func_0038CAD0(v + 0x330)) {
            return 0;
        }
        *(s32 *)(v + 0x330) = 0x1E;
        near = 0;
        if (*(s16 *)(v + 0x23C) == 0) {
            near = 1;
        } else {
            dist = func_0038CF38(a0 + 0x10, v + 0x220);
            func_L06_00351728(a0, v, &k, &n, &h);
            if (*(f32 *)(v + 0x31C) + *(f32 *)(v + 0x304) < h) {
                near = 1;
            } else if (*(f32 *)(v + 0x31C) < dist) {
                if (h < *(f32 *)(v + 0x314) + *(f32 *)(v + 0x304) && !func_L06_00351508(a0, v, 0, dist)) {
                    func_L06_003552F8(a0, v, n, (s32)&k);
                } else {
                    func_L06_00355610(a0, v, n, (s32)&k);
                }
            } else if (func_L06_00351508(a0, v, 1, dist)) {
                func_L06_00355610(a0, v, n, (s32)&k);
            } else {
                func_L06_003552F8(a0, v, n, (s32)&k);
            }
        }
        if (near) {
            if (*(s32 *)(v + 0x334) == 0) {
                *(s32 *)(v + 0x334) = 0xF;
            }
            if (func_0038CAD0(v + 0x334)) {
                func_L01_004450F0(a0, 1, 2);
                func_L06_00351930(a0, v, 4, 0, 10);
                return 1;
            }
        } else {
            *(s32 *)(v + 0x334) = 0;
        }
        if (a0[0x20] == 0x16 || a0[0x20] == 0x1D) {
            func_L01_004450F0(a0, 1, -1);
        }
        st = a0[0x20];
        if (st == 1) {
            return 1;
        }
    }
    if (!(*(s32 *)(v + 0x36C) == 0x12 && *(s32 *)(v + 0x384) != 0)) {
        if (st != 0x12 || (*(u8 **)(v + 0x260))[0x43] != 0xB) {
            return 0;
        }
    }
    if ((*(u8 **)(v + 0x260))[0x43] == 0xB) {
        func_L06_00352500(a0, v);
        if (*(s32 *)(v + 0x35C) < 0) {
            func_L06_003523B0(a0, v);
            func_L06_003519D0(a0, v, 10, 0, 10);
        }
        return 0;
    }
    if (func_L06_003523F0(a0, v)) {
        func_L06_003519D0(a0, v, 0xB, 6, 0xA);
        func_L06_00352370(a0, v);
    }
    return 0;
}
