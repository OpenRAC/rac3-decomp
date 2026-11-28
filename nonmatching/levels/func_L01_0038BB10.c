/* func_L01_0038BB10 (Claude wave 14 r68, 2026-11-28). Replaces the earlier draft of this function (W8b revised draft). */
/* wave 14 r68 (2026-11-28): from the W8b draft (820 raw), 789 raw with the file's line. Changes: frame now 0x110 like retail, because func_L01_00470C78 takes 12 arguments (10 int + 2 float: retail stores only two stack words; the draft passed two extra zeros) and the third burst loop adds each random offset as it is drawn (retail never keeps r1-r3 in callee-saved float registers); locals declared a, b, c, hit (retail slots 0x10/0x20/0x30/0x40); the camera at 0x1E2A40 as a struct alias (base + field offsets, as retail); vec_sub_ba for the camera - pos vector (retail loads pos first); the two five-pass loops as for (i = 4; i >= 0; i--) (retail bgez); i = (n < 11) ? n : 10 (retail slti/movn); pos assigned at the start of each state, not at the top. Still differs: register allocation (self s3 / inner s4 here, s2 / s3 in retail; &a spilled where retail keeps it in s7), D_L01_001D66B0 is CSE'd into a saved register where retail rematerialises its address at every call (the .sdata form gives retail's per-call la but 851), and the list loops (retail re-reads *list; that form alone is 838 here). */
#include "common.h"

