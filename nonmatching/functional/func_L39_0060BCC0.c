/* functional: high. Near exact (one extra delay nop and a register differ); PAL addresses, callees and the PAL gp offsets (D_001E1530_sda) used, not the NTSC draft's. */
typedef struct {
    u8 pad0[0x15C];
    s32 w15C;
    u8 pad160[4];
    s32 w164;
} H_0060BCC0;
typedef struct {
    u8 pad0[7];
    u8 b7;
    u8 pad8[0x18];
} B_0060BCC0;

__asm__(".extern D_L39_0024028C, 4");
extern s32 D_L39_0024028C;
extern u8 D_001DA121_sda;
__asm__(".extern D_001DA121_sda, 1");
extern void (*D_001DA114_sda)(void);
__asm__(".extern D_001DA114_sda, 4");
extern s32 D_001E1530_sda;
__asm__(".extern D_001E1530_sda, 4");
extern H_0060BCC0 D_001A43E0;
extern B_0060BCC0 D_L39_00225660;
__asm__(".extern D_L39_00225660, 16");

extern void func_001264E0(s32);
extern s32 func_00139E08(s32);
extern void func_L39_005A61D8(void);
extern void func_L39_005A5010(void);
extern s32 func_L39_005A4058(void);
extern void func_00193B80(s32);
extern s32 func_00193590(void);
extern void func_00193B50(void);
extern s32 func_00194B88(s32);
extern void func_00194A38(s32);
extern void func_L39_005FD6F8(void);
extern void func_00387EF0(void);

void func_L39_0060BCC0(void) {
    D_L39_0024028C = 0;
    if (D_001DA121_sda == 0) {
        do {
            func_001264E0(0);
            func_00139E08(0);
            func_001959F8();
            func_L39_005A61D8();
            func_L39_005A5010();
            D_001DA121_sda = func_L39_005A4058() != 0;
        } while (D_001DA121_sda == 0);
    }
    while (D_001A43E0.w15C != 2 || D_001A43E0.w164 >= 0) {
        func_001264E0(0);
        func_00139E08(0);
        func_L39_005A61D8();
        func_L39_005A5010();
        func_001959F8();
    }
    if (D_001E1530_sda != 0) {
        func_00193B80(D_001E1530_sda);
    }
    while (func_00193590() != 0) {
        func_001959F8();
    }
    func_00193B50();
    func_00194B88(0);
    func_00194A38(0);
    func_00194A38(0);
    D_L39_00225660.b7 = 0;
    func_L39_005FD6F8();
    if (D_001DA114_sda != 0) {
        D_001DA114_sda();
    }
    func_00387EF0();
}
