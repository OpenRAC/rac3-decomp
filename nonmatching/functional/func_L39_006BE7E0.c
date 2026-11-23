/* functional: high. Builds the multiplayer-menu page: 95 stack items (27 plain labels, 67 type-12 slot items, 1 selector) in retail creation order, then the item pointer table in retail order (column-major), and hands the page to func_L39_00689670. Items and array order were extracted from the assembly by a symbolic pass; not byte-exact (2222 diff: scheduling/spill order), frame size matches retail (0x24A0). */
typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ char label[0x34];
    /* 0x38 */ f32 x;
    /* 0x3C */ f32 y;
    /* 0x40 */ f32 w;
    /* 0x44 */ f32 h;
} Base_006BE7E0;

typedef struct {
    Base_006BE7E0 b;
    u8 pad48[8];
} Plain_006BE7E0;

typedef struct {
    Base_006BE7E0 b;
    u8 f48;
    u8 pad49[3];
    s32 f4C;
} Sel_006BE7E0;

typedef struct {
    Base_006BE7E0 b;
    s32 f48;
    f32 f4C;
    s32 f50;
    f32 f54;
    s32 f58;
    s32 f5C;
} Slot_006BE7E0;

typedef struct {
    Base_006BE7E0 b;
    s32 f48;
    s32 count;
    Base_006BE7E0 *items[0x60];
} Page_006BE7E0;

extern u8 D_L39_0047E998[];
extern char D_L39_00249550[];
extern f32 D_L39_00249578[];
extern f32 D_L39_0024957C[];
extern f32 D_L39_00249580[];
extern f32 D_L39_00249584[];
extern f32 D_L39_00249588[];
extern f32 D_L39_0024958C[];
extern f32 D_L39_00249590[];
extern f32 D_L39_00249594[];
extern f32 D_L39_00249598[];
extern f32 D_L39_0024959C[];
extern f32 D_L39_002495A0[];
extern f32 D_L39_002495AC[];
extern f32 D_L39_002495B8[];
extern f32 D_L39_002495BC[];
extern f32 D_L39_002495C0[];
extern void *func_L39_00688388(void *);
extern s32 func_0059A970(s32);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);

/* The menu items are objects built on the stack; their constructors are inlined here
 * (same shapes as the sibling pages). */
static __inline__ void base_006BE7E0(Base_006BE7E0 *b, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    b->type = 0;
    func_L39_0068CD28((u8 *)b, label, x, y, w, h);
}

/* plain item (type 1) */
static __inline__ void plain_init(Plain_006BE7E0 *p, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    base_006BE7E0(&p->b, label, x, y, w, h);
    p->b.type = 1;
}

/* selector item (type 4) */
static __inline__ void sel_init(Sel_006BE7E0 *s, s32 label, f32 x, f32 y, f32 w, f32 h, s32 v)
{
    base_006BE7E0(&s->b, label, x, y, w, h);
    s->b.type = 4;
    s->f4C = v;
    s->f48 = 0;
}

/* slot item (type 12) with its sprite id */
static __inline__ void slot_init(Slot_006BE7E0 *s, s32 label, f32 x, f32 y, f32 w, f32 h, s32 id)
{
    base_006BE7E0(&s->b, label, x, y, w, h);
    s->b.type = 12;
    s->f58 = id;
    s->f50 = 0;
    s->f48 = 0;
    s->f54 = 1.0f;
    s->f4C = 1.0f;
    s->f5C = 0x706EC8FF;
}

