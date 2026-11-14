#include "common.h"

typedef struct {
    u8 b[16];
} B_003F3C60;
typedef struct {
    u8 pad[0x88];
    s32 tbl[1];
} T_003F3C60;

INCLUDE_ASM("asm/levels", func_L40_003F2E88);

/* localdecomp:start func_L40_003F3828 */
#include "vu0.h"

typedef struct {
    f32 x, y;
} F2_003F3828;
typedef struct {
    u8 pad0[0x14];
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    f32 f20;
    u8 pad24[0x30 - 0x24];
    s32 w30;
    f32 f34;
    s32 w38;
} S_003F3828;

extern s32 D_L40_00264E00 __attribute__((section(".data")));
extern vu0_v4 D_L40_00249F40;
extern vu0_v4 D_001DE050_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DE050_sda, 8");
extern f32 D_001DE074_sda;
extern F2_003F3828 D_L40_00249770[2] __attribute__((section(".sdata")));
extern F2_003F3828 D_L40_00246ED0[2] __attribute__((section(".sdata")));
extern f32 D_L40_00249780;
extern f32 D_L40_00249784;
extern f32 *D_L40_00243264;
extern s32 D_L40_0024112C;
extern f32 D_L40_0024119C;
extern f32 D_001DB7B0_sda[2] __attribute__((section(".sdata")));
__asm__(".extern D_001DB7B0_sda, 8");
extern F2_003F3828 D_001DB7C0_sda[2] __attribute__((section(".sdata")));
__asm__(".extern D_001DB7C0_sda, 8");
extern void func_L40_003F2E88();
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00404808(void *, void *);

void func_L40_003F3828(u8 *m) {
    S_003F3828 *s;
    vu0_v4 d;
    vu0_v4 v;
    f32 *a;
    f32 *b;
    s32 i;
    f32 t;

    s = *(S_003F3828 **)(m + 0x68);
    if (D_L40_00264E00 != s->w30) {
        return;
    }
    if (m[0x20] == 0) {
        m[0x20] = 1;
        m[0x30] = 0xFF;
        for (i = 0; i < 2; i++) {
            D_L40_00249770[i].x = 0.0f;
            D_L40_00249770[i].y = 0.0f;
        }
        D_001DE050_sda = D_L40_00249F40;
        D_001DE074_sda = s->f14;
        return;
    }
    t = s->f14;
    vec_sub_ab(&d, &D_L40_00249F40, &D_001DE050_sda);
    D_001DE050_sda = D_L40_00249F40;
    D_001DE074_sda = t;
    if (!(s->f20 < D_L40_00249F40.z)) {
        return;
    }
    b = &D_L40_00249770[0].y;
    a = &D_L40_00249770[0].x;
    for (i = 0; i < 2; i++) {
        func_0038CE20(&v, &d, (D_001DB7B0_sda[i] + D_001DB7B0_sda[i]) / (s->f18 * 5.0f));
        if (v.x > 1.0f || v.x < 1.0f) {
            v.x = v.x - (f32)(s32)v.x;
        }
        if (v.y > 1.0f || v.y < 1.0f) {
            v.y = v.y - (f32)(s32)v.y;
        }
        a[i * 2] += v.x;
        b[i * 2] += v.y;
        if (a[i * 2] > 1.0f) {
            a[i * 2] -= 1.0f;
        }
        if (a[i * 2] < -1.0f) {
            a[i * 2] += 1.0f;
        }
        if (b[i * 2] > 1.0f) {
            b[i * 2] -= 1.0f;
        }
        if (b[i * 2] < -1.0f) {
            b[i * 2] += 1.0f;
        }
    }
    t = func_0038D0B0((f32)(D_L40_0024112C % 360) * 0.017444445f - 3.14f);
    D_L40_00243264 = &D_L40_00249780;
    D_L40_00249780 = D_L40_00249784 + t * s->f34;
    for (i = 0; i < 2; i++) {
        D_L40_00249770[i].x += D_001DB7C0_sda[i].x * D_L40_0024119C;
        if (D_L40_00249770[i].x > 1.0f) {
            D_L40_00249770[i].x -= 1.0f;
        }
        if (D_L40_00249770[i].x < -1.0f) {
            D_L40_00249770[i].x += 1.0f;
        }
        D_L40_00249770[i].y += D_L40_00246ED0[i].y * D_L40_0024119C;
        if (D_L40_00249770[i].y > 1.0f) {
            D_L40_00249770[i].y -= 1.0f;
        }
        if (D_L40_00249770[i].y < -1.0f) {
            D_L40_00249770[i].y += 1.0f;
        }
    }
    if (s->w38 != 0) {
        func_L01_004048D0(func_L40_003F2E88, m);
    } else {
        func_L01_00404808(func_L40_003F2E88, m);
    }
}
/* localdecomp:end func_L40_003F3828 */

