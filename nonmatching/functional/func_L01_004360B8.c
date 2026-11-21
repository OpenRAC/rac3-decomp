/* exact: byte-identical at level 01 (check.py). Levels 39-53 use 0x4DE0/0x4DE4 (catalogue false fold). */
typedef struct { s32 a; s32 b; } Pair_004360B8;
typedef struct { char pad[0x4E10]; Pair_004360B8 pr[3]; } S_004360B8;

void func_L01_004360B8(u32 index) {
    if (index < 3) {
        S_004360B8 *s = (S_004360B8 *)(D_L01_001D67C8 + 0x20000);
        s->pr[index].a = 0;
        s->pr[index].b = 0;
    }
}
