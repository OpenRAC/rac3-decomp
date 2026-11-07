#include "common.h"

/* localdecomp:start func_L02_0032EF80 */
typedef struct S_B_32EF80 {
    s32 f0;
    s32 f4;
    u8 pad8[2];
    u8 fA;
    u8 pad_b[4];
    u8 fF;
} S_B_32EF80;
typedef struct S_O_32EF80 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0x32];
    S_B_32EF80 *f68;
    u8 pad6C[0x3E];
    s16 fAA;
} S_O_32EF80;
typedef struct S_P_32EF80 {
    u8 pad0[0x21];
    u8 f21;
    u8 pad22[0x46];
    S_B_32EF80 *f68;
} S_P_32EF80;

extern u8 D_001A4C60[];
extern s32 func_L01_00456500(void *a, s32 b);
extern s32 func_L01_00424B88(f32 c, f32 d, void *a, s32 b);
extern void func_L01_00424D88(void);
extern void func_L02_0032F1C8(void *p);
extern s16 *D_0021B460[];
extern u8 *D_001DE99C;
__asm__(".extern D_001DE99C, 16");
extern u32 D_001D66B0;
__asm__(".extern D_001D66B0, 16");
extern s32 D_001DE9D8_sda;
__asm__(".extern D_001DE9D8_sda, 4");

void func_L02_0032EF80(S_P_32EF80 *p) {
    S_B_32EF80 *s;
    func_L02_0032F1C8(p);
    s = p->f68;
    if (s->f0 != -1 && func_L01_00456500(D_001A4C60, s->f0) != 0) {
        s16 *q;
        S_O_32EF80 *o;
        q = D_0021B460[p->f21];
        while (p->f21 != 0xFF && p->f21 <= D_001DE9D8_sda && q != 0 && (q[-1] >= 0 || q == D_0021B460[p->f21])) {
            o = (S_O_32EF80 *)(D_001DE99C + ((*q & 0x7FFF) << 8));
            if (o == 0) break;
            if ((S_P_32EF80 *)o != p) {
                o->f34 &= ~2;
                if (o->fAA == 0x18BD) o->f68->fF = 1;
                if (o->fAA == 0x18C2) o->f68->fA = 1;
            }
            q++;
        }
        if (s->f4 == -1) s->f4 = func_L01_00424B88(10.0f, 0.0f, &D_001D66B0, 0x7F608060);
    } else {
        s16 *q;
        S_O_32EF80 *o;
        q = D_0021B460[p->f21];
        while (p->f21 != 0xFF && p->f21 <= D_001DE9D8_sda && q != 0 && (q[-1] >= 0 || q == D_0021B460[p->f21])) {
            o = (S_O_32EF80 *)(D_001DE99C + ((*q & 0x7FFF) << 8));
            if (o == 0) break;
            if ((S_P_32EF80 *)o != p) {
                if (o->f20 != 1) {
                    if (o->fAA == 0x18BD) o->f68->fF = 0;
                    if (o->fAA == 0x18C2) o->f68->fA = 0;
                } else {
                    o->f34 |= 2;
                }
            }
            q++;
        }
        o = (S_O_32EF80 *)s->f4;
        if ((s32)o != -1) { func_L01_00424D88(); s->f4 = -1; }
    }
}
/* localdecomp:end func_L02_0032EF80 */

/* localdecomp:start func_L02_0032F1C8 */
typedef struct {
    s32 f0;
    s32 f4;
} S_B_0032F1C8;

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x0F];
    u8 f30;
    u8 pad31[0x37];
    S_B_0032F1C8 *f68;
} S_A_0032F1C8;

void func_L02_0032F1C8(void *arg0) {
    S_A_0032F1C8 *p = arg0;
    if (p->f20 == 0) {
        p->f68->f4 = -1;
        p->f30 = 0xFF;
        p->f20 = 1;
    }
}
/* localdecomp:end func_L02_0032F1C8 */
