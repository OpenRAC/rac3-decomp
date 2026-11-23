/* functional: high. Retail returns b+0x94 (8 if no state) in v0; file context declares this void (callers ignore it), so this snippet is void to match the context (the s32 return b+0x94 is dropped; change the context declaration to s32 to restore it). Calls func_L01_0045C240 with the leftover a0/a1 = (self,b) as retail leaves them. */
extern void func_L01_0045B8D8(u8 *, u8 *);
extern void func_L01_0045AF28(u8 *, u8 *);
extern void func_L01_0045B908(u8 *, u8 *);
extern void func_L01_0045B6C8(u8 *, u8 *, f32);
extern void func_L01_0045AAD8(u8 *, u8 *, u8 *, f32, void *, void *);
extern void func_L01_0045B110(u8 *, u8 *, u8 *);
extern void func_L01_0045BB60(u8 *, u8 *, f32);
extern void func_L01_0045C240(u8 *, u8 *);
extern s32 D_L01_001DFB40;
void func_L01_0045A898(f32 *self_, f32 *out_, f32 x) {
    u8 *self = (u8 *)self_;
    u8 *out = (u8 *)out_;
    f32 v0[4] __attribute__((aligned(16)));
    f32 v1[4] __attribute__((aligned(16)));
    u8 *b = (u8 *)func_L01_0045B958((M_4574A0 *)self);
    if (b == 0) {
        return;
    }
    if (D_L01_001DFB40 == *(s32 *)(b + 188)) {
        return;
    }
    *(s32 *)(b + 152) = *(s32 *)(b + 148);
    *(s32 *)(b + 148) = 0;
    if ((*(s32 *)(b + 56) & 0x100) == 0) {
        func_L01_0045B908(self, b);
    }
    if (D_L01_001DFB40 - *(s32 *)(b + 188) >= 2 || *(s32 *)(b + 188) == 0) {
        func_L01_0045B6C8(self, b, 0.0f);
        *(f32 *)(b + 180) = 0.0f;
        *(s32 *)(b + 156) &= ~2;
        *(u8 *)(b + 234) = 255;
        ((s32 *)(b + 160))[0] = 0;
        ((s32 *)(b + 160))[1] = 0;
        ((s32 *)(b + 160))[2] = 0;
        ((s32 *)(b + 160))[3] = 0;
        *(s32 *)(b + 128) = 0;
    }
    *(s32 *)(b + 188) = D_L01_001DFB40;
    func_L01_0045B8D8(self, b);
    func_L01_0045AAD8(self, b, out, x, v0, v1);
    func_L01_0045AF28(self, b);
    func_L01_0045B110(self, b, out);
    func_L01_0045BB60(self, b, x);
    func_L01_0045C240(self, b);
}
