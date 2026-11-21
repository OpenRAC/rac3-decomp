/* func_L01_00437B68: 3 diff in L01_00437AF8.c (its own flags):
   - the skip flag: retail loads the 1 before the xor (`addiu $v1,$zero,1` is the slot of the filter == -1
     `beq`, then `xor`, `b`, `movz`), gcc has xor first and the 1 after it (the hoisted constant's copy
     comes after the xor in sched1's order); every other wording of the flag (`skip = a != filter`, 1 then
     `if (a == filter) skip = 0`, an inlined helper, ?:) drops the movz for xor/sltu (about 100 diffs);
   - the 0x8D4 / a1C[h2E] select: gcc `bnel` (0x8D4 in the annulled slot), retail `bnez` with 0x8D4 in the
     slot; a fresh local for the value ('w = 0x8D4; if (!b4) w = ...' and if/else/?: forms) gives 95..145;
   fixed in round 6 (x2): the entry address as an integer sum `(u8 *)(j * 2 + (s32)p)` gives retail's
   `addu $v1,$s1,$v1`, and `s32 h = m->h0; ... (u32)h >> 8` gives `lh` + `srl` (a (u32)m->h0 or u16 form
   narrows the load to lhu).
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
            if (filter != -1) {
                if (a != filter) skip = 1; else skip = 0;
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
