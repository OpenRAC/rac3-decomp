/* functional: high. Retail adds the 3 lanes of obj+0x10 into dst after func_0038D000(dst, D_001DC860_sda, obj+0xC0) (vadd.xyz via VU0); written as plain float adds, the w lane stays untouched like vadd.xyz. Check: calls and arguments match retail, bytes differ (VU0 vs scalar). */
extern u8 D_001DC860_sda[8];
__asm__(".extern D_001DC860_sda, 8");
extern void func_0038D000(void *, void *, void *);

void func_L01_0031D188(u8 *obj, f32 *dst) {
    f32 *src = (f32 *)(obj + 0x10);
    func_0038D000(dst, D_001DC860_sda, obj + 0xC0);
    dst[0] += src[0];
    dst[1] += src[1];
    dst[2] += src[2];
}
