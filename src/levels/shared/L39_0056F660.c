#include "common.h"

/* localdecomp:start func_L39_0056F660 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x40];
    vu0_v4 pos;
    u8 pad50[0xF0 - 0x50];
    u8 *obj;
} St_0056F660;

typedef struct {
    u8 pad0[0x54];
    u8 *p54;
    u8 pad58[0x150 - 0x58];
    St_0056F660 st;
    u8 pad250[0x460 - 0x250];
} Ent_0056F660;

extern Ent_0056F660 D_L39_0024DE80[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

void func_L39_0056F660(u8 *a0) {
    vu0_v4 dir;
    vu0_v4 v10;
    u8 *q;
    St_0056F660 *st = &D_L39_0024DE80[*(s32 *)(a0 + 0x94)].st;

    func_0038CF68(&dir, st->obj + 0xE0, 1.0f);
    func_0038CE20(&v10, &dir, 1.6f);
    vec_add_ba(a0 + 0x30, &st->pos, &v10);
    q = D_L39_0024DE80[*(s32 *)(a0 + 0x94)].p54;
    *(vu0_v4 *)(a0 + 0x20) = dir;
    func_0038CE90(a0 + 0x10, q, &dir);
    func_0038CF68(a0 + 0x10, a0 + 0x10, 1.0f);
    func_0038CE90(a0, &dir, a0 + 0x10);
    *(vu0_v4 *)(a0 + 0x40) = *(vu0_v4 *)a0;
}
/* localdecomp:end func_L39_0056F660 */
