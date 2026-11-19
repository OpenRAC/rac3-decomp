#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L36_0037BDF0 */
typedef struct { u8 pad0[0x10]; vu0_v4 pos; } Mover_37BDF0;
typedef struct { u8 pad[0x18]; u8 kind, count; u16 id; u8 tail[0x14]; } Hit_37BDF0;
typedef struct { vu0_v4 normal; vu0_v4 pad; vu0_v4 offset; } Contact_37BDF0;
typedef struct { f32 r,g,b,zero; vu0_v4 pos; } Light_37BDF0;
extern Contact_37BDF0 D_L36_001E9560[];
extern Light_37BDF0 D_L36_001F0580[];
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00424D88(s32);
extern void func_L01_0037C758(void *);
extern void func_003C2880(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern s32 func_0038DC20(void *, f32);
extern void func_L01_00404A10(void *, u8 *);
extern void func_L36_0037C880(u8 *);
extern void func_L36_0037CA40(u8 *, vu0_v4 *, vu0_v4 *);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_0037C720(void);
extern void func_L01_0037C6E8(void *);
extern void func_L36_0037C740(u8 *, s32);
extern s32 func_0038CAD0(void *);
void func_L36_0037BDF0(u8 *a0) {
    vu0_v4 previous, temp, velocity;
    Hit_37BDF0 hit;
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 i;
    f32 length;
    Mover_37BDF0 *m = (Mover_37BDF0 *)a0;

    switch (a0[0x20]) {
    case 0:
        previous = m->pos;
        length = func_0038CEA8(s);
        vec_add_ab(&m->pos, s, &m->pos);
        *(f32 *)(s + 0x40) = func_0038DAB8(*(f32 *)(s + 0x40), 0.69813174f);
        func_0038CF68(s + 0x10, s + 0x10, func_0038D0B0(*(f32 *)(s + 0x40)) * 0.05f);
        func_0038CF68(s + 0x20, s + 0x20, func_0038D0B0(*(f32 *)(s + 0x40)) * 0.05f);
        vec_add_ab(s, s + 0x10, s);
        vec_add_ab(s, s + 0x20, s);
        func_0038CF68(s, s, length);
        func_0038CF68(s, s, length * 0.76f);
        if (m->pos.x < 2.0f || m->pos.x > 1021.0f ||
            m->pos.y < 2.0f || m->pos.y > 1021.0f ||
            m->pos.z < 2.0f || m->pos.z > 1021.0f) {
            if (*(s32 *)(s + 0x48) != -1) func_L01_00424D88(*(s32 *)(s + 0x48));
            *(s32 *)(s + 0x48) = -1;
            func_L01_0037C758(a0);
            func_003C2880(a0);
            break;
        }
        (*(s32 *)(s + 0x34))++;
        if (func_003D3CB0(&previous, &m->pos, 0, a0, 0)) {
            m->pos = D_L36_001E9560[0].normal;
            temp = D_L36_001E9560[0].offset;
            func_0038CF68(&temp, &temp, 0.5f);
            vec_add_ab(&m->pos, &m->pos, &temp);
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 1, -1);
            velocity = *(vu0_v4 *)s;
            func_0038CE20(&velocity, &velocity, 3.0f);
            velocity.w = 5627.925f;
            func_L01_00446760(&hit, a0, 0x10000, &velocity, 5.0f);
            hit.count = 1;
            hit.id = *(u16 *)(a0 + 0xAA);
            hit.kind = 0;
            if (*(s32 *)((u8 *)D_L36_001E9560 - 8) != 0) {
                if (*(s32 *)((u8 *)D_L36_001E9560 - 8) != *(s32 *)(s + 0x38)) {
                    func_003D4D00(D_L36_001E9560, 0, a0, &hit, 1.0f);
                }
            } else {
                func_003D4D00(D_L36_001E9560, 0, a0, &hit, 1.0f);
            }
        }
        if (*(s32 *)(s + 0x48) == -1) {
            *(s32 *)(s + 0x48) = func_L01_00424CB0(&m->pos, 5.0f, 0.0f, 0.5f, 0.25f, 0.125f);
        } else {
            Light_37BDF0 *light = &D_L36_001F0580[*(s32 *)(s + 0x48)];
            light->pos = m->pos;
            light->pos.w = 5.0f;
            light->r = 0.5f;
            light->g = 0.25f;
            light->b = 0.125f;
            light->zero = 0.0f;
        }
        temp = m->pos;
        temp.w = 0.5f;
        if (func_0038DC20(&temp, 96.0f) > 0) {
            func_L01_00404A10(func_L36_0037C880, a0);
            velocity = m->pos;
            func_L36_0037CA40(a0, &velocity, &previous);
        }
        if (*(s32 *)(s + 0x34) > 100) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 1:
        for (i = 0; i < 28; i++) {
            temp.x = m->pos.x + func_003824E0(-0.5f, 0.5f);
            temp.y = m->pos.y + func_003824E0(-0.5f, 0.5f);
            temp.z = m->pos.z + func_003824E0(-0.5f, 0.5f);
            ((vu0_v4 *)(s + 0x60))[i] = temp;
            ((f32 *)(s + 0x220))[i] = func_003824E0(0.10471976f, 0.19198623f);
        }
        if (!func_L01_0037C720()) func_L01_0037C6E8(a0);
        func_L01_004450F0(a0, 2, -1);
        break;
    case 2:
        if (++*(s32 *)(s + 0x34) > 2500) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 4, -1);
        }
        temp = m->pos;
        temp.w = 0.5f;
        if (func_0038DC20(&temp, 96.0f) > 0) func_L36_0037C740(a0, 0);
        break;
    case 3:
        if (++*(s32 *)(s + 0x34) > 2500) {
            *(s32 *)(s + 0x34) = 0;
            func_L01_004450F0(a0, 4, -1);
        }
        if (func_0038CAD0(s + 0x58)) {
            func_L01_004450F0(a0, 2, -1);
            *(s32 *)(s + 0x58) = 25;
        }
        temp = m->pos;
        temp.w = 0.5f;
        if (func_0038DC20(&temp, 96.0f) > 0) func_L36_0037C740(a0, 1);
        break;
    case 4:
        if (++*(s32 *)(s + 0x34) > 17) {
            if (*(s32 *)(s + 0x48) != -1) func_L01_00424D88(*(s32 *)(s + 0x48));
            *(s32 *)(s + 0x48) = -1;
            func_L01_0037C758(a0);
            func_003C2880(a0);
        }
        break;
    }
}

