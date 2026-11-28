/* func_L01_00456C98 (Claude wave 14 r51, 2026-11-28). Replaces the earlier draft of this function (near miss (open-rac-engine names it enemy_find_target)). */
/* func_L01_00456C98 (enemy_find_target): 325 diff with the file's flags (wave 14 r51; the round-13 draft had
 * 337). Change against it: the id != -1 path is written with nested ifs and the single `return out->valid`
 * at the end instead of early returns, so the skip label of `same && kind` has one use and cse keeps the hero
 * base of the first compare in $a0 for the second one, as retail (the mode != 0 path now matches up to the
 * D_L01_001D673C test). Still differs: the saves (retail sq/lq in 16-byte slots, frame 0xF0: the function
 * needs the existing line `-O2 -G8 -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2` (as
 * src/levels/shared/L01_003F79D8.c) plus an sq_ra_funcs row; 0x456C98-0x4572B0 starts and ends 8-aligned);
 * $f21/$f22 hold height/scale the other way round; and cross-jumping merges the three
 * func_L01_00450E48 calls into one here where retail keeps the call of the mode == 0 site (shared with the
 * mode site) and of the best-target site, the add tail being the shared one. */
#include "common.h"

/* localdecomp:start func_L01_00456C98 */
typedef int Q_00456C98 __attribute__((mode(TI)));
typedef struct { Q_00456C98 pos; u8 *target; s16 valid; u8 pad16[6]; s16 kind; } Target_00456C98;
typedef struct {
    u8 pad0[0xD0];
    Q_00456C98 pos;                /* 0xD0 */
    u8 padE0[0x25C0 - 0xE0];
    u8 *moby;                      /* 0x25C0 */
    s32 state;                     /* 0x25C4 */
} H_00456C98;
extern s32 D_L01_001D6694;
extern void func_L01_00450E48(void *, void *, f32, f32, f32);
extern M_453408 *func_L01_00456910(M_453408 *source, s32 index, s32 *out, s32 team, s32 c, s32 d, s32 check, s32 g, f32 scale);
extern int func_L01_00456B40(u8 *p, u8 *q, f32 f12, f32 f13);

