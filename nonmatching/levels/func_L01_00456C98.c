/* NEAR MISS: func_L01_00456C98 / enemy_find_target. Needs the sq route: retail saves $s0-$s7,
   $fp and $ra with sq in ascending 16-byte slots (frame 0xF0), which this file's flags
   (-fopt-stack) cannot give: it would need a file of its own without -fopt-stack and a
   config/levels/sq_ra_funcs.txt row (not made; the maintainer decides the split).
   2026-11-23 (round 13, r13_b/e3.c), measured after the master merge (baseline 339 words
   positional, 200 structural, 158 ignoring registers):
   - with the file's flags: 337 positional, 111 structural, 82 ignoring registers;
   - with --flags=-fno-opt-stack (no sq_ra row, so the saves are not reordered): 330, 99, 78.
   What closed the gap: declarations that agree with the file's current blocks (the matched
   func_L01_00456910 takes `s32 *` for the kind, and check.py's context has no prototypes for
   the file's own functions, so without these externs the calls were implicit, with doubles on
   the stack); the hero as a struct reached through &D_001A4BE0 (lui/addiu once, then
   0x25C0($4), as retail and 00456910); the moby lists and D_L01_001D673C under the names
   func_L01_00456270/004566F8 declare (.sdata, $gp); `origin` as a one-element array, so its
   stack slot comes first (retail: origin at 0, kind at 0x10, the spills from 0x14).
   Still differs: the saves (sq route); $f21/$f22 hold height/scale the other way round (a
   local copy of height for the 60.0 case: worse, 84); the hero base is recomputed at the
   second compare of the mode != 0 path where retail keeps it in $a0; where the vars->+0x10
   add is merged into the shared tail, retail falls into `b tail` and branches to the call
   (writing that site's if/else the other way round gives the same bytes; all three: 96).
   Older notes: sd/ld saves versus sq/lq, frame A0 versus F0; "plus a 309.0f reload". */
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
        if (!item) return out->valid;
        if (mode) {
            if (item == ((H_00456C98 *)&D_001A4BE0)->moby) return out->valid;
            if (same && *(s16 *)(item + 0xAA) == *(s16 *)(obj + 0xAA)) return out->valid;
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
        } else {
            if (same && *(s16 *)(item + 0xAA) == *(s16 *)(obj + 0xAA)) return out->valid;
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
