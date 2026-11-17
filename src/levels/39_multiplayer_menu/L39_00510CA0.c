#include "common.h"

/* localdecomp:start func_L39_00510CA0 */
typedef struct S_00510CA0_Src S_00510CA0_Src;
typedef struct {
    s32 (*fn0)(S_00510CA0_Src *);
    s32 (*read)(S_00510CA0_Src *, u8 *, s32 *, s32);
} S_00510CA0_Vt;
struct S_00510CA0_Src {
    S_00510CA0_Vt *vt;
};
typedef struct {
    s32 unk0;
    u8 *buf;
    s32 eof;
    u32 cap;
    u32 fill;
    s32 unk14;
    S_00510CA0_Src *src;
} S_00510CA0;
extern u8 *func_L39_004F7590(s32);
extern s32 func_L39_004F7538(void *, void *, s32);

s32 func_L39_00510CA0(S_00510CA0 *p, u8 **pos, s32 *len) {
    s32 n;
    s32 r;

    if (p->buf == 0) {
        p->buf = func_L39_004F7590(0x7D00);
        if (p->buf == 0) {
            return 0x803;
        }
        *pos = p->buf + 0x7D00;
        p->cap = p->fill = 0x7D00;
        p->unk14 = 0;
    }
    if (*pos != p->buf) {
        p->fill -= *pos - p->buf;
        func_L39_004F7538(p->buf, *pos, p->fill);
        p->unk14 = 0;
        if (p->eof == 0) {
            r = p->src->vt->read(p->src, p->buf + p->fill, &n, p->cap - p->fill);
            if (r != 0) {
                return r;
            }
            p->fill += n;
            if (p->fill < p->cap) {
                p->eof = 1;
            }
        }
    }
    *pos = p->buf;
    *len = p->fill;
    return 0;
}
/* localdecomp:end func_L39_00510CA0 */

INCLUDE_ASM("asm/levels", func_L39_00510DB8);

INCLUDE_ASM("asm/levels", func_L39_00510EB0);
