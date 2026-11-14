#include "vu0.h"
#include "common.h"

/* localdecomp:start func_L06_003506E0 */
extern void func_L06_00350BB8(void *arg0, u8 *arg1);
typedef struct {
    u8 pad0[32];
    u8 state;
    u8 pad1[52 - 33];
    u16 flags;
    u8 pad2[104 - 54];
    void *vars;
} Moby_0034F9E8;
extern u8 D_L06_001DD340[];
extern void func_L06_00350788(Moby_0034F9E8 *, void *);
extern s32 func_L06_00351C48(Moby_0034F9E8 *, void *);
extern s32 func_L04_004C1158(Moby_0034F9E8 *, void *);
extern void func_L06_003528B8(Moby_0034F9E8 *, void *);
extern void func_L06_00352AA0(Moby_0034F9E8 *, void *);
extern void func_L06_00354D48(Moby_0034F9E8 *, void *);
void func_L06_003506E0(Moby_0034F9E8 *m) {
    void *v;
    if (m->flags & 2) return;
    v = m->vars;
    if (m->state == 0) func_L06_00350788(m, v);
    if (func_L06_00351C48(m, v) == 0) return;
    if (func_L04_004C1158(m, D_L06_001DD340)) {
        ((void (*)(Moby_0034F9E8 *, void *))func_L06_00350BB8)(m, v);
        func_L06_003528B8(m, v);
        func_L06_00352AA0(m, v);
        func_L06_00354D48(m, v);
    }
}
/* localdecomp:end func_L06_003506E0 */

INCLUDE_ASM("asm/levels", func_L06_00350788);

/* localdecomp:start func_L06_00350BB8 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4;

typedef struct {
    Vec4 m[4];
} Mtx4;

extern void func_003C2EC0(void *, s32, Mtx4 *);
extern void func_0038D590(void *, Mtx4 *);
extern void func_003C48A8(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);

void func_L06_00350BB8(void *arg0, u8 *arg1) {
    Mtx4 m;

    func_003C2EC0(arg0, 0, &m);
    *(Vec4 *)(*(u8 **)(arg1 + 608) + 16) = m.m[3];
    func_0038D590(*(u8 **)(arg1 + 608) + 192, &m);
    func_003C48A8(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    if (*(f32 *)(arg1 + 880) != 0.0f) {
        *(f32 *)(*(u8 **)(arg1 + 608) + 248) = func_0038DAB8(*(f32 *)(*(u8 **)(arg1 + 608) + 248), *(f32 *)(arg1 + 880));
        func_0038D308(*(u8 **)(arg1 + 608) + 192, *(u8 **)(arg1 + 608) + 240);
    }
}
/* localdecomp:end func_L06_00350BB8 */

INCLUDE_ASM("asm/levels", func_L06_00350C50);

/* localdecomp:start func_L06_00350D60 */
void func_L06_00350D60(s32 a0, s32 a1, s32 a2, f32 *p) {
    f32 f;
    f32 lim;
    *(s32 *)p = 0;
    f = p[1];
    if (1.0471976f < f) {
        p[1] = 1.0471976f;
    } else if (f < -1.0471976f) {
        p[1] = -1.0471976f;
    }
    f = p[2];
    if (a2 == 0) {
        if (0.4886922f < f) {
            p[2] = 0.4886922f;
        } else if (f < -0.7853982f) {
            p[2] = -0.7853982f;
        }
    } else {
        if (0.7853982f < f) {
            p[2] = 0.7853982f;
        } else if (f < -0.4886922f) {
            p[2] = -0.4886922f;
        }
    }
}
/* localdecomp:end func_L06_00350D60 */

INCLUDE_ASM("asm/levels", func_L06_00350E28);

INCLUDE_ASM("asm/levels", func_L06_00350FD0);

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

INCLUDE_ASM("asm/levels", func_L06_00351390);

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