/* localdecomp:start func_L01_0038BB10 */
#include "vu0.h"
typedef union { f32 f[4]; vu0_q q; } V_VH;
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern u8 D_001425C0[];
typedef struct {
    f32 x, y, z, w;
    u8 pad10[0x10];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
    u8 pad30[0x10];
    f32 f40;
    u8 pad44[4];
    s32 w48;
} Cam_0038BB10;
extern Cam_0038BB10 D_L01_001E2A40_0038BB10;
extern u8 D_L01_001E2880[];
extern u8 *D_L01_001EEA80[];
extern u8 D_L01_00221098[];
extern u8 D_L01_002B3D60[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_00290820[];
extern u8 D_L01_001D66B0[];
extern s32 D_L01_001E1F1C;
extern f32 D_001DDF30_sda, D_001DDF34_sda, D_001DDF38_sda, D_001DDF44_sda, D_001DDF48_sda;
extern s32 D_001DDF4C_sda;
__asm__(".extern D_001DDF30_sda, 4");
__asm__(".extern D_001DDF34_sda, 4");
__asm__(".extern D_001DDF38_sda, 4");
__asm__(".extern D_001DDF44_sda, 4");
__asm__(".extern D_001DDF48_sda, 4");
__asm__(".extern D_001DDF4C_sda, 4");
extern s32 func_L01_004CB2D8(u8 *);
extern void func_L01_004CAB30(void *, void *);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_00404A10(void (*)(u8 *), u8 *);
extern void func_L01_00404808(void (*)(u8 *), u8 *);
extern void func_L01_00404AD8(void (*)(u8 *), u8 *);
extern void func_L01_0038CC38(u8 *);
extern void func_L01_0038D5C0(u8 *);
extern void func_L01_0038DF00(u8 *);
extern void func_L01_0038D138(u8 *);
extern void func_L01_0038D108(u8 *);
extern void func_L01_0038CDC8(u8 *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern void func_L01_00474680(void *, void *, s32, u32, u32, s32, s32, f32, f32, f32, f32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, u32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78(void *, s32, u32, s32, s32, void *, s32, s32, s32, s32, f32, f32);
extern void func_L01_0038E968(u8 *);
extern f32 func_0038CEA8(void *);
extern s32 func_L01_003F2058(void *, s32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_003298C8(void *, void *, s32, s32, s32, u32, s32, s32, s32, s32, f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_003D4D00(void *, s32, u8 *, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_00382348(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0035E638(u8 *, void *, void *, s32, f32);
extern f32 func_00382538(void);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00446760(void *, u8 *, u32, void *, f32);
extern void func_L01_00446978(u8 *, void *);
extern void func_L01_0031B090(u8 *, s32, s32);
extern void func_003C2880(u8 *);
typedef struct {
    u8 pad[0x24];
    s32 timer;
    f32 scale;
    s32 damage_timer;
    s32 alpha;
    u8 gap[4];
    s32 effect;
    s32 intro_timer;
} Effect_38BB10;
extern void func_L01_004C7D98(void *, void *);
void func_L01_0038BB10(u8 *self) {
    V_VH a, b, c;
    u8 hit[0x30] __attribute__((aligned(16)));
    Effect_38BB10 *inner = *(Effect_38BB10 **)(self + 0x68);
    u8 *pos;
    s32 i, n, k, life, ri;
    f32 heading, r1, r2, r3, ang, scl, dist;
    u8 *p;
    if (func_L01_004CB2D8(self)) func_L01_004CAB30(self + 0x10, self + 0x10);
    if (func_0038CAD0(&inner->intro_timer) == 0) {
        if (inner->intro_timer >= 0xD) {
            D_001DDF44_sda += 0.8f;
            D_001DDF48_sda += 0.4f;
        } else {
            D_001DDF44_sda -= 0.5f;
            D_001DDF48_sda -= 0.3f;
        }
        func_L01_00404A10(func_L01_0038CC38, self);
    }
    if (self[0x20] == 0) {
        func_0038CAD0(&inner->timer);
        inner->scale -= 0.1f;
        if (inner->timer >= 0x4C) {
            func_L01_00404808(func_L01_0038D5C0, self);
            return;
        }
        func_L01_00404808(func_L01_0038DF00, self);
        pos = self + 0x10;
        heading = func_0038D160(D_L01_001E2A40_0038BB10.x - *(f32 *)(self + 0x10),
                                D_L01_001E2A40_0038BB10.y - *(f32 *)(self + 0x14));
        for (i = 0; i < 0x31 + 1; ++i) {
            r1 = func_0038DAB8(heading, func_L01_00443A18(0.0f, 2.268928050994873f));
            *(f32 *)&a = func_0038D098(r1) * (func_003824E0(18.0f, 27.0f) * 0.020000001415610313f);
            *((f32 *)&a + 1) = func_0038D0B0(r1) * (func_003824E0(18.0f, 27.0f) * 0.020000001415610313f);
            *((f32 *)&a + 2) = func_003824E0(0.0f, 14.0f) * 0.020000001415610313f;
            scl = func_003824E0(0.8f, 1.2f);
            k = func_00382498(25, 35);
            func_L01_00474680(pos, &a, 0x19, 0x3F8080FF, 0x8080FF, (k * 5 + 2) / 6, 0,
                              0.04f, scl, 2.7f, 2.5f);
        }
        func_L01_0046B458(pos, 0x1C, 21.0f, 0.1f, 0xBF204080, 2, 1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(pos, 0x1C, 15.0f, 0.1f, 0xBF2040A0, 2, -1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(pos, 0x1C, 10.5f, 0.1f, 0xC0FFFFFF, 2, 1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(pos, 0x1C, 7.5f, 0.1f, 0xB0FFFFFF, 2, -1, D_L01_001D66B0, 0.0f, 1);
        func_L01_00470C78(pos, 0x21, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1, 3.6f, 2.8f);
        func_L01_00470C78(pos, 0x21, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1, 6.8f, 2.8f);
        func_L01_00470C78(pos, 0x21, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1, 8.0f, 6.0f);
        func_L01_0038E968(self);
        vec_sub_ba(&a, &D_L01_001E2A40_0038BB10, pos);
        k = (s32)(30.0f - func_0038CEA8(&a));
        D_001DDF4C_sda = k;
        if (k >= 0x1F) D_001DDF4C_sda = 0x1E;
        else if (k < 0xF) D_001DDF4C_sda = 0xF;
        inner->effect = func_L01_003F2058(D_L01_002B3D60, 0);
        D_L01_001E2A40_0038BB10.f20 = 0.4f;
        D_L01_001E2A40_0038BB10.f40 = 0.15f;
        D_L01_001E2A40_0038BB10.w48 = 0x15;
        D_L01_001E2A40_0038BB10.w2C = 0;
        D_L01_001E2A40_0038BB10.w28 = 0x15;
        for (i = 4; i >= 0; i--) {
            r2 = func_003824E0(0.08726646f, 0.5235988f);
            r1 = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
            func_00382760(&b, func_003824E0(8.0f, 15.0f) * 0.020000001415610313f, r1, r2);
            k = func_00382498(0x53, 0x6C);
            func_L01_003298C8(pos, &b, k, 3, 1, 0x80204080, 0, 1, 0x32, 0x78, 3.0f, 14.6f);
        }
        for (i = 4; i >= 0; i--) {
            f32 sz, sp;
            ri = (s32)func_L01_00443A18(2.0f, 6.0f);
            *(f32 *)&b = *(f32 *)(self + 0x10) + func_003824E0(-0.2f, 0.2f);
            *((f32 *)&b + 1) = *(f32 *)(self + 0x14) + func_003824E0(-0.2f, 0.2f);
            *((f32 *)&b + 2) = *(f32 *)(self + 0x18) + func_003824E0(-0.2f, 0.2f);
            sz = func_003824E0(0.15f, 0.2f);
            sp = func_003824E0(7.0f, 10.0f) * 0.020000001415610313f;
            ang = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.3962634f));
            *(f32 *)&c = func_0038D098(ang) * sp;
            *((f32 *)&c + 1) = func_0038D0B0(ang) * sp;
            *((f32 *)&c + 2) = 0.0f;
            *((f32 *)&c + 2) = func_003824E0(0.0f, 12.0f) * 0.020000001415610313f;
            life = (func_00382498(0x5A, 0x96) * 5 + 2) / 6;
            sz *= 210000.0f;
            p = func_L01_004713C8(&b, &c, life, 0x273538, ri, 0x7F, 0x7F, 1, sz, sz, 0.00584f);
            if (p != 0) {
                k = func_00382468(3);
                p[2] = *(u8 *)(*(s32 *)(D_L01_00221098 + 0x184) + k + 0xA);
                p[3] = 0x44;
            }
        }
        n = func_003D4D00(pos, 0, self, 0, 13.0f);
        i = (n < 11) ? n : 10;
        if (i > 0) {
            u8 **list = D_L01_001EEA80;
            s32 budget = 10;
            n = i;
            for (; n != 0; n--, list++) {
                u8 *m = *list;
                if (func_00382348(m) == 0 && (*(u16 *)(m + 0x34) & 0x4000) == 0) continue;
                if (m == (u8 *)D_001A4BE0.hero_moby) continue;
                dist = func_0038CF00(pos, m + 0x10);
                if (!(8.0f < dist)) continue;
                vec_sub_ab(&b, m + 0x10, pos);
                budget--;
                func_0038CF68(&b, &b, func_003824E0(20.0f, 30.0f) * 0.020000001415610313f);
                func_L01_0035E638(self, pos, &b, 0x10000, 10.0f);
            }
            k = budget + 5;
        } else {
            k = 10 + 5;
        }
        if (k > 0) {
            do {
                r2 = func_003824E0(-0.3490658402442932f, 0.2617994f);
                ang = func_00382538();
                func_00382760(&b, func_003824E0(20.0f, 30.0f) * 0.020000001415610313f, ang, r2);
                func_L01_0035E638(self, pos, &b, 0x10000, 10.0f);
            } while (--k != 0);
        }
        self[0x20] = 1;
        return;
    }
    if (self[0x20] == 1) {
        func_0038CAD0(&inner->timer);
        if (inner->timer < 0x49) {
            self[0x20] = 2;
            return;
        }
        func_L01_00404808(func_L01_0038D138, self);
        pos = self + 0x10;
        for (i = 0; i < 0x63 + 1; ++i) {
            heading = func_0038D160(*(f32 *)((u8 *)&D_001A4BE0 + 0x80) - *(f32 *)(D_L01_001E2880 + 0x140),
                                    *(f32 *)((u8 *)&D_001A4BE0 + 0x84) - *(f32 *)(D_L01_001E2880 + 0x144));
            func_L01_00443A18(1.0f, 2.0f);
            func_L01_004C7D98(pos, &b);
            func_0038CF68(&b, &b, 0.3f);
            vec_add_ab(&a, (u8 *)inner + 0x10, &b);
            ang = func_0038DAB8(heading, func_L01_00443A18(0.0f, -6.2831855f));
            *(f32 *)&c = func_0038D098(ang) * 0.3f;
            *((f32 *)&c + 1) = func_0038D0B0(ang) * 0.3f;
            *((f32 *)&c + 2) = 0.0f;
            life = (func_00382498(0x14, 0x28) * 5 + 2) / 6;
            ri = func_00382498(-2, -4);
            p = func_L01_004713C8(&a, &c, life, 0x4080FF, ri, 0x70, 0, 0, 168000.0f, 252000.015625f, 0.0f);
            if (p != 0) p[2] = **(u8 **)(D_L01_00221098 + 0x5C);
        }
        return;
    }
    if (self[0x20] == 2) {
        pos = self + 0x10;
        inner->scale += 0.5f;
        D_001DDF34_sda += 0.5f;
        D_001DDF38_sda += 0.7f;
        if (1.6f < inner->scale) inner->scale = 1.6f;
        if (func_0038CAD0(&inner->damage_timer) != 0) {
            self[0x20] = 3;
            return;
        }
        a.q = ((V_VH *)pos)->q;
        *((f32 *)&a + 3) = 2.0f;
        if (func_0038DC20(&a, 100.0f) != -1) {
            if (func_0038CAD0(&D_L01_001E1F1C) == 0) func_L01_00404AD8(func_L01_0038CDC8, self);
            D_001DDF30_sda += 0.8f;
            inner->alpha -= 4;
            if (inner->alpha < 0) inner->alpha = 0;
            func_L01_00404808(func_L01_0038D108, self);
            func_L01_00404808(func_L01_0038DF00, self);
        }
        n = func_003D4D00(pos, 0, self, 0,
                          (1.0f - (f32)inner->damage_timer / 25.0f) * 8.0f + 3.0f);
        if (n > 0) {
            u8 **list = D_L01_001EEA80;
            for (; n != 0; n--, list++) {
                u8 *m = *list;
                s16 cls;
                if (func_00382348(m) == 0 && (*(u16 *)(m + 0x34) & 0x4000) == 0) continue;
                cls = *(s16 *)(m + 0xAA);
                if (m == (u8 *)D_001A4BE0.hero_moby && cls != 0x1068) continue;
                if (cls == 0xA5A) continue;
                vec_sub_ba(&b, m + 0x10, pos);
                func_0038CF68(&b, &b, 1.5f);
                func_0038CF68(hit, hit, 2.0f);
                func_L01_00446760(hit, self, 0x1030000, &b,
                                  *(f32 *)(D_L01_002C5600 + D_001425C0[0x77] * 0xF0 + 0x6C));
                ((V_VH *)hit)->q = b.q;
                hit[0x18] = 5;
                *(f32 *)(hit + 0x0C) = 5627.9248046875f;
                *(s32 *)(hit + 0x20) = 1;
                hit[0x19] = 3;
                *(u16 *)(hit + 0x1A) = *(u16 *)(m + 0xAA);
                func_L01_00446978(m, hit);
                func_L01_0031B090(m, 0x77, *(s32 *)(self + 0xB8));
            }
        }
        return;
    }
    if (self[0x20] == 3) {
        u8 *q;
        for (q = D_L01_00290820; q < D_L01_00290820 + 0xB40; q += 0x60) {
            if (*(u8 **)(q + 0x30) == self) *(s32 *)(q + 0x30) = 0;
        }
        func_003C2880(self);
    }
}
/* localdecomp:end func_L01_0038BB10 */
