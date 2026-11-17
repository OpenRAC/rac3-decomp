#include "common.h"

/* localdecomp:start func_L19_003BA380 */
#include "vu0.h"

extern u8 D_001A4C60[];
extern s32 D_L19_001DF240;
extern s32 D_L19_001DF758;
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern u8 *D_L19_0021C260[];
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L19_003FF028(void *, void *, void *, void *, void *, s32, s32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L19_003AEBD8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003C2880(void *);

void func_L19_003BA380(u8 *o) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    u16 *lst;
    u8 *obj;
    s32 cnt;
    s32 col;
    u16 t;
    u8 st;

    st = o[0x20];
    if (st == 0) {
        *(u16 *)(o + 0x34) |= 0x10;
        func_L01_004450F0(o, 1, -1);
    } else if (st == 1) {
        if (o[0x31] != 0 && func_00382468(0x3C) == 0) {
            func_003A52A0(0, 0, o);
            *(vu0_q *)&v30 = 0;
            *(vu0_q *)&v10 = 0;
            *(vu0_q *)&v20 = 0;
            *(vu0_q *)&v40 = 0;
            v10.y = -0.4f;
            v10.z = 11.44f;
            v20.z = 15.67f;
            v30.x = -2.0f;
            v30.y = -3.5f;
            v10.w = 1.0f;
            v20.y = -0.5f;
            v20.w = 1.0f;
            v30.z = 2.0f;
            v30.w = 1.0f;
            v40.x = 2.0f;
            v40.y = -0.5f;
            v40.w = 1.0f;
            func_L19_003FF028(o, &v10, &v20, &v30, &v40, 5, 0);
        }
        cnt = D_L19_001DF240;
        col = func_0038DBD8(0xA0000080, 0x40000040, func_0038D0B0((f32)(cnt % 50) / 50.0f * 6.2831855f - 3.1415927f) * 0.5f + 0.5f);
        *(s32 *)(o + 0x78) = col;
        if (func_L01_00447490(o, -1, 0) != 0) {
            func_L01_004450F0(o, 2, -1);
        }
    } else if (st == 2) {
        if (func_L01_004561B8(o) != 0) {
            func_003A52A0(1, 0, o);
            t = *(u16 *)(o + 0x34) & 0xFFEF;
            *(vu0_q *)&v30 = 0;
            *(vu0_q *)&v40 = 0;
            *(vu0_q *)&v10 = 0;
            *(vu0_q *)&v20 = 0;
            *(u16 *)(o + 0x34) = t;
            v10.y = -0.4f;
            v10.z = 11.44f;
            v20.z = 15.67f;
            v30.x = -4.0f;
            v30.y = -7.0f;
            v10.w = 1.0f;
            v20.y = -0.5f;
            v20.w = 1.0f;
            v30.z = 4.0f;
            v30.w = 1.0f;
            v40.x = 4.0f;
            v40.y = -0.5f;
            v40.z = -1.0f;
            v40.w = 1.0f;
            func_L19_003FF028(o, &v10, &v20, &v30, &v40, 0x28, 0);
            if (o[0x21] != 0xFF) {
                lst = (u16 *)D_L19_0021C260[o[0x21]];
                while (o[0x21] != 0xFF && D_L19_001DF758 >= o[0x21] && lst != 0 && (((s16 *)lst)[-1] >= 0 || lst == (u16 *)D_L19_0021C260[o[0x21]])) {
                    obj = D_L19_001DF71C + ((*lst & 0x7FFF) << 8);
                    if (obj == 0) {
                        break;
                    }
                    if (*(s16 *)(obj + 0xAA) == 0x1A8E) {
                        func_L19_003AEBD8(obj);
                        lst++;
                    } else {
                        lst++;
                        if (*(s16 *)(obj + 0xAA) == 0x1A77) {
                            *(s32 *)(*(u8 **)(obj + 0x68) + 0xC) = 1;
                        }
                    }
                }
            }
            vec_sub_ba(&v10, o + 0x10, D_001A4C60);
            func_0038CF68(&v10, &v10, 0.080000006f);
            func_L01_00451FE0(o, 0xFF, &v10, 1.0f, 2.0f, 0.5f, 1.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            *(u16 *)(o + 0x34) |= 0x41;
            *(s32 *)(o + 0x98) = 0;
        }
        if (*(u16 *)(o + 0x96) >= 0x65) {
            func_003C2880(o);
            return;
        }
    }
    *(u16 *)(o + 0x96) = *(u16 *)(o + 0x96) + 1;
}
/* localdecomp:end func_L19_003BA380 */

/* localdecomp:start func_L19_003BA7F8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} Info_003BA7F8;

typedef struct Moby_003BA7F8 {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    Info_003BA7F8 *info;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 f34;
    u8 pad36[0xC];
    u8 f42;
    u8 f43;
    u8 pad44[0x1C];
    u8 f60;
    u8 pad61[7];
    struct Vars_003BA7F8 *vars;
    u8 pad6C[0x2C];
    s32 f98;
} Moby_003BA7F8;

typedef struct Vars_003BA7F8 {
    Moby_003BA7F8 *child;
} Vars_003BA7F8;

typedef struct {
    vu0_v4 pos;
    vu0_v4 mid;
    u32 col[4];
    u8 pad30[0x80];
} Seg_003BA7F8;

extern s32 D_L19_001D66D4;
extern u8 D_001A4C60[];
extern Seg_003BA7F8 D_L19_002A4E30[];
extern f32 D_L19_001DE780;
extern f32 D_L19_001DE784;
extern f32 D_L19_001DE788;
extern Moby_003BA7F8 *D_L19_001DE78C;
extern s32 D_L19_001DE740;
__asm__(".extern D_L19_001DE740, 4");
__asm__(".extern D_L19_001DE780, 4");
__asm__(".extern D_L19_001DE784, 4");
__asm__(".extern D_L19_001DE788, 4");
__asm__(".extern D_L19_001DE78C, 4");

extern void func_L01_004AA7E8(void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0040C7A0(void *, void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_0040C8A0(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L19_003BACA0(void);

void func_L19_003BA7F8(Moby_003BA7F8 *m) {
    Vars_003BA7F8 *vars = m->vars;
    Seg_003BA7F8 *p;
    Moby_003BA7F8 *c;
    vu0_v4 sum;
    vu0_v4 *q;
    s32 i;
    f32 f;

    if (D_L19_001D66D4 == 2) {
        m->f98 = 0;
        m->f34 = (m->f34 | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
    } else {
        m->f34 &= 0xFFBE;
        m->f34 |= m->info->f44 & 0x1000;
        m->f98 = m->info->f10;
    }

    switch (m->state) {
    case 0:
        f = func_003C3D30(&m->pos, 0, 0, 0.5f);
        m->f2C = m->f2C * D_L19_001DE788;
        m->pos.z = f + D_L19_001DE784 * D_L19_001DE788;
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(m) != 0) {
            if (m->f43 != 0) {
                func_003C3A10(m, 0, 0, 0);
            }
            c = vars->child;
            if (c != 0) {
                c->f34 |= 0x41;
                vars->child->f34 &= 0xEFFF;
                vars->child->f98 = 0;
                func_L01_004AA7E8(vars->child, 1);
                vars->child->f34 |= 2;
            }
        } else if (func_L01_0040E570(D_001A4C60, &m->pos) < D_L19_001DE780) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(m) != 0) {
            if (m->f43 != 1) {
                func_003C3A10(m, 1, 0, 0);
            }
        } else if (m->f42 == m->f43 && (m->f60 & 2)) {
            if (m->f43 != 2) {
                func_003C3A10(m, 2, 0, 0);
            }
            func_L01_004450F0(m, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(m) != 0) {
            if (m->f43 != 2) {
                func_003C3A10(m, 2, 0, 0);
            }
        } else {
            c = vars->child;
            if (c != 0) {
                c->f34 |= 0x41;
                vars->child->f34 &= 0xEFFF;
                vars->child->f98 = 0;
                func_L01_004AA7E8(vars->child, 1);
                func_L01_004450F0(m, 4, -1);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            if (m->f43 != 3) {
                func_003C3A10(m, 3, 0, 0);
            }
            qzero(&sum);
            for (i = 0; i < 3; i++) {
                p = &D_L19_002A4E30[i];
                func_L01_0040C7A0(p, &D_L19_001DE740);
                p->col[0] = 0x40606060;
                p->col[1] = 0x40706020;
                p->col[2] = 0x40606000;
                p->col[3] = 0x40403040;
                func_003C2F58(m, i, p);
                q = &p->pos;
                vec_add_ab(&sum, &sum, q);
            }
            func_0038CE20(&sum, &sum, 0.33333334f);
            for (i = 0; i < 3; i++) {
                q = &D_L19_002A4E30[i].mid;
                *q = sum;
            }
            D_L19_001DE78C = m;
        } else if (m->f42 == m->f43 && (m->f60 & 2)) {
            func_003C2F58(m, 3, &vars->child->pos);
            vars->child->f34 &= 0xFFBE;
            vars->child->f34 |= vars->child->info->f44 & 0x1000;
            vars->child->f98 = vars->child->info->f10;
            vars->child->f34 &= 0xFFFD;
            vars->child = 0;
            func_L01_00456230(m, 1);
            if (m->f43 != 2) {
                func_003C3A10(m, 2, 0, 0);
            }
            func_L01_004450F0(m, 3, -1);
        } else if (D_L19_001DE78C == m) {
            p = D_L19_002A4E30;
            for (i = 0; i < 3; i++) {
                func_003C2F58(m, i, p);
                func_L01_0040C8A0(p, &D_L19_001DE740);
                p++;
            }
            func_L01_00404808(func_L19_003BACA0, m);
        }
        break;
    }
}
/* localdecomp:end func_L19_003BA7F8 */

/* localdecomp:start func_L19_003BACA0 */
/* log: one e pointer: 66 diff (both i*0xB0 mults CSEd into one); pts[j] indexed off the table: 2 diff (a0/s2 swap);
   vperm: the table element written out again in each use, (&D_L19_002A4E30_003BACA0[i])->: MATCH */
typedef struct {
    f32 v[4];
} V_003BACA0;
typedef union {
    V_003BACA0 pts[11];
    struct {
        u8 pad0[0x20];
        s32 x20;
        u8 pad24[4];
        s32 x28;
    } s;
} S_003BACA0;
extern S_003BACA0 D_L19_002A4E30_003BACA0[];
extern s32 D_L19_001DE740;
extern s32 D_L19_001DE790;
extern f32 D_L19_001DE794;
extern f32 D_L19_001DE798;
__asm__(".extern D_L19_001DE740, 4");
__asm__(".extern D_L19_001DE790, 4");
__asm__(".extern D_L19_001DE794, 4");
__asm__(".extern D_L19_001DE798, 4");
extern void func_L01_0040C948(void *, void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L19_003BACA0(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 3; i++) {
        func_L01_0040C948(&D_L19_002A4E30_003BACA0[i], &D_L19_001DE740);
        for (j = 0; j < 2; j++) {
            u32 col = func_0038DBD8((&D_L19_002A4E30_003BACA0[i])->s.x20, (&D_L19_002A4E30_003BACA0[i])->s.x28, func_003824E0(0.0f, 1.0f)) | 0x60000000;
            f32 s = D_L19_001DE798 * func_003824E0(0.75f, 1.25f);

            func_003D9508(&D_L19_002A4E30_003BACA0[i].pts[j], D_L19_001DE790, col, 1, s, D_L19_001DE794, func_00382538());
        }
    }
}
/* localdecomp:end func_L19_003BACA0 */
