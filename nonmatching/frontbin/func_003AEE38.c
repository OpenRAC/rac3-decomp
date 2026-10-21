/* US draft of func_003AEE38 (rac3-uya-decomp func_003A9890, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AEE38 */
extern u8 *D_001D5C78_003AEE38;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
__asm__(".extern D_001D5C78_003AEE38, 16");
__asm__(".extern D_001D545C, 16");
extern s32 func_003ABDD8();
extern void func_003AB4A0();
extern void func_003ABD18();
extern void func_003ABBE0();
extern void func_003ABBE8();
extern void func_003AB530();
extern void func_003AB548();
extern void func_003ABD30();
extern void func_003ABD10();
extern void func_003AD7D8();
extern void func_003ABFA8();
extern void func_003AB778();
extern f32 *func_003AB820();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
void func_003AEE38(S_3A9890 *sx, s32 a1, s32 a2) {
    u8 *s = (u8 *)sx;
    u8 *b;
    u8 *q;
    s32 i;
    s32 k;
    u32 j;
    f32 *r;
    for (k = 0; k < 4; k++) {
        sx->a[k] = func_003ABDD8(D_001D5C78_003AEE38 + 0x7090, 0xC);
        sx->b[k] = func_003ABDD8(D_001D5C78_003AEE38 + 0x7090, 0xD);
    }
    if (D_001D545C != -2) {
        for (i = 0; i < 4; i++) {
            b = s + i * 0x618;
            j = 0;
            do {
                func_003AB4A0(b, 0x16, 1, D_001D8730, a2);
                func_003ABD18(b, 5);
                func_003ABBE0(b, 0x64);
                func_003ABBE8(b, 0);
                func_003AB530(b, 0x706EC8FF, 0x706EC8FF);
                func_003AB548(b, 0x80808080, 0x80808080);
                func_003ABD30(b, 0x80000000);
                func_003ABD10(b, 1);
                j++;
                b += 0x3C;
            } while (j < 0x1A);
            func_003AD7D8(s + (i * 0xB50 + 0x18A0), a1, a2);
            func_003ABFA8(s + (i * 0x230 + 0x4610), a2);
        }
    }
    q = s + 0x45E0;
    func_003AB778(q, D_001D8740, a2);
    *(f32 *)func_003AAEB8(q) = 2155905024.0f;
    *func_003AB820(q) = 60008.0f;
    ((s32 *)func_003AB820(q))[1] = 0;
    *(s32 *)(s + 0x189C) = a2;
    func_003ABFA8(s + 0x4ED0, a2);
}
/* localdecomp:end func_003AEE38 */
