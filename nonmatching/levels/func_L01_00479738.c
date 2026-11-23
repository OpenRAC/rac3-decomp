/* PAL near miss (sol-2): 4 words differ with the file's flags; the two tally-word loads appear in reverse order at the gain-start check. */
/* Near miss (6 differing words; open-rac-engine: hud_bolts_roll). Everything matches but the
 * second tally-start branch's test `[8] + [10] < bolts`: retail puts the 0x142660 high half in
 * $a0, [10] in $a1 and the bolts in $v1; this C gets $v1/$a0/$a1. Tried: the test flipped
 * (`bolts > [8] + [10]`, 6), the sum's operands swapped (7-9), the subtraction forms (8), the
 * shared `one` in the second branch too (12).
 * 18 -> 6 (2026-11-19): `one` declared with the other locals and stored to both t->shown and the
 * loss flag (retail shares the register holding 1; a block-local `one` or `(s16)1` does not), and
 * the tally address as an integer sum `(i << 4) + (s32)tallies` (retail adds the offset first).
 * What got it from 213 words to 18: the roll globals as words of the tallies' symbol
 * (`((s32 *)D_L01_001E03C0)[8]`, the docs/wiki/Matching-Patterns.md "next word of a declared
 * global" form; as their own scalars they land in delay slots and lose the tallies aliasing, and a
 * struct cast over the same memory changes gcc's alias info, 216 words); the loop indexing
 * `&tallies[i]` so gcc doesn't reverse it; a `switch` on `shown`; the loss clamp as one `?:`
 * condition; storing the new amount before testing the old one; block locals for the roll start. */
typedef struct {
    s32 amount;      /* 0x0: the +N/-N tally */
    s32 timer;       /* 0x4: frames since the last change, -1 once rolled */
    s32 fade;        /* 0x8: frames since it appeared */
    u8 padC[0xE - 0xC];
    s16 shown;       /* 0xE: 0 off, 1 fading in, 2 on, 3 rolling in */
} Tally_00479738;
extern s32 D_L01_001D6694;
extern Tally_00479390 D_L01_001E03C0[] __attribute__((section(".sdata")));
extern u8 D_00142660[];
extern void func_L01_004792D8(s32);
extern void func_L01_004796B8(void);
extern void func_003E54E0(s32 a);

/* The roll's globals follow the two tallies and are reached as words of the tallies' symbol:
   [8] 0x1E03E0 the count shown, [9] the count when the roll started, [10] the amount rolling in,
   [11] the tally changing (-1 for none), [12] 1 for a loss. */
/* hud_bolts_roll: the shown count 0x1E03E0 trails the bolts: changes collect in a +N/-N tally
   (two, fading in over 13 frames); 51 frames after the last change it rolls in over 13 frames,
   1/14 a frame, then snaps */
void func_L01_00479738(void)
{
    Tally_00479738 *tallies;
    Tally_00479738 *t;
    s32 i;
    s32 amount;
    s32 step;
    s32 one;

    func_L01_004792D8((s32)&((s32 *)D_L01_001E03C0)[8]);
    if (D_L01_001D6694 == 5 && *(s32 *)D_00142660 < ((s32 *)D_L01_001E03C0)[8]) {
        func_L01_004796B8();
        tallies = (Tally_00479738 *)D_L01_001E03C0;
    } else {
        tallies = (Tally_00479738 *)D_L01_001E03C0;
        if (((s32 *)D_L01_001E03C0)[12] == 0 && ((s32 *)D_L01_001E03C0)[11] == -1 && *(s32 *)D_00142660 < ((s32 *)D_L01_001E03C0)[8]) {
            i = D_L01_001E03C0[0].shown != 0;
            t = (Tally_00479738 *)((i << 4) + (s32)tallies);
            one = 1;
            t->shown = one;
            t->timer = 0;
            t->fade = 0;
            t->amount = ((s32 *)D_L01_001E03C0)[8] - *(s32 *)D_00142660;
            ((s32 *)D_L01_001E03C0)[11] = i;
            ((s32 *)D_L01_001E03C0)[12] = one;
        } else if (((s32 *)D_L01_001E03C0)[12] == 0 && ((s32 *)D_L01_001E03C0)[11] == -1) {
            s32 bolts = *(s32 *)D_00142660;
            s32 rolling = ((s32 *)D_L01_001E03C0)[10];
            s32 shown = ((s32 *)D_L01_001E03C0)[8];
            if (shown + rolling < bolts) {
                i = D_L01_001E03C0[0].shown != 0;
                t = (Tally_00479738 *)((i << 4) + (s32)tallies);
                t->shown = 1;
                t->timer = 0;
                t->fade = 0;
                t->amount = 0;
                ((s32 *)D_L01_001E03C0)[11] = i;
                ((s32 *)D_L01_001E03C0)[12] = 0;
            }
        }
    }
    i = ((s32 *)D_L01_001E03C0)[11];
    if (i != -1) {
        t = (Tally_00479738 *)((i << 4) + (s32)tallies);
        if (t->shown != 3) {
            if (t->amount >= 0) {
                amount = *(s32 *)D_00142660 - ((s32 *)D_L01_001E03C0)[8] + ((s32 *)D_L01_001E03C0)[10];
                step = t->amount;
                t->amount = amount;
                if (amount != step) {
                    t->timer = 0;
                }
            }
            t->timer++;
            t->fade++;
            if (t->timer >= 51) {
                s32 rolling = t->amount;

                ((s32 *)D_L01_001E03C0)[9] = ((s32 *)D_L01_001E03C0)[8];
                ((s32 *)D_L01_001E03C0)[10] = rolling;
                t->timer = -1;
                t->shown = 3;
            }
        }
    }
    if (i != -1 || D_L01_001E03C0[0].shown == 3 || D_L01_001E03C0[1].shown == 3) {
        func_003E54E0(150);
    }
    for (i = 0; i < 2; i++) {
        t = &((Tally_00479738 *)D_L01_001E03C0)[i];
        switch (t->shown) {
        case 1:
            if (t->fade >= 13) {
                t->shown = 2;
            }
            break;
        case 3:
            t->timer++;
            step = (s32)((f32)((s32 *)D_L01_001E03C0)[10] / 14.0f);
            ((s32 *)D_L01_001E03C0)[8] += step;
            t->amount -= step;
            if (((s32 *)D_L01_001E03C0)[12] != 0 ? t->amount > 0 : t->amount < 0) {
                t->amount = 0;
            }
            if (t->timer >= 13) {
                if (((s32 *)D_L01_001E03C0)[8] != ((s32 *)D_L01_001E03C0)[9] + ((s32 *)D_L01_001E03C0)[10]) {
                    ((s32 *)D_L01_001E03C0)[8] = ((s32 *)D_L01_001E03C0)[9] + ((s32 *)D_L01_001E03C0)[10];
                }
                ((s32 *)D_L01_001E03C0)[10] = 0;
                ((s32 *)D_L01_001E03C0)[11] = -1;
                t->shown = 0;
                ((s32 *)D_L01_001E03C0)[12] = 0;
            }
            break;
        }
    }
}
