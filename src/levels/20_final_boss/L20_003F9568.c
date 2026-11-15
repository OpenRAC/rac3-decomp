#include "common.h"

/* localdecomp:start func_L20_003F9568 */
#include "vu0.h"
extern u8 D_001E2E80[];
extern u8 D_001E9BE0[];
extern u8 D_001D66B0;
extern u8 D_00220258[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_00382580(void *, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern void func_L20_003EAA70(void *, void *, void *);
extern void func_003C2880(void *);
extern void func_L01_004AA7E8(u8 *, s32);

void func_L20_003F9568(u8 *self) {
    vu0_v4 pos;
    vu0_v4 vel;
    vu0_v4 v3;
    u8 *d;
    u8 *e;
    u8 *q;
    s32 n;
    s32 i;
    f32 sc;
    u8 *p;

    d = *(u8 **)(self + 0x68);
    *(s32 *)(self + 0x98) = 0;
    *(s16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(self, 1);
    *(s16 *)(self + 0x96) += 1;
    switch (*(u8 *)(self + 0x20)) {
    case 0:
        pos = *(vu0_v4 *)(self + 0x10);
        vec_add_ab(self + 0x10, self + 0x10, d + 0x10);
        *(f32 *)(d + 0x18) -= *(f32 *)(d + 4);
        if (func_003D3CB0(&pos, self + 0x10, 2, *(void **)(self + 0xB8), 0) != 0) {
            *(vu0_v4 *)(self + 0x10) = *(vu0_v4 *)D_001E9BE0;
            *(f32 *)(self + 0x18) += 0.5f;
            func_L01_004450F0(self, 1, -1);
        }
        break;
    case 1:
        p = D_001E2E80;
        *(f32 *)(p + 0x40) = 0.1f;
        *(s32 *)(p + 0x48) = 0x4B;
        *(f32 *)(p + 0x20) = 0.2f;
        *(s32 *)(p + 0x28) = 0x32;
        *(s32 *)(p + 0x2C) = 0;
        for (i = 0; i < 300; i++) {
            u8 *g = D_00220258;
            pos = *(vu0_v4 *)(self + 0x10);
            func_00382580(&vel, 0.6f, 0.70000005f);
            q = func_L01_004713C8(&pos, &vel, 0x32, 0, func_L01_00443A18(2.0f, 3.0f), 0x7F, 0x7F, 6,
                                  func_003824E0(0.8f, 1.25f) * 210000.0f * *(f32 *)d, *(f32 *)d * 2100.0f, 0.0f);
            if (q != 0) {
                q[3] = 0x44;
                q[2] = (*(u8 **)(g + 0xD4))[0];
            }
            q = func_L01_004713C8(&pos, &vel, 0x32, 0x7C0030, func_L01_00443A18(2.0f, 3.0f), 0x30, 0x30, 0,
                                  func_003824E0(0.8f, 1.25f) * 210000.0f * 1.25f * *(f32 *)d, *(f32 *)d * 4200.0f, 0.0f);
            if (q != 0) {
                q[3] = 0x44;
                q[2] = (*(u8 **)(g + 0xD4))[0];
            }
        }
        func_L20_003EAA70(*(void **)(self + 0xB8), &D_001D66B0, self + 0x10);
        func_003C2880(self);
        return;
    }
    *(f32 *)d += 0.017f;
    if (*(f32 *)d > 1.0f) {
        *(f32 *)d = 1.0f;
    }
    sc = *(f32 *)d * 262500.0f;
    pos = *(vu0_v4 *)(self + 0x10);
    if (func_00382468(2)) {
        n = func_L01_00443A18(1.0f, -1.0f);
        e = func_L01_0046A610(&pos, &D_001D66B0, 0xC, 6, 0x7C0030, n, sc * 6.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (e != 0) {
            e[2] = (*(u8 **)(D_00220258 + 0x170))[1];
        }
    }
    vel.x = pos.x + func_L01_00443A18(0.0f, 0.04f);
    vel.y = pos.y + func_L01_00443A18(0.0f, 0.04f);
    vel.z = pos.z + func_L01_00443A18(0.0f, 0.04f);
    if (func_00382468(2)) {
        vu0_v4 *pv = &vel;
        n = func_L01_00443A18(1.0f, -1.0f);
        e = func_L01_0046A610(pv, &D_001D66B0, 0xC, 0x7F, 0x7C0030, n, sc * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
        if (e != 0) {
            e[3] = func_00382468(2) ? 0x48 : 0x44;
            e[2] = (*(u8 **)(D_00220258 + 0x170))[0];
        }
    }
    for (i = 0; i < 6; i++) {
        u8 *g = D_00220258;
        func_00382580(&v3, *(f32 *)d * 0.10000001f, *(f32 *)d * 0.14000001f);
        q = func_L01_004713C8(&pos, &v3, 0xC, 0, func_L01_00443A18(2.0f, 5.0f), 0x7F, 0x7F, 6,
                              func_003824E0(0.8f, 1.25f) * 210000.0f * *(f32 *)d, *(f32 *)d * 2100.0f, 0.00584f);
        if (q != 0) {
            q[3] = 0x44;
            q[2] = (*(u8 **)(g + 0xD4))[0];
        }
        q = func_L01_004713C8(&pos, &v3, 0xC, 0, func_L01_00443A18(2.0f, 5.0f), 0x30, 0x30, 0,
                              func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * *(f32 *)d, *(f32 *)d * 4200.0f, 0.00584f);
        if (q != 0) {
            q[3] = 0x44;
            q[2] = (*(u8 **)(g + 0xD4))[0];
        }
    }
}
/* localdecomp:end func_L20_003F9568 */
