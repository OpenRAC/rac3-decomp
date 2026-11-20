#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    union {
        s128 q;
        f32 f[4];
    } pos;
    s128 col;
} E_001E8D00;

typedef struct {
    u8 pad0[4];
    s16 s4;
    u8 pad6[0x11];
    u8 b17;
    u8 *p18;
    s16 s1C;
} Rec_004474E8;
typedef struct {
    u8 pad0[0x20];
    u8 *p20;
    u32 f24;
    u8 b28;
    u8 pad29[3];
    f32 f2C;
} Src_004474E8;

/* localdecomp:start func_L01_004471A8 */


extern s32 D_L01_001DF9E0;
extern E_001E8D00 D_L01_001E8C80[];
extern s128 D_L01_001EAA40[];
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_003D5630(void);

void func_L01_004471A8(u8 *a0, f32 scale)
{
    f32 h;
    f32 t;
    E_001E8D00 *e;
    s32 n;

    if (a0[49] == 0) {
        return;
    }
    if (D_L01_001DF9E0 >= 32) {
        return;
    }
    D_L01_001E8C80[D_L01_001DF9E0].pos.q = *(s128 *)(a0 + 16);
    h = func_003C3D30(a0 + 16, 0, 0, 0.5f);
    if (func_003D5630() == 0) {
        return;
    }
    n = D_L01_001DF9E0;
    e = &D_L01_001E8C80[n];
    e->pos.f[2] = h + 0.025f;
    D_L01_001E8C80[n].col = D_L01_001EAA40[0];
    t = (8.0f - __builtin_fabsf(*(f32 *)(a0 + 24) - h)) * 0.125f;
    if (t < 0.25f) {
        t = 0.25f;
    }
    D_L01_001DF9E0 = n + 1;
    e->pos.f[3] = scale * t;
}
/* localdecomp:end func_L01_004471A8 */

/* localdecomp:start func_L01_004472C0 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0, pos;
    u8 pad20[0x70 - 0x20]; f32 f70, f74;
    u8 pad78[0xBD - 0x78]; u8 bBD;
    u8 padBE[0xE0 - 0xBE]; vu0_v4 normal;
} Obj_004472C0;
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
extern vu0_v4 D_L01_001EAA20[];
void func_L01_004472C0(Obj_004472C0 *o) {
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern void func_0038CE50(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    vu0_v4 a, b, c;
    f32 h, scale;
    if (D_L01_001D673C == 0) {
        if (o->normal.z < 0.9f) goto fail;
        *(vu0_q *)&a = *(vu0_q *)&o->pos;
        a.z -= 16.0f;
        if (a.z < 0.5f) a.z = 0.5f;
        *(vu0_q *)&b = *(vu0_q *)&o->pos;
        b.z += 0.5f;
        if (!func_003D3CB0(&b, &a, 0x22, 0, 0)) goto fail;
        *(f32 *)((u8 *)o + 0x70) = D_L01_001EAA20[0].z - o->pos.z;
        *(f32 *)((u8 *)o + 0x74) = o->v0.w * 0.000244140625f;
        return;

    } else {
        func_0038CE50(&a, o, 0.0009765625f);
        func_0038CE20(&b, &o->normal, -8.0f);
        vec_add_ab(&b, &a, &b);
        if (!func_003D3CB0(&a, &b, 0x22, 0, 0)) goto fail;
        vec_sub_ba(&c, D_L01_001EAA20, &o->pos);
        *(f32 *)((u8 *)o + 0x70) = func_0038CE68(&c, &o->normal);
        *(f32 *)((u8 *)o + 0x74) = 0.2f;
        o->bBD = 255;
    }
    return;
fail:
    *(s32 *)((u8 *)o + 0x70) = 0;
    *(s32 *)((u8 *)o + 0x74) = 0;
}
/* localdecomp:end func_L01_004472C0 */

/* localdecomp:start func_L01_00447450 */
extern void func_L01_004472C0_00447450();
 
void func_L01_00447450(void) {
    func_L01_004472C0_00447450();
}
/* localdecomp:end func_L01_00447450 */

/* localdecomp:start func_L01_00447470 */
extern void func_0038DBD8_00447470();
 
void func_L01_00447470(void) {
    func_0038DBD8_00447470();
}
/* localdecomp:end func_L01_00447470 */

/* localdecomp:start func_L01_00447490 */
typedef struct {
    u8 pad0[0x24];
    u32 flags;
    u8 pad28[0x10];
    u8 *owner;
    u8 pad3C[4];
} Slot_00447490;

extern Slot_00447490 D_L01_001EEC80[];

/* Returns the effect slot this object owns if its flags match the mask, else frees the slot unless asked to keep it. */
void *func_L01_00447490(u8 *a0, s32 mask, s32 keep) {
    Slot_00447490 *p;

    if (a0[168] == 255 || (p = &D_L01_001EEC80[a0[168]])->owner != a0) {
        return 0;
    }
    if (p->flags & mask) {
        return p;
    }
    if (keep == 0) {
        p->owner[168] = 255;
    }
    return 0;
}
/* localdecomp:end func_L01_00447490 */

/* localdecomp:start func_L01_004474E8 */
extern Rec_004474E8 *func_00382348(s32 a0);
extern u8 func_L01_0044CE88(u8 *p);
extern u8 *func_L01_00448FF0(s32 a0);

f32 func_L01_004474E8(s32 a0, Src_004474E8 *a1) {
    Rec_004474E8 *p = func_00382348(a0);
    f32 f = 0.0f;
    if (p != 0) {
        u8 *q = p->p18;
        if (q != 0) {
            u8 c = q[0x20];
            if (c != 0xFE) {
                if (c == 0xFD) {
                    p->s1C = 0;
                    p->p18 = 0;
                }
            } else {
                p->s1C = 0;
                p->p18 = 0;
            }
        }
        {
            short t = p->s1C;
            if (t != 0) {
                p->s1C = (unsigned short)p->s1C + 1;
                if (t >= 0x65) {
                    p->p18 = 0;
                    p->s1C = 0;
                }
            }
        }
        if (a1 != 0) {
            u8 *x = a1->p20;
            f = a1->f2C;
            if (x != 0) {
                if (p->p18 != x) {
                    p->p18 = x;
                    p->b17 = func_L01_0044CE88(a1->p20);
                    p->s1C = 1;
                } else {
                    if (a1->b28 == 9) {
                        if (p->s1C < 0x32) f = 0.0f;
                        else p->s1C = 1;
                    } else {
                        if (p->s1C < 8) f = 0.0f;
                        p->s1C = 1;
                    }
                }
            }
            if ((f32)p->s4 <= 1.0f && f > 0.0f && f < 1.0f) f = 1.0f;
            if (a1->f24 & 0x100000) {
                u8 *o = func_L01_00448FF0(a0);
                if (o != 0) o[0x18] = 1;
            } else if (a1->f24 & 0x200000) {
                u8 *o = func_L01_00448FF0(a0);
                if (o != 0) o[0x18] = 2;
            } else if (a1->f24 & 0x400000) {
                u8 *o = func_L01_00448FF0(a0);
                if (o != 0) o[0x18] = 3;
            } else if (a1->f24 & 0x10000000) {
                u8 *o = func_L01_00448FF0(a0);
                if (o != 0) o[0x18] = 4;
            } else {
                u8 *o = func_L01_00448FF0(a0);
                if (o != 0) o[0x18] = 0;
            }
        }
    }
    return f;
}
/* localdecomp:end func_L01_004474E8 */
