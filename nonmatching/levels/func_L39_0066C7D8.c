/* func_L39_0066C7D8: near miss (p2 w2): 2 diff with --mode S --as ps2as (sll/lui order swapped). Not matchable under the file flags (default mode, default as).
   Table lookup func_00381FF0(D_L39_002462E8[a0]); retail uses explicit lui/addiu/addu, lw in delay slot.
   Left: scheduling of sll vs lui; file needs a split-addresses+ps2as profile. */
extern int D_L39_002462E8[];
extern void func_00381FF0(int);
void func_L39_0066C7D8(int a0) {
 func_00381FF0(D_L39_002462E8[a0]); 
}
