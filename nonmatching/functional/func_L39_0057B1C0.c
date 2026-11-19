/* functional: medium. Branch-likely delay slots handled (bnel/beql); saved[] only written for live non-0xFE/0xFD objects as in retail. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V_B1C0;
extern u8 *D_L39_0024B940[];
extern s32 *D_L39_00241120;
extern V_B1C0 D_L39_0024B900[];
extern s32 D_L39_00242914;
extern u8 *D_L39_0024DED0;
extern s32 D_L39_00243200;
extern s32 D_001D80E8_sda;
extern void func_00384AC8(s32 i);
extern void func_00384BB8(s32 i);
extern void func_L39_0057AC28(s32 i);
extern void func_00384498(s32 i, s32 a);
extern void func_L39_005796D0(s32 i);
extern void func_00383830(void *p);
extern void func_003841B8(void *p);
extern void func_003C48A8(void *a, void *b);
extern void func_00384260(s32 i, void *p, s32 k);
extern void func_00384778(s32 i);
extern void func_00385EF0(void *h);
extern void func_L39_00578AA8(s32 i);
extern int func_0038CAD0(void *p);
extern void func_L01_004B14C8(s32 a);
extern void func_L39_0057B060(s32 a);

void func_L39_0057B1C0(void) {
    s32 saved[16];
    s32 i;
    u8 *o;

    for (i = 0; i < 16; i++) {
        o = D_L39_0024B940[i];
        if (o == 0) continue;
        if (o[0x20] == 0xFE) {
            D_L39_0024B940[i] = 0;
        } else if (o[0x20] != 0xFD) {
            saved[i] = *(s32 *)(o + 0x98);
            *(s32 *)(o + 0x98) = 0;
        } else {
            D_L39_0024B940[i] = 0;
        }
    }
    for (i = 0; i < *D_L39_00241120;) {
        u8 *h = (u8 *)D_L39_0024DE80 + i * 0x460;
        u8 *sub = h + 0x150;
        u8 *s17;
        s32 k = i;

        if (*(s32 *)(sub + 0x100) == 0x31) {
            u8 *p = *(u8 **)(sub + 0xF4);
            if (p != 0) *(s32 *)(p + 0x98) = 0;
        }
        *(s32 *)(h + 0x454) = *(s32 *)(h + 0x454) + 1;
        func_00384AC8(i);
        func_00384BB8(i);
        func_L39_0057AC28(i);
        func_00384498(i, 0);
        func_L39_005796D0(i);
        s17 = *(u8 **)(h + 0x50);
        if (*(s32 *)(h + 0x458) > 0) *(s16 *)(h + 0x2A0) = 0;
        if ((u16)(*(u16 *)(h + 0x2A0) - 1) < 2) func_00383830(*(void **)(h + 0x54));
        if (*(s16 *)(h + 0x2A0) == 3) {
            func_003841B8(s17);
        } else {
            *(V_B1C0 *)h = *(V_B1C0 *)(s17 + 0x30);
            *(V_B1C0 *)(h + 0x380) = *(V_B1C0 *)s17;
            *(V_B1C0 *)(h + 0x390) = *(V_B1C0 *)(s17 + 0x10);
            *(V_B1C0 *)(h + 0x3A0) = *(V_B1C0 *)(s17 + 0x20);
        }
        func_003C48A8(h + 0x380, h + 0x10);
        func_00384260(i, h + 0x20, 0);
        func_00384260(i, h + 0x30, 1);
        func_00384260(i, h + 0x40, 2);
        func_00384778(i);
        func_00385EF0(h);
        func_L39_00578AA8(i);
        *(u32 *)(h + 0x410) = 0; *(u32 *)(h + 0x414) = 0; *(u32 *)(h + 0x418) = 0; *(u32 *)(h + 0x41C) = 0;
        if (*(s32 *)(sub + 0x100) == 0x31) {
            u8 *p = *(u8 **)(sub + 0xF4);
            if (p != 0) *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
        }
        D_L39_0024B900[k] = *(V_B1C0 *)h;
        i++;
        func_0038CAD0(h + 0x458);
    }
    if (D_L39_00242914 == 0 || (D_L39_0024DED0 != 0 && *(s16 *)(D_L39_0024DED0 + 0x86) == 0x21)) {
        D_001D80E8_sda = D_L39_00243200;
        func_L01_004B14C8(0);
        func_L39_0057B060(0);
    }
    for (i = 0; i < 16; i++) {
        o = D_L39_0024B940[i];
        if (o != 0) *(s32 *)(o + 0x98) = saved[i];
    }
}