s32 func_L01_00456C98(u8 *obj, s32 id, void *position, s32 force, s32 mode, s32 same, s32 team, s32 option, f32 radius, f32 height, f32 scale, u8 ray, u8 extra) {
    Q_00456C98 origin[1];
    s32 kind;
    Target_00456C98 *out;
    u8 *item;
    u8 *best;
    s32 best_kind;
    s32 i;
    f32 score, distance;
    V_453408 *vars;

    if (!(*(u16 *)(obj + 0x34) & 0x20)) return 0;
    out = *(Target_00456C98 **)(*(u8 **)(obj + 0x68) + 0xC);
    if (position) origin[0] = *(Q_00456C98 *)position;
    else origin[0] = *(Q_00456C98 *)(obj + 0x10);
    out->target = ((H_00456C98 *)&D_001A4BE0)->moby;
    out->pos = ((H_00456C98 *)&D_001A4BE0)->pos;
    out->kind = 0;
    out->valid = 0;
    if (!force) {
        if (D_L01_001D6694) return 0;
        if (((H_00456C98 *)&D_001A4BE0)->state == 116) return 0;
    }
    if (id != -1) {
        item = (u8 *)func_L01_00456910((M_453408 *)obj, id, &kind, team, mode, option, ray, extra, scale);
        if (item) {
            if (mode) {
                if (item != ((H_00456C98 *)&D_001A4BE0)->moby
                    && !(same && *(s16 *)(item + 0xAA) == *(s16 *)(obj + 0xAA))) {
                    out->target = item;
                    out->valid = 1;
                    out->kind = *(u16 *)&kind;
                    if (item != ((H_00456C98 *)&D_001A4BE0)->moby) {
                        out->pos = *(Q_00456C98 *)(item + 0x10);
                        vars = func_00382348((M_453408 *)item);
                        if (vars) {
                            if (D_L01_001D673C_004566F8) func_L01_00450E48(item, out, 0.0f, 0.0f, *(f32 *)((u8 *)vars + 0x10));
                            else *(f32 *)((u8 *)out + 8) += *(f32 *)((u8 *)vars + 0x10);
                        }
                    }
                }
            } else {
                if (!(same && *(s16 *)(item + 0xAA) == *(s16 *)(obj + 0xAA))) {
                    out->target = item;
                    out->valid = 1;
                    out->kind = *(u16 *)&kind;
                    out->kind = *(u16 *)&kind;
                    if (item != ((H_00456C98 *)&D_001A4BE0)->moby) {
                        out->pos = *(Q_00456C98 *)(item + 0x10);
                        vars = func_00382348((M_453408 *)item);
                        if (vars) {
                            if (D_L01_001D673C_004566F8) func_L01_00450E48(item, out, 0.0f, 0.0f, *(f32 *)((u8 *)vars + 0x10));
                            else *(f32 *)((u8 *)out + 8) += *(f32 *)((u8 *)vars + 0x10);
                        }
                    }
                }
            }
        }
    } else {
        if (((H_00456C98 *)&D_001A4BE0)->state == 49) height = 60.0f;
        distance = 9999999.0f;
        best = 0;
        best_kind = 0;
        if (!mode) {
            item = ((H_00456C98 *)&D_001A4BE0)->moby;
            if (func_L01_00456B40(item, (u8 *)origin, radius, height)) {
                score = func_L01_004566F8((M_453408 *)obj, (M_453408 *)item, 0, 0, ray, extra, scale);
                if (score < distance) { best = item; best_kind = 1; distance = score; }
            }
        }
        if (!mode) {
            for (i = 1; i <= D_L01_001E0180_00456270[0]; i++) {
                item = D_L01_001E001C + (D_L01_001E0180_00456270[i] << 8);
                if (item && *(s16 *)(item + 0xAA) == 203 && item[0x20] != 254 && item[0x20] != 253 && item[0x20] == 3) {
                    if (func_L01_00456B40(item, (u8 *)origin, radius, height)) {
                        score = func_L01_004566F8((M_453408 *)obj, (M_453408 *)item, mode, 0, ray, extra, scale);
                        if (score < distance) { best = item; best_kind = 2; distance = score; }
                    }
                }
            }
        }
        for (i = 0; i < D_L01_001D6774; i++) {
            item = D_L01_001EFFE8[i];
            if (same && *(s16 *)(item + 0xAA) == *(s16 *)(obj + 0xAA)) continue;
            if (func_L01_00456B40(item, (u8 *)origin, radius, height) && item && item[0x20] != 254 && item[0x20] != 253 && item != obj) {
                score = func_L01_004566F8((M_453408 *)obj, (M_453408 *)item, mode, 0, ray, extra, scale);
                if (score < distance) {
                    if (team) {
                        if (D_L01_001F01E8[i] != team) continue;
                        best = item; best_kind = D_L01_001F01E8[i]; distance = score;
                    } else { best = item; best_kind = 3; distance = score; }
                }
            }
        }
        if (!mode) {
            for (i = 1; i <= D_L01_001E01C0[0]; i++) {
                item = D_L01_001E001C + (D_L01_001E01C0[i] << 8);
                if (item && *(s16 *)(item + 0xAA) == 7107 && item[0x20] != 254 && item[0x20] != 253) {
                    if (func_L01_00456B40(item, (u8 *)origin, radius, height)) {
                        score = func_L01_004566F8((M_453408 *)obj, (M_453408 *)item, mode, 0, ray, extra, scale);
                        if (score < distance) { best = item; best_kind = 4; distance = score; }
                    }
                }
            }
        }
        if (best) {
            out->valid = 1; out->kind = best_kind; out->target = best;
            if (best == ((H_00456C98 *)&D_001A4BE0)->moby) out->pos = ((H_00456C98 *)&D_001A4BE0)->pos;
            else {
                out->pos = *(Q_00456C98 *)(best + 0x10);
                vars = func_00382348((M_453408 *)best);
                if (vars) {
                    if (D_L01_001D673C_004566F8) func_L01_00450E48(best, out, 0.0f, 0.0f, *(f32 *)((u8 *)vars + 0x10));
                    else *(f32 *)((u8 *)out + 8) += *(f32 *)((u8 *)vars + 0x10);
                }
            }
        }
    }
    return out->valid;
}
/* localdecomp:end func_L01_00456C98 */
