#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003A80A0 */
#include "vu0.h"
typedef int Q_003A80A0 __attribute__((mode(TI)));
typedef union { Q_003A80A0 q; f32 f[4]; } __attribute__((aligned(16))) V4_003A80A0;
typedef struct {
    V4_003A80A0 v[4];
    s32 col[4];
    f32 uv[4][2];
    long f70, f78, f80, f88;
} S_003A80A0;

extern u8 D_L07_001E1E40_003A80A0[];
extern s32 D_L07_001DE3F0;
extern s32 D_L07_001DE3F4;
__asm__(".extern D_L07_001DE3F0, 4");
__asm__(".extern D_L07_001DE3F4, 4");
extern long func_00389598(s32);
extern void func_L04_0041E590(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0();
extern void func_0038CE20(f32 *, void *, f32);

void func_L07_003A80A0(u8 *a0, s32 n, s32 a2, s32 a3, s32 a4, s32 a5, f32 f12, f32 f13) {
    V4_003A80A0 v0, v1, v2, v3;
    S_003A80A0 A;
    S_003A80A0 B;
    V4_003A80A0 q0, q1;
    s32 i;
    f32 x, y;

    A.f78 = func_00389598(D_L07_001DE3F0);
    A.f80 = 0xFF9000000260;
    A.f88 = ((long)a2 << 32) | 0x68;
    A.col[3] = a3;
    A.col[2] = a3;
    A.col[1] = a3;
    A.col[0] = a3;
    A.f70 = 0;
    func_L04_0041E590(&A);
    A.uv[0][0] = 0.0f;
    A.uv[0][1] = 0.0f;
    A.uv[1][0] = 0.0f;
    A.uv[1][1] = 1.0f;
    A.uv[2][0] = 1.0f;
    A.uv[2][1] = 0.0f;
    A.uv[3][0] = 1.0f;
    A.uv[3][1] = 1.0f;
    B.f78 = func_00389598(D_L07_001DE3F0);
    B.f80 = 0xFF9000000260;
    B.col[3] = a4;
    B.col[2] = a4;
    B.col[1] = a4;
    B.col[0] = a4;
    B.f70 = 0;
    B.f88 = ((long)(a2 / 3) << 32) | 0x68;
    func_L04_0041E590(&B);
    q0.q = 0;
    q1.q = 0;
    B.uv[0][0] = 0.0f;
    B.uv[0][1] = 0.0f;
    B.uv[1][0] = 0.0f;
    B.uv[1][1] = 1.0f;
    B.uv[2][0] = 0.33f;
    B.uv[2][1] = 0.0f;
    B.uv[3][0] = 0.33f;
    B.uv[3][1] = 1.0f;
    q0.f[3] = 1.0f;
    q1.f[3] = 1.0f;
    q0.f[2] = f12;
    q1.f[2] = f12 * f13;
    vec_sub_ba(&v0, a0 + 16, a0);
    func_0038CF68(&v0, &v0, 1.0f);
    vec_sub_ba(&v1, D_L07_001E1E40_003A80A0, a0);
    func_0038CE90(&v2, &v1, &v0);
    func_0038CF68(&v2, &v2, 1.0f);
    func_0038CE90(&v1, &v0, &v2);
    A.v[0].q = q0.q;
    v3.q = *(Q_003A80A0 *)a0;
    func_0038CE20(A.v[1].f, &A.v[0], -1.0f);
    func_0038D028(&A.v[0], &A.v[0], &v0);
    func_0038D028(&A.v[1], &A.v[1], &v0);
    B.v[0].q = q1.q;
    func_0038CE20(B.v[1].f, &B.v[0], -1.0f);
    func_0038D028(&B.v[0], &B.v[0], &v0);
    func_0038D028(&B.v[1], &B.v[1], &v0);
    for (i = 1; i < n; i++) {
        A.v[2].q = q0.q;
        func_0038CE20(A.v[3].f, &A.v[2], -1.0f);
        B.v[2].q = q1.q;
        func_0038CE20(B.v[3].f, &B.v[2], -1.0f);
        vec_sub_ab(&v0, a0 + i * 16 + 16, a0 + i * 16);
        func_0038CF68(&v0, &v0, 1.0f);
        vec_sub_ab(&v1, D_L07_001E1E40_003A80A0, a0 + i * 16);
        func_0038CE90(&v2, &v1, &v0);
        func_0038CF68(&v2, &v2, 1.0f);
        func_0038CE90(&v1, &v0, &v2);
        v3.q = *(Q_003A80A0 *)(a0 + i * 16);
        func_0038D028(&A.v[2], &A.v[2], &v0);
        func_0038D028(&A.v[3], &A.v[3], &v0);
        func_0038D028(&B.v[2], &B.v[2], &v0);
        func_0038D028(&B.v[3], &B.v[3], &v0);
        if (i == n - 1) {
            A.col[2] = 0;
            A.col[3] = 0;
            B.col[2] = 0;
            B.col[3] = 0;
        }
        A.f78 = func_00389598(D_L07_001DE3F4);
        A.f88 = ((long)a2 << 32) | 0x68;
        A.f78 = func_00389598(0x2B);
        func_003D2DA0(&A, 0, 0);
        func_003D2DA0(&B, 0, 0);
        x = i * 0.33f;
        y = x + 0.33f;
        if (x >= 1.0f) {
            x -= 1.0f;
            y -= 1.0f;
        }
        B.uv[0][0] = x;
        B.uv[2][0] = y;
        B.uv[1][0] = x;
        B.uv[3][0] = y;
        A.v[0].q = A.v[2].q;
        A.v[1].q = A.v[3].q;
        B.v[0].q = B.v[2].q;
        B.v[1].q = B.v[3].q;
    }
}
/* localdecomp:end func_L07_003A80A0 */

/* localdecomp:start func_L07_003A8538 */
#include "vu0.h"
typedef int Q_003A8538 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003A8538;
typedef struct {
    Q_003A8538 vertices[4];
    s32 colors[4];
    f32 uv[4][2];
    unsigned long state[4];
} Packet_003A8538;
extern s32 D_001DE408_sda, D_001DE3F8_sda, D_001DE3FC_sda;
extern f32 D_001DE400_sda, D_001DE404_sda;
extern V_003A8538 D_L07_001E1E40;
__asm__(".extern D_001DE408_sda, 4");
__asm__(".extern D_001DE3F8_sda, 4");
__asm__(".extern D_001DE3FC_sda, 4");
__asm__(".extern D_001DE400_sda, 4");
__asm__(".extern D_001DE404_sda, 4");

static __inline__ V_003A8538 sub_003A8538(V_003A8538 *a, V_003A8538 *b) {
    V_003A8538 r;
    vec_sub_ba(&r, a, b);
    return r;
}

static __inline__ V_003A8538 add_003A8538(V_003A8538 *a, V_003A8538 *b) {
    V_003A8538 r;
    vec_add_ba(&r, a, b);
    return r;
}

static __inline__ V_003A8538 add2_003A8538(V_003A8538 *a, V_003A8538 *b) {
    V_003A8538 r;
    vec_add_ab(&r, a, b);
    return r;
}


void func_L07_003A8538(u8 *moby, Q_003A8538 *a, Q_003A8538 *b) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    V_003A8538 pos, end;
    Packet_003A8538 packet;
    V_003A8538 sideA, sideB, direction, temp;
    V_003A8538 *start = &pos, *finish = &end;
    f32 *uvb;
    u8 *p;
    f32 *uv;
    s32 i;
    *(Q_003A8538 *)start = *a;
    *(Q_003A8538 *)finish = *b;
    p = *(u8 **)(moby + 0x68);
    func_003D93B0(&packet, D_001DE408_sda, 1, 128);
    uvb = &packet.uv[0][0];
    packet.colors[3] = D_001DE3F8_sda;
    packet.colors[2] = packet.colors[3];
    packet.colors[1] = packet.colors[3];
    packet.colors[0] = packet.colors[3];
    packet.uv[0][0] = 0.0f;
    packet.uv[0][1] = 0.0f;
    packet.uv[1][0] = 0.0f;
    packet.uv[1][1] = 1.0f;
    packet.uv[2][0] = 1.0f;
    packet.uv[2][1] = 0.0f;
    packet.uv[3][0] = 1.0f;
    packet.uv[3][1] = 1.0f;
    uv = uvb;
    for (i = 3; i >= 0; i--) {
        *uv -= *(f32 *)(p + 0x2B0);
        if (*uv <= 7.0f) *uv += 7.0f;
        uv += 2;
    }
    vec_sub_ba(&direction, start, finish);
    func_0038CF68(&direction, &direction, 1.0f);
    vec_sub_ba(&sideA, start, &D_L07_001E1E40);
    vec_sub_ba(&sideB, finish, &D_L07_001E1E40);
    func_0038CE90(&sideA, &sideA, &direction);
    func_0038CF68(&sideA, &sideA, D_001DE400_sda);
    func_0038CE90(&sideB, &sideB, &direction);
    func_0038CF68(&sideB, &sideB, D_001DE404_sda);
    temp = sub_003A8538(start, &sideA);
    packet.vertices[0] = *(Q_003A8538 *)&temp;
    temp = add_003A8538(start, &sideA);
    packet.vertices[1] = *(Q_003A8538 *)&temp;
    temp = sub_003A8538(finish, &sideB);
    packet.vertices[2] = *(Q_003A8538 *)&temp;
    temp = add2_003A8538(finish, &sideB);
    packet.vertices[3] = *(Q_003A8538 *)&temp;
    func_003D2DA0(&packet, 0, 0);
    func_003D93B0(&packet, 14, 1, 128);
    packet.colors[3] = D_001DE3FC_sda;
    packet.colors[2] = packet.colors[3];
    packet.colors[1] = packet.colors[3];
    packet.colors[0] = packet.colors[3];
    packet.uv[0][0] = 0.0f;
    packet.uv[0][1] = 0.0f;
    packet.uv[1][0] = 0.0f;
    packet.uv[1][1] = 1.0f;
    packet.uv[2][0] = 1.0f;
    packet.uv[2][1] = 0.0f;
    packet.uv[3][0] = 1.0f;
    packet.uv[3][1] = 1.0f;
    uv = uvb;
    for (i = 3; i >= 0; i--) {
        *uv -= *(f32 *)(p + 0x2B0);
        if (*uv <= 7.0f) *uv += 7.0f;
        uv += 2;
    }
    vec_sub_ba(&direction, start, finish);
    func_0038CF68(&direction, &direction, 1.0f);
    vec_sub_ba(&sideA, start, &D_L07_001E1E40);
    vec_sub_ba(&sideB, finish, &D_L07_001E1E40);
    func_0038CE90(&sideA, &sideA, &direction);
    func_0038CF68(&sideA, &sideA, D_001DE400_sda * 0.5f);
    func_0038CE90(&sideB, &sideB, &direction);
    func_0038CF68(&sideB, &sideB, D_001DE404_sda * 0.5f);
    temp = sub_003A8538(start, &sideA);
    packet.vertices[0] = *(Q_003A8538 *)&temp;
    temp = add_003A8538(start, &sideA);
    packet.vertices[1] = *(Q_003A8538 *)&temp;
    temp = sub_003A8538(finish, &sideB);
    packet.vertices[2] = *(Q_003A8538 *)&temp;
    temp = add2_003A8538(finish, &sideB);
    packet.vertices[3] = *(Q_003A8538 *)&temp;
    func_003D2DA0(&packet, 0, 0);
}
/* localdecomp:end func_L07_003A8538 */

