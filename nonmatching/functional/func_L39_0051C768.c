/* functional: medium. Asm read block by block; compiles; diff = regs/scheduling; arg stores assumed equal by reading, not by an exact checker. Global slot D_001DF138_sda is the $gp-relative float (multiplayer $gp 0x247FC0). */
#include "vu0.h"
typedef struct { f32 x, y, z; } Params_0051C768;
typedef union { vu0_q q[3]; u8 b[48]; f32 f[12]; s32 w[12]; } Query_0051C768;
extern Params_0051C768 D_L39_0024A850;
extern f32 D_001DF138_sda;
extern u8 *D_L39_0024CE1C;
extern vu0_q D_L39_0025F760;
extern vu0_q D_L39_0024DE40;
extern void func_0038CFB8(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_003D5630(void);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L39_0051CC68(void *, s32);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L39_005B4468(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005B4398(s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_005C9A00(void *, void *, s32, s32, f32);

/* Multiplayer-menu level: a thrown/flying object with a spark tail (a "rocket"-style projectile).
 * Per frame it moves by its velocity, dies on leaving the map or timing out, collides against the
 * world (spawns an impact effect and dies on a hit), and drags a 16-link trail behind it that is
 * jittered and shrinks, plus occasional spark particles. */
void func_L39_0051C768(u8 *a) {
    struct { vu0_q old; Params_0051C768 params; Query_0051C768 query; vu0_q delta, current, cross, spark; } local;
    u8 *d;
    u8 *pos = a + 0x10;
    s32 result;
    s32 n;
    s32 i;
    u8 **slot;
    f32 scale;
    f32 length;

    local.params = D_L39_0024A850;
    d = *(u8 **)(a + 0x68);
    local.old = *(vu0_q *)pos;
    vec_add_ab(pos, pos, d);
    if (*(f32 *)(a + 0x10) < 0.0f || *(f32 *)(a + 0x14) < 0.0f || *(f32 *)(a + 0x18) < 0.0f) goto destroy;
    local.query.w[4] = *(s32 *)(d + 0x18);
    local.query.w[5] = 0x10001;
    local.query.f[7] = D_001DF138_sda;
    local.query.w[8] = 1;
    local.query.q[0] = *(vu0_q *)d;
    func_0038CFB8(&local.query, &local.query, 1.0f);
    local.query.f[2] = 1.0f;
    local.query.f[3] = 5627.925f;
    local.query.b[0x19] = 1;
    *(u16 *)(local.query.b + 0x1A) = *(u16 *)(a + 0xAA);
    local.query.b[0x18] = 1;
    local.query.w[10] = *(s32 *)(d + 0x60);
    if (func_0038CAD0(d + 0x10)) goto destroy;
    n = *(s32 *)(d + 0x18);
    func_L39_005FFDF8(D_L39_0024CE1C ? *(s32 *)(D_L39_0024CE1C + 0x2548) : -1);
    result = func_003D3CB0(&local.old, pos, 0, (void *)n, &local.query);
    func_L39_005FFE78();
    if (result != 0) {
        if (func_003D5630()) {
            *(vu0_q *)pos = D_L39_0025F760;
            local.query.f[7] = D_001DF138_sda * 0.5f;
            func_003D4D00(pos, 0, *(void **)(d + 0x18), &local.query, 2.0f);
            func_L01_003303B8(pos, 0, 2, 3, 2, 4, 0, 0, 0.4f, 0.0f, 0.0f, 2.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                              0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            goto destroy;
        }
        if (*(s32 *)(d + 0x10) >= 3) {
            *(s32 *)(d + 0x10) = 2;
        }
    }
    *(f32 *)(a + 0xF4) = func_0038DAB8(*(f32 *)(a + 0xF4), local.params.y);
    n = *(s32 *)(d + 0x14) - *(s32 *)(d + 0x10);
    if (n < 11) {
        scale = ((f32)n / 11.0f) * 0.15f;
    } else {
        scale = 0.15f;
    }
    vec_sub_ab(&local.delta, &local.old, pos);
    func_0038CF68(&local.delta, &local.delta, scale);
    local.current = *(vu0_q *)pos;
    if (*(u8 **)(d + 0x1C)) {
        *(vu0_q *)(*(u8 **)(d + 0x1C) + 0x10) = local.current;
    }
    slot = (u8 **)(d + 0x20);
    for (i = 15; i >= 0; i--, slot++) {
        u8 *m = *slot;
        if (m) {
            vec_add_ba(m + 0x10, &local.delta, &local.current);
            local.current = *(vu0_q *)(m + 0x10);
            *(f32 *)(m + 0x10) += func_L39_005B4468(0.0f, 0.125f);
            *(f32 *)(m + 0x14) += func_L39_005B4468(0.0f, 0.125f);
            *(f32 *)(m + 0x18) += func_L39_005B4468(0.0f, 0.125f);
            func_0038CE20(&local.delta, &local.delta, 1.05f);
        }
    }
    if (func_L39_005B4398(5)) return;
    func_0038CE90(&local.cross, &local.delta, &D_L39_0024DE40);
    func_0038D890(&local.cross, &local.cross, &local.delta, func_L39_005B4468(0.0f, 3.1415927f));
    length = func_0038CEA8(&local.cross);
    if (length == 0.0f) return;
    func_0038CE20(&local.spark, &local.cross, func_L39_005B4410(0.010000000707805157f, 0.04000000283122063f) / length);
    n = func_L39_005B43C8(8, 12);
    func_L39_005C9A00(a + 0x10, &local.spark, 0x7F2F4F6F, n, 70000.0f);
    return;
destroy:
    func_L39_0051CC68(a, 0);
    func_003C2880(a);
}
