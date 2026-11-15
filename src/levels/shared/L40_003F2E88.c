#include "common.h"

typedef struct {
    u8 b[16];
} B_003F3C60;
typedef struct {
    u8 pad[0x88];
    s32 tbl[1];
} T_003F3C60;

typedef struct N_003F4080 {
    u8 p0[8];
    s32 type;
    s32 wC;
    s32 time;
    s32 w14;
    s32 data[4];
    u8 p28[0x84 - 0x28];
    struct N_003F4080 *next;
} N_003F4080;
typedef struct { s32 w[4]; } B_003F4080;
typedef struct { u8 pad[0x128]; s32 w128; } G_003F4080;
typedef struct { f32 x, y, z, w; } V_003F4080;
typedef struct { u8 p0[0xD0]; u8 on; u8 pD1[0xDC - 0xD1]; u8 *owner; } S_1FE020;
typedef struct { u8 b[0x80]; } R_1FE020;

/* localdecomp:start func_L40_003F2E88 */
#include "vu0.h"

typedef struct {
    s32 c0;
    s32 c4;
    u8 pad08[4];
    s32 cC;
    s32 c10;
    u8 pad14[4];
    f32 f18;
    s32 tex1C;
    u8 pad20[8];
    f32 f28;
    u8 pad2C[0x38 - 0x2C];
    s32 w38;
} S_003F2E88;
typedef struct {
    u8 pad[0x238];
    f32 f238;
    f32 f23C;
} R_003F2E88;
typedef struct {
    u8 pad[0x140];
    vu0_v4 pos;
    u8 pad150[0x10];
    f32 mtx[4][4];
} C_003F2E88;
typedef struct {
    f32 x, y, z;
} P_003F2E88;
typedef struct {
    f32 u, v;
} T_003F2E88;
typedef struct {
    vu0_v4 v[4];
    s32 col[4];
    f32 uv[4][2];
    long f70, f78, f80, f88;
} Q_003F2E88;

extern R_003F2E88 D_L40_00259900;
extern C_003F2E88 D_L40_00249E00;
__asm__(".extern D_L40_002412DC, 16");
extern s32 D_L40_002412DC;
extern P_003F2E88 D_L40_0038E9E0[];
extern s32 D_L40_0038ECE0[];
extern T_003F2E88 D_L40_0038F1E0[];
extern P_003F2E88 D_L40_0038EDE0[];
extern s32 D_L40_0038F0E0[];
extern T_003F2E88 D_L40_0038F3E0[];
typedef struct {
    f32 x, y;
} F2_003F2E88;
extern F2_003F2E88 D_L40_00249770_003F2E88[2] __attribute__((section(".sdata")));
extern f32 D_L40_00249780;
extern f32 D_001DB7B0_sda[2] __attribute__((section(".sdata")));
__asm__(".extern D_001DB7B0_sda, 8");
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_L39_00589890(s32);
extern void func_0038C750(void);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern f32 func_0038CED8(void *);

