/* func_L01_003F8B30: NEAR 6 diff (register swap of the two index regs). Non-volatile asm with m operands (scheduling like j-form).
   Note: file declares it void; needs u32 return (retail lbu v0 at end). */
typedef int Q_3F8B30 __attribute__((mode(TI)));
typedef struct {
    u8 gap0[0x10];
    u8 plane[0x10];
    u8 gap20[0x10];
    Q_3F8B30 *points;
    u8 gap34[0x25];
    u8 indices[3];
    u8 count;
} S_3F8B30;
typedef struct {
    u8 gap0[0x68];
    S_3F8B30 *d;
} O_3F8B30;
extern void func_L01_003F8BE0(void *o, int i, ...);
extern void func_0038D000(void *a, void *b, void *c);
extern void func_L01_003F8F48(void *o, void *p, void *q);

u32 func_L01_003F8B30(O_3F8B30 *o, u32 idx, void *dir) {
    Q_3F8B30 diff;
    S_3F8B30 *d = o->d;
    d->indices[d->count] = idx;
    d->count++;
    func_L01_003F8BE0(o, d->count - 1, dir);
    if (d->count != 1) {
        __asm__(
            "lqc2    $vf1, %2\n"
            "lqc2    $vf2, %1\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2    $vf1, %0\n"
            : "=m"(diff) : "m"(d->points[d->indices[0]]), "m"(d->points[d->indices[1]]) : "vf1", "vf2");
        func_0038D000(&diff, &diff, (u8 *)o + 0xC0);
        func_L01_003F8F48(o, d->plane, &diff);
    }
    return d->count;
}
