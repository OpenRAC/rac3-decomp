#include "common.h"
#include "vu0.h"

typedef struct {
    char pad0[0x10];
    u8 count;
} Anim;
typedef struct {
    char pad0[0x48];
    Anim *anims[1];
} Class;
typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x40 - 0x28];
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    s32 unk44;
    char pad48[0x58 - 0x48];
    s32 unk58;
    s32 unk5C;
} Moby;
typedef struct {
    char data[0x600];
} Buf;
typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
typedef struct {
    u8 pad0[0x20];
    u8 b32;
    u8 pad21[0x34 - 0x21];
    u16 h52;
    u8 pad36[0xAA - 0x36];
    s16 h170;
} M_50C8E8;
typedef struct {
    M_50C8E8 *p[3];
    u8 padC[0x28 - 0xC];
    s32 w40;
    u8 pad2C[0x50 - 0x2C];
} E_50C8E8;
typedef struct {
    u8 pad0[0xBF8];
    M_50C8E8 *p3064;
    u8 padBFC[0x1200 - 0xBFC];
    E_50C8E8 e[1];
    u8 pad1250[0x12FC - 0x1250];
    M_50C8E8 *p4860;
    u8 pad1300[0x1A24 - 0x1300];
    M_50C8E8 *p6692;
    u8 pad1A28[0x25E4 - 0x1A28];
    u8 b9700;
} G_50C8E8;
typedef struct {
    u8 pad0[0x44];
    s16 h68;
    u8 pad46[0x1A0 - 0x46];
    M_50C8E8 *arr[1];
} H_50C8E8;
typedef struct {
    u8 pad0[0x20];
    s16 h32;
} K_50C8E8;
typedef struct {
    f32 m[16];
} M_0050D430;
typedef struct {
    f32 v[4];
} V_0050D430;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_50D4D8;
typedef struct {
    u8 pad0[64];
    Vec4_50D4D8 m;
    u8 pad50[9636];
    u8 b25F4;
} G_50D4D8;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D530;
typedef struct {
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x25F4 - 0x80];
    u8 mode;
} Cam50D5B0;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_00511618;
typedef struct {
    u8 m0[64];
    u8 m40[9716 - 64];
    u8 mode;
} S_50D870;
typedef struct {
    u8 pad[138];
    u16 h8A;
    u8 pad2[240 - 140];
} S_50D8F8;
typedef struct {
    u8 pad0[0x8A];
    u16 h8A;
    u8 pad8C[0xF0 - 0x8C];
} S_50DA08;
typedef struct {
    u8 arr[0x40];
} S_50DA08a;
typedef struct {
    s32 arr[0x40];
} S_50DA08b;
typedef struct {
    u8 pad0[52];
    s32 x34;
} G_0050F828;

typedef struct {
    u8 pad0[0x78];
    s32 color78;
} Node_005124D8;
typedef struct {
    u8 pad0[0x1340];
    Node_005124D8 *p1340;
    Node_005124D8 *p1344;
    Node_005124D8 *p1348;
    u8 pad134C[0x1390 - 0x134C];
    Node_005124D8 *p1390;
    u8 pad1394[0x2890 - 0x1394];
    f32 f2890;
    f32 f2894;
    f32 f2898;
    f32 f289C;
} Glob_005124D8;

typedef struct Manip_00512A30 {
    u8 pad0;
    u8 initialized;
    u8 pad2[0x1E];
    f32 scale[3];
    u8 pad2C[0x14];
} Manip_00512A30;

/* declared by functions of L01_0050F9E8.c, which this file was cut from */
extern D_001A4BE0_t D_001A4BE0;
extern s32 D_L01_001D6694;
extern s32 func_L01_00513EF0(void);
extern s32 D_L01_001D673C;
extern int D_001A71A4[];

/* localdecomp:start func_L01_00512DF8 */
extern u8 D_001439F4[];
extern u8 D_001A71C4[];

