/* functional: high. Same reads, writes, calls and order as retail; only register allocation and the shape of the two loops (do-while kept as do-while) may differ. Callees that take no argument in retail are called with none. Not byte-checked. */
extern u8 D_L01_002E9F98[];
extern s32 D_L01_002E9F9C;
extern s32 D_L01_001EA940[];
extern s32 D_L01_001E15E0[];
extern s32 D_L01_001E1070;
extern s32 D_L01_001DF948;
extern s32 D_L01_001F3FA0[];
extern s32 D_001A1ED0[];
extern s32 D_001D4BB4;
extern s32 D_001D4BC4;
extern s32 D_001D66A4;

extern s32 func_L01_00479200(void);
extern s32 func_L01_0047B3D8(void);
extern s32 func_L01_0047B948(void);
extern void func_L01_00514720(s32 *dst);
extern void *func_003E6C08(void *);
extern s32 func_003E6DE8(void *);
extern void func_L01_00514D78(s32, s32, u8 *);
extern void func_L01_00514DD0(s32, s32, s32);
extern void func_003A92F0(s32);
extern void func_0012C908(s32);
extern void func_L01_0048D930(s32, s32);
extern void func_L01_0047DEC0(void);
extern void func_L01_0047EDC0(s32);
extern void func_003A9108(void);
extern void func_0039EF28(void);
extern void func_L01_0042DF90(s32 *, s32 *);
extern void func_L01_0041C4A0(s32);
extern void func_L01_0041C170(s32, s32, s32);
extern void func_L01_004C5F70(s32, s32, s32);
extern void func_003E6FF0(s32, s32);
extern void func_L01_0047DCB8(void);

void func_L01_0047DF40(s32 a0) {
    s32 *S = (s32 *)D_L01_002E9F98;
    u8 *B = D_L01_002E9F98;
    s32 isTwo;
    s32 *img;
    s32 i;

    if (B[0x70] == 0 || B[0x71] != 0) {
        func_L01_00479200();
        func_L01_0047B3D8();
        func_L01_0047B948();
        func_L01_00514720((s32 *)(B + 0x60));
        func_L01_00514720((s32 *)(B + 0x50));
        if (B[0x70] == 0 && *(s32 *)(B + 0x74) != 5) {
            u8 tmp;
            void *p = D_L01_001E15E0;
            s32 h;
            tmp = 0;
            if (D_L01_001E15E0[1] == 0) {
                p = func_003E6C08(p);
            }
            h = func_003E6DE8(p);
            for (i = 0; i < 0x23; i++) {
                B[0x2C + i] = 0;
                if (h != 0) {
                    func_L01_00514D78(h, i, &tmp);
                    B[0x2C + i] = tmp;
                    func_L01_00514DD0(h, i, 0);
                }
            }
        }
    }
    func_003A92F0(1);
    func_0012C908(0);
    D_L01_001DF948 = D_L01_001DF948 + 1;
    *(s32 *)(B + 0x80) = D_001D4BB4;
    func_L01_0048D930(0, -1);
    isTwo = (S[0] == 2);
    if (isTwo) {
        s32 w3 = D_L01_001EA940[4] + 0x30000;
        s32 w4 = D_L01_001EA940[3] + 0x30000;
        s32 a7, a4, t6, t5;
        D_L01_001E1070 = 0x30000;
        *(s32 *)(B + 8) = w3;
        *(s32 *)(B + 4) = w4;
        func_L01_0047DEC0();
        a7 = *(s32 *)(B + 8);
        a4 = *(s32 *)(B + 4);
        t6 = a7 + 0xE0000;
        t5 = a4 + 0x3C000;
        *(s32 *)(B + 0x1C) = a4;
        *(s32 *)(B + 8) = t6 + 0x12C00;
        *(s32 *)(B + 4) = t5 + 0x12C00;
        *(s32 *)(B + 0x20) = a7;
        *(s32 *)(B + 0x24) = t5;
        *(s32 *)(B + 0x28) = t6;
        func_L01_0047EDC0(0);
    } else {
        s32 w2 = D_L01_001EA940[4] + 0x30000;
        s32 w3 = D_L01_001EA940[3] + 0x30000;
        s32 a6, a5, t16, t7;
        D_L01_001E1070 = 0x30000;
        *(s32 *)(B + 8) = w2;
        *(s32 *)(B + 4) = w3;
        func_L01_0047DEC0();
        a6 = *(s32 *)(B + 4) + 0xC000;
        a5 = *(s32 *)(B + 8) + 0xC000;
        t16 = a6 + 0x30000;
        t7 = a5 + 0xE0000;
        *(s32 *)(B + 8) = t7 + 0x61C00;
        *(s32 *)(B + 4) = t16 + 0xD6400;
        *(s32 *)(B + 0x1C) = a6;
        *(s32 *)(B + 0x20) = a5;
        *(s32 *)(B + 0x24) = t16;
        *(s32 *)(B + 0x28) = t7;
        func_L01_0047EDC0(1);
    }
    D_001D66A4 = 0x2000;
    func_003A9108();
    if (isTwo) {
        func_0039EF28();
        func_L01_0042DF90(&D_L01_002E9F9C, &D_L01_002E9F9C + 1);
    }
    func_L01_0041C4A0(0);
    func_L01_0041C170(isTwo ? 1 : 0, S[0x1C / 4], S[0x20 / 4]);
    func_L01_004C5F70(S[0x20 / 4], D_001A1ED0[1], D_001D4BC4 << 11);
    {
        s32 v5 = D_001D4BB4;
        if (isTwo) {
            s32 *b = D_L01_001F3FA0;
            s32 *q;
            s32 n;
            b[0x42C / 4] = v5;
            b[0x430 / 4] = v5 + 0x40000;
            D_001D4BB4 = v5 + 0x40400;
            q = &b[0x434 / 4];
            for (n = 3; n >= 0; n--) {
                *q = D_001D4BB4;
                D_001D4BB4 = D_001D4BB4 + 0x4000;
                q++;
            }
        } else {
            s32 *b = D_L01_001F3FA0;
            s32 *q;
            s32 n;
            b[0x42C / 4] = 0;
            b[0x430 / 4] = 0;
            q = &b[0x440 / 4];
            for (n = 3; n >= 0; n--) {
                *q = 0;
                q--;
            }
        }
    }
    if (B[0x70] != 0 && (u32)(S[0] - 0x14) < 2) {
        func_L01_0047DCB8();
    }
    *(s32 *)(B + 0x74) = 0;
    B[0x72] = 0;
    B[0x70] = 0;
    B[0x71] = 0;
    func_003E6FF0(a0, 1);
}
