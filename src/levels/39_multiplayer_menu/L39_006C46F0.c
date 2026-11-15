#include "common.h"

/* localdecomp:start func_L39_006C46F0 */
typedef struct {
    u8 name[8][16];
    u8 pad[0x60];
    s16 slot[8];
} S_006C46F0;
extern S_006C46F0 *D_001D5F30_sda;
extern s32 func_001205B0(s32, s32);

s32 func_L39_006C46F0(u8 *obj, s32 slot) {
    u8 *name;
    s32 i;
    slot += 15;
    obj += slot * 4;
    name = *(u8 **)(obj + 0x110) + 0x14;
    for (i = 0; i < 8; i++) {
        S_006C46F0 *tbl = D_001D5F30_sda;
        if (tbl == 0) continue;
        if (tbl->slot[i] == -1) continue;
        if (func_001205B0((s32)name, (s32)tbl->name[i]) == 0) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_006C46F0 */

/* localdecomp:start func_L39_006C4788 */
extern s32 D_001A5CD8[];

s32 func_L39_006C4788(s32 a, s32 n) {
    s32 idx;
    s32 i;
    if (D_001D5F30_sda == 0) {
        return -1;
    }
    idx = -1;
    for (i = 0; i < 8; i++) {
        if (D_001D5F30_sda->slot[i] != -1) {
            idx++;
        }
        if (D_001D5F30_sda->slot[i] == D_001A5CD8[0]) {
            if (n == 0) {
                return idx;
            }
            n--;
        }
    }
    return -1;
}
/* localdecomp:end func_L39_006C4788 */

LINKER_REMNANT("asm/levels", func_L39_006C47F8);

/* localdecomp:start func_L39_006C4818 */
typedef struct {
    s32 type;
    u8 pad4[0x44];
    u8 b48;
    u8 pad49[3];
    s32 i4C;
} W_006C4818;
typedef struct {
    s32 type;
    u8 pad4[0x44];
    u8 str[0x50];
    u8 pad98[8];
} L_006C4818;
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
} V_006C4818;
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
} C_006C4818;
typedef struct {
    u8 pad0[0x1C];
    void (*fn1C)(void *, s32, s32);
} VT_006C4818;
extern void func_L39_00688388(u8 *);
extern void func_L39_0068CD28(void *, u8 *, f32, f32, f32, f32);
extern u8 *func_00381FF0(s32);
extern void func_00120D28(u8 *, u8 *, s32);
extern void func_L39_00689670(u8 *, C_006C4818 *);
extern u8 D_L39_0047EAA0[];
extern u8 D_00249758[];
__asm__(".extern D_001DE008_sda, 4");
extern s32 D_001DE008_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001DDF18_sda, 4");
extern f32 D_001DDF18_sda;
__asm__(".extern D_001DDF1C_sda, 4");
extern f32 D_001DDF1C_sda;
__asm__(".extern D_001DDF20_sda, 4");
extern f32 D_001DDF20_sda;
__asm__(".extern D_001DDF24_sda, 4");
extern f32 D_001DDF24_sda;
__asm__(".extern D_001DDF28_sda, 4");
extern f32 D_001DDF28_sda;
__asm__(".extern D_001DDF2C_sda, 4");
extern f32 D_001DDF2C_sda;
__asm__(".extern D_001DDF30_sda, 4");
extern f32 D_001DDF30_sda;
__asm__(".extern D_001DDF34_sda, 4");
extern f32 D_001DDF34_sda;
__asm__(".extern D_001DDFC8_sda, 4");
extern f32 D_001DDFC8_sda;


static __inline__ void base_006C4818(void *t, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    *(s32 *)t = 0;
    func_L39_0068CD28(t, text, x, y, w, h);
}

static __inline__ void plain_006C4818(W_006C4818 *t, u8 *text, f32 x, f32 y, f32 w, f32 h) {
    base_006C4818(t, text, x, y, w, h);
    t->type = 1;
}

static __inline__ void label_006C4818(L_006C4818 *t, u8 *text, f32 x, f32 y, f32 w, f32 h, u8 *s) {
    base_006C4818(t, text, x, y, w, h);
    t->type = 7;
    if (s != 0) {
        func_00120D28(t->str, s, 0x4F);
        t->str[0x4F] = 0;
    } else {
        t->str[0] = 0;
    }
}

static __inline__ void box_006C4818(W_006C4818 *t, u8 *text, f32 x, f32 y, f32 w, f32 h, s32 sel) {
    base_006C4818(t, text, x, y, w, h);
    t->type = 4;
    t->i4C = sel;
    t->b48 = 0;
}

