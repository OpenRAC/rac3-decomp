/* functional: high. Compiles, not byte-exact; layout table D_004B0430 floats indexed by retail offsets; the text row copies D_00248698 (always non-null in retail, compiler may fold the test); sets self+0x310=1, +0x2C0=0 after registering */
typedef struct {
    s32 type;
    u8 label[0x34];
    f32 x, y, w, h;
} Item_006A2F50;
typedef struct {
    Item_006A2F50 h;
    u8 b48;
    u8 pad49[3];
    s32 w4C;
} Box_006A2F50;
typedef struct {
    Item_006A2F50 h;
    f32 f48, f4C, f50, f54;
    s32 id;
    s32 color;
} Cell_006A2F50;
typedef struct {
    Item_006A2F50 h;
    u8 b48;
    u8 pad49[0xC7];
    s32 max;
    u8 b114, b115, b116;
    u8 pad117[9];
} Field_006A2F50;
typedef struct {
    Item_006A2F50 h;
    u8 pad48[8];
} Label_006A2F50;
typedef struct {
    Item_006A2F50 h;
    char text[0x50];
    u8 pad98[8];
} Text_006A2F50;
typedef struct {
    Item_006A2F50 h;
    s32 unk48;
    s32 unk4C;
    s32 data;
    s32 max;
    s32 unk58;
    s32 unk5C;
    s32 sel;
    f32 unk64;
    u8 pad68[8];
} Spin_006A2F50;
typedef struct {
    Item_006A2F50 h;
    s32 f48, f4C, f50, f54, f58, f5C, f60;
    u8 pad64[0xC];
} Pick_006A2F50;
typedef struct {
    Item_006A2F50 h;
    s32 unk48;
    s32 count;
    void *items[0x60];
} Menu_006A2F50;

extern u8 D_L39_0047D858[];
extern u8 D_00248698[];
extern f32 D_004B0430[];
extern s32 D_002487C0[];
extern void func_L39_00688388(void *);
extern s32 func_0059A970(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_0068CD28(void *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

static __inline__ void mk_Cell_006A2F50(Cell_006A2F50 *c)
{
    c->h.type = 0;
    func_L39_0068CD28(c, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    c->h.type = 12;
    c->id = -1;
    c->f50 = 0.0f;
    c->f48 = 0.0f;
    c->f54 = 1.0f;
    c->f4C = 1.0f;
    c->color = 0x706EC8FF;
}

static __inline__ void mk_Field_006A2F50(Field_006A2F50 *fl, s32 id, f32 y)
{
    f32 *t = D_004B0430;
    fl->h.type = 0;
    func_L39_0068CD28(fl, id, t[0], y, t[2], t[3]);
    fl->h.type = 8;
    fl->b48 = 0;
    fl->b114 = 0;
    fl->max = 0x20;
    fl->b115 = 0;
    fl->b116 = 0;
}

void *func_L39_006A2F50(u8 *self)
{
    Box_006A2F50 box;
    Cell_006A2F50 c0[4];
    Cell_006A2F50 c1[8];
    Field_006A2F50 f1, f2, f3, f4, f6;
    Text_006A2F50 txt;
    Label_006A2F50 l7, l8, l11;
    Spin_006A2F50 sp;
    Pick_006A2F50 pk;
    Menu_006A2F50 menu;
    f32 *t;
    s32 i, id, data;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x340;
    *(void **)(self + 0x60) = D_L39_0047D858;

    box.h.type = 0;
    func_L39_0068CD28(&box, (s32)D_00248698, 0.50025f, 0.2175f, 0.815f, 0.15f);
    box.w4C = -1;
    box.h.type = 4;
    box.b48 = 0;
    for (i = 0; i < 4; i++) mk_Cell_006A2F50(&c0[i]);
    for (i = 0; i < 8; i++) mk_Cell_006A2F50(&c1[i]);

    t = D_004B0430;
    mk_Field_006A2F50(&f1, func_0059A970(0xFE6), t[5] * 0.0f + t[1]);
    mk_Field_006A2F50(&f2, func_0059A970(0xFE9), t[5] + t[1]);
    mk_Field_006A2F50(&f3, func_0059A970(0xFEA), t[5] + t[5] + t[1]);
    mk_Field_006A2F50(&f4, func_0059A970(0x116C), t[5] * 3.0f + t[1]);

    id = func_0059A970(0x1607);
    txt.h.type = 0;
    func_L39_0068CD28(&txt, id, t[0], t[5] * 4.0f + t[1], t[2], t[3]);
    txt.h.type = 7;
    if (D_00248698 != 0) {
        func_00120D28(txt.text, D_00248698, 0x4F);
        txt.text[0x4F] = 0;
    } else {
        txt.text[0] = 0;
    }

    mk_Field_006A2F50(&f6, func_0059A970(0x116D), t[5] * 5.0f + t[1]);

    id = func_0059A970(0x169D);
    l7.h.type = 0;
    func_L39_0068CD28(&l7, id, t[0], t[5] * 10.0f + t[1], t[2], t[3]);
    l7.h.type = 1;

    l8.h.type = 0;
    func_L39_0068CD28(&l8, (s32)D_00248698, 0.0f, 0.0f, 0.0f, 0.0f);
    l8.h.type = 1;

    data = func_0059A970(0x1015);
    sp.h.type = 0;
    func_L39_0068CD28(&sp, (s32)D_00248698, 0.69f, 0.86f, 0.335f, 1.0f);
    sp.data = data;
    sp.h.type = 5;
    sp.unk48 = 0;
    sp.unk4C = 0;
    sp.max = 8;
    sp.unk58 = 0;
    sp.unk5C = 0;
    sp.sel = -1;
    sp.unk64 = 0.0f;

    id = func_0059A970(0xFE7);
    pk.h.type = 0;
    func_L39_0068CD28(&pk, id, t[12], t[17] * 0.0f + t[13], t[14], t[15]);
    pk.h.type = 6;
    pk.f50 = 2;
    pk.f5C = -1;
    pk.f48 = 1;
    pk.f4C = 1;
    pk.f54 = 1;
    pk.f58 = -1;
    pk.f60 = -1;

    id = func_0059A970(0xF8C);
    l11.h.type = 0;
    func_L39_0068CD28(&l11, id, 0.695f, 0.834f, 1.0f, 1.0f);
    l11.h.type = 1;

    menu.h.type = 0;
    func_L39_0068CD28(&menu, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    menu.unk48 = 0x2E;
    menu.count = 24;
    menu.h.x = 0.0f;
    menu.h.y = 0.0f;
    menu.h.w = 1.0f;
    menu.h.h = 1.0f;
    menu.items[0] = &box;
    for (i = 0; i < 4; i++) {
        c0[i].id = 0xED26;
        menu.items[1 + i] = &c0[i];
    }
    for (i = 0; i < 8; i++) {
        c1[i].id = D_002487C0[i];
        menu.items[5 + i] = &c1[i];
    }
    menu.items[13] = &f1;
    menu.items[14] = &f2;
    menu.items[15] = &f3;
    menu.items[16] = &f4;
    menu.items[17] = &txt;
    menu.items[18] = &f6;
    menu.items[19] = &l7;
    menu.items[20] = &l8;
    menu.items[21] = &sp;
    menu.items[22] = &pk;
    menu.items[23] = &l11;
    func_L39_00689670(self, &menu);
    *(s32 *)(self + 0x310) = 1;
    *(s32 *)(self + 0x2C0) = 0;
    return self;
}
