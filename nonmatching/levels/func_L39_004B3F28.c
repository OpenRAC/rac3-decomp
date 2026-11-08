/* func_L39_004B3F28: near miss 5 diff (w2 p2w2). 92 bytes, 1 level, src/levels/39_multiplayer_menu/L39_004B3230.c
   Twin func_002A0430; written from asm (portrun was wrong). Remaining: addiu -11 / lw saved scheduled around beqz, lui reg for D load.
   Return codes -11 (null), -8 (D==0), 0 (copied 16 bytes, restored +0xC). */
extern int D_L39_00453FAC[];
extern u8 D_L39_004646B0[];

int func_L39_004B3F28(u8 *p)
{
    unsigned int i;
    int saved;
    int ret = -11;
    if (p != 0) {
        saved = *(int *)(p + 0xC);
        ret = -8;
        if (D_L39_00453FAC[0] != 0) {
            {u8 *d = p; u8 *s = D_L39_004646B0; for (i = 0; i < 16; i++) d[i] = s[i]; }
            *(int *)(p + 0xC) = saved;
            ret = 0;
        }
    }
    return ret;
}
