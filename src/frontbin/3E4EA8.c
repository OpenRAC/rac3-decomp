#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E5520(void);
extern void func_003E55B8(void);
extern void func_003E54E0(s32);
extern void func_003E5070(f32 *, f32);
extern s32 func_003E5090(s32);
extern s32 func_003E51F8(s32);
extern s32 func_003E5360(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E4D10.c's earlier functions */
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
extern S_3DF038 D_001DA938[];
extern u8 D_001D9554;
extern u8 D_001D9566;
extern s32 D_001D9550;
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E4F30(s32);
extern void func_003E4EA8();

/* localdecomp:start func_003E4EA8 */
extern s32 D_001D9550;
extern u8 D_001D9566;
extern void func_003E4D70(s32);
extern void func_003E3E40(void);
extern void func_003E4440(void);
extern void func_003E4508(void);
extern s32 func_003E7838(s32, s32, s32);
void func_003E4EA8(void) {
    if (D_001D9550 != 0 && D_001D9566 == 0) {
        D_001D9550--;
        func_003E4D70(0x90000);
        func_003E3E40();
        func_003E4440();
        func_003E4508();
    } else {
        func_003E7838(0x90000, 1, 0);
    }
}
/* localdecomp:end func_003E4EA8 */

/* localdecomp:start func_003E4F10 */
extern u8 D_001D9554;
extern s32 func_003E85A8();
void func_003E4F10(void) {
    D_001D9554 = 0;
    func_003E85A8(7);
}
/* localdecomp:end func_003E4F10 */

/* localdecomp:start func_003E4F30 */
typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_003E4588(s32);
extern void func_003E4F10(void);
extern void func_003E4EA8(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001DA780;
extern s32 D_001DA7A0;
extern s32 D_001DA7C0;
extern s32 D_001DA7E0;
extern s32 D_001DA768[2];
extern s32 D_001DA788[2];
extern s32 D_001DA7A8[2];
extern s32 D_001DA7C8[2];
extern V16_3DF9E0 D_001D9568[];
s32 func_003E4F30(s32 idx) {
    V16_3DF9E0 v;
    if (D_001DA780 == 0) {
        func_003E6FA0(D_001DA768, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA780 = 1;
    }
    if (D_001DA7A0 == 0) {
        func_003E6FA0(D_001DA788, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA7A0 = 1;
    }
    if (D_001DA7C0 == 0) {
        func_003E6FA0(D_001DA7A8, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA7C0 = 1;
    }
    if (D_001DA7E0 == 0) {
        func_003E6FA0(D_001DA7C8, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA7E0 = 1;
    }
    v = D_001D9568[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_003E4F30 */

/* localdecomp:start func_003E5070 */
void func_003E5070(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
/* localdecomp:end func_003E5070 */

/* localdecomp:start func_003E5090 */
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6CC0();
extern s32 func_003E58F8();
extern void func_003E6348(void **, s32, s32);
extern void *func_003F1CA8();
extern s32 func_003F2388();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
s32 func_003E5090(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938;
    if (!q->x4) q = func_003E6C08();
    obj = func_003E6DE8(q);
    func_003E73A0(0x48);
    vv = func_003E73A8();
    if (obj != 0) {
        if (func_003E58F8(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6C08(p);
            t1 = func_003E6CC0(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F1CA8(func_003F2388(0x48, e));
                r = ((s32 (*)())func_003E6348)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6C08(p);
                    w = func_003E6CC0(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5090 */

/* localdecomp:start func_003E51F8 */
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6CC0();
extern s32 func_003E58F8();
extern void func_003E6348(void **, s32, s32);
extern void *func_003EF110();
extern s32 func_003F2388();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
s32 func_003E51F8(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938;
    if (!q->x4) q = func_003E6C08();
    obj = func_003E6DE8(q);
    func_003E73A0(0x54);
    vv = func_003E73A8();
    if (obj != 0) {
        if (func_003E58F8(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6C08(p);
            t1 = func_003E6CC0(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EF110(func_003F2388(0x54, e));
                r = ((s32 (*)())func_003E6348)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6C08(p);
                    w = func_003E6CC0(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E51F8 */

/* localdecomp:start func_003E5360 */
typedef struct { u8 pad[8]; s32 (*f8)(); s32 (*fC)(); } VT_3DFE10;
typedef struct { VT_3DFE10 *vt; } O_3DFE10;
typedef struct { u8 pad[8]; VT_3DFE10 *vt; } D_3E5360;
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern void func_003E73A0(s32);
extern s32 func_003E73A8(void);
extern s32 func_003E58F8();
extern s32 func_003E6CC0();
extern s32 func_003F2388(s32, s32);
extern void *func_003EFF18();
extern void func_003E6348(void **, s32, s32);
s32 func_003E5360(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 a, b, c, r;
    D_3E5360 *d;
    O_3DFE10 *o;
    r = 0;
    q = D_001DA938;
    if (!q->x4) q = func_003E6C08();
    a = func_003E6DE8(q);
    func_003E73A0(0x64);
    b = func_003E73A8();
    if (a != 0) {
        if (func_003E58F8(a, arg0) == 0) {
            p = D_001DA938;
            if (p->x4) q = p; else q = func_003E6C08(p);
            o = (O_3DFE10 *)func_003E6CC0(q, 1);
            c = o->vt->f8(o, b);
            if (c != 0) {
                d = func_003EFF18(func_003F2388(0x64, c));
                r = ((s32 (*)())func_003E6348)(a, d, arg0) != 0;
                if (r == 0) {
                    ((void (*)())d->vt->f8)(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p; else q = func_003E6C08(p);
                    o = (O_3DFE10 *)func_003E6CC0(q, 1);
                    o->vt->fC(o, c);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5360 */

LINKER_REMNANT("asm/remnants", func_003E54C8);

/* localdecomp:start func_003E54E0 */
extern u8 D_001D9580;
extern s32 D_001D9578;
extern s32 func_003E7838(s32, s32, s32);
void func_003E54E0(s32 a) {
    if (D_001D9580 != 0) {
        D_001D9578 = a;
        func_003E7838(0x10000, 1, a != 0);
    }
}
/* localdecomp:end func_003E54E0 */

LINKER_REMNANT("asm/remnants", func_003E5510);

extern u8 D_001A71C4[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D9C08;
extern s32 D_001D9C0C;
extern s32 D_001D9C10;
extern s32 D_001D9C14;
extern s32 D_001D9C38;
extern s32 D_001D9C40;
extern s16 D_001D9EB4;
extern s16 D_001D9EB6;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
/* localdecomp:start func_003E5520 */
/* large data: retail reaches these with lui/%lo through $at */
__asm__(".extern D_001D9C08_003E5520, 16");
__asm__(".extern D_001D9C0C_003E5520, 16");
__asm__(".extern D_001D9C10_003E5520, 16");
__asm__(".extern D_001D9C14_003E5520, 16");
__asm__(".extern D_001D9C38_003E5520, 16");
__asm__(".extern D_001D9EB4_003E5520, 16");
__asm__(".extern D_001D9EB6_003E5520, 16");
__asm__(".extern D_001D9EB8_003E5520, 16");
__asm__(".extern D_001D9EBA_003E5520, 16");
__asm__(".extern D_001D9EBC_003E5520, 16");
__asm__(".extern D_001D52FC_003E5520, 16");
extern void *D_001D52FC_003E5520;
extern s32 D_001D9C08_003E5520;
extern s32 D_001D9C0C_003E5520;
extern s32 D_001D9C10_003E5520;
extern s32 D_001D9C14_003E5520;
extern s32 D_001D9C38_003E5520;
extern s16 D_001D9EB4_003E5520;
extern s16 D_001D9EB6_003E5520;
extern s16 D_001D9EB8_003E5520;
extern s16 D_001D9EBA_003E5520;
extern s16 D_001D9EBC_003E5520;
/* from boot_elf's func_003E58D8 */
void func_003E5520(void) {
    D_001D9C08_003E5520 = 0;
    D_001D9C10_003E5520 = 0;
    D_001D9C14_003E5520 = 0;
    D_001D9C0C_003E5520 = 0;
    D_001D9C38_003E5520 = 0;
    D_001D9C40 = 0;
    if ((D_001A71C4[0] == 1) && !((*(s32 *)((u8 *)D_001D52FC_003E5520 + 0x1A0)) & 0x10) && (D_001D5B94 != 4) && (D_001D5B90 != 4)) {
        D_001D9EB4_003E5520 = 0;
        D_001D9EB6_003E5520 = 0;
        D_001D9EB8_003E5520 = 0;
        D_001D9EBA_003E5520 = 0;
        D_001D9EBC_003E5520 = 0;
    }
}
/* localdecomp:end func_003E5520 */

/* func_003E55B8 (frontbin): PAL matching candidate.
   Based on the US draft (rac3-uya-decomp func_003E0068, commit 13cf5c5) with the
   names moved to the PAL addresses.  The US build needed the single-function
   override @ps2as; here the file's own flags (-mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division) have to produce the retail bytes, so
   the globals the retail touches with %hi/%lo (large data) are declared with a
   .extern size above -G8, and the ones the retail touches with $gp (small data)
   with a size of 4.  The frame-counter threshold is the PAL constant 0x2EE. */

/* large data: the retail reaches these with lui/lw (or lui/addiu) */
__asm__(".extern D_001D52FC_003E55B8, 16");
__asm__(".extern D_001D9D00_003E55B8, 16");
__asm__(".extern D_001D4C38_003E55B8, 16");
__asm__(".extern D_001D5BC4_003E55B8, 16");
__asm__(".extern D_001DA580_003E55B8, 16");
__asm__(".extern D_001D9110_003E55B8, 16");
/* small data: the retail reaches these with $gp */
__asm__(".extern D_001D95C8_003E55B8, 4");
__asm__(".extern D_001D4C38_gp_003E55B8, 4");
__asm__(".extern D_001D545C_003E55B8, 4");

extern u8 *D_001D52FC_003E55B8;
extern s32 D_001D95C8_003E55B8;
extern s32 D_001D4C38_gp_003E55B8;
extern s32 D_001D4C38_003E55B8;
extern s32 D_001D545C_003E55B8;
extern s32 D_001D9D00_003E55B8;
extern s32 D_001D5BC4_003E55B8;
extern s32 D_001DA580_003E55B8;
extern s32 D_001D9110_003E55B8;
extern s32 D_001A91E8_003E55B8[];

/* localdecomp:start func_003E55B8 */
void func_003E55B8(void) {
    u8 *o = D_001D52FC_003E55B8;
    s32 *c;
    if (*(s32 *)(o + 0x1A0) != 0) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x108) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x10C) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x100) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x104) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else {
        D_001D95C8_003E55B8 = D_001D95C8_003E55B8 + 1;
    }
    D_001D9D00_003E55B8 += 1;
    D_001D4C38_gp_003E55B8 = D_001D4C38_003E55B8 + 1;
    if (D_001D5BC4_003E55B8 != 0 && D_001D95C8_003E55B8 < 0x2EE) {
        c = &D_001A91E8_003E55B8[D_001D545C_003E55B8];
        *c += 1;
    }
    if (D_001DA580_003E55B8 != D_001D4C38_003E55B8 - 1) {
        D_001D9110_003E55B8 = -1;
    }
}
/* localdecomp:end func_003E55B8 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003E56C8);

/* localdecomp:start func_003E56E0 */
#include "vu0.h"
typedef int Q_003E56E0 __attribute__((mode(TI)));
typedef struct { f32 v[3]; u8 tag; u8 pad[3]; f32 r[4]; } E_003E56E0;
typedef struct { u8 pad[0x38]; s32 index; u8 pad3C[0x28]; E_003E56E0 *entries; } C_003E56E0;
typedef struct { u8 pad[0xB0]; f32 fB0; } H_003E56E0;
typedef struct { vu0_v4 v0; u8 pad[0x370]; f32 f380[4]; f32 f390[4]; f32 f3A0[4]; } M_003E56E0;
__asm__(".extern D_001D5471_003E56E0, 16");
__asm__(".extern D_001D5BC8_003E56E0, 16");
__asm__(".extern D_001D5BCC_003E56E0, 16");
extern C_003E56E0 D_00225700_003E56E0;
extern H_003E56E0 D_00225900_003E56E0;
extern M_003E56E0 D_00222480_003E56E0;
extern u8 D_002224A0[];
extern u8 D_001D5471_003E56E0;
extern f32 D_001D5BC8_003E56E0;
extern f32 D_001D5BCC_003E56E0;
extern void func_003873C0();
extern void func_12FF40(f32 *);
extern void func_130088(f32 *, f32 *, f32);
extern void func_130130(f32 *, f32 *, f32);
extern void func_12FFE0(f32 *, f32 *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_00384260(s32, void *, s32);
extern void func_00384CC8(s32);
s32 func_003E56E0(void) {
    f32 m[16] __attribute__((aligned(16)));
    vu0_v4 v;
    E_003E56E0 *e = &D_00225700_003E56E0.entries[D_00225700_003E56E0.index];
    f32 *r = e->r;
    s32 tag = e->tag;
    f32 k;
    f32 s = r[3];
    D_00225900_003E56E0.fB0 = s;
    if (D_001D5471_003E56E0) {
        D_00225900_003E56E0.fB0 = s * D_001D5BC8_003E56E0;
    }
    func_003873C0();
    *(Q_003E56E0 *)&D_00222480_003E56E0.v0 = *(Q_003E56E0 *)e;
    func_12FF40(m);
    func_130088(m, m, e->r[0]);
    func_130130(m, m, r[1]);
    func_12FFE0(m, m, r[2]);
    D_00222480_003E56E0.f380[0] = -m[8];
    D_00222480_003E56E0.f390[0] = -m[0];
    D_00222480_003E56E0.f3A0[0] = m[4];
    D_00222480_003E56E0.f380[1] = -m[9];
    D_00222480_003E56E0.f390[1] = -m[1];
    D_00222480_003E56E0.f3A0[1] = m[5];
    D_00222480_003E56E0.f380[2] = -m[10];
    D_00222480_003E56E0.f390[2] = -m[2];
    D_00222480_003E56E0.f3A0[2] = m[6];
    if (D_001D5471_003E56E0 && (k = D_001D5BCC_003E56E0) != 0.0f) {
        *(Q_003E56E0 *)&v = *(Q_003E56E0 *)D_00222480_003E56E0.f380;
        func_0038CF68(&v, &v, k);
        vec_sub_ab(&D_00222480_003E56E0.v0, &D_00222480_003E56E0.v0, &v);
    }
    func_00384260(0, D_002224A0, 0);
    func_00384260(0, D_002224A0 + 0x10, 1);
    func_00384260(0, D_002224A0 + 0x20, 2);
    func_00384CC8(0);
    return tag;
}
/* localdecomp:end func_003E56E0 */
