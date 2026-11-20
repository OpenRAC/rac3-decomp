#include "common.h"

/* localdecomp:start func_L39_0069F650 */
typedef struct {
    s32 unk0;
    u8 pad4[0x50 - 4];
} Btn_0069F650;

typedef struct {
    s32 unk0;
    u8 pad4[0x48 - 4];
    s32 unk48;
    f32 unk4C;
    s32 unk50;
    f32 unk54;
    s32 unk58;
    s32 unk5C;
} Lbl_0069F650;

typedef struct {
    s32 unk0;
    u8 pad4[0x38 - 4];
    s32 unk38;
    s32 unk3C;
    f32 unk40;
    f32 unk44;
    s32 unk48;
    s32 unk4C;
    void *unk50[16];
    u8 pad90[0x1D0 - 0x90];
} List_0069F650;

extern u8 D_L39_0047D510[];
extern u8 D_L39_00248508[];
extern void func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *arg0, u8 *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);
extern void func_L39_00689670(void *, void *);

static __inline__ void btn_init_0069F650(Btn_0069F650 *b, u8 *tex, f32 x, f32 y, f32 w, f32 h)
{
    b->unk0 = 0;
    func_L39_0068CD28((u8 *)b, tex, x, y, w, h);
    b->unk0 = 1;
}

static __inline__ void lbl_init_0069F650(Lbl_0069F650 *q, u8 *tex, f32 x, f32 y, s32 id)
{
    q->unk0 = 0;
    func_L39_0068CD28((u8 *)q, tex, x, y, 0.05f, 0.05f);
    q->unk0 = 0xC;
    q->unk58 = id;
    q->unk48 = 0;
    q->unk50 = 0;
    q->unk4C = 1.0f;
    q->unk54 = 1.0f;
    q->unk5C = 0x706EC8FF;
}

static __inline__ void list_init_0069F650(List_0069F650 *l)
{
    l->unk0 = 0;
    func_L39_0068CD28((u8 *)l, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    l->unk48 = 0x2E;
    l->unk4C = 0;
    l->unk38 = 0;
    l->unk3C = 0;
    l->unk40 = 1.0f;
    l->unk44 = 1.0f;
}

void *func_L39_0069F650(u8 *const this)
{
    Btn_0069F650 btn[8];
    Lbl_0069F650 lbl[8];
    List_0069F650 list;
    u8 *tex;

    func_L39_00688388(this);
    *(void **)(this + 0x60) = D_L39_0047D510;
    *(u8 **)(this + 0x2A4) = this + 0x2CC;
    tex = D_L39_00248508;

    btn_init_0069F650(&btn[0], tex, 0.502f, 0.24129999f, 0.435f, 0.05f);
    btn_init_0069F650(&btn[1], tex, 0.502f, 0.2999f, 0.435f, 0.05f);
    btn_init_0069F650(&btn[2], tex, 0.502f, 0.3585f, 0.435f, 0.05f);
    btn_init_0069F650(&btn[3], tex, 0.502f, 0.41709998f, 0.435f, 0.05f);
    btn_init_0069F650(&btn[4], tex, 0.502f, 0.4757f, 0.435f, 0.05f);
    btn_init_0069F650(&btn[5], tex, 0.502f, 0.53429997f, 0.435f, 0.05f);
    btn_init_0069F650(&btn[6], tex, 0.502f, 0.5929f, 0.435f, 0.05f);
    btn_init_0069F650(&btn[7], tex, 0.502f, 0.6515f, 0.435f, 0.05f);

    lbl_init_0069F650(&lbl[0], tex, 0.338875f, 0.7101f, 0xED32);
    lbl_init_0069F650(&lbl[1], tex, 0.44762498f, 0.7101f, 0xED2E);
    lbl_init_0069F650(&lbl[2], tex, 0.55637497f, 0.7101f, 0xED31);
    lbl_init_0069F650(&lbl[3], tex, 0.66512495f, 0.7101f, 0xED2F);
    lbl_init_0069F650(&lbl[4], tex, 0.338875f, 0.7687f, 0xED4F);
    lbl_init_0069F650(&lbl[5], tex, 0.44762498f, 0.7687f, 0xED2D);
    lbl_init_0069F650(&lbl[6], tex, 0.55637497f, 0.7687f, 0xEA77);
    lbl_init_0069F650(&lbl[7], tex, 0.66512495f, 0.7687f, 0xEA69);

    list_init_0069F650(&list);
    list.unk4C = 0x10;
    list.unk50[0] = &btn[0];
    list.unk50[1] = &btn[1];
    list.unk50[2] = &btn[2];
    list.unk50[5] = &btn[3];
    list.unk50[4] = &btn[4];
    list.unk50[3] = &btn[5];
    list.unk50[6] = &btn[6];
    list.unk50[7] = &btn[7];
    list.unk50[8] = &lbl[0];
    list.unk50[9] = &lbl[1];
    list.unk50[10] = &lbl[2];
    list.unk50[11] = &lbl[3];
    list.unk50[12] = &lbl[4];
    list.unk50[13] = &lbl[5];
    list.unk50[14] = &lbl[6];
    list.unk50[15] = &lbl[7];
    func_L39_00689670(this, &list);
    return this;
}
/* localdecomp:end func_L39_0069F650 */

LINKER_REMNANT("asm/levels", func_L39_0069FD08);
