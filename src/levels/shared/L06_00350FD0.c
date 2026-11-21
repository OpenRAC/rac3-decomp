#include "vu0.h"
#include "common.h"

/* localdecomp:start func_L06_00350FD0 */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_L06_00350BB8(void *arg0, u8 *arg1);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L06_00350E28(u8 *, u8 *, void *, s32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 D_L06_001DD2D8;
__asm__(".extern D_L06_001DD2D8, 4");
extern s32 D_L06_001DD2DC[];

s32 func_L06_00350FD0(u8 *a0, u8 *a1, u8 *tgt) {
    vu0_v4 d;
    vu0_v4 dir;
    vu0_v4 p;
    vu0_v4 t;
    f32 yaw;
    f32 dist;
    f32 s;
    s32 n;
    f32 f;

    vec_sub_ab(&d, tgt, a0 + 0x10);
    yaw = func_0038DB00(func_0038D160(d.x, d.y), *(f32 *)(a0 + 0xF8));
    func_L01_00448890(a1 + 0x370, yaw, a1 + 0x374, 0.010053097f,
                      0.010053097f, 0.12566371f, 0);
    func_L06_00350BB8(a0, a1);
    if ((u32)((*(u8 **)(a1 + 0x260))[0x43] - 10) < 2) {
        dir = d;
        dir.z = 0.0f;
        func_0038CF68(&dir, &dir, 1.0f);
        dist = func_0038CED8(&d);
        if (dist < 5.5f) {
            s = 0.5f - dist;
        } else {
            s = -5.0f;
        }
        n = *(s32 *)(a1 + 0x35C);
        if (n > 0) {
            f = (f32)n / (f32)*(s32 *)(a1 + 0x38C);
            f = s + (1.0f - f) * 10.0f;
        } else {
            f = s;
        }
        func_0038CE20(&t, &dir, f);
        vec_add_ab(&p, &t, tgt);
        func_L06_00350E28(a0, a1, &p, 0);
        func_L06_00350E28(a0, a1, &p, 1);
    } else {
        qzero(a1 + 0x400);
        func_L01_0044E850(*(void **)(a1 + 0x260), a1 + 0x3A0, D_L06_001DD2D8, 0.0432f, 0.43200004f);
        qzero(a1 + 0x480);
        func_L01_0044E850(*(void **)(a1 + 0x260), a1 + 0x420, D_L06_001DD2DC[0], 0.0432f, 0.43200004f);
    }
    return fabs_asm(func_0038DB00(*(f32 *)(a1 + 0x370), yaw)) < 0.08726646f;
}
/* localdecomp:end func_L06_00350FD0 */

/* localdecomp:start func_L06_00351220 */
extern void func_L06_003512D0(s32, u8 *);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038DB00(f32, f32);
s32 func_L06_00351220(s32 a0, u8 *a1) {
    func_L06_003512D0(a0, a1);
    if (*(f32 *)(a1 + 0x370) == 0.0f) {
        return 1;
    }
    func_L01_00448890(a1 + 0x370, 0.0f, a1 + 0x374, 0.010053097f, 0.010053097f, 0.12566371f, 0);
    if (fabs_asm(func_0038DB00(*(f32 *)(a1 + 0x370), 0.0f)) < 0.08726646f) {
        *(f32 *)(a1 + 0x370) = 0.0f;
        *(f32 *)(a1 + 0x374) = 0.0f;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00351220 */

/* localdecomp:start func_L06_003512D0 */
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 D_L06_001DD2D8;
__asm__(".extern D_L06_001DD2D8, 4");
extern s32 D_L06_001DD2DC[];
void func_L06_003512D0(s32 a0, u8 *a1) {
    qzero(a1 + 0x400);
    func_L01_0044E850(*(void **)(a1 + 0x260), a1 + 0x3A0, D_L06_001DD2D8, 0.0432f, 0.43200004f);
    qzero(a1 + 0x480);
    func_L01_0044E850(*(void **)(a1 + 0x260), a1 + 0x420, D_L06_001DD2DC[0], 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L06_003512D0 */

/* localdecomp:start func_L06_00351358 */
void func_L06_00351358(void *arg0, void *arg1) {
    void *temp_v1;

    *(f32 *)((u8 *)arg0 + 0x2C) = (f32) (2.0f * (*(f32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x24))) + 0x24)));
    temp_v1 = *(void **)((u8 *)arg1 + 0x260);
    if (temp_v1 != 0) {
        *(f32 *)((u8 *)temp_v1 + 0x2C) = (f32) (2.0f * (*(f32 *)((u8 *)((*(void **)((u8 *)temp_v1 + 0x24))) + 0x24)));
    }
}
/* localdecomp:end func_L06_00351358 */

/* localdecomp:start func_L06_00351390 */
extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CF38(void *a0, void *a1);
extern u8 D_001A4C60[];
s32 func_L06_00351390(u8 *a0, s32 a1) {
    s32 hit = func_00382380(D_001A4C60, *(s32 *)((u8 *)a1 + 0x264), 0);
    s32 r = 0;
    if (hit || func_0038CF38(a0 + 0x10, (u8 *)a1 + 0x220) < *(f32 *)((u8 *)a1 + 0x268)) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L06_00351390 */

/* localdecomp:start func_L06_00351410 */
extern void func_L01_00477BC0(s32, s32);
extern f32 func_0038CF00(void *, void *);
typedef struct { u8 pad[0xC]; f32 f; } __attribute__((aligned(16))) E_00351410;
typedef struct { s32 n; u8 pad[0xC]; E_00351410 e[1]; } P_00351410;
typedef struct { s32 key; f32 val; } K_00351410;
typedef struct {
    u8 pad0[0x274];
    s32 n;
    u8 pad278[0x280 - 0x278];
    K_00351410 k[(0x300 - 0x280) / 8];
    s32 x300;
    u8 pad304[0x340 - 0x304];
    s32 x340;
    u8 pad344[0x358 - 0x344];
    P_00351410 *p;
} O_00351410;
void func_L06_00351410(s32 a0, O_00351410 *o) {
    P_00351410 *p = o->p;
    s32 i;
    o->n = 0;
    for (i = 0; i < p->n; i++) {
        if (p->e[i].f < -2.0f || 0.0f <= p->e[i].f) {
            o->k[o->n].key = i;
            o->k[o->n].val = p->e[i].f;
            o->n++;
        }
    }
    func_L01_00477BC0(o->x300, 0);
    if (o->x340 != 0) {
        p->e[p->n - 1].f = func_0038CF00(&p->e[p->n - 1], &p->e[0]);
    }
}
/* localdecomp:end func_L06_00351410 */

/* localdecomp:start func_L06_00351508 */
extern f32 func_003824E0(f32, f32);
extern f32 func_L04_00455AF8(void *);
s32 func_L06_00351508(s32 a0, u8 *a1, s32 a2, f32 f) {
    f32 mid;
    if (*(s16 *)(a1 + 0x23C) == 0) {
        return 0;
    }
    if (*(s32 *)(a1 + 0x324) > 0) {
        return 0;
    }
    if (a2 != 0) {
        if (f < *(f32 *)(a1 + 0x318)) {
            return 0;
        }
        if (*(f32 *)(a1 + 0x31C) < f) {
            return 0;
        }
    }
    mid = *(f32 *)(a1 + 0x314) + (*(f32 *)(a1 + 0x31C) - *(f32 *)(a1 + 0x314)) * 0.5f;
    if (*(f32 *)(a1 + 0x32C) < *(f32 *)(a1 + 0x30) / (f32)*(s16 *)(a1 + 0x34) && f < mid) {
        if (*(f32 *)(a1 + 0x328) < func_003824E0(0.0f, 1.0f)) {
            return 0;
        }
    }
    if (func_L04_00455AF8(a1 + 0x220) < *(f32 *)(a1 + 0x228) + 64.0f) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L06_00351508 */

/* localdecomp:start func_L06_00351628 */
extern s32 D_L06_001DD2F0;
__asm__(".extern D_L06_001DD2F0, 4");
extern s32 D_L06_001DD2F4[];
extern void func_003C2F58(s32, s32, s32);

void func_L06_00351628(s32 a0, u8 *obj, s32 a2, s32 a3) {
    func_003C2F58(*(s32 *)(obj + 0x260), D_L06_001DD2F0, a2);
    func_003C2F58(*(s32 *)(obj + 0x260), D_L06_001DD2F4[0], a3);
}
/* localdecomp:end func_L06_00351628 */

/* localdecomp:start func_L06_00351678 */
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CAD0(void *);

void func_L06_00351678(u8 *moby, u8 *vars) {
    f32 r = 7.0f;
    f32 x = *(f32 *)(vars + 784);
    if (x < r) {
        r = x;
    } else if (r < x * 0.5f) {
        r = x * 0.5f;
    }
    r = r * r;
    if (func_L01_0040E570(moby + 16, vars + 544) < r) {
        func_0038CAD0(vars + 632);
    } else {
        *(int *)(vars + 632) = 150;
    }
}
/* localdecomp:end func_L06_00351678 */

/* localdecomp:start func_L06_00351718 */
s32 func_L06_00351718(s32 arg0, void *arg1) {
    return (*(s32 *)((u8 *)arg1 + 0x278)) == 0;
}
/* localdecomp:end func_L06_00351718 */

/* localdecomp:start func_L06_00351728 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038CF38(void *a0, void *a1);
extern s32 func_L06_0045AFF8(void *a0, s32 a1, void *a2);
extern f32 func_0038CF00(void *a0, void *a1);
void func_L06_00351728(u8 *a0, u8 *a1, u128_t *a2, s32 *a3, f32 *t0) {
    if (*(s32 *)(a1 + 624) != 0) {
        *a2 = *(u128_t *)(a0 + 16);
        *a3 = 0;
        *t0 = func_0038CF38(a0 + 16, a1 + 544);
    } else {
        *a3 = func_L06_0045AFF8(a2, *(s32 *)(a1 + 856), a1 + 544);
        *t0 = func_0038CF00(a1 + 544, a2);
    }
}
/* localdecomp:end func_L06_00351728 */

/* localdecomp:start func_L06_003517C0 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L06_00351A68(u8 *, u8 *, s32);
extern void func_L06_003519A0(u8 *, u8 *, s32, s32, s32);
void func_L06_003517C0(u8 *a0, u8 *a1, s32 st) {
    if (a0[0x43] == st) {
        return;
    }
    switch (st) {
    case 5:
        func_L01_0045BD78(a0, 0.006f, 0.20000002f, 0.010053097f, 0.25132743f);
        func_L06_00351A68(a0, a1, 5);
        break;
    case 0x14:
        func_L01_0045BD78(a0, 0.0056000003f, 0.10000001f, 0.010053097f, 0.25132743f);
        func_L06_003519A0(a0, a1, 0x14, 0, 10);
        break;
    case 0x15:
        func_L01_0045BD78(a0, 0.0056000003f, -0.10000001f, 0.010053097f, 0.25132743f);
        func_L06_003519A0(a0, a1, 0x15, 0, 10);
        break;
    }
}
/* localdecomp:end func_L06_003517C0 */
