/* functional: high. Initialises the level's entry slots (up to 64) from two parallel arrays (pointer, count), sets float 5.0 at +0xC of each 16-byte element, calls func_L40_004904B8 per slot, then fills index tables 0..127 (stride 0x20, +0x1C) and 0..63 (stride 0x40, +0x30). The retail $gp slots 0x660/0x668 are D_L40_00248620/D_L40_00248628 (level gp 0x247FC0). Compiles; only frame size and register use differ. */
typedef struct E_0048FDE8 {
    unsigned char pad00[0x10];
    unsigned char *p10;
    int n14;
    float f18;
    float f1C;
} E_0048FDE8;

extern int D_L40_00248620;
extern int D_L40_00248624;
extern int D_L40_00248628;
extern char D_L40_00243390[];
extern E_0048FDE8 D_L40_00290EE0[];
extern unsigned char D_L40_002916E0[];
extern unsigned char D_L40_002986E0[];
extern void func_L01_004A0A78(char *);
extern void func_L40_004904B8(unsigned char *, int, unsigned char *, float *, float *);

void func_L40_0048FDE8(unsigned char **arg0, int *arg1, int n) {
    int i;
    int j;
    int k;
    E_0048FDE8 *e;

    D_L40_00248620 = 0;
    D_L40_00248624 = 0;
    D_L40_00248628 = 0;
    if (n >= 0x40) {
        func_L01_004A0A78(D_L40_00243390);
    }
    for (i = 0; i < n; i++) {
        e = &D_L40_00290EE0[i];
        e->p10 = arg0[i];
        e->n14 = arg1[i];
        for (j = 0; j < arg1[i]; j++) {
            *(float *)(e->p10 + j * 16 + 0xC) = 5.0f;
        }
        func_L40_004904B8(arg0[i], arg1[i], (unsigned char *)e, &e->f18, &e->f1C);
        D_L40_00248620 = D_L40_00248620 + 1;
    }
    for (k = 0x7F; k >= 0; k--) {
        *(int *)(D_L40_002916E0 + k * 0x20 + 0x1C) = k;
    }
    for (k = 0x3F; k >= 0; k--) {
        *(int *)(D_L40_002986E0 + k * 0x40 + 0x30) = k;
    }
}
