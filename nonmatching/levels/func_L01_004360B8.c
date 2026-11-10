/* func_L01_004360B8: MATCH at 34 places (L01..L38) but L39..L53 differ by 2 diff: retail there is 0x4de0/0x4de4 and a different gp slot (variant, needs own copy).
   w6 p2w1 hand draft. */
extern char *D_L01_001D67C8 __attribute__((section(".sdata")));
typedef struct { int a; int b; } Pair;
typedef struct { char pad[0x4E10]; Pair pr[3]; } S;
void func_L01_004360B8(unsigned int index) {
    if (index < 3) {
        S *s = (S *)(D_L01_001D67C8 + 0x20000);
        s->pr[index].a = 0;
        s->pr[index].b = 0;
    }
}
