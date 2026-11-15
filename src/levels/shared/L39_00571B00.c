#include "common.h"

typedef struct {
    u8 pad0[0x460];
} Ent_005718B8;
typedef struct {
    u8 pad0[0x30];
    u8 pos[0x50];
} Pt_005718B8;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 pad14[0x26 - 0x14];
    s16 x26;
    u8 pad28[0x34 - 0x28];
    s32 x34;
    u8 pad38[0x4A - 0x38];
    s16 x4A;
} Info_005718B8;
typedef struct {
    u8 pad0[0x1C];
    Info_005718B8 *info;
} Row_005718B8;

/* declared by functions of L39_005718B8.c, which this file was cut from */
extern Ent_005718B8 D_L39_0024DE80[];
extern Row_005718B8 *D_L39_0024B850;

/* localdecomp:start func_L39_00571B00 */
typedef int Q_00571B00 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00571B00;
typedef struct {
    u8 pad0[0x20];
    s32 x20;
    s16 x24;
    s16 x26;
    f32 x28;
    f32 x2C;
    f32 x30;
    u8 pad34[0x38 - 0x34];
    f32 x38;
    f32 x3C;
    f32 x40;
    f32 x44;
} Info_00571B00;
typedef struct {
    f32 x0;
    f32 x4;
    f32 x8;
    u8 padC[0x14 - 0xC];
    f32 x14;
    f32 x18;
    u8 pad1C[0x20 - 0x1C];
} Tbl_00571B00;

