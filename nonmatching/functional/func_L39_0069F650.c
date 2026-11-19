/* functional: high. Compiles, not byte-exact (float literals); layout constants taken straight from retail immediates; label stride 0x50 kept */
typedef struct {
    s32 type;
    u8 label[0x34];
    f32 x, y, w, h;
} Item_0069F650;
typedef struct {
    Item_0069F650 h;
    u8 pad48[8];
} Label_0069F650;
typedef struct {
    Item_0069F650 h;
    f32 f48, f4C, f50, f54;
    s32 id;
    s32 color;
} Cell_0069F650;
typedef struct {
    Item_0069F650 h;
    s32 unk48;
    s32 count;
    void *items[0x60];
} Menu_0069F650;

extern u8 D_L39_0047D510[];
extern u8 D_00248508[];
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(void *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

static __inline__ void mk_Cell_0069F650(Cell_0069F650 *c, s32 id, f32 x, f32 y)
{
    c->h.type = 0;
    func_L39_0068CD28(c, (s32)D_00248508, x, y, 0.05f, 0.05f);
    c->h.type = 12;
    c->f48 = 0.0f;
    c->f4C = 1.0f;
    c->f50 = 0.0f;
    c->f54 = 1.0f;
    c->id = id;
    c->color = 0x706EC8FF;
}

void *func_L39_0069F650(u8 *self)
{
    Label_0069F650 lbl[8];
    Cell_0069F650 c[8];
    Menu_0069F650 menu;
    s32 i;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047D510;
    *(u8 **)(self + 0x2A4) = self + 0x2CC;
    lbl[0].h.type = 0;
    func_L39_0068CD28(&lbl[0], (s32)D_00248508, 0.502f, 0.24129999f, 0.435f, 0.05f);
    lbl[0].h.type = 1;
    lbl[1].h.type = 0;
    func_L39_0068CD28(&lbl[1], (s32)D_00248508, 0.502f, 0.2999f, 0.435f, 0.05f);
    lbl[1].h.type = 1;
    lbl[2].h.type = 0;
    func_L39_0068CD28(&lbl[2], (s32)D_00248508, 0.502f, 0.3585f, 0.435f, 0.05f);
    lbl[2].h.type = 1;
    lbl[3].h.type = 0;
    func_L39_0068CD28(&lbl[3], (s32)D_00248508, 0.502f, 0.41709998f, 0.435f, 0.05f);
    lbl[3].h.type = 1;
    lbl[4].h.type = 0;
    func_L39_0068CD28(&lbl[4], (s32)D_00248508, 0.502f, 0.4757f, 0.435f, 0.05f);
    lbl[4].h.type = 1;
    lbl[5].h.type = 0;
    func_L39_0068CD28(&lbl[5], (s32)D_00248508, 0.502f, 0.53429997f, 0.435f, 0.05f);
    lbl[5].h.type = 1;
    lbl[6].h.type = 0;
    func_L39_0068CD28(&lbl[6], (s32)D_00248508, 0.502f, 0.5929f, 0.435f, 0.05f);
    lbl[6].h.type = 1;
    lbl[7].h.type = 0;
    func_L39_0068CD28(&lbl[7], (s32)D_00248508, 0.502f, 0.6515f, 0.435f, 0.05f);
    lbl[7].h.type = 1;
    mk_Cell_0069F650(&c[0], 0xED32, 0.338875f, 0.7101f);
    mk_Cell_0069F650(&c[1], 0xED2E, 0.44762498f, 0.7101f);
    mk_Cell_0069F650(&c[2], 0xED31, 0.55637497f, 0.7101f);
    mk_Cell_0069F650(&c[3], 0xED2F, 0.66512495f, 0.7101f);
    mk_Cell_0069F650(&c[4], 0xED4F, 0.338875f, 0.7687f);
    mk_Cell_0069F650(&c[5], 0xED2D, 0.44762498f, 0.7687f);
    mk_Cell_0069F650(&c[6], 0xEA77, 0.55637497f, 0.7687f);
    mk_Cell_0069F650(&c[7], 0xEA69, 0.66512495f, 0.7687f);
    menu.h.type = 0;
    func_L39_0068CD28(&menu, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    menu.unk48 = 0x2E;
    menu.h.x = 0.0f;
    menu.h.y = 0.0f;
    menu.h.w = 1.0f;
    menu.h.h = 1.0f;
    menu.count = 16;
    for (i = 0; i < 8; i++)
        menu.items[i] = &lbl[i];
    for (i = 0; i < 8; i++)
        menu.items[8 + i] = &c[i];
    func_L39_00689670(self, &menu);
    return self;
}
