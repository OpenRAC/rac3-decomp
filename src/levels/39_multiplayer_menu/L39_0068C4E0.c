#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0068C4E0);

LINKER_REMNANT("asm/levels", func_L39_0068C708);

INCLUDE_ASM("asm/levels", func_L39_0068C718);

INCLUDE_ASM("asm/levels", func_L39_0068C918);

/* localdecomp:start func_L39_0068CBE8 */
typedef struct {
    u8 pad0[0xEC];
    u8 active;
    u8 pad1[0x1F0 - 0xED];
} S_0068CBE8;

extern S_0068CBE8 D_001FC6B0[];
extern u8 D_001D82EC_sda;
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_001DC3F4_sda;

s32 func_L39_0068CBE8(void *arg0, s32 arg1)
{
    s32 i;
    s32 j;
    S_0068CBE8 *p;
    S_0068CBE8 *q;

    (arg1 + D_001FC6B0)->active = 0;
    for (i = 0; i < 5; i = j) {
        j = i + 1;
        p = &D_001FC6B0[i];
        if (p->active == 0) {
            *p = (D_001FC6B0 + 1)[i];
            q = &D_001FC6B0[j];
            q->active = 0;
        }
    }
    D_001D82EC_sda = 1;
    if (D_L39_002403F8 == 1) {
        D_001DC3F4_sda = 6;
    }
    return 1;
}
/* localdecomp:end func_L39_0068CBE8 */

/* localdecomp:start func_L39_0068CD28 */
void func_00120D28(s32, s32, s32);

void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5)
{
    if (arg1 != 0) {
        func_00120D28(arg0 + 4, arg1, 0x33);
        *(s8 *)(arg0 + 0x37) = 0;
    } else {
        *(s8 *)(arg0 + 4) = 0;
    }
    *(f32 *)(arg0 + 0x38) = arg2;
    *(f32 *)(arg0 + 0x3C) = arg3;
    *(f32 *)(arg0 + 0x40) = arg4;
    *(f32 *)(arg0 + 0x44) = arg5;
}
/* localdecomp:end func_L39_0068CD28 */

INCLUDE_ASM("asm/levels", func_L39_0068CDA8);

LINKER_REMNANT("asm/levels", func_L39_0068D1C0);

