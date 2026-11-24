/* func_L01_00437B68: 1 diff in L01_00437AF8.c (its own flags, check.py --mode S --no-context; round 21 W4):
   - the skip flag is solved: `skip = 1; if (filter != -1) { if (a == filter) skip = 0; } else skip = 0;`
     gives retail's `addiu $v1,1` in the filter == -1 `beq` slot, then xor, movz (every other wording of the
     flag: 6 diff (else-if chain) .. about 100);
   - left: the 0x8D4 / a1C[h2E] select: gcc `bnel` (0x8D4 in the annulled slot), retail `bnez` with 0x8D4 in the
     slot. With a local (`w = 0x8D4; if (!b4) w = a1C[h2E]; out[n].w8 = w;`, any of skip/h/b or a fresh s32/s16)
     gcc does emit `bnez` + 0x8D4 in the slot, but loop.c then no longer hoists the 0x14 mult constant into
     $s4 (it is rebuilt in $t0 inside the loop, max moves to $fp, frame 0x60): 145 diff. Ternary forms that
     change nothing: `b4 != 0 ? :`, `(s32)a1C[..]`, swapped arms, `0x8D4 + (!b4 ? x - 0x8D4 : 0)`; a store of
     0x8D4 first then a conditional store (148); `m->h2C == 2` as the condition (99).
   fixed in round 6 (x2): the entry address as an integer sum `(u8 *)(j * 2 + (s32)p)` gives retail's
   `addu $v1,$s1,$v1`, and `s32 h = m->h0; ... (u32)h >> 8` gives `lh` + `srl` (a (u32)m->h0 or u16 form
   narrows the load to lhu).
   Round 25 W7 (b39, ~75 compiles, base 626eebd0d; the 1-diff seed above is unchanged):
   - Root cause of why the plain-bnez forms lose: -ds / -dL dumps show the ternary seed has TWO `li 20` sets (before and
     after the select's diamond), so loop.c merges them (`Insn 214 ... moved`, `340 matches 214`) and hoists 0x14 into $s4.
     `w = 0x8D4; if (!b4) w = a1C[..];` puts the li before the branch (retail's plain bnez) but the join label has one jump
     use and cse1's skip-block path extension (any else-arm size, toy-verified) merges the two sets into ONE, which loop.c
     does not move: the constant is rebuilt per iteration and `max` wins $fp (145 diff). A toy loop shows the 2-set,
     plain-`bne` form is `if (b4) w = 0x8D4; else w = a1C[..]; out[*count].w8 = w;` (also stores in both arms): it keeps the
     hoist AND emits `bne` + `li` in the slot (not bnel), but then gcse no longer PREs the loop test's `lw count` into $a3
     for the first mult (the body reloads it) and max/filter/i*4 shuffle ($t1 vs $t0, s6/s7 swap): 99 / 92 diff.
   - Reorg theory for the seed's bnel: own_thread_p is true (the then-block follows a barrier), so the slot li could be
     moved plain; retail has it before the branch (fill_simple_delay_slots backward pick) instead.
   - Tested (diff): tails duplicated into both arms 120; tail stmts before the select 26/28; w typed s32/u32/s16/u16/s8/u8
     145, s64 151; w = 0x8D4 at 4 other positions 145; a1C value forms x5 145; if/else into w 99; stores in both arms 92;
     value hoisted into a local 43 (movz, not retail); 30 declaration-order permutations 99 (order has no effect);
     --all-modes 1/1/139/139; -fno-sched-interblock / -fno-regmove / -fno-strength-reduce / -fno-expensive-optimizations 1,
     -fno-gcse 150, -fno-schedule-insns2 90. A 256-wording sweep (if/else-into-w, stores in both arms, both arm orders x
     selector b4 / b4 != 0 / m->h2C == 2 / b4 & 1 x four a1C value forms x four tail orders): best 83 (`m->h2C == 2` selector,
     which makes loop.c hoist the constant 2 into $a3 and changes the frame), the b4-memory selectors 92..108.
   */
#include "common.h"
typedef struct {
    s32 w0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad7;
    s32 w8;
    s32 wC;
    u8 b10;
    u8 pad11[3];
} O_00437B68;

typedef struct {
    s16 h0;
    u8 pad2[6];
    s16 h8;
    u8 padA[0x18 - 0xA];
    u16 flags;
    s16 h1A;
    s16 a1C[8];
    s16 h2C;
    s16 h2E;
} M_00437B68;

typedef struct {
    u8 *p[4];
} L_00437B68;

extern L_00437B68 D_L01_001D7B48;
extern u8 *D_L01_002E99F0[];
extern s32 func_0039F4B0(u8 *);

s32 func_L01_00437B68(O_00437B68 *out, s32 *count, s32 max, s32 filter) {
    L_00437B68 lists = D_L01_001D7B48;
    s32 i;
    s32 j;
    u8 *e;
    s32 a;
    s32 b;
    M_00437B68 *m;
    s32 skip;
    s32 h;

    *count = 0;
    for (i = 0; lists.p[i] != 0; i++) {
        for (j = 0; !func_0039F4B0(lists.p[i] + j * 2) && *count < max; j++) {
            e = (u8 *)(j * 2 + (s32)lists.p[i]);
            a = e[0];
            b = e[1];
            m = (M_00437B68 *)(D_L01_002E99F0[a - 1] + b * 48);
            if (m->flags & 2) {
                continue;
            }
            if (m->h2C == 0) {
                continue;
            }
            if ((m->flags & 1) && m->h2C == 2) {
                continue;
            }
            skip = 1;
            if (filter != -1) {
                if (a == filter) skip = 0;
            } else {
                skip = 0;
            }
            if (skip) {
                continue;
            }
            out[*count].b10 = a - 1;
            out[*count].w0 = m->h8;
            out[*count].b4 = m->h2C == 2;
            out[*count].b6 = *(u8 *)m;
            out[*count].w8 = out[*count].b4 ? 0x8D4 : m->a1C[m->h2E];
            h = m->h0;
            out[*count].b5 = (u32)h >> 8;
            out[*count].wC = m->h1A;
            (*count)++;
        }
    }
    return *count > 0 && *count <= max;
}
