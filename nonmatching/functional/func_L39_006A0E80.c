/* functional: high. Compiles, not byte-exact; the 8-entry selector pairs text 0xFBF with seven level-data strings D_002485E8..18; sda var at gp+0x620 named D_001DCED0_sda; state fields at self+0x2A8/0x2B0/0x2B4/0x1640 cleared after registering */
typedef struct {
    s32 type;
    u8 label[0x34];
    f32 x, y, w, h;
} Item_006A0E80;
typedef struct {
    Item_006A0E80 h;
    s32 count;
    s32 *opts;
    s32 unk50;
    u8 pad54[0x1C];
} Sel_006A0E80;
typedef struct {
    Item_006A0E80 h;
    u8 pad48[8];
} Label_006A0E80;
typedef struct {
    Item_006A0E80 h;
    char text[0x50];
    u8 pad98[8];
} Text_006A0E80;
typedef struct {
    Item_006A0E80 h;
    s32 unk48;
    s32 unk4C;
    s32 data;
    s32 max;
    s32 unk58;
    s32 unk5C;
    s32 sel;
    s32 unk64;
    u8 pad68[8];
} Spin_006A0E80;
typedef struct {
    Item_006A0E80 h;
    f32 f48, f4C, f50, f54;
    s32 id;
    s32 color;
} Cell_006A0E80;
typedef struct {
    Item_006A0E80 h;
    s32 unk48;
    s32 count;
    void *items[0x60];
} Menu_006A0E80;