long func_L01_00512DF8(long a0) {
    if (D_001439F4[0] != 0 && D_001A71C4[0] == 0) {
        switch (a0) {
        case 0x40:
            return 0x44;
        case 4:
            return 1;
        case 8:
            return 2;
        }
    }
    return a0;
}
/* localdecomp:end func_L01_00512DF8 */

/* localdecomp:start func_L01_00512E68 */
typedef struct {
    u8 pad0[0x20];
    f32 v20[4];
    u8 pad30[0x10];
    Vec4_50D4D8 v40;
    u8 pad50[0x30];
    Vec4 v80;
    u8 pad90[0x100];
    u128_t q190;
    f32 f1A0;
    u8 pad1A4[0x368 - 0x1A4];
    s16 h368;
    u8 pad36A[0x1200 - 0x36A];
    u8 *p1200;
    u8 pad1204[0x1228 - 0x1204];
    s32 w1228;
    u8 pad122C[0x1434 - 0x122C];
    u16 h1434;
    u8 pad1436[0x1480 - 0x1436];
    f32 m1480[0x18];
    Vec4_50D4D8 v14E0;
    f32 v14F0[4];
    u8 pad1500[0x20];
    u128_t q1520;
    u8 pad1530[0x10];
    f32 m1540[0xC];
    Vec4 v1570;
    f32 f1580;
    u8 pad1584[0x15A0 - 0x1584];
    f32 f15A0;
    u8 pad15A4[0x15F8 - 0x15A4];
    f32 f15F8;
    u8 pad15FC[4];
    f32 v1600[4];
    u8 pad1610[0x10];
    u16 h1620;
    u8 pad1622[0x1630 - 0x1622];
    u128_t q1630;
    u8 pad1640[0x1664 - 0x1640];
    f32 f1664;
    s32 w1668;
    u8 pad166C[0x16A8 - 0x166C];
    f32 f16A8;
    s32 w16AC;
    s32 w16B0;
    u8 pad16B4[0x16BC - 0x16B4];
    s32 w16BC;
    u8 pad16C0[0x16CC - 0x16C0];
    f32 f16CC;
    u8 pad16D0[0x25C4 - 0x16D0];
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
    u8 b25E5;
} Hero_00512E68;
extern Hero_00512E68 D_001A4BE0_00512E68;
extern u8 D_00143950_00512E68[];
extern u8 *D_001D52FC;
typedef struct {
    u8 pad0[0x14];
    f32 f14;
    f32 f18;
    u8 pad1C[0x380 - 0x1C];
    u128_t q380;
} Cam_00512E68;
extern Cam_00512E68 D_L01_001E2A40;
extern u128_t D_L01_001E2AC0[];
void func_L01_00512E68(void) {
    extern s32 func_003A3BB8(s32, s32);
    extern void func_L01_00514508(s32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CC88(void *, void *, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D2A0(void *);
    extern void func_0038D5B0(M_0050D430 *, M_0050D430 *);
    extern void func_L01_004130D0(void *);
    extern void func_L01_004130C0(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4138(void *, f32, f32);
    extern void func_L01_00413138(void *, void *, void *, void *, void *, s32, f32);
    extern void func_L01_00513FD8(void);
    extern void func_0038D000(Vec4_50D4D8 *, f32 *, Vec4_50D4D8 *);
    extern void func_003C3FC0(void *, void *);
    extern void func_L01_005133E8(void);
    M_0050D430 matrix;
    Vec4 target;
    u8 *m;
    u8 *actor;
    s32 input;
    s32 option;
    D_001A4BE0_00512E68.h1620 &= 0xFFF7;
    if (D_001A4BE0_00512E68.w16B0) {
        input = *(s32 *)(D_001D52FC + 0x1A0) & func_003A3BB8(4, 0);
        if (input && D_00143950_00512E68[0xA4] == 1 && (D_001A4BE0_00512E68.w25C4 == 1 || D_001A4BE0_00512E68.w25C4 == 29)) {
            D_001A4BE0_00512E68.h1620 |= 8;
            func_L01_00514508(2);
        } else if (!input && D_00143950_00512E68[0xA4] == 1 &&
                   (D_001A4BE0_00512E68.w16B0 == 2 || (D_001A4BE0_00512E68.w16B0 == 1 && func_0038CE68(D_001A4BE0_00512E68.v1600, D_001A4BE0_00512E68.v1600) == 0.0f))) {
            D_001A4BE0_00512E68.w1668 = 0;
            func_L01_00514508(1);
            if (D_001A4BE0_00512E68.f1664 < 2.0f) D_001A4BE0_00512E68.f1664 = 2.0f;
        }
        func_0038CC88(D_001A4BE0_00512E68.m1480, &D_001A4BE0_00512E68, 0x30);
        *(u128_t *)&D_001A4BE0_00512E68.m1480[8] = D_L01_001E2AC0[0];
        func_0038CF68(&D_001A4BE0_00512E68.m1480[8], &D_001A4BE0_00512E68.m1480[8], 1.0f);
        func_0038CE90(&D_001A4BE0_00512E68.m1480[4], D_001A4BE0_00512E68.m1480, &D_001A4BE0_00512E68.m1480[8]);
        func_0038CF68(&D_001A4BE0_00512E68.m1480[4], &D_001A4BE0_00512E68.m1480[4], 1.0f);
        func_0038CE90(D_001A4BE0_00512E68.m1480, &D_001A4BE0_00512E68.m1480[8], &D_001A4BE0_00512E68.m1480[4]);
        func_0038CF68(D_001A4BE0_00512E68.m1480, D_001A4BE0_00512E68.m1480, 1.0f);
        func_0038D2A0(&matrix);
        func_0038D5B0(&matrix, (M_0050D430 *)D_001A4BE0_00512E68.m1480);
        func_0038CC88(&D_001A4BE0_00512E68.m1480[12], &matrix, 0x30);
        if ((D_001A4BE0_00512E68.v20[2] > 0.99999f && D_001A4BE0_00512E68.h368 == 0 && !D_L01_001D673C) || D_001A4BE0_00512E68.w25C4 == 43 || D_001A4BE0_00512E68.w25C4 == 44)
            func_L01_004130D0(D_001A4BE0_00512E68.m1540);
        else
            func_L01_004130C0(D_001A4BE0_00512E68.m1540);
        if (D_001A4BE0_00512E68.w25CC == 17) {
            target.q = D_001A4BE0_00512E68.v80.q;
            target.f[2] += 0.1f;
        } else {
            func_0038CE20(&target, &D_001A4BE0_00512E68.m1480[8], 0.7f);
            vec_add_ba(&target, &target, &D_001A4BE0_00512E68.v80);
        }
        option = D_00143950_00512E68[0xA4];
        if (!option && (D_001A4BE0_00512E68.w25C4 == 1 || D_001A4BE0_00512E68.w25C4 == 29)) D_001A4BE0_00512E68.h1620 |= 8;
        if (D_001A4BE0_00512E68.w25CC == 3 || D_001A4BE0_00512E68.w25CC == 20) {
            if (D_001A4BE0_00512E68.f15F8 != -0.7853982f) func_003C4138(&D_001A4BE0_00512E68.f15F8, -0.7853982f, 0.041887906f);
        } else {
            if (D_001A4BE0_00512E68.f15F8 != -1.0471976f) func_003C4138(&D_001A4BE0_00512E68.f15F8, -1.0471976f, 0.041887906f);
        }
        m = (u8 *)D_001A4BE0_00512E68.m1540;
        func_L01_00413138(m, D_001D52FC, m - 0x20, m - 0x30, &target, option, 1.0f);
        func_L01_00513FD8();
        if (D_001A4BE0_00512E68.w16B0 && D_001A4BE0_00512E68.w1228 != 9) {
            D_001A4BE0_00512E68.h1434 = 2;
            D_001A4BE0_00512E68.f1A0 = D_001A4BE0_00512E68.f1580;
            D_001A4BE0_00512E68.q190 = D_001A4BE0_00512E68.q1630;
        }
    } else if (!D_00143950_00512E68[0xA4]) {
        D_001A4BE0_00512E68.f15A0 = D_L01_001E2A40.f14;
        D_001A4BE0_00512E68.f1580 = D_L01_001E2A40.f18;
        D_001A4BE0_00512E68.q1630 = D_L01_001E2A40.q380;
        func_0038CC88(D_001A4BE0_00512E68.m1540, &D_L01_001E2A40.q380, 0x30);
        func_0038CF68(&D_001A4BE0_00512E68.v1570, D_001A4BE0_00512E68.v20, D_001A4BE0_00512E68.f16CC);
        vec_add_ab(&D_001A4BE0_00512E68.v1570, &D_001A4BE0_00512E68.v1570, &D_001A4BE0_00512E68.v80);
        D_001A4BE0_00512E68.q1520 = D_001A4BE0_00512E68.v1570.q;
    }
    if (func_L01_00513EF0() || ((D_001A4BE0_00512E68.w25C4 == 1 || D_001A4BE0_00512E68.w25C4 == 29) && D_001A4BE0_00512E68.b25E5)) {
        if (!D_001A4BE0_00512E68.w16B0) {
            actor = D_001A4BE0_00512E68.p1200;
            if (actor && *(s16 *)(actor + 0xAA) != 71) {
                vec_sub_ab(&D_001A4BE0_00512E68.v14E0, actor + 0x10, &D_001A4BE0_00512E68.v80);
                func_0038D000(&D_001A4BE0_00512E68.v14E0, (f32 *)&D_001A4BE0_00512E68.v14E0, &D_001A4BE0_00512E68.v40);
                func_003C3FC0(D_001A4BE0_00512E68.v14F0, actor + 0xF0);
            }
            D_001A4BE0_00512E68.w16B0 = D_00143950_00512E68[0xA4] ? D_00143950_00512E68[0xA4] : 2;
            D_001A4BE0_00512E68.f16A8 = 1.0f;
            D_001A4BE0_00512E68.w16AC = 0;
            D_001A4BE0_00512E68.w16BC = 0;
        }
    } else if (D_001A4BE0_00512E68.w25C4 != 1 && D_001A4BE0_00512E68.w25C4 != 29) D_001A4BE0_00512E68.w16B0 = 0;
    if (!D_001A4BE0_00512E68.b25E4 && D_001A4BE0_00512E68.w16B0 == 2) func_L01_005133E8();
}
/* localdecomp:end func_L01_00512E68 */

/* localdecomp:start func_L01_005133E8 */
typedef struct { Vec4 row[4]; } Matrix_005133E8;
extern D_001A4BE0_t D_001A4BE0;
extern S_50D8F8 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_001D5477;
__asm__(".extern D_001D5477, 16");
extern f32 D_L01_001DC080[2];
__asm__(".extern D_L01_001DC080, 4");
extern f32 D_001A62A4[];
extern u8 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern u8 D_L01_001E2A40_005133E8[];
extern u8 D_L01_001EAA20[];
extern u128_t D_L01_001E2A50[];
void func_L01_005133E8(void) {
    extern s32 func_L01_004E9270(s32);
    extern void func_003C7C38(u8 *);
    extern void func_0038D570(void *, void *);
    extern s32 func_L01_00513EF0(void);
    extern void func_003C4138(f32 *, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern void func_0038D028(V_0050D430 *, V_0050D430 *, M_0050D430 *);
    extern void func_0038D328(M_0050D430 *, u8 *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_003C48A8(void *, void *);
    extern void func_003C3FC0(void *, void *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_003C41A0(f32 *, f32 *, f32, f32, f32, f32);
    extern void func_0038D590(void *, void *);
    Matrix_005133E8 matrix, rotation;
    Vec4 offset, point, delta;
    u8 *g = (u8 *)&D_001A4BE0;
    u8 *m = *(u8 **)(g + 0x1200);
    u8 *weapon;
    u8 *attachment;
    u8 *base;
    f32 speed, radius, height;
    if (m == 0) return;
    if (*(s16 *)(m + 0xAA) == 0x47) {
        if (g[0x121C] == 0 && m[0x20] == 0) {
            m[0x31] = 0;
            *(u16 *)(m + 0x34) |= 1;
        } else {
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= ~1;
        }
        return;
    }
    if (func_L01_004E9270(0)) {
        m[0x31] = 0;
        *(u16 *)(m + 0x34) |= 1;
        if (*(void (**)(u8 *))(m + 0x64)) (*(void (**)(u8 *))(m + 0x64))(m);
        func_003C7C38(m);
        return;
    }
    weapon = (u8 *)&D_L01_002C5600[D_001425C0[*(s32 *)(g + 0x1228)]];
    func_0038D570(&matrix, g + 0x1540);
    attachment = weapon + 0xA0;
    offset.q = *(u128_t *)attachment;
    offset.f[0] += *(f32 *)(g + 0x16B8);
    matrix.row[3].q = *(u128_t *)(g + 0x1570);
    matrix.row[3].f[3] = 1.0f;
    if (D_001D5477 != 0 && !func_L01_00513EF0()) offset.f[1] = -offset.f[1];
    {
        u8 *h = (u8 *)&D_001A4BE0;
        if (*(f32 *)(h + 0x174) > 0.02f) {
            speed = D_L01_001DC080[1] * 0.017453292f * 0.020000001f;
        } else {
            speed = D_L01_001DC080[0] * 0.017453292f * 0.020000001f;
        }
    }
    func_003C4138(D_001A62A4, speed, 0.010053097f);
    base = (u8 *)D_001A62A4 - 0x16C4;
    *(f32 *)(base + 0x16C0) = func_0038DAB8(*(f32 *)(base + 0x16C0), *(f32 *)(base + 0x16C4));
    offset.f[2] += func_0038D0B0(*(f32 *)(base + 0x16C0)) * 0.02f;
    func_0038D028((V_0050D430 *)(m + 0x10), (V_0050D430 *)&offset, (M_0050D430 *)&matrix);
    if (!func_L01_00513EF0()) {
        {
            vu0_q qa, qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(base + 0x150)));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)(m + 0x10)) : "j"(qr));
        }
    }
    func_0038D328((M_0050D430 *)&rotation, attachment + 0x10);
    func_0038D5F0(m + 0xC0, &matrix, &rotation);
    func_003C48A8(m + 0xC0, m + 0xF0);
    func_003C3FC0((u8 *)D_001A62A4 - 0x1C4, m + 0xF0);
    m[0x31] = 1;
    *(u16 *)(m + 0x34) &= ~1;
    func_003C7C38(m);
    if (((D_L01_001DFB40 ^ 1) & 1) != 0) {
        f32 scale = 0.0009765625f;
        radius = *(f32 *)(m + 0xC) * scale;
        func_0038CE20(point.f, (f32 *)m, scale);
        func_0038CF68(delta.f, (f32 *)(m + 0xD0), radius * -1.2f);
        {
            vu0_q qa, qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)&delta));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)&point));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)&delta) : "j"(qr));
        }
        if (func_003D3CB0(D_L01_001E2A40_005133E8, &delta, 0, *(u8 **)(base + 0x25C0), 0)) {
            height = (*(f32 *)(base + 0x16B8) - radius) + func_0038CF00(D_L01_001EAA20, &point);
            *(f32 *)(base + 0x16BC) = height;
            if (height > 0.0f) *(f32 *)(base + 0x16BC) = 0.0f;
            else if (height < -1.5f) *(f32 *)(base + 0x16BC) = -1.5f;
        } else *(s32 *)(base + 0x16BC) = 0;
    }
    {
    u8 *tail = (u8 *)&D_001A4BE0;
    if (tail[0x25F0]) *(f32 *)(tail + 0x16BC) = -1.5f;
    func_003C41A0((f32 *)(tail + 0x16B8), (f32 *)(tail + 0x16B4), *(f32 *)(tail + 0x16BC), 0.006f, 0.006f, 0.10000001f);
    func_0038D590(tail + 0x6C0, &matrix);
    {
        u128_t a = *(u128_t *)&matrix;
        u128_t b = D_L01_001E2A50[0];
        *(u128_t *)(tail + 0x6F0) = a;
        *(u128_t *)(tail + 0x700) = b;
    }
    if (*(void (**)(u8 *))(m + 0x64)) (*(void (**)(u8 *))(m + 0x64))(m);
    }
}
/* localdecomp:end func_L01_005133E8 */

