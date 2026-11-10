#include "common.h"

/* localdecomp:start func_L39_006B5288 */
void func_L39_006B5288(void *arg0, s32 arg1, s8 arg2) {
    *(s8 *)((u8 *)arg0 + 0x2B4) = arg2;
    *(s8 *)((u8 *)arg0 + 0x2B6) = 1;
    *(s32 *)((u8 *)arg0 + 0x2A8) = arg1;
    *(s32 *)((u8 *)arg0 + 0x2AC) = 0;
}
/* localdecomp:end func_L39_006B5288 */

INCLUDE_ASM("asm/levels", func_L39_006B52A0);

INCLUDE_ASM("asm/levels", func_L39_006B5498);

INCLUDE_ASM("asm/levels", func_L39_006B5D00);

/* localdecomp:start func_L39_006B5F20 */
typedef struct E_006B5F20 {
    u8 pad0[0x1C];
    s32 f1C;
} E_006B5F20;

typedef struct I_006B5F20 {
    s32 f0;
    s32 count;
    E_006B5F20 **arr;
} I_006B5F20;

typedef struct L_006B5F20 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[7];
    s32 f10;
    u8 pad14[0x14];
    I_006B5F20 items[1];
} L_006B5F20;

typedef struct G_006B5F20 {
    u8 pad0[0x30];
    s32 *f30;
    u8 pad34[0xC];
    L_006B5F20 *f40;
} G_006B5F20;

/* The flag below lives in a byte-wide register in retail (it is zero-extended before its test and
 * set by a branch, not by sltiu); a plain u8 or s32 local is widened and folds to sltiu. */
typedef struct B_006B5F20 {
    u8 v;
} B_006B5F20;

typedef struct O_006B5F20 O_006B5F20;

typedef struct V_006B5F20 {
    u8 pad0[0x20];
    void (*f20)(O_006B5F20 *, s32, s32);
} V_006B5F20;

struct O_006B5F20 {
    u8 pad0[0x60];
    V_006B5F20 *vt;
};

typedef struct T_006B5F20 {
    u8 pad0[0x11C];
    O_006B5F20 *f11C;
    O_006B5F20 *f120;
    u8 pad124[4];
    O_006B5F20 *f128;
    O_006B5F20 *f12C;
    u8 pad130[0x2A8 - 0x130];
    s32 f2A8;
    u8 pad2AC[0x2DA - 0x2AC];
    u8 f2DA;
    u8 pad2DB[5];
    u8 f2E0;
    u8 f2E1;
    u8 pad2E2[2];
    s32 f2E4;
} T_006B5F20;

__asm__(".extern D_L39_0024D760, 16");
extern G_006B5F20 *D_L39_0024D760;
extern void func_L39_006D5D68(L_006B5F20 *);

void func_L39_006B5F20(T_006B5F20 *this) {
    G_006B5F20 *g = D_L39_0024D760;
    L_006B5F20 *l = g->f40;
    I_006B5F20 *p;
    B_006B5F20 b;
    u8 found;
    s32 i;

    if (this->f2E0 != 0) {
        if (l->f8 == 0) {
            func_L39_006D5D68(l);
            this->f2E0 = 0;
        }
    }
    if (l->f10 != this->f2E4) {
        this->f2E4 = l->f10;
        b.v = 0;
        p = 0;
        if (l->f0 != 0 && l->f4 >= 0) {
            p = &l->items[l->f4];
        }
        if (p != 0) {
            if (l->f8 == 0) {
                b.v = 1;
            }
        }
        if (!b.v || *g->f30 == this->f2A8) {
            this->f128->vt->f20(this->f128, 2, 0);
            this->f12C->vt->f20(this->f12C, 0, 0);
            return;
        }
        found = 0;
        p = 0;
        if (l->f0 != 0 && l->f4 >= 0) {
            p = &l->items[l->f4];
        }
        if (p != 0) {
            for (i = 0; i < p->count; i++) {
                if (p->arr[i]->f1C == this->f2A8) {
                    found = 1;
                    break;
                }
            }
        }
        this->f2E1 = found;
        if (this->f2E1) {
            this->f128->vt->f20(this->f128, 0, 0);
            this->f12C->vt->f20(this->f12C, 3, 0);
            this->f11C->vt->f20(this->f11C, 2, 0);
        } else {
            this->f128->vt->f20(this->f128, this->f2DA ? 2 : 3, 0);
            this->f12C->vt->f20(this->f12C, 0, 0);
        }
        if (this->f2DA == 0) {
            this->f120->vt->f20(this->f120, this->f2E1 ? 2 : 3, 0);
        }
    }
}
/* localdecomp:end func_L39_006B5F20 */

INCLUDE_ASM("asm/levels", func_L39_006B6158);

LINKER_REMNANT("asm/levels", func_L39_006B6388);

INCLUDE_ASM("asm/levels", func_L39_006B63B8);

LINKER_REMNANT("asm/levels", func_L39_006B6648);

/* localdecomp:start func_L39_006B6650 */
extern u8 D_L39_0047E540[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B6650(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E540;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B6650 */

/* localdecomp:start func_L39_006B6678 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots 0x111C..0x112C. */
extern f32 D_001DD9CC_sda;
extern f32 D_001DD9D0_sda;
extern f32 D_001DD9D4_sda;
extern f32 D_001DD9D8_sda;
extern f32 D_001DD9DC_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_006B6678(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DD9CC_sda, D_001DD9D0_sda, D_001DD9D4_sda, D_001DD9D8_sda, D_001DD9DC_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_006B6678 */
