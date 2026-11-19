/* functional: high. Per-frame menu update, ported from the NTSC-U draft of the twin with PAL names re-derived from the PAL asm: bumps the frame-guard counter D_001DB0CC, runs the pre-update calls, stores frame counters, converts the timer T0_COUNT into a frame-time ratio (D_L39_0024BB48, divisor 11520/9600 by the video-mode flag D_001A5810), clears a byte, accumulates and resets T0_COUNT into the 64-bit D_L39_00240200, runs the update calls, and if the global menu object D_L39_0024D760 exists runs its update, measures elapsed ticks since a stored stamp and picks between func_L39_00689420 and func_L39_00689570. */
typedef struct { u8 p0; u8 f1; u8 p2[6]; s32 f8; } S_0067CAC0;

extern s32 D_001DB0CC_sda;
__asm__(".extern D_001DB0CC_sda, 4");
extern s32 D_001DB0FC_sda;
__asm__(".extern D_001DB0FC_sda, 4");
extern u8 D_001DC30A_sda;
__asm__(".extern D_001DC30A_sda, 1");
extern s32 D_001E0434_sda;
__asm__(".extern D_001E0434_sda, 4");
extern s32 D_001E02B8_sda;
__asm__(".extern D_001E02B8_sda, 4");
extern s32 D_L39_0024BB44;
__asm__(".extern D_L39_0024BB44, 16");
extern f32 D_L39_0024BB48;
__asm__(".extern D_L39_0024BB48, 16");
extern s32 D_L39_0024B9C8;
__asm__(".extern D_L39_0024B9C8, 16");
extern u8 D_L39_002429AE;
__asm__(".extern D_L39_002429AE, 16");
extern unsigned long D_L39_00240200;
__asm__(".extern D_L39_00240200, 16");
extern S_0067CAC0 *D_L39_0024D760;
__asm__(".extern D_L39_0024D760, 16");
extern s32 D_001A5810[];
extern void func_L39_0067C9C0(void);
extern void func_L39_005A61D8(void);
extern void func_003A92F0(s32);
extern s32 func_00139E08(s32);
extern void func_00388138(void);
extern void func_L39_0058CC68(void);
extern void func_L39_005FCDF8(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_L39_00597E70(void);
extern void func_L01_00461818(void);
extern void func_001959F8(void);
extern void func_L39_0067EC30(void);
extern void func_L39_005F1718(void);
extern void func_L39_006D8B88(void *);
extern s32 func_0012DCB0(void);
extern long func_00130760(s32, s32);
extern void func_L39_00689420(void);
extern void func_L39_00689570(void);

void func_L39_0067CAC0(void) {
    S_0067CAC0 *p;
    s32 v;

    D_001DB0CC_sda++;
    func_L39_0067C9C0();
    D_001E0434_sda = D_L39_0024BB44 + 1;
    func_L39_005A61D8();
    func_003A92F0(1);
    D_L39_0024BB48 = (f32)*(volatile u32 *)0x10000800 / (D_001A5810[0] != 0 ? 11520.0f : 9600.0f);
    func_00139E08(0);
    D_L39_002429AE = 0;
    D_001E02B8_sda = D_L39_0024B9C8 + 1;
    func_00388138();
    D_L39_00240200 += *(volatile u32 *)0x10000800;
    *(volatile u32 *)0x10000800 = 0;
    func_L39_0058CC68();
    func_L39_005FCDF8();
    func_003A9150();
    func_003923D0();
    func_00392748(1);
    func_L39_00597E70();
    func_L01_00461818();
    func_001959F8();
    func_L39_0067EC30();
    func_L39_005F1718();
    if (D_L39_0024D760 != 0) {
        func_L39_006D8B88(D_L39_0024D760);
        p = D_L39_0024D760;
        v = 0;
        if (p->f1 != 0) {
            v = (s32)func_00130760(func_0012DCB0(), 0x24000) - p->f8;
        }
        if (D_001DB0FC_sda < v && D_001DC30A_sda != 0) {
            func_L39_00689420();
        } else {
            func_L39_00689570();
        }
    }
    D_001DB0CC_sda--;
}
