#include "common.h"

/* localdecomp:start func_L39_006B5288 */
void func_L39_006B5288(void *arg0, s32 arg1, s8 arg2) {
    *(s8 *)((u8 *)arg0 + 0x2B4) = arg2;
    *(s8 *)((u8 *)arg0 + 0x2B6) = 1;
    *(s32 *)((u8 *)arg0 + 0x2A8) = arg1;
    *(s32 *)((u8 *)arg0 + 0x2AC) = 0;
}
/* localdecomp:end func_L39_006B5288 */

/* localdecomp:start func_L39_006B52A0 */
typedef struct G_006B52A0 {
    u8 pad0[0x38];
    s32 *f38;
    void *f3C;
    u8 pad40[0xC];
    s32 *f4C;
} G_006B52A0;

typedef struct T_006B52A0 {
    u8 pad0[0x2AC];
    s32 f2AC;
    s32 f2B0;
    u8 f2B4;
} T_006B52A0;

extern G_006B52A0 *D_001E2050_sda;
extern char D_00248F10[];
extern char D_00248F18[];
extern void *func_L39_006D4380(void *);
extern void func_L39_006CC120(void *);
extern void func_L39_006CC4F8(void *, void *);
extern s32 func_L39_006CC350(void *, s32);
extern void func_L39_006CC158(void *, s32);
extern u8 *func_L39_006DB750(s32 *, s32);
extern void func_001200E0(s32 type, s32 n, void *s);

s32 func_L39_006B52A0(T_006B52A0 *this) {
    G_006B52A0 *g = D_001E2050_sda;
    u8 result = 0;
    s32 id = this->f2B0;
    u8 buf[0x1E0];
    s32 a, b;
    s32 idx;
    s32 *pa;
    s32 *pb;
    s32 mode;
    s32 *t;
    u8 *e;
    u8 *s;
    void *p;

    if (id >= 0 && id != *g->f4C && this->f2B4 != 0) {
        idx = id;
        if (this->f2AC == 3) {
            p = func_L39_006D4380(g->f3C);
            if (p != 0) {
                func_L39_006CC120(buf);
                func_L39_006CC4F8(buf, p);
                idx = func_L39_006CC350(buf, 2);
                func_L39_006CC158(buf, 2);
            }
        }
        e = func_L39_006DB750(g->f4C, idx);
        if (e != 0) {
            s = e + 0x1C;
            pa = &a;
            pb = &b;
            mode = 8;
            if (s[0] == 'C') {
                if (s[1] == 'Y') {
                    mode = 1;
                    ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F10, pa, pb);

                } else if (s[1] == 'R') {
                    mode = 4;
                    ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F10, pa, pb);

                } else if (s[1] == 'C') {
                    mode = 2;
                    ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F18, pa, pb);

                }
            } else if (s[0] == 'H') {
                mode = 6;
                ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F10, pa, pb);

            }
            t = g->f38;
            switch (mode) {
            case 1:
                result = 1;
                break;
            case 2:
                result = (*t == a || *t == b);
                break;
            case 4:
                result = (*t == a);
                break;
            }
        }
    }
    return result;
}
/* localdecomp:end func_L39_006B52A0 */

INCLUDE_ASM("asm/levels", func_L39_006B5498);

/* localdecomp:start func_L39_006B5D00 */
typedef struct E_006B5D00 {
    u8 pad0[0x1C];
    s32 f1C;
} E_006B5D00;

typedef struct I_006B5D00 {
    s32 f0;
    s32 count;
    E_006B5D00 **arr;
} I_006B5D00;

typedef struct L_006B5D00 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[7];
    s32 f10;
    u8 pad14[0x14];
    I_006B5D00 items[1];
} L_006B5D00;

typedef struct B_006B5D00 {
    u8 v;
} B_006B5D00;

typedef struct O_006B5D00 O_006B5D00;

typedef struct V_006B5D00 {
    u8 pad0[0x20];
    void (*f20)(O_006B5D00 *, s32, s32);
} V_006B5D00;

struct O_006B5D00 {
    u8 pad0[0x60];
    V_006B5D00 *vt;
};

typedef struct T_006B5D00 {
    u8 pad0[0x120];
    O_006B5D00 *f120;
    O_006B5D00 *f124;
    O_006B5D00 *f128;
    u8 pad12C[0x2A8 - 0x12C];
    s32 f2A8;
    u8 pad2AC[0x2D9 - 0x2AC];
    u8 f2D9;
    u8 f2DA;
    u8 pad2DB;
    s32 f2DC;
    u8 pad2E0;
    u8 f2E1;
} T_006B5D00;

typedef struct G_006B5D00 {
    u8 pad0[0x30];
    s32 *f30;
    L_006B5D00 *f34;
} G_006B5D00;

__asm__(".extern D_L39_0024D760, 16");
extern struct G_006B5F20 *D_L39_0024D760;
extern s32 func_L39_006CD768(void *);

