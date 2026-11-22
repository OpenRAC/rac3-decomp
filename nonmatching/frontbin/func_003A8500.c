/* func_003A8500 (frontbin): near miss, 48 differences (tools/check.py) with its file's flags
   (src/frontbin/3A8308.c, -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as),
   measured on upstream 6de86dfe (NM-FE5, 2026-11-22; FE-1's draft measures 62 there).

   It binds the SIF RPC client at D_001D4B08 to server 0x11 (func_00122630; a negative result hangs),
   polls func_00122A10 until it is free, retries after a 0xFFFF-count delay while the client's word
   at +0x24 is 0, then calls function 2 for three words and clears the 64 16-byte entries of
   D_0022DF20 (the tail is func_003A8630's body). Compiled code, not hand-written. Its jr delay slot
   (addiu $sp) is the 4-byte LINKER_REMNANT func_003A8628, which goes when this becomes C (one
   inherent difference until then). Its boot_elf twin func_003A8900 is a 300-byte LINKER_REMNANT.

   What this form fixes (FE-1's blocker, "&D_001D4B08 rebuilt per use"): declaring the client
   small data, `__attribute__((section(".sdata")))` (docs/wiki/Matching-Patterns.md, "Declarations
   and address forms (round 3)"), makes gcc emit one `la` macro that Ps2EeAs expands to retail's
   adjacent lui/addiu at every use; every larger or unsized declaration let gcse PRE and cse keep
   the address in $s0. The `while (1) { ... break; }` form makes reorg fill the `serve` branch's
   delay slot from the fall-through, as retail does (a goto loop fills it from the target).
   The prologue, the bind, the hang loop and the RPC call's argument setup are then retail's.

   What still differs:
   1. Loop padding (31 of the 48): the poll loop holds the `la` macro, which tools/asm_filter.py's
      insn_count cannot count, so the filter leaves the loop to Ps2EeAs, which pads it to 7 words
      where retail has 6; every later word is shifted. With insn_count counting an `la` of a
      symbol that is neither small nor defined as two words under @ps2as reorder mode (the rule
      it already applies to loads and stores), the same C measures 17 (diagnostic only; the tool
      was not changed).
   2. Registers (the 17): the delay counter is $v0 with -1 in $v1, where retail has $a2 and $v0
      (one counter shared with the clear loop gives -1 in $v0 but the counter in $a1, 19); after
      the RPC call retail loads r[0] into $a1 and the table pointer into $v0, gcc picks $a0/$a1.
      The order of the five stores in the source does not change the scheduled order (72 orders
      tried). */

typedef struct { u8 pad0[0x24]; s32 serve; } Cd_3A8500;
extern Cd_3A8500 D_001D4B08 __attribute__((section(".sdata")));
extern s32 D_001D4B00;
extern s32 D_001D4B04;
extern s32 D_001D4B30;
extern s32 D_001D4B34;
extern s32 D_001D4B38;
extern s32 D_0022DF20[256];
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122A10(void *);
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
void func_003A8500(void) {
    s32 r[4];
    s32 i;
    s32 n;
    s32 *p;
    func_00121FE8(0);
    while (1) {
        if (func_00122630(&D_001D4B08, 0x11, 1) < 0) {
            while (1) {
            }
        }
        while (func_00122A10(&D_001D4B08) != 0) {
        }
        if (D_001D4B08.serve != 0) {
            break;
        }
        n = 0xFFFF;
        do {
            n--;
        } while (n != -1);
    }
    func_00122810(&D_001D4B08, 2, 0, 0, 0, r, 0x10, 0, 0);
    D_001D4B00 = r[0];
    D_001D4B04 = r[1];
    D_001D4B38 = r[2];
    D_001D4B34 = 0;
    D_001D4B30 = D_001D4B00;
    p = D_0022DF20;
    for (i = 0x3F; i >= 0; i--) {
        p[0] = 0;
        p[1] = 0;
        p += 4;
    }
}
