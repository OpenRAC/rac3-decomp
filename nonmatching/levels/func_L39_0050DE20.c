/* func_L39_0050DE20: NEAR 19 (p2w1 w7). 76 bytes, 1 level, file src/levels/39_multiplayer_menu/L39_0050DC88.c.
   Structure right: if (p) { tmp[0]=*p>>8; tmp[1]=*(u8*)p; b={tmp,2}; r=func_L39_0050DFA0(a0,a1,a2,&b);} return r;
   Diff: ours spills a1/a2 to t0/t1 and uses them as temps; retail leaves a0-a2 alone (temps in v1/t0/t1) and keeps p in t0. */
typedef struct { unsigned char *data; int len; } Buf;
extern int func_L39_0050DFA0(int, int, int, Buf *);

int func_L39_0050DE20(int a0, int a1, int a2, unsigned short *p)
{
    Buf b;
    unsigned char tmp[2];
    int r = 0;
    if (p != 0) {
        tmp[0] = *p >> 8;
        tmp[1] = *(unsigned char *)p;
        b.data = tmp;
        b.len = 2;
        r = func_L39_0050DFA0(a0, a1, a2, &b);
    }
    return r;
}
