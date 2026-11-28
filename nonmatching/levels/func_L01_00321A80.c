/* func_L01_00321A80 (Claude wave 14 retry r81, 2026-11-28). Replaces the earlier draft of this function (Codex wave 10 near miss). */
/* PAL near miss, wave 14 retry r81 (2026-11-28): func_L01_00321A80 (1288 B, 34 places), 12 diff under the file's
 * own line (build/codex/wave10/p10/check.py, level 01); r63's near (from the Codex wave 10 draft) had 20.
 * Changed against r63's near: the moby argument of func_003D3CB0 is assigned to a local in the call
 * (`mob = D_001A4BE0.moby`, found by the permuter; a copy of the weapon pointer gives the same 12): the
 * lui pairs of the angle's vsub_ab and of D_001A4EC0 in the particle loop now take retail's v0/v1;
 * func_L01_00446780 declared s32 (other files test its result; same count either way).
 * Still differs (12 rows): (1) 9 rows, the hit record: retail stores owner and flags right after the
 * lqc2 of `end` and before the weapon's damage load; here every field store waits for that load (the
 * damage field is the first statement: anti-dependence in sched2). Field orders owner/flags/damage/enabled
 * (41), owner/flags/enabled/damage (47) and vec_sub_ba before the field stores (275-278, vf1/vf2 swap)
 * are worse. (2) 3 rows, the argument moves of func_L01_004669B0: the file declares it
 * (f32, f32, f32, f32, u8 *, s32, f32 *, u32, s32) but its definition and other callers put the position
 * pointer first, which is retail's move order (a0 before f12/f13); the file's declaration is kept. */
#include "common.h"

/* localdecomp:start func_L01_00321A80 */
#include "vu0.h"
typedef struct {
    f32 vector[4];
    u8 *owner;
    u32 flags;
    u8 kind;
    u8 subtype;
    u16 class_id;
    f32 damage;
    s32 enabled;
} Hit_00321A80;
extern u8 D_001A4EC0[];
extern u8 *D_L01_00221098[];
extern vu0_v4 D_L01_001EAA20;
__asm__(".extern D_L01_001DC940, 4");
void func_L01_00321A80(u8 *self) {
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_L01_00446780(u8 *, f32 *, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_0038D160(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern u8 *func_L01_0046A610(f32 *, f32 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    Hit_00321A80 hit;
    vu0_v4 delta;
    f32 velocity[4] __attribute__((aligned(16)));
    f32 position[4] __attribute__((aligned(16)));
    End_00321608 *end;
    G_31DB28 *weapon;
    u8 *cam;
    u8 *particle;
    u8 *vars;
    u8 *mob;
    s32 i;
    s32 j;
    s32 spin;
    f32 angle;
    f32 size;
    f32 speed;
    f32 elevation;

    for (i = 0; i < D_L01_001DC940; i++) {
        end = &D_L01_00276A30[i];
        weapon = &D_L01_002C5600[D_001425C0[0x47]];
        hit.damage = weapon->f6C;
        hit.owner = self;
        hit.flags = 0x410000;
        hit.enabled = 1;
        vec_sub_ba(hit.vector, end, self + 0x10);
        func_0038CF68(hit.vector, (s32)hit.vector, 0.7f);
        hit.class_id = *(u16 *)(self + 0xAA);
        hit.vector[3] = 5627.9248046875f;
        hit.kind = 1;
        hit.subtype = 1;
        if (func_L01_0040E548(self + 0x10, end) < 3600.0f &&
            func_003D3CB0(self + 0x10, end, 0, mob = D_001A4BE0.moby, (s32)&hit) != 0) {
            weapon = &D_L01_002C5600[D_001425C0[0x47]];
            if (((E240_321CB8 *)weapon)->x1 >= 4) {
                func_L01_00446780(self, end->f, 0x410000, 0, 1, 0, 2.0f, weapon->f6C, 0.0f);
            } else {
                func_L01_00446780(self, end->f, 0x410000, 0, 1, 0, 1.0f, weapon->f6C, 0.0f);
            }
            vec_sub_ab(&delta, &D_L01_001E29C0, &D_L01_001EAA20);
            angle = func_0038D160(delta.x, delta.y);
            cam = (u8 *)D_L01_001EAA00;
            for (j = 0; j < 20; j++) {
                func_0038CE20(velocity, D_001A4EC0, -(func_003824E0(0.2f, 3.0f) * 0.020000001415610313f));
                spin = func_L01_00443A18(1.0f, 2.0f);
                size = func_003824E0(0.3f, 0.75f) * 210000.0f;
                position[0] = *(f32 *)(cam + 0x20) + func_L01_00443A18(0.0f, 0.2f);
                position[1] = *(f32 *)(cam + 0x24) + func_L01_00443A18(0.0f, 0.2f);
                position[2] = *(f32 *)(cam + 0x28) + func_L01_00443A18(0.0f, 0.2f);
                particle = func_L01_004669B0(0.0f, 1.0f, 1.01f, size, (u8 *)position, spin, velocity, 0x7F202020, 0);
                if (particle != 0) {
                    particle[3] = 0x44;
                    *(s16 *)(particle + 0xA) = 75;
                    vars = particle + 0x20;
                    particle[9] = 0x44;
                    *(f32 *)(vars + 0x1C) = 4.0f;
                    *(s32 *)(vars + 4) = 3;
                    vars[0xA] = 0x30;
                    vars[0xB] = particle[0xA];
                }
                speed = func_003824E0(1.0f, 2.0f);
                elevation = func_003824E0(0.0f, 1.3962634f);
                size = func_0038DAB8(angle, func_L01_00443A18(0.0f, 1.3962634f));
                func_00382760(velocity, speed * 0.020000001415610313f, size, elevation);
                position[0] = *(f32 *)(cam + 0x20) + func_L01_00443A18(0.0f, 0.1f);
                position[1] = *(f32 *)(cam + 0x24) + func_L01_00443A18(0.0f, 0.1f);
                position[2] = *(f32 *)(cam + 0x28) + func_L01_00443A18(0.0f, 0.1f);
                size = func_003824E0(0.25f, 0.7f) * 210000.0f;
                particle = func_L01_0046A610(position, velocity, 25, 127, 0x7FFF8040, spin, size, 500.0f, 1.0f, 0.0f, 0.0f);
                if (particle != 0) {
                    particle[2] = D_L01_00221098[0x61][6];
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00321A80 */
