/* functional: high. Menu screen-change dispatcher: resets the menu heap (0xC8000-byte arena at D_L39_0024027C/0280), consumes the pending transition id D_L39_00241440 (set to -1) and switches on it (0..9) to run that transition's setup: per-case it sets the menu object state word (+0x284) to 0x18/0/0x12/0x19/0x15/0x1D, runs the per-slot refresh loop over the count at *D_L39_00241120 (skipped when D_L39_002412DC == 0x27), copies the saved selection fields of D_001A5CD0 (+0x70/+0x78) back into the cursor object, fills the sub-object at menu+0x50 (name 0x11, flags 0x98/0x9D, value 0x94) and then installs the new per-frame callbacks func_L39_0067CA48 / func_L39_0067CAC0 / func_L39_0067CCB0 via func_001953B8 and func_001953D0 (some cases call the pair twice). Cases 4/6/9/3/5 share one loop block; id 4 and 9 set the state word early; 6 returns early after the cursor copy. Switch table jtbl_0047B520: 0->A, 1->B, 2->C, 3/5->G, 4/6/9->F, 7->D, 8->E. */
extern s32 D_L39_0024027C;
extern s32 D_L39_00240280;
extern u32 D_L39_00241440;
extern s32 D_L39_002412DC;
extern s32 **D_L39_00241120;
extern void *D_L39_00241640;
extern u8 D_L39_002359E0[];
extern u8 D_001A5CD0[];
extern u8 *D_L39_00247914;
extern u8 *D_L39_0024D760;
extern u8 *D_001DC204_sda;
extern u8 *D_001E2050_sda;
__asm__(".extern D_L39_0024027C, 16");
__asm__(".extern D_L39_00240280, 16");
__asm__(".extern D_L39_00241440, 16");
__asm__(".extern D_L39_002412DC, 16");
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_00241640, 16");
__asm__(".extern D_L39_00247914, 16");
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_001DC204_sda, 4");
__asm__(".extern D_001E2050_sda, 4");
extern void func_L39_0067EC00(void);
extern void func_00392260(s32, s32, s32);
extern void func_L39_006D78B8(s32, s32);
extern void func_L39_006813F8(void);
extern void func_L39_00685E30(s32, s32);
extern void func_L01_00480B10(s32);
extern void func_L39_0067CCB0(void);
extern void func_L39_0067CA48(void);
extern void func_L39_0067CAC0(void);
extern void func_001953B8(void *);
extern void func_001953D0(void *);
extern void func_L39_006D8D80(void *);
extern void func_001206F4(void *, void *);
extern s32 func_L39_0067CE40(void *);
extern void func_L39_006DCC80(void *);
extern void func_L39_005DA820(s32);
extern void func_L39_005E0450(s32);
extern void func_L39_005D7360(s32);
extern void func_L39_006774C8(void);
extern void func_L39_005D8DB8(void);
extern void func_L39_00686048(void);
extern void func_L39_006A7928(void);
extern void func_00199050(void);
extern void func_L39_006D40B0(void *);

