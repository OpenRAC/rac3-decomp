/* near miss (level 7, Annihilation Nation), 2026-11-15: newly reconstructed baseline (no saved draft or
   history). 30 -> 1 differing word with the owning file's flags
   -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as; exact 116 bytes.
   Residual +0x5C: addu a0,a3,v1 instead of retail's addu a0,v1,a3. Same
   open problem as func_L07_00353D98 / func_L07_003A63E8 ("Two-array copy
   address order remains open"). No divs_nops row needed. */
typedef int Q_3CE330 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x2C0];
    Q_3CE330 a[10];
    Q_3CE330 b[10];
    u8 pad400[0x8];
    u8 head;
    u8 count;
} S_3CE330;

void func_L07_003CE330(u8 *arg0, Q_3CE330 *arg1, Q_3CE330 *arg2) {
    S_3CE330 *s = *(S_3CE330 **)(arg0 + 0x68);
    int i;

    s->count++;
    if (s->count > 10) {
        s->head = (s->head + 1) % 10;
        s->count = 10;
    }
    i = (s->head + s->count - 1) % 10;
    s->a[i] = *arg1;
    s->b[i] = *arg2;
}
