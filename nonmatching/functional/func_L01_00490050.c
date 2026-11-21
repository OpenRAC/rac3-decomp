/* functional: medium. Switch over state D_L01_001D8D98 (0..5) of a screen/menu per-frame update; ee-gcc allocates one fewer saved register so bytes differ, behaviour same. Prototypes of func_00381FF0 (char *(s32)) and func_0011B2E8 (needs varargs: called with 6 args) differ from the file context's: widen those two earlier externs when merging; D_001D5520/D_001D52FC are core data (below 0x1D5680). */
extern s32 D_L01_001D8D98 __attribute__((section(".sdata")));
extern s32 D_L01_001D8D9C __attribute__((section(".sdata")));
extern s32 D_L01_001D8DA0 __attribute__((section(".sdata")));
extern s32 D_L01_001D8D70 __attribute__((section(".sdata")));
extern s32 D_L01_001D8D6C __attribute__((section(".sdata")));
extern s32 D_L01_001D8D64 __attribute__((section(".sdata")));
extern s32 D_001D5520 __attribute__((section(".sdata")));
extern u8 *D_001D52FC __attribute__((section(".sdata")));
extern char D_L01_001D8DA8[];
extern char D_L01_002EAF38[];
extern u8 D_L01_001D672C;
extern s32 func_003B97B0(void);
extern s32 func_L01_00498110(void);
extern char *func_00381FF0(s32);
extern void func_0011B2E8(char *, char *, ...);
extern s32 func_003B9700(s32, s32, s32, s32, s32);
extern void func_003B96D8(s32, s32);
extern void func_L01_00491220(void);
extern void func_003B9890(void);
extern void func_00414448(s32, s32, s32);
extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);
extern s32 func_003B9C58(s32);
extern void func_L01_00490970(s32, s32);
extern void func_L01_00490A50(void);
extern void func_L01_00490FC8(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern void func_L01_00516090(void *);
extern void *func_L01_0047EBE0(void);
extern void func_00517748(void *);

void func_L01_00490050(s32 a0) {
    char *a, *b, *c, *d, *e;
    s32 s, x, y;
    switch ((u32)D_L01_001D8D98) {
    case 1:
        if (func_003B97B0() == 0) {
            switch (func_L01_00498110()) {
            case 1:
                D_L01_001D8D9C = D_L01_001D8D70;
                D_L01_001D8DA0 = D_L01_001D8D6C;
                a = func_00381FF0(0x511);
                b = func_00381FF0(0x512);
                c = func_00381FF0(0x513);
                func_0011B2E8(D_L01_002EAF38, D_L01_001D8DA8, a, b, D_L01_001D8DA0, c);
                d = func_00381FF0(0x8E3);
                e = func_00381FF0(0x8DF);
                func_003B9700(0, d, e, (s32)D_L01_002EAF38, 0);
                func_003B96D8(0x20, 0x10);
                D_L01_001D8D98 = 2;
                break;
            case 2:
                D_L01_001D8D98 = 0;
                break;
            }
        }
        break;
    case 2:
        D_001D5520 = (D_001D5520 == 0);
        func_L01_00491220();
        D_L01_001D8D98 = 3;
        break;
    case 3:
        a = func_00381FF0(0x511);
        b = func_00381FF0(0x512);
        c = func_00381FF0(0x513);
        func_0011B2E8(D_L01_002EAF38, D_L01_001D8DA8, a, b, D_L01_001D8DA0, c);
        if (func_003B97B0() == 0) {
            switch (func_L01_00498110()) {
            case 1:
                D_L01_001D8D98 = 0;
                break;
            case 2:
                D_L01_001D8D98 = 4;
                break;
            }
        } else {
            D_L01_001D8D9C = D_L01_001D8D9C - 1;
            if (D_L01_001D8D9C <= 0) {
                D_L01_001D8DA0 = D_L01_001D8DA0 - 1;
                if (D_L01_001D8DA0 <= 0) {
                    func_003B9890();
                    D_L01_001D8D98 = 4;
                }
                D_L01_001D8D9C = D_L01_001D8D70;
            }
        }
        break;
    case 4:
        D_001D5520 = (D_001D5520 == 0);
        func_L01_00491220();
        D_L01_001D8D98 = 0;
        break;
    case 5:
        if (func_003B97B0() == 0) {
            D_L01_001D8D98 = 0;
        } else {
            s = *(s32 *)(D_001D52FC + 0x1C4);
            x = -1;
            if (!(s & 0x8000)) x = (s & 0x2000) != 0;
            s = *(s32 *)(D_001D52FC + 0x1C4);
            y = -1;
            if (!(s & 0x1000)) y = (s & 0x4000) != 0;
            func_00414448(x, y, 1);
        }
        break;
    case 0:
        s = *(s32 *)(D_001D52FC + 0x1C4);
        func_003BA4F8(func_003B9BD0(0), s);
        D_L01_001D8D64 = func_003B9C58(func_003B9BD0(0));
        func_L01_00490970(a0, s);
        func_L01_00490A50();
        func_L01_00490FC8();
        break;
    }
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090((void *)a0);
        if (D_L01_001D672C == 0) {
            func_00517748(func_L01_0047EBE0());
        }
    }
}
