#include "common.h"

typedef struct {
    u8 pad0[0x44];
    s32 ids[3];
} Grp_003326D8;

typedef struct { u8 pad[0x44]; s32 ids[3]; } Grp_00332298;

/* localdecomp:start func_L07_00332CF0 */
#include "vu0.h"
typedef struct { u8 pad[0x18]; u8 *moby; } Hit_00332CF0;
extern Hit_00332CF0 D_L07_001E8C00;
extern vu0_v4 D_L07_001D9AE0 __attribute__((section(".sdata")));
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_L07_00333858(void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L07_00333878(u8 *);
extern f32 func_L07_003330E8(u8 *, u8 *, f32, f32);
extern f32 func_L07_00332F90(u8 *, u8 *, u8 *, f32);

f32 func_L07_00332CF0(u8 *a, u8 *b, vu0_v4 *c, f32 angle) {
    vu0_v4 diff, offset, end, side, start, finish;
    s32 hit;
    f32 original, adjusted, radius, result;

    hit = func_L07_00332A90(a);
    vec_sub_ba(&diff, c, b + 0x10);
    func_0038CF68(&diff, &diff, 10.0f);
    original = func_0038D160(diff.x, diff.y);
    adjusted = func_0038DAB8(original, angle);
    *(vu0_q *)&end = 0;
    end.x = func_0038D098(adjusted) * 10.0f;
    end.y = func_0038D0B0(adjusted) * 10.0f;
    *(vu0_q *)&offset = *(vu0_q *)&end;
    vec_add_ab(&end, b + 0x10, &offset);
    if (!hit)
        return func_L07_00332F90(a, b, (u8 *)&end, angle);
    func_0038CE90(&side, &offset, &D_L07_001D9AE0);
    radius = func_L07_00333858(b);
    func_0038CF68(&side, &side, radius);
    vec_add_ba(&start, b + 0x10, &side);
    func_0038CF68(&side, b + 0xC0, radius);
    vec_add_ba(&start, &start, &side);
    vec_add_ab(&finish, &end, &side);
    if (func_003D3CB0(&start, &finish, 9, b, 0) && D_L07_001E8C00.moby && func_L07_00333878(D_L07_001E8C00.moby)) {
        result = ((f32 (*)(u8 *, u8 *, void *, f32, f32))func_L07_003330E8)(b, D_L07_001E8C00.moby, c, original, adjusted);
    } else {
        vec_sub_ba(&start, b + 0x10, &side);
        vec_sub_ab(&finish, &end, &side);
        if (func_003D3CB0(&start, &finish, 9, b, 0) && D_L07_001E8C00.moby && func_L07_00333878(D_L07_001E8C00.moby))
            result = ((f32 (*)(u8 *, u8 *, void *, f32, f32))func_L07_003330E8)(b, D_L07_001E8C00.moby, c, original, adjusted);
        else
            result = func_L07_00332F90(a, b, (u8 *)&end, angle);
    }
    func_L07_00332BE0(a);
    return result;
}
/* localdecomp:end func_L07_00332CF0 */
