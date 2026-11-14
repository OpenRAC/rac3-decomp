#include "common.h"

typedef struct Ent_003BAFA0 {
    u8 pad0[0x24];
    f32 f24;
    u8 pad28[8];
    s32 type;
    u8 pad34[0xC];
} Ent_003BAFA0;
typedef struct Set_003BAFA0 {
    Ent_003BAFA0 e[64];
    s32 count;
    s32 id;
} Set_003BAFA0;
typedef struct Obj_003BAFA0 {
    u8 pad0[0x10];
    u8 v10[0x10];
    u8 pad20[0x8A];
    s16 id;
    u8 pad_AC[0x14];
    u8 vC0[0x10];
} Obj_003BAFA0;

INCLUDE_ASM("asm/levels", func_L02_003BA9F8);

INCLUDE_ASM("asm/levels", func_L02_003BAAB0);

/* localdecomp:start func_L02_003BAFA0 */
#include "vu0.h"


extern f32 func_003824E0(f32, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L02_003BB140(void *, void *, f32, void *);
extern void func_L02_003BB1D0(void *, void *, f32, void *);
extern void func_L02_003BB2D8(void *, void *, f32, void *);

void func_L02_003BAFA0(Obj_003BAFA0 *p, f32 dt, Set_003BAFA0 *s, void *out, void *arg) {
    Ent_003BAFA0 *e;
    f32 r;
    s32 i;
    s32 found;

    found = 0;
    if (p != 0 && p->id == s->id && s->count != 0) {
        r = func_003824E0(0.0f, 1.0f);
        for (i = 0; i < s->count && !found; i++) {
            e = &s->e[i];
            if (r <= e->f24) {
                found = 1;
                if (e->type == 1) func_L02_003BB140(e, out, dt, arg);
                if (e->type == 2) func_L02_003BB1D0(e, out, dt, arg);
                if (e->type == 3) func_L02_003BB2D8(e, out, dt, arg);
            } else {
                r -= e->f24;
            }
        }
        if (found) {
            func_0038D000(out, out, p->vC0);
            vec_add_ba(out, out, p->v10);
            return;
        }
    }
    qzero(out);
}
/* localdecomp:end func_L02_003BAFA0 */

INCLUDE_ASM("asm/levels", func_L02_003BB140);

INCLUDE_ASM("asm/levels", func_L02_003BB1D0);

INCLUDE_ASM("asm/levels", func_L02_003BB2D8);