extern u8 D_L39_0047D730[];
extern u8 D_002485E0[], D_002485E8[], D_002485F0[], D_002485F8[];
extern u8 D_00248600[], D_00248608[], D_00248610[], D_00248618[];
extern u8 D_001DCED0_sda[];
extern void func_L39_00688388(void *);
extern void func_L39_006CC120(void *);
extern s32 func_0059A970(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_0068CD28(void *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

static __inline__ void mk_Sel_006A0E80(Sel_006A0E80 *s, s32 id, f32 y, s32 count, s32 *opts)
{
    s->h.type = 0;
    func_L39_0068CD28(s, id, 0.10500002f, y, 0.39f, 0.05f);
    s->h.type = 3;
    s->count = count;
    s->opts = opts;
    s->unk50 = 0;
}

static __inline__ void mk_Cell_006A0E80(Cell_006A0E80 *c, f32 x, s32 color)
{
    c->h.type = 0;
    func_L39_0068CD28(c, (s32)D_001DCED0_sda, x, 0.50883335f, 0.03f, 0.04f);
    c->h.type = 12;
    c->f48 = 0.0f;
    c->f4C = 1.0f;
    c->f50 = 0.0f;
    c->f54 = 1.0f;
    c->id = 0xED26;
    c->color = color;
}

void *func_L39_006A0E80(u8 *self)
{
    s32 a[11], d4[4], e[2], g[8], one[1];
    s32 color;
    Sel_006A0E80 s0, s1, s2, s3, s4;
    Text_006A0E80 txt;
    Spin_006A0E80 sp;
    Label_006A0E80 l0, l1;
    Cell_006A0E80 c[4];
    Menu_006A0E80 menu;
    s32 id, src;
    char *dst;
    s32 i;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047D730;
    func_L39_006CC120(self + 0x10C4);
    func_L39_006CC120(self + 0x1298);
    func_L39_006CC120(self + 0x146C);
    *(u8 **)(self + 0x2A4) = self + 0x1644;
    a[0] = func_0059A970(0xFBF);
    a[1] = func_0059A970(0xBB1);
    a[2] = func_0059A970(0xBB2);
    a[3] = func_0059A970(0xDA);
    a[4] = func_0059A970(0xBB4);
    a[5] = func_0059A970(0xD8);
    a[6] = func_0059A970(0xD4);
    a[7] = func_0059A970(0x18C4);
    a[8] = func_0059A970(0x18C5);
    a[9] = func_0059A970(0x18C6);
    a[10] = func_0059A970(0x18C7);
    d4[0] = func_0059A970(0xFBF);
    d4[1] = func_0059A970(0x1024);
    d4[2] = func_0059A970(0x10E2);
    d4[3] = func_0059A970(0x1026);
    e[0] = func_0059A970(0x116C);
    e[1] = func_0059A970(0xF67);
    one[0] = (s32)D_002485E0;
    g[0] = func_0059A970(0xFBF);
    g[1] = (s32)D_002485E8;
    g[2] = (s32)D_002485F0;
    g[3] = (s32)D_002485F8;
    g[4] = (s32)D_00248600;
    g[5] = (s32)D_00248608;
    g[6] = (s32)D_00248610;
    g[7] = (s32)D_00248618;

    mk_Sel_006A0E80(&s0, func_0059A970(0xFEA), 0.20383331f, 2, e);
    mk_Sel_006A0E80(&s1, func_0059A970(0xFBA), 0.3055f, 11, a);
    mk_Sel_006A0E80(&s2, func_0059A970(0xFBB), 0.40716666f, 4, d4);

    id = func_0059A970(0x160B);
    src = func_0059A970(0xFBF);
    txt.h.type = 0;
    func_L39_0068CD28(&txt, id, 0.10500002f, 0.50883335f, 0.39f, 0.05f);
    txt.h.type = 7;
    if (src != 0) {
        func_00120D28(txt.text, (void *)src, 0x4F);
        txt.text[0x4F] = 0;
    } else {
        txt.text[0] = 0;
    }

    mk_Sel_006A0E80(&s3, func_0059A970(0xFB8), 0.6105f, 8, g);
    mk_Sel_006A0E80(&s4, func_0059A970(0x116C), 0.71216667f, 1, one);
    color = 0x706EC8FF;

    l0.h.type = 0;
    func_L39_0068CD28(&l0, func_0059A970(0x10E9), 0.3f, 0.82f, 0.39f, 0.05f);
    l0.h.type = 1;
    l1.h.type = 0;
    func_L39_0068CD28(&l1, func_0059A970(0x10EA), 0.715f, 0.19f, 1.0f, 1.0f);
    l1.h.type = 1;

    sp.h.type = 0;
    id = func_0059A970(0x1016);
    func_L39_0068CD28(&sp, (s32)D_001DCED0_sda, 0.716f, 0.52f, 0.36f, 0.6f);
    sp.h.type = 5;
    sp.data = id;
    sp.unk48 = 0;
    sp.unk4C = 0;
    sp.max = 12;
    sp.unk58 = 0;
    sp.unk5C = 0;
    sp.sel = -1;
    sp.unk64 = 0;

    mk_Cell_006A0E80(&c[0], 0.48f, color);
    mk_Cell_006A0E80(&c[1], 0.445f, color);
    mk_Cell_006A0E80(&c[2], 0.405f, color);
    mk_Cell_006A0E80(&c[3], 0.37f, color);

    menu.h.type = 0;
    func_L39_0068CD28(&menu, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    menu.unk48 = 0x2E;
    menu.h.x = 0.0f;
    menu.h.y = 0.0f;
    menu.h.w = 1.0f;
    menu.h.h = 1.0f;
    menu.count = 13;
    menu.items[0] = &s0;
    menu.items[1] = &s1;
    menu.items[2] = &s2;
    menu.items[3] = &txt;
    menu.items[4] = &s3;
    menu.items[5] = &s4;
    menu.items[6] = &l0;
    menu.items[7] = &l1;
    menu.items[8] = &sp;
    for (i = 0; i < 4; i++)
        menu.items[9 + i] = &c[i];
    func_L39_00689670(self, &menu);
    self[0x2A8] = 0;
    *(s32 *)(self + 0x2B0) = 0;
    *(s32 *)(self + 0x2B4) = 0;
    *(s32 *)(self + 0x1640) = 0;
    return self;
}
