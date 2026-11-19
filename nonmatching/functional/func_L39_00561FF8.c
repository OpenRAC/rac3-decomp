/* functional: high. Same blocks, calls and arguments as retail; differs only in codegen (retail saves a copy of the position quad to the stack that is never read; 1/0 guarded to +max like PS2 div.s). */
#include "common.h"
extern u8 D_00242930[];
extern s32 D_0024CE20[];
extern u8 D_0025F760[];
extern u8 D_002FB000[];
s32 func_L01_004561B8(u8 *);
s32 func_0038CAD0(void *);
f32 func_0038CEA8(void *);
f32 func_0038CF00(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_003C2880(void *);
void func_L01_00446760(void *, u8 *, s32, void *, f32);
void func_L39_005FFDF8(s32);
void func_L39_005FFE78(void);
s32 func_003D3CB0(void *, void *, s32, s32, void *);
void func_L07_003CB1F8(void *);
void func_L07_003CC1C0(void *);
void func_L39_00562858(f32 *, u8 *);
void func_L01_00404A10(void *, u8 *);

void func_L39_00561FF8(u8 *a) {
    u8 *st = *(u8 **)(a + 0x68);
    f32 tmp[4];
    u8 hit[0x40];
    s32 n;
    s32 i;
    s32 cnt;
    f32 d;
    u8 *tbl;
    if (a[0x20] == 0) {
        if (func_L01_004561B8(a) == 0) {
            *(f32 *)(a + 0x10) += *(f32 *)(st + 0x0);
            *(f32 *)(a + 0x14) += *(f32 *)(st + 0x4);
            *(f32 *)(a + 0x18) += *(f32 *)(st + 0x8);
        }
        if (func_0038CAD0(st + 0x24) != 0) {
            func_003C2880(a);
            return;
        }
        if (*(s32 *)(st + 0x30) == 0) {
            if (*(f32 *)(st + 0x20) < func_0038CEA8(st)) {
                tmp[0] = *(f32 *)(a + 0x10) + *(f32 *)(st + 0x0);
                tmp[1] = *(f32 *)(a + 0x14) + *(f32 *)(st + 0x4);
                tmp[2] = *(f32 *)(a + 0x18) + *(f32 *)(st + 0x8);
                tmp[3] = *(f32 *)(a + 0x1C);
            } else {
                func_0038CF68(tmp, st, *(f32 *)(st + 0x20));
                tmp[0] += *(f32 *)(a + 0x10);
                tmp[1] += *(f32 *)(a + 0x14);
                tmp[2] += *(f32 *)(a + 0x18);
            }
            func_L01_00446760(hit, a, 0x10001, D_00242930, *(f32 *)(st + 0x34));
            *(s32 *)(hit + 0x28) = *(s32 *)(st + 0x44);
            n = *(s32 *)(a + 0xB8);
            tbl = (u8 *)D_0024CE20[*(s32 *)(st + 0x40)];
            func_L39_005FFDF8(tbl != 0 ? *(s32 *)(tbl + 0x2548) : -1);
            i = func_003D3CB0(a + 0x10, tmp, 0x10, n, hit);
            func_L39_005FFE78();
            if (i != 0) {
                *(s32 *)(st + 0x30) = 1;
                *(s32 *)(st + 0x10) = *(s32 *)(D_0025F760 + 0x0);
                *(s32 *)(st + 0x14) = *(s32 *)(D_0025F760 + 0x4);
                *(s32 *)(st + 0x18) = *(s32 *)(D_0025F760 + 0x8);
                *(s32 *)(st + 0x1C) = *(s32 *)(D_0025F760 + 0xC);
                d = func_0038CF00(a + 0x10, st + 0x10);
                d = d / func_0038CEA8(st);
                cnt = ((s32)d * 5 + 2) / 6;
                *(s32 *)(st + 0x24) = cnt;
                *(f32 *)(st + 0x28) = cnt != 0 ? 1.0f / (f32)cnt : 3.4028235e38f;
                if (*(s32 *)(D_0025F760 - 8) == 0)
                    func_L07_003CC1C0(a);
                else
                    func_L39_00562858((f32 *)(st + 0x10), D_002FB000);
            }
        }
        func_L01_00404A10(func_L07_003CB1F8, a);
    }
    if (*(f32 *)(a + 0x10) < 2.0f || 1021.0f < *(f32 *)(a + 0x10)
        || *(f32 *)(a + 0x14) < 2.0f || 1021.0f < *(f32 *)(a + 0x14)
        || *(f32 *)(a + 0x18) < 2.0f || 1021.0f < *(f32 *)(a + 0x18))
        func_003C2880(a);
}
