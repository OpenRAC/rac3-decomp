#include "common.h"

/* declared by functions of L16_003C9768.c, which this file was cut from */
extern void func_L16_003CBBF0(u8 *a0);

/* localdecomp:start func_L16_003CBA28 */
extern s32 D_001DE96C;
extern s8 D_001DE970;
extern f32 D_001DE918;
extern f32 D_001DE910;
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_0044E7D8(void *);
extern void func_L01_004450F0(void *, s32, s32);

typedef struct {
    u8 pad0[0x40];
    f32 f40;
    s16 h44;
    u8 pad46[2];
    u8 b48;
    u8 b49;
    u8 pad4A[4];
    u8 b4E;
    u8 b4F;
    f32 f50;
    u8 pad54[0x14];
    u8 b68;
    u8 pad69;
    u8 b6A;
    u8 pad6B[3];
    u8 b6E;
    u8 b6F;
    u8 pad70[3];
    u8 b73;
    u8 b74;
    u8 pad75[0xB];
    f32 f80;
    f32 f84;
    u8 pad88[0x108];
    s32 w190;
    u8 pad194[0x14];
    s32 w1A8;
    s32 w1AC;
    s32 w1B0;
    s32 w1B4;
    s32 w1B8;
    s32 w1BC;
    s32 w1C0;
    s32 w1C4;
    s32 w1C8;
    s32 w1CC;
    s32 w1D0;
    s32 w1D4;
    s32 w1D8;
    u8 pad1DC[4];
    s32 w1E0;
    s32 w1E4;
    s32 w1E8;
    u8 pad1EC[0x1C];
    s32 w208;
    s32 w20C;
    s16 h210;
    s16 h212;
    s16 h214;
    s16 h216;
    s16 h218;
    s16 h21A;
    u8 pad21C[8];
    s32 w224;
} S_003CBA28;

void func_L16_003CBA28(u8 *a0)
{
    S_003CBA28 *q = *(S_003CBA28 **)(a0 + 0x68);
    s32 n;

    q->b68 = 0x14;
    q->b6A = 0x28;
    if (q->h44 == 0) {
        q->h44 = 1000;
    }
    n = D_001DE96C;
    D_001DE970 = 0;
    if (n >= 7) {
        q->h44 = q->h44 / 2;
    } else if (n == 6) {
        q->h44 = q->h44 * 65 / 100;
    } else if (n == 5) {
        q->h44 = q->h44 * 80 / 100;
    } else if (n == 4) {
        q->h44 = q->h44 * 90 / 100;
    }
    q->f40 = q->h44;
    q->b4E = q->b48 = 3;
    q->b49 = 0;
    q->b6E = 0;
    q->b6F = 0;
    q->b4F = 0;
    q->b73 = 0;
    q->b74 = 0;
    q->f50 = 3.0f;
    q->f84 = q->f80 = D_001DE918;
    q->w1B4 = -1;
    q->h218 = -1;
    q->h21A = -1;
    q->h212 = -1;
    q->h210 = -1;
    q->h214 = -1;
    q->h216 = -1;
    q->w1BC = 0;
    q->w190 = 0;
    q->w1B8 = 0;
    q->w1D4 = 0;
    q->w1D8 = 0;
    q->w1AC = 0;
    q->w1A8 = 0;
    q->w1E0 = 0;
    q->w1E4 = 0;
    q->w1E8 = 0;
    q->w1B0 = 0;
    q->w224 = 0;
    q->w1D0 = 0;
    q->w208 = -1;
    q->w1C0 = 0;
    q->w1C4 = 0;
    q->w1C8 = 0;
    q->w1CC = 0;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(a0 + 0x2C) * D_001DE910;
    func_L01_00456230(a0, 0);
    q->w20C = func_L01_0044E7D8(a0);
    func_L01_004450F0(a0, 2, 0);
}
/* localdecomp:end func_L16_003CBA28 */

/* localdecomp:start func_L16_003CBBF0 */
extern s32 func_0038CAD0(void *);
extern void func_L01_0044E850(void *, void *, f32, f32, s32);
extern f32 D_001DE964;
__asm__(".extern D_001DE964, 4");
extern f32 D_001DE968;
__asm__(".extern D_001DE968, 4");

void func_L16_003CBBF0(u8 *a0)
{
    u8 *p = a0;
    u8 *q = *(u8 **)(p + 0x68);

    if (*(u16 *)(p + 0x96) <= 0xFFFE) {
        *(u16 *)(p + 0x96) = *(u16 *)(p + 0x96) + 1;
    }
    func_0038CAD0(q + 0x1D4);
    func_0038CAD0(q + 0x1D8);
    *(u32 *)(q + 0x1AC) += 1;
    func_0038CAD0(q + 0x1E4);
    func_L01_0044E850(p, q + 0x270, D_001DE964, D_001DE968, 6);
    func_L01_0044E850(p, q + 0x2F0, D_001DE964, D_001DE968, 7);
}
/* localdecomp:end func_L16_003CBBF0 */
