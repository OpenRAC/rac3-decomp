/* functional: high. 11 words differ with the right context (--no-context needed: the file context declares func_L01_0049F798(void) for the callback table, while the function really takes the screen arg in a0, so that declaration needs a void* prototype when landed); near-exact */
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } Pad_0049F798;
extern Pad_0049F798 *D_001D52FC[];
extern u8 D_L01_001D672C[];
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00517190(s32, s32);
extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);
extern void func_L01_004A0430(void *);
extern void func_L01_004A04B8(void);
extern void func_L01_004A0608(void);
extern void func_L01_004A0A80(void);
extern void func_L01_004A1050(void);
extern u8 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern void func_L01_00516090(void *);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);

void func_L01_0049F798(void *arg) {
    s32 buttons = D_001D52FC[0]->w1C4;

    func_L01_00516D60(0x540003, 1);
    func_L01_00517190(0x540003, 1);
    func_003BA4F8(func_003B9BD0(0), buttons);
    func_L01_004A0430(arg);
    func_L01_004A04B8();
    func_L01_004A0608();
    func_L01_004A0A80();
    func_L01_004A1050();
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090(arg);
        if (D_L01_001D672C[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