void func_L40_003F2E88(u8 *m) {
    S_003F2E88 *s;
    vu0_v4 t0;
    vu0_v4 t1;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 v[4];
    vu0_v4 d0;
    vu0_v4 d1;
    Q_003F2E88 q;
    f32 save238;
    f32 save23C;
    s32 i;
    s32 j;
    s32 n;
    s32 col;
    s32 c0;
    s32 c1;
    f32 f;
    f32 x;
    f32 y;

    s = *(S_003F2E88 **)(m + 0x68);
    save238 = D_L40_00259900.f238;
    save23C = D_L40_00259900.f23C;
    func_003A9440(0x42, 0x3200000044UL);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    if (s->w38 != 0) {
        func_003A9440(0x47, 0x5310B);
    } else {
        func_003A9440(0x47, 0x513F1);
    }
    func_003A9440(6, func_L39_00589890(0x16));
    func_0038C750();
    a.x = 1.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    a.w = 1.0f;
    func_0038D000(&a, &a, D_L40_00249E00.mtx);
    b.x = 0.0f;
    b.y = 1.0f;
    b.z = 0.0f;
    b.w = 1.0f;
    func_0038D000(&b, &b, D_L40_00249E00.mtx);
    c.x = 0.0f;
    c.y = 0.0f;
    c.z = 1.0f;
    c.w = 1.0f;
    func_0038D000(&c, &c, D_L40_00249E00.mtx);
    if (fabs_asm(c.z) < fabs_asm(b.z)) {
        b = c;
    }
    if (D_L40_002412DC != 13) {
        a.z = 0.0f;
    }
    func_0038CF68(&a, &a, 1.0f);
    if (D_L40_002412DC != 13) {
        b.z = 0.0f;
    }
    func_0038CF68(&b, &b, 1.0f);
    func_0038CF68(&t0, &a, -75.0f);
    func_0038CF68(&t1, &b, -87.0f);
    vec_add_ba(&v[0], &t0, &t1);
    func_0038CF68(&t1, &b, 87.0f);
    vec_add_ba(&v[2], &t0, &t1);
    func_0038CF68(&t0, &a, s->f28);
    func_0038CF68(&t1, &b, -750.0f);
    vec_add_ba(&v[1], &t0, &t1);
    func_0038CF68(&t1, &b, 750.0f);
    vec_add_ab(&v[3], &t0, &t1);
    for (i = 0; i < 4; i++) {
        vec_add_ab(&v[i], &v[i], &D_L40_00249E00.pos);
        v[i].z = D_L40_00249780;
    }
    vec_sub_ba(&d0, &v[1], &v[0]);
    vec_sub_ab(&d1, &v[3], &v[2]);
    for (i = 0; i < 12; i += 2) {
        f = i;
        f /= 10.0f;
        col = func_0038DBD8(s->c0, s->c4, f);
        func_0038CE20(&t0, &d0, f);
        vec_add_ab(&t0, &t0, &v[0]);
        D_L40_0038ECE0[i] = col;
        D_L40_0038F1E0[i].u = 0.0f;
        D_L40_0038F1E0[i].v = 0.0f;
        D_L40_0038E9E0[i].x = t0.x;
        D_L40_0038E9E0[i].y = t0.y;
        D_L40_0038E9E0[i].z = t0.z;
        func_0038CE20(&t0, &d1, f);
        vec_add_ab(&t0, &t0, &v[2]);
        D_L40_0038ECE0[i + 1] = col;
        D_L40_0038F1E0[i + 1].u = 0.0f;
        D_L40_0038F1E0[i + 1].v = 0.0f;
        D_L40_0038E9E0[i + 1].x = t0.x;
        D_L40_0038E9E0[i + 1].y = t0.y;
        D_L40_0038E9E0[i + 1].z = t0.z;
    }
    func_003D3A24(12, D_L40_0038E9E0, D_L40_0038ECE0, D_L40_0038F1E0, 1);

    q.f78 = func_L39_00589890(0x16);
    q.f80 = 0xFF9000000260UL;
    q.f70 = 0;
    q.f88 = 0x8000000044UL;
    func_003A9440(0x42, 0x8000000048UL);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    c0 = s->cC;
    c1 = s->c10;
    c0 = func_0038DBD8(0, c0, 1.0f);
    c1 = func_0038DBD8(0, c1, 1.0f);
    for (j = 0; j < 2; j++) {
        func_003A9440(6, func_L39_00589890(s->tex1C + 100 + j));
        for (y = s->f18 * -2.0f; y < s->f18 + s->f18; y += s->f18) {
            n = 0;
            for (x = s->f18 * -2.0f; x < s->f18 + s->f18; x += s->f18) {
                f32 h = (f32)(j + 1);
                f32 t;
                f32 sc = D_001DB7B0_sda[j];
                f32 ou = D_L40_00249770_003F2E88[j].x;
                f32 ov = D_L40_00249770_003F2E88[j].y;

                i = n;
                D_L40_0038F3E0[i].u = x / (s->f18 + s->f18) * sc + ou;
                D_L40_0038F3E0[i].v = y / (s->f18 + s->f18) * sc + ov;
                D_L40_0038EDE0[i].x = x + D_L40_00249E00.pos.x + 1.0f;
                D_L40_0038EDE0[i].y = y + D_L40_00249E00.pos.y + 1.0f;
                t = h;
                t *= 0.05f;
                D_L40_0038EDE0[i].z = D_L40_00249780 + t;
                i++;
                D_L40_0038F3E0[i].u = x / (s->f18 + s->f18) * sc + ou;
                D_L40_0038F3E0[i].v = (y + s->f18) / (s->f18 + s->f18) * sc + ov;
                D_L40_0038EDE0[i].x = x + D_L40_00249E00.pos.x + 1.0f;
                D_L40_0038EDE0[i].y = (y + s->f18) + D_L40_00249E00.pos.y + 1.0f;
                D_L40_0038EDE0[i].z = D_L40_00249780 + t;
                i++;
                D_L40_0038F3E0[i].u = (x + s->f18) / (s->f18 + s->f18) * sc + ou;
                D_L40_0038F3E0[i].v = y / (s->f18 + s->f18) * sc + ov;
                D_L40_0038EDE0[i].x = (x + s->f18) + D_L40_00249E00.pos.x + 1.0f;
                D_L40_0038EDE0[i].y = y + D_L40_00249E00.pos.y + 1.0f;
                D_L40_0038EDE0[i].z = D_L40_00249780 + t;
                i++;
                D_L40_0038F3E0[i].u = (x + s->f18) / (s->f18 + s->f18) * sc + ou;
                D_L40_0038F3E0[i].v = (y + s->f18) / (s->f18 + s->f18) * sc + ov;
                D_L40_0038EDE0[i].x = (x + s->f18) + D_L40_00249E00.pos.x + 1.0f;
                D_L40_0038EDE0[i].y = (y + s->f18) + D_L40_00249E00.pos.y + 1.0f;
                D_L40_0038EDE0[i].z = D_L40_00249780 + t;
                for (i = n; i < n + 4; i++) {
                    t0.x = D_L40_0038EDE0[i].x - D_L40_00249E00.pos.x;
                    t0.y = D_L40_0038EDE0[i].y - D_L40_00249E00.pos.y;
                    t0.z = D_L40_0038EDE0[i].z - D_L40_00249E00.pos.z;
                    t0.w = 1.0f;
                    f = func_0038CED8(&t0) / (s->f18 + s->f18);
                    if (f > 1.0f) {
                        f = 1.0f;
                    }
                    D_L40_0038F0E0[i] = func_0038DBD8(c0, c1, f);
                }
                n += 4;
            }
            func_003D3A24(n, D_L40_0038EDE0, D_L40_0038F0E0, D_L40_0038F3E0, 1);
        }
    }
    D_L40_00259900.f238 = save238;
    D_L40_00259900.f23C = save23C;
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L40_003F2E88 */

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

/* localdecomp:start func_L40_003F4080 */
extern G_003F4080 D_1A5CD0;

extern R_1FE020 D_1FE020[];
__asm__(".extern D_L40_00242930, 16");
extern V_003F4080 D_L40_00242930 __attribute__((section(".sdata")));
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern u32 func_L40_0053F018(u8 *);
extern s32 func_L40_0053F038(u8 *, s32);
extern s32 func_L40_0053F068(u8 *, s32, s32);
extern u8*func_L40_0053E760(s32, void*, s32, s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005F3088(s32);
extern void func_L40_0053F6E0(u8 *);
extern void func_L39_005F2FF8(void *, s32);
extern N_003F4080 *func_L39_0066C3C8(N_003F4080 *, N_003F4080 **);
extern void func_L39_005B8978(u8 *, void *, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);

void func_L40_003F4080(s32 a0, u8 *self) {
    u8 *mv = *(u8 **)(self + 0x90);
    N_003F4080 *p = *(N_003F4080 **)(mv + 0x38);
    u8 *v = *(u8 **)(self + 0x68);
    s32 *q;
    s32 i;
    u8 *e;

    while (p != 0) {
        q = &p->type;
        if (q[2] > D_1A5CD0.w128) {
            p = p->next;
            continue;
        }
        switch (p->type) {
        case 1:
            switch (q[3]) {
            case 0:
                func_L01_004450F0(self, 7, -1);
                if (self[0x43] != 2) {
                    func_003C3A10(self, 2, 0, 6);
                }
                *(B_003F4080 *)(v + 0x220) = *(B_003F4080 *)p->data;
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            case 2:
                *(f32 *)(v + 0x230) = 0.8f;
                *(f32 *)(v + 0x238) = 0.5f;
                if (self[0x43] != 2) {
                    func_003C3A10(self, 2, 0, 3);
                }
                func_L01_004450F0(self, 3, -1);
                if (func_L40_0053F018(self) == 0) {
                    *(s32 *)(v + 0x2A4) = 1;
                }
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            case 3:
                func_L01_004450F0(self, 4, -1);
                if (self[0x43] != 3) {
                    func_003C3A10(self, 3, 0, 3);
                }
                if (func_L40_0053F018(self) == 0) {
                    *(s32 *)(v + 0x2A4) = 10;
                }
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            case 1:
                func_L01_004450F0(self, 2, -1);
                *(f32 *)(v + 0x230) = 0.8f;
                *(f32 *)(v + 0x238) = 0.1f;
                if (self[0x43] != 2) {
                    func_003C3A10(self, 2, 0, 6);
                }
                *(s32 *)(v + 0x2E0) = p->data[0];
                if (func_L40_0053F018(self) == 0) {
                    *(s32 *)(v + 0x2A4) = 4;
                    *(s32 *)(v + 0x2C0) = *(s32 *)(v + 0x2E0);
                }
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                if (*(s32 *)(v + 0x2E0) != -1) {
                    for (i = 0; i < 4; i++) {
                        e = func_L39_0061BF38(i);
                        if (*(s32 *)e == *(s32 *)(v + 0x2E0)) {
                            func_L40_0053F038(self, q[2]);
                        }
                    }
                    if (i == 8) {
                        func_L40_0053F068(self, **(s32 **)(e + 0x2558), q[2]);
                    }
                }
                continue;
            default:
                p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
                continue;
            }
            break;
        case 2: {
            s32 idx = *(s32 *)(v + 0x2CC);
            if (idx != -1) {
                if (((S_1FE020 *)&D_1FE020[idx])->owner == self && ((S_1FE020 *)&D_1FE020[idx])->on) {
                    func_L39_005F3088(idx);
                }
            }
            *(s32 *)(v + 0x2CC) = -1;
            func_L39_005B8978(self, v + 0x2B0, self + 0x10, 5, 2, 4, 2.0f, 0.0f, 2.0f, 1.0f, 9.0f, 1.0f, 0.0f, -1, 0, 1, -1, 0, 0x1010001);
            func_L01_00451FE0(self, 15, &D_L40_00242930, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L40_0053F6E0(self);
            func_L01_004450F0(self, 0x25, -1);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            return;
        }
        default:
            break;
        }
        p = func_L39_0066C3C8(p, (N_003F4080 **)(mv + 0x38));
    }
    if (*(s32 *)(v + 0x2E0) != 0) {
        func_L40_0053E760(*(s32 *)(v + 0x2E0), v + 0x2D0, -1, 0);
    }
}
/* localdecomp:end func_L40_003F4080 */
