/* functional: medium. Flag meanings unknown but every read/write/call matches the asm; sprintf's int varargs are cast to char* only because the file context prototypes them that way. */
typedef struct { s32 w0; u8 pad4[0x3C]; s16 h40; s16 h42; } S_00142660_0048C0F0;
typedef struct { u8 pad0[5]; u8 b5; u8 pad6; u8 b7; u8 pad8[0xC]; u8 b14; u8 pad15[0xB]; u8 b20; u8 b21; u8 b22; } S_00142CA0_0048C0F0;
typedef struct { u8 pad[0x7E]; u8 b7E; } S_001426E0_0048C0F0;
extern S_00142660_0048C0F0 D_00142660[];
extern S_00142CA0_0048C0F0 D_00142CA0[];
extern S_001426E0_0048C0F0 D_001426E0[];
extern u32 D_00142C18[];
extern u8 D_001D554F[];
extern u8 D_001D5550[];
extern u8 D_001D5551[];
extern u8 D_001D5552[];
extern u8 D_001D5553[];
extern char *D_L01_001D8BC0;
extern char *D_L01_001D8BC4[];
extern char *D_L01_001D8BC8[];
extern char *D_L01_001D8BCC[];
extern char *D_L01_001D8BD0[];
extern char *D_L01_001D8BD4[];
extern char *D_L01_001D8BD8[];
extern char D_L01_001D8BF8[];
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00517F50(s32, s32, s32);
extern void func_L01_00517190(s32, s32);
extern s32 func_L01_00452740(void);
extern s32 func_L01_004526E8(void);
extern void func_L01_0048BFC8(void);

void func_L01_0048C0F0(void) {
    s32 *SEL = (s32 *)&D_L01_001E0900;
    s32 i;
    s32 a;
    s32 b;
    s32 c;

    for (i = 9; i >= 0; i--) {
        SEL[i] = -1;
    }
    SEL[0] = D_00142660[0].h40 + 11;
    if (D_00142CA0[0].b14 != 0) {
        SEL[1] = 0;
    } else if (D_00142CA0[0].b21 != 0) {
        if ((D_00142C18[0] & 0x1000000) == 0) {
            SEL[1] = 3;
        }
    }
    if (D_00142CA0[0].b7 != 0) SEL[2] = 2;
    if (D_00142CA0[0].b5 != 0) SEL[3] = 1;
    if (D_00142CA0[0].b20 != 0) SEL[4] = 16;
    if (D_001D554F[0] != 0) SEL[5] = 5;
    if (D_001D5551[0] != 0) SEL[6] = 6;
    if (D_001D5552[0] != 0) SEL[7] = 7;
    if (D_001D5550[0] != 0) SEL[8] = 8;
    if (D_00142CA0[0].b22 != 0) SEL[9] = 4;
    if (D_001D5553[0] != 0) SEL[9] = 9;

    for (i = 0; i < 10; i++) {
        s32 v = SEL[i];
        if (v == -1 || D_L01_002BC9F0[v].w8 == -1) {
            func_L01_00516D60(i + 0x30, 0);
            continue;
        }
        func_L01_00516D60(i + 0x30, 1);
        a = D_L01_002BC9F0[SEL[i]].w0;
        if (a == 0xC6E) {
            func_L01_00517F50(i + 0x30, D_L01_002BC9F0[SEL[i]].w8, 0);
        } else if (a == 0xC6F) {
            func_L01_00517F50(i + 0x30, D_L01_002BC9F0[SEL[i]].w8, 1);
        } else if (a == 0xC70) {
            func_L01_00517F50(i + 0x30, D_L01_002BC9F0[SEL[i]].w8, 2);
        } else if (a == 0xC71) {
            func_L01_00517F50(i + 0x30, D_L01_002BC9F0[SEL[i]].w8, 3);
        } else if (a == 0xC72) {
            func_L01_00517F50(i + 0x30, D_L01_002BC9F0[SEL[i]].w8, 4);
        } else {
            func_L01_00517190(i + 0x30, D_L01_002BC9F0[SEL[i]].w8);
        }
    }

    a = func_L01_00452740();
    c = func_L01_004526E8();
    b = 0x28 - a;
    func_0011B2E8(D_L01_001D8BC0, D_L01_001D8BF8, (char *)a);
    func_0011B2E8(D_L01_001D8BC4[0], D_L01_001D8BF8, (char *)b);
    func_0011B2E8(D_L01_001D8BC8[0], D_L01_001D8BF8, (char *)c);
    a = D_00142660[0].h42;
    c = D_001426E0[0].b7E;
    b = (0x65 - c) - a;
    func_0011B2E8(D_L01_001D8BCC[0], D_L01_001D8BF8, (char *)a);
    func_0011B2E8(D_L01_001D8BD0[0], D_L01_001D8BF8, (char *)b);
    func_0011B2E8(D_L01_001D8BD4[0], D_L01_001D8BF8, (char *)c);
    func_0011B2E8(D_L01_001D8BD8[0], D_L01_001D8BF8, (char *)D_00142660[0].w0);
    D_L01_001D8BE0 = 0;
    func_L01_0048BFC8();
}
