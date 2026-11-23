/* functional: high. 8-word alloc diff; retail has two nops after the packed table copy (divs row needed), same behaviour. */
#include "common.h"

/* localdecomp:start func_L01_00396B78 */
#include "vu0.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_0039E0C8;
typedef struct { s32 colors[2]; } __attribute__((packed)) Colors_00396B78;
extern Colors_00396B78 D_L01_001DE0C8;
void func_L01_00396B78(u8 *moby, s32 unused, Vec4_0039E0C8 *position, Vec4_0039E0C8 *direction) {
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_0038CE90(Vec4_0039E0C8 *, Vec4_0039E0C8 *, Vec4_0039E0C8 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_00382538(void);
    extern void func_0038D890(Vec4_0039E0C8 *, Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern s32 func_0013D3E0(void);
    extern void func_L01_00472238(void *, void *, s32, s32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_L01_00472560(void *, void *, s32, s32, f32);
    Vec4_0039E0C8 end, start, small, delta;
    Colors_00396B78 colors;
    Vec4_0039E0C8 rotated;
    u8 *state;
    s32 i;
    f32 angle;
    f32 size;
    state = *(u8 **)(moby + 0x68);
    func_003A52A0(0, 0, moby);
    func_0038CF68(&end, direction, 2.0f);
    vec_add_ab(&end, &end, position);
    func_0038CE90(&delta, position, &end);
    func_0038CF68(&start, direction, 0.15f);
    vec_add_ba(&start, position, &start);
    func_0038CF68(&delta, &delta, 1.0f);
    func_0038CE20((f32 *)&small, (f32 *)direction, 0.0009765625f);
    func_0038CF68(&small, &small, 1.0f);
    colors = D_L01_001DE0C8;
    angle = func_00382538();
    for (i = 23; i >= 0; i--) {
        func_0038D890(&rotated, &delta, direction, angle);
        func_L01_00472238(&start, &rotated, colors.colors[func_0013D3E0() % 2], 17, 0.05000000447f);
        angle = func_0038DAB8(angle, 0.2731819749f);
    }
    for (i = 0; i < 24; i++) {
        s32 r;
        size = ((f32)i / 23.0f) * 1.5f;
        r = func_0013D3E0();
        func_L01_00472560(position, &small, colors.colors[r % 2], func_00382498(25, 42), size);
    }
    *(vu0_q *)state = *(vu0_q *)&small;
}
/* localdecomp:end func_L01_00396B78 */