void func_L39_006B5D00(T_006B5D00 *this) {
    G_006B5D00 *g = (G_006B5D00 *)D_L39_0024D760;
    L_006B5D00 *l = g->f34;
    I_006B5D00 *p;
    B_006B5D00 b;
    u8 found;
    s32 i;

    if (this->f2D9 != 0) {
        if (l->f8 == 0) {
            func_L39_006CD768(l);
            this->f2D9 = 0;
        }
    }
    if (l->f10 != this->f2DC) {
        this->f2DC = l->f10;
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
            this->f120->vt->f20(this->f120, 2, 0);
            this->f124->vt->f20(this->f124, 0, 0);
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
        this->f2DA = found;
        if (this->f2DA) {
            this->f120->vt->f20(this->f120, 0, 0);
            this->f124->vt->f20(this->f124, 3, 0);
        } else {
            this->f120->vt->f20(this->f120, this->f2E1 ? 2 : 3, 0);
            this->f124->vt->f20(this->f124, 0, 0);
        }
        if (this->f2E1 == 0) {
            this->f128->vt->f20(this->f128, this->f2DA ? 2 : 3, 0);
        }
    }
}
/* localdecomp:end func_L39_006B5D00 */

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

/* localdecomp:start func_L39_006B6158 */
typedef struct E_006B6158 {
    u8 pad0[0x1C];
    s32 f1C;
} E_006B6158;

typedef struct I_006B6158 {
    s32 f0;
    s32 count;
    E_006B6158 **arr;
} I_006B6158;

typedef struct M_006B6158 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[7];
    s32 f10;
    u8 pad14[4];
    I_006B6158 items[1];
} M_006B6158;

typedef struct L_006B6158 {
    s32 f0;
    u8 pad4[0x3B4 - 4];
    M_006B6158 a;
    u8 pad3D8[0x424 - 0x3D8];
    M_006B6158 b;
} L_006B6158;

typedef struct G_006B6158 {
    u8 pad0[0x38];
    L_006B6158 *f38;
} G_006B6158;

typedef struct B_006B6158 {
    u8 v;
} B_006B6158;

typedef struct T_006B6158 {
    u8 pad0[0x2A8];
    s32 f2A8;
    u8 pad2AC[0x2D8 - 0x2AC];
    u8 f2D8;
    u8 pad2D9[0x2E8 - 0x2D9];
    u8 f2E8;
    u8 pad2E9;
    u8 f2EA;
    u8 f2EB;
    s32 f2EC;
    s32 f2F0;
} T_006B6158;

struct G_006B5F20;
__asm__(".extern D_L39_0024D760, 16");
extern struct G_006B5F20 *D_L39_0024D760;
extern void func_L39_006D1658(L_006B6158 *);
extern void func_L39_006D08E8(L_006B6158 *);

void func_L39_006B6158(T_006B6158 *this) {
    L_006B6158 *l = ((G_006B6158 *)D_L39_0024D760)->f38;
    I_006B6158 *p;
    I_006B6158 *p2;
    B_006B6158 b;
    u8 found;
    u8 found2;
    s32 i;
    s32 id;

    if (this->f2E8 != 0) {
        if (l->f0 >= 0 && l->b.f8 == 0 && l->a.f8 == 0) {
            func_L39_006D1658(l);
            func_L39_006D08E8(l);
            this->f2E8 = 0;
        }
    }
    if (l->b.f10 != this->f2EC || l->a.f10 != this->f2F0) {
        b.v = 0;
        p = 0;
        if (l->a.f0 != 0 && l->a.f4 >= 0) {
            p = &l->a.items[l->a.f4];
        }
        if (p != 0) {
            if (l->a.f8 == 0) {
                b.v = 1;
            }
        }
        if (!b.v) {
            return;
        }
        b.v = 0;
        p = 0;
        if (l->b.f0 != 0 && l->b.f4 >= 0) {
            p = &l->b.items[l->b.f4];
        }
        if (p != 0) {
            if (l->b.f8 == 0) {
                b.v = 1;
            }
        }
        if (b.v) {
            found = 0;
            this->f2EC = l->b.f10;
            id = this->f2A8;
            this->f2F0 = l->a.f10;
            p = 0;
            if (l->b.f0 != 0 && l->b.f4 >= 0) {
                p = &l->b.items[l->b.f4];
            }
            if (p != 0) {
                for (i = 0; i < p->count; i++) {
                    if (p->arr[i]->f1C == id) {
                        found = 1;
                        break;
                    }
                }
            }
            this->f2EB = found;
            found2 = 0;
            id = this->f2A8;
            p2 = 0;
            if (l->a.f0 != 0 && l->a.f4 >= 0) {
                p2 = &l->a.items[l->a.f4];
            }
            if (p2 != 0) {
                for (i = 0; i < p2->count; i++) {
                    if (p2->arr[i]->f1C == id) {
                        found2 = 1;
                        break;
                    }
                }
            }
            this->f2EA = found2;
            this->f2D8 = 0;
        }
    }
}
/* localdecomp:end func_L39_006B6158 */

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
