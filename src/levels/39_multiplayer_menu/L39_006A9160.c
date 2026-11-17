#include "common.h"

/* localdecomp:start func_L39_006A9160 */
typedef struct {
    s32 type;
    char text[0x34];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
} H_006A9160;

typedef struct {
    H_006A9160 h;
    u8 pad48[8];
} A_006A9160;

typedef struct {
    H_006A9160 h;
    char name[0x50];
} N_006A9160;

typedef struct {
    H_006A9160 h;
    s32 x48;
    s32 x4C;
    void *items[0x60];
} D_006A9160;

extern u8 D_L39_00248978[];
extern u8 D_L39_0047DB98[];
extern void *func_L39_00688388(void *);
extern s32 func_00381FF0(s32);
extern void func_L39_0068CD28(u8 *, void *, f32, f32, f32, f32);
extern void func_00120D28(void *, void *, s32);
extern void func_L39_00689670(void *, void *);

static __inline__ void lab_006A9160(H_006A9160 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    t->type = 0;
    func_L39_0068CD28((u8 *)t, text, x, y, w, h);
}

static __inline__ void A_init_006A9160(A_006A9160 *t, void *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006A9160(&t->h, text, x, y, w, h);
    t->h.type = 1;
}

static __inline__ void N_init_006A9160(N_006A9160 *t, char *text, f32 x, f32 y, f32 w, f32 h) {
    lab_006A9160(&t->h, text, x, y, w, h);
    t->h.type = 7;
    if (text != 0) {
        func_00120D28(t->name, text, 0x4F);
        t->name[0x4F] = 0;
    } else {
        t->name[0] = 0;
    }
}

static __inline__ void D_init_006A9160(D_006A9160 *t) {
    lab_006A9160(&t->h, 0, 1.0f, 1.0f, 1.0f, 1.0f);
    t->x48 = 0x2E;
    t->x4C = 0;
    t->h.x = 0;
    t->h.y = 0;
    t->h.w = 1.0f;
    t->h.h = 1.0f;
}

void *func_L39_006A9160(u8 *self)
{
    A_006A9160 title;
    N_006A9160 header;
    A_006A9160 lines[52];
    D_006A9160 d;

    func_L39_00688388(self);
    *(s32 *)(self + 0x2AC) = 0;
    *(s32 *)(self + 0x2B0) = 0;
    *(s32 *)(self + 0x2B4) = 0;
    *(u8 **)(self + 0x60) = D_L39_0047DB98;
    *(u8 **)(self + 0x2A4) = self + 0x3C0;

    A_init_006A9160(&title, (void *)func_00381FF0(0xFDF), 0.5f, 0.45f, 1.0f, 1.0f);
    N_init_006A9160(&header, (char *)D_L39_00248978, 0.2f, 0.55f, 1.0f, 1.0f);
    A_init_006A9160(&lines[0], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[1], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[2], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[3], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[4], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[5], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[6], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[7], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[8], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[9], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[10], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[11], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[12], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[13], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[14], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[15], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[16], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[17], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[18], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[19], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[20], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[21], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[22], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[23], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[24], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[25], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[26], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[27], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[28], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[29], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[30], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[31], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[32], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[33], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[34], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[35], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[36], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[37], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[38], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[39], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[40], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[41], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[42], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[43], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[44], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[45], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[46], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[47], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[48], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[49], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[50], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    A_init_006A9160(&lines[51], D_L39_00248978, 0.0f, 0.0f, 1.0f, 1.0f);
    D_init_006A9160(&d);
    d.x4C = 0x36;
    d.items[0] = &title;
    d.items[1] = &header;
    d.items[2] = &lines[0];
    d.items[3] = &lines[1];
    d.items[4] = &lines[2];
    d.items[5] = &lines[3];
    d.items[6] = &lines[4];
    d.items[7] = &lines[5];
    d.items[8] = &lines[6];
    d.items[9] = &lines[7];
    d.items[10] = &lines[8];
    d.items[11] = &lines[9];
    d.items[12] = &lines[10];
    d.items[13] = &lines[11];
    d.items[14] = &lines[12];
    d.items[15] = &lines[13];
    d.items[16] = &lines[14];
    d.items[17] = &lines[15];
    d.items[18] = &lines[16];
    d.items[19] = &lines[17];
    d.items[20] = &lines[18];
    d.items[21] = &lines[19];
    d.items[22] = &lines[20];
    d.items[23] = &lines[21];
    d.items[24] = &lines[22];
    d.items[25] = &lines[23];
    d.items[26] = &lines[24];
    d.items[27] = &lines[25];
    d.items[28] = &lines[26];
    d.items[29] = &lines[27];
    d.items[30] = &lines[28];
    d.items[31] = &lines[29];
    d.items[32] = &lines[30];
    d.items[33] = &lines[31];
    d.items[34] = &lines[32];
    d.items[35] = &lines[33];
    d.items[36] = &lines[34];
    d.items[37] = &lines[35];
    d.items[38] = &lines[36];
    d.items[39] = &lines[37];
    d.items[40] = &lines[38];
    d.items[41] = &lines[39];
    d.items[42] = &lines[40];
    d.items[43] = &lines[41];
    d.items[44] = &lines[42];
    d.items[45] = &lines[43];
    d.items[46] = &lines[44];
    d.items[50] = &lines[45];
    d.items[49] = &lines[46];
    d.items[48] = &lines[47];
    d.items[47] = &lines[48];
    d.items[51] = &lines[49];
    d.items[52] = &lines[50];
    d.items[53] = &lines[51];

    *(s32 *)(self + 0x394) = 0xC8;
    *(s32 *)(self + 0x39C) = -1;
    *(s32 *)(self + 0x3A0) = -1;
    *(s32 *)(self + 0x3A4) = -1;
    *(s32 *)(self + 0x3A8) = -1;
    *(s32 *)(self + 0x3AC) = -1;
    *(s32 *)(self + 0x390) = 0;
    *(s32 *)(self + 0x3B4) = -1;
    *(s32 *)(self + 0x3B0) = -1;
    *(s32 *)(self + 0x3B8) = -1;
    func_L39_00689670(self, &d);
    return self;
}
/* localdecomp:end func_L39_006A9160 */
