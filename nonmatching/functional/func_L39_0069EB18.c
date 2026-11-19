/* functional: high. Compiles, not byte-exact; the first four cells multiply the row by 1.0 where retail has no multiply (same value); gp float constants named D_001DCD74..8C_sda (0x4C4..0x4DC off gp); cell ids 0xED32.. are text/icon ids */
typedef struct {
    s32 type;
    u8 label[0x34];
    f32 x, y, w, h;
} Item_0069EB18;
typedef struct {
    Item_0069EB18 h;
    f32 f48, f4C, f50, f54;
    s32 id;
    s32 color;
} Cell_0069EB18;
typedef struct {
    Item_0069EB18 h;
    s32 unk48;
    s32 count;
    void *items[0x60];
} Menu_0069EB18;

extern u8 D_L39_0047D410[];
extern u8 D_002484A8[];
extern f32 D_001DCD74_sda;
extern f32 D_001DCD78_sda;
extern f32 D_001DCD7C_sda;
extern f32 D_001DCD80_sda;
extern f32 D_001DCD84_sda;
extern f32 D_001DCD88_sda;
extern f32 D_001DCD8C_sda;
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(void *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

static __inline__ void mk_Cell_0069EB18(Cell_0069EB18 *c, s32 id, f32 k, f32 rowmul)
{
    f32 x = D_001DCD74_sda + ((D_001DCD7C_sda - D_001DCD8C_sda - D_001DCD8C_sda) * k) * 0.25f;
    f32 y = D_001DCD78_sda + ((-(D_001DCD80_sda - D_001DCD8C_sda)) * rowmul) / 3.0f;
    c->h.type = 0;
    func_L39_0068CD28(c, (s32)D_002484A8, x, y, D_001DCD84_sda, D_001DCD88_sda);
    c->h.type = 12;
    c->f48 = 0.0f;
    c->f4C = 1.0f;
    c->f50 = 0.0f;
    c->f54 = 1.0f;
    c->id = id;
    c->color = 0x706EC8FF;
}

void *func_L39_0069EB18(u8 *self)
{
    Cell_0069EB18 c[8];
    Item_0069EB18 bar;
    Menu_0069EB18 menu;
    f32 d, x, y, w;
    s32 i;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x2B4;
    *(void **)(self + 0x60) = D_L39_0047D410;

    mk_Cell_0069EB18(&c[0], 0xED32, -1.5f, 1.0f);
    mk_Cell_0069EB18(&c[1], 0xED2E, -0.5f, 1.0f);
    mk_Cell_0069EB18(&c[2], 0xED31, 0.5f, 1.0f);
    mk_Cell_0069EB18(&c[3], 0xED2F, 1.5f, 1.0f);
    mk_Cell_0069EB18(&c[4], 0xED4F, -1.5f, 0.0f);
    mk_Cell_0069EB18(&c[5], 0xED2D, -0.5f, 0.0f);
    mk_Cell_0069EB18(&c[6], 0xEA77, 0.5f, 0.0f);
    mk_Cell_0069EB18(&c[7], 0xEA69, 1.5f, 0.0f);

    d = D_001DCD8C_sda;
    x = D_001DCD74_sda;
    y = D_001DCD78_sda + (D_001DCD80_sda - d) / 3.0f;
    w = D_001DCD7C_sda - (d + d);
    bar.type = 0;
    func_L39_0068CD28(&bar, (s32)D_002484A8, x, y, w, 0.05f);
    bar.type = 1;

    menu.h.type = 0;
    func_L39_0068CD28(&menu, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    menu.unk48 = 0x2E;
    menu.h.x = 0.0f;
    menu.h.y = 0.0f;
    menu.h.w = 1.0f;
    menu.h.h = 1.0f;
    menu.count = 9;
    for (i = 0; i < 8; i++)
        menu.items[i] = &c[i];
    menu.items[8] = &bar;
    func_L39_00689670(self, &menu);
    return self;
}
