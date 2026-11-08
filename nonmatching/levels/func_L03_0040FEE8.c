/* func_L03_0040FEE8: near miss, prep by Sonnet worker w5 (wave 3)
   Matches every instruction except the last jr delay slot (catalogue size 280 omits it): 1 diff, from rac2 func_00290B48.
   Levels: 03 only; flags -O2 -G8 -fopt-stack -mno-check-zero-division. */
extern int D_L03_001E9140[];
extern int D_L03_001E09F0;
__asm__(".extern D_L03_001E09F0, 16");
extern char D_510717[];
extern char D_1FF8000[];
extern char D_1FFC000[];
extern void func_11A264(void *, int, int);

void func_L03_0040FEE8(void)
{
    int *state = D_L03_001E9140;
    unsigned int start, size;

    func_11A264(state, 0, 0xA0);
    state[0] = 0;
    state[1] = 0x100000;
    start = (unsigned int)D_510717 & ~0xFFF;
    state[2] = start;
    state[3] = start;
    size = D_L03_001E09F0;
    state[4] = state[3] + size;
    state[5] = state[4] + size;
    state[6] = state[5] + state[1];
    state[0x88 / 4] = (unsigned int)D_1FF8000;
    state[0x84 / 4] = state[0x88 / 4] - 0x40000;
    state[0x80 / 4] = state[0x84 / 4] - 0x64000;
    state[0x7C / 4] = state[0x80 / 4];
    state[0x78 / 4] = state[0x7C / 4] - 0x2C000;
    state[0x74 / 4] = state[0x78 / 4] - 0x8000;
    state[0x68 / 4] = state[6];
    state[0x8C / 4] = (unsigned int)D_1FFC000;
    state[0x70 / 4] = state[0x74 / 4] - 0x14000;
    state[0x6C / 4] = state[0x70 / 4];
    state[0x90 / 4] = 0x07000000;
    state[0x94 / 4] = 0x07100000;
    state[0x98 / 4] = 0x07180000;
    state[0x9C / 4] = 0x07200000;
}
