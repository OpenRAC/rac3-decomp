/* func_0038E0E8 (PAL frontbin, src/frontbin/38E0A8.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division -mno-split-addresses), written from the assembly 2026-11-16.
   Not landable as is, for two reasons:
   - The boundary is wrong: retail's function ends with `jr $31; addiu $sp, $sp, 0x10`, but the
     delay-slot word and its alignment nop (0x38E130) are marked LINKER_REMNANT(func_0038E130). The
     C below compiles to the 0x48 bytes plus that delay slot, so the remnant has to become part of
     this function (inventory, splat split) first.
   - Retail interleaves the `lui`/`addiu` halves of the two address pairs (split addresses): with
     `--mode S` the C is MATCH but for the delay slot above; with this file's -mno-split-addresses it
     is 7 diff (each address as one adjacent `la` pair). The file would have to be cut here. */
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
