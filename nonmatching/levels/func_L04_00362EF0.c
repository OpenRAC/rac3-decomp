/* func_L04_00362EF0: near miss, 5 diff (Sonnet w1, p2)
   rac2 func_L18_003F8E80
   Left: result lives in $a1 then moves to $v0 (extra move, branch target 0x18)
*/
unsigned char func_L04_00362EF0(unsigned char *s)
{
    int r = 0;
    if (s[0x95] == 7) {
        r = s[0x20] == 0x1A;
    }
    return r;
}
