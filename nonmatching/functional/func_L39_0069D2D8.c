/* functional: high. Compiles; float literals load from sdata instead of lui/ori and arrays are built directly, so not byte-exact; widget structs reused from the sibling L39_00696308 layout; type codes 0..11 are item kinds */
typedef struct {
    s32 type;
    u8 label[0x34];
    f32 x, y, w, h;
} Item_0069D2D8;
typedef struct {
    Item_0069D2D8 h;
    s32 count;
    s32 *opts;
    s32 unk50;
    u8 pad54[0x1C];
} Sel_0069D2D8;
typedef struct {
    Item_0069D2D8 h;
    u8 pad48[8];
} Label_0069D2D8;
typedef struct {
    Item_0069D2D8 h;
    s32 unk48;
    s32 maxlen;
} Box_0069D2D8;
typedef struct {
    Item_0069D2D8 h;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
} Slider_0069D2D8;
typedef struct {
    Item_0069D2D8 h;
    s32 val;
    u8 pad4C[4];
} Icon_0069D2D8;
typedef struct {
    Item_0069D2D8 h;
    s32 unk48;
    s32 count;
    void *items[0x60];
} Menu_0069D2D8;

extern u8 D_L39_0047D210[];
extern u8 D_00248338[];
extern u8 D_00248340[];
extern f32 D_004B03A0[];
extern void func_L39_00688388(void *);
extern s32 func_0059A970(s32);
extern void func_L39_0068CD28(void *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

void *func_L39_0069D2D8(u8 *self)
{
    s32 a[3], b[2], c[2];
    Sel_0069D2D8 s0, s1, s2;
    Label_0069D2D8 lbl;
    Label_0069D2D8 lbl2;
    Box_0069D2D8 box;
    Slider_0069D2D8 sl;
    Icon_0069D2D8 ic[12];
    Menu_0069D2D8 menu;
    f32 *tbl;
    s32 i;

    func_L39_00688388(self);
    *(void **)(self + 0x60) = D_L39_0047D210;
    *(u8 **)(self + 0x2A4) = self + 0x2CC;
    a[0] = func_0059A970(0xF2A);
    a[1] = func_0059A970(0xF2B);
    a[2] = func_0059A970(0xF29);
    b[0] = func_0059A970(0xF2D);
    b[1] = func_0059A970(0xF2C);
    c[0] = func_0059A970(0xF2C);
    c[1] = func_0059A970(0xF2D);

    s0.h.type = 0;
    func_L39_0068CD28(&s0, func_0059A970(0x18C9), 0.11f, 0.598f, 0.78f, 0.04f);
    s0.h.type = 3;
    s0.count = 3;
    s0.opts = a;
    s0.unk50 = 0;

    s1.h.type = 0;
    func_L39_0068CD28(&s1, func_0059A970(0x191), 0.11f, 0.654f, 0.78f, 0.04f);
    s1.h.type = 3;
    s1.opts = c;
    s1.count = 2;
    s1.unk50 = 0;

    s2.h.type = 0;
    func_L39_0068CD28(&s2, func_0059A970(0x190), 0.11f, 0.71f, 0.78f, 0.04f);
    s2.h.type = 3;
    s2.opts = b;
    s2.count = 2;
    s2.unk50 = 0;

    lbl.h.type = 0;
    func_L39_0068CD28(&lbl, func_0059A970(0x18CA), 0.11f, 0.766f, 0.78f, 0.04f);
    lbl.h.type = 1;

    lbl2.h.type = 0;
    func_L39_0068CD28(&lbl2, func_0059A970(0x149), 0.11f, 0.82199997f, 0.78f, 0.04f);
    lbl2.h.type = 2;

    box.h.type = 0;
    func_L39_0068CD28(&box, (s32)D_00248338, 0.5f, 0.346f, 0.8f, 0.39f);
    box.h.type = 4;
    box.maxlen = 0x47;
    *(u8 *)&box.unk48 = 0;

    sl.h.type = 0;
    func_L39_0068CD28(&sl, func_0059A970(0x18CA), 0.7875f, 0.766f, 0.195f, 0.04f);
    sl.h.type = 10;
    sl.unk48 = 0;
    sl.unk4C = 100;
    sl.unk50 = 5;
    sl.unk54 = 5;

    tbl = D_004B03A0;
    for (i = 0; i < 12; i++) {
        ic[i].h.type = 0;
        func_L39_0068CD28(&ic[i], (s32)D_00248340, tbl[i * 3], tbl[i * 3 + 1], 1.0f, 1.0f);
        ic[i].h.type = 11;
        ic[i].val = ((s32 *)tbl)[i * 3 + 2];
    }

    menu.h.type = 0;
    func_L39_0068CD28(&menu, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    menu.unk48 = 0x2E;
    menu.h.x = 0.0f;
    menu.h.y = 0.0f;
    menu.h.w = 1.0f;
    menu.h.h = 1.0f;
    menu.count = 19;
    menu.items[0] = &s0;
    menu.items[1] = &s1;
    menu.items[2] = &s2;
    menu.items[3] = &sl;
    menu.items[4] = &lbl;
    menu.items[5] = &lbl2;
    menu.items[6] = &box;
    for (i = 0; i < 12; i++)
        menu.items[7 + i] = &ic[i];
    func_L39_00689670(self, &menu);
    return self;
}