/* localdecomp:start func_L01_00513800 */

extern s16 D_L01_002C4C62[];
extern G_0050F828 D_00142660;

extern s32 func_L01_0041A4F0(void);

void func_L01_00513800(s32 *out, s32 *total, s32 *acc) {
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 191; i++) {
        if ((D_L01_002C4C62 - 1)[i * 2] < 0) {
            break;
        }
        sum += (D_L01_002C4C62 - 1)[i * 2];
        if ((D_00142660.x34 >> 5) < sum) {
            break;
        }
        *acc += D_L01_002C4C62[i * 2];
        *out = sum;
        if (func_L01_0041A4F0() == 0 && i >= 90) {
            break;
        }
    }
    *total = sum;
}
/* localdecomp:end func_L01_00513800 */

INCLUDE_ASM("asm/levels", func_L01_005138F8);

/* localdecomp:start func_L01_00513EF0 */
typedef struct {
    u8 pad0[0xA4];
    u8 camera_setting; /* 0 follow, 1 lock-strafe, 2 first person */
} Options_513EF0;
typedef struct {
    u8 pad0[0x86];
    s16 mode;
} Camera_513EF0;
typedef struct {
    u8 pad0[0x238];
    s32 no_look_timer;
    u8 pad23C[0x16B0 - 0x23C];
    s32 camera_mode;
    u8 pad16B4[0x25C4 - 0x16B4];
    s32 state;
    u8 pad25C8[0x25CC - 0x25C8];
    s32 state_type;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 character;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 health;
    u8 pad2854[0x28C4 - 0x2854];
    s32 any_state;
} Hero_513EF0;
extern D_001A4BE0_t D_001A4BE0;
extern Options_513EF0 D_00143950;
extern s32 D_L01_001D6694;
extern Camera_513EF0 *D_L01_001E2A90[];

