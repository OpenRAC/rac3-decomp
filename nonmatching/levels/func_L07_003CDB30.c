/* Historical evidence preserved: the earlier draft reported 44 differences with
   the owning default assembler and 32 under diagnostic @ps2as; -fcaller-saves
   had no effect. Its claim that the caller-save counter pair was unreachable
   is superseded by this retry's matched-twin evidence. The owning file also
   contains C that needs the default assembler, so its flags remain unchanged.
   Recheck: UYA_TOOLCHAIN=~/sn UYA_RUNNER=~/bin/wibo venv/bin/python
   tools/check.py nonmatching/levels/func_L07_003CDB30.c func_L07_003CDB30
   --target level_07. Flags: -O2 -G8 -fopt-stack -mno-check-zero-division.
   Stop: only the 1.8f assembler literal-pool expansion remains. */
/* PAL level 7 retry: 44 -> 28 differing words with unchanged owning flags.
   Shape adapted from matched twin func_L07_00353498. All counter allocation
   now agrees with retail. Remaining mismatch is the default assembler's
   1.8f literal-pool expansion, which shortens the function by two words.
   Caller-specific prototype below preserves retail's ignored arguments to
   func_L01_003F8470, whose shared implementation returns 1. */

extern s32 func_00382498(s32, s32);
extern s32 func_L01_003F8470(void *, s32, s32, f32);
extern void func_L07_003CD2E8(void *, s32);

s32 func_L07_003CDB30(void *arg0) {
    u8 used = 0;
    s32 count;
    s32 slot;
    s32 i;
    s32 kind;
    s32 dir;
    f32 delay;

    for (count = 3; count > 0; count--) {
        slot = func_00382498(0, count - 1);
        for (i = 0; i < 3; i++) {
            if (slot < i) continue;
            slot += (used >> i) & 1;
        }
        if (slot == 2) {
            delay = 1.5f;
            kind = 0;
            dir = -1;
        } else {
            dir = slot == 1 ? -1 : 1;
            delay = 1.8f;
            kind = 1;
        }
        if (func_L01_003F8470(arg0, kind, dir, delay) != 0) {
            func_L07_003CD2E8(arg0, slot + 0x12);
            return 1;
        }
        used = (used | (1 << slot)) & 0xFF;
    }
    return 0;
}