static __inline__ void list_006C4818(V_006C4818 *t, u8 *text, f32 x, f32 y, f32 w, f32 h, u8 *s, s32 rows, s32 sel) {
    base_006C4818(t, text, x, y, w, h);
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

static __inline__ void page_006C4818(C_006C4818 *t) {
    base_006C4818(t, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->u48 = 0x2E;
    t->count = 0;
    t->u38 = 0;
    t->u3C = 0;
    t->u40 = 1.0f;
    t->u44 = 1.0f;
}

u8 *func_L39_006C4818(s32 arg) {
    u8 *self = (u8 *)arg;
    W_006C4818 w[8];
    V_006C4818 v;
    L_006C4818 title;
    W_006C4818 box0;
    W_006C4818 box1;
    L_006C4818 l[5];
    W_006C4818 a[10];
    W_006C4818 b[10];
    C_006C4818 c;
    f32 x;
    f32 y;
    f32 step;
    s32 rows = 0xD;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0xD54;
    *(u8 **)(self + 0x60) = D_L39_0047EAA0;
    x = 0.292f;
    step = 0.05f;
    plain_006C4818(&w[0], func_00381FF0(0x18B7), x, 0.19f, 0.4f, 0.05f);
    y = 0.264f;
    plain_006C4818(&w[1], func_00381FF0(D_001DE008_sda[0]), x, y, 0.4f, 0.05f);
    y += step;
    plain_006C4818(&w[2], func_00381FF0(D_001DE008_sda[1]), x, y, 0.4f, 0.05f);
    y += step;
    plain_006C4818(&w[3], func_00381FF0(D_001DE008_sda[2]), x, y, 0.4f, 0.05f);
    y += step;
    plain_006C4818(&w[4], func_00381FF0(D_001DE008_sda[3]), x, y, 0.4f, 0.05f);
    y += step;
    plain_006C4818(&w[5], func_00381FF0(D_001DE008_sda[4]), x, y, 0.4f, 0.05f);
    y += step;
    plain_006C4818(&w[6], func_00381FF0(D_001DE008_sda[5]), x, y, 0.4f, 0.05f);
    y += step;
    plain_006C4818(&w[7], func_00381FF0(D_001DE008_sda[6]), x, y, 0.4f, 0.05f);
    y += step;
    list_006C4818(&v, D_00249758, 0.37f, 0.67f, 0.31f, 1.0f, D_00249758, rows, -1);
    label_006C4818(&title, D_00249758, 0.3f, 0.18f, 0.4f, 0.05f, D_00249758);
    box_006C4818(&box0, D_00249758, D_001DDF18_sda, D_001DDF1C_sda, D_001DDF20_sda, D_001DDF24_sda, 6);
    box_006C4818(&box1, D_00249758, D_001DDF28_sda, D_001DDF2C_sda, D_001DDF30_sda, D_001DDF34_sda, 0x49);
    label_006C4818(&l[0], D_00249758, 0.71f, 0.18f, 0.2f, 0.05f, func_00381FF0(0xF89));
    label_006C4818(&l[1], D_00249758, 0.893f, 0.18f, 0.2f, 0.05f, func_00381FF0(0x133F));
    label_006C4818(&l[2], D_00249758, 0.71f, 0.23f, 0.2f, 0.05f, D_00249758);
    label_006C4818(&l[3], D_00249758, 0.515f, 0.77f, 0.2f, 0.05f, D_00249758);
    label_006C4818(&l[4], D_00249758, 0.515f, 0.82f, 0.2f, 0.05f, D_00249758);
    x = 0.523f;
    y = 0.28f;
    step = D_001DDFC8_sda;
    plain_006C4818(&a[0], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[1], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[2], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[3], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[4], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[5], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[6], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[7], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[8], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&a[9], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    x = 0.89f;
    y = 0.28f;
    step = D_001DDFC8_sda;
    plain_006C4818(&b[0], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[1], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[2], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[3], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[4], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[5], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[6], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[7], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[8], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    plain_006C4818(&b[9], D_00249758, x, y, 0.2f, 0.05f);
    y += step;
    page_006C4818(&c);
    c.count = 0x25;
    c.items[0] = &w[1];
    c.items[1] = &w[2];
    c.items[2] = &w[3];
    c.items[3] = &w[4];
    c.items[4] = &w[5];
    c.items[5] = &w[6];
    c.items[6] = &w[7];
    c.items[7] = &v;
    c.items[11] = &title;
    c.items[8] = &l[0];
    c.items[9] = &l[1];
    c.items[12] = &l[2];
    c.items[14] = &l[4];
    c.items[13] = &l[3];
    c.items[10] = &w[0];
    c.items[15] = &a[0];
    c.items[16] = &a[1];
    c.items[17] = &a[2];
    c.items[18] = &a[3];
    c.items[19] = &a[4];
    c.items[20] = &a[5];
    c.items[21] = &a[6];
    c.items[22] = &a[7];
    c.items[23] = &a[8];
    c.items[24] = &a[9];
    c.items[25] = &b[0];
    c.items[26] = &b[1];
    c.items[27] = &b[2];
    c.items[28] = &b[3];
    c.items[29] = &b[4];
    c.items[30] = &b[5];
    c.items[31] = &b[6];
    c.items[32] = &b[7];
    c.items[33] = &b[8];
    c.items[34] = &b[9];
    c.items[35] = &box0;
    c.items[36] = &box1;
    func_L39_00689670(self, &c);
    *(s32 *)(self + 0x2A8) = 0;
    self[0x2B4] = 0;
    {
        u8 *o = *(u8 **)(self + 0x128);
        (*(VT_006C4818 **)(o + 0x60))->fn1C(o, 0, 0);
    }
    *(s32 *)(self + 0xD50) = 5;
    *(s32 *)(self + 0xBA8) = 1;
    *(s32 *)(self + 0xBAC) = 0x7FFFFFFF;
    self[0xB61] = 0;
    self[0xB60] = 0;
    self[0xBB0] = 0;
    *(s32 *)(self + 0xB68) = 0;
    *(s32 *)(self + 0xB64) = 0;
    return self;
}
/* localdecomp:end func_L39_006C4818 */

LINKER_REMNANT("asm/levels", func_L39_006C5510);
