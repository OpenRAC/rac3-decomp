/* Near miss for func_L01_003355B8 (no readable name yet; as func_L01_003352B8, aimed at the
   0x100-byte record at D_L01_001E001C that cfg +0x60 names, or at the hero's moby for -1),
   file src/levels/shared/L01_003326A8.c (its context: u128_t, and the earlier blocks'
   externs): tools/check.py nonmatching/levels/func_L01_003355B8.c func_L01_003355B8.
   13 words differ, register allocation only, then one store's place: retail loads the index
   into $v1 and the record base into $a0 (here $a0 and $v1), and puts the first
   sq $v0, 0x4A0($s1) right after its lq (here after the argument moves). Same bytes with the
   index in a local, the branches swapped, a ?:, &D[i * 256], an integer sum and a 0x100-byte
   record type. */
extern u8 D_001A4BE0[];
extern u8 *D_L01_001E001C;
extern void func_L01_00334358(void *, void *, f32);

/* As func_L01_003352B8, aimed at the record cfg +0x60 names (0x100-byte records at
 * D_L01_001E001C) or, with none (-1), at the hero's moby. */
s32 func_L01_003355B8(u8 *a0, u8 *b, u8 *c, u8 *d, s32 t0, u8 *cfg)
{
    u8 *t;
    s32 idx = *(s32 *)(cfg + 0x60);

    if (idx != -1) {
        t = D_L01_001E001C + (idx << 8);
    } else {
        t = *(u8 **)(D_001A4BE0 + 0x25C0);
    }
    *(u128_t *)(d + 0x4A0) = *(u128_t *)(t + 0x10);
    *(u8 **)(d + 0x440) = t;
    *(u128_t *)(d + 0x400) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x3F0) = *(u128_t *)(t + 0x10);
    *(u128_t *)(d + 0x410) = *(u128_t *)(t + 0x10);
    func_L01_00334358(c, d, 12.0f);
    *(u128_t *)(b + 0x80) = *(u128_t *)(c + 0x10);
    *(u128_t *)(d + 0x4A0) = *(u128_t *)(t + 0x10);
    return 0;
}
