/* US draft of func_003AF1F0 (rac3-uya-decomp func_003AF050, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003AF1F0 */
extern u8 *D_001D5C78_003AF1F0;
extern s32 D_001D545C;
extern u8 D_001D8730[];
extern u8 D_001D8740[];
__asm__(".extern D_001D5C78_003AF1F0, 16");
__asm__(".extern D_001D545C, 16");
extern s32 func_003AC190();
extern void func_003AB858();
extern void func_003AC0D0();
extern void func_003ABF98();
extern void func_003ABFA0();
extern void func_003AB8E8();
extern void func_003AB900();
extern void func_003AC0E8();
extern void func_003AC0C8();
extern void func_003ADB90();
extern void func_003AC360();
extern void func_003ABB30();
extern f32 *func_003ABBD8();
typedef struct { u8 pad[0x5100]; s32 a[4]; s32 b[4]; } S_3A9890;
void func_003AF1F0(S_3A9890 *sx, s32 a1, s32 a2) {
    u8 *s = (u8 *)sx;
    u8 *b;
    u8 *q;
    s32 i;
    s32 k;
    u32 j;
    f32 *r;
    for (k = 0; k < 4; k++) {
        sx->a[k] = func_003AC190(D_001D5C78_003AF1F0 + 0x7090, 0xC);
        sx->b[k] = func_003AC190(D_001D5C78_003AF1F0 + 0x7090, 0xD);
    }
    if (D_001D545C != -2) {
        for (i = 0; i < 4; i++) {
            b = s + i * 0x618;
            j = 0;
            do {
                func_003AB858(b, 0x16, 1, D_001D8730, a2);
                func_003AC0D0(b, 5);
                func_003ABF98(b, 0x64);
                func_003ABFA0(b, 0);
                func_003AB8E8(b, 0x706EC8FF, 0x706EC8FF);
                func_003AB900(b, 0x80808080, 0x80808080);
                func_003AC0E8(b, 0x80000000);
                func_003AC0C8(b, 1);
                j++;
                b += 0x3C;
            } while (j < 0x1A);
            func_003ADB90(s + (i * 0xB50 + 0x18A0), a1, a2);
            func_003AC360(s + (i * 0x230 + 0x4610), a2);
        }
    }
    q = s + 0x45E0;
    func_003ABB30(q, D_001D8740, a2);
    *(f32 *)func_003AB270(q) = 2155905024.0f;
    *func_003ABBD8(q) = 60008.0f;
    ((s32 *)func_003ABBD8(q))[1] = 0;
    *(s32 *)(s + 0x189C) = a2;
    func_003AC360(s + 0x4ED0, a2);
}
/* localdecomp:end func_003AF1F0 */