/* localdecomp:end func_L36_0037BDF0 */

/* localdecomp:start func_L36_0037C440 */
extern long func_00389598(s32);
extern f32 func_0038D0B0(f32);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern void func_L36_0037CF50(u8 *, u8 *, s32, s32, f32, f32, f32, f32);
void func_L36_0037C440(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *p;
    f32 *q;
    s32 i;
    *(long *)(s + 0x50) = func_00389598(-1);
    q = (f32 *)(s + 0x290);
    p = s + 0x60;
    i = 0x1B;
    do {
        i--;
        func_003D9508(p, 0x39, 0x207F7F8F, 1, func_0038D0B0(q[0]) * 0.25f + 0.5f, -0.1f, q[0]);
        func_003D9508(p, 0x39, 0x207F7F8F, 1, func_0038D0B0(q[0]) * 0.25f + 0.5f, -0.1f, -q[0]);
        func_L36_0037CF50(a0, p, 0x3B, 1, (func_0038D0B0(q[0]) * 0.7f + 0.75f) * 0.1f, 0.2f, 0.0f, 0.005f);
        q++;
        p += 0x10;
    } while (i >= 0);
}
/* localdecomp:end func_L36_0037C440 */

/* localdecomp:start func_L36_0037C5C0 */
extern long func_00389598(s32);
extern f32 func_0038D0B0(f32);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
extern void func_L36_0037CF50(u8 *, u8 *, s32, s32, f32, f32, f32, f32);
void func_L36_0037C5C0(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *p;
    f32 *q;
    s32 i;
    *(long *)(s + 0x50) = func_00389598(-1);
    q = (f32 *)(s + 0x290);
    p = s + 0x60;
    i = 0x1B;
    do {
        i--;
        func_003D9508(p, 0x39, 0x207F7FFF, 1, func_0038D0B0(q[0]) * 0.25f + 0.5f, -0.1f, q[0]);
        func_003D9508(p, 0x39, 0x207F7FFF, 1, func_0038D0B0(q[0]) * 0.25f + 0.5f, -0.1f, -q[0]);
        func_L36_0037CF50(a0, p, 0x3B, 1, (func_0038D0B0(q[0]) * 0.7f + 0.75f) * 0.1f, 0.2f, 0.0f, 0.005f);
        q++;
        p += 0x10;
    } while (i >= 0);
}
/* localdecomp:end func_L36_0037C5C0 */

