/* func_0038E0E8 (PAL frontbin, src/frontbin/38E0A8.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division -mno-split-addresses @ps2as), ported from boot_elf's func_0038E4C8
   (src/boot_elf/text/38E488.c). It matches with split addresses, as 38E488.c has, and only so:
   - with this file's -mno-split-addresses it is 7 diff (tools/check.py): retail interleaves the
     `lui`/`addiu` halves of the two address pairs, the flag builds each as one adjacent `la` pair;
   - with `--mode S` it is MATCH in the build once LINKER_REMNANT(func_0038E130) goes: that word is
     its delay slot (`addiu $sp, $sp, 0x10`), and config/inventory.tsv gives the function 76 bytes,
     that word included (check.py alone shows it as 1 diff).
   38E0A8.c as a whole cannot take split addresses: without -mno-split-addresses the frontbin build
   grows by 24 bytes (NO MATCH; tested 2026-11-21 with this C and func_0038FA18's in place).
   The cut it needs: a file at 0x38E138 (func_0038E138 onwards) with 38E0A8.c's present flag line,
   and 38E0A8.c (0x38E0A8-0x38E138) without -mno-split-addresses. That cut moves the markers of
   another contributor's claimed functions (func_0038E150, func_0038E7E8, func_0038F078, and with
   them func_00391328, func_003914A0, func_00391678, func_00392260) into the new file, so it is not
   made. */
/* localdecomp:start func_0038E0E8 */
extern u8 D_00143E40[];
extern u8 D_00144440[];
extern u8 D_0014A240[];
extern u8 D_0014A840[];
extern void func_0038DE18(s32, u8 *, u8 *);
void func_0038E0E8(void) {
    func_0038DE18(0, D_00144440, D_00143E40);
    func_0038DE18(1, D_0014A840, D_0014A240);
    func_0038E150(0);
}
/* localdecomp:end func_0038E0E8 */
