/* Near miss of func_0039EED8 with its file's own flags: tools/check.py reports 2 diff
   (the US draft it started from: 8).
   What differs: Only 2 instructions differ: the base of the two field stores is built as "lui
   $v1, 0x16" + "ori $v1, $v1, 0xc580" instead of retail's "lui $v1, 0x17" + "addiu $v1, $v1,
   -0x3a80". Everything else (the lui $at / sw lo($at) stores to 0x1D4B60/0x1D4B90/0x1D4BA0,
   $v0 = -1, the store order and the 0x30 store in the jr delay slot) matches. The signed split
   (addiu) is only produced for a symbol reference (D_0016C580), but with the symbol this
   compiler allocates $v0 to the base and $v1 to the constant and rotates the two same-base
   stores, giving 12 diffs instead of 2.
*/

/* func_0039EED8 - PAL retail candidate (best attempt: 2 instructions differ).

   Retail (48 bytes):
       addiu $v0, $zero, -1
       lui   $v1, %hi(D_16C580)
       addiu $v1, $v1, %lo(D_16C580)     <- lui 0x17 / addiu -0x3a80
       lui   $at, 0x1d
       sw    $v0, 0x4b60($at)
       sw    $v0, 0x18($v1)
       lui   $at, 0x1d
       sw    $v0, 0x4b90($at)
       lui   $at, 0x1d
       sw    $v0, 0x4ba0($at)
       jr    $ra
       sw    $v0, 0x30($v1)

   The three globals are reached through literal addresses: a store to a
   literal constant address compiles to "lui $at / sw lo($at)", exactly what
   retail has, while a store to a named symbol lands in a general register
   ($a0/$a1/$a2) in split-address mode.

   What still differs: the base of the two field stores.  With the named
   symbol D_0016C580 this compiler emits the retail "lui $v1, %hi(D) +
   addiu $v1, $v1, %lo(D)" (lui 0x17 / addiu -0x3a80), but then it allocates
   $v0 to the base and $v1 to the constant -1, and it rotates the two
   same-base stores (0x30 before 0x18) leaving a nop in the delay slot
   (12 diffs).  With the literal address 0x16C580 the register allocation and
   the store order are exactly retail's, but the constant is split unsigned
   ("lui $v1, 0x16" + "ori $v1, $v1, 0xc580"); only a symbol reference gives
   the signed split ("lui 0x17" + "addiu -0x3a80") the retail bytes use. */

void func_0039EED8(void)
{
  u8 *p;
  p = (u8 *)0x16C580;
  *(s32 *)0x1D4B60 = -1;
  *(s32 *)(p + 0x18) = -1;
  *(s32 *)0x1D4B90 = -1;
  *(s32 *)0x1D4BA0 = -1;
  *(s32 *)(p + 0x30) = -1;
}
