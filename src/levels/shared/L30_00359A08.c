#include "common.h"

typedef struct Ent_00359D78 {
    u8 pad[0x20];
    u8 type;
    u8 pad2[0xDF];
} Ent_00359D78;
typedef struct Obj_00359D78 {
    u8 pad[4];
    s32 i4;
    s32 i8;
    u8 pad2[0x94];
    s32 fA0[3];
} Obj_00359D78;

/* localdecomp:start func_L30_00359A08 */
#include "vu0.h"

typedef struct Obj_00359A08 {
    u8 pad[4];
    s32 i4;
    s32 i8;
    s32 iC;
    s32 i10;
    u8 pad14[0x40 - 0x14];
    s32 i40;
    s32 i44;
    u8 pad48[0xA4 - 0x48];
    s32 iA4;
    s32 iA8;
    s32 iAC;
    u8 padB0[0xC0 - 0xB0];
    vu0_v4 vC0;
    f32 fD0;
    u8 padD4[4];
    s32 iD8;
    s32 iDC;
} Obj_00359A08;
typedef struct Ent_00359A08 {
    u8 pad[0x30];
    vu0_v4 v30;
    u8 pad40[0x40];
} Ent_00359A08;
typedef struct Cam_00359A08 {
    u8 pad[0x80];
    vu0_v4 v80;
} Cam_00359A08;
extern Cam_00359A08 D_001A4BE0;
__asm__(".extern D_L30_001E1440, 16");
__asm__(".extern D_L30_001E1450, 16");
extern vu0_v4 D_L30_001E1440 __attribute__((section(".sdata")));
extern vu0_v4 D_L30_001E1450 __attribute__((section(".sdata")));
extern Ent_00359A08 *D_L30_001DF800;
__asm__(".extern D_L30_001DDB08, 4");
extern f32 D_L30_001DDB08;
extern u8 D_00142660[];
extern u8 D_L30_001E2240[];
extern Ent_00359D78 *D_L30_001DF71C;
extern void func_L30_00359D78(u8 *);
extern void func_L30_00358A18(void);
extern void func_L01_00404A10(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00456230(void *, s32);

void func_L30_00359A08(u8 *m) {
    Obj_00359A08 *v = *(Obj_00359A08 **)(m + 0x68);
    vu0_v4 d __attribute__((aligned(16)));
    f32 y;

    if (v->iAC != 0) {
        func_L30_00359D78(m);
        return;
    }
    *(vu0_q *)&D_L30_001E1440 = *(vu0_q *)D_L30_001E2240;
    D_L30_001E1440.y = D_001A4BE0.v80.y;
    if (v->iA4 == 1 || v->iA8 == 1) {
        func_L01_00404A10(func_L30_00358A18, m);
        v->fD0 = 1.2f - fabs_asm((f32)(v->iD8 / 2 - v->iDC)) / 150.0f;
        *(vu0_q *)&D_L30_001E1440 = *(vu0_q *)&D_001A4BE0.v80;
        if (v->fD0 > 1.0f) {
            v->fD0 = 1.0f;
        } else if (v->fD0 < 0.0f) {
            v->fD0 = 0.0f;
        }
        if (v->iDC < (s32)((f32)v->iD8 * 0.5f)) {
            vec_sub_ba(&d, &D_L30_001E1450, &v->vC0);
            y = D_001A4BE0.v80.y;
            func_0038CE20(&d, &d,
                fabs_asm(D_L30_001DF800[v->i44].v30.y - y + D_L30_001DDB08) /
                fabs_asm(v->vC0.y - y + D_L30_001DDB08));
            vec_add_ba(&D_L30_001E1450, &D_L30_001DF800[v->i44].v30, &d);
            v->vC0 = D_L30_001DF800[v->i44].v30;
            if (v->iA4 == 1) {
                v->iA4 = 2;
                func_L01_00456230(&D_L30_001DF71C[v->iC], 1);
                D_00142660[0x77] |= 2;
            }
            if (v->iA8 == 1) {
                v->iA8 = 2;
                func_L01_00456230(&D_L30_001DF71C[v->i10], 1);
                D_00142660[0x77] |= 4;
            }
            D_001A4BE0.v80 = D_L30_001DF800[v->i40].v30;
        }
    } else if (v->iA4 == 2 || v->iA8 == 2) {
        if (v->iDC >= 3) {
            func_L01_00404A10(func_L30_00358A18, m);
        }
        v->fD0 = 1.2f - fabs_asm((f32)(v->iD8 / 2 - v->iDC)) / 150.0f;
        if (v->fD0 > 1.0f) {
            v->fD0 = 1.0f;
        } else if (v->fD0 < 0.0f) {
            v->fD0 = 0.0f;
        }
    }
}
/* localdecomp:end func_L30_00359A08 */
