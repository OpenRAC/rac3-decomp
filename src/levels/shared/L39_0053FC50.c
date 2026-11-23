#include "common.h"

/* localdecomp:start func_L39_0053FC50 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x10];
    f32 f20;
    u8 pad24[4];
    s32 w28;
    s32 w2C;
} E_0053FC50;

extern E_0053FC50 D_L39_0024DE80[];
extern u8 D_L39_00242930[] __attribute__((section(".sdata")));
extern u8 *D_L39_00296818[];
extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_0034C300(void *, f32);
extern void func_L39_005B8978(void *, void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, s32, f32, void *, u32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L39_005BC330(void *, void *, s32);
extern void func_0038CE20(void *, void *, f32);

void func_L39_0053FC50(u8 *a0, s32 a1, s32 a2) {
    vu0_v4 sphere;
    vu0_v4 d;
    vu0_v4 mid;
    vu0_v4 p50;
    vu0_v4 v60;
    vu0_v4 p70;
    vu0_v4 p80;
    f32 heading;
    s32 n;
    s32 i;
    s32 j;
    s32 m;
    s32 s;
    vu0_v4 *pos = (vu0_v4 *)(a0 + 0x10);

    sphere = *pos;
    sphere.w = 2.0f;
    if (func_L39_005BE900(&sphere, 0, 48.0f) == 1) {
        func_L01_0034C300(*(void **)(a0 + 0x68), func_0038CF00(pos, D_L39_0024DE80));
        D_L39_0024DE80[0].w28 = 0x21;
        D_L39_0024DE80[0].f20 = 0.1f;
        D_L39_0024DE80[0].w2C = 0;
    }
    func_L39_005B8978(a0, D_L39_00242930, pos, 0, 0, 0, -1, 0,
                      0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.0f, 20.0f, 0, -1, 0, 0x1010001);
    vec_sub_ba(&d, D_L39_0024DE80, pos);
    func_0038CF68(&d, &d, 0.5f);
    vec_add_ab(&mid, pos, &d);
    *pos = mid;
    heading = func_0038D160(D_L39_0024DE80[0].pos.x - *(f32 *)(a0 + 0x10),
                            D_L39_0024DE80[0].pos.y - *(f32 *)(a0 + 0x14));

    n = 20;
    switch (a2) {
    case 2:
        n = 10;
        break;
    case 3:
        n = 5;
        break;
    case 4:
        n = 1;
        break;
    }
    s = 1;
    for (i = 0; i < n; i++) {
        f32 a;
        f32 b;
        u8 *q;
        p50.x = mid.x + func_L39_005B4468(0.0f, 1.0f);
        s = -s;
        p50.y = mid.y + func_L39_005B4468(0.0f, 1.0f);
        p50.z = mid.z + func_L39_005B4468(0.0f, 1.0f);
        a = func_L39_005B4410(0.020000001f, 0.040000003f);
        b = func_L39_005B4468(0.0f, 1.3962634f);
        func_00382760(&v60, a, func_0038DAB8(heading, func_L39_005B4468(0.0f, 1.5707964f)), b);
        q = func_L01_004669B0(&p50, 0.0f, 1.0f, 1.01f, s, 315000.0f, &v60, 0x7F60A0FF, 1);
        if (q != 0) {
            s32 r;
            u8 *data;
            r = func_L39_005B43C8(0x28, 0x46);
            q[9] = 0x44;
            *(s16 *)(q + 0xA) = (r * 5 + 2) / 6;
            data = q + 0x20;
            *(s32 *)(data + 4) = 3;
            r = func_L39_005B43C8(1, 10);
            data[0xA] = 0x40;
            *(f32 *)(data + 0x1C) = (r * 5 + 2) / 6;
            data[0xB] = q[0xA];
        }
    }

    n = 32;
    switch (a2) {
    case 2:
        n = 16;
        break;
    case 3:
        n = 8;
        break;
    case 4:
        n = 2;
        break;
    }
    for (j = 0; j < n; j++) {
        s32 k;
        s32 col;
        s32 r;
        f32 sz;
        f32 big;
        f32 sp;
        f32 yaw;
        u8 *q;
        k = func_L39_005B4468(2.0f, 5.0f);
        r = func_L39_005B43C8(0x32, 0x50);
        p50.x = mid.x + func_L39_005B4468(0.0f, 0.1f);
        p50.y = mid.y + func_L39_005B4468(0.0f, 0.1f);
        p50.z = mid.z + func_L39_005B4468(0.0f, 0.1f);
        sz = func_L39_005B4410(0.35f, 0.75f);
        sp = func_L39_005B4410(4.0f, 8.0f);
        yaw = func_0038DAB8(heading, func_L39_005B4468(0.0f, 1.3962634f));
        sp *= 0.020000001f;
        big = sz * 210000.0f;
        v60.x = func_0038D098(yaw) * sp;
        v60.y = func_0038D0B0(yaw) * sp;
        v60.z = 0.0f;
        v60.z = func_L39_005B4410(0.0f, 12.0f) * 0.020000001f;
        col = (r * 5 + 2) / 6;
        func_L01_0046FB40(&p50, &v60, col, 0x7F7F7F, k, 0x7F, 0x7F, big, 2100.0f, 0.00584f, 1);
        p70.x = p50.x + func_L39_005B4468(0.0f, 0.01f);
        p70.y = p50.y + func_L39_005B4468(0.0f, 0.01f);
        p70.z = p50.z + func_L39_005B4468(0.0f, 0.01f);
        func_L01_0046FB40(&p70, &v60, col, 0x7F7F7F, -k, 0x7F, 0x7F, big, 2100.0f, 0.00584f, 1);
        k *= 2;
        sz *= 6.0f;
        q = func_L01_0046FB40(&p50, &v60, col, 0x202080, -k, 0x30, 0x30, sz * 210000.0f, 4200.0f, 0.00584f, 1);
        if (q != 0) {
            q[2] = *D_L39_00296818[0x35];
        }
    }

    vec_sub_ba(&p50, D_L39_0024DE80, &mid);
    func_0038CF68(&p50, &p50, 1.0f);
    vec_add_ab(&mid, &mid, &p50);

    n = 20;
    switch (a2) {
    case 2:
        n = 10;
        break;
    case 3:
        n = 5;
        break;
    case 4:
        n = 1;
        break;
    }
    for (m = 0; m < n; m++) {
        s32 k;
        s32 r;
        f32 sz;
        u8 *q;
        func_L39_005BC330(&p70, &p70, 0);
        func_0038CE20(&v60, &p70, -(func_L39_005B4410(0.2f, 3.0f) * 0.020000001f));
        r = (func_L39_005B43C8(0x5A, 0xB4) * 5 + 2) / 6;
        k = func_L39_005B4468(1.0f, 2.0f);
        sz = func_L39_005B4410(0.5f, 1.5f) * 210000.0f;
        p80.x = mid.x + func_L39_005B4468(0.0f, 0.75f);
        p80.y = mid.y + func_L39_005B4468(0.0f, 0.75f);
        p80.z = mid.z + func_L39_005B4468(0.0f, 0.75f);
        q = func_L01_004669B0(&p80, 0.0f, 1.0f, 1.01f, k, sz, &v60, 0x7F202020, 1);
        if (q != 0) {
            u8 *data;
            *(s16 *)(q + 0xA) = r;
            q[3] = 0x44;
            q[9] = 0x44;
            data = q + 0x20;
            k = func_L39_005B43C8(7, 0xF);
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x7F;
            *(f32 *)(data + 0x1C) = (k * 5 + 2) / 6;
            data[0xB] = q[0xA];
        }
    }
}
/* localdecomp:end func_L39_0053FC50 */

