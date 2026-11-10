/* Near miss, ported from rac4-decomp's func_003F6470 (cross-game near pair). NEAR: 11 diff: retail keeps b copy in a3 and recomputes b+i (no strength reduction); 8 wordings same bytes */
unsigned char *func_L39_004D0D68(unsigned char *a, unsigned char *b)
{
    int i;
    for (i = 0; i < 8; i++)
        b[i] ^= a[i];
    return b;
}
