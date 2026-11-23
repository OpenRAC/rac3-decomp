/* functional: high. Compiles at level 5 with 10 differing instructions (register/scheduling only); behaviour checked against retail asm: state 2 and 3 set the motion callback pair, state 3 also copies a quadword and calls the shared transform helper first. */
typedef int u128_t __attribute__((mode(TI)));

typedef struct Slot_003E63C0 {
    u8 pad00[0x50];
    char *ship;
    u8 pad54[0x460 - 0x54];
} Slot_003E63C0;

extern Slot_003E63C0 D_L05_001E2700[];
extern void func_L01_003F5FC0(void *, void *, void *);

void func_L05_003E63C0(int idx, int state, void *arg)
{
    int off = idx * 0x460;
    char *ship = *(char **)((char *)D_L05_001E2700 + off + 0x50);
    char *motion = *(char **)(ship + 0x70);
    char *pad = motion + 0xE0;
    *(u8 *)(ship + 0x88) = state;
    if (state == 2) {
        *(void **)(pad + 4) = arg;
        *(void **)(motion + 0xE0) = arg;
    } else if (state == 3) {
        char *p = (char *)D_L05_001E2700 + off;
        *(u128_t *)(motion + 0x110) = *(u128_t *)(p + 0x190);
        func_L01_003F5FC0(motion + 0xFC, &D_L05_001E2700[*(int *)(ship + 0x94)], p + 0x190);
        *(void **)(pad + 4) = arg;
        *(void **)(motion + 0xE0) = arg;
    }
}
