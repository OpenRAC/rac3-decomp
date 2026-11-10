/* func_L39_004F16B0: near miss, 1 diff (Sonnet w1, p2)
   rac2 func_L20_00449AD8
   Left: only diff is a 0xCDCDCDCD fill word retail counts inside the 16 bytes (catalogue size); body matches
*/
int func_L39_004F16B0(char *a0)
{
    char *p = *(char **)(a0 + 4);
    return *(int *)(p + 4);
}