/* localdecomp:start func_L39_00540570 */
typedef struct {
    vu0_v4 v[4];
    u32 col[4];
    f32 uv[4][2];
    unsigned long u70;
    unsigned long u78;
    unsigned long u80;
    unsigned long gif;
} Q_00540570;
typedef struct {
    f32 ang[6];
    u8 pad18[4];
    s16 h1C;
    s16 h1E;
    f32 f20;
    f32 f24;
    s16 h28;
    s16 h2A;
    f32 f2C;
    f32 f30;
    s16 h34;
    s16 h36;
    f32 f38;
    f32 f3C;
} V_00540570;
extern vu0_v4 D_L39_002432B0[4];
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_0038CB00(void *);
extern void func_003860A8(f32 *, void *);
extern void func_0038D890(void *, void *, void *, f32);

static __inline__ f32 lerp_00540570(f32 a, f32 b, f32 t) {
    return a + (b - a) * t;
}

void func_L39_00540570(u8 *a0) {
    Q_00540570 q;
    vu0_v4 m[4];
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 basis[4];
    vu0_v4 cam;
    vu0_v4 t2;
    V_00540570 *v;
    f32 len;
    f32 fade;
    f32 dot;
    f32 size;
    f32 t;
    f32 k;
    f32 c;
    s32 col;
    s32 a;
    s32 i;

    vec_sub_ab(&d, a0 + 0x10, D_L39_0024DE80);
    v = *(V_00540570 **)(a0 + 0x68);
    len = func_0038CEA8(&d);
    if (len != 0.0f) {
        func_0038CE20(&d, &d, 1.0f / len);
    }
    fade = 1.0f;
    if (len < 11.0f) {
        if (len <= 7.0f) {
            fade = 0.0f;
        } else {
            fade = (len - 7.0f) * 0.25f;
        }
    }
    dot = func_0038CE68(&d, a0 + 0xC0);
    t = v->h1C * v->f20;
    size = lerp_00540570(20.0f, 2.0f, t);
    if (v->h1C < v->h28) {
        c = v->h1C * v->f2C;
        col = (s32)(c * 60.0f * dot * dot) << 24;
    } else {
        col = (s32)(dot * 60.0f * dot) << 24;
    }
    /* 1 */
    if (fabs_asm(v->ang[0]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[0]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    m[3] = *(vu0_v4 *)(a0 + 0x10);
    func_0038CE20(&m[0], a0 + 0xC0, size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    func_003D93B0(&q, 0x38, 1, 0x80);
    q.col[3] = col | 0x7F7F7F;
    q.col[2] = col | 0x7F7F7F;
    q.col[1] = col | 0x7F7F7F;
    q.col[0] = col | 0x7F7F7F;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    /* 2 */
    if (fabs_asm(v->ang[0]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, -v->ang[0]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    m[3] = *(vu0_v4 *)(a0 + 0x10);
    func_0038CE20(&m[0], a0 + 0xC0, size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    t = v->h1E * v->f24;
    size = lerp_00540570(4.0f, 1.0f, t);
    if (v->h1E < v->h2A) {
        c = func_L01_004451D0(1.0f, 0.0f, 1.0f, 2.0f, v->h1E * v->f30);
    } else {
        c = 1.0f;
    }
    col = (s32)(c * 255.0f * fade);
    a = (s32)(col * 0.2f) << 24;
    col <<= 24;
    q.col[3] = a | 0xFFFFFF;
    q.col[2] = a | 0xFFFFFF;
    q.col[1] = a | 0xFFFFFF;
    q.col[0] = a | 0xFFFFFF;
    /* 3 */
    if (fabs_asm(v->ang[1]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[1]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    k = size * 1.5f;
    func_0038CE20(&m[0], a0 + 0xC0, k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    a = (s32)(c * 255.0f * fade * 1.5f);
    if (a > 255) {
        a = 255;
    }
    func_003D93B0(&q, 0x39, 1, 0x80);
    basis[3] = *(vu0_v4 *)(a0 + 0x10);
    q.col[3] = (a << 24) | 0xFFFFFF;
    q.col[2] = (a << 24) | 0xFFFFFF;
    q.col[1] = (a << 24) | 0xFFFFFF;
    q.col[0] = (a << 24) | 0xFFFFFF;
    q.uv[0][0] = 0.0f;
    q.uv[0][1] = 0.0f;
    q.uv[1][0] = 0.0f;
    q.uv[1][1] = 1.0f;
    q.uv[2][0] = 1.0f;
    q.uv[2][1] = 0.0f;
    q.uv[3][0] = 1.0f;
    q.uv[3][1] = 1.0f;
    /* 4 */
    if (fabs_asm(v->ang[2]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[2]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    k = size * 1.25f;
    func_0038CE20(&m[0], a0 + 0xC0, k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    /* 5 */
    if (fabs_asm(v->ang[3]) > 1e-5f) {
        func_003C4840(&r, a0 + 0xC0, v->ang[3]);
        func_0038D850(&m[1], a0 + 0xD0, &r);
        func_0038D850(&m[2], a0 + 0xE0, &r);
    } else {
        m[1] = *(vu0_v4 *)(a0 + 0xD0);
        m[2] = *(vu0_v4 *)(a0 + 0xE0);
    }
    m[3] = *(vu0_v4 *)(a0 + 0x10);
    func_0038CE20(&m[0], a0 + 0xC0, size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    q.col[3] = col | 0xFFFFFF;
    q.col[2] = col | 0xFFFFFF;
    q.col[1] = col | 0xFFFFFF;
    q.col[0] = col | 0xFFFFFF;
    vec_sub_ab(&r, D_L39_0024DE80, a0 + 0x10);
    func_0038CF68(&r, &r, 0.25f);
    vec_add_ba(&m[3], a0 + 0x10, &r);
    {
        vu0_v4 *b = basis;
        func_L39_005BC330(&b[3], &cam, 1);
        vec_sub_ba(&b[0], D_L39_0024DE80, &m[3]);
        func_0038CF68(&b[0], &b[0], 1.0f);
        func_0038CE90(&b[1], &b[0], &cam);
        func_0038CF68(&b[1], &b[1], 1.0f);
        func_0038CE90(&b[2], &b[1], &b[0]);
    }    /* 6 */
    if (fabs_asm(v->ang[4]) > 1e-5f) {
        func_003C4840(&t2, &basis[0], v->ang[4]);
        func_0038D850(&m[1], &basis[1], &t2);
        func_0038D850(&m[2], &basis[2], &t2);
    } else {
        m[1] = basis[1];
        m[2] = basis[2];
    }
    func_0038CE20(&m[0], &basis[0], size);
    func_0038CE20(&m[1], &m[1], size);
    func_0038CE20(&m[2], &m[2], size);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);

    /* 7 */
    if (fabs_asm(v->ang[5]) > 1e-5f) {
        func_003C4840(&t2, &basis[0], v->ang[5]);
        func_0038D850(&m[1], &basis[1], &t2);
        func_0038D850(&m[2], &basis[2], &t2);
    } else {
        m[1] = basis[1];
        m[2] = basis[2];
    }
    k = size * 0.75f;
    func_0038CE20(&m[0], &basis[0], k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);

    a = (s32)((f32)((col >> 24) & 0xFF) * 0.2f) << 24;
    func_003D93B0(&q, 0x38, 1, 0x80);
    q.col[3] = a | 0xFFFFFF;
    q.col[2] = a | 0xFFFFFF;
    q.col[1] = a | 0xFFFFFF;
    q.col[0] = a | 0xFFFFFF;
    /* 8 */
    if (fabs_asm(v->ang[1]) > 1e-5f) {
        func_003C4840(&t2, &basis[0], v->ang[1]);
        func_0038D850(&m[1], &basis[1], &t2);
        func_0038D850(&m[2], &basis[2], &t2);
    } else {
        m[1] = basis[1];
        m[2] = basis[2];
    }
    k = size * 1.5f;
    func_0038CE20(&m[0], &basis[0], k);
    func_0038CE20(&m[1], &m[1], k);
    func_0038CE20(&m[2], &m[2], k);
    m[0].w = m[1].w = m[2].w = 0.0f;
    m[3].w = 1.0f;
    {
        s32 j;
        for (j = 0; j < 4; j++) {
            func_0038D028(&q.v[j], &D_L39_002432B0[j], m);
        }
    }
    func_003D2DA0(&q, 0, 0);
    if (func_0038CB00(&v->h36) == 0) {
        func_003860A8(&t2.x, a0 + 0x10);
        if (28492.0f <= t2.x && t2.x <= 37082.0f && 28492.0f <= t2.y && t2.y <= 37082.0f) {
            vu0_v4 ax;
            f32 w[4];
            vu0_v4 off;
            vu0_v4 sd;
            vu0_v4 o;
            vu0_v4 o2;
            vu0_q pp;
            f32 one;
            f32 W;
            f32 iW;
            f32 rx;
            f32 ry;
            f32 u;
            f32 mn;
            t2.x -= 28492.0f;
            t2.y -= 28492.0f;
            one = 1.0f;
            W = 8590.0f;
            iW = 1.0f / 8590.0f;
            c = v->h36 * v->f38;
            col = (s32)(c * 64.0f) << 24;
            func_0038D890(&ax, &cam, &d, 0.7853982f);
            func_003D93B0(&q, 0xB, 1, 0x80);
            q.u70 = 5;
            q.uv[0][0] = 0.0f;
            q.uv[0][1] = 1.0f;
            q.uv[1][0] = 1.0f;
            q.uv[1][1] = 1.0f;
            q.uv[2][0] = 0.0f;
            q.uv[2][1] = 0.0f;
            q.uv[3][0] = 1.0f;
            q.uv[3][1] = 0.0f;
            q.col[1] = 0x104050;
            q.col[0] = 0x104050;
            q.col[3] = col | 0x104050;
            q.col[2] = col | 0x104050;
            mn = t2.x < t2.y ? t2.x : t2.y;
            u = mn * iW;
            if (u < 0.5f) {
                w[3] = lerp_00540570(0.0f, one, u * 2.0f);
            } else {
                w[3] = lerp_00540570(one, 6.0f, (u - 0.5f) * 2.0f);
            }
            ry = W - t2.y;
            mn = t2.x < ry ? t2.x : ry;
            u = mn * iW;
            if (u < 0.5f) {
                w[2] = lerp_00540570(0.0f, 1.0f, u * 2.0f);
            } else {
                w[2] = lerp_00540570(1.0f, 6.0f, (u - 0.5f) * 2.0f);
            }
            rx = W - t2.x;
            mn = rx < ry ? rx : ry;
            u = mn * iW;
            if (u < 0.5f) {
                w[1] = lerp_00540570(0.0f, 1.0f, u * 2.0f);
            } else {
                w[1] = lerp_00540570(1.0f, 6.0f, (u - 0.5f) * 2.0f);
            }
            mn = rx < t2.y ? rx : t2.y;
            u = mn * iW;
            if (u < 0.5f) {
                w[0] = lerp_00540570(0.0f, 1.0f, u * 2.0f);
            } else {
                w[0] = lerp_00540570(1.0f, 6.0f, (u - 0.5f) * 2.0f);
            }
            func_0038CF68(&off, &d, 2.0f);
            for (i = 0; i < 4; i++) {
                func_0038CF68(&ax, &ax, w[i]);
                func_0038CE90(&sd, &d, &ax);
                func_0038CF68(&sd, &sd, 0.01f);
                vec_add_ba(&o, D_L39_0024DE80, &off);
                vec_sub_ba(&o2, &o, a0 + 0x10);
                __asm__("lqc2 %0, %1" : "=j"(pp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
                vec_add_ba(&q.v[0], &o, &sd);
                vec_sub_ab(&q.v[1], &o, &sd);
                {
                    vu0_q qa, qr;
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(ax));
                    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(pp), "j"(qa));
                    __asm__("sqc2 %1, %0" : "=m"(o) : "j"(qr));
                }
                vec_add_ba(&o, &o2, &o);
                func_0038CE20(&sd, &sd, 5.0f);
                vec_add_ab(&q.v[2], &o, &sd);
                vec_sub_ab(&q.v[3], &o, &sd);
                func_003D2DA0(&q, 0, 0);
                if (i < 3) {
                    func_0038D890(&ax, &ax, &d, 1.5707964f);
                }
            }
        }
    }
    if (v->h34 != 0) {
        vu0_v4 dd;
        vu0_v4 o;
        vu0_v4 sx;
        vu0_v4 sy;
        vu0_v4 o2;
        c = v->h34 * v->f3C;
        func_003D93B0(&q, 0xB, 4, 0x80);
        q.col[3] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.col[2] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.col[1] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.col[0] = ((s32)(c * 255.0f) << 24) | 0x808080;
        q.uv[0][0] = 0.0f;
        q.uv[0][1] = 0.0f;
        q.uv[1][0] = 0.0f;
        q.uv[1][1] = 1.0f;
        q.uv[2][0] = 1.0f;
        q.uv[2][1] = 0.0f;
        q.uv[3][0] = 1.0f;
        q.uv[3][1] = 1.0f;
        vec_sub_ba(&t2, a0 + 0x10, D_L39_0024DE80);
        func_0038CF68(&dd, &t2, 0.1f);
        vec_add_ba(&o, D_L39_0024DE80, &dd);
        func_0038CE90(&sx, &t2, &cam);
        func_0038CF68(&sx, &sx, 0.075f);
        func_0038CE90(&sy, &sx, &t2);
        func_0038CF68(&sy, &sy, 0.075f);
        vec_add_ba(&o2, &o, &sy);
        vec_add_ab(&q.v[0], &o2, &sx);
        vec_sub_ab(&q.v[1], &o2, &sx);
        vec_sub_ab(&o2, &o, &sy);
        vec_add_ab(&q.v[2], &o2, &sx);
        vec_sub_ab(&q.v[3], &o2, &sx);
        func_003D2DA0(&q, 0, 0);
    }
}
/* localdecomp:end func_L39_00540570 */
