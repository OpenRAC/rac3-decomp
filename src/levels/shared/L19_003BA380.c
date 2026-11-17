#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003BA380);

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

INCLUDE_ASM("asm/levels", func_L19_003BACA0);
