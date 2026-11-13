#include "common.h"

/* localdecomp:start func_L39_0059EEB8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q;
} V_0059EEB8;
typedef struct {
    s16 h0;
    s16 h2;
    s16 h4;
    s16 h6;
    s16 h8;
    s16 hA;
    s16 *buf;
    s32 used;
    char pad14[0x30 - 0x14];
} Slot_0059EEB8;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    V_0059EEB8 v10;
} Info_0059EEB8;
typedef struct {
    u8 pad0[0x1A];
    u16 h1A;
    u8 pad1C[4];
} Ent_0059EEB8;

extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern Slot_0059EEB8 D_L39_002668C0[];
extern Info_0059EEB8 D_L39_002667C0[];
extern Ent_0059EEB8 *D_L39_0024CA38[];
extern Ent_0059EEB8 *D_L39_0024C9E4;
__asm__(".extern D_L39_0024C9E4, 16");
extern s16 *func_003DE880(s16 *, s16 *, s32, void *);
extern s16 *func_003E10C0(s16 *, s16 *, s32, void *);
extern s16 *func_003D0880(s16 *, s16 *, s32, void *);

void func_L39_0059EEB8(s32 idx)
{
    Slot_0059EEB8 *s = &D_L39_002668C0[idx];
    Info_0059EEB8 *in = &D_L39_002667C0[idx];
    V_0059EEB8 v[1];
    V_0059EEB8 *pv;
    s16 *r;
    s16 *end;
    s32 i;
    s32 j;

    pv = &in->v10;
    v[0] = *pv;
    r = s->buf;
    end = r + 0x200;
    if (r < end) {
        s->h0 = 0;
        r = func_003DE880(r, end, idx, &in->v10);
        s->h2 = (r - s->buf);
        if (*D_00241120 >= 2) {
            for (i = 1; i < *D_00241120; i++) {
                Ent_0059EEB8 *dst = D_L39_0024CA38[i];
                s16 *p = s->buf + s->h0;
                for (j = 0; j < s->h2; j++) {
                    s16 k = *p++;
                    dst[k].h1A = D_L39_0024C9E4[k].h1A;
                }
            }
        }
        if (r < end) {
            s->h4 = (r - s->buf);
            r = func_003E10C0(r, end, idx, &in->v10);
            s->h6 = (r - s->buf) - s->h4;
            if (r < end) {
                s->h8 = (r - s->buf);
                r = func_003D0880(r, end, idx, &in->v10);
                s->hA = (r - s->buf) - s->h8;
            }
        }
    }
}
/* localdecomp:end func_L39_0059EEB8 */
