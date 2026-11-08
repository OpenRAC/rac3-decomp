/* func_L39_004FA538: near miss 10 diff (w2 p2w2). 116 bytes, 1 level. Written from asm; port was wrong. Remaining: retail frame 0x50 with s0/s1/ra saved at 0x20/0x30/0x40 (16 spacing), ours 0x40 with 8 spacing. */
extern char D_L39_00478E58[];
extern char D_L39_00478E60[];
extern char D_L39_00478E68[];
extern char D_L39_00478E78[];
extern void func_00120048(char *, char *, ...);
extern void func_L39_004DE348(int, char *, char *, char *, char *);

void func_L39_004FA538(int a0, int a1)
{
    char buf0[16];
    char buf1[16];
    func_00120048(buf0, D_L39_00478E58, a0);
    func_00120048(buf1, D_L39_00478E60, a1);
    func_L39_004DE348(4, D_L39_00478E68, buf0, D_L39_00478E78, buf1);
}
