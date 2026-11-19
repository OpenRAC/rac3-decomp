/* functional: high. Debug-draw loop: for every entry of table D_L40_00290EE0 (count D_L40_00248620) walks its closed polyline (vec array of 16-byte points, n points; last point wraps to first via modulo), lifts each end point by 0.05 in z and calls func_L40_00491768 (draw line, colour 0x6000FFFF, width 0.2). Draft from nonmatching/levels re-verified against the PAL asm; compiles, near-exact. */
typedef int Q_00491130 __attribute__((mode(TI)));

typedef struct V4_00491130 {
    float x, y, z, w;
} V4_00491130 __attribute__((aligned(16)));

typedef struct Ent_00491130 {
    unsigned char pad0[16];
    unsigned char *vec;
    int n;
    unsigned char pad1[8];
} Ent_00491130;

extern int D_L40_00248620;
extern Ent_00491130 D_L40_00290EE0[];
extern void func_L40_00491768(void *, void *, int, float);

void func_L40_00491130(void) {
    Ent_00491130 *e;
    V4_00491130 l1;
    V4_00491130 l2;
    int i;
    int j;
    int k;

    for (i = 0; i < D_L40_00248620; i++) {
        if (D_L40_00290EE0[i].n - 1 > 0) {
            e = &D_L40_00290EE0[i];
            j = 0;
            do {
                *(Q_00491130 *)&l1 = *(Q_00491130 *)(e->vec + j * 16);
                l1.z = l1.z + 0.05f;
                k = (j + 1) % e->n;
                *(Q_00491130 *)&l2 = *(Q_00491130 *)(e->vec + k * 16);
                l2.z = l2.z + 0.05f;
                func_L40_00491768(&l1, &l2, 0x6000FFFF, 0.2f);
                j++;
            } while (j < e->n - 1);
        }
    }
}