void *func_L39_006BE7E0(u8 *this)
{
    Plain_006BE7E0 a[27];
    Slot_006BE7E0 c[67];
    Sel_006BE7E0 e[1];
    Page_006BE7E0 page;

    func_L39_00688388(this);
    *(u8 **)(this + 0x60) = D_L39_0047E998;
    *(u8 *)(this + 0x2B4) = 0;
    *(u8 *)(this + 0x2C0) = 0;
    *(u8 **)(this + 0x2A4) = this + 0x304;
    *(s32 *)(this + 0x2B0) = -1;
    *(s32 *)(this + 0x2AC) = -1;

    plain_init(&a[0], (s32)D_L39_00249550, 0.5f, 0.163f, 0.825f, 0.05f);
    plain_init(&a[1], (s32)D_L39_00249550, 0.287f, 0.227f, 0.38f, 0.38f);
    plain_init(&a[2], (s32)D_L39_00249550, 0.287f, 0.269f, 0.38f, 0.38f);
    plain_init(&a[3], func_0059A970(0xFD1), 0.287f, 0.34149998f, 0.38f, 0.05f);
    plain_init(&a[4], func_0059A970(0xFF9), 0.287f, 0.3905f, 0.38f, 0.05f);
    plain_init(&a[5], func_0059A970(0x1666), 0.287f, 0.3905f, 0.38f, 0.05f);
    sel_init(&e[0], (s32)D_L39_00249550, 0.704f, 0.31f, 0.39999998f, 0.21000001f, 0x25);
    plain_init(&a[6], func_0059A970(0x1332), D_L39_00249578[0], 0.46488887f, D_L39_002495A0[0], 0.05f);
    plain_init(&a[7], func_0059A970(0x1607), ((D_L39_0024957C[0]+D_L39_00249580[0])*0.5f), 0.46488887f, D_L39_002495C0[0], 0.05f);
    slot_init(&c[0], (s32)D_L39_00249550, D_L39_0024958C[0], 0.46488887f, 0.03f, 0.04f, 0xED3F);
    plain_init(&a[8], func_0059A970(0x1631), D_L39_00249590[0], 0.46488887f, D_L39_002495B8[0], 0.05f);
    plain_init(&a[9], func_0059A970(0x1632), D_L39_00249594[0], 0.46488887f, D_L39_002495BC[0], 0.05f);
    plain_init(&a[10], func_0059A970(0x1633), D_L39_00249598[0], 0.46488887f, D_L39_002495C0[0], 0.05f);
    plain_init(&a[11], (s32)D_L39_00249550, D_L39_00249578[0], 0.51066667f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[1], (s32)D_L39_00249550, D_L39_0024957C[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[2], (s32)D_L39_00249550, D_L39_00249580[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[3], (s32)D_L39_00249550, D_L39_00249584[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[4], (s32)D_L39_00249550, D_L39_00249588[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[5], (s32)D_L39_00249550, D_L39_0024958C[0], 0.51066667f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[6], (s32)D_L39_00249550, D_L39_00249590[0], 0.51066667f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[12], (s32)D_L39_00249550, D_L39_00249594[0], 0.51066667f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[7], (s32)D_L39_00249550, D_L39_00249598[0], 0.51066667f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[8], (s32)D_L39_00249550, D_L39_00249590[0], 0.51066667f, 0.03f, 0.04f, 0xED3D);
    plain_init(&a[13], (s32)D_L39_00249550, D_L39_00249578[0], 0.55644447f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[9], (s32)D_L39_00249550, D_L39_0024957C[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[10], (s32)D_L39_00249550, D_L39_00249580[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[11], (s32)D_L39_00249550, D_L39_00249584[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[12], (s32)D_L39_00249550, D_L39_00249588[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[13], (s32)D_L39_00249550, D_L39_0024958C[0], 0.55644447f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[14], (s32)D_L39_00249550, D_L39_00249590[0], 0.55644447f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[14], (s32)D_L39_00249550, D_L39_00249594[0], 0.55644447f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[15], (s32)D_L39_00249550, D_L39_00249598[0], 0.55644447f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[16], (s32)D_L39_00249550, D_L39_00249590[0], 0.55644447f, 0.03f, 0.04f, 0xED3D);
    plain_init(&a[15], (s32)D_L39_00249550, D_L39_00249578[0], 0.6022222f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[17], (s32)D_L39_00249550, D_L39_0024957C[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[18], (s32)D_L39_00249550, D_L39_00249580[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[19], (s32)D_L39_00249550, D_L39_00249584[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[20], (s32)D_L39_00249550, D_L39_00249588[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[21], (s32)D_L39_00249550, D_L39_0024958C[0], 0.6022222f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[22], (s32)D_L39_00249550, D_L39_00249590[0], 0.6022222f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[16], (s32)D_L39_00249550, D_L39_00249594[0], 0.6022222f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[23], (s32)D_L39_00249550, D_L39_00249598[0], 0.6022222f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[24], (s32)D_L39_00249550, D_L39_00249590[0], 0.6022222f, 0.03f, 0.04f, 0xED3D);
    plain_init(&a[17], (s32)D_L39_00249550, D_L39_00249578[0], 0.648f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[25], (s32)D_L39_00249550, D_L39_0024957C[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[26], (s32)D_L39_00249550, D_L39_00249580[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[27], (s32)D_L39_00249550, D_L39_00249584[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[28], (s32)D_L39_00249550, D_L39_00249588[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[29], (s32)D_L39_00249550, D_L39_0024958C[0], 0.648f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[30], (s32)D_L39_00249550, D_L39_00249590[0], 0.648f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[18], (s32)D_L39_00249550, D_L39_00249594[0], 0.648f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[31], (s32)D_L39_00249550, D_L39_00249598[0], 0.648f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[32], (s32)D_L39_00249550, D_L39_00249590[0], 0.648f, 0.03f, 0.04f, 0xED3D);
    plain_init(&a[19], (s32)D_L39_00249550, D_L39_00249578[0], 0.6937778f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[33], (s32)D_L39_00249550, D_L39_0024957C[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[34], (s32)D_L39_00249550, D_L39_00249580[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[35], (s32)D_L39_00249550, D_L39_00249584[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[36], (s32)D_L39_00249550, D_L39_00249588[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[37], (s32)D_L39_00249550, D_L39_0024958C[0], 0.6937778f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[38], (s32)D_L39_00249550, D_L39_00249590[0], 0.6937778f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[20], (s32)D_L39_00249550, D_L39_00249594[0], 0.6937778f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[39], (s32)D_L39_00249550, D_L39_00249598[0], 0.6937778f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[40], (s32)D_L39_00249550, D_L39_00249590[0], 0.6937778f, 0.03f, 0.04f, 0xED3D);
    plain_init(&a[21], (s32)D_L39_00249550, D_L39_00249578[0], 0.73955554f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[41], (s32)D_L39_00249550, D_L39_0024957C[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[42], (s32)D_L39_00249550, D_L39_00249580[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[43], (s32)D_L39_00249550, D_L39_00249584[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[44], (s32)D_L39_00249550, D_L39_00249588[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[45], (s32)D_L39_00249550, D_L39_0024958C[0], 0.73955554f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[46], (s32)D_L39_00249550, D_L39_00249590[0], 0.73955554f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[22], (s32)D_L39_00249550, D_L39_00249594[0], 0.73955554f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[47], (s32)D_L39_00249550, D_L39_00249598[0], 0.73955554f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[48], (s32)D_L39_00249550, D_L39_00249590[0], 0.73955554f, 0.03f, 0.04f, 0xED3D);
    plain_init(&a[23], (s32)D_L39_00249550, D_L39_00249578[0], 0.78533334f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[49], (s32)D_L39_00249550, D_L39_0024957C[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[50], (s32)D_L39_00249550, D_L39_00249580[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[51], (s32)D_L39_00249550, D_L39_00249584[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[52], (s32)D_L39_00249550, D_L39_00249588[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[53], (s32)D_L39_00249550, D_L39_0024958C[0], 0.78533334f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[54], (s32)D_L39_00249550, D_L39_00249590[0], 0.78533334f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[24], (s32)D_L39_00249550, D_L39_00249594[0], 0.78533334f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[55], (s32)D_L39_00249550, D_L39_00249598[0], 0.78533334f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[56], (s32)D_L39_00249550, D_L39_00249590[0], 0.78533334f, 0.03f, 0.04f, 0xED3D);
    plain_init(&a[25], (s32)D_L39_00249550, D_L39_00249578[0], 0.83111113f, D_L39_002495A0[0], 0.05f);
    slot_init(&c[57], (s32)D_L39_00249550, D_L39_0024957C[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[58], (s32)D_L39_00249550, D_L39_00249580[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[59], (s32)D_L39_00249550, D_L39_00249584[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[60], (s32)D_L39_00249550, D_L39_00249588[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&c[61], (s32)D_L39_00249550, D_L39_0024958C[0], 0.83111113f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[62], (s32)D_L39_00249550, D_L39_00249590[0], 0.83111113f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&a[26], (s32)D_L39_00249550, D_L39_00249594[0], 0.83111113f, D_L39_002495AC[0], 0.05f);
    slot_init(&c[63], (s32)D_L39_00249550, D_L39_00249598[0], 0.83111113f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[64], (s32)D_L39_00249550, D_L39_00249590[0], 0.83111113f, 0.03f, 0.04f, 0xED3D);
    slot_init(&c[65], (s32)D_L39_00249550, D_L39_0024959C[0], 0.46488887f, 0.03f, 0.04f, 0xED2B);
    slot_init(&c[66], (s32)D_L39_00249550, D_L39_0024959C[0], 0.46488887f, 0.03f, 0.04f, 0xED2B);

    base_006BE7E0(&page.b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    page.f48 = 0x2E;
    page.count = 0;
    page.b.x = 0;
    page.b.y = 0;
    page.b.w = 1.0f;
    page.b.h = 1.0f;
    page.items[0] = &a[0];
    page.items[1] = &a[1];
    page.items[2] = &a[2];
    page.items[3] = &a[3];
    page.items[4] = &a[4];
    page.items[5] = &a[5];
    page.items[6] = &e[0];
    page.items[7] = &a[6];
    page.items[8] = &a[7];
    page.items[9] = &c[0];
    page.items[10] = &a[8];
    page.items[11] = &a[9];
    page.items[12] = &a[10];
    page.items[13] = &c[65];
    page.items[14] = &c[66];
    page.items[15] = &a[11];
    page.items[16] = &a[13];
    page.items[17] = &a[15];
    page.items[18] = &a[17];
    page.items[19] = &a[19];
    page.items[20] = &a[21];
    page.items[21] = &a[23];
    page.items[22] = &a[25];
    page.items[23] = &c[1];
    page.items[24] = &c[9];
    page.items[25] = &c[17];
    page.items[26] = &c[25];
    page.items[27] = &c[33];
    page.items[28] = &c[41];
    page.items[29] = &c[49];
    page.items[30] = &c[57];
    page.items[31] = &c[2];
    page.items[32] = &c[10];
    page.items[33] = &c[18];
    page.items[34] = &c[26];
    page.items[35] = &c[34];
    page.items[36] = &c[42];
    page.items[37] = &c[50];
    page.items[38] = &c[58];
    page.items[39] = &c[3];
    page.items[40] = &c[11];
    page.items[41] = &c[19];
    page.items[42] = &c[27];
    page.items[43] = &c[35];
    page.items[44] = &c[43];
    page.items[45] = &c[51];
    page.items[46] = &c[59];
    page.items[47] = &c[4];
    page.items[48] = &c[12];
    page.items[49] = &c[20];
    page.items[50] = &c[28];
    page.items[51] = &c[36];
    page.items[52] = &c[44];
    page.items[53] = &c[52];
    page.items[54] = &c[60];
    page.items[55] = &c[5];
    page.items[56] = &c[13];
    page.items[57] = &c[21];
    page.items[58] = &c[29];
    page.items[59] = &c[37];
    page.items[60] = &c[45];
    page.items[61] = &c[53];
    page.items[62] = &c[61];
    page.items[63] = &c[8];
    page.items[64] = &c[16];
    page.items[65] = &c[24];
    page.items[66] = &c[32];
    page.items[67] = &c[40];
    page.items[68] = &c[48];
    page.items[69] = &c[56];
    page.items[70] = &c[64];
    page.items[71] = &c[6];
    page.items[72] = &c[14];
    page.items[73] = &c[22];
    page.items[74] = &c[30];
    page.items[75] = &c[38];
    page.items[76] = &c[46];
    page.items[77] = &c[54];
    page.items[78] = &c[62];
    page.items[79] = &a[12];
    page.items[80] = &a[14];
    page.items[81] = &a[16];
    page.items[82] = &a[18];
    page.items[83] = &a[20];
    page.items[84] = &a[22];
    page.items[85] = &a[24];
    page.items[86] = &a[26];
    page.items[87] = &c[7];
    page.items[88] = &c[15];
    page.items[89] = &c[23];
    page.items[90] = &c[31];
    page.items[91] = &c[39];
    page.items[92] = &c[47];
    page.items[93] = &c[55];
    page.items[94] = &c[63];
    page.count = 0x5F;
    func_L39_00689670(this, &page);
    return this;
}
