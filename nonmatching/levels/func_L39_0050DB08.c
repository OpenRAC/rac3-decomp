/* func_L39_0050DB08: near miss 2 diff (w6 p2w1), file src/levels/39_multiplayer_menu/L39_0050D5B0.c
   Only the store order differs: retail sw zero,4(a1) before sw D,(a0).
   No rac2 twin used; 48 orders tried. */
extern char D_L39_0046F410[];
typedef struct N { char *a; struct N *b; } N;
void func_L39_0050DB08(N *a, N *b) { a->a=D_L39_0046F410;a->b=b;b->b=0;b->a=0; }
