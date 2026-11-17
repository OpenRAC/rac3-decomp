#include "common.h"

/* declared by functions of L39_006AC860.c, which this file was cut from */
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L39_006ACEA8 */
typedef struct S_006ACEA8_Base {
    s32 type;
    char text[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} S_006ACEA8_Base;
typedef struct S_006ACEA8_Label {
    S_006ACEA8_Base b;
    s32 f48;
    s32 f4C;
} S_006ACEA8_Label;
typedef struct S_006ACEA8_Slider {
    S_006ACEA8_Base b;
    u8 f48;
    s32 f4C;
} S_006ACEA8_Slider;
typedef struct S_006ACEA8_Check {
    S_006ACEA8_Base b;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    s32 f58;
    s32 f5C;
} S_006ACEA8_Check;
typedef struct S_006ACEA8_List {
    S_006ACEA8_Base b;
    s32 f48;
    s32 count;
    void *items[0x60];
} S_006ACEA8_List;
typedef struct S_006ACEA8_This {
    u8 pad[0x60];
    u8 *vtbl;
    u8 pad64[0x2A4 - 0x64];
    u8 *f2A4;
    u8 pad2A8[0x3C4 - 0x2A8];
    u8 f3C4[1];
} S_006ACEA8_This;
extern void *func_L39_00688388(void *);
extern void func_L39_0068CD28(u8 *, s32, f32, f32, f32, f32);
extern void func_L39_00689670(void *, void *);
extern s32 func_00381FF0(s32);
extern u8 D_L39_0047DDA0[];
extern char D_00248B90[];
extern f32 D_00248B64;
extern f32 D_00248B68;
extern f32 D_00248B74;
extern f32 D_00248B78;
extern f32 D_001DD3F4_sda;
extern f32 D_001DD3F8_sda;
extern f32 D_001DD3FC_sda;
extern f32 D_001DD400_sda;
extern f32 D_001DD404_sda;
extern f32 D_001DD408_sda;
extern f32 D_001DD410_sda;
extern f32 D_001DD414_sda;
extern f32 D_001DD418_sda;
extern f32 D_001DD41C_sda;
extern f32 D_001DD420_sda;
extern f32 D_001DD424_sda;
extern f32 D_001DD428_sda;
extern f32 D_001DD42C_sda;
extern f32 D_001DD430_sda;
extern f32 D_001DD438_sda;
extern f32 D_001DD440_sda;
extern f32 D_001DD444_sda;
extern f32 D_001DD450_sda;
extern f32 D_001DD460_sda;
extern f32 D_001DD46C_sda;
extern f32 D_001DD470_sda;

__asm__(".extern D_001DD3F4_sda, 4");
__asm__(".extern D_001DD3F8_sda, 4");
__asm__(".extern D_001DD3FC_sda, 4");
__asm__(".extern D_001DD400_sda, 4");
__asm__(".extern D_001DD404_sda, 4");
__asm__(".extern D_001DD408_sda, 4");
__asm__(".extern D_001DD410_sda, 4");
__asm__(".extern D_001DD414_sda, 4");
__asm__(".extern D_001DD418_sda, 4");
__asm__(".extern D_001DD41C_sda, 4");
__asm__(".extern D_001DD420_sda, 4");
__asm__(".extern D_001DD424_sda, 4");
__asm__(".extern D_001DD428_sda, 4");
__asm__(".extern D_001DD42C_sda, 4");
__asm__(".extern D_001DD430_sda, 4");
__asm__(".extern D_001DD438_sda, 4");
__asm__(".extern D_001DD440_sda, 4");
__asm__(".extern D_001DD444_sda, 4");
__asm__(".extern D_001DD450_sda, 4");
__asm__(".extern D_001DD460_sda, 4");
__asm__(".extern D_001DD46C_sda, 4");
__asm__(".extern D_001DD470_sda, 4");



static __inline__ void lab_006ACEA8(S_006ACEA8_Label *l, s32 text, f32 x, f32 y, f32 w, f32 h) {
    l->b.type = 0;
    func_L39_0068CD28((u8 *)l, text, x, y, w, h);
    l->b.type = 1;
}
static __inline__ void chk_006ACEA8(S_006ACEA8_Check *c, f32 x, f32 y, f32 w, f32 h) {
    c->b.type = 0;
    func_L39_0068CD28((u8 *)c, (s32)D_00248B90, x, y, w, h);
    c->b.type = 0xC;
    c->f58 = 0xED3D;
    c->f48 = 0.0f;
    c->f50 = 0.0f;
    c->f4C = 1.0f;
    c->f54 = 1.0f;
    c->f5C = 0x706EC8FF;
}
static __inline__ void sld_006ACEA8(S_006ACEA8_Slider *s, s32 text, f32 x, f32 y, f32 w, f32 h, s32 max) {
    s->b.type = 0;
    func_L39_0068CD28((u8 *)s, text, x, y, w, h);
    s->b.type = 4;
    s->f4C = max;
    s->f48 = 0;
}
static __inline__ void list_006ACEA8(S_006ACEA8_List *l) {
    l->b.type = 0;
    func_L39_0068CD28((u8 *)l, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    l->f48 = 0x2E;
    l->b.x = 0.0f;
    l->count = 0;
    l->b.y = 0.0f;
    l->b.w = 1.0f;
    l->b.h = 1.0f;
}

void *func_L39_006ACEA8(S_006ACEA8_This *const this) {
    S_006ACEA8_Label w0;
    S_006ACEA8_Label w1;
    S_006ACEA8_Label w2;
    S_006ACEA8_Label w3;
    S_006ACEA8_Slider w4;
    S_006ACEA8_Label w5;
    S_006ACEA8_Label w6;
    S_006ACEA8_Label w7;
    S_006ACEA8_Label w8;
    S_006ACEA8_Check w9;
    S_006ACEA8_Label w10;
    S_006ACEA8_Check w11;
    S_006ACEA8_Label w12;
    S_006ACEA8_Check w13;
    S_006ACEA8_Label w14;
    S_006ACEA8_Check w15;
    S_006ACEA8_Label w16;
    S_006ACEA8_Check w17;
    S_006ACEA8_Label w18;
    S_006ACEA8_Check w19;
    S_006ACEA8_Label w20;
    S_006ACEA8_Check w21;
    S_006ACEA8_Label w22;
    S_006ACEA8_Check w23;
    S_006ACEA8_List list;

    func_L39_00688388(this);
    this->vtbl = D_L39_0047DDA0;
    this->f2A4 = this->f3C4;
    lab_006ACEA8(&w0, (s32)D_00248B90, D_001DD3F4_sda, D_001DD3F8_sda, D_001DD3FC_sda, D_001DD400_sda);
    lab_006ACEA8(&w1, (s32)D_00248B90, D_001DD404_sda, D_001DD408_sda + (D_001DD410_sda - D_001DD444_sda) * -0.5f * 0.5f, D_001DD41C_sda - D_001DD444_sda, D_001DD41C_sda - D_001DD444_sda);
    lab_006ACEA8(&w2, (s32)D_00248B90, D_001DD404_sda, D_001DD408_sda + (D_001DD410_sda - D_001DD444_sda) * 0.5f * 0.5f, D_001DD41C_sda - D_001DD444_sda, D_001DD41C_sda - D_001DD444_sda);
    lab_006ACEA8(&w3, func_00381FF0(0xFF9), D_001DD414_sda, D_001DD418_sda + (D_001DD420_sda - D_001DD444_sda) * 0.0f * 0.5f, D_001DD41C_sda - D_001DD444_sda, 0.05f);
    sld_006ACEA8(&w4, (s32)D_00248B90, D_001DD424_sda, D_001DD428_sda, D_001DD42C_sda - D_001DD444_sda, D_001DD430_sda - D_001DD444_sda, 0x25);
    lab_006ACEA8(&w5, func_00381FF0(0x1332), D_001DD450_sda, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * -2.0f / 5.0f, D_001DD460_sda, 0.05f);
    lab_006ACEA8(&w6, func_00381FF0(0x1631), D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * -2.0f / 5.0f, D_00248B74, 0.05f);
    lab_006ACEA8(&w7, func_00381FF0(0x1632), D_00248B68, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * -2.0f / 5.0f, D_00248B78, 0.05f);
    lab_006ACEA8(&w8, (s32)D_00248B90, D_001DD450_sda, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * -1.0f / 5.0f, D_001DD460_sda, 0.05f);
    chk_006ACEA8(&w9, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * -1.0f / 5.0f, D_001DD46C_sda * 0.7f, D_001DD470_sda * 0.7f);
    lab_006ACEA8(&w10, (s32)D_00248B90, D_00248B68, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * -1.0f / 5.0f, D_00248B78, 0.05f);
    chk_006ACEA8(&w11, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * -1.0f / 5.0f, D_001DD46C_sda, D_001DD470_sda);
    lab_006ACEA8(&w12, (s32)D_00248B90, D_001DD450_sda, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 0.0f / 5.0f, D_001DD460_sda, 0.05f);
    chk_006ACEA8(&w13, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 0.0f / 5.0f, D_001DD46C_sda * 0.7f, D_001DD470_sda * 0.7f);
    lab_006ACEA8(&w14, (s32)D_00248B90, D_00248B68, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 0.0f / 5.0f, D_00248B78, 0.05f);
    chk_006ACEA8(&w15, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 0.0f / 5.0f, D_001DD46C_sda, D_001DD470_sda);
    lab_006ACEA8(&w16, (s32)D_00248B90, D_001DD450_sda, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 1.0f / 5.0f, D_001DD460_sda, 0.05f);
    chk_006ACEA8(&w17, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 1.0f / 5.0f, D_001DD46C_sda * 0.7f, D_001DD470_sda * 0.7f);
    lab_006ACEA8(&w18, (s32)D_00248B90, D_00248B68, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 1.0f / 5.0f, D_00248B78, 0.05f);
    chk_006ACEA8(&w19, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 1.0f / 5.0f, D_001DD46C_sda, D_001DD470_sda);
    lab_006ACEA8(&w20, (s32)D_00248B90, D_001DD450_sda, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 2.0f / 5.0f, D_001DD460_sda, 0.05f);
    chk_006ACEA8(&w21, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 2.0f / 5.0f, D_001DD46C_sda * 0.7f, D_001DD470_sda * 0.7f);
    lab_006ACEA8(&w22, (s32)D_00248B90, D_00248B68, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 2.0f / 5.0f, D_00248B78, 0.05f);
    chk_006ACEA8(&w23, D_00248B64, D_001DD438_sda + (D_001DD440_sda - D_001DD444_sda) * 2.0f / 5.0f, D_001DD46C_sda, D_001DD470_sda);
    list_006ACEA8(&list);
    list.count = 24;
    list.items[0] = &w0;
    list.items[1] = &w1;
    list.items[2] = &w2;
    list.items[3] = &w3;
    list.items[4] = &w4;
    list.items[5] = &w5;
    list.items[6] = &w6;
    list.items[7] = &w7;
    list.items[8] = &w8;
    list.items[16] = &w9;
    list.items[20] = &w10;
    list.items[12] = &w11;
    list.items[9] = &w12;
    list.items[17] = &w13;
    list.items[21] = &w14;
    list.items[13] = &w15;
    list.items[10] = &w16;
    list.items[18] = &w17;
    list.items[22] = &w18;
    list.items[14] = &w19;
    list.items[11] = &w20;
    list.items[19] = &w21;
    list.items[23] = &w22;
    list.items[15] = &w23;
    func_L39_00689670(this, &list);
    return this;
}
/* localdecomp:end func_L39_006ACEA8 */

LINKER_REMNANT("asm/levels", func_L39_006AD970);
