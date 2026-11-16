/* NTSC-U draft (Claude wave C2): C of func_L39_00550D60, the NTSC-U twin of func_L39_005516B0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 63 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00550D60", whose code is not the PAL one).
 * Worker's note: 63 diff (right semantics, wrong address forms): retail materializes D_L39_003C14F0 (= D_L39_003C14E0 + 0x10) with lui/addiu into v1 for the vector store (addu v0,row*0x12C0+idx*0x30,v1; sq 0(v0)) and derives the table base as s4 = v1 - 0x10 for everything ...
 */
#include "common.h"

/* NTSC-U counterpart of the PAL function at the same position (L39 shared, @ps2as) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_00550D60 */
typedef struct {
    u8 pad_00[0x10];
    u128_t v10;
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
} Elem_550D60;

extern Elem_550D60 D_L39_003C14E0[][100];
extern f32 func_L01_00447C00(f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern void func_L39_00550E78(void *, s32);

void func_L39_00550D60(u8 *obj, u128_t *pos) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 idx = *(s16 *)(sub + 0x30);
    s32 row = sub[0x3A];
    u128_t *vp;
    Elem_550D60 *e;

    vp = &D_L39_003C14E0[row][idx].v10;
    *vp = *pos;
    e = &D_L39_003C14E0[row][idx];
    e->f20 = func_L01_00447C00((f32)idx * 0.6981317f);
    e->f24 = 0.25f;
    e->f28 = func_L39_005B2510(3.0f, 3.0f) * 0.017453292f;
    e->f2C = func_L39_005B2568(0.01f, 0.2f) * 0.016666668f;
    func_L39_00550E78(D_L39_003C14E0[row], idx);
    *(u16 *)(sub + 0x30) += 1;
}
/* localdecomp:end func_L39_00550D60 */
