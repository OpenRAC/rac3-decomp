/* Near miss for func_L01_00337E10 (no readable name yet; it blends the wrench object's moby
   to sequence 11 in hero state 0x37, else from sequences 11, 19 and 18 back to 1), file
   src/levels/shared/L01_003326A8.c: tools/check.py nonmatching/levels/func_L01_00337E10.c
   func_L01_00337E10. One instruction short in the second branch (22 words differ, most from
   the shift): retail loads the sequence byte into $v0, masks it into $a0 for the three
   compares (andi $a0, $v0, 0xFF) and copies the unmasked value to $a2 for the `!= 1` test
   (move $a2, $v0 in the first beq's delay slot); here the load goes to $a0 and the mask to
   $v1 with no copy. Same bytes with an s32 and a u8 copy, a (u8) cast in the compares, a
   switch, a reread of moby[0x43] and an early return. */
extern u8 D_001A4BE0[];
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L01_00337E10(u8 *moby)
{
    s32 seq;

    if (*(s32 *)(D_001A4BE0 + 0x25C4) == 0x37) {
        if (moby[0x43] != 11) {
            func_003C3A10(moby, 11, 0, 6);
        }
        return;
    }
    seq = moby[0x43];
    if ((u8)seq == 11 || (u8)seq == 19 || (u8)seq == 18) {
        if (seq != 1) {
            func_003C3A10(moby, 1, 0, 14);
        }
    }
}
