/* func_L01_003A4910: p2 near miss (w8), 5 diff. rac2 twin func_L18_003F8E80.
   Retail computes sltiu into $v0 then 'move $a1,$v0; jr; move $v0,$a1'; we emit sltiu straight into $a1.
   Tried: r=cmp, ternary, local temps, ^0x10 forms; all 5 diff. */
int func_L01_003A4910(unsigned char *s) { int r = 0; if (s[0x95] == 6) { int t = s[0x20] == 0x10; r = t; } return r; }
