/* Near miss of func_003A5AF8 with its file's own flags: tools/check.py reports 39 diff
   (the US draft it started from: 87).
   What differs: addressing form of the six small globals: retail has `lui $a0, 0x1d`
   immediately followed by `lh $a0, 0x5bb6($a0)` (same register, adjacent), while gcc 2.95.3
   with this file's flags (`-G8`, default `bin/ee-as.exe`) emits the split-address form `lui
   $a2, 0x1d` + `lh $a0, 0x5bb6($a2)` — the `lui` is hoisted away from its load, lands in a
   different register, and the argument load is then pushed into the previous call's delay
   slot, so 39 of 113 words differ (the prologue, the whole loop and the epilogue match).
   Retail's shape is the one the SN assembler (Ps2EeAs, `@ps2as`) produces by...
*/

/* US draft of func_003A5AF8 (rac3-uya-decomp func_003A59B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override).

   Retail reaches the six small globals with lui/%lo, so they are declared unsized
   (an unsized array is never small data).  Retail computes the high half again for
   every use of a global it reads twice (D_001D5BB8, D_001D5BBA, D_001D5BBC), while gcc
   would share one %hi across both uses and keep it alive in a saved register across the
   calls, so each use gets its own alias name. */


/* localdecomp:start func_003A5AF8 */
typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A5AF8;
extern u32 D_001D54D0_003A5AF8[];
extern s16 D_001D5BB0_003A5AF8[];
extern s16 D_001D5BB6_003A5AF8[];
extern s16 D_001D5BB8_003A5AF8[];
extern s16 D_001D5BB8_003A5AF8_b[];
extern s16 D_001D5BBA_003A5AF8[];
extern s16 D_001D5BBA_003A5AF8_b[];
extern s16 D_001D5BBC_003A5AF8[];
extern s16 D_001D5BBC_003A5AF8_b[];
extern O_3A02D8 *func_003C2868_003A5AF8(s32, s32);
extern void func_003A5AA0(void);
void func_003A5AF8(O_3A02D8 *o) {
    s16 *k;
    O_3A02D8 **t;
    O_3A02D8 *p;
    s32 i;
    if (o == 0) o = D_0016C580_003A5AF8.f0;
    func_003A5AA0();
    o->f30 = 0xFF;
    k = &D_001D5BB0_003A5AF8[(D_001D54D0_003A5AF8[0] >> 2) & 3];
    t = (O_3A02D8 **)D_0022D8B0;
    t[0] = func_003C2868_003A5AF8(*k, 0x80);
    t[1] = p = func_003C2868_003A5AF8(*k, 0x80);
    p->f34 |= 0x8000;
    t[2] = func_003C2868_003A5AF8(D_001D5BB6_003A5AF8[0], 0x80);
    t[3] = func_003C2868_003A5AF8(D_001D5BB8_003A5AF8[0], 0x80);
    t[4] = p = func_003C2868_003A5AF8(D_001D5BB8_003A5AF8_b[0], 0x80);
    p->f34 |= 0x8000;
    t[5] = func_003C2868_003A5AF8(D_001D5BBA_003A5AF8[0], 0x80);
    t[6] = p = func_003C2868_003A5AF8(D_001D5BBA_003A5AF8_b[0], 0x80);
    p->f34 |= 0x8000;
    t[7] = func_003C2868_003A5AF8(D_001D5BBC_003A5AF8[0], 0x80);
    t[8] = p = func_003C2868_003A5AF8(D_001D5BBC_003A5AF8_b[0], 0x80);
    p->f34 |= 0x8000;
    for (i = 0; t[i] != 0; i++) {
        if (t[i]->f63 != 0) t[i]->f63 = 8;
        t[i]->f34 |= 0x124;
        t[i]->f32 = 0x1FF;
        t[i]->f68->f8 = (u8 *)t[i]->f68 + 0x30;
    }
    o->f34 |= 0x20;
    o->f68->f8 = (u8 *)o->f68 + 0x30;
}
/* localdecomp:end func_003A5AF8 */
