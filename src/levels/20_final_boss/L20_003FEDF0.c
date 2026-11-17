#include "common.h"
#include "vu0.h"

/* types of func_L20_003FEDF0, from upstream's L20_003FB630.c */
typedef int u128_t __attribute__((mode(TI)));
typedef union Mo_ { u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Pv_ *pv[0x40]; union Mo_ *mp[0x40]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x400]; s8 c[0x400]; s16 h[0x200]; u16 uh[0x200]; s32 i[0x100]; u32 u[0x100]; f32 f[0x100]; void *p[0x100]; Mo *mp[0x100]; u128_t q[0x40]; } Pv;

typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;

/* declared by functions of L20_003FB630.c, which this file was cut from */
extern void func_L20_003FEDF0(Mo *m);

/* declarations func_L20_003FEDF0's C had before it in L20_003FB630.c */
extern Mo *D_L20_001E029C;
extern s32 D_L20_001E02D8;
extern s16 *D_L20_0021CFE0[];
/* localdecomp:start func_L20_003FEDF0 */
void func_L20_003FEDF0(Mo *m) {
    u16 *q;

    if (m->b[0x21] == 0xFF) {
        return;
    }
    q = (u16 *)D_L20_0021CFE0[m->b[0x21]];
    while (m->b[0x21] != 0xFF && m->b[0x21] <= D_L20_001E02D8 && q != 0 &&
           ((s16)q[-1] >= 0 || q == (u16 *)D_L20_0021CFE0[m->b[0x21]])) {
        Mo *e = &D_L20_001E029C[*q & 0x7FFF];
        if (e == 0) {
            break;
        }
        q++;
        if (e->h[0xAA / 2] == m->h[0xAA / 2]) {
            e->pv[0x68 / 4]->uh[0x3D8 / 2] = 1;
        }
    }
}
/* localdecomp:end func_L20_003FEDF0 */
