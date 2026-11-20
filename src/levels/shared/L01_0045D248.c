#include "common.h"
#include "vu0.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;

/* localdecomp:start func_L01_0045D248 */
extern S_4574A0 *func_L01_0045B958(M_4574A0 *);
extern s32 D_L01_001DFB40;
extern void func_0038D5B0(void *, void *);
extern void func_L01_0045D4B8(u8 *, u8 *, s32);
extern void func_L01_0045E1B8(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0045B908(u8 *, u8 *);
extern void func_L01_0045B8D8(u8 *, u8 *);
extern void func_L01_0045D5C0(u8 *, u8 *);
extern void func_L01_0045D788(u8 *, u8 *, u8 *, s32, void *, void *, void *);
extern void func_L01_0045DA60(u8 *, u8 *, void *, void *);
extern void func_L01_0045DBF0(u8 *, u8 *, u8 *, void *);
extern void func_0038CF68(f32, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern u8 D_L01_001EAA00[];
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);


s32 func_L01_0045D248(u8 *a, u8 *b, s32 c) {
    u8 *o;
    f32 m[16];
    f32 v1[4];
    f32 v2[12];
    f32 *mp;
    f32 v3[4];
    f32 v4[4];
    f32 v5[4];
    f32 v6[4];

    o = ((u8 * (*)(u8 *))func_L01_0045B958)(a);
    if (o == 0) {
        return 8;
    }
    if (D_L01_001DFB40 != *(s32 *)(o + 0xBC)) {
        func_0038D5B0(m, a + 0xC0);
        mp = m;
        func_L01_0045D4B8(a, (u8 *)v1, 0);
        func_L01_0045E1B8(a + 0xC0, v1, v2);
        func_0038D000(o + 0xA0, o + 0xA0, v2);
        *(s32 *)(o + 0x98) = *(s32 *)(o + 0x94);
        *(s32 *)(o + 0x94) = 0;
        func_L01_0045B908(a, o);
        func_L01_0045B8D8(a, o);
        if (D_L01_001DFB40 - *(s32 *)(o + 0xBC) >= 2 || *(s32 *)(o + 0xBC) == 0) {
            func_L01_0045D5C0(a, o);
            *(s32 *)(o + 0xB4) = 0;
            *(u8 *)(o + 0xEA) = 0xFF;
            *(s32 *)(o + 0x9C) |= -3;
            qzero(o + 0xA0);
        }
        *(s32 *)(o + 0xBC) = D_L01_001DFB40;
        func_L01_0045D788(a, o, b, c, v3, v4, mp);
        func_L01_0045DA60(a, o, v4, mp);
        func_L01_0045DBF0(a, o, b, mp);
        if (*(s32 *)(o + 0x38) & 0x400) {
            return *(s32 *)(o + 0x94);
        }
        func_0038CF68(0.1f, v5, a + 0xE0);
        func_0038CF68(-3.0f, v6, a + 0xE0);
        vec_add_ba(v5, v5, a + 0x10);
        vec_add_ba(v6, v6, a + 0x10);
        if (func_0038CE68(D_L01_001EAA00 + 0x40, a + 0xE0) > 0.7f) {
            if (func_003D3CB0(v5, v6, 2, a, 0) != 0) {
                *(vu0_q *)(a + 0x10) = *(vu0_q *)(D_L01_001EAA00 + 0x20);
            }
        }
    }
    return *(s32 *)(o + 0x94);
}
/* localdecomp:end func_L01_0045D248 */

LINKER_REMNANT("asm/levels", func_L01_0045D4A8);

/* localdecomp:start func_L01_0045D4B8 */
#include "vu0.h"

extern void func_0038CF68(f32, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern void func_0038CE20(void *, void *, float);
extern u8 D_L01_001EAA00_0045D4B8[];

void func_L01_0045D4B8(u8 *a, u8 *b, s32 c) {
    f32 v1[4];
    f32 v2[4];

    func_0038CF68(0.4f, v1, a + 0xE0);
    func_0038CF68(-3.0f, v2, a + 0xE0);
    vec_add_ba(v1, v1, a + 0x10);
    vec_add_ba(v2, v2, a + 0x10);
    if (func_003D3CB0(v1, v2, 2, a, 0) != 0) {
        func_0038CF68(1.0f, b, D_L01_001EAA00_0045D4B8 + 0x40);
    } else {
        func_0038CF68(-1.0f, b, a + 0xE0);
    }
    if (c == 0) {
        func_0038CE20((f32 *)b, (f32 *)b, -1.0f);
    }
}
/* localdecomp:end func_L01_0045D4B8 */

INCLUDE_ASM("asm/levels", func_L01_0045D5C0);

/* localdecomp:start func_L01_0045D728 */
extern f32 func_0038CED8(u8 *);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);

f32 func_L01_0045D728(u8 *a0, void *a1) {
    f32 v[4];
    f32 m[12];
    func_L01_0040EE50(m, a0 + 192);
    func_0038D000(v, a1, m);
    return func_0038D160(v[2], ((f32 (*)(void *))func_0038CED8)(v));
}
/* localdecomp:end func_L01_0045D728 */

/* localdecomp:start func_L01_0045D788 */

extern f32 func_L01_0045E010_0045D788(char *, char *, vu0_v4 *, int);
extern f32 func_L01_00451738_0045D788(u8 *, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_00451020_0045D788(u8 *, void *, f32);
extern void func_0038CF68(f32, void *, void *);
extern void func_L01_004510A8_0045D788(u8 *, void *, void *, f32, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C4BB0(void *, f32);
extern f32 func_L01_004510F8_0045D788(u8 *, void *, void *);
extern void func_L01_00451388_0045D788(u8 *, void *, void *, f32);
extern f32 func_003C50E8(u8 *, u8 *, void *);
extern void func_003C4360(f32 *, f32, f32, f32, f32);

void func_L01_0045D788(u8 *a, u8 *o, u8 *b, s32 c, void *e, void *f, void *mp) {
    vu0_v4 t;
    vu0_v4 u;
    f32 w;
    f32 d;
    f32 s;

    if (!(*(s32 *)(o + 0x38) & 0x10)) {
        func_L01_0045E010_0045D788((char *)a, (char *)o, (vu0_v4 *)c, (int)mp);
    }
    d = 0.0f;
    if (!(*(s32 *)(o + 0x38) & 0x10)) {
        d = func_L01_00451738_0045D788(a, (void *)c, mp);
    }
    if (*(f32 *)(o + 0x30) < d) {
        qzero(&t);
        *(s32 *)(o + 0x9C) |= 2;
    } else {
        *(s32 *)(o + 0x9C) &= ~2;
        *(f32 *)(o + 0xCC) = func_0038CF00(a + 0x10, b);
        if (*(f32 *)(o + 0xCC) <= *(f32 *)(o + 0x34)) {
            qzero(&t);
        } else {
            s = sqrt_asm((*(f32 *)(o + 0xCC) - *(f32 *)(o + 0x34)) * 2.0f * *(f32 *)(o + 0x24));
            if (*(f32 *)(o + 0x28) < s) {
                s = *(f32 *)(o + 0x28);
            }
            func_L01_00451020_0045D788(a, &t, s);
        }
        if (*(s32 *)(o + 0x38) & 0x10) {
            func_0038CF68(sqrt_asm((*(f32 *)(o + 0xCC) - *(f32 *)(o + 0x34)) * 2.0f * *(f32 *)(o + 0x24)), &t, (void *)c);
        }
    }
    vec_sub_ab(&u, &t, o + 0xA0);
    func_L01_004510A8_0045D788(a, &u, &u, 0.0f, mp);
    if (0.0f < func_0038CE68(&t, o + 0xA0)) {
        func_003C4BB0(&u, *(f32 *)(o + 0x20));
    } else {
        func_003C4BB0(&u, *(f32 *)(o + 0x24));
    }
    vec_add_ab(o + 0xA0, o + 0xA0, &u);
    *(f32 *)(o + 0xB0) = func_L01_004510F8_0045D788(a, o + 0xA0, mp);
    if (!(*(s32 *)(o + 0x38) & 4)) {
        if (*(f32 *)(o + 0x90) < 0.0f) {
            func_L01_00451388_0045D788(a, o + 0xA0, o + 0xA0, *(f32 *)(o + 0x2C));
            if (*(s16 *)(o + 0xC0) == 0) {
                *(s32 *)(o + 0x94) |= 0x20;
            }
        } else {
            w = func_003C50E8(a, o + 0xA0, mp);
            if (*(f32 *)(o + 0x90) < w) {
                w = *(f32 *)(o + 0x90);
            } else if (w < 0.0f) {
                w = 0.0f;
            }
            func_003C4360(&w, *(f32 *)(o + 0x90), 0.016f, 0.016f, 1.0f);
            func_L01_004510A8_0045D788(a, o + 0xA0, o + 0xA0, w, mp);
        }
    }
}
/* localdecomp:end func_L01_0045D788 */

INCLUDE_ASM("asm/levels", func_L01_0045DA60);

/* localdecomp:start func_L01_0045DBF0 */
extern void func_L01_0045D5C0(u8 *, u8 *);
extern f32 func_L01_0045D728(u8 *, void *);
extern u8 *func_L01_00448FF0(u8 *);
extern void func_L01_0045B8F0(u8 *, u8 *);
extern void func_L01_0045D4B8(u8 *, u8 *, s32);
extern f32 func_003C50E8(u8 *, u8 *, void *);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern f32 func_0038CF00(void *, void *);
extern u8 D_L01_001EAA20_0045DBF0[];
extern s32 D_001D545C;

void func_L01_0045DBF0(u8 *a, u8 *o, u8 *b, void *mp) {
    f32 m[4];
    f32 v10[4];
    f32 v20[4];
    f32 v30[4];
    f32 v40[4];
    s32 flag;
    s32 ok;
    u8 *p;
    u8 *q;
    f32 f;

    flag = 0;
    func_L01_0045D5C0(a, o);
    if (*(f32 *)(o + 8) < fabs_asm(*(f32 *)(o + 0x90))) {
        if (D_001D545C != 0x16 && D_001D545C != 0xD && *(s16 *)(a + 0xAA) != 0x16E5) {
            flag = 1;
            *(s32 *)(o + 0x94) |= 2;
        }
    }
    if (((*(u8 *)(o + 0x38) ^ 1) & 1) && *(s16 *)(o + 0xC2) < 5) {
        if (*(f32 *)(o + 0x90) < -*(f32 *)(o + 0xC)) {
            flag = 1;
            *(s32 *)(o + 0x94) |= 1;
        }
    }
    if (*(s16 *)(o + 0xC0) != 0) {
        f = func_L01_0045D728(a, o + 0x50);
        if (*(f32 *)(o + 0x10) < f) {
            flag = 1;
            *(s32 *)(o + 0x94) |= 4;
        }
    }
    if (*(s32 *)(o + 0xD8) != -1 && *(s16 *)(o + 0xC0) != 0) {
        p = func_L01_00448FF0(a);
        if (p != 0 && *(u8 *)(p + 0x49) != 0 && *(u16 *)(p + 0x4A) != 0 &&
            ((*(u16 *)(p + 0x4A) >> *(s32 *)(o + 0xD8)) & 1)) {
            flag = 1;
            *(s32 *)(o + 0x94) |= 0x200;
        }
    }
    if (flag) {
        func_L01_0045B8F0(a, o);
        func_L01_0045D5C0(a, o);
    }
    ok = 1;
    func_L01_0045D4B8(a, (u8 *)m, 1);
    func_0038CF68(0.05f, v10, m);
    func_0038CF68(-*(f32 *)(o + 0xC) - 0.1f, v20, m);
    vec_add_ba(v10, v10, a + 0x10);
    vec_add_ba(v20, v20, a + 0x10);
    if (func_003D3CB0(v10, v20, 0, a, 0) != 0) {
        func_0038CF68(1.0f, v40, m);
        vec_sub_ba(v30, D_L01_001EAA20_0045DBF0, a + 0x10);
        if (func_0038CE68(v40, v30) != *(f32 *)(o + 0x90)) {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    if (ok == 0) {
        f = func_003C50E8(a, o + 0xA0, mp);
        q = a + 0x10;
        if (f <= *(f32 *)(o + 0x90)) {
            func_L01_00450E48(a, q, 0.0f, 0.0f, -*(f32 *)(o + 0x90));
        }
        *(s16 *)(o + 0xC2) = 0;
        *(s16 *)(o + 0xC0) = *(s16 *)(o + 0xC0) + 1;
    } else {
        q = a + 0x10;
        if (*(f32 *)(o + 0x90) < -*(f32 *)(o + 0xC)) {
            *(s16 *)(o + 0xC0) = 0;
            *(s16 *)(o + 0xC2) = *(s16 *)(o + 0xC2) + 1;
        }
    }
    f = func_0038CF00(q, b);
    *(f32 *)(o + 0xCC) = f;
    if (f <= *(f32 *)(o + 0x34)) {
        *(s32 *)(o + 0x94) |= 0x80;
    }
}
/* localdecomp:end func_L01_0045DBF0 */

INCLUDE_ASM("asm/levels", func_L01_0045DF48);

/* localdecomp:start func_L01_0045E010 */
#include "vu0.h"

extern float func_L01_00451700_0045E010(void*,void*,int);
extern float func_L01_00448890_0045E010(void*,void*,int,float,float,float,float);
extern void func_0038D308(void*,void*);
extern void func_0038D5F0(void*,void*,void*);
float func_L01_0045E010(char *m,char *state,vu0_v4 *input,int mode) {
 vu0_v4 v; float matrix[12] __attribute__((aligned(16)));int zero;float angle;
 v=*input;
 angle=func_L01_00451700_0045E010(m,&v,mode);
 zero=0;
 func_L01_00448890_0045E010(&zero,state+0xb4,0,angle,0.005026548635214567f,0.005026548635214567f,0.3574434518814087f);
 qzero(&v);
 v.z=*(float*)(state+0xb4);
 func_0038D308(matrix,&v);
 func_0038D5F0(m+0xc0,m+0xc0,matrix);
 return fabs_asm(angle)-fabs_asm(*(float*)(state+0xb4));
}
/* localdecomp:end func_L01_0045E010 */

/* localdecomp:start func_L01_0045E0D8 */
#include "vu0.h"

extern void func_0038CF68(f32, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, float);
extern f32 func_0038CEA8(void *);
extern void func_0038D810(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CC88(void *, void *, s32);

void func_L01_0045E0D8(void *a0, void *a1, void *a2) {
    f32 m[12];
    f32 q[4];
    f32 v[4];
    f32 one = 1.0f;
    f32 d;

    func_0038CF68(one, v, a1);
    func_0038CE90(q, v, (u8 *)a0 + 0x20);
    func_0038CE20(q, q, 0.05f);
    d = func_0038CEA8(q);
    q[3] = -sqrt_asm(one - d * d);
    func_0038D810(q, m);
    func_0038D5F0(a0, m, a0);
    if (a2 != 0) {
        func_0038CC88(a2, m, 0x30);
    }
}
/* localdecomp:end func_L01_0045E0D8 */

/* localdecomp:start func_L01_0045E1B8 */
extern void func_0038CE20(void *, void *, float);
extern void func_L01_0045E0D8(void *, void *, void *);
void func_L01_0045E0D8(void *a0, void *a1, void *a2);

/* from rac2-decomp's func_002B03B8, renamed */
void func_L01_0045E1B8(void *first, void *second, void *third) {
    float vector[4];
    func_0038CE20(vector, second, -1.0f);
    func_L01_0045E0D8(first, vector, third);
}
/* localdecomp:end func_L01_0045E1B8 */