/* localdecomp:start func_L39_0068D1C8 */
extern u8 D_L39_0047C520[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0068D1C8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047C520;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0068D1C8 */

/* localdecomp:start func_L39_0068D1F0 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots at -0x444..-0x434. */
extern f32 D_001DC46C_sda;
extern f32 D_001DC470_sda;
extern f32 D_001DC474_sda;
extern f32 D_001DC478_sda;
extern f32 D_001DC47C_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_0068D1F0(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DC46C_sda, D_001DC470_sda, D_001DC474_sda, D_001DC478_sda, D_001DC47C_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_0068D1F0 */

/* localdecomp:start func_L39_0068D230 */
extern void func_L39_0067F100(s32);
extern void func_L39_0068AAB8(void *);
extern s32 func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_0068A4A8(void *, s32, s32, s32, f32, f32, f32, f32);
extern f32 D_001DC480_sda;
extern f32 D_001DC484_sda;
extern f32 D_001DC488_sda;
extern f32 D_001DC48C_sda;
extern f32 D_001DC490_sda;

typedef struct S_0068D230_obj S_0068D230_obj;
typedef struct {
    u8 pad00[0x1C];
    void (*f1C)(S_0068D230_obj *, s32, s32);
    u8 pad20[0x20];
    void (*f40)(S_0068D230_obj *, s32);
    u8 pad44[0x4];
    void (*f48)(S_0068D230_obj *, s32, s32);
    void (*f4C)(S_0068D230_obj *, s32, s32);
    u8 pad50[0x68];
    void (*fB8)(S_0068D230_obj *, s32);
} S_0068D230_vt;
struct S_0068D230_obj {
    u8 pad00[0x60];
    S_0068D230_vt *vt;
};

typedef struct {
    u8 pad000[0x110];
    S_0068D230_obj *objs[6];
    u8 pad128[0x180];
    s32 mode;
    s32 v2AC;
    u8 v2B0;
    u8 pad2B1[3];
    s32 v2B4;
    s32 v2B8;
    s32 v2BC;
    s32 v2C0;
} S_0068D230;

void func_L39_0068D230(S_0068D230 *this)
{
    u8 buf[64];
    S_0068D230_obj **p;
    s32 i;

    func_L39_0067F100(0x320000);
    func_L39_0068AAB8(this);
    p = this->objs;
    for (i = 5; i >= 0; i--) {
        (*p)->vt->f40(*p, 1);
        (*p)->vt->f4C(*p, 0x40, 1);
        (*p)->vt->f1C(*p, 1, 0);
        (*p)->vt->f48(*p, 3, 3);
        p++;
    }

    if (this->mode == 1) {
        if (this->v2BC == 0) {
            this->objs[4]->vt->fB8(this->objs[4], func_00381FF0(0x166C));
        } else if (this->v2BC == 1) {
            this->objs[4]->vt->fB8(this->objs[4], func_00381FF0(0x166E));
        } else {
            func_00120048(buf, (u8 *)func_00381FF0(0x166D), this->v2BC);
            this->objs[4]->vt->fB8(this->objs[4], (s32)buf);
        }
        if (this->v2C0 == 0) {
            this->objs[5]->vt->fB8(this->objs[5], func_00381FF0(0x1670));
        } else {
            this->objs[5]->vt->fB8(this->objs[5], func_00381FF0(0x166F));
        }
        func_L39_0068A4A8(this, 0, 5, 0x332299DE, D_001DC480_sda,
                          D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -3.0f * 0.125f,
                          D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -2.0f * 0.125f
                              - (D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -3.0f * 0.125f),
                          D_001DC488_sda - D_001DC490_sda);
    } else if (this->mode == 0) {
        this->objs[4]->vt->f1C(this->objs[4], 0, 0);
        if (this->v2C0 == 0) {
            this->objs[5]->vt->fB8(this->objs[5], func_00381FF0(0x185A));
        } else {
            this->objs[5]->vt->fB8(this->objs[5], func_00381FF0(0x185B));
        }
        func_L39_0068A4A8(this, 0, 3, 0x332299DE, D_001DC480_sda,
                          D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -3.0f * 0.125f,
                          D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -2.0f * 0.125f
                              - (D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -3.0f * 0.125f),
                          D_001DC488_sda - D_001DC490_sda);
    } else {
        this->objs[4]->vt->f1C(this->objs[4], 0, 0);
        this->objs[5]->vt->f1C(this->objs[5], 0, 0);
        func_L39_0068A4A8(this, 0, 3, 0x332299DE, D_001DC480_sda,
                          D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -3.0f * 0.125f,
                          D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -2.0f * 0.125f
                              - (D_001DC484_sda + (D_001DC48C_sda - D_001DC490_sda) * -3.0f * 0.125f),
                          D_001DC488_sda - D_001DC490_sda);
    }

    if (this->v2AC == 0) {
        this->objs[0]->vt->fB8(this->objs[0], func_00381FF0(0x1672));
    } else {
        func_00120048(buf, (u8 *)func_00381FF0(0x1671), this->v2AC);
        this->objs[0]->vt->fB8(this->objs[0], (s32)buf);
    }
    if (this->v2B4 == 0) {
        this->objs[1]->vt->fB8(this->objs[1], func_00381FF0(0x168C));
    } else {
        func_00120048(buf, (u8 *)func_00381FF0(0x168D), this->v2B4);
        this->objs[1]->vt->fB8(this->objs[1], (s32)buf);
    }
    if (this->v2B0 != 0) {
        this->objs[2]->vt->fB8(this->objs[2], func_00381FF0(0x1673));
    } else {
        this->objs[2]->vt->fB8(this->objs[2], func_00381FF0(0x1674));
    }
    if (this->v2B8 != 0) {
        this->objs[3]->vt->fB8(this->objs[3], func_00381FF0(0x192E));
    } else {
        this->objs[3]->vt->fB8(this->objs[3], func_00381FF0(0x192D));
    }
}
/* localdecomp:end func_L39_0068D230 */
