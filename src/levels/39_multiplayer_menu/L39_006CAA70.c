#include "common.h"

/* localdecomp:start func_L39_006CAA70 */
typedef struct T3_006CAA70 T3_006CAA70;
typedef struct {
    char _p0[0x24];
    void (*f24)(T3_006CAA70 *arg0);
} T2_006CAA70;
struct T3_006CAA70 {
    char _p0[0x60];
    T2_006CAA70 *f60;
};
typedef struct {
    char _p0[0x110];
    T3_006CAA70 *f110;
} T1_006CAA70;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006CAA70(T1_006CAA70 *arg0) {
    T3_006CAA70 *o = arg0->f110;
    o->f60->f24(o);
}
/* localdecomp:end func_L39_006CAA70 */

/* localdecomp:start func_L39_006CAA98 */
typedef struct {
    char _p0[0x2a8];
    u32 f2a8[256];
    s32 f6a8;
    s32 f6ac;
    s32 f6b0;
} S_006CAA98;

/* from rac4-decomp's func_L00_00749408 */
void func_L39_006CAA98(S_006CAA98 *owner, const u32 *input, s32 count)
{
    s32 index;
    if (count > 256)
        count = 256;
    owner->f6b0 = 0;
    owner->f6a8 = count;
    owner->f6ac = 0;
    for (index = 0; index < owner->f6a8; index++) {
        owner->f2a8[index] = *input++;
    }
}
/* localdecomp:end func_L39_006CAA98 */

/* localdecomp:start func_L39_006CAAE8 */
typedef struct O_006CAAE8 O_006CAAE8;
typedef struct {
    char _p0[0x20];
    void (*f20)(O_006CAAE8 *, s32, s32);
    void (*f24)(O_006CAAE8 *, u32);
} V_006CAAE8;
struct O_006CAAE8 {
    char _p0[0x60];
    V_006CAAE8 *f60;
};
typedef struct {
    char _p0[0x110];
    O_006CAAE8 *f110[7];
    char _p1[0x2a8 - 0x12c];
    u32 f2a8[256];
    s32 f6a8;
    s32 f6ac;
    s32 f6b0;
} S_006CAAE8;
extern void func_L39_0068B2F8(void *, s32, s32);

