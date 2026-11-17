#include "common.h"

/* localdecomp:start func_L06_0032E168 */
typedef struct {
    u8 p0[0x260];
    void *f260;
} S_0032E168_O;

typedef struct {
    u8 p0[0x20];
    u8 b20;
    u8 p21[0x47];
    S_0032E168_O *f68;
    u8 p6C[0x3E];
    s16 hAA;
    u8 pAC[4];
    u8 bB0;
} S_0032E168_E;

typedef struct {
    u8 p0[0x10];
    s32 f10;
    u8 p14[0x54];
    S_0032E168_O *f68;
} S_0032E168_A;

extern S_0032E168_E *D_L06_001DED9C;
extern S_0032E168_E *D_L06_001DEDA0;
__asm__(".extern D_L06_001DED9C, 16");
extern void func_003C2880(void *);

void func_L06_0032E168(S_0032E168_A *a0) {
    S_0032E168_E *e = D_L06_001DED9C;
    S_0032E168_A *o = (S_0032E168_A *)a0->f68;
    if (e < D_L06_001DEDA0) {
        do {
            if (e->bB0 == o->f10 && e != 0 && e->b20 != 0xFE && e->b20 != 0xFD) {
                switch (e->hAA) {
                case 0x1699: {
                    S_0032E168_O *x = e->f68;
                    func_003C2880(x->f260);
                    x->f260 = 0;
                }
                    /* fall through */
                case 0x1619:
                case 0x1BDC:
                    func_003C2880(e);
                }
            }
            e = (S_0032E168_E *)((u8 *)e + 0x100);
        } while (e < D_L06_001DEDA0);
    }
}
/* localdecomp:end func_L06_0032E168 */

/* localdecomp:start func_L06_0032E280 */
void func_L01_00459C50(s32);
extern s16 D_001426A0[];

void func_L06_0032E280(void) {
    if (D_001426A0[0] == 4) {
        func_L01_00459C50(4);
    }
}
/* localdecomp:end func_L06_0032E280 */

/* localdecomp:start func_L06_0032E2B0 */
typedef struct {
    s32 v[3];
    s16 state;
    u8 bits;
    u8 index;
} Sub_0032E2B0;

typedef struct {
    u8 pad[0x68];
    Sub_0032E2B0 *sub;
} Obj_0032E2B0;

typedef struct {
    u8 pad00[0x24];
    s32 f24;
    u8 pad28[0x44];
    s32 f6C;
    u8 pad70[6];
    s16 f76;
    u8 pad78[0x1C];
    s32 f94;
    s16 f98;
    s16 f9A;
    s16 f9C;
    s16 f9E;
} Glob_0032E2B0;

extern u8 D_001426F4[];
extern f32 D_001A4C64[];
extern Glob_0032E2B0 D_001CCFD0;
__asm__(".extern D_001426F4, 16");
__asm__(".extern D_001A4C64, 16");

extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);

void func_L06_0032E2B0(Obj_0032E2B0 *a) {
    Sub_0032E2B0 *s = a->sub;
    s32 bit;

    if (!D_001426F4[0]) {
        if (D_001A4C64[0] > 280.0f) {
            s->index = 2;
        } else if (D_001A4C64[0] > 215.0f) {
            s->index = 1;
        } else if (D_001A4C64[0] > 150.0f) {
            s->index = 0;
        }

        switch (s->state) {
        case 0:
            if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0 &&
                s->index != 255 && ((1 ^ (s->bits >> s->index)) & 1)) {
                func_003A2B68((s->v[s->index] & 0x3FFF) + 2000, 0);
                bit = 1 << s->index;
                s->index = 255;
                s->state = 1;
                s->bits |= bit;
            }
            break;
        case 1:
            if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 7000) {
                func_003A1798();
                s->state = 0;
            }
            break;
        }
    }
}
/* localdecomp:end func_L06_0032E2B0 */