/* localdecomp:start func_L40_003F3C60 */
#include "vu0.h"


extern s32 D_001A5DF8[];
extern s32 D_L40_0024112C;
extern T_003F3C60 *D_L40_0035746C __attribute__((section(".data")));
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, s32, s32, s32, u8 *);
extern f32 func_L39_005B44C8(void);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L40_0053E1A8(void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_L40_0053E760(s32, void *, s32, s32);

void func_L40_003F3C60(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 uid = **(s32 **)(m + 0x90);
    s32 st;
    u8 *p;
    u8 *q;
    s32 tg;
    vu0_v4 buf;

    if (*(s32 *)(v + 0x2A4) == 0) {
        *(s32 *)(v + 0x2A4) = 1;
    }
    st = *(s32 *)(v + 0x2A4);
    switch (st) {
    case 1: {
        if (++*(s32 *)(v + 0x2A8) >= 0xA8) {
            f32 zero = 0.0f;
            f32 ang;
            f32 r;
            *(s32 *)(v + 0x2A8) = 0;
            ang = func_L39_005B44C8();
            r = func_L39_005B4410(zero, 3.0f);
            buf.x = func_0038D098(ang) * r;
            buf.y = func_0038D0B0(ang) * r;
            buf.z = zero;
            vec_add_ab(v + 0x220, v + 0x1F0, &buf);
            p = func_L39_0066C2B8();
            if (p == 0) {
                return;
            }
            q = p + func_L39_0066C280(1, uid, D_001A5DF8[0] + 0x1F4, 0, p);
            *(B_003F3C60 *)q = *(B_003F3C60 *)(v + 0x220);
            q += 0x10;
            *(s32 *)p = q - p;
        }
        *(s32 *)(v + 0x2C0) = func_L40_0053E1A8(m, D_L40_0035746C->tbl[*(s32 *)(v + 0x2AC)], 0, 0, 28.0f, -1.0f, 3.0f);
        if (*(s32 *)(v + 0x2C0) == -1) {
            return;
        }
        p = func_L39_0066C2B8();
        if (p == 0) {
            return;
        }
        q = p + func_L39_0066C280(1, uid, D_001A5DF8[0] + 0x1F4, 1, p);
        *(s32 *)q = *(s32 *)(v + 0x2C0);
        q += 4;
        *(s32 *)p = q - p;
        *(s32 *)(v + 0x2A4) = 4;
        break;
    }
    case 4:
        if (func_L40_0053E760(*(s32 *)(v + 0x2C0), &buf, -1, 0) == 0 &&
            (D_L40_0024112C & 0x3F) == (((s32)m >> 8) & 0x3F)) {
            tg = func_L40_0053E1A8(m, D_L40_0035746C->tbl[*(s32 *)(v + 0x2AC)], 0, 0, 28.0f, -1.0f, 3.0f);
            *(s32 *)(v + 0x2C0) = tg;
            if (tg != -1) {
                p = func_L39_0066C2B8();
                if (p == 0) {
                    return;
                }
                q = p + func_L39_0066C280(1, uid, D_001A5DF8[0] + 0x1F4, 1, p);
                *(s32 *)q = *(s32 *)(v + 0x2C0);
                q += 4;
                *(s32 *)p = q - p;
                *(s32 *)(v + 0x2A4) = st;
            } else {
                p = func_L39_0066C2B8();
                if (p == 0) {
                    return;
                }
                *(s32 *)p = func_L39_0066C280(1, uid, D_001A5DF8[0] + 0x1F4, 2, p);
                *(s32 *)(v + 0x2A4) = 1;
            }
            return;
        }
        if (m[0x20] == 4 && func_L01_0044E1B8(m, 14.0f) != 0) {
            p = func_L39_0066C2B8();
            if (p == 0) {
                return;
            }
            *(s32 *)p = func_L39_0066C280(1, uid, D_001A5DF8[0] + 0x1F4, 2, p);
            *(s32 *)(v + 0x2A4) = 10;
            return;
        }
        if (func_0038CF38(&buf, v + 0x1F0) > 35.0f) {
            p = func_L39_0066C2B8();
            if (p == 0) {
                return;
            }
            tg = func_L39_0066C280(1, uid, D_001A5DF8[0] + 0x1F4, 2, p);
            *(s32 *)(v + 0x2A4) = 10;
            *(s32 *)p = tg;
        }
        break;
    case 10:
        if (*(s32 *)(v + 0x2C4) >= 0xA8) {
            *(s32 *)(v + 0x2C4) = 0;
            *(s32 *)(v + 0x2A4) = 1;
        } else {
            *(s32 *)(v + 0x2C4) = *(s32 *)(v + 0x2C4) + 1;
        }
        break;
    }
}
/* localdecomp:end func_L40_003F3C60 */

INCLUDE_ASM("asm/levels", func_L40_003F4080);