void func_L39_0067C408(void) {
    u32 st;
    s32 rest;
    void (*fn)(void);
    u8 *obj;
    u8 *sub;
    s32 i;
    s32 n;
    s32 v;
    u8 b6;

    func_L39_0067EC00();
    func_00392260(0, 0, 0);
    st = D_L39_00241440;
    rest = D_L39_00240280 - D_L39_0024027C - 0xC8000;
    D_L39_00241440 = -1;
    func_L39_006D78B8(D_L39_0024027C, 0xC8000);
    func_L39_006813F8();
    func_L39_00685E30(D_L39_0024027C + 0xC8000, rest);
    func_L01_00480B10(10);

    switch (st) {
    case 0:
        obj = D_L39_00247914;
        fn = func_L39_0067CCB0;
        *(s32 *)(obj + 0x284) = 0x18;
        func_001953B8(fn);
        func_001953D0(fn);
        return;
    case 1:
        obj = D_L39_00247914;
        fn = func_L39_0067CA48;
        *(s32 *)(obj + 0x284) = 0;
        func_001953B8(fn);
        func_001953D0(fn);
        if (*(s32 *)(D_001A5CD0 + 0x174) != 0) {
            fn = func_L39_0067CCB0;
        } else {
            if (D_001A5CD0[0x2E4] == 0) {
                func_L39_006D8D80(D_001E2050_sda);
            }
            b6 = D_001A5CD0[0x2E5];
            if (b6 != 0) {
                sub = *(u8 **)(D_001E2050_sda + 0x50);
                v = *(s32 *)(D_001A5CD0 + 0x2C4);
                sub[0x9D] = b6;
                sub[0x98] = D_001A5CD0[0x180];
                func_001206F4(sub + 0x11, D_001A5CD0 + 0x182);
                *(s32 *)(sub + 0x94) = v;
                if (func_L39_0067CE40(sub) != 0) {
                    func_L39_006DCC80(sub);
                }
            }
            fn = func_L39_0067CAC0;
        }
        func_001953B8(fn);
        func_001953D0(fn);
        return;
    case 2:
        obj = D_L39_00247914;
        fn = func_L39_0067CAC0;
        *(s32 *)(obj + 0x284) = 0;
        func_001953B8(fn);
        func_001953D0(fn);
        return;
    case 4:
    case 6:
    case 9:
        if (D_L39_002412DC != 0x27) {
            n = **D_L39_00241120;
            if (n > 0) {
                i = 0;
                do {
                    func_L39_005DA820(i);
                    func_L39_005E0450(i);
                    func_L39_005D7360(i);
                    i++;
                } while (i < **D_L39_00241120);
            }
            func_L39_006774C8();
            func_L39_005D8DB8();
        }
        if (st == 4) {
            *(s32 *)(D_L39_00247914 + 0x284) = 0x12;
        }
        if (st == 9) {
            *(s32 *)(D_L39_00247914 + 0x284) = 0x19;
        }
        func_001953B8(func_L39_0067CA48);
        func_001953D0(func_L39_0067CA48);
        func_L39_00686048();
        *(s32 *)(D_001A5CD0 + 0x170) = 0;
        if (D_L39_00241640 == (void *)D_L39_002359E0) {
            D_L39_00241640 = 0;
        }
        func_001953B8(func_L39_0067CAC0);
        func_001953D0(func_L39_0067CAC0);
        if (st == 6) {
            u8 *cur = D_001E2050_sda;
            v = *(s32 *)(D_001A5CD0 + 0x78);
            **(s32 **)(cur + 0x4C) = v;
            *(s32 *)(D_001A5CD0 + 0x78) = v;
            v = *(s32 *)(D_001A5CD0 + 0x70);
            *(s32 *)(*(u8 **)(cur + 0x30) + 0x28) = v;
            *(s32 *)(D_001A5CD0 + 0x70) = v;
            func_L39_006A7928();
            return;
        }
        if (st == 4) {
            return;
        }
        func_00199050();
        obj = D_001DC204_sda;
        if (*(s32 *)(D_001A5CD0 + 0x174) != 0) {
            *(s32 *)(obj + 0x284) = 0x15;
        } else {
            func_L39_006D40B0(*(void **)(D_L39_0024D760 + 0x3C));
        }
        return;
    case 3:
    case 5:
        if (D_L39_002412DC != 0x27) {
            n = **D_L39_00241120;
            if (n > 0) {
                i = 0;
                do {
                    func_L39_005DA820(i);
                    func_L39_005E0450(i);
                    func_L39_005D7360(i);
                    i++;
                } while (i < **D_L39_00241120);
            }
            func_L39_006774C8();
            func_L39_005D8DB8();
        }
        obj = D_001DC204_sda;
        fn = func_L39_0067CCB0;
        if (st == 5) {
            func_L39_006A7928();
        } else {
            *(s32 *)(obj + 0x284) = 0x12;
        }
        func_001953B8(fn);
        func_001953D0(fn);
        return;
    case 7:
    case 8:
        sub = *(u8 **)(D_L39_0024D760 + 0x50);
        v = *(s32 *)(D_001A5CD0 + 0x2C4);
        sub[0x9D] = D_001A5CD0[0x2E5];
        sub[0x98] = D_001A5CD0[0x180];
        func_001206F4(sub + 0x11, D_001A5CD0 + 0x182);
        *(s32 *)(sub + 0x94) = v;
        obj = D_001DC204_sda;
        if (func_L39_0067CE40(sub) != 0) {
            func_L39_006DCC80(sub);
            obj = D_L39_00247914;
        }
        fn = (st == 8) ? func_L39_0067CAC0 : func_L39_0067CCB0;
        *(s32 *)(obj + 0x284) = 0x1D;
        func_001953B8(fn);
        func_001953D0(fn);
        return;
    default:
        return;
    }
}
