#include "common.h"

/* declared by functions of L04_003D0968.c, which this file was cut from */
typedef void (*Fn_003CF2A0)(u8 *);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);

/* localdecomp:start func_L04_003D3018 */
typedef void (*Fn_003D3018)(u8 *);

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x44 - 0x36];
    u8 b44;
    u8 pad45[0x70 - 0x45];
    s32 w70;
    u8 pad74[0x7E - 0x74];
    u8 b7E;
    u8 pad7F;
    u8 b80;
    u8 pad81[0x84 - 0x81];
    s32 w84;
    s32 w88;
    f32 f8C;
    s32 w90;
    s32 w94;
    s32 w98;
    f32 f9C;
    s32 wA0;
    s32 wA4;
    s32 wA8;
    u8 padAC[0xB8 - 0xAC];
    f32 fB8;
    u8 padBC[0xC8 - 0xBC];
    s32 wC8;
    u8 padCC[0xD0 - 0xCC];
    s32 wD0;
    s32 wD4;
} P_003D3018;

extern u8 *D_001A30F4 __attribute__((section(".data")));
extern s32 D_001D545C_003D3018;
__asm__(".extern D_001D545C_003D3018, 16");
extern u8 D_0014275B[];
extern f32 D_L04_001DA8B8;
__asm__(".extern D_L04_001DA8B8, 4");
extern f32 D_L04_001DA8B0;
__asm__(".extern D_L04_001DA8B0, 4");
extern f32 D_L04_002F1F70[];
extern f32 D_L04_002F1D90[];
extern f32 func_00382538(void);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);

void func_L04_003D3018(u8 *self, P_003D3018 *p) {
    s32 v;

    self[0xBC] = 0;
    p->fB8 = *(f32 *)(self + 0x18);
    p->wC8 = -1;
    p->f8C = 1.0f;
    p->wA0 = 0;
    p->w94 = 0;
    p->w98 = 0;
    p->wA4 = 0;
    p->wA8 = 0;
    p->w88 = 0;
    p->wD4 = 0;
    D_001A30F4 = self;
    p->f9C = func_00382538();
    if (p->h34 == 0) {
        p->h34 = 50;
        if (func_L01_0041A4F0() != 0) {
            p->h34 = p->h34 * ((D_001D545C_003D3018 == 7 && D_0014275B[0] != 0) ? D_L04_001DA8B8 : D_L04_002F1F70[D_001D545C_003D3018]);
        }
    }
    p->f30 = p->h34;
    if (p->b44 == 0) {
        p->b44 = 9;
        if (func_L01_0041A4F0() != 0) {
            v = p->b44 * ((D_001D545C_003D3018 == 7 && D_0014275B[0] != 0) ? D_L04_001DA8B0 : D_L04_002F1D90[D_001D545C_003D3018]);
            if (v > 255) {
                v = 255;
            }
            p->b44 = v;
        }
    }
    p->w84 = 0;
    p->w90 = 0;
    func_L01_004450F0(self, 1, -1);
    func_L01_00456230(self, 0);
    if (p->w70 > 0) {
        Fn_003CF2A0 *fn = func_L01_0043B548(6625, 108);
        p->w70 = -1;
        p->b7E = 4;
        (*fn)(self);
    } else if (p->b80 != 0) {
        func_L01_004450F0(self, 5, -1);
    } else if (p->wD0 != -1) {
        func_L01_004450F0(self, 3, -1);
    }
}
/* localdecomp:end func_L04_003D3018 */
