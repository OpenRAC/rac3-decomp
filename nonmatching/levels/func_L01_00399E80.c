/* func_L01_00399E80 (Claude wave 14 r56, 2026-11-28). Replaces the earlier draft of this function (Codex wave 8 near miss). */
/* func_L01_00399E80: near miss, 261 positional diffs under the file's own line (the Codex wave 8 draft no
 * longer compiles on this master: its func_0038CB00(u8 *) conflicts with the file's
 * `extern s32 func_0038CB00(void *);`, and it redefined the later block's Vec4_0039E0C8 typedef).
 * Changed against that draft: the file's func_0038CB00 prototype; func_0038CF68 through the file's
 * own alias idiom (func_0038CF68_00399E80(void *, void *, f32), as the file's other blocks do);
 * D_L01_001E2040/2048/2050 as small s16[4] tables with a 16-byte .extern hint (retail rebuilds each
 * address with an assembler la, lui/addiu in the same register, inside the loop); the VU0 load
 * orders from retail (vec_sub_ba for end = point - pos and for the deltas, vec_add_ab for
 * end = point + end and the rebuild); natural up-counting loops (gcc reverses them as retail has).
 * Same block structure, frame (0x150), loop alignment and calls as retail; what differs is register
 * allocation: combine merges target = D_L01_002A1BF0[i] into mtlo/madd, which sched1 hoists above
 * the four calls of the then-arm, so i dies early, s4 is reused and next (i + 1) gets $fp; retail
 * keeps mult/addu after the vadd, spills next to 0xD4($sp) and holds 9 in $fp (s6/s7 roles and the
 * 0xD4/0xD8 spill slots follow from that). */
#include "common.h"

/* localdecomp:start func_L01_00399E80 */
extern s16 D_L01_001E2040[4];
__asm__(".extern D_L01_001E2040, 16");
extern s16 D_L01_001E2048[4];
__asm__(".extern D_L01_001E2048, 16");
extern s16 D_L01_001E2050[4];
__asm__(".extern D_L01_001E2050, 16");
extern vu0_q D_L01_002A1BF0[][10];
extern f32 D_001DE0E8_sda;
__asm__(".extern D_001DE0E8_sda, 4");
extern f32 D_001DE0EC_sda;
__asm__(".extern D_001DE0EC_sda, 4");
extern void func_0038CF68_00399E80(void *, void *, f32);

void func_L01_00399E80(u8 *obj) {
    extern s32 func_0038CB00(void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
    struct {
        vu0_v4 point;
        vu0_v4 end;
        vu0_v4 temp;
        vu0_v4 delta[10];
    } local;
    u8 *vars = *(u8 **)(obj + 0x68);
    vu0_v4 *deltas = local.delta;
    s32 i, next, j;

    for (i = 0; i < 4; i = next) {
        if (func_0038CB00(&D_L01_001E2040[i])) {
            vu0_q *target;
            f32 t;

            next = i + 1;
            D_L01_001E2048[i] = 0;
            D_L01_001E2040[i] = (D_L01_001E2050[i] * 5 + 2) / 6;
            *(vu0_q *)&local.point = *(vu0_q *)(vars + 0x30);
            local.point.x += func_003824E0(-0.5f, 0.5f);
            local.point.y += func_003824E0(-0.5f, 0.5f);
            local.point.z += func_003824E0(-0.5f, 0.5f);
            vec_sub_ba(&local.end, &local.point, obj + 0x10);
            func_0038CF68_00399E80(&local.end, &local.end, D_001DE0E8_sda);
            vec_add_ab(&local.end, &local.point, &local.end);
            target = D_L01_002A1BF0[i];
            for (j = 0; j < 10; j++) {
                t = j * 0.1f;
                if (j == 9) {
                    t = 1.0f;
                }
                func_L01_00445208(&local.temp, obj + 0x10, &local.point, vars + 0x40, &local.end, t);
                *target++ = *(vu0_q *)&local.temp;
            }
        } else {
            next = i + 1;
            for (j = 1; j < 10; j++) {
                vec_sub_ba(&local.delta[j], &D_L01_002A1BF0[i][j], &D_L01_002A1BF0[i][j - 1]);
                deltas[j].x += func_L01_00443A18(0.0f, 0.05f);
                deltas[j].y += func_L01_00443A18(0.0f, 0.05f);
                deltas[j].z += func_L01_00443A18(0.0f, 0.05f);
            }
            D_L01_002A1BF0[i][0] = *(vu0_q *)(obj + 0x10);
            for (j = 1; j < 10; j++) {
                vec_add_ab(&D_L01_002A1BF0[i][j], &D_L01_002A1BF0[i][j - 1], &local.delta[j]);
            }
        }
        for (j = 2; j < 9; j++) {
            *(vu0_q *)&local.point = D_L01_002A1BF0[0][j];
            local.point.x += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            local.point.y += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            local.point.z += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            D_L01_002A1BF0[1][j] = *(vu0_q *)&local.point;
        }
        for (j = 2; j < 9; j++) {
            *(vu0_q *)&local.point = D_L01_002A1BF0[0][j];
            local.point.x += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            local.point.y += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            local.point.z += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            D_L01_002A1BF0[2][j] = *(vu0_q *)&local.point;
        }
        for (j = 2; j < 9; j++) {
            *(vu0_q *)&local.point = D_L01_002A1BF0[0][j];
            local.point.x += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            local.point.y += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            local.point.z += func_L01_00443A18(0.0f, D_001DE0EC_sda);
            D_L01_002A1BF0[3][j] = *(vu0_q *)&local.point;
        }
    }
}
/* localdecomp:end func_L01_00399E80 */
