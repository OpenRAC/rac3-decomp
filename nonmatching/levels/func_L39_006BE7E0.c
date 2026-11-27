/* func_L39_006BE7E0: near miss (k8, 2026-11-26), from the functional C. Same length as retail (2505 words) but
   2455 word differences, under `-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as`
   (the file's line has neither): retail's float constants are lui/ori/mtc1 (SN's assembler expanding li.s) and its
   D_L39_002495xx loads are `lui $at; lwc1 %lo` (no split addresses), so the file needs that line.
   Found: every item is its own local in creation order (retail's stack offsets 0, 0x50, 0xA0, ... match); the
   empty label D_L39_00249550 is $gp-relative (size hint); all 96 constructor calls have the right args in order.
   Left: register allocation and sched1 placement of the shared constants. Retail holds 0x706EC8FF in three
   pseudos ($s0 spilled to 0x23B4, $a2 spilled to 0x2428, $fp), 1.0f in two ($f20, then $f21 from item 63 on),
   and keeps D_L39_0024957C / D_L39_00249580 in $f22/$f23 across calls (so the source had locals for those two
   columns; frame 0x24A0 with $f20-$f23 saved). Copies of the same constant point at cse.c's hash-table flush
   every 1000 insns, so the exact RTL count of the source matters. Locals x1/x2 for the two columns, assigned at
   the first use (inside the (x1 + x2) * 0.5f) gave the f22/f23 shape but a 0x24B0 frame.
   Tried: constructors returning the item pointer (sibling func_L39_0068CDA8's shape): worse (2832). */
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
__asm__(".extern D_L39_00249550, 4");
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

