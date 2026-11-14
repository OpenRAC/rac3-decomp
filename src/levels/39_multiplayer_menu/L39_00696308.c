#include "common.h"

/* localdecomp:start func_L39_00696308 */
typedef struct {
    s32 type;
    u8 label[0x34];
    f32 x, y, w, h;
} Item_00696308;
typedef struct {
    Item_00696308 h;
    s32 unk48;
    s32 unk4C;
    void *unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    u8 pad68[8];
} Spin_00696308;
typedef struct {
    Item_00696308 h;
    char text[0x50];
    u8 pad98[8];
} Text_00696308;
typedef struct {
    Item_00696308 h;
    u8 pad48[8];
} Label_00696308;
typedef struct {
    Item_00696308 h;
    s32 unk48;
    s32 count;
    void *items[0x60];
} Menu_00696308;

extern char D_00248020[];
extern u8 D_L39_0047CDB0[];
extern void func_L39_00688388(void *);
extern s32 func_00381FF0(s32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_0068CD28(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
static __inline__ void mk_Item_00696308(Item_00696308 *it, s32 id, f32 x, f32 y, f32 w, f32 h)
{
    it->type = 0;
    func_L39_0068CD28((u8 *)it, id, x, y, w, h);
}
static __inline__ void mk_Text_00696308(Text_00696308 *t, s32 id, char *src, f32 x, f32 y, f32 w, f32 h)
{
    mk_Item_00696308(&t->h, id, x, y, w, h);
    t->h.type = 7;
    if (src) {
        func_00120D28(t->text, src, 0x4F);
        t->text[0x4F] = 0;
    } else {
        t->text[0] = 0;
    }
}

static __inline__ void mk_Spin_00696308(Spin_00696308 *s, s32 id, void *data, s32 max, s32 sel, f32 x, f32 y, f32 w, f32 h)
{
    mk_Item_00696308(&s->h, id, x, y, w, h);
    s->h.type = 5;
    s->unk50 = data;
    s->unk48 = 0;
    s->unk4C = 0;
    s->unk54 = max;
    s->unk58 = 0;
    s->unk5C = 0;
    s->unk60 = sel;
    s->unk64 = 0;
}

static __inline__ Item_00696308 *mk_Label_00696308(Item_00696308 *it, s32 id, f32 x, f32 y, f32 w, f32 h)
{
    mk_Item_00696308(it, id, x, y, w, h);
    it->type = 1;
    return it;
}

static __inline__ Menu_00696308 *mk_Menu_00696308(Menu_00696308 *m)
{
    mk_Item_00696308(&m->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    m->unk48 = 0x2E;
    m->count = 0;
    m->h.x = 0.0f;
    m->h.y = 0.0f;
    m->h.w = 1.0f;
    m->h.h = 1.0f;
    return m;
}

extern void func_L39_00689670(void *, void *);

void *func_L39_00696308(u8 *self)
{
    Item_00696308 title;
    Spin_00696308 spin;
    Text_00696308 t0;
    Text_00696308 t1;
    Item_00696308 hdr;
    Text_00696308 t2;
    Text_00696308 t3;
    Text_00696308 t4;
    Text_00696308 t5;
    Label_00696308 l[8];
    Menu_00696308 menu;
    s32 id;
    Label_00696308 *q0, *q1, *q2, *q3, *q4, *q5, *q6, *q7;

    func_L39_00688388(self);
    *(u8 **)(self + 0x2A4) = self + 0x4C4;
    *(void **)(self + 0x60) = D_L39_0047CDB0;
    mk_Item_00696308(&title, (s32)func_00381FF0(0xFC6), 0.27399998903274536f, 0.17499998211860657f, 0.32500001788139343f, 0.05000000074505806f);
    title.type = 1;
    id = (s32)func_00381FF0(0x101B);
    mk_Spin_00696308(&spin, (s32)D_00248020, (void *)id, 13, -1, 0.27399998903274536f, 0.5249999761581421f, 0.32500001788139343f, 0.6500000953674316f);
    mk_Text_00696308(&t0, (s32)func_00381FF0(0xF8A), D_00248020, 0.4855000376701355f, 0.17342858016490936f, 0.4050000011920929f, 0.05000000074505806f);
    mk_Text_00696308(&t1, (s32)func_00381FF0(0x1101), D_00248020, 0.4855000376701355f, 0.22028572857379913f, 0.4050000011920929f, 0.05000000074505806f);
    mk_Label_00696308(&hdr, (s32)func_00381FF0(0x1654), 0.6880000233650208f, 0.2671428620815277f, 0.4050000011920929f, 0.05000000074505806f);
    mk_Text_00696308(&t2, (s32)func_00381FF0(0x1334), D_00248020, 0.4855000376701355f, 0.3140000104904175f, 0.4050000011920929f, 0.05000000074505806f);
    mk_Text_00696308(&t3, (s32)func_00381FF0(0x1336), D_00248020, 0.4855000376701355f, 0.36085715889930725f, 0.4050000011920929f, 0.05000000074505806f);
    mk_Text_00696308(&t4, (s32)func_00381FF0(0x168F), D_00248020, 0.4855000376701355f, 0.407714307308197f, 0.4050000011920929f, 0.05000000074505806f);
    mk_Text_00696308(&t5, (s32)func_00381FF0(0x1691), D_00248020, 0.4855000376701355f, 0.4545714259147644f, 0.4050000011920929f, 0.05000000074505806f);
    q0 = (Label_00696308 *)mk_Label_00696308(&l[0].h, (s32)func_00381FF0(0x1171), 0.6880000233650208f, 0.5324286222457886f, 0.4050000011920929f, 0.05000000074505806f);
    q1 = (Label_00696308 *)mk_Label_00696308(&l[1].h, (s32)func_00381FF0(0xFC9), 0.6880000233650208f, 0.5812857151031494f, 0.4050000011920929f, 0.05000000074505806f);
    q2 = (Label_00696308 *)mk_Label_00696308(&l[2].h, (s32)func_00381FF0(0xFCE), 0.6880000233650208f, 0.630142867565155f, 0.4050000011920929f, 0.05000000074505806f);
    q3 = (Label_00696308 *)mk_Label_00696308(&l[3].h, (s32)func_00381FF0(0x1691), 0.6880000233650208f, 0.6790000200271606f, 0.4050000011920929f, 0.05000000074505806f);
    q4 = (Label_00696308 *)mk_Label_00696308(&l[4].h, (s32)func_00381FF0(0x1692), 0.6880000233650208f, 0.6790000200271606f, 0.4050000011920929f, 0.05000000074505806f);
    q5 = (Label_00696308 *)mk_Label_00696308(&l[5].h, (s32)func_00381FF0(0x1172), 0.6880000233650208f, 0.7278571724891663f, 0.4050000011920929f, 0.05000000074505806f);
    q6 = (Label_00696308 *)mk_Label_00696308(&l[6].h, (s32)func_00381FF0(0x168F), 0.6880000233650208f, 0.7767143249511719f, 0.4050000011920929f, 0.05000000074505806f);
    q7 = (Label_00696308 *)mk_Label_00696308(&l[7].h, (s32)func_00381FF0(0x1395), 0.6880000233650208f, 0.8255714178085327f, 0.4050000011920929f, 0.05000000074505806f);
    mk_Menu_00696308(&menu);
    menu.count = 17;
    menu.items[0] = &title;
    menu.items[1] = &spin;
    menu.items[3] = &t0;
    menu.items[4] = &t1;
    menu.items[2] = &hdr;
    menu.items[5] = &t2;
    menu.items[6] = &t3;
    menu.items[7] = &t4;
    menu.items[8] = &t5;
    menu.items[9] = q0;
    menu.items[10] = q1;
    menu.items[11] = q2;
    menu.items[12] = q3;
    menu.items[13] = q4;
    menu.items[14] = q5;
    menu.items[15] = q6;
    menu.items[16] = q7;
    func_L39_00689670(self, &menu);
    return self;
}
/* localdecomp:end func_L39_00696308 */

LINKER_REMNANT("asm/levels", func_L39_00696AC0);
