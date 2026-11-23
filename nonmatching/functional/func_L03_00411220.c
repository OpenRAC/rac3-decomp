/* functional: high. 127 byte differences (register allocation of the five result variables a..e and scheduling). Verified vs PAL asm: gp-relative globals, (x*5+2)/6 thresholds, case 0 six-step chain, case 2 flag loop (loop counter shares the retail register with c, which is reset to &D_001D6C50 after), cases 12/13/17, jump table jtbl_002BAEF0 (0,2,12,13,17 handled; others fall through), final call args (a,b,c,e,0,1,0) or (d,b,c,e). Delete INCLUDE_RODATA of the table when landing. */
extern int D_001D545C;
__asm__(".extern D_001D545C, 16");
extern int D_L03_001E6800[];
__asm__(".extern D_L03_001E6800, 16");
extern int D_L03_002E5CA0[];
__asm__(".extern D_L03_002E5CA0, 16");
extern int D_L03_002E5CF0[], D_L03_002E5D50[], D_L03_002E5DC0[], D_L03_002E5E30[], D_L03_002E5E90[], D_L03_002E5EF0[], D_L03_002E5F50[];
extern s32 D_L03_001D6B90[] __attribute__((section(".sdata")));
extern float D_001D6B64_sda; __asm__(".extern D_001D6B64_sda, 4");
extern char D_001D6AD0_sda; __asm__(".extern D_001D6AD0_sda, 4");
extern unsigned char D_001D6AC5_sda; __asm__(".extern D_001D6AC5_sda, 1");
extern int D_001D6B90_sda; __asm__(".extern D_001D6B90_sda, 4");
extern int D_001D6BA8_sda; __asm__(".extern D_001D6BA8_sda, 4");
extern int D_001D6BC0_sda; __asm__(".extern D_001D6BC0_sda, 4");
extern int D_001D6BD8_sda; __asm__(".extern D_001D6BD8_sda, 4");
extern int D_001D6BF0_sda; __asm__(".extern D_001D6BF0_sda, 4");
extern int D_001D6C20_sda; __asm__(".extern D_001D6C20_sda, 4");
extern int D_001D6C08_sda; __asm__(".extern D_001D6C08_sda, 4");
extern int D_001D6C38_sda; __asm__(".extern D_001D6C38_sda, 4");
extern int D_001D6C50_sda; __asm__(".extern D_001D6C50_sda, 4");
extern int D_001D6C78_sda[4] __attribute__((section(".sdata"))); __asm__(".extern D_001D6C78_sda, 4");
extern int D_001D6C68_sda[4] __attribute__((section(".sdata"))); __asm__(".extern D_001D6C68_sda, 4");
extern void func_L01_00423068();
extern void func_L03_004109D8();

void func_L03_00411220(void) {
    int *a, *d;
    void *b, *c;
    int e, i, flag;
    e = 0; d = 0; c = 0; b = 0; a = 0;
    D_L03_002E5CA0[12] = 1;
    D_001D6B64_sda = 1.0f;
    *(char **)&D_L03_002E5CA0[8] = &D_001D6AD0_sda;
    D_001D6AC5_sda = 0;
    if (D_001D545C == 3) {
        switch (D_L03_001E6800[12]) {
        case 0: {
            int t = D_L03_001E6800[13];
            a = D_L03_002E5CF0;
            if (t < (D_L03_001D6B90[1] * 5 + 2) / 6) { b = &D_001D6B90_sda; }
            else if (t < (D_L03_001D6B90[7] * 5 + 2) / 6) { b = &D_001D6BA8_sda; }
            else if (t < (D_L03_001D6B90[13] * 5 + 2) / 6) { b = &D_001D6BC0_sda; }
            else if (t < (D_L03_001D6B90[19] * 5 + 2) / 6) { b = &D_001D6BD8_sda; }
            else if (t < (D_L03_001D6B90[25] * 5 + 2) / 6) { b = &D_001D6BF0_sda; }
            else if (t < (D_L03_001D6B90[31] * 5 + 2) / 6) { b = &D_001D6C08_sda; }
            else { b = &D_001D6C20_sda; }
            break;
        }
        case 2: {
            int t = D_L03_001E6800[13];
            if (t < (D_001D6C38_sda * 5 + 2) / 6) {
                D_L03_002E5CA0[12] = 0;
                e = 1;
                c = 0;
                if (D_001D6AC5_sda == 0) {
                    flag = 0;
                    i = 0;
                    while (flag == 0 && i < 4) {
                        if (!(t < (D_001D6C68_sda[i] * 5 + 2) / 6) && !((D_001D6C78_sda[i] * 5 + 2) / 6 < t)) flag = 1;
                        i++;
                    }
                    D_001D6AC5_sda = flag;
                }
                c = &D_001D6C50_sda;
            } else {
                b = &D_001D6C38_sda;
            }
            if ((D_L03_002E5D50[21] * 5 + 2) / 6 < D_L03_001E6800[13]) d = D_L03_002E5DC0;
            else d = D_L03_002E5D50;
            break;
        }
        case 12:
            if (!(D_L03_001E6800[13] < (D_L03_002E5E30[14] * 5 + 2) / 6)) a = D_L03_002E5E30;
            break;
        case 13:
            a = D_L03_002E5E90;
            if (!(D_L03_001E6800[13] < (D_L03_002E5E90[15] * 5 + 2) / 6)) a = D_L03_002E5EF0;
            break;
        case 17:
            a = D_L03_002E5F50;
            break;
        }
    }
    if (a != 0) func_L01_00423068(a, b, c, e, 0, 1, 0);
    else if (d != 0) func_L03_004109D8(d, b, c, e);
}
