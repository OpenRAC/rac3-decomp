#include "common.h"

typedef struct {
    u8 pad0[0x50];
    u8 *p50;
    u8 pad54[0x460 - 0x54];
} Ent_003C5150;
typedef struct {
    u8 pad0[0x1C];
    u8 *st;
} Sp_003C5150;

/* declared by functions of L02_003C5150.c, which this file was cut from */
extern Ent_003C5150 D_L02_001E1300[];
extern Sp_003C5150 *D_L02_001DE184;
extern u8 D_001A4C60[];

/* localdecomp:start func_L02_003C5310 */
#include "vu0.h"

extern u8 *D_001D52FC;
extern s32 func_L01_003E8B28(u8 *);
extern s32 func_L01_003E8AD8(u8 *);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_003A3BB8(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_003E8F90(s32, s32);
extern void func_L01_003E8E70(s32);
extern void func_L01_003E9250(s32, f32 *, f32, f32);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L02_003C1360(s32, f32);
extern void func_L01_003E8C28(s32, f32, f32);
extern void func_L01_003E8C70(s32, s32, f32, f32);
extern void func_L01_003E8D48(s32, f32);
extern void func_L01_003E8D80(s32, s32);
extern void func_L01_003E8DB8(s32, f32, f32);
extern void func_L01_003E8EA8(s32);
extern void func_L01_003E8E10(s32, f32, f32);

typedef struct {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1C[0x50 - 0x1C];
    u8 *p50;
    u8 pad54[0x104 - 0x54];
    f32 f104;
    u8 pad108[0x460 - 0x108];
} Ent_003C5310;

void func_L02_003C5310(u8 *moby) {
    u8 *st = D_L02_001DE184[*(s16 *)(moby + 0x84)].st;
    u8 *hero8;
    u8 *hero6;
    u8 *hero5;
    u8 *hero10;
    u8 *hero54;
    u8 *hero56;
    s32 flag;
    f32 scale;
    f32 ang;
    s16 type;
    vu0_v4 v;

    if (*(s16 *)(st + 0x2C) == 8) {
        hero8 = ((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(hero8 + 0x94) * 0x460))->p50;
        if (*(s32 *)(*(u8 **)(hero8 + 0x70) + 0x270) == 0) return;
    }
    if (*(s16 *)(st + 0x2C) == 6) {
        hero6 = ((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(hero6 + 0x94) * 0x460))->p50;
        if (*(s32 *)(*(u8 **)(hero6 + 0x70) + 0x270) != 0) return;
    }
    if (!func_L02_003C5150(moby)) {
        if (*(s16 *)(st + 0x2E)) *(s16 *)(st + 0x4A) = 1;
        *(s16 *)(st + 0x2E) = 0;
        func_L01_003E8AD8(moby);
        return;
    }
    if (func_L01_003E8B28(moby) <= 0) {
        if (*(s16 *)(st + 0x2E)) *(s16 *)(st + 0x4A) = 1;
        *(s16 *)(st + 0x2E) = 0;
        return;
    }
    if (*(s16 *)(st + 0x36) &&
        func_0038DBA0(*(f32 *)((u8 *)&D_L02_001DE184[*(s16 *)(moby + 0x84)] + 0x18),
                      ((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(moby + 0x94) * 0x460))->f18) >= 1.3962634f) {
        if (*(s16 *)(st + 0x2E)) *(s16 *)(st + 0x4A) = 1;
        *(s16 *)(st + 0x2E) = 0;
        func_L01_003E8AD8(moby);
        return;
    }
    if (*(s16 *)(st + 0x48) && *(s16 *)(st + 0x2C) == 5 &&
        (*(s32 *)(D_001D52FC + 0x1A0) & func_003A3BB8(4, 0))) {
        if (*(s16 *)(st + 0x2E)) *(s16 *)(st + 0x4A) = 1;
        *(s16 *)(st + 0x2E) = 0;
        func_L01_003E8AD8(moby);
        return;
    }
    if (*(s16 *)(st + 0x2E) == 0) {
        *(f32 *)(st + 0x40) = *(f32 *)(*(u8 **)(((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(moby + 0x94) * 0x460))->p50 + 0x70) + 0x15C);
        *(f32 *)(st + 0x44) = *(f32 *)(*(u8 **)(((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(moby + 0x94) * 0x460))->p50 + 0x70) + 0x160);
    }
    if (*(s32 *)(st + 0x2C) == 5) { /* retail: one lw of 0x2C/0x2E against 5 */
        u8 *pv;
        u8 *a;
        u8 *b;
        u8 *c;
        u8 *d;

        *(f32 *)(st + 0) = 0.0f;
        hero5 = ((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(hero5 + 0x94) * 0x460))->p50;
        pv = *(u8 **)(hero5 + 0x70);
        a = pv + 0x180;
        b = pv + 0x60;
        func_0038CF68(a, a, *(f32 *)(st + 0x24));
        c = pv + 0x210;
        *(f32 *)(a + 0x2C) = *(f32 *)(st + 0x24);
        d = pv + 0x20;
        *(f32 *)(a + 0x30) = *(f32 *)(st + 0x28);
        *(f32 *)(b + 0xD0) = *(f32 *)(st + 0x30);
        *(vu0_v4 *)(pv + 0x190) = *(vu0_v4 *)(pv + 0x180);
        func_0038CE20(&v, D_001A4C60 + 0x260, -*(f32 *)(a + 0x30));
        vec_add_ba(pv + 0xB0, D_001A4C60, &v);
        vec_add_ba(hero5 + 0x30, pv + 0xB0, pv + 0x180);
        func_0038CE20(&v, D_001A4C60 + 0x260, -*(f32 *)(b + 0xD0));
        vec_add_ab(pv + 0xA0, D_001A4C60, &v);
        *(vu0_v4 *)(pv + 0x110) = *(vu0_v4 *)(pv + 0xA0);
        *(vu0_v4 *)(pv + 0xC0) = *(vu0_v4 *)(pv + 0x60) = *(vu0_v4 *)D_001A4C60;
        *(vu0_v4 *)(pv + 0) = *(vu0_v4 *)(hero5 + 0x30);
        *(vu0_v4 *)(pv + 0x230) = *(vu0_v4 *)(hero5 + 0x30);
        *(f32 *)(c + 0x30) = *(f32 *)(a + 0x2C) - func_0038CEA8(a);
        *(s32 *)(d + 0x14) = 0;
        *(f32 *)(d + 4) = *(f32 *)(b + 0xD0);
        *(f32 *)(d + 8) = *(f32 *)(a + 0x30);
        *(f32 *)(d + 0x18) = *(f32 *)(d + 0x14);
        *(f32 *)(d + 0x10) = *(f32 *)(d + 0x14);
        *(f32 *)(d + 0xC) = *(f32 *)(d + 0x14);
    }
    flag = 0;
    *(s16 *)(st + 0x2E) += 1;
    scale = 167.0f;
    if (*(s16 *)(st + 0x2C) == 10) {
        func_L01_003E8F90(*(s32 *)(moby + 0x94), -1);
        hero10 = ((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(hero10 + 0x94) * 0x460))->p50;
        *(s32 *)(*(u8 **)(hero10 + 0x70) + 0x270) = 0x14D;
    }
    if (*(s16 *)(st + 0x2C) == 11) {
        func_L01_003E8F90(*(s32 *)(moby + 0x94), -1);
        *(s32 *)(*(u8 **)(((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(moby + 0x94) * 0x460))->p50 + 0x70) + 0x270) = 2;
    }
    if (*(s16 *)(st + 0x2C) == 2 || *(s16 *)(st + 0x2C) == 4) {
        {
            u8 *f = *(u8 **)(((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(moby + 0x94) * 0x460))->p50 + 0x70) + 0x1E0;
            *(u32 *)(f + 0x10) |= 3;
        }
        if (*(s16 *)(st + 0x2E) >= 0xA8) {
            flag = 1;
            *(s16 *)(st + 0x2E) = 0xA7;
        }
        func_L01_003E8E70(*(s32 *)(moby + 0x94));
    } else if (*(s16 *)(st + 0x2C) == 1 || *(s16 *)(st + 0x2C) == 7 || *(s16 *)(st + 0x2C) == 10 || *(s16 *)(st + 0x2C) == 9) {
        if (*(f32 *)(D_001D52FC + 0x100) != 0.0f || *(f32 *)(D_001D52FC + 0x104) != 0.0f) {
            *(s16 *)(st + 0x2E) = 0xA7;
        }
        if (*(s16 *)(st + 0x2E) >= 0xA7) {
            flag = 1;
            if (((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(moby + 0x94) * 0x460))->f104 > 0.0f) {
                *(s16 *)(st + 0x2E) = 0xA7;
            }
        }
        if (*(s16 *)(st + 0x2E) >= 0x14D) {
            flag = 0;
            *(s16 *)(st + 0x2E) = 1;
        }
    } else if (*(s16 *)(st + 0x2C) == 3) {
        scale = 1.0f;
        if (*(s16 *)(st + 0x2E) >= 2) {
            *(s16 *)(st + 0x2E) = 1;
            flag = 1;
        }
    } else {
        if (*(s16 *)(st + 0x2E) >= 0xA8) {
            *(s16 *)(st + 0x2E) = 0xA7;
            flag = 1;
        }
    }
    *(f32 *)((u8 *)&v + 0) = func_0038D098(*(f32 *)((u8 *)&D_L02_001DE184[*(s16 *)(moby + 0x84)] + 0x18));
    *(f32 *)((u8 *)&v + 4) = func_0038D0B0(*(f32 *)((u8 *)&D_L02_001DE184[*(s16 *)(moby + 0x84)] + 0x18));
    *(f32 *)((u8 *)&v + 8) = 0.0f;
    ang = *(f32 *)(st + 0) * 0.017453292f * ((f32)*(s16 *)(st + 0x2E) / scale);
    type = *(s16 *)(st + 0x2C);
    if ((type != 1 && type != 7 && type != 9) || !flag) {
        func_L01_003E9250(*(s32 *)(moby + 0x94), (f32 *)&v, ang, *(f32 *)(st + 0x20) * 0.017453292f);
    }
    if (*(f32 *)(st + 0x24) != 0.0f) {
        if (*(s16 *)(st + 0x2C) == 6 || *(s16 *)(st + 0x2C) == 8) {
            func_L01_003E8BD0(*(s32 *)(moby + 0x94), 0, *(f32 *)(st + 0x24), 0.002f);
            func_L02_003C1360(*(s32 *)(moby + 0x94), *(f32 *)(st + 0x24) + 1.36f);
        } else {
            func_L01_003E8BD0(*(s32 *)(moby + 0x94), 0, *(f32 *)(st + 0x24), 0.003f);
            func_L01_003E8E70(*(s32 *)(moby + 0x94));
        }
    }
    if (*(f32 *)(st + 0x28) != 0.0f) {
        if (*(s16 *)(st + 0x2C) == 6 || *(s16 *)(st + 0x2C) == 8) {
            func_L01_003E8C28(*(s32 *)(moby + 0x94), *(f32 *)(st + 0x28), 0.002f);
        } else {
            func_L01_003E8C28(*(s32 *)(moby + 0x94), *(f32 *)(st + 0x28), 0.003f);
        }
    }
    if (*(f32 *)(st + 0x30) != 0.0f) {
        if (*(s16 *)(st + 0x2C) == 6 || *(s16 *)(st + 0x2C) == 8) {
            func_L01_003E8C70(*(s32 *)(moby + 0x94), 0, *(f32 *)(st + 0x30), 0.002f);
        } else {
            func_L01_003E8C70(*(s32 *)(moby + 0x94), 0, *(f32 *)(st + 0x30), 0.005f);
        }
    }
    if (*(f32 *)(st + 0x50) != 0.0f) {
        func_L01_003E8D48(*(s32 *)(moby + 0x94), *(f32 *)(st + 0x50) * 0.017453292f);
    }
    if (*(s16 *)(st + 0x54)) {
        hero54 = ((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(hero54 + 0x94) * 0x460))->p50;
        {
            u8 *f = *(u8 **)(hero54 + 0x70) + 0x1E0;
            *(u32 *)(f + 0x10) |= 2;
        }
    }
    if (*(s16 *)(st + 0x56)) {
        hero56 = ((Ent_003C5310 *)((u8 *)D_L02_001E1300 + *(s32 *)(hero56 + 0x94) * 0x460))->p50;
        {
            u8 *f = *(u8 **)(hero56 + 0x70) + 0x1E0;
            *(u32 *)(f + 0x10) |= 1;
        }
    }
    if (*(s16 *)(st + 0x34) == 0) {
        func_L01_003E8D80(*(s32 *)(moby + 0x94), 0);
    }
    if (*(f32 *)(st + 0x38) != 0.0f || *(f32 *)(st + 0x3C) != 0.0f) {
        if (*(s16 *)(st + 0x2E) >= 100) {
            func_L01_003E8DB8(*(s32 *)(moby + 0x94), *(f32 *)(st + 0x38), *(f32 *)(st + 0x3C));
        } else {
            f32 t = (f32)*(s16 *)(st + 0x2E) / 100.0f;
            f32 a = *(f32 *)(st + 0x40);
            f32 b = *(f32 *)(st + 0x44);
            func_L01_003E8DB8(*(s32 *)(moby + 0x94), a + (*(f32 *)(st + 0x38) - a) * t,
                              b + (*(f32 *)(st + 0x3C) - b) * t);
        }
    }
    if (*(s16 *)(st + 0x2C) == 1 || *(s16 *)(st + 0x2C) == 7 || *(s16 *)(st + 0x2C) == 10) {
        func_L01_003E8E70(*(s32 *)(moby + 0x94));
        func_L01_003E8EA8(*(s32 *)(moby + 0x94));
        func_L01_003E8E10(*(s32 *)(moby + 0x94), 0.01f, 0.2f);
    }
}
/* localdecomp:end func_L02_003C5310 */
