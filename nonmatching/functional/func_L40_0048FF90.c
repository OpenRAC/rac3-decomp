/* functional: high. Appends one entry (16-byte position, tag, vertical range below\/above) to the 0x60-byte entry table D_L40_002926E0 at index D_L40_00248628, clears its 8 neighbour links (-1) and 8 flags, and returns the new index; reports via func_L01_004A0A78 when the table (0x100) is full. Compiles near-exact; only the two float register roles are swapped. */
typedef int Q_0048FF90 __attribute__((mode(TI)));

typedef struct S_0048FF90 {
    Q_0048FF90 pos;
    float f10;
    float f14;
    float f18;
    int i1C;
    short h20[8];
    unsigned char pad30[0x20];
    unsigned char b50[8];
    unsigned char pad58[8];
} S_0048FF90 __attribute__((aligned(16)));

extern int D_L40_00248628;
extern char D_L40_002433B8[];
extern S_0048FF90 D_L40_002926E0[];
extern void func_L01_004A0A78(char *);

int func_L40_0048FF90(Q_0048FF90 *pos, int tag, float below, float above) {
    S_0048FF90 *e;
    int i;
    int n;

    if (D_L40_00248628 >= 0x100) {
        func_L01_004A0A78(D_L40_002433B8);
    }
    e = &D_L40_002926E0[D_L40_00248628];
    e->pos = *pos;
    e->i1C = tag;
    e->f10 = -1.0f;
    e->f18 = *(float *)((char *)e + 8) + above;
    e->f14 = *(float *)((char *)e + 8) - below;
    for (i = 0; i < 8; i++) {
        e->h20[i] = -1;
        e->b50[i] = 0;
    }
    n = D_L40_00248628;
    D_L40_00248628 = n + 1;
    return n;
}