/* localdecomp:start func_L36_0037C740 */
#include "vu0.h"
extern void func_L01_004C7D98(u8 *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00404A10(void *, u8 *);
extern void func_L36_0037C5C0(u8 *);
extern void func_L36_0037C440(u8 *);
void func_L36_0037C740(u8 *a0, s32 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 v0, v1, v2;
    u8 *p;
    f32 *q;
    s32 i;
    f32 t;
    func_L01_004C7D98(a0 + 0x10, &v0);
    q = (f32 *)(s + 0x290);
    p = s + 0x60;
    i = 0x1B;
    do {
        vec_sub_ab(&v1, p, a0 + 0x10);
        func_0038D890(&v2, &v1, &v0, 0.0872664626f);
        i--;
        vec_add_ab(p, &v2, a0 + 0x10);
        *q = func_0038DAB8(q[0], q[-28]);
        t = func_0038D0B0(*q);
        q++;
        t = t * func_003824E0(0.01f, 0.015f);
        *(f32 *)(p + 8) += t;
        p += 0x10;
    } while (i >= 0);
    if (a1 != 0) {
        func_L01_00404A10(func_L36_0037C5C0, a0);
    } else {
        func_L01_00404A10(func_L36_0037C440, a0);
    }
}
/* localdecomp:end func_L36_0037C740 */

/* localdecomp:start func_L36_0037C880 */
extern f32 func_0038DAB8(f32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(u8 *, s32, s32, s32, f32, f32, f32);
void func_L36_0037C880(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 r;
    u8 *p;
    r = func_0038DAB8(*(f32 *)(s + 0x30), 0.017453292f);
    *(f32 *)(s + 0x30) = r;
    p = a0 + 0x10;
    func_003D9508(p, 0x39, 0x40505050, 1, 0.5f, 0.08f, func_0038DAB8(r * 2.5f, 0.0f));
    func_003D9508(p, 0x2A, 0x2040207F, 1, 0.5f, 0.08f, func_0038DAB8(-*(f32 *)(s + 0x30) * 1.5f, 0.0f));
    func_003D9508(p, 0x2C, 0x2040207F, 1, 0.5f, 0.08f, func_0038DAB8(*(f32 *)(s + 0x30), 0.0f));
    func_003D9508(p, 0x31, 0x20007FFF, 1, 0.36f, 0.08f, *(f32 *)(s + 0x30) * 0.5f);
    func_003D9508(p, 0x31, 0x20007FFF, 1, 0.36f, 0.08f, *(f32 *)(s + 0x30) * -0.5f);
    func_003D9508(p, 0x2F, 0x507F7F7F, 1, 0.11f, 0.08f, func_00382538());
}
/* localdecomp:end func_L36_0037C880 */

INCLUDE_ASM("asm/levels", func_L36_0037CA40);

/* localdecomp:start func_L36_0037CF50 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_37CF50;
extern vu0_v4 D_L36_001E2780;
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L36_001D7AD0[4];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);

void func_L36_0037CF50(u8 *a0, u8 *pos, s32 tex, s32 shrink, f32 size, f32 lift, f32 roll, f32 jitter)
{
    Q_37CF50 q;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 p;
    vu0_v4 z;
    vu0_v4 c;
    vu0_v4 t;
    vu0_v4 w;
    s32 i;
    s32 j;
    s32 k;
    s32 n;

    func_003D93B0(&q, tex, 1, 0x80);
    q.gif = (0x8000L << 24) | 0x4A;
    p = *(vu0_v4 *)pos;
    q.col[3] = 0x80808080;
    q.col[2] = 0x80808080;
    q.col[1] = 0x80808080;
    q.col[0] = 0x80808080;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    vec_sub_ab(&d, &D_L36_001E2780, &p);
    func_0038CF68(&d, &d, 1.0f);
    func_0038CE90(&e, &d, &D_001A4EC0);
    func_0038CF68(&e, &e, 1.0f);
    func_0038CE90(&f, &e, &d);
    if (roll != 0.0f) {
        *(vu0_q *)&z = 0;
        z.x = roll;
        func_0038D308(&c, &z);
        func_0038D5F0(&d, &d, &c);
    }
    func_0038CE20(&z, &d, lift);
    vec_add_ab(&p, &p, &z);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&q.v[i], &D_L36_001D7AD0[i], size);
        func_0038D028(&q.v[i], &q.v[i], &d);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    if (shrink != 0) {
        c = q.v[0];
        for (k = 1; k < 4; k++) {
            vec_add_ba(&c, &c, &q.v[k]);
        }
        func_0038CE20(&c, &c, 0.25f);
        for (j = 0; j < 4; j++) {
            vec_sub_ba(&t, &q.v[j], &c);
            func_0038CE20(&t, &t, 2.0f);
            vec_add_ab(&t, &c, &t);
            func_00389478(&t, &q.uv[j][0], &q.uv[j][1]);
            if (func_00382468(1) == 0) {
                q.uv[j][0] += func_003824E0(-jitter, jitter);
                q.uv[j][1] += func_003824E0(-jitter, jitter);
            }
            if (1.0f < q.uv[j][0]) {
                q.uv[j][0] = 1.0f;
            } else if (q.uv[j][0] < 0.0f) {
                q.uv[j][0] = 0.0f;
            }
            if (1.0f < q.uv[j][1]) {
                q.uv[j][1] = 1.0f;
            } else if (q.uv[j][1] < 0.0f) {
                q.uv[j][1] = 0.0f;
            }
        }
    } else {
        for (n = 0; n < 4; n++) {
            func_00389478(&q.v[n], &q.uv[n][0], &q.uv[n][1]);
            if (func_00382468(1) == 0) {
                q.uv[n][0] += func_003824E0(-jitter, jitter);
                q.uv[n][1] += func_003824E0(-jitter, jitter);
            }
            if (1.0f < q.uv[n][0]) {
                q.uv[n][0] = 1.0f;
            } else if (q.uv[n][0] < 0.0f) {
                q.uv[n][0] = 0.0f;
            }
            if (1.0f < q.uv[n][1]) {
                q.uv[n][1] = 1.0f;
            } else if (q.uv[n][1] < 0.0f) {
                q.uv[n][1] = 0.0f;
            }
        }
    }
    q.u78 = *(unsigned long *)(*(u8 **)(a0 + 0x68) + 0x50);
    q.u80 = (0xFF90L << 32) | 0x260;
    q.gif = (0x8000L << 24) | 0x54;
    q.u70 = 0;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L36_0037CF50 */
