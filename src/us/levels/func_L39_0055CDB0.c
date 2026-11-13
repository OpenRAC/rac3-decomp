#include "common.h"

/* NTSC-U counterpart of func_L39_0055D828 (src/levels/shared/L39_0055D7F8.c): 50 -> 60 */
/* localdecomp:start func_L39_0055CDB0 */
typedef struct E_0055D828 {
    u8 pad0[0x34];
    u16 h34;
    u8 pad36[0x98 - 0x36];
    s32 w98;
} E_0055D828;

typedef struct P_0055D828 {
    u8 pad0[0x10];
    s32 w10;
    u8 pad14[0x44 - 0x14];
    u16 h44;
} P_0055D828;

typedef struct R_0055D828 {
    s32 w0;
    s32 w4;
    s32 w8;
} R_0055D828;

typedef struct Q_0055D828 {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    u8 pad36[0x200 - 0x36];
    u32 w200;
    s32 w204;
    s32 w208;
    u8 pad20C[0x220 - 0x20C];
    s32 w220;
    s32 w224;
    u8 pad228[0x24C - 0x228];
    s32 w24C;
    u8 pad250[0x258 - 0x250];
    E_0055D828 *p258;
} Q_0055D828;

typedef struct S_0055D828 {
    u8 pad0[0x24];
    P_0055D828 *p24;
    u8 pad28[0x34 - 0x28];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    Q_0055D828 *p68;
    u8 pad6C[0x98 - 0x6C];
    s32 w98;
    u8 pad9C[0xA8 - 0x9C];
    u8 bA8;
} S_0055D828;

extern s32 D_001A5F78[];
__asm__(".extern D_L39_002412AC, 16");
extern s32 D_L39_002412AC;
__asm__(".extern D_L39_0024C05C, 16");
extern u8 *D_L39_0024C05C;
extern void func_L39_005F08F8(void *, s32);
extern s32 func_L39_0055CD90(u8 *);
extern s32 func_L39_0055CDA0(u8 *);

void func_L39_0055CDB0(S_0055D828 *s) {
    P_0055D828 *p = s->p24;
    Q_0055D828 *q = s->p68;
    s32 t;
    R_0055D828 *r = (R_0055D828 *)((u8 *)q + 0x200);

    s->h34 &= 0xFFBE;
    s->h34 |= p->h44 & 0x1000;
    s->w98 = p->w10;
    q->p258->h34 |= 0x41;
    q->p258->h34 &= 0xEFFF;
    q->p258->w98 = 0;
    func_L39_005F08F8(q->p258, 1);
    s->bA8 = 0xFF;
    r->w4 = 0;
    t = D_L39_002412AC + 0x3C;
    r->w8 = D_001A5F78[0];
    q->w200 = 0xFFFFFFFF;
    q->w224 = t;
    q->w220 = 0;
    q->f30 = q->h34;
    if (q->w24C >= 0) {
        if (func_L39_0055CD90(D_L39_0024C05C + (q->w24C << 8)) == 0) {
            func_L39_0055CDA0(D_L39_0024C05C + (q->w24C << 8));
        }
    }
}
/* localdecomp:end func_L39_0055CDB0 */
