#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L02_00351780 */
extern u16 *D_L02_0021B460[];
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE99C, 16");
extern s32 D_L02_001DE9D8;

void func_L02_00351780(u8 *object) {
    u16 *p;
    u8 *entity;
    if (object[0x21] == 0xFF)
        return;
    p = D_L02_0021B460[object[0x21]];
    while (object[0x21] != 0xFF && object[0x21] <= D_L02_001DE9D8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L02_0021B460[object[0x21]])) {
        entity = D_L02_001DE99C + ((*p & 0x7FFF) << 8);
        if (entity == 0)
            break;
        if (*(s16 *)(entity + 0xAA) == *(s16 *)(object + 0xAA))
            *(s32 *)(*(u8 **)(entity + 0x68) + 0x2D8) = 1;
        p++;
    }
}
/* localdecomp:end func_L02_00351780 */

/* localdecomp:start func_L02_00351838 */
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, s32, s32, f32, s32);

void func_L02_00351838(u8 *self) {
    u8 *m = *(u8 **)(self + 0x68);
    u8 *p = *(u8 **)(*(u8 **)(self + 0xB8) + 0x68);
    vu0_v4 v;
    vec_sub_ba(&v, m + 0x30, self + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    func_0038CF68(&v, &v, 1.5f);
    *(vu0_v4 *)(p + 0x720) = v;
    *(f32 *)(p + 0x72C) = 1.0f;
    vec_sub_ba(&v, m + 0x30, self + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    func_0038CF68(&v, &v, -1.5f);
    *(vu0_v4 *)(p + 0x710) = v;
    *(f32 *)(p + 0x71C) = 1.0f;
    func_L01_00408C98(p + 0x710, 0x1E, p + 0x310, p + 0x510, *(s32 *)(p + 0x914), *(s32 *)(p + 0x918),
                      0x2096006B, 0x450030, *(f32 *)(p + 0x910), 5);
}
/* localdecomp:end func_L02_00351838 */

/* localdecomp:start func_L02_00351950 */
typedef int u128_350840 __attribute__((mode(TI)));

typedef struct {
    s32 w[4];
} S_350840_V;

typedef struct {
    u8 pad0[0x310];
    u128_350840 hist[32];
    S_350840_V slots[64];
    s32 w910;
    s32 w914;
    s32 w918;
} S_350840_Vars;

typedef struct {
    u8 pad0[0x68];
    S_350840_Vars *vars;
} S_350840_Pv;

typedef struct {
    u8 pad0[0x10];
    u128_350840 pos;
    u8 pad20[0x98];
    S_350840_Pv *pv;
} S_350840;

extern void func_003C3FC0(S_350840_V *, S_350840_V *);

void func_L02_00351950(S_350840 *self) {
    S_350840_Vars *v = self->pv->vars;
    S_350840_V z;
    v->w910 = 0;
    v->w914 = (v->w914 + 1) % 30;
    if (v->w918 < 30) {
        v->w918++;
    }
    z.w[0] = 0;
    z.w[1] = 0;
    z.w[2] = 0;
    z.w[3] = 0;
    func_003C3FC0(&v->slots[v->w914], &z);
    *(v->hist + v->w914) = self->pos;
}
/* localdecomp:end func_L02_00351950 */