__asm__(".extern D_L39_00241164, 16");
extern u8 *D_L39_00241164;
extern s32 D_L39_0024BB44;
extern Tbl_00571B00 *D_L39_0024B850_00571B00 __attribute__((section(".sdata")));
extern s32 func_L39_005718B8(u8 *);
extern s32 func_L01_003E8B28(u8 *);
extern s32 func_L01_003E8AD8(u8 *);
extern s32 func_L39_005C42E8(s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L01_003E8E70(s32);
extern void func_L01_003E8C28(s32, f32, f32);
extern void func_L01_003E8C70(s32, s32, f32, f32);
extern void func_L01_003E8D48(s32, f32);
extern void func_L01_003E8D80(s32, s32);
extern void func_L01_003E8CE0(s32, f32, f32, f32);

void func_L39_00571B00(u8 *a)
{
    u8 *ent = (u8 *)((s32)D_L39_0024DE80 + *(s32 *)(a + 0x94) * 0x460);
    Info_00571B00 *info = (Info_00571B00 *)D_L39_0024B850[*(s16 *)(a + 0x84)].info;
    u8 *st = ent + 0x150;
    s32 n;

    if (func_L39_005718B8(a)) {
        if (func_L01_003E8B28(a) <= 0) {
            if (info->x20 != 0) {
                info->x26 = 1;
            }
            info->x20 = 0;
            return;
        }
        if (!((*(u32 *)(D_L39_00241164 + 0x1A0) & func_L39_005C42E8(4, 0)) && D_L39_0024BB44 >= 11)) {
            goto on;
        }
    }
    if (info->x20 != 0) {
        info->x26 = 1;
    }
    info->x20 = 0;
    func_L01_003E8AD8(a);
    return;

on:
    if (info->x20 < 2) {
        V4_00571B00 v0;
        V4_00571B00 d;
        V4_00571B00 pr;
        V4_00571B00 pe;
        Q_00571B00 q1, q2, q3;
        f32 ang;
        f32 dot;
        f32 t;
        u8 *owner;
        u8 *sub;
        u8 *s180;
        u8 *s20;
        u8 *s60;
        u8 *s210;

        if (info->x2C == 0.0f && info->x30 == 0.0f) {
            Tbl_00571B00 *tbl = D_L39_0024B850_00571B00;
            info->x2C = tbl[*(s16 *)(a + 0x84)].x14;
            info->x30 = tbl[*(s16 *)(a + 0x84)].x18;
        }
        ang = func_0038D160(*(f32 *)(st + 0x40) - ((Tbl_00571B00 *)D_L39_0024B850)[*(s16 *)(a + 0x84)].x0,
                            *(f32 *)(st + 0x44) - ((Tbl_00571B00 *)D_L39_0024B850)[*(s16 *)(a + 0x84)].x4);
        if (func_0038DBA0(info->x30, ang) > 0.034906585f) {
            info->x44 = func_0038DB00(info->x30, ang);
        }
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(V4_00571B00 *)(st + 0x40)));
        v0.x = ((Tbl_00571B00 *)D_L39_0024B850)[*(s16 *)(a + 0x84)].x0;
        v0.y = ((Tbl_00571B00 *)D_L39_0024B850)[*(s16 *)(a + 0x84)].x4;
        v0.z = ((Tbl_00571B00 *)D_L39_0024B850)[*(s16 *)(a + 0x84)].x8;
        v0.w = 0.0f;
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(v0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(q3));
        dot = func_0038CE68(&d, (st + 0x80));
        func_0038CE20(&pr, (st + 0x80), dot);
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(d));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(pr));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(pe) : "j"(q3));
        info->x38 = func_0038CEA8(&pe);
        info->x3C = -dot;
        t = info->x2C;
        if (__builtin_fabsf(t) == 1.5707964f) {
            info->x40 = 0.0f;
        } else {
            f32 tn = func_0038D0B0(t) / func_0038D098(t);
            info->x40 = info->x3C - info->x38 * tn;
        }

        owner = *(u8 **)(ent + 0x50);
        *(V4_00571B00 *)(owner + 0x30) = v0;
        sub = *(u8 **)(owner + 0x70);
        s180 = sub + 0x180;
        s20 = sub + 0x20;
        s60 = sub + 0x60;
        s210 = sub + 0x210;
        *(f32 *)(s180 + 0x2C) = info->x38;
        *(f32 *)(s180 + 0x30) = info->x3C;
        *(f32 *)(s20 + 0x28) = info->x44;
        *(f32 *)(s60 + 0xD0) = info->x40;
        func_0038CE20(&pr, (st + 0x80), -*(f32 *)(s180 + 0x30));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(pr));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(V4_00571B00 *)(st + 0x40)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_00571B00 *)(sub + 0xB0)) : "j"(q3));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(*(V4_00571B00 *)(sub + 0xB0)));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(v0));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_00571B00 *)(sub + 0x180)) : "j"(q3));
        *(V4_00571B00 *)(sub + 0x190) = *(V4_00571B00 *)(sub + 0x180);
        func_0038CE20(&pr, (st + 0x80), -*(f32 *)(s60 + 0xD0));
        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(*(V4_00571B00 *)(st + 0x40)));
        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(pr));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(q3) : "j"(q1), "j"(q2));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_00571B00 *)(sub + 0xA0)) : "j"(q3));
        *(V4_00571B00 *)(sub + 0x110) = *(V4_00571B00 *)(sub + 0xA0);
        *(V4_00571B00 *)(sub + 0xC0) = *(V4_00571B00 *)(sub + 0x60) = *(V4_00571B00 *)(st + 0x40);
        *(V4_00571B00 *)(sub + 0x0) = *(V4_00571B00 *)(owner + 0x30);
        *(V4_00571B00 *)(sub + 0x230) = *(V4_00571B00 *)(owner + 0x30);
        *(f32 *)(s210 + 0x30) = 0.0f;
        *(f32 *)(s20 + 0x14) = 0.0f;
        *(f32 *)(s20 + 0x4) = *(f32 *)(s60 + 0xD0);
        *(f32 *)(s20 + 0x8) = *(f32 *)(s180 + 0x30);
        *(s16 *)(s20 + 0x2) = 0;
        *(f32 *)(s20 + 0x18) = *(f32 *)(s20 + 0x14);
        *(f32 *)(s20 + 0x10) = *(f32 *)(s20 + 0x14);
        *(f32 *)(s20 + 0xC) = *(f32 *)(s20 + 0x14);
    }

    n = info->x20 + 1;
    info->x20 = n;
    if (n >= 0xA8) {
        info->x20 = 0xA7;
    }
    if (info->x38 != 0.0f) {
        func_L01_003E8BD0(*(s32 *)(a + 0x94), 0, info->x38, 0.003f);
        func_L01_003E8E70(*(s32 *)(a + 0x94));
    }
    if (info->x3C != 0.0f) {
        func_L01_003E8C28(*(s32 *)(a + 0x94), info->x3C, 0.003f);
    }
    if (info->x40 != 0.0f) {
        func_L01_003E8C70(*(s32 *)(a + 0x94), 0, info->x40, 0.005f);
    }
    if (info->x28 != 0.0f) {
        func_L01_003E8D48(*(s32 *)(a + 0x94), info->x28 * 0.017453292f);
    }
    if (info->x24 == 0) {
        func_L01_003E8D80(*(s32 *)(a + 0x94), 0);
    }
    if (info->x44 != 0.0f) {
        func_L01_003E8CE0(*(s32 *)(a + 0x94), info->x44, 60.0f, 60.0f);
    }
}
/* localdecomp:end func_L39_00571B00 */