/* hero_camera_allowed: the camera setting if the hero camera may run now, else 0 */
s32 func_L01_00513EF0(void) {
    Hero_513EF0 *hero;
    s32 state;

    if (D_00143950.camera_setting == 0) {
        if (((Hero_513EF0 *)&D_001A4BE0)->camera_mode == 0) {
            return 0;
        }
    }
    if (((Hero_513EF0 *)&D_001A4BE0)->no_look_timer != 0) {
        return 0;
    }
    /* game modes 2 and 6 */
    if (D_L01_001D6694 == 2 || D_L01_001D6694 == 6) {
        return 0;
    }
    /* a scripted camera */
    if (D_L01_001E2A90[0] != 0 && D_L01_001E2A90[0]->mode == 5) {
        return 0;
    }
    hero = (Hero_513EF0 *)&D_001A4BE0;
    if (hero->character == 5 || hero->state_type == 0x14 || hero->health == 0) {
        return 0;
    }
    if (hero->any_state == 0) {
        state = hero->state;
        if (state == 0x74 || state == 0x31 || state == 0x1C || state == 0x91 || state == 0xB0 ||
            state == 0x76) {
            return 0;
        }
    }
    return D_00143950.camera_setting;
}
/* localdecomp:end func_L01_00513EF0 */