static __inline__ void base_006BE7E0(Base_006BE7E0 *b, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    b->type = 0;
    func_L39_0068CD28((u8 *)b, label, x, y, w, h);
}
static __inline__ void plain_init(Plain_006BE7E0 *p, s32 label, f32 x, f32 y, f32 w, f32 h)
{
    base_006BE7E0(&p->b, label, x, y, w, h);
    p->b.type = 1;
}
static __inline__ void sel_init(Sel_006BE7E0 *p, s32 label, f32 x, f32 y, f32 w, f32 h, s32 v)
{
    base_006BE7E0(&p->b, label, x, y, w, h);
    p->b.type = 4;
    p->f4C = v;
    p->f48 = 0;
}
static __inline__ void slot_init(Slot_006BE7E0 *p, s32 label, f32 x, f32 y, f32 w, f32 h, s32 id)
{
    base_006BE7E0(&p->b, label, x, y, w, h);
    p->b.type = 12;
    p->f58 = id;
    p->f50 = 0;
    p->f48 = 0;
    p->f54 = 1.0f;
    p->f4C = 1.0f;
    p->f5C = 0x706EC8FF;
}
void *func_L39_006BE7E0(u8 *this)
{
    Plain_006BE7E0 i0;
    Plain_006BE7E0 i1;
    Plain_006BE7E0 i2;
    Plain_006BE7E0 i3;
    Plain_006BE7E0 i4;
    Plain_006BE7E0 i5;
    Sel_006BE7E0 i6;
    Plain_006BE7E0 i7;
    Plain_006BE7E0 i8;
    Slot_006BE7E0 i9;
    Plain_006BE7E0 i10;
    Plain_006BE7E0 i11;
    Plain_006BE7E0 i12;
    Plain_006BE7E0 i13;
    Slot_006BE7E0 i14;
    Slot_006BE7E0 i15;
    Slot_006BE7E0 i16;
    Slot_006BE7E0 i17;
    Slot_006BE7E0 i18;
    Slot_006BE7E0 i19;
    Plain_006BE7E0 i20;
    Slot_006BE7E0 i21;
    Slot_006BE7E0 i22;
    Plain_006BE7E0 i23;
    Slot_006BE7E0 i24;
    Slot_006BE7E0 i25;
    Slot_006BE7E0 i26;
    Slot_006BE7E0 i27;
    Slot_006BE7E0 i28;
    Slot_006BE7E0 i29;
    Plain_006BE7E0 i30;
    Slot_006BE7E0 i31;
    Slot_006BE7E0 i32;
    Plain_006BE7E0 i33;
    Slot_006BE7E0 i34;
    Slot_006BE7E0 i35;
    Slot_006BE7E0 i36;
    Slot_006BE7E0 i37;
    Slot_006BE7E0 i38;
    Slot_006BE7E0 i39;
    Plain_006BE7E0 i40;
    Slot_006BE7E0 i41;
    Slot_006BE7E0 i42;
    Plain_006BE7E0 i43;
    Slot_006BE7E0 i44;
    Slot_006BE7E0 i45;
    Slot_006BE7E0 i46;
    Slot_006BE7E0 i47;
    Slot_006BE7E0 i48;
    Slot_006BE7E0 i49;
    Plain_006BE7E0 i50;
    Slot_006BE7E0 i51;
    Slot_006BE7E0 i52;
    Plain_006BE7E0 i53;
    Slot_006BE7E0 i54;
    Slot_006BE7E0 i55;
    Slot_006BE7E0 i56;
    Slot_006BE7E0 i57;
    Slot_006BE7E0 i58;
    Slot_006BE7E0 i59;
    Plain_006BE7E0 i60;
    Slot_006BE7E0 i61;
    Slot_006BE7E0 i62;
    Plain_006BE7E0 i63;
    Slot_006BE7E0 i64;
    Slot_006BE7E0 i65;
    Slot_006BE7E0 i66;
    Slot_006BE7E0 i67;
    Slot_006BE7E0 i68;
    Slot_006BE7E0 i69;
    Plain_006BE7E0 i70;
    Slot_006BE7E0 i71;
    Slot_006BE7E0 i72;
    Plain_006BE7E0 i73;
    Slot_006BE7E0 i74;
    Slot_006BE7E0 i75;
    Slot_006BE7E0 i76;
    Slot_006BE7E0 i77;
    Slot_006BE7E0 i78;
    Slot_006BE7E0 i79;
    Plain_006BE7E0 i80;
    Slot_006BE7E0 i81;
    Slot_006BE7E0 i82;
    Plain_006BE7E0 i83;
    Slot_006BE7E0 i84;
    Slot_006BE7E0 i85;
    Slot_006BE7E0 i86;
    Slot_006BE7E0 i87;
    Slot_006BE7E0 i88;
    Slot_006BE7E0 i89;
    Plain_006BE7E0 i90;
    Slot_006BE7E0 i91;
    Slot_006BE7E0 i92;
    Slot_006BE7E0 i93;
    Slot_006BE7E0 i94;
    Page_006BE7E0 page;

    func_L39_00688388(this);
    *(u8 **)(this + 0x60) = D_L39_0047E998;
    *(u8 *)(this + 0x2B4) = 0;
    *(u8 *)(this + 0x2C0) = 0;
    *(u8 **)(this + 0x2A4) = this + 0x304;
    *(s32 *)(this + 0x2B0) = -1;
    *(s32 *)(this + 0x2AC) = -1;

    plain_init(&i0, (s32)D_L39_00249550, 0.5f, 0.163f, 0.825f, 0.05f);
    plain_init(&i1, (s32)D_L39_00249550, 0.287f, 0.227f, 0.38f, 0.38f);
    plain_init(&i2, (s32)D_L39_00249550, 0.287f, 0.269f, 0.38f, 0.38f);
    plain_init(&i3, func_0059A970(0xFD1), 0.287f, 0.34149998f, 0.38f, 0.05f);
    plain_init(&i4, func_0059A970(0xFF9), 0.287f, 0.3905f, 0.38f, 0.05f);
    plain_init(&i5, func_0059A970(0x1666), 0.287f, 0.3905f, 0.38f, 0.05f);
    sel_init(&i6, (s32)D_L39_00249550, 0.704f, 0.31f, 0.39999998f, 0.21000001f, 0x25);
    plain_init(&i7, func_0059A970(0x1332), D_L39_00249578[0], 0.46488887f, D_L39_002495A0[0], 0.05f);
    plain_init(&i8, func_0059A970(0x1607), ((D_L39_0024957C[0]+D_L39_00249580[0])*0.5f), 0.46488887f, D_L39_002495C0[0], 0.05f);
    slot_init(&i9, (s32)D_L39_00249550, D_L39_0024958C[0], 0.46488887f, 0.03f, 0.04f, 0xED3F);
    plain_init(&i10, func_0059A970(0x1631), D_L39_00249590[0], 0.46488887f, D_L39_002495B8[0], 0.05f);
    plain_init(&i11, func_0059A970(0x1632), D_L39_00249594[0], 0.46488887f, D_L39_002495BC[0], 0.05f);
    plain_init(&i12, func_0059A970(0x1633), D_L39_00249598[0], 0.46488887f, D_L39_002495C0[0], 0.05f);
    plain_init(&i13, (s32)D_L39_00249550, D_L39_00249578[0], 0.51066667f, D_L39_002495A0[0], 0.05f);
    slot_init(&i14, (s32)D_L39_00249550, D_L39_0024957C[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&i15, (s32)D_L39_00249550, D_L39_00249580[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&i16, (s32)D_L39_00249550, D_L39_00249584[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&i17, (s32)D_L39_00249550, D_L39_00249588[0], 0.51066667f, 0.03f, 0.04f, 0xED26);
    slot_init(&i18, (s32)D_L39_00249550, D_L39_0024958C[0], 0.51066667f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i19, (s32)D_L39_00249550, D_L39_00249590[0], 0.51066667f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i20, (s32)D_L39_00249550, D_L39_00249594[0], 0.51066667f, D_L39_002495AC[0], 0.05f);
    slot_init(&i21, (s32)D_L39_00249550, D_L39_00249598[0], 0.51066667f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i22, (s32)D_L39_00249550, D_L39_00249590[0], 0.51066667f, 0.03f, 0.04f, 0xED3D);
    plain_init(&i23, (s32)D_L39_00249550, D_L39_00249578[0], 0.55644447f, D_L39_002495A0[0], 0.05f);
    slot_init(&i24, (s32)D_L39_00249550, D_L39_0024957C[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&i25, (s32)D_L39_00249550, D_L39_00249580[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&i26, (s32)D_L39_00249550, D_L39_00249584[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&i27, (s32)D_L39_00249550, D_L39_00249588[0], 0.55644447f, 0.03f, 0.04f, 0xED26);
    slot_init(&i28, (s32)D_L39_00249550, D_L39_0024958C[0], 0.55644447f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i29, (s32)D_L39_00249550, D_L39_00249590[0], 0.55644447f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i30, (s32)D_L39_00249550, D_L39_00249594[0], 0.55644447f, D_L39_002495AC[0], 0.05f);
    slot_init(&i31, (s32)D_L39_00249550, D_L39_00249598[0], 0.55644447f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i32, (s32)D_L39_00249550, D_L39_00249590[0], 0.55644447f, 0.03f, 0.04f, 0xED3D);
    plain_init(&i33, (s32)D_L39_00249550, D_L39_00249578[0], 0.6022222f, D_L39_002495A0[0], 0.05f);
    slot_init(&i34, (s32)D_L39_00249550, D_L39_0024957C[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&i35, (s32)D_L39_00249550, D_L39_00249580[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&i36, (s32)D_L39_00249550, D_L39_00249584[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&i37, (s32)D_L39_00249550, D_L39_00249588[0], 0.6022222f, 0.03f, 0.04f, 0xED26);
    slot_init(&i38, (s32)D_L39_00249550, D_L39_0024958C[0], 0.6022222f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i39, (s32)D_L39_00249550, D_L39_00249590[0], 0.6022222f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i40, (s32)D_L39_00249550, D_L39_00249594[0], 0.6022222f, D_L39_002495AC[0], 0.05f);
    slot_init(&i41, (s32)D_L39_00249550, D_L39_00249598[0], 0.6022222f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i42, (s32)D_L39_00249550, D_L39_00249590[0], 0.6022222f, 0.03f, 0.04f, 0xED3D);
    plain_init(&i43, (s32)D_L39_00249550, D_L39_00249578[0], 0.648f, D_L39_002495A0[0], 0.05f);
    slot_init(&i44, (s32)D_L39_00249550, D_L39_0024957C[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&i45, (s32)D_L39_00249550, D_L39_00249580[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&i46, (s32)D_L39_00249550, D_L39_00249584[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&i47, (s32)D_L39_00249550, D_L39_00249588[0], 0.648f, 0.03f, 0.04f, 0xED26);
    slot_init(&i48, (s32)D_L39_00249550, D_L39_0024958C[0], 0.648f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i49, (s32)D_L39_00249550, D_L39_00249590[0], 0.648f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i50, (s32)D_L39_00249550, D_L39_00249594[0], 0.648f, D_L39_002495AC[0], 0.05f);
    slot_init(&i51, (s32)D_L39_00249550, D_L39_00249598[0], 0.648f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i52, (s32)D_L39_00249550, D_L39_00249590[0], 0.648f, 0.03f, 0.04f, 0xED3D);
    plain_init(&i53, (s32)D_L39_00249550, D_L39_00249578[0], 0.6937778f, D_L39_002495A0[0], 0.05f);
    slot_init(&i54, (s32)D_L39_00249550, D_L39_0024957C[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&i55, (s32)D_L39_00249550, D_L39_00249580[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&i56, (s32)D_L39_00249550, D_L39_00249584[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&i57, (s32)D_L39_00249550, D_L39_00249588[0], 0.6937778f, 0.03f, 0.04f, 0xED26);
    slot_init(&i58, (s32)D_L39_00249550, D_L39_0024958C[0], 0.6937778f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i59, (s32)D_L39_00249550, D_L39_00249590[0], 0.6937778f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i60, (s32)D_L39_00249550, D_L39_00249594[0], 0.6937778f, D_L39_002495AC[0], 0.05f);
    slot_init(&i61, (s32)D_L39_00249550, D_L39_00249598[0], 0.6937778f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i62, (s32)D_L39_00249550, D_L39_00249590[0], 0.6937778f, 0.03f, 0.04f, 0xED3D);
    plain_init(&i63, (s32)D_L39_00249550, D_L39_00249578[0], 0.73955554f, D_L39_002495A0[0], 0.05f);
    slot_init(&i64, (s32)D_L39_00249550, D_L39_0024957C[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&i65, (s32)D_L39_00249550, D_L39_00249580[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&i66, (s32)D_L39_00249550, D_L39_00249584[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&i67, (s32)D_L39_00249550, D_L39_00249588[0], 0.73955554f, 0.03f, 0.04f, 0xED26);
    slot_init(&i68, (s32)D_L39_00249550, D_L39_0024958C[0], 0.73955554f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i69, (s32)D_L39_00249550, D_L39_00249590[0], 0.73955554f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i70, (s32)D_L39_00249550, D_L39_00249594[0], 0.73955554f, D_L39_002495AC[0], 0.05f);
    slot_init(&i71, (s32)D_L39_00249550, D_L39_00249598[0], 0.73955554f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i72, (s32)D_L39_00249550, D_L39_00249590[0], 0.73955554f, 0.03f, 0.04f, 0xED3D);
    plain_init(&i73, (s32)D_L39_00249550, D_L39_00249578[0], 0.78533334f, D_L39_002495A0[0], 0.05f);
    slot_init(&i74, (s32)D_L39_00249550, D_L39_0024957C[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&i75, (s32)D_L39_00249550, D_L39_00249580[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&i76, (s32)D_L39_00249550, D_L39_00249584[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&i77, (s32)D_L39_00249550, D_L39_00249588[0], 0.78533334f, 0.03f, 0.04f, 0xED26);
    slot_init(&i78, (s32)D_L39_00249550, D_L39_0024958C[0], 0.78533334f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i79, (s32)D_L39_00249550, D_L39_00249590[0], 0.78533334f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i80, (s32)D_L39_00249550, D_L39_00249594[0], 0.78533334f, D_L39_002495AC[0], 0.05f);
    slot_init(&i81, (s32)D_L39_00249550, D_L39_00249598[0], 0.78533334f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i82, (s32)D_L39_00249550, D_L39_00249590[0], 0.78533334f, 0.03f, 0.04f, 0xED3D);
    plain_init(&i83, (s32)D_L39_00249550, D_L39_00249578[0], 0.83111113f, D_L39_002495A0[0], 0.05f);
    slot_init(&i84, (s32)D_L39_00249550, D_L39_0024957C[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&i85, (s32)D_L39_00249550, D_L39_00249580[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&i86, (s32)D_L39_00249550, D_L39_00249584[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&i87, (s32)D_L39_00249550, D_L39_00249588[0], 0.83111113f, 0.03f, 0.04f, 0xED26);
    slot_init(&i88, (s32)D_L39_00249550, D_L39_0024958C[0], 0.83111113f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i89, (s32)D_L39_00249550, D_L39_00249590[0], 0.83111113f, 0.021f, 0.027999999f, 0xED3D);
    plain_init(&i90, (s32)D_L39_00249550, D_L39_00249594[0], 0.83111113f, D_L39_002495AC[0], 0.05f);
    slot_init(&i91, (s32)D_L39_00249550, D_L39_00249598[0], 0.83111113f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i92, (s32)D_L39_00249550, D_L39_00249590[0], 0.83111113f, 0.03f, 0.04f, 0xED3D);
    slot_init(&i93, (s32)D_L39_00249550, D_L39_0024959C[0], 0.46488887f, 0.03f, 0.04f, 0xED2B);
    slot_init(&i94, (s32)D_L39_00249550, D_L39_0024959C[0], 0.46488887f, 0.03f, 0.04f, 0xED2B);
    base_006BE7E0(&page.b, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    page.f48 = 0x2E;
    page.count = 0;
    page.b.x = 0;
    page.b.y = 0;
    page.b.w = 1.0f;
    page.b.h = 1.0f;
    page.items[0] = &i0;
    page.items[1] = &i1;
    page.items[2] = &i2;
    page.items[3] = &i3;
    page.items[4] = &i4;
    page.items[5] = &i5;
    page.items[6] = &i6;
    page.items[7] = &i7;
    page.items[8] = &i8;
    page.items[9] = &i9;
    page.items[10] = &i10;
    page.items[11] = &i11;
    page.items[12] = &i12;
    page.items[13] = &i93;
    page.items[14] = &i94;
    page.items[15] = &i13;
    page.items[16] = &i23;
    page.items[17] = &i33;
    page.items[18] = &i43;
    page.items[19] = &i53;
    page.items[20] = &i63;
    page.items[21] = &i73;
    page.items[22] = &i83;
    page.items[23] = &i14;
    page.items[24] = &i24;
    page.items[25] = &i34;
    page.items[26] = &i44;
    page.items[27] = &i54;
    page.items[28] = &i64;
    page.items[29] = &i74;
    page.items[30] = &i84;
    page.items[31] = &i15;
    page.items[32] = &i25;
    page.items[33] = &i35;
    page.items[34] = &i45;
    page.items[35] = &i55;
    page.items[36] = &i65;
    page.items[37] = &i75;
    page.items[38] = &i85;
    page.items[39] = &i16;
    page.items[40] = &i26;
    page.items[41] = &i36;
    page.items[42] = &i46;
    page.items[43] = &i56;
    page.items[44] = &i66;
    page.items[45] = &i76;
    page.items[46] = &i86;
    page.items[47] = &i17;
    page.items[48] = &i27;
    page.items[49] = &i37;
    page.items[50] = &i47;
    page.items[51] = &i57;
    page.items[52] = &i67;
    page.items[53] = &i77;
    page.items[54] = &i87;
    page.items[55] = &i18;
    page.items[56] = &i28;
    page.items[57] = &i38;
    page.items[58] = &i48;
    page.items[59] = &i58;
    page.items[60] = &i68;
    page.items[61] = &i78;
    page.items[62] = &i88;
    page.items[63] = &i22;
    page.items[64] = &i32;
    page.items[65] = &i42;
    page.items[66] = &i52;
    page.items[67] = &i62;
    page.items[68] = &i72;
    page.items[69] = &i82;
    page.items[70] = &i92;
    page.items[71] = &i19;
    page.items[72] = &i29;
    page.items[73] = &i39;
    page.items[74] = &i49;
    page.items[75] = &i59;
    page.items[76] = &i69;
    page.items[77] = &i79;
    page.items[78] = &i89;
    page.items[79] = &i20;
    page.items[80] = &i30;
    page.items[81] = &i40;
    page.items[82] = &i50;
    page.items[83] = &i60;
    page.items[84] = &i70;
    page.items[85] = &i80;
    page.items[86] = &i90;
    page.items[87] = &i21;
    page.items[88] = &i31;
    page.items[89] = &i41;
    page.items[90] = &i51;
    page.items[91] = &i61;
    page.items[92] = &i71;
    page.items[93] = &i81;
    page.items[94] = &i91;
    page.count = 0x5F;
    func_L39_00689670(this, &page);
    return this;
}

