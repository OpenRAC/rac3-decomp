/* near miss (level 5, Daxx): 23 differences: idx*0x460 mult kept in a0 by retail, source address of the lq built as addu then lq 0x190 where gcc builds addiu then lq 0 */
#include "common.h"

/* localdecomp:start func_L05_003E63C0 */
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
    Slot_003E63C0 *slot = &D_L05_001E2700[idx];
    char *ship = slot->ship;
    char *motion = *(char **)(ship + 0x70);
    char *pad = motion + 0xE0;

    *(u8 *)(ship + 0x88) = state;
    if (state == 2) {
        *(void **)(pad + 4) = arg;
        *(void **)(motion + 0xE0) = arg;
    } else if (state == 3) {
        char *src = (char *)&D_L05_001E2700[idx] + 0x190;
        *(u128_t *)(motion + 0x110) = *(u128_t *)src;
        func_L01_003F5FC0(motion + 0xFC, &D_L05_001E2700[*(int *)(ship + 0x94)], src);
        *(void **)(pad + 4) = arg;
        *(void **)(motion + 0xE0) = arg;
    }
}
/* localdecomp:end func_L05_003E63C0 */
