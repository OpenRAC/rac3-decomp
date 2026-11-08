/* Near miss, ported from rac4-decomp's func_0040B730 (cross-game near pair). NEAR: 4 diff: use unsigned long (u64 is 128-bit); ldl/ldr/sdl/sdr right but value reg $v1 vs retail $v0; 5 wordings same */
typedef struct __attribute__((packed)) {
    unsigned long v;
} S_50DBB0;

s32 func_L39_0050DBB0(u8 *src, u8 *dst) {
    ((S_50DBB0 *)dst)->v = ((S_50DBB0 *)(src + 0xC))->v;
    return 0;
}
