#include "common.h"

/* NTSC-U counterpart of func_L39_00530E18 (src/levels/shared/L39_00530E18.c) */
typedef int Q_00530798 __attribute__((mode(TI)));

/* localdecomp:start func_L39_005307D0 */
#include "vu0.h"

extern void func_L39_00530798(int, Q_00530798 *);
extern void func_L39_0056F4F0(s32, void *, void *, s32, s32, s32);
extern void func_L01_00410840(void *, void *, f32, f32, u8 *);
extern f32 func_00388770(void *);
extern void func_L39_006459F8();
extern void func_L39_00594968(void *, void *, void *, void *, void *, s32, f32);
extern void func_L39_00595BA8(void *, s32);
extern f32 func_003893C8(f32, f32);
extern void func_00389018(void *, s32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L39_005BC8D0(s32, void *, s32);
extern void func_L01_003F4D78(s32, void *, u32, void *, s32, f32, f32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003894A0(f32, u32, u32);
extern f32 func_003887C8(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L07_003C9438(void *, void *, void *, s32, void *, s32, u32, f32, f32);
extern void func_L39_005F0CE0(s32, s32, void *);
extern int func_L01_003EFFE0(unsigned int, int);
extern s32 func_L39_0066B708(void *, s32, void *, s32, void *);
extern s32 func_003883C8(void *);
extern void func_L01_003E9730(s32, s32);
extern f32 func_L01_004455F0(s32, f32, s32, f32, f32, f32, s32);

typedef struct {
    u8 pad[0xA4];
    u8 fA4[4];
} G_00530E18;
extern G_00530E18 D_001A5990;
__asm__(".extern D_L39_00242AB0, 16");
extern s32 D_L39_00242AB0;
__asm__(".extern D_L39_0024AD44, 4");
extern f32 D_L39_0024AD44;
__asm__(".extern D_L39_0024AD48, 4");
extern f32 D_L39_0024AD48;
__asm__(".extern D_L39_0024AD4C, 4");
extern f32 D_L39_0024AD4C;
extern vu0_q D_L39_0024AD50_005307D0 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024AD50_005307D0, 8");
__asm__(".extern D_L39_0024AD60_005307D0, 4");
extern f32 D_L39_0024AD60_005307D0;
__asm__(".extern D_L39_0024ACEC, 4");
extern f32 D_L39_0024ACEC;
__asm__(".extern D_L39_0024AC48, 4");
extern s32 D_L39_0024AC48;

void func_L39_005307D0(u8 *a0) {
    vu0_v4 v0;
    vu0_v4 v10;
    Q_00530798 q;
    vu0_q v30;
    vu0_q v40;
    s32 m;
    u8 *vars = *(u8 **)(a0 + 0x68);
    u8 *cam = *(u8 **)(vars + 0x6D0);
    u8 *pl = *(u8 **)(cam + 0x2DC);
    f32 t;
    f32 fov;
    f32 scale;
    f32 pitch;
    f32 yaw;
    void *tgt;
    f32 a;
    f32 r;
    f32 d;
    s32 col;

    if (pl[0x1A14] != 0 && *(f32 *)(cam + 0x308) > 0.0f && a0[0xBC] != 10 && a0[0xBC] != 11 &&
        a0[0xBC] != 7 && a0[0xBC] != 8) {
        if (*(s32 *)(vars + 0x72C) == -1 || *(s32 *)(vars + 0x72C) == 99) {
            if (*(f32 *)(vars + 0x724) == -999.0f) {
                *(f32 *)(vars + 0x724) = *(f32 *)(a0 + 0xF8);
            }
            *(f32 *)(cam + 0x220) = 0.0f;
            *(f32 *)(cam + 0x224) = *(f32 *)(vars + 0x728);
            *(f32 *)(cam + 0x228) = *(f32 *)(vars + 0x724);
            *(vu0_q *)(cam + 0x210) = *(vu0_q *)(cam + 0x220);
            *(s32 *)(vars + 0x72C) = pl[0x24C9];
            func_L39_0056F4F0(pl[0x24C9], *(u8 **)(pl + 0x2530), *(u8 **)(pl + 0x2530) + 0x10, 3, 60, 0);
            *(s32 *)(vars + 0x730) = 0;
            func_L39_00530798((int)a0, &q);
            func_L01_00410840(vars + 0x70, &q, *(f32 *)(a0 + 0xF8), 0.0f, a0);
            *(s16 *)(vars + 0x150) = 1;
            if (D_001A5990.fA4[*(s32 *)(pl + 0x2544)] != 2) {
                *(s16 *)(vars + 0x150) = 9;
            }
            pitch = D_L39_0024AD48 * 0.017453292f;
            yaw = D_L39_0024AD44 * 0.017453292f;
            *(f32 *)(vars + 0x190) = 75.0f;
            *(f32 *)(vars + 0x124) = pitch;
            *(f32 *)(vars + 0x128) = yaw;
            fov = func_00388770(&D_L39_0024AD50_005307D0);
            scale = D_L39_0024AD60_005307D0;
            *(f32 *)(vars + 0x194) = fov;
            *(f32 *)(vars + 0xD8) *= scale;
            *(f32 *)(vars + 0xB8) *= scale;
            *(f32 *)(vars + 0xBC) *= scale;
            *(s16 *)(vars + 0x152) = *(u16 *)(pl + 0x1282);
            *(void **)(vars + 0x154) = func_L39_006459F8;
            *(s32 *)(vars + 0x19C) = pl[0x24C9];
            *(s32 *)(vars + 0x1A8) = *(s32 *)(pl + 0x2544);
            *(u8 **)(vars + 0x1A0) = pl;
            *(vu0_q *)(vars + 0x130) = D_L39_0024AD50_005307D0;
            *(vu0_q *)(vars + 0x140) = *(vu0_q *)&D_L39_00242AB0;
            *(f32 *)(vars + 0x144) = D_L39_0024AD4C * 0.017453292f;
            return;
        }
        func_L39_00530798((int)a0, &q);
        func_L39_00594968(vars + 0x70, *(void **)(pl + 0x2534), &q, vars + 0x620, &q,
                          D_001A5990.fA4[*(s32 *)(pl + 0x2544)] == 2 ? 2 : -1, 1.0f);
        t = 0.0f;
        func_L39_00595BA8(vars + 0x70, *(s32 *)(vars + 0x72C));
        *(f32 *)(vars + 0x724) = *(f32 *)(vars + 0xB0);
        *(f32 *)(vars + 0x728) = *(f32 *)(vars + 0xD0);
        r = func_003893C8(*(f32 *)(vars + 0x724), *(f32 *)(a0 + 0xF8));
        func_00389018(vars + 0x570, 2, r);
        func_00389018(vars + 0x5B0, 1, *(f32 *)(vars + 0x728));
        *(vu0_q *)(vars + 0x5F0) = *(vu0_q *)(vars + 0x5B0);
        func_003BDA38(a0, cam[0x2FF] ? 0x12 : 0x11, &v0);
        if (*(f32 *)(vars + 0x120) >= 0.85f) {
            t = (*(f32 *)(vars + 0x120) - 0.85f) / (1.0f - 0.85f);
        }
        if (t != 0.0f) {
            func_L39_005BC8D0(*(s32 *)(vars + 0xFC), &v30, 0);
            if (pl[0x1A14] != 0) {
                func_L01_003F4D78(pl[0x24C9], a0, 0x800F0FFF, 0, 0x21, 0.7f, 0.0f, -1, 4, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
            col = func_003894A0(t, 0xFF0FFFFF, 0xFF0F0FFF);
            d = func_003887C8(&v0, &v30);
            a = fabs_asm(0.9f - d * 0.65f / 150.0f);
            tgt = *(void **)(cam + 0x2D0);
            if (pl[0x1A14] != 0) {
                func_L01_003F4D78(pl[0x24C9], tgt, col, &v30, 0x26, a, 0.0f, -1, 4, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
            func_003886E8(&v40, vars + 0x110, d / 1.50000011921f * t);
            vec_add_ba(&v30, &v30, &v40);
            vec_sub_ab(&v10, &v30, &v0);
        } else {
            if (pl[0x1A14] != 0) {
                func_L01_003F4D78(pl[0x24C9], a0, 0x800FFF0F, 0, 0x21, 0.7f, 0.0f, -1, 4, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            }
            vec_sub_ab(&v10, vars + 0x180, &v0);
        }
        if (func_00388730(&v10, vars + 0x70) > 0.0f) {
            func_00388830(&v10, &v10, 1.50000011921f);
        } else {
            func_00388830(&v10, vars + 0x70, 1.50000011921f);
        }
        if (*(s16 *)(pl + 0x320) == 0 && (*(s32 *)(*(u8 **)(pl + 0x2534) + 0x1A0) & 0x28) &&
            *(s16 *)(vars + 0x716) <= 0) {
            u8 *m2;
            s32 idx;
            idx = *(s32 *)(pl + 0x2544);
            m = 0x80000000;
            m2 = func_L07_003C9438(&v0, &v10, a0, 1, &m, idx, 0xFFFFFFFF, 4.0f, D_L39_0024ACEC);
            func_L39_005F0CE0(3, 0, a0);
            func_L01_003EFFE0(D_L39_0024AC48, *(s32 *)(pl + 0x2534));
            if (m2 != 0) {
                s32 r = func_L39_0066B708(pl, 7, m2, *(s32 *)(vars + 0xFC), &v10);
                *(s32 *)(*(u8 **)(m2 + 0x68) + 0x44) = r;
                *(s32 *)(*(u8 **)(m2 + 0x68) + 0x24) = 60;
                *(f32 *)(*(u8 **)(m2 + 0x68) + 0x28) = 0.016666668f;
                cam[0x2FF] ^= 1;
                *(s16 *)(vars + 0x716) = 10;
            }
        }
        func_003883C8(vars + 0x716);
        *(f32 *)(cam + 0x214) = *(f32 *)(vars + 0x728);
        *(f32 *)(cam + 0x218) = *(f32 *)(vars + 0x724);
        return;
    }
    if (*(s32 *)(vars + 0x72C) == -1) {
        if (*(f32 *)(vars + 0x724) == -999.0f) {
            *(f32 *)(vars + 0x724) = *(f32 *)(a0 + 0xF8);
        }
        *(f32 *)(cam + 0x220) = 0.0f;
        *(f32 *)(cam + 0x224) = *(f32 *)(vars + 0x728);
        *(f32 *)(cam + 0x228) = *(f32 *)(vars + 0x724);
        *(s32 *)(vars + 0x72C) = 99;
        *(s32 *)(vars + 0x730) = 0;
        return;
    }
    if (*(s32 *)(vars + 0x72C) != 99 && a0[0xBC] == 9) {
        func_L39_00530798((int)a0, &q);
        *(s32 *)(*(u8 **)(pl + 0x2534) + 0x108) = 0;
        *(s32 *)(*(u8 **)(pl + 0x2534) + 0x10C) = 0;
        *(s32 *)(*(u8 **)(pl + 0x2534) + 0x100) = 0;
        *(s32 *)(*(u8 **)(pl + 0x2534) + 0x104) = 0;
        func_L39_00594968(vars + 0x70, *(void **)(pl + 0x2534), &q, vars + 0x620, &q, -1, 1.0f);
        func_L39_00595BA8(vars + 0x70, *(s32 *)(vars + 0x72C));
    }
    if (a0[0xBC] == 11 && *(s32 *)(vars + 0x72C) != 99) {
        func_L01_003E9730(*(s32 *)(vars + 0x72C), 0);
    }
    func_L01_004455F0((s32)(vars + 0x724), *(f32 *)(cam + 0x228), (s32)(vars + 0x740), 0.0145444106311f,
                      0.00242406851612f, 0.0872664675117f, 0);
    func_L01_004455F0((s32)(vars + 0x728), *(f32 *)(cam + 0x224), (s32)(vars + 0x744), 0.0145444106311f,
                      0.00242406851612f, 0.0581776462495f, 0);
    r = func_003893C8(*(f32 *)(vars + 0x724), *(f32 *)(a0 + 0xF8));
    func_00389018(vars + 0x570, 2, r);
    func_00389018(vars + 0x5B0, 1, *(f32 *)(vars + 0x728));
    *(vu0_q *)(vars + 0x5F0) = *(vu0_q *)(vars + 0x5B0);
}
/* localdecomp:end func_L39_005307D0 */