void func_L39_006CAAE8(S_006CAAE8 *owner, s32 sel)
{
    s32 i;
    s32 top;

    owner->f6b0 = sel;
    if (owner->f6a8 - 1 < sel) {
        owner->f6b0 = owner->f6a8 - 1;
    } else if (sel < 0) {
        owner->f6b0 = 0;
    }
    owner->f6ac = owner->f6b0;
    if (owner->f6b0 + 5 >= owner->f6a8) {
        top = owner->f6a8 - 6;
        owner->f6ac = top;
        if (owner->f6a8 - 1 < top) {
            owner->f6ac = owner->f6a8 - 1;
        } else if (top < 0) {
            owner->f6ac = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (i + owner->f6ac < owner->f6a8) {
            owner->f110[i + 1]->f60->f24(owner->f110[i + 1], owner->f2a8[i + owner->f6ac]);
            owner->f110[i + 1]->f60->f20(owner->f110[i + 1], 3, 0);
        } else {
            owner->f110[i + 1]->f60->f20(owner->f110[i + 1], 0, 0);
        }
    }
    ((s32 (*)(void *, s32, s32))func_L39_0068B2F8)(owner, owner->f6b0 - owner->f6ac + 1, 0);
}
/* localdecomp:end func_L39_006CAAE8 */

/* localdecomp:start func_L39_006CAC48 */
typedef struct O_006CAC48 O_006CAC48;
typedef struct {
    char _p0[0x20];
    void (*f20)(O_006CAC48 *, s32, s32);
    void (*f24)(O_006CAC48 *, u32);
} V_006CAC48;
struct O_006CAC48 {
    char _p0[0x60];
    V_006CAC48 *f60;
};
typedef struct {
    char _p0[0x110];
    O_006CAC48 *f110[7];
    char _p1[0x2a8 - 0x12c];
    u32 f2a8[256];
    s32 f6a8;
    s32 f6ac;
    s32 f6b0;
} S_006CAC48;
extern void func_L39_0068B2F8(void *, s32, s32);

void func_L39_006CAC48(S_006CAC48 *owner)
{
    s32 i;
    s32 last;
    s32 cur;

    cur = owner->f6b0 + 1;
    last = owner->f6a8 - 1;
    owner->f6b0 = cur;
    if (last < cur) {
        owner->f6b0 = last;
    } else if (cur < 0) {
        owner->f6b0 = 0;
    }
    if (owner->f6b0 >= owner->f6ac + 6) {
        owner->f6ac = owner->f6b0 - 5;
        for (i = 0; i < 6; i++) {
            if (i + owner->f6ac < owner->f6a8) {
                owner->f110[i + 1]->f60->f24(owner->f110[i + 1], owner->f2a8[i + owner->f6ac]);
                owner->f110[i + 1]->f60->f20(owner->f110[i + 1], 3, 0);
            } else {
                owner->f110[i + 1]->f60->f20(owner->f110[i + 1], 0, 0);
            }
        }
    }
    func_L39_0068B2F8(owner, owner->f6b0 - owner->f6ac + 1, 0);
}
/* localdecomp:end func_L39_006CAC48 */

/* localdecomp:start func_L39_006CAD88 */
typedef struct O_006CAD88 O_006CAD88;
typedef struct {
    char _p0[0x20];
    void (*f20)(O_006CAD88 *, s32, s32);
    void (*f24)(O_006CAD88 *, u32);
} V_006CAD88;
struct O_006CAD88 {
    char _p0[0x60];
    V_006CAD88 *f60;
};
typedef struct {
    char _p0[0x110];
    O_006CAD88 *f110[7];
    char _p1[0x2a8 - 0x12c];
    u32 f2a8[256];
    s32 f6a8;
    s32 f6ac;
    s32 f6b0;
} S_006CAD88;
extern void func_L39_0068B2F8(void *, s32, s32);

void func_L39_006CAD88(S_006CAD88 *owner)
{
    s32 i;
    s32 last;
    s32 cur;

    cur = owner->f6b0 - 1;
    last = owner->f6a8 - 1;
    owner->f6b0 = cur;
    if (last < cur) {
        owner->f6b0 = last;
    } else if (cur < 0) {
        owner->f6b0 = 0;
    }
    if (owner->f6b0 < owner->f6ac) {
        owner->f6ac = owner->f6b0;
        for (i = 0; i < 6; i++) {
            if (i + owner->f6ac < owner->f6a8) {
                owner->f110[i + 1]->f60->f24(owner->f110[i + 1], owner->f2a8[i + owner->f6ac]);
                owner->f110[i + 1]->f60->f20(owner->f110[i + 1], 3, 0);
            } else {
                owner->f110[i + 1]->f60->f20(owner->f110[i + 1], 0, 0);
            }
        }
    }
    func_L39_0068B2F8(owner, owner->f6b0 - owner->f6ac + 1, 0);
}
/* localdecomp:end func_L39_006CAD88 */

LINKER_REMNANT("asm/levels", func_L39_006CAEC0);

/* localdecomp:start func_L39_006CAEC8 */
typedef struct {
    s32 type;
    u8 pad4[0x44];
    u8 b48;
    u8 pad49[3];
    s32 i4C;
} W_006CAEC8;
typedef struct {
    s32 type;
    u8 pad4[0x44];
    s32 u48;
    s32 u4C;
    u8 *u50;
    s32 u54;
    s32 u58;
    s32 u5C;
    s32 u60;
    s32 u64;
    u8 pad68[8];
} V_006CAEC8;
typedef struct {
    s32 type;
    u8 pad4[0x34];
    s32 u38;
    s32 u3C;
    f32 u40;
    f32 u44;
    s32 u48;
    s32 count;
    void *items[0x60];
} C_006CAEC8;
extern void *func_L39_00688388(void *);
extern void func_L39_0068CD28(void *, u8 *, f32, f32, f32, f32);
extern s32 func_00381FF0(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_00689670(u8 *, C_006CAEC8 *);
extern u8 D_L39_0047EEC0[];
extern u8 D_L39_002499E8[];
extern u8 D_L39_002499F0[];
__asm__(".extern D_001DE2B4_sda, 4");
extern f32 D_001DE2B4_sda;
__asm__(".extern D_001DE2B8_sda, 4");
extern f32 D_001DE2B8_sda;
__asm__(".extern D_001DE2BC_sda, 4");
extern f32 D_001DE2BC_sda;
__asm__(".extern D_001DE2C0_sda, 4");
extern f32 D_001DE2C0_sda;
__asm__(".extern D_001DE2C4_sda, 4");
extern f32 D_001DE2C4_sda;
__asm__(".extern D_001DE2C8_sda, 4");
extern f32 D_001DE2C8_sda;
__asm__(".extern D_001DE2CC_sda, 4");
extern f32 D_001DE2CC_sda;
__asm__(".extern D_001DE2D0_sda, 4");
extern f32 D_001DE2D0_sda;
__asm__(".extern D_001DE2D4_sda, 4");
extern f32 D_001DE2D4_sda;

static __inline__ void base_006CAEC8(void *t, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    *(s32 *)t = 0;
    func_L39_0068CD28(t, text, x, y, w, h);
}

static __inline__ void box_006CAEC8(W_006CAEC8 *t, u8 *text, f32 x, f32 y, f32 w, f32 h, s32 sel) {
    base_006CAEC8(t, text, x, y, w, h);
    t->type = 4;
    t->i4C = sel;
    t->b48 = 0;
}

static __inline__ void list_006CAEC8(V_006CAEC8 *t, u8 *text, f32 x, f32 y, f32 w, f32 h, u8 *s, s32 rows, s32 sel) {
    base_006CAEC8(t, text, x, y, w, h);
    t->type = 5;
    t->u48 = 0;
    t->u4C = 0;
    t->u50 = s;
    t->u54 = rows;
    t->u58 = 0;
    t->u5C = 0;
    t->u60 = sel;
    t->u64 = 0;
}

static __inline__ void page_006CAEC8(C_006CAEC8 *t) {
    base_006CAEC8(t, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->u48 = 0x2E;
    t->count = 0;
    t->u38 = 0;
    t->u3C = 0;
    t->u40 = 1.0f;
    t->u44 = 1.0f;
}

/* from func_L39_006C4818 (L39_006C46F0.c) */
u8 *func_L39_006CAEC8(s32 arg) {
    u8 *self = (u8 *)arg;
    W_006CAEC8 box;
    V_006CAEC8 list;
    C_006CAEC8 c;
    s32 sel;


    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x2B8;
    *(u8 **)(self + 0x60) = D_L39_0047EEC0;
    sel = func_L39_005B43C8(0x1B, 0x20);
    box_006CAEC8(&box, D_L39_002499E8, D_001DE2B4_sda, D_001DE2B8_sda, D_001DE2BC_sda - D_001DE2D4_sda, D_001DE2C0_sda - D_001DE2D4_sda, sel);
    list_006CAEC8(&list, D_L39_002499F0, D_001DE2C4_sda, D_001DE2C8_sda, D_001DE2CC_sda - (D_001DE2D4_sda + D_001DE2D4_sda),
                  D_001DE2D0_sda - D_001DE2D4_sda * 4.0f, (u8 *)func_00381FF0(0x1664), 8, -1);
    page_006CAEC8(&c);
    c.items[0] = &box;
    c.items[1] = &list;
    c.count = 2;
    func_L39_00689670(self, &c);
    return self;
}
/* localdecomp:end func_L39_006CAEC8 */

LINKER_REMNANT("asm/levels", func_L39_006CB078);

/* localdecomp:start func_L39_006CB080 */
extern u8 D_L39_0047EEC0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006CB080(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047EEC0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006CB080 */

/* localdecomp:start func_L39_006CB0A8 */
typedef struct O_006CB0A8 O_006CB0A8;

typedef struct {
    char _p0[0x1C];
    void (*f1C)(O_006CB0A8 *, s32, s32);
    void (*f20)(O_006CB0A8 *, s32, s32);
    char _p1[0x40 - 0x24];
    void (*f40)(O_006CB0A8 *, s32);
    char _p2[0x6C - 0x44];
    s32 (*f6C)(O_006CB0A8 *, s32, char **);
    char _p3[0x84 - 0x70];
    void (*f84)(O_006CB0A8 *, s32);
} V_006CB0A8;
struct O_006CB0A8 {
    char _p0[0x60];
    V_006CB0A8 *f60;
};
typedef struct {
    char _p0[0x114];
    O_006CB0A8 *f114;
    char _p1[0x2A8 - 0x118];
    u8 f2A8;
    char _p2[0x2B4 - 0x2A9];
    f32 f2B4;
} S_006CB0A8;
extern f32 D_001DE2B4_sda;
extern f32 D_001DE2B8_sda;
extern f32 D_001DE2BC_sda;
extern f32 D_001DE2C0_sda;
extern f32 D_001DE2C4_sda;
extern f32 D_001DE2C8_sda;
extern f32 D_001DE2CC_sda;
extern f32 D_001DE2D0_sda;
extern f32 D_001DE2D4_sda;
extern u8 D_L39_002499F8[];
extern s32 func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern s32 func_00381FF0(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_0068A6D0(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068A7B8(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);

void func_L39_006CB0A8(S_006CB0A8 *o)
{
    char *names[64];
    u8 on = 1;

    func_L39_0067F100(0x220000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(o, func_00381FF0(0x1655));
    func_L39_00689DB8(o, func_00381FF0(0xCD5));
    func_L39_0068A6D0(o, 0, 0x332299DE, D_001DE2B4_sda, D_001DE2B8_sda, D_001DE2BC_sda, D_001DE2C0_sda);
    func_L39_0068A6D0(o, 1, 0x332299DE, D_001DE2C4_sda, D_001DE2C8_sda, D_001DE2CC_sda, D_001DE2D0_sda);
    func_L39_0068A7B8(o, 0, 0x331465B7, D_001DE2C4_sda,
                      D_001DE2C8_sda - D_001DE2D0_sda * 0.5f + D_001DE2D4_sda,
                      D_001DE2D0_sda - D_001DE2D4_sda * 2.0f,
                      D_001DE2CC_sda - D_001DE2D4_sda * 2.0f);
    func_L39_0068AAB8(o);
    names[0] = (char *)D_L39_002499F8;
    o->f114->f60->f6C(o->f114, 1, names);
    o->f114->f60->f20(o->f114, 2, 0);
    o->f114->f60->f1C(o->f114, 1, 0);
    o->f114->f60->f84(o->f114, 1);
    o->f114->f60->f40(o->f114, 1);
    o->f2A8 = on;
    o->f2B4 = 0.0f;
}
/* localdecomp:end func_L39_006CB0A8 */

/* localdecomp:start func_L39_006CB230 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006CB230(void *);

extern void func_L39_0067F168();
void func_L39_006CB230(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006CB230 */
