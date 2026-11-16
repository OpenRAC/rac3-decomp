/* func_L09_003BDED0: 5 diff with --as ps2as (87 diff with the file's default-assembler flags: constants come from $gp pool, retail uses lui/ori; NEEDS-FLAGS --as ps2as). Remaining: inner-loop slti uses $v0 (retail $v1), and the last func_003D4D00 call orders mov.s $f12 after a2/a3 (retail first). Tried k var, ptr var, do-while. */
#include "vu0.h"
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);

void func_L09_003BDED0(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 off;
    vu0_v4 w[6];
    u8 *s;
    s32 i;
    s32 j;
    f32 ang;

    s = *(u8 **)(a0 + 0x68);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            func_003C2F58(a0, i * 5 + 0x28 + j, &pos);
            ang = func_0038D160(pos.x - *(f32 *)(a0 + 0x10), pos.y - *(f32 *)(a0 + 0x14));
            off.x = func_0038D098(ang) * 3.0f;
            ang = func_0038D160(pos.x - *(f32 *)(a0 + 0x10), pos.y - *(f32 *)(a0 + 0x14));
            off.y = func_0038D0B0(ang) * 3.0f;
            off.z = 0.5f;
            off.w = 5627.9248f;
            func_L01_00446760(w, a0, 0x10001, &off, (f32)s[0x44]);
            func_003D4D00(&pos, 0, a0, w, 1.5f - (f32)j * 0.2f);
        }
    }
    pos = *(vu0_v4 *)(a0 + 0x10);
    off.x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 1.3f;
    off.y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 1.3f;
    off.z = 1.5f;
    vec_add_ab(&pos, &pos, &off);
    w[0].x = func_0038D098(*(f32 *)(a0 + 0xF8)) * 3.0f;
    w[0].y = func_0038D0B0(*(f32 *)(a0 + 0xF8)) * 3.0f;
    w[0].z = 0.5f;
    w[0].w = 5627.9248f;
    func_L01_00446760(&w[3], a0, 0x10001, w, (f32)s[0x44]);
    func_003D4D00(&pos, 0, a0, &w[3], 3.0f);
}
