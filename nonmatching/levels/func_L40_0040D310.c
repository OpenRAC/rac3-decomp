/* func_L40_0040D310: near miss (Sonnet w4 p2w3): NEAR 60
   Size 428 bytes. structure ported from asm (twin func_002B50E0); retail reads one global (0x24112C) in both gp form and lui form within the function; single-declaration C gives one form, so ~60 diff; no clean C form found
   Left for lead: see note.
*/
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L39_0024112C;
__asm__(".extern D_L39_0024112C, 4");
extern u8 *func_L01_0045B958(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_0045B908(void *, void *);
extern void func_L01_0045B6C8(void *, void *, f32);
extern void func_L40_0040D7D0(void *, void *, void *, void *, void *, f32);
extern void func_L40_0040D4C0(void *, void *, void *, void *);
extern void func_L01_0045B110(void *, void *, void *);
extern void func_L01_0045BB60(void *, void *, f32);
extern void func_L01_0045C240(void);
s32 func_L40_0040D310(u8 *self, void *target, s32 mode, f32 amount) {
    u128_t work[3];
    u8 *data = func_L01_0045B958(self);
    s32 flags;
    if (func_0038CF38(self + 0x10, target) < *(f32 *)(data + 0x34))
        return 0;
    if (data == 0)
        return 8;
    if (D_L39_0024112C == *(s32 *)(data + 0xBC))
        return *(s32 *)(data + 0x94);
    flags = *(s32 *)(data + 0x38);
    *(s32 *)(data + 0x38) = flags | 4;
    *(s32 *)(data + 0xA8) = 0;
    *(s32 *)(data + 0x98) = *(s32 *)(data + 0x94);
    *(s32 *)(data + 0x94) = 0;
    if (!(*(s32 *)(data + 0x38) & 0x100))
        func_L01_0045B908(self, data);
    work[0] = *(u128_t *)(self + 0x10);
    if (D_L39_0024112C - *(s32 *)(data + 0xBC) >= 2 || *(s32 *)(data + 0xBC) == 0) {
        func_L01_0045B6C8(self, data, 0.0f);
        *(s32 *)(data + 0x9C) &= ~2;
        *(u8 *)(data + 0xEA) = 0xFF;
        *(f32 *)(data + 0xB4) = 0.0f;
        *(s32 *)(data + 0x80) = 0;
    }
    *(s32 *)(data + 0xBC) = D_L39_0024112C;
    if (mode == 1)
        func_L40_0040D7D0(self, data, target, &work[1], &work[2], amount);
    func_L40_0040D4C0(self, data, &work[0], &work[2]);
    func_L01_0045B110(self, data, target);
    func_L01_0045BB60(self, data, amount);
    func_L01_0045C240();
    *(s32 *)(data + 0x38) = flags;
    return *(s32 *)(data + 0x94);
}