/* localdecomp:start func_L07_003A8908 */
extern f32 D_001A4C64[];
extern u8 D_001A30B0[];
extern s32 func_L07_003BAC00(u8 *, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L07_003A8908(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *c = *(u8 **)(s + 0xC8);
    f32 q[4] __attribute__((aligned(16)));
    f32 tmp[4] __attribute__((aligned(16)));
    s32 h;
    s32 id;
    u8 *e;
    f32 r;

    if (c == 0) {
        return;
    }
    if (func_L07_003BAC00(c, obj[0x21]) == 0) {
        return;
    }
    h = *(s16 *)(s + 0xC6);
    *(vu0_q *)q = *(vu0_q *)(obj + 0x10);
    switch (obj[0x20]) {
    case 0:
        obj[0x30] = 0xFF;
        *(s32 *)(s + 0x6C) |= 0x10;
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            u8 *row = s + h * 2;
            u16 t = *(u16 *)(row + 0x70);
            *(u16 *)(s + 0xC4) = t;
            if ((s16)t == -1) {
                func_L01_004450F0(obj, 6, -1);
                break;
            }
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj) != 0) {
            u8 *row = s + h * 2;
            *(u16 *)(s + 0xC4) = *(u16 *)(row + 0xB0);
        }
        if (func_0038CB00(s + 0xC4) != 0 && D_001A4C64[0] < *(f32 *)(obj + 0x14) + 1.0f) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(obj) != 0) {
            u8 *row = s + h * 2;
            s32 t = (*(s16 *)(row + 0x80) * 5 + 2) / 6;
            id = *(s32 *)(s + 0xCC);
            *(u16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)(s16)t;
            if (id == -1 ||
                (e = (u8 *)((id << 7) + (s32)D_001A30B0),
                 *(u8 **)(e + 0xDC) != obj || e[0xD0] == 0)) {
                *(s32 *)(s + 0xCC) = func_003A52A0(0, 4, obj);
            }
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            s32 release_id = *(s32 *)(s + 0xCC);
            if (release_id != -1) {
                u8 *entry = (u8 *)((release_id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(entry + 0xDC) == obj && entry[0xD0] != 0) {
                    func_003A4F28(release_id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_L01_004450F0(obj, 4, -1);
        }
        r = func_003C4088(-8.5f, 0.0f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
        goto apply_offset;
    case 4:
        if (func_L01_004561B8(obj) != 0) {
            u8 *row = s + h * 2;
            *(u16 *)(s + 0xC4) = (*(s16 *)(row + 0xA0) * 5 + 2) / 6;
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            func_L01_004450F0(obj, 5, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(obj) != 0) {
            u8 *row = s + h * 2;
            s32 t = (*(s16 *)(row + 0x90) * 5 + 2) / 6;
            id = *(s32 *)(s + 0xCC);
            *(u16 *)(s + 0xC4) = t;
            *(f32 *)(s + 0xC0) = 1.0f / (f32)(s16)t;
            if (id == -1 ||
                (e = (u8 *)((id << 7) + (s32)D_001A30B0),
                 *(u8 **)(e + 0xDC) != obj || e[0xD0] == 0)) {
                *(s32 *)(s + 0xCC) = func_003A52A0(1, 4, obj);
            }
        }
        if (func_0038CB00(s + 0xC4) != 0) {
            s32 release_id = *(s32 *)(s + 0xCC);
            if (release_id != -1) {
                u8 *entry = (u8 *)((release_id << 7) + (s32)D_001A30B0);
                if (*(u8 **)(entry + 0xDC) == obj && entry[0xD0] != 0) {
                    func_003A4F28(release_id);
                }
            }
            *(s32 *)(s + 0xCC) = -1;
            func_L01_004450F0(obj, 2, -1);
        }
        r = func_003C3BE8(0.0f, -8.5f, (f32)*(s16 *)(s + 0xC4) * *(f32 *)(s + 0xC0));
apply_offset:
        func_0038CE20(tmp, obj + 0xD0, r);
        vec_add_ab(obj + 0x10, s + 0xD0, tmp);
        break;
    }
    vec_sub_ba(q, obj + 0x10, q);
    func_003C4DA8(s + 0x30, q, obj + 0xF0, obj + 0xF0);
}
/* localdecomp:end func_L07_003A8908 */

/* localdecomp:start func_L07_003A8D58 */
typedef int u128_t __attribute__((mode(TI)));
void func_L07_003A8D58(void *arg0, s16 arg1, s32 arg2) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    *(u128_t *)(p + 0xD0) = *(u128_t *)((u8 *)arg0 + 0x10);
    *(s16 *)(p + 0xC6) = arg1;
    *(s32 *)(p + 0xC8) = arg2;
}
/* localdecomp:end func_L07_003A8D58 */

/* localdecomp:start func_L07_003A8D70 */
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003A8D70(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    *(u128_t *)(arg0 + 0x10) = *(u128_t *)(p + 0xD0);
    *(u128_t *)(p + 0xD0) = *(u128_t *)D_L07_001D66B0;
    *(s32 *)(p + 0xC0) = 0;
    *(s16 *)(p + 0xC4) = 0;
    *(s16 *)(p + 0xC6) = 0;
    *(s32 *)(p + 0xC8) = 0;
    func_L01_004450F0(arg0, 0, -1);
}
/* localdecomp:end func_L07_003A8D70 */
