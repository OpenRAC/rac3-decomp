#include "common.h"

/* localdecomp:start func_L39_005F62A0 */
#include "vu0.h"

typedef struct {
    u8 b0;
    u8 pad1[3];
    u8 b4;
    u8 pad5[3];
    u8 b8;
    u8 pad9[3];
    f32 fC;
    u8 pad10[0xD];
    u8 b1D;
    u8 b1E;
    u8 pad1F;
} E_005F62A0;

typedef struct {
    f32 r0[4];
    f32 r1[4];
    f32 r2[4];
    f32 r3[4];
} M_005F62A0;

extern E_005F62A0 *D_L39_0024C9E4;
__asm__(".extern D_L39_0024C9E4, 16");
extern M_005F62A0 *D_L39_0024C9EC;
__asm__(".extern D_L39_0024C9EC, 16");
extern u8 *D_L39_002BA440[];
extern E_005F62A0 *D_L39_0024CA38[];
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE50(void *, void *, f32);

void func_L39_005F62A0(s32 idx, s32 flag)
{
    E_005F62A0 *e = &D_L39_0024C9E4[idx];
    M_005F62A0 *m = &D_L39_0024C9EC[idx];
    s32 a = 0;
    s32 b = 0;
    s32 c = 0;
    f32 s;
    s32 i;

    if (e->b1E & 2) {
        a = e->b0 & 0x3F;
        b = e->b4 & 0x3F;
        c = e->b8 & 0x3F;
    }
    func_0038D000(e, D_L39_002BA440[e->b1D] + 0x50, m);
    s = func_0038CEA8(m->r0);
    s = fmax_asm(s, func_0038CEA8(m->r1));
    s = fmax_asm(s, func_0038CEA8(m->r2));
    e->fC = *(f32 *)(D_L39_002BA440[e->b1D] + 0x5C) * s;
    func_0038CE50(e, e, m->r3[3]);
    vec_add_ba(e, e, m->r3);
    m->r0[3] = 1.0f / func_0038CEA8(m->r0);
    m->r1[3] = 1.0f / func_0038CEA8(m->r1);
    m->r2[3] = 1.0f / func_0038CEA8(m->r2);
    if (flag) {
        e->b1E |= 1;
    }
    if (*D_00241120 >= 2) {
        for (i = 1; i < *D_00241120; i++) {
            *(vu0_q *)&D_L39_0024CA38[i][idx] = *(vu0_q *)e;
            D_L39_0024CA38[i][idx].b1E = e->b1E;
        }
    }
    if (e->b1E & 2) {
        e->b0 = a | (e->b0 & 0xC0);
        e->b4 = b | (e->b4 & 0xC0);
        e->b8 = c | (e->b8 & 0xC0);
    }
}
/* localdecomp:end func_L39_005F62A0 */

/* localdecomp:start func_L39_005F64F8 */
typedef struct {
    u8 pad0[0x14];
    u16 f14;
    s16 f16;
    u8 pad18[7];
    u8 f1F;
} Node_005F64F8;

extern s32 D_L39_0025F680[];
extern s32 D_L39_002BC740[];
extern Node_005F64F8 *D_L39_0024C9E8;
__asm__(".extern D_L39_0024C9E8, 16");
extern s32 D_L39_0024C9F4;
__asm__(".extern D_L39_0024C9F4, 16");
extern s32 *D_L39_0024CA1C;
__asm__(".extern D_L39_0024CA1C, 16");
extern s32 D_L39_0024CA10;
__asm__(".extern D_L39_0024CA10, 16");
extern s32 D_L39_0024CA14;
__asm__(".extern D_L39_0024CA14, 16");
extern s32 D_L39_0024CA18;
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern Node_005F64F8 *D_L39_0024CA48[];
extern s32 D_L39_0024CA68[];
extern s32 D_L39_0024CA78[];
extern s32 D_L39_0024CA88[];

void func_L39_005F64F8(void)
{
    Node_005F64F8 *p;
    s32 i;

    D_L39_0024C9F4 = D_L39_0025F680[5];
    D_L39_0024CA1C = D_L39_002BC740;
    D_L39_0024CA10 = 0;
    D_L39_0024CA14 = 0;
    D_L39_0024CA18 = 0;
    for (p = (Node_005F64F8 *)D_L39_0024C9E4; p != D_L39_0024C9E8; p++) {
        p->f16 = 0;
        p->f14 = 0xFFFF;
        p->f1F = 0xFF;
    }
    if (*D_00241120 >= 2) {
        for (i = 0; i < *D_00241120; i++) {
            Node_005F64F8 *q;

            D_L39_0024CA68[i] = 0;
            D_L39_0024CA78[i] = 0;
            D_L39_0024CA88[i] = 0;
            for (q = (Node_005F64F8 *)D_L39_0024CA38[i]; q != D_L39_0024CA48[i]; q++) {
                q->f16 = 0;
                q->f14 = 0xFFFF;
                q->f1F = 0xFF;
            }
        }
    }
}
/* localdecomp:end func_L39_005F64F8 */
