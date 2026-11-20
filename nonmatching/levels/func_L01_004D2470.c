/* func_L01_004D2470: near miss (Sonnet w4 p2w3): NEAR 1
   Size 40 bytes. MATCH at 01..38 places; false fold: levels 39-53 use 0x45E0 instead of 0x4610
   Left for lead: see note.
   Round 12: measured again at levels 01 and 39: MATCH at 01 (and the other places up to 38), 1 diff at 39 (addiu $a1, $a1,
   0x4610 against retail's 0x45e0). Same hash and callee-masked bytes, different immediate: a catalogue split. */
void func_L01_004D2470(void *p, s32 i) {
    func_003ACBC0((u8 *)p + (i * 0x230 + 0x4610));
}
