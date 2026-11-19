/* functional: high. Same dispatch, calls and argument order as retail (strings 0x142/0x146/0x148/0x18D/0x18E/0x233/0x234/0x508/0x509 via func_00381FF0 into func_0011B2E8); retail's mtlo/madd address calc and register choice differ. func_0011B2E8 must be declared varargs in the file context (here called with 2..4 args); D_L01_002EB038 element type in the context is E_0048D0C8 (same 12-byte layout) */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} E_00490A50;
extern E_00490A50 D_L01_002EB038[];
extern u8 D_00143950[];
extern s32 D_001D5520;
extern char D_L01_001D8DB8[];
extern char D_L01_001D8DC0[];
extern char D_L01_001D8DC8[];
extern char D_L01_001D8DD0[];
extern s32 D_L01_001D8D60 __attribute__((section(".sdata")));
extern s32 D_L01_001D8D64 __attribute__((section(".sdata")));
extern s32 D_L01_001D8D68 __attribute__((section(".sdata")));
extern s32 D_L01_001D8DB4 __attribute__((section(".sdata")));
extern s32 func_003B9BD0(s32);
extern char *func_003B9E30(s32, s32, s32);
extern char *func_00381FF0(s32);
extern void func_0011B2E8(char *, char *, ...);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);

void func_L01_00490A50(void) {
    s32 i;
    char *r, *s, *t;

    for (i = 0; i < D_L01_001D8D60; i++) {
        switch (D_L01_002EB038[i].w0) {
        case 0x146:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(r, D_L01_001D8DB8, func_00381FF0(0x146));
            r = func_003B9E30(func_003B9BD0(0), 1, i);
            if (*(s32 *)(D_00143950 + 8) != 0) s = func_00381FF0(0x237);
            else s = func_00381FF0(0x236);
            func_0011B2E8(r, D_L01_001D8DC0, s);
            break;
        case 0x148:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(r, D_L01_001D8DB8, func_00381FF0(0x148));
            r = func_003B9E30(func_003B9BD0(0), 1, i);
            if (D_00143950[6] != 0) s = func_00381FF0(0x175);
            else s = func_00381FF0(0x176);
            func_0011B2E8(r, D_L01_001D8DC0, s);
            break;
        case 0x234:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(r, D_L01_001D8DB8, func_00381FF0(0x234));
            func_0011B2E8(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC8);
            break;
        case 0x233:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(r, D_L01_001D8DB8, func_00381FF0(0x233));
            func_0011B2E8(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC8);
            break;
        case 0x508:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(r, D_L01_001D8DB8, func_00381FF0(0x508));
            r = func_003B9E30(func_003B9BD0(0), 1, i);
            if (D_00143950[0xAD] != 0) s = func_00381FF0(0x175);
            else s = func_00381FF0(0x176);
            func_0011B2E8(r, D_L01_001D8DC0, s);
            break;
        case 0x509:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(r, D_L01_001D8DB8, func_00381FF0(0x509));
            r = func_003B9E30(func_003B9BD0(0), 1, i);
            if (D_001D5520 != 0) s = func_00381FF0(0x175);
            else s = func_00381FF0(0x176);
            func_0011B2E8(r, D_L01_001D8DC0, s);
            break;
        case 0x18E:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            s = func_00381FF0(0x142);
            t = func_00381FF0(0x18E);
            func_0011B2E8(r, D_L01_001D8DD0, s, t);
            r = func_003B9E30(func_003B9BD0(0), 1, i);
            if (D_00143950[5] != 0) s = func_00381FF0(0x175);
            else s = func_00381FF0(0x176);
            func_0011B2E8(r, D_L01_001D8DC0, s);
            break;
        case 0x18D:
            r = func_003B9E30(func_003B9BD0(0), 0, i);
            s = func_00381FF0(0x142);
            t = func_00381FF0(0x18D);
            func_0011B2E8(r, D_L01_001D8DD0, s, t);
            r = func_003B9E30(func_003B9BD0(0), 1, i);
            if (D_00143950[4] != 0) s = func_00381FF0(0x175);
            else s = func_00381FF0(0x176);
            func_0011B2E8(r, D_L01_001D8DC0, s);
            break;
        }
    }
    if (D_L01_001D8D64 >= 0) {
        if (D_L01_001D8D68 != D_L01_001D8D64) D_L01_001D8DB4 = 0x1E;
        if (D_L01_001D8DB4 != 0) {
            D_L01_001D8DB4 = D_L01_001D8DB4 - 1;
            if (D_L01_001D8DB4 == 0) {
                func_L01_00517190(0x1E0003, D_L01_002EB038[D_L01_001D8D64].w8);
                func_L01_00516D60(0x1E0003, 1);
            }
        }
        D_L01_001D8D68 = D_L01_001D8D64;
    }
}
